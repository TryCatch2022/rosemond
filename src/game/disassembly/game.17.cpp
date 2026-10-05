#include "game.h"
namespace game
{

/* align: skip  */
void Application::asm_sub_46bd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bd80  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046bd83  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046bd87  e8f4a8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bd8c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bd8e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bd90  e8eba8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bd95  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bd99  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bd9b  e8e0a8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bda0  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bda4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bda6  e8d5a8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bdab  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0046bdad  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0046bdaf  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046bdb3  d84c2400               -fmul dword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp));
    // 0046bdb7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046bdbb  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046bdc1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046bdc3  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046bdc7  d84c2404               -fmul dword ptr [esp + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0046bdcb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046bdcd  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0046bdcf  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bdd2  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bdd4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046bdd7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46bde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bde0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bde2  e899a8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bde7  e8a4af0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bdec  a38c2d4a00             -mov dword ptr [0x4a2d8c], eax
    app->getMemory<x86::reg32>(x86::reg32(4861324) /* 0x4a2d8c */) = cpu.eax;
    // 0046bdf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46be00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046be00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046be01  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046be03  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046be05  e876a8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046be0a  e881af0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046be0f  83f8ff                 +cmp eax, -1
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
    // 0046be12  7505                   -jne 0x46be19
    if (!cpu.flags.zf)
    {
        goto L_0x0046be19;
    }
    // 0046be14  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046be17  eb09                   -jmp 0x46be22
    goto L_0x0046be22;
L_0x0046be19:
    // 0046be19  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046be1f  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046be22:
    // 0046be22  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046be24  e87728ffff             -call 0x45e6a0
    cpu.esp -= 4;
    sub_45e6a0(app, cpu);
    // 0046be29  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046be2c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046be2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046be31  7505                   -jne 0x46be38
    if (!cpu.flags.zf)
    {
        goto L_0x0046be38;
    }
    // 0046be33  e8684dffff             -call 0x460ba0
    cpu.esp -= 4;
    sub_460ba0(app, cpu);
L_0x0046be38:
    // 0046be38  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046be3b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046be3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046be40  7505                   -jne 0x46be47
    if (!cpu.flags.zf)
    {
        goto L_0x0046be47;
    }
    // 0046be42  e8594dffff             -call 0x460ba0
    cpu.esp -= 4;
    sub_460ba0(app, cpu);
L_0x0046be47:
    // 0046be47  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046be4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be4b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046be4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046be50  7505                   -jne 0x46be57
    if (!cpu.flags.zf)
    {
        goto L_0x0046be57;
    }
    // 0046be52  e9494dffff             -jmp 0x460ba0
    return sub_460ba0(app, cpu);
L_0x0046be57:
    // 0046be57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46be60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046be60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046be61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046be62  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046be64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046be65  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046be67  e814a8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046be6c  e81faf0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046be71  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046be73  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046be75  e806a8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046be7a  e811af0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046be7f  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046be81  83ffff                 +cmp edi, -1
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
    // 0046be84  7505                   -jne 0x46be8b
    if (!cpu.flags.zf)
    {
        goto L_0x0046be8b;
    }
    // 0046be86  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046be89  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046be8b:
    // 0046be8b  83feff                 +cmp esi, -1
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
    // 0046be8e  7505                   -jne 0x46be95
    if (!cpu.flags.zf)
    {
        goto L_0x0046be95;
    }
    // 0046be90  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046be93  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
L_0x0046be95:
    // 0046be95  83ffff                 +cmp edi, -1
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
    // 0046be98  7405                   -je 0x46be9f
    if (cpu.flags.zf)
    {
        goto L_0x0046be9f;
    }
    // 0046be9a  83feff                 +cmp esi, -1
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
    // 0046be9d  750d                   -jne 0x46beac
    if (!cpu.flags.zf)
    {
        goto L_0x0046beac;
    }
L_0x0046be9f:
    // 0046be9f  68a42f4a00             -push 0x4a2fa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861860 /*0x4a2fa4*/;
    cpu.esp -= 4;
    // 0046bea4  e8678dfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046bea9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046beac:
    // 0046beac  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046beb2  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046beb5  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046bebb  83e1bf                 +and ecx, 0xffffffbf
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/))));
    // 0046bebe  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046bec4  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bec9  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046becc  e84fe6fdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046bed1  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bed6  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0046bed9  8b14b0                 -mov edx, dword ptr [eax + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046bedc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bedd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bede  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bedf  e92c2fffff             -jmp 0x45ee10
    return sub_45ee10(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46bef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bef1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bef2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046bef4  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046bef8  e883a7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046befd  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046beff  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bf01  e87aa7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bf06  e885ae0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bf0b  83f8ff                 +cmp eax, -1
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
    // 0046bf0e  7505                   -jne 0x46bf15
    if (!cpu.flags.zf)
    {
        goto L_0x0046bf15;
    }
    // 0046bf10  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046bf13  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046bf15:
    // 0046bf15  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bf1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf1c  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046bf1f  8b82e8020000           -mov eax, dword ptr [edx + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(744) /* 0x2e8 */);
    // 0046bf25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bf27  7513                   -jne 0x46bf3c
    if (!cpu.flags.zf)
    {
        goto L_0x0046bf3c;
    }
    // 0046bf29  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046bf2d  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046bf33  c70481000080bf         -mov dword ptr [ecx + eax*4], 0xbf800000
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 3212836864 /*0xbf800000*/;
    // 0046bf3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bf3c:
    // 0046bf3c  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 0046bf3e  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046bf42  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046bf47  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bf4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46bf50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bf50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bf51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bf52  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046bf54  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bf56  e825a7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bf5b  e830ae0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bf60  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046bf62  83feff                 +cmp esi, -1
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
    // 0046bf65  7505                   -jne 0x46bf6c
    if (!cpu.flags.zf)
    {
        goto L_0x0046bf6c;
    }
    // 0046bf67  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046bf6a  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046bf6c:
    // 0046bf6c  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bf71  8b14b0                 -mov edx, dword ptr [eax + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046bf74  8b8ae8020000           -mov ecx, dword ptr [edx + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(744) /* 0x2e8 */);
    // 0046bf7a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046bf7c  740f                   -je 0x46bf8d
    if (cpu.flags.zf)
    {
        goto L_0x0046bf8d;
    }
    // 0046bf7e  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046bf80  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046bf83  e8f82effff             -call 0x45ee80
    cpu.esp -= 4;
    sub_45ee80(app, cpu);
    // 0046bf88  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
L_0x0046bf8d:
    // 0046bf8d  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046bf90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf92  8b88ec020000           -mov ecx, dword ptr [eax + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0046bf98  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046bf9a  7410                   -je 0x46bfac
    if (cpu.flags.zf)
    {
        goto L_0x0046bfac;
    }
    // 0046bf9c  80794819               +cmp byte ptr [ecx + 0x48], 0x19
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(72) /* 0x48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(25 /*0x19*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046bfa0  750a                   -jne 0x46bfac
    if (!cpu.flags.zf)
    {
        goto L_0x0046bfac;
    }
    // 0046bfa2  c780ec02000000000000   -mov dword ptr [eax + 0x2ec], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */) = 0 /*0x0*/;
L_0x0046bfac:
    // 0046bfac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46bfb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bfb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bfb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bfb2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bfb4  e8c7a6ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bfb9  e8d2ad0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bfbe  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046bfc2  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046bfc4  e8b7a6ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bfc9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046bfcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bfcc  7408                   -je 0x46bfd6
    if (cpu.flags.zf)
    {
        goto L_0x0046bfd6;
    }
    // 0046bfce  d91d14d24900           -fstp dword ptr [0x49d214]
    app->getMemory<float>(x86::reg32(4837908) /* 0x49d214 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bfd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bfd5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bfd6:
    // 0046bfd6  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046bfda  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046bfe0  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bfe2  d90514d24900           -fld dword ptr [0x49d214]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837908) /* 0x49d214 */)));
    // 0046bfe8  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bfeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bfec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46bff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bff1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bff2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046bff3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bff4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046bff6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bff7  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0046bffb  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046bffe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c000  7516                   -jne 0x46c018
    if (!cpu.flags.zf)
    {
        goto L_0x0046c018;
    }
    // 0046c002  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046c004  e89726ffff             -call 0x45e6a0
    cpu.esp -= 4;
    sub_45e6a0(app, cpu);
    // 0046c009  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 0046c00f  80cc40                 -or ah, 0x40
    cpu.ah |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0046c012  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
L_0x0046c018:
    // 0046c018  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046c01b  b3fa                   -mov bl, 0xfa
    cpu.bl = 250 /*0xfa*/;
    // 0046c01d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c01f  7479                   -je 0x46c09a
    if (cpu.flags.zf)
    {
        goto L_0x0046c09a;
    }
    // 0046c021  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046c024  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046c026  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046c028  7e70                   -jle 0x46c09a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c09a;
    }
L_0x0046c02a:
    // 0046c02a  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046c02d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046c02f  8b34a8                 -mov esi, dword ptr [eax + ebp*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 4);
    // 0046c032  8a4614                 -mov al, byte ptr [esi + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c035  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046c037  7650                   -jbe 0x46c089
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046c089;
    }
L_0x0046c039:
    // 0046c039  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c03c  d944f904               -fld dword ptr [ecx + edi*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8)));
    // 0046c040  dc2598744800           -fsub qword ptr [0x487498]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4748440) /* 0x487498 */));
    // 0046c046  8d44f904               -lea eax, [ecx + edi*8 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 0046c04a  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c04c  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c04f  885e18                 -mov byte ptr [esi + 0x18], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.bl;
    // 0046c052  d944fa04               -fld dword ptr [edx + edi*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8)));
    // 0046c056  d81d90744800           -fcomp dword ptr [0x487490]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748432) /* 0x487490 */)));
    cpu.fpu.pop();
    // 0046c05c  8d4cfa04               -lea ecx, [edx + edi*8 + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 0046c060  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c062  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0046c067  740f                   -je 0x46c078
    if (cpu.flags.zf)
    {
        goto L_0x0046c078;
    }
    // 0046c069  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0046c06b  d81df4724800           -fcomp dword ptr [0x4872f4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748020) /* 0x4872f4 */)));
    cpu.fpu.pop();
    // 0046c071  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c073  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0046c076  7a07                   -jp 0x46c07f
    if (cpu.flags.pf)
    {
        goto L_0x0046c07f;
    }
L_0x0046c078:
    // 0046c078  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046c07a  e86144ffff             -call 0x4604e0
    cpu.esp -= 4;
    sub_4604e0(app, cpu);
L_0x0046c07f:
    // 0046c07f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c081  47                     -inc edi
    (cpu.edi)++;
    // 0046c082  8a4614                 -mov al, byte ptr [esi + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c085  3bf8                   +cmp edi, eax
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
    // 0046c087  7cb0                   -jl 0x46c039
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c039;
    }
L_0x0046c089:
    // 0046c089  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c08d  45                     -inc ebp
    (cpu.ebp)++;
    // 0046c08e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046c091  3b6818                 +cmp ebp, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c094  7c94                   -jl 0x46c02a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c02a;
    }
    // 0046c096  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0046c09a:
    // 0046c09a  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046c09d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c09f  7479                   -je 0x46c11a
    if (cpu.flags.zf)
    {
        goto L_0x0046c11a;
    }
    // 0046c0a1  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046c0a4  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046c0a6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046c0a8  7e70                   -jle 0x46c11a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c11a;
    }
L_0x0046c0aa:
    // 0046c0aa  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046c0ad  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046c0af  8b34aa                 -mov esi, dword ptr [edx + ebp*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.ebp * 4);
    // 0046c0b2  8a4614                 -mov al, byte ptr [esi + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c0b5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046c0b7  7650                   -jbe 0x46c109
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046c109;
    }
L_0x0046c0b9:
    // 0046c0b9  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c0bc  d944f804               -fld dword ptr [eax + edi*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 8)));
    // 0046c0c0  dc2598744800           -fsub qword ptr [0x487498]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4748440) /* 0x487498 */));
    // 0046c0c6  8d44f804               -lea eax, [eax + edi*8 + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 0046c0ca  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c0cc  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c0cf  885e18                 -mov byte ptr [esi + 0x18], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.bl;
    // 0046c0d2  d944f904               -fld dword ptr [ecx + edi*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8)));
    // 0046c0d6  d81d90744800           -fcomp dword ptr [0x487490]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748432) /* 0x487490 */)));
    cpu.fpu.pop();
    // 0046c0dc  8d4cf904               -lea ecx, [ecx + edi*8 + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 0046c0e0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c0e2  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0046c0e7  740f                   -je 0x46c0f8
    if (cpu.flags.zf)
    {
        goto L_0x0046c0f8;
    }
    // 0046c0e9  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0046c0eb  d81df4724800           -fcomp dword ptr [0x4872f4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748020) /* 0x4872f4 */)));
    cpu.fpu.pop();
    // 0046c0f1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c0f3  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0046c0f6  7a07                   -jp 0x46c0ff
    if (cpu.flags.pf)
    {
        goto L_0x0046c0ff;
    }
L_0x0046c0f8:
    // 0046c0f8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046c0fa  e8e143ffff             -call 0x4604e0
    cpu.esp -= 4;
    sub_4604e0(app, cpu);
L_0x0046c0ff:
    // 0046c0ff  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c101  47                     -inc edi
    (cpu.edi)++;
    // 0046c102  8a5614                 -mov dl, byte ptr [esi + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c105  3bfa                   +cmp edi, edx
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
    // 0046c107  7cb0                   -jl 0x46c0b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c0b9;
    }
