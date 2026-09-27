#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_426b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426b10  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00426b13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426b14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426b15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426b16  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00426b18  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426b19  8bae20010000           -mov ebp, dword ptr [esi + 0x120]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */);
    // 00426b1f  8b8618010000           -mov eax, dword ptr [esi + 0x118]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */);
    // 00426b25  8bdd                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00426b27  8bbe10010000           -mov edi, dword ptr [esi + 0x110]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 00426b2d  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00426b30  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00426b34  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00426b36  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00426b39  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00426b3c  896c2424               -mov dword ptr [esp + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 00426b40  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00426b44  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00426b47  8d0c00                 -lea ecx, [eax + eax]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00426b4a  e8a172feff             -call 0x40ddf0
    cpu.esp -= 4;
    sub_40ddf0(app, cpu);
    // 00426b4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426b51  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00426b53  750d                   -jne 0x426b62
    if (!cpu.flags.zf)
    {
        goto L_0x00426b62;
    }
    // 00426b55  68503a4900             -push 0x493a50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799056 /*0x493a50*/;
    cpu.esp -= 4;
    // 00426b5a  e8b1e0ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00426b5f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00426b62:
    // 00426b62  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00426b64  3bfa                   +cmp edi, edx
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
    // 00426b66  0f8eb5000000           -jle 0x426c21
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00426c21;
    }
    // 00426b6c  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00426b70  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00426b74  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
L_0x00426b78:
    // 00426b78  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00426b7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426b7e  7e7b                   -jle 0x426bfb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00426bfb;
    }
    // 00426b80  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00426b84  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00426b86  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00426b8a:
    // 00426b8a  8d45ff                 -lea eax, [ebp - 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00426b8d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00426b8f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426b91  7e46                   -jle 0x426bd9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00426bd9;
    }
    // 00426b93  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00426b95  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00426b97  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00426b99:
    // 00426b99  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 00426b9f  83f801                 +cmp eax, 1
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
    // 00426ba2  7423                   -je 0x426bc7
    if (cpu.flags.zf)
    {
        goto L_0x00426bc7;
    }
    // 00426ba4  83f807                 +cmp eax, 7
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
    // 00426ba7  741e                   -je 0x426bc7
    if (cpu.flags.zf)
    {
        goto L_0x00426bc7;
    }
    // 00426ba9  83f806                 +cmp eax, 6
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
    // 00426bac  7419                   -je 0x426bc7
    if (cpu.flags.zf)
    {
        goto L_0x00426bc7;
    }
    // 00426bae  83f808                 +cmp eax, 8
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
    // 00426bb1  7414                   -je 0x426bc7
    if (cpu.flags.zf)
    {
        goto L_0x00426bc7;
    }
    // 00426bb3  83f809                 +cmp eax, 9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426bb6  740f                   -je 0x426bc7
    if (cpu.flags.zf)
    {
        goto L_0x00426bc7;
    }
    // 00426bb8  83f80a                 +cmp eax, 0xa
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
    // 00426bbb  740a                   -je 0x426bc7
    if (cpu.flags.zf)
    {
        goto L_0x00426bc7;
    }
    // 00426bbd  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00426bbf  66c704014100           -mov word ptr [ecx + eax], 0x41
    app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 1) = 65 /*0x41*/;
    // 00426bc5  eb08                   -jmp 0x426bcf
    goto L_0x00426bcf;
L_0x00426bc7:
    // 00426bc7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00426bc9  66c704012000           -mov word ptr [ecx + eax], 0x20
    app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 1) = 32 /*0x20*/;
L_0x00426bcf:
    // 00426bcf  83c102                 +add ecx, 2
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
    // 00426bd2  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00426bd3  75c4                   -jne 0x426b99
    if (!cpu.flags.zf)
    {
        goto L_0x00426b99;
    }
    // 00426bd5  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
L_0x00426bd9:
    // 00426bd9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00426bdb  8d0c3a                 -lea ecx, [edx + edi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edi * 1);
    // 00426bde  03d5                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00426be0  66c704482000           -mov word ptr [eax + ecx*2], 0x20
    app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2) = 32 /*0x20*/;
    // 00426be6  8d442d00               -lea eax, [ebp + ebp]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 1);
    // 00426bea  03d8                   +add ebx, eax
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
    // 00426bec  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00426bf0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00426bf1  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00426bf5  7593                   -jne 0x426b8a
    if (!cpu.flags.zf)
    {
        goto L_0x00426b8a;
    }
    // 00426bf7  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x00426bfb:
    // 00426bfb  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00426bff  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00426c03  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 00426c06  03d3                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00426c08  03c8                   +add ecx, eax
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
    // 00426c0a  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00426c0e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00426c0f  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00426c13  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00426c17  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00426c1b  0f8557ffffff           -jne 0x426b78
    if (!cpu.flags.zf)
    {
        goto L_0x00426b78;
    }
L_0x00426c21:
    // 00426c21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426c22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426c23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426c24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426c25  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00426c28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426c30  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00426c33  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426c34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426c35  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00426c37  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00426c3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426c3c  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00426c40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426c41  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00426c45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426c46  8b8d30010000           -mov ecx, dword ptr [ebp + 0x130]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(304) /* 0x130 */);
    // 00426c4c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426c4d  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00426c51  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00426c53  e80824ffff             -call 0x419060
    cpu.esp -= 4;
    sub_419060(app, cpu);
    // 00426c58  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 00426c5b  8b853c010000           -mov eax, dword ptr [ebp + 0x13c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(316) /* 0x13c */);
    // 00426c61  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00426c63  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00426c67  746d                   -je 0x426cd6
    if (cpu.flags.zf)
    {
        goto L_0x00426cd6;
    }
    // 00426c69  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426c6a  8d7d08                 -lea edi, [ebp + 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00426c6d:
    // 00426c6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426c6e  e82a110500             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 00426c73  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00426c77  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00426c7b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00426c7e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00426c80  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00426c82  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00426c84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426c85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426c86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426c87  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00426c89  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00426c8d  e80e7afeff             -call 0x40e6a0
    cpu.esp -= 4;
    sub_40e6a0(app, cpu);
    // 00426c92  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00426c96  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00426c9a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426c9b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00426c9d  e8ee010000             -call 0x426e90
    cpu.esp -= 4;
    sub_426e90(app, cpu);
    // 00426ca2  898780000000           -mov dword ptr [edi + 0x80], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 00426ca8  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 00426caa  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00426cae  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00426cb2  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00426cb6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00426cb8  68403a4900             -push 0x493a40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799040 /*0x493a40*/;
    cpu.esp -= 4;
    // 00426cbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426cbe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426cbf  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00426cc3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426cc4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00426cc6  e8357bfeff             -call 0x40e800
    cpu.esp -= 4;
    sub_40e800(app, cpu);
    // 00426ccb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00426ccd  43                     -inc ebx
    (cpu.ebx)++;
    // 00426cce  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00426cd1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00426cd3  7598                   -jne 0x426c6d
    if (!cpu.flags.zf)
    {
        goto L_0x00426c6d;
    }
    // 00426cd5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00426cd6:
    // 00426cd6  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00426cda  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00426cde  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426cdf  8b8d30010000           -mov ecx, dword ptr [ebp + 0x130]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(304) /* 0x130 */);
    // 00426ce5  899d10010000           -mov dword ptr [ebp + 0x110], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(272) /* 0x110 */) = cpu.ebx;
    // 00426ceb  e8b023ffff             -call 0x4190a0
    cpu.esp -= 4;
    sub_4190a0(app, cpu);
    // 00426cf0  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00426cf4  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00426cf8  899520010000           -mov dword ptr [ebp + 0x120], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(288) /* 0x120 */) = cpu.edx;
    // 00426cfe  898518010000           -mov dword ptr [ebp + 0x118], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(280) /* 0x118 */) = cpu.eax;
    // 00426d04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426d05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426d06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426d07  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00426d0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426d10  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00426d13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426d14  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00426d16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426d17  8b8e30010000           -mov ecx, dword ptr [esi + 0x130]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 00426d1d  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00426d1f  83e800                 +sub eax, 0
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
    // 00426d22  0f84c2000000           -je 0x426dea
    if (cpu.flags.zf)
    {
        goto L_0x00426dea;
    }
    // 00426d28  83e802                 +sub eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00426d2b  7471                   -je 0x426d9e
    if (cpu.flags.zf)
    {
        goto L_0x00426d9e;
    }
    // 00426d2d  83e802                 +sub eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00426d30  7440                   -je 0x426d72
    if (cpu.flags.zf)
    {
        goto L_0x00426d72;
    }
    // 00426d32  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00426d36  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00426d3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426d3b  e86023ffff             -call 0x4190a0
    cpu.esp -= 4;
    sub_4190a0(app, cpu);
    // 00426d40  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00426d44  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00426d48  898e20010000           -mov dword ptr [esi + 0x120], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */) = cpu.ecx;
    // 00426d4e  8b8e30010000           -mov ecx, dword ptr [esi + 0x130]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 00426d54  899618010000           -mov dword ptr [esi + 0x118], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */) = cpu.edx;
    // 00426d5a  e861fdffff             -call 0x426ac0
    cpu.esp -= 4;
    sub_426ac0(app, cpu);
    // 00426d5f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00426d61  898610010000           -mov dword ptr [esi + 0x110], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */) = cpu.eax;
    // 00426d67  e8a4fdffff             -call 0x426b10
    cpu.esp -= 4;
    sub_426b10(app, cpu);
    // 00426d6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426d6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426d6e  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00426d71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00426d72:
    // 00426d72  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00426d76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426d77  6898054900             -push 0x490598
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785560 /*0x490598*/;
    cpu.esp -= 4;
    // 00426d7c  e87fe00200             -call 0x454e00
    cpu.esp -= 4;
    sub_454e00(app, cpu);
    // 00426d81  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00426d83  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00426d86  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00426d88  7460                   -je 0x426dea
    if (cpu.flags.zf)
    {
        goto L_0x00426dea;
    }
    // 00426d8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426d8b  e80d100500             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 00426d90  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00426d93  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00426d95  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00426d98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426d99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426d9a  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00426d9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00426d9e:
    // 00426d9e  8b0d10155200           -mov ecx, dword ptr [0x521510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 00426da4  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00426da8  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00426dae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426daf  68743a4900             -push 0x493a74
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799092 /*0x493a74*/;
    cpu.esp -= 4;
    // 00426db4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426db5  e83e000500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00426dba  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00426dbe  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00426dc2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426dc3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426dc4  e837e00200             -call 0x454e00
    cpu.esp -= 4;
    sub_454e00(app, cpu);
    // 00426dc9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00426dcb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00426dce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00426dd0  7418                   -je 0x426dea
    if (cpu.flags.zf)
    {
        goto L_0x00426dea;
    }
    // 00426dd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426dd3  e8c50f0500             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 00426dd8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00426ddc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00426ddf  89963c010000           -mov dword ptr [esi + 0x13c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(316) /* 0x13c */) = cpu.edx;
    // 00426de5  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00426de7  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00426dea:
    // 00426dea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426deb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426dec  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00426def  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426df1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426df2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426df3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426df4  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00426df6  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00426df8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426df9  68b03a4900             -push 0x493ab0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799152 /*0x493ab0*/;
    cpu.esp -= 4;
    // 00426dfe  e8b4ff0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00426e03  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00426e06  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00426e08  e8b3fbfeff             -call 0x4169c0
    cpu.esp -= 4;
    sub_4169c0(app, cpu);
    // 00426e0d  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00426e0f  e88cfcffff             -call 0x426aa0
    cpu.esp -= 4;
    sub_426aa0(app, cpu);
    // 00426e14  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00426e16  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00426e18  c7863401000000000000   -mov dword ptr [esi + 0x134], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(308) /* 0x134 */) = 0 /*0x0*/;
    // 00426e22  89be30010000           -mov dword ptr [esi + 0x130], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */) = cpu.edi;
    // 00426e28  e8e3feffff             -call 0x426d10
    cpu.esp -= 4;
    sub_426d10(app, cpu);
    // 00426e2d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00426e2f  e8fcfdffff             -call 0x426c30
    cpu.esp -= 4;
    sub_426c30(app, cpu);
    // 00426e34  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00426e36  e8d5fafeff             -call 0x416910
    cpu.esp -= 4;
    sub_416910(app, cpu);
    // 00426e3b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00426e3d  898644010000           -mov dword ptr [esi + 0x144], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(324) /* 0x144 */) = cpu.eax;
    // 00426e43  e868fbfeff             -call 0x4169b0
    cpu.esp -= 4;
    sub_4169b0(app, cpu);
    // 00426e48  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00426e4a  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00426e4c  898648010000           -mov dword ptr [esi + 0x148], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(328) /* 0x148 */) = cpu.eax;
    // 00426e52  e879e3feff             -call 0x4151d0
    cpu.esp -= 4;
    sub_4151d0(app, cpu);
    // 00426e57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426e59  89864c010000           -mov dword ptr [esi + 0x14c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(332) /* 0x14c */) = cpu.eax;
    // 00426e5f  750d                   -jne 0x426e6e
    if (!cpu.flags.zf)
    {
        goto L_0x00426e6e;
    }
    // 00426e61  68843a4900             -push 0x493a84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799108 /*0x493a84*/;
    cpu.esp -= 4;
    // 00426e66  e8a5ddffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00426e6b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00426e6e:
    // 00426e6e  8b864c010000           -mov eax, dword ptr [esi + 0x14c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(332) /* 0x14c */);
    // 00426e74  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00426e76  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00426e78  8988d0000000           -mov dword ptr [eax + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 00426e7e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00426e80  7406                   -je 0x426e88
    if (cpu.flags.zf)
    {
        goto L_0x00426e88;
    }
    // 00426e82  89ae50010000           -mov dword ptr [esi + 0x150], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(336) /* 0x150 */) = cpu.ebp;
L_0x00426e88:
    // 00426e88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426e89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426e8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426e8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426e8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426e90  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00426e93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426e94  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426e95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426e96  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00426e98  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00426e9a  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00426e9c  c744240c00000000       -mov dword ptr [esp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00426ea4  0f84c1000000           -je 0x426f6b
    if (cpu.flags.zf)
    {
        goto L_0x00426f6b;
    }
    // 00426eaa  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00426eae  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00426eb0  0f84b5000000           -je 0x426f6b
    if (cpu.flags.zf)
    {
        goto L_0x00426f6b;
    }
    // 00426eb6  e81570feff             -call 0x40ded0
    cpu.esp -= 4;
    sub_40ded0(app, cpu);
    // 00426ebb  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00426ebe  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00426ec1  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00426ec5  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00426ec9  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00426ecd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426ece  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426ed0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426ed1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00426ed3  d95c2424               -fstp dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00426ed7  e8147ffeff             -call 0x40edf0
    cpu.esp -= 4;
    sub_40edf0(app, cpu);
    // 00426edc  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00426ee0  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00426ee4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426ee6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00426ee8  e8a3fe0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00426eed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426eee  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00426ef0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00426ef2  e8f97efeff             -call 0x40edf0
    cpu.esp -= 4;
    sub_40edf0(app, cpu);
    // 00426ef7  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00426efb  d8d1                   -fcom st(1)
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(cpu.fpu.st(1)));
    // 00426efd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00426eff  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00426f02  7b10                   -jnp 0x426f14
    if (!cpu.flags.pf)
    {
        goto L_0x00426f14;
    }
    // 00426f04  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00426f08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426f0a  742e                   -je 0x426f3a
    if (cpu.flags.zf)
    {
        goto L_0x00426f3a;
    }
    // 00426f0c  d805b8744800           +fadd dword ptr [0x4874b8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 00426f12  eb26                   -jmp 0x426f3a
    goto L_0x00426f3a;
L_0x00426f14:
    // 00426f14  db4610                 -fild dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */))));
    // 00426f17  d80db8754800           -fmul dword ptr [0x4875b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748728) /* 0x4875b8 */));
    // 00426f1d  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00426f21  d8542418               -fcom dword ptr [esp + 0x18]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00426f25  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00426f27  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00426f2a  7a08                   -jp 0x426f34
    if (cpu.flags.pf)
    {
        goto L_0x00426f34;
    }
    // 00426f2c  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00426f2e  d9442418               +fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00426f32  eb06                   -jmp 0x426f3a
    goto L_0x00426f3a;
L_0x00426f34:
    // 00426f34  d80590744800           -fadd dword ptr [0x487490]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748432) /* 0x487490 */));
L_0x00426f3a:
    // 00426f3a  db03                   -fild dword ptr [ebx]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))));
    // 00426f3c  def2                   -fdivrp st(2)
    cpu.fpu.st(2) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(2));
    cpu.fpu.pop();
    // 00426f3e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00426f40  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00426f42  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00426f44  e847fe0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00426f49  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00426f4b  2bc8                   +sub ecx, eax
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
    // 00426f4d  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 00426f4f  7906                   -jns 0x426f57
    if (!cpu.flags.sf)
    {
        goto L_0x00426f57;
    }
    // 00426f51  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
