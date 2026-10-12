#include "menu.h"
namespace menu
{

/* align: skip  */
void Application::asm_sub_41a8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a8e0  8b0d7c3f4500           -mov ecx, dword ptr [0x453f7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538236) /* 0x453f7c */);
    // 0041a8e6  e8658cfeff             -call 0x403550
    cpu.esp -= 4;
    sub_403550(app, cpu);
    // 0041a8eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041a8ed  740b                   -je 0x41a8fa
    if (cpu.flags.zf)
    {
        goto L_0x0041a8fa;
    }
    // 0041a8ef  8a80ac000000           -mov al, byte ptr [eax + 0xac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0041a8f5  a210574900             -mov byte ptr [0x495710], al
    app->getMemory<x86::reg8>(x86::reg32(4806416) /* 0x495710 */) = cpu.al;
L_0x0041a8fa:
    // 0041a8fa  c6051157490000         -mov byte ptr [0x495711], 0
    app->getMemory<x86::reg8>(x86::reg32(4806417) /* 0x495711 */) = 0 /*0x0*/;
    // 0041a901  8b0d10574900           -mov ecx, dword ptr [0x495710]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4806416) /* 0x495710 */);
    // 0041a907  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041a90d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041a90e  68c4b44300             -push 0x43b4c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437188 /*0x43b4c4*/;
    cpu.esp -= 4;
    // 0041a913  e87ca80000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041a918  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041a91b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41a920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041a921  68b4a44300             -push 0x43a4b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433076 /*0x43a4b4*/;
    cpu.esp -= 4;
    // 0041a926  e8c5b3feff             -call 0x405cf0
    cpu.esp -= 4;
    sub_405cf0(app, cpu);
    // 0041a92b  8b0d7c3f4500           -mov ecx, dword ptr [0x453f7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538236) /* 0x453f7c */);
    // 0041a931  a30c404500             -mov dword ptr [0x45400c], eax
    app->getMemory<x86::reg32>(x86::reg32(4538380) /* 0x45400c */) = cpu.eax;
    // 0041a936  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041a937  680ca54300             -push 0x43a50c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433164 /*0x43a50c*/;
    cpu.esp -= 4;
    // 0041a93c  68c4a44300             -push 0x43a4c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433092 /*0x43a4c4*/;
    cpu.esp -= 4;
    // 0041a941  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041a942  e889b8feff             -call 0x4061d0
    cpu.esp -= 4;
    sub_4061d0(app, cpu);
    // 0041a947  8b15883f4500           -mov edx, dword ptr [0x453f88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538248) /* 0x453f88 */);
    // 0041a94d  a33c3f4500             -mov dword ptr [0x453f3c], eax
    app->getMemory<x86::reg32>(x86::reg32(4538172) /* 0x453f3c */) = cpu.eax;
    // 0041a952  a10c404500             -mov eax, dword ptr [0x45400c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538380) /* 0x45400c */);
    // 0041a957  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041a958  6838a54300             -push 0x43a538
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433208 /*0x43a538*/;
    cpu.esp -= 4;
    // 0041a95d  68d0a44300             -push 0x43a4d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433104 /*0x43a4d0*/;
    cpu.esp -= 4;
    // 0041a962  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041a963  e868b8feff             -call 0x4061d0
    cpu.esp -= 4;
    sub_4061d0(app, cpu);
    // 0041a968  8b0db8784600           -mov ecx, dword ptr [0x4678b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618424) /* 0x4678b8 */);
    // 0041a96e  8b150c404500           -mov edx, dword ptr [0x45400c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538380) /* 0x45400c */);
    // 0041a974  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041a975  6864a54300             -push 0x43a564
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433252 /*0x43a564*/;
    cpu.esp -= 4;
    // 0041a97a  68e0a44300             -push 0x43a4e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433120 /*0x43a4e0*/;
    cpu.esp -= 4;
    // 0041a97f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041a980  a3c83f4500             -mov dword ptr [0x453fc8], eax
    app->getMemory<x86::reg32>(x86::reg32(4538312) /* 0x453fc8 */) = cpu.eax;
    // 0041a985  e886bafeff             -call 0x406410
    cpu.esp -= 4;
    sub_406410(app, cpu);
    // 0041a98a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041a98c  a3c8784600             -mov dword ptr [0x4678c8], eax
    app->getMemory<x86::reg32>(x86::reg32(4618440) /* 0x4678c8 */) = cpu.eax;
    // 0041a991  a10c404500             -mov eax, dword ptr [0x45400c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538380) /* 0x45400c */);
    // 0041a996  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041a997  68fca54300             -push 0x43a5fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433404 /*0x43a5fc*/;
    cpu.esp -= 4;
    // 0041a99c  6800a54300             -push 0x43a500
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433152 /*0x43a500*/;
    cpu.esp -= 4;
    // 0041a9a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041a9a2  e829b8feff             -call 0x4061d0
    cpu.esp -= 4;
    sub_4061d0(app, cpu);
    // 0041a9a7  8b0d0c404500           -mov ecx, dword ptr [0x45400c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538380) /* 0x45400c */);
    // 0041a9ad  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041a9b0  a31c794600             -mov dword ptr [0x46791c], eax
    app->getMemory<x86::reg32>(x86::reg32(4618524) /* 0x46791c */) = cpu.eax;
    // 0041a9b5  6868e44300             -push 0x43e468
    app->getMemory<x86::reg32>(cpu.esp-4) = 4449384 /*0x43e468*/;
    cpu.esp -= 4;
    // 0041a9ba  68b0a54300             -push 0x43a5b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433328 /*0x43a5b0*/;
    cpu.esp -= 4;
    // 0041a9bf  68f0a44300             -push 0x43a4f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433136 /*0x43a4f0*/;
    cpu.esp -= 4;
    // 0041a9c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041a9c5  e846bafeff             -call 0x406410
    cpu.esp -= 4;
    sub_406410(app, cpu);
    // 0041a9ca  a318404500             -mov dword ptr [0x454018], eax
    app->getMemory<x86::reg32>(x86::reg32(4538392) /* 0x454018 */) = cpu.eax;
    // 0041a9cf  a1ec7f4600             -mov eax, dword ptr [0x467fec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4620268) /* 0x467fec */);
    // 0041a9d4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041a9d7  3bc3                   +cmp eax, ebx
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
    // 0041a9d9  7419                   -je 0x41a9f4
    if (cpu.flags.zf)
    {
        goto L_0x0041a9f4;
    }
    // 0041a9db  8b15c8784600           -mov edx, dword ptr [0x4678c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618440) /* 0x4678c8 */);
    // 0041a9e1  889a9c000000           -mov byte ptr [edx + 0x9c], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(156) /* 0x9c */) = cpu.bl;
    // 0041a9e7  a118404500             -mov eax, dword ptr [0x454018]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538392) /* 0x454018 */);
    // 0041a9ec  88989c000000           -mov byte ptr [eax + 0x9c], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(156) /* 0x9c */) = cpu.bl;
    // 0041a9f2  eb6e                   -jmp 0x41aa62
    goto L_0x0041aa62;
L_0x0041a9f4:
    // 0041a9f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a9f5  8b35c8784600           -mov esi, dword ptr [0x4678c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4618440) /* 0x4678c8 */);
    // 0041a9fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a9fc  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041a9fe  399ea0000000           +cmp dword ptr [esi + 0xa0], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041aa04  7e1e                   -jle 0x41aa24
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041aa24;
    }
L_0x0041aa06:
    // 0041aa06  8b8ea4000000           -mov ecx, dword ptr [esi + 0xa4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0041aa0c  8b0cb9                 -mov ecx, dword ptr [ecx + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edi * 4);
    // 0041aa0f  3bcb                   +cmp ecx, ebx
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
    // 0041aa11  7406                   -je 0x41aa19
    if (cpu.flags.zf)
    {
        goto L_0x0041aa19;
    }
    // 0041aa13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041aa14  e8378dfeff             -call 0x403750
    cpu.esp -= 4;
    sub_403750(app, cpu);
L_0x0041aa19:
    // 0041aa19  8b86a0000000           -mov eax, dword ptr [esi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 0041aa1f  47                     -inc edi
    (cpu.edi)++;
    // 0041aa20  3bf8                   +cmp edi, eax
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
    // 0041aa22  7ce2                   -jl 0x41aa06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041aa06;
    }
L_0x0041aa24:
    // 0041aa24  c6869c00000001         -mov byte ptr [esi + 0x9c], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 0041aa2b  8b3518404500           -mov esi, dword ptr [0x454018]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4538392) /* 0x454018 */);
    // 0041aa31  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041aa33  399ea0000000           +cmp dword ptr [esi + 0xa0], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041aa39  7e1e                   -jle 0x41aa59
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041aa59;
    }
L_0x0041aa3b:
    // 0041aa3b  8b96a4000000           -mov edx, dword ptr [esi + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0041aa41  8b0cba                 -mov ecx, dword ptr [edx + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 0041aa44  3bcb                   +cmp ecx, ebx
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
    // 0041aa46  7406                   -je 0x41aa4e
    if (cpu.flags.zf)
    {
        goto L_0x0041aa4e;
    }
    // 0041aa48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041aa49  e8028dfeff             -call 0x403750
    cpu.esp -= 4;
    sub_403750(app, cpu);
L_0x0041aa4e:
    // 0041aa4e  8b86a0000000           -mov eax, dword ptr [esi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 0041aa54  47                     -inc edi
    (cpu.edi)++;
    // 0041aa55  3bf8                   +cmp edi, eax
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
    // 0041aa57  7ce2                   -jl 0x41aa3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041aa3b;
    }
L_0x0041aa59:
    // 0041aa59  c6869c00000001         -mov byte ptr [esi + 0x9c], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 0041aa60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041aa61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041aa62:
    // 0041aa62  a13c3f4500             -mov eax, dword ptr [0x453f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538172) /* 0x453f3c */);
    // 0041aa67  8b0dc83f4500           -mov ecx, dword ptr [0x453fc8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538312) /* 0x453fc8 */);
    // 0041aa6d  8b151c794600           -mov edx, dword ptr [0x46791c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618524) /* 0x46791c */);
    // 0041aa73  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041aa76  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041aa79  89583c                 -mov dword ptr [eax + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0041aa7c  895840                 -mov dword ptr [eax + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0041aa7f  a1c83f4500             -mov eax, dword ptr [0x453fc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538312) /* 0x453fc8 */);
    // 0041aa84  8b0dc8784600           -mov ecx, dword ptr [0x4678c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618440) /* 0x4678c8 */);
    // 0041aa8a  8b153c3f4500           -mov edx, dword ptr [0x453f3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538172) /* 0x453f3c */);
    // 0041aa90  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041aa93  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041aa96  89583c                 -mov dword ptr [eax + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0041aa99  895840                 -mov dword ptr [eax + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0041aa9c  a1c8784600             -mov eax, dword ptr [0x4678c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618440) /* 0x4678c8 */);
    // 0041aaa1  8b0d1c794600           -mov ecx, dword ptr [0x46791c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618524) /* 0x46791c */);
    // 0041aaa7  8b15c83f4500           -mov edx, dword ptr [0x453fc8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538312) /* 0x453fc8 */);
    // 0041aaad  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041aab0  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041aab3  89583c                 -mov dword ptr [eax + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0041aab6  895840                 -mov dword ptr [eax + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0041aab9  a11c794600             -mov eax, dword ptr [0x46791c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618524) /* 0x46791c */);
    // 0041aabe  8b0d3c3f4500           -mov ecx, dword ptr [0x453f3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538172) /* 0x453f3c */);
    // 0041aac4  8b15c8784600           -mov edx, dword ptr [0x4678c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618440) /* 0x4678c8 */);
    // 0041aaca  89583c                 -mov dword ptr [eax + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0041aacd  895840                 -mov dword ptr [eax + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0041aad0  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041aad3  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041aad6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041aad7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41aae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041aae0  68f0b44300             -push 0x43b4f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437232 /*0x43b4f0*/;
    cpu.esp -= 4;
    // 0041aae5  e8aaa60000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041aaea  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041aaef  e807a90000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041aaf4  a1bc394900             -mov eax, dword ptr [0x4939bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798908) /* 0x4939bc */);
    // 0041aaf9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041aafc  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041aafe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041aaff  ff514c                 -call dword ptr [ecx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ab02  a1bc394900             -mov eax, dword ptr [0x4939bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798908) /* 0x4939bc */);
    // 0041ab07  8b0d0c3a4900           -mov ecx, dword ptr [0x493a0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 0041ab0d  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0041ab0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ab10  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041ab12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ab13  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ab16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041ab18  687cac4300             -push 0x43ac7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4435068 /*0x43ac7c*/;
    cpu.esp -= 4;
    // 0041ab1d  6878ac4300             -push 0x43ac78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4435064 /*0x43ac78*/;
    cpu.esp -= 4;
    // 0041ab22  6874ac4300             -push 0x43ac74
    app->getMemory<x86::reg32>(cpu.esp-4) = 4435060 /*0x43ac74*/;
    cpu.esp -= 4;
    // 0041ab27  6870ac4300             -push 0x43ac70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4435056 /*0x43ac70*/;
    cpu.esp -= 4;
    // 0041ab2c  68dcb44300             -push 0x43b4dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437212 /*0x43b4dc*/;
    cpu.esp -= 4;
    // 0041ab31  684cac4300             -push 0x43ac4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4435020 /*0x43ac4c*/;
    cpu.esp -= 4;
    // 0041ab36  684cac4300             -push 0x43ac4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4435020 /*0x43ac4c*/;
    cpu.esp -= 4;
    // 0041ab3b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041ab3d  e8d2b20000             -call 0x425e14
    cpu.esp -= 4;
    sub_425e14(app, cpu);
    // 0041ab42  a1bc394900             -mov eax, dword ptr [0x4939bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798908) /* 0x4939bc */);
    // 0041ab47  8b0d0c3a4900           -mov ecx, dword ptr [0x493a0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 0041ab4d  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0041ab50  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041ab52  6a53                   -push 0x53
    app->getMemory<x86::reg32>(cpu.esp-4) = 83 /*0x53*/;
    cpu.esp -= 4;
    // 0041ab54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ab55  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ab56  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ab59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ab5b  7417                   -je 0x41ab74
    if (cpu.flags.zf)
    {
        goto L_0x0041ab74;
    }
    // 0041ab5d  68b8ab4300             -push 0x43abb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434872 /*0x43abb8*/;
    cpu.esp -= 4;
    // 0041ab62  e82da60000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ab67  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ab6c  e88aa80000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ab71  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041ab74:
    // 0041ab74  a1bc394900             -mov eax, dword ptr [0x4939bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798908) /* 0x4939bc */);
    // 0041ab79  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0041ab7b  68e0010000             -push 0x1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 0041ab80  6880020000             -push 0x280
    app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 0041ab85  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041ab87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ab88  ff5254                 -call dword ptr [edx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ab8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ab8d  7417                   -je 0x41aba6
    if (cpu.flags.zf)
    {
        goto L_0x0041aba6;
    }
    // 0041ab8f  689cab4300             -push 0x43ab9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434844 /*0x43ab9c*/;
    cpu.esp -= 4;
    // 0041ab94  e8fba50000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ab99  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ab9e  e858a80000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041aba3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041aba6:
    // 0041aba6  680cac4300             -push 0x43ac0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434956 /*0x43ac0c*/;
    cpu.esp -= 4;
    // 0041abab  e8e4a50000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041abb0  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041abb5  e841a80000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041abba  a10c3a4900             -mov eax, dword ptr [0x493a0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 0041abbf  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041abc2  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0041abc4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041abc5  ff152c014300           -call dword ptr [0x43012c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391212) /* 0x43012c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041abcb  e860a5feff             -call 0x405130
    cpu.esp -= 4;
    sub_405130(app, cpu);
    // 0041abd0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041abd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41abe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041abe0  e89badfeff             -call 0x405980
    cpu.esp -= 4;
    sub_405980(app, cpu);
    // 0041abe5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041abe9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41abf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041abf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041abf1  6828a64300             -push 0x43a628
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433448 /*0x43a628*/;
    cpu.esp -= 4;
    // 0041abf6  e8f5b0feff             -call 0x405cf0
    cpu.esp -= 4;
    sub_405cf0(app, cpu);
    // 0041abfb  8b0d3c3f4500           -mov ecx, dword ptr [0x453f3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538172) /* 0x453f3c */);
    // 0041ac01  a3dc784600             -mov dword ptr [0x4678dc], eax
    app->getMemory<x86::reg32>(x86::reg32(4618460) /* 0x4678dc */) = cpu.eax;
    // 0041ac06  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ac07  687ca64300             -push 0x43a67c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433532 /*0x43a67c*/;
    cpu.esp -= 4;
    // 0041ac0c  6834a64300             -push 0x43a634
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433460 /*0x43a634*/;
    cpu.esp -= 4;
    // 0041ac11  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ac12  e8b9b5feff             -call 0x4061d0
    cpu.esp -= 4;
    sub_4061d0(app, cpu);
    // 0041ac17  8b15b4784600           -mov edx, dword ptr [0x4678b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618420) /* 0x4678b4 */);
    // 0041ac1d  a374794600             -mov dword ptr [0x467974], eax
    app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */) = cpu.eax;
    // 0041ac22  a1dc784600             -mov eax, dword ptr [0x4678dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618460) /* 0x4678dc */);
    // 0041ac27  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041ac28  68a8a64300             -push 0x43a6a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433576 /*0x43a6a8*/;
    cpu.esp -= 4;
    // 0041ac2d  6840a64300             -push 0x43a640
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433472 /*0x43a640*/;
    cpu.esp -= 4;
    // 0041ac32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ac33  e898b5feff             -call 0x4061d0
    cpu.esp -= 4;
    sub_4061d0(app, cpu);
    // 0041ac38  8b0d18794600           -mov ecx, dword ptr [0x467918]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618520) /* 0x467918 */);
    // 0041ac3e  8b15dc784600           -mov edx, dword ptr [0x4678dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618460) /* 0x4678dc */);
    // 0041ac44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ac45  68d4a64300             -push 0x43a6d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433620 /*0x43a6d4*/;
    cpu.esp -= 4;
    // 0041ac4a  684ca64300             -push 0x43a64c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433484 /*0x43a64c*/;
    cpu.esp -= 4;
    // 0041ac4f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041ac50  a3e83f4500             -mov dword ptr [0x453fe8], eax
    app->getMemory<x86::reg32>(x86::reg32(4538344) /* 0x453fe8 */) = cpu.eax;
    // 0041ac55  e876b5feff             -call 0x4061d0
    cpu.esp -= 4;
    sub_4061d0(app, cpu);
    // 0041ac5a  a35c794600             -mov dword ptr [0x46795c], eax
    app->getMemory<x86::reg32>(x86::reg32(4618588) /* 0x46795c */) = cpu.eax;
    // 0041ac5f  a1dc784600             -mov eax, dword ptr [0x4678dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618460) /* 0x4678dc */);
    // 0041ac64  68e0aa4100             -push 0x41aae0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4303584 /*0x41aae0*/;
    cpu.esp -= 4;
    // 0041ac69  6800a74300             -push 0x43a700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433664 /*0x43a700*/;
    cpu.esp -= 4;
    // 0041ac6e  6858a64300             -push 0x43a658
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433496 /*0x43a658*/;
    cpu.esp -= 4;
    // 0041ac73  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ac74  e817b3feff             -call 0x405f90
    cpu.esp -= 4;
    sub_405f90(app, cpu);
    // 0041ac79  8b0ddc784600           -mov ecx, dword ptr [0x4678dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618460) /* 0x4678dc */);
    // 0041ac7f  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041ac82  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041ac84  a3543f4500             -mov dword ptr [0x453f54], eax
    app->getMemory<x86::reg32>(x86::reg32(4538196) /* 0x453f54 */) = cpu.eax;
    // 0041ac89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ac8a  682ca74300             -push 0x43a72c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433708 /*0x43a72c*/;
    cpu.esp -= 4;
    // 0041ac8f  6864a64300             -push 0x43a664
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433508 /*0x43a664*/;
    cpu.esp -= 4;
    // 0041ac94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ac95  e836b5feff             -call 0x4061d0
    cpu.esp -= 4;
    sub_4061d0(app, cpu);
    // 0041ac9a  8b15dc784600           -mov edx, dword ptr [0x4678dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618460) /* 0x4678dc */);
    // 0041aca0  68e0ab4100             -push 0x41abe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4303840 /*0x41abe0*/;
    cpu.esp -= 4;
    // 0041aca5  6858a74300             -push 0x43a758
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433752 /*0x43a758*/;
    cpu.esp -= 4;
    // 0041acaa  6870a64300             -push 0x43a670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433520 /*0x43a670*/;
    cpu.esp -= 4;
    // 0041acaf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041acb0  a3703f4500             -mov dword ptr [0x453f70], eax
    app->getMemory<x86::reg32>(x86::reg32(4538224) /* 0x453f70 */) = cpu.eax;
    // 0041acb5  e8d6b2feff             -call 0x405f90
    cpu.esp -= 4;
    sub_405f90(app, cpu);
    // 0041acba  8b0d74794600           -mov ecx, dword ptr [0x467974]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */);
    // 0041acc0  8b15e83f4500           -mov edx, dword ptr [0x453fe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538344) /* 0x453fe8 */);
    // 0041acc6  a3783f4500             -mov dword ptr [0x453f78], eax
    app->getMemory<x86::reg32>(x86::reg32(4538232) /* 0x453f78 */) = cpu.eax;
    // 0041accb  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041acce  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0041acd1  895138                 -mov dword ptr [ecx + 0x38], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0041acd4  89713c                 -mov dword ptr [ecx + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0041acd7  897140                 -mov dword ptr [ecx + 0x40], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0041acda  a1e83f4500             -mov eax, dword ptr [0x453fe8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538344) /* 0x453fe8 */);
    // 0041acdf  8b0d5c794600           -mov ecx, dword ptr [0x46795c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618588) /* 0x46795c */);
    // 0041ace5  8b1574794600           -mov edx, dword ptr [0x467974]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */);
    // 0041aceb  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041acee  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041acf1  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0041acf4  897040                 -mov dword ptr [eax + 0x40], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0041acf7  a15c794600             -mov eax, dword ptr [0x46795c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618588) /* 0x46795c */);
    // 0041acfc  8b0d543f4500           -mov ecx, dword ptr [0x453f54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538196) /* 0x453f54 */);
    // 0041ad02  8b15e83f4500           -mov edx, dword ptr [0x453fe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538344) /* 0x453fe8 */);
    // 0041ad08  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041ad0b  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041ad0e  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0041ad11  897040                 -mov dword ptr [eax + 0x40], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0041ad14  a1543f4500             -mov eax, dword ptr [0x453f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538196) /* 0x453f54 */);
    // 0041ad19  8b0d703f4500           -mov ecx, dword ptr [0x453f70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538224) /* 0x453f70 */);
    // 0041ad1f  8b155c794600           -mov edx, dword ptr [0x46795c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618588) /* 0x46795c */);
    // 0041ad25  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041ad28  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041ad2b  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0041ad2e  897040                 -mov dword ptr [eax + 0x40], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0041ad31  8b0d783f4500           -mov ecx, dword ptr [0x453f78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538232) /* 0x453f78 */);
    // 0041ad37  a1703f4500             -mov eax, dword ptr [0x453f70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538224) /* 0x453f70 */);
    // 0041ad3c  8b15543f4500           -mov edx, dword ptr [0x453f54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538196) /* 0x453f54 */);
    // 0041ad42  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041ad45  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041ad48  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0041ad4b  897040                 -mov dword ptr [eax + 0x40], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0041ad4e  a1783f4500             -mov eax, dword ptr [0x453f78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538232) /* 0x453f78 */);
    // 0041ad53  8b0d74794600           -mov ecx, dword ptr [0x467974]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */);
    // 0041ad59  8b15703f4500           -mov edx, dword ptr [0x453f70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538224) /* 0x453f70 */);
    // 0041ad5f  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0041ad62  897040                 -mov dword ptr [eax + 0x40], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0041ad65  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041ad68  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0041ad6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ad6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41ad70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ad70  68fcb54300             -push 0x43b5fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437500 /*0x43b5fc*/;
    cpu.esp -= 4;
    // 0041ad75  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041ad7a  e815a40000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ad7f  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ad84  e872a60000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ad89  e862b5ffff             -call 0x4162f0
    cpu.esp -= 4;
    sub_4162f0(app, cpu);
    // 0041ad8e  68e8b54300             -push 0x43b5e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437480 /*0x43b5e8*/;
    cpu.esp -= 4;
    // 0041ad93  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041ad98  e8f7a30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ad9d  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ada2  e854a60000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ada7  e864bcffff             -call 0x416a10
    cpu.esp -= 4;
    sub_416a10(app, cpu);
    // 0041adac  68d8b54300             -push 0x43b5d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437464 /*0x43b5d8*/;
    cpu.esp -= 4;
    // 0041adb1  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041adb6  e8d9a30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041adbb  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041adc0  e836a60000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041adc5  e8f6bcffff             -call 0x416ac0
    cpu.esp -= 4;
    sub_416ac0(app, cpu);
    // 0041adca  68c4b54300             -push 0x43b5c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437444 /*0x43b5c4*/;
    cpu.esp -= 4;
    // 0041adcf  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041add4  e8bba30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041add9  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041adde  e818a60000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ade3  e818ddffff             -call 0x418b00
    cpu.esp -= 4;
    sub_418b00(app, cpu);
    // 0041ade8  68b0b54300             -push 0x43b5b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437424 /*0x43b5b0*/;
    cpu.esp -= 4;
    // 0041aded  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041adf2  e89da30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041adf7  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041adfc  e8faa50000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ae01  e80ae3ffff             -call 0x419110
    cpu.esp -= 4;
    sub_419110(app, cpu);
    // 0041ae06  689cb54300             -push 0x43b59c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437404 /*0x43b59c*/;
    cpu.esp -= 4;
    // 0041ae0b  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041ae10  e87fa30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ae15  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041ae18  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ae1d  e8d9a50000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ae22  e819ecffff             -call 0x419a40
    cpu.esp -= 4;
    sub_419a40(app, cpu);
    // 0041ae27  6888b54300             -push 0x43b588
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437384 /*0x43b588*/;
    cpu.esp -= 4;
    // 0041ae2c  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041ae31  e85ea30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ae36  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ae3b  e8bba50000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ae40  e8cbecffff             -call 0x419b10
    cpu.esp -= 4;
    sub_419b10(app, cpu);
    // 0041ae45  6874b54300             -push 0x43b574
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437364 /*0x43b574*/;
    cpu.esp -= 4;
    // 0041ae4a  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041ae4f  e840a30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ae54  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ae59  e89da50000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ae5e  e8bdf2ffff             -call 0x41a120
    cpu.esp -= 4;
    sub_41a120(app, cpu);
    // 0041ae63  6860b54300             -push 0x43b560
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437344 /*0x43b560*/;
    cpu.esp -= 4;
    // 0041ae68  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041ae6d  e822a30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ae72  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ae77  e87fa50000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ae7c  e88ff9ffff             -call 0x41a810
    cpu.esp -= 4;
    sub_41a810(app, cpu);
    // 0041ae81  684cb54300             -push 0x43b54c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437324 /*0x43b54c*/;
    cpu.esp -= 4;
    // 0041ae86  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041ae8b  e804a30000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041ae90  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041ae95  e861a50000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041ae9a  e881faffff             -call 0x41a920
    cpu.esp -= 4;
    sub_41a920(app, cpu);
    // 0041ae9f  6820b54300             -push 0x43b520
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437280 /*0x43b520*/;
    cpu.esp -= 4;
    // 0041aea4  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041aea9  e8e6a20000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041aeae  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041aeb3  e843a50000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041aeb8  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041aebb  e830fdffff             -call 0x41abf0
    cpu.esp -= 4;
    sub_41abf0(app, cpu);
    // 0041aec0  a1703f4500             -mov eax, dword ptr [0x453f70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538224) /* 0x453f70 */);
    // 0041aec5  c780a800000088e04300   -mov dword ptr [eax + 0xa8], 0x43e088
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 4448392 /*0x43e088*/;
    // 0041aecf  8b151c794600           -mov edx, dword ptr [0x46791c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618524) /* 0x46791c */);
    // 0041aed5  8b0d74794600           -mov ecx, dword ptr [0x467974]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */);
    // 0041aedb  898aa8000000           -mov dword ptr [edx + 0xa8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.ecx;
    // 0041aee1  a1e03f4500             -mov eax, dword ptr [0x453fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538336) /* 0x453fe0 */);
    // 0041aee6  8b0d3c3f4500           -mov ecx, dword ptr [0x453f3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538172) /* 0x453f3c */);
    // 0041aeec  8988a8000000           -mov dword ptr [eax + 0xa8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = cpu.ecx;
    // 0041aef2  8b15883f4500           -mov edx, dword ptr [0x453f88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538248) /* 0x453f88 */);
    // 0041aef8  a1c83f4500             -mov eax, dword ptr [0x453fc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538312) /* 0x453fc8 */);
    // 0041aefd  8982a8000000           -mov dword ptr [edx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0041af03  8b0db8784600           -mov ecx, dword ptr [0x4678b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618424) /* 0x4678b8 */);
    // 0041af09  8b15c8784600           -mov edx, dword ptr [0x4678c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618440) /* 0x4678c8 */);
    // 0041af0f  8991a8000000           -mov dword ptr [ecx + 0xa8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.edx;
    // 0041af15  a1903f4500             -mov eax, dword ptr [0x453f90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538256) /* 0x453f90 */);
    // 0041af1a  8b0d60794600           -mov ecx, dword ptr [0x467960]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618592) /* 0x467960 */);
    // 0041af20  8988a8000000           -mov dword ptr [eax + 0xa8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = cpu.ecx;
    // 0041af26  8b15dc3f4500           -mov edx, dword ptr [0x453fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538332) /* 0x453fdc */);
    // 0041af2c  a1b4784600             -mov eax, dword ptr [0x4678b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618420) /* 0x4678b4 */);
    // 0041af31  8982a8000000           -mov dword ptr [edx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0041af37  8b0d8c3f4500           -mov ecx, dword ptr [0x453f8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538252) /* 0x453f8c */);
    // 0041af3d  8b15e83f4500           -mov edx, dword ptr [0x453fe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538344) /* 0x453fe8 */);
    // 0041af43  8991a8000000           -mov dword ptr [ecx + 0xa8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.edx;
    // 0041af49  8b0d983f4500           -mov ecx, dword ptr [0x453f98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4538264) /* 0x453f98 */);
    // 0041af4f  a174794600             -mov eax, dword ptr [0x467974]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */);
    // 0041af54  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0041af5a  8b15b0784600           -mov edx, dword ptr [0x4678b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618416) /* 0x4678b0 */);
    // 0041af60  a14c794600             -mov eax, dword ptr [0x46794c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618572) /* 0x46794c */);
    // 0041af65  8982a8000000           -mov dword ptr [edx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0041af6b  8b0d9c794600           -mov ecx, dword ptr [0x46799c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618652) /* 0x46799c */);
    // 0041af71  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041af75  8b15103f4500           -mov edx, dword ptr [0x453f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538128) /* 0x453f10 */);
    // 0041af7b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041af7d  8991a8000000           -mov dword ptr [ecx + 0xa8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.edx;
    // 0041af83  746e                   -je 0x41aff3
    if (cpu.flags.zf)
    {
        goto L_0x0041aff3;
    }
    // 0041af85  a1ec7f4600             -mov eax, dword ptr [0x467fec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4620268) /* 0x467fec */);
    // 0041af8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041af8c  7422                   -je 0x41afb0
    if (cpu.flags.zf)
    {
        goto L_0x0041afb0;
    }
    // 0041af8e  a1dc784600             -mov eax, dword ptr [0x4678dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4618460) /* 0x4678dc */);
    // 0041af93  8b0d74794600           -mov ecx, dword ptr [0x467974]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */);
    // 0041af99  6814b54300             -push 0x43b514
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437268 /*0x43b514*/;
    cpu.esp -= 4;
    // 0041af9e  a3a4394900             -mov dword ptr [0x4939a4], eax
    app->getMemory<x86::reg32>(x86::reg32(4798884) /* 0x4939a4 */) = cpu.eax;
    // 0041afa3  890dac394900           -mov dword ptr [0x4939ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */) = cpu.ecx;
    // 0041afa9  e8e6a10000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041afae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041afaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041afb0:
    // 0041afb0  a011574900             -mov al, byte ptr [0x495711]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4806417) /* 0x495711 */);
    // 0041afb5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041afb7  7522                   -jne 0x41afdb
    if (!cpu.flags.zf)
    {
        goto L_0x0041afdb;
    }
    // 0041afb9  8b150c404500           -mov edx, dword ptr [0x45400c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4538380) /* 0x45400c */);
    // 0041afbf  a118404500             -mov eax, dword ptr [0x454018]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4538392) /* 0x454018 */);
    // 0041afc4  6814b54300             -push 0x43b514
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437268 /*0x43b514*/;
    cpu.esp -= 4;
    // 0041afc9  8915a4394900           -mov dword ptr [0x4939a4], edx
    app->getMemory<x86::reg32>(x86::reg32(4798884) /* 0x4939a4 */) = cpu.edx;
    // 0041afcf  a3ac394900             -mov dword ptr [0x4939ac], eax
    app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */) = cpu.eax;
    // 0041afd4  e8bba10000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041afd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041afda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041afdb:
    // 0041afdb  8b0dac784600           -mov ecx, dword ptr [0x4678ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4618412) /* 0x4678ac */);
    // 0041afe1  8b15b4784600           -mov edx, dword ptr [0x4678b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4618420) /* 0x4678b4 */);
    // 0041afe7  890da4394900           -mov dword ptr [0x4939a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(4798884) /* 0x4939a4 */) = cpu.ecx;
    // 0041afed  8915ac394900           -mov dword ptr [0x4939ac], edx
    app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */) = cpu.edx;
L_0x0041aff3:
    // 0041aff3  6814b54300             -push 0x43b514
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437268 /*0x43b514*/;
    cpu.esp -= 4;
    // 0041aff8  e897a10000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041affd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041affe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b000  8b0dac394900           -mov ecx, dword ptr [0x4939ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */);
    // 0041b006  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b007  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b008  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041b00a  81f988e04300           +cmp ecx, 0x43e088
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4448392 /*0x43e088*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b010  7518                   -jne 0x41b02a
    if (!cpu.flags.zf)
    {
        goto L_0x0041b02a;
    }
    // 0041b012  687cb64300             -push 0x43b67c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437628 /*0x43b67c*/;
    cpu.esp -= 4;
    // 0041b017  e878a10000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b01c  8b0dac394900           -mov ecx, dword ptr [0x4939ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */);
    // 0041b022  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b025  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x0041b02a:
    // 0041b02a  81f910394900           +cmp ecx, 0x493910
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4798736 /*0x493910*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b030  751d                   -jne 0x41b04f
    if (!cpu.flags.zf)
    {
        goto L_0x0041b04f;
    }
    // 0041b032  6870b64300             -push 0x43b670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437616 /*0x43b670*/;
    cpu.esp -= 4;
    // 0041b037  e858a10000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b03c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b03f  e89cf8ffff             -call 0x41a8e0
    cpu.esp -= 4;
    sub_41a8e0(app, cpu);
    // 0041b044  8b0dac394900           -mov ecx, dword ptr [0x4939ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */);
    // 0041b04a  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
