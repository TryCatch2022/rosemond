#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_481335(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481335  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481338  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    return sub_48133b(app, cpu);
}

/* align: skip  */
void Application::sub_48133b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048133b  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0048133e  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00481341  e821a1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00481346  8b4de4                 -mov ecx, dword ptr [ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00481349  89486c                 -mov dword ptr [eax + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 0048134c  e816a1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00481351  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00481354  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 00481357  813f63736de0           +cmp dword ptr [edi], 0xe06d7363
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3765269347 /*0xe06d7363*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048135d  7529                   -jne 0x481388
    if (!cpu.flags.zf)
    {
        goto L_0x00481388;
    }
    // 0048135f  837f1003               +cmp dword ptr [edi + 0x10], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481363  7523                   -jne 0x481388
    if (!cpu.flags.zf)
    {
        goto L_0x00481388;
    }
    // 00481365  817f1420059319         +cmp dword ptr [edi + 0x14], 0x19930520
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(429065504 /*0x19930520*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048136c  751a                   -jne 0x481388
    if (!cpu.flags.zf)
    {
        goto L_0x00481388;
    }
    // 0048136e  837ddc00               +cmp dword ptr [ebp - 0x24], 0
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
    // 00481372  7514                   -jne 0x481388
    if (!cpu.flags.zf)
    {
        goto L_0x00481388;
    }
    // 00481374  837dd400               +cmp dword ptr [ebp - 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481378  740e                   -je 0x481388
    if (cpu.flags.zf)
    {
        goto L_0x00481388;
    }
    // 0048137a  e88388ffff             -call 0x479c02
    cpu.esp -= 4;
    __abnormal_termination(app, cpu);
    // 0048137f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481380  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481381  e8f1010000             -call 0x481577
    cpu.esp -= 4;
    sub_481577(app, cpu);
    // 00481386  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481387  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481388:
    // 00481388  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481389(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481389  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048138d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048138f  813863736de0           +cmp dword ptr [eax], 0xe06d7363
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
    // 00481395  7519                   -jne 0x4813b0
    if (!cpu.flags.zf)
    {
        goto L_0x004813b0;
    }
    // 00481397  83781003               +cmp dword ptr [eax + 0x10], 3
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
    // 0048139b  7513                   -jne 0x4813b0
    if (!cpu.flags.zf)
    {
        goto L_0x004813b0;
    }
    // 0048139d  81781420059319         +cmp dword ptr [eax + 0x14], 0x19930520
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
    // 004813a4  750a                   -jne 0x4813b0
    if (!cpu.flags.zf)
    {
        goto L_0x004813b0;
    }
    // 004813a6  83781c00               +cmp dword ptr [eax + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004813aa  7504                   -jne 0x4813b0
    if (!cpu.flags.zf)
    {
        goto L_0x004813b0;
    }
    // 004813ac  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004813ae  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004813b0:
    // 004813b0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004813b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4813b3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004813b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004813b4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004813b6  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004813b8  68a8854800             -push 0x4885a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752808 /*0x4885a8*/;
    cpu.esp -= 4;
    // 004813bd  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 004813c2  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004813c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004813c9  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004813d0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004813d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004813d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004813d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004813d6  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004813d9  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004813dc  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004813df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004813e1  0f8475010000           -je 0x48155c
    if (cpu.flags.zf)
    {
        goto L_0x0048155c;
    }
    // 004813e7  80780800               +cmp byte ptr [eax + 8], 0
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
    // 004813eb  0f846b010000           -je 0x48155c
    if (cpu.flags.zf)
    {
        goto L_0x0048155c;
    }
    // 004813f1  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004813f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004813f6  0f8460010000           -je 0x48155c
    if (cpu.flags.zf)
    {
        goto L_0x0048155c;
    }
    // 004813fc  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004813ff  8d7c100c               -lea edi, [eax + edx + 0xc]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 1);
    // 00481403  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481407  f60108                 +test byte ptr [ecx], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx) & 8 /*0x8*/));
    // 0048140a  7444                   -je 0x481450
    if (cpu.flags.zf)
    {
        goto L_0x00481450;
    }
    // 0048140c  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048140f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481411  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00481414  e83d2e0000             -call 0x484256
    cpu.esp -= 4;
    sub_484256(app, cpu);
    // 00481419  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048141a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048141b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048141d  0f8430010000           -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 00481423  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481425  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481426  e8472e0000             -call 0x484272
    cpu.esp -= 4;
    sub_484272(app, cpu);
    // 0048142b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048142c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048142d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048142f  0f841e010000           -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 00481435  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00481438  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048143a  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048143d  83c108                 +add ecx, 8
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
    // 00481440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x00481441:
    // 00481441  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481442  e897010000             -call 0x4815de
    cpu.esp -= 4;
    sub_4815de(app, cpu);
    // 00481447  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481448  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481449  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048144b  e908010000             -jmp 0x481558
    goto L_0x00481558;
L_0x00481450:
    // 00481450  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00481453  f60601                 +test byte ptr [esi], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi) & 1 /*0x1*/));
    // 00481456  7452                   -je 0x4814aa
    if (cpu.flags.zf)
    {
        goto L_0x004814aa;
    }
    // 00481458  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048145b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048145d  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00481460  e8f12d0000             -call 0x484256
    cpu.esp -= 4;
    sub_484256(app, cpu);
    // 00481465  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481466  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481467  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481469  0f84e4000000           -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 0048146f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481472  e8fb2d0000             -call 0x484272
    cpu.esp -= 4;
    sub_484272(app, cpu);
    // 00481477  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481478  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481479  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048147b  0f84d2000000           -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 00481481  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00481484  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00481487  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481488  e8d3090000             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 0048148d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481490  837e1404               +cmp dword ptr [esi + 0x14], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481494  0f85be000000           -jne 0x481558
    if (!cpu.flags.zf)
    {
        goto L_0x00481558;
    }
    // 0048149a  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048149c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048149e  0f84b4000000           -je 0x481558
    if (cpu.flags.zf)
    {
        goto L_0x00481558;
    }
    // 004814a4  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004814a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004814a8  eb97                   -jmp 0x481441
    goto L_0x00481441;
L_0x004814aa:
    // 004814aa  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004814ae  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004814b1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004814b3  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004814b6  753a                   -jne 0x4814f2
    if (!cpu.flags.zf)
    {
        goto L_0x004814f2;
    }
    // 004814b8  e8992d0000             -call 0x484256
    cpu.esp -= 4;
    sub_484256(app, cpu);
    // 004814bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004814c1  0f848c000000           -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 004814c7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004814c9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004814ca  e8a32d0000             -call 0x484272
    cpu.esp -= 4;
    sub_484272(app, cpu);
    // 004814cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004814d3  747e                   -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 004814d5  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004814d8  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004814db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004814dc  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004814df  e8fa000000             -call 0x4815de
    cpu.esp -= 4;
    sub_4815de(app, cpu);
    // 004814e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004814e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004814e8  e873090000             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 004814ed  83c40c                 +add esp, 0xc
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
    // 004814f0  eb66                   -jmp 0x481558
    goto L_0x00481558;
L_0x004814f2:
    // 004814f2  e85f2d0000             -call 0x484256
    cpu.esp -= 4;
    sub_484256(app, cpu);
    // 004814f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004814fb  7456                   -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 004814fd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004814ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481500  e86d2d0000             -call 0x484272
    cpu.esp -= 4;
    sub_484272(app, cpu);
    // 00481505  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481506  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481507  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481509  7448                   -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 0048150b  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0048150e  e87b2d0000             -call 0x48428e
    cpu.esp -= 4;
    sub_48428e(app, cpu);
    // 00481513  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481514  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481516  743b                   -je 0x481553
    if (cpu.flags.zf)
    {
        goto L_0x00481553;
    }
    // 00481518  f60604                 +test byte ptr [esi], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi) & 4 /*0x4*/));
    // 0048151b  741c                   -je 0x481539
    if (cpu.flags.zf)
    {
        goto L_0x00481539;
    }
    // 0048151d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048151f  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00481522  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481523  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00481526  e8b3000000             -call 0x4815de
    cpu.esp -= 4;
    sub_4815de(app, cpu);
    // 0048152b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048152c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048152d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048152e  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00481531  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481532  e8868cffff             -call 0x47a1bd
    cpu.esp -= 4;
    sub_47a1bd(app, cpu);
    // 00481537  eb1f                   -jmp 0x481558
    goto L_0x00481558;
L_0x00481539:
    // 00481539  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048153c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048153d  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00481540  e899000000             -call 0x4815de
    cpu.esp -= 4;
    sub_4815de(app, cpu);
    // 00481545  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481546  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481547  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481548  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0048154b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048154c  e8658cffff             -call 0x47a1b6
    cpu.esp -= 4;
    sub_47a1b6(app, cpu);
    // 00481551  eb05                   -jmp 0x481558
    goto L_0x00481558;
L_0x00481553:
    // 00481553  e865010000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x00481558:
    // 00481558  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0048155c:
    // 0048155c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0048155f  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00481566  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481567  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481568  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481569  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048156a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48156b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048156b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048156d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048156e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48156f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048156f  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00481572  e9e5000000             -jmp 0x48165c
    return sub_48165c(app, cpu);
}

/* align: skip  */
void Application::sub_481577(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481577  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481578  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048157a  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0048157c  68b8854800             -push 0x4885b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752824 /*0x4885b8*/;
    cpu.esp -= 4;
    // 00481581  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 00481586  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0048158c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048158d  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00481594  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481595  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481596  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481597  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481598  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481599  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0048159c  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048159f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004815a1  741b                   -je 0x4815be
    if (cpu.flags.zf)
    {
        goto L_0x004815be;
    }
    // 004815a3  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004815a6  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004815a9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004815ab  7411                   -je 0x4815be
    if (cpu.flags.zf)
    {
        goto L_0x004815be;
    }
    // 004815ad  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004815b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004815b2  ff7018                 -push dword ptr [eax + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004815b5  e8fc8bffff             -call 0x47a1b6
    cpu.esp -= 4;
    sub_47a1b6(app, cpu);
    // 004815ba  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x004815be:
    // 004815be  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004815c1  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004815c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004815c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004815ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004815cb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004815cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4815cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004815cd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004815cf  38450c                 +cmp byte ptr [ebp + 0xc], al
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004815d2  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004815d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4815d6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004815d6  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004815d9  e97e000000             -jmp 0x48165c
    return sub_48165c(app, cpu);
}

/* align: skip  */
void Application::sub_4815de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004815de  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004815e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004815e3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004815e7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004815e9  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004815ec  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004815ee  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004815f0  7c0d                   -jl 0x4815ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004815ff;
    }
    // 004815f2  8b3432                 -mov esi, dword ptr [edx + esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1);
    // 004815f5  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004815f8  8b0c0e                 -mov ecx, dword ptr [esi + ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004815fb  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004815fd  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004815ff:
    // 004815ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481600  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__CallSettingFrame_12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481610  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481611  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481613  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481616  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481617  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481618  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048161b  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048161e  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00481621  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481624  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481625  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00481628  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048162b  8b6dfc                 -mov ebp, dword ptr [ebp - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048162e  e8f285ffff             -call 0x479c25
    cpu.esp -= 4;
    __NLG_Notify1(app, cpu);
    // 00481633  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481634  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481635  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00481637  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481638  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481639  8bdd                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048163b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048163c  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048163f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481640  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00481642  81f900010000           +cmp ecx, 0x100
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
    // 00481648  7505                   -jne 0x48164f
    if (!cpu.flags.zf)
    {
        goto L_0x0048164f;
    }
    // 0048164a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x0048164f:
    // 0048164f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481650  e8d085ffff             -call 0x479c25
    cpu.esp -= 4;
    __NLG_Notify1(app, cpu);
    // 00481655  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481656  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481657  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481658  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481659  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_48165c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048165c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048165d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048165f  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00481661  68c8854800             -push 0x4885c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752840 /*0x4885c8*/;
    cpu.esp -= 4;
    // 00481666  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0048166b  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00481671  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481672  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00481679  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048167a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048167b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048167c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048167d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048167e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00481681  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00481683  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00481686  e8dc9dffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 0048168b  397060                 +cmp dword ptr [eax + 0x60], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048168e  741f                   -je 0x4816af
    if (cpu.flags.zf)
    {
        return sub_4816af(app, cpu);
    }
    // 00481690  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00481697  e8cb9dffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 0048169c  ff5060                 -call dword ptr [eax + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048169f  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004816a2  eb0b                   -jmp 0x4816af
    return sub_4816af(app, cpu);
}

/* align: skip  */
void Application::sub_4816a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816a4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004816a6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004816a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4816a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816a8  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004816ab  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004816af  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004816b3  e800000000             -call 0x4816b8
    cpu.esp -= 4;
    sub_4816b8(app, cpu);
    // 004816b8  e9e92b0000             -jmp 0x4842a6
    return sub_4842a6(app, cpu);
}

/* align: skip  */
void Application::sub_4816b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004816b8;
    // 004816a8  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004816ab  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004816af  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004816b3  e800000000             -call 0x4816b8
    cpu.esp -= 4;
    sub_4816b8(app, cpu);
L_entry_0x004816b8:
    // 004816b8  e9e92b0000             -jmp 0x4842a6
    return sub_4842a6(app, cpu);
}

/* align: skip  */
void Application::sub_4816af(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004816af;
    // 004816a8  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004816ab  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_entry_0x004816af:
    // 004816af  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004816b3  e800000000             -call 0x4816b8
    cpu.esp -= 4;
    sub_4816b8(app, cpu);
    // 004816b8  e9e92b0000             -jmp 0x4842a6
    return sub_4842a6(app, cpu);
}

/* align: skip  */
void Application::sub_4816bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816bd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004816be  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004816c0  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004816c2  68e0854800             -push 0x4885e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752864 /*0x4885e0*/;
    cpu.esp -= 4;
    // 004816c7  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 004816cc  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004816d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004816d3  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004816da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004816db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004816dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004816dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004816de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004816df  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004816e2  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004816e6  a1d0684a00             -mov eax, dword ptr [0x4a68d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876496) /* 0x4a68d0 */);
    // 004816eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004816ed  7416                   -je 0x481705
    if (cpu.flags.zf)
    {
        return sub_481705(app, cpu);
    }
    // 004816ef  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 004816f6  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004816f8  eb07                   -jmp 0x481701
    return sub_481701(app, cpu);
}

/* align: skip  */
void Application::sub_4816fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816fa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004816fc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004816fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4816fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816fe  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00481701  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481705  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00481709  e800000000             -call 0x48170e
    cpu.esp -= 4;
    sub_48170e(app, cpu);
    // 0048170e  e949ffffff             -jmp 0x48165c
    return sub_48165c(app, cpu);
}

/* align: skip  */
void Application::sub_48170e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048170e;
    // 004816fe  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00481701  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481705  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00481709  e800000000             -call 0x48170e
    cpu.esp -= 4;
    sub_48170e(app, cpu);
L_entry_0x0048170e:
    // 0048170e  e949ffffff             -jmp 0x48165c
    return sub_48165c(app, cpu);
}

/* align: skip  */
void Application::sub_481705(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00481705;
    // 004816fe  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00481701  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_entry_0x00481705:
    // 00481705  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00481709  e800000000             -call 0x48170e
    cpu.esp -= 4;
    sub_48170e(app, cpu);
    // 0048170e  e949ffffff             -jmp 0x48165c
    return sub_48165c(app, cpu);
}

/* align: skip  */
void Application::sub_481701(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00481701;
    // 004816fe  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
L_entry_0x00481701:
    // 00481701  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481705  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00481709  e800000000             -call 0x48170e
    cpu.esp -= 4;
    sub_48170e(app, cpu);
    // 0048170e  e949ffffff             -jmp 0x48165c
    return sub_48165c(app, cpu);
}

/* align: skip  */
void Application::_memset(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481720  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00481724  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481728  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048172a  7447                   -je 0x481773
    if (cpu.flags.zf)
    {
        goto L_0x00481773;
    }
    // 0048172c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048172e  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481732  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481733  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00481735  83fa04                 +cmp edx, 4
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
    // 00481738  722d                   -jb 0x481767
    if (cpu.flags.cf)
    {
        goto L_0x00481767;
    }
    // 0048173a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048173c  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0048173f  7408                   -je 0x481749
    if (cpu.flags.zf)
    {
        goto L_0x00481749;
    }
    // 00481741  2bd1                   +sub edx, ecx
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
L_0x00481743:
    // 00481743  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00481745  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00481746  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481747  75fa                   -jne 0x481743
    if (!cpu.flags.zf)
    {
        goto L_0x00481743;
    }
L_0x00481749:
    // 00481749  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048174b  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0048174e  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00481750  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481752  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00481755  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00481757  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00481759  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048175c  c1e902                 +shr ecx, 2
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
    // 0048175f  7406                   -je 0x481767
    if (cpu.flags.zf)
    {
        goto L_0x00481767;
    }
    // 00481761  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00481763  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481765  7406                   -je 0x48176d
    if (cpu.flags.zf)
    {
        goto L_0x0048176d;
    }
L_0x00481767:
    // 00481767  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00481769  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048176a  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048176b  75fa                   -jne 0x481767
    if (!cpu.flags.zf)
    {
        goto L_0x00481767;
    }
L_0x0048176d:
    // 0048176d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481771  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481772  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481773:
    // 00481773  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481777  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481778(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481778  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481779  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048177b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048177c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048177d  9b                     -wait 
    /*nothing*/;
    // 0048177e  d97dfc                 -fnstcw word ptr [ebp - 4]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.control.word;
    // 00481781  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00481784  e83a000000             -call 0x4817c3
    cpu.esp -= 4;
    sub_4817c3(app, cpu);
    // 00481789  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048178b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048178e  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00481790  23f0                   -and esi, eax
    cpu.esi &= x86::reg32(x86::sreg32(cpu.eax));
    // 00481792  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481795  23450c                 -and eax, dword ptr [ebp + 0xc]
    cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00481798  0bf0                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048179a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048179b  e8b5000000             -call 0x481855
    cpu.esp -= 4;
    sub_481855(app, cpu);
    // 004817a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817a1  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004817a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817a5  d96d0c                 -fldcw word ptr [ebp + 0xc]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004817a8  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004817aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817ab  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4817ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004817ad  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004817b1  25fffff7ff             -and eax, 0xfff7ffff
    cpu.eax &= x86::reg32(x86::sreg32(4294443007 /*0xfff7ffff*/));
    // 004817b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004817b7  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004817bb  e8b8ffffff             -call 0x481778
    cpu.esp -= 4;
    sub_481778(app, cpu);
    // 004817c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4817c3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004817c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004817c4  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004817c8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004817ca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004817cb  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004817ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004817cf  7403                   -je 0x4817d4
    if (cpu.flags.zf)
    {
        goto L_0x004817d4;
    }
    // 004817d1  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004817d3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004817d4:
    // 004817d4  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004817d7  7402                   -je 0x4817db
    if (cpu.flags.zf)
    {
        goto L_0x004817db;
    }
    // 004817d9  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004817db:
    // 004817db  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004817de  7402                   -je 0x4817e2
    if (cpu.flags.zf)
    {
        goto L_0x004817e2;
    }
    // 004817e0  0c04                   -or al, 4
    cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004817e2:
    // 004817e2  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 004817e5  7402                   -je 0x4817e9
    if (cpu.flags.zf)
    {
        goto L_0x004817e9;
    }
    // 004817e7  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004817e9:
    // 004817e9  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004817ec  7402                   -je 0x4817f0
    if (cpu.flags.zf)
    {
        goto L_0x004817f0;
    }
    // 004817ee  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004817f0:
    // 004817f0  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004817f3  7405                   -je 0x4817fa
    if (cpu.flags.zf)
    {
        goto L_0x004817fa;
    }
    // 004817f5  0d00000800             -or eax, 0x80000
    cpu.eax |= x86::reg32(x86::sreg32(524288 /*0x80000*/));
L_0x004817fa:
    // 004817fa  0fb7cb                 -movzx ecx, bx
    cpu.ecx = x86::reg32(cpu.bx);
    // 004817fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004817fe  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00481800  be000c0000             -mov esi, 0xc00
    cpu.esi = 3072 /*0xc00*/;
    // 00481805  bf00030000             -mov edi, 0x300
    cpu.edi = 768 /*0x300*/;
    // 0048180a  23d6                   +and edx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(cpu.esi))));
    // 0048180c  bd00020000             -mov ebp, 0x200
    cpu.ebp = 512 /*0x200*/;
    // 00481811  741f                   -je 0x481832
    if (cpu.flags.zf)
    {
        goto L_0x00481832;
    }
    // 00481813  81fa00040000           +cmp edx, 0x400
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
    // 00481819  7414                   -je 0x48182f
    if (cpu.flags.zf)
    {
        goto L_0x0048182f;
    }
    // 0048181b  81fa00080000           +cmp edx, 0x800
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
    // 00481821  7408                   -je 0x48182b
    if (cpu.flags.zf)
    {
        goto L_0x0048182b;
    }
    // 00481823  3bd6                   +cmp edx, esi
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
    // 00481825  750b                   -jne 0x481832
    if (!cpu.flags.zf)
    {
        goto L_0x00481832;
    }
    // 00481827  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00481829  eb07                   -jmp 0x481832
    goto L_0x00481832;
L_0x0048182b:
    // 0048182b  0bc5                   +or eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0048182d  eb03                   -jmp 0x481832
    goto L_0x00481832;
L_0x0048182f:
    // 0048182f  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00481832:
    // 00481832  23cf                   +and ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.edi))));
    // 00481834  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481835  740b                   -je 0x481842
    if (cpu.flags.zf)
    {
        goto L_0x00481842;
    }
    // 00481837  3bcd                   +cmp ecx, ebp
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
    // 00481839  750c                   -jne 0x481847
    if (!cpu.flags.zf)
    {
        goto L_0x00481847;
    }
    // 0048183b  0d00000100             +or eax, 0x10000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(65536 /*0x10000*/))));
    // 00481840  eb05                   -jmp 0x481847
    goto L_0x00481847;
L_0x00481842:
    // 00481842  0d00000200             -or eax, 0x20000
    cpu.eax |= x86::reg32(x86::sreg32(131072 /*0x20000*/));
L_0x00481847:
    // 00481847  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481848  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481849  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 0048184c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048184d  7405                   -je 0x481854
    if (cpu.flags.zf)
    {
        goto L_0x00481854;
    }
    // 0048184f  0d00000400             -or eax, 0x40000
    cpu.eax |= x86::reg32(x86::sreg32(262144 /*0x40000*/));
L_0x00481854:
    // 00481854  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481855(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481855  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481856  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048185a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048185c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048185d  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00481860  7403                   -je 0x481865
    if (cpu.flags.zf)
    {
        goto L_0x00481865;
    }
    // 00481862  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481864  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481865:
    // 00481865  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00481868  7402                   -je 0x48186c
    if (cpu.flags.zf)
    {
        goto L_0x0048186c;
    }
    // 0048186a  0c04                   -or al, 4
    cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0048186c:
    // 0048186c  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0048186f  7402                   -je 0x481873
    if (cpu.flags.zf)
    {
        goto L_0x00481873;
    }
    // 00481871  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00481873:
    // 00481873  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00481876  7402                   -je 0x48187a
    if (cpu.flags.zf)
    {
        goto L_0x0048187a;
    }
    // 00481878  0c10                   -or al, 0x10
    cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0048187a:
    // 0048187a  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0048187d  7402                   -je 0x481881
    if (cpu.flags.zf)
    {
        goto L_0x00481881;
    }
    // 0048187f  0c20                   -or al, 0x20
    cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00481881:
    // 00481881  f7c300000800           +test ebx, 0x80000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 524288 /*0x80000*/));
    // 00481887  7402                   -je 0x48188b
    if (cpu.flags.zf)
    {
        goto L_0x0048188b;
    }
    // 00481889  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0048188b:
    // 0048188b  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048188d  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 00481892  23ca                   +and ecx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00481894  be00020000             -mov esi, 0x200
    cpu.esi = 512 /*0x200*/;
    // 00481899  741d                   -je 0x4818b8
    if (cpu.flags.zf)
    {
        goto L_0x004818b8;
    }
    // 0048189b  81f900010000           +cmp ecx, 0x100
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
    // 004818a1  7412                   -je 0x4818b5
    if (cpu.flags.zf)
    {
        goto L_0x004818b5;
    }
    // 004818a3  3bce                   +cmp ecx, esi
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
    // 004818a5  7409                   -je 0x4818b0
    if (cpu.flags.zf)
    {
        goto L_0x004818b0;
    }
    // 004818a7  3bca                   +cmp ecx, edx
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
    // 004818a9  750d                   -jne 0x4818b8
    if (!cpu.flags.zf)
    {
        goto L_0x004818b8;
    }
    // 004818ab  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 004818ae  eb08                   -jmp 0x4818b8
    goto L_0x004818b8;
L_0x004818b0:
    // 004818b0  80cc08                 +or ah, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004818b3  eb03                   -jmp 0x4818b8
    goto L_0x004818b8;
L_0x004818b5:
    // 004818b5  80cc04                 -or ah, 4
    cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004818b8:
    // 004818b8  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004818ba  81e100000300           +and ecx, 0x30000
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(196608 /*0x30000*/))));
    // 004818c0  740c                   -je 0x4818ce
    if (cpu.flags.zf)
    {
        goto L_0x004818ce;
    }
    // 004818c2  81f900000100           +cmp ecx, 0x10000
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
    // 004818c8  7506                   -jne 0x4818d0
    if (!cpu.flags.zf)
    {
        goto L_0x004818d0;
    }
    // 004818ca  0bc6                   +or eax, esi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.esi))));
    // 004818cc  eb02                   -jmp 0x4818d0
    goto L_0x004818d0;
L_0x004818ce:
    // 004818ce  0bc2                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x004818d0:
    // 004818d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818d1  f7c300000400           +test ebx, 0x40000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 262144 /*0x40000*/));
    // 004818d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818d8  7403                   -je 0x4818dd
    if (cpu.flags.zf)
    {
        goto L_0x004818dd;
    }
    // 004818da  80cc10                 -or ah, 0x10
    cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x004818dd:
    // 004818dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4818de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818de  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004818e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004818e3  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004818e5  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004818e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818e7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004818e9  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 004818eb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004818ed  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004818f1  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004818f2  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004818f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818f5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004818f9  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004818fb  83caff                 -or edx, 0xffffffff
    cpu.edx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004818fe  d3e2                   +shl edx, cl
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
    // 00481900  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00481902  8514b0                 -test dword ptr [eax + esi*4], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4) & cpu.edx));
    // 00481905  751c                   -jne 0x481923
    if (!cpu.flags.zf)
    {
        goto L_0x00481923;
    }
    // 00481907  46                     -inc esi
    (cpu.esi)++;
    // 00481908  83fe03                 +cmp esi, 3
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
    // 0048190b  7d11                   -jge 0x48191e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048191e;
    }
    // 0048190d  8d04b0                 -lea eax, [eax + esi*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.esi * 4);
L_0x00481910:
    // 00481910  833800                 +cmp dword ptr [eax], 0
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
    // 00481913  750e                   -jne 0x481923
    if (!cpu.flags.zf)
    {
        goto L_0x00481923;
    }
    // 00481915  46                     -inc esi
    (cpu.esi)++;
    // 00481916  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481919  83fe03                 +cmp esi, 3
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
    // 0048191c  7cf2                   -jl 0x481910
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481910;
    }
L_0x0048191e:
    // 0048191e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481920  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481921  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481922  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481923:
    // 00481923  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481925  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481926  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481927(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481927  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048192b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048192c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048192d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048192e  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00481930  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00481934  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00481935  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481936  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00481938  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048193a  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048193e  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0048193f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00481941  8d3cb3                 -lea edi, [ebx + esi*4]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 4);
    // 00481944  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481945  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 00481947  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481948  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048194a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048194b  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048194d  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048194f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481950  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 00481952  e8252b0000             -call 0x48447c
    cpu.esp -= 4;
    sub_48447c(app, cpu);
    // 00481957  83c40c                 +add esp, 0xc
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
    // 0048195a  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048195b  781c                   -js 0x481979
    if (cpu.flags.sf)
    {
        goto L_0x00481979;
    }
    // 0048195d  8d3cb3                 -lea edi, [ebx + esi*4]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 4);
L_0x00481960:
    // 00481960  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481962  7415                   -je 0x481979
    if (cpu.flags.zf)
    {
        goto L_0x00481979;
    }
    // 00481964  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481965  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481967  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 00481969  e80e2b0000             -call 0x48447c
    cpu.esp -= 4;
    sub_48447c(app, cpu);
    // 0048196e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481971  4e                     -dec esi
    (cpu.esi)--;
    // 00481972  83ef04                 -sub edi, 4
    (cpu.edi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481975  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00481977  7de7                   -jge 0x481960
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481960;
    }