L_0x00426f57:
    // 00426f57  dc0dd8744800           -fmul qword ptr [0x4874d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 00426f5d  e82efe0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00426f62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426f63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426f64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426f65  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00426f68  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00426f6b:
    // 00426f6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426f6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426f6d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426f6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426f70  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00426f73  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_426f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426f80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426f81  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00426f83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426f84  d98640010000           -fld dword ptr [esi + 0x140]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(320) /* 0x140 */)));
    // 00426f8a  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00426f90  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00426f92  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00426f95  7b74                   -jnp 0x42700b
    if (!cpu.flags.pf)
    {
        goto L_0x0042700b;
    }
    // 00426f97  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 00426f9d  8b8e0c010000           -mov ecx, dword ptr [esi + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00426fa3  48                     -dec eax
    (cpu.eax)--;
    // 00426fa4  3bc8                   +cmp ecx, eax
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
    // 00426fa6  7d63                   -jge 0x42700b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042700b;
    }
    // 00426fa8  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00426faa  e881e70300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00426faf  d8a640010000           -fsub dword ptr [esi + 0x140]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(320) /* 0x140 */));
    // 00426fb5  db84be88000000         -fild dword ptr [esi + edi*4 + 0x88]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */ + cpu.edi * 4))));
    // 00426fbc  dc0d10774800           -fmul qword ptr [0x487710]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749072) /* 0x487710 */));
    // 00426fc2  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00426fc4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00426fc6  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00426fc9  7a40                   -jp 0x42700b
    if (cpu.flags.pf)
    {
        goto L_0x0042700b;
    }
    // 00426fcb  8b8e10010000           -mov ecx, dword ptr [esi + 0x110]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 00426fd1  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00426fd4  49                     -dec ecx
    (cpu.ecx)--;
    // 00426fd5  89860c010000           -mov dword ptr [esi + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 00426fdb  3bc1                   +cmp eax, ecx
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
    // 00426fdd  7515                   -jne 0x426ff4
    if (!cpu.flags.zf)
    {
        goto L_0x00426ff4;
    }
    // 00426fdf  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00426fe1  c7864001000000000000   -mov dword ptr [esi + 0x140], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(320) /* 0x140 */) = 0 /*0x0*/;
    // 00426feb  899608010000           -mov dword ptr [esi + 0x108], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.edx;
    // 00426ff1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426ff2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426ff3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00426ff4:
    // 00426ff4  e837e70300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00426ff9  8b960c010000           -mov edx, dword ptr [esi + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00426fff  d99e40010000           -fstp dword ptr [esi + 0x140]
    app->getMemory<float>(cpu.esi + x86::reg32(320) /* 0x140 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00427005  899608010000           -mov dword ptr [esi + 0x108], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.edx;
L_0x0042700b:
    // 0042700b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042700c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042700d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427010  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00427012  8b0d40d44a00           -mov ecx, dword ptr [0x4ad440]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904000) /* 0x4ad440 */);
    // 00427018  e8d3fdffff             -call 0x426df0
    cpu.esp -= 4;
    sub_426df0(app, cpu);
    // 0042701d  a340d44a00             -mov dword ptr [0x4ad440], eax
    app->getMemory<x86::reg32>(x86::reg32(4904000) /* 0x4ad440 */) = cpu.eax;
    // 00427022  a148d44a00             -mov eax, dword ptr [0x4ad448]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904008) /* 0x4ad448 */);
    // 00427027  40                     -inc eax
    (cpu.eax)++;
    // 00427028  a348d44a00             -mov dword ptr [0x4ad448], eax
    app->getMemory<x86::reg32>(x86::reg32(4904008) /* 0x4ad448 */) = cpu.eax;
    // 0042702d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427030  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00427032  e8d9ffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 00427037  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0042703c  e8cfffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 00427041  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00427046  e8c5ffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 0042704b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00427050  e8bbffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 00427055  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0042705a  e8b1ffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 0042705f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00427064  e8a7ffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 00427069  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0042706e  e89dffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 00427073  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00427078  e893ffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 0042707d  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 00427082  e889ffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 00427087  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042708c  e87fffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 00427091  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00427096  e875ffffff             -call 0x427010
    cpu.esp -= 4;
    sub_427010(app, cpu);
    // 0042709b  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 004270a0  e96bffffff             -jmp 0x427010
    return sub_427010(app, cpu);
}

/* align: skip  */
void Application::sub_4270b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004270b0  390d50d44a00           +cmp dword ptr [0x4ad450], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004270b6  7403                   -je 0x4270bb
    if (cpu.flags.zf)
    {
        goto L_0x004270bb;
    }
    // 004270b8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004270ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004270bb:
    // 004270bb  a144d44a00             -mov eax, dword ptr [0x4ad444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */);
    // 004270c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004270c2  7501                   -jne 0x4270c5
    if (!cpu.flags.zf)
    {
        goto L_0x004270c5;
    }
    // 004270c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004270c5:
    // 004270c5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004270c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4270d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004270d0  8b0d50d44a00           -mov ecx, dword ptr [0x4ad450]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */);
    // 004270d6  e8b5020000             -call 0x427390
    cpu.esp -= 4;
    sub_427390(app, cpu);
    // 004270db  8b8044010000           -mov eax, dword ptr [eax + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(324) /* 0x144 */);
    // 004270e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4270f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004270f0  8b8108010000           -mov eax, dword ptr [ecx + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */);
    // 004270f6  8b9110010000           -mov edx, dword ptr [ecx + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(272) /* 0x110 */);
    // 004270fc  40                     -inc eax
    (cpu.eax)++;
    // 004270fd  3bc2                   +cmp eax, edx
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
    // 004270ff  898108010000           -mov dword ptr [ecx + 0x108], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 00427105  7c0a                   -jl 0x427111
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427111;
    }
    // 00427107  c7810801000000000000   -mov dword ptr [ecx + 0x108], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */) = 0 /*0x0*/;
L_0x00427111:
    // 00427111  8b8108010000           -mov eax, dword ptr [ecx + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */);
    // 00427117  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427120  8b8108010000           -mov eax, dword ptr [ecx + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */);
    // 00427126  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00427127  898108010000           -mov dword ptr [ecx + 0x108], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 0042712d  790d                   -jns 0x42713c
    if (!cpu.flags.sf)
    {
        goto L_0x0042713c;
    }
    // 0042712f  8b8110010000           -mov eax, dword ptr [ecx + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(272) /* 0x110 */);
    // 00427135  48                     -dec eax
    (cpu.eax)--;
    // 00427136  898108010000           -mov dword ptr [ecx + 0x108], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */) = cpu.eax;
L_0x0042713c:
    // 0042713c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427140  8b810c010000           -mov eax, dword ptr [ecx + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */);
    // 00427146  8b9110010000           -mov edx, dword ptr [ecx + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(272) /* 0x110 */);
    // 0042714c  40                     -inc eax
    (cpu.eax)++;
    // 0042714d  3bc2                   +cmp eax, edx
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
    // 0042714f  89810c010000           -mov dword ptr [ecx + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 00427155  7c0a                   -jl 0x427161
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427161;
    }
    // 00427157  c7810c01000000000000   -mov dword ptr [ecx + 0x10c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */) = 0 /*0x0*/;
L_0x00427161:
    // 00427161  8b810c010000           -mov eax, dword ptr [ecx + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */);
    // 00427167  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427170  8b8114010000           -mov eax, dword ptr [ecx + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(276) /* 0x114 */);
    // 00427176  8b9118010000           -mov edx, dword ptr [ecx + 0x118]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(280) /* 0x118 */);
    // 0042717c  40                     -inc eax
    (cpu.eax)++;
    // 0042717d  3bc2                   +cmp eax, edx
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
    // 0042717f  898114010000           -mov dword ptr [ecx + 0x114], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(276) /* 0x114 */) = cpu.eax;
    // 00427185  7c3a                   -jl 0x4271c1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004271c1;
    }
    // 00427187  e8b4ffffff             -call 0x427140
    cpu.esp -= 4;
    sub_427140(app, cpu);
    // 0042718c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042718e  7527                   -jne 0x4271b7
    if (!cpu.flags.zf)
    {
        goto L_0x004271b7;
    }
    // 00427190  8b8110010000           -mov eax, dword ptr [ecx + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(272) /* 0x110 */);
    // 00427196  8b9118010000           -mov edx, dword ptr [ecx + 0x118]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(280) /* 0x118 */);
    // 0042719c  48                     -dec eax
    (cpu.eax)--;
    // 0042719d  4a                     -dec edx
    (cpu.edx)--;
    // 0042719e  89810c010000           -mov dword ptr [ecx + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 004271a4  c7813401000001000000   -mov dword ptr [ecx + 0x134], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(308) /* 0x134 */) = 1 /*0x1*/;
    // 004271ae  899114010000           -mov dword ptr [ecx + 0x114], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(276) /* 0x114 */) = cpu.edx;
    // 004271b4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004271b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004271b7:
    // 004271b7  c7811401000000000000   -mov dword ptr [ecx + 0x114], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(276) /* 0x114 */) = 0 /*0x0*/;
L_0x004271c1:
    // 004271c1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004271c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4271d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004271d0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004271d2  7503                   -jne 0x4271d7
    if (!cpu.flags.zf)
    {
        goto L_0x004271d7;
    }
    // 004271d4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004271d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004271d7:
    // 004271d7  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 004271da  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004271e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004271e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4271f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004271f0  8b8120010000           -mov eax, dword ptr [ecx + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(288) /* 0x120 */);
    // 004271f6  0faf8118010000         -imul eax, dword ptr [ecx + 0x118]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(280) /* 0x118 */))));
    // 004271fd  0faf8108010000         -imul eax, dword ptr [ecx + 0x108]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */))));
    // 00427204  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427210  8b8120010000           -mov eax, dword ptr [ecx + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(288) /* 0x120 */);
    // 00427216  0faf8118010000         -imul eax, dword ptr [ecx + 0x118]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(280) /* 0x118 */))));
    // 0042721d  0faf810c010000         -imul eax, dword ptr [ecx + 0x10c]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */))));
    // 00427224  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427230  e8dbffffff             -call 0x427210
    cpu.esp -= 4;
    sub_427210(app, cpu);
    // 00427235  8b9120010000           -mov edx, dword ptr [ecx + 0x120]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(288) /* 0x120 */);
    // 0042723b  0faf9114010000         -imul edx, dword ptr [ecx + 0x114]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(276) /* 0x114 */))));
    // 00427242  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00427244  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427250  e8dbffffff             -call 0x427230
    cpu.esp -= 4;
    sub_427230(app, cpu);
    // 00427255  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00427257  8d0441                 -lea eax, [ecx + eax*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 2);
    // 0042725a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427260  e88bffffff             -call 0x4271f0
    cpu.esp -= 4;
    sub_4271f0(app, cpu);
    // 00427265  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00427267  8d0441                 -lea eax, [ecx + eax*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 2);
    // 0042726a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427270  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427274  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427276  7e40                   -jle 0x4272b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004272b8;
    }
    // 00427278  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427279  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042727a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042727b  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042727d  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042727f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00427281:
    // 00427281  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00427283  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00427285  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 00427289  741f                   -je 0x4272aa
    if (cpu.flags.zf)
    {
        goto L_0x004272aa;
    }
    // 0042728b  3c0a                   +cmp al, 0xa
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
    // 0042728d  741b                   -je 0x4272aa
    if (cpu.flags.zf)
    {
        goto L_0x004272aa;
    }
    // 0042728f  3c0d                   +cmp al, 0xd
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
    // 00427291  7417                   -je 0x4272aa
    if (cpu.flags.zf)
    {
        goto L_0x004272aa;
    }
    // 00427293  3c09                   +cmp al, 9
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00427295  7413                   -je 0x4272aa
    if (cpu.flags.zf)
    {
        goto L_0x004272aa;
    }
    // 00427297  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042729b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042729d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042729e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042729f  e8da1f0500             -call 0x47927e
    cpu.esp -= 4;
    sub_47927e(app, cpu);
    // 004272a4  83c40c                 +add esp, 0xc
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
    // 004272a7  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004272a8  eb05                   -jmp 0x4272af
    goto L_0x004272af;
L_0x004272aa:
    // 004272aa  66c7062000             -mov word ptr [esi], 0x20
    app->getMemory<x86::reg16>(cpu.esi) = 32 /*0x20*/;
L_0x004272af:
    // 004272af  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004272b2  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004272b3  75cc                   -jne 0x427281
    if (!cpu.flags.zf)
    {
        goto L_0x00427281;
    }
    // 004272b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004272b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004272b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004272b8:
    // 004272b8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4272c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004272c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004272c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004272c2  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004272c4  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004272c6  8b8744010000           -mov eax, dword ptr [edi + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(324) /* 0x144 */);
    // 004272cc  8338ff                 +cmp dword ptr [eax], -1
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
    // 004272cf  7435                   -je 0x427306
    if (cpu.flags.zf)
    {
        goto L_0x00427306;
    }
    // 004272d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004272d2  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004272d4:
    // 004272d4  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 004272d7  e844dffeff             -call 0x415220
    cpu.esp -= 4;
    sub_415220(app, cpu);
    // 004272dc  83fb01                 +cmp ebx, 1
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
    // 004272df  7515                   -jne 0x4272f6
    if (!cpu.flags.zf)
    {
        goto L_0x004272f6;
    }
    // 004272e1  8b8744010000           -mov eax, dword ptr [edi + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(324) /* 0x144 */);
    // 004272e7  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 004272ea  e801dffeff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 004272ef  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x004272f6:
    // 004272f6  8b8744010000           -mov eax, dword ptr [edi + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(324) /* 0x144 */);
    // 004272fc  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004272ff  833c06ff               +cmp dword ptr [esi + eax], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427303  75cf                   -jne 0x4272d4
    if (!cpu.flags.zf)
    {
        goto L_0x004272d4;
    }
    // 00427305  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00427306:
    // 00427306  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427307  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427308  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427311  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427312  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00427314  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00427316  8b8744010000           -mov eax, dword ptr [edi + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(324) /* 0x144 */);
    // 0042731c  8338ff                 +cmp dword ptr [eax], -1
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
    // 0042731f  7440                   -je 0x427361
    if (cpu.flags.zf)
    {
        goto L_0x00427361;
    }
    // 00427321  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427322  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00427324:
    // 00427324  8b0406                 -mov eax, dword ptr [esi + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 00427327  83f830                 +cmp eax, 0x30
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
    // 0042732a  7425                   -je 0x427351
    if (cpu.flags.zf)
    {
        goto L_0x00427351;
    }
    // 0042732c  83f823                 +cmp eax, 0x23
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042732f  7420                   -je 0x427351
    if (cpu.flags.zf)
    {
        goto L_0x00427351;
    }
    // 00427331  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00427333  e818dffeff             -call 0x415250
    cpu.esp -= 4;
    sub_415250(app, cpu);
    // 00427338  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042733a  7415                   -je 0x427351
    if (cpu.flags.zf)
    {
        goto L_0x00427351;
    }
    // 0042733c  8b8744010000           -mov eax, dword ptr [edi + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(324) /* 0x144 */);
    // 00427342  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 00427345  e8a6defeff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0042734a  c740240000803f         -mov dword ptr [eax + 0x24], 0x3f800000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1065353216 /*0x3f800000*/;
L_0x00427351:
    // 00427351  8b8744010000           -mov eax, dword ptr [edi + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(324) /* 0x144 */);
    // 00427357  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042735a  833c06ff               +cmp dword ptr [esi + eax], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042735e  75c4                   -jne 0x427324
    if (!cpu.flags.zf)
    {
        goto L_0x00427324;
    }
    // 00427360  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00427361:
    // 00427361  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427362  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427363  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427370  a144d44a00             -mov eax, dword ptr [0x4ad444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */);
    // 00427375  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427377  740a                   -je 0x427383
    if (cpu.flags.zf)
    {
        goto L_0x00427383;
    }
    // 00427379  c70544d44a0000000000   -mov dword ptr [0x4ad444], 0
    app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */) = 0 /*0x0*/;
L_0x00427383:
    // 00427383  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427390  a144d44a00             -mov eax, dword ptr [0x4ad444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */);
    // 00427395  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00427397  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427399  7408                   -je 0x4273a3
    if (cpu.flags.zf)
    {
        goto L_0x004273a3;
    }
    // 0042739b  399030010000           +cmp dword ptr [eax + 0x130], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(304) /* 0x130 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004273a1  740b                   -je 0x4273ae
    if (cpu.flags.zf)
    {
        goto L_0x004273ae;
    }
L_0x004273a3:
    // 004273a3  8b0d40d44a00           -mov ecx, dword ptr [0x4ad440]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904000) /* 0x4ad440 */);
    // 004273a9  e812000000             -call 0x4273c0
    cpu.esp -= 4;
    sub_4273c0(app, cpu);
L_0x004273ae:
    // 004273ae  a344d44a00             -mov dword ptr [0x4ad444], eax
    app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */) = cpu.eax;
    // 004273b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4273c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004273c0  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004273c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004273c4  7412                   -je 0x4273d8
    if (cpu.flags.zf)
    {
        goto L_0x004273d8;
    }
L_0x004273c6:
    // 004273c6  399030010000           +cmp dword ptr [eax + 0x130], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(304) /* 0x130 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004273cc  740c                   -je 0x4273da
    if (cpu.flags.zf)
    {
        goto L_0x004273da;
    }
    // 004273ce  8b8050010000           -mov eax, dword ptr [eax + 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(336) /* 0x150 */);
    // 004273d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004273d6  75ee                   -jne 0x4273c6
    if (!cpu.flags.zf)
    {
        goto L_0x004273c6;
    }
L_0x004273d8:
    // 004273d8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004273da:
    // 004273da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4273e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004273e0  a144d44a00             -mov eax, dword ptr [0x4ad444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */);
    // 004273e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004273e7  7504                   -jne 0x4273ed
    if (!cpu.flags.zf)
    {
        goto L_0x004273ed;
    }
    // 004273e9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004273ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004273ed:
    // 004273ed  8b8028010000           -mov eax, dword ptr [eax + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(296) /* 0x128 */);
    // 004273f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427400  a144d44a00             -mov eax, dword ptr [0x4ad444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */);
    // 00427405  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427407  7412                   -je 0x42741b
    if (cpu.flags.zf)
    {
        goto L_0x0042741b;
    }
    // 00427409  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042740a  8b35d8c84a00           -mov esi, dword ptr [0x4ac8d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */);
    // 00427410  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 00427412  8b8014010000           -mov eax, dword ptr [eax + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(276) /* 0x114 */);
    // 00427418  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0042741a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042741b:
    // 0042741b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427420  a144d44a00             -mov eax, dword ptr [0x4ad444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */);
    // 00427425  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427427  7501                   -jne 0x42742a
    if (!cpu.flags.zf)
    {
        goto L_0x0042742a;
    }
    // 00427429  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042742a:
    // 0042742a  8b8008010000           -mov eax, dword ptr [eax + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(264) /* 0x108 */);
    // 00427430  40                     -inc eax
    (cpu.eax)++;
    // 00427431  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427440  8b0d50d44a00           -mov ecx, dword ptr [0x4ad450]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */);
    // 00427446  e845ffffff             -call 0x427390
    cpu.esp -= 4;
    sub_427390(app, cpu);
    // 0042744b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042744d  e93e030000             -jmp 0x427790
    return sub_427790(app, cpu);
}

/* align: skip  */
void Application::sub_427460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427460  8b8108010000           -mov eax, dword ptr [ecx + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */);
    // 00427466  8b448108               -mov eax, dword ptr [ecx + eax*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.eax * 4);
    // 0042746a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427470  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 00427475  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427476  24fb                   -and al, 0xfb
    cpu.al &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00427478  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042747a  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0042747c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042747e  a34cd44a00             -mov dword ptr [0x4ad44c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */) = cpu.eax;
    // 00427483  7c05                   -jl 0x42748a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042748a;
    }
    // 00427485  83fe0c                 +cmp esi, 0xc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427488  7c0e                   -jl 0x427498
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427498;
    }
L_0x0042748a:
    // 0042748a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042748b  68c83a4900             -push 0x493ac8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799176 /*0x493ac8*/;
    cpu.esp -= 4;
    // 00427490  e87bd7ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00427495  83c408                 +add esp, 8
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
L_0x00427498:
    // 00427498  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042749a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042749b  e9c0000000             -jmp 0x427560
    return sub_427560(app, cpu);
}