L_0x0041b04f:
    // 0041b04f  81f9b0e44300           +cmp ecx, 0x43e4b0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4449456 /*0x43e4b0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b055  751d                   -jne 0x41b074
    if (!cpu.flags.zf)
    {
        goto L_0x0041b074;
    }
    // 0041b057  68c4b74300             -push 0x43b7c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437956 /*0x43b7c4*/;
    cpu.esp -= 4;
    // 0041b05c  e833a10000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b061  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b064  e8e7e7ffff             -call 0x419850
    cpu.esp -= 4;
    sub_419850(app, cpu);
    // 0041b069  8b0dac394900           -mov ecx, dword ptr [0x4939ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */);
    // 0041b06f  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
L_0x0041b074:
    // 0041b074  81f958394900           +cmp ecx, 0x493958
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4798808 /*0x493958*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b07a  751d                   -jne 0x41b099
    if (!cpu.flags.zf)
    {
        goto L_0x0041b099;
    }
    // 0041b07c  6844b64300             -push 0x43b644
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437572 /*0x43b644*/;
    cpu.esp -= 4;
    // 0041b081  e80ea10000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b086  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b089  e8c2deffff             -call 0x418f50
    cpu.esp -= 4;
    sub_418f50(app, cpu);
    // 0041b08e  8b0dac394900           -mov ecx, dword ptr [0x4939ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */);
    // 0041b094  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
L_0x0041b099:
    // 0041b099  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041b09b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0041b09d:
    // 0041b09d  8d90a8e14300           -lea edx, [eax + 0x43e1a8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4448680) /* 0x43e1a8 */);
    // 0041b0a3  3bd1                   +cmp edx, ecx
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
    // 0041b0a5  7417                   -je 0x41b0be
    if (cpu.flags.zf)
    {
        goto L_0x0041b0be;
    }
    // 0041b0a7  8d9018ec4700           -lea edx, [eax + 0x47ec18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4713496) /* 0x47ec18 */);
    // 0041b0ad  3bd1                   +cmp edx, ecx
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
    // 0041b0af  7428                   -je 0x41b0d9
    if (cpu.flags.zf)
    {
        goto L_0x0041b0d9;
    }
    // 0041b0b1  83c044                 -add eax, 0x44
    (cpu.eax) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041b0b4  46                     -inc esi
    (cpu.esi)++;
    // 0041b0b5  3da8020000             +cmp eax, 0x2a8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(680 /*0x2a8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b0ba  72e1                   -jb 0x41b09d
    if (cpu.flags.cf)
    {
        goto L_0x0041b09d;
    }
    // 0041b0bc  eb3a                   -jmp 0x41b0f8
    goto L_0x0041b0f8;
L_0x0041b0be:
    // 0041b0be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b0bf  682cb64300             -push 0x43b62c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437548 /*0x43b62c*/;
    cpu.esp -= 4;
    // 0041b0c4  e8cba00000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b0c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b0ca  e841fffeff             -call 0x40b010
    cpu.esp -= 4;
    sub_40b010(app, cpu);
    // 0041b0cf  83c40c                 +add esp, 0xc
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
    // 0041b0d2  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
    // 0041b0d7  eb19                   -jmp 0x41b0f2
    goto L_0x0041b0f2;
L_0x0041b0d9:
    // 0041b0d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b0da  6810b64300             -push 0x43b610
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437520 /*0x43b610*/;
    cpu.esp -= 4;
    // 0041b0df  e8b0a00000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b0e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b0e5  e826fffeff             -call 0x40b010
    cpu.esp -= 4;
    sub_40b010(app, cpu);
    // 0041b0ea  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041b0ed  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
L_0x0041b0f2:
    // 0041b0f2  8b0dac394900           -mov ecx, dword ptr [0x4939ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */);
L_0x0041b0f8:
    // 0041b0f8  81f968e44300           +cmp ecx, 0x43e468
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4449384 /*0x43e468*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b0fe  7502                   -jne 0x41b102
    if (!cpu.flags.zf)
    {
        goto L_0x0041b102;
    }
    // 0041b100  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0041b102:
    // 0041b102  e8c9b7ffff             -call 0x4168d0
    cpu.esp -= 4;
    sub_4168d0(app, cpu);
    // 0041b107  e854c4ffff             -call 0x417560
    cpu.esp -= 4;
    sub_417560(app, cpu);
    // 0041b10c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041b10e  752d                   -jne 0x41b13d
    if (!cpu.flags.zf)
    {
        goto L_0x0041b13d;
    }
    // 0041b110  a1ec7f4600             -mov eax, dword ptr [0x467fec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4620268) /* 0x467fec */);
    // 0041b115  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b117  7417                   -je 0x41b130
    if (cpu.flags.zf)
    {
        goto L_0x0041b130;
    }
    // 0041b119  68b0b74300             -push 0x43b7b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437936 /*0x43b7b0*/;
    cpu.esp -= 4;
    // 0041b11e  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0041b123  e86ca00000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b128  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b12b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041b12d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b12e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b12f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b130:
    // 0041b130  6898b74300             -push 0x43b798
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437912 /*0x43b798*/;
    cpu.esp -= 4;
    // 0041b135  e85aa00000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b13a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b13d:
    // 0041b13d  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041b13f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b140  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b141  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b150  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b154  8b0d34ca4700           -mov ecx, dword ptr [0x47ca34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4704820) /* 0x47ca34 */);
    // 0041b15a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b15b  3bc1                   +cmp eax, ecx
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
    // 0041b15d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041b15f  7510                   -jne 0x41b171
    if (!cpu.flags.zf)
    {
        goto L_0x0041b171;
    }
    // 0041b161  8b35342f4500           -mov esi, dword ptr [0x452f34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4534068) /* 0x452f34 */);
    // 0041b167  c7053d58490001000000   -mov dword ptr [0x49583d], 1
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 1 /*0x1*/;
L_0x0041b171:
    // 0041b171  3b0540ca4700           +cmp eax, dword ptr [0x47ca40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4704832) /* 0x47ca40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b177  7510                   -jne 0x41b189
    if (!cpu.flags.zf)
    {
        goto L_0x0041b189;
    }
    // 0041b179  8b35dc384900           -mov esi, dword ptr [0x4938dc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4798684) /* 0x4938dc */);
    // 0041b17f  c7053d58490002000000   -mov dword ptr [0x49583d], 2
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 2 /*0x2*/;
L_0x0041b189:
    // 0041b189  3b053cca4700           +cmp eax, dword ptr [0x47ca3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4704828) /* 0x47ca3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b18f  7510                   -jne 0x41b1a1
    if (!cpu.flags.zf)
    {
        goto L_0x0041b1a1;
    }
    // 0041b191  8b3504ca4700           -mov esi, dword ptr [0x47ca04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4704772) /* 0x47ca04 */);
    // 0041b197  c7053d58490003000000   -mov dword ptr [0x49583d], 3
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 3 /*0x3*/;
L_0x0041b1a1:
    // 0041b1a1  3b0544ca4700           +cmp eax, dword ptr [0x47ca44]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4704836) /* 0x47ca44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b1a7  7510                   -jne 0x41b1b9
    if (!cpu.flags.zf)
    {
        goto L_0x0041b1b9;
    }
    // 0041b1a9  8b3574794600           -mov esi, dword ptr [0x467974]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */);
    // 0041b1af  c7053d58490004000000   -mov dword ptr [0x49583d], 4
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 4 /*0x4*/;
L_0x0041b1b9:
    // 0041b1b9  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041b1bc  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041b1be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b1c0  7409                   -je 0x41b1cb
    if (cpu.flags.zf)
    {
        goto L_0x0041b1cb;
    }
L_0x0041b1c2:
    // 0041b1c2  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041b1c4  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041b1c7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b1c9  75f7                   -jne 0x41b1c2
    if (!cpu.flags.zf)
    {
        goto L_0x0041b1c2;
    }
L_0x0041b1cb:
    // 0041b1cb  c705a879460000000000   -mov dword ptr [0x4679a8], 0
    app->getMemory<x86::reg32>(x86::reg32(4618664) /* 0x4679a8 */) = 0 /*0x0*/;
    // 0041b1d5  a3ac794600             -mov dword ptr [0x4679ac], eax
    app->getMemory<x86::reg32>(x86::reg32(4618668) /* 0x4679ac */) = cpu.eax;
    // 0041b1da  8935cc7c4600           -mov dword ptr [0x467ccc], esi
    app->getMemory<x86::reg32>(x86::reg32(4619468) /* 0x467ccc */) = cpu.esi;
    // 0041b1e0  e85ba6feff             -call 0x405840
    cpu.esp -= 4;
    sub_405840(app, cpu);
    // 0041b1e5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b1e7  e884020000             -call 0x41b470
    cpu.esp -= 4;
    sub_41b470(app, cpu);
    // 0041b1ec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b1ef  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041b1f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b1f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b200  6884a74300             -push 0x43a784
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433796 /*0x43a784*/;
    cpu.esp -= 4;
    // 0041b205  e8e6aafeff             -call 0x405cf0
    cpu.esp -= 4;
    sub_405cf0(app, cpu);
    // 0041b20a  6850b14100             -push 0x41b150
    app->getMemory<x86::reg32>(cpu.esp-4) = 4305232 /*0x41b150*/;
    cpu.esp -= 4;
    // 0041b20f  68c0a74300             -push 0x43a7c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433856 /*0x43a7c0*/;
    cpu.esp -= 4;
    // 0041b214  6890a74300             -push 0x43a790
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433808 /*0x43a790*/;
    cpu.esp -= 4;
    // 0041b219  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b21a  a338ca4700             -mov dword ptr [0x47ca38], eax
    app->getMemory<x86::reg32>(x86::reg32(4704824) /* 0x47ca38 */) = cpu.eax;
    // 0041b21f  e86cadfeff             -call 0x405f90
    cpu.esp -= 4;
    sub_405f90(app, cpu);
    // 0041b224  a334ca4700             -mov dword ptr [0x47ca34], eax
    app->getMemory<x86::reg32>(x86::reg32(4704820) /* 0x47ca34 */) = cpu.eax;
    // 0041b229  a138ca4700             -mov eax, dword ptr [0x47ca38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4704824) /* 0x47ca38 */);
    // 0041b22e  6850b14100             -push 0x41b150
    app->getMemory<x86::reg32>(cpu.esp-4) = 4305232 /*0x41b150*/;
    cpu.esp -= 4;
    // 0041b233  68eca74300             -push 0x43a7ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433900 /*0x43a7ec*/;
    cpu.esp -= 4;
    // 0041b238  689ca74300             -push 0x43a79c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433820 /*0x43a79c*/;
    cpu.esp -= 4;
    // 0041b23d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b23e  e84dadfeff             -call 0x405f90
    cpu.esp -= 4;
    sub_405f90(app, cpu);
    // 0041b243  8b0d38ca4700           -mov ecx, dword ptr [0x47ca38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4704824) /* 0x47ca38 */);
    // 0041b249  6850b14100             -push 0x41b150
    app->getMemory<x86::reg32>(cpu.esp-4) = 4305232 /*0x41b150*/;
    cpu.esp -= 4;
    // 0041b24e  6818a84300             -push 0x43a818
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433944 /*0x43a818*/;
    cpu.esp -= 4;
    // 0041b253  68a8a74300             -push 0x43a7a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433832 /*0x43a7a8*/;
    cpu.esp -= 4;
    // 0041b258  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b259  a340ca4700             -mov dword ptr [0x47ca40], eax
    app->getMemory<x86::reg32>(x86::reg32(4704832) /* 0x47ca40 */) = cpu.eax;
    // 0041b25e  e82dadfeff             -call 0x405f90
    cpu.esp -= 4;
    sub_405f90(app, cpu);
    // 0041b263  8b1538ca4700           -mov edx, dword ptr [0x47ca38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4704824) /* 0x47ca38 */);
    // 0041b269  6850b14100             -push 0x41b150
    app->getMemory<x86::reg32>(cpu.esp-4) = 4305232 /*0x41b150*/;
    cpu.esp -= 4;
    // 0041b26e  6844a84300             -push 0x43a844
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433988 /*0x43a844*/;
    cpu.esp -= 4;
    // 0041b273  68b4a74300             -push 0x43a7b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4433844 /*0x43a7b4*/;
    cpu.esp -= 4;
    // 0041b278  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b279  a33cca4700             -mov dword ptr [0x47ca3c], eax
    app->getMemory<x86::reg32>(x86::reg32(4704828) /* 0x47ca3c */) = cpu.eax;
    // 0041b27e  e80dadfeff             -call 0x405f90
    cpu.esp -= 4;
    sub_405f90(app, cpu);
    // 0041b283  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041b286  a344ca4700             -mov dword ptr [0x47ca44], eax
    app->getMemory<x86::reg32>(x86::reg32(4704836) /* 0x47ca44 */) = cpu.eax;
    // 0041b28b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b290  6820b54300             -push 0x43b520
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437280 /*0x43b520*/;
    cpu.esp -= 4;
    // 0041b295  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 0041b29a  e8f59e0000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041b29f  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041b2a4  e852a10000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041b2a9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041b2ac  e84fffffff             -call 0x41b200
    cpu.esp -= 4;
    sub_41b200(app, cpu);
    // 0041b2b1  a138ca4700             -mov eax, dword ptr [0x47ca38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4704824) /* 0x47ca38 */);
    // 0041b2b6  8b0d34ca4700           -mov ecx, dword ptr [0x47ca34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4704820) /* 0x47ca34 */);
    // 0041b2bc  a3a4394900             -mov dword ptr [0x4939a4], eax
    app->getMemory<x86::reg32>(x86::reg32(4798884) /* 0x4939a4 */) = cpu.eax;
    // 0041b2c1  890dac394900           -mov dword ptr [0x4939ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(4798892) /* 0x4939ac */) = cpu.ecx;
    // 0041b2c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b2d0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b2d4  8b0d282f4500           -mov ecx, dword ptr [0x452f28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4534056) /* 0x452f28 */);
    // 0041b2da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b2db  3bc1                   +cmp eax, ecx
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
    // 0041b2dd  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041b2df  7418                   -je 0x41b2f9
    if (cpu.flags.zf)
    {
        goto L_0x0041b2f9;
    }
    // 0041b2e1  3b05d0384900           +cmp eax, dword ptr [0x4938d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4798672) /* 0x4938d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b2e7  7410                   -je 0x41b2f9
    if (cpu.flags.zf)
    {
        goto L_0x0041b2f9;
    }
    // 0041b2e9  3b05f8c94700           +cmp eax, dword ptr [0x47c9f8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4704760) /* 0x47c9f8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b2ef  7408                   -je 0x41b2f9
    if (cpu.flags.zf)
    {
        goto L_0x0041b2f9;
    }
    // 0041b2f1  3b0568794600           +cmp eax, dword ptr [0x467968]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4618600) /* 0x467968 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b2f7  7510                   -jne 0x41b309
    if (!cpu.flags.zf)
    {
        goto L_0x0041b309;
    }
L_0x0041b2f9:
    // 0041b2f9  8b35342f4500           -mov esi, dword ptr [0x452f34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4534068) /* 0x452f34 */);
    // 0041b2ff  c7053d58490001000000   -mov dword ptr [0x49583d], 1
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 1 /*0x1*/;
L_0x0041b309:
    // 0041b309  3b050c2f4500           +cmp eax, dword ptr [0x452f0c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4534028) /* 0x452f0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b30f  7418                   -je 0x41b329
    if (cpu.flags.zf)
    {
        goto L_0x0041b329;
    }
    // 0041b311  3b05ac384900           +cmp eax, dword ptr [0x4938ac]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4798636) /* 0x4938ac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b317  7410                   -je 0x41b329
    if (cpu.flags.zf)
    {
        goto L_0x0041b329;
    }
    // 0041b319  3b05d8c94700           +cmp eax, dword ptr [0x47c9d8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4704728) /* 0x47c9d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b31f  7408                   -je 0x41b329
    if (cpu.flags.zf)
    {
        goto L_0x0041b329;
    }
    // 0041b321  3b0548794600           +cmp eax, dword ptr [0x467948]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4618568) /* 0x467948 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b327  7510                   -jne 0x41b339
    if (!cpu.flags.zf)
    {
        goto L_0x0041b339;
    }
L_0x0041b329:
    // 0041b329  8b35dc384900           -mov esi, dword ptr [0x4938dc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4798684) /* 0x4938dc */);
    // 0041b32f  c7053d58490002000000   -mov dword ptr [0x49583d], 2
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 2 /*0x2*/;
L_0x0041b339:
    // 0041b339  3b054cf54300           +cmp eax, dword ptr [0x43f54c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4453708) /* 0x43f54c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b33f  7418                   -je 0x41b359
    if (cpu.flags.zf)
    {
        goto L_0x0041b359;
    }
    // 0041b341  3b05e8fe4700           +cmp eax, dword ptr [0x47fee8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4718312) /* 0x47fee8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b347  7410                   -je 0x41b359
    if (cpu.flags.zf)
    {
        goto L_0x0041b359;
    }
    // 0041b349  3b0514904600           +cmp eax, dword ptr [0x469014]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4624404) /* 0x469014 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b34f  7408                   -je 0x41b359
    if (cpu.flags.zf)
    {
        goto L_0x0041b359;
    }
    // 0041b351  3b05843f4500           +cmp eax, dword ptr [0x453f84]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4538244) /* 0x453f84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b357  7510                   -jne 0x41b369
    if (!cpu.flags.zf)
    {
        goto L_0x0041b369;
    }
L_0x0041b359:
    // 0041b359  8b3504ca4700           -mov esi, dword ptr [0x47ca04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4704772) /* 0x47ca04 */);
    // 0041b35f  c7053d58490003000000   -mov dword ptr [0x49583d], 3
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 3 /*0x3*/;
L_0x0041b369:
    // 0041b369  3b05f82e4500           +cmp eax, dword ptr [0x452ef8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4534008) /* 0x452ef8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b36f  7418                   -je 0x41b389
    if (cpu.flags.zf)
    {
        goto L_0x0041b389;
    }
    // 0041b371  3b059c384900           +cmp eax, dword ptr [0x49389c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4798620) /* 0x49389c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b377  7410                   -je 0x41b389
    if (cpu.flags.zf)
    {
        goto L_0x0041b389;
    }
    // 0041b379  3b05c8c94700           +cmp eax, dword ptr [0x47c9c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4704712) /* 0x47c9c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b37f  7408                   -je 0x41b389
    if (cpu.flags.zf)
    {
        goto L_0x0041b389;
    }
    // 0041b381  3b0538794600           +cmp eax, dword ptr [0x467938]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4618552) /* 0x467938 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b387  7510                   -jne 0x41b399
    if (!cpu.flags.zf)
    {
        goto L_0x0041b399;
    }
L_0x0041b389:
    // 0041b389  8b3574794600           -mov esi, dword ptr [0x467974]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4618612) /* 0x467974 */);
    // 0041b38f  c7053d58490004000000   -mov dword ptr [0x49583d], 4
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 4 /*0x4*/;
L_0x0041b399:
    // 0041b399  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041b39c  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041b39e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b3a0  7409                   -je 0x41b3ab
    if (cpu.flags.zf)
    {
        goto L_0x0041b3ab;
    }
L_0x0041b3a2:
    // 0041b3a2  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041b3a4  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041b3a7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b3a9  75f7                   -jne 0x41b3a2
    if (!cpu.flags.zf)
    {
        goto L_0x0041b3a2;
    }
L_0x0041b3ab:
    // 0041b3ab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b3ad  c705a879460000000000   -mov dword ptr [0x4679a8], 0
    app->getMemory<x86::reg32>(x86::reg32(4618664) /* 0x4679a8 */) = 0 /*0x0*/;
    // 0041b3b7  a3ac794600             -mov dword ptr [0x4679ac], eax
    app->getMemory<x86::reg32>(x86::reg32(4618668) /* 0x4679ac */) = cpu.eax;
    // 0041b3bc  8935cc7c4600           -mov dword ptr [0x467ccc], esi
    app->getMemory<x86::reg32>(x86::reg32(4619468) /* 0x467ccc */) = cpu.esi;
    // 0041b3c2  e8a9000000             -call 0x41b470
    cpu.esp -= 4;
    sub_41b470(app, cpu);
    // 0041b3c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b3ca  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041b3cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b3cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b3d0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b3d2  c7053d58490001000000   -mov dword ptr [0x49583d], 1
    app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */) = 1 /*0x1*/;
    // 0041b3dc  e8ef09ffff             -call 0x40bdd0
    cpu.esp -= 4;
    sub_40bdd0(app, cpu);
    // 0041b3e1  833d3d58490002         +cmp dword ptr [0x49583d], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b3e8  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0041b3eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b3ec  e8ef59ffff             -call 0x410de0
    cpu.esp -= 4;
    sub_410de0(app, cpu);
    // 0041b3f1  833d3d58490003         +cmp dword ptr [0x49583d], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b3f8  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 0041b3fb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b3fc  e89fa9ffff             -call 0x415da0
    cpu.esp -= 4;
    sub_415da0(app, cpu);
    // 0041b401  833d3d58490004         +cmp dword ptr [0x49583d], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b408  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 0041b40b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b40c  e85ff9ffff             -call 0x41ad70
    cpu.esp -= 4;
    sub_41ad70(app, cpu);
    // 0041b411  a13d584900             -mov eax, dword ptr [0x49583d]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */);
    // 0041b416  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041b419  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b41b  7505                   -jne 0x41b422
    if (!cpu.flags.zf)
    {
        goto L_0x0041b422;
    }
    // 0041b41d  e96efeffff             -jmp 0x41b290
    return sub_41b290(app, cpu);
L_0x0041b422:
    // 0041b422  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b424  e847000000             -call 0x41b470
    cpu.esp -= 4;
    sub_41b470(app, cpu);
    // 0041b429  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b42a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041b430  a13d584900             -mov eax, dword ptr [0x49583d]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */);
    // 0041b435  48                     -dec eax
    (cpu.eax)--;
    // 0041b436  83f803                 +cmp eax, 3
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
    // 0041b439  771b                   -ja 0x41b456
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041b456;
    }
    // 0041b43b  ff24855cb44100         -jmp dword ptr [eax*4 + 0x41b45c]
    cpu.ip = app->getMemory<x86::reg32>(4306012 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041b442:
    // 0041b442  e9b90bffff             -jmp 0x40c000
    return sub_40c000(app, cpu);
  case 0x0041b447:
    // 0041b447  e9245cffff             -jmp 0x411070
    return sub_411070(app, cpu);
  case 0x0041b44c:
    // 0041b44c  e9dfabffff             -jmp 0x416030
    return sub_416030(app, cpu);
  case 0x0041b451:
    // 0041b451  e9aafbffff             -jmp 0x41b000
    return sub_41b000(app, cpu);
L_0x0041b456:
    // 0041b456  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b458  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_41b470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b471  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b475  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b476  e855d5feff             -call 0x4089d0
    cpu.esp -= 4;
    sub_4089d0(app, cpu);
    // 0041b47b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b47c  e83f23ffff             -call 0x40d7c0
    cpu.esp -= 4;
    sub_40d7c0(app, cpu);
    // 0041b481  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b482  e8f972ffff             -call 0x412780
    cpu.esp -= 4;
    sub_412780(app, cpu);
    // 0041b487  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b488  e8b3c2ffff             -call 0x417740
    cpu.esp -= 4;
    sub_417740(app, cpu);
    // 0041b48d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041b490  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b491  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b4a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b4b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b4b1  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041b4b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041b4b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b4b5  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0041b4b8  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0041b4bb  3bfd                   +cmp edi, ebp
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
    // 0041b4bd  7448                   -je 0x41b507
    if (cpu.flags.zf)
    {
        goto L_0x0041b507;
    }
    // 0041b4bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0041b4c0:
    // 0041b4c0  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0041b4c2  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 0041b4c4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041b4c7  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041b4c9  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041b4cb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041b4cd  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041b4d0  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041b4d3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041b4d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b4d8  7410                   -je 0x41b4ea
    if (cpu.flags.zf)
    {
        goto L_0x0041b4ea;
    }
    // 0041b4da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b4db  e866990000             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0041b4e0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b4e3  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x0041b4ea:
    // 0041b4ea  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b4ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b4ed  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0041b4f0  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041b4f3  e853a60000             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0041b4f8  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0041b4fb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b4fe  49                     -dec ecx
    (cpu.ecx)--;
    // 0041b4ff  3bfd                   +cmp edi, ebp
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
    // 0041b501  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041b504  75ba                   -jne 0x41b4c0
    if (!cpu.flags.zf)
    {
        goto L_0x0041b4c0;
    }
    // 0041b506  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041b507:
    // 0041b507  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0041b50a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b50b  e83ba60000             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0041b510  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b513  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b515  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041b518  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041b51b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b51c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b51d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b51e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b520  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b521  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b522  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b523  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041b525  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041b528  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0041b52a  3bf3                   +cmp esi, ebx
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
    // 0041b52c  7427                   -je 0x41b555
    if (cpu.flags.zf)
    {
        goto L_0x0041b555;
    }
L_0x0041b52e:
    // 0041b52e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041b530  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0041b532  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b533  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041b536  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041b538  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0041b53a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041b53c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041b53f  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041b542  e804a60000             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0041b547  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0041b54a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b54d  49                     -dec ecx
    (cpu.ecx)--;
    // 0041b54e  3bf3                   +cmp esi, ebx
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
    // 0041b550  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041b553  75d9                   -jne 0x41b52e
    if (!cpu.flags.zf)
    {
        goto L_0x0041b52e;
    }
L_0x0041b555:
    // 0041b555  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041b558  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b559  e8eda50000             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0041b55e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b561  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b563  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041b566  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041b569  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b56a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b56b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b56c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b570  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0041b572  e8dfa50000             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 0041b577  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b57b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b57e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b580  7502                   -jne 0x41b584
    if (!cpu.flags.zf)
    {
        goto L_0x0041b584;
    }
    // 0041b582  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0041b584:
    // 0041b584  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041b586  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b58a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b58c  7406                   -je 0x41b594
    if (cpu.flags.zf)
    {
        goto L_0x0041b594;
    }
    // 0041b58e  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041b591  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041b594:
    // 0041b594  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041b597  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41b5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b5a0  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0041b5a2  e8afa50000             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 0041b5a7  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b5ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b5ae  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b5b0  7502                   -jne 0x41b5b4
    if (!cpu.flags.zf)
    {
        goto L_0x0041b5b4;
    }
    // 0041b5b2  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0041b5b4:
    // 0041b5b4  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041b5b6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b5ba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b5bc  7406                   -je 0x41b5c4
    if (cpu.flags.zf)
    {
        goto L_0x0041b5c4;
    }
    // 0041b5be  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041b5c1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041b5c4:
    // 0041b5c4  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041b5c7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41b5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b5d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b5d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b5d2  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041b5d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b5d7  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041b5d9  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0041b5db  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041b5de  e873a50000             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 0041b5e3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b5e6  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041b5e8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b5ea  7502                   -jne 0x41b5ee
    if (!cpu.flags.zf)
    {
        goto L_0x0041b5ee;
    }
    // 0041b5ec  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0041b5ee:
    // 0041b5ee  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041b5f0  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041b5f2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041b5f4  7502                   -jne 0x41b5f8
    if (!cpu.flags.zf)
    {
        goto L_0x0041b5f8;
    }
    // 0041b5f6  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0041b5f8:
    // 0041b5f8  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041b5fb  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041b5fe  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041b601  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041b603  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041b606  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b608  7414                   -je 0x41b61e
    if (cpu.flags.zf)
    {
        goto L_0x0041b61e;
    }
    // 0041b60a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041b60e  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0041b610  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 0041b612  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0041b615  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0041b618  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0041b61b  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x0041b61e:
    // 0041b61e  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0041b621  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b622  41                     -inc ecx
    (cpu.ecx)++;
    // 0041b623  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b624  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041b627  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b62b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b62c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041b62e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041b630  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41b640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b640  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0041b642  e80fa50000             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 0041b647  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b64b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b64e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b650  7502                   -jne 0x41b654
    if (!cpu.flags.zf)
    {
        goto L_0x0041b654;
    }
    // 0041b652  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0041b654:
    // 0041b654  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041b656  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b65a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b65c  7406                   -je 0x41b664
    if (cpu.flags.zf)
    {
        goto L_0x0041b664;
    }
    // 0041b65e  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041b661  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041b664:
    // 0041b664  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041b667  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41b670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b670  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b674  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b676  740e                   -je 0x41b686
    if (cpu.flags.zf)
    {
        goto L_0x0041b686;
    }
    // 0041b678  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b67c  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041b67e  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0041b680  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0041b683  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
L_0x0041b686:
    // 0041b686  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b690  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b694  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b696  7414                   -je 0x41b6ac
    if (cpu.flags.zf)
    {
        goto L_0x0041b6ac;
    }
    // 0041b698  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b69c  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041b69e  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0041b6a0  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0041b6a3  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041b6a6  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0041b6a9  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x0041b6ac:
    // 0041b6ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b6b0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b6b3  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041b6b6  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041b6b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b6b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b6ba  bfd4b74300             -mov edi, 0x43b7d4
    cpu.edi = 4437972 /*0x43b7d4*/;
    // 0041b6bf  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0041b6c1  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0041b6c3  49                     -dec ecx
    (cpu.ecx)--;
    // 0041b6c4  bf58b84300             -mov edi, 0x43b858
    cpu.edi = 4438104 /*0x43b858*/;
    // 0041b6c9  890d505a4900           -mov dword ptr [0x495a50], ecx
    app->getMemory<x86::reg32>(x86::reg32(4807248) /* 0x495a50 */) = cpu.ecx;
    // 0041b6cf  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0041b6d2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0041b6d4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0041b6d6  49                     -dec ecx
    (cpu.ecx)--;
    // 0041b6d7  890d545a4900           -mov dword ptr [0x495a54], ecx
    app->getMemory<x86::reg32>(x86::reg32(4807252) /* 0x495a54 */) = cpu.ecx;
    // 0041b6dd  e88e010000             -call 0x41b870
    cpu.esp -= 4;
    sub_41b870(app, cpu);
    // 0041b6e2  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041b6e6  6800214300             -push 0x432100
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399360 /*0x432100*/;
    cpu.esp -= 4;
    // 0041b6eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b6ec  e8909a0000             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 0041b6f1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b6f4  a3f0394900             -mov dword ptr [0x4939f0], eax
    app->getMemory<x86::reg32>(x86::reg32(4798960) /* 0x4939f0 */) = cpu.eax;
    // 0041b6f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b6fb  0f845a010000           -je 0x41b85b
    if (cpu.flags.zf)
    {
        goto L_0x0041b85b;
    }
    // 0041b701  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b702  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0041b704  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041b708  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b70a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b70b  e8fd980000             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 0041b710  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041b713  83f808                 +cmp eax, 8
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
    // 0041b716  7415                   -je 0x41b72d
    if (cpu.flags.zf)
    {
        goto L_0x0041b72d;
    }
    // 0041b718  682cb94300             -push 0x43b92c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438316 /*0x43b92c*/;
    cpu.esp -= 4;
    // 0041b71d  e86e280000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041b722  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b725  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b727  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b728  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b729  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b72c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b72d:
    // 0041b72d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b731  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b732  e83e970000             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0041b737  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041b73b  a3f8394900             -mov dword ptr [0x4939f8], eax
    app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */) = cpu.eax;
    // 0041b740  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041b744  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b745  a3f4394900             -mov dword ptr [0x4939f4], eax
    app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */) = cpu.eax;
    // 0041b74a  e826970000             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0041b74f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041b751  a1f8394900             -mov eax, dword ptr [0x4939f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041b756  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b759  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b75b  0f84ed000000           -je 0x41b84e
    if (cpu.flags.zf)
    {
        goto L_0x0041b84e;
    }
    // 0041b761  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b763  0f84e5000000           -je 0x41b84e
    if (cpu.flags.zf)
    {
        goto L_0x0041b84e;
    }
    // 0041b769  8b15f0394900           -mov edx, dword ptr [0x4939f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798960) /* 0x4939f0 */);
    // 0041b76f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041b773  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b774  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b775  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b777  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b778  e890980000             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 0041b77d  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041b781  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041b784  3bc1                   +cmp eax, ecx
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
    // 0041b786  7415                   -je 0x41b79d
    if (cpu.flags.zf)
    {
        goto L_0x0041b79d;
    }
    // 0041b788  68f8b84300             -push 0x43b8f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438264 /*0x43b8f8*/;
    cpu.esp -= 4;
    // 0041b78d  e8fe270000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041b792  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b795  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b797  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b798  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b799  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b79c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b79d:
    // 0041b79d  8b0df0394900           -mov ecx, dword ptr [0x4939f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798960) /* 0x4939f0 */);
    // 0041b7a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b7a4  e847960000             -call 0x424df0
    cpu.esp -= 4;
    sub_424df0(app, cpu);
    // 0041b7a9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041b7ad  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b7b0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041b7b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b7b4  7621                   -jbe 0x41b7d7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041b7d7;
    }
L_0x0041b7b6:
    // 0041b7b6  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041b7b8  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041b7ba  f735505a4900           -div dword ptr [0x495a50]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(x86::reg32(4807248) /* 0x495a50 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0041b7c0  8a0431                 -mov al, byte ptr [ecx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1);
    // 0041b7c3  8a92d4b74300           -mov dl, byte ptr [edx + 0x43b7d4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4437972) /* 0x43b7d4 */);
    // 0041b7c9  2ac2                   -sub al, dl
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.dl));
    // 0041b7cb  880431                 -mov byte ptr [ecx + esi], al
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.al;
    // 0041b7ce  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041b7d2  41                     -inc ecx
    (cpu.ecx)++;
    // 0041b7d3  3bc8                   +cmp ecx, eax
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
    // 0041b7d5  72df                   -jb 0x41b7b6
    if (cpu.flags.cf)
    {
        goto L_0x0041b7b6;
    }
L_0x0041b7d7:
    // 0041b7d7  8b0df8394900           -mov ecx, dword ptr [0x4939f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041b7dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b7de  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041b7e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b7e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b7e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b7e5  e8163b0000             -call 0x41f300
    cpu.esp -= 4;
    sub_41f300(app, cpu);
    // 0041b7ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b7eb  e856960000             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0041b7f0  a1f4394900             -mov eax, dword ptr [0x4939f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041b7f5  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041b7f9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041b7fc  3bc8                   +cmp ecx, eax
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
    // 0041b7fe  7415                   -je 0x41b815
    if (cpu.flags.zf)
    {
        goto L_0x0041b815;
    }
    // 0041b800  68c4b84300             -push 0x43b8c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438212 /*0x43b8c4*/;
    cpu.esp -= 4;
    // 0041b805  e886270000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041b80a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b80d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b80f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b810  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b811  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b814  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b815:
    // 0041b815  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041b817  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b819  7628                   -jbe 0x41b843
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041b843;
    }