L_0x00481979:
    // 00481979  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048197a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048197b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048197c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48197d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048197d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048197e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481981  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481982  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481985  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481986  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481987  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481988  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0048198b  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0048198d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048198e  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481992  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00481995  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00481997  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481999  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048199a  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0048199b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048199d  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 0048199f  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004819a1  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004819a3  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004819a4  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004819a6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004819a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819aa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004819ac  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 004819af  8d0488                 -lea eax, [eax + ecx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 004819b2  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004819b5  2bf2                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004819b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819b8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004819ba  d3e2                   +shl edx, cl
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
    // 004819bc  8510                   -test dword ptr [eax], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax) & cpu.edx));
    // 004819be  7421                   -je 0x4819e1
    if (cpu.flags.zf)
    {
        goto L_0x004819e1;
    }
    // 004819c0  43                     -inc ebx
    (cpu.ebx)++;
    // 004819c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004819c2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004819c5  e814ffffff             -call 0x4818de
    cpu.esp -= 4;
    sub_4818de(app, cpu);
    // 004819ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004819cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819ce  750e                   -jne 0x4819de
    if (!cpu.flags.zf)
    {
        goto L_0x004819de;
    }
    // 004819d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004819d1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004819d4  e84effffff             -call 0x481927
    cpu.esp -= 4;
    sub_481927(app, cpu);
    // 004819d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819da  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004819dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004819de:
    // 004819de  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004819e1:
    // 004819e1  83caff                 -or edx, 0xffffffff
    cpu.edx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004819e4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004819e6  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004819e8  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004819ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819eb  2110                   -and dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(cpu.edx));
    // 004819ed  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004819f0  40                     -inc eax
    (cpu.eax)++;
    // 004819f1  3bc1                   +cmp eax, ecx
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
    // 004819f3  7d0c                   -jge 0x481a01
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481a01;
    }
    // 004819f5  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004819f8  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004819fa  8d3c82                 -lea edi, [edx + eax*4]
    cpu.edi = x86::reg32(cpu.edx + cpu.eax * 4);
    // 004819fd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004819ff  f3ab                   -rep stosd dword ptr es:[edi], eax
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
L_0x00481a01:
    // 00481a01  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00481a04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a07  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481a09(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481a09  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481a0d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481a11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481a12  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00481a14  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00481a16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481a17:
    // 00481a17  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00481a19  893401                 -mov dword ptr [ecx + eax], esi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.esi;
    // 00481a1c  83c004                 +add eax, 4
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
    // 00481a1f  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481a20  75f5                   -jne 0x481a17
    if (!cpu.flags.zf)
    {
        goto L_0x00481a17;
    }
    // 00481a22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481a24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481a24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481a25  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481a29  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481a2b  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00481a2c  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00481a2d  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00481a2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481a30  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481a34  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00481a36:
    // 00481a36  833800                 +cmp dword ptr [eax], 0
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
    // 00481a39  750d                   -jne 0x481a48
    if (!cpu.flags.zf)
    {
        goto L_0x00481a48;
    }
    // 00481a3b  41                     -inc ecx
    (cpu.ecx)++;
    // 00481a3c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481a3f  83f903                 +cmp ecx, 3
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
    // 00481a42  7cf2                   -jl 0x481a36
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481a36;
    }
    // 00481a44  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481a46  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481a48:
    // 00481a48  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481a4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481a4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481a4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481a4c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481a4e  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481a51  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481a54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481a55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481a56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481a57  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00481a59  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481a5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481a5d  83ceff                 -or esi, 0xffffffff
    cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00481a60  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00481a61  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481a63  c745fc03000000         -mov dword ptr [ebp - 4], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 3 /*0x3*/;
    // 00481a6a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00481a6c  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00481a6f  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481a72  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00481a73  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00481a75  83650c00               -and dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481a79  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00481a7b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 00481a7d  2bda                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00481a7f  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
L_0x00481a81:
    // 00481a81  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00481a83  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481a85  23ce                   -and ecx, esi
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.esi));
    // 00481a87  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00481a8a  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00481a8c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00481a8e  0b450c                 -or eax, dword ptr [ebp + 0xc]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00481a91  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00481a93  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00481a96  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481a98  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481a9b  d3e0                   +shl eax, cl
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
    // 00481a9d  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481aa0  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00481aa3  75dc                   -jne 0x481a81
    if (!cpu.flags.zf)
    {
        goto L_0x00481a81;
    }
    // 00481aa5  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481aa8  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00481aaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481aab  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00481aad  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00481aaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ab0  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
L_0x00481ab3:
    // 00481ab3  3bdf                   +cmp ebx, edi
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
    // 00481ab5  7c0f                   -jl 0x481ac6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481ac6;
    }
    // 00481ab7  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481aba  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481abc  2bc6                   +sub eax, esi
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
    // 00481abe  8b0410                 -mov eax, dword ptr [eax + edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 1);
    // 00481ac1  890411                 -mov dword ptr [ecx + edx], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.eax;
    // 00481ac4  eb07                   -jmp 0x481acd
    goto L_0x00481acd;
L_0x00481ac6:
    // 00481ac6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481ac9  83240100               -and dword ptr [ecx + eax], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00481acd:
    // 00481acd  4b                     -dec ebx
    (cpu.ebx)--;
    // 00481ace  83e904                 +sub ecx, 4
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
    // 00481ad1  79e0                   -jns 0x481ab3
    if (!cpu.flags.sf)
    {
        goto L_0x00481ab3;
    }
    // 00481ad3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ad4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ad5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ad6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ad7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481ad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481ad8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481ad9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481adb  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00481ade  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481ae1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481ae2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481ae3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481ae4  0fb7480a               -movzx ecx, word ptr [eax + 0xa]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */));
    // 00481ae8  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00481aea  81e100800000           -and ecx, 0x8000
    cpu.ecx &= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00481af0  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00481af3  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00481af6  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00481af9  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00481afc  0fb700                 -movzx eax, word ptr [eax]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.eax));
    // 00481aff  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00481b02  81e3ff7f0000           -and ebx, 0x7fff
    cpu.ebx &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 00481b08  81ebff3f0000           -sub ebx, 0x3fff
    (cpu.ebx) -= x86::reg32(x86::sreg32(16383 /*0x3fff*/));
    // 00481b0e  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00481b11  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00481b14  81fb01c0ffff           +cmp ebx, 0xffffc001
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
    // 00481b1a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00481b1d  7526                   -jne 0x481b45
    if (!cpu.flags.zf)
    {
        goto L_0x00481b45;
    }
    // 00481b1f  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481b22  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00481b24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b25  e806ffffff             -call 0x481a30
    cpu.esp -= 4;
    sub_481a30(app, cpu);
    // 00481b2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481b2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b2d  0f85d1000000           -jne 0x481c04
    if (!cpu.flags.zf)
    {
        goto L_0x00481c04;
    }
    // 00481b33  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481b36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b37  e8e8feffff             -call 0x481a24
    cpu.esp -= 4;
    sub_481a24(app, cpu);
    // 00481b3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481b3d:
    // 00481b3d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
L_0x00481b3f:
    // 00481b3f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b40  e9c1000000             -jmp 0x481c06
    goto L_0x00481c06;
L_0x00481b45:
    // 00481b45  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481b48  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b49  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00481b4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b4d  e8b7feffff             -call 0x481a09
    cpu.esp -= 4;
    sub_481a09(app, cpu);
    // 00481b52  ff7708                 -push dword ptr [edi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00481b55  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481b58  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b59  e81ffeffff             -call 0x48197d
    cpu.esp -= 4;
    sub_48197d(app, cpu);
    // 00481b5e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481b61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481b63  7401                   -je 0x481b66
    if (cpu.flags.zf)
    {
        goto L_0x00481b66;
    }
    // 00481b65  43                     -inc ebx
    (cpu.ebx)++;
L_0x00481b66:
    // 00481b66  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00481b69  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481b6b  2b4f08                 -sub ecx, dword ptr [edi + 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00481b6e  3bd9                   +cmp ebx, ecx
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
    // 00481b70  7d0c                   -jge 0x481b7e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481b7e;
    }
    // 00481b72  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481b75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b76  e8a9feffff             -call 0x481a24
    cpu.esp -= 4;
    sub_481a24(app, cpu);
    // 00481b7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b7c  eb3c                   -jmp 0x481bba
    goto L_0x00481bba;
L_0x00481b7e:
    // 00481b7e  3bd8                   +cmp ebx, eax
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
    // 00481b80  7f3f                   -jg 0x481bc1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00481bc1;
    }
    // 00481b82  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481b84  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481b86  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00481b89  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b8a  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481b8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b8e  e876feffff             -call 0x481a09
    cpu.esp -= 4;
    sub_481a09(app, cpu);
    // 00481b93  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481b96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481b97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b98  e8aefeffff             -call 0x481a4b
    cpu.esp -= 4;
    sub_481a4b(app, cpu);
    // 00481b9d  ff7708                 -push dword ptr [edi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00481ba0  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481ba3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481ba4  e8d4fdffff             -call 0x48197d
    cpu.esp -= 4;
    sub_48197d(app, cpu);
    // 00481ba9  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00481bac  40                     -inc eax
    (cpu.eax)++;
    // 00481bad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481bae  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481bb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481bb2  e894feffff             -call 0x481a4b
    cpu.esp -= 4;
    sub_481a4b(app, cpu);
    // 00481bb7  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00481bba:
    // 00481bba  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00481bbc  e97cffffff             -jmp 0x481b3d
    goto L_0x00481b3d;
L_0x00481bc1:
    // 00481bc1  3b1f                   +cmp ebx, dword ptr [edi]
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
    // 00481bc3  7c28                   -jl 0x481bed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481bed;
    }
    // 00481bc5  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481bc8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481bc9  e856feffff             -call 0x481a24
    cpu.esp -= 4;
    sub_481a24(app, cpu);
    // 00481bce  ff770c                 -push dword ptr [edi + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481bd1  804df780               -or byte ptr [ebp - 9], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-9) /* -0x9 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00481bd5  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481bd8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481bd9  e86dfeffff             -call 0x481a4b
    cpu.esp -= 4;
    sub_481a4b(app, cpu);
    // 00481bde  8b7714                 -mov esi, dword ptr [edi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00481be1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481be4  0337                   +add esi, dword ptr [edi]
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
    // 00481be6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481be8  e952ffffff             -jmp 0x481b3f
    goto L_0x00481b3f;
L_0x00481bed:
    // 00481bed  ff770c                 -push dword ptr [edi + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481bf0  8b7714                 -mov esi, dword ptr [edi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00481bf3  8065f77f               -and byte ptr [ebp - 9], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-9) /* -0x9 */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00481bf7  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481bfa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481bfb  03f3                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00481bfd  e849feffff             -call 0x481a4b
    cpu.esp -= 4;
    sub_481a4b(app, cpu);
    // 00481c02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481c04:
    // 00481c04  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00481c06:
    // 00481c06  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 00481c08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c09  2b4f0c                 -sub ecx, dword ptr [edi + 0xc]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 00481c0c  8b7f10                 -mov edi, dword ptr [edi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00481c0f  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 00481c11  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481c14  f7d9                   +neg ecx
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
    // 00481c16  1bc9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00481c18  81e100000080           -and ecx, 0x80000000
    cpu.ecx &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00481c1e  0bf1                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481c20  0b75f4                 -or esi, dword ptr [ebp - 0xc]
    cpu.esi |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00481c23  83ff40                 +cmp edi, 0x40
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
    // 00481c26  750d                   -jne 0x481c35
    if (!cpu.flags.zf)
    {
        goto L_0x00481c35;
    }
    // 00481c28  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481c2b  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00481c2e  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00481c31  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00481c33  eb0a                   -jmp 0x481c3f
    goto L_0x00481c3f;
L_0x00481c35:
    // 00481c35  83ff20                 +cmp edi, 0x20
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
    // 00481c38  7505                   -jne 0x481c3f
    if (!cpu.flags.zf)
    {
        goto L_0x00481c3f;
    }
    // 00481c3a  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481c3d  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
L_0x00481c3f:
    // 00481c3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c42  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481c44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c44  68e0684a00             -push 0x4a68e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4876512 /*0x4a68e0*/;
    cpu.esp -= 4;
    // 00481c49  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481c4d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481c51  e882feffff             -call 0x481ad8
    cpu.esp -= 4;
    sub_481ad8(app, cpu);
    // 00481c56  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481c59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481c5a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c5a  68f8684a00             -push 0x4a68f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4876536 /*0x4a68f8*/;
    cpu.esp -= 4;
    // 00481c5f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481c63  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481c67  e86cfeffff             -call 0x481ad8
    cpu.esp -= 4;
    sub_481ad8(app, cpu);
    // 00481c6c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481c6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c70  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481c71  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481c73  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481c76  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481c78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481c79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481c7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481c7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481c7c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481c7f  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481c82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481c83  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481c86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481c87  e8d61b0000             -call 0x483862
    cpu.esp -= 4;
    sub_483862(app, cpu);
    // 00481c8c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00481c8f  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481c92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481c93  e8acffffff             -call 0x481c44
    cpu.esp -= 4;
    sub_481c44(app, cpu);
    // 00481c98  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00481c9b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481c9d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c9d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481c9e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481ca0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481ca3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481ca5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481ca6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481ca7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481ca8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481ca9  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481cac  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481caf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481cb0  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481cb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481cb4  e8a91b0000             -call 0x483862
    cpu.esp -= 4;
    sub_483862(app, cpu);
    // 00481cb9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00481cbc  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481cbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481cc0  e895ffffff             -call 0x481c5a
    cpu.esp -= 4;
    sub_481c5a(app, cpu);
    // 00481cc5  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00481cc8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481cc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481cca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481cca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481ccb  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481ccd  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00481cd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481cd1  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481cd4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481cd5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481cd8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00481cdb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481cdc  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00481cdf  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00481ce2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481ce4  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00481ce6  7e1f                   -jle 0x481d07
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481d07;
    }
    // 00481ce8  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00481ceb  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00481ced:
    // 00481ced  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00481cef  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00481cf1  7406                   -je 0x481cf9
    if (cpu.flags.zf)
    {
        goto L_0x00481cf9;
    }
    // 00481cf3  0fbed2                 -movsx edx, dl
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 00481cf6  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00481cf7  eb03                   -jmp 0x481cfc
    goto L_0x00481cfc;
L_0x00481cf9:
    // 00481cf9  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00481cfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481cfc:
    // 00481cfc  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00481cfe  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00481cff  ff4d08                 +dec dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00481d02  75e9                   -jne 0x481ced
    if (!cpu.flags.zf)
    {
        goto L_0x00481ced;
    }
    // 00481d04  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x00481d07:
    // 00481d07  802000                 -and byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00481d0a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481d0c  7c12                   -jl 0x481d20
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481d20;
    }
    // 00481d0e  803935                 +cmp byte ptr [ecx], 0x35
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
    // 00481d11  7c0d                   -jl 0x481d20
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481d20;
    }
L_0x00481d13:
    // 00481d13  48                     -dec eax
    (cpu.eax)--;
    // 00481d14  803839                 +cmp byte ptr [eax], 0x39
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
    // 00481d17  7505                   -jne 0x481d1e
    if (!cpu.flags.zf)
    {
        goto L_0x00481d1e;
    }
    // 00481d19  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 00481d1c  ebf5                   -jmp 0x481d13
    goto L_0x00481d13;
L_0x00481d1e:
    // 00481d1e  fe00                   -inc byte ptr [eax]
    (app->getMemory<x86::reg8>(cpu.eax))++;
L_0x00481d20:
    // 00481d20  803e31                 +cmp byte ptr [esi], 0x31
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
    // 00481d23  7505                   -jne 0x481d2a
    if (!cpu.flags.zf)
    {
        goto L_0x00481d2a;
    }
    // 00481d25  ff4204                 +inc dword ptr [edx + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00481d28  eb12                   -jmp 0x481d3c
    goto L_0x00481d3c;
L_0x00481d2a:
    // 00481d2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481d2b  e8b0c0ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00481d30  40                     -inc eax
    (cpu.eax)++;
    // 00481d31  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481d32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481d33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481d34  e827010000             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 00481d39  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00481d3c:
    // 00481d3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481d41(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481d41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481d42  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481d44  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00481d47  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481d48  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481d4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481d4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481d4d  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481d50  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481d51  e847000000             -call 0x481d9d
    cpu.esp -= 4;
    sub_481d9d(app, cpu);
    // 00481d56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d57  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00481d5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d5b  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00481d5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481d5f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481d61  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00481d63  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481d66  8bfc                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00481d68  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00481d69  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00481d6a  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 00481d6c  e8ac280000             -call 0x48461d
    cpu.esp -= 4;
    sub_48461d(app, cpu);
    // 00481d71  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00481d74  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00481d77  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00481d7a  0fbe45da               -movsx eax, byte ptr [ebp - 0x26]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-38) /* -0x26 */)));
    // 00481d7e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00481d80  0fbf45d8               -movsx eax, word ptr [ebp - 0x28]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 00481d84  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00481d87  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00481d8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481d8b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481d8c  e89fd4ffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00481d91  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00481d94  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00481d97  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481d99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d9b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481d9d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481d9d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481d9e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481da1  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481da4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481da5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481da6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481da7  668b4206               -mov ax, word ptr [edx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00481dab  bfff070000             -mov edi, 0x7ff
    cpu.edi = 2047 /*0x7ff*/;
    // 00481db0  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481db2  2500800000             -and eax, 0x8000
    cpu.eax &= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00481db7  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 00481dba  23cf                   -and ecx, edi
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edi));
    // 00481dbc  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00481dbf  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00481dc2  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00481dc4  0fb7d9                 -movzx ebx, cx
    cpu.ebx = x86::reg32(cpu.cx);
    // 00481dc7  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 00481dcc  25ffff0f00             -and eax, 0xfffff
    cpu.eax &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00481dd1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481dd3  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00481dd6  7413                   -je 0x481deb
    if (cpu.flags.zf)
    {
        goto L_0x00481deb;
    }
    // 00481dd8  3bdf                   +cmp ebx, edi
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
    // 00481dda  7408                   -je 0x481de4
    if (cpu.flags.zf)
    {
        goto L_0x00481de4;
    }
    // 00481ddc  8db9003c0000           -lea edi, [ecx + 0x3c00]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(15360) /* 0x3c00 */);
    // 00481de2  eb28                   -jmp 0x481e0c
    goto L_0x00481e0c;
L_0x00481de4:
    // 00481de4  bfff7f0000             -mov edi, 0x7fff
    cpu.edi = 32767 /*0x7fff*/;
    // 00481de9  eb21                   -jmp 0x481e0c
    goto L_0x00481e0c;
L_0x00481deb:
    // 00481deb  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481ded  3bc3                   +cmp eax, ebx
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
    // 00481def  7512                   -jne 0x481e03
    if (!cpu.flags.zf)
    {
        goto L_0x00481e03;
    }
    // 00481df1  3bd3                   +cmp edx, ebx
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
    // 00481df3  750e                   -jne 0x481e03
    if (!cpu.flags.zf)
    {
        goto L_0x00481e03;
    }
    // 00481df5  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481df8  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00481dfb  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00481dfd  66895808               -mov word ptr [eax + 8], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 00481e01  eb4b                   -jmp 0x481e4e
    goto L_0x00481e4e;
L_0x00481e03:
    // 00481e03  8db9013c0000           -lea edi, [ecx + 0x3c01]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(15361) /* 0x3c01 */);
    // 00481e09  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
L_0x00481e0c:
    // 00481e0c  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00481e0e  c1e915                 -shr ecx, 0x15
    cpu.ecx >>= 21 /*0x15*/ % 32;
    // 00481e11  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 00481e14  0bc8                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00481e16  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481e19  0b4dfc                 -or ecx, dword ptr [ebp - 4]
    cpu.ecx |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00481e1c  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 00481e1f  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00481e22  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00481e24:
    // 00481e24  85ce                   +test esi, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.ecx));
    // 00481e26  751d                   -jne 0x481e45
    if (!cpu.flags.zf)
    {
        goto L_0x00481e45;
    }
    // 00481e28  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00481e2a  03c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00481e2c  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00481e2e  c1eb1f                 -shr ebx, 0x1f
    cpu.ebx >>= 31 /*0x1f*/ % 32;
    // 00481e31  0bd9                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481e33  8d0c12                 -lea ecx, [edx + edx]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00481e36  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00481e38  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00481e3b  81c7ffff0000           +add edi, 0xffff
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
    // 00481e41  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00481e43  ebdf                   -jmp 0x481e24
    goto L_0x00481e24;
L_0x00481e45:
    // 00481e45  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481e48  0bcf                   -or ecx, edi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00481e4a  66894808               -mov word ptr [eax + 8], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.cx;
L_0x00481e4e:
    // 00481e4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e51  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00481e60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481e61  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481e63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481e64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481e65  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481e68  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00481e6b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481e6e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481e70  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00481e72  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00481e74  3bfe                   +cmp edi, esi
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
    // 00481e76  7608                   -jbe 0x481e80
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481e80;
    }
    // 00481e78  3bf8                   +cmp edi, eax
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
    // 00481e7a  0f8278010000           -jb 0x481ff8
    if (cpu.flags.cf)
    {
        goto L_0x00481ff8;
    }
L_0x00481e80:
    // 00481e80  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00481e86  7514                   -jne 0x481e9c
    if (!cpu.flags.zf)
    {
        goto L_0x00481e9c;
    }
    // 00481e88  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00481e8b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00481e8e  83f908                 +cmp ecx, 8
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
    // 00481e91  7229                   -jb 0x481ebc
    if (cpu.flags.cf)
    {
        goto L_0x00481ebc;
    }
    // 00481e93  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00481e95  ff2495a81f4800         -jmp dword ptr [edx*4 + 0x481fa8]
    cpu.ip = app->getMemory<x86::reg32>(4726696 + cpu.edx * 4); goto dynamic_jump;
L_0x00481e9c:
    // 00481e9c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00481e9e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00481ea3  83e904                 +sub ecx, 4
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
    // 00481ea6  720c                   -jb 0x481eb4
    if (cpu.flags.cf)
    {
        goto L_0x00481eb4;
    }
    // 00481ea8  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00481eab  03c8                   +add ecx, eax
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
    // 00481ead  ff2485c01e4800         -jmp dword ptr [eax*4 + 0x481ec0]
    cpu.ip = app->getMemory<x86::reg32>(4726464 + cpu.eax * 4); goto dynamic_jump;
L_0x00481eb4:
    // 00481eb4  ff248db81f4800         -jmp dword ptr [ecx*4 + 0x481fb8]
    cpu.ip = app->getMemory<x86::reg32>(4726712 + cpu.ecx * 4); goto dynamic_jump;
L_0x00481ebc:
    // 00481ebc  ff248d3c1f4800         -jmp dword ptr [ecx*4 + 0x481f3c]
    cpu.ip = app->getMemory<x86::reg32>(4726588 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00481ed0:
    // 00481ed0  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481ed2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00481ed4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00481ed6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00481ed9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00481edc  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00481edf  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00481ee2  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00481ee5  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00481ee8  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00481eeb  83f908                 +cmp ecx, 8
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
    // 00481eee  72cc                   -jb 0x481ebc
    if (cpu.flags.cf)
    {
        goto L_0x00481ebc;
    }
    // 00481ef0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00481ef2  ff2495a81f4800         -jmp dword ptr [edx*4 + 0x481fa8]
    cpu.ip = app->getMemory<x86::reg32>(4726696 + cpu.edx * 4); goto dynamic_jump;
  case 0x00481efc:
    // 00481efc  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481efe  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00481f00  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00481f02  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00481f05  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00481f08  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00481f0b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00481f0e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00481f11  83f908                 +cmp ecx, 8
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
    // 00481f14  72a6                   -jb 0x481ebc
    if (cpu.flags.cf)
    {
        goto L_0x00481ebc;
    }
    // 00481f16  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00481f18  ff2495a81f4800         -jmp dword ptr [edx*4 + 0x481fa8]
    cpu.ip = app->getMemory<x86::reg32>(4726696 + cpu.edx * 4); goto dynamic_jump;
  case 0x00481f20:
    // 00481f20  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481f22  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00481f24  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00481f26  46                     -inc esi
    (cpu.esi)++;
    // 00481f27  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00481f2a  47                     -inc edi
    (cpu.edi)++;
    // 00481f2b  83f908                 +cmp ecx, 8
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
    // 00481f2e  728c                   -jb 0x481ebc
    if (cpu.flags.cf)
    {
        goto L_0x00481ebc;
    }
    // 00481f30  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00481f32  ff2495a81f4800         -jmp dword ptr [edx*4 + 0x481fa8]
    cpu.ip = app->getMemory<x86::reg32>(4726696 + cpu.edx * 4); goto dynamic_jump;
  case 0x00481f5c:
    // 00481f5c  8b448ee4               -mov eax, dword ptr [esi + ecx*4 - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4);
    // 00481f60  89448fe4               -mov dword ptr [edi + ecx*4 - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00481f64:
    // 00481f64  8b448ee8               -mov eax, dword ptr [esi + ecx*4 - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4);
    // 00481f68  89448fe8               -mov dword ptr [edi + ecx*4 - 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00481f6c:
    // 00481f6c  8b448eec               -mov eax, dword ptr [esi + ecx*4 - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4);
    // 00481f70  89448fec               -mov dword ptr [edi + ecx*4 - 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00481f74:
    // 00481f74  8b448ef0               -mov eax, dword ptr [esi + ecx*4 - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4);
    // 00481f78  89448ff0               -mov dword ptr [edi + ecx*4 - 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00481f7c:
    // 00481f7c  8b448ef4               -mov eax, dword ptr [esi + ecx*4 - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4);
    // 00481f80  89448ff4               -mov dword ptr [edi + ecx*4 - 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00481f84:
    // 00481f84  8b448ef8               -mov eax, dword ptr [esi + ecx*4 - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4);
    // 00481f88  89448ff8               -mov dword ptr [edi + ecx*4 - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00481f8c:
    // 00481f8c  8b448efc               -mov eax, dword ptr [esi + ecx*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 00481f90  89448ffc               -mov dword ptr [edi + ecx*4 - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 00481f94  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00481f9b  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00481f9d  03f8                   +add edi, eax
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
  case 0x00481f9f:
    // 00481f9f  ff2495a81f4800         -jmp dword ptr [edx*4 + 0x481fa8]
    cpu.ip = app->getMemory<x86::reg32>(4726696 + cpu.edx * 4); goto dynamic_jump;
  case 0x00481fb8:
    // 00481fb8  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481fbb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fbd  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fbe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00481fc0:
    // 00481fc0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00481fc2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00481fc4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481fc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fc9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fca  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00481fcc:
    // 00481fcc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00481fce  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00481fd0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00481fd3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00481fd6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481fd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fdb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481fdc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00481fe0:
    // 00481fe0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00481fe2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00481fe4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00481fe7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00481fea  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00481fed  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00481ff0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481ff3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ff4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ff5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ff6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481ff8:
    // 00481ff8  8d7431fc               -lea esi, [ecx + esi - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 00481ffc  8d7c39fc               -lea edi, [ecx + edi - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 00482000  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00482006  7524                   -jne 0x48202c
    if (!cpu.flags.zf)
    {
        goto L_0x0048202c;
    }
    // 00482008  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0048200b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048200e  83f908                 +cmp ecx, 8
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
    // 00482011  720d                   -jb 0x482020
    if (cpu.flags.cf)
    {
        goto L_0x00482020;
    }
    // 00482013  fd                     -std 
    cpu.flags.df = 1;
    // 00482014  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00482016  fc                     -cld 
    cpu.flags.df = 0;
    // 00482017  ff249540214800         -jmp dword ptr [edx*4 + 0x482140]
    cpu.ip = app->getMemory<x86::reg32>(4727104 + cpu.edx * 4); goto dynamic_jump;
L_0x00482020:
    // 00482020  f7d9                   +neg ecx
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
    // 00482022  ff248df0204800         -jmp dword ptr [ecx*4 + 0x4820f0]
    cpu.ip = app->getMemory<x86::reg32>(4727024 + cpu.ecx * 4); goto dynamic_jump;
L_0x0048202c:
    // 0048202c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048202e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00482033  83f904                 +cmp ecx, 4
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
    // 00482036  720c                   -jb 0x482044
    if (cpu.flags.cf)
    {
        goto L_0x00482044;
    }
    // 00482038  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048203b  2bc8                   +sub ecx, eax
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
    // 0048203d  ff248548204800         -jmp dword ptr [eax*4 + 0x482048]
    cpu.ip = app->getMemory<x86::reg32>(4726856 + cpu.eax * 4); goto dynamic_jump;
L_0x00482044:
    // 00482044  ff248d40214800         -jmp dword ptr [ecx*4 + 0x482140]
    cpu.ip = app->getMemory<x86::reg32>(4727104 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00482058:
    // 00482058  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0048205b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048205d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00482060  4e                     -dec esi
    (cpu.esi)--;
    // 00482061  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00482064  4f                     -dec edi
    (cpu.edi)--;
    // 00482065  83f908                 +cmp ecx, 8
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
    // 00482068  72b6                   -jb 0x482020
    if (cpu.flags.cf)
    {
        goto L_0x00482020;
    }
    // 0048206a  fd                     -std 
    cpu.flags.df = 1;
    // 0048206b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048206d  fc                     -cld 
    cpu.flags.df = 0;
    // 0048206e  ff249540214800         -jmp dword ptr [edx*4 + 0x482140]
    cpu.ip = app->getMemory<x86::reg32>(4727104 + cpu.edx * 4); goto dynamic_jump;
  case 0x00482078:
    // 00482078  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0048207b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048207d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00482080  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00482083  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00482086  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00482089  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048208c  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048208f  83f908                 +cmp ecx, 8
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
    // 00482092  728c                   -jb 0x482020
    if (cpu.flags.cf)
    {
        goto L_0x00482020;
    }
    // 00482094  fd                     -std 
    cpu.flags.df = 1;
    // 00482095  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00482097  fc                     -cld 
    cpu.flags.df = 0;
    // 00482098  ff249540214800         -jmp dword ptr [edx*4 + 0x482140]
    cpu.ip = app->getMemory<x86::reg32>(4727104 + cpu.edx * 4); goto dynamic_jump;
  case 0x004820a0:
    // 004820a0  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004820a3  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004820a5  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004820a8  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004820ab  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004820ae  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004820b1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004820b4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004820b7  83ee03                 -sub esi, 3
    (cpu.esi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004820ba  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004820bd  83f908                 +cmp ecx, 8
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
    // 004820c0  0f825affffff           -jb 0x482020
    if (cpu.flags.cf)
    {
        goto L_0x00482020;
    }
    // 004820c6  fd                     -std 
    cpu.flags.df = 1;
    // 004820c7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004820c9  fc                     -cld 
    cpu.flags.df = 0;
    // 004820ca  ff249540214800         -jmp dword ptr [edx*4 + 0x482140]
    cpu.ip = app->getMemory<x86::reg32>(4727104 + cpu.edx * 4); goto dynamic_jump;
  case 0x004820f4:
    // 004820f4  8b448e1c               -mov eax, dword ptr [esi + ecx*4 + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4);
    // 004820f8  89448f1c               -mov dword ptr [edi + ecx*4 + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004820fc:
    // 004820fc  8b448e18               -mov eax, dword ptr [esi + ecx*4 + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4);
    // 00482100  89448f18               -mov dword ptr [edi + ecx*4 + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00482104:
    // 00482104  8b448e14               -mov eax, dword ptr [esi + ecx*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4);
    // 00482108  89448f14               -mov dword ptr [edi + ecx*4 + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0048210c:
    // 0048210c  8b448e10               -mov eax, dword ptr [esi + ecx*4 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4);
    // 00482110  89448f10               -mov dword ptr [edi + ecx*4 + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00482114:
    // 00482114  8b448e0c               -mov eax, dword ptr [esi + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 00482118  89448f0c               -mov dword ptr [edi + ecx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0048211c:
    // 0048211c  8b448e08               -mov eax, dword ptr [esi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00482120  89448f08               -mov dword ptr [edi + ecx*4 + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00482124:
    // 00482124  8b448e04               -mov eax, dword ptr [esi + ecx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 00482128  89448f04               -mov dword ptr [edi + ecx*4 + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 0048212c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00482133  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482135  03f8                   +add edi, eax
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
  case 0x00482137:
    // 00482137  ff249540214800         -jmp dword ptr [edx*4 + 0x482140]
    cpu.ip = app->getMemory<x86::reg32>(4727104 + cpu.edx * 4); goto dynamic_jump;
  case 0x00482150:
    // 00482150  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482153  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482154  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482155  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482156  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00482158:
    // 00482158  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0048215b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0048215e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482161  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482162  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482163  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482164  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00482168:
    // 00482168  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0048216b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0048216e  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00482171  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00482174  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482177  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482178  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482179  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048217a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048217c:
    // 0048217c  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0048217f  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00482182  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00482185  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00482188  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048218b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048218e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482191  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482192  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482193  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482194  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_482195(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482195  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00482197  e89d7fffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 0048219c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048219d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48219e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048219e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004821a2  3b05e01f5200           +cmp eax, dword ptr [0x521fe0]
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
    // 004821a8  7203                   -jb 0x4821ad
    if (cpu.flags.cf)
    {
        goto L_0x004821ad;
    }
    // 004821aa  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004821ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004821ad:
    // 004821ad  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004821af  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004821b2  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004821b5  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 004821b8  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 004821bf  8a448104               -mov al, byte ptr [ecx + eax*4 + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004821c3  83e040                 -and eax, 0x40
    cpu.eax &= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004821c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4821c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004821c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004821c8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004821ca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004821cc  bee81f5200             -mov esi, 0x521fe8
    cpu.esi = 5382120 /*0x521fe8*/;
    // 004821d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004821d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004821d3  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004821d9  8b3d8c714800           -mov edi, dword ptr [0x48718c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    // 004821df  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004821e1  391de41f5200           +cmp dword ptr [0x521fe4], ebx
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
    // 004821e7  740e                   -je 0x4821f7
    if (cpu.flags.zf)
    {
        goto L_0x004821f7;
    }
    // 004821e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004821ea  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004821ec  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 004821ee  e8d6a8ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004821f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821f4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004821f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004821f7:
    // 004821f7  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004821fa  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004821fd  e81e000000             -call 0x482220
    cpu.esp -= 4;
    sub_482220(app, cpu);
    // 00482202  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482203  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00482206  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482208  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482209  740a                   -je 0x482215
    if (cpu.flags.zf)
    {
        goto L_0x00482215;
    }
    // 0048220b  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0048220d  e818a9ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00482212  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482213  eb03                   -jmp 0x482218
    goto L_0x00482218;
L_0x00482215:
    // 00482215  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482216  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00482218:
    // 00482218  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048221b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048221c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048221d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048221e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048221f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482220  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482221  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00482223  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482226  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482228  7502                   -jne 0x48222c
    if (!cpu.flags.zf)
    {
        goto L_0x0048222c;
    }
    // 0048222a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048222b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048222c:
    // 0048222c  833dc4eb510000         +cmp dword ptr [0x51ebc4], 0
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
    // 00482233  7512                   -jne 0x482247
    if (!cpu.flags.zf)
    {
        goto L_0x00482247;
    }
    // 00482235  668b4d0c               -mov cx, word ptr [ebp + 0xc]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00482239  6681f9ff00             +cmp cx, 0xff
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
    // 0048223e  7739                   -ja 0x482279
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00482279;
    }
    // 00482240  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482242  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00482244  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482245  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482246  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482247:
    // 00482247  8d4d08                 -lea ecx, [ebp + 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048224a  83650800               -and dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0048224e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048224f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482251  ff3518644a00           -push dword ptr [0x4a6418]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
    cpu.esp -= 4;
    // 00482257  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482258  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048225b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048225d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048225e  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00482263  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 00482269  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048226f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482271  7406                   -je 0x482279
    if (cpu.flags.zf)
    {
        goto L_0x00482279;
    }
    // 00482273  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 00482277  740e                   -je 0x482287
    if (cpu.flags.zf)
    {
        goto L_0x00482287;
    }
L_0x00482279:
    // 00482279  e834c2ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0048227e  c7002a000000           -mov dword ptr [eax], 0x2a
    app->getMemory<x86::reg32>(cpu.eax) = 42 /*0x2a*/;
    // 00482284  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00482287:
    // 00482287  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482288  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__aulldiv(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482291  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482292  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00482296  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482298  7518                   -jne 0x4822b2
    if (!cpu.flags.zf)
    {
        goto L_0x004822b2;
    }
    // 0048229a  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048229e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004822a2  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004822a4  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004822a6  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004822a8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004822ac  f7f1                   +div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004822ae  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004822b0  eb41                   -jmp 0x4822f3
    goto L_0x004822f3;
L_0x004822b2:
    // 004822b2  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004822b4  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004822b8  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004822bc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x004822c0:
    // 004822c0  d1e9                   +shr ecx, 1
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
    // 004822c2  d1db                   -rcr ebx, 1
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
    // 004822c4  d1ea                   +shr edx, 1
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
    // 004822c6  d1d8                   -rcr eax, 1
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
    // 004822c8  0bc9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004822ca  75f4                   -jne 0x4822c0
    if (!cpu.flags.zf)
    {
        goto L_0x004822c0;
    }
    // 004822cc  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004822ce  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004822d0  f7642418               -mul dword ptr [esp + 0x18]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 004822d4  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004822d6  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004822da  f7e6                   -mul esi
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.esi);
    // 004822dc  03d1                   +add edx, ecx
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
    // 004822de  720e                   -jb 0x4822ee
    if (cpu.flags.cf)
    {
        goto L_0x004822ee;
    }
    // 004822e0  3b542410               +cmp edx, dword ptr [esp + 0x10]
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
    // 004822e4  7708                   -ja 0x4822ee
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004822ee;
    }
    // 004822e6  7207                   -jb 0x4822ef
    if (cpu.flags.cf)
    {
        goto L_0x004822ef;
    }
    // 004822e8  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 004822ec  7601                   -jbe 0x4822ef
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004822ef;
    }