/* align: skip  */
void Application::sub_4274a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004274a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004274a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004274a2  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004274a4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004274a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004274a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004274a8  68303b4900             -push 0x493b30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799280 /*0x493b30*/;
    cpu.esp -= 4;
    // 004274ad  e805f90400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004274b2  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 004274b7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004274ba  24fb                   -and al, 0xfb
    cpu.al &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004274bc  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004274be  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004274c0  a34cd44a00             -mov dword ptr [0x4ad44c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */) = cpu.eax;
    // 004274c5  7c05                   -jl 0x4274cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004274cc;
    }
    // 004274c7  83fe0c                 +cmp esi, 0xc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004274ca  7c0f                   -jl 0x4274db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004274db;
    }
L_0x004274cc:
    // 004274cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004274cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004274ce  68f83a4900             -push 0x493af8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799224 /*0x493af8*/;
    cpu.esp -= 4;
    // 004274d3  e838d7ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004274d8  83c40c                 +add esp, 0xc
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
L_0x004274db:
    // 004274db  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004274dd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004274df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004274e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004274e1  e98a000000             -jmp 0x427570
    return sub_427570(app, cpu);
}

/* align: skip  */
void Application::sub_4274f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004274f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004274f1  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004274f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004274f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004274f7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004274f9  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004274fb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004274fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004274fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004274fe  688c3b4900             -push 0x493b8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799372 /*0x493b8c*/;
    cpu.esp -= 4;
    // 00427503  e8aff80400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00427508  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 0042750d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00427510  24fb                   -and al, 0xfb
    cpu.al &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00427512  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00427514  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00427516  a34cd44a00             -mov dword ptr [0x4ad44c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */) = cpu.eax;
    // 0042751b  7c05                   -jl 0x427522
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427522;
    }
    // 0042751d  83fe0c                 +cmp esi, 0xc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427520  7c0f                   -jl 0x427531
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427531;
    }
L_0x00427522:
    // 00427522  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427523  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427524  68503b4900             -push 0x493b50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799312 /*0x493b50*/;
    cpu.esp -= 4;
    // 00427529  e8e2d6ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042752e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00427531:
    // 00427531  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427532  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00427534  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427536  e8b5010000             -call 0x4276f0
    cpu.esp -= 4;
    sub_4276f0(app, cpu);
    // 0042753b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042753c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042753d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042753e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_427550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427550  a150d44a00             -mov eax, dword ptr [0x4ad450]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */);
    // 00427555  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427560  890d50d44a00           -mov dword ptr [0x4ad450], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */) = cpu.ecx;
    // 00427566  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427570  890d50d44a00           -mov dword ptr [0x4ad450], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */) = cpu.ecx;
    // 00427576  e905000000             -jmp 0x427580
    return sub_427580(app, cpu);
}

/* align: skip  */
void Application::sub_427580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427580  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427581  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427582  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00427583  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427584  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427585  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00427587  e804feffff             -call 0x427390
    cpu.esp -= 4;
    sub_427390(app, cpu);
    // 0042758c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042758e  e8cdfefeff             -call 0x417460
    cpu.esp -= 4;
    sub_417460(app, cpu);
    // 00427593  c7862c01000001000000   -mov dword ptr [esi + 0x12c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(300) /* 0x12c */) = 1 /*0x1*/;
    // 0042759d  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004275a2  8b0dc4e54900           -mov ecx, dword ptr [0x49e5c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004275a8  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004275ab  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004275ad  e82e6ffeff             -call 0x40e4e0
    cpu.esp -= 4;
    sub_40e4e0(app, cpu);
    // 004275b2  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004275b4  3bc5                   +cmp eax, ebp
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
    // 004275b6  7416                   -je 0x4275ce
    if (cpu.flags.zf)
    {
        goto L_0x004275ce;
    }
    // 004275b8  b90000803f             -mov ecx, 0x3f800000
    cpu.ecx = 1065353216 /*0x3f800000*/;
    // 004275bd  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004275c0  89482c                 -mov dword ptr [eax + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 004275c3  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004275c9  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004275cb  894828                 -mov dword ptr [eax + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ecx;
L_0x004275ce:
    // 004275ce  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 004275d4  83f801                 +cmp eax, 1
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
    // 004275d7  0f84be000000           -je 0x42769b
    if (cpu.flags.zf)
    {
        goto L_0x0042769b;
    }
    // 004275dd  83f807                 +cmp eax, 7
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
    // 004275e0  0f84b5000000           -je 0x42769b
    if (cpu.flags.zf)
    {
        goto L_0x0042769b;
    }
    // 004275e6  83f806                 +cmp eax, 6
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
    // 004275e9  0f84ac000000           -je 0x42769b
    if (cpu.flags.zf)
    {
        goto L_0x0042769b;
    }
    // 004275ef  83f808                 +cmp eax, 8
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
    // 004275f2  0f84a3000000           -je 0x42769b
    if (cpu.flags.zf)
    {
        goto L_0x0042769b;
    }
    // 004275f8  83f809                 +cmp eax, 9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004275fb  0f849a000000           -je 0x42769b
    if (cpu.flags.zf)
    {
        goto L_0x0042769b;
    }
    // 00427601  83f80a                 +cmp eax, 0xa
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
    // 00427604  0f8491000000           -je 0x42769b
    if (cpu.flags.zf)
    {
        goto L_0x0042769b;
    }
    // 0042760a  3bc5                   +cmp eax, ebp
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
    // 0042760c  0f8489000000           -je 0x42769b
    if (cpu.flags.zf)
    {
        goto L_0x0042769b;
    }
    // 00427612  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00427616  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00427617  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427618  e8e3d70200             -call 0x454e00
    cpu.esp -= 4;
    sub_454e00(app, cpu);
    // 0042761d  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042761f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00427622  3bfd                   +cmp edi, ebp
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
    // 00427624  7514                   -jne 0x42763a
    if (!cpu.flags.zf)
    {
        goto L_0x0042763a;
    }
    // 00427626  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427627  68b43b4900             -push 0x493bb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799412 /*0x493bb4*/;
    cpu.esp -= 4;
    // 0042762c  e886f70400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00427631  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00427634  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427635  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427636  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427637  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427638  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427639  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042763a:
    // 0042763a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042763b  e85d070500             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 00427640  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00427642  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00427645  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00427649  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042764c  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042764e  89863c010000           -mov dword ptr [esi + 0x13c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(316) /* 0x13c */) = cpu.eax;
    // 00427654  e8d7f5ffff             -call 0x426c30
    cpu.esp -= 4;
    sub_426c30(app, cpu);
    // 00427659  39ae4c010000           +cmp dword ptr [esi + 0x14c], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(332) /* 0x14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042765f  750d                   -jne 0x42766e
    if (!cpu.flags.zf)
    {
        goto L_0x0042766e;
    }
    // 00427661  68843a4900             -push 0x493a84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799108 /*0x493a84*/;
    cpu.esp -= 4;
    // 00427666  e8a5d5ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042766b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042766e:
    // 0042766e  8b8e4c010000           -mov ecx, dword ptr [esi + 0x14c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(332) /* 0x14c */);
    // 00427674  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00427676  8991d0000000           -mov dword ptr [ecx + 0xd0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */) = cpu.edx;
    // 0042767c  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042767e  89ae08010000           -mov dword ptr [esi + 0x108], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.ebp;
    // 00427684  89ae0c010000           -mov dword ptr [esi + 0x10c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.ebp;
    // 0042768a  89ae1c010000           -mov dword ptr [esi + 0x11c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */) = cpu.ebp;
    // 00427690  89ae14010000           -mov dword ptr [esi + 0x114], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */) = cpu.ebp;
    // 00427696  e815000000             -call 0x4276b0
    cpu.esp -= 4;
    sub_4276b0(app, cpu);
L_0x0042769b:
    // 0042769b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042769c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042769d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042769e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042769f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004276a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4276b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004276b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004276b1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004276b3  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004276b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004276ba  68e83b4900             -push 0x493be8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799464 /*0x493be8*/;
    cpu.esp -= 4;
    // 004276bf  e8f3f60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004276c4  8b9610010000           -mov edx, dword ptr [esi + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004276ca  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004276cd  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004276cf  83fa01                 +cmp edx, 1
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
    // 004276d2  0f9fc1                 -setg cl
    cpu.cl = (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of));
    // 004276d5  83c10d                 -add ecx, 0xd
    (cpu.ecx) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 004276d8  e833f2feff             -call 0x416910
    cpu.esp -= 4;
    sub_416910(app, cpu);
    // 004276dd  898644010000           -mov dword ptr [esi + 0x144], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(324) /* 0x144 */) = cpu.eax;
    // 004276e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004276e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4276f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004276f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004276f1  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004276f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004276f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004276f7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004276f9  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004276fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004276fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004276fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004276fe  68fc3b4900             -push 0x493bfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799484 /*0x493bfc*/;
    cpu.esp -= 4;
    // 00427703  893550d44a00           -mov dword ptr [0x4ad450], esi
    app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */) = cpu.esi;
    // 00427709  e8a9f60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042770e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00427711  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00427713  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427715  e866feffff             -call 0x427580
    cpu.esp -= 4;
    sub_427580(app, cpu);
    // 0042771a  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042771c  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042771e  e81d19ffff             -call 0x419040
    cpu.esp -= 4;
    sub_419040(app, cpu);
    // 00427723  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427724  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427725  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427726  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_427730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427730  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 00427735  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 00427737  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042773a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427740  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 00427745  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00427748  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46d7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0046d7e0;
L_0x00427750:
    // 00427750  890d54d44a00           -mov dword ptr [0x4ad454], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904020) /* 0x4ad454 */) = cpu.ecx;
    // 00427756  c3                     -ret 
    cpu.esp += 4;
    return;
L_entry_0x0046d7e0:
    // 0046d7e0  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046d7e2  e8998effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d7e7  e8a4950000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0046d7ec  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d7ee  e95d9ffbff             -jmp 0x427750
    goto L_0x00427750;
}

/* align: skip  */
void Application::sub_427760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427760  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00427762  8b0d40d44a00           -mov ecx, dword ptr [0x4ad440]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904000) /* 0x4ad440 */);
    // 00427768  e853fcffff             -call 0x4273c0
    cpu.esp -= 4;
    sub_4273c0(app, cpu);
    // 0042776d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042776f  741a                   -je 0x42778b
    if (cpu.flags.zf)
    {
        goto L_0x0042778b;
    }
    // 00427771  8b8824010000           -mov ecx, dword ptr [eax + 0x124]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(292) /* 0x124 */);
    // 00427777  83f905                 +cmp ecx, 5
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042777a  740f                   -je 0x42778b
    if (cpu.flags.zf)
    {
        goto L_0x0042778b;
    }
    // 0042777c  83f90a                 +cmp ecx, 0xa
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
    // 0042777f  740a                   -je 0x42778b
    if (cpu.flags.zf)
    {
        goto L_0x0042778b;
    }
    // 00427781  c7802401000005000000   -mov dword ptr [eax + 0x124], 5
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(292) /* 0x124 */) = 5 /*0x5*/;
L_0x0042778b:
    // 0042778b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00427790  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427793  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427797  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042779b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042779c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042779d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042779e  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004277a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004277a1  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004277a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004277a6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004277a7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004277a8  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004277ac  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004277b0  e8ebb5ffff             -call 0x422da0
    cpu.esp -= 4;
    sub_422da0(app, cpu);
    // 004277b5  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004277b7  3bf5                   +cmp esi, ebp
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
    // 004277b9  7515                   -jne 0x4277d0
    if (!cpu.flags.zf)
    {
        goto L_0x004277d0;
    }
    // 004277bb  684c3c4900             -push 0x493c4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799564 /*0x493c4c*/;
    cpu.esp -= 4;
    // 004277c0  e8f2f50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004277c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004277c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004277c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004277ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004277cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004277cc  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004277cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004277d0:
    // 004277d0  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 004277d6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004277db  3bc3                   +cmp eax, ebx
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
    // 004277dd  7406                   -je 0x4277e5
    if (cpu.flags.zf)
    {
        goto L_0x004277e5;
    }
    // 004277df  845c2414               -test byte ptr [esp + 0x14], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & cpu.bl));
    // 004277e3  eb09                   -jmp 0x4277ee
    goto L_0x004277ee;
L_0x004277e5:
    // 004277e5  b142                   -mov cl, 0x42
    cpu.cl = 66 /*0x42*/;
    // 004277e7  e8f4b30300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004277ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x004277ee:
    // 004277ee  740a                   -je 0x4277fa
    if (cpu.flags.zf)
    {
        goto L_0x004277fa;
    }
    // 004277f0  c7862401000005000000   -mov dword ptr [esi + 0x124], 5
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 5 /*0x5*/;
L_0x004277fa:
    // 004277fa  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004277fc  e87ff7ffff             -call 0x426f80
    cpu.esp -= 4;
    sub_426f80(app, cpu);
    // 00427801  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427803  e808050000             -call 0x427d10
    cpu.esp -= 4;
    sub_427d10(app, cpu);
    // 00427808  e863050000             -call 0x427d70
    cpu.esp -= 4;
    sub_427d70(app, cpu);
    // 0042780d  8b8624010000           -mov eax, dword ptr [esi + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */);
    // 00427813  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427816  7769                   -ja 0x427881
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00427881;
    }
    // 00427818  ff2485a47c4200         -jmp dword ptr [eax*4 + 0x427ca4]
    cpu.ip = app->getMemory<x86::reg32>(4357284 + cpu.eax * 4); goto dynamic_jump;
  case 0x0042781f:
    // 0042781f  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 00427824  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00427826  24fb                   -and al, 0xfb
    cpu.al &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00427828  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042782a  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0042782c  a34cd44a00             -mov dword ptr [0x4ad44c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */) = cpu.eax;
    // 00427831  e8dafaffff             -call 0x427310
    cpu.esp -= 4;
    sub_427310(app, cpu);
    // 00427836  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427838  c7862401000002000000   -mov dword ptr [esi + 0x124], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 2 /*0x2*/;
    // 00427842  89ae28010000           -mov dword ptr [esi + 0x128], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = cpu.ebp;
    // 00427848  e873050000             -call 0x427dc0
    cpu.esp -= 4;
    sub_427dc0(app, cpu);
    // 0042784d  e8ee2e0300             -call 0x45a740
    cpu.esp -= 4;
    sub_45a740(app, cpu);
    // 00427852  a150d44a00             -mov eax, dword ptr [0x4ad450]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */);
    // 00427857  83f806                 +cmp eax, 6
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
    // 0042785a  752d                   -jne 0x427889
    if (!cpu.flags.zf)
    {
        goto L_0x00427889;
    }
    // 0042785c  e84fb60300             -call 0x462eb0
    cpu.esp -= 4;
    sub_462eb0(app, cpu);
    // 00427861  e8da110000             -call 0x428a40
    cpu.esp -= 4;
    sub_428a40(app, cpu);
    // 00427866  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00427867  e8e4050000             -call 0x427e50
    cpu.esp -= 4;
    sub_427e50(app, cpu);
    // 0042786c  8b8e18010000           -mov ecx, dword ptr [esi + 0x118]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */);
    // 00427872  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00427873  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x00427874:
    // 00427874  8b9620010000           -mov edx, dword ptr [esi + 0x120]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */);
    // 0042787a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042787c  e87f0e0000             -call 0x428700
    cpu.esp -= 4;
    sub_428700(app, cpu);