L_0x0046c109:
    // 0046c109  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c10d  45                     -inc ebp
    (cpu.ebp)++;
    // 0046c10e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046c111  3b6818                 +cmp ebp, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c114  7c94                   -jl 0x46c0aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c0aa;
    }
    // 0046c116  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0046c11a:
    // 0046c11a  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c11d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c11f  7475                   -je 0x46c196
    if (cpu.flags.zf)
    {
        goto L_0x0046c196;
    }
    // 0046c121  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046c124  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046c126  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046c128  7e6c                   -jle 0x46c196
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c196;
    }
L_0x0046c12a:
    // 0046c12a  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046c12d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046c12f  8b34a9                 -mov esi, dword ptr [ecx + ebp*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 0046c132  8a4614                 -mov al, byte ptr [esi + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c135  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046c137  7650                   -jbe 0x46c189
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046c189;
    }
L_0x0046c139:
    // 0046c139  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c13c  d944fa04               -fld dword ptr [edx + edi*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8)));
    // 0046c140  dc2598744800           -fsub qword ptr [0x487498]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4748440) /* 0x487498 */));
    // 0046c146  8d44fa04               -lea eax, [edx + edi*8 + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 0046c14a  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c14c  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c14f  885e18                 -mov byte ptr [esi + 0x18], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.bl;
    // 0046c152  d944f804               -fld dword ptr [eax + edi*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 8)));
    // 0046c156  d81d90744800           -fcomp dword ptr [0x487490]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748432) /* 0x487490 */)));
    cpu.fpu.pop();
    // 0046c15c  8d4cf804               -lea ecx, [eax + edi*8 + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 0046c160  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c162  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0046c167  740f                   -je 0x46c178
    if (cpu.flags.zf)
    {
        goto L_0x0046c178;
    }
    // 0046c169  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0046c16b  d81df4724800           -fcomp dword ptr [0x4872f4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748020) /* 0x4872f4 */)));
    cpu.fpu.pop();
    // 0046c171  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c173  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0046c176  7a07                   -jp 0x46c17f
    if (cpu.flags.pf)
    {
        goto L_0x0046c17f;
    }
L_0x0046c178:
    // 0046c178  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046c17a  e86143ffff             -call 0x4604e0
    cpu.esp -= 4;
    sub_4604e0(app, cpu);
L_0x0046c17f:
    // 0046c17f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c181  47                     -inc edi
    (cpu.edi)++;
    // 0046c182  8a4e14                 -mov cl, byte ptr [esi + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c185  3bf9                   +cmp edi, ecx
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
    // 0046c187  7cb0                   -jl 0x46c139
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c139;
    }
L_0x0046c189:
    // 0046c189  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c18d  45                     -inc ebp
    (cpu.ebp)++;
    // 0046c18e  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046c191  3b6818                 +cmp ebp, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c194  7c94                   -jl 0x46c12a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c12a;
    }
L_0x0046c196:
    // 0046c196  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c197  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c198  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c199  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c19a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c19b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c1a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c1a1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c1a3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c1a5  e8d6a4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c1aa  e8e1ab0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c1af  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c1b5  83f8ff                 +cmp eax, -1
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
    // 0046c1b8  7505                   -jne 0x46c1bf
    if (!cpu.flags.zf)
    {
        goto L_0x0046c1bf;
    }
    // 0046c1ba  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c1bd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046c1bf:
    // 0046c1bf  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046c1c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c1c3  c78210030000f0bf4600   -mov dword ptr [edx + 0x310], 0x46bff0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(784) /* 0x310 */) = 4636656 /*0x46bff0*/;
    // 0046c1cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c1d0  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046c1d6  e825a5ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c1db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c1dc  6880ee5100             -push 0x51ee80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5369472 /*0x51ee80*/;
    cpu.esp -= 4;
    // 0046c1e1  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046c1e5  68842d4a00             -push 0x4a2d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861316 /*0x4a2d84*/;
    cpu.esp -= 4;
    // 0046c1ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c1eb  e808ac0000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0046c1f0  68c82f4a00             -push 0x4a2fc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861896 /*0x4a2fc8*/;
    cpu.esp -= 4;
    // 0046c1f5  e8168afbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046c1fa  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0046c200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c210  68e42f4a00             -push 0x4a2fe4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861924 /*0x4a2fe4*/;
    cpu.esp -= 4;
    // 0046c215  e8f689fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046c21a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c21b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c220  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c221  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c222  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c224  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c226  e855a4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c22b  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c22f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c233  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c236  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c237  e80489feff             -call 0x454b40
    cpu.esp -= 4;
    sub_454b40(app, cpu);
    // 0046c23c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c23d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c23e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c240  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c241  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c243  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c245  e836a4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c24a  e841ab0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c24f  83f8ff                 +cmp eax, -1
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
    // 0046c252  7505                   -jne 0x46c259
    if (!cpu.flags.zf)
    {
        goto L_0x0046c259;
    }
    // 0046c254  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c257  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046c259:
    // 0046c259  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c25f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c260  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046c263  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c265  8d90cc000000           -lea edx, [eax + 0xcc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(204) /* 0xcc */);
    // 0046c26b  e9d071feff             -jmp 0x453440
    return sub_453440(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46c270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c270  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046c276  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c277  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c278  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c279  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c27a  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046c27c  e87fa4ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c281  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c283  e878a4ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c288  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c28a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046c28c  e8efa3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c291  e8faaa0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c296  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046c298  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c29b  7505                   -jne 0x46c2a2
    if (!cpu.flags.zf)
    {
        goto L_0x0046c2a2;
    }
    // 0046c29d  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046c2a0  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046c2a2:
    // 0046c2a2  680cc94800             -push 0x48c90c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770060 /*0x48c90c*/;
    cpu.esp -= 4;
    // 0046c2a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c2a8  e803890100             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0046c2ad  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c2b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c2b2  743b                   -je 0x46c2ef
    if (cpu.flags.zf)
    {
        goto L_0x0046c2ef;
    }
    // 0046c2b4  680cc94800             -push 0x48c90c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770060 /*0x48c90c*/;
    cpu.esp -= 4;
    // 0046c2b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c2ba  e8f1880100             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0046c2bf  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c2c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c2c4  7429                   -je 0x46c2ef
    if (cpu.flags.zf)
    {
        goto L_0x0046c2ef;
    }
    // 0046c2c6  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c2ca  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c2cc  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046c2ce:
    // 0046c2ce  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046c2d0  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0046c2d3  40                     -inc eax
    (cpu.eax)++;
    // 0046c2d4  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0046c2d6  75f6                   -jne 0x46c2ce
    if (!cpu.flags.zf)
    {
        goto L_0x0046c2ce;
    }
    // 0046c2d8  8d942490000000         -lea edx, [esp + 0x90]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0046c2df  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046c2e1  2bd3                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0046c2e3:
    // 0046c2e3  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046c2e5  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0046c2e8  40                     -inc eax
    (cpu.eax)++;
    // 0046c2e9  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0046c2eb  75f6                   -jne 0x46c2e3
    if (!cpu.flags.zf)
    {
        goto L_0x0046c2e3;
    }
    // 0046c2ed  eb58                   -jmp 0x46c347
    goto L_0x0046c347;
L_0x0046c2ef:
    // 0046c2ef  833ddc28490013         +cmp dword ptr [0x4928dc], 0x13
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c2f6  7f7a                   -jg 0x46c372
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046c372;
    }
    // 0046c2f8  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c2fe  8b14a9                 -mov edx, dword ptr [ecx + ebp*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 0046c301  8b8aec020000           -mov ecx, dword ptr [edx + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(748) /* 0x2ec */);
    // 0046c307  e80491f9ff             -call 0x405410
    cpu.esp -= 4;
    sub_405410(app, cpu);
    // 0046c30c  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046c30e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046c310  750d                   -jne 0x46c31f
    if (!cpu.flags.zf)
    {
        goto L_0x0046c31f;
    }
    // 0046c312  6810304a00             -push 0x4a3010
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861968 /*0x4a3010*/;
    cpu.esp -= 4;
    // 0046c317  e8f488fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046c31c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046c31f:
    // 0046c31f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c321  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0046c328  6804304a00             -push 0x4a3004
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861956 /*0x4a3004*/;
    cpu.esp -= 4;
    // 0046c32d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c32e  e8c5aa0000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0046c333  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c334  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c335  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046c339  6804304a00             -push 0x4a3004
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861956 /*0x4a3004*/;
    cpu.esp -= 4;
    // 0046c33e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c33f  e8b4aa0000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0046c344  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0046c347:
    // 0046c347  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c349  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c34d  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046c353  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c355  8d8c2490000000         -lea ecx, [esp + 0x90]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0046c35c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c35d  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046c363  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c365  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c36a  8b0ca8                 -mov ecx, dword ptr [eax + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 4);
    // 0046c36d  e80e000000             -call 0x46c380
    cpu.esp -= 4;
    sub_46c380(app, cpu);
L_0x0046c372:
    // 0046c372  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c373  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c374  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c375  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c376  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046c37c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c380  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046c383  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c384  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c385  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c387  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c388  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046c38a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046c38c  e80f23ffff             -call 0x45e6a0
    cpu.esp -= 4;
    sub_45e6a0(app, cpu);
    // 0046c391  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 0046c397  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046c39a  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c39d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046c3a1  80cc40                 -or ah, 0x40
    cpu.ah |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0046c3a4  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0046c3a8  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 0046c3ae  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046c3b1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046c3b5  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046c3b9  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046c3bb:
    // 0046c3bb  8b54b40c               -mov edx, dword ptr [esp + esi*4 + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */ + cpu.esi * 4);
    // 0046c3bf  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c3c1  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046c3c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c3c6  7e16                   -jle 0x46c3de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c3de;
    }
L_0x0046c3c8:
    // 0046c3c8  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0046c3cb  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046c3ce  397808                 +cmp dword ptr [eax + 8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c3d1  7503                   -jne 0x46c3d6
    if (!cpu.flags.zf)
    {
        goto L_0x0046c3d6;
    }
    // 0046c3d3  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
L_0x0046c3d6:
    // 0046c3d6  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046c3d9  41                     -inc ecx
    (cpu.ecx)++;
    // 0046c3da  3bc8                   +cmp ecx, eax
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
    // 0046c3dc  7cea                   -jl 0x46c3c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c3c8;
    }
L_0x0046c3de:
    // 0046c3de  46                     -inc esi
    (cpu.esi)++;
    // 0046c3df  83fe03                 +cmp esi, 3
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
    // 0046c3e2  7cd7                   -jl 0x46c3bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c3bb;
    }
    // 0046c3e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3e7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046c3ea  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_46c3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c3f0  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046c3f6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c3f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c3f8  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046c3fa  8b8fec020000           -mov ecx, dword ptr [edi + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(748) /* 0x2ec */);
    // 0046c400  e80b90f9ff             -call 0x405410
    cpu.esp -= 4;
    sub_405410(app, cpu);
    // 0046c405  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c407  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046c409  750d                   -jne 0x46c418
    if (!cpu.flags.zf)
    {
        goto L_0x0046c418;
    }
    // 0046c40b  6810304a00             -push 0x4a3010
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861968 /*0x4a3010*/;
    cpu.esp -= 4;
    // 0046c410  e8fb87fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046c415  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046c418:
    // 0046c418  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c419  684cbb4a00             -push 0x4abb4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4897612 /*0x4abb4c*/;
    cpu.esp -= 4;
    // 0046c41e  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0046c425  6804304a00             -push 0x4a3004
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861956 /*0x4a3004*/;
    cpu.esp -= 4;
    // 0046c42a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c42b  e8c8a90000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0046c430  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c431  680cc94800             -push 0x48c90c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770060 /*0x48c90c*/;
    cpu.esp -= 4;
    // 0046c436  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046c43a  6804304a00             -push 0x4a3004
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861956 /*0x4a3004*/;
    cpu.esp -= 4;
    // 0046c43f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c440  e8b3a90000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0046c445  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046c448  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c44a  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046c44e  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046c454  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c456  8d8c2488000000         -lea ecx, [esp + 0x88]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0046c45d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c45e  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046c464  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c466  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046c468  e813ffffff             -call 0x46c380
    cpu.esp -= 4;
    sub_46c380(app, cpu);
    // 0046c46d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c46e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c46f  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046c475  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c480  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c483  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c484  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c485  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c487  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c488  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c48a  e8f1a1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c48f  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c493  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c495  e8e6a1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c49a  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c49e  e85da2ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c4a3  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046c4a5  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046c4a8  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046c4aa  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046c4ac  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0046c4ae  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046c4b0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046c4b1  7505                   -jne 0x46c4b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046c4b8;
    }
    // 0046c4b3  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c4b6  eb02                   -jmp 0x46c4ba
    goto L_0x0046c4ba;
L_0x0046c4b8:
    // 0046c4b8  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046c4ba:
    // 0046c4ba  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046c4be  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0046c4c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c4c3  e8c8a80000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c4c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c4c9  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046c4cb  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046c4cd  e82eb8f9ff             -call 0x407d00
    cpu.esp -= 4;
    sub_407d00(app, cpu);
    // 0046c4d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4d5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c4d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c4e0  e81ba2ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c4e5  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c4e7  e9c4b6f9ff             -jmp 0x407bb0
    return sub_407bb0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46c4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c4f0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046c4f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c4f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c4f5  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046c4f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c4f8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c4fa  e881a1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c4ff  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c503  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c505  e876a1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c50a  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c50e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c510  e86ba1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c515  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c519  e8e2a1ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c51e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c520  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046c523  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046c525  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046c527  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0046c529  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046c52b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046c52c  7505                   -jne 0x46c533
    if (!cpu.flags.zf)
    {
        goto L_0x0046c533;
    }
    // 0046c52e  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046c531  eb02                   -jmp 0x46c535
    goto L_0x0046c535;