L_0x004822ee:
    // 004822ee  4e                     -dec esi
    (cpu.esi)--;
L_0x004822ef:
    // 004822ef  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004822f1  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004822f3:
    // 004822f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822f5  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::__aullrem(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482301  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00482305  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482307  7518                   -jne 0x482321
    if (!cpu.flags.zf)
    {
        goto L_0x00482321;
    }
    // 00482309  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048230d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00482311  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482313  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00482315  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482319  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0048231b  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048231d  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048231f  eb50                   -jmp 0x482371
    goto L_0x00482371;
L_0x00482321:
    // 00482321  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482323  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00482327  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048232b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0048232f:
    // 0048232f  d1e9                   +shr ecx, 1
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
    // 00482331  d1db                   -rcr ebx, 1
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
    // 00482333  d1ea                   +shr edx, 1
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
    // 00482335  d1d8                   -rcr eax, 1
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
    // 00482337  0bc9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00482339  75f4                   -jne 0x48232f
    if (!cpu.flags.zf)
    {
        goto L_0x0048232f;
    }
    // 0048233b  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0048233d  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048233f  f7642414               -mul dword ptr [esp + 0x14]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00482343  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00482344  f7642410               -mul dword ptr [esp + 0x10]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00482348  03d1                   +add edx, ecx
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
    // 0048234a  720e                   -jb 0x48235a
    if (cpu.flags.cf)
    {
        goto L_0x0048235a;
    }
    // 0048234c  3b54240c               +cmp edx, dword ptr [esp + 0xc]
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
    // 00482350  7708                   -ja 0x48235a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048235a;
    }
    // 00482352  720e                   -jb 0x482362
    if (cpu.flags.cf)
    {
        goto L_0x00482362;
    }
    // 00482354  3b442408               +cmp eax, dword ptr [esp + 8]
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
    // 00482358  7608                   -jbe 0x482362
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482362;
    }
L_0x0048235a:
    // 0048235a  2b442410               +sub eax, dword ptr [esp + 0x10]
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
    // 0048235e  1b542414               -sbb edx, dword ptr [esp + 0x14]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)) + cpu.flags.cf);
L_0x00482362:
    // 00482362  2b442408               +sub eax, dword ptr [esp + 8]
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
    // 00482366  1b54240c               -sbb edx, dword ptr [esp + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)) + cpu.flags.cf);
    // 0048236a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0048236c  f7d8                   +neg eax
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
    // 0048236e  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x00482371:
    // 00482371  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482372  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_482375(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482375  ff05e4ea5100           -inc dword ptr [0x51eae4]
    (app->getMemory<x86::reg32>(x86::reg32(5368548) /* 0x51eae4 */))++;
    // 0048237b  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00482380  e8f54effff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00482385  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482386  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048238a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048238c  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048238f  740d                   -je 0x48239e
    if (cpu.flags.zf)
    {
        goto L_0x0048239e;
    }
    // 00482391  83490c08               +or dword ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(8 /*0x8*/))));
    // 00482395  c7411800100000         -mov dword ptr [ecx + 0x18], 0x1000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 4096 /*0x1000*/;
    // 0048239c  eb11                   -jmp 0x4823af
    goto L_0x004823af;
L_0x0048239e:
    // 0048239e  83490c04               -or dword ptr [ecx + 0xc], 4
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004823a2  8d4114                 -lea eax, [ecx + 0x14]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004823a5  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004823a8  c7411802000000         -mov dword ptr [ecx + 0x18], 2
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 2 /*0x2*/;
L_0x004823af:
    // 004823af  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004823b2  83610400               -and dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004823b6  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004823b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4823b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004823b9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004823ba  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004823bc  83ec58                 +sub esp, 0x58
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004823bf  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004823c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004823c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004823c4  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004823c7  0fb708                 -movzx ecx, word ptr [eax]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(cpu.eax));
    // 004823ca  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004823cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004823cd  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004823ce  894d10                 -mov dword ptr [ebp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004823d1  742b                   -je 0x4823fe
    if (cpu.flags.zf)
    {
        goto L_0x004823fe;
    }
    // 004823d3  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004823d4  7424                   -je 0x4823fa
    if (cpu.flags.zf)
    {
        goto L_0x004823fa;
    }
    // 004823d6  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004823d7  741d                   -je 0x4823f6
    if (cpu.flags.zf)
    {
        goto L_0x004823f6;
    }
    // 004823d9  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004823da  7416                   -je 0x4823f2
    if (cpu.flags.zf)
    {
        goto L_0x004823f2;
    }
    // 004823dc  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004823dd  741f                   -je 0x4823fe
    if (cpu.flags.zf)
    {
        goto L_0x004823fe;
    }
    // 004823df  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004823e0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004823e1  7407                   -je 0x4823ea
    if (cpu.flags.zf)
    {
        goto L_0x004823ea;
    }
    // 004823e3  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004823e4  756e                   -jne 0x482454
    if (!cpu.flags.zf)
    {
        goto L_0x00482454;
    }
    // 004823e6  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004823e8  eb16                   -jmp 0x482400
    goto L_0x00482400;
L_0x004823ea:
    // 004823ea  c70601000000           -mov dword ptr [esi], 1
    app->getMemory<x86::reg32>(cpu.esi) = 1 /*0x1*/;
    // 004823f0  eb62                   -jmp 0x482454
    goto L_0x00482454;
L_0x004823f2:
    // 004823f2  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 004823f4  eb0a                   -jmp 0x482400
    goto L_0x00482400;
L_0x004823f6:
    // 004823f6  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004823f8  eb06                   -jmp 0x482400
    goto L_0x00482400;
L_0x004823fa:
    // 004823fa  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004823fc  eb02                   -jmp 0x482400
    goto L_0x00482400;
L_0x004823fe:
    // 004823fe  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
L_0x00482400:
    // 00482400  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482401  8d7e18                 -lea edi, [esi + 0x18]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00482404  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482405  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482406  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482407  e889dcffff             -call 0x480095
    cpu.esp -= 4;
    sub_480095(app, cpu);
    // 0048240c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048240f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482411  7541                   -jne 0x482454
    if (!cpu.flags.zf)
    {
        goto L_0x00482454;
    }
    // 00482413  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482416  83f810                 +cmp eax, 0x10
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
    // 00482419  7410                   -je 0x48242b
    if (cpu.flags.zf)
    {
        goto L_0x0048242b;
    }
    // 0048241b  83f816                 +cmp eax, 0x16
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
    // 0048241e  740b                   -je 0x48242b
    if (cpu.flags.zf)
    {
        goto L_0x0048242b;
    }
    // 00482420  83f81d                 +cmp eax, 0x1d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482423  7406                   -je 0x48242b
    if (cpu.flags.zf)
    {
        goto L_0x0048242b;
    }
    // 00482425  8365e0fe               +and dword ptr [ebp - 0x20], 0xfffffffe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/))));
    // 00482429  eb12                   -jmp 0x48243d
    goto L_0x0048243d;
L_0x0048242b:
    // 0048242b  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0048242e  dd4610                 -fld qword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00482431  83e1e3                 -and ecx, 0xffffffe3
    cpu.ecx &= x86::reg32(x86::sreg32(4294967267 /*0xffffffe3*/));
    // 00482434  dd5dd0                 -fstp qword ptr [ebp - 0x30]
    app->getMemory<double>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00482437  83c903                 -or ecx, 3
    cpu.ecx |= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048243a  894de0                 -mov dword ptr [ebp - 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ecx;
L_0x0048243d:
    // 0048243d  8d4e08                 -lea ecx, [esi + 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00482440  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482442  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482443  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00482446  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482447  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482448  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 0048244b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048244c  e891d9ffff             -call 0x47fde2
    cpu.esp -= 4;
    sub_47fde2(app, cpu);
    // 00482451  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x00482454:
    // 00482454  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 00482459  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0048245c  e8cfe0ffff             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 00482461  833e08                 +cmp dword ptr [esi], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482464  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482465  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482466  7414                   -je 0x48247c
    if (cpu.flags.zf)
    {
        goto L_0x0048247c;
    }
    // 00482468  833dc81e520000         +cmp dword ptr [0x521ec8], 0
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
    // 0048246f  750b                   -jne 0x48247c
    if (!cpu.flags.zf)
    {
        goto L_0x0048247c;
    }
    // 00482471  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482472  e8b92afeff             -call 0x464f30
    cpu.esp -= 4;
    sub_464f30(app, cpu);
    // 00482477  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482479  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048247a  7508                   -jne 0x482484
    if (!cpu.flags.zf)
    {
        goto L_0x00482484;
    }
L_0x0048247c:
    // 0048247c  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0048247e  e8b1deffff             -call 0x480334
    cpu.esp -= 4;
    sub_480334(app, cpu);
    // 00482483  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482484:
    // 00482484  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482485  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482486  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482487  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482488  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482489(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482489  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048248b  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0048248f  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00482493  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00482497  e804000000             -call 0x4824a0
    cpu.esp -= 4;
    sub_4824a0(app, cpu);
    // 0048249c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048249f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4824a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004824a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004824a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004824a3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004824a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004824a7  8365f800               -and dword ptr [ebp - 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004824ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004824ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004824ad  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004824b0  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004824b2  8d7701                 -lea esi, [edi + 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004824b5  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
L_0x004824b8:
    // 004824b8  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 004824bf  7e0f                   -jle 0x4824d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004824d0;
    }
    // 004824c1  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 004824c4  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004824c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004824c7  e8bdadffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 004824cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004824cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004824ce  eb0f                   -jmp 0x4824df
    goto L_0x004824df;
L_0x004824d0:
    // 004824d0  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 004824d6  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 004824d9  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 004824dc  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004824df:
    // 004824df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004824e1  7405                   -je 0x4824e8
    if (cpu.flags.zf)
    {
        goto L_0x004824e8;
    }
    // 004824e3  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004824e5  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004824e6  ebd0                   -jmp 0x4824b8
    goto L_0x004824b8;
L_0x004824e8:
    // 004824e8  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004824eb  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004824ee  7506                   -jne 0x4824f6
    if (!cpu.flags.zf)
    {
        goto L_0x004824f6;
    }
    // 004824f0  834d1402               +or dword ptr [ebp + 0x14], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004824f4  eb05                   -jmp 0x4824fb
    goto L_0x004824fb;
L_0x004824f6:
    // 004824f6  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004824f9  7506                   -jne 0x482501
    if (!cpu.flags.zf)
    {
        goto L_0x00482501;
    }
L_0x004824fb:
    // 004824fb  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004824fd  46                     -inc esi
    (cpu.esi)++;
    // 004824fe  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
L_0x00482501:
    // 00482501  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00482504  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482506  0f8c89010000           -jl 0x482695
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482695;
    }
    // 0048250c  83f801                 +cmp eax, 1
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
    // 0048250f  0f8480010000           -je 0x482695
    if (cpu.flags.zf)
    {
        goto L_0x00482695;
    }
    // 00482515  83f824                 +cmp eax, 0x24
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482518  0f8f77010000           -jg 0x482695
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00482695;
    }
    // 0048251e  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00482520  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482522  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482523  7524                   -jne 0x482549
    if (!cpu.flags.zf)
    {
        goto L_0x00482549;
    }
    // 00482525  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482528  7409                   -je 0x482533
    if (cpu.flags.zf)
    {
        goto L_0x00482533;
    }
    // 0048252a  c745100a000000         -mov dword ptr [ebp + 0x10], 0xa
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 10 /*0xa*/;
    // 00482531  eb32                   -jmp 0x482565
    goto L_0x00482565;
L_0x00482533:
    // 00482533  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00482535  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482537  740d                   -je 0x482546
    if (cpu.flags.zf)
    {
        goto L_0x00482546;
    }
    // 00482539  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048253b  7409                   -je 0x482546
    if (cpu.flags.zf)
    {
        goto L_0x00482546;
    }
    // 0048253d  c7451008000000         -mov dword ptr [ebp + 0x10], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 8 /*0x8*/;
    // 00482544  eb1f                   -jmp 0x482565
    goto L_0x00482565;
L_0x00482546:
    // 00482546  894d10                 -mov dword ptr [ebp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00482549:
    // 00482549  394d10                 +cmp dword ptr [ebp + 0x10], ecx
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
    // 0048254c  7517                   -jne 0x482565
    if (!cpu.flags.zf)
    {
        goto L_0x00482565;
    }
    // 0048254e  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482551  7512                   -jne 0x482565
    if (!cpu.flags.zf)
    {
        goto L_0x00482565;
    }
    // 00482553  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00482555  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482557  7404                   -je 0x48255d
    if (cpu.flags.zf)
    {
        goto L_0x0048255d;
    }
    // 00482559  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048255b  7508                   -jne 0x482565
    if (!cpu.flags.zf)
    {
        goto L_0x00482565;
    }
L_0x0048255d:
    // 0048255d  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00482560  46                     -inc esi
    (cpu.esi)++;
    // 00482561  46                     -inc esi
    (cpu.esi)++;
    // 00482562  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
L_0x00482565:
    // 00482565  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482568  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048256a  f77510                 -div dword ptr [ebp + 0x10]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0048256d  bf03010000             -mov edi, 0x103
    cpu.edi = 259 /*0x103*/;
    // 00482572  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00482575:
    // 00482575  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 0048257c  0fb6f3                 -movzx esi, bl
    cpu.esi = x86::reg32(cpu.bl);
    // 0048257f  7e0c                   -jle 0x48258d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048258d;
    }
    // 00482581  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00482583  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482584  e800adffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00482589  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048258a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048258b  eb0b                   -jmp 0x482598
    goto L_0x00482598;
L_0x0048258d:
    // 0048258d  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00482592  8a0470                 -mov al, byte ptr [eax + esi*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.esi * 2);
    // 00482595  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00482598:
    // 00482598  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048259a  7408                   -je 0x4825a4
    if (cpu.flags.zf)
    {
        goto L_0x004825a4;
    }
    // 0048259c  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0048259f  83e930                 +sub ecx, 0x30
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004825a2  eb32                   -jmp 0x4825d6
    goto L_0x004825d6;
L_0x004825a4:
    // 004825a4  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 004825ab  7e0b                   -jle 0x4825b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004825b8;
    }
    // 004825ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004825ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004825af  e8d5acffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 004825b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825b6  eb0b                   -jmp 0x4825c3
    goto L_0x004825c3;
L_0x004825b8:
    // 004825b8  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 004825bd  668b0470               -mov ax, word ptr [eax + esi*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + cpu.esi * 2);
    // 004825c1  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
L_0x004825c3:
    // 004825c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004825c5  744a                   -je 0x482611
    if (cpu.flags.zf)
    {
        goto L_0x00482611;
    }
    // 004825c7  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 004825ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004825cb  e8e0220000             -call 0x4848b0
    cpu.esp -= 4;
    sub_4848b0(app, cpu);
    // 004825d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825d1  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004825d3  83e937                 -sub ecx, 0x37
    (cpu.ecx) -= x86::reg32(x86::sreg32(55 /*0x37*/));
L_0x004825d6:
    // 004825d6  3b4d10                 +cmp ecx, dword ptr [ebp + 0x10]
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
    // 004825d9  7336                   -jae 0x482611
    if (!cpu.flags.cf)
    {
        goto L_0x00482611;
    }
    // 004825db  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004825de  834d1408               -or dword ptr [ebp + 0x14], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004825e2  3b75f4                 +cmp esi, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004825e5  7214                   -jb 0x4825fb
    if (cpu.flags.cf)
    {
        goto L_0x004825fb;
    }
    // 004825e7  750c                   -jne 0x4825f5
    if (!cpu.flags.zf)
    {
        goto L_0x004825f5;
    }
    // 004825e9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004825ec  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004825ee  f77510                 -div dword ptr [ebp + 0x10]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004825f1  3bca                   +cmp ecx, edx
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
    // 004825f3  7606                   -jbe 0x4825fb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004825fb;
    }
L_0x004825f5:
    // 004825f5  834d1404               +or dword ptr [ebp + 0x14], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004825f9  eb09                   -jmp 0x482604
    goto L_0x00482604;
L_0x004825fb:
    // 004825fb  0faf7510               -imul esi, dword ptr [ebp + 0x10]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004825ff  03f1                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00482601  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
L_0x00482604:
    // 00482604  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482607  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048260a  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0048260c  e964ffffff             -jmp 0x482575
    goto L_0x00482575;
L_0x00482611:
    // 00482611  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00482614  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 00482617  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048261a  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0048261c  7510                   -jne 0x48262e
    if (!cpu.flags.zf)
    {
        goto L_0x0048262e;
    }
    // 0048261e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482620  7406                   -je 0x482628
    if (cpu.flags.zf)
    {
        goto L_0x00482628;
    }
    // 00482622  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482625  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x00482628:
    // 00482628  8365f800               +and dword ptr [ebp - 8], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0048262c  eb4b                   -jmp 0x482679
    goto L_0x00482679;
L_0x0048262e:
    // 0048262e  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00482630  beffffff7f             -mov esi, 0x7fffffff
    cpu.esi = 2147483647 /*0x7fffffff*/;
    // 00482635  751b                   -jne 0x482652
    if (!cpu.flags.zf)
    {
        goto L_0x00482652;
    }
    // 00482637  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00482639  753e                   -jne 0x482679
    if (!cpu.flags.zf)
    {
        goto L_0x00482679;
    }
    // 0048263b  83e002                 +and eax, 2
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0048263e  7409                   -je 0x482649
    if (cpu.flags.zf)
    {
        goto L_0x00482649;
    }
    // 00482640  817df800000080         +cmp dword ptr [ebp - 8], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482647  7709                   -ja 0x482652
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00482652;
    }
L_0x00482649:
    // 00482649  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048264b  752c                   -jne 0x482679
    if (!cpu.flags.zf)
    {
        goto L_0x00482679;
    }
    // 0048264d  3975f8                 +cmp dword ptr [ebp - 8], esi
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
    // 00482650  7627                   -jbe 0x482679
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482679;
    }
L_0x00482652:
    // 00482652  e85bbeffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00482657  f6451401               +test byte ptr [ebp + 0x14], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */) & 1 /*0x1*/));
    // 0048265b  c70022000000           -mov dword ptr [eax], 0x22
    app->getMemory<x86::reg32>(cpu.eax) = 34 /*0x22*/;
    // 00482661  7406                   -je 0x482669
    if (cpu.flags.zf)
    {
        goto L_0x00482669;
    }
    // 00482663  834df8ff               +or dword ptr [ebp - 8], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00482667  eb10                   -jmp 0x482679
    goto L_0x00482679;
L_0x00482669:
    // 00482669  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048266c  2402                   -and al, 2
    cpu.al &= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0048266e  f6d8                   +neg al
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
    // 00482670  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00482672  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00482674  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00482676  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00482679:
    // 00482679  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048267b  7405                   -je 0x482682
    if (cpu.flags.zf)
    {
        goto L_0x00482682;
    }
    // 0048267d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00482680  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00482682:
    // 00482682  f6451402               +test byte ptr [ebp + 0x14], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */) & 2 /*0x2*/));
    // 00482686  7408                   -je 0x482690
    if (cpu.flags.zf)
    {
        goto L_0x00482690;
    }
    // 00482688  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048268b  f7d8                   +neg eax
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
    // 0048268d  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00482690:
    // 00482690  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00482693  eb0b                   -jmp 0x4826a0
    goto L_0x004826a0;
L_0x00482695:
    // 00482695  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00482698  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048269a  7402                   -je 0x48269e
    if (cpu.flags.zf)
    {
        goto L_0x0048269e;
    }
    // 0048269c  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
L_0x0048269e:
    // 0048269e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004826a0:
    // 004826a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_strstr(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004826b0  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004826b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004826b5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004826b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004826b7  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004826b9  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004826bd  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004826bf  7469                   -je 0x48272a
    if (cpu.flags.zf)
    {
        goto L_0x0048272a;
    }
    // 004826c1  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004826c4  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 004826c6  744f                   -je 0x482717
    if (cpu.flags.zf)
    {
        goto L_0x00482717;
    }
L_0x004826c8:
    // 004826c8  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004826ca  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004826ce  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004826d0  46                     -inc esi
    (cpu.esi)++;
    // 004826d1  38d0                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004826d3  7415                   -je 0x4826ea
    if (cpu.flags.zf)
    {
        goto L_0x004826ea;
    }
    // 004826d5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004826d7  740b                   -je 0x4826e4
    if (cpu.flags.zf)
    {
        goto L_0x004826e4;
    }
L_0x004826d9:
    // 004826d9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004826db  46                     -inc esi
    (cpu.esi)++;
L_0x004826dc:
    // 004826dc  38d0                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004826de  740a                   -je 0x4826ea
    if (cpu.flags.zf)
    {
        goto L_0x004826ea;
    }
    // 004826e0  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004826e2  75f5                   -jne 0x4826d9
    if (!cpu.flags.zf)
    {
        goto L_0x004826d9;
    }
L_0x004826e4:
    // 004826e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826e7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004826e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004826ea:
    // 004826ea  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004826ec  46                     -inc esi
    (cpu.esi)++;
    // 004826ed  38f0                   +cmp al, dh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004826ef  75eb                   -jne 0x4826dc
    if (!cpu.flags.zf)
    {
        goto L_0x004826dc;
    }
    // 004826f1  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
L_0x004826f4:
    // 004826f4  8a6102                 -mov ah, byte ptr [ecx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004826f7  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004826f9  7428                   -je 0x482723
    if (cpu.flags.zf)
    {
        goto L_0x00482723;
    }
    // 004826fb  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004826fd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00482700  38e0                   +cmp al, ah
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482702  75c4                   -jne 0x4826c8
    if (!cpu.flags.zf)
    {
        goto L_0x004826c8;
    }
    // 00482704  8a4103                 -mov al, byte ptr [ecx + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 00482707  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00482709  7418                   -je 0x482723
    if (cpu.flags.zf)
    {
        goto L_0x00482723;
    }
    // 0048270b  8a66ff                 -mov ah, byte ptr [esi - 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0048270e  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00482711  38e0                   +cmp al, ah
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482713  74df                   -je 0x4826f4
    if (cpu.flags.zf)
    {
        goto L_0x004826f4;
    }
    // 00482715  ebb1                   -jmp 0x4826c8
    goto L_0x004826c8;