L_0x00427881:
    // 00427881  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427882  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427883  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427884  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427885  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427888  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427889:
    // 00427889  83f808                 +cmp eax, 8
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
    // 0042788c  7560                   -jne 0x4278ee
    if (!cpu.flags.zf)
    {
        goto L_0x004278ee;
    }
    // 0042788e  e81db60300             -call 0x462eb0
    cpu.esp -= 4;
    sub_462eb0(app, cpu);
    // 00427893  e858190000             -call 0x4291f0
    cpu.esp -= 4;
    sub_4291f0(app, cpu);
    // 00427898  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042789a  0f8558030000           -jne 0x427bf8
    if (!cpu.flags.zf)
    {
        goto L_0x00427bf8;
    }
    // 004278a0  e83b0e0000             -call 0x4286e0
    cpu.esp -= 4;
    sub_4286e0(app, cpu);
    // 004278a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004278a7  0f844b030000           -je 0x427bf8
    if (cpu.flags.zf)
    {
        goto L_0x00427bf8;
    }
    // 004278ad  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x004278af:
    // 004278af  8b8618010000           -mov eax, dword ptr [esi + 0x118]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */);
    // 004278b5  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004278b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004278b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004278ba  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004278bc  899608010000           -mov dword ptr [esi + 0x108], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.edx;
    // 004278c2  e899f9ffff             -call 0x427260
    cpu.esp -= 4;
    sub_427260(app, cpu);
    // 004278c7  8b9620010000           -mov edx, dword ptr [esi + 0x120]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */);
    // 004278cd  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004278cf  e87c160000             -call 0x428f50
    cpu.esp -= 4;
    sub_428f50(app, cpu);
    // 004278d4  47                     -inc edi
    (cpu.edi)++;
    // 004278d5  83ff06                 +cmp edi, 6
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004278d8  7cd5                   -jl 0x4278af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004278af;
    }
    // 004278da  e8111c0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 004278df  48                     -dec eax
    (cpu.eax)--;
    // 004278e0  898608010000           -mov dword ptr [esi + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 004278e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004278e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004278e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004278e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004278ea  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004278ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004278ee:
    // 004278ee  83f809                 +cmp eax, 9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004278f1  754d                   -jne 0x427940
    if (!cpu.flags.zf)
    {
        goto L_0x00427940;
    }
    // 004278f3  e8b8b50300             -call 0x462eb0
    cpu.esp -= 4;
    sub_462eb0(app, cpu);
    // 004278f8  e8f3180000             -call 0x4291f0
    cpu.esp -= 4;
    sub_4291f0(app, cpu);
    // 004278fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004278ff  0f85f3020000           -jne 0x427bf8
    if (!cpu.flags.zf)
    {
        goto L_0x00427bf8;
    }
    // 00427905  392d90d34a00           +cmp dword ptr [0x4ad390], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4903824) /* 0x4ad390 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042790b  0f85e7020000           -jne 0x427bf8
    if (!cpu.flags.zf)
    {
        goto L_0x00427bf8;
    }
    // 00427911  e86a1c0000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 00427916  3bc3                   +cmp eax, ebx
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
    // 00427918  0f84da020000           -je 0x427bf8
    if (cpu.flags.zf)
    {
        goto L_0x00427bf8;
    }
    // 0042791e  e8cd1b0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 00427923  8b8e18010000           -mov ecx, dword ptr [esi + 0x118]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */);
    // 00427929  8b9620010000           -mov edx, dword ptr [esi + 0x120]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */);
    // 0042792f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00427930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427931  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00427933  e858190000             -call 0x429290
    cpu.esp -= 4;
    sub_429290(app, cpu);
    // 00427938  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427939  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042793a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042793b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042793c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042793f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427940:
    // 00427940  83f80a                 +cmp eax, 0xa
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
    // 00427943  0f8538ffffff           -jne 0x427881
    if (!cpu.flags.zf)
    {
        goto L_0x00427881;
    }
    // 00427949  e862b50300             -call 0x462eb0
    cpu.esp -= 4;
    sub_462eb0(app, cpu);
    // 0042794e  e89d180000             -call 0x4291f0
    cpu.esp -= 4;
    sub_4291f0(app, cpu);
    // 00427953  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427955  0f859d020000           -jne 0x427bf8
    if (!cpu.flags.zf)
    {
        goto L_0x00427bf8;
    }
    // 0042795b  392d90d34a00           +cmp dword ptr [0x4ad390], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4903824) /* 0x4ad390 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427961  0f8591020000           -jne 0x427bf8
    if (!cpu.flags.zf)
    {
        goto L_0x00427bf8;
    }
    // 00427967  e8141c0000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 0042796c  3bc3                   +cmp eax, ebx
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
    // 0042796e  0f8484020000           -je 0x427bf8
    if (cpu.flags.zf)
    {
        goto L_0x00427bf8;
    }
    // 00427974  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427975  e8e6040000             -call 0x427e60
    cpu.esp -= 4;
    sub_427e60(app, cpu);
    // 0042797a  8b9618010000           -mov edx, dword ptr [esi + 0x118]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */);
    // 00427980  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00427981  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00427982  e9edfeffff             -jmp 0x427874
    goto L_0x00427874;
  case 0x00427987:
    // 00427987  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 0042798c  23c3                   -and eax, ebx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042798e  3ac3                   +cmp al, bl
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
    // 00427990  0f85ebfeffff           -jne 0x427881
    if (!cpu.flags.zf)
    {
        goto L_0x00427881;
    }
    // 00427996  899e24010000           -mov dword ptr [esi + 0x124], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = cpu.ebx;
    // 0042799c  a054d44a00             -mov al, byte ptr [0x4ad454]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4904020) /* 0x4ad454 */);
    // 004279a1  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004279a3  0f84d8feffff           -je 0x427881
    if (cpu.flags.zf)
    {
        goto L_0x00427881;
    }
    // 004279a9  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004279ab  e8c0cdfeff             -call 0x414770
    cpu.esp -= 4;
    sub_414770(app, cpu);
    // 004279b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004279b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004279b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004279b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004279b4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004279b7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004279b8:
    // 004279b8  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004279bc  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004279c2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004279c4  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004279c9  7518                   -jne 0x4279e3
    if (!cpu.flags.zf)
    {
        goto L_0x004279e3;
    }
    // 004279cb  c7862401000003000000   -mov dword ptr [esi + 0x124], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 3 /*0x3*/;
    // 004279d5  899e28010000           -mov dword ptr [esi + 0x128], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = cpu.ebx;
    // 004279db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004279dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004279dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004279de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004279df  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004279e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004279e3:
    // 004279e3  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004279e7  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004279ed  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004279ef  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004279f2  7a18                   -jp 0x427a0c
    if (cpu.flags.pf)
    {
        goto L_0x00427a0c;
    }
    // 004279f4  c7862401000004000000   -mov dword ptr [esi + 0x124], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 4 /*0x4*/;
    // 004279fe  899e28010000           -mov dword ptr [esi + 0x128], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = cpu.ebx;
    // 00427a04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a08  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427a0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427a0c:
    // 00427a0c  391d50d44a00           +cmp dword ptr [0x4ad450], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4904016) /* 0x4ad450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427a12  7511                   -jne 0x427a25
    if (!cpu.flags.zf)
    {
        goto L_0x00427a25;
    }
    // 00427a14  f644241402             +test byte ptr [esp + 0x14], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 2 /*0x2*/));
    // 00427a19  740a                   -je 0x427a25
    if (cpu.flags.zf)
    {
        goto L_0x00427a25;
    }
    // 00427a1b  c7862401000006000000   -mov dword ptr [esi + 0x124], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 6 /*0x6*/;
L_0x00427a25:
    // 00427a25  899e28010000           -mov dword ptr [esi + 0x128], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = cpu.ebx;
    // 00427a2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a2f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427a32  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427a33:
    // 00427a33  68403c4900             -push 0x493c40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799552 /*0x493c40*/;
    cpu.esp -= 4;
    // 00427a38  e87af30400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00427a3d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00427a40  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427a42  e8a9f6ffff             -call 0x4270f0
    cpu.esp -= 4;
    sub_4270f0(app, cpu);
    // 00427a47  c786240100000b000000   -mov dword ptr [esi + 0x124], 0xb
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 11 /*0xb*/;
    // 00427a51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a55  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427a58  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427a59:
    // 00427a59  68343c4900             -push 0x493c34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799540 /*0x493c34*/;
    cpu.esp -= 4;
    // 00427a5e  e854f30400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00427a63  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00427a66  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427a68  e8b3f6ffff             -call 0x427120
    cpu.esp -= 4;
    sub_427120(app, cpu);
    // 00427a6d  c786240100000c000000   -mov dword ptr [esi + 0x124], 0xc
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 12 /*0xc*/;
    // 00427a77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a7b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427a7e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427a7f:
    // 00427a7f  399e34010000           +cmp dword ptr [esi + 0x134], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(308) /* 0x134 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427a85  750e                   -jne 0x427a95
    if (!cpu.flags.zf)
    {
        goto L_0x00427a95;
    }
    // 00427a87  899e24010000           -mov dword ptr [esi + 0x124], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = cpu.ebx;
    // 00427a8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a91  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427a94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427a95:
    // 00427a95  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427a97  c7862801000002000000   -mov dword ptr [esi + 0x128], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = 2 /*0x2*/;
    // 00427aa1  e8ba020000             -call 0x427d60
    cpu.esp -= 4;
    sub_427d60(app, cpu);
    // 00427aa6  bad8c84a00             -mov edx, 0x4ac8d8
    cpu.edx = 4901080 /*0x4ac8d8*/;
    // 00427aab  b998c84a00             -mov ecx, 0x4ac898
    cpu.ecx = 4901016 /*0x4ac898*/;
    // 00427ab0  e81bf7ffff             -call 0x4271d0
    cpu.esp -= 4;
    sub_4271d0(app, cpu);
    // 00427ab5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427ab7  750d                   -jne 0x427ac6
    if (!cpu.flags.zf)
    {
        goto L_0x00427ac6;
    }
    // 00427ab9  68183c4900             -push 0x493c18
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799512 /*0x493c18*/;
    cpu.esp -= 4;
    // 00427abe  e84dd1ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00427ac3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00427ac6:
    // 00427ac6  c7862401000007000000   -mov dword ptr [esi + 0x124], 7
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 7 /*0x7*/;
    // 00427ad0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ad1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ad2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ad3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ad4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427ad7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427ad8:
    // 00427ad8  f644241402             +test byte ptr [esp + 0x14], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 2 /*0x2*/));
    // 00427add  7512                   -jne 0x427af1
    if (!cpu.flags.zf)
    {
        goto L_0x00427af1;
    }
    // 00427adf  c7862401000008000000   -mov dword ptr [esi + 0x124], 8
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 8 /*0x8*/;
    // 00427ae9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427aea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427aeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427aec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427aed  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427af0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427af1:
    // 00427af1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427af2  892dd8c84a00           -mov dword ptr [0x4ac8d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.ebp;
    // 00427af8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427af9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427afa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427afb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427afe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427aff:
    // 00427aff  8b8e20010000           -mov ecx, dword ptr [esi + 0x120]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */);
    // 00427b05  49                     -dec ecx
    (cpu.ecx)--;
    // 00427b06  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427b07  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427b09  e842f7ffff             -call 0x427250
    cpu.esp -= 4;
    sub_427250(app, cpu);
    // 00427b0e  ba98c84a00             -mov edx, 0x4ac898
    cpu.edx = 4901016 /*0x4ac898*/;
    // 00427b13  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00427b15  e856f7ffff             -call 0x427270
    cpu.esp -= 4;
    sub_427270(app, cpu);
    // 00427b1a  8b8620010000           -mov eax, dword ptr [esi + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */);
    // 00427b20  8b0dd8c84a00           -mov ecx, dword ptr [0x4ac8d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */);
    // 00427b26  48                     -dec eax
    (cpu.eax)--;
    // 00427b27  3bc8                   +cmp ecx, eax
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
    // 00427b29  7e05                   -jle 0x427b30
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00427b30;
    }
    // 00427b2b  a3d8c84a00             -mov dword ptr [0x4ac8d8], eax
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.eax;
L_0x00427b30:
    // 00427b30  f644241402             +test byte ptr [esp + 0x14], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 2 /*0x2*/));
    // 00427b35  7412                   -je 0x427b49
    if (cpu.flags.zf)
    {
        goto L_0x00427b49;
    }
    // 00427b37  c7862401000009000000   -mov dword ptr [esi + 0x124], 9
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 9 /*0x9*/;
    // 00427b41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b45  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427b48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427b49:
    // 00427b49  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00427b4d  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00427b53  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00427b55  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00427b5a  7519                   -jne 0x427b75
    if (!cpu.flags.zf)
    {
        goto L_0x00427b75;
    }
    // 00427b5c  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427b5e  e88d020000             -call 0x427df0
    cpu.esp -= 4;
    sub_427df0(app, cpu);
    // 00427b63  c7862401000003000000   -mov dword ptr [esi + 0x124], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 3 /*0x3*/;
    // 00427b6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b71  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427b74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427b75:
    // 00427b75  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00427b79  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00427b7f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00427b81  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00427b84  0f8af7fcffff           -jp 0x427881
    if (cpu.flags.pf)
    {
        goto L_0x00427881;
    }
    // 00427b8a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427b8c  e85f020000             -call 0x427df0
    cpu.esp -= 4;
    sub_427df0(app, cpu);
    // 00427b91  c7862401000004000000   -mov dword ptr [esi + 0x124], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 4 /*0x4*/;
    // 00427b9b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427b9f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427ba2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427ba3:
    // 00427ba3  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427ba5  e846020000             -call 0x427df0
    cpu.esp -= 4;
    sub_427df0(app, cpu);
    // 00427baa  c7862401000006000000   -mov dword ptr [esi + 0x124], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 6 /*0x6*/;
    // 00427bb4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bb5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bb6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bb8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427bbb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427bbc:
    // 00427bbc  f644241402             +test byte ptr [esp + 0x14], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 2 /*0x2*/));
    // 00427bc1  0f85bafcffff           -jne 0x427881
    if (!cpu.flags.zf)
    {
        goto L_0x00427881;
    }
    // 00427bc7  899e24010000           -mov dword ptr [esi + 0x124], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = cpu.ebx;
    // 00427bcd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bd0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bd1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427bd4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427bd5:
    // 00427bd5  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00427bd9  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00427bdf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00427be1  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00427be4  0f8a97fcffff           -jp 0x427881
    if (cpu.flags.pf)
    {
        goto L_0x00427881;
    }
    // 00427bea  899e24010000           -mov dword ptr [esi + 0x124], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = cpu.ebx;
    // 00427bf0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bf1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bf2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bf3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bf4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427bf7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427bf8:
L_0x00427bf8:
    // 00427bf8  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00427bfa  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427bfc  e8bff6ffff             -call 0x4272c0
    cpu.esp -= 4;
    sub_4272c0(app, cpu);
    // 00427c01  f60554d44a0004         +test byte ptr [0x4ad454], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(4904020) /* 0x4ad454 */) & 4 /*0x4*/));
    // 00427c08  7407                   -je 0x427c11
    if (cpu.flags.zf)
    {
        goto L_0x00427c11;
    }
    // 00427c0a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427c0c  e85fcbfeff             -call 0x414770
    cpu.esp -= 4;
    sub_414770(app, cpu);
L_0x00427c11:
    // 00427c11  c786240100000a000000   -mov dword ptr [esi + 0x124], 0xa
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 10 /*0xa*/;
    // 00427c1b  89ae28010000           -mov dword ptr [esi + 0x128], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = cpu.ebp;
    // 00427c21  89ae40010000           -mov dword ptr [esi + 0x140], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(320) /* 0x140 */) = cpu.ebp;
    // 00427c27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c2b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427c2e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427c2f:
    // 00427c2f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00427c31  e8aa000000             -call 0x427ce0
    cpu.esp -= 4;
    sub_427ce0(app, cpu);
    // 00427c36  3bc3                   +cmp eax, ebx
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
    // 00427c38  0f8543fcffff           -jne 0x427881
    if (!cpu.flags.zf)
    {
        goto L_0x00427881;
    }
    // 00427c3e  e82df7ffff             -call 0x427370
    cpu.esp -= 4;
    sub_427370(app, cpu);
    // 00427c43  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 00427c48  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00427c4e  24f9                   -and al, 0xf9
    cpu.al &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 00427c50  bf98c84a00             -mov edi, 0x4ac898
    cpu.edi = 4901016 /*0x4ac898*/;
    // 00427c55  a34cd44a00             -mov dword ptr [0x4ad44c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */) = cpu.eax;
    // 00427c5a  8b8e20010000           -mov ecx, dword ptr [esi + 0x120]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */);
    // 00427c60  03c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00427c62  899638010000           -mov dword ptr [esi + 0x138], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(312) /* 0x138 */) = cpu.edx;
    // 00427c68  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00427c6a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00427c6c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00427c6f  89ae24010000           -mov dword ptr [esi + 0x124], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = cpu.ebp;
    // 00427c75  892dd8c84a00           -mov dword ptr [0x4ac8d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.ebp;
    // 00427c7b  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00427c7d  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00427c7f  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00427c82  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 00427c84  e8772a0300             -call 0x45a700
    cpu.esp -= 4;
    sub_45a700(app, cpu);
    // 00427c89  849e2c010000           -test byte ptr [esi + 0x12c], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(300) /* 0x12c */) & cpu.bl));
    // 00427c8f  0f84ecfbffff           -je 0x427881
    if (cpu.flags.zf)
    {
        goto L_0x00427881;
    }
    // 00427c95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c99  83c414                 +add esp, 0x14
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
    // 00427c9c  e9bff7feff             -jmp 0x417460
    return sub_417460(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_427ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427ce0  8b8144010000           -mov eax, dword ptr [ecx + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(324) /* 0x144 */);
    // 00427ce6  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00427ce8  e893d5feff             -call 0x415280
    cpu.esp -= 4;
    sub_415280(app, cpu);
    // 00427ced  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00427cf3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00427cf5  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00427cf8  7a06                   -jp 0x427d00
    if (cpu.flags.pf)
    {
        goto L_0x00427d00;
    }
    // 00427cfa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00427cff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427d00:
    // 00427d00  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00427d02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427d10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427d11  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00427d13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427d14  83be3001000001         +cmp dword ptr [esi + 0x130], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427d1b  7507                   -jne 0x427d24
    if (!cpu.flags.zf)
    {
        goto L_0x00427d24;
    }
    // 00427d1d  e83ef5ffff             -call 0x427260
    cpu.esp -= 4;
    sub_427260(app, cpu);
    // 00427d22  eb05                   -jmp 0x427d29
    goto L_0x00427d29;
L_0x00427d24:
    // 00427d24  e837f7ffff             -call 0x427460
    cpu.esp -= 4;
    sub_427460(app, cpu);
L_0x00427d29:
    // 00427d29  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00427d2b  8b864c010000           -mov eax, dword ptr [esi + 0x14c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(332) /* 0x14c */);
    // 00427d31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427d33  751c                   -jne 0x427d51
    if (!cpu.flags.zf)
    {
        goto L_0x00427d51;
    }
    // 00427d35  68783c4900             -push 0x493c78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799608 /*0x493c78*/;
    cpu.esp -= 4;
    // 00427d3a  e8d1ceffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00427d3f  8b864c010000           -mov eax, dword ptr [esi + 0x14c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(332) /* 0x14c */);
    // 00427d45  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00427d48  89b8d0000000           -mov dword ptr [eax + 0xd0], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.edi;
    // 00427d4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427d4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427d50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427d51:
    // 00427d51  8b8e4c010000           -mov ecx, dword ptr [esi + 0x14c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(332) /* 0x14c */);
    // 00427d57  89b9d0000000           -mov dword ptr [ecx + 0xd0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */) = cpu.edi;
    // 00427d5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427d5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427d5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427d60  8b810c010000           -mov eax, dword ptr [ecx + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */);
    // 00427d66  898108010000           -mov dword ptr [ecx + 0x108], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 00427d6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427d70  f6054cd44a0006         +test byte ptr [0x4ad44c], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(4904012) /* 0x4ad44c */) & 6 /*0x6*/));
    // 00427d77  7437                   -je 0x427db0
    if (cpu.flags.zf)
    {
        goto L_0x00427db0;
    }
    // 00427d79  a144d44a00             -mov eax, dword ptr [0x4ad444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904004) /* 0x4ad444 */);
    // 00427d7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427d80  742e                   -je 0x427db0
    if (cpu.flags.zf)
    {
        goto L_0x00427db0;
    }
    // 00427d82  8b8044010000           -mov eax, dword ptr [eax + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(324) /* 0x144 */);
    // 00427d88  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00427d8a  e8f1d4feff             -call 0x415280
    cpu.esp -= 4;
    sub_415280(app, cpu);
    // 00427d8f  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 00427d95  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00427d97  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00427d9a  a14cd44a00             -mov eax, dword ptr [0x4ad44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */);
    // 00427d9f  7a08                   -jp 0x427da9
    if (cpu.flags.pf)
    {
        goto L_0x00427da9;
    }
    // 00427da1  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00427da3  a34cd44a00             -mov dword ptr [0x4ad44c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */) = cpu.eax;
    // 00427da8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427da9:
    // 00427da9  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00427dab  a34cd44a00             -mov dword ptr [0x4ad44c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904012) /* 0x4ad44c */) = cpu.eax;
L_0x00427db0:
    // 00427db0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427dc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427dc1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00427dc3  db863c010000           -fild dword ptr [esi + 0x13c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(316) /* 0x13c */))));
    // 00427dc9  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00427dcf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00427dd1  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00427dd4  7b0b                   -jnp 0x427de1
    if (!cpu.flags.pf)
    {
        goto L_0x00427de1;
    }
    // 00427dd6  e855d90300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00427ddb  d99e40010000           -fstp dword ptr [esi + 0x140]
    app->getMemory<float>(cpu.esi + x86::reg32(320) /* 0x140 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00427de1:
    // 00427de1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427de2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427df0  c705d8c84a0000000000   -mov dword ptr [0x4ac8d8], 0
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = 0 /*0x0*/;
    // 00427dfa  e871f3ffff             -call 0x427170
    cpu.esp -= 4;
    sub_427170(app, cpu);
    // 00427dff  e95cffffff             -jmp 0x427d60
    return sub_427d60(app, cpu);
}

/* align: skip  */
void Application::sub_427e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427e10  83f940                 +cmp ecx, 0x40
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427e13  7c0d                   -jl 0x427e22
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427e22;
    }
    // 00427e15  83f94e                 +cmp ecx, 0x4e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(78 /*0x4e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427e18  7f08                   -jg 0x427e22
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00427e22;
    }
    // 00427e1a  d9048dc03c4900         -fld dword ptr [ecx*4 + 0x493cc0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4799680) /* 0x493cc0 */ + cpu.ecx * 4)));
    // 00427e21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427e22:
    // 00427e22  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00427e28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427e30  83f940                 +cmp ecx, 0x40
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427e33  7c0d                   -jl 0x427e42
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427e42;
    }
    // 00427e35  83f94e                 +cmp ecx, 0x4e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(78 /*0x4e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427e38  7f08                   -jg 0x427e42
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00427e42;
    }
    // 00427e3a  d9048d843c4900         -fld dword ptr [ecx*4 + 0x493c84]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4799620) /* 0x493c84 */ + cpu.ecx * 4)));
    // 00427e41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427e42:
    // 00427e42  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00427e48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427e50  a168125200             -mov eax, dword ptr [0x521268]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378664) /* 0x521268 */);
    // 00427e55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427e60  a1dc125200             -mov eax, dword ptr [0x5212dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378780) /* 0x5212dc */);
    // 00427e65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427e70  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427e71  b939000000             -mov ecx, 0x39
    cpu.ecx = 57 /*0x39*/;
    // 00427e76  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00427e78  bf60125200             -mov edi, 0x521260
    cpu.edi = 5378656 /*0x521260*/;
    // 00427e7d  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00427e7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427e80  e9fb190000             -jmp 0x429880
    return sub_429880(app, cpu);
}