L_0x0046c533:
    // 0046c533  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046c535:
    // 0046c535  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046c539  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c53d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c53e  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c542  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c543  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c544  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046c546  e895b9f9ff             -call 0x407ee0
    cpu.esp -= 4;
    sub_407ee0(app, cpu);
    // 0046c54b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c54c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c54d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c54e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046c551  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c560  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046c563  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c564  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c565  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046c567  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c568  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c56a  e811a1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c56f  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c573  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c575  e806a1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c57a  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c57e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c580  e8fba0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c585  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c589  e872a1ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c58e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c590  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046c593  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046c595  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046c597  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0046c599  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046c59b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046c59c  7505                   -jne 0x46c5a3
    if (!cpu.flags.zf)
    {
        goto L_0x0046c5a3;
    }
    // 0046c59e  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046c5a1  eb02                   -jmp 0x46c5a5
    goto L_0x0046c5a5;
L_0x0046c5a3:
    // 0046c5a3  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046c5a5:
    // 0046c5a5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046c5a9  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c5ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c5ae  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c5b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c5b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c5b4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046c5b6  e885b9f9ff             -call 0x407f40
    cpu.esp -= 4;
    sub_407f40(app, cpu);
    // 0046c5bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c5bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c5bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c5be  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046c5c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c5d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c5d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c5d2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c5d4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c5d6  e8a5a0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c5db  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c5df  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c5e1  e89aa0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c5e6  e8a5a70000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c5eb  83f8ff                 +cmp eax, -1
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
    // 0046c5ee  7505                   -jne 0x46c5f5
    if (!cpu.flags.zf)
    {
        goto L_0x0046c5f5;
    }
    // 0046c5f0  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c5f3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046c5f5:
    // 0046c5f5  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c5fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c5fc  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046c5ff  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c603  898a54020000           -mov dword ptr [edx + 0x254], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(596) /* 0x254 */) = cpu.ecx;
    // 0046c609  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c60f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0046c612  8b80ec020000           -mov eax, dword ptr [eax + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0046c618  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c61a  7403                   -je 0x46c61f
    if (cpu.flags.zf)
    {
        goto L_0x0046c61f;
    }
    // 0046c61c  894868                 -mov dword ptr [eax + 0x68], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */) = cpu.ecx;
L_0x0046c61f:
    // 0046c61f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c620  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c630  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c631  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 0046c635  e846a0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c63a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c63c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c63e  e83da0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c643  e848a70000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c648  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046c64e  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046c651  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c657  8b8280000000           -mov eax, dword ptr [edx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0046c65d  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046c660  8b82e8020000           -mov eax, dword ptr [edx + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(744) /* 0x2e8 */);
    // 0046c666  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c668  7415                   -je 0x46c67f
    if (cpu.flags.zf)
    {
        goto L_0x0046c67f;
    }
    // 0046c66a  db80b4020000           -fild dword ptr [eax + 0x2b4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(692) /* 0x2b4 */))));
    // 0046c670  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c674  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046c67a  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c67d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c67e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c67f:
    // 0046c67f  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c683  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046c688  c70490000080bf         -mov dword ptr [eax + edx*4], 0xbf800000
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = 3212836864 /*0xbf800000*/;
    // 0046c68f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c690  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c6a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c6a1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c6a3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c6a5  e8d69fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c6aa  e8e1a60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c6af  83f8ff                 +cmp eax, -1
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
    // 0046c6b2  7511                   -jne 0x46c6c5
    if (!cpu.flags.zf)
    {
        goto L_0x0046c6c5;
    }
    // 0046c6b4  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c6b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c6b8  8b80ec020000           -mov eax, dword ptr [eax + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0046c6be  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c6c0  e9fbb3feff             -jmp 0x457ac0
    return sub_457ac0(app, cpu);
L_0x0046c6c5:
    // 0046c6c5  8b0d54845100           -mov ecx, dword ptr [0x518454]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342292) /* 0x518454 */);
    // 0046c6cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c6cc  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046c6cf  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c6d1  e9eab3feff             -jmp 0x457ac0
    return sub_457ac0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46c6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c6e0  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0046c6e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c6e4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c6e6  e8959fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c6eb  d95c2444               -fstp dword ptr [esp + 0x44]
    app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c6ef  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c6f1  e88a9fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c6f6  d95c2440               -fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c6fa  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c6fc  e87f9fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c701  d95c243c               -fstp dword ptr [esp + 0x3c]
    app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c705  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c707  e8749fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c70c  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c710  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c712  e8699fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c717  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c71b  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c71d  e85e9fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c722  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c726  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c728  e8539fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c72d  e85ea60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c732  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046c736  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c738  e8439fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c73d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c73f  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046c743  e8389fffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c748  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046c74c  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c750  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c754  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c755  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c756  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c757  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c759  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046c75b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c75d  e8be56fcff             -call 0x431e20
    cpu.esp -= 4;
    sub_431e20(app, cpu);
    // 0046c762  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c768  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c76a  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046c76e  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0046c774  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046c777  e8a457fcff             -call 0x431f20
    cpu.esp -= 4;
    sub_431f20(app, cpu);
    // 0046c77c  8b9680000000           -mov edx, dword ptr [esi + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0046c782  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c787  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0046c78a  8b8918030000           -mov ecx, dword ptr [ecx + 0x318]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 0046c790  e84bb8ffff             -call 0x467fe0
    cpu.esp -= 4;
    sub_467fe0(app, cpu);
    // 0046c795  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046c79b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046c79f  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0046c7a3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046c7a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c7a8  d91c82                 -fstp dword ptr [edx + eax*4]
    app->getMemory<float>(cpu.edx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c7ab  8b0d50845100           -mov ecx, dword ptr [0x518450]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342288) /* 0x518450 */);
    // 0046c7b1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046c7b5  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046c7ba  49                     -dec ecx
    (cpu.ecx)--;
    // 0046c7bb  894c2400               -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0046c7bf  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046c7c3  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c7c6  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0046c7c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c7d0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c7d2  e8a99effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c7d7  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046c7dd  c7058ca4510001000000   -mov dword ptr [0x51a48c], 1
    app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */) = 1 /*0x1*/;
    // 0046c7e7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c7e9  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046c7ec  7a0a                   -jp 0x46c7f8
    if (cpu.flags.pf)
    {
        goto L_0x0046c7f8;
    }
    // 0046c7ee  c7058ca4510000000000   -mov dword ptr [0x51a48c], 0
    app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */) = 0 /*0x0*/;
L_0x0046c7f8:
    // 0046c7f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c801  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c802  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c803  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046c805  e8f69effff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c80a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c80c  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046c80f  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046c811  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046c813  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0046c815  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046c817  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046c818  750d                   -jne 0x46c827
    if (!cpu.flags.zf)
    {
        goto L_0x0046c827;
    }
    // 0046c81a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046c81d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046c81f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c820  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c821  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c822  e989b4f9ff             -jmp 0x407cb0
    return sub_407cb0(app, cpu);
L_0x0046c827:
    // 0046c827  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046c829  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c82a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c82b  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046c82d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c82e  e97db4f9ff             -jmp 0x407cb0
    return sub_407cb0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46c840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c840  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046c843  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c845  e8369effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c84a  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c84e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c850  e82b9effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c855  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c859  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c85b  e8209effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c860  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c864  e8979effff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c869  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c86d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c872  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046c876  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c877  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c878  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c87a  e821e2f9ff             -call 0x40aaa0
    cpu.esp -= 4;
    sub_40aaa0(app, cpu);
    // 0046c87f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046c882  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c890  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c891  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c892  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c894  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c898  e8e39dffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c89d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c89f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c8a1  e8da9dffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c8a6  e8e5a40000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c8ab  83f8ff                 +cmp eax, -1
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
    // 0046c8ae  7505                   -jne 0x46c8b5
    if (!cpu.flags.zf)
    {
        goto L_0x0046c8b5;
    }
    // 0046c8b0  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c8b3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046c8b5:
    // 0046c8b5  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c8bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c8bc  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046c8bf  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c8c3  8b8254020000           -mov eax, dword ptr [edx + 0x254]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(596) /* 0x254 */);
    // 0046c8c9  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046c8cf  89048a                 -mov dword ptr [edx + ecx*4], eax
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = cpu.eax;
    // 0046c8d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c8d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c8e0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c8e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c8e4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c8e6  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c8ea  e8919dffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c8ef  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c8f2  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046c8f8  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c8fa  8b80ec020000           -mov eax, dword ptr [eax + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0046c900  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c901  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c903  750b                   -jne 0x46c910
    if (!cpu.flags.zf)
    {
        goto L_0x0046c910;
    }
    // 0046c905  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c909  89048a                 -mov dword ptr [edx + ecx*4], eax
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = cpu.eax;
    // 0046c90c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c90f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c910:
    // 0046c910  f6404a01               +test byte ptr [eax + 0x4a], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(74) /* 0x4a */) & 1 /*0x1*/));
    // 0046c914  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c918  7416                   -je 0x46c930
    if (cpu.flags.zf)
    {
        goto L_0x0046c930;
    }
    // 0046c91a  0fbf808c020000         -movsx eax, word ptr [eax + 0x28c]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(652) /* 0x28c */)));
    // 0046c921  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046c925  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0046c929  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c92c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c92f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c930:
    // 0046c930  0fbf808a020000         -movsx eax, word ptr [eax + 0x28a]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(650) /* 0x28a */)));
    // 0046c937  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046c93b  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0046c93f  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c942  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c945  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c950  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046c952  e8299dffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c957  e834a40000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c95c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c95e  e99d6afeff             -jmp 0x453400
    return sub_453400(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46c970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c970  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0046c973  8b88ec020000           -mov ecx, dword ptr [eax + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0046c979  c6416401               -mov byte ptr [ecx + 0x64], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(100) /* 0x64 */) = 1 /*0x1*/;
    // 0046c97d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46c980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c981  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c982  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c983  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046c985  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c986  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046c98a  e8f19cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c98f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c991  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c993  e8e89cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c998  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c99a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c99c  e8df9cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c9a1  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c9a3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c9a5  e8d69cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c9aa  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c9ac  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c9ae  e8cd9cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046c9b3  e8d8a30000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046c9b8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c9ba  e8419dffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046c9bf  83feff                 +cmp esi, -1
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
    // 0046c9c2  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046c9c4  7505                   -jne 0x46c9cb
    if (!cpu.flags.zf)
    {
        goto L_0x0046c9cb;
    }
    // 0046c9c6  8b7314                 -mov esi, dword ptr [ebx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046c9c9  eb08                   -jmp 0x46c9d3
    goto L_0x0046c9d3;
L_0x0046c9cb:
    // 0046c9cb  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046c9d0  8b34b0                 -mov esi, dword ptr [eax + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
L_0x0046c9d3:
    // 0046c9d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c9d4  6824304a00             -push 0x4a3024
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861988 /*0x4a3024*/;
    cpu.esp -= 4;
    // 0046c9d9  e8d9a30000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046c9de  8b96ec020000           -mov edx, dword ptr [esi + 0x2ec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0046c9e4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c9e7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046c9e9  740a                   -je 0x46c9f5
    if (cpu.flags.zf)
    {
        goto L_0x0046c9f5;
    }
    // 0046c9eb  6683ba8a02000000       +cmp word ptr [edx + 0x28a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(650) /* 0x28a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046c9f3  7e1f                   -jle 0x46ca14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046ca14;
    }
L_0x0046c9f5:
    // 0046c9f5  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046c9f7  e8e41afaff             -call 0x40e4e0
    cpu.esp -= 4;
    sub_40e4e0(app, cpu);
    // 0046c9fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c9fe  7403                   -je 0x46ca03
    if (cpu.flags.zf)
    {
        goto L_0x0046ca03;
    }
    // 0046ca00  897028                 -mov dword ptr [eax + 0x28], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.esi;
L_0x0046ca03:
    // 0046ca03  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ca07  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046ca0d  c7048a00000000         -mov dword ptr [edx + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = 0 /*0x0*/;
L_0x0046ca14:
    // 0046ca14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46ca20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ca20  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046ca23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ca24  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ca25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ca26  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046ca28  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ca2c  e84f9cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ca31  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ca33  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046ca37  e8449cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ca3c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ca3e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ca40  e83b9cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ca45  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ca47  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ca49  e8329cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ca4e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ca50  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ca52  e8299cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ca57  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ca59  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ca5b  e8209cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ca60  e82ba30000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ca65  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ca67  e8949cffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046ca6c  83feff                 +cmp esi, -1
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
    // 0046ca6f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046ca71  7505                   -jne 0x46ca78
    if (!cpu.flags.zf)
    {
        goto L_0x0046ca78;
    }
    // 0046ca73  8b7f14                 -mov edi, dword ptr [edi + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046ca76  eb08                   -jmp 0x46ca80
    goto L_0x0046ca80;
L_0x0046ca78:
    // 0046ca78  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ca7d  8b3cb0                 -mov edi, dword ptr [eax + esi*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
L_0x0046ca80:
    // 0046ca80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ca81  6874304a00             -push 0x4a3074
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862068 /*0x4a3074*/;
    cpu.esp -= 4;
    // 0046ca86  e82ca30000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046ca8b  8b97ec020000           -mov edx, dword ptr [edi + 0x2ec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(748) /* 0x2ec */);
    // 0046ca91  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ca94  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046ca96  740e                   -je 0x46caa6
    if (cpu.flags.zf)
    {
        goto L_0x0046caa6;
    }
    // 0046ca98  6683ba8a02000000       +cmp word ptr [edx + 0x28a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(650) /* 0x28a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046caa0  0f8e88000000           -jle 0x46cb2e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046cb2e;
    }