L_0x00482717:
    // 00482717  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482719  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048271a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048271b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048271c  8ac2                   -mov al, dl
    cpu.al = cpu.dl;
    // 0048271e  e95377ffff             -jmp 0x479e76
    return sub_479e76(app, cpu);
L_0x00482723:
    // 00482723  8d47ff                 -lea eax, [edi - 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00482726  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482727  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482728  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482729  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048272a:
    // 0048272a  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048272c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048272d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048272e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048272f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_strcmp(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482730  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482734  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482738  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 0048273e  753c                   -jne 0x48277c
    if (!cpu.flags.zf)
    {
        goto L_0x0048277c;
    }
L_0x00482740:
    // 00482740  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00482742  3a01                   +cmp al, byte ptr [ecx]
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
    // 00482744  752e                   -jne 0x482774
    if (!cpu.flags.zf)
    {
        goto L_0x00482774;
    }
    // 00482746  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 00482748  7426                   -je 0x482770
    if (cpu.flags.zf)
    {
        goto L_0x00482770;
    }
    // 0048274a  3a6101                 +cmp ah, byte ptr [ecx + 1]
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
    // 0048274d  7525                   -jne 0x482774
    if (!cpu.flags.zf)
    {
        goto L_0x00482774;
    }
    // 0048274f  0ae4                   +or ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(cpu.ah))));
    // 00482751  741d                   -je 0x482770
    if (cpu.flags.zf)
    {
        goto L_0x00482770;
    }
    // 00482753  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00482756  3a4102                 +cmp al, byte ptr [ecx + 2]
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
    // 00482759  7519                   -jne 0x482774
    if (!cpu.flags.zf)
    {
        goto L_0x00482774;
    }
    // 0048275b  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0048275d  7411                   -je 0x482770
    if (cpu.flags.zf)
    {
        goto L_0x00482770;
    }
    // 0048275f  3a6103                 +cmp ah, byte ptr [ecx + 3]
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
    // 00482762  7510                   -jne 0x482774
    if (!cpu.flags.zf)
    {
        goto L_0x00482774;
    }
    // 00482764  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482767  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048276a  0ae4                   +or ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(cpu.ah))));
    // 0048276c  75d2                   -jne 0x482740
    if (!cpu.flags.zf)
    {
        goto L_0x00482740;
    }
    // 0048276e  8bff                   -mov edi, edi
    cpu.edi = cpu.edi;
L_0x00482770:
    // 00482770  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482772  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482774:
    // 00482774  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00482776  d1e0                   -shl eax, 1
    cpu.eax <<= 1 /*0x1*/ % 32;
    // 00482778  40                     -inc eax
    (cpu.eax)++;
    // 00482779  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048277c:
    // 0048277c  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 00482782  7414                   -je 0x482798
    if (cpu.flags.zf)
    {
        goto L_0x00482798;
    }
    // 00482784  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00482786  42                     -inc edx
    (cpu.edx)++;
    // 00482787  3a01                   +cmp al, byte ptr [ecx]
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
    // 00482789  75e9                   -jne 0x482774
    if (!cpu.flags.zf)
    {
        goto L_0x00482774;
    }
    // 0048278b  41                     -inc ecx
    (cpu.ecx)++;
    // 0048278c  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0048278e  74e0                   -je 0x482770
    if (cpu.flags.zf)
    {
        goto L_0x00482770;
    }
    // 00482790  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 00482796  74a8                   -je 0x482740
    if (cpu.flags.zf)
    {
        goto L_0x00482740;
    }
L_0x00482798:
    // 00482798  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 0048279b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048279e  3a01                   +cmp al, byte ptr [ecx]
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
    // 004827a0  75d2                   -jne 0x482774
    if (!cpu.flags.zf)
    {
        goto L_0x00482774;
    }
    // 004827a2  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 004827a4  74ca                   -je 0x482770
    if (cpu.flags.zf)
    {
        goto L_0x00482770;
    }
    // 004827a6  3a6101                 +cmp ah, byte ptr [ecx + 1]
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
    // 004827a9  75c9                   -jne 0x482774
    if (!cpu.flags.zf)
    {
        goto L_0x00482774;
    }
    // 004827ab  0ae4                   +or ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(cpu.ah))));
    // 004827ad  74c1                   -je 0x482770
    if (cpu.flags.zf)
    {
        goto L_0x00482770;
    }
    // 004827af  83c102                 +add ecx, 2
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
    // 004827b2  eb8c                   -jmp 0x482740
    goto L_0x00482740;
}

/* align: skip  */
void Application::sub_4827c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004827c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004827c1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004827c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004827c4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004827c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004827c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004827c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004827c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004827ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004827cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004827cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004827cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004827ce  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004827d1  8d4900                 -lea ecx, [ecx]
    cpu.ecx = x86::reg32(cpu.ecx);
L_0x004827d4:
    // 004827d4  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004827d6  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 004827d8  7407                   -je 0x4827e1
    if (cpu.flags.zf)
    {
        goto L_0x004827e1;
    }
    // 004827da  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004827db  0fab0424               +bts dword ptr [esp], eax
    {
        const x86::reg32 mask = x86::reg32(1) << (cpu.eax & 31);
        cpu.flags.cf = (x86::reg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32((x86::sreg32(cpu.eax) >> 5) * 4))) & mask) != 0;
        app->getMemory<x86::reg32>(cpu.esp + x86::reg32((x86::sreg32(cpu.eax) >> 5) * 4)) = x86::reg32(x86::reg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32((x86::sreg32(cpu.eax) >> 5) * 4))) | mask);
    }
    // 004827df  ebf3                   -jmp 0x4827d4
    goto L_0x004827d4;
L_0x004827e1:
    // 004827e1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004827e4  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004827e7  90                     -nop 
    ;
L_0x004827e8:
    // 004827e8  41                     -inc ecx
    (cpu.ecx)++;
    // 004827e9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004827eb  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 004827ed  7407                   -je 0x4827f6
    if (cpu.flags.zf)
    {
        goto L_0x004827f6;
    }
    // 004827ef  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004827f0  0fa30424               +bt dword ptr [esp], eax
    {
        const x86::reg32 mask = x86::reg32(1) << (cpu.eax & 31);
        cpu.flags.cf = (x86::reg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32((x86::sreg32(cpu.eax) >> 5) * 4))) & mask) != 0;
    }
    // 004827f4  73f2                   -jae 0x4827e8
    if (!cpu.flags.cf)
    {
        goto L_0x004827e8;
    }
L_0x004827f6:
    // 004827f6  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004827f8  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004827fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827fc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004827fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482800  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482801  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00482803  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482804  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482806  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482807  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482808  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482809  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048280a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048280b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048280c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048280d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048280e  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00482811  8d4900                 -lea ecx, [ecx]
    cpu.ecx = x86::reg32(cpu.ecx);
L_0x00482814:
    // 00482814  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00482816  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 00482818  7407                   -je 0x482821
    if (cpu.flags.zf)
    {
        goto L_0x00482821;
    }
    // 0048281a  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048281b  0fab0424               +bts dword ptr [esp], eax
    {
        const x86::reg32 mask = x86::reg32(1) << (cpu.eax & 31);
        cpu.flags.cf = (x86::reg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32((x86::sreg32(cpu.eax) >> 5) * 4))) & mask) != 0;
        app->getMemory<x86::reg32>(cpu.esp + x86::reg32((x86::sreg32(cpu.eax) >> 5) * 4)) = x86::reg32(x86::reg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32((x86::sreg32(cpu.eax) >> 5) * 4))) | mask);
    }
    // 0048281f  ebf3                   -jmp 0x482814
    goto L_0x00482814;
L_0x00482821:
    // 00482821  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00482824:
    // 00482824  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00482826  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 00482828  740a                   -je 0x482834
    if (cpu.flags.zf)
    {
        goto L_0x00482834;
    }
    // 0048282a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048282b  0fa30424               +bt dword ptr [esp], eax
    {
        const x86::reg32 mask = x86::reg32(1) << (cpu.eax & 31);
        cpu.flags.cf = (x86::reg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32((x86::sreg32(cpu.eax) >> 5) * 4))) & mask) != 0;
    }
    // 0048282f  73f3                   -jae 0x482824
    if (!cpu.flags.cf)
    {
        goto L_0x00482824;
    }
    // 00482831  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
L_0x00482834:
    // 00482834  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00482837  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482838  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482839  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48283a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048283a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048283b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048283d  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0048283f  68f8854800             -push 0x4885f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752888 /*0x4885f8*/;
    cpu.esp -= 4;
    // 00482844  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 00482849  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0048284f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482850  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00482857  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048285a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048285b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048285c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048285d  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00482860  a158ed5100             -mov eax, dword ptr [0x51ed58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369176) /* 0x51ed58 */);
    // 00482865  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482867  3bc3                   +cmp eax, ebx
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
    // 00482869  753e                   -jne 0x4828a9
    if (!cpu.flags.zf)
    {
        goto L_0x004828a9;
    }
    // 0048286b  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0048286e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048286f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482871  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482872  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482873  68487e4800             -push 0x487e48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750920 /*0x487e48*/;
    cpu.esp -= 4;
    // 00482878  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482879  ff1584714800           -call dword ptr [0x487184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747652) /* 0x487184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048287f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482881  7404                   -je 0x482887
    if (cpu.flags.zf)
    {
        goto L_0x00482887;
    }
    // 00482883  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482885  eb1d                   -jmp 0x4828a4
    goto L_0x004828a4;
L_0x00482887:
    // 00482887  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0048288a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048288b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048288c  68447e4800             -push 0x487e44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750916 /*0x487e44*/;
    cpu.esp -= 4;
    // 00482891  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482892  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482893  ff15e4704800           -call dword ptr [0x4870e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747492) /* 0x4870e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00482899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048289b  0f84ce000000           -je 0x48296f
    if (cpu.flags.zf)
    {
        return sub_48296f(app, cpu);
    }
    // 004828a1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004828a3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004828a4:
    // 004828a4  a358ed5100             -mov dword ptr [0x51ed58], eax
    app->getMemory<x86::reg32>(x86::reg32(5369176) /* 0x51ed58 */) = cpu.eax;
L_0x004828a9:
    // 004828a9  83f802                 +cmp eax, 2
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
    // 004828ac  7524                   -jne 0x4828d2
    if (!cpu.flags.zf)
    {
        goto L_0x004828d2;
    }
    // 004828ae  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004828b1  3bc3                   +cmp eax, ebx
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
    // 004828b3  7505                   -jne 0x4828ba
    if (!cpu.flags.zf)
    {
        goto L_0x004828ba;
    }
    // 004828b5  a1c4eb5100             -mov eax, dword ptr [0x51ebc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
L_0x004828ba:
    // 004828ba  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004828bd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004828c0  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004828c3  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004828c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004828c7  ff15e4704800           -call dword ptr [0x4870e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747492) /* 0x4870e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004828cd  e99f000000             -jmp 0x482971
    return sub_482971(app, cpu);
L_0x004828d2:
    // 004828d2  83f801                 +cmp eax, 1
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
    // 004828d5  0f8594000000           -jne 0x48296f
    if (!cpu.flags.zf)
    {
        return sub_48296f(app, cpu);
    }
    // 004828db  395d18                 +cmp dword ptr [ebp + 0x18], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004828de  7508                   -jne 0x4828e8
    if (!cpu.flags.zf)
    {
        goto L_0x004828e8;
    }
    // 004828e0  a1d4eb5100             -mov eax, dword ptr [0x51ebd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    // 004828e5  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004828e8:
    // 004828e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004828e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004828ea  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004828ed  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004828f0  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004828f3  f7d8                   +neg eax
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
    // 004828f5  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004828f7  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004828fa  40                     -inc eax
    (cpu.eax)++;
    // 004828fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004828fc  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004828ff  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00482905  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00482908  3bc3                   +cmp eax, ebx
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
    // 0048290a  7463                   -je 0x48296f
    if (cpu.flags.zf)
    {
        return sub_48296f(app, cpu);
    }
    // 0048290c  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0048290f  8d3c00                 -lea edi, [eax + eax]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00482912  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482914  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00482917  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00482919  e81254ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0048291e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00482921  8bf4                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00482923  8975dc                 -mov dword ptr [ebp - 0x24], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.esi;
    // 00482926  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482927  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482928  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482929  e8f2edffff             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 0048292e  83c40c                 +add esp, 0xc
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
    // 00482931  eb0b                   -jmp 0x48293e
    return sub_48293e(app, cpu);
}

/* align: skip  */
void Application::sub_482933(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482933  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482935  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482936  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482937(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482937  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0048293a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048293c  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048293e  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482942  3bf3                   +cmp esi, ebx
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
    // 00482944  7429                   -je 0x48296f
    if (cpu.flags.zf)
    {
        goto L_0x0048296f;
    }
    // 00482946  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00482949  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048294a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0048294d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00482950  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482952  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00482955  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048295b  3bc3                   +cmp eax, ebx
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
    // 0048295d  7410                   -je 0x48296f
    if (cpu.flags.zf)
    {
        goto L_0x0048296f;
    }
    // 0048295f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00482962  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482963  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482964  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482967  ff1584714800           -call dword ptr [0x487184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747652) /* 0x487184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048296d  eb02                   -jmp 0x482971
    goto L_0x00482971;
L_0x0048296f:
    // 0048296f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482971:
    // 00482971  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00482974  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00482977  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0048297e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482980  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482981  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482982  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482971(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00482971;
    // 00482937  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0048293a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048293c  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048293e  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482942  3bf3                   +cmp esi, ebx
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
    // 00482944  7429                   -je 0x48296f
    if (cpu.flags.zf)
    {
        goto L_0x0048296f;
    }
    // 00482946  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00482949  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048294a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0048294d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00482950  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482952  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00482955  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048295b  3bc3                   +cmp eax, ebx
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
    // 0048295d  7410                   -je 0x48296f
    if (cpu.flags.zf)
    {
        goto L_0x0048296f;
    }
    // 0048295f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00482962  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482963  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482964  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482967  ff1584714800           -call dword ptr [0x487184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747652) /* 0x487184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048296d  eb02                   -jmp 0x482971
    goto L_0x00482971;
L_0x0048296f:
    // 0048296f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482971:
L_entry_0x00482971:
    // 00482971  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00482974  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00482977  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0048297e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482980  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482981  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482982  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48296f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048296f;
    // 00482937  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0048293a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048293c  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048293e  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482942  3bf3                   +cmp esi, ebx
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
    // 00482944  7429                   -je 0x48296f
    if (cpu.flags.zf)
    {
        goto L_0x0048296f;
    }
    // 00482946  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00482949  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048294a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0048294d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00482950  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482952  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00482955  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048295b  3bc3                   +cmp eax, ebx
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
    // 0048295d  7410                   -je 0x48296f
    if (cpu.flags.zf)
    {
        goto L_0x0048296f;
    }
    // 0048295f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00482962  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482963  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482964  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482967  ff1584714800           -call dword ptr [0x487184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747652) /* 0x487184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048296d  eb02                   -jmp 0x482971
    goto L_0x00482971;
L_0x0048296f:
L_entry_0x0048296f:
    // 0048296f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482971:
    // 00482971  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00482974  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00482977  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0048297e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482980  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482981  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482982  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48293e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048293e;
    // 00482937  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0048293a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048293c  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_entry_0x0048293e:
    // 0048293e  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482942  3bf3                   +cmp esi, ebx
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
    // 00482944  7429                   -je 0x48296f
    if (cpu.flags.zf)
    {
        goto L_0x0048296f;
    }
    // 00482946  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00482949  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048294a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0048294d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00482950  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482952  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00482955  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048295b  3bc3                   +cmp eax, ebx
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
    // 0048295d  7410                   -je 0x48296f
    if (cpu.flags.zf)
    {
        goto L_0x0048296f;
    }
    // 0048295f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00482962  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482963  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482964  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482967  ff1584714800           -call dword ptr [0x487184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747652) /* 0x487184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048296d  eb02                   -jmp 0x482971
    goto L_0x00482971;
L_0x0048296f:
    // 0048296f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482971:
    // 00482971  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00482974  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00482977  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0048297e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048297f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482980  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482981  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482982  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482983(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482983  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 0048298a  7e0e                   -jle 0x48299a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048299a;
    }
    // 0048298c  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0048298e  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482992  e8f2a8ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00482997  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482998  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482999  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048299a:
    // 0048299a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048299e  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 004829a4  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 004829a7  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004829aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__allshl(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004829b0  80f940                 +cmp cl, 0x40
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
    // 004829b3  7315                   -jae 0x4829ca
    if (!cpu.flags.cf)
    {
        goto L_0x004829ca;
    }
    // 004829b5  80f920                 +cmp cl, 0x20
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
    // 004829b8  7306                   -jae 0x4829c0
    if (!cpu.flags.cf)
    {
        goto L_0x004829c0;
    }
    // 004829ba  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 004829bd  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004829bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004829c0:
    // 004829c0  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004829c2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004829c4  80e11f                 -and cl, 0x1f
    cpu.cl &= x86::reg8(x86::sreg8(31 /*0x1f*/));
    // 004829c7  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004829c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004829ca:
    // 004829ca  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004829cc  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004829ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4829cf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004829cf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004829d0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004829d4  83fbff                 +cmp ebx, -1
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
    // 004829d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004829d8  7441                   -je 0x482a1b
    if (cpu.flags.zf)
    {
        goto L_0x00482a1b;
    }
    // 004829da  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004829de  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004829e1  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004829e3  7508                   -jne 0x4829ed
    if (!cpu.flags.zf)
    {
        goto L_0x004829ed;
    }
    // 004829e5  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004829e7  7432                   -je 0x482a1b
    if (cpu.flags.zf)
    {
        goto L_0x00482a1b;
    }
    // 004829e9  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004829eb  752e                   -jne 0x482a1b
    if (!cpu.flags.zf)
    {
        goto L_0x00482a1b;
    }
L_0x004829ed:
    // 004829ed  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004829f1  7507                   -jne 0x4829fa
    if (!cpu.flags.zf)
    {
        goto L_0x004829fa;
    }
    // 004829f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004829f4  e87cf9ffff             -call 0x482375
    cpu.esp -= 4;
    sub_482375(app, cpu);
    // 004829f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004829fa:
    // 004829fa  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004829fc  3b4608                 +cmp eax, dword ptr [esi + 8]
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
    // 004829ff  7509                   -jne 0x482a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00482a0a;
    }
    // 00482a01  837e0400               +cmp dword ptr [esi + 4], 0
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
    // 00482a05  7514                   -jne 0x482a1b
    if (!cpu.flags.zf)
    {
        goto L_0x00482a1b;
    }
    // 00482a07  40                     -inc eax
    (cpu.eax)++;
    // 00482a08  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00482a0a:
    // 00482a0a  f6460c40               +test byte ptr [esi + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 00482a0e  7411                   -je 0x482a21
    if (cpu.flags.zf)
    {
        goto L_0x00482a21;
    }
    // 00482a10  ff0e                   -dec dword ptr [esi]
    (app->getMemory<x86::reg32>(cpu.esi))--;
    // 00482a12  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00482a14  3818                   +cmp byte ptr [eax], bl
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
    // 00482a16  740f                   -je 0x482a27
    if (cpu.flags.zf)
    {
        goto L_0x00482a27;
    }
    // 00482a18  40                     -inc eax
    (cpu.eax)++;
    // 00482a19  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00482a1b:
    // 00482a1b  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00482a1e:
    // 00482a1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482a21:
    // 00482a21  ff0e                   -dec dword ptr [esi]
    (app->getMemory<x86::reg32>(cpu.esi))--;
    // 00482a23  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00482a25  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x00482a27:
    // 00482a27  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00482a2a  ff4604                 -inc dword ptr [esi + 4]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */))++;
    // 00482a2d  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00482a2f  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00482a31  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00482a34  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482a36  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00482a3b  ebe1                   -jmp 0x482a1e
    goto L_0x00482a1e;
}

/* align: skip  */
void Application::sub_482a3d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482a3d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482a3e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00482a40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482a41  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00482a44  f6460c40               +test byte ptr [esi + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 00482a48  0f85c5000000           -jne 0x482b13
    if (!cpu.flags.zf)
    {
        goto L_0x00482b13;
    }
    // 00482a4e  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00482a51  83f8ff                 +cmp eax, -1
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
    // 00482a54  7417                   -je 0x482a6d
    if (cpu.flags.zf)
    {
        goto L_0x00482a6d;
    }
    // 00482a56  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482a58  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00482a5b  83e01f                 +and eax, 0x1f
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/))));
    // 00482a5e  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 00482a65  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00482a68  8d0481                 -lea eax, [ecx + eax*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 00482a6b  eb05                   -jmp 0x482a72
    goto L_0x00482a72;
L_0x00482a6d:
    // 00482a6d  b830644a00             -mov eax, 0x4a6430
    cpu.eax = 4875312 /*0x4a6430*/;
L_0x00482a72:
    // 00482a72  f6400480               +test byte ptr [eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 128 /*0x80*/));
    // 00482a76  0f8497000000           -je 0x482b13
    if (cpu.flags.zf)
    {
        goto L_0x00482b13;
    }
    // 00482a7c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482a7f  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00482a82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482a83  e83ff7ffff             -call 0x4821c7
    cpu.esp -= 4;
    sub_4821c7(app, cpu);
    // 00482a88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a89  83f8ff                 +cmp eax, -1
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
    // 00482a8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a8d  7514                   -jne 0x482aa3
    if (!cpu.flags.zf)
    {
        goto L_0x00482aa3;
    }
    // 00482a8f  e81ebaffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00482a94  c7002a000000           -mov dword ptr [eax], 0x2a
    app->getMemory<x86::reg32>(cpu.eax) = 42 /*0x2a*/;
L_0x00482a9a:
    // 00482a9a  660dffff               +or ax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(65535 /*0xffff*/))));
    // 00482a9e  e990000000             -jmp 0x482b33
    goto L_0x00482b33;
L_0x00482aa3:
    // 00482aa3  83f801                 +cmp eax, 1
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
    // 00482aa6  752c                   -jne 0x482ad4
    if (!cpu.flags.zf)
    {
        goto L_0x00482ad4;
    }
    // 00482aa8  ff4e04                 +dec dword ptr [esi + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482aab  780f                   -js 0x482abc
    if (cpu.flags.sf)
    {
        goto L_0x00482abc;
    }
    // 00482aad  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00482aaf  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00482ab2  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00482ab4  0fb6450c               -movzx eax, byte ptr [ebp + 0xc]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */));
L_0x00482ab8:
    // 00482ab8  ff06                   +inc dword ptr [esi]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00482aba  eb0d                   -jmp 0x482ac9
    goto L_0x00482ac9;
L_0x00482abc:
    // 00482abc  0fbe450c               -movsx eax, byte ptr [ebp + 0xc]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00482ac0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00482ac1:
    // 00482ac1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482ac2  e82188ffff             -call 0x47b2e8
    cpu.esp -= 4;
    sub_47b2e8(app, cpu);
    // 00482ac7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ac8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482ac9:
    // 00482ac9  83f8ff                 +cmp eax, -1
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
    // 00482acc  74cc                   -je 0x482a9a
    if (cpu.flags.zf)
    {
        goto L_0x00482a9a;
    }
    // 00482ace  668b4508               -mov ax, word ptr [ebp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482ad2  eb5f                   -jmp 0x482b33
    goto L_0x00482b33;
L_0x00482ad4:
    // 00482ad4  ff4e04                 +dec dword ptr [esi + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482ad7  780f                   -js 0x482ae8
    if (cpu.flags.sf)
    {
        goto L_0x00482ae8;
    }
    // 00482ad9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00482adb  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00482ade  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00482ae0  ff06                   +inc dword ptr [esi]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00482ae2  0fb6450c               -movzx eax, byte ptr [ebp + 0xc]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 00482ae6  eb0d                   -jmp 0x482af5
    goto L_0x00482af5;
L_0x00482ae8:
    // 00482ae8  0fbe450c               -movsx eax, byte ptr [ebp + 0xc]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00482aec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482aed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482aee  e8f587ffff             -call 0x47b2e8
    cpu.esp -= 4;
    sub_47b2e8(app, cpu);
    // 00482af3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482af4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482af5:
    // 00482af5  83f8ff                 +cmp eax, -1
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
    // 00482af8  74a0                   -je 0x482a9a
    if (cpu.flags.zf)
    {
        goto L_0x00482a9a;
    }
    // 00482afa  ff4e04                 +dec dword ptr [esi + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00482afd  780d                   -js 0x482b0c
    if (cpu.flags.sf)
    {
        goto L_0x00482b0c;
    }
    // 00482aff  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00482b01  8a4d0d                 -mov cl, byte ptr [ebp + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 00482b04  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00482b06  0fb6450d               -movzx eax, byte ptr [ebp + 0xd]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */));
    // 00482b0a  ebac                   -jmp 0x482ab8
    goto L_0x00482ab8;
L_0x00482b0c:
    // 00482b0c  0fbe450d               -movsx eax, byte ptr [ebp + 0xd]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */)));
    // 00482b10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482b11  ebae                   -jmp 0x482ac1
    goto L_0x00482ac1;
L_0x00482b13:
    // 00482b13  834604fe               +add dword ptr [esi + 4], -2
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00482b17  780d                   -js 0x482b26
    if (cpu.flags.sf)
    {
        goto L_0x00482b26;
    }
    // 00482b19  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00482b1b  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482b1e  668901                 -mov word ptr [ecx], ax
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.ax;
    // 00482b21  830602                 +add dword ptr [esi], 2
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00482b24  eb0d                   -jmp 0x482b33
    goto L_0x00482b33;
L_0x00482b26:
    // 00482b26  0fb74508               -movzx eax, word ptr [ebp + 8]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 00482b2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482b2b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482b2c  e84f210000             -call 0x484c80
    cpu.esp -= 4;
    sub_484c80(app, cpu);
    // 00482b31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482b33:
    // 00482b33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482b36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482b36  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482b37  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b38  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482b39  8b3508eb5100           -mov esi, dword ptr [0x51eb08]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */);
    // 00482b3f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482b40  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00482b42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482b44  744c                   -je 0x482b92
    if (cpu.flags.zf)
    {
        goto L_0x00482b92;
    }
    // 00482b46  8b1dbc714800           -mov ebx, dword ptr [0x4871bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
L_0x00482b4c:
    // 00482b4c  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00482b4e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b4f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b50  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00482b52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482b53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b54  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482b56  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00482b58  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482b5a  3bfd                   +cmp edi, ebp
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
    // 00482b5c  743b                   -je 0x482b99
    if (cpu.flags.zf)
    {
        goto L_0x00482b99;
    }
    // 00482b5e  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00482b61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482b62  e81347ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00482b67  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00482b69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b6a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00482b6c  742b                   -je 0x482b99
    if (cpu.flags.zf)
    {
        goto L_0x00482b99;
    }
    // 00482b6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482b6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b70  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00482b72  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 00482b74  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482b76  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482b78  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00482b7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482b7c  741b                   -je 0x482b99
    if (cpu.flags.zf)
    {
        goto L_0x00482b99;
    }
    // 00482b7e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482b80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b81  e80ac2ffff             -call 0x47ed90
    cpu.esp -= 4;
    sub_47ed90(app, cpu);
    // 00482b86  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00482b89  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482b8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482b8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b90  75ba                   -jne 0x482b4c
    if (!cpu.flags.zf)
    {
        goto L_0x00482b4c;
    }
L_0x00482b92:
    // 00482b92  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00482b94:
    // 00482b94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482b99:
    // 00482b99  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00482b9c  ebf6                   -jmp 0x482b94
    goto L_0x00482b94;
}

/* align: skip  */
void Application::sub_482b9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482b9e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00482ba2:
    // 00482ba2  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00482ba5  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00482ba8  740b                   -je 0x482bb5
    if (cpu.flags.zf)
    {
        goto L_0x00482bb5;
    }
    // 00482baa  663b4c2408             +cmp cx, word ptr [esp + 8]
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00482baf  7404                   -je 0x482bb5
    if (cpu.flags.zf)
    {
        goto L_0x00482bb5;
    }
    // 00482bb1  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00482bb2  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00482bb3  ebed                   -jmp 0x482ba2
    goto L_0x00482ba2;