L_0x0041b81b:
    // 0041b81b  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041b81d  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041b81f  f735545a4900           -div dword ptr [0x495a54]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(x86::reg32(4807252) /* 0x495a54 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0041b825  8b35f8394900           -mov esi, dword ptr [0x4939f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041b82b  8a040e                 -mov al, byte ptr [esi + ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ecx * 1);
    // 0041b82e  8a9258b84300           -mov dl, byte ptr [edx + 0x43b858]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4438104) /* 0x43b858 */);
    // 0041b834  2ac2                   -sub al, dl
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.dl));
    // 0041b836  88040e                 -mov byte ptr [esi + ecx], al
    app->getMemory<x86::reg8>(cpu.esi + cpu.ecx * 1) = cpu.al;
    // 0041b839  a1f4394900             -mov eax, dword ptr [0x4939f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041b83e  41                     -inc ecx
    (cpu.ecx)++;
    // 0041b83f  3bc8                   +cmp ecx, eax
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
    // 0041b841  72d8                   -jb 0x41b81b
    if (cpu.flags.cf)
    {
        goto L_0x0041b81b;
    }
L_0x0041b843:
    // 0041b843  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b844  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041b849  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b84a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b84d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b84e:
    // 0041b84e  68a0b84300             -push 0x43b8a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438176 /*0x43b8a0*/;
    cpu.esp -= 4;
    // 0041b853  e838270000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041b858  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b85b:
    // 0041b85b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b85c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b85e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b85f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b862  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b870  a1f8394900             -mov eax, dword ptr [0x4939f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041b875  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b877  741d                   -je 0x41b896
    if (cpu.flags.zf)
    {
        goto L_0x0041b896;
    }
    // 0041b879  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b87a  e8c7950000             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0041b87f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b882  c705f839490000000000   -mov dword ptr [0x4939f8], 0
    app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */) = 0 /*0x0*/;
    // 0041b88c  c705f439490000000000   -mov dword ptr [0x4939f4], 0
    app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */) = 0 /*0x0*/;
L_0x0041b896:
    // 0041b896  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41b8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b8a0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b8a3  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041b8a6  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041b8a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b8a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b8aa  bfd4b74300             -mov edi, 0x43b7d4
    cpu.edi = 4437972 /*0x43b7d4*/;
    // 0041b8af  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0041b8b1  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0041b8b3  49                     -dec ecx
    (cpu.ecx)--;
    // 0041b8b4  bf58b84300             -mov edi, 0x43b858
    cpu.edi = 4438104 /*0x43b858*/;
    // 0041b8b9  890d505a4900           -mov dword ptr [0x495a50], ecx
    app->getMemory<x86::reg32>(x86::reg32(4807248) /* 0x495a50 */) = cpu.ecx;
    // 0041b8bf  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0041b8c2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0041b8c4  a1f8394900             -mov eax, dword ptr [0x4939f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041b8c9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0041b8cb  49                     -dec ecx
    (cpu.ecx)--;
    // 0041b8cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b8ce  890d545a4900           -mov dword ptr [0x495a54], ecx
    app->getMemory<x86::reg32>(x86::reg32(4807252) /* 0x495a54 */) = cpu.ecx;
    // 0041b8d4  7515                   -jne 0x41b8eb
    if (!cpu.flags.zf)
    {
        goto L_0x0041b8eb;
    }
    // 0041b8d6  6844ba4300             -push 0x43ba44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438596 /*0x43ba44*/;
    cpu.esp -= 4;
    // 0041b8db  e8b0260000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041b8e0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b8e3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b8e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b8e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b8e7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b8ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b8eb:
    // 0041b8eb  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041b8ef  6848214300             -push 0x432148
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399432 /*0x432148*/;
    cpu.esp -= 4;
    // 0041b8f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b8f5  e887980000             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 0041b8fa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b8fd  a3f0394900             -mov dword ptr [0x4939f0], eax
    app->getMemory<x86::reg32>(x86::reg32(4798960) /* 0x4939f0 */) = cpu.eax;
    // 0041b902  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b904  7515                   -jne 0x41b91b
    if (!cpu.flags.zf)
    {
        goto L_0x0041b91b;
    }
    // 0041b906  6818ba4300             -push 0x43ba18
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438552 /*0x43ba18*/;
    cpu.esp -= 4;
    // 0041b90b  e880260000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041b910  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b913  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b915  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b916  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b917  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b91a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b91b:
    // 0041b91b  a1f4394900             -mov eax, dword ptr [0x4939f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041b920  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041b924  05e8030000             -add eax, 0x3e8
    (cpu.eax) += x86::reg32(x86::sreg32(1000 /*0x3e8*/));
    // 0041b929  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b92a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0041b92e  e842950000             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0041b933  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041b935  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b938  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b93a  7515                   -jne 0x41b951
    if (!cpu.flags.zf)
    {
        goto L_0x0041b951;
    }
    // 0041b93c  68ecb94300             -push 0x43b9ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438508 /*0x43b9ec*/;
    cpu.esp -= 4;
    // 0041b941  e84a260000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041b946  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b949  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b94b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b94c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b94d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b950  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b951:
    // 0041b951  a1f4394900             -mov eax, dword ptr [0x4939f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041b956  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041b958  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b95a  7628                   -jbe 0x41b984
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041b984;
    }
L_0x0041b95c:
    // 0041b95c  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041b95e  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041b960  f735545a4900           -div dword ptr [0x495a54]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(x86::reg32(4807252) /* 0x495a54 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0041b966  8b3df8394900           -mov edi, dword ptr [0x4939f8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041b96c  8a040f                 -mov al, byte ptr [edi + ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.ecx * 1);
    // 0041b96f  8a9258b84300           -mov dl, byte ptr [edx + 0x43b858]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4438104) /* 0x43b858 */);
    // 0041b975  02c2                   -add al, dl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.dl));
    // 0041b977  88040f                 -mov byte ptr [edi + ecx], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ecx * 1) = cpu.al;
    // 0041b97a  a1f4394900             -mov eax, dword ptr [0x4939f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041b97f  41                     -inc ecx
    (cpu.ecx)++;
    // 0041b980  3bc8                   +cmp ecx, eax
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
    // 0041b982  72d8                   -jb 0x41b95c
    if (cpu.flags.cf)
    {
        goto L_0x0041b95c;
    }
L_0x0041b984:
    // 0041b984  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041b988  8b0df8394900           -mov ecx, dword ptr [0x4939f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041b98e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b98f  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041b993  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b994  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b995  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b996  e8f5390000             -call 0x41f390
    cpu.esp -= 4;
    sub_41f390(app, cpu);
    // 0041b99b  a1f0394900             -mov eax, dword ptr [0x4939f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798960) /* 0x4939f0 */);
    // 0041b9a0  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041b9a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b9a5  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0041b9a7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b9a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b9aa  e83a950000             -call 0x424ee9
    cpu.esp -= 4;
    sub_424ee9(app, cpu);
    // 0041b9af  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041b9b2  83f808                 +cmp eax, 8
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
    // 0041b9b5  7415                   -je 0x41b9cc
    if (cpu.flags.zf)
    {
        goto L_0x0041b9cc;
    }
    // 0041b9b7  68a8b94300             -push 0x43b9a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438440 /*0x43b9a8*/;
    cpu.esp -= 4;
    // 0041b9bc  e8cf250000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041b9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b9c4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b9c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b9c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b9c8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b9cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b9cc:
    // 0041b9cc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041b9d0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041b9d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b9d4  7621                   -jbe 0x41b9f7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041b9f7;
    }
L_0x0041b9d6:
    // 0041b9d6  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041b9d8  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041b9da  f735505a4900           -div dword ptr [0x495a50]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(x86::reg32(4807248) /* 0x495a50 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0041b9e0  8a0431                 -mov al, byte ptr [ecx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1);
    // 0041b9e3  8a92d4b74300           -mov dl, byte ptr [edx + 0x43b7d4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4437972) /* 0x43b7d4 */);
    // 0041b9e9  02c2                   -add al, dl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.dl));
    // 0041b9eb  880431                 -mov byte ptr [ecx + esi], al
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.al;
    // 0041b9ee  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041b9f2  41                     -inc ecx
    (cpu.ecx)++;
    // 0041b9f3  3bc8                   +cmp ecx, eax
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
    // 0041b9f5  72df                   -jb 0x41b9d6
    if (cpu.flags.cf)
    {
        goto L_0x0041b9d6;
    }
L_0x0041b9f7:
    // 0041b9f7  8b0df0394900           -mov ecx, dword ptr [0x4939f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798960) /* 0x4939f0 */);
    // 0041b9fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b9fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b9ff  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ba01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ba02  e8e2940000             -call 0x424ee9
    cpu.esp -= 4;
    sub_424ee9(app, cpu);
    // 0041ba07  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041ba0b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ba0e  3bc1                   +cmp eax, ecx
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
    // 0041ba10  7415                   -je 0x41ba27
    if (cpu.flags.zf)
    {
        goto L_0x0041ba27;
    }
    // 0041ba12  6868b94300             -push 0x43b968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438376 /*0x43b968*/;
    cpu.esp -= 4;
    // 0041ba17  e874250000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041ba1c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ba1f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ba21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ba22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ba23  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ba26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ba27:
    // 0041ba27  8b15f0394900           -mov edx, dword ptr [0x4939f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798960) /* 0x4939f0 */);
    // 0041ba2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041ba2e  e8bd930000             -call 0x424df0
    cpu.esp -= 4;
    sub_424df0(app, cpu);
    // 0041ba33  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ba36  e835feffff             -call 0x41b870
    cpu.esp -= 4;
    sub_41b870(app, cpu);
    // 0041ba3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ba3c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041ba41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ba42  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ba45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41ba50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ba50  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ba53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ba54  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041ba58  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041ba5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ba5b  7513                   -jne 0x41ba70
    if (!cpu.flags.zf)
    {
        goto L_0x0041ba70;
    }
    // 0041ba5d  689cba4300             -push 0x43ba9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438684 /*0x43ba9c*/;
    cpu.esp -= 4;
    // 0041ba62  e829250000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041ba67  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ba6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ba6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ba6c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ba6f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ba70:
    // 0041ba70  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041ba72  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041ba74  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041ba78  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041ba7b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041ba7f  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041ba82  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041ba86  8b0df4394900           -mov ecx, dword ptr [0x4939f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041ba8c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041ba8f  a1f8394900             -mov eax, dword ptr [0x4939f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041ba94  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0041ba98  c644241700             -mov byte ptr [esp + 0x17], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(23) /* 0x17 */) = 0 /*0x0*/;
    // 0041ba9d  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0041baa0  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041baa2  3bc2                   +cmp eax, edx
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
    // 0041baa4  732a                   -jae 0x41bad0
    if (!cpu.flags.cf)
    {
        goto L_0x0041bad0;
    }
L_0x0041baa6:
    // 0041baa6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041baaa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041baab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041baac  e83f330100             -call 0x42edf0
    cpu.esp -= 4;
    sub_42edf0(app, cpu);
    // 0041bab1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041bab4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bab6  7444                   -je 0x41bafc
    if (cpu.flags.zf)
    {
        goto L_0x0041bafc;
    }
    // 0041bab8  8b0df4394900           -mov ecx, dword ptr [0x4939f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041babe  a1f8394900             -mov eax, dword ptr [0x4939f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041bac3  81c710010000           -add edi, 0x110
    (cpu.edi) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0041bac9  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0041bacc  3bfa                   +cmp edi, edx
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
    // 0041bace  72d6                   -jb 0x41baa6
    if (cpu.flags.cf)
    {
        goto L_0x0041baa6;
    }
L_0x0041bad0:
    // 0041bad0  81c110010000           -add ecx, 0x110
    (cpu.ecx) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0041bad6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bad7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bad8  e8ebaa0000             -call 0x4265c8
    cpu.esp -= 4;
    sub_4265c8(app, cpu);
    // 0041badd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041bae0  a3f8394900             -mov dword ptr [0x4939f8], eax
    app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */) = cpu.eax;
    // 0041bae5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bae7  7520                   -jne 0x41bb09
    if (!cpu.flags.zf)
    {
        goto L_0x0041bb09;
    }
    // 0041bae9  6874ba4300             -push 0x43ba74
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438644 /*0x43ba74*/;
    cpu.esp -= 4;
    // 0041baee  e89d240000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041baf3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041baf6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041baf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041baf8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bafb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bafc:
    // 0041bafc  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 0041bb01  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0041bb03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb05  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bb08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bb09:
    // 0041bb09  8b0df4394900           -mov ecx, dword ptr [0x4939f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041bb0f  8d3c01                 -lea edi, [ecx + eax]
    cpu.edi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0041bb12  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 0041bb17  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0041bb19  8b15f4394900           -mov edx, dword ptr [0x4939f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041bb1f  a1f8394900             -mov eax, dword ptr [0x4939f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041bb24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb26  c644020f00             -mov byte ptr [edx + eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 1) = 0 /*0x0*/;
    // 0041bb2b  a1f4394900             -mov eax, dword ptr [0x4939f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041bb30  0510010000             -add eax, 0x110
    (cpu.eax) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0041bb35  a3f4394900             -mov dword ptr [0x4939f4], eax
    app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */) = cpu.eax;
    // 0041bb3a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bb3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41bb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041bb40  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bb43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bb44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041bb45  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041bb49  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041bb4b  7515                   -jne 0x41bb62
    if (!cpu.flags.zf)
    {
        goto L_0x0041bb62;
    }
    // 0041bb4d  68d0ba4300             -push 0x43bad0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438736 /*0x43bad0*/;
    cpu.esp -= 4;
    // 0041bb52  e839240000             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0041bb57  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041bb5a:
    // 0041bb5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb5b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041bb5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb5e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bb61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bb62:
    // 0041bb62  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041bb64  8b35f8394900           -mov esi, dword ptr [0x4939f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041bb6a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041bb6c  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041bb70  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041bb73  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041bb77  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041bb7a  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041bb7e  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041bb81  a1f4394900             -mov eax, dword ptr [0x4939f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041bb86  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0041bb88  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0041bb8c  3bf0                   +cmp esi, eax
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
    // 0041bb8e  c644241700             -mov byte ptr [esp + 0x17], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(23) /* 0x17 */) = 0 /*0x0*/;
    // 0041bb93  73c5                   -jae 0x41bb5a
    if (!cpu.flags.cf)
    {
        goto L_0x0041bb5a;
    }
L_0x0041bb95:
    // 0041bb95  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041bb99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bb9a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bb9b  e850320100             -call 0x42edf0
    cpu.esp -= 4;
    sub_42edf0(app, cpu);
    // 0041bba0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041bba3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bba5  741f                   -je 0x41bbc6
    if (cpu.flags.zf)
    {
        goto L_0x0041bbc6;
    }
    // 0041bba7  8b15f8394900           -mov edx, dword ptr [0x4939f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798968) /* 0x4939f8 */);
    // 0041bbad  a1f4394900             -mov eax, dword ptr [0x4939f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798964) /* 0x4939f4 */);
    // 0041bbb2  81c610010000           -add esi, 0x110
    (cpu.esi) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0041bbb8  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041bbba  3bf0                   +cmp esi, eax
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
    // 0041bbbc  72d7                   -jb 0x41bb95
    if (cpu.flags.cf)
    {
        goto L_0x0041bb95;
    }
    // 0041bbbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbbf  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041bbc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbc2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bbc5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bbc6:
    // 0041bbc6  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 0041bbcb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041bbd0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0041bbd2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbd3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbd4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bbd7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41bbe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041bbe0  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0041bbe3  a114bb4300             -mov eax, dword ptr [0x43bb14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4438804) /* 0x43bb14 */);
    // 0041bbe8  8b0d18bb4300           -mov ecx, dword ptr [0x43bb18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4438808) /* 0x43bb18 */);
    // 0041bbee  8b1510bb4300           -mov edx, dword ptr [0x43bb10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4438800) /* 0x43bb10 */);
    // 0041bbf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041bbf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bbf6  8b742460               -mov esi, dword ptr [esp + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0041bbfa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041bbfb  89442416               -mov dword ptr [esp + 0x16], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(22) /* 0x16 */) = cpu.eax;
    // 0041bbff  894c241a               -mov dword ptr [esp + 0x1a], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(26) /* 0x1a */) = cpu.ecx;
    // 0041bc03  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 0041bc08  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041bc0a  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0041bc0c  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0041bc0e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041bc10  6804bb4300             -push 0x43bb04
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438788 /*0x43bb04*/;
    cpu.esp -= 4;
    // 0041bc15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bc16  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0041bc18  c644241801             -mov byte ptr [esp + 0x18], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) = 1 /*0x1*/;
    // 0041bc1d  885c2419               -mov byte ptr [esp + 0x19], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(25) /* 0x19 */) = cpu.bl;
    // 0041bc21  885c241a               -mov byte ptr [esp + 0x1a], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(26) /* 0x1a */) = cpu.bl;
    // 0041bc25  c644241b02             -mov byte ptr [esp + 0x1b], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(27) /* 0x1b */) = 2 /*0x2*/;
    // 0041bc2a  885c241c               -mov byte ptr [esp + 0x1c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.bl;
    // 0041bc2e  885c241d               -mov byte ptr [esp + 0x1d], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) = cpu.bl;
    // 0041bc32  885c241e               -mov byte ptr [esp + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 0041bc36  885c241f               -mov byte ptr [esp + 0x1f], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(31) /* 0x1f */) = cpu.bl;
    // 0041bc3a  885c2420               -mov byte ptr [esp + 0x20], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.bl;
    // 0041bc3e  885c2421               -mov byte ptr [esp + 0x21], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(33) /* 0x21 */) = cpu.bl;
    // 0041bc42  8954244a               -mov dword ptr [esp + 0x4a], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(74) /* 0x4a */) = cpu.edx;
    // 0041bc46  c644245e80             -mov byte ptr [esp + 0x5e], 0x80
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(94) /* 0x5e */) = 128 /*0x80*/;
    // 0041bc4b  885c245f               -mov byte ptr [esp + 0x5f], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(95) /* 0x5f */) = cpu.bl;
    // 0041bc4f  66895c2460             -mov word ptr [esp + 0x60], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.bx;
    // 0041bc54  66895c2462             -mov word ptr [esp + 0x62], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(98) /* 0x62 */) = cpu.bx;
    // 0041bc59  885c2464               -mov byte ptr [esp + 0x64], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.bl;
    // 0041bc5d  885c2465               -mov byte ptr [esp + 0x65], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(101) /* 0x65 */) = cpu.bl;
    // 0041bc61  885c2466               -mov byte ptr [esp + 0x66], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(102) /* 0x66 */) = cpu.bl;
    // 0041bc65  885c2467               -mov byte ptr [esp + 0x67], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(103) /* 0x67 */) = cpu.bl;
    // 0041bc69  885c2468               -mov byte ptr [esp + 0x68], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.bl;
    // 0041bc6d  885c2469               -mov byte ptr [esp + 0x69], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(105) /* 0x69 */) = cpu.bl;
    // 0041bc71  e85a990000             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0041bc76  885e0f                 -mov byte ptr [esi + 0xf], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.bl;
    // 0041bc79  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0041bc7c  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0041bc81  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041bc85  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0041bc87  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041bc8a  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0041bc8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc8f  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0041bc92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41bca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041bca0  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0041bca6  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0041bcab  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041bcad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bcae  8bb42408010000         -mov esi, dword ptr [esp + 0x108]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0041bcb5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041bcb6  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041bcba  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0041bcbc  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 0041bcc1  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0041bcc3  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0041bcc5  681cbb4300             -push 0x43bb1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438812 /*0x43bb1c*/;
    cpu.esp -= 4;
    // 0041bcca  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0041bccc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bccd  e8fe980000             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0041bcd2  c6460f00               -mov byte ptr [esi + 0xf], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 0041bcd6  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0041bcd9  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0041bcde  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041bce2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041bce5  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0041bce7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bce8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bce9  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0041bcef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41bcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041bcf0  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041bcf3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041bcf4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bcf5  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041bcf9  b080                   -mov al, 0x80
    cpu.al = 128 /*0x80*/;
    // 0041bcfb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041bcfc  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0041bd00  8844240d               -mov byte ptr [esp + 0xd], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0041bd04  8844240f               -mov byte ptr [esp + 0xf], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(15) /* 0xf */) = cpu.al;
    // 0041bd08  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 0041bd0c  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 0041bd11  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041bd13  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0041bd15  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0041bd17  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041bd19  6828bb4300             -push 0x43bb28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438824 /*0x43bb28*/;
    cpu.esp -= 4;
    // 0041bd1e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bd1f  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0041bd21  c644241a04             -mov byte ptr [esp + 0x1a], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(26) /* 0x1a */) = 4 /*0x4*/;
    // 0041bd26  c644241d01             -mov byte ptr [esp + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 0041bd2b  66c744241e8002         -mov word ptr [esp + 0x1e], 0x280
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = 640 /*0x280*/;
    // 0041bd32  66c7442420e001         -mov word ptr [esp + 0x20], 0x1e0
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */) = 480 /*0x1e0*/;
    // 0041bd39  66c74424221000         -mov word ptr [esp + 0x22], 0x10
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(34) /* 0x22 */) = 16 /*0x10*/;
    // 0041bd40  885c2424               -mov byte ptr [esp + 0x24], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.bl;
    // 0041bd44  895c2425               -mov dword ptr [esp + 0x25], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(37) /* 0x25 */) = cpu.ebx;
    // 0041bd48  895c2429               -mov dword ptr [esp + 0x29], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(41) /* 0x29 */) = cpu.ebx;
    // 0041bd4c  e87f980000             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0041bd51  885e0f                 -mov byte ptr [esi + 0xf], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.bl;
    // 0041bd54  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0041bd57  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0041bd5c  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041bd60  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0041bd62  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041bd65  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0041bd66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bd67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bd68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bd69  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041bd6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41bd70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041bd70  6800574900             -push 0x495700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806400 /*0x495700*/;
    cpu.esp -= 4;
    // 0041bd75  e8d6fcffff             -call 0x41ba50
    cpu.esp -= 4;
    sub_41ba50(app, cpu);
    // 0041bd7a  6840594900             -push 0x495940
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806976 /*0x495940*/;
    cpu.esp -= 4;
    // 0041bd7f  e8ccfcffff             -call 0x41ba50
    cpu.esp -= 4;
    sub_41ba50(app, cpu);
    // 0041bd84  6820584900             -push 0x495820
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806688 /*0x495820*/;
    cpu.esp -= 4;
    // 0041bd89  e8c2fcffff             -call 0x41ba50
    cpu.esp -= 4;
    sub_41ba50(app, cpu);
    // 0041bd8e  a13d584900             -mov eax, dword ptr [0x49583d]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */);
    // 0041bd93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bd94  6834bb4300             -push 0x43bb34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438836 /*0x43bb34*/;
    cpu.esp -= 4;
    // 0041bd99  e8f6930000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041bd9e  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041bda2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bda3  e8f8faffff             -call 0x41b8a0
    cpu.esp -= 4;
    sub_41b8a0(app, cpu);
    // 0041bda8  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041bdab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41bdb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041bdb0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041bdb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bdb5  e8f6f8ffff             -call 0x41b6b0
    cpu.esp -= 4;
    sub_41b6b0(app, cpu);
    // 0041bdba  6800574900             -push 0x495700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806400 /*0x495700*/;
    cpu.esp -= 4;
    // 0041bdbf  e81cfeffff             -call 0x41bbe0
    cpu.esp -= 4;
    sub_41bbe0(app, cpu);
    // 0041bdc4  6840594900             -push 0x495940
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806976 /*0x495940*/;
    cpu.esp -= 4;
    // 0041bdc9  e8d2feffff             -call 0x41bca0
    cpu.esp -= 4;
    sub_41bca0(app, cpu);
    // 0041bdce  6820584900             -push 0x495820
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806688 /*0x495820*/;
    cpu.esp -= 4;
    // 0041bdd3  e818ffffff             -call 0x41bcf0
    cpu.esp -= 4;
    sub_41bcf0(app, cpu);
    // 0041bdd8  8b0d3d584900           -mov ecx, dword ptr [0x49583d]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */);
    // 0041bdde  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bddf  685cbb4300             -push 0x43bb5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438876 /*0x43bb5c*/;
    cpu.esp -= 4;
    // 0041bde4  e8ab930000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041bde9  6800574900             -push 0x495700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806400 /*0x495700*/;
    cpu.esp -= 4;
    // 0041bdee  e84dfdffff             -call 0x41bb40
    cpu.esp -= 4;
    sub_41bb40(app, cpu);
    // 0041bdf3  6840594900             -push 0x495940
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806976 /*0x495940*/;
    cpu.esp -= 4;
    // 0041bdf8  e843fdffff             -call 0x41bb40
    cpu.esp -= 4;
    sub_41bb40(app, cpu);
    // 0041bdfd  6820584900             -push 0x495820
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806688 /*0x495820*/;
    cpu.esp -= 4;
    // 0041be02  e839fdffff             -call 0x41bb40
    cpu.esp -= 4;
    sub_41bb40(app, cpu);
    // 0041be07  8b153d584900           -mov edx, dword ptr [0x49583d]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4806717) /* 0x49583d */);
    // 0041be0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041be0e  6848bb4300             -push 0x43bb48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438856 /*0x43bb48*/;
    cpu.esp -= 4;
    // 0041be13  e87c930000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041be18  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0041be1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41be20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041be20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041be21  8b35043a4900           -mov esi, dword ptr [0x493a04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4798980) /* 0x493a04 */);
    // 0041be27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041be28  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041be2c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041be2e  7415                   -je 0x41be45
    if (cpu.flags.zf)
    {
        goto L_0x0041be45;
    }
L_0x0041be30:
    // 0041be30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041be31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041be32  e8b92f0100             -call 0x42edf0
    cpu.esp -= 4;
    sub_42edf0(app, cpu);
    // 0041be37  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041be3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041be3c  741a                   -je 0x41be58
    if (cpu.flags.zf)
    {
        goto L_0x0041be58;
    }
    // 0041be3e  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0041be41  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041be43  75eb                   -jne 0x41be30
    if (!cpu.flags.zf)
    {
        goto L_0x0041be30;
    }
L_0x0041be45:
    // 0041be45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041be46  6874bb4300             -push 0x43bb74
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438900 /*0x43bb74*/;
    cpu.esp -= 4;
    // 0041be4b  e844930000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041be50  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041be53  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041be55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041be58:
    // 0041be58  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0041be5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41be60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041be60  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041be64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041be65  8b35043a4900           -mov esi, dword ptr [0x493a04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4798980) /* 0x493a04 */);
    // 0041be6b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041be6d  740c                   -je 0x41be7b
    if (cpu.flags.zf)
    {
        goto L_0x0041be7b;
    }
L_0x0041be6f:
    // 0041be6f  3b4620                 +cmp eax, dword ptr [esi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041be72  7419                   -je 0x41be8d
    if (cpu.flags.zf)
    {
        goto L_0x0041be8d;
    }
    // 0041be74  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0041be77  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041be79  75f4                   -jne 0x41be6f
    if (!cpu.flags.zf)
    {
        goto L_0x0041be6f;
    }
L_0x0041be7b:
    // 0041be7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041be7c  68a8bb4300             -push 0x43bba8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438952 /*0x43bba8*/;
    cpu.esp -= 4;
    // 0041be81  e80e930000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041be86  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041be89  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041be8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041be8d:
    // 0041be8d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041be8e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041be8f  6894bb4300             -push 0x43bb94
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438932 /*0x43bb94*/;
    cpu.esp -= 4;
    // 0041be94  e8fb920000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041be99  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041be9c  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041be9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41bea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041bea0  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0041bea6  b8c0564900             -mov eax, 0x4956c0
    cpu.eax = 4806336 /*0x4956c0*/;
L_0x0041beab:
    // 0041beab  66c74002ffff           -mov word ptr [eax + 2], 0xffff
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 65535 /*0xffff*/;
    // 0041beb1  66c700ffff             -mov word ptr [eax], 0xffff
    app->getMemory<x86::reg16>(cpu.eax) = 65535 /*0xffff*/;
    // 0041beb6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041beb9  3de4564900             +cmp eax, 0x4956e4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4806372 /*0x4956e4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041bebe  7ceb                   -jl 0x41beab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041beab;
    }
    // 0041bec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041bec1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bec2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041bec3  6898b44300             -push 0x43b498
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437144 /*0x43b498*/;
    cpu.esp -= 4;
    // 0041bec8  68e0ad4300             -push 0x43ade0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4435424 /*0x43ade0*/;
    cpu.esp -= 4;
    // 0041becd  e8af920000             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 0041bed2  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041bed4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041bed7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041bed9  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0041bedd  7517                   -jne 0x41bef6
    if (!cpu.flags.zf)
    {
        goto L_0x0041bef6;
    }
    // 0041bedf  6834bc4300             -push 0x43bc34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439092 /*0x43bc34*/;
    cpu.esp -= 4;
    // 0041bee4  e8ab920000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041bee9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041beec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041beed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041beee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041beef  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0041bef5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bef6:
    // 0041bef6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bef7  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041befb  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 0041befd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041befe  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041bf00  e86ca60000             -call 0x426571
    cpu.esp -= 4;
    sub_426571(app, cpu);
    // 0041bf05  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0041bf08  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041bf0b  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0041bf0d  0f8517010000           -jne 0x41c02a
    if (!cpu.flags.zf)
    {
        goto L_0x0041c02a;
    }
    // 0041bf13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041bf14  bdc2564900             -mov ebp, 0x4956c2
    cpu.ebp = 4806338 /*0x4956c2*/;
    // 0041bf19  bfc0564900             -mov edi, 0x4956c0
    cpu.edi = 4806336 /*0x4956c0*/;