/* align: skip  */
void Application::sub_427e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427e90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427e91  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00427e95  d80da0764800           -fmul dword ptr [0x4876a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748960) /* 0x4876a0 */));
    // 00427e9b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427e9c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427e9d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427e9e  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00427ea0  e8ebee0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00427ea5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00427ea7  8d0476                 -lea eax, [esi + esi*2]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00427eaa  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00427ead  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00427eb0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00427eb4  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00427eb8  d86c2414               -fsubr dword ptr [esp + 0x14]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)) - cpu.fpu.st(0);
    // 00427ebc  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00427ebe  e8cdee0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00427ec3  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00427ec5  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00427ec9  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00427ecd  d8e9                   -fsubr st(1)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(1)) - cpu.fpu.st(0);
    // 00427ecf  d80d08754800           -fmul dword ptr [0x487508]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */));
    // 00427ed5  e8b6ee0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00427eda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00427edb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427edc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427edd  68303f4900             -push 0x493f30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800304 /*0x493f30*/;
    cpu.esp -= 4;
    // 00427ee2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427ee3  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00427ee5  e8d4ff0400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 00427eea  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00427eed  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00427eef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ef0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ef1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ef2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ef3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_427f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427f00  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 00427f03  8b0485a83c4900         -mov eax, dword ptr [eax*4 + 0x493ca8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4799656) /* 0x493ca8 */ + cpu.eax * 4);
    // 00427f0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427f10  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 00427f13  8b0485ac3c4900         -mov eax, dword ptr [eax*4 + 0x493cac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4799660) /* 0x493cac */ + cpu.eax * 4);
    // 00427f1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427f20  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 00427f23  8b0485b03c4900         -mov eax, dword ptr [eax*4 + 0x493cb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4799664) /* 0x493cb0 */ + cpu.eax * 4);
    // 00427f2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427f30  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 00427f33  8b0485b43c4900         -mov eax, dword ptr [eax*4 + 0x493cb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4799668) /* 0x493cb4 */ + cpu.eax * 4);
    // 00427f3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427f40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427f41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427f42  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00427f44  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00427f46  e80cef0400             -call 0x476e57
    cpu.esp -= 4;
    _rand(app, cpu);
    // 00427f4b  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00427f4c  2bf7                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00427f4e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00427f50  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00427f52  03c7                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00427f54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427f55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427f56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427f60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427f61  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00427f63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427f64  83fe01                 +cmp esi, 1
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
    // 00427f67  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00427f69  7c05                   -jl 0x427f70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427f70;
    }
    // 00427f6b  83fe06                 +cmp esi, 6
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427f6e  7e0e                   -jle 0x427f7e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00427f7e;
    }
L_0x00427f70:
    // 00427f70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427f71  68783f4900             -push 0x493f78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800376 /*0x493f78*/;
    cpu.esp -= 4;
    // 00427f76  e895ccffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00427f7b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00427f7e:
    // 00427f7e  83ff01                 +cmp edi, 1
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
    // 00427f81  7c05                   -jl 0x427f88
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427f88;
    }
    // 00427f83  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427f86  7e0e                   -jle 0x427f96
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00427f96;
    }
L_0x00427f88:
    // 00427f88  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427f89  68543f4900             -push 0x493f54
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800340 /*0x493f54*/;
    cpu.esp -= 4;
    // 00427f8e  e87dccffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00427f93  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00427f96:
    // 00427f96  8d0477                 -lea eax, [edi + esi*2]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 2);
    // 00427f99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427f9a  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00427f9c  d904b5743d4900         -fld dword ptr [esi*4 + 0x493d74]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4799860) /* 0x493d74 */ + cpu.esi * 4)));
    // 00427fa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427fa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_427fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427fb0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00427fb1  7429                   -je 0x427fdc
    if (cpu.flags.zf)
    {
        goto L_0x00427fdc;
    }
    // 00427fb3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00427fb4  7413                   -je 0x427fc9
    if (cpu.flags.zf)
    {
        goto L_0x00427fc9;
    }
    // 00427fb6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427fba  c7020000a0c1           -mov dword ptr [edx], 0xc1a00000
    app->getMemory<x86::reg32>(cpu.edx) = 3248488448 /*0xc1a00000*/;
    // 00427fc0  c7000000a041           -mov dword ptr [eax], 0x41a00000
    app->getMemory<x86::reg32>(cpu.eax) = 1101004800 /*0x41a00000*/;
    // 00427fc6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00427fc9:
    // 00427fc9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427fcd  c702000020c1           -mov dword ptr [edx], 0xc1200000
    app->getMemory<x86::reg32>(cpu.edx) = 3240099840 /*0xc1200000*/;
    // 00427fd3  c70100002041           -mov dword ptr [ecx], 0x41200000
    app->getMemory<x86::reg32>(cpu.ecx) = 1092616192 /*0x41200000*/;
    // 00427fd9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00427fdc:
    // 00427fdc  c7020000a0c0           -mov dword ptr [edx], 0xc0a00000
    app->getMemory<x86::reg32>(cpu.edx) = 3231711232 /*0xc0a00000*/;
    // 00427fe2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427fe6  c7020000a040           -mov dword ptr [edx], 0x40a00000
    app->getMemory<x86::reg32>(cpu.edx) = 1084227584 /*0x40a00000*/;
    // 00427fec  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_427ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427ff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427ff1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00427ff3  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00427ff5  7504                   -jne 0x427ffb
    if (!cpu.flags.zf)
    {
        goto L_0x00427ffb;
    }
    // 00427ff7  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00427ff9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ffa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427ffb:
    // 00427ffb  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00427ffc  7433                   -je 0x428031
    if (cpu.flags.zf)
    {
        goto L_0x00428031;
    }
    // 00427ffe  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00427fff  7418                   -je 0x428019
    if (cpu.flags.zf)
    {
        goto L_0x00428019;
    }
    // 00428001  83f901                 +cmp ecx, 1
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
    // 00428004  7507                   -jne 0x42800d
    if (!cpu.flags.zf)
    {
        goto L_0x0042800d;
    }
    // 00428006  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0042800b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042800c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042800d:
    // 0042800d  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428010  7c24                   -jl 0x428036
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428036;
    }
    // 00428012  b83c000000             -mov eax, 0x3c
    cpu.eax = 60 /*0x3c*/;
    // 00428017  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428018  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428019:
    // 00428019  83f901                 +cmp ecx, 1
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
    // 0042801c  7507                   -jne 0x428025
    if (!cpu.flags.zf)
    {
        goto L_0x00428025;
    }
    // 0042801e  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00428023  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428024  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428025:
    // 00428025  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428028  7c0c                   -jl 0x428036
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428036;
    }
    // 0042802a  b81e000000             -mov eax, 0x1e
    cpu.eax = 30 /*0x1e*/;
    // 0042802f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428030  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428031:
    // 00428031  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 00428034  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428035  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428036:
    // 00428036  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0042803a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042803b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428040  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428041  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00428043  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00428046  e815000000             -call 0x428060
    cpu.esp -= 4;
    sub_428060(app, cpu);
    // 0042804b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042804d  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00428050  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00428053  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428054  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428060  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428061  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00428063  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00428065  7411                   -je 0x428078
    if (cpu.flags.zf)
    {
        goto L_0x00428078;
    }
L_0x00428067:
    // 00428067  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00428069  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0042806b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042806c  e843f30400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00428071  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428074  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00428076  75ef                   -jne 0x428067
    if (!cpu.flags.zf)
    {
        goto L_0x00428067;
    }
L_0x00428078:
    // 00428078  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428079  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428080  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428083  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428084  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428085  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428086  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00428088  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042808a  e821020000             -call 0x4282b0
    cpu.esp -= 4;
    sub_4282b0(app, cpu);
    // 0042808f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00428091  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00428098  e8e3140000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 0042809d  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004280a0  e84b140000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 004280a5  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004280a8  a158d44a00             -mov eax, dword ptr [0x4ad458]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904024) /* 0x4ad458 */);
    // 004280ad  683c404900             -push 0x49403c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800572 /*0x49403c*/;
    cpu.esp -= 4;
    // 004280b2  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004280b6  e8fcec0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004280bb  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004280bf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004280c0  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004280c3  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004280c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004280c7  6818404900             -push 0x494018
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800536 /*0x494018*/;
    cpu.esp -= 4;
    // 004280cc  e8e6ec0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004280d1  683c404900             -push 0x49403c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800572 /*0x49403c*/;
    cpu.esp -= 4;
    // 004280d6  e8dcec0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004280db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004280dc  680c404900             -push 0x49400c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800524 /*0x49400c*/;
    cpu.esp -= 4;
    // 004280e1  e8d1ec0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004280e6  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004280e9  83fb03                 +cmp ebx, 3
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
    // 004280ec  0f8fb2000000           -jg 0x4281a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004281a4;
    }
    // 004280f2  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004280f5  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004280fb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004280fd  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00428100  0f8b9e000000           -jnp 0x4281a4
    if (!cpu.flags.pf)
    {
        goto L_0x004281a4;
    }
    // 00428106  a190d34a00             -mov eax, dword ptr [0x4ad390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903824) /* 0x4ad390 */);
    // 0042810b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042810d  3bc3                   +cmp eax, ebx
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
    // 0042810f  0f858f000000           -jne 0x4281a4
    if (!cpu.flags.zf)
    {
        goto L_0x004281a4;
    }
    // 00428115  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00428119  dc1d80744800           -fcomp qword ptr [0x487480]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748416) /* 0x487480 */)));
    cpu.fpu.pop();
    // 0042811f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428121  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00428126  7539                   -jne 0x428161
    if (!cpu.flags.zf)
    {
        goto L_0x00428161;
    }
    // 00428128  68f83f4900             -push 0x493ff8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800504 /*0x493ff8*/;
    cpu.esp -= 4;
    // 0042812d  e885ec0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00428132  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428135  ba28000000             -mov edx, 0x28
    cpu.edx = 40 /*0x28*/;
    // 0042813a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042813c  e8fffdffff             -call 0x427f40
    cpu.esp -= 4;
    sub_427f40(app, cpu);
    // 00428141  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00428145  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
L_0x00428149:
    // 00428149  d80dbc764800           -fmul dword ptr [0x4876bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748988) /* 0x4876bc */));
    // 0042814f  d84708                 -fadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 00428152  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00428155  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00428158:
    // 00428158  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042815a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042815b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042815c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042815d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428160  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428161:
    // 00428161  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00428165  dc1d40734800           -fcomp qword ptr [0x487340]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748096) /* 0x487340 */)));
    cpu.fpu.pop();
    // 0042816b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042816d  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00428172  7523                   -jne 0x428197
    if (!cpu.flags.zf)
    {
        goto L_0x00428197;
    }
    // 00428174  68e43f4900             -push 0x493fe4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800484 /*0x493fe4*/;
    cpu.esp -= 4;
    // 00428179  e839ec0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042817e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428181  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00428183  b9d8ffffff             -mov ecx, 0xffffffd8
    cpu.ecx = 4294967256 /*0xffffffd8*/;
    // 00428188  e8b3fdffff             -call 0x427f40
    cpu.esp -= 4;
    sub_427f40(app, cpu);
    // 0042818d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00428191  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00428195  ebb2                   -jmp 0x428149
    goto L_0x00428149;
L_0x00428197:
    // 00428197  68d03f4900             -push 0x493fd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800464 /*0x493fd0*/;
    cpu.esp -= 4;
    // 0042819c  e816ec0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004281a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004281a4:
    // 004281a4  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004281a7  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004281ab  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004281ac  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004281b0  e8fbfdffff             -call 0x427fb0
    cpu.esp -= 4;
    sub_427fb0(app, cpu);
    // 004281b5  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004281b9  d82558744800           -fsub dword ptr [0x487458]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */));
    // 004281bf  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 004281c5  e8c6eb0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 004281ca  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004281ce  d82558744800           -fsub dword ptr [0x487458]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */));
    // 004281d4  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004281d6  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 004281dc  e8afeb0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 004281e1  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004281e3  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004281e5  e856fdffff             -call 0x427f40
    cpu.esp -= 4;
    sub_427f40(app, cpu);
    // 004281ea  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004281ee  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004281f1  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 004281f5  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004281f8  d80dbc764800           -fmul dword ptr [0x4876bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748988) /* 0x4876bc */));
    // 004281fe  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00428202  e859fdffff             -call 0x427f60
    cpu.esp -= 4;
    sub_427f60(app, cpu);
    // 00428207  d8442410               -fadd dword ptr [esp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0042820b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00428210  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00428213  e818fdffff             -call 0x427f30
    cpu.esp -= 4;
    sub_427f30(app, cpu);
    // 00428218  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042821a  e801fdffff             -call 0x427f20
    cpu.esp -= 4;
    sub_427f20(app, cpu);
    // 0042821f  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00428221  e81afdffff             -call 0x427f40
    cpu.esp -= 4;
    sub_427f40(app, cpu);
    // 00428226  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00428229  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042822c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042822d  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00428230  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428231  68b83f4900             -push 0x493fb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800440 /*0x493fb8*/;
    cpu.esp -= 4;
    // 00428236  e87ceb0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042823b  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042823e  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00428241  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00428244  3bc8                   +cmp ecx, eax
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
    // 00428246  0f8c0cffffff           -jl 0x428158
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428158;
    }
    // 0042824c  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 0042824f  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00428255  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428257  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0042825a  0f8bf8feffff           -jnp 0x428158
    if (!cpu.flags.pf)
    {
        goto L_0x00428158;
    }
    // 00428260  68983f4900             -push 0x493f98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800408 /*0x493f98*/;
    cpu.esp -= 4;
    // 00428265  e84deb0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042826a  8b570c                 -mov edx, dword ptr [edi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0042826d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428270  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00428273  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00428275  b9ceffffff             -mov ecx, 0xffffffce
    cpu.ecx = 4294967246 /*0xffffffce*/;
    // 0042827a  e8c1fcffff             -call 0x427f40
    cpu.esp -= 4;
    sub_427f40(app, cpu);
    // 0042827f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00428283  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 00428287  d80dbc764800           -fmul dword ptr [0x4876bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748988) /* 0x4876bc */));
    // 0042828d  d84708                 -fadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 00428290  d85608                 -fcom dword ptr [esi + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00428293  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428295  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00428298  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042829a  7a0a                   -jp 0x4282a6
    if (cpu.flags.pf)
    {
        goto L_0x004282a6;
    }
    // 0042829c  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042829f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004282a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004282a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004282a2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004282a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004282a6:
    // 004282a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004282a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004282a8  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004282aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004282ab  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004282ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4282b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004282b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004282b1  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004282b3  e8c2ef0400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 004282b8  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004282ba  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004282bf  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004282c1  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004282c3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004282c6  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 004282c8  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004282ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004282cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4282d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004282d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004282d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004282d2  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 004282d7  e864470200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 004282dc  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004282de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004282e0  7433                   -je 0x428315
    if (cpu.flags.zf)
    {
        goto L_0x00428315;
    }
    // 004282e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004282e3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004282e5  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004282e9  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004282eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004282ec  e897f30400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004282f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004282f2  e8e0f20400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 004282f7  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004282fb  d81db4754800           -fcomp dword ptr [0x4875b4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748724) /* 0x4875b4 */)));
    cpu.fpu.pop();
    // 00428301  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00428304  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428306  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042830b  7508                   -jne 0x428315
    if (!cpu.flags.zf)
    {
        goto L_0x00428315;
    }
    // 0042830d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00428312  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428313  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428314  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428315:
    // 00428315  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00428317  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428318  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428319  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428320  b9242d4900             -mov ecx, 0x492d24
    cpu.ecx = 4795684 /*0x492d24*/;
    // 00428325  e8a6ffffff             -call 0x4282d0
    cpu.esp -= 4;
    sub_4282d0(app, cpu);
    // 0042832a  83f801                 +cmp eax, 1
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
    // 0042832d  750f                   -jne 0x42833e
    if (!cpu.flags.zf)
    {
        goto L_0x0042833e;
    }
    // 0042832f  803d101552004e         +cmp byte ptr [0x521510], 0x4e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00428336  7506                   -jne 0x42833e
    if (!cpu.flags.zf)
    {
        goto L_0x0042833e;
    }
    // 00428338  b801010000             -mov eax, 0x101
    cpu.eax = 257 /*0x101*/;
    // 0042833d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042833e:
    // 0042833e  b9602d4900             -mov ecx, 0x492d60
    cpu.ecx = 4795744 /*0x492d60*/;
    // 00428343  e888ffffff             -call 0x4282d0
    cpu.esp -= 4;
    sub_4282d0(app, cpu);
    // 00428348  f7d8                   +neg eax
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
    // 0042834a  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0042834c  2500010000             -and eax, 0x100
    cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00428351  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428360  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428361  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428362  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00428364  e8d7fcffff             -call 0x428040
    cpu.esp -= 4;
    sub_428040(app, cpu);
    // 00428369  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x0042836e:
    // 0042836e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428370  e84b010000             -call 0x4284c0
    cpu.esp -= 4;
    sub_4284c0(app, cpu);
    // 00428375  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428377  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428379  e862000000             -call 0x4283e0
    cpu.esp -= 4;
    sub_4283e0(app, cpu);
    // 0042837e  46                     -inc esi
    (cpu.esi)++;
    // 0042837f  83fe0a                 +cmp esi, 0xa
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
    // 00428382  7cea                   -jl 0x42836e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042836e;
    }
    // 00428384  e8574afeff             -call 0x40cde0
    cpu.esp -= 4;
    sub_40cde0(app, cpu);
    // 00428389  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042838a  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042838d  e86e4afeff             -call 0x40ce00
    cpu.esp -= 4;
    sub_40ce00(app, cpu);
    // 00428392  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00428394  e8d7010000             -call 0x428570
    cpu.esp -= 4;
    sub_428570(app, cpu);
    // 00428399  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042839b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042839d  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042839f  e83c000000             -call 0x4283e0
    cpu.esp -= 4;
    sub_4283e0(app, cpu);
    // 004283a4  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004283a7  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004283a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004283ab  740e                   -je 0x4283bb
    if (cpu.flags.zf)
    {
        goto L_0x004283bb;
    }