L_0x00482bb5:
    // 00482bb5  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00482bb8  662b4c2408             -sub cx, word ptr [esp + 8]
    (cpu.cx) -= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00482bbd  66f7d9                 +neg cx
    {
        x86::reg16 tmp1 = 0;
        x86::reg16& tmp2 = cpu.cx;
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00482bc0  1bc9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00482bc2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00482bc4  23c1                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482bc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482bc7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482bc7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482bc8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00482bca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482bcb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482bcc  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482bce  395d10                 +cmp dword ptr [ebp + 0x10], ebx
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
    // 00482bd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482bd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482bd3  7507                   -jne 0x482bdc
    if (!cpu.flags.zf)
    {
        goto L_0x00482bdc;
    }
    // 00482bd5  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482bd7  e9c7000000             -jmp 0x482ca3
    goto L_0x00482ca3;
L_0x00482bdc:
    // 00482bdc  391dc0eb5100           +cmp dword ptr [0x51ebc0], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368768) /* 0x51ebc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482be2  744c                   -je 0x482c30
    if (cpu.flags.zf)
    {
        goto L_0x00482c30;
    }
    // 00482be4  bee81f5200             -mov esi, 0x521fe8
    cpu.esi = 5382120 /*0x521fe8*/;
    // 00482be9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482bea  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00482bf0  391de41f5200           +cmp dword ptr [0x521fe4], ebx
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
    // 00482bf6  8b3d8c714800           -mov edi, dword ptr [0x48718c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    // 00482bfc  7414                   -je 0x482c12
    if (cpu.flags.zf)
    {
        goto L_0x00482c12;
    }
    // 00482bfe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482bff  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00482c01  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00482c03  e8c19effff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00482c08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c09  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00482c10  eb03                   -jmp 0x482c15
    goto L_0x00482c15;
L_0x00482c12:
    // 00482c12  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
L_0x00482c15:
    // 00482c15  a1c0eb5100             -mov eax, dword ptr [0x51ebc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368768) /* 0x51ebc0 */);
    // 00482c1a  3bc3                   +cmp eax, ebx
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
    // 00482c1c  7525                   -jne 0x482c43
    if (!cpu.flags.zf)
    {
        goto L_0x00482c43;
    }
    // 00482c1e  395dfc                 +cmp dword ptr [ebp - 4], ebx
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
    // 00482c21  740a                   -je 0x482c2d
    if (cpu.flags.zf)
    {
        goto L_0x00482c2d;
    }
    // 00482c23  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00482c25  e8009fffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00482c2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c2b  eb03                   -jmp 0x482c30
    goto L_0x00482c30;
L_0x00482c2d:
    // 00482c2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482c2e  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00482c30:
    // 00482c30  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00482c33  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00482c36  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482c39  e884230000             -call 0x484fc2
    cpu.esp -= 4;
    sub_484fc2(app, cpu);
    // 00482c3e  83c40c                 +add esp, 0xc
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
    // 00482c41  eb60                   -jmp 0x482ca3
    goto L_0x00482ca3;
L_0x00482c43:
    // 00482c43  ff35d8eb5100           -push dword ptr [0x51ebd8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368792) /* 0x51ebd8 */);
    cpu.esp -= 4;
    // 00482c49  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00482c4c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00482c4f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00482c52  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482c55  6801100000             -push 0x1001
    app->getMemory<x86::reg32>(cpu.esp-4) = 4097 /*0x1001*/;
    cpu.esp -= 4;
    // 00482c5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482c5b  e847210000             -call 0x484da7
    cpu.esp -= 4;
    sub_484da7(app, cpu);
    // 00482c60  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482c62  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00482c65  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482c67  7524                   -jne 0x482c8d
    if (!cpu.flags.zf)
    {
        goto L_0x00482c8d;
    }
    // 00482c69  3945fc                 +cmp dword ptr [ebp - 4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482c6c  740a                   -je 0x482c78
    if (cpu.flags.zf)
    {
        goto L_0x00482c78;
    }
    // 00482c6e  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00482c70  e8b59effff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00482c75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c76  eb03                   -jmp 0x482c7b
    goto L_0x00482c7b;
L_0x00482c78:
    // 00482c78  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482c79  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00482c7b:
    // 00482c7b  e832b8ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00482c80  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
    // 00482c86  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 00482c8b  eb16                   -jmp 0x482ca3
    goto L_0x00482ca3;
L_0x00482c8d:
    // 00482c8d  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00482c91  740a                   -je 0x482c9d
    if (cpu.flags.zf)
    {
        goto L_0x00482c9d;
    }
    // 00482c93  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00482c95  e8909effff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00482c9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c9b  eb03                   -jmp 0x482ca0
    goto L_0x00482ca0;
L_0x00482c9d:
    // 00482c9d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482c9e  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00482ca0:
    // 00482ca0  8d43fe                 -lea eax, [ebx - 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-2) /* -0x2 */);
L_0x00482ca3:
    // 00482ca3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ca4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ca5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ca6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ca7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482ca8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482ca8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482ca9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482cad  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482caf  7421                   -je 0x482cd2
    if (cpu.flags.zf)
    {
        goto L_0x00482cd2;
    }
    // 00482cb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482cb2  e8e650ffff             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 00482cb7  8d440002               -lea eax, [eax + eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 00482cbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482cbc  e8b945ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00482cc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482cc4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cc5  740b                   -je 0x482cd2
    if (cpu.flags.zf)
    {
        goto L_0x00482cd2;
    }
    // 00482cc7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482cc8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482cc9  e8aa50ffff             -call 0x477d78
    cpu.esp -= 4;
    sub_477d78(app, cpu);
    // 00482cce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ccf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482cd2:
    // 00482cd2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482cd4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482cd6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482cd6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482cd7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00482cd9  833dbc1c520000         +cmp dword ptr [0x521cbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5381308) /* 0x521cbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482ce1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482ce2  750f                   -jne 0x482cf3
    if (!cpu.flags.zf)
    {
        goto L_0x00482cf3;
    }
    // 00482ce4  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00482ce7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482cea  e88171ffff             -call 0x479e70
    cpu.esp -= 4;
    _strchr(app, cpu);
    // 00482cef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482cf1  eb76                   -jmp 0x482d69
    goto L_0x00482d69;
L_0x00482cf3:
    // 00482cf3  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00482cf5  e8cf9dffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00482cfa  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482cfd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482cfe:
    // 00482cfe  660fb61e               -movzx bx, byte ptr [esi]
    cpu.bx = x86::reg16(app->getMemory<x86::reg8>(cpu.esi));
    // 00482d02  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00482d05  744a                   -je 0x482d51
    if (cpu.flags.zf)
    {
        goto L_0x00482d51;
    }
    // 00482d07  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00482d0a  f680c11d520004         +test byte ptr [eax + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00482d11  741a                   -je 0x482d2d
    if (cpu.flags.zf)
    {
        goto L_0x00482d2d;
    }
    // 00482d13  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00482d16  46                     -inc esi
    (cpu.esi)++;
    // 00482d17  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00482d19  741d                   -je 0x482d38
    if (cpu.flags.zf)
    {
        goto L_0x00482d38;
    }
    // 00482d1b  0fb7cb                 -movzx ecx, bx
    cpu.ecx = x86::reg32(cpu.bx);
    // 00482d1e  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 00482d21  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00482d24  0bc8                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00482d26  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
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
    // 00482d29  7419                   -je 0x482d44
    if (cpu.flags.zf)
    {
        goto L_0x00482d44;
    }
    // 00482d2b  eb08                   -jmp 0x482d35
    goto L_0x00482d35;
L_0x00482d2d:
    // 00482d2d  0fb7c3                 -movzx eax, bx
    cpu.eax = x86::reg32(cpu.bx);
    // 00482d30  39450c                 +cmp dword ptr [ebp + 0xc], eax
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
    // 00482d33  741c                   -je 0x482d51
    if (cpu.flags.zf)
    {
        goto L_0x00482d51;
    }
L_0x00482d35:
    // 00482d35  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00482d36  ebc6                   -jmp 0x482cfe
    goto L_0x00482cfe;
L_0x00482d38:
    // 00482d38  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00482d3a  e8eb9dffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00482d3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d40  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482d42  eb25                   -jmp 0x482d69
    goto L_0x00482d69;
L_0x00482d44:
    // 00482d44  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00482d46  e8df9dffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00482d4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d4c  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00482d4f  eb18                   -jmp 0x482d69
    goto L_0x00482d69;
L_0x00482d51:
    // 00482d51  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00482d53  e8d29dffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00482d58  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00482d5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d5c  0fb7cb                 -movzx ecx, bx
    cpu.ecx = x86::reg32(cpu.bx);
    // 00482d5f  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482d61  f7d8                   +neg eax
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
    // 00482d63  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00482d65  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00482d67  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x00482d69:
    // 00482d69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d6b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482d6d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482d6e  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482d72  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482d74  741e                   -je 0x482d94
    if (cpu.flags.zf)
    {
        goto L_0x00482d94;
    }
    // 00482d76  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482d77  e864b0ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00482d7c  40                     -inc eax
    (cpu.eax)++;
    // 00482d7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482d7e  e8f744ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00482d83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482d86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d87  740b                   -je 0x482d94
    if (cpu.flags.zf)
    {
        goto L_0x00482d94;
    }
    // 00482d89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482d8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482d8b  e8a0c4ffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00482d90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482d94:
    // 00482d94  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482d96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482d97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482d98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482d98  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482d9c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482d9d  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482d9f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00482da2  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00482da5  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00482da8  be00800000             -mov esi, 0x8000
    cpu.esi = 32768 /*0x8000*/;
    // 00482dad  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 00482db4  8d548104               -lea edx, [ecx + eax*4 + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 00482db8  8a4c8104               -mov cl, byte ptr [ecx + eax*4 + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 00482dbc  8ac1                   -mov al, cl
    cpu.al = cpu.cl;
    // 00482dbe  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00482dc3  3974240c               +cmp dword ptr [esp + 0xc], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482dc7  7505                   -jne 0x482dce
    if (!cpu.flags.zf)
    {
        goto L_0x00482dce;
    }
    // 00482dc9  80e17f                 +and cl, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(127 /*0x7f*/))));
    // 00482dcc  eb0d                   -jmp 0x482ddb
    goto L_0x00482ddb;
L_0x00482dce:
    // 00482dce  817c240c00400000       +cmp dword ptr [esp + 0xc], 0x4000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482dd6  7511                   -jne 0x482de9
    if (!cpu.flags.zf)
    {
        goto L_0x00482de9;
    }
    // 00482dd8  80c980                 -or cl, 0x80
    cpu.cl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00482ddb:
    // 00482ddb  f7d8                   +neg eax
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
    // 00482ddd  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00482ddf  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00482de1  662500c0               -and ax, 0xc000
    cpu.ax &= x86::reg16(x86::sreg16(49152 /*0xc000*/));
    // 00482de5  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00482de7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482de8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482de9:
    // 00482de9  e8c4b6ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00482dee  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
    // 00482df4  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482df7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482df9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482df9  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 00482dfd  ff155c714800           -call dword ptr [0x48715c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747612) /* 0x48715c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00482e03  83f8ff                 +cmp eax, -1
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
    // 00482e06  7511                   -jne 0x482e19
    if (!cpu.flags.zf)
    {
        goto L_0x00482e19;
    }
    // 00482e08  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00482e0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482e0f  e82bb6ffff             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 00482e14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482e15:
    // 00482e15  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482e18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482e19:
    // 00482e19  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00482e1b  741f                   -je 0x482e3c
    if (cpu.flags.zf)
    {
        goto L_0x00482e3c;
    }
    // 00482e1d  f644240802             +test byte ptr [esp + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00482e22  7418                   -je 0x482e3c
    if (cpu.flags.zf)
    {
        goto L_0x00482e3c;
    }
    // 00482e24  e889b6ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00482e29  c7000d000000           -mov dword ptr [eax], 0xd
    app->getMemory<x86::reg32>(cpu.eax) = 13 /*0xd*/;
    // 00482e2f  e887b6ffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00482e34  c70005000000           -mov dword ptr [eax], 5
    app->getMemory<x86::reg32>(cpu.eax) = 5 /*0x5*/;
    // 00482e3a  ebd9                   -jmp 0x482e15
    goto L_0x00482e15;
L_0x00482e3c:
    // 00482e3c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482e3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482e3f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482e3f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482e40  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00482e42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482e43  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00482e45  3935bc1c5200           +cmp dword ptr [0x521cbc], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5381308) /* 0x521cbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482e4b  750f                   -jne 0x482e5c
    if (!cpu.flags.zf)
    {
        goto L_0x00482e5c;
    }
    // 00482e4d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00482e50  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00482e53  e868220000             -call 0x4850c0
    cpu.esp -= 4;
    _strrchr(app, cpu);
    // 00482e58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e5a  eb52                   -jmp 0x482eae
    goto L_0x00482eae;
L_0x00482e5c:
    // 00482e5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482e5d  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00482e5f  e8659cffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00482e64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e65  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00482e68:
    // 00482e68  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00482e6a  0fb6c2                 -movzx eax, dl
    cpu.eax = x86::reg32(cpu.dl);
    // 00482e6d  0fb6f8                 -movzx edi, al
    cpu.edi = x86::reg32(cpu.al);
    // 00482e70  f687c11d520004         +test byte ptr [edi + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00482e77  741e                   -je 0x482e97
    if (cpu.flags.zf)
    {
        goto L_0x00482e97;
    }
    // 00482e79  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00482e7c  41                     -inc ecx
    (cpu.ecx)++;
    // 00482e7d  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00482e7f  7412                   -je 0x482e93
    if (cpu.flags.zf)
    {
        goto L_0x00482e93;
    }
    // 00482e81  0fb6fa                 -movzx edi, dl
    cpu.edi = x86::reg32(cpu.dl);
    // 00482e84  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00482e87  0bc7                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00482e89  39450c                 +cmp dword ptr [ebp + 0xc], eax
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
    // 00482e8c  7510                   -jne 0x482e9e
    if (!cpu.flags.zf)
    {
        goto L_0x00482e9e;
    }
    // 00482e8e  8d71ff                 -lea esi, [ecx - 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00482e91  eb0b                   -jmp 0x482e9e
    goto L_0x00482e9e;
L_0x00482e93:
    // 00482e93  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482e95  eb03                   -jmp 0x482e9a
    goto L_0x00482e9a;
L_0x00482e97:
    // 00482e97  39450c                 +cmp dword ptr [ebp + 0xc], eax
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
L_0x00482e9a:
    // 00482e9a  7502                   -jne 0x482e9e
    if (!cpu.flags.zf)
    {
        goto L_0x00482e9e;
    }
    // 00482e9c  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00482e9e:
    // 00482e9e  41                     -inc ecx
    (cpu.ecx)++;
    // 00482e9f  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00482ea1  75c5                   -jne 0x482e68
    if (!cpu.flags.zf)
    {
        goto L_0x00482e68;
    }
    // 00482ea3  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00482ea5  e8809cffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00482eaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eab  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482ead  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482eae:
    // 00482eae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482eb1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482eb1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482eb2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00482eb4  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00482eb7  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00482eba  8065ff00               -and byte ptr [ebp - 1], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00482ebe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482ebf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482ec0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482ec1  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00482ec3  3bc7                   +cmp eax, edi
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
    // 00482ec5  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 00482ec8  7415                   -je 0x482edf
    if (cpu.flags.zf)
    {
        goto L_0x00482edf;
    }
    // 00482eca  83f801                 +cmp eax, 1
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
    // 00482ecd  7410                   -je 0x482edf
    if (cpu.flags.zf)
    {
        goto L_0x00482edf;
    }
    // 00482ecf  7e30                   -jle 0x482f01
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482f01;
    }
    // 00482ed1  83f803                 +cmp eax, 3
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
    // 00482ed4  7e09                   -jle 0x482edf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482edf;
    }
    // 00482ed6  83f804                 +cmp eax, 4
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
    // 00482ed9  7526                   -jne 0x482f01
    if (!cpu.flags.zf)
    {
        goto L_0x00482f01;
    }
    // 00482edb  c645ff01               -mov byte ptr [ebp - 1], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = 1 /*0x1*/;
L_0x00482edf:
    // 00482edf  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00482ee2  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00482ee5:
    // 00482ee5  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00482ee7  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00482ee9  742d                   -je 0x482f18
    if (cpu.flags.zf)
    {
        goto L_0x00482f18;
    }
L_0x00482eeb:
    // 00482eeb  40                     -inc eax
    (cpu.eax)++;
    // 00482eec  803800                 +cmp byte ptr [eax], 0
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
    // 00482eef  75fa                   -jne 0x482eeb
    if (!cpu.flags.zf)
    {
        goto L_0x00482eeb;
    }
    // 00482ef1  80780100               +cmp byte ptr [eax + 1], 0
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
    // 00482ef5  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00482ef8  74eb                   -je 0x482ee5
    if (cpu.flags.zf)
    {
        goto L_0x00482ee5;
    }
    // 00482efa  c60020                 -mov byte ptr [eax], 0x20
    app->getMemory<x86::reg8>(cpu.eax) = 32 /*0x20*/;
    // 00482efd  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482eff  ebe4                   -jmp 0x482ee5
    goto L_0x00482ee5;
L_0x00482f01:
    // 00482f01  e8acb5ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00482f06  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
    // 00482f0c  e8aab5ffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00482f11  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 00482f13  e924010000             -jmp 0x48303c
    goto L_0x0048303c;
L_0x00482f18:
    // 00482f18  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 00482f1a  8d45a0                 -lea eax, [ebp - 0x60]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 00482f1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f1e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482f1f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482f20  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482f21  e8fae7ffff             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 00482f26  8975a0                 -mov dword ptr [ebp - 0x60], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = cpu.esi;
    // 00482f29  8b35e01f5200           -mov esi, dword ptr [0x521fe0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */);
    // 00482f2f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00482f32  3bf7                   +cmp esi, edi
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
    // 00482f34  7424                   -je 0x482f5a
    if (cpu.flags.zf)
    {
        goto L_0x00482f5a;
    }
    // 00482f36  8d4eff                 -lea ecx, [esi - 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
L_0x00482f39:
    // 00482f39  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00482f3b  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482f3d  c1fa05                 -sar edx, 5
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (5 /*0x5*/ % 32));
    // 00482f40  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00482f43  8b1495e01e5200         -mov edx, dword ptr [edx*4 + 0x521ee0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.edx * 4);
    // 00482f4a  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00482f4d  807c820400             +cmp byte ptr [edx + eax*4 + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482f52  7506                   -jne 0x482f5a
    if (!cpu.flags.zf)
    {
        goto L_0x00482f5a;
    }
    // 00482f54  4e                     -dec esi
    (cpu.esi)--;
    // 00482f55  49                     -dec ecx
    (cpu.ecx)--;
    // 00482f56  3bf7                   +cmp esi, edi
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
    // 00482f58  75df                   -jne 0x482f39
    if (!cpu.flags.zf)
    {
        goto L_0x00482f39;
    }
L_0x00482f5a:
    // 00482f5a  8d44b604               -lea eax, [esi + esi*4 + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.esi * 4);
    // 00482f5e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482f60  668945d2               -mov word ptr [ebp - 0x2e], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-46) /* -0x2e */) = cpu.ax;
    // 00482f64  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 00482f67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482f68  e8fb74ffff             -call 0x47a468
    cpu.esp -= 4;
    sub_47a468(app, cpu);
    // 00482f6d  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 00482f70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f71  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00482f73  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00482f76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482f77  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482f79  3bf7                   +cmp esi, edi
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
    // 00482f7b  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00482f7e  8d543004               -lea edx, [eax + esi + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00482f82  7e3a                   -jle 0x482fbe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482fbe;
    }
L_0x00482f84:
    // 00482f84  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00482f86  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482f88  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00482f8b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00482f8e  8b3cbde01e5200         -mov edi, dword ptr [edi*4 + 0x521ee0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.edi * 4);
    // 00482f95  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00482f98  8d3c87                 -lea edi, [edi + eax*4]
    cpu.edi = x86::reg32(cpu.edi + cpu.eax * 4);
    // 00482f9b  8a4704                 -mov al, byte ptr [edi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00482f9e  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00482fa0  7508                   -jne 0x482faa
    if (!cpu.flags.zf)
    {
        goto L_0x00482faa;
    }
    // 00482fa2  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00482fa4  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00482fa6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00482fa8  eb06                   -jmp 0x482fb0
    goto L_0x00482fb0;
L_0x00482faa:
    // 00482faa  802100                 -and byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00482fad  830aff                 -or dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00482fb0:
    // 00482fb0  43                     -inc ebx
    (cpu.ebx)++;
    // 00482fb1  41                     -inc ecx
    (cpu.ecx)++;
    // 00482fb2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00482fb5  3bde                   +cmp ebx, esi
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
    // 00482fb7  7ccb                   -jl 0x482f84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00482f84;
    }
    // 00482fb9  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00482fbc  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00482fbe:
    // 00482fbe  807dff00               +cmp byte ptr [ebp - 1], 0
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
    // 00482fc2  742d                   -je 0x482ff1
    if (cpu.flags.zf)
    {
        goto L_0x00482ff1;
    }
    // 00482fc4  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00482fc7  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482fc9  8d443004               -lea eax, [eax + esi + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
L_0x00482fcd:
    // 00482fcd  83fe03                 +cmp esi, 3
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
    // 00482fd0  7d04                   -jge 0x482fd6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00482fd6;
    }
    // 00482fd2  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00482fd4  eb03                   -jmp 0x482fd9
    goto L_0x00482fd9;
L_0x00482fd6:
    // 00482fd6  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00482fd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00482fd9:
    // 00482fd9  3bd3                   +cmp edx, ebx
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
    // 00482fdb  7d0d                   -jge 0x482fea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00482fea;
    }
    // 00482fdd  802100                 -and byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00482fe0  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00482fe3  42                     -inc edx
    (cpu.edx)++;
    // 00482fe4  41                     -inc ecx
    (cpu.ecx)++;
    // 00482fe5  83c004                 +add eax, 4
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
    // 00482fe8  ebe3                   -jmp 0x482fcd
    goto L_0x00482fcd;
L_0x00482fea:
    // 00482fea  c745f808000000         -mov dword ptr [ebp - 8], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 8 /*0x8*/;
L_0x00482ff1:
    // 00482ff1  e8bcb4ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00482ff6  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 00482ff8  e8beb4ffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00482ffd  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 00482fff  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00483002  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483003  8d45a0                 -lea eax, [ebp - 0x60]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 00483006  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483007  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483008  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0048300b  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0048300e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00483010  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483011  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483012  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 00483015  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00483018  ff15c0704800           -call dword ptr [0x4870c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747456) /* 0x4870c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048301e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483020  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483026  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 00483029  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048302b  e88443ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00483030  3bf7                   +cmp esi, edi
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
    // 00483032  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483033  750c                   -jne 0x483041
    if (!cpu.flags.zf)
    {
        goto L_0x00483041;
    }
    // 00483035  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483036  e804b4ffff             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 0048303b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048303c:
    // 0048303c  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0048303f  eb54                   -jmp 0x483095
    goto L_0x00483095;
L_0x00483041:
    // 00483041  837d0802               +cmp dword ptr [ebp + 8], 2
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
    // 00483045  7506                   -jne 0x48304d
    if (!cpu.flags.zf)
    {
        goto L_0x0048304d;
    }
    // 00483047  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483048  e82356ffff             -call 0x478670
    cpu.esp -= 4;
    __exit(app, cpu);
L_0x0048304d:
    // 0048304d  397d08                 +cmp dword ptr [ebp + 8], edi
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
    // 00483050  8b35d4704800           -mov esi, dword ptr [0x4870d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747476) /* 0x4870d4 */);
    // 00483056  751f                   -jne 0x483077
    if (!cpu.flags.zf)
    {
        goto L_0x00483077;
    }
    // 00483058  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0048305a  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0048305d  ff15d0704800           -call dword ptr [0x4870d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747472) /* 0x4870d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483063  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00483066  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483067  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0048306a  ff15b4704800           -call dword ptr [0x4870b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747444) /* 0x4870b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483070  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 00483073  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483075  eb16                   -jmp 0x48308d
    goto L_0x0048308d;
L_0x00483077:
    // 00483077  837d0804               +cmp dword ptr [ebp + 8], 4
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
    // 0048307b  750a                   -jne 0x483087
    if (!cpu.flags.zf)
    {
        goto L_0x00483087;
    }
    // 0048307d  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 00483080  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483082  897d10                 -mov dword ptr [ebp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00483085  eb06                   -jmp 0x48308d
    goto L_0x0048308d;
L_0x00483087:
    // 00483087  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0048308a  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0048308d:
    // 0048308d  ff75e8                 -push dword ptr [ebp - 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    // 00483090  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483092  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x00483095:
    // 00483095  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483096  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483097  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483098  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483099  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48309a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048309a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048309b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048309d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048309e  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004830a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004830a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004830a3  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004830a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830a6  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004830a8:
    // 004830a8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004830aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004830ac  7410                   -je 0x4830be
    if (cpu.flags.zf)
    {
        goto L_0x004830be;
    }
    // 004830ae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004830af  83c304                 +add ebx, 4
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
    // 004830b2  e829adffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 004830b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830b8  8d7c0701               -lea edi, [edi + eax + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004830bc  ebea                   -jmp 0x4830a8
    goto L_0x004830a8;
L_0x004830be:
    // 004830be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004830bf  e8b641ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 004830c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830c5  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004830c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004830ca  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004830cc  750b                   -jne 0x4830d9
    if (!cpu.flags.zf)
    {
        goto L_0x004830d9;
    }
    // 004830ce  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004830d1  832000                 +and dword ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 004830d4  e9e2000000             -jmp 0x4831bb
    goto L_0x004831bb;
L_0x004830d9:
    // 004830d9  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004830dc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004830de  7416                   -je 0x4830f6
    if (cpu.flags.zf)
    {
        goto L_0x004830f6;
    }
L_0x004830e0:
    // 004830e0  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004830e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004830e4  7437                   -je 0x48311d
    if (cpu.flags.zf)
    {
        goto L_0x0048311d;
    }
    // 004830e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004830e7  83c704                 +add edi, 4
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
    // 004830ea  e8f1acffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 004830ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830f0  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004830f4  ebea                   -jmp 0x4830e0
    goto L_0x004830e0;
L_0x004830f6:
    // 004830f6  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004830f9  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004830fc  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004830ff  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00483102:
    // 00483102  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00483105  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00483107  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048310a  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048310d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048310f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483111  0f85c2000000           -jne 0x4831d9
    if (!cpu.flags.zf)
    {
        goto L_0x004831d9;
    }
L_0x00483117:
    // 00483117  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483118  e9db000000             -jmp 0x4831f8
    goto L_0x004831f8;
L_0x0048311d:
    // 0048311d  a12ceb5100             -mov eax, dword ptr [0x51eb2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */);
    // 00483122  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483124  7512                   -jne 0x483138
    if (!cpu.flags.zf)
    {
        goto L_0x00483138;
    }
    // 00483126  e801daffff             -call 0x480b2c
    cpu.esp -= 4;
    sub_480b2c(app, cpu);
    // 0048312b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048312d  a32ceb5100             -mov dword ptr [0x51eb2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */) = cpu.eax;
    // 00483132  0f8499000000           -je 0x4831d1
    if (cpu.flags.zf)
    {
        goto L_0x004831d1;
    }
L_0x00483138:
    // 00483138  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048313a  3818                   +cmp byte ptr [eax], bl
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
    // 0048313c  7423                   -je 0x483161
    if (cpu.flags.zf)
    {
        goto L_0x00483161;
    }
    // 0048313e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00483140  8a0f                   -mov cl, byte ptr [edi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi);
L_0x00483142:
    // 00483142  80f93d                 +cmp cl, 0x3d
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
    // 00483145  741a                   -je 0x483161
    if (cpu.flags.zf)
    {
        goto L_0x00483161;
    }
    // 00483147  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483148  e893acffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0048314d  8d5c0301               -lea ebx, [ebx + eax + 1]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00483151  a12ceb5100             -mov eax, dword ptr [0x51eb2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */);
    // 00483156  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483157  8a0c18                 -mov cl, byte ptr [eax + ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 0048315a  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0048315d  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0048315f  75e1                   -jne 0x483142
    if (!cpu.flags.zf)
    {
        goto L_0x00483142;
    }
L_0x00483161:
    // 00483161  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00483163  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00483165:
    // 00483165  80383d                 +cmp byte ptr [eax], 0x3d
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
    // 00483168  7529                   -jne 0x483193
    if (!cpu.flags.zf)
    {
        goto L_0x00483193;
    }
    // 0048316a  80780100               +cmp byte ptr [eax + 1], 0
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
    // 0048316e  7423                   -je 0x483193
    if (cpu.flags.zf)
    {
        goto L_0x00483193;
    }
    // 00483170  8078023a               +cmp byte ptr [eax + 2], 0x3a
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
    // 00483174  751d                   -jne 0x483193
    if (!cpu.flags.zf)
    {
        goto L_0x00483193;
    }
    // 00483176  8078033d               +cmp byte ptr [eax + 3], 0x3d
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
    // 0048317a  7517                   -jne 0x483193
    if (!cpu.flags.zf)
    {
        goto L_0x00483193;
    }
    // 0048317c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048317f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483180  e85bacffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00483185  8d7c0705               -lea edi, [edi + eax + 5]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5) /* 0x5 */ + cpu.eax * 1);
    // 00483189  a12ceb5100             -mov eax, dword ptr [0x51eb2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */);
    // 0048318e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048318f  03c7                   +add eax, edi
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
    // 00483191  ebd2                   -jmp 0x483165
    goto L_0x00483165;
L_0x00483193:
    // 00483193  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483195  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483197  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00483199  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048319a  e8db40ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0048319f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831a0  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004831a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004831a5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004831a7  0f8555ffffff           -jne 0x483102
    if (!cpu.flags.zf)
    {
        goto L_0x00483102;
    }
    // 004831ad  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004831b0  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 004831b2  e8fd41ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 004831b7  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004831ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004831bb:
    // 004831bb  e8f2b2ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 004831c0  c7000c000000           -mov dword ptr [eax], 0xc
    app->getMemory<x86::reg32>(cpu.eax) = 12 /*0xc*/;
    // 004831c6  e8f0b2ffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 004831cb  c70008000000           -mov dword ptr [eax], 8
    app->getMemory<x86::reg32>(cpu.eax) = 8 /*0x8*/;
L_0x004831d1:
    // 004831d1  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004831d4  e9c2000000             -jmp 0x48329b
    goto L_0x0048329b;
L_0x004831d9:
    // 004831d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004831da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004831db  e850c0ffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 004831e0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004831e3  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004831e5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004831e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004831e9  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004831ec  e8efabffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 004831f1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004831f4  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