L_0x0041bf1e:
    // 0041bf1e  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 0041bf20  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041bf24  6824bc4300             -push 0x43bc24
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439076 /*0x43bc24*/;
    cpu.esp -= 4;
    // 0041bf29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bf2a  e8512f0100             -call 0x42ee80
    cpu.esp -= 4;
    sub_42ee80(app, cpu);
    // 0041bf2f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041bf32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bf34  7516                   -jne 0x41bf4c
    if (!cpu.flags.zf)
    {
        goto L_0x0041bf4c;
    }
    // 0041bf36  4b                     -dec ebx
    (cpu.ebx)--;
    // 0041bf37  83ef04                 -sub edi, 4
    (cpu.edi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041bf3a  c705fc39490001000000   -mov dword ptr [0x4939fc], 1
    app->getMemory<x86::reg32>(x86::reg32(4798972) /* 0x4939fc */) = 1 /*0x1*/;
    // 0041bf44  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041bf47  e9b6000000             -jmp 0x41c002
    goto L_0x0041c002;
L_0x0041bf4c:
    // 0041bf4c  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 0041bf4e  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041bf52  6814bc4300             -push 0x43bc14
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439060 /*0x43bc14*/;
    cpu.esp -= 4;
    // 0041bf57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041bf58  e8232f0100             -call 0x42ee80
    cpu.esp -= 4;
    sub_42ee80(app, cpu);
    // 0041bf5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041bf60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bf62  7516                   -jne 0x41bf7a
    if (!cpu.flags.zf)
    {
        goto L_0x0041bf7a;
    }
    // 0041bf64  4b                     -dec ebx
    (cpu.ebx)--;
    // 0041bf65  83ef04                 -sub edi, 4
    (cpu.edi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041bf68  c705003a490001000000   -mov dword ptr [0x493a00], 1
    app->getMemory<x86::reg32>(x86::reg32(4798976) /* 0x493a00 */) = 1 /*0x1*/;
    // 0041bf72  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041bf75  e988000000             -jmp 0x41c002
    goto L_0x0041c002;
L_0x0041bf7a:
    // 0041bf7a  8a4c2414               -mov cl, byte ptr [esp + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041bf7e  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041bf82  80f93a                 +cmp cl, 0x3a
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041bf85  740d                   -je 0x41bf94
    if (cpu.flags.zf)
    {
        goto L_0x0041bf94;
    }
L_0x0041bf87:
    // 0041bf87  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0041bf89  7409                   -je 0x41bf94
    if (cpu.flags.zf)
    {
        goto L_0x0041bf94;
    }
    // 0041bf8b  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0041bf8e  40                     -inc eax
    (cpu.eax)++;
    // 0041bf8f  80f93a                 +cmp cl, 0x3a
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041bf92  75f3                   -jne 0x41bf87
    if (!cpu.flags.zf)
    {
        goto L_0x0041bf87;
    }
L_0x0041bf94:
    // 0041bf94  803800                 +cmp byte ptr [eax], 0
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
    // 0041bf97  0f8487000000           -je 0x41c024
    if (cpu.flags.zf)
    {
        goto L_0x0041c024;
    }
    // 0041bf9d  8d8c24d4000000         -lea ecx, [esp + 0xd4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(212) /* 0xd4 */);
    // 0041bfa4  8d942494000000         -lea edx, [esp + 0x94]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0041bfab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bfac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041bfad  40                     -inc eax
    (cpu.eax)++;
    // 0041bfae  680cbc4300             -push 0x43bc0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439052 /*0x43bc0c*/;
    cpu.esp -= 4;
    // 0041bfb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bfb4  e8eb9e0000             -call 0x425ea4
    cpu.esp -= 4;
    sub_425ea4(app, cpu);
    // 0041bfb9  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041bfbb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bfbe  83fe01                 +cmp esi, 1
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
    // 0041bfc1  7c15                   -jl 0x41bfd8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041bfd8;
    }
    // 0041bfc3  8d842494000000         -lea eax, [esp + 0x94]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0041bfca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bfcb  e850feffff             -call 0x41be20
    cpu.esp -= 4;
    sub_41be20(app, cpu);
    // 0041bfd0  83c404                 +add esp, 4
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
    // 0041bfd3  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0041bfd6  eb05                   -jmp 0x41bfdd
    goto L_0x0041bfdd;
L_0x0041bfd8:
    // 0041bfd8  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
L_0x0041bfdd:
    // 0041bfdd  83fe02                 +cmp esi, 2
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
    // 0041bfe0  7516                   -jne 0x41bff8
    if (!cpu.flags.zf)
    {
        goto L_0x0041bff8;
    }
    // 0041bfe2  8d8c24d4000000         -lea ecx, [esp + 0xd4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(212) /* 0xd4 */);
    // 0041bfe9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bfea  e831feffff             -call 0x41be20
    cpu.esp -= 4;
    sub_41be20(app, cpu);
    // 0041bfef  83c404                 +add esp, 4
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
    // 0041bff2  66894500               -mov word ptr [ebp], ax
    app->getMemory<x86::reg16>(cpu.ebp) = cpu.ax;
    // 0041bff6  eb06                   -jmp 0x41bffe
    goto L_0x0041bffe;
L_0x0041bff8:
    // 0041bff8  66c745000000           -mov word ptr [ebp], 0
    app->getMemory<x86::reg16>(cpu.ebp) = 0 /*0x0*/;
L_0x0041bffe:
    // 0041bffe  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0041c002:
    // 0041c002  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c003  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041c007  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 0041c009  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c00a  43                     -inc ebx
    (cpu.ebx)++;
    // 0041c00b  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c00e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c011  e85ba50000             -call 0x426571
    cpu.esp -= 4;
    sub_426571(app, cpu);
    // 0041c016  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0041c019  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c01c  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0041c01e  0f84fafeffff           -je 0x41bf1e
    if (cpu.flags.zf)
    {
        goto L_0x0041bf1e;
    }
L_0x0041c024:
    // 0041c024  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c027  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c028  741a                   -je 0x41c044
    if (cpu.flags.zf)
    {
        goto L_0x0041c044;
    }
L_0x0041c02a:
    // 0041c02a  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0041c02c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041c02d  68dcbb4300             -push 0x43bbdc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439004 /*0x43bbdc*/;
    cpu.esp -= 4;
    // 0041c032  e85d910000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c037  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c03a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c03b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c03c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c03d  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0041c043  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c044:
    // 0041c044  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041c046  bec2564900             -mov esi, 0x4956c2
    cpu.esi = 4806338 /*0x4956c2*/;
L_0x0041c04b:
    // 0041c04b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c04d  668b46fe               -mov ax, word ptr [esi - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0041c051  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c052  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c053  68ccbb4300             -push 0x43bbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438988 /*0x43bbcc*/;
    cpu.esp -= 4;
    // 0041c058  e837910000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c05d  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0041c060  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c063  663dffff               +cmp ax, 0xffff
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
    // 0041c067  7413                   -je 0x41c07c
    if (cpu.flags.zf)
    {
        goto L_0x0041c07c;
    }
    // 0041c069  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041c06e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c06f  68c8bb4300             -push 0x43bbc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4438984 /*0x43bbc8*/;
    cpu.esp -= 4;
    // 0041c074  e81b910000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c079  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041c07c:
    // 0041c07c  68b0284300             -push 0x4328b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401328 /*0x4328b0*/;
    cpu.esp -= 4;
    // 0041c081  e80e910000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c086  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c089  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c08c  47                     -inc edi
    (cpu.edi)++;
    // 0041c08d  81fee6564900           +cmp esi, 0x4956e6
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4806374 /*0x4956e6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c093  7cb6                   -jl 0x41c04b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041c04b;
    }
    // 0041c095  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041c099  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c09a  e8518d0000             -call 0x424df0
    cpu.esp -= 4;
    sub_424df0(app, cpu);
    // 0041c09f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c0a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c0a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c0a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c0a5  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0041c0ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41c0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c0b0  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c0b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c0b7  6898b44300             -push 0x43b498
    app->getMemory<x86::reg32>(cpu.esp-4) = 4437144 /*0x43b498*/;
    cpu.esp -= 4;
    // 0041c0bc  6880bc4300             -push 0x43bc80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439168 /*0x43bc80*/;
    cpu.esp -= 4;
    // 0041c0c1  e8bb900000             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 0041c0c6  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041c0c8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041c0cb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041c0cd  7515                   -jne 0x41c0e4
    if (!cpu.flags.zf)
    {
        goto L_0x0041c0e4;
    }
    // 0041c0cf  6868bc4300             -push 0x43bc68
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439144 /*0x43bc68*/;
    cpu.esp -= 4;
    // 0041c0d4  e8bb900000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c0d9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c0dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c0dd  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c0e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c0e4:
    // 0041c0e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c0e5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c0e9  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 0041c0eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c0ec  e880a40000             -call 0x426571
    cpu.esp -= 4;
    sub_426571(app, cpu);
    // 0041c0f1  8a470c                 -mov al, byte ptr [edi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0041c0f4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c0f7  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0041c0f9  7559                   -jne 0x41c154
    if (!cpu.flags.zf)
    {
        goto L_0x0041c154;
    }
    // 0041c0fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0041c0fc:
    // 0041c0fc  6a28                   -push 0x28
    app->getMemory<x86::reg32>(cpu.esp-4) = 40 /*0x28*/;
    cpu.esp -= 4;
    // 0041c0fe  e8728d0000             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0041c103  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041c105  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041c109  8d4e20                 -lea ecx, [esi + 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0041c10c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c10d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c10e  6860bc4300             -push 0x43bc60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439136 /*0x43bc60*/;
    cpu.esp -= 4;
    // 0041c113  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c114  e88b9d0000             -call 0x425ea4
    cpu.esp -= 4;
    sub_425ea4(app, cpu);
    // 0041c119  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041c11c  83f802                 +cmp eax, 2
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
    // 0041c11f  740d                   -je 0x41c12e
    if (cpu.flags.zf)
    {
        goto L_0x0041c12e;
    }
    // 0041c121  684cbc4300             -push 0x43bc4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439116 /*0x43bc4c*/;
    cpu.esp -= 4;
    // 0041c126  e869900000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c12b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041c12e:
    // 0041c12e  a1043a4900             -mov eax, dword ptr [0x493a04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798980) /* 0x493a04 */);
    // 0041c133  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c134  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041c138  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 0041c13a  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0041c13d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c13e  8935043a4900           -mov dword ptr [0x493a04], esi
    app->getMemory<x86::reg32>(x86::reg32(4798980) /* 0x493a04 */) = cpu.esi;
    // 0041c144  e828a40000             -call 0x426571
    cpu.esp -= 4;
    sub_426571(app, cpu);
    // 0041c149  8a470c                 -mov al, byte ptr [edi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0041c14c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c14f  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0041c151  74a9                   -je 0x41c0fc
    if (cpu.flags.zf)
    {
        goto L_0x0041c0fc;
    }
    // 0041c153  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041c154:
    // 0041c154  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c155  e8968c0000             -call 0x424df0
    cpu.esp -= 4;
    sub_424df0(app, cpu);
    // 0041c15a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c15d  e83efdffff             -call 0x41bea0
    cpu.esp -= 4;
    sub_41bea0(app, cpu);
    // 0041c162  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c163  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c169  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41c170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c170  a1043a4900             -mov eax, dword ptr [0x493a04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798980) /* 0x493a04 */);
    // 0041c175  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c177  741b                   -je 0x41c194
    if (cpu.flags.zf)
    {
        goto L_0x0041c194;
    }
    // 0041c179  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0041c17a:
    // 0041c17a  8b7024                 -mov esi, dword ptr [eax + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0041c17d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c17e  e8c38c0000             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0041c183  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c186  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041c188  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041c18a  75ee                   -jne 0x41c17a
    if (!cpu.flags.zf)
    {
        goto L_0x0041c17a;
    }
    // 0041c18c  8935043a4900           -mov dword ptr [0x493a04], esi
    app->getMemory<x86::reg32>(x86::reg32(4798980) /* 0x493a04 */) = cpu.esi;
    // 0041c192  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c193  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c194:
    // 0041c194  c705043a490000000000   -mov dword ptr [0x493a04], 0
    app->getMemory<x86::reg32>(x86::reg32(4798980) /* 0x493a04 */) = 0 /*0x0*/;
    // 0041c19e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41c1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c1a0  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c1a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041c1a7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041c1a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c1a9  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041c1ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c1ac  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041c1af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c1b1  751f                   -jne 0x41c1d2
    if (!cpu.flags.zf)
    {
        goto L_0x0041c1d2;
    }
    // 0041c1b3  6808bd4300             -push 0x43bd08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439304 /*0x43bd08*/;
    cpu.esp -= 4;
    // 0041c1b8  e8d78f0000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c1bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c1c0  b8f0010480             -mov eax, 0x800401f0
    cpu.eax = 2147746288 /*0x800401f0*/;
    // 0041c1c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c1c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c1c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c1c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c1c9  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c1cf  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0041c1d2:
    // 0041c1d2  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0041c1d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c1db  0f8495000000           -je 0x41c276
    if (cpu.flags.zf)
    {
        goto L_0x0041c276;
    }
    // 0041c1e1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c1e3  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041c1e6  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041c1e9  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041c1ec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041c1ee  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0041c1f2  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0041c1f6  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041c1fa  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041c1fe  7d16                   -jge 0x41c216
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041c216;
    }
    // 0041c200  8bbc24a0000000         -mov edi, dword ptr [esp + 0xa0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0041c207  2bfa                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c209  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c20b  89bc24a0000000         -mov dword ptr [esp + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.edi;
    // 0041c212  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x0041c216:
    // 0041c216  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0041c218  7d16                   -jge 0x41c230
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041c230;
    }
    // 0041c21a  8bbc24a4000000         -mov edi, dword ptr [esp + 0xa4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0041c221  2bfb                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c223  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c225  89bc24a4000000         -mov dword ptr [esp + 0xa4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.edi;
    // 0041c22c  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
L_0x0041c230:
    // 0041c230  8b7e50                 -mov edi, dword ptr [esi + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0041c233  3bcf                   +cmp ecx, edi
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
    // 0041c235  7e1a                   -jle 0x41c251
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c251;
    }
    // 0041c237  8bef                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0041c239  2be9                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041c23b  8b8c24a8000000         -mov ecx, dword ptr [esp + 0xa8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0041c242  03cd                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0041c244  898c24a8000000         -mov dword ptr [esp + 0xa8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */) = cpu.ecx;
    // 0041c24b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041c24d  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0041c251:
    // 0041c251  8b7e54                 -mov edi, dword ptr [esi + 0x54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0041c254  3bc7                   +cmp eax, edi
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
    // 0041c256  7e3a                   -jle 0x41c292
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c292;
    }
    // 0041c258  8bef                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0041c25a  2be8                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c25c  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0041c25e  8bac24ac000000         -mov ebp, dword ptr [esp + 0xac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0041c265  03e8                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041c267  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041c269  89ac24ac000000         -mov dword ptr [esp + 0xac], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.ebp;
    // 0041c270  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041c274  eb23                   -jmp 0x41c299
    goto L_0x0041c299;
L_0x0041c276:
    // 0041c276  8b4e50                 -mov ecx, dword ptr [esi + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0041c279  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0041c27c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c27e  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041c280  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0041c284  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0041c288  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041c28c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041c290  eb9e                   -jmp 0x41c230
    goto L_0x0041c230;
L_0x0041c292:
    // 0041c292  8bac24ac000000         -mov ebp, dword ptr [esp + 0xac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
L_0x0041c299:
    // 0041c299  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c29b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041c29d  0f8e8d010000           -jle 0x41c430
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c430;
    }
    // 0041c2a3  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c2a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c2a7  0f8e83010000           -jle 0x41c430
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c430;
    }
    // 0041c2ad  8b8424a8000000         -mov eax, dword ptr [esp + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0041c2b4  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0041c2bb  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c2bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c2bf  0f8e6b010000           -jle 0x41c430
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c430;
    }
    // 0041c2c5  2bac24a4000000         -sub ebp, dword ptr [esp + 0xa4]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
    // 0041c2cc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041c2ce  0f8e5c010000           -jle 0x41c430
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c430;
    }
    // 0041c2d4  8bbc2498000000         -mov edi, dword ptr [esp + 0x98]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0041c2db  833f00                 +cmp dword ptr [edi], 0
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
    // 0041c2de  7528                   -jne 0x41c308
    if (!cpu.flags.zf)
    {
        goto L_0x0041c308;
    }
    // 0041c2e0  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0041c2e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c2e9  750a                   -jne 0x41c2f5
    if (!cpu.flags.zf)
    {
        goto L_0x0041c2f5;
    }
    // 0041c2eb  68d8bc4300             -push 0x43bcd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439256 /*0x43bcd8*/;
    cpu.esp -= 4;
    // 0041c2f0  e933010000             -jmp 0x41c428
    goto L_0x0041c428;
L_0x0041c2f5:
    // 0041c2f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c2f6  e88585feff             -call 0x404880
    cpu.esp -= 4;
    sub_404880(app, cpu);
    // 0041c2fb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c2fe  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0041c300  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c302  0f841b010000           -je 0x41c423
    if (cpu.flags.zf)
    {
        goto L_0x0041c423;
    }
L_0x0041c308:
    // 0041c308  8b9c24b4000000         -mov ebx, dword ptr [esp + 0xb4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0041c30f  8bac24b0000000         -mov ebp, dword ptr [esp + 0xb0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0041c316  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041c319  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041c31a  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0041c321  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041c322  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c324  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c325  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041c327  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c328  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041c32c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c32d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c32e  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c331  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c333  0f8df7000000           -jge 0x41c430
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041c430;
    }
    // 0041c339  3dc2017688             +cmp eax, 0x887601c2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435074 /*0x887601c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c33e  753e                   -jne 0x41c37e
    if (!cpu.flags.zf)
    {
        goto L_0x0041c37e;
    }
    // 0041c340  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041c342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c343  e89884feff             -call 0x4047e0
    cpu.esp -= 4;
    sub_4047e0(app, cpu);
    // 0041c348  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041c34b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c34e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c350  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c351  ff516c                 -call dword ptr [ecx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c354  8b7648                 -mov esi, dword ptr [esi + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041c357  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041c359  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041c35a  8d8424a4000000         -lea eax, [esp + 0xa4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0041c361  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041c363  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041c364  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c365  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041c369  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c36a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c36b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c36c  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c36f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c370  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c371  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c372  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c374  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c375  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c37b  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0041c37e:
    // 0041c37e  3d96007688             +cmp eax, 0x88760096
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289434774 /*0x88760096*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c383  7571                   -jne 0x41c3f6
    if (!cpu.flags.zf)
    {
        goto L_0x0041c3f6;
    }
    // 0041c385  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0041c387  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041c38b  c74424246c000000       -mov dword ptr [esp + 0x24], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 108 /*0x6c*/;
    // 0041c393  c744242806000000       -mov dword ptr [esp + 0x28], 6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 6 /*0x6*/;
    // 0041c39b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c39d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c39e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c39f  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c3a2  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0041c3a6  8b8c24a8000000         -mov ecx, dword ptr [esp + 0xa8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0041c3ad  3bc8                   +cmp ecx, eax
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
    // 0041c3af  7607                   -jbe 0x41c3b8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041c3b8;
    }
    // 0041c3b1  898424a8000000         -mov dword ptr [esp + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */) = cpu.eax;
L_0x0041c3b8:
    // 0041c3b8  398424a4000000         +cmp dword ptr [esp + 0xa4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c3bf  760b                   -jbe 0x41c3cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041c3cc;
    }
    // 0041c3c1  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041c3c5  898424a4000000         -mov dword ptr [esp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
L_0x0041c3cc:
    // 0041c3cc  8b7648                 -mov esi, dword ptr [esi + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041c3cf  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0041c3d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041c3d2  8d9424a4000000         -lea edx, [esp + 0xa4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0041c3d9  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041c3db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041c3dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c3dd  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041c3e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c3e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c3e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c3e4  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c3e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c3e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c3e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c3ea  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c3ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c3ed  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c3f3  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0041c3f6:
    // 0041c3f6  8b8c24a4000000         -mov ecx, dword ptr [esp + 0xa4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0041c3fd  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0041c404  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c405  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c406  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c407  68bcbc4300             -push 0x43bcbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439228 /*0x43bcbc*/;
    cpu.esp -= 4;
    // 0041c40c  e8838d0000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c411  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c414  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c416  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c417  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c418  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c419  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c41a  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c420  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0041c423:
    // 0041c423  688cbc4300             -push 0x43bc8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439180 /*0x43bc8c*/;
    cpu.esp -= 4;
L_0x0041c428:
    // 0041c428  e8678d0000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041c42d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041c430:
    // 0041c430  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c431  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c432  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c433  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c435  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c436  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041c43c  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41c440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c440  8b4164                 -mov eax, dword ptr [ecx + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    // 0041c443  8b515c                 -mov edx, dword ptr [ecx + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 0041c446  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c448  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c44a  7e40                   -jle 0x41c48c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c48c;
    }
    // 0041c44c  8b5168                 -mov edx, dword ptr [ecx + 0x68]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 0041c44f  8b4160                 -mov eax, dword ptr [ecx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */);
    // 0041c452  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c454  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041c456  7e34                   -jle 0x41c48c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c48c;
    }
    // 0041c458  8b515c                 -mov edx, dword ptr [ecx + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 0041c45b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041c45d  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 0041c462  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c465  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0041c467  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0041c469  8b5160                 -mov edx, dword ptr [ecx + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */);
    // 0041c46c  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c46f  8b5164                 -mov edx, dword ptr [ecx + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    // 0041c472  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041c475  8b5168                 -mov edx, dword ptr [ecx + 0x68]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 0041c478  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041c47b  8b414c                 -mov eax, dword ptr [ecx + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0041c47e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c47f  8d5158                 -lea edx, [ecx + 0x58]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0041c482  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0041c485  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c486  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c487  e814fdffff             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
L_0x0041c48c:
    // 0041c48c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41c490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c490  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0041c492  68d8f14200             -push 0x42f1d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4387288 /*0x42f1d8*/;
    cpu.esp -= 4;
    // 0041c497  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0041c49d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c49e  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0041c4a5  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0041c4a8  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0041c4af  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041c4b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c4b1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041c4b3  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c4b5  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0041c4b9  3bc3                   +cmp eax, ebx
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
    // 0041c4bb  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0041c4be  895e08                 -mov dword ptr [esi + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0041c4c1  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041c4c4  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0041c4c7  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0041c4ca  895e14                 -mov dword ptr [esi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0041c4cd  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0041c4d0  895e34                 -mov dword ptr [esi + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0041c4d3  895e38                 -mov dword ptr [esi + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0041c4d6  895e3c                 -mov dword ptr [esi + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0041c4d9  895e40                 -mov dword ptr [esi + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0041c4dc  c70684014300           -mov dword ptr [esi], 0x430184
    app->getMemory<x86::reg32>(cpu.esi) = 4391300 /*0x430184*/;
    // 0041c4e2  7409                   -je 0x41c4ed
    if (cpu.flags.zf)
    {
        goto L_0x0041c4ed;
    }
    // 0041c4e4  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0041c4e7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c4e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c4ea  ff5104                 -call dword ptr [ecx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0041c4ed:
    // 0041c4ed  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0041c4f4  3bc3                   +cmp eax, ebx
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
    // 0041c4f6  742d                   -je 0x41c525
    if (cpu.flags.zf)
    {
        goto L_0x0041c525;
    }
    // 0041c4f8  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0041c4fb  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c4fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c4fe  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c501  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041c504  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041c508  c744240c6c000000       -mov dword ptr [esp + 0xc], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 108 /*0x6c*/;
    // 0041c510  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c511  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c513  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c514  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c517  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041c51b  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041c51f  894650                 -mov dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0041c522  894e54                 -mov dword ptr [esi + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.ecx;
L_0x0041c525:
    // 0041c525  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c526  895e4c                 -mov dword ptr [esi + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0041c529  895e5c                 -mov dword ptr [esi + 0x5c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = cpu.ebx;
    // 0041c52c  895e64                 -mov dword ptr [esi + 0x64], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.ebx;
    // 0041c52f  895e60                 -mov dword ptr [esi + 0x60], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.ebx;
    // 0041c532  895e68                 -mov dword ptr [esi + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 0041c535  8d7e7c                 -lea edi, [esi + 0x7c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0041c538  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c53a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c53c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041c53e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0041c540  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 0041c547  c706b4014300           -mov dword ptr [esi], 0x4301b4
    app->getMemory<x86::reg32>(cpu.esi) = 4391348 /*0x4301b4*/;
    // 0041c54d  889e9c000000           -mov byte ptr [esi + 0x9c], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(156) /* 0x9c */) = cpu.bl;
    // 0041c553  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c556  899ea0000000           -mov dword ptr [esi + 0xa0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = cpu.ebx;
    // 0041c55c  899ea4000000           -mov dword ptr [esi + 0xa4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */) = cpu.ebx;
    // 0041c562  895e58                 -mov dword ptr [esi + 0x58], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.ebx;
    // 0041c565  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041c568  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041c56b  8d7e6c                 -lea edi, [esi + 0x6c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 0041c56e  89466c                 -mov dword ptr [esi + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0041c571  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c574  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041c577  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041c57a  8dbe8c000000           -lea edi, [esi + 0x8c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0041c580  89868c000000           -mov dword ptr [esi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0041c586  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0041c58d  3bc3                   +cmp eax, ebx
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
    // 0041c58f  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c592  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041c595  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041c598  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c599  740e                   -je 0x41c5a9
    if (cpu.flags.zf)
    {
        goto L_0x0041c5a9;
    }
    // 0041c59b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c59c  e86f81feff             -call 0x404710
    cpu.esp -= 4;
    sub_404710(app, cpu);
    // 0041c5a1  83c404                 +add esp, 4
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
    // 0041c5a4  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0041c5a7  eb03                   -jmp 0x41c5ac
    goto L_0x0041c5ac;
L_0x0041c5a9:
    // 0041c5a9  895e4c                 -mov dword ptr [esi + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.ebx;
L_0x0041c5ac:
    // 0041c5ac  8b842490000000         -mov eax, dword ptr [esp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0041c5b3  3bc3                   +cmp eax, ebx
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
    // 0041c5b5  7417                   -je 0x41c5ce
    if (cpu.flags.zf)
    {
        goto L_0x0041c5ce;
    }
    // 0041c5b7  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c5b9  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0041c5bc  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041c5bf  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0041c5c2  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041c5c5  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0041c5c8  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041c5cb  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0041c5ce:
    // 0041c5ce  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0041c5d5  3bc3                   +cmp eax, ebx
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
    // 0041c5d7  7417                   -je 0x41c5f0
    if (cpu.flags.zf)
    {
        goto L_0x0041c5f0;
    }
    // 0041c5d9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c5db  894e5c                 -mov dword ptr [esi + 0x5c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = cpu.ecx;
    // 0041c5de  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041c5e1  895660                 -mov dword ptr [esi + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0041c5e4  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041c5e7  894e64                 -mov dword ptr [esi + 0x64], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.ecx;
    // 0041c5ea  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041c5ed  895668                 -mov dword ptr [esi + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = cpu.edx;
L_0x0041c5f0:
    // 0041c5f0  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0041c5f7  3bc3                   +cmp eax, ebx
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
    // 0041c5f9  7417                   -je 0x41c612
    if (cpu.flags.zf)
    {
        goto L_0x0041c612;
    }
    // 0041c5fb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c5fd  894e6c                 -mov dword ptr [esi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 0041c600  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041c603  895670                 -mov dword ptr [esi + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 0041c606  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041c609  894e74                 -mov dword ptr [esi + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 0041c60c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041c60f  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
L_0x0041c612:
    // 0041c612  8b8424a0000000         -mov eax, dword ptr [esp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0041c619  3bc3                   +cmp eax, ebx
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
    // 0041c61b  7420                   -je 0x41c63d
    if (cpu.flags.zf)
    {
        goto L_0x0041c63d;
    }
    // 0041c61d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c61f  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 0041c622  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041c625  899680000000           -mov dword ptr [esi + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 0041c62b  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041c62e  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0041c634  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041c637  899688000000           -mov dword ptr [esi + 0x88], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edx;
L_0x0041c63d:
    // 0041c63d  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0041c644  3bc3                   +cmp eax, ebx
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
    // 0041c646  7423                   -je 0x41c66b
    if (cpu.flags.zf)
    {
        goto L_0x0041c66b;
    }
    // 0041c648  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c64a  898e8c000000           -mov dword ptr [esi + 0x8c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.ecx;
    // 0041c650  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041c653  899690000000           -mov dword ptr [esi + 0x90], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 0041c659  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041c65c  898e94000000           -mov dword ptr [esi + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 0041c662  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041c665  899698000000           -mov dword ptr [esi + 0x98], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */) = cpu.edx;
L_0x0041c66b:
    // 0041c66b  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0041c66f  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041c671  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c672  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c673  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0041c67a  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0041c67d  c22000                 -ret 0x20
    cpu.esp += 4+32 /*0x20*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41c680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c680  8a819c000000           -mov al, byte ptr [ecx + 0x9c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 0041c686  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c689  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041c68b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c68c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c68d  747f                   -je 0x41c70e
    if (cpu.flags.zf)
    {
        goto L_0x0041c70e;
    }
    // 0041c68f  8b8184000000           -mov eax, dword ptr [ecx + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0041c695  8b717c                 -mov esi, dword ptr [ecx + 0x7c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 0041c698  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041c69a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c69c  7e70                   -jle 0x41c70e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c70e;
    }
    // 0041c69e  8b9188000000           -mov edx, dword ptr [ecx + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */);
    // 0041c6a4  8bb980000000           -mov edi, dword ptr [ecx + 0x80]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0041c6aa  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0041c6ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041c6ae  7e5e                   -jle 0x41c70e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c70e;
    }
    // 0041c6b0  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0041c6b3  8b7914                 -mov edi, dword ptr [ecx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0041c6b6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041c6b8  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 0041c6bd  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0041c6bf  03d7                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0041c6c1  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c6c4  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0041c6c8  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0041c6cc  8b517c                 -mov edx, dword ptr [ecx + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 0041c6cf  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0041c6d1  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0041c6d5  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0041c6d9  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0041c6db  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0041c6e1  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c6e4  8b9184000000           -mov edx, dword ptr [ecx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0041c6ea  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041c6ed  8b9188000000           -mov edx, dword ptr [ecx + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */);
    // 0041c6f3  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041c6f6  8b414c                 -mov eax, dword ptr [ecx + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0041c6f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c6fa  8d5158                 -lea edx, [ecx + 0x58]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0041c6fd  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041c701  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c702  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c703  e898faffff             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
    // 0041c708  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c709  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c70a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c70d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c70e:
    // 0041c70e  8b5164                 -mov edx, dword ptr [ecx + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    // 0041c711  8b715c                 -mov esi, dword ptr [ecx + 0x5c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 0041c714  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041c716  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041c718  7e3f                   -jle 0x41c759
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c759;
    }
    // 0041c71a  8b4168                 -mov eax, dword ptr [ecx + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 0041c71d  8b7160                 -mov esi, dword ptr [ecx + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */);
    // 0041c720  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041c722  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c724  7e33                   -jle 0x41c759
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c759;
    }
    // 0041c726  8b415c                 -mov eax, dword ptr [ecx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 0041c729  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041c72b  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 0041c730  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c733  8bd4                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0041c735  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0041c737  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041c739  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041c73c  8b4164                 -mov eax, dword ptr [ecx + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    // 0041c73f  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041c742  8b4168                 -mov eax, dword ptr [ecx + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 0041c745  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041c748  8b514c                 -mov edx, dword ptr [ecx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0041c74b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c74c  8d4158                 -lea eax, [ecx + 0x58]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0041c74f  8d5110                 -lea edx, [ecx + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0041c752  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c753  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c754  e847faffff             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
L_0x0041c759:
    // 0041c759  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c75a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c75b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c75e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41c760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c760  8a819c000000           -mov al, byte ptr [ecx + 0x9c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 0041c766  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c769  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041c76b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c76c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c76d  0f8485000000           -je 0x41c7f8
    if (cpu.flags.zf)
    {
        goto L_0x0041c7f8;
    }
    // 0041c773  8b8194000000           -mov eax, dword ptr [ecx + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */);
    // 0041c779  8bb18c000000           -mov esi, dword ptr [ecx + 0x8c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0041c77f  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041c781  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c783  7e73                   -jle 0x41c7f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c7f8;
    }
    // 0041c785  8b9198000000           -mov edx, dword ptr [ecx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 0041c78b  8bb990000000           -mov edi, dword ptr [ecx + 0x90]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */);
    // 0041c791  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0041c793  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041c795  7e61                   -jle 0x41c7f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c7f8;
    }
    // 0041c797  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0041c79a  8b7914                 -mov edi, dword ptr [ecx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0041c79d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041c79f  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 0041c7a4  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0041c7a6  03d7                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0041c7a8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c7ab  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0041c7af  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0041c7b3  8b918c000000           -mov edx, dword ptr [ecx + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0041c7b9  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0041c7bb  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0041c7bf  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0041c7c3  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0041c7c5  8b9190000000           -mov edx, dword ptr [ecx + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */);
    // 0041c7cb  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c7ce  8b9194000000           -mov edx, dword ptr [ecx + 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */);
    // 0041c7d4  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041c7d7  8b9198000000           -mov edx, dword ptr [ecx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 0041c7dd  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041c7e0  8b414c                 -mov eax, dword ptr [ecx + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0041c7e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c7e4  8d5158                 -lea edx, [ecx + 0x58]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0041c7e7  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041c7eb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c7ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c7ed  e8aef9ffff             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
    // 0041c7f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c7f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c7f4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c7f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c7f8:
    // 0041c7f8  8b4174                 -mov eax, dword ptr [ecx + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */);
    // 0041c7fb  8b716c                 -mov esi, dword ptr [ecx + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */);
    // 0041c7fe  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041c800  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c802  7e61                   -jle 0x41c865
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c865;
    }
    // 0041c804  8b5178                 -mov edx, dword ptr [ecx + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0041c807  8b7970                 -mov edi, dword ptr [ecx + 0x70]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 0041c80a  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0041c80c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041c80e  7e55                   -jle 0x41c865
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c865;
    }
    // 0041c810  8b7914                 -mov edi, dword ptr [ecx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0041c813  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0041c816  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041c818  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 0041c81d  03d7                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0041c81f  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0041c821  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c824  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0041c828  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0041c82c  8b416c                 -mov eax, dword ptr [ecx + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */);
    // 0041c82f  8bd4                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0041c831  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0041c835  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0041c839  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0041c83b  8b4170                 -mov eax, dword ptr [ecx + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 0041c83e  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041c841  8b4174                 -mov eax, dword ptr [ecx + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */);
    // 0041c844  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041c847  8b4178                 -mov eax, dword ptr [ecx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0041c84a  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041c84d  8b514c                 -mov edx, dword ptr [ecx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0041c850  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c851  8d4158                 -lea eax, [ecx + 0x58]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0041c854  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041c858  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c859  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c85a  e841f9ffff             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
    // 0041c85f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c860  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c861  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c864  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c865:
    // 0041c865  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041c867  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c869  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c86a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c86b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c86e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41c870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c870  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0041c872  68f8f14200             -push 0x42f1f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4387320 /*0x42f1f8*/;
    cpu.esp -= 4;
    // 0041c877  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0041c87d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c87e  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0041c885  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0041c888  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041c889  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c88a  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041c88c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c88e  8b842488000000         -mov eax, dword ptr [esp + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0041c895  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c896  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0041c899  895e08                 -mov dword ptr [esi + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0041c89c  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041c89f  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0041c8a2  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0041c8a5  895e14                 -mov dword ptr [esi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0041c8a8  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0041c8ab  895e34                 -mov dword ptr [esi + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0041c8ae  895e38                 -mov dword ptr [esi + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0041c8b1  895e3c                 -mov dword ptr [esi + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0041c8b4  895e40                 -mov dword ptr [esi + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0041c8b7  3bc3                   +cmp eax, ebx
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
    // 0041c8b9  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0041c8bd  c70684014300           -mov dword ptr [esi], 0x430184
    app->getMemory<x86::reg32>(cpu.esi) = 4391300 /*0x430184*/;
    // 0041c8c3  7409                   -je 0x41c8ce
    if (cpu.flags.zf)
    {
        goto L_0x0041c8ce;
    }
    // 0041c8c5  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0041c8c8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c8ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c8cb  ff5104                 -call dword ptr [ecx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0041c8ce:
    // 0041c8ce  8b842490000000         -mov eax, dword ptr [esp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0041c8d5  3bc3                   +cmp eax, ebx
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
    // 0041c8d7  742d                   -je 0x41c906
    if (cpu.flags.zf)
    {
        goto L_0x0041c906;
    }
    // 0041c8d9  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0041c8dc  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c8de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c8df  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c8e2  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041c8e5  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041c8e9  c74424106c000000       -mov dword ptr [esp + 0x10], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 108 /*0x6c*/;
    // 0041c8f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c8f2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c8f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c8f5  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c8f8  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041c8fc  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041c900  894650                 -mov dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0041c903  894e54                 -mov dword ptr [esi + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.ecx;
L_0x0041c906:
    // 0041c906  8d7e7c                 -lea edi, [esi + 0x7c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0041c909  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c90b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c90d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041c90f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0041c911  895e4c                 -mov dword ptr [esi + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0041c914  895e5c                 -mov dword ptr [esi + 0x5c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = cpu.ebx;
    // 0041c917  895e64                 -mov dword ptr [esi + 0x64], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.ebx;
    // 0041c91a  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c91d  895e60                 -mov dword ptr [esi + 0x60], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.ebx;
    // 0041c920  895e68                 -mov dword ptr [esi + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 0041c923  889e9c000000           -mov byte ptr [esi + 0x9c], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(156) /* 0x9c */) = cpu.bl;
    // 0041c929  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041c92c  899ea0000000           -mov dword ptr [esi + 0xa0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = cpu.ebx;
    // 0041c932  899ea4000000           -mov dword ptr [esi + 0xa4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */) = cpu.ebx;
    // 0041c938  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041c93b  8d7e6c                 -lea edi, [esi + 0x6c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 0041c93e  89466c                 -mov dword ptr [esi + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0041c941  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c944  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041c947  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041c94a  8dbe8c000000           -lea edi, [esi + 0x8c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0041c950  89868c000000           -mov dword ptr [esi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0041c956  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c959  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041c95c  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041c95f  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0041c966  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 0041c96d  3bc3                   +cmp eax, ebx
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
    // 0041c96f  c70600054300           -mov dword ptr [esi], 0x430500
    app->getMemory<x86::reg32>(cpu.esi) = 4392192 /*0x430500*/;
    // 0041c975  899ea8000000           -mov dword ptr [esi + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 0041c97b  c786ac0000000000803f   -mov dword ptr [esi + 0xac], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = 1065353216 /*0x3f800000*/;
    // 0041c985  899eb0000000           -mov dword ptr [esi + 0xb0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */) = cpu.ebx;
    // 0041c98b  c786d40000000ad7233c   -mov dword ptr [esi + 0xd4], 0x3c23d70a
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */) = 1008981770 /*0x3c23d70a*/;
    // 0041c995  899eb8000000           -mov dword ptr [esi + 0xb8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.ebx;
    // 0041c99b  899eb4000000           -mov dword ptr [esi + 0xb4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */) = cpu.ebx;
    // 0041c9a1  899ec0000000           -mov dword ptr [esi + 0xc0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.ebx;
    // 0041c9a7  899ebc000000           -mov dword ptr [esi + 0xbc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = cpu.ebx;
    // 0041c9ad  899ec4000000           -mov dword ptr [esi + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 0041c9b3  899ecc000000           -mov dword ptr [esi + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 0041c9b9  899ec8000000           -mov dword ptr [esi + 0xc8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = cpu.ebx;
    // 0041c9bf  899ed0000000           -mov dword ptr [esi + 0xd0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.ebx;
    // 0041c9c5  895e58                 -mov dword ptr [esi + 0x58], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.ebx;
    // 0041c9c8  740e                   -je 0x41c9d8
    if (cpu.flags.zf)
    {
        goto L_0x0041c9d8;
    }
    // 0041c9ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c9cb  e8407dfeff             -call 0x404710
    cpu.esp -= 4;
    sub_404710(app, cpu);
    // 0041c9d0  83c404                 +add esp, 4
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
    // 0041c9d3  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0041c9d6  eb03                   -jmp 0x41c9db
    goto L_0x0041c9db;
L_0x0041c9d8:
    // 0041c9d8  895e4c                 -mov dword ptr [esi + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.ebx;
L_0x0041c9db:
    // 0041c9db  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0041c9e2  3bc3                   +cmp eax, ebx
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
    // 0041c9e4  741a                   -je 0x41ca00
    if (cpu.flags.zf)
    {
        goto L_0x0041ca00;
    }
    // 0041c9e6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041c9e8  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0041c9eb  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0041c9ee  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041c9f1  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041c9f4  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041c9f7  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041c9fa  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041c9fd  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0041ca00:
    // 0041ca00  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0041ca07  3bc3                   +cmp eax, ebx
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
    // 0041ca09  7417                   -je 0x41ca22
    if (cpu.flags.zf)
    {
        goto L_0x0041ca22;
    }
    // 0041ca0b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041ca0d  894e5c                 -mov dword ptr [esi + 0x5c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = cpu.ecx;
    // 0041ca10  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041ca13  895660                 -mov dword ptr [esi + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0041ca16  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041ca19  894e64                 -mov dword ptr [esi + 0x64], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.ecx;
    // 0041ca1c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041ca1f  895668                 -mov dword ptr [esi + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = cpu.edx;