L_0x0046caa6:
    // 0046caa6  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046caa8  e8331afaff             -call 0x40e4e0
    cpu.esp -= 4;
    sub_40e4e0(app, cpu);
    // 0046caad  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046caaf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046cab1  744d                   -je 0x46cb00
    if (cpu.flags.zf)
    {
        goto L_0x0046cb00;
    }
    // 0046cab3  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 0046cab6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cab9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046cabd  897e28                 -mov dword ptr [esi + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0046cac0  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046cac4  dc0d10774800           -fmul qword ptr [0x487710]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749072) /* 0x487710 */));
    // 0046caca  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cacd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046cace  685c304a00             -push 0x4a305c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862044 /*0x4a305c*/;
    cpu.esp -= 4;
    // 0046cad3  e8dfa20000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046cad8  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 0046cadb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046cade  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046cadf  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046cae1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046cae5  d1f8                   +sar eax, 1
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
    // 0046cae7  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046caed  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046caf1  db442410               +fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0046caf5  dc0d10774800           +fmul qword ptr [0x487710]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749072) /* 0x487710 */));
    // 0046cafb  d91c8a                 +fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cafe  eb1e                   -jmp 0x46cb1e
    goto L_0x0046cb1e;
L_0x0046cb00:
    // 0046cb00  6834304a00             -push 0x4a3034
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862004 /*0x4a3034*/;
    cpu.esp -= 4;
    // 0046cb05  e8ada20000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046cb0a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046cb0e  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cb14  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046cb17  c7048100000000         -mov dword ptr [ecx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 0 /*0x0*/;
L_0x0046cb1e:
    // 0046cb1e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046cb22  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cb27  c7049000000000         -mov dword ptr [eax + edx*4], 0
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = 0 /*0x0*/;
L_0x0046cb2e:
    // 0046cb2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb31  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046cb34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46cb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cb40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cb41  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046cb43  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046cb46  8b88ec020000           -mov ecx, dword ptr [eax + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0046cb4c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046cb4e  750d                   -jne 0x46cb5d
    if (!cpu.flags.zf)
    {
        goto L_0x0046cb5d;
    }
    // 0046cb50  6888304a00             -push 0x4a3088
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862088 /*0x4a3088*/;
    cpu.esp -= 4;
    // 0046cb55  e8b680fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046cb5a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046cb5d:
    // 0046cb5d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cb5f  e81c9bffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cb64  e827a20000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046cb69  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046cb6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb6d  8b91ec020000           -mov edx, dword ptr [ecx + 0x2ec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(748) /* 0x2ec */);
    // 0046cb73  89422c                 -mov dword ptr [edx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046cb76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46cb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cb80  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cb83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cb84  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046cb86  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cb8a  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0046cb92  e8e99affff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cb97  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cb99  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cb9b  e8e09affff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cba0  e8eba10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046cba5  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046cbab  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046cbae  8b82ec020000           -mov eax, dword ptr [edx + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(748) /* 0x2ec */);
    // 0046cbb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cbb6  745a                   -je 0x46cc12
    if (cpu.flags.zf)
    {
        goto L_0x0046cc12;
    }
    // 0046cbb8  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046cbbb  8b89ec020000           -mov ecx, dword ptr [ecx + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(748) /* 0x2ec */);
    // 0046cbc1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046cbc3  7437                   -je 0x46cbfc
    if (cpu.flags.zf)
    {
        goto L_0x0046cbfc;
    }
    // 0046cbc5  8b512c                 -mov edx, dword ptr [ecx + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 0046cbc8  8b482c                 -mov ecx, dword ptr [eax + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0046cbcb  85d1                   +test ecx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.edx));
    // 0046cbcd  7418                   -je 0x46cbe7
    if (cpu.flags.zf)
    {
        goto L_0x0046cbe7;
    }
    // 0046cbcf  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 0046cbd5  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cbdb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cbdf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cbe0  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cbe3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cbe6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cbe7:
    // 0046cbe7  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046cbeb  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cbef  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cbf4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cbf5  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cbf8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cbfb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cbfc:
    // 0046cbfc  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046cc00  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cc04  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cc0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc0b  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cc0e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cc11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cc12:
    // 0046cc12  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046cc16  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cc1c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cc20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc21  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cc24  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cc27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46cc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cc30  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cc33  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 0046cc37  c744240400000000       -mov dword ptr [esp + 4], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0046cc3f  e83c9affff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cc44  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cc46  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cc48  e8339affff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cc4d  e83ea10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046cc52  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046cc58  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046cc5b  8b82ec020000           -mov eax, dword ptr [edx + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(748) /* 0x2ec */);
    // 0046cc61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cc63  7431                   -je 0x46cc96
    if (cpu.flags.zf)
    {
        goto L_0x0046cc96;
    }
    // 0046cc65  f6404a01               +test byte ptr [eax + 0x4a], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(74) /* 0x4a */) & 1 /*0x1*/));
    // 0046cc69  7417                   -je 0x46cc82
    if (cpu.flags.zf)
    {
        goto L_0x0046cc82;
    }
    // 0046cc6b  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 0046cc71  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046cc75  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cc7b  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cc7e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cc81  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cc82:
    // 0046cc82  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046cc86  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046cc8a  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cc8f  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cc92  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cc95  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cc96:
    // 0046cc96  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046cc9a  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046cc9e  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cca4  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cca7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ccaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46ccb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ccb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ccb1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046ccb3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ccb5  e8c699ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ccba  e8d1a00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ccbf  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ccc5  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046ccc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ccc9  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0046cccc  8b89ec020000           -mov ecx, dword ptr [ecx + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(748) /* 0x2ec */);
    // 0046ccd2  8988ec020000           -mov dword ptr [eax + 0x2ec], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */) = cpu.ecx;
    // 0046ccd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46cce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cce0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cce1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cce2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cce3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cce5  e89699ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ccea  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ccee  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ccf0  e88b99ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ccf5  e896a00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ccfa  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ccfc  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046ccfe  e87d99ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cd03  e888a00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046cd08  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046cd0a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046cd0c  7c51                   -jl 0x46cd5f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046cd5f;
    }
    // 0046cd0e  3b35c0f35100           +cmp esi, dword ptr [0x51f3c0]
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
    // 0046cd14  7d49                   -jge 0x46cd5f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046cd5f;
    }
    // 0046cd16  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046cd18  83e800                 +sub eax, 0
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
    // 0046cd1b  7424                   -je 0x46cd41
    if (cpu.flags.zf)
    {
        goto L_0x0046cd41;
    }
    // 0046cd1d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046cd1e  753f                   -jne 0x46cd5f
    if (!cpu.flags.zf)
    {
        goto L_0x0046cd5f;
    }
    // 0046cd20  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046cd24  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046cd26  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046cd28  e863a00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046cd2d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046cd2e  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046cd33  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046cd35  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046cd38  e813b5feff             -call 0x458250
    cpu.esp -= 4;
    sub_458250(app, cpu);
    // 0046cd3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cd41:
    // 0046cd41  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046cd45  e846a00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046cd4a  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046cd50  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046cd51  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046cd53  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046cd55  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046cd58  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046cd5a  e8f1b4feff             -call 0x458250
    cpu.esp -= 4;
    sub_458250(app, cpu);
L_0x0046cd5f:
    // 0046cd5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46cd70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cd70  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cd73  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cd77  e80499ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cd7c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cd7e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cd80  e8fb98ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cd85  e806a00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046cd8a  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046cd90  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046cd93  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cd97  8a8226030000           -mov al, byte ptr [edx + 0x326]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(806) /* 0x326 */);
    // 0046cd9d  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cda3  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0046cda5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046cdaa  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046cdae  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046cdb2  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cdb5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cdb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46cdc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cdc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cdc1  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 0046cdc5  e8b698ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cdca  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046cdce  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046cdd4  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cdd6  db05c4e54900           -fild dword ptr [0x49e5c4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */))));
    // 0046cddc  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cddf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cde0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46cdf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cdf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cdf1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046cdf3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cdf4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cdf6  e88598ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cdfb  e8909f0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ce00  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ce02  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046ce04  e87798ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ce09  e8829f0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ce0e  83f8ff                 +cmp eax, -1
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
    // 0046ce11  7505                   -jne 0x46ce18
    if (!cpu.flags.zf)
    {
        goto L_0x0046ce18;
    }
    // 0046ce13  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046ce16  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046ce18:
    // 0046ce18  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ce1e  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046ce20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ce21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ce22  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046ce25  8b88b4020000           -mov ecx, dword ptr [eax + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(692) /* 0x2b4 */);
    // 0046ce2b  e91057fbff             -jmp 0x422540
    return sub_422540(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46ce30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ce30  e8cb98ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046ce35  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046ce37  e98447fcff             -jmp 0x4315c0
    return sub_4315c0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46ce40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ce40  e8bb98ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046ce45  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046ce47  e98447fcff             -jmp 0x4315d0
    return sub_4315d0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46ce50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ce50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ce51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ce52  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046ce54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ce55  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ce57  e82498ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ce5c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ce5e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ce60  e81b98ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ce65  e8269f0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ce6a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ce6c  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046ce6e  e80d98ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ce73  e8189f0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ce78  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046ce7a  83ffff                 +cmp edi, -1
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
    // 0046ce7d  7505                   -jne 0x46ce84
    if (!cpu.flags.zf)
    {
        goto L_0x0046ce84;
    }
    // 0046ce7f  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046ce82  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046ce84:
    // 0046ce84  e8d78dfeff             -call 0x455c60
    cpu.esp -= 4;
    sub_455c60(app, cpu);
    // 0046ce89  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ce8b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046ce8d  7412                   -je 0x46cea1
    if (cpu.flags.zf)
    {
        goto L_0x0046cea1;
    }
L_0x0046ce8f:
    // 0046ce8f  39be80000000           +cmp dword ptr [esi + 0x80], edi
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
    // 0046ce95  7417                   -je 0x46ceae
    if (cpu.flags.zf)
    {
        goto L_0x0046ceae;
    }
    // 0046ce97  8bb630030000           -mov esi, dword ptr [esi + 0x330]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(816) /* 0x330 */);
    // 0046ce9d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046ce9f  75ee                   -jne 0x46ce8f
    if (!cpu.flags.zf)
    {
        goto L_0x0046ce8f;
    }
L_0x0046cea1:
    // 0046cea1  68a4304a00             -push 0x4a30a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862116 /*0x4a30a4*/;
    cpu.esp -= 4;
    // 0046cea6  e8657dfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046ceab  83c404                 +add esp, 4
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
L_0x0046ceae:
    // 0046ceae  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046ceb0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046ceb1  7504                   -jne 0x46ceb7
    if (!cpu.flags.zf)
    {
        goto L_0x0046ceb7;
    }
    // 0046ceb3  804e4b01               -or byte ptr [esi + 0x4b], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(75) /* 0x4b */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0046ceb7:
    // 0046ceb7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ceb8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ceb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ceba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46cec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0046cec0  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046cec3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cec4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cec6  e8b597ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cecb  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cecf  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ced1  e8aa97ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ced6  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ceda  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cedc  e89f97ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046cee1  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cee5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cee7  e89497ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ceec  e89f9e0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046cef1  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046cef3  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0046cef8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cefa  750d                   -jne 0x46cf09
    if (!cpu.flags.zf)
    {
        goto L_0x0046cf09;
    }
    // 0046cefc  68f0304a00             -push 0x4a30f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862192 /*0x4a30f0*/;
    cpu.esp -= 4;
    // 0046cf01  e80a7dfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046cf06  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046cf09:
    // 0046cf09  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046cf0b  0f849c000000           -je 0x46cfad
    if (cpu.flags.zf)
    {
        goto L_0x0046cfad;
    }
    // 0046cf11  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046cf16  8b0dc4e54900           -mov ecx, dword ptr [0x49e5c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0046cf1c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cf1d  8b3530845100           -mov esi, dword ptr [0x518430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046cf23  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046cf26  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0046cf2c  8b1496                 -mov edx, dword ptr [esi + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 0046cf2f  8b92d0000000           -mov edx, dword ptr [edx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0046cf35  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046cf39  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046cf3c  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0046cf42  8b1496                 -mov edx, dword ptr [esi + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 0046cf45  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0046cf4b  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0046cf4f  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046cf52  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0046cf58  8b1496                 -mov edx, dword ptr [esi + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 0046cf5b  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0046cf61  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0046cf65  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046cf68  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046cf6c  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0046cf72  8b0c8e                 -mov ecx, dword ptr [esi + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4);
    // 0046cf75  e8361dffff             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0046cf7a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046cf7e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046cf82  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046cf86  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cf87  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046cf8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046cf8e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cf8f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cf91  e86a27feff             -call 0x44f700
    cpu.esp -= 4;
    sub_44f700(app, cpu);
    // 0046cf96  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046cf9b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046cf9d  c781c802000000000000   -mov dword ptr [ecx + 0x2c8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */) = 0 /*0x0*/;
    // 0046cfa7  e8f404ffff             -call 0x45d4a0
    cpu.esp -= 4;
    sub_45d4a0(app, cpu);
    // 0046cfac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046cfad:
    // 0046cfad  83ff03                 +cmp edi, 3
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
    // 0046cfb0  7723                   -ja 0x46cfd5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046cfd5;
    }
    // 0046cfb2  ff24bdfccf4600         -jmp dword ptr [edi*4 + 0x46cffc]
    cpu.ip = app->getMemory<x86::reg32>(4640764 + cpu.edi * 4); goto dynamic_jump;
  case 0x0046cfb9:
    // 0046cfb9  e8d204ffff             -call 0x45d490
    cpu.esp -= 4;
    sub_45d490(app, cpu);
    // 0046cfbe  eb23                   -jmp 0x46cfe3
    goto L_0x0046cfe3;
  case 0x0046cfc0:
    // 0046cfc0  e8fb04ffff             -call 0x45d4c0
    cpu.esp -= 4;
    sub_45d4c0(app, cpu);
    // 0046cfc5  eb1c                   -jmp 0x46cfe3
    goto L_0x0046cfe3;
  case 0x0046cfc7:
    // 0046cfc7  e87405ffff             -call 0x45d540
    cpu.esp -= 4;
    sub_45d540(app, cpu);
    // 0046cfcc  eb15                   -jmp 0x46cfe3
    goto L_0x0046cfe3;
  case 0x0046cfce:
    // 0046cfce  e80d05ffff             -call 0x45d4e0
    cpu.esp -= 4;
    sub_45d4e0(app, cpu);
    // 0046cfd3  eb0e                   -jmp 0x46cfe3
    goto L_0x0046cfe3;