L_0x004283ad:
    // 004283ad  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004283b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004283b2  7407                   -je 0x4283bb
    if (cpu.flags.zf)
    {
        goto L_0x004283bb;
    }
    // 004283b4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004283b6  42                     -inc edx
    (cpu.edx)++;
    // 004283b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004283b9  75f2                   -jne 0x4283ad
    if (!cpu.flags.zf)
    {
        goto L_0x004283ad;
    }
L_0x004283bb:
    // 004283bb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004283bd  e8befcffff             -call 0x428080
    cpu.esp -= 4;
    sub_428080(app, cpu);
    // 004283c2  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004283c4  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004283c6  e815000000             -call 0x4283e0
    cpu.esp -= 4;
    sub_4283e0(app, cpu);
    // 004283cb  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004283ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004283cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004283d0  e9db010000             -jmp 0x4285b0
    return sub_4285b0(app, cpu);
}

/* align: skip  */
void Application::sub_4283e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004283e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004283e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004283e2  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004283e4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004283e6  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004283e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004283ea  6878404900             -push 0x494078
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800632 /*0x494078*/;
    cpu.esp -= 4;
    // 004283ef  e8c3e90400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004283f4  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004283f7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004283fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004283fc  751f                   -jne 0x42841d
    if (!cpu.flags.zf)
    {
        goto L_0x0042841d;
    }
    // 004283fe  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00428401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428402  686c404900             -push 0x49406c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800620 /*0x49406c*/;
    cpu.esp -= 4;
    // 00428407  e8abe90400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042840c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042840d  685c404900             -push 0x49405c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800604 /*0x49405c*/;
    cpu.esp -= 4;
    // 00428412  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00428415  e89de90400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042841a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042841d:
    // 0042841d  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00428420  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00428422  e819000000             -call 0x428440
    cpu.esp -= 4;
    sub_428440(app, cpu);
    // 00428427  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042842a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0042842d  40                     -inc eax
    (cpu.eax)++;
    // 0042842e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042842f  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00428432  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428433  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428441  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428442  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428443  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00428445  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00428447  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00428449  7437                   -je 0x428482
    if (cpu.flags.zf)
    {
        goto L_0x00428482;
    }
L_0x0042844b:
    // 0042844b  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0042844e  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00428454  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428456  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00428459  7b1b                   -jnp 0x428476
    if (!cpu.flags.pf)
    {
        goto L_0x00428476;
    }
    // 0042845b  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042845e  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00428461  3bc6                   +cmp eax, esi
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
    // 00428463  7f11                   -jg 0x428476
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428476;
    }
    // 00428465  7523                   -jne 0x42848a
    if (!cpu.flags.zf)
    {
        goto L_0x0042848a;
    }
    // 00428467  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0042846a  d85908                 -fcomp dword ptr [ecx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 0042846d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042846f  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00428474  7514                   -jne 0x42848a
    if (!cpu.flags.zf)
    {
        goto L_0x0042848a;
    }
L_0x00428476:
    // 00428476  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00428478  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042847a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042847c  75cd                   -jne 0x42844b
    if (!cpu.flags.zf)
    {
        goto L_0x0042844b;
    }
    // 0042847e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00428480  7521                   -jne 0x4284a3
    if (!cpu.flags.zf)
    {
        goto L_0x004284a3;
    }
L_0x00428482:
    // 00428482  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00428484  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428485  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00428487  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428488  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428489  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042848a:
    // 0042848a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042848c  7508                   -jne 0x428496
    if (!cpu.flags.zf)
    {
        goto L_0x00428496;
    }
    // 0042848e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042848f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428490  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428491  e91a000000             -jmp 0x4284b0
    return sub_4284b0(app, cpu);
L_0x00428496:
    // 00428496  e815000000             -call 0x4284b0
    cpu.esp -= 4;
    sub_4284b0(app, cpu);
    // 0042849b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0042849d  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042849f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004284a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004284a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004284a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004284a3:
    // 004284a3  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 004284a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004284a6  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004284a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004284a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004284aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4284b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004284b0  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004284b2  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004284b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4284c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004284c0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004284c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004284c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004284c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004284c6  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004284c8  e8b3100000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 004284cd  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004284cf  e8dcfdffff             -call 0x4282b0
    cpu.esp -= 4;
    sub_4282b0(app, cpu);
    // 004284d4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004284d6  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004284d8  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004284db  e850faffff             -call 0x427f30
    cpu.esp -= 4;
    sub_427f30(app, cpu);
    // 004284e0  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004284e2  e839faffff             -call 0x427f20
    cpu.esp -= 4;
    sub_427f20(app, cpu);
    // 004284e7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004284e9  e852faffff             -call 0x427f40
    cpu.esp -= 4;
    sub_427f40(app, cpu);
    // 004284ee  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004284f0  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004284f2  e8f9faffff             -call 0x427ff0
    cpu.esp -= 4;
    sub_427ff0(app, cpu);
    // 004284f7  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004284fa  895e14                 -mov dword ptr [esi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004284fd  e8ee0f0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 00428502  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428505  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00428508  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042850c  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00428510  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428511  e89afaffff             -call 0x427fb0
    cpu.esp -= 4;
    sub_427fb0(app, cpu);
    // 00428516  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0042851a  d80d50774800           -fmul dword ptr [0x487750]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749136) /* 0x487750 */));
    // 00428520  e86be80400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00428525  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00428529  d80d50774800           -fmul dword ptr [0x487750]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749136) /* 0x487750 */));
    // 0042852f  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00428531  e85ae80400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00428536  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00428538  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042853a  e801faffff             -call 0x427f40
    cpu.esp -= 4;
    sub_427f40(app, cpu);
    // 0042853f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00428543  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428546  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042854a  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0042854d  d80d80764800           -fmul dword ptr [0x487680]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748928) /* 0x487680 */));
    // 00428553  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00428557  e804faffff             -call 0x427f60
    cpu.esp -= 4;
    sub_427f60(app, cpu);
    // 0042855c  d8442410               -fadd dword ptr [esp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00428560  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00428562  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428563  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00428566  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428567  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428568  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042856b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428571  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428572  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00428574  e837fdffff             -call 0x4282b0
    cpu.esp -= 4;
    sub_4282b0(app, cpu);
    // 00428579  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042857b  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00428582  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00428585  e8f60f0000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 0042858a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0042858d  e85e0f0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 00428592  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00428595  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00428599  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042859c  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042859e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042859f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004285a0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4285b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004285b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004285b2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004285b7  740a                   -je 0x4285c3
    if (cpu.flags.zf)
    {
        goto L_0x004285c3;
    }
L_0x004285b9:
    // 004285b9  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004285bc  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004285be  40                     -inc eax
    (cpu.eax)++;
    // 004285bf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004285c1  75f6                   -jne 0x4285b9
    if (!cpu.flags.zf)
    {
        goto L_0x004285b9;
    }
L_0x004285c3:
    // 004285c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4285d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004285d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004285d1  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004285d3  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004285d5  0faf4c2408             -imul ecx, dword ptr [esp + 8]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 004285da  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004285dc  7e0e                   -jle 0x4285ec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004285ec;
    }
    // 004285de  b820002000             -mov eax, 0x200020
    cpu.eax = 2097184 /*0x200020*/;
    // 004285e3  d1e9                   +shr ecx, 1
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
    // 004285e5  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 004285e7  13c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004285e9  66f3ab                 -rep stosw word ptr es:[edi], ax
    while (cpu.ecx)
    {
        app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = cpu.ax;
        if (cpu.flags.df)
        {
            cpu.edi -= 2;
        }
        else
        {
            cpu.edi += 2;
        }
        --cpu.ecx;
    }
L_0x004285ec:
    // 004285ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004285ed  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4285f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004285f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004285f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004285f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004285f3  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004285f5  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004285f7  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004285fc:
    // 004285fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004285fe  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428600  7415                   -je 0x428617
    if (cpu.flags.zf)
    {
        goto L_0x00428617;
    }
L_0x00428602:
    // 00428602  397118                 +cmp dword ptr [ecx + 0x18], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428605  7408                   -je 0x42860f
    if (cpu.flags.zf)
    {
        goto L_0x0042860f;
    }
    // 00428607  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00428609  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042860b  75f5                   -jne 0x428602
    if (!cpu.flags.zf)
    {
        goto L_0x00428602;
    }
    // 0042860d  eb08                   -jmp 0x428617
    goto L_0x00428617;
L_0x0042860f:
    // 0042860f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428610  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00428612  e819000000             -call 0x428630
    cpu.esp -= 4;
    sub_428630(app, cpu);
L_0x00428617:
    // 00428617  46                     -inc esi
    (cpu.esi)++;
    // 00428618  83fe05                 +cmp esi, 5
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
    // 0042861b  7edf                   -jle 0x4285fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004285fc;
    }
    // 0042861d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042861e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042861f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428620  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428630  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428631  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428632  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428633  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428634  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00428636  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428637  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00428639  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0042863d  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00428642  eb04                   -jmp 0x428648
    goto L_0x00428648;
L_0x00428644:
    // 00428644  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00428648:
    // 00428648  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042864a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042864c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042864e  7427                   -je 0x428677
    if (cpu.flags.zf)
    {
        goto L_0x00428677;
    }
L_0x00428650:
    // 00428650  396e18                 +cmp dword ptr [esi + 0x18], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428653  7522                   -jne 0x428677
    if (!cpu.flags.zf)
    {
        goto L_0x00428677;
    }
    // 00428655  397e14                 +cmp dword ptr [esi + 0x14], edi
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
    // 00428658  7515                   -jne 0x42866f
    if (!cpu.flags.zf)
    {
        goto L_0x0042866f;
    }
    // 0042865a  3b5c2418               +cmp ebx, dword ptr [esp + 0x18]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042865e  7d03                   -jge 0x428663
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00428663;
    }
    // 00428660  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00428661  eb0c                   -jmp 0x42866f
    goto L_0x0042866f;
L_0x00428663:
    // 00428663  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428665  7410                   -je 0x428677
    if (cpu.flags.zf)
    {
        goto L_0x00428677;
    }
    // 00428667  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428668  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042866a  e821000000             -call 0x428690
    cpu.esp -= 4;
    sub_428690(app, cpu);
L_0x0042866f:
    // 0042866f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428671  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00428673  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00428675  75d9                   -jne 0x428650
    if (!cpu.flags.zf)
    {
        goto L_0x00428650;
    }
L_0x00428677:
    // 00428677  47                     -inc edi
    (cpu.edi)++;
    // 00428678  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042867b  7ec7                   -jle 0x428644
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00428644;
    }
    // 0042867d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042867e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042867f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428680  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428681  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428682  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_428690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428691  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428693  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00428695  7414                   -je 0x4286ab
    if (cpu.flags.zf)
    {
        goto L_0x004286ab;
    }
    // 00428697  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0042869b:
    // 0042869b  395018                 +cmp dword ptr [eax + 0x18], edx
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
    // 0042869e  750b                   -jne 0x4286ab
    if (!cpu.flags.zf)
    {
        goto L_0x004286ab;
    }
    // 004286a0  397014                 +cmp dword ptr [eax + 0x14], esi
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
    // 004286a3  7506                   -jne 0x4286ab
    if (!cpu.flags.zf)
    {
        goto L_0x004286ab;
    }
    // 004286a5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004286a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004286a9  75f0                   -jne 0x42869b
    if (!cpu.flags.zf)
    {
        goto L_0x0042869b;
    }
L_0x004286ab:
    // 004286ab  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 004286ad  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004286af  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004286b1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004286b3  e808000000             -call 0x4286c0
    cpu.esp -= 4;
    sub_4286c0(app, cpu);
    // 004286b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004286b9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4286c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004286c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004286c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004286c2  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004286c4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004286c6  3bf7                   +cmp esi, edi
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
    // 004286c8  7411                   -je 0x4286db
    if (cpu.flags.zf)
    {
        goto L_0x004286db;
    }
L_0x004286ca:
    // 004286ca  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004286cc  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004286ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004286cf  e8e0ec0400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 004286d4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004286d7  3bf7                   +cmp esi, edi
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
    // 004286d9  75ef                   -jne 0x4286ca
    if (!cpu.flags.zf)
    {
        goto L_0x004286ca;
    }
L_0x004286db:
    // 004286db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004286dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004286dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4286e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004286e0  8b0d74125200           -mov ecx, dword ptr [0x521274]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378676) /* 0x521274 */);
    // 004286e6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004286e8  7410                   -je 0x4286fa
    if (cpu.flags.zf)
    {
        goto L_0x004286fa;
    }
    // 004286ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004286ef:
    // 004286ef  39411c                 +cmp dword ptr [ecx + 0x1c], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004286f2  7408                   -je 0x4286fc
    if (cpu.flags.zf)
    {
        goto L_0x004286fc;
    }
    // 004286f4  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004286f6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004286f8  75f5                   -jne 0x4286ef
    if (!cpu.flags.zf)
    {
        goto L_0x004286ef;
    }
L_0x004286fa:
    // 004286fa  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004286fc:
    // 004286fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428700  81eccc010000           -sub esp, 0x1cc
    (cpu.esp) -= x86::reg32(x86::sreg32(460 /*0x1cc*/));
    // 00428706  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428707  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428708  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428709  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042870b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042870c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042870d  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0042870f  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00428713  e885f60400             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 00428718  8b8424e4010000         -mov eax, dword ptr [esp + 0x1e4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(484) /* 0x1e4 */);
    // 0042871f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428722  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00428724  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428726  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428727  e8a4feffff             -call 0x4285d0
    cpu.esp -= 4;
    sub_4285d0(app, cpu);
    // 0042872c  e8bf0d0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 00428731  a364125200             -mov dword ptr [0x521264], eax
    app->getMemory<x86::reg32>(x86::reg32(5378660) /* 0x521264 */) = cpu.eax;
    // 00428736  e8450e0000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 0042873b  8b8c24e8010000         -mov ecx, dword ptr [esp + 0x1e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(488) /* 0x1e8 */);
    // 00428742  a360125200             -mov dword ptr [0x521260], eax
    app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */) = cpu.eax;
    // 00428747  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428749  7521                   -jne 0x42876c
    if (!cpu.flags.zf)
    {
        goto L_0x0042876c;
    }
    // 0042874b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042874c  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00428750  6848414900             -push 0x494148
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800840 /*0x494148*/;
    cpu.esp -= 4;
    // 00428755  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428756  e89de60400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042875b  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042875f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00428760  e85bc60200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428765  83c410                 +add esp, 0x10
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
    // 00428768  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042876a  eb41                   -jmp 0x4287ad
    goto L_0x004287ad;
L_0x0042876c:
    // 0042876c  6838414900             -push 0x494138
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800824 /*0x494138*/;
    cpu.esp -= 4;
    // 00428771  e84ac60200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428776  8b0d5cd44a00           -mov ecx, dword ptr [0x4ad45c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904028) /* 0x4ad45c */);
    // 0042877c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042877f  81f900010000           +cmp ecx, 0x100
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
    // 00428785  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00428787  7c24                   -jl 0x4287ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004287ad;
    }
    // 00428789  a16c125200             -mov eax, dword ptr [0x52126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 0042878e  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 00428791  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 00428797  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428799  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0042879c  7b05                   -jnp 0x4287a3
    if (!cpu.flags.pf)
    {
        goto L_0x004287a3;
    }
    // 0042879e  e85d21ffff             -call 0x41a900
    cpu.esp -= 4;
    sub_41a900(app, cpu);
L_0x004287a3:
    // 004287a3  c7055cd44a0000000000   -mov dword ptr [0x4ad45c], 0
    app->getMemory<x86::reg32>(x86::reg32(4904028) /* 0x4ad45c */) = 0 /*0x0*/;
L_0x004287ad:
    // 004287ad  8b0d64125200           -mov ecx, dword ptr [0x521264]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378660) /* 0x521264 */);
    // 004287b3  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004287b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004287b8  6830414900             -push 0x494130
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800816 /*0x494130*/;
    cpu.esp -= 4;
    // 004287bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004287be  e835e60400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004287c3  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004287c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004287c8  e8f3c50200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004287cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004287ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004287cf  8d4c2474               -lea ecx, [esp + 0x74]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004287d3  6818414900             -push 0x494118
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800792 /*0x494118*/;
    cpu.esp -= 4;
    // 004287d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004287d9  e8e0f60400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 004287de  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004287e1  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004287e5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004287e7  e8b456feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004287ec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004287ed  680c414900             -push 0x49410c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800780 /*0x49410c*/;
    cpu.esp -= 4;
    // 004287f2  e8c0e50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004287f7  68fc404900             -push 0x4940fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800764 /*0x4940fc*/;
    cpu.esp -= 4;
    // 004287fc  8d3cad00000000         -lea edi, [ebp*4]
    cpu.edi = x86::reg32(cpu.ebp * 4);
    // 00428803  e8b8c50200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428808  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042880b  8d4c7e0a               -lea ecx, [esi + edi*2 + 0xa]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(10) /* 0xa */ + cpu.edi * 2);
    // 0042880f  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428811  e88a56feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00428816  68f0404900             -push 0x4940f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800752 /*0x4940f0*/;
    cpu.esp -= 4;
    // 0042881b  e8a0c50200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428820  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428823  8d4c7e34               -lea ecx, [esi + edi*2 + 0x34]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.edi * 2);
    // 00428827  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428829  e87256feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042882e  68e0404900             -push 0x4940e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800736 /*0x4940e0*/;
    cpu.esp -= 4;
    // 00428833  e888c50200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428838  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042883b  8d4c7e4a               -lea ecx, [esi + edi*2 + 0x4a]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(74) /* 0x4a */ + cpu.edi * 2);
    // 0042883f  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428841  e85a56feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00428846  8b9c24e4010000         -mov ebx, dword ptr [esp + 0x1e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(484) /* 0x1e4 */);
    // 0042884d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042884f  0f84a9010000           -je 0x4289fe
    if (cpu.flags.zf)
    {
        goto L_0x004289fe;
    }
    // 00428855  8b0d70125200           -mov ecx, dword ptr [0x521270]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378672) /* 0x521270 */);
    // 0042885b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042885d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042885f  0f8e99010000           -jle 0x4289fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004289fe;
    }
    // 00428865  8d4c6d00               -lea ecx, [ebp + ebp*2]
    cpu.ecx = x86::reg32(cpu.ebp + cpu.ebp * 2);
    // 00428869  8d546d00               -lea edx, [ebp + ebp*2]
    cpu.edx = x86::reg32(cpu.ebp + cpu.ebp * 2);
    // 0042886d  03c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042886f  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00428873  8d74960a               -lea esi, [esi + edx*4 + 0xa]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(10) /* 0xa */ + cpu.edx * 4);