L_0x0041ca22:
    // 0041ca22  8b8424a0000000         -mov eax, dword ptr [esp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0041ca29  3bc3                   +cmp eax, ebx
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
    // 0041ca2b  7423                   -je 0x41ca50
    if (cpu.flags.zf)
    {
        goto L_0x0041ca50;
    }
    // 0041ca2d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041ca2f  898ec4000000           -mov dword ptr [esi + 0xc4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.ecx;
    // 0041ca35  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041ca38  8996c8000000           -mov dword ptr [esi + 0xc8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = cpu.edx;
    // 0041ca3e  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041ca41  898ecc000000           -mov dword ptr [esi + 0xcc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ecx;
    // 0041ca47  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041ca4a  8996d0000000           -mov dword ptr [esi + 0xd0], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.edx;
L_0x0041ca50:
    // 0041ca50  8b8424ac000000         -mov eax, dword ptr [esp + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0041ca57  3bc3                   +cmp eax, ebx
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
    // 0041ca59  7417                   -je 0x41ca72
    if (cpu.flags.zf)
    {
        goto L_0x0041ca72;
    }
    // 0041ca5b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041ca5d  894e6c                 -mov dword ptr [esi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 0041ca60  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041ca63  895670                 -mov dword ptr [esi + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 0041ca66  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041ca69  894e74                 -mov dword ptr [esi + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 0041ca6c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041ca6f  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
L_0x0041ca72:
    // 0041ca72  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0041ca79  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0041ca7c  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0041ca7f  3bd3                   +cmp edx, ebx
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
    // 0041ca81  8986b4000000           -mov dword ptr [esi + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0041ca87  8986bc000000           -mov dword ptr [esi + 0xbc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = cpu.eax;
    // 0041ca8d  898eb8000000           -mov dword ptr [esi + 0xb8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.ecx;
    // 0041ca93  898ec0000000           -mov dword ptr [esi + 0xc0], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.ecx;
    // 0041ca99  7415                   -je 0x41cab0
    if (cpu.flags.zf)
    {
        goto L_0x0041cab0;
    }
    // 0041ca9b  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0041ca9d  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041ca9f  89beb4000000           -mov dword ptr [esi + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0041caa5  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0041caa8  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041caaa  8996b8000000           -mov dword ptr [esi + 0xb8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.edx;
L_0x0041cab0:
    // 0041cab0  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0041cab7  3bd3                   +cmp edx, ebx
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
    // 0041cab9  7413                   -je 0x41cace
    if (cpu.flags.zf)
    {
        goto L_0x0041cace;
    }
    // 0041cabb  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0041cabd  8986bc000000           -mov dword ptr [esi + 0xbc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = cpu.eax;
    // 0041cac3  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0041cac6  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041cac8  8986c0000000           -mov dword ptr [esi + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.eax;
L_0x0041cace:
    // 0041cace  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0041cad2  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041cad4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cad5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cad6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cad7  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0041cade  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0041cae1  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41caf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041caf0  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041caf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041caf4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041caf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041caf7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041caf9  ff5038                 -call dword ptr [eax + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cafc  8b86b4000000           -mov eax, dword ptr [esi + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0041cb02  8b8ebc000000           -mov ecx, dword ptr [esi + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041cb08  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041cb0a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041cb0e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041cb12  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041cb16  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0041cb18  da44240c               -fiadd dword ptr [esp + 0xc]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0041cb1c  e803900000             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
    // 0041cb21  8b96c0000000           -mov edx, dword ptr [esi + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 0041cb27  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041cb29  8b86b8000000           -mov eax, dword ptr [esi + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 0041cb2f  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041cb31  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041cb35  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041cb39  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0041cb3d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0041cb3f  da442408               -fiadd dword ptr [esp + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0041cb43  e8dc8f0000             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
    // 0041cb48  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041cb4e  8b96c4000000           -mov edx, dword ptr [esi + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041cb54  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041cb56  8b96d0000000           -mov edx, dword ptr [esi + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041cb5c  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0041cb5e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041cb60  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041cb64  8b8ec8000000           -mov ecx, dword ptr [esi + 0xc8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */);
    // 0041cb6a  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 0041cb6f  2bd1                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041cb71  8b8ec4000000           -mov ecx, dword ptr [esi + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041cb77  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041cb7a  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0041cb7e  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041cb80  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0041cb82  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041cb86  8b96c8000000           -mov edx, dword ptr [esi + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */);
    // 0041cb8c  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0041cb90  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041cb92  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041cb98  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cb9a  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041cb9d  8b96d0000000           -mov edx, dword ptr [esi + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041cba3  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041cba6  8d4e58                 -lea ecx, [esi + 0x58]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 0041cba9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041cbac  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 0041cbaf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cbb0  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041cbb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cbb5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041cbb6  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041cbb8  e8e3f5ffff             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
    // 0041cbbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cbbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cbbf  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041cbc2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41cbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cbd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cbd1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041cbd3  8a86d8000000           -mov al, byte ptr [esi + 0xd8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0041cbd9  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041cbdb  7505                   -jne 0x41cbe2
    if (!cpu.flags.zf)
    {
        goto L_0x0041cbe2;
    }
    // 0041cbdd  e89efaffff             -call 0x41c680
    cpu.esp -= 4;
    sub_41c680(app, cpu);
L_0x0041cbe2:
    // 0041cbe2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041cbe4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041cbe6  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cbe9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cbea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41cbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cbf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cbf1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041cbf3  8a86d8000000           -mov al, byte ptr [esi + 0xd8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0041cbf9  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041cbfb  7505                   -jne 0x41cc02
    if (!cpu.flags.zf)
    {
        goto L_0x0041cc02;
    }
    // 0041cbfd  e85efbffff             -call 0x41c760
    cpu.esp -= 4;
    sub_41c760(app, cpu);
L_0x0041cc02:
    // 0041cc02  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041cc04  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041cc06  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cc09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cc0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41cc10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cc10  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041cc13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cc14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041cc15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cc16  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041cc18  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041cc19  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041cc1b  ff5038                 -call dword ptr [eax + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cc1e  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041cc24  8b8eb4000000           -mov ecx, dword ptr [esi + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0041cc2a  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041cc2e  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041cc30  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041cc34  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0041cc38  db44241c               -fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 0041cc3c  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cc40  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0041cc44  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cc48  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0041cc4c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0041cc4e  d8442410               -fadd dword ptr [esp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0041cc52  e8cd8e0000             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
    // 0041cc57  8b8eb8000000           -mov ecx, dword ptr [esi + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 0041cc5d  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0041cc5f  8b86c0000000           -mov eax, dword ptr [esi + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 0041cc65  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0041cc69  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0041cc6d  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041cc6f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041cc73  db44241c               -fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 0041cc77  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cc7b  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0041cc7f  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cc83  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0041cc87  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0041cc89  d8442414               -fadd dword ptr [esp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0041cc8d  e8928e0000             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
    // 0041cc92  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cc94  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0041cc98  8bbecc000000           -mov edi, dword ptr [esi + 0xcc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041cc9e  8b9ec4000000           -mov ebx, dword ptr [esi + 0xc4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041cca4  8b8ec8000000           -mov ecx, dword ptr [esi + 0xc8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */);
    // 0041ccaa  2bfb                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041ccac  d8642410               -fsub dword ptr [esp + 0x10]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0041ccb0  db442424               -fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 0041ccb4  8b9ed0000000           -mov ebx, dword ptr [esi + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041ccba  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0041ccbe  2bd9                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ccc0  03fd                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0041ccc2  d8642414               -fsub dword ptr [esp + 0x14]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0041ccc6  03d8                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041ccc8  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0041ccca  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0041cccc  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0041ccce  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0041ccd0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041ccd2  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0041ccd4  dc0540054300           -fadd qword ptr [0x430540]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4392256) /* 0x430540 */));
    // 0041ccda  db442438               -fild dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */))));
    // 0041ccde  d8642414               -fsub dword ptr [esp + 0x14]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0041cce2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0041cce4  db442434               -fild dword ptr [esp + 0x34]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 0041cce8  d8642410               -fsub dword ptr [esp + 0x10]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0041ccec  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 0041ccee  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041ccf0  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 0041ccf2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0041ccf4  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041ccf6  dddb                   -fstp st(3)
    cpu.fpu.st(3) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ccf8  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ccfa  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ccfc  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0041cd00  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0041cd02  d8442410               -fadd dword ptr [esp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0041cd06  e8198e0000             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
    // 0041cd0b  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0041cd0f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041cd11  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0041cd13  d8442414               -fadd dword ptr [esp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0041cd17  e8088e0000             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
    // 0041cd1c  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0041cd20  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041cd22  7404                   -je 0x41cd28
    if (cpu.flags.zf)
    {
        goto L_0x0041cd28;
    }
    // 0041cd24  d919                   +fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cd26  eb02                   -jmp 0x41cd2a
    goto L_0x0041cd2a;
L_0x0041cd28:
    // 0041cd28  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041cd2a:
    // 0041cd2a  3bee                   +cmp ebp, esi
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
    // 0041cd2c  7f1a                   -jg 0x41cd48
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041cd48;
    }
    // 0041cd2e  3bfe                   +cmp edi, esi
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
    // 0041cd30  7e16                   -jle 0x41cd48
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041cd48;
    }
    // 0041cd32  3944242c               +cmp dword ptr [esp + 0x2c], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041cd36  7f10                   -jg 0x41cd48
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041cd48;
    }
    // 0041cd38  3bd8                   +cmp ebx, eax
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
    // 0041cd3a  7e0c                   -jle 0x41cd48
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041cd48;
    }
    // 0041cd3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cd3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cd3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cd3f  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0041cd41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cd42  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041cd45  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0041cd48:
    // 0041cd48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cd49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cd4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cd4b  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0041cd4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cd4e  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041cd51  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41cd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cd60  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041cd63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cd64  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041cd66  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041cd68  ff5038                 -call dword ptr [eax + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cd6b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041cd6f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041cd73  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cd77  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041cd7b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cd7c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041cd7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cd7e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041cd80  e88bfeffff             -call 0x41cc10
    cpu.esp -= 4;
    sub_41cc10(app, cpu);
    // 0041cd85  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041cd87  7542                   -jne 0x41cdcb
    if (!cpu.flags.zf)
    {
        goto L_0x0041cdcb;
    }
    // 0041cd89  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0041cd8d  d85c2404               -fcomp dword ptr [esp + 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    cpu.fpu.pop();
    // 0041cd91  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041cd93  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0041cd96  741e                   -je 0x41cdb6
    if (cpu.flags.zf)
    {
        goto L_0x0041cdb6;
    }
    // 0041cd98  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041cd9c  d82548054300           -fsub dword ptr [0x430548]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4392264) /* 0x430548 */));
    // 0041cda2  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041cda4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cda5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041cda7  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cdaa  ff523c                 -call dword ptr [edx + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cdad  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041cdaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cdb0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041cdb3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041cdb6:
    // 0041cdb6  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041cdba  d80548054300           -fadd dword ptr [0x430548]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4392264) /* 0x430548 */));
    // 0041cdc0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041cdc2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cdc3  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041cdc5  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cdc8  ff503c                 -call dword ptr [eax + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0041cdcb:
    // 0041cdcb  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041cdcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cdce  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041cdd1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41cde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cde0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cde1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cde2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cde3  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041cde5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041cde6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041cde8  ff5038                 -call dword ptr [eax + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cdeb  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041cdef  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041cdf3  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cdf5  d986ac000000           -fld dword ptr [esi + 0xac]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(172) /* 0xac */)));
    // 0041cdfb  d8a6a8000000           -fsub dword ptr [esi + 0xa8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(168) /* 0xa8 */));
    // 0041ce01  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041ce03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ce04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ce05  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041ce07  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ce0b  e800feffff             -call 0x41cc10
    cpu.esp -= 4;
    sub_41cc10(app, cpu);
    // 0041ce10  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041ce12  7476                   -je 0x41ce8a
    if (cpu.flags.zf)
    {
        goto L_0x0041ce8a;
    }
    // 0041ce14  8b8ebc000000           -mov ecx, dword ptr [esi + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041ce1a  8b96b4000000           -mov edx, dword ptr [esi + 0xb4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0041ce20  8b86b8000000           -mov eax, dword ptr [esi + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 0041ce26  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ce28  8b96c0000000           -mov edx, dword ptr [esi + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 0041ce2e  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0041ce32  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0041ce36  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ce38  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041ce3c  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0041ce40  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041ce44  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0041ce48  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041ce4a  2bcf                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0041ce4c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041ce50  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0041ce52  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0041ce54  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0041ce56  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0041ce58  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041ce5a  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0041ce5c  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0041ce60  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0041ce64  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0041ce66  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0041ce6a  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0041ce6c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041ce6e  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 0041ce70  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0041ce72  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041ce74  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0041ce78  d886b0000000           -fadd dword ptr [esi + 0xb0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(176) /* 0xb0 */));
    // 0041ce7e  d99eb0000000           -fstp dword ptr [esi + 0xb0]
    app->getMemory<float>(cpu.esi + x86::reg32(176) /* 0xb0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ce84  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ce86  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ce88  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041ce8a:
    // 0041ce8a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041ce8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ce8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ce8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ce8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ce90  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41cea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cea0  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0041cea2  681bf24200             -push 0x42f21b
    app->getMemory<x86::reg32>(cpu.esp-4) = 4387355 /*0x42f21b*/;
    cpu.esp -= 4;
    // 0041cea7  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0041cead  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ceae  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0041ceb5  81ecdc000000           -sub esp, 0xdc
    (cpu.esp) -= x86::reg32(x86::sreg32(220 /*0xdc*/));
    // 0041cebb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cebc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cebd  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041cebf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041cec0  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0041cec4  e897060000             -call 0x41d560
    cpu.esp -= 4;
    sub_41d560(app, cpu);
    // 0041cec9  8b8424f8000000         -mov eax, dword ptr [esp + 0xf8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 0041ced0  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041ced2  895e34                 -mov dword ptr [esi + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0041ced5  895e38                 -mov dword ptr [esi + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0041ced8  895e3c                 -mov dword ptr [esi + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0041cedb  895e40                 -mov dword ptr [esi + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0041cede  3bc3                   +cmp eax, ebx
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
    // 0041cee0  c70684014300           -mov dword ptr [esi], 0x430184
    app->getMemory<x86::reg32>(cpu.esi) = 4391300 /*0x430184*/;
    // 0041cee6  7409                   -je 0x41cef1
    if (cpu.flags.zf)
    {
        goto L_0x0041cef1;
    }
    // 0041cee8  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0041ceeb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041ceed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ceee  ff5104                 -call dword ptr [ecx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0041cef1:
    // 0041cef1  8b8424fc000000         -mov eax, dword ptr [esp + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0041cef8  3bc3                   +cmp eax, ebx
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
    // 0041cefa  742d                   -je 0x41cf29
    if (cpu.flags.zf)
    {
        goto L_0x0041cf29;
    }
    // 0041cefc  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0041ceff  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041cf01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cf02  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cf05  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041cf08  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041cf0c  c74424106c000000       -mov dword ptr [esp + 0x10], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 108 /*0x6c*/;
    // 0041cf14  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041cf15  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041cf17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cf18  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cf1b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041cf1f  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041cf23  894650                 -mov dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0041cf26  894e54                 -mov dword ptr [esi + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.ecx;
L_0x0041cf29:
    // 0041cf29  8d7e7c                 -lea edi, [esi + 0x7c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0041cf2c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041cf2e  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041cf30  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041cf32  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0041cf34  895e4c                 -mov dword ptr [esi + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0041cf37  895e5c                 -mov dword ptr [esi + 0x5c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = cpu.ebx;
    // 0041cf3a  895e64                 -mov dword ptr [esi + 0x64], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.ebx;
    // 0041cf3d  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041cf40  895e60                 -mov dword ptr [esi + 0x60], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.ebx;
    // 0041cf43  895e68                 -mov dword ptr [esi + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 0041cf46  895e58                 -mov dword ptr [esi + 0x58], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.ebx;
    // 0041cf49  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041cf4c  889e9c000000           -mov byte ptr [esi + 0x9c], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(156) /* 0x9c */) = cpu.bl;
    // 0041cf52  899ea0000000           -mov dword ptr [esi + 0xa0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = cpu.ebx;
    // 0041cf58  899ea4000000           -mov dword ptr [esi + 0xa4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */) = cpu.ebx;
    // 0041cf5e  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041cf61  8d7e6c                 -lea edi, [esi + 0x6c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 0041cf64  89466c                 -mov dword ptr [esi + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0041cf67  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041cf6a  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041cf6d  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041cf70  8dbe8c000000           -lea edi, [esi + 0x8c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0041cf76  89868c000000           -mov dword ptr [esi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0041cf7c  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041cf7f  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041cf82  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0041cf85  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0041cf8c  899c24f0000000         -mov dword ptr [esp + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
    // 0041cf93  3bc3                   +cmp eax, ebx
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
    // 0041cf95  c70644044300           -mov dword ptr [esi], 0x430444
    app->getMemory<x86::reg32>(cpu.esi) = 4392004 /*0x430444*/;
    // 0041cf9b  899ed0000000           -mov dword ptr [esi + 0xd0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.ebx;
    // 0041cfa1  899ecc000000           -mov dword ptr [esi + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 0041cfa7  899ec8000000           -mov dword ptr [esi + 0xc8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = cpu.ebx;
    // 0041cfad  899ec4000000           -mov dword ptr [esi + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 0041cfb3  899ec0000000           -mov dword ptr [esi + 0xc0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.ebx;
    // 0041cfb9  899ebc000000           -mov dword ptr [esi + 0xbc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = cpu.ebx;
    // 0041cfbf  899eb8000000           -mov dword ptr [esi + 0xb8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.ebx;
    // 0041cfc5  899eb4000000           -mov dword ptr [esi + 0xb4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */) = cpu.ebx;
    // 0041cfcb  899ea8000000           -mov dword ptr [esi + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 0041cfd1  743f                   -je 0x41d012
    if (cpu.flags.zf)
    {
        goto L_0x0041d012;
    }
    // 0041cfd3  8986a8000000           -mov dword ptr [esi + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0041cfd9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041cfdb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cfdc  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cfdf  8b86a8000000           -mov eax, dword ptr [esi + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0041cfe5  8d54247c               -lea edx, [esp + 0x7c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0041cfe9  c744247c6c000000       -mov dword ptr [esp + 0x7c], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = 108 /*0x6c*/;
    // 0041cff1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041cff2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041cff4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cff5  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cff8  8b842488000000         -mov eax, dword ptr [esp + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0041cfff  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0041d006  8986ac000000           -mov dword ptr [esi + 0xac], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0041d00c  898eb0000000           -mov dword ptr [esi + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
L_0x0041d012:
    // 0041d012  8b842408010000         -mov eax, dword ptr [esp + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0041d019  899ed4000000           -mov dword ptr [esi + 0xd4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */) = cpu.ebx;
    // 0041d01f  3bc3                   +cmp eax, ebx
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
    // 0041d021  899eb0000000           -mov dword ptr [esi + 0xb0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */) = cpu.ebx;
    // 0041d027  899eac000000           -mov dword ptr [esi + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 0041d02d  899eec000000           -mov dword ptr [esi + 0xec], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(236) /* 0xec */) = cpu.ebx;
    // 0041d033  899ee4000000           -mov dword ptr [esi + 0xe4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(228) /* 0xe4 */) = cpu.ebx;
    // 0041d039  899ee8000000           -mov dword ptr [esi + 0xe8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(232) /* 0xe8 */) = cpu.ebx;
    // 0041d03f  899ee0000000           -mov dword ptr [esi + 0xe0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(224) /* 0xe0 */) = cpu.ebx;
    // 0041d045  895e58                 -mov dword ptr [esi + 0x58], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.ebx;
    // 0041d048  740e                   -je 0x41d058
    if (cpu.flags.zf)
    {
        goto L_0x0041d058;
    }
    // 0041d04a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d04b  e8c076feff             -call 0x404710
    cpu.esp -= 4;
    sub_404710(app, cpu);
    // 0041d050  83c404                 +add esp, 4
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
    // 0041d053  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0041d056  eb03                   -jmp 0x41d05b
    goto L_0x0041d05b;
L_0x0041d058:
    // 0041d058  895e4c                 -mov dword ptr [esi + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.ebx;
L_0x0041d05b:
    // 0041d05b  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0041d062  3bc3                   +cmp eax, ebx
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
    // 0041d064  741a                   -je 0x41d080
    if (cpu.flags.zf)
    {
        goto L_0x0041d080;
    }
    // 0041d066  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041d068  8d5610                 -lea edx, [esi + 0x10]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0041d06b  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041d06e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041d071  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041d074  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041d077  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041d07a  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041d07d  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0041d080:
    // 0041d080  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0041d087  3bc3                   +cmp eax, ebx
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
    // 0041d089  7417                   -je 0x41d0a2
    if (cpu.flags.zf)
    {
        goto L_0x0041d0a2;
    }
    // 0041d08b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041d08d  894e5c                 -mov dword ptr [esi + 0x5c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = cpu.ecx;
    // 0041d090  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041d093  895660                 -mov dword ptr [esi + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0041d096  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041d099  894e64                 -mov dword ptr [esi + 0x64], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.ecx;
    // 0041d09c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041d09f  895668                 -mov dword ptr [esi + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = cpu.edx;
L_0x0041d0a2:
    // 0041d0a2  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 0041d0a9  3bc3                   +cmp eax, ebx
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
    // 0041d0ab  7417                   -je 0x41d0c4
    if (cpu.flags.zf)
    {
        goto L_0x0041d0c4;
    }
    // 0041d0ad  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041d0af  894e6c                 -mov dword ptr [esi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 0041d0b2  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041d0b5  895670                 -mov dword ptr [esi + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 0041d0b8  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041d0bb  894e74                 -mov dword ptr [esi + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 0041d0be  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041d0c1  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
L_0x0041d0c4:
    // 0041d0c4  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0041d0cb  8b8c2418010000         -mov ecx, dword ptr [esp + 0x118]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 0041d0d2  8b942420010000         -mov edx, dword ptr [esp + 0x120]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0041d0d9  8986b4000000           -mov dword ptr [esi + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0041d0df  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 0041d0e6  898eb8000000           -mov dword ptr [esi + 0xb8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.ecx;
    // 0041d0ec  8b8c2424010000         -mov ecx, dword ptr [esp + 0x124]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0041d0f3  8996bc000000           -mov dword ptr [esi + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 0041d0f9  8b942428010000         -mov edx, dword ptr [esp + 0x128]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 0041d100  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0041d103  898ecc000000           -mov dword ptr [esi + 0xcc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ecx;
    // 0041d109  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d10a  8986c8000000           -mov dword ptr [esi + 0xc8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = cpu.eax;
    // 0041d110  8996d0000000           -mov dword ptr [esi + 0xd0], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.edx;
    // 0041d116  e85a7d0000             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0041d11b  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0041d11d  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041d11f  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0041d121  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041d123  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0041d126  89bed4000000           -mov dword ptr [esi + 0xd4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */) = cpu.edi;
    // 0041d12c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041d12f  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0041d131  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041d133  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0041d136  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 0041d138  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 0041d13f  8b8c2434010000         -mov ecx, dword ptr [esp + 0x134]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 0041d146  8986d8000000           -mov dword ptr [esi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 0041d14c  898edc000000           -mov dword ptr [esi + 0xdc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */) = cpu.ecx;
    // 0041d152  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 0041d159  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041d15b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d15c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d15d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d15e  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0041d165  81c4e8000000           -add esp, 0xe8
    (cpu.esp) += x86::reg32(x86::sreg32(232 /*0xe8*/));
    // 0041d16b  c24000                 -ret 0x40
    cpu.esp += 4+64 /*0x40*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41d170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d170  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0041d173  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d174  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041d175  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d176  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d178  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d179  8b86e8000000           -mov eax, dword ptr [esi + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(232) /* 0xe8 */);
    // 0041d17f  8b96e0000000           -mov edx, dword ptr [esi + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(224) /* 0xe0 */);
    // 0041d185  8d9ee0000000           -lea ebx, [esi + 0xe0]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(224) /* 0xe0 */);
    // 0041d18b  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d18d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d18f  7e44                   -jle 0x41d1d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d1d5;
    }
    // 0041d191  8b8eec000000           -mov ecx, dword ptr [esi + 0xec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(236) /* 0xec */);
    // 0041d197  8b96e4000000           -mov edx, dword ptr [esi + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(228) /* 0xe4 */);
    // 0041d19d  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d19f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041d1a1  7e32                   -jle 0x41d1d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d1d5;
    }
    // 0041d1a3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041d1a5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041d1a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d1a8  6800800001             -push 0x1008000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16809984 /*0x1008000*/;
    cpu.esp -= 4;
    // 0041d1ad  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041d1b0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0041d1b5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0041d1b7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041d1b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d1ba  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0041d1bd  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041d1c0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041d1c2  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041d1c5  8d96a8000000           -lea edx, [esi + 0xa8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0041d1cb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d1cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d1cd  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0041d1d0  e8cbefffff             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
L_0x0041d1d5:
    // 0041d1d5  8baecc000000           -mov ebp, dword ptr [esi + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041d1db  8bbed0000000           -mov edi, dword ptr [esi + 0xd0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041d1e1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041d1e3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041d1e5  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041d1e9  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0041d1ed  8b86c4000000           -mov eax, dword ptr [esi + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041d1f3  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0041d1f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d1f9  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0041d1fd  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0041d201  0f8e3c010000           -jle 0x41d343
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d343;
    }
L_0x0041d207:
    // 0041d207  3b8ec8000000           +cmp ecx, dword ptr [esi + 0xc8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d20d  0f8d30010000           -jge 0x41d343
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d343;
    }
    // 0041d213  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d217  8b96dc000000           -mov edx, dword ptr [esi + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */);
    // 0041d21d  3bc2                   +cmp eax, edx
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
    // 0041d21f  0f8d1e010000           -jge 0x41d343
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d343;
    }
    // 0041d225  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d229  8b86d8000000           -mov eax, dword ptr [esi + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0041d22f  3bd0                   +cmp edx, eax
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
    // 0041d231  7d42                   -jge 0x41d275
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d275;
    }
    // 0041d233  8b86d4000000           -mov eax, dword ptr [esi + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041d239  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d23b  8a1408                 -mov dl, byte ptr [eax + ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + cpu.ecx * 1);
    // 0041d23e  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041d240  83f80a                 +cmp eax, 0xa
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
    // 0041d243  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041d247  752f                   -jne 0x41d278
    if (!cpu.flags.zf)
    {
        goto L_0x0041d278;
    }
L_0x0041d249:
    // 0041d249  8b96b8000000           -mov edx, dword ptr [esi + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 0041d24f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d253  8baecc000000           -mov ebp, dword ptr [esi + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041d259  03fa                   +add edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041d25b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0041d25c  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0041d260  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0041d264  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0041d26c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041d270  e9bb000000             -jmp 0x41d330
    goto L_0x0041d330;
L_0x0041d275:
    // 0041d275  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041d276  ebd1                   -jmp 0x41d249
    goto L_0x0041d249;
L_0x0041d278:
    // 0041d278  83f820                 +cmp eax, 0x20
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
    // 0041d27b  0f849a000000           -je 0x41d31b
    if (cpu.flags.zf)
    {
        goto L_0x0041d31b;
    }
    // 0041d281  8baebc000000           -mov ebp, dword ptr [esi + 0xbc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041d287  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d289  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0041d28b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041d28f  8b9eb8000000           -mov ebx, dword ptr [esi + 0xb8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 0041d295  8bbeb4000000           -mov edi, dword ptr [esi + 0xb4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0041d29b  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041d29d  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d29f  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0041d2a1  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0041d2a4  8d140f                 -lea edx, [edi + ecx]
    cpu.edx = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 0041d2a7  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0041d2aa  8d2c03                 -lea ebp, [ebx + eax]
    cpu.ebp = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0041d2ad  896c2444               -mov dword ptr [esp + 0x44], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ebp;
    // 0041d2b1  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041d2b5  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0041d2b9  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041d2bd  896c242c               -mov dword ptr [esp + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 0041d2c1  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041d2c5  03fd                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0041d2c7  897c2430               -mov dword ptr [esp + 0x30], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edi;
    // 0041d2cb  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041d2cf  03df                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0041d2d1  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0041d2d5  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041d2d7  2bd9                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041d2d9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0041d2db  7e3a                   -jle 0x41d317
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d317;
    }
    // 0041d2dd  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0041d2e1  2bd8                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041d2e3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0041d2e5  7e30                   -jle 0x41d317
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d317;
    }
    // 0041d2e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d2e9  6800800001             -push 0x1008000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16809984 /*0x1008000*/;
    cpu.esp -= 4;
    // 0041d2ee  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041d2f1  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0041d2f3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d2f5  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 0041d2f7  8d8ea8000000           -lea ecx, [esi + 0xa8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0041d2fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d2fe  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041d300  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041d303  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0041d307  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041d30a  8d542448               -lea edx, [esp + 0x48]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0041d30e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d30f  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041d312  e889eeffff             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
L_0x0041d317:
    // 0041d317  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0041d31b:
    // 0041d31b  8b96b4000000           -mov edx, dword ptr [esi + 0xb4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0041d321  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d325  03ea                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041d327  40                     -inc eax
    (cpu.eax)++;
    // 0041d328  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0041d32c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0041d330:
    // 0041d330  8b86c4000000           -mov eax, dword ptr [esi + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041d336  41                     -inc ecx
    (cpu.ecx)++;
    // 0041d337  3bc8                   +cmp ecx, eax
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
    // 0041d339  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0041d33d  0f8cc4feffff           -jl 0x41d207
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d207;
    }
L_0x0041d343:
    // 0041d343  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d344  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d345  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d346  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d347  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0041d34a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41d350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d350  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d351  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d353  e828f3ffff             -call 0x41c680
    cpu.esp -= 4;
    sub_41c680(app, cpu);
    // 0041d358  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d35a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041d35c  e80ffeffff             -call 0x41d170
    cpu.esp -= 4;
    sub_41d170(app, cpu);
    // 0041d361  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d362  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d370  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d371  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d373  e8e8f3ffff             -call 0x41c760
    cpu.esp -= 4;
    sub_41c760(app, cpu);
    // 0041d378  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041d37a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041d37c  e8effdffff             -call 0x41d170
    cpu.esp -= 4;
    sub_41d170(app, cpu);
    // 0041d381  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d382  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d390  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041d394  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d395  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041d397  7c62                   -jl 0x41d3fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d3fb;
    }
    // 0041d399  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d39d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0041d39f  7c5a                   -jl 0x41d3fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d3fb;
    }
    // 0041d3a1  3b91d8000000           +cmp edx, dword ptr [ecx + 0xd8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d3a7  7d52                   -jge 0x41d3fb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d3fb;
    }
    // 0041d3a9  3b99dc000000           +cmp ebx, dword ptr [ecx + 0xdc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d3af  7d4a                   -jge 0x41d3fb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d3fb;
    }
    // 0041d3b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d3b2  8bb1b4000000           -mov esi, dword ptr [ecx + 0xb4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 0041d3b8  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041d3ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d3bb  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0041d3be  8b91cc000000           -mov edx, dword ptr [ecx + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 0041d3c4  8bb9b8000000           -mov edi, dword ptr [ecx + 0xb8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(184) /* 0xb8 */);
    // 0041d3ca  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041d3cc  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041d3ce  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0041d3d1  8b99d0000000           -mov ebx, dword ptr [ecx + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0041d3d7  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041d3d9  03d3                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0041d3db  89b1e8000000           -mov dword ptr [ecx + 0xe8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.esi;
    // 0041d3e1  03fa                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041d3e3  8981e0000000           -mov dword ptr [ecx + 0xe0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 0041d3e9  89b9ec000000           -mov dword ptr [ecx + 0xec], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.edi;
    // 0041d3ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d3f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d3f1  8991e4000000           -mov dword ptr [ecx + 0xe4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 0041d3f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d3f8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041d3fb:
    // 0041d3fb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041d3fd  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d400  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d401  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41d410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d410  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d411  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041d415  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041d417  7c4e                   -jl 0x41d467
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d467;
    }
    // 0041d419  3bb1dc000000           +cmp esi, dword ptr [ecx + 0xdc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d41f  7d46                   -jge 0x41d467
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d467;
    }
    // 0041d421  8b91b8000000           -mov edx, dword ptr [ecx + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(184) /* 0xb8 */);
    // 0041d427  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041d429  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0041d42c  8bb1d0000000           -mov esi, dword ptr [ecx + 0xd0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0041d432  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0041d434  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d435  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041d437  8981e4000000           -mov dword ptr [ecx + 0xe4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */) = cpu.eax;
    // 0041d43d  8991ec000000           -mov dword ptr [ecx + 0xec], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.edx;
    // 0041d443  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0041d449  0faf91b4000000         -imul edx, dword ptr [ecx + 0xb4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */))));
    // 0041d450  8b81cc000000           -mov eax, dword ptr [ecx + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 0041d456  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041d458  8981e0000000           -mov dword ptr [ecx + 0xe0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 0041d45e  8991e8000000           -mov dword ptr [ecx + 0xe8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.edx;
    // 0041d464  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0041d467:
    // 0041d467  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041d469  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d46c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d46d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41d470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d471  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041d475  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041d477  7c4e                   -jl 0x41d4c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d4c7;
    }
    // 0041d479  3bb1d8000000           +cmp esi, dword ptr [ecx + 0xd8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d47f  7d46                   -jge 0x41d4c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d4c7;
    }
    // 0041d481  8b91b4000000           -mov edx, dword ptr [ecx + 0xb4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 0041d487  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041d489  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0041d48c  8bb1cc000000           -mov esi, dword ptr [ecx + 0xcc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 0041d492  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0041d494  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d495  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041d497  8981e0000000           -mov dword ptr [ecx + 0xe0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 0041d49d  8991e8000000           -mov dword ptr [ecx + 0xe8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.edx;
    // 0041d4a3  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0041d4a9  0faf91b8000000         -imul edx, dword ptr [ecx + 0xb8]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(184) /* 0xb8 */))));
    // 0041d4b0  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0041d4b6  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041d4b8  8981e4000000           -mov dword ptr [ecx + 0xe4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */) = cpu.eax;
    // 0041d4be  8991ec000000           -mov dword ptr [ecx + 0xec], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.edx;
    // 0041d4c4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0041d4c7:
    // 0041d4c7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041d4c9  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d4cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d4cd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41d4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d4d0  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0041d4d6  8b91cc000000           -mov edx, dword ptr [ecx + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 0041d4dc  0faf81b4000000         -imul eax, dword ptr [ecx + 0xb4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */))));
    // 0041d4e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d4e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d4e5  8bb1d0000000           -mov esi, dword ptr [ecx + 0xd0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0041d4eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d4ec  8bb9b8000000           -mov edi, dword ptr [ecx + 0xb8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(184) /* 0xb8 */);
    // 0041d4f2  8b89dc000000           -mov ecx, dword ptr [ecx + 0xdc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0041d4f8  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0041d4fb  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d4ff  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041d501  03ce                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0041d503  3bd3                   +cmp edx, ebx
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
    // 0041d505  7f1b                   -jg 0x41d522
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041d522;
    }
    // 0041d507  3bc3                   +cmp eax, ebx
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
    // 0041d509  7e17                   -jle 0x41d522
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d522;
    }
    // 0041d50b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d50f  3bf0                   +cmp esi, eax
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
    // 0041d511  7f0f                   -jg 0x41d522
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041d522;
    }
    // 0041d513  3bc8                   +cmp ecx, eax
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
    // 0041d515  7e0b                   -jle 0x41d522
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d522;
    }
    // 0041d517  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041d519  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d51a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0041d51c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d51d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d51e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d51f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041d522:
    // 0041d522  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d523  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d524  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041d527  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d528  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41d530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d530  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041d534  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d535  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d537  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d538  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d53c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d53d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041d53f  e88cffffff             -call 0x41d4d0
    cpu.esp -= 4;
    sub_41d4d0(app, cpu);
    // 0041d544  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d546  7c08                   -jl 0x41d550
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d550;
    }
    // 0041d548  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d54a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d54b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041d54d  ff5240                 -call dword ptr [edx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0041d550:
    // 0041d550  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041d552  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d553  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41d560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d560  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041d562  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041d564  c700a4024300           -mov dword ptr [eax], 0x4302a4
    app->getMemory<x86::reg32>(cpu.eax) = 4391588 /*0x4302a4*/;
    // 0041d56a  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041d56d  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041d570  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0041d573  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041d576  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0041d579  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0041d57c  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041d57f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d580  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d581  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d583  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0041d586  c70684014300           -mov dword ptr [esi], 0x430184
    app->getMemory<x86::reg32>(cpu.esi) = 4391300 /*0x430184*/;
    // 0041d58c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d58e  740d                   -je 0x41d59d
    if (cpu.flags.zf)
    {
        goto L_0x0041d59d;
    }
    // 0041d590  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041d592  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d593  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d596  c7464800000000         -mov dword ptr [esi + 0x48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