L_0x0046cfd5:
    // 0046cfd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cfd6  68cc304a00             -push 0x4a30cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862156 /*0x4a30cc*/;
    cpu.esp -= 4;
    // 0046cfdb  e8307cfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046cfe0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0046cfe3:
    // 0046cfe3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cfe7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046cfeb  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046cfef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cff0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046cff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cff2  e829f6feff             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 0046cff7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cff8  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046cffb  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_46d010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d010  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d011  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d012  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d014  e86796ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d019  e8729d0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d01e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d020  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d022  e85996ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d027  e8649d0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d02c  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046d02e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d02f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d030  684c314a00             -push 0x4a314c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862284 /*0x4a314c*/;
    cpu.esp -= 4;
    // 0046d035  e87d9d0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046d03a  83c40c                 +add esp, 0xc
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
    // 0046d03d  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046d03f  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046d041  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d042  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d043  e98884fbff             -jmp 0x4254d0
    return sub_4254d0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46d050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d050  e8ab96ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d055  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046d056  e8b57bfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046d05b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d05c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d060  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d062  e81996ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d067  e8249d0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d06c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046d06d  6868314a00             -push 0x4a3168
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862312 /*0x4a3168*/;
    cpu.esp -= 4;
    // 0046d072  a3902d4a00             -mov dword ptr [0x4a2d90], eax
    app->getMemory<x86::reg32>(x86::reg32(4861328) /* 0x4a2d90 */) = cpu.eax;
    // 0046d077  e83b9d0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046d07c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d07f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d080  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d083  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d084  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d085  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d086  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046d088  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d089  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d08b  e8f095ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d090  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d094  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d096  e8e595ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d09b  e8f09c0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d0a0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d0a2  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d0a4  e8d795ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d0a9  e8e29c0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d0ae  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d0b0  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046d0b2  e8c995ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d0b7  e8d49c0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d0bc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046d0c0  e83b96ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d0c5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d0c7  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046d0c9  e8b295ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d0ce  e8bd9c0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d0d3  83f8ff                 +cmp eax, -1
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
    // 0046d0d6  7505                   -jne 0x46d0dd
    if (!cpu.flags.zf)
    {
        goto L_0x0046d0dd;
    }
    // 0046d0d8  8b5b14                 -mov ebx, dword ptr [ebx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046d0db  eb09                   -jmp 0x46d0e6
    goto L_0x0046d0e6;
L_0x0046d0dd:
    // 0046d0dd  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d0e3  8b1c81                 -mov ebx, dword ptr [ecx + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046d0e6:
    // 0046d0e6  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046d0ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d0eb  680000c03f             -push 0x3fc00000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1069547520 /*0x3fc00000*/;
    cpu.esp -= 4;
    // 0046d0f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d0f1  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046d0f3  e8a83dffff             -call 0x460ea0
    cpu.esp -= 4;
    sub_460ea0(app, cpu);
    // 0046d0f8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d0fa  83feff                 +cmp esi, -1
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
    // 0046d0fd  7454                   -je 0x46d153
    if (cpu.flags.zf)
    {
        goto L_0x0046d153;
    }
    // 0046d0ff  8b8310030000           -mov eax, dword ptr [ebx + 0x310]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(784) /* 0x310 */);
    // 0046d105  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d107  7419                   -je 0x46d122
    if (cpu.flags.zf)
    {
        goto L_0x0046d122;
    }
    // 0046d109  8b8bb4020000           -mov ecx, dword ptr [ebx + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(692) /* 0x2b4 */);
    // 0046d10f  e8fc26ffff             -call 0x45f810
    cpu.esp -= 4;
    sub_45f810(app, cpu);
    // 0046d114  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046d115  68ac314a00             -push 0x4a31ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862380 /*0x4a31ac*/;
    cpu.esp -= 4;
    // 0046d11a  e8f17afbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046d11f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0046d122:
    // 0046d122  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0046d128  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046d12a  899308030000           -mov dword ptr [ebx + 0x308], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(776) /* 0x308 */) = cpu.edx;
    // 0046d130  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046d132  e8191affff             -call 0x45eb50
    cpu.esp -= 4;
    sub_45eb50(app, cpu);
    // 0046d137  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046d13b  c7831003000070d14600   -mov dword ptr [ebx + 0x310], 0x46d170
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(784) /* 0x310 */) = 4641136 /*0x46d170*/;
    // 0046d145  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d146  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d147  898340020000           -mov dword ptr [ebx + 0x240], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(576) /* 0x240 */) = cpu.eax;
    // 0046d14d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d14e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d14f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d152  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d153:
    // 0046d153  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d154  6880314a00             -push 0x4a3180
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862336 /*0x4a3180*/;
    cpu.esp -= 4;
    // 0046d159  e8b27afbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046d15e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d161  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d162  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d163  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d164  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d165  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d171  a148845100             -mov eax, dword ptr [0x518448]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0046d176  8b9108030000           -mov edx, dword ptr [ecx + 0x308]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(776) /* 0x308 */);
    // 0046d17c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d17e  683333333f             -push 0x3f333333
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060320051 /*0x3f333333*/;
    cpu.esp -= 4;
    // 0046d183  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046d187  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d188  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0046d18c  d98140020000           -fld dword ptr [ecx + 0x240]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(576) /* 0x240 */)));
    // 0046d192  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 0046d198  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046d19a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d19c  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046d19e  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d1a1  e8aafbfdff             -call 0x44cd50
    cpu.esp -= 4;
    sub_44cd50(app, cpu);
    // 0046d1a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d1a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d1b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d1b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d1b2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d1b4  e8c794ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d1b9  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d1bd  e83e95ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d1c2  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046d1c6  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d1c8  e8c39b0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d1cd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046d1cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d1d0  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d1d2  83c404                 +add esp, 4
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
    // 0046d1d5  e97606feff             -jmp 0x44d850
    return sub_44d850(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46d1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d1e0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d1e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d1e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d1e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d1e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d1e7  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046d1eb  e89094ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d1f0  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d1f2  e80995ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d1f7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d1f9  e88225ffff             -call 0x45f780
    cpu.esp -= 4;
    sub_45f780(app, cpu);
    // 0046d1fe  8b1d2c845100           -mov ebx, dword ptr [0x51842c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 0046d204  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046d206  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046d208  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0046d20c  7e34                   -jle 0x46d242
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d242;
    }
    // 0046d20e  8b3d30845100           -mov edi, dword ptr [0x518430]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
L_0x0046d214:
    // 0046d214  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0046d217  8b91a8020000           -mov edx, dword ptr [ecx + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0046d21d  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0046d220  7417                   -je 0x46d239
    if (cpu.flags.zf)
    {
        goto L_0x0046d239;
    }
    // 0046d222  8ba9e8020000           -mov ebp, dword ptr [ecx + 0x2e8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 0046d228  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046d22a  750d                   -jne 0x46d239
    if (!cpu.flags.zf)
    {
        goto L_0x0046d239;
    }
    // 0046d22c  f6c20c                 +test dl, 0xc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 12 /*0xc*/));
    // 0046d22f  7508                   -jne 0x46d239
    if (!cpu.flags.zf)
    {
        goto L_0x0046d239;
    }
    // 0046d231  3981b4020000           +cmp dword ptr [ecx + 0x2b4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d237  7421                   -je 0x46d25a
    if (cpu.flags.zf)
    {
        goto L_0x0046d25a;
    }
L_0x0046d239:
    // 0046d239  46                     -inc esi
    (cpu.esi)++;
    // 0046d23a  3bf3                   +cmp esi, ebx
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
    // 0046d23c  7cd6                   -jl 0x46d214
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d214;
    }
    // 0046d23e  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
L_0x0046d242:
    // 0046d242  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046d246  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d24b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d24c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d24d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d24e  c70490000080bf         -mov dword ptr [eax + edx*4], 0xbf800000
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = 3212836864 /*0xbf800000*/;
    // 0046d255  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d256  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d259  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d25a:
    // 0046d25a  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046d25e  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d264  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0046d268  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d269  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046d26d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d26e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d26f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d270  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d273  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d276  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d280  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d281  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d283  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046d285  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d286  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d288  e8f393ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d28d  e8fe9a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d292  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d294  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d296  e8e593ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d29b  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d29f  e85c94ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d2a4  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046d2a8  d81dec724800           -fcomp dword ptr [0x4872ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    cpu.fpu.pop();
    // 0046d2ae  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046d2b0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046d2b2  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046d2b5  7a09                   -jp 0x46d2c0
    if (cpu.flags.pf)
    {
        goto L_0x0046d2c0;
    }
    // 0046d2b7  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046d2ba  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 0046d2bc  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046d2c0:
    // 0046d2c0  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046d2c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d2c5  e8c69a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d2ca  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d2cc  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046d2ce  e88d1dfcff             -call 0x42f060
    cpu.esp -= 4;
    sub_42f060(app, cpu);
    // 0046d2d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d2e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d2e1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046d2e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d2e4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d2e6  e89593ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d2eb  e8a09a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d2f0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d2f2  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046d2f4  e88793ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d2f9  e8929a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d2fe  83f8ff                 +cmp eax, -1
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
    // 0046d301  7505                   -jne 0x46d308
    if (!cpu.flags.zf)
    {
        goto L_0x0046d308;
    }
    // 0046d303  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046d306  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046d308:
    // 0046d308  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046d30a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d30b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d30d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d30e  e98d1ffcff             -jmp 0x42f2a0
    return sub_42f2a0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46d320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0046d320  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d324  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d325  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046d327  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d329  e85293ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d32e  e85d9a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d333  83f812                 +cmp eax, 0x12
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
    // 0046d336  0f8750040000           -ja 0x46d78c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046d78c;
    }
    // 0046d33c  ff248594d74600         -jmp dword ptr [eax*4 + 0x46d794]
    cpu.ip = app->getMemory<x86::reg32>(4642708 + cpu.eax * 4); goto dynamic_jump;
  case 0x0046d343:
    // 0046d343  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d344  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d345  83c408                 +add esp, 8
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
    // 0046d348  e9d3fef9ff             -jmp 0x40d220
    return sub_40d220(app, cpu);
  case 0x0046d34d:
    // 0046d34d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d34f  e82c93ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d354  e8379a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d359  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d35b  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d35f  e8ec30fbff             -call 0x420450
    cpu.esp -= 4;
    sub_420450(app, cpu);
    // 0046d364  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d365  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d366  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d369  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d36a:
    // 0046d36a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d36c  e80f93ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d371  e81a9a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d376  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d378  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d37c  e8ff92ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d381  e80a9a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d386  83f8ff                 +cmp eax, -1
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
    // 0046d389  7505                   -jne 0x46d390
    if (!cpu.flags.zf)
    {
        goto L_0x0046d390;
    }
    // 0046d38b  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046d38e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046d390:
    // 0046d390  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d396  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d39a  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046d39d  e8fe30fbff             -call 0x4204a0
    cpu.esp -= 4;
    sub_4204a0(app, cpu);
    // 0046d3a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d3a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d3a4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d3a7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d3a8:
    // 0046d3a8  e85393ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d3ad  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d3af  e84c93ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d3b4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d3b6  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046d3b8  e8c392ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d3bd  e8ce990000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d3c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d3c3  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046d3c5  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d3c7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046d3cb  e820a1fbff             -call 0x4274f0
    cpu.esp -= 4;
    sub_4274f0(app, cpu);
    // 0046d3d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d3d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d3d2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d3d5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d3d6:
    // 0046d3d6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d3d8  e8a392ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d3dd  e8ae990000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d3e2  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d3e4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d3e8  e883a0fbff             -call 0x427470
    cpu.esp -= 4;
    sub_427470(app, cpu);
    // 0046d3ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d3ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d3ef  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d3f2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d3f3:
    // 0046d3f3  e80893ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d3f8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d3fa  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d3fc  e87f92ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d401  e88a990000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d406  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046d408  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d40a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d40e  e88da0fbff             -call 0x4274a0
    cpu.esp -= 4;
    sub_4274a0(app, cpu);
    // 0046d413  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d414  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d415  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d418  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d419:
    // 0046d419  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d41d  e85e92ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d422  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d424  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d426  e85592ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d42b  e860990000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d430  83f8ff                 +cmp eax, -1
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
    // 0046d433  7505                   -jne 0x46d43a
    if (!cpu.flags.zf)
    {
        goto L_0x0046d43a;
    }
    // 0046d435  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046d438  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
L_0x0046d43a:
    // 0046d43a  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d440  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046d443  e84837fcff             -call 0x430b90
    cpu.esp -= 4;
    sub_430b90(app, cpu);
    // 0046d448  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d44c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046d450  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046d454  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d459  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d45a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d45b  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d45e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d461  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d462:
    // 0046d462  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d466  e81592ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d46b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d46d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d46f  e80c92ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d474  e817990000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d479  83f8ff                 +cmp eax, -1
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
    // 0046d47c  7505                   -jne 0x46d483
    if (!cpu.flags.zf)
    {
        goto L_0x0046d483;
    }
    // 0046d47e  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046d481  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
L_0x0046d483:
    // 0046d483  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d489  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0046d48c  e8ef31fbff             -call 0x420680
    cpu.esp -= 4;
    sub_420680(app, cpu);
    // 0046d491  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d497  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046d49b  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046d49f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d4a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4a5  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d4a8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d4ab  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d4ac:
    // 0046d4ac  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d4b0  e8cb91ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d4b5  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d4b7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d4b9  e8c291ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d4be  e8cd980000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d4c3  83f8ff                 +cmp eax, -1
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
    // 0046d4c6  7505                   -jne 0x46d4cd
    if (!cpu.flags.zf)
    {
        goto L_0x0046d4cd;
    }
    // 0046d4c8  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046d4cb  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