L_0x00428877:
    // 00428877  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042887a  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0042887e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042887f  68d8404900             -push 0x4940d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800728 /*0x4940d8*/;
    cpu.esp -= 4;
    // 00428884  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428885  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00428889  e830f60400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 0042888e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00428891  8d4ef8                 -lea ecx, [esi - 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-8) /* -0x8 */);
    // 00428894  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00428898  e80356feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042889d  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004288a0  e85bf6ffff             -call 0x427f00
    cpu.esp -= 4;
    sub_427f00(app, cpu);
    // 004288a5  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004288a7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004288a9  e8f255feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004288ae  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004288b1  bad4404900             -mov edx, 0x4940d4
    cpu.edx = 4800724 /*0x4940d4*/;
    // 004288b6  e8e555feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004288bb  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004288be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004288c0  0f85a3000000           -jne 0x428969
    if (!cpu.flags.zf)
    {
        goto L_0x00428969;
    }
    // 004288c6  e88560ffff             -call 0x41e950
    cpu.esp -= 4;
    sub_41e950(app, cpu);
    // 004288cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004288cd  0f8ca5000000           -jl 0x428978
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428978;
    }
    // 004288d3  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 004288d9  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 004288dc  8b7cca04               -mov edi, dword ptr [edx + ecx*8 + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8);
    // 004288e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004288e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004288e2  68b4404900             -push 0x4940b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800692 /*0x4940b4*/;
    cpu.esp -= 4;
    // 004288e7  e8cbe40400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004288ec  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004288ef  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004288f4  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004288f8  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004288fa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004288fc  e80f010000             -call 0x428a10
    cpu.esp -= 4;
    sub_428a10(app, cpu);
    // 00428901  8d4ef6                 -lea ecx, [esi - 0xa]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-10) /* -0xa */);
    // 00428904  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00428908  e89355feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042890d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00428912  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00428916  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00428918  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042891a  e8f1000000             -call 0x428a10
    cpu.esp -= 4;
    sub_428a10(app, cpu);
    // 0042891f  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00428923  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00428927  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042892b  03c5                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0042892d  8d4c41fc               -lea ecx, [ecx + eax*2 - 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 2);
    // 00428931  e86a55feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00428936  8d94245c010000         -lea edx, [esp + 0x15c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(348) /* 0x15c */);
    // 0042893d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042893e  6880064900             -push 0x490680
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785792 /*0x490680*/;
    cpu.esp -= 4;
    // 00428943  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00428944  e8afe40400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00428949  8d842468010000         -lea eax, [esp + 0x168]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(360) /* 0x168 */);
    // 00428950  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428951  e86ac40200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428956  83c410                 +add esp, 0x10
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
    // 00428959  8d4e14                 -lea ecx, [esi + 0x14]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0042895c  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042895e  e83d55feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00428963  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00428967  eb0f                   -jmp 0x428978
    goto L_0x00428978;
L_0x00428969:
    // 00428969  e8a2f5ffff             -call 0x427f10
    cpu.esp -= 4;
    sub_427f10(app, cpu);
    // 0042896e  8d4e14                 -lea ecx, [esi + 0x14]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428971  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428973  e82855feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
L_0x00428978:
    // 00428978  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0042897b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042897c  8d8c24a0010000         -lea ecx, [esp + 0x1a0]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 00428983  e808f5ffff             -call 0x427e90
    cpu.esp -= 4;
    sub_427e90(app, cpu);
    // 00428988  8d4e2a                 -lea ecx, [esi + 0x2a]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(42) /* 0x2a */);
    // 0042898b  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042898d  e80e55feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00428992  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00428995  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428997  7521                   -jne 0x4289ba
    if (!cpu.flags.zf)
    {
        goto L_0x004289ba;
    }
    // 00428999  d94308                 -fld dword ptr [ebx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 0042899c  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004289a2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004289a4  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 004289a7  7a11                   -jp 0x4289ba
    if (cpu.flags.pf)
    {
        goto L_0x004289ba;
    }
    // 004289a9  68a0404900             -push 0x4940a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800672 /*0x4940a0*/;
    cpu.esp -= 4;
    // 004289ae  e80dc40200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004289b3  83c404                 +add esp, 4
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
    // 004289b6  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004289b8  eb1a                   -jmp 0x4289d4
    goto L_0x004289d4;
L_0x004289ba:
    // 004289ba  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004289bd  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004289c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004289c2  6898404900             -push 0x494098
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800664 /*0x494098*/;
    cpu.esp -= 4;
    // 004289c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004289c8  e8f1f40400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 004289cd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004289d0  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
L_0x004289d4:
    // 004289d4  8d4e40                 -lea ecx, [esi + 0x40]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 004289d7  e8c454feff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004289dc  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004289e0  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004289e2  8d4c2d00               -lea ecx, [ebp + ebp]
    cpu.ecx = x86::reg32(cpu.ebp + cpu.ebp * 1);
    // 004289e6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004289e8  03f1                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004289ea  8b0d70125200           -mov ecx, dword ptr [0x521270]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378672) /* 0x521270 */);
    // 004289f0  03d5                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004289f2  3bc1                   +cmp eax, ecx
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
    // 004289f4  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004289f8  0f8c79feffff           -jl 0x428877
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428877;
    }
L_0x004289fe:
    // 004289fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004289ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428a00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428a01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428a02  81c4cc010000           -add esp, 0x1cc
    (cpu.esp) += x86::reg32(x86::sreg32(460 /*0x1cc*/));
    // 00428a08  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_428a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428a10  3b542404               +cmp edx, dword ptr [esp + 4]
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
    // 00428a14  7511                   -jne 0x428a27
    if (!cpu.flags.zf)
    {
        goto L_0x00428a27;
    }
    // 00428a16  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00428a1b  66c741020000           -mov word ptr [ecx + 2], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 00428a21  668901                 -mov word ptr [ecx], ax
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.ax;
    // 00428a24  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00428a27:
    // 00428a27  68203f4900             -push 0x493f20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800288 /*0x493f20*/;
    cpu.esp -= 4;
    // 00428a2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428a2d  e88cf40400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 00428a32  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428a35  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_428a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428a40  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428a41  e83a0b0000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 00428a46  a360125200             -mov dword ptr [0x521260], eax
    app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */) = cpu.eax;
    // 00428a4b  e8a00a0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 00428a50  b960125200             -mov ecx, 0x521260
    cpu.ecx = 5378656 /*0x521260*/;
    // 00428a55  a364125200             -mov dword ptr [0x521264], eax
    app->getMemory<x86::reg32>(x86::reg32(5378660) /* 0x521264 */) = cpu.eax;
    // 00428a5a  e801f9ffff             -call 0x428360
    cpu.esp -= 4;
    sub_428360(app, cpu);
    // 00428a5f  b960125200             -mov ecx, 0x521260
    cpu.ecx = 5378656 /*0x521260*/;
    // 00428a64  e8a7000000             -call 0x428b10
    cpu.esp -= 4;
    sub_428b10(app, cpu);
    // 00428a69  833d6012520001         +cmp dword ptr [0x521260], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428a70  7517                   -jne 0x428a89
    if (!cpu.flags.zf)
    {
        goto L_0x00428a89;
    }
    // 00428a72  803d1015520040         +cmp byte ptr [0x521510], 0x40
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00428a79  720e                   -jb 0x428a89
    if (cpu.flags.cf)
    {
        goto L_0x00428a89;
    }
    // 00428a7b  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 00428a80  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00428a82  bf7c125200             -mov edi, 0x52127c
    cpu.edi = 5378684 /*0x52127c*/;
    // 00428a87  f3ab                   -rep stosd dword ptr es:[edi], eax
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
L_0x00428a89:
    // 00428a89  a160125200             -mov eax, dword ptr [0x521260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */);
    // 00428a8e  8b156c125200           -mov edx, dword ptr [0x52126c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 00428a94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428a95  b97c125200             -mov ecx, 0x52127c
    cpu.ecx = 5378684 /*0x52127c*/;
    // 00428a9a  e8010b0000             -call 0x4295a0
    cpu.esp -= 4;
    sub_4295a0(app, cpu);
    // 00428a9f  b960125200             -mov ecx, 0x521260
    cpu.ecx = 5378656 /*0x521260*/;
    // 00428aa4  e8c7010000             -call 0x428c70
    cpu.esp -= 4;
    sub_428c70(app, cpu);
    // 00428aa9  8b0d60125200           -mov ecx, dword ptr [0x521260]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */);
    // 00428aaf  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00428ab2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00428ab5  8b9098125200           -mov edx, dword ptr [eax + 0x521298]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5378712) /* 0x521298 */);
    // 00428abb  8d8098125200           -lea eax, [eax + 0x521298]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(5378712) /* 0x521298 */);
    // 00428ac1  83ca01                 -or edx, 1
    cpu.edx |= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00428ac4  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00428ac6  e825070000             -call 0x4291f0
    cpu.esp -= 4;
    sub_4291f0(app, cpu);
    // 00428acb  833d6012520003         +cmp dword ptr [0x521260], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428ad2  752e                   -jne 0x428b02
    if (!cpu.flags.zf)
    {
        goto L_0x00428b02;
    }
    // 00428ad4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428ad6  752a                   -jne 0x428b02
    if (!cpu.flags.zf)
    {
        goto L_0x00428b02;
    }
    // 00428ad8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428ad9  e8a20f0000             -call 0x429a80
    cpu.esp -= 4;
    sub_429a80(app, cpu);
    // 00428ade  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00428ae0  e80b0a0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 00428ae5  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00428ae8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428ae9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428aea  6850414900             -push 0x494150
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800848 /*0x494150*/;
    cpu.esp -= 4;
    // 00428aef  e8c3e20400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00428af4  83c40c                 +add esp, 0xc
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
    // 00428af7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428af9  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00428afb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428afc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428afd  e98ec5feff             -jmp 0x415090
    return sub_415090(app, cpu);
L_0x00428b02:
    // 00428b02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428b10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428b11  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00428b13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428b14  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00428b17  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00428b19  7454                   -je 0x428b6f
    if (cpu.flags.zf)
    {
        goto L_0x00428b6f;
    }
    // 00428b1b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428b1d  e87e060000             -call 0x4291a0
    cpu.esp -= 4;
    sub_4291a0(app, cpu);
    // 00428b22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428b24  7549                   -jne 0x428b6f
    if (!cpu.flags.zf)
    {
        goto L_0x00428b6f;
    }
    // 00428b26  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428b29  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00428b2b  e820010000             -call 0x428c50
    cpu.esp -= 4;
    sub_428c50(app, cpu);
    // 00428b30  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428b32  e849000000             -call 0x428b80
    cpu.esp -= 4;
    sub_428b80(app, cpu);
    // 00428b37  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428b39  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00428b3c  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00428b42  c7421c01000000         -mov dword ptr [edx + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 00428b49  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428b4b  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00428b4e  7b1f                   -jnp 0x428b6f
    if (!cpu.flags.pf)
    {
        goto L_0x00428b6f;
    }
    // 00428b50  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428b52  e849000000             -call 0x428ba0
    cpu.esp -= 4;
    sub_428ba0(app, cpu);
    // 00428b57  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428b5a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00428b5f  e88cfaffff             -call 0x4285f0
    cpu.esp -= 4;
    sub_4285f0(app, cpu);
    // 00428b64  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428b67  e8f4000000             -call 0x428c60
    cpu.esp -= 4;
    sub_428c60(app, cpu);
    // 00428b6c  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00428b6f:
    // 00428b6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428b80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428b81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428b82  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00428b84  e827f7ffff             -call 0x4282b0
    cpu.esp -= 4;
    sub_4282b0(app, cpu);
    // 00428b89  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00428b8e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00428b90  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00428b92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b93  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00428b99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428ba0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428ba1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00428ba3  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428ba6  e815000000             -call 0x428bc0
    cpu.esp -= 4;
    sub_428bc0(app, cpu);
    // 00428bab  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00428bae  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00428bb1  40                     -inc eax
    (cpu.eax)++;
    // 00428bb2  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00428bb5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428bb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428bc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428bc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428bc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428bc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428bc4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428bc6  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00428bc8  7507                   -jne 0x428bd1
    if (!cpu.flags.zf)
    {
        goto L_0x00428bd1;
    }
    // 00428bca  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00428bcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428bcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428bce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428bcf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428bd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428bd1:
    // 00428bd1  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00428bd4  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00428bd6  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00428bd8:
    // 00428bd8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00428bdb  3be8                   +cmp ebp, eax
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
    // 00428bdd  7c36                   -jl 0x428c15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428c15;
    }
    // 00428bdf  753c                   -jne 0x428c1d
    if (!cpu.flags.zf)
    {
        goto L_0x00428c1d;
    }
    // 00428be1  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428be4  8b7a14                 -mov edi, dword ptr [edx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00428be7  3bc7                   +cmp eax, edi
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
    // 00428be9  7c2a                   -jl 0x428c15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428c15;
    }
    // 00428beb  7530                   -jne 0x428c1d
    if (!cpu.flags.zf)
    {
        goto L_0x00428c1d;
    }
    // 00428bed  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00428bf0  8b7a0c                 -mov edi, dword ptr [edx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00428bf3  3bc7                   +cmp eax, edi
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
    // 00428bf5  7f1e                   -jg 0x428c15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428c15;
    }
    // 00428bf7  7524                   -jne 0x428c1d
    if (!cpu.flags.zf)
    {
        goto L_0x00428c1d;
    }
    // 00428bf9  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00428bfc  d85a08                 -fcomp dword ptr [edx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 00428bff  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428c01  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00428c06  740d                   -je 0x428c15
    if (cpu.flags.zf)
    {
        goto L_0x00428c15;
    }
    // 00428c08  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00428c0b  d85a08                 -fcomp dword ptr [edx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 00428c0e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428c10  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00428c13  7b08                   -jnp 0x428c1d
    if (!cpu.flags.pf)
    {
        goto L_0x00428c1d;
    }
L_0x00428c15:
    // 00428c15  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00428c17  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00428c19  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00428c1b  75bb                   -jne 0x428bd8
    if (!cpu.flags.zf)
    {
        goto L_0x00428bd8;
    }
L_0x00428c1d:
    // 00428c1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428c1e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428c20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428c21  e80a000000             -call 0x428c30
    cpu.esp -= 4;
    sub_428c30(app, cpu);
    // 00428c26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428c27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428c28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428c29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428c2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428c30  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00428c32  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00428c36  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428c38  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00428c3a  7406                   -je 0x428c42
    if (cpu.flags.zf)
    {
        goto L_0x00428c42;
    }
    // 00428c3c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00428c3e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x00428c42:
    // 00428c42  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_428c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428c50  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428c52  7409                   -je 0x428c5d
    if (cpu.flags.zf)
    {
        goto L_0x00428c5d;
    }
L_0x00428c54:
    // 00428c54  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00428c57  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00428c59  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428c5b  75f7                   -jne 0x428c54
    if (!cpu.flags.zf)
    {
        goto L_0x00428c54;
    }
L_0x00428c5d:
    // 00428c5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428c60  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00428c62  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428c64  7407                   -je 0x428c6d
    if (cpu.flags.zf)
    {
        goto L_0x00428c6d;
    }
L_0x00428c66:
    // 00428c66  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00428c68  40                     -inc eax
    (cpu.eax)++;
    // 00428c69  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428c6b  75f9                   -jne 0x428c66
    if (!cpu.flags.zf)
    {
        goto L_0x00428c66;
    }
L_0x00428c6d:
    // 00428c6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428c70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428c71  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00428c73  e878050000             -call 0x4291f0
    cpu.esp -= 4;
    sub_4291f0(app, cpu);
    // 00428c78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428c7a  754f                   -jne 0x428ccb
    if (!cpu.flags.zf)
    {
        goto L_0x00428ccb;
    }
    // 00428c7c  e8ff080000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 00428c81  83f801                 +cmp eax, 1
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
    // 00428c84  7529                   -jne 0x428caf
    if (!cpu.flags.zf)
    {
        goto L_0x00428caf;
    }
    // 00428c86  803d1015520040         +cmp byte ptr [0x521510], 0x40
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00428c8d  7220                   -jb 0x428caf
    if (cpu.flags.cf)
    {
        goto L_0x00428caf;
    }
    // 00428c8f  8b4e7c                 -mov ecx, dword ptr [esi + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00428c92  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428c94  740c                   -je 0x428ca2
    if (cpu.flags.zf)
    {
        goto L_0x00428ca2;
    }
    // 00428c96  e8c5f3ffff             -call 0x428060
    cpu.esp -= 4;
    sub_428060(app, cpu);
    // 00428c9b  c7467c00000000         -mov dword ptr [esi + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
L_0x00428ca2:
    // 00428ca2  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00428ca5  e826000000             -call 0x428cd0
    cpu.esp -= 4;
    sub_428cd0(app, cpu);
    // 00428caa  89467c                 -mov dword ptr [esi + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 00428cad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428cae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428caf:
    // 00428caf  8b567c                 -mov edx, dword ptr [esi + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00428cb2  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00428cb5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00428cb7  750a                   -jne 0x428cc3
    if (!cpu.flags.zf)
    {
        goto L_0x00428cc3;
    }
    // 00428cb9  e812000000             -call 0x428cd0
    cpu.esp -= 4;
    sub_428cd0(app, cpu);
    // 00428cbe  89467c                 -mov dword ptr [esi + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 00428cc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428cc2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428cc3:
    // 00428cc3  e838000000             -call 0x428d00
    cpu.esp -= 4;
    sub_428d00(app, cpu);
    // 00428cc8  89467c                 -mov dword ptr [esi + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.eax;
L_0x00428ccb:
    // 00428ccb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428ccc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428cd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428cd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428cd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428cd3  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00428cd5  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00428cd7  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00428cd9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00428cdb  741b                   -je 0x428cf8
    if (cpu.flags.zf)
    {
        goto L_0x00428cf8;
    }