L_0x004831f8:
    // 004831f8  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004831fb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004831fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004831ff  7423                   -je 0x483224
    if (cpu.flags.zf)
    {
        goto L_0x00483224;
    }
    // 00483201  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483202  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483203  e828c0ffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00483208  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048320b  83451004               -add dword ptr [ebp + 0x10], 4
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048320f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00483211  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483212  e8c9abffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00483217  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048321a  03f0                   +add esi, eax
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
    // 0048321c  c60620                 -mov byte ptr [esi], 0x20
    app->getMemory<x86::reg8>(cpu.esi) = 32 /*0x20*/;
    // 0048321f  e9f3feffff             -jmp 0x483117
    goto L_0x00483117;
L_0x00483224:
    // 00483224  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483227  8066ff00               -and byte ptr [esi - 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0048322b  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0048322e  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 00483232  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00483234  743e                   -je 0x483274
    if (cpu.flags.zf)
    {
        goto L_0x00483274;
    }
    // 00483236  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483238  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048323a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048323b  a12ceb5100             -mov eax, dword ptr [0x51eb2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */);
    // 00483240  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00483242  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483243  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483244  e8e79affff             -call 0x47cd30
    cpu.esp -= 4;
    sub_47cd30(app, cpu);
    // 00483249  2bfb                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048324b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048324e  03f7                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00483250  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x00483253:
    // 00483253  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00483255  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483257  741b                   -je 0x483274
    if (cpu.flags.zf)
    {
        goto L_0x00483274;
    }
    // 00483259  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048325a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048325b  e8d0bfffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00483260  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00483262  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483265  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483266  e875abffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0048326b  83c40c                 +add esp, 0xc
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
    // 0048326e  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00483272  ebdf                   -jmp 0x483253
    goto L_0x00483253;
L_0x00483274:
    // 00483274  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483276  740e                   -je 0x483286
    if (cpu.flags.zf)
    {
        goto L_0x00483286;
    }
    // 00483278  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048327b  3b30                   +cmp esi, dword ptr [eax]
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
    // 0048327d  7504                   -jne 0x483283
    if (!cpu.flags.zf)
    {
        goto L_0x00483283;
    }
    // 0048327f  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00483282  46                     -inc esi
    (cpu.esi)++;
L_0x00483283:
    // 00483283  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x00483286:
    // 00483286  ff352ceb5100           -push dword ptr [0x51eb2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */);
    cpu.esp -= 4;
    // 0048328c  e82341ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00483291  83252ceb510000         -and dword ptr [0x51eb2c], 0
    app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00483298  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483299  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048329b:
    // 0048329b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048329c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048329d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048329e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048329f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4832a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004832a0  833d18ee510000         +cmp dword ptr [0x51ee18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5369368) /* 0x51ee18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004832a7  7524                   -jne 0x4832cd
    if (!cpu.flags.zf)
    {
        goto L_0x004832cd;
    }
    // 004832a9  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 004832ab  e81998ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004832b0  833d18ee510000         +cmp dword ptr [0x51ee18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5369368) /* 0x51ee18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004832b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832b8  750b                   -jne 0x4832c5
    if (!cpu.flags.zf)
    {
        goto L_0x004832c5;
    }
    // 004832ba  e80f000000             -call 0x4832ce
    cpu.esp -= 4;
    sub_4832ce(app, cpu);
    // 004832bf  ff0518ee5100           -inc dword ptr [0x51ee18]
    (app->getMemory<x86::reg32>(x86::reg32(5369368) /* 0x51ee18 */))++;
L_0x004832c5:
    // 004832c5  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 004832c7  e85e98ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 004832cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004832cd:
    // 004832cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4832ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004832ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004832cf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004832d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004832d2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004832d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004832d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004832d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004832d6  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 004832d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832d9  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004832db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004832dc  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004832df  e8e597ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004832e4  830db8694a00ff         -or dword ptr [0x4a69b8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4876728) /* 0x4a69b8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004832eb  830da8694a00ff         -or dword ptr [0x4a69a8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4876712) /* 0x4a69a8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004832f2  891d60ed5100           -mov dword ptr [0x51ed60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5369184) /* 0x51ed60 */) = cpu.ebx;
    // 004832f8  c7042444864800         -mov dword ptr [esp], 0x488644
    app->getMemory<x86::reg32>(cpu.esp) = 4752964 /*0x488644*/;
    // 004832ff  e8d66affff             -call 0x479dda
    cpu.esp -= 4;
    sub_479dda(app, cpu);
    // 00483304  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483306  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483307  3bf3                   +cmp esi, ebx
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
    // 00483309  0f85fd000000           -jne 0x48340c
    if (!cpu.flags.zf)
    {
        goto L_0x0048340c;
    }
    // 0048330f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483310  e81598ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00483315  c7042468ed5100         -mov dword ptr [esp], 0x51ed68
    app->getMemory<x86::reg32>(cpu.esp) = 5369192 /*0x51ed68*/;
    // 0048331c  ff15c4704800           -call dword ptr [0x4870c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747460) /* 0x4870c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483322  83f8ff                 +cmp eax, -1
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
    // 00483325  0f8425020000           -je 0x483550
    if (cpu.flags.zf)
    {
        goto L_0x00483550;
    }
    // 0048332b  a168ed5100             -mov eax, dword ptr [0x51ed68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369192) /* 0x51ed68 */);
    // 00483330  8b0dbced5100           -mov ecx, dword ptr [0x51edbc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5369276) /* 0x51edbc */);
    // 00483336  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 00483339  66391daeed5100         +cmp word ptr [0x51edae], bx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5369262) /* 0x51edae */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00483340  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00483342  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483343  a314694a00             -mov dword ptr [0x4a6914], eax
    app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */) = cpu.eax;
    // 00483348  891560ed5100           -mov dword ptr [0x51ed60], edx
    app->getMemory<x86::reg32>(x86::reg32(5369184) /* 0x51ed60 */) = cpu.edx;
    // 0048334e  740c                   -je 0x48335c
    if (cpu.flags.zf)
    {
        goto L_0x0048335c;
    }
    // 00483350  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00483352  6bf63c                 -imul esi, esi, 0x3c
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 00483355  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00483357  a314694a00             -mov dword ptr [0x4a6914], eax
    app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */) = cpu.eax;
L_0x0048335c:
    // 0048335c  66391d02ee5100         +cmp word ptr [0x51ee02], bx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5369346) /* 0x51ee02 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00483363  741b                   -je 0x483380
    if (cpu.flags.zf)
    {
        goto L_0x00483380;
    }
    // 00483365  a110ee5100             -mov eax, dword ptr [0x51ee10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369360) /* 0x51ee10 */);
    // 0048336a  3bc3                   +cmp eax, ebx
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
    // 0048336c  7412                   -je 0x483380
    if (cpu.flags.zf)
    {
        goto L_0x00483380;
    }
    // 0048336e  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483370  891518694a00           -mov dword ptr [0x4a6918], edx
    app->getMemory<x86::reg32>(x86::reg32(4876568) /* 0x4a6918 */) = cpu.edx;
    // 00483376  6bc03c                 +imul eax, eax, 0x3c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 00483379  a31c694a00             -mov dword ptr [0x4a691c], eax
    app->getMemory<x86::reg32>(x86::reg32(4876572) /* 0x4a691c */) = cpu.eax;
    // 0048337e  eb0c                   -jmp 0x48338c
    goto L_0x0048338c;
L_0x00483380:
    // 00483380  891d18694a00           -mov dword ptr [0x4a6918], ebx
    app->getMemory<x86::reg32>(x86::reg32(4876568) /* 0x4a6918 */) = cpu.ebx;
    // 00483386  891d1c694a00           -mov dword ptr [0x4a691c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4876572) /* 0x4a691c */) = cpu.ebx;
L_0x0048338c:
    // 0048338c  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048338f  8b35a8714800           -mov esi, dword ptr [0x4871a8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    // 00483395  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483396  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483397  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 00483399  bf20020000             -mov edi, 0x220
    cpu.edi = 544 /*0x220*/;
    // 0048339e  ff35a0694a00           -push dword ptr [0x4a69a0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4876704) /* 0x4a69a0 */);
    cpu.esp -= 4;
    // 004833a4  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004833a6  686ced5100             -push 0x51ed6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5369196 /*0x51ed6c*/;
    cpu.esp -= 4;
    // 004833ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004833ac  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 004833b2  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004833b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004833b6  7410                   -je 0x4833c8
    if (cpu.flags.zf)
    {
        goto L_0x004833c8;
    }
    // 004833b8  395dfc                 +cmp dword ptr [ebp - 4], ebx
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
    // 004833bb  750b                   -jne 0x4833c8
    if (!cpu.flags.zf)
    {
        goto L_0x004833c8;
    }
    // 004833bd  a1a0694a00             -mov eax, dword ptr [0x4a69a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876704) /* 0x4a69a0 */);
    // 004833c2  80603f00               +and byte ptr [eax + 0x3f], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(63) /* 0x3f */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 004833c6  eb08                   -jmp 0x4833d0
    goto L_0x004833d0;
L_0x004833c8:
    // 004833c8  a1a0694a00             -mov eax, dword ptr [0x4a69a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876704) /* 0x4a69a0 */);
    // 004833cd  802000                 -and byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x004833d0:
    // 004833d0  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004833d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004833d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004833d5  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 004833d7  ff35a4694a00           -push dword ptr [0x4a69a4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4876708) /* 0x4a69a4 */);
    cpu.esp -= 4;
    // 004833dd  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004833df  68c0ed5100             -push 0x51edc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5369280 /*0x51edc0*/;
    cpu.esp -= 4;
    // 004833e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004833e5  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 004833eb  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004833ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004833ef  0f844a010000           -je 0x48353f
    if (cpu.flags.zf)
    {
        goto L_0x0048353f;
    }
    // 004833f5  395dfc                 +cmp dword ptr [ebp - 4], ebx
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
    // 004833f8  0f8541010000           -jne 0x48353f
    if (!cpu.flags.zf)
    {
        goto L_0x0048353f;
    }
    // 004833fe  a1a4694a00             -mov eax, dword ptr [0x4a69a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876708) /* 0x4a69a4 */);
    // 00483403  80603f00               +and byte ptr [eax + 0x3f], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(63) /* 0x3f */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00483407  e944010000             -jmp 0x483550
    goto L_0x00483550;
L_0x0048340c:
    // 0048340c  803e00                 +cmp byte ptr [esi], 0
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
    // 0048340f  0f8434010000           -je 0x483549
    if (cpu.flags.zf)
    {
        goto L_0x00483549;
    }
    // 00483415  a114ee5100             -mov eax, dword ptr [0x51ee14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369364) /* 0x51ee14 */);
    // 0048341a  3bc3                   +cmp eax, ebx
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
    // 0048341c  7411                   -je 0x48342f
    if (cpu.flags.zf)
    {
        goto L_0x0048342f;
    }
    // 0048341e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048341f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483420  e80bf3ffff             -call 0x482730
    cpu.esp -= 4;
    _strcmp(app, cpu);
    // 00483425  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483426  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483428  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483429  0f841a010000           -je 0x483549
    if (cpu.flags.zf)
    {
        goto L_0x00483549;
    }
L_0x0048342f:
    // 0048342f  ff3514ee5100           -push dword ptr [0x51ee14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5369364) /* 0x51ee14 */);
    cpu.esp -= 4;
    // 00483435  e87a3fffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0048343a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048343b  e8a0a9ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00483440  40                     -inc eax
    (cpu.eax)++;
    // 00483441  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483442  e8333effff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00483447  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048344a  3bc3                   +cmp eax, ebx
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
    // 0048344c  a314ee5100             -mov dword ptr [0x51ee14], eax
    app->getMemory<x86::reg32>(x86::reg32(5369364) /* 0x51ee14 */) = cpu.eax;
    // 00483451  0f84f2000000           -je 0x483549
    if (cpu.flags.zf)
    {
        goto L_0x00483549;
    }
    // 00483457  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483458  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483459  e8d2bdffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 0048345e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048345f  e8c696ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00483464  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00483466  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483467  ff35a0694a00           -push dword ptr [0x4a69a0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4876704) /* 0x4a69a0 */);
    cpu.esp -= 4;
    // 0048346d  e84e49ffff             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 00483472  a1a0694a00             -mov eax, dword ptr [0x4a69a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876704) /* 0x4a69a0 */);
    // 00483477  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048347a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048347d  80600300               -and byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00483481  803e2d                 +cmp byte ptr [esi], 0x2d
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
    // 00483484  7508                   -jne 0x48348e
    if (!cpu.flags.zf)
    {
        goto L_0x0048348e;
    }
    // 00483486  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
    // 0048348d  46                     -inc esi
    (cpu.esi)++;
L_0x0048348e:
    // 0048348e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048348f  e8c660ffff             -call 0x47955a
    cpu.esp -= 4;
    sub_47955a(app, cpu);
    // 00483494  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483495  b330                   -mov bl, 0x30
    cpu.bl = 48 /*0x30*/;
    // 00483497  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483499  69c9100e0000           -imul ecx, ecx, 0xe10
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(3600 /*0xe10*/)));
    // 0048349f  890d14694a00           -mov dword ptr [0x4a6914], ecx
    app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */) = cpu.ecx;
L_0x004834a5:
    // 004834a5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004834a7  3c2b                   +cmp al, 0x2b
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
    // 004834a9  7408                   -je 0x4834b3
    if (cpu.flags.zf)
    {
        goto L_0x004834b3;
    }
    // 004834ab  3ac3                   +cmp al, bl
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
    // 004834ad  7c07                   -jl 0x4834b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004834b6;
    }
    // 004834af  3c39                   +cmp al, 0x39
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
    // 004834b1  7f03                   -jg 0x4834b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004834b6;
    }
L_0x004834b3:
    // 004834b3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004834b4  ebef                   -jmp 0x4834a5
    goto L_0x004834a5;
L_0x004834b6:
    // 004834b6  803e3a                 +cmp byte ptr [esi], 0x3a
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
    // 004834b9  754e                   -jne 0x483509
    if (!cpu.flags.zf)
    {
        goto L_0x00483509;
    }
    // 004834bb  46                     -inc esi
    (cpu.esi)++;
    // 004834bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004834bd  e89860ffff             -call 0x47955a
    cpu.esp -= 4;
    sub_47955a(app, cpu);
    // 004834c2  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 004834c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834c6  8b0d14694a00           -mov ecx, dword ptr [0x4a6914]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */);
    // 004834cc  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004834ce  890d14694a00           -mov dword ptr [0x4a6914], ecx
    app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */) = cpu.ecx;
L_0x004834d4:
    // 004834d4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004834d6  3ac3                   +cmp al, bl
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
    // 004834d8  7c07                   -jl 0x4834e1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004834e1;
    }
    // 004834da  3c39                   +cmp al, 0x39
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
    // 004834dc  7f03                   -jg 0x4834e1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004834e1;
    }
    // 004834de  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004834df  ebf3                   -jmp 0x4834d4
    goto L_0x004834d4;
L_0x004834e1:
    // 004834e1  803e3a                 +cmp byte ptr [esi], 0x3a
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
    // 004834e4  7523                   -jne 0x483509
    if (!cpu.flags.zf)
    {
        goto L_0x00483509;
    }
    // 004834e6  46                     -inc esi
    (cpu.esi)++;
    // 004834e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004834e8  e86d60ffff             -call 0x47955a
    cpu.esp -= 4;
    sub_47955a(app, cpu);
    // 004834ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834ee  8b0d14694a00           -mov ecx, dword ptr [0x4a6914]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */);
    // 004834f4  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004834f6  890d14694a00           -mov dword ptr [0x4a6914], ecx
    app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */) = cpu.ecx;
L_0x004834fc:
    // 004834fc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004834fe  3ac3                   +cmp al, bl
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
    // 00483500  7c07                   -jl 0x483509
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483509;
    }
    // 00483502  3c39                   +cmp al, 0x39
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
    // 00483504  7f03                   -jg 0x483509
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483509;
    }
    // 00483506  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483507  ebf3                   -jmp 0x4834fc
    goto L_0x004834fc;
L_0x00483509:
    // 00483509  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 0048350d  7408                   -je 0x483517
    if (cpu.flags.zf)
    {
        goto L_0x00483517;
    }
    // 0048350f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00483511  890d14694a00           -mov dword ptr [0x4a6914], ecx
    app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */) = cpu.ecx;
L_0x00483517:
    // 00483517  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 0048351a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048351c  a318694a00             -mov dword ptr [0x4a6918], eax
    app->getMemory<x86::reg32>(x86::reg32(4876568) /* 0x4a6918 */) = cpu.eax;
    // 00483521  741c                   -je 0x48353f
    if (cpu.flags.zf)
    {
        goto L_0x0048353f;
    }
    // 00483523  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00483525  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483526  ff35a4694a00           -push dword ptr [0x4a69a4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4876708) /* 0x4a69a4 */);
    cpu.esp -= 4;
    // 0048352c  e88f48ffff             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 00483531  a1a4694a00             -mov eax, dword ptr [0x4a69a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876708) /* 0x4a69a4 */);
    // 00483536  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00483539  80600300               +and byte ptr [eax + 3], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0048353d  eb11                   -jmp 0x483550
    goto L_0x00483550;
L_0x0048353f:
    // 0048353f  a1a4694a00             -mov eax, dword ptr [0x4a69a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876708) /* 0x4a69a4 */);
    // 00483544  802000                 +and byte ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00483547  eb07                   -jmp 0x483550
    goto L_0x00483550;
L_0x00483549:
    // 00483549  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048354a  e8db95ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0048354f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00483550:
    // 00483550  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483551  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483552  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483553  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483554  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483555(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483555  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483556  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 00483558  e86c95ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0048355d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00483561  e810000000             -call 0x483576
    cpu.esp -= 4;
    sub_483576(app, cpu);
    // 00483566  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 00483568  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048356a  e8bb95ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0048356f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00483572  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483574  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483575  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483576(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483576  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483577  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483578  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483579  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048357b  393d18694a00           +cmp dword ptr [0x4a6918], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4876568) /* 0x4a6918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483581  7507                   -jne 0x48358a
    if (!cpu.flags.zf)
    {
        goto L_0x0048358a;
    }
L_0x00483583:
    // 00483583  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00483585  e94c010000             -jmp 0x4836d6
    goto L_0x004836d6;
L_0x0048358a:
    // 0048358a  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048358e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00483590  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483591  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00483594  3b05a8694a00           +cmp eax, dword ptr [0x4a69a8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4876712) /* 0x4a69a8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048359a  750c                   -jne 0x4835a8
    if (!cpu.flags.zf)
    {
        goto L_0x004835a8;
    }
    // 0048359c  3b05b8694a00           +cmp eax, dword ptr [0x4a69b8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4876728) /* 0x4a69b8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004835a2  0f8402010000           -je 0x4836aa
    if (cpu.flags.zf)
    {
        goto L_0x004836aa;
    }
L_0x004835a8:
    // 004835a8  393d60ed5100           +cmp dword ptr [0x51ed60], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5369184) /* 0x51ed60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004835ae  0f84cc000000           -je 0x483680
    if (cpu.flags.zf)
    {
        goto L_0x00483680;
    }
    // 004835b4  0fb70d0eee5100         -movzx ecx, word ptr [0x51ee0e]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369358) /* 0x51ee0e */));
    // 004835bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835bc  66393d00ee5100         +cmp word ptr [0x51ee00], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5369344) /* 0x51ee00 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004835c3  0fb70d0cee5100         -movzx ecx, word ptr [0x51ee0c]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369356) /* 0x51ee0c */));
    // 004835ca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835cb  0fb70d0aee5100         -movzx ecx, word ptr [0x51ee0a]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369354) /* 0x51ee0a */));
    // 004835d2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835d3  0fb70d08ee5100         -movzx ecx, word ptr [0x51ee08]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369352) /* 0x51ee08 */));
    // 004835da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835db  751d                   -jne 0x4835fa
    if (!cpu.flags.zf)
    {
        goto L_0x004835fa;
    }
    // 004835dd  0fb70d04ee5100         -movzx ecx, word ptr [0x51ee04]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369348) /* 0x51ee04 */));
    // 004835e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004835e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835e6  0fb70d06ee5100         -movzx ecx, word ptr [0x51ee06]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369350) /* 0x51ee06 */));
    // 004835ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835ee  0fb70d02ee5100         -movzx ecx, word ptr [0x51ee02]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369346) /* 0x51ee02 */));
    // 004835f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004835f7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004835f8  eb14                   -jmp 0x48360e
    goto L_0x0048360e;
L_0x004835fa:
    // 004835fa  0fb70d06ee5100         -movzx ecx, word ptr [0x51ee06]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369350) /* 0x51ee06 */));
    // 00483601  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483602  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483603  0fb70d02ee5100         -movzx ecx, word ptr [0x51ee02]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369346) /* 0x51ee02 */));
    // 0048360a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048360b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048360c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048360d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048360e:
    // 0048360e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048360f  e80e010000             -call 0x483722
    cpu.esp -= 4;
    sub_483722(app, cpu);
    // 00483614  0fb705baed5100         -movzx eax, word ptr [0x51edba]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369274) /* 0x51edba */));
    // 0048361b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048361e  66393daced5100         +cmp word ptr [0x51edac], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5369260) /* 0x51edac */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00483625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483626  0fb705b8ed5100         -movzx eax, word ptr [0x51edb8]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369272) /* 0x51edb8 */));
    // 0048362d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048362e  0fb705b6ed5100         -movzx eax, word ptr [0x51edb6]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369270) /* 0x51edb6 */));
    // 00483635  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483636  0fb705b4ed5100         -movzx eax, word ptr [0x51edb4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369268) /* 0x51edb4 */));
    // 0048363d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048363e  7528                   -jne 0x483668
    if (!cpu.flags.zf)
    {
        goto L_0x00483668;
    }
    // 00483640  0fb705b0ed5100         -movzx eax, word ptr [0x51edb0]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369264) /* 0x51edb0 */));
    // 00483647  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483648  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483649  0fb705b2ed5100         -movzx eax, word ptr [0x51edb2]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369266) /* 0x51edb2 */));
    // 00483650  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483651  0fb705aeed5100         -movzx eax, word ptr [0x51edae]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369262) /* 0x51edae */));
    // 00483658  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483659  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0048365c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0048365d:
    // 0048365d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048365e  e8bf000000             -call 0x483722
    cpu.esp -= 4;
    sub_483722(app, cpu);
    // 00483663  83c42c                 +add esp, 0x2c
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
    // 00483666  eb42                   -jmp 0x4836aa
    goto L_0x004836aa;
L_0x00483668:
    // 00483668  0fb705b2ed5100         -movzx eax, word ptr [0x51edb2]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369266) /* 0x51edb2 */));
    // 0048366f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483670  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483671  0fb705aeed5100         -movzx eax, word ptr [0x51edae]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(5369262) /* 0x51edae */));
    // 00483678  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483679  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048367a  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0048367d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048367e  ebdd                   -jmp 0x48365d
    goto L_0x0048365d;
L_0x00483680:
    // 00483680  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483681  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483682  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483683  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00483685  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483686  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483687  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483688  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0048368a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048368b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048368c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048368d  e890000000             -call 0x483722
    cpu.esp -= 4;
    sub_483722(app, cpu);
    // 00483692  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483693  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483694  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483695  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00483697  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483698  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483699  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0048369b  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0048369d  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004836a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004836a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004836a2  e87b000000             -call 0x483722
    cpu.esp -= 4;
    sub_483722(app, cpu);
    // 004836a7  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
L_0x004836aa:
    // 004836aa  8b15ac694a00           -mov edx, dword ptr [0x4a69ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4876716) /* 0x4a69ac */);
    // 004836b0  a1bc694a00             -mov eax, dword ptr [0x4a69bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876732) /* 0x4a69bc */);
    // 004836b5  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004836b8  3bd0                   +cmp edx, eax
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
    // 004836ba  7d1e                   -jge 0x4836da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004836da;
    }
    // 004836bc  3bca                   +cmp ecx, edx
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
    // 004836be  0f8cbffeffff           -jl 0x483583
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483583;
    }
    // 004836c4  3bc8                   +cmp ecx, eax
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
    // 004836c6  0f8fb7feffff           -jg 0x483583
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483583;
    }
    // 004836cc  3bca                   +cmp ecx, edx
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
    // 004836ce  7e1e                   -jle 0x4836ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004836ee;
    }
    // 004836d0  3bc8                   +cmp ecx, eax
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
    // 004836d2  7d1a                   -jge 0x4836ee
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004836ee;
    }
L_0x004836d4:
    // 004836d4  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004836d6:
    // 004836d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004836da:
    // 004836da  3bc8                   +cmp ecx, eax
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
    // 004836dc  7cf6                   -jl 0x4836d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004836d4;
    }
    // 004836de  3bca                   +cmp ecx, edx
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
    // 004836e0  7ff2                   -jg 0x4836d4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004836d4;
    }
    // 004836e2  3bc8                   +cmp ecx, eax
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
    // 004836e4  7e08                   -jle 0x4836ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004836ee;
    }
    // 004836e6  3bca                   +cmp ecx, edx
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
    // 004836e8  0f8c95feffff           -jl 0x483583
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483583;
    }
L_0x004836ee:
    // 004836ee  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004836f1  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 004836f4  034604                 -add eax, dword ptr [esi + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004836f7  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 004836fa  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004836fc  69c0e8030000           -imul eax, eax, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 00483702  3bca                   +cmp ecx, edx
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
    // 00483704  750f                   -jne 0x483715
    if (!cpu.flags.zf)
    {
        goto L_0x00483715;
    }
    // 00483706  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483708  3b05b0694a00           +cmp eax, dword ptr [0x4a69b0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4876720) /* 0x4a69b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048370e  0f9dc1                 -setge cl
    cpu.cl = (cpu.flags.sf == cpu.flags.of);
L_0x00483711:
    // 00483711  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483713  ebc1                   -jmp 0x4836d6
    goto L_0x004836d6;
L_0x00483715:
    // 00483715  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483717  3b05c0694a00           +cmp eax, dword ptr [0x4a69c0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4876736) /* 0x4a69c0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048371d  0f9cc1                 -setl cl
    cpu.cl = (cpu.flags.sf != cpu.flags.of);
    // 00483720  ebef                   -jmp 0x483711
    goto L_0x00483711;
}

/* align: skip  */
void Application::sub_483722(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483722  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483723  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00483725  837d0c01               +cmp dword ptr [ebp + 0xc], 1
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
    // 00483729  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048372a  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048372d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048372e  0f8589000000           -jne 0x4837bd
    if (!cpu.flags.zf)
    {
        goto L_0x004837bd;
    }
    // 00483734  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00483737  895d10                 -mov dword ptr [ebp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0048373a  83651003               +and dword ptr [ebp + 0x10], 3
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0048373e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483740  750b                   -jne 0x48374d
    if (!cpu.flags.zf)
    {
        goto L_0x0048374d;
    }
    // 00483742  c1e602                 +shl esi, 2
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
    // 00483745  8b86c0694a00           -mov eax, dword ptr [esi + 0x4a69c0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4876736) /* 0x4a69c0 */);
    // 0048374b  eb09                   -jmp 0x483756
    goto L_0x00483756;
L_0x0048374d:
    // 0048374d  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00483750  8b86f4694a00           -mov eax, dword ptr [esi + 0x4a69f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4876788) /* 0x4a69f4 */);
L_0x00483756:
    // 00483756  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00483758  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048375b  69d26d010000           -imul edx, edx, 0x16d
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(365 /*0x16d*/)));
    // 00483761  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00483764  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483765  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00483768  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048376a  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0048376c  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048376e  8d843a259cffff         -lea eax, [edx + edi - 0x63db]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-25563) /* -0x63db */ + cpu.edi * 1);
    // 00483775  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483776  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00483777  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00483779  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0048377c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048377d  3b551c                 +cmp edx, dword ptr [ebp + 0x1c]
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
    // 00483780  7f0e                   -jg 0x483790
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483790;
    }
    // 00483782  6bc007                 -imul eax, eax, 7
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(7 /*0x7*/)));
    // 00483785  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00483787  03451c                 +add eax, dword ptr [ebp + 0x1c]
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
    // 0048378a  8d4c01f9               -lea ecx, [ecx + eax - 7]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-7) /* -0x7 */ + cpu.eax * 1);
    // 0048378e  eb0a                   -jmp 0x48379a
    goto L_0x0048379a;
L_0x00483790:
    // 00483790  6bc007                 -imul eax, eax, 7
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(7 /*0x7*/)));
    // 00483793  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00483795  03451c                 -add eax, dword ptr [ebp + 0x1c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 00483798  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0048379a:
    // 0048379a  837d1805               +cmp dword ptr [ebp + 0x18], 5
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
    // 0048379e  7538                   -jne 0x4837d8
    if (!cpu.flags.zf)
    {
        goto L_0x004837d8;
    }
    // 004837a0  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 004837a4  7508                   -jne 0x4837ae
    if (!cpu.flags.zf)
    {
        goto L_0x004837ae;
    }
    // 004837a6  8bb6c4694a00           -mov esi, dword ptr [esi + 0x4a69c4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4876740) /* 0x4a69c4 */);
    // 004837ac  eb06                   -jmp 0x4837b4
    goto L_0x004837b4;
L_0x004837ae:
    // 004837ae  8bb6f8694a00           -mov esi, dword ptr [esi + 0x4a69f8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4876792) /* 0x4a69f8 */);
L_0x004837b4:
    // 004837b4  3bce                   +cmp ecx, esi
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
    // 004837b6  7e20                   -jle 0x4837d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004837d8;
    }
    // 004837b8  83e907                 +sub ecx, 7
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
    // 004837bb  eb1b                   -jmp 0x4837d8
    goto L_0x004837d8;