L_0x0046d4cd:
    // 0046d4cd  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d4d3  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0046d4d8  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046d4db  e85037fcff             -call 0x430c30
    cpu.esp -= 4;
    sub_430c30(app, cpu);
    // 0046d4e0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d4e4  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046d4e8  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046d4ec  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d4f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4f3  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d4f6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d4f9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d4fa:
    // 0046d4fa  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d4fe  e87d91ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d503  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d505  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d507  e87491ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d50c  e87f980000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d511  83f8ff                 +cmp eax, -1
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
    // 0046d514  7505                   -jne 0x46d51b
    if (!cpu.flags.zf)
    {
        goto L_0x0046d51b;
    }
    // 0046d516  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046d519  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
L_0x0046d51b:
    // 0046d51b  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d521  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0046d526  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046d529  e89231fbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d52e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d532  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046d536  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046d53a  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d53f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d540  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d541  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d544  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d547  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d548:
    // 0046d548  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d54a  e83191ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d54f  e83c980000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d554  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d556  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d558  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d55c  e8efa8faff             -call 0x417e50
    cpu.esp -= 4;
    sub_417e50(app, cpu);
    // 0046d561  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d562  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d563  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d566  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d567:
    // 0046d567  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d569  e81291ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d56e  e81d980000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d573  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d575  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046d57a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d57e  e8cda8faff             -call 0x417e50
    cpu.esp -= 4;
    sub_417e50(app, cpu);
    // 0046d583  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d584  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d585  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d588  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d589:
    // 0046d589  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d58b  e8f090ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d590  e8fb970000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d595  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d597  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d59b  e8c0c0fbff             -call 0x429660
    cpu.esp -= 4;
    sub_429660(app, cpu);
    // 0046d5a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5a2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d5a5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d5a6:
    // 0046d5a6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d5a8  e8d390ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d5ad  e8de970000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d5b2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d5b6  e825e0faff             -call 0x41b5e0
    cpu.esp -= 4;
    sub_41b5e0(app, cpu);
    // 0046d5bb  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d5bf  e8acc0fbff             -call 0x429670
    cpu.esp -= 4;
    sub_429670(app, cpu);
    // 0046d5c4  837c240802             +cmp dword ptr [esp + 8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d5c9  7510                   -jne 0x46d5db
    if (!cpu.flags.zf)
    {
        goto L_0x0046d5db;
    }
    // 0046d5cb  b9fe000000             -mov ecx, 0xfe
    cpu.ecx = 254 /*0xfe*/;
    // 0046d5d0  e82bd3faff             -call 0x41a900
    cpu.esp -= 4;
    sub_41a900(app, cpu);
    // 0046d5d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5d7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d5da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d5db:
    // 0046d5db  b9ff000000             -mov ecx, 0xff
    cpu.ecx = 255 /*0xff*/;
    // 0046d5e0  e81bd3faff             -call 0x41a900
    cpu.esp -= 4;
    sub_41a900(app, cpu);
    // 0046d5e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5e7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d5ea  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d5eb:
    // 0046d5eb  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d5ef  e88c90ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d5f4  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d5f6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d5f8  e88390ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d5fd  e88e970000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d602  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d604  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d606  e87590ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d60b  e880970000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d610  83f8ff                 +cmp eax, -1
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
    // 0046d613  7505                   -jne 0x46d61a
    if (!cpu.flags.zf)
    {
        goto L_0x0046d61a;
    }
    // 0046d615  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046d618  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
L_0x0046d61a:
    // 0046d61a  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d620  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046d622  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046d625  e80636fcff             -call 0x430c30
    cpu.esp -= 4;
    sub_430c30(app, cpu);
    // 0046d62a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d62e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046d632  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046d636  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d63b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d63c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d63d  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d640  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d643  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046d644:
    // 0046d644  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d645  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d646  83c408                 +add esp, 8
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
    // 0046d649  e9d2abfaff             -jmp 0x418220
    return sub_418220(app, cpu);
  case 0x0046d64e:
    // 0046d64e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d64f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d650  83c408                 +add esp, 8
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
    // 0046d653  e9e8abfaff             -jmp 0x418240
    return sub_418240(app, cpu);
  case 0x0046d658:
    // 0046d658  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d65c  e81f90ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d661  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d663  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d665  e81690ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d66a  e821970000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d66f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d671  83feff                 +cmp esi, -1
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
    // 0046d674  7505                   -jne 0x46d67b
    if (!cpu.flags.zf)
    {
        goto L_0x0046d67b;
    }
    // 0046d676  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046d679  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
L_0x0046d67b:
    // 0046d67b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d680  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0046d685  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046d688  e83330fbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d68d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d68f  0f85df000000           -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d695  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d69b  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 0046d6a0  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046d6a3  e81830fbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d6a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d6aa  0f85c4000000           -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d6b0  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d6b5  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0046d6ba  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046d6bd  e8fe2ffbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d6c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d6c4  0f85aa000000           -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d6ca  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d6d0  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0046d6d5  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046d6d8  e8e32ffbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d6dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d6df  0f858f000000           -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d6e5  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d6ea  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 0046d6ef  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046d6f2  e8c92ffbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d6f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d6f9  7579                   -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d6fb  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d701  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 0046d706  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046d709  e8b22ffbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d70e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d710  7562                   -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d712  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d717  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0046d71c  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046d71f  e89c2ffbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d724  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d726  754c                   -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d728  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d72e  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 0046d733  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046d736  e8852ffbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d73b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d73d  7535                   -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d73f  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d744  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 0046d749  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046d74c  e86f2ffbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d751  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d753  751f                   -jne 0x46d774
    if (!cpu.flags.zf)
    {
        goto L_0x0046d774;
    }
    // 0046d755  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d75b  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0046d760  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046d763  e8582ffbff             -call 0x4206c0
    cpu.esp -= 4;
    sub_4206c0(app, cpu);
    // 0046d768  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d76a  c744240c00000000       -mov dword ptr [esp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0046d772  7408                   -je 0x46d77c
    if (cpu.flags.zf)
    {
        goto L_0x0046d77c;
    }
L_0x0046d774:
    // 0046d774  c744240c01000000       -mov dword ptr [esp + 0xc], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0046d77c:
    // 0046d77c  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046d780  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d785  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d789  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
  [[fallthrough]];
  case 0x0046d78c:
L_0x0046d78c:
    // 0046d78c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d78d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d78e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d791  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_46d7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d7e0  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046d7e2  e8998effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d7e7  e8a4950000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d7ec  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d7ee  e95d9ffbff             -jmp 0x427750
    return sub_427750(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46d800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d800  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046d802  e8798effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d807  e884950000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d80c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d80e  e95d6ffaff             -jmp 0x414770
    return sub_414770(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46d820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d820  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046d822  e8598effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d827  e864950000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d82c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d82e  e9fd3df9ff             -jmp 0x401630
    return sub_401630(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46d840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d840  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d841  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046d843  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d844  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d846  e8358effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d84b  e840950000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d850  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d852  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046d854  e8278effff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d859  e832950000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d85e  83f8ff                 +cmp eax, -1
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
    // 0046d861  7505                   -jne 0x46d868
    if (!cpu.flags.zf)
    {
        goto L_0x0046d868;
    }
    // 0046d863  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046d866  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046d868:
    // 0046d868  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d86e  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046d871  8b8aec020000           -mov ecx, dword ptr [edx + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(748) /* 0x2ec */);
    // 0046d877  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046d879  7409                   -je 0x46d884
    if (cpu.flags.zf)
    {
        goto L_0x0046d884;
    }
    // 0046d87b  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046d87d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d87e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d87f  e96c7ff9ff             -jmp 0x4057f0
    return sub_4057f0(app, cpu);
L_0x0046d884:
    // 0046d884  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d885  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d886  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d890  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d891  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046d893  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d894  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d896  e8e58dffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d89b  e8f0940000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d8a0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d8a2  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046d8a4  e8d78dffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d8a9  e8e2940000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d8ae  83f8ff                 +cmp eax, -1
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
    // 0046d8b1  7505                   -jne 0x46d8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046d8b8;
    }
    // 0046d8b3  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046d8b6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046d8b8:
    // 0046d8b8  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d8be  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046d8c1  8b8aec020000           -mov ecx, dword ptr [edx + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(748) /* 0x2ec */);
    // 0046d8c7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046d8c9  7409                   -je 0x46d8d4
    if (cpu.flags.zf)
    {
        goto L_0x0046d8d4;
    }
    // 0046d8cb  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046d8cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d8ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d8cf  e96c5ff9ff             -jmp 0x403840
    return sub_403840(app, cpu);
L_0x0046d8d4:
    // 0046d8d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d8d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d8d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d8e0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046d8e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d8e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d8e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d8e6  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046d8e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d8e9  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046d8eb  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046d8ed  e8ae0dffff             -call 0x45e6a0
    cpu.esp -= 4;
    sub_45e6a0(app, cpu);
    // 0046d8f2  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 0046d8f8  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046d8fb  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046d8fe  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046d902  80cc40                 -or ah, 0x40
    cpu.ah |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0046d905  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0046d909  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 0046d90f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046d912  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046d916  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046d91a  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046d91c  bd00040000             -mov ebp, 0x400
    cpu.ebp = 1024 /*0x400*/;
L_0x0046d921:
    // 0046d921  8b54b410               -mov edx, dword ptr [esp + esi*4 + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */ + cpu.esi * 4);
    // 0046d925  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d927  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046d92a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d92c  7e21                   -jle 0x46d94f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d94f;
    }
L_0x0046d92e:
    // 0046d92e  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0046d931  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046d934  397808                 +cmp dword ptr [eax + 8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d937  750e                   -jne 0x46d947
    if (!cpu.flags.zf)
    {
        goto L_0x0046d947;
    }
    // 0046d939  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046d93b  7406                   -je 0x46d943
    if (cpu.flags.zf)
    {
        goto L_0x0046d943;
    }
    // 0046d93d  806011fb               +and byte ptr [eax + 0x11], 0xfb
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) &= x86::reg8(x86::sreg8(251 /*0xfb*/))));
    // 0046d941  eb04                   -jmp 0x46d947
    goto L_0x0046d947;
L_0x0046d943:
    // 0046d943  66096810               -or word ptr [eax + 0x10], bp
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) |= x86::reg16(x86::sreg16(cpu.bp));
L_0x0046d947:
    // 0046d947  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046d94a  41                     -inc ecx
    (cpu.ecx)++;
    // 0046d94b  3bc8                   +cmp ecx, eax
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
    // 0046d94d  7cdf                   -jl 0x46d92e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d92e;
    }
L_0x0046d94f:
    // 0046d94f  46                     -inc esi
    (cpu.esi)++;
    // 0046d950  83fe03                 +cmp esi, 3
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
    // 0046d953  7ccc                   -jl 0x46d921
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d921;
    }
    // 0046d955  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d956  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d957  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d958  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d959  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046d95c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_46d960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d961  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d962  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d963  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d964  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046d966  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d968  e8138dffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d96d  e81e940000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d972  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046d974  e8878dffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046d979  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d97b  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046d97d  e8fe8cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d982  e809940000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046d987  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d989  83feff                 +cmp esi, -1
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
    // 0046d98c  7505                   -jne 0x46d993
    if (!cpu.flags.zf)
    {
        goto L_0x0046d993;
    }
    // 0046d98e  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046d991  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046d993:
    // 0046d993  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d994  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d996  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046d998  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046d99e  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046d9a4  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d9a6  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046d9a9  e832ffffff             -call 0x46d8e0
    cpu.esp -= 4;
    sub_46d8e0(app, cpu);
    // 0046d9ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d9c0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d9c3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d9c7  e8b48cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d9cc  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d9ce  e86d2cfbff             -call 0x420640
    cpu.esp -= 4;
    sub_420640(app, cpu);
    // 0046d9d3  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046d9d9  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046d9dd  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046d9e1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d9e5  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d9e8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d9eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46d9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d9f0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d9f3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d9f7  e8848cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d9fc  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d9fe  e8bd22fbff             -call 0x41fcc0
    cpu.esp -= 4;
    sub_41fcc0(app, cpu);
    // 0046da03  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046da09  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046da0d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046da11  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046da15  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046da18  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046da1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46da20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046da20  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0046da23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046da24  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046da26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046da27  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046da2b  e8508cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046da30  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046da32  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da34  e8478cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046da39  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046da3d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da3f  e83c8cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046da44  e847930000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046da49  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da4b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046da4d  e82e8cffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046da52  e839930000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046da57  83f8ff                 +cmp eax, -1
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
    // 0046da5a  7505                   -jne 0x46da61
    if (!cpu.flags.zf)
    {
        goto L_0x0046da61;
    }
    // 0046da5c  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046da5f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046da61:
    // 0046da61  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046da67  c744240cffffffff       -mov dword ptr [esp + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 0046da6f  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046da73  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046da76  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0046da7a  8b92d0000000           -mov edx, dword ptr [edx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0046da80  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046da84  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046da87  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0046da8d  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046da91  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0046da95  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046da98  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0046da9e  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0046daa2  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046daa5  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046daa9  e80212ffff             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0046daae  a12c845100             -mov eax, dword ptr [0x51842c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 0046dab3  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046dab5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046dab7  0f8ea5000000           -jle 0x46db62
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046db62;
    }
    // 0046dabd  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