L_0x0041d59d:
    // 0041d59d  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0041d5a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d5a2  740d                   -je 0x41d5b1
    if (cpu.flags.zf)
    {
        goto L_0x0041d5b1;
    }
    // 0041d5a4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041d5a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d5a7  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d5aa  c7464400000000         -mov dword ptr [esi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
L_0x0041d5b1:
    // 0041d5b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d5b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d5c0  d981b0000000           -fld dword ptr [ecx + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */)));
    // 0041d5c6  d899a8000000           -fcomp dword ptr [ecx + 0xa8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(168) /* 0xa8 */)));
    cpu.fpu.pop();
    // 0041d5cc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041d5ce  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0041d5d1  740c                   -je 0x41d5df
    if (cpu.flags.zf)
    {
        goto L_0x0041d5df;
    }
    // 0041d5d3  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0041d5d9  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
L_0x0041d5df:
    // 0041d5df  d981b0000000           -fld dword ptr [ecx + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */)));
    // 0041d5e5  d899ac000000           -fcomp dword ptr [ecx + 0xac]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(172) /* 0xac */)));
    cpu.fpu.pop();
    // 0041d5eb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041d5ed  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041d5f0  750c                   -jne 0x41d5fe
    if (!cpu.flags.zf)
    {
        goto L_0x0041d5fe;
    }
    // 0041d5f2  8b91ac000000           -mov edx, dword ptr [ecx + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0041d5f8  8991b0000000           -mov dword ptr [ecx + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.edx;
L_0x0041d5fe:
    // 0041d5fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d600  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d601  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d603  d986b0000000           -fld dword ptr [esi + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(176) /* 0xb0 */)));
    // 0041d609  d8a6d4000000           -fsub dword ptr [esi + 0xd4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */));
    // 0041d60f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d611  d99eb0000000           -fstp dword ptr [esi + 0xb0]
    app->getMemory<float>(cpu.esi + x86::reg32(176) /* 0xb0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d617  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d61a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041d61c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d61d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d620  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d621  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d623  d986d4000000           -fld dword ptr [esi + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */)));
    // 0041d629  d886b0000000           -fadd dword ptr [esi + 0xb0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(176) /* 0xb0 */));
    // 0041d62f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d631  d99eb0000000           -fstp dword ptr [esi + 0xb0]
    app->getMemory<float>(cpu.esi + x86::reg32(176) /* 0xb0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d637  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d63a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041d63c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d63d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d640  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d641  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d643  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d645  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d648  d986b0000000           -fld dword ptr [esi + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(176) /* 0xb0 */)));
    // 0041d64e  d8a6a8000000           -fsub dword ptr [esi + 0xa8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(168) /* 0xa8 */));
    // 0041d654  d986ac000000           -fld dword ptr [esi + 0xac]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(172) /* 0xac */)));
    // 0041d65a  d8a6a8000000           -fsub dword ptr [esi + 0xa8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(168) /* 0xa8 */));
    // 0041d660  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d661  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041d663  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d670  d9054c054300           -fld dword ptr [0x43054c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4392268) /* 0x43054c */)));
    // 0041d676  d8642404               -fsub dword ptr [esp + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0041d67a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041d67c  d889a8000000           -fmul dword ptr [ecx + 0xa8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(168) /* 0xa8 */));
    // 0041d682  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041d686  d889ac000000           -fmul dword ptr [ecx + 0xac]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(172) /* 0xac */));
    // 0041d68c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041d68e  d999b0000000           -fstp dword ptr [ecx + 0xb0]
    app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d694  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d697  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41d6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d6a0  a10c3a4900             -mov eax, dword ptr [0x493a0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 0041d6a5  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041d6a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d6a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d6aa  ff153c014300           -call dword ptr [0x43013c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391228) /* 0x43013c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d6b0  8b3538014300           -mov esi, dword ptr [0x430138]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4391224) /* 0x430138 */);
    // 0041d6b6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d6b8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d6ba  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d6be  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d6c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d6c1  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d6c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d6c5  7438                   -je 0x41d6ff
    if (cpu.flags.zf)
    {
        goto L_0x0041d6ff;
    }
    // 0041d6c7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d6c8  8b1d34014300           -mov ebx, dword ptr [0x430134]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4391220) /* 0x430134 */);
    // 0041d6ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d6cf  8b3d30014300           -mov edi, dword ptr [0x430130]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4391216) /* 0x430130 */);
L_0x0041d6d5:
    // 0041d6d5  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d6d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d6da  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d6dc  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d6e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d6e1  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d6e3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d6e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d6e7  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d6eb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d6ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d6ee  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d6f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d6f2  75e1                   -jne 0x41d6d5
    if (!cpu.flags.zf)
    {
        goto L_0x0041d6d5;
    }
    // 0041d6f4  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d6f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d6f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d6fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d6fb  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041d6fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041d6ff:
    // 0041d6ff  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d703  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d704  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041d707  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d710  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041d713  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 0041d717  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041d719  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d71b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d71d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041d71f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d720  ff1540014300           -call dword ptr [0x430140]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391232) /* 0x430140 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d726  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d728  7416                   -je 0x41d740
    if (cpu.flags.zf)
    {
        goto L_0x0041d740;
    }
    // 0041d72a  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 0041d72e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d72f  ff1530014300           -call dword ptr [0x430130]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391216) /* 0x430130 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d735  8d542400               -lea edx, [esp]
    cpu.edx = x86::reg32(cpu.esp);
    // 0041d739  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d73a  ff1534014300           -call dword ptr [0x430134]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391220) /* 0x430134 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0041d740:
    // 0041d740  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041d743  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d750  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d751  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041d755  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d757  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041d75a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d75b  68d4c74300             -push 0x43c7d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442068 /*0x43c7d4*/;
    cpu.esp -= 4;
    // 0041d760  e82f7a0000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041d765  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d767  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041d76a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0041d76c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d76d  3d050000c0             +cmp eax, 0xc0000005
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
    // 0041d772  7510                   -jne 0x41d784
    if (!cpu.flags.zf)
    {
        goto L_0x0041d784;
    }
    // 0041d774  6864c74300             -push 0x43c764
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441956 /*0x43c764*/;
    cpu.esp -= 4;
    // 0041d779  6848c74300             -push 0x43c748
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441928 /*0x43c748*/;
    cpu.esp -= 4;
    // 0041d77e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d77f  e99e010000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d784:
    // 0041d784  3d8c0000c0             +cmp eax, 0xc000008c
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
    // 0041d789  7510                   -jne 0x41d79b
    if (!cpu.flags.zf)
    {
        goto L_0x0041d79b;
    }
    // 0041d78b  68d0c64300             -push 0x43c6d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441808 /*0x43c6d0*/;
    cpu.esp -= 4;
    // 0041d790  68b0c64300             -push 0x43c6b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441776 /*0x43c6b0*/;
    cpu.esp -= 4;
    // 0041d795  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d796  e987010000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d79b:
    // 0041d79b  3d03000080             +cmp eax, 0x80000003
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
    // 0041d7a0  7510                   -jne 0x41d7b2
    if (!cpu.flags.zf)
    {
        goto L_0x0041d7b2;
    }
    // 0041d7a2  6890c64300             -push 0x43c690
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441744 /*0x43c690*/;
    cpu.esp -= 4;
    // 0041d7a7  6878c64300             -push 0x43c678
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441720 /*0x43c678*/;
    cpu.esp -= 4;
    // 0041d7ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d7ad  e970010000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d7b2:
    // 0041d7b2  3d02000080             +cmp eax, 0x80000002
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
    // 0041d7b7  7510                   -jne 0x41d7c9
    if (!cpu.flags.zf)
    {
        goto L_0x0041d7c9;
    }
    // 0041d7b9  68a4c54300             -push 0x43c5a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441508 /*0x43c5a4*/;
    cpu.esp -= 4;
    // 0041d7be  6884c54300             -push 0x43c584
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441476 /*0x43c584*/;
    cpu.esp -= 4;
    // 0041d7c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d7c4  e959010000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d7c9:
    // 0041d7c9  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 0041d7ce  7510                   -jne 0x41d7e0
    if (!cpu.flags.zf)
    {
        goto L_0x0041d7e0;
    }
    // 0041d7d0  68e8c44300             -push 0x43c4e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441320 /*0x43c4e8*/;
    cpu.esp -= 4;
    // 0041d7d5  68c8c44300             -push 0x43c4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441288 /*0x43c4c8*/;
    cpu.esp -= 4;
    // 0041d7da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d7db  e942010000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d7e0:
    // 0041d7e0  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 0041d7e5  7510                   -jne 0x41d7f7
    if (!cpu.flags.zf)
    {
        goto L_0x0041d7f7;
    }
    // 0041d7e7  6870c44300             -push 0x43c470
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441200 /*0x43c470*/;
    cpu.esp -= 4;
    // 0041d7ec  6850c44300             -push 0x43c450
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441168 /*0x43c450*/;
    cpu.esp -= 4;
    // 0041d7f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d7f2  e92b010000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d7f7:
    // 0041d7f7  3d8f0000c0             +cmp eax, 0xc000008f
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
    // 0041d7fc  7510                   -jne 0x41d80e
    if (!cpu.flags.zf)
    {
        goto L_0x0041d80e;
    }
    // 0041d7fe  68f0c34300             -push 0x43c3f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441072 /*0x43c3f0*/;
    cpu.esp -= 4;
    // 0041d803  68d0c34300             -push 0x43c3d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4441040 /*0x43c3d0*/;
    cpu.esp -= 4;
    // 0041d808  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d809  e914010000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d80e:
    // 0041d80e  3d900000c0             +cmp eax, 0xc0000090
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
    // 0041d813  7510                   -jne 0x41d825
    if (!cpu.flags.zf)
    {
        goto L_0x0041d825;
    }
    // 0041d815  687cc34300             -push 0x43c37c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440956 /*0x43c37c*/;
    cpu.esp -= 4;
    // 0041d81a  685cc34300             -push 0x43c35c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440924 /*0x43c35c*/;
    cpu.esp -= 4;
    // 0041d81f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d820  e9fd000000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d825:
    // 0041d825  3d910000c0             +cmp eax, 0xc0000091
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
    // 0041d82a  7510                   -jne 0x41d83c
    if (!cpu.flags.zf)
    {
        goto L_0x0041d83c;
    }
    // 0041d82c  68f0c24300             -push 0x43c2f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440816 /*0x43c2f0*/;
    cpu.esp -= 4;
    // 0041d831  68d8c24300             -push 0x43c2d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440792 /*0x43c2d8*/;
    cpu.esp -= 4;
    // 0041d836  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d837  e9e6000000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d83c:
    // 0041d83c  3d920000c0             +cmp eax, 0xc0000092
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
    // 0041d841  7510                   -jne 0x41d853
    if (!cpu.flags.zf)
    {
        goto L_0x0041d853;
    }
    // 0041d843  6884c24300             -push 0x43c284
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440708 /*0x43c284*/;
    cpu.esp -= 4;
    // 0041d848  6868c24300             -push 0x43c268
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440680 /*0x43c268*/;
    cpu.esp -= 4;
    // 0041d84d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d84e  e9cf000000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d853:
    // 0041d853  3d930000c0             +cmp eax, 0xc0000093
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
    // 0041d858  7510                   -jne 0x41d86a
    if (!cpu.flags.zf)
    {
        goto L_0x0041d86a;
    }
    // 0041d85a  68fcc14300             -push 0x43c1fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440572 /*0x43c1fc*/;
    cpu.esp -= 4;
    // 0041d85f  68e4c14300             -push 0x43c1e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440548 /*0x43c1e4*/;
    cpu.esp -= 4;
    // 0041d864  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d865  e9b8000000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d86a:
    // 0041d86a  3d1d0000c0             +cmp eax, 0xc000001d
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
    // 0041d86f  7510                   -jne 0x41d881
    if (!cpu.flags.zf)
    {
        goto L_0x0041d881;
    }
    // 0041d871  68b0c14300             -push 0x43c1b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440496 /*0x43c1b0*/;
    cpu.esp -= 4;
    // 0041d876  6890c14300             -push 0x43c190
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440464 /*0x43c190*/;
    cpu.esp -= 4;
    // 0041d87b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d87c  e9a1000000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d881:
    // 0041d881  3d060000c0             +cmp eax, 0xc0000006
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
    // 0041d886  7510                   -jne 0x41d898
    if (!cpu.flags.zf)
    {
        goto L_0x0041d898;
    }
    // 0041d888  68bcc04300             -push 0x43c0bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440252 /*0x43c0bc*/;
    cpu.esp -= 4;
    // 0041d88d  68a4c04300             -push 0x43c0a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440228 /*0x43c0a4*/;
    cpu.esp -= 4;
    // 0041d892  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d893  e98a000000             -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d898:
    // 0041d898  3d940000c0             +cmp eax, 0xc0000094
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
    // 0041d89d  750d                   -jne 0x41d8ac
    if (!cpu.flags.zf)
    {
        goto L_0x0041d8ac;
    }
    // 0041d89f  6858c04300             -push 0x43c058
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440152 /*0x43c058*/;
    cpu.esp -= 4;
    // 0041d8a4  6838c04300             -push 0x43c038
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440120 /*0x43c038*/;
    cpu.esp -= 4;
    // 0041d8a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d8aa  eb76                   -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d8ac:
    // 0041d8ac  3d950000c0             +cmp eax, 0xc0000095
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
    // 0041d8b1  750d                   -jne 0x41d8c0
    if (!cpu.flags.zf)
    {
        goto L_0x0041d8c0;
    }
    // 0041d8b3  68d4bf4300             -push 0x43bfd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4440020 /*0x43bfd4*/;
    cpu.esp -= 4;
    // 0041d8b8  68bcbf4300             -push 0x43bfbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439996 /*0x43bfbc*/;
    cpu.esp -= 4;
    // 0041d8bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d8be  eb62                   -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d8c0:
    // 0041d8c0  3d260000c0             +cmp eax, 0xc0000026
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
    // 0041d8c5  750d                   -jne 0x41d8d4
    if (!cpu.flags.zf)
    {
        goto L_0x0041d8d4;
    }
    // 0041d8c7  6810bf4300             -push 0x43bf10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439824 /*0x43bf10*/;
    cpu.esp -= 4;
    // 0041d8cc  68f0be4300             -push 0x43bef0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439792 /*0x43bef0*/;
    cpu.esp -= 4;
    // 0041d8d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d8d2  eb4e                   -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d8d4:
    // 0041d8d4  3d250000c0             +cmp eax, 0xc0000025
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
    // 0041d8d9  750d                   -jne 0x41d8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0041d8e8;
    }
    // 0041d8db  689cbe4300             -push 0x43be9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439708 /*0x43be9c*/;
    cpu.esp -= 4;
    // 0041d8e0  6878be4300             -push 0x43be78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439672 /*0x43be78*/;
    cpu.esp -= 4;
    // 0041d8e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d8e6  eb3a                   -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d8e8:
    // 0041d8e8  3d960000c0             +cmp eax, 0xc0000096
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
    // 0041d8ed  750d                   -jne 0x41d8fc
    if (!cpu.flags.zf)
    {
        goto L_0x0041d8fc;
    }
    // 0041d8ef  6810be4300             -push 0x43be10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439568 /*0x43be10*/;
    cpu.esp -= 4;
    // 0041d8f4  68f4bd4300             -push 0x43bdf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439540 /*0x43bdf4*/;
    cpu.esp -= 4;
    // 0041d8f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d8fa  eb26                   -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d8fc:
    // 0041d8fc  3d04000080             +cmp eax, 0x80000004
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
    // 0041d901  750d                   -jne 0x41d910
    if (!cpu.flags.zf)
    {
        goto L_0x0041d910;
    }
    // 0041d903  6890bd4300             -push 0x43bd90
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439440 /*0x43bd90*/;
    cpu.esp -= 4;
    // 0041d908  6878bd4300             -push 0x43bd78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439416 /*0x43bd78*/;
    cpu.esp -= 4;
    // 0041d90d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d90e  eb12                   -jmp 0x41d922
    goto L_0x0041d922;
L_0x0041d910:
    // 0041d910  3dfd0000c0             +cmp eax, 0xc00000fd
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
    // 0041d915  7518                   -jne 0x41d92f
    if (!cpu.flags.zf)
    {
        goto L_0x0041d92f;
    }
    // 0041d917  6858bd4300             -push 0x43bd58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439384 /*0x43bd58*/;
    cpu.esp -= 4;
    // 0041d91c  683cbd4300             -push 0x43bd3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439356 /*0x43bd3c*/;
    cpu.esp -= 4;
    // 0041d921  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
L_0x0041d922:
    // 0041d922  681cbd4300             -push 0x43bd1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4439324 /*0x43bd1c*/;
    cpu.esp -= 4;
    // 0041d927  e868780000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041d92c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0041d92f:
    // 0041d92f  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041d934  e8c27a0000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041d939  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041d93c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041d941  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41d950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d950  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041d951  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0041d953  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0041d955  6850054300             -push 0x430550
    app->getMemory<x86::reg32>(cpu.esp-4) = 4392272 /*0x430550*/;
    cpu.esp -= 4;
    // 0041d95a  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 0041d95f  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0041d965  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d966  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0041d96d  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041d970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d971  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d972  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d973  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0041d976  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041d978  891dec7f4600           -mov dword ptr [0x467fec], ebx
    app->getMemory<x86::reg32>(x86::reg32(4620268) /* 0x467fec */) = cpu.ebx;
    // 0041d97e  891dc0ee4700           -mov dword ptr [0x47eec0], ebx
    app->getMemory<x86::reg32>(x86::reg32(4714176) /* 0x47eec0 */) = cpu.ebx;
    // 0041d984  6850e44300             -push 0x43e450
    app->getMemory<x86::reg32>(cpu.esp-4) = 4449360 /*0x43e450*/;
    cpu.esp -= 4;
    // 0041d989  680c394900             -push 0x49390c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798732 /*0x49390c*/;
    cpu.esp -= 4;
    // 0041d98e  683cc84300             -push 0x43c83c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442172 /*0x43c83c*/;
    cpu.esp -= 4;
    // 0041d993  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0041d996  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d997  e808850000             -call 0x425ea4
    cpu.esp -= 4;
    sub_425ea4(app, cpu);
    // 0041d99c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041d99f  83f802                 +cmp eax, 2
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
    // 0041d9a2  740a                   -je 0x41d9ae
    if (cpu.flags.zf)
    {
        goto L_0x0041d9ae;
    }
    // 0041d9a4  c705c0ee470001000000   -mov dword ptr [0x47eec0], 1
    app->getMemory<x86::reg32>(x86::reg32(4714176) /* 0x47eec0 */) = 1 /*0x1*/;
L_0x0041d9ae:
    // 0041d9ae  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0041d9b1  8935083a4900           -mov dword ptr [0x493a08], esi
    app->getMemory<x86::reg32>(x86::reg32(4798984) /* 0x493a08 */) = cpu.esi;
    // 0041d9b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d9b8  e893040000             -call 0x41de50
    cpu.esp -= 4;
    sub_41de50(app, cpu);
    // 0041d9bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041d9c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d9c2  7518                   -jne 0x41d9dc
    if (!cpu.flags.zf)
    {
        goto L_0x0041d9dc;
    }
    // 0041d9c4  e8d7fcffff             -call 0x41d6a0
    cpu.esp -= 4;
    sub_41d6a0(app, cpu);
    // 0041d9c9  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0041d9cc  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0041d9d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d9d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d9d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d9d6  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0041d9d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d9d9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041d9dc:
    // 0041d9dc  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0041d9df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d9e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d9e1  e8da040000             -call 0x41dec0
    cpu.esp -= 4;
    sub_41dec0(app, cpu);
    // 0041d9e6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041d9e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d9eb  7518                   -jne 0x41da05
    if (!cpu.flags.zf)
    {
        goto L_0x0041da05;
    }
    // 0041d9ed  e8aefcffff             -call 0x41d6a0
    cpu.esp -= 4;
    sub_41d6a0(app, cpu);
    // 0041d9f2  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0041d9f5  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0041d9fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d9fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d9fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d9ff  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0041da01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da02  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041da05:
    // 0041da05  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041da06  68c8000000             -push 0xc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 200 /*0xc8*/;
    cpu.esp -= 4;
    // 0041da0b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041da0d  8b0d0c3a4900           -mov ecx, dword ptr [0x493a0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 0041da13  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041da14  ff1544014300           -call dword ptr [0x430144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391236) /* 0x430144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041da1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041da1c  7507                   -jne 0x41da25
    if (!cpu.flags.zf)
    {
        goto L_0x0041da25;
    }
    // 0041da1e  6828c84300             -push 0x43c828
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442152 /*0x43c828*/;
    cpu.esp -= 4;
    // 0041da23  eb05                   -jmp 0x41da2a
    goto L_0x0041da2a;
L_0x0041da25:
    // 0041da25  6810c84300             -push 0x43c810
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442128 /*0x43c810*/;
    cpu.esp -= 4;
L_0x0041da2a:
    // 0041da2a  e865770000             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0041da2f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041da32  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0041da35  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041da36  e85580feff             -call 0x405a90
    cpu.esp -= 4;
    sub_405a90(app, cpu);
    // 0041da3b  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0041da3e  e85dfcffff             -call 0x41d6a0
    cpu.esp -= 4;
    sub_41d6a0(app, cpu);
    // 0041da43  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 0041da48  e8ae790000             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 0041da4d  83c408                 +add esp, 8
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
    // 0041da50  eb15                   -jmp 0x41da67
    return sub_41da67(app, cpu);
}

/* align: skip  */
void Application::asm_sub_41da52(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041da52  6804c84300             -push 0x43c804
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442116 /*0x43c804*/;
    cpu.esp -= 4;
    // 0041da57  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0041da5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041da5b  e8f0fcffff             -call 0x41d750
    cpu.esp -= 4;
    sub_41d750(app, cpu);
    // 0041da60  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041da63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41da64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041da64  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0041da67  c745fcffffffff         -mov dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 4294967295 /*0xffffffff*/;
    // 0041da6e  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0041da71  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0041da74  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0041da7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da7e  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0041da80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da81  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41da67(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0041da67;
    // 0041da64  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
L_entry_0x0041da67:
    // 0041da67  c745fcffffffff         -mov dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 4294967295 /*0xffffffff*/;
    // 0041da6e  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0041da71  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0041da74  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0041da7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da7e  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0041da80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041da81  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41da90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041da90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041da91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041da92  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041da96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041da97  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041da9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041da9c  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041daa0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041daa1  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041daa5  81fe01020000           +cmp esi, 0x201
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(513 /*0x201*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041daab  0f87c9020000           -ja 0x41dd7a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041dd7a;
    }
    // 0041dab1  81fe01020000           +cmp esi, 0x201
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(513 /*0x201*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dab7  0f848f020000           -je 0x41dd4c
    if (cpu.flags.zf)
    {
        goto L_0x0041dd4c;
    }
    // 0041dabd  83fe7e                 +cmp esi, 0x7e
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(126 /*0x7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dac0  0f87d4000000           -ja 0x41db9a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041db9a;
    }
    // 0041dac6  0f8499000000           -je 0x41db65
    if (cpu.flags.zf)
    {
        goto L_0x0041db65;
    }
    // 0041dacc  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041dace  83e802                 +sub eax, 2
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
    // 0041dad1  7478                   -je 0x41db4b
    if (cpu.flags.zf)
    {
        goto L_0x0041db4b;
    }
    // 0041dad3  83e81a                 +sub eax, 0x1a
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041dad6  744a                   -je 0x41db22
    if (cpu.flags.zf)
    {
        goto L_0x0041db22;
    }
    // 0041dad8  83e804                 +sub eax, 4
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
    // 0041dadb  0f8545030000           -jne 0x41de26
    if (!cpu.flags.zf)
    {
        goto L_0x0041de26;
    }
    // 0041dae1  e82a6bfeff             -call 0x404610
    cpu.esp -= 4;
    sub_404610(app, cpu);
    // 0041dae6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041dae8  741e                   -je 0x41db08
    if (cpu.flags.zf)
    {
        goto L_0x0041db08;
    }
    // 0041daea  a1143a4900             -mov eax, dword ptr [0x493a14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798996) /* 0x493a14 */);
    // 0041daef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041daf0  ff1554014300           -call dword ptr [0x430154]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391252) /* 0x430154 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041daf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041daf7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041daf8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041daf9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041dafa  ff1550014300           -call dword ptr [0x430150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391248) /* 0x430150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db05  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041db08:
    // 0041db08  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041db0a  ff1554014300           -call dword ptr [0x430154]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391252) /* 0x430154 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db10  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041db11  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041db12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041db13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041db14  ff1550014300           -call dword ptr [0x430150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391248) /* 0x430150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db1f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041db22:
    // 0041db22  83fb01                 +cmp ebx, 1
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
    // 0041db25  0f85fb020000           -jne 0x41de26
    if (!cpu.flags.zf)
    {
        goto L_0x0041de26;
    }
    // 0041db2b  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0041db2d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041db2e  ff152c014300           -call dword ptr [0x43012c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391212) /* 0x43012c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db34  e8f775feff             -call 0x405130
    cpu.esp -= 4;
    sub_405130(app, cpu);
    // 0041db39  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041db3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041db3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041db3c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041db3d  ff1550014300           -call dword ptr [0x430150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391248) /* 0x430150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db48  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041db4b:
    // 0041db4b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041db4d  ff154c014300           -call dword ptr [0x43014c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391244) /* 0x43014c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041db54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041db55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041db56  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041db57  ff1550014300           -call dword ptr [0x430150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391248) /* 0x430150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db62  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041db65:
    // 0041db65  a10c3a4900             -mov eax, dword ptr [0x493a0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 0041db6a  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041db6c  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041db6e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041db70  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0041db73  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041db79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041db7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041db7b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041db7d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041db7f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041db81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041db82  ff1548014300           -call dword ptr [0x430148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391240) /* 0x430148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db88  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041db89  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041db8a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041db8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041db8c  ff1550014300           -call dword ptr [0x430150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391248) /* 0x430150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041db97  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041db9a:
    // 0041db9a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041db9c  2d00010000             +sub eax, 0x100
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041dba1  0f8406010000           -je 0x41dcad
    if (cpu.flags.zf)
    {
        goto L_0x0041dcad;
    }
    // 0041dba7  83e813                 +sub eax, 0x13
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041dbaa  7453                   -je 0x41dbff
    if (cpu.flags.zf)
    {
        goto L_0x0041dbff;
    }
    // 0041dbac  2ded000000             +sub eax, 0xed
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(237 /*0xed*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041dbb1  0f856f020000           -jne 0x41de26
    if (!cpu.flags.zf)
    {
        goto L_0x0041de26;
    }
    // 0041dbb7  a1183a4900             -mov eax, dword ptr [0x493a18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4799000) /* 0x493a18 */);
    // 0041dbbc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041dbbe  7404                   -je 0x41dbc4
    if (cpu.flags.zf)
    {
        goto L_0x0041dbc4;
    }
    // 0041dbc0  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0041dbc2  eb19                   -jmp 0x41dbdd
    goto L_0x0041dbdd;
L_0x0041dbc4:
    // 0041dbc4  a11c3a4900             -mov eax, dword ptr [0x493a1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4799004) /* 0x493a1c */);
    // 0041dbc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041dbcb  740e                   -je 0x41dbdb
    if (cpu.flags.zf)
    {
        goto L_0x0041dbdb;
    }
    // 0041dbcd  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041dbd1  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0041dbd3  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041dbd5  c1ea10                 +shr edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.edx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0041dbd8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041dbd9  eb0c                   -jmp 0x41dbe7
    goto L_0x0041dbe7;
L_0x0041dbdb:
    // 0041dbdb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
L_0x0041dbdd:
    // 0041dbdd  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041dbe1  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041dbe3  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0041dbe6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0041dbe7:
    // 0041dbe7  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041dbec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041dbed  e8be75feff             -call 0x4051b0
    cpu.esp -= 4;
    sub_4051b0(app, cpu);
    // 0041dbf2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041dbf5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041dbf7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dbf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dbf9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dbfa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dbfb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dbfc  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041dbff:
    // 0041dbff  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041dc03  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041dc07  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041dc08  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041dc0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041dc0d  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041dc11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041dc12  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041dc16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041dc17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041dc18  e86361feff             -call 0x403d80
    cpu.esp -= 4;
    sub_403d80(app, cpu);
    // 0041dc1d  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0041dc21  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041dc24  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dc27  7d07                   -jge 0x41dc30
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041dc30;
    }
    // 0041dc29  68c8000000             -push 0xc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 200 /*0xc8*/;
    cpu.esp -= 4;
    // 0041dc2e  eb0a                   -jmp 0x41dc3a
    goto L_0x0041dc3a;
L_0x0041dc30:
    // 0041dc30  83f80a                 +cmp eax, 0xa
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
    // 0041dc33  7e0d                   -jle 0x41dc42
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041dc42;
    }
    // 0041dc35  68d0000000             -push 0xd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 208 /*0xd0*/;
    cpu.esp -= 4;
L_0x0041dc3a:
    // 0041dc3a  e8e17bfeff             -call 0x405820
    cpu.esp -= 4;
    sub_405820(app, cpu);
    // 0041dc3f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041dc42:
    // 0041dc42  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041dc46  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dc49  7d07                   -jge 0x41dc52
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041dc52;
    }
    // 0041dc4b  68cb000000             -push 0xcb
    app->getMemory<x86::reg32>(cpu.esp-4) = 203 /*0xcb*/;
    cpu.esp -= 4;
    // 0041dc50  eb0a                   -jmp 0x41dc5c
    goto L_0x0041dc5c;
L_0x0041dc52:
    // 0041dc52  83f80a                 +cmp eax, 0xa
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
    // 0041dc55  7e0d                   -jle 0x41dc64
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041dc64;
    }
    // 0041dc57  68cd000000             -push 0xcd
    app->getMemory<x86::reg32>(cpu.esp-4) = 205 /*0xcd*/;
    cpu.esp -= 4;
L_0x0041dc5c:
    // 0041dc5c  e8bf7bfeff             -call 0x405820
    cpu.esp -= 4;
    sub_405820(app, cpu);
    // 0041dc61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041dc64:
    // 0041dc64  f644242401             +test byte ptr [esp + 0x24], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) & 1 /*0x1*/));
    // 0041dc69  740a                   -je 0x41dc75
    if (cpu.flags.zf)
    {
        goto L_0x0041dc75;
    }
    // 0041dc6b  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0041dc6d  e8ae7bfeff             -call 0x405820
    cpu.esp -= 4;
    sub_405820(app, cpu);
    // 0041dc72  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041dc75:
    // 0041dc75  f644242402             +test byte ptr [esp + 0x24], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) & 2 /*0x2*/));
    // 0041dc7a  740a                   -je 0x41dc86
    if (cpu.flags.zf)
    {
        goto L_0x0041dc86;
    }
    // 0041dc7c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041dc7e  e89d7bfeff             -call 0x405820
    cpu.esp -= 4;
    sub_405820(app, cpu);
    // 0041dc83  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041dc86:
    // 0041dc86  f644242404             +test byte ptr [esp + 0x24], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) & 4 /*0x4*/));
    // 0041dc8b  0f8495010000           -je 0x41de26
    if (cpu.flags.zf)
    {
        goto L_0x0041de26;
    }
    // 0041dc91  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 0041dc93  e8887bfeff             -call 0x405820
    cpu.esp -= 4;
    sub_405820(app, cpu);
    // 0041dc98  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041dc9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041dc9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041dc9d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041dc9e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041dc9f  ff1550014300           -call dword ptr [0x430150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391248) /* 0x430150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041dca5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dca6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dca7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dca8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dca9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dcaa  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041dcad:
    // 0041dcad  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041dcb1  83fe26                 +cmp esi, 0x26
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dcb4  7507                   -jne 0x41dcbd
    if (!cpu.flags.zf)
    {
        goto L_0x0041dcbd;
    }
    // 0041dcb6  68c8000000             -push 0xc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 200 /*0xc8*/;
    cpu.esp -= 4;
    // 0041dcbb  eb3d                   -jmp 0x41dcfa
    goto L_0x0041dcfa;
L_0x0041dcbd:
    // 0041dcbd  83fe28                 +cmp esi, 0x28
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dcc0  7507                   -jne 0x41dcc9
    if (!cpu.flags.zf)
    {
        goto L_0x0041dcc9;
    }
    // 0041dcc2  68d0000000             -push 0xd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 208 /*0xd0*/;
    cpu.esp -= 4;
    // 0041dcc7  eb31                   -jmp 0x41dcfa
    goto L_0x0041dcfa;
L_0x0041dcc9:
    // 0041dcc9  83fe25                 +cmp esi, 0x25
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dccc  7507                   -jne 0x41dcd5
    if (!cpu.flags.zf)
    {
        goto L_0x0041dcd5;
    }
    // 0041dcce  68cb000000             -push 0xcb
    app->getMemory<x86::reg32>(cpu.esp-4) = 203 /*0xcb*/;
    cpu.esp -= 4;
    // 0041dcd3  eb25                   -jmp 0x41dcfa
    goto L_0x0041dcfa;