L_0x00428cdd:
    // 00428cdd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428cdf  e89cfeffff             -call 0x428b80
    cpu.esp -= 4;
    sub_428b80(app, cpu);
    // 00428ce4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00428ce6  7502                   -jne 0x428cea
    if (!cpu.flags.zf)
    {
        goto L_0x00428cea;
    }
    // 00428ce8  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00428cea:
    // 00428cea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00428cec  7402                   -je 0x428cf0
    if (cpu.flags.zf)
    {
        goto L_0x00428cf0;
    }
    // 00428cee  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00428cf0:
    // 00428cf0  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00428cf2  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00428cf4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00428cf6  75e5                   -jne 0x428cdd
    if (!cpu.flags.zf)
    {
        goto L_0x00428cdd;
    }
L_0x00428cf8:
    // 00428cf8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428cf9  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00428cfb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428cfc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428cfd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428d00  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428d03  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428d04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428d05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428d06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428d07  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00428d09  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00428d0b  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00428d0d  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00428d0f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00428d11  742c                   -je 0x428d3f
    if (cpu.flags.zf)
    {
        goto L_0x00428d3f;
    }
L_0x00428d13:
    // 00428d13  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00428d16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428d18  7504                   -jne 0x428d1e
    if (!cpu.flags.zf)
    {
        goto L_0x00428d1e;
    }
    // 00428d1a  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00428d1c  eb1b                   -jmp 0x428d39
    goto L_0x00428d39;
L_0x00428d1e:
    // 00428d1e  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00428d20  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428d22  e8c9000000             -call 0x428df0
    cpu.esp -= 4;
    sub_428df0(app, cpu);
    // 00428d27  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428d29  e852feffff             -call 0x428b80
    cpu.esp -= 4;
    sub_428b80(app, cpu);
    // 00428d2e  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428d30  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428d32  e809f7ffff             -call 0x428440
    cpu.esp -= 4;
    sub_428440(app, cpu);
    // 00428d37  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00428d39:
    // 00428d39  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00428d3b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00428d3d  75d4                   -jne 0x428d13
    if (!cpu.flags.zf)
    {
        goto L_0x00428d13;
    }
L_0x00428d3f:
    // 00428d3f  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00428d41  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00428d43  e8a8000000             -call 0x428df0
    cpu.esp -= 4;
    sub_428df0(app, cpu);
    // 00428d48  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00428d4a  e831feffff             -call 0x428b80
    cpu.esp -= 4;
    sub_428b80(app, cpu);
    // 00428d4f  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00428d51  e8caf5ffff             -call 0x428320
    cpu.esp -= 4;
    sub_428320(app, cpu);
    // 00428d56  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00428d5a  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 00428d5e  d9542410               -fst dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    // 00428d62  d81dbc784800           -fcomp dword ptr [0x4878bc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749500) /* 0x4878bc */)));
    cpu.fpu.pop();
    // 00428d68  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428d6a  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00428d6f  755b                   -jne 0x428dcc
    if (!cpu.flags.zf)
    {
        goto L_0x00428dcc;
    }
    // 00428d71  e80a080000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 00428d76  83f803                 +cmp eax, 3
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
    // 00428d79  7551                   -jne 0x428dcc
    if (!cpu.flags.zf)
    {
        goto L_0x00428dcc;
    }
    // 00428d7b  d94308                 -fld dword ptr [ebx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 00428d7e  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00428d84  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428d86  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00428d89  7b41                   -jnp 0x428dcc
    if (!cpu.flags.pf)
    {
        goto L_0x00428dcc;
    }
    // 00428d8b  a190d34a00             -mov eax, dword ptr [0x4ad390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903824) /* 0x4ad390 */);
    // 00428d90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428d92  7538                   -jne 0x428dcc
    if (!cpu.flags.zf)
    {
        goto L_0x00428dcc;
    }
    // 00428d94  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00428d96  ba602d4900             -mov edx, 0x492d60
    cpu.edx = 4795744 /*0x492d60*/;
    // 00428d9b  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00428d9f  c744241800000000       -mov dword ptr [esp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00428da7  e8a45cffff             -call 0x41ea50
    cpu.esp -= 4;
    sub_41ea50(app, cpu);
    // 00428dac  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00428db0  e8dbdf0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00428db5  a35cd44a00             -mov dword ptr [0x4ad45c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904028) /* 0x4ad45c */) = cpu.eax;
    // 00428dba  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00428dbd  83c0ec                 +add eax, -0x14
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-20 /*-0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00428dc0  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00428dc3  7907                   -jns 0x428dcc
    if (!cpu.flags.sf)
    {
        goto L_0x00428dcc;
    }
    // 00428dc5  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x00428dcc:
    // 00428dcc  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00428dce  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428dd0  e86bf6ffff             -call 0x428440
    cpu.esp -= 4;
    sub_428440(app, cpu);
    // 00428dd5  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00428dd7  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428dd9  e8d2f7ffff             -call 0x4285b0
    cpu.esp -= 4;
    sub_4285b0(app, cpu);
    // 00428dde  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00428de0  e87bf2ffff             -call 0x428060
    cpu.esp -= 4;
    sub_428060(app, cpu);
    // 00428de5  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00428de7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428de8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428de9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428dea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428deb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428dee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428df0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00428df2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428df3  740e                   -je 0x428e03
    if (cpu.flags.zf)
    {
        goto L_0x00428e03;
    }
    // 00428df5  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
L_0x00428df8:
    // 00428df8  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428dfb  7419                   -je 0x428e16
    if (cpu.flags.zf)
    {
        goto L_0x00428e16;
    }
    // 00428dfd  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00428dff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00428e01  75f5                   -jne 0x428df8
    if (!cpu.flags.zf)
    {
        goto L_0x00428df8;
    }
L_0x00428e03:
    // 00428e03  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00428e06  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428e07  6878414900             -push 0x494178
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800888 /*0x494178*/;
    cpu.esp -= 4;
    // 00428e0c  e8ffbdffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00428e11  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428e14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428e15  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428e16:
    // 00428e16  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00428e19  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00428e1f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428e21  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00428e24  7b0b                   -jnp 0x428e31
    if (!cpu.flags.pf)
    {
        goto L_0x00428e31;
    }
    // 00428e26  d94108                 +fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 00428e29  d84208                 +fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 00428e2c  d95908                 +fstp dword ptr [ecx + 8]
    app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00428e2f  eb07                   -jmp 0x428e38
    goto L_0x00428e38;
L_0x00428e31:
    // 00428e31  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00428e38:
    // 00428e38  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00428e3b  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00428e3e  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00428e40  89710c                 -mov dword ptr [ecx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00428e43  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00428e46  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00428e49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428e4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_428e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428e50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428e51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428e52  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00428e54  e827070000             -call 0x429580
    cpu.esp -= 4;
    sub_429580(app, cpu);
    // 00428e59  a360125200             -mov dword ptr [0x521260], eax
    app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */) = cpu.eax;
    // 00428e5e  e88d060000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 00428e63  a364125200             -mov dword ptr [0x521264], eax
    app->getMemory<x86::reg32>(x86::reg32(5378660) /* 0x521264 */) = cpu.eax;
    // 00428e68  a160125200             -mov eax, dword ptr [0x521260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */);
    // 00428e6d  48                     -dec eax
    (cpu.eax)--;
    // 00428e6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428e70  7d07                   -jge 0x428e79
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00428e79;
    }
    // 00428e72  83f802                 +cmp eax, 2
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
    // 00428e75  7e02                   -jle 0x428e79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00428e79;
    }
    // 00428e77  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00428e79:
    // 00428e79  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00428e7c  8db060125200           -lea esi, [eax + 0x521260]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(5378656) /* 0x521260 */);
    // 00428e82  8b80fc125200           -mov eax, dword ptr [eax + 0x5212fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5378812) /* 0x5212fc */);
    // 00428e88  83f801                 +cmp eax, 1
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
    // 00428e8b  751d                   -jne 0x428eaa
    if (!cpu.flags.zf)
    {
        goto L_0x00428eaa;
    }
    // 00428e8d  8b868c000000           -mov eax, dword ptr [esi + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00428e93  3bf8                   +cmp edi, eax
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
    // 00428e95  7c13                   -jl 0x428eaa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428eaa;
    }
    // 00428e97  756b                   -jne 0x428f04
    if (!cpu.flags.zf)
    {
        goto L_0x00428f04;
    }
    // 00428e99  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00428e9d  d89e88000000           -fcomp dword ptr [esi + 0x88]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(136) /* 0x88 */)));
    cpu.fpu.pop();
    // 00428ea3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00428ea5  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00428ea8  7a5a                   -jp 0x428f04
    if (cpu.flags.pf)
    {
        goto L_0x00428f04;
    }
L_0x00428eaa:
    // 00428eaa  a16c125200             -mov eax, dword ptr [0x52126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 00428eaf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428eb1  7423                   -je 0x428ed6
    if (cpu.flags.zf)
    {
        goto L_0x00428ed6;
    }
    // 00428eb3  68cc414900             -push 0x4941cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800972 /*0x4941cc*/;
    cpu.esp -= 4;
    // 00428eb8  e8fade0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00428ebd  8b0d6c125200           -mov ecx, dword ptr [0x52126c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 00428ec3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428ec4  e8ebe40400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00428ec9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428ecc  c7056c12520000000000   -mov dword ptr [0x52126c], 0
    app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */) = 0 /*0x0*/;
L_0x00428ed6:
    // 00428ed6  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00428eda  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428edc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00428edd  e88ef6ffff             -call 0x428570
    cpu.esp -= 4;
    sub_428570(app, cpu);
    // 00428ee2  a36c125200             -mov dword ptr [0x52126c], eax
    app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */) = cpu.eax;
    // 00428ee7  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00428eee  a160125200             -mov eax, dword ptr [0x521260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */);
    // 00428ef3  8b156c125200           -mov edx, dword ptr [0x52126c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 00428ef9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428efa  b9e0125200             -mov ecx, 0x5212e0
    cpu.ecx = 5378784 /*0x5212e0*/;
    // 00428eff  e89c060000             -call 0x4295a0
    cpu.esp -= 4;
    sub_4295a0(app, cpu);
L_0x00428f04:
    // 00428f04  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 00428f0e  8b0d60125200           -mov ecx, dword ptr [0x521260]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378656) /* 0x521260 */);
    // 00428f14  e8d7edfeff             -call 0x417cf0
    cpu.esp -= 4;
    sub_417cf0(app, cpu);
    // 00428f19  b9e0125200             -mov ecx, 0x5212e0
    cpu.ecx = 5378784 /*0x5212e0*/;
    // 00428f1e  e8fd060000             -call 0x429620
    cpu.esp -= 4;
    sub_429620(app, cpu);
    // 00428f23  8b0d40135200           -mov ecx, dword ptr [0x521340]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378880) /* 0x521340 */);
    // 00428f29  d91d14125200           -fstp dword ptr [0x521214]
    app->getMemory<float>(x86::reg32(5378580) /* 0x521214 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00428f2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428f30  68b0414900             -push 0x4941b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800944 /*0x4941b0*/;
    cpu.esp -= 4;
    // 00428f35  e87dde0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00428f3a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428f3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428f3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428f3f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_428f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428f50  81ec84010000           -sub esp, 0x184
    (cpu.esp) -= x86::reg32(x86::sreg32(388 /*0x184*/));
    // 00428f56  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428f57  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428f58  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00428f5a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428f5b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428f5c  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00428f5e  e83aee0400             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 00428f63  8b842498010000         -mov eax, dword ptr [esp + 0x198]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 00428f6a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428f6d  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00428f6f  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00428f71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428f72  e859f6ffff             -call 0x4285d0
    cpu.esp -= 4;
    sub_4285d0(app, cpu);
    // 00428f77  6818424900             -push 0x494218
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801048 /*0x494218*/;
    cpu.esp -= 4;
    // 00428f7c  e83fbe0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428f81  8b8c249c010000         -mov ecx, dword ptr [esp + 0x19c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(412) /* 0x19c */);
    // 00428f88  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00428f8c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428f8d  6830414900             -push 0x494130
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800816 /*0x494130*/;
    cpu.esp -= 4;
    // 00428f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00428f93  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00428f95  e85ede0400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00428f9a  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00428f9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428f9f  e81cbe0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428fa4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428fa5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428fa6  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00428faa  6818414900             -push 0x494118
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800792 /*0x494118*/;
    cpu.esp -= 4;
    // 00428faf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428fb0  e809ef0400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 00428fb5  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00428fb8  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00428fbc  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00428fbe  e8dd4efeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00428fc3  8d34ad00000000         -lea esi, [ebp*4]
    cpu.esi = x86::reg32(cpu.ebp * 4);
    // 00428fca  6810424900             -push 0x494210
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801040 /*0x494210*/;
    cpu.esp -= 4;
    // 00428fcf  e8ecbd0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428fd4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428fd7  8d4c7302               -lea ecx, [ebx + esi*2 + 2]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */ + cpu.esi * 2);
    // 00428fdb  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428fdd  e8be4efeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00428fe2  68f0404900             -push 0x4940f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800752 /*0x4940f0*/;
    cpu.esp -= 4;
    // 00428fe7  e8d4bd0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00428fec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428fef  8d4c732c               -lea ecx, [ebx + esi*2 + 0x2c]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(44) /* 0x2c */ + cpu.esi * 2);
    // 00428ff3  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428ff5  e8a64efeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00428ffa  68e0404900             -push 0x4940e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800736 /*0x4940e0*/;
    cpu.esp -= 4;
    // 00428fff  e8bcbd0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00429004  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429007  8d4c733c               -lea ecx, [ebx + esi*2 + 0x3c]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(60) /* 0x3c */ + cpu.esi * 2);
    // 0042900b  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042900d  e88e4efeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00429012  6804424900             -push 0x494204
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801028 /*0x494204*/;
    cpu.esp -= 4;
    // 00429017  e8a4bd0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0042901c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042901f  8d4c734e               -lea ecx, [ebx + esi*2 + 0x4e]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(78) /* 0x4e */ + cpu.esi * 2);
    // 00429023  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00429025  e8764efeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042902a  8b3574125200           -mov esi, dword ptr [0x521274]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5378676) /* 0x521274 */);
    // 00429030  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429032  0f8453010000           -je 0x42918b
    if (cpu.flags.zf)
    {
        goto L_0x0042918b;
    }
    // 00429038  8d446d00               -lea eax, [ebp + ebp*2]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 2);
    // 0042903c  8d546d00               -lea edx, [ebp + ebp*2]
    cpu.edx = x86::reg32(cpu.ebp + cpu.ebp * 2);
    // 00429040  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00429042  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429043  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00429047  8d7c932c               -lea edi, [ebx + edx*4 + 0x2c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(44) /* 0x2c */ + cpu.edx * 4);
L_0x0042904b:
    // 0042904b  8b84249c010000         -mov eax, dword ptr [esp + 0x19c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(412) /* 0x19c */);
    // 00429052  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00429055  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429056  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429057  68e8414900             -push 0x4941e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801000 /*0x4941e8*/;
    cpu.esp -= 4;
    // 0042905c  e856dd0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429061  8b9424a8010000         -mov edx, dword ptr [esp + 0x1a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(424) /* 0x1a8 */);
    // 00429068  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0042906b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042906e  3bc2                   +cmp eax, edx
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
    // 00429070  0f85f7000000           -jne 0x42916d
    if (!cpu.flags.zf)
    {
        goto L_0x0042916d;
    }
    // 00429076  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00429079  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042907b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042907d  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00429081  e88af9ffff             -call 0x428a10
    cpu.esp -= 4;
    sub_428a10(app, cpu);
    // 00429086  8d4fd4                 -lea ecx, [edi - 0x2c]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-44) /* -0x2c */);
    // 00429089  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0042908d  e80e4efeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00429092  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00429095  8d4c2454               -lea ecx, [esp + 0x54]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00429099  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0042909b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042909d  e86ef9ffff             -call 0x428a10
    cpu.esp -= 4;
    sub_428a10(app, cpu);
    // 004290a2  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004290a6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004290aa  03c5                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004290ac  8d4c43fc               -lea ecx, [ebx + eax*2 - 4]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 2);
    // 004290b0  e8eb4dfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004290b5  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004290b8  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004290bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004290bd  6848414900             -push 0x494148
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800840 /*0x494148*/;
    cpu.esp -= 4;
    // 004290c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004290c3  e830dd0400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004290c8  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004290cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004290cd  e8eebc0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004290d2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004290d5  8d4fd6                 -lea ecx, [edi - 0x2a]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-42) /* -0x2a */);
    // 004290d8  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004290da  e8c14dfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004290df  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004290e2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004290e3  8d8c2458010000         -lea ecx, [esp + 0x158]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(344) /* 0x158 */);
    // 004290ea  e8a1edffff             -call 0x427e90
    cpu.esp -= 4;
    sub_427e90(app, cpu);
    // 004290ef  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004290f1  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004290f3  e8a84dfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004290f8  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004290fb  8d442454               -lea eax, [esp + 0x54]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004290ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429100  6898404900             -push 0x494098
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800664 /*0x494098*/;
    cpu.esp -= 4;
    // 00429105  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429106  e8b3ed0400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 0042910b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042910e  8d4f16                 -lea ecx, [edi + 0x16]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 00429111  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00429115  e8864dfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042911a  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0042911d  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00429123  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00429125  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00429128  7a11                   -jp 0x42913b
    if (cpu.flags.pf)
    {
        goto L_0x0042913b;
    }
    // 0042912a  68a0404900             -push 0x4940a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800672 /*0x4940a0*/;
    cpu.esp -= 4;
    // 0042912f  e88cbc0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00429134  83c404                 +add esp, 4
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
    // 00429137  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00429139  eb1a                   -jmp 0x429155
    goto L_0x00429155;
L_0x0042913b:
    // 0042913b  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0042913e  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00429142  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429143  6898404900             -push 0x494098
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800664 /*0x494098*/;
    cpu.esp -= 4;
    // 00429148  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429149  e870ed0400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 0042914e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00429151  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
L_0x00429155:
    // 00429155  8d4f26                 -lea ecx, [edi + 0x26]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(38) /* 0x26 */);
    // 00429158  e8434dfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042915d  8d442d00               -lea eax, [ebp + ebp]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 1);
    // 00429161  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00429163  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00429167  03c5                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00429169  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042916d:
    // 0042916d  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0042916f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429171  0f85d4feffff           -jne 0x42904b
    if (!cpu.flags.zf)
    {
        goto L_0x0042904b;
    }
    // 00429177  a16c125200             -mov eax, dword ptr [0x52126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 0042917c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042917d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042917f  740a                   -je 0x42918b
    if (cpu.flags.zf)
    {
        goto L_0x0042918b;
    }
    // 00429181  b960125200             -mov ecx, 0x521260
    cpu.ecx = 5378656 /*0x521260*/;
    // 00429186  e8c5040000             -call 0x429650
    cpu.esp -= 4;
    sub_429650(app, cpu);
L_0x0042918b:
    // 0042918b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042918c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042918d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042918e  81c484010000           -add esp, 0x184
    (cpu.esp) += x86::reg32(x86::sreg32(388 /*0x184*/));
    // 00429194  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

}