L_0x0046dac3:
    // 0046dac3  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046dac6  39b8b4020000           +cmp dword ptr [eax + 0x2b4], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(692) /* 0x2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dacc  7570                   -jne 0x46db3e
    if (!cpu.flags.zf)
    {
        goto L_0x0046db3e;
    }
    // 0046dace  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046dad4  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046dad7  7465                   -je 0x46db3e
    if (cpu.flags.zf)
    {
        goto L_0x0046db3e;
    }
    // 0046dad9  f7c100000040           +test ecx, 0x40000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 1073741824 /*0x40000000*/));
    // 0046dadf  755d                   -jne 0x46db3e
    if (!cpu.flags.zf)
    {
        goto L_0x0046db3e;
    }
    // 0046dae1  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0046dae4  7458                   -je 0x46db3e
    if (cpu.flags.zf)
    {
        goto L_0x0046db3e;
    }
    // 0046dae6  8b88e8020000           -mov ecx, dword ptr [eax + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(744) /* 0x2e8 */);
    // 0046daec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046daee  754e                   -jne 0x46db3e
    if (!cpu.flags.zf)
    {
        goto L_0x0046db3e;
    }
    // 0046daf0  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0046daf4  d8a0d0000000           -fsub dword ptr [eax + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */));
    // 0046dafa  d95c2440               -fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046dafe  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046db01  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0046db05  d8a0d4000000           -fsub dword ptr [eax + 0xd4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */));
    // 0046db0b  d95c2444               -fstp dword ptr [esp + 0x44]
    app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046db0f  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046db12  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0046db16  d8a1d8000000           -fsub dword ptr [ecx + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */));
    // 0046db1c  8d4c243c               -lea ecx, [esp + 0x3c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046db20  d95c2448               -fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046db24  e897f1fdff             -call 0x44ccc0
    cpu.esp -= 4;
    sub_44ccc0(app, cpu);
    // 0046db29  d85c2408               -fcomp dword ptr [esp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 0046db2d  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046db33  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046db35  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0046db38  7a04                   -jp 0x46db3e
    if (cpu.flags.pf)
    {
        goto L_0x0046db3e;
    }
    // 0046db3a  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x0046db3e:
    // 0046db3e  a12c845100             -mov eax, dword ptr [0x51842c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 0046db43  46                     -inc esi
    (cpu.esi)++;
    // 0046db44  3bf0                   +cmp esi, eax
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
    // 0046db46  0f8c77ffffff           -jl 0x46dac3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046dac3;
    }
    // 0046db4c  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046db50  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046db54  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046db59  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db5a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db5b  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046db5e  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0046db61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046db62:
    // 0046db62  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046db66  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046db6a  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046db70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db72  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046db75  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0046db78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46db80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046db80  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046db83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046db84  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046db86  e8f58affff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046db8b  e800920000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046db90  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046db92  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046db96  e8e58affff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046db9b  e8f0910000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046dba0  8b0d90d34a00           -mov ecx, dword ptr [0x4ad390]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903824) /* 0x4ad390 */);
    // 0046dba6  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046dbaa  83f901                 +cmp ecx, 1
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
    // 0046dbad  7509                   -jne 0x46dbb8
    if (!cpu.flags.zf)
    {
        goto L_0x0046dbb8;
    }
    // 0046dbaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dbb0  83c408                 +add esp, 8
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
    // 0046dbb3  e90885fbff             -jmp 0x4260c0
    return sub_4260c0(app, cpu);
L_0x0046dbb8:
    // 0046dbb8  3d67120000             +cmp eax, 0x1267
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4711 /*0x1267*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dbbd  756a                   -jne 0x46dc29
    if (!cpu.flags.zf)
    {
        goto L_0x0046dc29;
    }
    // 0046dbbf  e8bcbefbff             -call 0x429a80
    cpu.esp -= 4;
    sub_429a80(app, cpu);
    // 0046dbc4  83f803                 +cmp eax, 3
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
    // 0046dbc7  7f1d                   -jg 0x46dbe6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046dbe6;
    }
    // 0046dbc9  b92c324a00             -mov ecx, 0x4a322c
    cpu.ecx = 4862508 /*0x4a322c*/;
    // 0046dbce  e8fd39fcff             -call 0x4315d0
    cpu.esp -= 4;
    sub_4315d0(app, cpu);
    // 0046dbd3  b9a4374900             -mov ecx, 0x4937a4
    cpu.ecx = 4798372 /*0x4937a4*/;
    // 0046dbd8  e8f339fcff             -call 0x4315d0
    cpu.esp -= 4;
    sub_4315d0(app, cpu);
    // 0046dbdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dbde  83c408                 +add esp, 8
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
    // 0046dbe1  e9da84fbff             -jmp 0x4260c0
    return sub_4260c0(app, cpu);
L_0x0046dbe6:
    // 0046dbe6  83f804                 +cmp eax, 4
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
    // 0046dbe9  7c1d                   -jl 0x46dc08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046dc08;
    }
    // 0046dbeb  b920324a00             -mov ecx, 0x4a3220
    cpu.ecx = 4862496 /*0x4a3220*/;
    // 0046dbf0  e8db39fcff             -call 0x4315d0
    cpu.esp -= 4;
    sub_4315d0(app, cpu);
    // 0046dbf5  b9a4374900             -mov ecx, 0x4937a4
    cpu.ecx = 4798372 /*0x4937a4*/;
    // 0046dbfa  e8d139fcff             -call 0x4315d0
    cpu.esp -= 4;
    sub_4315d0(app, cpu);
    // 0046dbff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dc00  83c408                 +add esp, 8
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
    // 0046dc03  e9b884fbff             -jmp 0x4260c0
    return sub_4260c0(app, cpu);
L_0x0046dc08:
    // 0046dc08  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046dc09  68ec314a00             -push 0x4a31ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862444 /*0x4a31ec*/;
    cpu.esp -= 4;
    // 0046dc0e  e8a4910000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046dc13  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dc16  b9a4374900             -mov ecx, 0x4937a4
    cpu.ecx = 4798372 /*0x4937a4*/;
    // 0046dc1b  e8b039fcff             -call 0x4315d0
    cpu.esp -= 4;
    sub_4315d0(app, cpu);
    // 0046dc20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dc21  83c408                 +add esp, 8
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
    // 0046dc24  e99784fbff             -jmp 0x4260c0
    return sub_4260c0(app, cpu);
L_0x0046dc29:
    // 0046dc29  83f8ff                 +cmp eax, -1
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
    // 0046dc2c  743b                   -je 0x46dc69
    if (cpu.flags.zf)
    {
        goto L_0x0046dc69;
    }
    // 0046dc2e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dc32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046dc34  7f0a                   -jg 0x46dc40
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046dc40;
    }
    // 0046dc36  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 0046dc3b  40                     -inc eax
    (cpu.eax)++;
    // 0046dc3c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0046dc40:
    // 0046dc40  6824c74800             -push 0x48c724
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769572 /*0x48c724*/;
    cpu.esp -= 4;
    // 0046dc45  68e0314a00             -push 0x4a31e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862432 /*0x4a31e0*/;
    cpu.esp -= 4;
    // 0046dc4a  e80fa00000             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 0046dc4f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dc51  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dc54  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046dc56  744a                   -je 0x46dca2
    if (cpu.flags.zf)
    {
        goto L_0x0046dca2;
    }
    // 0046dc58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dc59  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046dc5b  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046dc5f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0046dc61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046dc62  e8389b0000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0046dc67  eb27                   -jmp 0x46dc90
    goto L_0x0046dc90;
L_0x0046dc69:
    // 0046dc69  6808c74800             -push 0x48c708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769544 /*0x48c708*/;
    cpu.esp -= 4;
    // 0046dc6e  68e0314a00             -push 0x4a31e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862432 /*0x4a31e0*/;
    cpu.esp -= 4;
    // 0046dc73  e8e69f0000             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 0046dc78  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dc7a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dc7d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046dc7f  7421                   -je 0x46dca2
    if (cpu.flags.zf)
    {
        goto L_0x0046dca2;
    }
    // 0046dc81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dc82  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046dc84  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046dc88  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0046dc8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046dc8b  e8f8990000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
L_0x0046dc90:
    // 0046dc90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dc91  e841990000             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0046dc96  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046dc9a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046dc9d  e8ee8afbff             -call 0x426790
    cpu.esp -= 4;
    sub_426790(app, cpu);
L_0x0046dca2:
    // 0046dca2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dca3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dca6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46dcb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dcb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046dcb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dcb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046dcb3  e8488affff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046dcb8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dcba  e8418affff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046dcbf  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046dcc1  e83a8affff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046dcc6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046dcc7  e8f470feff             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0046dccc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046dccd  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046dccf  e8ec70feff             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0046dcd4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dcd5  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046dcd7  e8e470feff             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0046dcdc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046dcdf  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046dce1  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046dce3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046dce4  e8f7b9faff             -call 0x4196e0
    cpu.esp -= 4;
    sub_4196e0(app, cpu);
    // 0046dce9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dcea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dceb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dcec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46dcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dcf0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dcf3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dcf7  e88489ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046dcfc  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046dcfe  e88db9faff             -call 0x419690
    cpu.esp -= 4;
    sub_419690(app, cpu);
    // 0046dd03  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046dd09  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046dd0d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046dd11  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dd15  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046dd18  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dd1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46dd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dd20  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dd23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dd24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046dd25  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dd27  e85489ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046dd2c  e85f900000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046dd31  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dd33  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dd35  e84689ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046dd3a  e851900000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046dd3f  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046dd43  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046dd45  e83689ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046dd4a  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046dd4c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046dd4e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046dd50  e81b2bfbff             -call 0x420870
    cpu.esp -= 4;
    sub_420870(app, cpu);
    // 0046dd55  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046dd5b  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046dd5f  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0046dd63  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046dd67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd69  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046dd6c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dd6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46dd70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dd70  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dd73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dd74  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dd76  e80589ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046dd7b  e810900000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046dd80  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dd84  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dd86  e8f588ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046dd8b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046dd8d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046dd8f  e8cc2afbff             -call 0x420860
    cpu.esp -= 4;
    sub_420860(app, cpu);
    // 0046dd94  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046dd9a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046dd9e  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0046dda2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dda6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dda7  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ddaa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ddad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46ddb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ddb0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ddb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ddb4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ddb6  e8c588ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ddbb  e8d08f0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ddc0  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ddc4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ddc6  e8b588ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ddcb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046ddcd  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ddcf  e8dc2afbff             -call 0x4208b0
    cpu.esp -= 4;
    sub_4208b0(app, cpu);
    // 0046ddd4  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046ddda  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046ddde  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0046dde2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dde6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dde7  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ddea  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dded  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46ddf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ddf0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ddf3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ddf7  e88488ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ddfc  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ddfe  e85d2bfbff             -call 0x420960
    cpu.esp -= 4;
    sub_420960(app, cpu);
    // 0046de03  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046de09  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046de0d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046de11  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046de15  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046de18  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046de1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46de20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046de20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046de21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046de22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046de23  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046de25  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046de29  e85288ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046de2e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046de30  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046de32  e84988ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046de37  e8548f0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046de3c  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046de42  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046de44  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046de48  83feff                 +cmp esi, -1
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
    // 0046de4b  c7048100000000         -mov dword ptr [ecx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 0 /*0x0*/;
    // 0046de52  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046de58  7526                   -jne 0x46de80
    if (!cpu.flags.zf)
    {
        goto L_0x0046de80;
    }
    // 0046de5a  8b7f14                 -mov edi, dword ptr [edi + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046de5d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046de5f  741f                   -je 0x46de80
    if (cpu.flags.zf)
    {
        goto L_0x0046de80;
    }
    // 0046de61  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0046de66  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046de68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046de6a  7e10                   -jle 0x46de7c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046de7c;
    }
    // 0046de6c  8bbfec020000           -mov edi, dword ptr [edi + 0x2ec]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(748) /* 0x2ec */);
L_0x0046de72:
    // 0046de72  393cb1                 +cmp dword ptr [ecx + esi*4], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046de75  7405                   -je 0x46de7c
    if (cpu.flags.zf)
    {
        goto L_0x0046de7c;
    }
    // 0046de77  46                     -inc esi
    (cpu.esi)++;
    // 0046de78  3bf0                   +cmp esi, eax
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
    // 0046de7a  7cf6                   -jl 0x46de72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046de72;
    }
L_0x0046de7c:
    // 0046de7c  3bf0                   +cmp esi, eax
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
    // 0046de7e  7469                   -je 0x46dee9
    if (cpu.flags.zf)
    {
        goto L_0x0046dee9;
    }
L_0x0046de80:
    // 0046de80  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046de83  8b8284020000           -mov eax, dword ptr [edx + 0x284]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(644) /* 0x284 */);
    // 0046de89  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046de8b  7405                   -je 0x46de92
    if (cpu.flags.zf)
    {
        goto L_0x0046de92;
    }
    // 0046de8d  83f8ff                 +cmp eax, -1
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
    // 0046de90  7514                   -jne 0x46dea6
    if (!cpu.flags.zf)
    {
        goto L_0x0046dea6;
    }