L_0x004837bd:
    // 004837bd  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004837c0  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 004837c3  7509                   -jne 0x4837ce
    if (!cpu.flags.zf)
    {
        goto L_0x004837ce;
    }
    // 004837c5  8b0c85c0694a00         -mov ecx, dword ptr [eax*4 + 0x4a69c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4876736) /* 0x4a69c0 */ + cpu.eax * 4);
    // 004837cc  eb07                   -jmp 0x4837d5
    goto L_0x004837d5;
L_0x004837ce:
    // 004837ce  8b0c85f4694a00         -mov ecx, dword ptr [eax*4 + 0x4a69f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4876788) /* 0x4a69f4 */ + cpu.eax * 4);
L_0x004837d5:
    // 004837d5  034d20                 -add ecx, dword ptr [ebp + 0x20]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
L_0x004837d8:
    // 004837d8  837d0801               +cmp dword ptr [ebp + 8], 1
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
    // 004837dc  752b                   -jne 0x483809
    if (!cpu.flags.zf)
    {
        goto L_0x00483809;
    }
    // 004837de  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004837e1  890dac694a00           -mov dword ptr [0x4a69ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(4876716) /* 0x4a69ac */) = cpu.ecx;
    // 004837e7  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 004837ea  034528                 -add eax, dword ptr [ebp + 0x28]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */)));
    // 004837ed  891da8694a00           -mov dword ptr [0x4a69a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(4876712) /* 0x4a69a8 */) = cpu.ebx;
    // 004837f3  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 004837f6  03452c                 -add eax, dword ptr [ebp + 0x2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */)));
    // 004837f9  69c0e8030000           -imul eax, eax, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 004837ff  034530                 +add eax, dword ptr [ebp + 0x30]
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
    // 00483802  a3b0694a00             -mov dword ptr [0x4a69b0], eax
    app->getMemory<x86::reg32>(x86::reg32(4876720) /* 0x4a69b0 */) = cpu.eax;
    // 00483807  eb55                   -jmp 0x48385e
    goto L_0x0048385e;
L_0x00483809:
    // 00483809  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0048380c  890dbc694a00           -mov dword ptr [0x4a69bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(4876732) /* 0x4a69bc */) = cpu.ecx;
    // 00483812  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 00483815  034528                 -add eax, dword ptr [ebp + 0x28]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */)));
    // 00483818  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0048381b  03051c694a00           -add eax, dword ptr [0x4a691c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4876572) /* 0x4a691c */)));
    // 00483821  03452c                 -add eax, dword ptr [ebp + 0x2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */)));
    // 00483824  69c0e8030000           -imul eax, eax, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 0048382a  034530                 +add eax, dword ptr [ebp + 0x30]
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
    // 0048382d  a3c0694a00             -mov dword ptr [0x4a69c0], eax
    app->getMemory<x86::reg32>(x86::reg32(4876736) /* 0x4a69c0 */) = cpu.eax;
    // 00483832  790d                   -jns 0x483841
    if (!cpu.flags.sf)
    {
        goto L_0x00483841;
    }
    // 00483834  05005c2605             +add eax, 0x5265c00
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
    // 00483839  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048383a  a3c0694a00             -mov dword ptr [0x4a69c0], eax
    app->getMemory<x86::reg32>(x86::reg32(4876736) /* 0x4a69c0 */) = cpu.eax;
    // 0048383f  eb11                   -jmp 0x483852
    goto L_0x00483852;
L_0x00483841:
    // 00483841  ba005c2605             -mov edx, 0x5265c00
    cpu.edx = 86400000 /*0x5265c00*/;
    // 00483846  3bc2                   +cmp eax, edx
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
    // 00483848  7c0e                   -jl 0x483858
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483858;
    }
    // 0048384a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048384c  41                     -inc ecx
    (cpu.ecx)++;
    // 0048384d  a3c0694a00             -mov dword ptr [0x4a69c0], eax
    app->getMemory<x86::reg32>(x86::reg32(4876736) /* 0x4a69c0 */) = cpu.eax;
L_0x00483852:
    // 00483852  890dbc694a00           -mov dword ptr [0x4a69bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(4876732) /* 0x4a69bc */) = cpu.ecx;
L_0x00483858:
    // 00483858  891db8694a00           -mov dword ptr [0x4a69b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(4876728) /* 0x4a69b8 */) = cpu.ebx;
L_0x0048385e:
    // 0048385e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048385f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483860  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483861  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483862(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00483862  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483863  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00483865  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00483868  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483869  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048386a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048386b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048386e  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 00483871  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00483873  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00483876  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483878  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483879  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0048387c  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 0048387f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00483882  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00483885  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00483888  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0048388b  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0048388e  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00483891  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00483894  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00483897  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0048389a  897d10                 -mov dword ptr [ebp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0048389d:
    // 0048389d  8a0f                   -mov cl, byte ptr [edi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi);
    // 0048389f  80f920                 +cmp cl, 0x20
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
    // 004838a2  740f                   -je 0x4838b3
    if (cpu.flags.zf)
    {
        goto L_0x004838b3;
    }
    // 004838a4  80f909                 +cmp cl, 9
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004838a7  740a                   -je 0x4838b3
    if (cpu.flags.zf)
    {
        goto L_0x004838b3;
    }
    // 004838a9  80f90a                 +cmp cl, 0xa
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
    // 004838ac  7405                   -je 0x4838b3
    if (cpu.flags.zf)
    {
        goto L_0x004838b3;
    }
    // 004838ae  80f90d                 +cmp cl, 0xd
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004838b1  7503                   -jne 0x4838b6
    if (!cpu.flags.zf)
    {
        goto L_0x004838b6;
    }
L_0x004838b3:
    // 004838b3  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004838b4  ebe7                   -jmp 0x48389d
    goto L_0x0048389d;
L_0x004838b6:
    // 004838b6  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004838b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004838b9:
    // 004838b9  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004838bb  47                     -inc edi
    (cpu.edi)++;
    // 004838bc  83f80b                 +cmp eax, 0xb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004838bf  0f8777020000           -ja 0x483b3c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483b3c;
    }
    // 004838c5  ff2485033d4800         -jmp dword ptr [eax*4 + 0x483d03]
    cpu.ip = app->getMemory<x86::reg32>(4734211 + cpu.eax * 4); goto dynamic_jump;
  case 0x004838cc:
    // 004838cc  80fb31                 +cmp bl, 0x31
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(49 /*0x31*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004838cf  7c0c                   -jl 0x4838dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004838dd;
    }
    // 004838d1  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004838d4  7f07                   -jg 0x4838dd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004838dd;
    }
L_0x004838d6:
    // 004838d6  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004838d8  e91d020000             -jmp 0x483afa
    goto L_0x00483afa;
L_0x004838dd:
    // 004838dd  3a1d1c644a00           +cmp bl, byte ptr [0x4a641c]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004838e3  7507                   -jne 0x4838ec
    if (!cpu.flags.zf)
    {
        goto L_0x004838ec;
    }
L_0x004838e5:
    // 004838e5  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004838e7  e946020000             -jmp 0x483b32
    goto L_0x00483b32;
L_0x004838ec:
    // 004838ec  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 004838ef  83e82b                 +sub eax, 0x2b
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
    // 004838f2  741e                   -je 0x483912
    if (cpu.flags.zf)
    {
        goto L_0x00483912;
    }
    // 004838f4  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004838f5  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004838f6  740e                   -je 0x483906
    if (cpu.flags.zf)
    {
        goto L_0x00483906;
    }
    // 004838f8  83e803                 +sub eax, 3
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
    // 004838fb  0f85d4020000           -jne 0x483bd5
    if (!cpu.flags.zf)
    {
        goto L_0x00483bd5;
    }
    // 00483901  e98f000000             -jmp 0x483995
    goto L_0x00483995;
L_0x00483906:
    // 00483906  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00483908  c745d800800000         -mov dword ptr [ebp - 0x28], 0x8000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = 32768 /*0x8000*/;
    // 0048390f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483910  eba7                   -jmp 0x4838b9
    goto L_0x004838b9;
L_0x00483912:
    // 00483912  8365d800               +and dword ptr [ebp - 0x28], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 00483916  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00483918  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483919  eb9e                   -jmp 0x4838b9
    goto L_0x004838b9;
  case 0x0048391b:
    // 0048391b  80fb31                 +cmp bl, 0x31
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(49 /*0x31*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048391e  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00483921  7c05                   -jl 0x483928
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483928;
    }
    // 00483923  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483926  7eae                   -jle 0x4838d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004838d6;
    }
L_0x00483928:
    // 00483928  3a1d1c644a00           +cmp bl, byte ptr [0x4a641c]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048392e  0f84bc000000           -je 0x4839f0
    if (cpu.flags.zf)
    {
        goto L_0x004839f0;
    }
    // 00483934  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483937  7431                   -je 0x48396a
    if (cpu.flags.zf)
    {
        goto L_0x0048396a;
    }
    // 00483939  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048393c  742c                   -je 0x48396a
    if (cpu.flags.zf)
    {
        goto L_0x0048396a;
    }
    // 0048393e  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483941  7452                   -je 0x483995
    if (cpu.flags.zf)
    {
        goto L_0x00483995;
    }
L_0x00483943:
    // 00483943  80fb43                 +cmp bl, 0x43
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(67 /*0x43*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483946  0f8e89020000           -jle 0x483bd5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483bd5;
    }
    // 0048394c  80fb45                 +cmp bl, 0x45
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048394f  7e12                   -jle 0x483963
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483963;
    }
    // 00483951  80fb63                 +cmp bl, 0x63
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(99 /*0x63*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483954  0f8e7b020000           -jle 0x483bd5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483bd5;
    }
    // 0048395a  80fb65                 +cmp bl, 0x65
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(101 /*0x65*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048395d  0f8f72020000           -jg 0x483bd5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483bd5;
    }
L_0x00483963:
    // 00483963  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00483965  e9c8010000             -jmp 0x483b32
    goto L_0x00483b32;
L_0x0048396a:
    // 0048396a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048396b  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 0048396d  e9c0010000             -jmp 0x483b32
    goto L_0x00483b32;
  case 0x00483972:
    // 00483972  80fb31                 +cmp bl, 0x31
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(49 /*0x31*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483975  7c09                   -jl 0x483980
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483980;
    }
    // 00483977  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048397a  0f8e56ffffff           -jle 0x4838d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004838d6;
    }
L_0x00483980:
    // 00483980  3a1d1c644a00           +cmp bl, byte ptr [0x4a641c]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483986  0f8459ffffff           -je 0x4838e5
    if (cpu.flags.zf)
    {
        goto L_0x004838e5;
    }
    // 0048398c  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048398f  0f85b5010000           -jne 0x483b4a
    if (!cpu.flags.zf)
    {
        goto L_0x00483b4a;
    }
L_0x00483995:
    // 00483995  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483997  e91dffffff             -jmp 0x4838b9
    goto L_0x004838b9;
  case 0x0048399c:
    // 0048399c  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x0048399f:
    // 0048399f  391518644a00           +cmp dword ptr [0x4a6418], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004839a5  7e11                   -jle 0x4839b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004839b8;
    }
    // 004839a7  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 004839aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004839ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004839ac  e8d898ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 004839b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004839b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004839b3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004839b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004839b6  eb0e                   -jmp 0x4839c6
    goto L_0x004839c6;
L_0x004839b8:
    // 004839b8  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 004839be  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 004839c1  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 004839c4  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x004839c6:
    // 004839c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004839c8  741e                   -je 0x4839e8
    if (cpu.flags.zf)
    {
        goto L_0x004839e8;
    }
    // 004839ca  837dfc19               +cmp dword ptr [ebp - 4], 0x19
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004839ce  7310                   -jae 0x4839e0
    if (!cpu.flags.cf)
    {
        goto L_0x004839e0;
    }
    // 004839d0  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004839d3  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 004839d6  80eb30                 +sub bl, 0x30
    {
        x86::reg8& tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004839d9  ff45f4                 +inc dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004839dc  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004839de  eb03                   -jmp 0x4839e3
    goto L_0x004839e3;
L_0x004839e0:
    // 004839e0  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004839e3:
    // 004839e3  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004839e5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004839e6  ebb7                   -jmp 0x48399f
    goto L_0x0048399f;
L_0x004839e8:
    // 004839e8  3a1d1c644a00           +cmp bl, byte ptr [0x4a641c]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004839ee  7567                   -jne 0x483a57
    if (!cpu.flags.zf)
    {
        goto L_0x00483a57;
    }
L_0x004839f0:
    // 004839f0  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004839f2  e9c2feffff             -jmp 0x4838b9
    goto L_0x004838b9;
  case 0x004839f7:
    // 004839f7  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 004839fb  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004839fe  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 00483a01  750d                   -jne 0x483a10
    if (!cpu.flags.zf)
    {
        goto L_0x00483a10;
    }
L_0x00483a03:
    // 00483a03  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483a06  7508                   -jne 0x483a10
    if (!cpu.flags.zf)
    {
        goto L_0x00483a10;
    }
    // 00483a08  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483a0b  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00483a0d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483a0e  ebf3                   -jmp 0x483a03
    goto L_0x00483a03;
L_0x00483a10:
    // 00483a10  391518644a00           +cmp dword ptr [0x4a6418], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483a16  7e11                   -jle 0x483a29
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483a29;
    }
    // 00483a18  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00483a1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483a1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483a1d  e86798ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00483a22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a24  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00483a26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a27  eb0e                   -jmp 0x483a37
    goto L_0x00483a37;
L_0x00483a29:
    // 00483a29  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00483a2f  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00483a32  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 00483a35  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x00483a37:
    // 00483a37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483a39  741c                   -je 0x483a57
    if (cpu.flags.zf)
    {
        goto L_0x00483a57;
    }
    // 00483a3b  837dfc19               +cmp dword ptr [ebp - 4], 0x19
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483a3f  7311                   -jae 0x483a52
    if (!cpu.flags.cf)
    {
        goto L_0x00483a52;
    }
    // 00483a41  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00483a44  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00483a47  80eb30                 +sub bl, 0x30
    {
        x86::reg8& tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00483a4a  ff45f4                 +inc dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483a4d  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483a50  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x00483a52:
    // 00483a52  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00483a54  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483a55  ebb9                   -jmp 0x483a10
    goto L_0x00483a10;
L_0x00483a57:
    // 00483a57  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483a5a  0f840affffff           -je 0x48396a
    if (cpu.flags.zf)
    {
        goto L_0x0048396a;
    }
    // 00483a60  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483a63  0f8401ffffff           -je 0x48396a
    if (cpu.flags.zf)
    {
        goto L_0x0048396a;
    }
    // 00483a69  e9d5feffff             -jmp 0x483943
    goto L_0x00483943;
  case 0x00483a6e:
    // 00483a6e  391518644a00           +cmp dword ptr [0x4a6418], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483a74  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 00483a77  7e11                   -jle 0x483a8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483a8a;
    }
    // 00483a79  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00483a7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483a7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483a7e  e80698ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00483a83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a85  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00483a87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a88  eb0e                   -jmp 0x483a98
    goto L_0x00483a98;
L_0x00483a8a:
    // 00483a8a  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00483a90  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00483a93  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 00483a96  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x00483a98:
    // 00483a98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483a9a  0f84aa000000           -je 0x483b4a
    if (cpu.flags.zf)
    {
        goto L_0x00483b4a;
    }
    // 00483aa0  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483aa2  eb57                   -jmp 0x483afb
    goto L_0x00483afb;
  case 0x00483aa4:
    // 00483aa4  8d4ffe                 -lea ecx, [edi - 2]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 00483aa7  80fb31                 +cmp bl, 0x31
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(49 /*0x31*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483aaa  894d10                 -mov dword ptr [ebp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00483aad  7c05                   -jl 0x483ab4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483ab4;
    }
    // 00483aaf  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483ab2  7e44                   -jle 0x483af8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483af8;
    }
L_0x00483ab4:
    // 00483ab4  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00483ab7  83e82b                 +sub eax, 0x2b
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
    // 00483aba  7474                   -je 0x483b30
    if (cpu.flags.zf)
    {
        goto L_0x00483b30;
    }
    // 00483abc  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483abd  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483abe  7464                   -je 0x483b24
    if (cpu.flags.zf)
    {
        goto L_0x00483b24;
    }
    // 00483ac0  83e803                 +sub eax, 3
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
    // 00483ac3  0f850f010000           -jne 0x483bd8
    if (!cpu.flags.zf)
    {
        goto L_0x00483bd8;
    }
L_0x00483ac9:
    // 00483ac9  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00483acb  eb65                   -jmp 0x483b32
    goto L_0x00483b32;
  case 0x00483acd:
    // 00483acd  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
L_0x00483ad0:
    // 00483ad0  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483ad3  7505                   -jne 0x483ada
    if (!cpu.flags.zf)
    {
        goto L_0x00483ada;
    }
    // 00483ad5  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00483ad7  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483ad8  ebf6                   -jmp 0x483ad0
    goto L_0x00483ad0;
L_0x00483ada:
    // 00483ada  80fb31                 +cmp bl, 0x31
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(49 /*0x31*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483add  0f8cf2000000           -jl 0x483bd5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483bd5;
    }
    // 00483ae3  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483ae6  0f8fe9000000           -jg 0x483bd5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483bd5;
    }
    // 00483aec  eb0a                   -jmp 0x483af8
    goto L_0x00483af8;
  case 0x00483aee:
    // 00483aee  80fb31                 +cmp bl, 0x31
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(49 /*0x31*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483af1  7c0e                   -jl 0x483b01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483b01;
    }
    // 00483af3  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483af6  7f09                   -jg 0x483b01
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483b01;
    }
L_0x00483af8:
    // 00483af8  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
L_0x00483afa:
    // 00483afa  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00483afb:
    // 00483afb  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483afc  e9b8fdffff             -jmp 0x4838b9
    goto L_0x004838b9;
L_0x00483b01:
    // 00483b01  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483b04  7544                   -jne 0x483b4a
    if (!cpu.flags.zf)
    {
        goto L_0x00483b4a;
    }
    // 00483b06  ebc1                   -jmp 0x483ac9
    goto L_0x00483ac9;
  case 0x00483b08:
    // 00483b08  837d2000               +cmp dword ptr [ebp + 0x20], 0
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
    // 00483b0c  742a                   -je 0x483b38
    if (cpu.flags.zf)
    {
        goto L_0x00483b38;
    }
    // 00483b0e  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00483b11  8d4fff                 -lea ecx, [edi - 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00483b14  83e82b                 +sub eax, 0x2b
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
    // 00483b17  894d10                 -mov dword ptr [ebp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00483b1a  7414                   -je 0x483b30
    if (cpu.flags.zf)
    {
        goto L_0x00483b30;
    }
    // 00483b1c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483b1d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483b1e  0f85b4000000           -jne 0x483bd8
    if (!cpu.flags.zf)
    {
        goto L_0x00483bd8;
    }
L_0x00483b24:
    // 00483b24  834de8ff               +or dword ptr [ebp - 0x18], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00483b28  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00483b2a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b2b  e989fdffff             -jmp 0x4838b9
    goto L_0x004838b9;
L_0x00483b30:
    // 00483b30  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
L_0x00483b32:
    // 00483b32  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b33  e981fdffff             -jmp 0x4838b9
    goto L_0x004838b9;
L_0x00483b38:
    // 00483b38  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00483b3a  4f                     -dec edi
    (cpu.edi)--;
    // 00483b3b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
  [[fallthrough]];
  case 0x00483b3c:
L_0x00483b3c:
    // 00483b3c  83f80a                 +cmp eax, 0xa
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
    // 00483b3f  0f8495000000           -je 0x483bda
    if (cpu.flags.zf)
    {
        goto L_0x00483bda;
    }
    // 00483b45  e96ffdffff             -jmp 0x4838b9
    goto L_0x004838b9;
L_0x00483b4a:
    // 00483b4a  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00483b4d  e988000000             -jmp 0x483bda
    goto L_0x00483bda;
  case 0x00483b52:
    // 00483b52  c745e001000000         -mov dword ptr [ebp - 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = 1 /*0x1*/;
    // 00483b59  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00483b5b:
    // 00483b5b  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 00483b62  7e0f                   -jle 0x483b73
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483b73;
    }
    // 00483b64  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00483b67  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00483b69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483b6a  e81a97ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00483b6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b71  eb0f                   -jmp 0x483b82
    goto L_0x00483b82;
L_0x00483b73:
    // 00483b73  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00483b79  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00483b7c  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 00483b7f  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00483b82:
    // 00483b82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483b84  741c                   -je 0x483ba2
    if (cpu.flags.zf)
    {
        goto L_0x00483ba2;
    }
    // 00483b86  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00483b89  8d04b6                 -lea eax, [esi + esi*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 4);
    // 00483b8c  8d7441d0               -lea esi, [ecx + eax*2 - 0x30]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 00483b90  81fe50140000           +cmp esi, 0x1450
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5200 /*0x1450*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483b96  7f05                   -jg 0x483b9d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483b9d;
    }
    // 00483b98  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00483b9a  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483b9b  ebbe                   -jmp 0x483b5b
    goto L_0x00483b5b;
L_0x00483b9d:
    // 00483b9d  be51140000             -mov esi, 0x1451
    cpu.esi = 5201 /*0x1451*/;
L_0x00483ba2:
    // 00483ba2  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
L_0x00483ba5:
    // 00483ba5  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 00483bac  7e0f                   -jle 0x483bbd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483bbd;
    }
    // 00483bae  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00483bb1  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00483bb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483bb4  e8d096ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00483bb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bbb  eb0f                   -jmp 0x483bcc
    goto L_0x00483bcc;
L_0x00483bbd:
    // 00483bbd  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00483bc3  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00483bc6  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 00483bc9  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00483bcc:
    // 00483bcc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483bce  7405                   -je 0x483bd5
    if (cpu.flags.zf)
    {
        goto L_0x00483bd5;
    }
    // 00483bd0  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00483bd2  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483bd3  ebd0                   -jmp 0x483ba5
    goto L_0x00483ba5;
L_0x00483bd5:
    // 00483bd5  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483bd6  eb02                   -jmp 0x483bda
    goto L_0x00483bda;
L_0x00483bd8:
    // 00483bd8  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x00483bda:
    // 00483bda  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00483bdd  837df000               +cmp dword ptr [ebp - 0x10], 0
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
    // 00483be1  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 00483be3  0f84d9000000           -je 0x483cc2
    if (cpu.flags.zf)
    {
        goto L_0x00483cc2;
    }
    // 00483be9  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00483beb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bec  3945fc                 +cmp dword ptr [ebp - 4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483bef  7615                   -jbe 0x483c06
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483c06;
    }
    // 00483bf1  807dbb05               +cmp byte ptr [ebp - 0x45], 5
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-69) /* -0x45 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(5 /*0x5*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483bf5  7c03                   -jl 0x483bfa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483bfa;
    }
    // 00483bf7  fe45bb                 +inc byte ptr [ebp - 0x45]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-69) /* -0x45 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
L_0x00483bfa:
    // 00483bfa  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00483bfd  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00483c00  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483c01  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483c04  eb03                   -jmp 0x483c09
    goto L_0x00483c09;
L_0x00483c06:
    // 00483c06  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x00483c09:
    // 00483c09  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00483c0d  0f86a5000000           -jbe 0x483cb8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483cb8;
    }
L_0x00483c13:
    // 00483c13  48                     -dec eax
    (cpu.eax)--;
    // 00483c14  803800                 +cmp byte ptr [eax], 0
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
    // 00483c17  7508                   -jne 0x483c21
    if (!cpu.flags.zf)
    {
        goto L_0x00483c21;
    }
    // 00483c19  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483c1c  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483c1f  ebf2                   -jmp 0x483c13
    goto L_0x00483c13;
L_0x00483c21:
    // 00483c21  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00483c24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483c25  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 00483c28  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00483c2b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483c2c  e825090000             -call 0x484556
    cpu.esp -= 4;
    sub_484556(app, cpu);
    // 00483c31  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00483c34  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483c36  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00483c39  394de8                 +cmp dword ptr [ebp - 0x18], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c3c  7d02                   -jge 0x483c40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483c40;
    }
    // 00483c3e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x00483c40:
    // 00483c40  0345f8                 -add eax, dword ptr [ebp - 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00483c43  394de0                 +cmp dword ptr [ebp - 0x20], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c46  7503                   -jne 0x483c4b
    if (!cpu.flags.zf)
    {
        goto L_0x00483c4b;
    }
    // 00483c48  034518                 -add eax, dword ptr [ebp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
L_0x00483c4b:
    // 00483c4b  394ddc                 +cmp dword ptr [ebp - 0x24], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c4e  7503                   -jne 0x483c53
    if (!cpu.flags.zf)
    {
        goto L_0x00483c53;
    }
    // 00483c50  2b451c                 -sub eax, dword ptr [ebp + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
L_0x00483c53:
    // 00483c53  3d50140000             +cmp eax, 0x1450
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5200 /*0x1450*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c58  7e30                   -jle 0x483c8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483c8a;
    }
    // 00483c5a  c745d401000000         -mov dword ptr [ebp - 0x2c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = 1 /*0x1*/;
L_0x00483c61:
    // 00483c61  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00483c64  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00483c67  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00483c6a  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x00483c6d:
    // 00483c6d  837dd400               +cmp dword ptr [ebp - 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c71  7460                   -je 0x483cd3
    if (cpu.flags.zf)
    {
        goto L_0x00483cd3;
    }
    // 00483c73  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483c75  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
    // 00483c7a  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 00483c7f  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00483c81  c745ec02000000         -mov dword ptr [ebp - 0x14], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 2 /*0x2*/;
    // 00483c88  eb5e                   -jmp 0x483ce8
    goto L_0x00483ce8;
L_0x00483c8a:
    // 00483c8a  3db0ebffff             +cmp eax, 0xffffebb0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962096 /*0xffffebb0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c8f  7d09                   -jge 0x483c9a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483c9a;
    }
    // 00483c91  c745d001000000         -mov dword ptr [ebp - 0x30], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = 1 /*0x1*/;
    // 00483c98  ebc7                   -jmp 0x483c61
    goto L_0x00483c61;
L_0x00483c9a:
    // 00483c9a  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00483c9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483c9e  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00483ca1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483ca2  e860160000             -call 0x485307
    cpu.esp -= 4;
    sub_485307(app, cpu);
    // 00483ca7  8b55c0                 -mov edx, dword ptr [ebp - 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00483caa  8b5dc2                 -mov ebx, dword ptr [ebp - 0x3e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-62) /* -0x3e */);
    // 00483cad  8b75c6                 -mov esi, dword ptr [ebp - 0x3a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-58) /* -0x3a */);
    // 00483cb0  8b45ca                 -mov eax, dword ptr [ebp - 0x36]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-54) /* -0x36 */);
    // 00483cb3  83c40c                 +add esp, 0xc
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
    // 00483cb6  ebb5                   -jmp 0x483c6d
    goto L_0x00483c6d;
L_0x00483cb8:
    // 00483cb8  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483cba  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483cbc  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00483cbe  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00483cc0  ebab                   -jmp 0x483c6d
    goto L_0x00483c6d;
L_0x00483cc2:
    // 00483cc2  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483cc4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483cc6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00483cc8  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00483cca  c745ec04000000         -mov dword ptr [ebp - 0x14], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 4 /*0x4*/;
    // 00483cd1  eb15                   -jmp 0x483ce8
    goto L_0x00483ce8;
L_0x00483cd3:
    // 00483cd3  837dd000               +cmp dword ptr [ebp - 0x30], 0
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
    // 00483cd7  740f                   -je 0x483ce8
    if (cpu.flags.zf)
    {
        goto L_0x00483ce8;
    }
    // 00483cd9  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483cdb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483cdd  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00483cdf  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483ce1  c745ec01000000         -mov dword ptr [ebp - 0x14], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 1 /*0x1*/;
L_0x00483ce8:
    // 00483ce8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00483ceb  0b45d8                 -or eax, dword ptr [ebp - 0x28]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 00483cee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cef  897106                 -mov dword ptr [ecx + 6], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.esi;
    // 00483cf2  895902                 -mov dword ptr [ecx + 2], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.ebx;
    // 00483cf5  6689410a               -mov word ptr [ecx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00483cf9  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00483cfc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cfd  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 00483d00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d01  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d02  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_483d33(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483d33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483d34  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00483d36  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00483d39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483d3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483d3c  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00483d3e  e8868dffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00483d43  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00483d46  e895010000             -call 0x483ee0
    cpu.esp -= 4;
    sub_483ee0(app, cpu);
    // 00483d4b  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483d4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d4e  3b1da81c5200           +cmp ebx, dword ptr [0x521ca8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483d54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d55  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00483d58  7507                   -jne 0x483d61
    if (!cpu.flags.zf)
    {
        goto L_0x00483d61;
    }
L_0x00483d5a:
    // 00483d5a  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00483d5c  e970010000             -jmp 0x483ed1
    goto L_0x00483ed1;
L_0x00483d61:
    // 00483d61  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483d63  0f8456010000           -je 0x483ebf
    if (cpu.flags.zf)
    {
        goto L_0x00483ebf;
    }
    // 00483d69  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483d6b  b8386a4a00             -mov eax, 0x4a6a38
    cpu.eax = 4876856 /*0x4a6a38*/;