L_0x0041dcd5:
    // 0041dcd5  83fe27                 +cmp esi, 0x27
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(39 /*0x27*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dcd8  7507                   -jne 0x41dce1
    if (!cpu.flags.zf)
    {
        goto L_0x0041dce1;
    }
    // 0041dcda  68cd000000             -push 0xcd
    app->getMemory<x86::reg32>(cpu.esp-4) = 205 /*0xcd*/;
    cpu.esp -= 4;
    // 0041dcdf  eb19                   -jmp 0x41dcfa
    goto L_0x0041dcfa;
L_0x0041dce1:
    // 0041dce1  83fe0d                 +cmp esi, 0xd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dce4  7504                   -jne 0x41dcea
    if (!cpu.flags.zf)
    {
        goto L_0x0041dcea;
    }
    // 0041dce6  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0041dce8  eb10                   -jmp 0x41dcfa
    goto L_0x0041dcfa;
L_0x0041dcea:
    // 0041dcea  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dced  7504                   -jne 0x41dcf3
    if (!cpu.flags.zf)
    {
        goto L_0x0041dcf3;
    }
    // 0041dcef  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041dcf1  eb07                   -jmp 0x41dcfa
    goto L_0x0041dcfa;
L_0x0041dcf3:
    // 0041dcf3  83fe08                 +cmp esi, 8
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
    // 0041dcf6  750a                   -jne 0x41dd02
    if (!cpu.flags.zf)
    {
        goto L_0x0041dd02;
    }
    // 0041dcf8  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
L_0x0041dcfa:
    // 0041dcfa  e8217bfeff             -call 0x405820
    cpu.esp -= 4;
    sub_405820(app, cpu);
    // 0041dcff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041dd02:
    // 0041dd02  a1602b4300             -mov eax, dword ptr [0x432b60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4402016) /* 0x432b60 */);
    // 0041dd07  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041dd09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041dd0b  0f84e5000000           -je 0x41ddf6
    if (cpu.flags.zf)
    {
        goto L_0x0041ddf6;
    }
    // 0041dd11  b8602b4300             -mov eax, 0x432b60
    cpu.eax = 4402016 /*0x432b60*/;
L_0x0041dd16:
    // 0041dd16  3b7004                 +cmp esi, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dd19  7417                   -je 0x41dd32
    if (cpu.flags.zf)
    {
        goto L_0x0041dd32;
    }
    // 0041dd1b  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041dd1e  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041dd21  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0041dd24  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041dd26  75ee                   -jne 0x41dd16
    if (!cpu.flags.zf)
    {
        goto L_0x0041dd16;
    }
    // 0041dd28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd2b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041dd2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd2f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041dd32:
    // 0041dd32  8b0c8d602b4300         -mov ecx, dword ptr [ecx*4 + 0x432b60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4402016) /* 0x432b60 */ + cpu.ecx * 4);
    // 0041dd39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041dd3a  e8e17afeff             -call 0x405820
    cpu.esp -= 4;
    sub_405820(app, cpu);
    // 0041dd3f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041dd42  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041dd44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd49  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041dd4c:
    // 0041dd4c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041dd50  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041dd52  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041dd54  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0041dd57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x0041dd58:
    // 0041dd58  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041dd5d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041dd5e  e84d74feff             -call 0x4051b0
    cpu.esp -= 4;
    sub_4051b0(app, cpu);
    // 0041dd63  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041dd66  c705183a490001000000   -mov dword ptr [0x493a18], 1
    app->getMemory<x86::reg32>(x86::reg32(4799000) /* 0x493a18 */) = 1 /*0x1*/;
    // 0041dd70  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041dd72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dd77  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041dd7a:
    // 0041dd7a  81fe10030000           +cmp esi, 0x310
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
    // 0041dd80  0f878e000000           -ja 0x41de14
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041de14;
    }
    // 0041dd86  0f8490000000           -je 0x41de1c
    if (cpu.flags.zf)
    {
        goto L_0x0041de1c;
    }
    // 0041dd8c  8d86fefdffff           -lea eax, [esi - 0x202]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-514) /* -0x202 */);
    // 0041dd92  83f804                 +cmp eax, 4
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
    // 0041dd95  0f878b000000           -ja 0x41de26
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041de26;
    }
    // 0041dd9b  ff248538de4100         -jmp dword ptr [eax*4 + 0x41de38]
    cpu.ip = app->getMemory<x86::reg32>(4316728 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041dda2:
    // 0041dda2  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041dda6  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041dda8  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041ddaa  c1e910                 +shr ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0041ddad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ddae  eba8                   -jmp 0x41dd58
    goto L_0x0041dd58;
  case 0x0041ddb0:
    // 0041ddb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddb3  c705183a490000000000   -mov dword ptr [0x493a18], 0
    app->getMemory<x86::reg32>(x86::reg32(4799000) /* 0x493a18 */) = 0 /*0x0*/;
    // 0041ddbd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ddbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddc1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
  case 0x0041ddc4:
    // 0041ddc4  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041ddc8  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0041ddca  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041ddcc  c1ea10                 +shr edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.edx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0041ddcf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041ddd0  eb0c                   -jmp 0x41ddde
    goto L_0x0041ddde;
  case 0x0041ddd2:
    // 0041ddd2  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041ddd6  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0041ddd8  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041ddda  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0041dddd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0041ddde:
    // 0041ddde  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041dde3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041dde4  e8c773feff             -call 0x4051b0
    cpu.esp -= 4;
    sub_4051b0(app, cpu);
    // 0041dde9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041ddec  c7051c3a490001000000   -mov dword ptr [0x493a1c], 1
    app->getMemory<x86::reg32>(x86::reg32(4799004) /* 0x493a1c */) = 1 /*0x1*/;
L_0x0041ddf6:
    // 0041ddf6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddf8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddf9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ddfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ddfd  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
  case 0x0041de00:
    // 0041de00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de03  c7051c3a490000000000   -mov dword ptr [0x493a1c], 0
    app->getMemory<x86::reg32>(x86::reg32(4799004) /* 0x493a1c */) = 0 /*0x0*/;
    // 0041de0d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041de0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de11  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0041de14:
    // 0041de14  81fe11030000           +cmp esi, 0x311
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
    // 0041de1a  750a                   -jne 0x41de26
    if (!cpu.flags.zf)
    {
        goto L_0x0041de26;
    }
L_0x0041de1c:
    // 0041de1c  c705103a490001000000   -mov dword ptr [0x493a10], 1
    app->getMemory<x86::reg32>(x86::reg32(4798992) /* 0x493a10 */) = 1 /*0x1*/;
L_0x0041de26:
    // 0041de26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041de27  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041de28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041de29  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041de2a  ff1550014300           -call dword ptr [0x430150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391248) /* 0x430150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041de30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de34  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de35  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_41de50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041de50  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041de53  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041de57  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041de58  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041de5a  68007f0000             -push 0x7f00
    app->getMemory<x86::reg32>(cpu.esp-4) = 32512 /*0x7f00*/;
    cpu.esp -= 4;
    // 0041de5f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041de60  c744240c08000000       -mov dword ptr [esp + 0xc], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 8 /*0x8*/;
    // 0041de68  c744241090da4100       -mov dword ptr [esp + 0x10], 0x41da90
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 4315792 /*0x41da90*/;
    // 0041de70  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0041de74  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0041de78  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041de7c  ff155c014300           -call dword ptr [0x43015c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391260) /* 0x43015c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041de82  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041de84  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041de88  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0041de8c  ff1520004300           -call dword ptr [0x430020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390944) /* 0x430020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041de92  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041de96  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041de9a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041de9b  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 0041de9f  c744242c44c84300       -mov dword ptr [esp + 0x2c], 0x43c844
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4442180 /*0x43c844*/;
    // 0041dea7  ff1558014300           -call dword ptr [0x430158]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391256) /* 0x430158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041dead  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041deb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041deb3  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041deb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41dec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041dec0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041dec4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041dec7  a3083a4900             -mov dword ptr [0x493a08], eax
    app->getMemory<x86::reg32>(x86::reg32(4798984) /* 0x493a08 */) = cpu.eax;
    // 0041decc  68007f0000             -push 0x7f00
    app->getMemory<x86::reg32>(cpu.esp-4) = 32512 /*0x7f00*/;
    cpu.esp -= 4;
    // 0041ded1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041ded3  ff1570014300           -call dword ptr [0x430170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391280) /* 0x430170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ded9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041dedb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041dedd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041dedf  685cc84300             -push 0x43c85c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442204 /*0x43c85c*/;
    cpu.esp -= 4;
    // 0041dee4  a3143a4900             -mov dword ptr [0x493a14], eax
    app->getMemory<x86::reg32>(x86::reg32(4798996) /* 0x493a14 */) = cpu.eax;
    // 0041dee9  ff151c004300           -call dword ptr [0x43001c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390940) /* 0x43001c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041deef  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 0041def1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041def2  ff1518004300           -call dword ptr [0x430018]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390936) /* 0x430018 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041def8  83f808                 +cmp eax, 8
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
    // 0041defb  7e0a                   -jle 0x41df07
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041df07;
    }
    // 0041defd  c705103a490001000000   -mov dword ptr [0x493a10], 1
    app->getMemory<x86::reg32>(x86::reg32(4798992) /* 0x493a10 */) = 1 /*0x1*/;
L_0x0041df07:
    // 0041df07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041df08  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041df0c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df0e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041df0f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df11  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 0041df13  ff1568014300           -call dword ptr [0x430168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391272) /* 0x430168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041df19  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041df1d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041df21  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041df25  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041df29  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041df2b  8b15083a4900           -mov edx, dword ptr [0x493a08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798984) /* 0x493a08 */);
    // 0041df31  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df33  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041df34  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041df37  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df39  2bce                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041df3b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041df3e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041df3f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df41  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df43  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 0041df48  6854c84300             -push 0x43c854
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442196 /*0x43c854*/;
    cpu.esp -= 4;
    // 0041df4d  6844c84300             -push 0x43c844
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442180 /*0x43c844*/;
    cpu.esp -= 4;
    // 0041df52  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df54  ff1564014300           -call dword ptr [0x430164]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391268) /* 0x430164 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041df5a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041df5c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041df5e  7505                   -jne 0x41df65
    if (!cpu.flags.zf)
    {
        goto L_0x0041df65;
    }
    // 0041df60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041df61  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041df64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041df65:
    // 0041df65  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0041df67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041df68  89350c3a4900           -mov dword ptr [0x493a0c], esi
    app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */) = cpu.esi;
    // 0041df6e  ff152c014300           -call dword ptr [0x43012c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391212) /* 0x43012c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041df74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041df75  ff1560014300           -call dword ptr [0x430160]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391264) /* 0x430160 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041df7b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041df80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041df81  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041df84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41df90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041df90  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041df94  8b0d0c3a4900           -mov ecx, dword ptr [0x493a0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 0041df9a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041df9c  6864c84300             -push 0x43c864
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442212 /*0x43c864*/;
    cpu.esp -= 4;
    // 0041dfa1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041dfa2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041dfa3  ff156c014300           -call dword ptr [0x43016c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391276) /* 0x43016c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041dfa9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41f2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f2e0  ff250c004300           -jmp dword ptr [0x43000c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4390924), cpu);
}

/* align: skip  */
void Application::asm_sub_41f2e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f2e6  ff2500004300           -jmp dword ptr [0x430000]
    return app->dynamic_call(app->getMemory<x86::reg32>(4390912), cpu);
}

/* align: skip  */
void Application::asm_sub_41f2ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f2ec  ff2504004300           -jmp dword ptr [0x430004]
    return app->dynamic_call(app->getMemory<x86::reg32>(4390916), cpu);
}

/* align: skip  */
void Application::asm_sub_41f300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f300  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0041f303  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0041f307  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0041f30b  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0041f30f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f310  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0041f314  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f315  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0041f319  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041f31d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f31f  6a38                   -push 0x38
    app->getMemory<x86::reg32>(cpu.esp-4) = 56 /*0x38*/;
    cpu.esp -= 4;
    // 0041f321  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041f325  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f327  6870c84300             -push 0x43c870
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442224 /*0x43c870*/;
    cpu.esp -= 4;
    // 0041f32c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f32d  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0041f331  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0041f335  897c2434               -mov dword ptr [esp + 0x34], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 0041f339  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 0041f33d  e8ae020000             -call 0x41f5f0
    cpu.esp -= 4;
    sub_41f5f0(app, cpu);
    // 0041f342  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041f345  3bc7                   +cmp eax, edi
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
    // 0041f347  753e                   -jne 0x41f387
    if (!cpu.flags.zf)
    {
        goto L_0x0041f387;
    }
    // 0041f349  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f34d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041f34f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f350  e8bb020000             -call 0x41f610
    cpu.esp -= 4;
    sub_41f610(app, cpu);
    // 0041f355  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041f357  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041f35a  83ff01                 +cmp edi, 1
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
    // 0041f35d  7415                   -je 0x41f374
    if (cpu.flags.zf)
    {
        goto L_0x0041f374;
    }
    // 0041f35f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f363  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f364  e827010000             -call 0x41f490
    cpu.esp -= 4;
    sub_41f490(app, cpu);
    // 0041f369  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f36c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f36e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f36f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f370  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0041f373  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f374:
    // 0041f374  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041f378  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f37c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f37d  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0041f37f  e80c010000             -call 0x41f490
    cpu.esp -= 4;
    sub_41f490(app, cpu);
    // 0041f384  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f387:
    // 0041f387  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f388  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f389  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0041f38c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41f390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f390  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0041f393  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0041f397  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0041f39b  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0041f39f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f3a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f3a1  8b7c2448               -mov edi, dword ptr [esp + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0041f3a5  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0041f3a9  6a38                   -push 0x38
    app->getMemory<x86::reg32>(cpu.esp-4) = 56 /*0x38*/;
    cpu.esp -= 4;
    // 0041f3ab  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041f3af  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0041f3b1  6870c84300             -push 0x43c870
    app->getMemory<x86::reg32>(cpu.esp-4) = 4442224 /*0x43c870*/;
    cpu.esp -= 4;
    // 0041f3b6  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041f3ba  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0041f3bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f3bd  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0041f3c1  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0041f3c5  c744243800000000       -mov dword ptr [esp + 0x38], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 0041f3cd  c744243c00000000       -mov dword ptr [esp + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 0041f3d5  c744244000000000       -mov dword ptr [esp + 0x40], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 0041f3dd  e85e060000             -call 0x41fa40
    cpu.esp -= 4;
    sub_41fa40(app, cpu);
    // 0041f3e2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041f3e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f3e7  7547                   -jne 0x41f430
    if (!cpu.flags.zf)
    {
        goto L_0x0041f430;
    }
    // 0041f3e9  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f3ed  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041f3ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f3f0  e81b090000             -call 0x41fd10
    cpu.esp -= 4;
    sub_41fd10(app, cpu);
    // 0041f3f5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041f3f7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041f3fa  83fe01                 +cmp esi, 1
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
    // 0041f3fd  741e                   -je 0x41f41d
    if (cpu.flags.zf)
    {
        goto L_0x0041f41d;
    }
    // 0041f3ff  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f403  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f404  e8770c0000             -call 0x420080
    cpu.esp -= 4;
    sub_420080(app, cpu);
    // 0041f409  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f40c  b8fbffffff             -mov eax, 0xfffffffb
    cpu.eax = 4294967291 /*0xfffffffb*/;
    // 0041f411  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f413  741b                   -je 0x41f430
    if (cpu.flags.zf)
    {
        goto L_0x0041f430;
    }
    // 0041f415  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041f417  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f418  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f419  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0041f41c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f41d:
    // 0041f41d  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041f421  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f425  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f426  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0041f428  e8530c0000             -call 0x420080
    cpu.esp -= 4;
    sub_420080(app, cpu);
    // 0041f42d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f430:
    // 0041f430  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f431  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f432  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0041f435  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41f440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f440  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041f444  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f446  3bc2                   +cmp eax, edx
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
    // 0041f448  7434                   -je 0x41f47e
    if (cpu.flags.zf)
    {
        goto L_0x0041f47e;
    }
    // 0041f44a  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0041f44d  3bca                   +cmp ecx, edx
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
    // 0041f44f  742d                   -je 0x41f47e
    if (cpu.flags.zf)
    {
        goto L_0x0041f47e;
    }
    // 0041f451  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0041f454  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041f457  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0041f45a  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0041f45d  f7da                   +neg edx
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
    // 0041f45f  1bd2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0041f461  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0041f464  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0041f466  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0041f469  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041f46d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f46e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f46f  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0041f472  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f473  e8d8160000             -call 0x420b50
    cpu.esp -= 4;
    sub_420b50(app, cpu);
    // 0041f478  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041f47b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f47d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f47e:
    // 0041f47e  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041f483  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41f490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f490  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f491  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f495  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f497  743d                   -je 0x41f4d6
    if (cpu.flags.zf)
    {
        goto L_0x0041f4d6;
    }
    // 0041f499  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f49c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f49e  7436                   -je 0x41f4d6
    if (cpu.flags.zf)
    {
        goto L_0x0041f4d6;
    }
    // 0041f4a0  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0041f4a3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041f4a5  742f                   -je 0x41f4d6
    if (cpu.flags.zf)
    {
        goto L_0x0041f4d6;
    }
    // 0041f4a7  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0041f4aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f4ac  740f                   -je 0x41f4bd
    if (cpu.flags.zf)
    {
        goto L_0x0041f4bd;
    }
    // 0041f4ae  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f4b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f4b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f4b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f4b5  e856240000             -call 0x421910
    cpu.esp -= 4;
    sub_421910(app, cpu);
    // 0041f4ba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0041f4bd:
    // 0041f4bd  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f4c0  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0041f4c3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f4c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f4c5  ff5624                 -call dword ptr [esi + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041f4c8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041f4cb  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0041f4d2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f4d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f4d6:
    // 0041f4d6  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041f4db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41f4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f4e0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041f4e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f4e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f4e6  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f4e8  3bc7                   +cmp eax, edi
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
    // 0041f4ea  0f84f6000000           -je 0x41f5e6
    if (cpu.flags.zf)
    {
        goto L_0x0041f5e6;
    }
    // 0041f4f0  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0041f4f2  8a0d70c84300           -mov cl, byte ptr [0x43c870]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4442224) /* 0x43c870 */);
    // 0041f4f8  3ac1                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f4fa  0f85e6000000           -jne 0x41f5e6
    if (!cpu.flags.zf)
    {
        goto L_0x0041f5e6;
    }
    // 0041f500  837c241838             +cmp dword ptr [esp + 0x18], 0x38
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f505  0f85db000000           -jne 0x41f5e6
    if (!cpu.flags.zf)
    {
        goto L_0x0041f5e6;
    }
    // 0041f50b  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041f50f  3bf7                   +cmp esi, edi
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
    // 0041f511  7508                   -jne 0x41f51b
    if (!cpu.flags.zf)
    {
        goto L_0x0041f51b;
    }
    // 0041f513  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041f518  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f519  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f51a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f51b:
    // 0041f51b  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0041f51e  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0041f521  3bc7                   +cmp eax, edi
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
    // 0041f523  750a                   -jne 0x41f52f
    if (!cpu.flags.zf)
    {
        goto L_0x0041f52f;
    }
    // 0041f525  c74620801a4200         -mov dword ptr [esi + 0x20], 0x421a80
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 4332160 /*0x421a80*/;
    // 0041f52c  897e28                 -mov dword ptr [esi + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edi;
L_0x0041f52f:
    // 0041f52f  397e24                 +cmp dword ptr [esi + 0x24], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f532  7507                   -jne 0x41f53b
    if (!cpu.flags.zf)
    {
        goto L_0x0041f53b;
    }
    // 0041f534  c74624a01a4200         -mov dword ptr [esi + 0x24], 0x421aa0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 4332192 /*0x421aa0*/;
L_0x0041f53b:
    // 0041f53b  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0041f53e  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0041f540  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041f542  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f543  ff5620                 -call dword ptr [esi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041f546  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041f549  3bc7                   +cmp eax, edi
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
    // 0041f54b  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041f54e  7508                   -jne 0x41f558
    if (!cpu.flags.zf)
    {
        goto L_0x0041f558;
    }
    // 0041f550  b8fcffffff             -mov eax, 0xfffffffc
    cpu.eax = 4294967292 /*0xfffffffc*/;
    // 0041f555  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f556  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f557  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f558:
    // 0041f558  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041f55c  897814                 -mov dword ptr [eax + 0x14], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0041f55f  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f562  3bcf                   +cmp ecx, edi
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
    // 0041f564  897a0c                 -mov dword ptr [edx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0041f567  7d0c                   -jge 0x41f575
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041f575;
    }
    // 0041f569  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f56c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0041f56e  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0041f575:
    // 0041f575  83f908                 +cmp ecx, 8
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
    // 0041f578  7c5b                   -jl 0x41f5d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041f5d5;
    }
    // 0041f57a  83f90f                 +cmp ecx, 0xf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f57d  7f56                   -jg 0x41f5d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041f5d5;
    }
    // 0041f57f  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f582  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041f587  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0041f589  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041f58c  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f58f  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0041f592  f7da                   +neg edx
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
    // 0041f594  1bd2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0041f596  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f597  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 0041f599  81e250194200           -and edx, 0x421950
    cpu.edx &= x86::reg32(x86::sreg32(4331856 /*0x421950*/));
    // 0041f59f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f5a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f5a1  e84a160000             -call 0x420bf0
    cpu.esp -= 4;
    sub_420bf0(app, cpu);
    // 0041f5a6  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f5a9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041f5ac  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041f5af  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f5b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f5b3  397a14                 +cmp dword ptr [edx + 0x14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f5b6  7510                   -jne 0x41f5c8
    if (!cpu.flags.zf)
    {
        goto L_0x0041f5c8;
    }
    // 0041f5b8  e8d3feffff             -call 0x41f490
    cpu.esp -= 4;
    sub_41f490(app, cpu);
    // 0041f5bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f5c0  b8fcffffff             -mov eax, 0xfffffffc
    cpu.eax = 4294967292 /*0xfffffffc*/;
    // 0041f5c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f5c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f5c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f5c8:
    // 0041f5c8  e873feffff             -call 0x41f440
    cpu.esp -= 4;
    sub_41f440(app, cpu);
    // 0041f5cd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f5d0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f5d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f5d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f5d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f5d5:
    // 0041f5d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f5d6  e8b5feffff             -call 0x41f490
    cpu.esp -= 4;
    sub_41f490(app, cpu);
    // 0041f5db  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f5de  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041f5e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f5e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f5e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f5e6:
    // 0041f5e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f5e7  b8faffffff             -mov eax, 0xfffffffa
    cpu.eax = 4294967290 /*0xfffffffa*/;
    // 0041f5ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f5ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41f5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f5f0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041f5f4  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f5f8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041f5fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f5fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f5fe  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0041f600  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f601  e8dafeffff             -call 0x41f4e0
    cpu.esp -= 4;
    sub_41f4e0(app, cpu);
    // 0041f606  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041f609  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41f610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041f610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041f611  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041f612  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f613  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041f617  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f619  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f61a  0f84d3030000           -je 0x41f9f3
    if (cpu.flags.zf)
    {
        goto L_0x0041f9f3;
    }
    // 0041f620  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f623  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f625  0f84c8030000           -je 0x41f9f3
    if (cpu.flags.zf)
    {
        goto L_0x0041f9f3;
    }
    // 0041f62b  833e00                 +cmp dword ptr [esi], 0
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
    // 0041f62e  0f84bf030000           -je 0x41f9f3
    if (cpu.flags.zf)
    {
        goto L_0x0041f9f3;
    }
    // 0041f634  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041f638  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f63a  0f8cb3030000           -jl 0x41f9f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041f9f3;
    }
    // 0041f640  bffbffffff             -mov edi, 0xfffffffb
    cpu.edi = 4294967291 /*0xfffffffb*/;
L_0x0041f645:
    // 0041f645  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
L_0x0041f64a:
    // 0041f64a  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f64d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041f64f  83f90d                 +cmp ecx, 0xd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f652  0f879b030000           -ja 0x41f9f3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041f9f3;
    }
    // 0041f658  ff248d00fa4100         -jmp dword ptr [ecx*4 + 0x41fa00]
    cpu.ip = app->getMemory<x86::reg32>(4323840 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0041f65f:
    // 0041f65f  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f662  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041f664  0f8465030000           -je 0x41f9cf
    if (cpu.flags.zf)
    {
        goto L_0x0041f9cf;
    }
    // 0041f66a  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f66d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f66f  49                     -dec ecx
    (cpu.ecx)--;
    // 0041f670  45                     -inc ebp
    (cpu.ebp)++;
    // 0041f671  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041f674  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f676  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f678  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0041f67b  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041f67d  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041f680  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f683  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f685  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041f688  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0041f68b  45                     -inc ebp
    (cpu.ebp)++;
    // 0041f68c  80f908                 +cmp cl, 8
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f68f  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 0041f691  7415                   -je 0x41f6a8
    if (cpu.flags.zf)
    {
        goto L_0x0041f6a8;
    }
    // 0041f693  c7000d000000           -mov dword ptr [eax], 0xd
    app->getMemory<x86::reg32>(cpu.eax) = 13 /*0xd*/;
    // 0041f699  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f69c  c74618ccc84300         -mov dword ptr [esi + 0x18], 0x43c8cc
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4442316 /*0x43c8cc*/;
    // 0041f6a3  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0041f6a6  eba2                   -jmp 0x41f64a
    goto L_0x0041f64a;
L_0x0041f6a8:
    // 0041f6a8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041f6ab  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0041f6ae  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0041f6b1  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041f6b4  3bca                   +cmp ecx, edx
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
    // 0041f6b6  7618                   -jbe 0x41f6d0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041f6d0;
    }
    // 0041f6b8  c7000d000000           -mov dword ptr [eax], 0xd
    app->getMemory<x86::reg32>(cpu.eax) = 13 /*0xd*/;
    // 0041f6be  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f6c1  c74618b8c84300         -mov dword ptr [esi + 0x18], 0x43c8b8
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4442296 /*0x43c8b8*/;
    // 0041f6c8  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0041f6cb  e97affffff             -jmp 0x41f64a
    goto L_0x0041f64a;
L_0x0041f6d0:
    // 0041f6d0  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
  [[fallthrough]];
  case 0x0041f6d6:
    // 0041f6d6  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f6d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f6db  0f84ee020000           -je 0x41f9cf
    if (cpu.flags.zf)
    {
        goto L_0x0041f9cf;
    }
    // 0041f6e1  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f6e3  48                     -dec eax
    (cpu.eax)--;
    // 0041f6e4  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f6e7  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f6ea  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f6ed  40                     -inc eax
    (cpu.eax)++;
    // 0041f6ee  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041f6f1  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f6f3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f6f5  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f6f7  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0041f6f9  40                     -inc eax
    (cpu.eax)++;
    // 0041f6fa  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041f6fc  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0041f6ff  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0041f702  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f704  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 0041f709  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0041f70b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041f70d  741d                   -je 0x41f72c
    if (cpu.flags.zf)
    {
        goto L_0x0041f72c;
    }
    // 0041f70f  c7030d000000           -mov dword ptr [ebx], 0xd
    app->getMemory<x86::reg32>(cpu.ebx) = 13 /*0xd*/;
    // 0041f715  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f718  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0041f71d  c74618a0c84300         -mov dword ptr [esi + 0x18], 0x43c8a0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4442272 /*0x43c8a0*/;
    // 0041f724  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0041f727  e91effffff             -jmp 0x41f64a
    goto L_0x0041f64a;
L_0x0041f72c:
    // 0041f72c  f6c120                 +test cl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 32 /*0x20*/));
    // 0041f72f  0f8572010000           -jne 0x41f8a7
    if (!cpu.flags.zf)
    {
        goto L_0x0041f8a7;
    }
    // 0041f735  c70307000000           -mov dword ptr [ebx], 7
    app->getMemory<x86::reg32>(cpu.ebx) = 7 /*0x7*/;
    // 0041f73b  e905ffffff             -jmp 0x41f645
    goto L_0x0041f645;
  case 0x0041f740:
    // 0041f740  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0041f743  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f744  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f745  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f746  e815150000             -call 0x420c60
    cpu.esp -= 4;
    sub_420c60(app, cpu);
    // 0041f74b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041f74d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041f750  83fffd                 +cmp edi, -3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f753  7518                   -jne 0x41f76d
    if (!cpu.flags.zf)
    {
        goto L_0x0041f76d;
    }
    // 0041f755  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f758  c7020d000000           -mov dword ptr [edx], 0xd
    app->getMemory<x86::reg32>(cpu.edx) = 13 /*0xd*/;
    // 0041f75e  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f761  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0041f768  e9ddfeffff             -jmp 0x41f64a
    goto L_0x0041f64a;
L_0x0041f76d:
    // 0041f76d  83ff01                 +cmp edi, 1
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
    // 0041f770  0f8559020000           -jne 0x41f9cf
    if (!cpu.flags.zf)
    {
        goto L_0x0041f9cf;
    }
    // 0041f776  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f779  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f77b  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0041f77e  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041f781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f782  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f783  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f784  e8c7130000             -call 0x420b50
    cpu.esp -= 4;
    sub_420b50(app, cpu);
    // 0041f789  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f78c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041f78f  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041f792  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041f794  740b                   -je 0x41f7a1
    if (cpu.flags.zf)
    {
        goto L_0x0041f7a1;
    }
    // 0041f796  c7000c000000           -mov dword ptr [eax], 0xc
    app->getMemory<x86::reg32>(cpu.eax) = 12 /*0xc*/;
    // 0041f79c  e9a9feffff             -jmp 0x41f64a
    goto L_0x0041f64a;
L_0x0041f7a1:
    // 0041f7a1  c70008000000           -mov dword ptr [eax], 8
    app->getMemory<x86::reg32>(cpu.eax) = 8 /*0x8*/;
  [[fallthrough]];
  case 0x0041f7a7:
    // 0041f7a7  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f7aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f7ac  0f841d020000           -je 0x41f9cf
    if (cpu.flags.zf)
    {
        goto L_0x0041f9cf;
    }
    // 0041f7b2  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f7b5  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f7b7  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f7ba  48                     -dec eax
    (cpu.eax)--;
    // 0041f7bb  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f7be  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f7c0  45                     -inc ebp
    (cpu.ebp)++;
    // 0041f7c1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f7c3  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0041f7c6  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0041f7c8  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 0041f7cb  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041f7ce  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f7d0  40                     -inc eax
    (cpu.eax)++;
    // 0041f7d1  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041f7d3  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f7d6  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
  [[fallthrough]];
  case 0x0041f7dc:
    // 0041f7dc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f7df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f7e1  0f84e8010000           -je 0x41f9cf
    if (cpu.flags.zf)
    {
        goto L_0x0041f9cf;
    }
    // 0041f7e7  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f7e9  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f7eb  48                     -dec eax
    (cpu.eax)--;
    // 0041f7ec  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f7ee  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f7f1  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f7f4  40                     -inc eax
    (cpu.eax)++;
    // 0041f7f5  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041f7f8  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f7fb  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041f7fd  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f800  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0041f803  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041f805  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041f808  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f80a  40                     -inc eax
    (cpu.eax)++;
    // 0041f80b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041f80d  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f810  c7000a000000           -mov dword ptr [eax], 0xa
    app->getMemory<x86::reg32>(cpu.eax) = 10 /*0xa*/;
  [[fallthrough]];
  case 0x0041f816:
    // 0041f816  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f819  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f81b  0f84ae010000           -je 0x41f9cf
    if (cpu.flags.zf)
    {
        goto L_0x0041f9cf;
    }
    // 0041f821  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f823  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f825  48                     -dec eax
    (cpu.eax)--;
    // 0041f826  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f828  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f82b  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f82e  40                     -inc eax
    (cpu.eax)++;
    // 0041f82f  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041f832  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f835  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041f837  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f83a  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0041f83d  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041f83f  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041f842  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f844  40                     -inc eax
    (cpu.eax)++;
    // 0041f845  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041f847  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f84a  c7000b000000           -mov dword ptr [eax], 0xb
    app->getMemory<x86::reg32>(cpu.eax) = 11 /*0xb*/;
  [[fallthrough]];
  case 0x0041f850:
    // 0041f850  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f853  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f855  0f8474010000           -je 0x41f9cf
    if (cpu.flags.zf)
    {
        goto L_0x0041f9cf;
    }
    // 0041f85b  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f85e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f860  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f862  48                     -dec eax
    (cpu.eax)--;
    // 0041f863  42                     -inc edx
    (cpu.edx)++;
    // 0041f864  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f867  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f86a  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041f86d  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f86f  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041f871  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f874  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041f876  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041f879  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f87b  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f87e  45                     -inc ebp
    (cpu.ebp)++;
    // 0041f87f  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 0041f881  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041f884  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f887  3bca                   +cmp ecx, edx
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
    // 0041f889  0f8447010000           -je 0x41f9d6
    if (cpu.flags.zf)
    {
        goto L_0x0041f9d6;
    }
    // 0041f88f  c7000d000000           -mov dword ptr [eax], 0xd
    app->getMemory<x86::reg32>(cpu.eax) = 13 /*0xd*/;
    // 0041f895  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f898  c7461888c84300         -mov dword ptr [esi + 0x18], 0x43c888
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4442248 /*0x43c888*/;
    // 0041f89f  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0041f8a2  e9a3fdffff             -jmp 0x41f64a
    goto L_0x0041f64a;