L_0x0046de92:
    // 0046de92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046de93  6898274900             -push 0x492798
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794264 /*0x492798*/;
    cpu.esp -= 4;
    // 0046de98  e8736dfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046de9d  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046dea3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0046dea6:
    // 0046dea6  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046dea9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046deaf  8b8884020000           -mov ecx, dword ptr [eax + 0x284]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(644) /* 0x284 */);
    // 0046deb5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046deb7  8b348a                 -mov esi, dword ptr [edx + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0046deba  8a86e0020000           -mov al, byte ptr [esi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(736) /* 0x2e0 */);
    // 0046dec0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046dec1  6838324a00             -push 0x4a3238
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862520 /*0x4a3238*/;
    cpu.esp -= 4;
    // 0046dec6  e8ec8e0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046decb  8a86e0020000           -mov al, byte ptr [esi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(736) /* 0x2e0 */);
    // 0046ded1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ded4  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046ded6  7411                   -je 0x46dee9
    if (cpu.flags.zf)
    {
        goto L_0x0046dee9;
    }
    // 0046ded8  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dedc  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046dee2  c7048a0000803f         -mov dword ptr [edx + ecx*4], 0x3f800000
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = 1065353216 /*0x3f800000*/;
L_0x0046dee9:
    // 0046dee9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046deea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046deeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046deec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46def0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046def0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046def3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046def7  e88487ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046defc  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046defe  e86d19fbff             -call 0x41f870
    cpu.esp -= 4;
    sub_41f870(app, cpu);
    // 0046df03  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046df09  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046df0d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046df11  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046df15  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046df18  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046df1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46df20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046df20  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046df23  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046df27  e85487ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046df2c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046df2e  e8bd1dfbff             -call 0x41fcf0
    cpu.esp -= 4;
    sub_41fcf0(app, cpu);
    // 0046df33  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046df39  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046df3d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046df41  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046df45  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046df48  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046df4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46df50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046df50  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046df53  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046df57  e82487ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046df5c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046df5e  e8ad1dfbff             -call 0x41fd10
    cpu.esp -= 4;
    sub_41fd10(app, cpu);
    // 0046df63  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046df69  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046df6d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046df71  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046df75  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046df78  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046df7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46df80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046df80  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046df83  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046df87  e8f486ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046df8c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046df8e  e80d1dfbff             -call 0x41fca0
    cpu.esp -= 4;
    sub_41fca0(app, cpu);
    // 0046df93  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046df99  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046df9d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046dfa1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dfa5  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046dfa8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dfab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46dfb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dfb0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dfb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dfb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046dfb5  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046dfb7  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046dfbb  e8c086ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046dfc0  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046dfc2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dfc4  e8b786ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046dfc9  e8c28d0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046dfce  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dfd0  83feff                 +cmp esi, -1
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
    // 0046dfd3  7505                   -jne 0x46dfda
    if (!cpu.flags.zf)
    {
        goto L_0x0046dfda;
    }
    // 0046dfd5  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046dfd8  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046dfda:
    // 0046dfda  e8a11cfcff             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0046dfdf  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046dfe5  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046dfe7  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046dfea  8b82fc020000           -mov eax, dword ptr [edx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(764) /* 0x2fc */);
    // 0046dff0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046dff2  750d                   -jne 0x46e001
    if (!cpu.flags.zf)
    {
        goto L_0x0046e001;
    }
    // 0046dff4  6868324a00             -push 0x4a3268
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862568 /*0x4a3268*/;
    cpu.esp -= 4;
    // 0046dff9  e8126cfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046dffe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046e001:
    // 0046e001  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046e006  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046e009  8b81ec020000           -mov eax, dword ptr [ecx + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(748) /* 0x2ec */);
    // 0046e00f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e011  750d                   -jne 0x46e020
    if (!cpu.flags.zf)
    {
        goto L_0x0046e020;
    }
    // 0046e013  684c324a00             -push 0x4a324c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862540 /*0x4a324c*/;
    cpu.esp -= 4;
    // 0046e018  e8f36bfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046e01d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046e020:
    // 0046e020  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046e026  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046e029  8b88ec020000           -mov ecx, dword ptr [eax + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0046e02f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e031  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0046e034  8b8a80000000           -mov ecx, dword ptr [edx + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0046e03a  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e040  3bf9                   +cmp edi, ecx
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
    // 0046e042  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e046  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0046e049  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046e04d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e04e  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0046e052  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e053  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e056  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e059  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e060  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e063  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e067  e81486ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e06c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e06e  e8bd96fbff             -call 0x427730
    cpu.esp -= 4;
    sub_427730(app, cpu);
    // 0046e073  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e079  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e07d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046e081  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e085  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e088  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e08b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e090  e90bb9fbff             -jmp 0x4299a0
    return sub_4299a0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e0a0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e0a3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e0a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e0a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e0a9  e8d285ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e0ae  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e0b0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e0b2  e8c985ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e0b7  e8d48c0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e0bc  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046e0be  e83d86ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046e0c3  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 0046e0c8  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e0ca  e871e9fdff             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0046e0cf  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046e0d1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046e0d3  7536                   -jne 0x46e10b
    if (!cpu.flags.zf)
    {
        goto L_0x0046e10b;
    }
    // 0046e0d5  6890324a00             -push 0x4a3290
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862608 /*0x4a3290*/;
    cpu.esp -= 4;
    // 0046e0da  e8d88c0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046e0df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046e0e2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046e0e4  7e0e                   -jle 0x46e0f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e0f4;
    }
L_0x0046e0e6:
    // 0046e0e6  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046e0e8  e89385ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e0ed  d95c2408               +fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e0f1  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046e0f2  75f2                   -jne 0x46e0e6
    if (!cpu.flags.zf)
    {
        goto L_0x0046e0e6;
    }
L_0x0046e0f4:
    // 0046e0f4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e0f8  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e0fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e100  c7048100000000         -mov dword ptr [ecx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 0 /*0x0*/;
    // 0046e107  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e10a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e10b:
    // 0046e10b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046e10d  7e20                   -jle 0x46e12f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e12f;
    }
L_0x0046e10f:
    // 0046e10f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e111  e86a85ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e116  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e11a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e11b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046e11d  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e121  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0046e123  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e124  e876960000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0046e129  83c410                 +add esp, 0x10
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
    // 0046e12c  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046e12d  75e0                   -jne 0x46e10f
    if (!cpu.flags.zf)
    {
        goto L_0x0046e10f;
    }
L_0x0046e12f:
    // 0046e12f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e133  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e139  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e13a  c704810000803f         -mov dword ptr [ecx + eax*4], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 1065353216 /*0x3f800000*/;
    // 0046e141  e891940000             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0046e146  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046e149  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e14a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e14b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e14e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e150  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e151  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0046e153  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0046e156  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046e159  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e15a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e15b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e15c  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e160  e81b85ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e165  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e167  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e169  e81285ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e16e  e81d8c0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e173  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046e175  e88685ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046e17a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046e17c  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0046e181  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046e183  e8b8e8fdff             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0046e188  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046e18a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046e18c  7554                   -jne 0x46e1e2
    if (!cpu.flags.zf)
    {
        goto L_0x0046e1e2;
    }
    // 0046e18e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e18f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e190  68d8324a00             -push 0x4a32d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862680 /*0x4a32d8*/;
    cpu.esp -= 4;
    // 0046e195  e81d8c0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046e19a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046e19d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046e19f  7e29                   -jle 0x46e1ca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e1ca;
    }
L_0x0046e1a1:
    // 0046e1a1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e1a3  e8d884ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e1a8  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e1ac  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046e1b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e1b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e1b2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e1b5  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e1b8  68b4324a00             -push 0x4a32b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4862644 /*0x4a32b4*/;
    cpu.esp -= 4;
    // 0046e1bd  e8f58b0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046e1c2  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046e1c5  47                     -inc edi
    (cpu.edi)++;
    // 0046e1c6  3bfe                   +cmp edi, esi
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
    // 0046e1c8  7cd7                   -jl 0x46e1a1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046e1a1;
    }
L_0x0046e1ca:
    // 0046e1ca  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e1ce  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e1d4  c7048100000000         -mov dword ptr [ecx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 0 /*0x0*/;
    // 0046e1db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e1dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e1dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e1de  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046e1e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e1e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e1e2:
    // 0046e1e2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046e1e4  7e31                   -jle 0x46e217
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e217;
    }
L_0x0046e1e6:
    // 0046e1e6  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e1ea  e89184ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e1ef  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e1f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e1f4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046e1f6  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0046e1f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e1f9  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e1fb  e888940000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0046e200  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0046e204  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046e208  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e20e  83c410                 +add esp, 0x10
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
    // 0046e211  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046e212  d91c81                 +fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e215  75cf                   -jne 0x46e1e6
    if (!cpu.flags.zf)
    {
        goto L_0x0046e1e6;
    }
L_0x0046e217:
    // 0046e217  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e21b  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e220  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e221  c704900000803f         -mov dword ptr [eax + edx*4], 0x3f800000
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = 1065353216 /*0x3f800000*/;
    // 0046e228  e8aa930000             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0046e22d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046e230  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e231  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e232  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e233  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046e235  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e236  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e240  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046e242  e83984ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e247  e8448b0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e24c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e24e  e92d09fbff             -jmp 0x41eb80
    return sub_41eb80(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e260  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e263  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e267  e81484ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e26c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e26e  e8adc1faff             -call 0x41a420
    cpu.esp -= 4;
    sub_41a420(app, cpu);
    // 0046e273  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e279  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e27d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046e281  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e285  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e288  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e28b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e290  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046e293  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e297  e8e483ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e29c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e29e  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e2a2  e8d983ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e2a7  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e2a9  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e2ad  e8ce83ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e2b2  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e2b6  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e2ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e2bb  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e2bf  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e2c1  e8aa99faff             -call 0x417c70
    cpu.esp -= 4;
    sub_417c70(app, cpu);
    // 0046e2c6  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046e2ca  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e2d0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e2d4  d91c91                 -fstp dword ptr [ecx + edx*4]
    app->getMemory<float>(cpu.ecx + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e2d7  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0046e2db  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e2e0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e2e4  d91c88                 -fstp dword ptr [eax + ecx*4]
    app->getMemory<float>(cpu.eax + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e2e7  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0046e2eb  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e2ef  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e2f4  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e2f7  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046e2fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e300  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e301  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e302  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e304  e87783ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e309  e8828a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e30e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e310  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046e312  e86983ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e317  e8748a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e31c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e31e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046e320  e85b83ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e325  e8668a0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e32a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e32b  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046e32d  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e32f  e8cc98faff             -call 0x417c00
    cpu.esp -= 4;
    sub_417c00(app, cpu);
    // 0046e334  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e335  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e336  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e340  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e343  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e347  e83483ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e34c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e34e  e86db7fbff             -call 0x429ac0
    cpu.esp -= 4;
    sub_429ac0(app, cpu);
    // 0046e353  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e359  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e35d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046e361  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e365  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e368  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e36b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e370  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e373  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e377  e80483ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e37c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e37e  e8fdb6fbff             -call 0x429a80
    cpu.esp -= 4;
    sub_429a80(app, cpu);
    // 0046e383  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e389  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e38d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046e391  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e395  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e398  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e39b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e3a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e3a1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046e3a3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e3a5  e8d682ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e3aa  e8e1890000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e3af  83f8ff                 +cmp eax, -1
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
    // 0046e3b2  7505                   -jne 0x46e3b9
    if (!cpu.flags.zf)
    {
        goto L_0x0046e3b9;
    }
    // 0046e3b4  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046e3b7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046e3b9:
    // 0046e3b9  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046e3bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3c0  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046e3c3  e9782cfcff             -jmp 0x431040
    return sub_431040(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e3d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e3d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046e3d3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e3d5  e8a682ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e3da  e8b1890000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e3df  83f8ff                 +cmp eax, -1
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
    // 0046e3e2  7505                   -jne 0x46e3e9
    if (!cpu.flags.zf)
    {
        goto L_0x0046e3e9;
    }
    // 0046e3e4  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046e3e7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046e3e9:
    // 0046e3e9  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046e3ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3f0  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046e3f3  e9882dfcff             -jmp 0x431180
    return sub_431180(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e400  e8fb82ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046e405  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e407  e9e4acfaff             -jmp 0x4190f0
    return sub_4190f0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e410  e93badfaff             -jmp 0x419150
    return sub_419150(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e420  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e421  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046e423  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e424  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e426  e85582ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e42b  e860890000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e430  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e432  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046e434  e84782ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e439  e852890000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e43e  83f8ff                 +cmp eax, -1
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
    // 0046e441  7505                   -jne 0x46e448
    if (!cpu.flags.zf)
    {
        goto L_0x0046e448;
    }
    // 0046e443  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046e446  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046e448:
    // 0046e448  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046e44e  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046e450  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e451  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e452  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046e455  e92628fbff             -jmp 0x420c80
    return sub_420c80(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e460  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046e462  e81982ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e467  e824890000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046e46c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e46e  e93d28fbff             -jmp 0x420cb0
    return sub_420cb0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e480  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e481  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e483  e8f881ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e488  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e48c  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e490  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e491  e88a27fbff             -call 0x420c20
    cpu.esp -= 4;
    sub_420c20(app, cpu);
    // 0046e496  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e497  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e4a0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046e4a5  e84684faff             -call 0x4168f0
    cpu.esp -= 4;
    sub_4168f0(app, cpu);
    // 0046e4aa  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046e4ac  b90c334a00             -mov ecx, 0x4a330c
    cpu.ecx = 4862732 /*0x4a330c*/;
    // 0046e4b1  e98aabfaff             -jmp 0x419040
    return sub_419040(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e4c0  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0046e4c5  e82684faff             -call 0x4168f0
    cpu.esp -= 4;
    sub_4168f0(app, cpu);
    // 0046e4ca  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046e4cc  b90c334a00             -mov ecx, 0x4a330c
    cpu.ecx = 4862732 /*0x4a330c*/;
    // 0046e4d1  e96aabfaff             -jmp 0x419040
    return sub_419040(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e4e0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e4e3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e4e7  e89481ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e4ec  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e4ee  e80d84faff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 0046e4f3  f7d8                   +neg eax
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
    // 0046e4f5  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e4fb  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0046e4fd  40                     -inc eax
    (cpu.eax)++;
    // 0046e4fe  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e502  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e506  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046e50a  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e50d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e510  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46e520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e520  e85b07fbff             -call 0x41ec80
    cpu.esp -= 4;
    sub_41ec80(app, cpu);
    // 0046e525  e986b7fbff             -jmp 0x429cb0
    return sub_429cb0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46e530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e530  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e533  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e537  e84481ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e53c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e53e  e83d17fcff             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0046e543  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046e549  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e54d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046e551  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e555  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e558  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e55b  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