L_0x00483d70:
    // 00483d70  3918                   +cmp dword ptr [eax], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483d72  7474                   -je 0x483de8
    if (cpu.flags.zf)
    {
        goto L_0x00483de8;
    }
    // 00483d74  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00483d77  42                     -inc edx
    (cpu.edx)++;
    // 00483d78  3d286b4a00             +cmp eax, 0x4a6b28
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4877096 /*0x4a6b28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483d7d  7cf1                   -jl 0x483d70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483d70;
    }
    // 00483d7f  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00483d82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483d83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d84  ff1524714800           -call dword ptr [0x487124]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747556) /* 0x487124 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483d8a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00483d8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d8d  3bc6                   +cmp eax, esi
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
    // 00483d8f  0f8521010000           -jne 0x483eb6
    if (!cpu.flags.zf)
    {
        goto L_0x00483eb6;
    }
    // 00483d95  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00483d97  8325c41e520000         -and dword ptr [0x521ec4], 0
    app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00483d9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d9f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483da1  bfc01d5200             -mov edi, 0x521dc0
    cpu.edi = 5381568 /*0x521dc0*/;
    // 00483da6  3975e8                 +cmp dword ptr [ebp - 0x18], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483da9  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00483dab  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 00483dac  891da81c5200           -mov dword ptr [0x521ca8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */) = cpu.ebx;
    // 00483db2  0f86eb000000           -jbe 0x483ea3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483ea3;
    }
    // 00483db8  807dee00               +cmp byte ptr [ebp - 0x12], 0
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
    // 00483dbc  0f84bc000000           -je 0x483e7e
    if (cpu.flags.zf)
    {
        goto L_0x00483e7e;
    }
    // 00483dc2  8d4def                 -lea ecx, [ebp - 0x11]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-17) /* -0x11 */);
L_0x00483dc5:
    // 00483dc5  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00483dc7  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00483dc9  0f84af000000           -je 0x483e7e
    if (cpu.flags.zf)
    {
        goto L_0x00483e7e;
    }
    // 00483dcf  0fb641ff               -movzx eax, byte ptr [ecx - 1]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */));
    // 00483dd3  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
L_0x00483dd6:
    // 00483dd6  3bc2                   +cmp eax, edx
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
    // 00483dd8  0f8794000000           -ja 0x483e72
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483e72;
    }
    // 00483dde  8088c11d520004         +or byte ptr [eax + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00483de5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483de6  ebee                   -jmp 0x483dd6
    goto L_0x00483dd6;
L_0x00483de8:
    // 00483de8  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00483dec  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00483dee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483def  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483df1  bfc01d5200             -mov edi, 0x521dc0
    cpu.edi = 5381568 /*0x521dc0*/;
    // 00483df6  8d3452                 -lea esi, [edx + edx*2]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 2);
    // 00483df9  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00483dfb  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00483dfe  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 00483dff  8d9e486a4a00           -lea ebx, [esi + 0x4a6a48]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(4876872) /* 0x4a6a48 */);
L_0x00483e05:
    // 00483e05  803b00                 +cmp byte ptr [ebx], 0
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
    // 00483e08  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00483e0a  742c                   -je 0x483e38
    if (cpu.flags.zf)
    {
        goto L_0x00483e38;
    }
L_0x00483e0c:
    // 00483e0c  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00483e0f  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00483e11  7425                   -je 0x483e38
    if (cpu.flags.zf)
    {
        goto L_0x00483e38;
    }
    // 00483e13  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 00483e16  0fb6fa                 -movzx edi, dl
    cpu.edi = x86::reg32(cpu.dl);
    // 00483e19  3bc7                   +cmp eax, edi
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
    // 00483e1b  7714                   -ja 0x483e31
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483e31;
    }
    // 00483e1d  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00483e20  8a92306a4a00           -mov dl, byte ptr [edx + 0x4a6a30]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4876848) /* 0x4a6a30 */);
L_0x00483e26:
    // 00483e26  0890c11d5200           -or byte ptr [eax + 0x521dc1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) |= x86::reg8(x86::sreg8(cpu.dl));
    // 00483e2c  40                     -inc eax
    (cpu.eax)++;
    // 00483e2d  3bc7                   +cmp eax, edi
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
    // 00483e2f  76f5                   -jbe 0x483e26
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483e26;
    }
L_0x00483e31:
    // 00483e31  41                     -inc ecx
    (cpu.ecx)++;
    // 00483e32  41                     -inc ecx
    (cpu.ecx)++;
    // 00483e33  803900                 +cmp byte ptr [ecx], 0
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
    // 00483e36  75d4                   -jne 0x483e0c
    if (!cpu.flags.zf)
    {
        goto L_0x00483e0c;
    }
L_0x00483e38:
    // 00483e38  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00483e3b  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483e3e  837dfc04               +cmp dword ptr [ebp - 4], 4
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
    // 00483e42  72c1                   -jb 0x483e05
    if (cpu.flags.cf)
    {
        goto L_0x00483e05;
    }
    // 00483e44  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00483e47  c705bc1c520001000000   -mov dword ptr [0x521cbc], 1
    app->getMemory<x86::reg32>(x86::reg32(5381308) /* 0x521cbc */) = 1 /*0x1*/;
    // 00483e51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483e52  a3a81c5200             -mov dword ptr [0x521ca8], eax
    app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */) = cpu.eax;
    // 00483e57  e8ce000000             -call 0x483f2a
    cpu.esp -= 4;
    sub_483f2a(app, cpu);
    // 00483e5c  8db63c6a4a00           -lea esi, [esi + 0x4a6a3c]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4876860) /* 0x4a6a3c */);
    // 00483e62  bfb01c5200             -mov edi, 0x521cb0
    cpu.edi = 5381296 /*0x521cb0*/;
    // 00483e67  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00483e68  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00483e69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e6a  a3c41e5200             -mov dword ptr [0x521ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */) = cpu.eax;
    // 00483e6f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00483e70  eb52                   -jmp 0x483ec4
    goto L_0x00483ec4;
L_0x00483e72:
    // 00483e72  41                     -inc ecx
    (cpu.ecx)++;
    // 00483e73  41                     -inc ecx
    (cpu.ecx)++;
    // 00483e74  8079ff00               +cmp byte ptr [ecx - 1], 0
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
    // 00483e78  0f8547ffffff           -jne 0x483dc5
    if (!cpu.flags.zf)
    {
        goto L_0x00483dc5;
    }
L_0x00483e7e:
    // 00483e7e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00483e80:
    // 00483e80  8088c11d520008         -or byte ptr [eax + 0x521dc1], 8
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00483e87  40                     -inc eax
    (cpu.eax)++;
    // 00483e88  3dff000000             +cmp eax, 0xff
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
    // 00483e8d  72f1                   -jb 0x483e80
    if (cpu.flags.cf)
    {
        goto L_0x00483e80;
    }
    // 00483e8f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483e90  e895000000             -call 0x483f2a
    cpu.esp -= 4;
    sub_483f2a(app, cpu);
    // 00483e95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e96  a3c41e5200             -mov dword ptr [0x521ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */) = cpu.eax;
    // 00483e9b  8935bc1c5200           -mov dword ptr [0x521cbc], esi
    app->getMemory<x86::reg32>(x86::reg32(5381308) /* 0x521cbc */) = cpu.esi;
    // 00483ea1  eb07                   -jmp 0x483eaa
    goto L_0x00483eaa;
L_0x00483ea3:
    // 00483ea3  8325bc1c520000         -and dword ptr [0x521cbc], 0
    app->getMemory<x86::reg32>(x86::reg32(5381308) /* 0x521cbc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00483eaa:
    // 00483eaa  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00483eac  bfb01c5200             -mov edi, 0x521cb0
    cpu.edi = 5381296 /*0x521cb0*/;
    // 00483eb1  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00483eb2  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00483eb3  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00483eb4  eb0e                   -jmp 0x483ec4
    goto L_0x00483ec4;
L_0x00483eb6:
    // 00483eb6  833d1cee510000         +cmp dword ptr [0x51ee1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5369372) /* 0x51ee1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483ebd  740f                   -je 0x483ece
    if (cpu.flags.zf)
    {
        goto L_0x00483ece;
    }
L_0x00483ebf:
    // 00483ebf  e899000000             -call 0x483f5d
    cpu.esp -= 4;
    sub_483f5d(app, cpu);
L_0x00483ec4:
    // 00483ec4  e8bd000000             -call 0x483f86
    cpu.esp -= 4;
    sub_483f86(app, cpu);
    // 00483ec9  e98cfeffff             -jmp 0x483d5a
    goto L_0x00483d5a;
L_0x00483ece:
    // 00483ece  83ceff                 -or esi, 0xffffffff
    cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00483ed1:
    // 00483ed1  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00483ed3  e8528cffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00483ed8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ed9  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483edb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483edc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483edd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ede  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483edf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483ee0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483ee4  83251cee510000         -and dword ptr [0x51ee1c], 0
    app->getMemory<x86::reg32>(x86::reg32(5369372) /* 0x51ee1c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00483eeb  83f8fe                 +cmp eax, -2
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
    // 00483eee  7510                   -jne 0x483f00
    if (!cpu.flags.zf)
    {
        goto L_0x00483f00;
    }
    // 00483ef0  c7051cee510001000000   -mov dword ptr [0x51ee1c], 1
    app->getMemory<x86::reg32>(x86::reg32(5369372) /* 0x51ee1c */) = 1 /*0x1*/;
    // 00483efa  ff25cc704800           -jmp dword ptr [0x4870cc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4747468), cpu);
L_0x00483f00:
    // 00483f00  83f8fd                 +cmp eax, -3
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
    // 00483f03  7510                   -jne 0x483f15
    if (!cpu.flags.zf)
    {
        goto L_0x00483f15;
    }
    // 00483f05  c7051cee510001000000   -mov dword ptr [0x51ee1c], 1
    app->getMemory<x86::reg32>(x86::reg32(5369372) /* 0x51ee1c */) = 1 /*0x1*/;
    // 00483f0f  ff25c8704800           -jmp dword ptr [0x4870c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4747464), cpu);
L_0x00483f15:
    // 00483f15  83f8fc                 +cmp eax, -4
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
    // 00483f18  750f                   -jne 0x483f29
    if (!cpu.flags.zf)
    {
        goto L_0x00483f29;
    }
    // 00483f1a  a1d4eb5100             -mov eax, dword ptr [0x51ebd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    // 00483f1f  c7051cee510001000000   -mov dword ptr [0x51ee1c], 1
    app->getMemory<x86::reg32>(x86::reg32(5369372) /* 0x51ee1c */) = 1 /*0x1*/;
L_0x00483f29:
    // 00483f29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483f2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f2a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483f2e  2da4030000             +sub eax, 0x3a4
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
    // 00483f33  7422                   -je 0x483f57
    if (cpu.flags.zf)
    {
        goto L_0x00483f57;
    }
    // 00483f35  83e804                 +sub eax, 4
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
    // 00483f38  7417                   -je 0x483f51
    if (cpu.flags.zf)
    {
        goto L_0x00483f51;
    }
    // 00483f3a  83e80d                 +sub eax, 0xd
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
    // 00483f3d  740c                   -je 0x483f4b
    if (cpu.flags.zf)
    {
        goto L_0x00483f4b;
    }
    // 00483f3f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483f40  7403                   -je 0x483f45
    if (cpu.flags.zf)
    {
        goto L_0x00483f45;
    }
    // 00483f42  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f45:
    // 00483f45  b804040000             -mov eax, 0x404
    cpu.eax = 1028 /*0x404*/;
    // 00483f4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f4b:
    // 00483f4b  b812040000             -mov eax, 0x412
    cpu.eax = 1042 /*0x412*/;
    // 00483f50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f51:
    // 00483f51  b804080000             -mov eax, 0x804
    cpu.eax = 2052 /*0x804*/;
    // 00483f56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f57:
    // 00483f57  b811040000             -mov eax, 0x411
    cpu.eax = 1041 /*0x411*/;
    // 00483f5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483f5d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f5d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483f5e  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00483f60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f61  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f63  bfc01d5200             -mov edi, 0x521dc0
    cpu.edi = 5381568 /*0x521dc0*/;
    // 00483f68  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00483f6a  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 00483f6b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f6d  bfb01c5200             -mov edi, 0x521cb0
    cpu.edi = 5381296 /*0x521cb0*/;
    // 00483f72  a3a81c5200             -mov dword ptr [0x521ca8], eax
    app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */) = cpu.eax;
    // 00483f77  a3bc1c5200             -mov dword ptr [0x521cbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5381308) /* 0x521cbc */) = cpu.eax;
    // 00483f7c  a3c41e5200             -mov dword ptr [0x521ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */) = cpu.eax;
    // 00483f81  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00483f82  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00483f83  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00483f84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483f86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483f87  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00483f89  81ec14050000           -sub esp, 0x514
    (cpu.esp) -= x86::reg32(x86::sreg32(1300 /*0x514*/));
    // 00483f8f  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00483f92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483f93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483f94  ff35a81c5200           -push dword ptr [0x521ca8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */);
    cpu.esp -= 4;
    // 00483f9a  ff1524714800           -call dword ptr [0x487124]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747556) /* 0x487124 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00483fa0  83f801                 +cmp eax, 1
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
    // 00483fa3  0f8516010000           -jne 0x4840bf
    if (!cpu.flags.zf)
    {
        goto L_0x004840bf;
    }
    // 00483fa9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483fab  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
L_0x00483fb0:
    // 00483fb0  888405ecfeffff         -mov byte ptr [ebp + eax - 0x114], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-276) /* -0x114 */ + cpu.eax * 1) = cpu.al;
    // 00483fb7  40                     -inc eax
    (cpu.eax)++;
    // 00483fb8  3bc6                   +cmp eax, esi
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
    // 00483fba  72f4                   -jb 0x483fb0
    if (cpu.flags.cf)
    {
        goto L_0x00483fb0;
    }
    // 00483fbc  8a45f2                 -mov al, byte ptr [ebp - 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00483fbf  c685ecfeffff20         -mov byte ptr [ebp - 0x114], 0x20
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-276) /* -0x114 */) = 32 /*0x20*/;
    // 00483fc6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00483fc8  7437                   -je 0x484001
    if (cpu.flags.zf)
    {
        goto L_0x00484001;
    }
    // 00483fca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483fcb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483fcc  8d55f3                 -lea edx, [ebp - 0xd]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-13) /* -0xd */);
L_0x00483fcf:
    // 00483fcf  0fb60a                 -movzx ecx, byte ptr [edx]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.edx));
    // 00483fd2  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 00483fd5  3bc1                   +cmp eax, ecx
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
    // 00483fd7  771d                   -ja 0x483ff6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483ff6;
    }
    // 00483fd9  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00483fdb  8dbc05ecfeffff         -lea edi, [ebp + eax - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */ + cpu.eax * 1);
    // 00483fe2  41                     -inc ecx
    (cpu.ecx)++;
    // 00483fe3  b820202020             -mov eax, 0x20202020
    cpu.eax = 538976288 /*0x20202020*/;
    // 00483fe8  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00483fea  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00483fed  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00483fef  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00483ff1  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00483ff4  f3aa                   -rep stosb byte ptr es:[edi], al
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
L_0x00483ff6:
    // 00483ff6  42                     -inc edx
    (cpu.edx)++;
    // 00483ff7  42                     -inc edx
    (cpu.edx)++;
    // 00483ff8  8a42ff                 -mov al, byte ptr [edx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00483ffb  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00483ffd  75d0                   -jne 0x483fcf
    if (!cpu.flags.zf)
    {
        goto L_0x00483fcf;
    }
    // 00483fff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484000  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484001:
    // 00484001  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484003  8d85ecfaffff           -lea eax, [ebp - 0x514]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 00484009  ff35c41e5200           -push dword ptr [0x521ec4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */);
    cpu.esp -= 4;
    // 0048400f  ff35a81c5200           -push dword ptr [0x521ca8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */);
    cpu.esp -= 4;
    // 00484015  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484016  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0048401c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048401d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048401e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484020  e815e8ffff             -call 0x48283a
    cpu.esp -= 4;
    sub_48283a(app, cpu);
    // 00484025  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484027  8d85ecfdffff           -lea eax, [ebp - 0x214]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-532) /* -0x214 */);
    // 0048402d  ff35a81c5200           -push dword ptr [0x521ca8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */);
    cpu.esp -= 4;
    // 00484033  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484034  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484035  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0048403b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048403c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048403d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048403e  ff35c41e5200           -push dword ptr [0x521ec4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */);
    cpu.esp -= 4;
    // 00484044  e81c90ffff             -call 0x47d065
    cpu.esp -= 4;
    sub_47d065(app, cpu);
    // 00484049  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048404b  8d85ecfcffff           -lea eax, [ebp - 0x314]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-788) /* -0x314 */);
    // 00484051  ff35a81c5200           -push dword ptr [0x521ca8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */);
    cpu.esp -= 4;
    // 00484057  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484058  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484059  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0048405f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484060  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484061  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00484066  ff35c41e5200           -push dword ptr [0x521ec4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */);
    cpu.esp -= 4;
    // 0048406c  e8f48fffff             -call 0x47d065
    cpu.esp -= 4;
    sub_47d065(app, cpu);
    // 00484071  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00484074  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484076  8d8decfaffff           -lea ecx, [ebp - 0x514]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
L_0x0048407c:
    // 0048407c  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 0048407f  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00484082  7416                   -je 0x48409a
    if (cpu.flags.zf)
    {
        goto L_0x0048409a;
    }
    // 00484084  8088c11d520010         +or byte ptr [eax + 0x521dc1], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048408b  8a9405ecfdffff         -mov dl, byte ptr [ebp + eax - 0x214]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-532) /* -0x214 */ + cpu.eax * 1);
L_0x00484092:
    // 00484092  8890c01c5200           -mov byte ptr [eax + 0x521cc0], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381312) /* 0x521cc0 */) = cpu.dl;
    // 00484098  eb1c                   -jmp 0x4840b6
    goto L_0x004840b6;
L_0x0048409a:
    // 0048409a  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0048409d  7410                   -je 0x4840af
    if (cpu.flags.zf)
    {
        goto L_0x004840af;
    }
    // 0048409f  8088c11d520020         +or byte ptr [eax + 0x521dc1], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004840a6  8a9405ecfcffff         -mov dl, byte ptr [ebp + eax - 0x314]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-788) /* -0x314 */ + cpu.eax * 1);
    // 004840ad  ebe3                   -jmp 0x484092
    goto L_0x00484092;
L_0x004840af:
    // 004840af  80a0c01c520000         -and byte ptr [eax + 0x521cc0], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381312) /* 0x521cc0 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x004840b6:
    // 004840b6  40                     -inc eax
    (cpu.eax)++;
    // 004840b7  41                     -inc ecx
    (cpu.ecx)++;
    // 004840b8  41                     -inc ecx
    (cpu.ecx)++;
    // 004840b9  3bc6                   +cmp eax, esi
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
    // 004840bb  72bf                   -jb 0x48407c
    if (cpu.flags.cf)
    {
        goto L_0x0048407c;
    }
    // 004840bd  eb49                   -jmp 0x484108
    goto L_0x00484108;
L_0x004840bf:
    // 004840bf  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004840c1  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
L_0x004840c6:
    // 004840c6  83f841                 +cmp eax, 0x41
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
    // 004840c9  7219                   -jb 0x4840e4
    if (cpu.flags.cf)
    {
        goto L_0x004840e4;
    }
    // 004840cb  83f85a                 +cmp eax, 0x5a
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
    // 004840ce  7714                   -ja 0x4840e4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004840e4;
    }
    // 004840d0  8088c11d520010         -or byte ptr [eax + 0x521dc1], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004840d7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004840d9  80c120                 +add cl, 0x20
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
L_0x004840dc:
    // 004840dc  8888c01c5200           -mov byte ptr [eax + 0x521cc0], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381312) /* 0x521cc0 */) = cpu.cl;
    // 004840e2  eb1f                   -jmp 0x484103
    goto L_0x00484103;
L_0x004840e4:
    // 004840e4  83f861                 +cmp eax, 0x61
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
    // 004840e7  7213                   -jb 0x4840fc
    if (cpu.flags.cf)
    {
        goto L_0x004840fc;
    }
    // 004840e9  83f87a                 +cmp eax, 0x7a
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
    // 004840ec  770e                   -ja 0x4840fc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004840fc;
    }
    // 004840ee  8088c11d520020         -or byte ptr [eax + 0x521dc1], 0x20
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004840f5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004840f7  80e920                 +sub cl, 0x20
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
    // 004840fa  ebe0                   -jmp 0x4840dc
    goto L_0x004840dc;
L_0x004840fc:
    // 004840fc  80a0c01c520000         -and byte ptr [eax + 0x521cc0], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381312) /* 0x521cc0 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x00484103:
    // 00484103  40                     -inc eax
    (cpu.eax)++;
    // 00484104  3bc6                   +cmp eax, esi
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
    // 00484106  72be                   -jb 0x4840c6
    if (cpu.flags.cf)
    {
        goto L_0x004840c6;
    }
L_0x00484108:
    // 00484108  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484109  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048410a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48410b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048410b  833d1820520000         +cmp dword ptr [0x522018], 0
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
    // 00484112  7512                   -jne 0x484126
    if (!cpu.flags.zf)
    {
        goto L_0x00484126;
    }
    // 00484114  6afd                   -push -3
    app->getMemory<x86::reg32>(cpu.esp-4) = -3 /*-0x3*/;
    cpu.esp -= 4;
    // 00484116  e818fcffff             -call 0x483d33
    cpu.esp -= 4;
    sub_483d33(app, cpu);
    // 0048411b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048411c  c7051820520001000000   -mov dword ptr [0x522018], 1
    app->getMemory<x86::reg32>(x86::reg32(5382168) /* 0x522018 */) = 1 /*0x1*/;
L_0x00484126:
    // 00484126  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484127(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484127  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00484129  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048412b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0048412f  e804000000             -call 0x484138
    cpu.esp -= 4;
    sub_484138(app, cpu);
    // 00484134  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484137  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484138(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484138  0fb6442404             -movzx eax, byte ptr [esp + 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0048413d  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484141  8488c11d5200           -test byte ptr [eax + 0x521dc1], cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) & cpu.cl));
    // 00484147  751c                   -jne 0x484165
    if (!cpu.flags.zf)
    {
        goto L_0x00484165;
    }
    // 00484149  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0048414e  740e                   -je 0x48415e
    if (cpu.flags.zf)
    {
        goto L_0x0048415e;
    }
    // 00484150  0fb7044516624a00       -movzx eax, word ptr [eax*2 + 0x4a6216]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4874774) /* 0x4a6216 */ + cpu.eax * 2));
    // 00484158  23442408               +and eax, dword ptr [esp + 8]
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)))));
    // 0048415c  eb02                   -jmp 0x484160
    goto L_0x00484160;
L_0x0048415e:
    // 0048415e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484160:
    // 00484160  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484162  7501                   -jne 0x484165
    if (!cpu.flags.zf)
    {
        goto L_0x00484165;
    }
    // 00484164  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484165:
    // 00484165  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484167  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484169(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484169  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048416a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048416c  391d20ee5100           +cmp dword ptr [0x51ee20], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5369376) /* 0x51ee20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484172  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484173  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484174  7542                   -jne 0x4841b8
    if (!cpu.flags.zf)
    {
        goto L_0x004841b8;
    }
    // 00484176  6878864800             -push 0x488678
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753016 /*0x488678*/;
    cpu.esp -= 4;
    // 0048417b  ff1558704800           -call dword ptr [0x487058]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747352) /* 0x487058 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484181  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484183  3bfb                   +cmp edi, ebx
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
    // 00484185  7467                   -je 0x4841ee
    if (cpu.flags.zf)
    {
        goto L_0x004841ee;
    }
    // 00484187  8b3584704800           -mov esi, dword ptr [0x487084]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747396) /* 0x487084 */);
    // 0048418d  686c864800             -push 0x48866c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753004 /*0x48866c*/;
    cpu.esp -= 4;
    // 00484192  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484193  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484195  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484197  a320ee5100             -mov dword ptr [0x51ee20], eax
    app->getMemory<x86::reg32>(x86::reg32(5369376) /* 0x51ee20 */) = cpu.eax;
    // 0048419c  7450                   -je 0x4841ee
    if (cpu.flags.zf)
    {
        goto L_0x004841ee;
    }
    // 0048419e  685c864800             -push 0x48865c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752988 /*0x48865c*/;
    cpu.esp -= 4;
    // 004841a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004841a4  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004841a6  6848864800             -push 0x488648
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752968 /*0x488648*/;
    cpu.esp -= 4;
    // 004841ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004841ac  a324ee5100             -mov dword ptr [0x51ee24], eax
    app->getMemory<x86::reg32>(x86::reg32(5369380) /* 0x51ee24 */) = cpu.eax;
    // 004841b1  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004841b3  a328ee5100             -mov dword ptr [0x51ee28], eax
    app->getMemory<x86::reg32>(x86::reg32(5369384) /* 0x51ee28 */) = cpu.eax;
L_0x004841b8:
    // 004841b8  a124ee5100             -mov eax, dword ptr [0x51ee24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369380) /* 0x51ee24 */);
    // 004841bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004841bf  7416                   -je 0x4841d7
    if (cpu.flags.zf)
    {
        goto L_0x004841d7;
    }
    // 004841c1  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004841c3  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004841c5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004841c7  740e                   -je 0x4841d7
    if (cpu.flags.zf)
    {
        goto L_0x004841d7;
    }
    // 004841c9  a128ee5100             -mov eax, dword ptr [0x51ee28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369384) /* 0x51ee28 */);
    // 004841ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004841d0  7405                   -je 0x4841d7
    if (cpu.flags.zf)
    {
        goto L_0x004841d7;
    }
    // 004841d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004841d3  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004841d5  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004841d7:
    // 004841d7  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004841db  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004841df  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004841e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004841e4  ff1520ee5100           -call dword ptr [0x51ee20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5369376) /* 0x51ee20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004841ea:
    // 004841ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004841eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004841ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004841ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004841ee:
    // 004841ee  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004841f0  ebf8                   -jmp 0x4841ea
    goto L_0x004841ea;
}

/* align: skip  */
void Application::sub_4841f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004841f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004841f3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004841f7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004841f9  813863736de0           +cmp dword ptr [eax], 0xe06d7363
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
    // 004841ff  7514                   -jne 0x484215
    if (!cpu.flags.zf)
    {
        goto L_0x00484215;
    }
    // 00484201  83781003               +cmp dword ptr [eax + 0x10], 3
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
    // 00484205  750e                   -jne 0x484215
    if (!cpu.flags.zf)
    {
        goto L_0x00484215;
    }
    // 00484207  81781420059319         +cmp dword ptr [eax + 0x14], 0x19930520
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
    // 0048420e  7505                   -jne 0x484215
    if (!cpu.flags.zf)
    {
        goto L_0x00484215;
    }
    // 00484210  e947d4ffff             -jmp 0x48165c
    return sub_48165c(app, cpu);
L_0x00484215:
    // 00484215  a12cee5100             -mov eax, dword ptr [0x51ee2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369388) /* 0x51ee2c */);
    // 0048421a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048421c  7414                   -je 0x484232
    if (cpu.flags.zf)
    {
        goto L_0x00484232;
    }
    // 0048421e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048421f  e86a000000             -call 0x48428e
    cpu.esp -= 4;
    sub_48428e(app, cpu);
    // 00484224  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484226  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484227  7409                   -je 0x484232
    if (cpu.flags.zf)
    {
        goto L_0x00484232;
    }
    // 00484229  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048422a  ff152cee5100           -call dword ptr [0x51ee2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5369388) /* 0x51ee2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484230  eb02                   -jmp 0x484234
    goto L_0x00484234;
L_0x00484232:
    // 00484232  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484234:
    // 00484234  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484235  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_484238(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484238  68f2414800             -push 0x4841f2
    app->getMemory<x86::reg32>(cpu.esp-4) = 4735474 /*0x4841f2*/;
    cpu.esp -= 4;
    // 0048423d  ff15a4704800           -call dword ptr [0x4870a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747428) /* 0x4870a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484243  a32cee5100             -mov dword ptr [0x51ee2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5369388) /* 0x51ee2c */) = cpu.eax;
    // 00484248  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484249(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484249  ff352cee5100           -push dword ptr [0x51ee2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5369388) /* 0x51ee2c */);
    cpu.esp -= 4;
    // 0048424f  ff15a4704800           -call dword ptr [0x4870a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747428) /* 0x4870a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484255  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484256(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484256  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484257  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484259  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048425a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0048425e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484262  ff15bc704800           -call dword ptr [0x4870bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747452) /* 0x4870bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484268  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048426a  7402                   -je 0x48426e
    if (cpu.flags.zf)
    {
        goto L_0x0048426e;
    }
    // 0048426c  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048426e:
    // 0048426e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484270  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484271  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484272(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484272  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484273  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484275  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484276  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0048427a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0048427e  ff1570704800           -call dword ptr [0x487070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747376) /* 0x487070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484284  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484286  7402                   -je 0x48428a
    if (cpu.flags.zf)
    {
        goto L_0x0048428a;
    }
    // 00484288  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048428a:
    // 0048428a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048428c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048428d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48428e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048428e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048428f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484291  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484292  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484296  ff15a8704800           -call dword ptr [0x4870a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747432) /* 0x4870a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048429c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048429e  7402                   -je 0x4842a2
    if (cpu.flags.zf)
    {
        goto L_0x004842a2;
    }
    // 004842a0  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004842a2:
    // 004842a2  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004842a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4842a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004842a6  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004842a8  e8eac9ffff             -call 0x480c97
    cpu.esp -= 4;
    sub_480c97(app, cpu);
    // 004842ad  6a16                   -push 0x16
    app->getMemory<x86::reg32>(cpu.esp-4) = 22 /*0x16*/;
    cpu.esp -= 4;
    // 004842af  e809000000             -call 0x4842bd
    cpu.esp -= 4;
    sub_4842bd(app, cpu);
    // 004842b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842b6  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004842b8  e8b343ffff             -call 0x478670
    cpu.esp -= 4;
    __exit(app, cpu);
    return sub_4842bd(app, cpu);
}

}