L_0x0041f8a7:
    // 0041f8a7  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f8aa  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0041f8af  c70002000000           -mov dword ptr [eax], 2
    app->getMemory<x86::reg32>(cpu.eax) = 2 /*0x2*/;
  [[fallthrough]];
  case 0x0041f8b5:
    // 0041f8b5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f8b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f8ba  7507                   -jne 0x41f8c3
    if (!cpu.flags.zf)
    {
        goto L_0x0041f8c3;
    }
    // 0041f8bc  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f8be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f8c3:
    // 0041f8c3  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f8c6  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f8c8  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f8ca  48                     -dec eax
    (cpu.eax)--;
    // 0041f8cb  42                     -inc edx
    (cpu.edx)++;
    // 0041f8cc  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f8cf  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f8d2  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041f8d5  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f8d7  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041f8d9  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0041f8dc  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041f8df  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f8e1  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f8e4  40                     -inc eax
    (cpu.eax)++;
    // 0041f8e5  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041f8e7  c70103000000           -mov dword ptr [ecx], 3
    app->getMemory<x86::reg32>(cpu.ecx) = 3 /*0x3*/;
  [[fallthrough]];
  case 0x0041f8ed:
    // 0041f8ed  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f8f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f8f2  7507                   -jne 0x41f8fb
    if (!cpu.flags.zf)
    {
        goto L_0x0041f8fb;
    }
    // 0041f8f4  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f8f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f8fb:
    // 0041f8fb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f8fd  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f8ff  48                     -dec eax
    (cpu.eax)--;
    // 0041f900  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f902  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f905  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f908  40                     -inc eax
    (cpu.eax)++;
    // 0041f909  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041f90c  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f90f  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0041f911  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f914  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0041f917  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f919  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041f91c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f91e  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f921  40                     -inc eax
    (cpu.eax)++;
    // 0041f922  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041f924  c70204000000           -mov dword ptr [edx], 4
    app->getMemory<x86::reg32>(cpu.edx) = 4 /*0x4*/;
  [[fallthrough]];
  case 0x0041f92a:
    // 0041f92a  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f92d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f92f  7507                   -jne 0x41f938
    if (!cpu.flags.zf)
    {
        goto L_0x0041f938;
    }
    // 0041f931  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f933  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f934  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f935  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f936  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f937  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f938:
    // 0041f938  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f93a  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041f93c  48                     -dec eax
    (cpu.eax)--;
    // 0041f93d  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f93f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f942  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f945  40                     -inc eax
    (cpu.eax)++;
    // 0041f946  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041f949  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f94c  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041f94e  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f951  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0041f954  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041f956  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041f959  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f95b  40                     -inc eax
    (cpu.eax)++;
    // 0041f95c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041f95e  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f961  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
  [[fallthrough]];
  case 0x0041f963:
    // 0041f963  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041f966  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f968  7507                   -jne 0x41f971
    if (!cpu.flags.zf)
    {
        goto L_0x0041f971;
    }
    // 0041f96a  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f96c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f96d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f96e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f96f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f970  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f971:
    // 0041f971  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041f974  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f976  48                     -dec eax
    (cpu.eax)--;
    // 0041f977  42                     -inc edx
    (cpu.edx)++;
    // 0041f978  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f97b  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f97e  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041f981  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f983  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041f985  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f988  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041f98a  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041f98d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f98f  40                     -inc eax
    (cpu.eax)++;
    // 0041f990  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041f992  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f995  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f998  894e30                 -mov dword ptr [esi + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0041f99b  c70006000000           -mov dword ptr [eax], 6
    app->getMemory<x86::reg32>(cpu.eax) = 6 /*0x6*/;
    // 0041f9a1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0041f9a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9aa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f9ab:
    // 0041f9ab  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f9ae  c7020d000000           -mov dword ptr [edx], 0xd
    app->getMemory<x86::reg32>(cpu.edx) = 13 /*0xd*/;
    // 0041f9b4  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f9b7  c7461878c84300         -mov dword ptr [esi + 0x18], 0x43c878
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4442232 /*0x43c878*/;
    // 0041f9be  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0041f9c5  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041f9ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f9cf:
    // 0041f9cf  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f9d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f9d6:
    // 0041f9d6  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f9d9  c7010c000000           -mov dword ptr [ecx], 0xc
    app->getMemory<x86::reg32>(cpu.ecx) = 12 /*0xc*/;
  [[fallthrough]];
  case 0x0041f9df:
    // 0041f9df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041f9e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9e8  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f9e9:
    // 0041f9e9  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 0041f9ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f9f3:
    // 0041f9f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9f6  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041f9fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9fc  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_41fa40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fa40  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041fa44  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041fa48  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041fa4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fa4d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041fa51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fa52  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041fa54  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0041fa56  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0041fa58  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0041fa5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041fa5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fa5c  e80f000000             -call 0x41fa70
    cpu.esp -= 4;
    sub_41fa70(app, cpu);
    // 0041fa61  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041fa64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41fa70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fa70  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041fa74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fa75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fa76  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fa78  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0041fa7a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fa7b  3bc2                   +cmp eax, edx
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
    // 0041fa7d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fa7e  0f8401020000           -je 0x41fc85
    if (cpu.flags.zf)
    {
        goto L_0x0041fc85;
    }
    // 0041fa84  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0041fa86  8a0d70c84300           -mov cl, byte ptr [0x43c870]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4442224) /* 0x43c870 */);
    // 0041fa8c  3ac1                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fa8e  0f85f1010000           -jne 0x41fc85
    if (!cpu.flags.zf)
    {
        goto L_0x0041fc85;
    }
    // 0041fa94  837c243038             +cmp dword ptr [esp + 0x30], 0x38
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fa99  0f85e6010000           -jne 0x41fc85
    if (!cpu.flags.zf)
    {
        goto L_0x0041fc85;
    }
    // 0041fa9f  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041faa3  3bfa                   +cmp edi, edx
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
    // 0041faa5  750a                   -jne 0x41fab1
    if (!cpu.flags.zf)
    {
        goto L_0x0041fab1;
    }
    // 0041faa7  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041faac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041faad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041faae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041faaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fab0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fab1:
    // 0041fab1  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0041fab4  895718                 -mov dword ptr [edi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0041fab7  3bc2                   +cmp eax, edx
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
    // 0041fab9  750a                   -jne 0x41fac5
    if (!cpu.flags.zf)
    {
        goto L_0x0041fac5;
    }
    // 0041fabb  c74720801a4200         -mov dword ptr [edi + 0x20], 0x421a80
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = 4332160 /*0x421a80*/;
    // 0041fac2  895728                 -mov dword ptr [edi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.edx;
L_0x0041fac5:
    // 0041fac5  395724                 +cmp dword ptr [edi + 0x24], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fac8  7507                   -jne 0x41fad1
    if (!cpu.flags.zf)
    {
        goto L_0x0041fad1;
    }
    // 0041faca  c74724a01a4200         -mov dword ptr [edi + 0x24], 0x421aa0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = 4332192 /*0x421aa0*/;
L_0x0041fad1:
    // 0041fad1  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041fad5  83f9ff                 +cmp ecx, -1
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
    // 0041fad8  750c                   -jne 0x41fae6
    if (!cpu.flags.zf)
    {
        goto L_0x0041fae6;
    }
    // 0041fada  c744241806000000       -mov dword ptr [esp + 0x18], 6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 6 /*0x6*/;
    // 0041fae2  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0041fae6:
    // 0041fae6  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041faea  3bda                   +cmp ebx, edx
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
    // 0041faec  7d07                   -jge 0x41faf5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041faf5;
    }
    // 0041faee  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0041faf3  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x0041faf5:
    // 0041faf5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041faf9  83f801                 +cmp eax, 1
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
    // 0041fafc  0f8c79010000           -jl 0x41fc7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fc7b;
    }
    // 0041fb02  83f809                 +cmp eax, 9
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
    // 0041fb05  0f8f70010000           -jg 0x41fc7b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041fc7b;
    }
    // 0041fb0b  837c241c08             +cmp dword ptr [esp + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb10  0f8565010000           -jne 0x41fc7b
    if (!cpu.flags.zf)
    {
        goto L_0x0041fc7b;
    }
    // 0041fb16  83fb08                 +cmp ebx, 8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb19  0f8c5c010000           -jl 0x41fc7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fc7b;
    }
    // 0041fb1f  83fb0f                 +cmp ebx, 0xf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb22  0f8f53010000           -jg 0x41fc7b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041fc7b;
    }
    // 0041fb28  3bca                   +cmp ecx, edx
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
    // 0041fb2a  0f8c4b010000           -jl 0x41fc7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fc7b;
    }
    // 0041fb30  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb33  0f8f42010000           -jg 0x41fc7b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041fc7b;
    }
    // 0041fb39  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041fb3d  3bc2                   +cmp eax, edx
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
    // 0041fb3f  0f8c36010000           -jl 0x41fc7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fc7b;
    }
    // 0041fb45  83f802                 +cmp eax, 2
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
    // 0041fb48  0f8f2d010000           -jg 0x41fc7b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041fc7b;
    }
    // 0041fb4e  8b4f28                 -mov ecx, dword ptr [edi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041fb51  68b8160000             -push 0x16b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5816 /*0x16b8*/;
    cpu.esp -= 4;
    // 0041fb56  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fb58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fb59  ff5720                 -call dword ptr [edi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041fb5c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041fb5e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041fb61  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041fb63  750a                   -jne 0x41fb6f
    if (!cpu.flags.zf)
    {
        goto L_0x0041fb6f;
    }
    // 0041fb65  b8fcffffff             -mov eax, 0xfffffffc
    cpu.eax = 4294967292 /*0xfffffffc*/;
    // 0041fb6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fb6f:
    // 0041fb6f  89771c                 -mov dword ptr [edi + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0041fb72  896e14                 -mov dword ptr [esi + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0041fb75  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0041fb78  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0041fb7a  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041fb7e  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0041fb83  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
    // 0041fb85  8d4b07                 -lea ecx, [ebx + 7]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 0041fb88  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041fb8d  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0041fb8f  894e44                 -mov dword ptr [esi + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.ecx;
    // 0041fb92  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0041fb95  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0041fb97  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0041fb9a  8d55ff                 -lea edx, [ebp - 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 0041fb9d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0041fb9f  894640                 -mov dword ptr [esi + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0041fba2  48                     -dec eax
    (cpu.eax)--;
    // 0041fba3  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0041fba6  b8abaaaaaa             -mov eax, 0xaaaaaaab
    cpu.eax = 2863311531 /*0xaaaaaaab*/;
    // 0041fbab  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0041fbae  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0041fbb0  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 0041fbb2  89564c                 -mov dword ptr [esi + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0041fbb5  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041fbb8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fbb9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fbba  ff5720                 -call dword ptr [edi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041fbbd  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0041fbc0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041fbc3  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0041fbc6  8b5728                 -mov edx, dword ptr [edi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041fbc9  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0041fbcb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fbcc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041fbcd  ff5720                 -call dword ptr [edi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041fbd0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041fbd3  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0041fbd6  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041fbd9  8b4f28                 -mov ecx, dword ptr [edi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041fbdc  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0041fbde  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fbdf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fbe0  ff5720                 -call dword ptr [edi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041fbe3  894638                 -mov dword ptr [esi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0041fbe6  8d4b06                 -lea ecx, [ebx + 6]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0041fbe9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041fbee  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041fbf1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0041fbf3  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041fbf5  898690160000           -mov dword ptr [esi + 0x1690], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5776) /* 0x1690 */) = cpu.eax;
    // 0041fbfb  8b5728                 -mov edx, dword ptr [edi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041fbfe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fbff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041fc00  ff5720                 -call dword ptr [edi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041fc03  8b4e2c                 -mov ecx, dword ptr [esi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 0041fc06  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041fc09  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041fc0b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041fc0e  7450                   -je 0x41fc60
    if (cpu.flags.zf)
    {
        goto L_0x0041fc60;
    }
    // 0041fc10  8b4e34                 -mov ecx, dword ptr [esi + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0041fc13  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041fc15  7449                   -je 0x41fc60
    if (cpu.flags.zf)
    {
        goto L_0x0041fc60;
    }
    // 0041fc17  8b4e38                 -mov ecx, dword ptr [esi + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0041fc1a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041fc1c  7442                   -je 0x41fc60
    if (cpu.flags.zf)
    {
        goto L_0x0041fc60;
    }
    // 0041fc1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fc20  743e                   -je 0x41fc60
    if (cpu.flags.zf)
    {
        goto L_0x0041fc60;
    }
    // 0041fc22  8b8e90160000           -mov ecx, dword ptr [esi + 0x1690]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5776) /* 0x1690 */);
    // 0041fc28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fc29  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0041fc2b  c6461908               -mov byte ptr [esi + 0x19], 8
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(25) /* 0x19 */) = 8 /*0x8*/;
    // 0041fc2f  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 0041fc31  8d1450                 -lea edx, [eax + edx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.edx * 2);
    // 0041fc34  8d0448                 -lea eax, [eax + ecx*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 0041fc37  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041fc39  899698160000           -mov dword ptr [esi + 0x1698], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5784) /* 0x1698 */) = cpu.edx;
    // 0041fc3f  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041fc43  898e8c160000           -mov dword ptr [esi + 0x168c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5772) /* 0x168c */) = cpu.ecx;
    // 0041fc49  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041fc4d  89567c                 -mov dword ptr [esi + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0041fc50  894e78                 -mov dword ptr [esi + 0x78], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.ecx;
    // 0041fc53  e838000000             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 0041fc58  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fc5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fc60:
    // 0041fc60  a170ca4300             -mov eax, dword ptr [0x43ca70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4442736) /* 0x43ca70 */);
    // 0041fc65  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fc66  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0041fc69  e812040000             -call 0x420080
    cpu.esp -= 4;
    sub_420080(app, cpu);
    // 0041fc6e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fc71  b8fcffffff             -mov eax, 0xfffffffc
    cpu.eax = 4294967292 /*0xfffffffc*/;
    // 0041fc76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fc7b:
    // 0041fc7b  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041fc80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fc85:
    // 0041fc85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc88  b8faffffff             -mov eax, 0xfffffffa
    cpu.eax = 4294967290 /*0xfffffffa*/;
    // 0041fc8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41fc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fc90  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041fc94  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fc96  3bc1                   +cmp eax, ecx
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
    // 0041fc98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fc99  7464                   -je 0x41fcff
    if (cpu.flags.zf)
    {
        goto L_0x0041fcff;
    }
    // 0041fc9b  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0041fc9e  3bf1                   +cmp esi, ecx
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
    // 0041fca0  745d                   -je 0x41fcff
    if (cpu.flags.zf)
    {
        goto L_0x0041fcff;
    }
    // 0041fca2  394820                 +cmp dword ptr [eax + 0x20], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fca5  7458                   -je 0x41fcff
    if (cpu.flags.zf)
    {
        goto L_0x0041fcff;
    }
    // 0041fca7  394824                 +cmp dword ptr [eax + 0x24], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fcaa  7453                   -je 0x41fcff
    if (cpu.flags.zf)
    {
        goto L_0x0041fcff;
    }
    // 0041fcac  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0041fcaf  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041fcb2  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0041fcb5  c7402c02000000         -mov dword ptr [eax + 0x2c], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 2 /*0x2*/;
    // 0041fcbc  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041fcbf  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041fcc2  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041fcc5  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0041fcc8  3bd1                   +cmp edx, ecx
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
    // 0041fcca  7d03                   -jge 0x41fccf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041fccf;
    }
    // 0041fccc  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x0041fccf:
    // 0041fccf  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0041fcd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fcd3  f7da                   +neg edx
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
    // 0041fcd5  1bd2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0041fcd7  83e247                 -and edx, 0x47
    cpu.edx &= x86::reg32(x86::sreg32(71 /*0x47*/));
    // 0041fcda  83c22a                 -add edx, 0x2a
    (cpu.edx) += x86::reg32(x86::sreg32(42 /*0x2a*/));
    // 0041fcdd  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041fce0  c7403001000000         -mov dword ptr [eax + 0x30], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 0041fce7  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041fcea  e8c11d0000             -call 0x421ab0
    cpu.esp -= 4;
    sub_421ab0(app, cpu);
    // 0041fcef  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fcf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fcf3  e818040000             -call 0x420110
    cpu.esp -= 4;
    sub_420110(app, cpu);
    // 0041fcf8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fcfb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fcfd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fcff:
    // 0041fcff  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041fd04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41fd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fd10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fd11  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041fd15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fd16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fd17  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0041fd19  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fd1a  0f849c020000           -je 0x41ffbc
    if (cpu.flags.zf)
    {
        goto L_0x0041ffbc;
    }
    // 0041fd20  8b731c                 -mov esi, dword ptr [ebx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0041fd23  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041fd25  0f8491020000           -je 0x41ffbc
    if (cpu.flags.zf)
    {
        goto L_0x0041ffbc;
    }
    // 0041fd2b  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041fd2f  83fd04                 +cmp ebp, 4
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd32  0f8f84020000           -jg 0x41ffbc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041ffbc;
    }
    // 0041fd38  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041fd3a  0f8c7c020000           -jl 0x41ffbc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ffbc;
    }
    // 0041fd40  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0041fd43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fd45  0f8468020000           -je 0x41ffb3
    if (cpu.flags.zf)
    {
        goto L_0x0041ffb3;
    }
    // 0041fd4b  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd4e  750b                   -jne 0x41fd5b
    if (!cpu.flags.zf)
    {
        goto L_0x0041fd5b;
    }
    // 0041fd50  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0041fd53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fd55  0f8558020000           -jne 0x41ffb3
    if (!cpu.flags.zf)
    {
        goto L_0x0041ffb3;
    }
L_0x0041fd5b:
    // 0041fd5b  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041fd5e  3d9a020000             +cmp eax, 0x29a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(666 /*0x29a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd63  7509                   -jne 0x41fd6e
    if (!cpu.flags.zf)
    {
        goto L_0x0041fd6e;
    }
    // 0041fd65  83fd04                 +cmp ebp, 4
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd68  0f8545020000           -jne 0x41ffb3
    if (!cpu.flags.zf)
    {
        goto L_0x0041ffb3;
    }
L_0x0041fd6e:
    // 0041fd6e  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0041fd71  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041fd73  7512                   -jne 0x41fd87
    if (!cpu.flags.zf)
    {
        goto L_0x0041fd87;
    }
    // 0041fd75  a174ca4300             -mov eax, dword ptr [0x43ca74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4442740) /* 0x43ca74 */);
    // 0041fd7a  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0041fd7d  b8fbffffff             -mov eax, 0xfffffffb
    cpu.eax = 4294967291 /*0xfffffffb*/;
    // 0041fd82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fd87:
    // 0041fd87  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041fd8a  83f82a                 +cmp eax, 0x2a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd8d  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0041fd8f  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0041fd93  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0041fd96  757b                   -jne 0x41fe13
    if (!cpu.flags.zf)
    {
        goto L_0x0041fe13;
    }
    // 0041fd98  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0041fd9b  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0041fd9e  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 0041fda1  81e900780000           -sub ecx, 0x7800
    (cpu.ecx) -= x86::reg32(x86::sreg32(30720 /*0x7800*/));
    // 0041fda7  48                     -dec eax
    (cpu.eax)--;
    // 0041fda8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0041fdaa  83f803                 +cmp eax, 3
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
    // 0041fdad  7605                   -jbe 0x41fdb4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041fdb4;
    }
    // 0041fdaf  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x0041fdb4:
    // 0041fdb4  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0041fdb7  0bc8                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fdb9  8b4660                 -mov eax, dword ptr [esi + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 0041fdbc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fdbe  7403                   -je 0x41fdc3
    if (cpu.flags.zf)
    {
        goto L_0x0041fdc3;
    }
    // 0041fdc0  83c920                 -or ecx, 0x20
    cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0041fdc3:
    // 0041fdc3  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041fdc5  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fdc7  bf1f000000             -mov edi, 0x1f
    cpu.edi = 31 /*0x1f*/;
    // 0041fdcc  c7460471000000         -mov dword ptr [esi + 4], 0x71
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 113 /*0x71*/;
    // 0041fdd3  f7f7                   -div edi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.edi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0041fdd5  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fdd7  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0041fdd9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fdda  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fddb  e8f0010000             -call 0x41ffd0
    cpu.esp -= 4;
    sub_41ffd0(app, cpu);
    // 0041fde0  8b4660                 -mov eax, dword ptr [esi + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 0041fde3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041fde6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fde8  7422                   -je 0x41fe0c
    if (cpu.flags.zf)
    {
        goto L_0x0041fe0c;
    }
    // 0041fdea  8b5330                 -mov edx, dword ptr [ebx + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0041fded  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0041fdf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041fdf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fdf2  e8d9010000             -call 0x41ffd0
    cpu.esp -= 4;
    sub_41ffd0(app, cpu);
    // 0041fdf7  8b4330                 -mov eax, dword ptr [ebx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0041fdfa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041fdfd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041fe02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fe03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fe04  e8c7010000             -call 0x41ffd0
    cpu.esp -= 4;
    sub_41ffd0(app, cpu);
    // 0041fe09  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041fe0c:
    // 0041fe0c  c7433001000000         -mov dword ptr [ebx + 0x30], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
L_0x0041fe13:
    // 0041fe13  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0041fe16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fe18  741e                   -je 0x41fe38
    if (cpu.flags.zf)
    {
        goto L_0x0041fe38;
    }
    // 0041fe1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fe1b  e8e0010000             -call 0x420000
    cpu.esp -= 4;
    sub_420000(app, cpu);
    // 0041fe20  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0041fe23  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fe26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fe28  7533                   -jne 0x41fe5d
    if (!cpu.flags.zf)
    {
        goto L_0x0041fe5d;
    }
    // 0041fe2a  c7461cffffffff         -mov dword ptr [esi + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
    // 0041fe31  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fe33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fe38:
    // 0041fe38  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0041fe3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fe3d  751e                   -jne 0x41fe5d
    if (!cpu.flags.zf)
    {
        goto L_0x0041fe5d;
    }
    // 0041fe3f  3b6c2414               +cmp ebp, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fe43  7f18                   -jg 0x41fe5d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041fe5d;
    }
    // 0041fe45  83fd04                 +cmp ebp, 4
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fe48  7413                   -je 0x41fe5d
    if (cpu.flags.zf)
    {
        goto L_0x0041fe5d;
    }
    // 0041fe4a  8b0d74ca4300           -mov ecx, dword ptr [0x43ca74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4442740) /* 0x43ca74 */);
    // 0041fe50  b8fbffffff             -mov eax, 0xfffffffb
    cpu.eax = 4294967291 /*0xfffffffb*/;
    // 0041fe55  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0041fe58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fe5d:
    // 0041fe5d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041fe60  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0041fe63  3d9a020000             +cmp eax, 0x29a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(666 /*0x29a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fe68  7517                   -jne 0x41fe81
    if (!cpu.flags.zf)
    {
        goto L_0x0041fe81;
    }
    // 0041fe6a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041fe6c  7417                   -je 0x41fe85
    if (cpu.flags.zf)
    {
        goto L_0x0041fe85;
    }
    // 0041fe6e  8b1574ca4300           -mov edx, dword ptr [0x43ca74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4442740) /* 0x43ca74 */);
    // 0041fe74  b8fbffffff             -mov eax, 0xfffffffb
    cpu.eax = 4294967291 /*0xfffffffb*/;
    // 0041fe79  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0041fe7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe7e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fe81:
    // 0041fe81  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041fe83  751a                   -jne 0x41fe9f
    if (!cpu.flags.zf)
    {
        goto L_0x0041fe9f;
    }
L_0x0041fe85:
    // 0041fe85  8b4e68                 -mov ecx, dword ptr [esi + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 0041fe88  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041fe8a  7513                   -jne 0x41fe9f
    if (!cpu.flags.zf)
    {
        goto L_0x0041fe9f;
    }
    // 0041fe8c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041fe8e  0f84ab000000           -je 0x41ff3f
    if (cpu.flags.zf)
    {
        goto L_0x0041ff3f;
    }
    // 0041fe94  3d9a020000             +cmp eax, 0x29a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(666 /*0x29a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fe99  0f84a0000000           -je 0x41ff3f
    if (cpu.flags.zf)
    {
        goto L_0x0041ff3f;
    }
L_0x0041fe9f:
    // 0041fe9f  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0041fea2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fea4  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041fea7  ff148528c94300         -call dword ptr [eax*4 + 0x43c928]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4442408) /* 0x43c928 */ + cpu.eax * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041feae  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041feb1  83f802                 +cmp eax, 2
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
    // 0041feb4  7405                   -je 0x41febb
    if (cpu.flags.zf)
    {
        goto L_0x0041febb;
    }
    // 0041feb6  83f803                 +cmp eax, 3
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
    // 0041feb9  7507                   -jne 0x41fec2
    if (!cpu.flags.zf)
    {
        goto L_0x0041fec2;
    }
L_0x0041febb:
    // 0041febb  c746049a020000         -mov dword ptr [esi + 4], 0x29a
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 666 /*0x29a*/;
L_0x0041fec2:
    // 0041fec2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fec4  0f84d4000000           -je 0x41ff9e
    if (cpu.flags.zf)
    {
        goto L_0x0041ff9e;
    }
    // 0041feca  83f802                 +cmp eax, 2
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
    // 0041fecd  0f84cb000000           -je 0x41ff9e
    if (cpu.flags.zf)
    {
        goto L_0x0041ff9e;
    }
    // 0041fed3  83f801                 +cmp eax, 1
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
    // 0041fed6  7567                   -jne 0x41ff3f
    if (!cpu.flags.zf)
    {
        goto L_0x0041ff3f;
    }
    // 0041fed8  3be8                   +cmp ebp, eax
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
    // 0041feda  750b                   -jne 0x41fee7
    if (!cpu.flags.zf)
    {
        goto L_0x0041fee7;
    }
    // 0041fedc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fedd  e8ee1f0000             -call 0x421ed0
    cpu.esp -= 4;
    sub_421ed0(app, cpu);
    // 0041fee2  83c404                 +add esp, 4
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
    // 0041fee5  eb3a                   -jmp 0x41ff21
    goto L_0x0041ff21;
L_0x0041fee7:
    // 0041fee7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041fee9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041feeb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041feed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041feee  e81d1f0000             -call 0x421e10
    cpu.esp -= 4;
    sub_421e10(app, cpu);
    // 0041fef3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041fef6  83fd03                 +cmp ebp, 3
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
    // 0041fef9  7526                   -jne 0x41ff21
    if (!cpu.flags.zf)
    {
        goto L_0x0041ff21;
    }
    // 0041fefb  8b4e40                 -mov ecx, dword ptr [esi + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041fefe  8b5638                 -mov edx, dword ptr [esi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0041ff01  66c7444afe0000         -mov word ptr [edx + ecx*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 2) = 0 /*0x0*/;
    // 0041ff08  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041ff0b  8b7e38                 -mov edi, dword ptr [esi + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0041ff0e  8d4c00fe               -lea ecx, [eax + eax - 2]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1);
    // 0041ff12  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ff14  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0041ff16  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0041ff19  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0041ff1b  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041ff1d  23cd                   -and ecx, ebp
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.ebp));
    // 0041ff1f  f3aa                   -rep stosb byte ptr es:[edi], al
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
L_0x0041ff21:
    // 0041ff21  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ff22  e8d9000000             -call 0x420000
    cpu.esp -= 4;
    sub_420000(app, cpu);
    // 0041ff27  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0041ff2a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ff2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ff2f  750e                   -jne 0x41ff3f
    if (!cpu.flags.zf)
    {
        goto L_0x0041ff3f;
    }
    // 0041ff31  c7461cffffffff         -mov dword ptr [esi + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
    // 0041ff38  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ff3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff3c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff3e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ff3f:
    // 0041ff3f  83fd04                 +cmp ebp, 4
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff42  7407                   -je 0x41ff4b
    if (cpu.flags.zf)
    {
        goto L_0x0041ff4b;
    }
    // 0041ff44  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ff46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ff4b:
    // 0041ff4b  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0041ff4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ff50  740a                   -je 0x41ff5c
    if (cpu.flags.zf)
    {
        goto L_0x0041ff5c;
    }
    // 0041ff52  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041ff57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff5b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ff5c:
    // 0041ff5c  8b4330                 -mov eax, dword ptr [ebx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0041ff5f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0041ff62  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ff63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ff64  e867000000             -call 0x41ffd0
    cpu.esp -= 4;
    sub_41ffd0(app, cpu);
    // 0041ff69  8b4b30                 -mov ecx, dword ptr [ebx + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0041ff6c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ff6f  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041ff75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ff76  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ff77  e854000000             -call 0x41ffd0
    cpu.esp -= 4;
    sub_41ffd0(app, cpu);
    // 0041ff7c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ff7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ff80  e87b000000             -call 0x420000
    cpu.esp -= 4;
    sub_420000(app, cpu);
    // 0041ff85  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0041ff88  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ff8b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ff8d  c74614ffffffff         -mov dword ptr [esi + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
    // 0041ff94  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041ff96  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0041ff99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ff9e:
    // 0041ff9e  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0041ffa1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ffa3  7507                   -jne 0x41ffac
    if (!cpu.flags.zf)
    {
        goto L_0x0041ffac;
    }
    // 0041ffa5  c7461cffffffff         -mov dword ptr [esi + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
L_0x0041ffac:
    // 0041ffac  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ffae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ffb3:
    // 0041ffb3  8b1568ca4300           -mov edx, dword ptr [0x43ca68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4442728) /* 0x43ca68 */);
    // 0041ffb9  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0041ffbc:
    // 0041ffbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffbf  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0041ffc4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41ffc6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ffc6  90                     -nop 
    ;
    return sub_41ffc7(app, cpu);
}

/* align: skip  */
void Application::asm_sub_41ffc7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ffc7  90                     -nop 
    ;
    return sub_41ffc8(app, cpu);
}

/* align: skip  */
void Application::asm_sub_41ffc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ffc8  90                     -nop 
    ;
    // 0041ffc9  90                     -nop 
    ;
    // 0041ffca  90                     -nop 
    ;
    // 0041ffcb  90                     -nop 
    ;
    // 0041ffcc  90                     -nop 
    ;
    // 0041ffcd  90                     -nop 
    ;
    // 0041ffce  90                     -nop 
    ;
    // 0041ffcf  90                     -nop 
    ;
    return sub_41ffd0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_41ffd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ffd0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041ffd4  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ffd8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ffd9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ffda  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041ffdd  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0041ffe0  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0041ffe2  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0041ffe5  88143e                 -mov byte ptr [esi + edi], dl
    app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1) = cpu.dl;
    // 0041ffe8  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0041ffeb  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041ffee  42                     -inc edx
    (cpu.edx)++;
    // 0041ffef  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0041fff2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fff3  880c16                 -mov byte ptr [esi + edx], cl
    app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 1) = cpu.cl;
    // 0041fff6  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0041fff9  41                     -inc ecx
    (cpu.ecx)++;
    // 0041fffa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fffb  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041fffe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_420000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420000  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420004  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420005  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420006  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420007  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0042000a  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0042000d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00420010  3bd1                   +cmp edx, ecx
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
    // 00420012  7602                   -jbe 0x420016
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420016;
    }
    // 00420014  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00420016:
    // 00420016  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420018  7454                   -je 0x42006e
    if (cpu.flags.zf)
    {
        goto L_0x0042006e;
    }
    // 0042001a  8b760c                 -mov esi, dword ptr [esi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042001d  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00420020  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00420022  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00420024  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00420027  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00420029  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042002b  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042002e  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00420030  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00420033  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00420036  03fa                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00420038  89780c                 -mov dword ptr [eax + 0xc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0042003b  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042003e  03f2                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00420040  89710c                 -mov dword ptr [ecx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00420043  8b5814                 -mov ebx, dword ptr [eax + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00420046  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00420049  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0042004c  03da                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0042004e  2bfa                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00420050  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00420053  897810                 -mov dword ptr [eax + 0x10], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00420056  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00420059  2bf2                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042005b  897110                 -mov dword ptr [ecx + 0x10], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0042005e  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00420061  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00420064  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00420066  7506                   -jne 0x42006e
    if (!cpu.flags.zf)
    {
        goto L_0x0042006e;
    }
    // 00420068  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042006b  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x0042006e:
    // 0042006e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042006f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420070  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420071  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_420079(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420079  90                     -nop 
    ;
    // 0042007a  90                     -nop 
    ;
    // 0042007b  90                     -nop 
    ;
    // 0042007c  90                     -nop 
    ;
    // 0042007d  90                     -nop 
    ;
    // 0042007e  90                     -nop 
    ;
    return sub_42007f(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42007f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042007f  90                     -nop 
    ;
    return sub_420080(app, cpu);
}

/* align: skip  */
void Application::asm_sub_420080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420080  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420081  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00420085  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00420087  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420088  747e                   -je 0x420108
    if (cpu.flags.zf)
    {
        goto L_0x00420108;
    }
    // 0042008a  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0042008d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042008f  7477                   -je 0x420108
    if (cpu.flags.zf)
    {
        goto L_0x00420108;
    }
    // 00420091  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00420094  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420096  740b                   -je 0x4200a3
    if (cpu.flags.zf)
    {
        goto L_0x004200a3;
    }
    // 00420098  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420099  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0042009c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042009d  ff5624                 -call dword ptr [esi + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004200a0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004200a3:
    // 004200a3  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004200a6  8b4138                 -mov eax, dword ptr [ecx + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004200a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004200ab  740b                   -je 0x4200b8
    if (cpu.flags.zf)
    {
        goto L_0x004200b8;
    }
    // 004200ad  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004200b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004200b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004200b2  ff5624                 -call dword ptr [esi + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004200b5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004200b8:
    // 004200b8  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004200bb  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004200be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004200c0  740b                   -je 0x4200cd
    if (cpu.flags.zf)
    {
        goto L_0x004200cd;
    }
    // 004200c2  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004200c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004200c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004200c7  ff5624                 -call dword ptr [esi + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004200ca  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004200cd:
    // 004200cd  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004200d0  8b422c                 -mov eax, dword ptr [edx + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004200d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004200d5  740b                   -je 0x4200e2
    if (cpu.flags.zf)
    {
        goto L_0x004200e2;
    }
    // 004200d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004200d8  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004200db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004200dc  ff5624                 -call dword ptr [esi + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004200df  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004200e2:
    // 004200e2  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004200e5  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004200e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004200e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004200ea  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004200ed  ff5624                 -call dword ptr [esi + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004200f0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004200f3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004200f5  83ff71                 +cmp edi, 0x71
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(113 /*0x71*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004200f8  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004200ff  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00420102  48                     -dec eax
    (cpu.eax)--;
    // 00420103  24fd                   -and al, 0xfd
    cpu.al &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00420105  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420106  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420107  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420108:
    // 00420108  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420109  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0042010e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042010f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_420110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420110  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420114  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420115  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420116  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00420118  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0042011b  8b4a40                 -mov ecx, dword ptr [edx + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 0042011e  d1e0                   -shl eax, 1
    cpu.eax <<= 1 /*0x1*/ % 32;
    // 00420120  894230                 -mov dword ptr [edx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00420123  8b4238                 -mov eax, dword ptr [edx + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 00420126  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420127  66897448fe             -mov word ptr [eax + ecx*2 - 2], si
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 2) = cpu.si;
    // 0042012c  8b4a40                 -mov ecx, dword ptr [edx + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 0042012f  8b7a38                 -mov edi, dword ptr [edx + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 00420132  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420134  8d4c09fe               -lea ecx, [ecx + ecx - 2]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 1);
    // 00420138  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042013a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042013d  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042013f  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00420141  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00420144  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 00420146  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 00420149  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042014b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042014c  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0042014f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00420152  668b8822c94300         -mov cx, word ptr [eax + 0x43c922]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4442402) /* 0x43c922 */);
    // 00420159  894a74                 -mov dword ptr [edx + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 0042015c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042015e  668b8820c94300         -mov cx, word ptr [eax + 0x43c920]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4442400) /* 0x43c920 */);
    // 00420165  898a80000000           -mov dword ptr [edx + 0x80], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */) = cpu.ecx;
    // 0042016b  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042016d  668b8824c94300         -mov cx, word ptr [eax + 0x43c924]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4442404) /* 0x43c924 */);
    // 00420174  898a84000000           -mov dword ptr [edx + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0042017a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042017c  668b8826c94300         -mov cx, word ptr [eax + 0x43c926]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4442406) /* 0x43c926 */);
    // 00420183  897260                 -mov dword ptr [edx + 0x60], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = cpu.esi;
    // 00420186  897250                 -mov dword ptr [edx + 0x50], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.esi;
    // 00420189  897268                 -mov dword ptr [edx + 0x68], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(104) /* 0x68 */) = cpu.esi;
    // 0042018c  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00420191  89725c                 -mov dword ptr [edx + 0x5c], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */) = cpu.esi;
    // 00420194  89723c                 -mov dword ptr [edx + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 00420197  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420198  894a70                 -mov dword ptr [edx + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 0042019b  89426c                 -mov dword ptr [edx + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0042019e  894254                 -mov dword ptr [edx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 004201a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004201a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
