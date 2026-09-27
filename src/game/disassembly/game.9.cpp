#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_42ddc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ddc0  8b8190000000           -mov eax, dword ptr [ecx + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */);
    // 0042ddc6  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042ddc9  8b818c000000           -mov eax, dword ptr [ecx + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0042ddcf  40                     -inc eax
    (cpu.eax)++;
    // 0042ddd0  899190000000           -mov dword ptr [ecx + 0x90], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 0042ddd6  89818c000000           -mov dword ptr [ecx + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0042dddc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42dde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dde0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042dde4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042dde6  740a                   -je 0x42ddf2
    if (cpu.flags.zf)
    {
        goto L_0x0042ddf2;
    }
    // 0042dde8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dde9  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042ddec  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0042ddef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ddf0  eb09                   -jmp 0x42ddfb
    goto L_0x0042ddfb;
L_0x0042ddf2:
    // 0042ddf2  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042ddf5  899190000000           -mov dword ptr [ecx + 0x90], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.edx;
L_0x0042ddfb:
    // 0042ddfb  8b918c000000           -mov edx, dword ptr [ecx + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0042de01  4a                     -dec edx
    (cpu.edx)--;
    // 0042de02  89918c000000           -mov dword ptr [ecx + 0x8c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */) = cpu.edx;
    // 0042de08  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0042de0f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42de20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042de20  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042de21  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0042de23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042de24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042de25  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042de27  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042de29  0f84b6000000           -je 0x42dee5
    if (cpu.flags.zf)
    {
        goto L_0x0042dee5;
    }
    // 0042de2f  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0042de35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042de37  750d                   -jne 0x42de46
    if (!cpu.flags.zf)
    {
        goto L_0x0042de46;
    }
    // 0042de39  6880704900             -push 0x497080
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812928 /*0x497080*/;
    cpu.esp -= 4;
    // 0042de3e  e8cd6dffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042de43  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042de46:
    // 0042de46  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0042de4c  8bb884020000           -mov edi, dword ptr [eax + 0x284]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(644) /* 0x284 */);
    // 0042de52  83ffff                 +cmp edi, -1
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
    // 0042de55  0f848a000000           -je 0x42dee5
    if (cpu.flags.zf)
    {
        goto L_0x0042dee5;
    }
    // 0042de5b  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042de61  8b04b9                 -mov eax, dword ptr [ecx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edi * 4);
    // 0042de64  8a88e0020000           -mov cl, byte ptr [eax + 0x2e0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(736) /* 0x2e0 */);
    // 0042de6a  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042de6c  7477                   -je 0x42dee5
    if (cpu.flags.zf)
    {
        goto L_0x0042dee5;
    }
    // 0042de6e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042de70  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0042de76  7e6d                   -jle 0x42dee5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042dee5;
    }
    // 0042de78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042de79  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x0042de7d:
    // 0042de7d  8b90e4020000           -mov edx, dword ptr [eax + 0x2e4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(740) /* 0x2e4 */);
    // 0042de83  833cb200               +cmp dword ptr [edx + esi*4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042de87  750e                   -jne 0x42de97
    if (!cpu.flags.zf)
    {
        goto L_0x0042de97;
    }
    // 0042de89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042de8a  684c704900             -push 0x49704c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812876 /*0x49704c*/;
    cpu.esp -= 4;
    // 0042de8f  e87c6dffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042de94  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0042de97:
    // 0042de97  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042de9c  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0042de9f  8b91e4020000           -mov edx, dword ptr [ecx + 0x2e4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(740) /* 0x2e4 */);
    // 0042dea5  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042dea8  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042deaa  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042deac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042dead  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042deaf  e82cfeffff             -call 0x42dce0
    cpu.esp -= 4;
    sub_42dce0(app, cpu);
    // 0042deb4  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042deba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042debb  8b04ba                 -mov eax, dword ptr [edx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 0042debe  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042dec0  8b88e4020000           -mov ecx, dword ptr [eax + 0x2e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(740) /* 0x2e4 */);
    // 0042dec6  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042dec9  e822000000             -call 0x42def0
    cpu.esp -= 4;
    sub_42def0(app, cpu);
    // 0042dece  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042ded4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042ded6  46                     -inc esi
    (cpu.esi)++;
    // 0042ded7  8b04ba                 -mov eax, dword ptr [edx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 0042deda  8a88e0020000           -mov cl, byte ptr [eax + 0x2e0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(736) /* 0x2e0 */);
    // 0042dee0  3bf1                   +cmp esi, ecx
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
    // 0042dee2  7c99                   -jl 0x42de7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042de7d;
    }
    // 0042dee4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042dee5:
    // 0042dee5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dee6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dee7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dee8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42def0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042def0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042def4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042def5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042def6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042def7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042def9  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042defb  3bc7                   +cmp eax, edi
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
    // 0042defd  744a                   -je 0x42df49
    if (cpu.flags.zf)
    {
        goto L_0x0042df49;
    }
    // 0042deff  8a85e0020000           -mov al, byte ptr [ebp + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(736) /* 0x2e0 */);
    // 0042df05  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042df07  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042df09  763e                   -jbe 0x42df49
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042df49;
    }
    // 0042df0b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042df0c:
    // 0042df0c  8b85e4020000           -mov eax, dword ptr [ebp + 0x2e4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(740) /* 0x2e4 */);
    // 0042df12  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042df16  8b3498                 -mov esi, dword ptr [eax + ebx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 0042df19  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042df1b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042df1c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042df1e  e8bdfdffff             -call 0x42dce0
    cpu.esp -= 4;
    sub_42dce0(app, cpu);
    // 0042df23  8a86e0020000           -mov al, byte ptr [esi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(736) /* 0x2e0 */);
    // 0042df29  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042df2b  740e                   -je 0x42df3b
    if (cpu.flags.zf)
    {
        goto L_0x0042df3b;
    }
    // 0042df2d  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042df31  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042df33  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042df34  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042df36  e8b5ffffff             -call 0x42def0
    cpu.esp -= 4;
    sub_42def0(app, cpu);
L_0x0042df3b:
    // 0042df3b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042df3d  43                     -inc ebx
    (cpu.ebx)++;
    // 0042df3e  8a85e0020000           -mov al, byte ptr [ebp + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(736) /* 0x2e0 */);
    // 0042df44  3bd8                   +cmp ebx, eax
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
    // 0042df46  7cc4                   -jl 0x42df0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042df0c;
    }
    // 0042df48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042df49:
    // 0042df49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042df4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042df4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042df4c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42df50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042df50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042df51  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042df53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042df54  6818724900             -push 0x497218
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813336 /*0x497218*/;
    cpu.esp -= 4;
    // 0042df59  e8526c0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042df5e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042df61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042df63  7507                   -jne 0x42df6c
    if (!cpu.flags.zf)
    {
        goto L_0x0042df6c;
    }
    // 0042df65  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042df6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042df6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042df6c:
    // 0042df6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042df6d  6808724900             -push 0x497208
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813320 /*0x497208*/;
    cpu.esp -= 4;
    // 0042df72  e8396c0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042df77  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042df7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042df7c  7507                   -jne 0x42df85
    if (!cpu.flags.zf)
    {
        goto L_0x0042df85;
    }
    // 0042df7e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0042df83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042df84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042df85:
    // 0042df85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042df86  68f8714900             -push 0x4971f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813304 /*0x4971f8*/;
    cpu.esp -= 4;
    // 0042df8b  e8206c0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042df90  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042df93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042df95  7507                   -jne 0x42df9e
    if (!cpu.flags.zf)
    {
        goto L_0x0042df9e;
    }
    // 0042df97  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0042df9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042df9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042df9e:
    // 0042df9e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042df9f  68ec714900             -push 0x4971ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813292 /*0x4971ec*/;
    cpu.esp -= 4;
    // 0042dfa4  e8076c0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042dfa9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042dfac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dfae  7502                   -jne 0x42dfb2
    if (!cpu.flags.zf)
    {
        goto L_0x0042dfb2;
    }
    // 0042dfb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dfb1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042dfb2:
    // 0042dfb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dfb3  68dc714900             -push 0x4971dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813276 /*0x4971dc*/;
    cpu.esp -= 4;
    // 0042dfb8  e8f36b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042dfbd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042dfc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dfc2  7507                   -jne 0x42dfcb
    if (!cpu.flags.zf)
    {
        goto L_0x0042dfcb;
    }
    // 0042dfc4  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0042dfc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dfca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042dfcb:
    // 0042dfcb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dfcc  68cc714900             -push 0x4971cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813260 /*0x4971cc*/;
    cpu.esp -= 4;
    // 0042dfd1  e8da6b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042dfd6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042dfd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dfdb  7507                   -jne 0x42dfe4
    if (!cpu.flags.zf)
    {
        goto L_0x0042dfe4;
    }
    // 0042dfdd  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0042dfe2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dfe3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042dfe4:
    // 0042dfe4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dfe5  68c0714900             -push 0x4971c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813248 /*0x4971c0*/;
    cpu.esp -= 4;
    // 0042dfea  e8c16b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042dfef  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042dff2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dff4  7507                   -jne 0x42dffd
    if (!cpu.flags.zf)
    {
        goto L_0x0042dffd;
    }
    // 0042dff6  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0042dffb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dffc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042dffd:
    // 0042dffd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dffe  68b4714900             -push 0x4971b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813236 /*0x4971b4*/;
    cpu.esp -= 4;
    // 0042e003  e8a86b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e008  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e00b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e00d  7507                   -jne 0x42e016
    if (!cpu.flags.zf)
    {
        goto L_0x0042e016;
    }
    // 0042e00f  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0042e014  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e015  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e016:
    // 0042e016  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e017  68a4714900             -push 0x4971a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813220 /*0x4971a4*/;
    cpu.esp -= 4;
    // 0042e01c  e88f6b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e021  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e024  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e026  7507                   -jne 0x42e02f
    if (!cpu.flags.zf)
    {
        goto L_0x0042e02f;
    }
    // 0042e028  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0042e02d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e02e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e02f:
    // 0042e02f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e030  6894714900             -push 0x497194
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813204 /*0x497194*/;
    cpu.esp -= 4;
    // 0042e035  e8766b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e03a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e03d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e03f  7507                   -jne 0x42e048
    if (!cpu.flags.zf)
    {
        goto L_0x0042e048;
    }
    // 0042e041  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0042e046  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e047  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e048:
    // 0042e048  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e049  6884714900             -push 0x497184
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813188 /*0x497184*/;
    cpu.esp -= 4;
    // 0042e04e  e85d6b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e053  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e056  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e058  7507                   -jne 0x42e061
    if (!cpu.flags.zf)
    {
        goto L_0x0042e061;
    }
    // 0042e05a  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0042e05f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e060  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e061:
    // 0042e061  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e062  6874714900             -push 0x497174
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813172 /*0x497174*/;
    cpu.esp -= 4;
    // 0042e067  e8446b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e06c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e06f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e071  7507                   -jne 0x42e07a
    if (!cpu.flags.zf)
    {
        goto L_0x0042e07a;
    }
    // 0042e073  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0042e078  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e079  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e07a:
    // 0042e07a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e07b  6864714900             -push 0x497164
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813156 /*0x497164*/;
    cpu.esp -= 4;
    // 0042e080  e82b6b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e085  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e088  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e08a  7507                   -jne 0x42e093
    if (!cpu.flags.zf)
    {
        goto L_0x0042e093;
    }
    // 0042e08c  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0042e091  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e092  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e093:
    // 0042e093  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e094  6854714900             -push 0x497154
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813140 /*0x497154*/;
    cpu.esp -= 4;
    // 0042e099  e8126b0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e09e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e0a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e0a3  7507                   -jne 0x42e0ac
    if (!cpu.flags.zf)
    {
        goto L_0x0042e0ac;
    }
    // 0042e0a5  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0042e0aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e0ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e0ac:
    // 0042e0ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e0ad  6844714900             -push 0x497144
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813124 /*0x497144*/;
    cpu.esp -= 4;
    // 0042e0b2  e8f96a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e0b7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e0ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e0bc  7507                   -jne 0x42e0c5
    if (!cpu.flags.zf)
    {
        goto L_0x0042e0c5;
    }
    // 0042e0be  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0042e0c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e0c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e0c5:
    // 0042e0c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e0c6  6834714900             -push 0x497134
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813108 /*0x497134*/;
    cpu.esp -= 4;
    // 0042e0cb  e8e06a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e0d0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e0d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e0d5  7507                   -jne 0x42e0de
    if (!cpu.flags.zf)
    {
        goto L_0x0042e0de;
    }
    // 0042e0d7  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0042e0dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e0dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e0de:
    // 0042e0de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e0df  6824714900             -push 0x497124
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813092 /*0x497124*/;
    cpu.esp -= 4;
    // 0042e0e4  e8c76a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e0e9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e0ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e0ee  7507                   -jne 0x42e0f7
    if (!cpu.flags.zf)
    {
        goto L_0x0042e0f7;
    }
    // 0042e0f0  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0042e0f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e0f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e0f7:
    // 0042e0f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e0f8  6814714900             -push 0x497114
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813076 /*0x497114*/;
    cpu.esp -= 4;
    // 0042e0fd  e8ae6a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e102  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e105  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e107  7507                   -jne 0x42e110
    if (!cpu.flags.zf)
    {
        goto L_0x0042e110;
    }
    // 0042e109  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0042e10e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e10f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e110:
    // 0042e110  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e111  6804714900             -push 0x497104
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813060 /*0x497104*/;
    cpu.esp -= 4;
    // 0042e116  e8956a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e11b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e11e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e120  7507                   -jne 0x42e129
    if (!cpu.flags.zf)
    {
        goto L_0x0042e129;
    }
    // 0042e122  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 0042e127  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e128  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e129:
    // 0042e129  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e12a  68f4704900             -push 0x4970f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813044 /*0x4970f4*/;
    cpu.esp -= 4;
    // 0042e12f  e87c6a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e134  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e137  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e139  7507                   -jne 0x42e142
    if (!cpu.flags.zf)
    {
        goto L_0x0042e142;
    }
    // 0042e13b  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0042e140  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e141  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e142:
    // 0042e142  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e143  68e4704900             -push 0x4970e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813028 /*0x4970e4*/;
    cpu.esp -= 4;
    // 0042e148  e8636a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e14d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e150  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e152  7507                   -jne 0x42e15b
    if (!cpu.flags.zf)
    {
        goto L_0x0042e15b;
    }
    // 0042e154  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 0042e159  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e15a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e15b:
    // 0042e15b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e15c  68d4704900             -push 0x4970d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813012 /*0x4970d4*/;
    cpu.esp -= 4;
    // 0042e161  e84a6a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e166  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e169  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e16b  7507                   -jne 0x42e174
    if (!cpu.flags.zf)
    {
        goto L_0x0042e174;
    }
    // 0042e16d  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0042e172  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e173  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e174:
    // 0042e174  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e175  68c0704900             -push 0x4970c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812992 /*0x4970c0*/;
    cpu.esp -= 4;
    // 0042e17a  e8316a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e17f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e182  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e184  7507                   -jne 0x42e18d
    if (!cpu.flags.zf)
    {
        goto L_0x0042e18d;
    }
    // 0042e186  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 0042e18b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e18c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e18d:
    // 0042e18d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e18e  68b4704900             -push 0x4970b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812980 /*0x4970b4*/;
    cpu.esp -= 4;
    // 0042e193  e8186a0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e198  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e19b  f7d8                   +neg eax
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
    // 0042e19d  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0042e19f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e1a0  24e8                   -and al, 0xe8
    cpu.al &= x86::reg8(x86::sreg8(232 /*0xe8*/));
    // 0042e1a2  83c017                 -add eax, 0x17
    (cpu.eax) += x86::reg32(x86::sreg32(23 /*0x17*/));
    // 0042e1a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e1b0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042e1b5  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0042e1bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e1bd  7505                   -jne 0x42e1c4
    if (!cpu.flags.zf)
    {
        goto L_0x0042e1c4;
    }
    // 0042e1bf  e83c010000             -call 0x42e300
    cpu.esp -= 4;
    sub_42e300(app, cpu);
L_0x0042e1c4:
    // 0042e1c4  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 0042e1c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e1ca  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042e1cf  8d8c2488000000         -lea ecx, [esp + 0x88]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0042e1d6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e1d7  6864724900             -push 0x497264
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813412 /*0x497264*/;
    cpu.esp -= 4;
    // 0042e1dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e1dd  e8168c0400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042e1e2  8d942494000000         -lea edx, [esp + 0x94]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0042e1e9  6840c74800             -push 0x48c740
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769600 /*0x48c740*/;
    cpu.esp -= 4;
    // 0042e1ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e1ef  e86a9a0400             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 0042e1f4  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042e1f6  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042e1f9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042e1fb  0f84f2000000           -je 0x42e2f3
    if (cpu.flags.zf)
    {
        goto L_0x0042e2f3;
    }
    // 0042e201  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e202  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e203  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e207  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e208  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e209  6820c94800             -push 0x48c920
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770080 /*0x48c920*/;
    cpu.esp -= 4;
    // 0042e20e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e20f  e826970400             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 0042e214  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e217  83f801                 +cmp eax, 1
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
    // 0042e21a  0f85b0000000           -jne 0x42e2d0
    if (!cpu.flags.zf)
    {
        goto L_0x0042e2d0;
    }
L_0x0042e220:
    // 0042e220  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e224  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e225  6858724900             -push 0x497258
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813400 /*0x497258*/;
    cpu.esp -= 4;
    // 0042e22a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e22b  e80a970400             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 0042e230  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e233  83f801                 +cmp eax, 1
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
    // 0042e236  0f8594000000           -jne 0x42e2d0
    if (!cpu.flags.zf)
    {
        goto L_0x0042e2d0;
    }
    // 0042e23c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e240  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e242  0f8488000000           -je 0x42e2d0
    if (cpu.flags.zf)
    {
        goto L_0x0042e2d0;
    }
    // 0042e248  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0042e24b  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0042e24e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e24f  e826900400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042e254  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042e256  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042e259  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042e25b  750d                   -jne 0x42e26a
    if (!cpu.flags.zf)
    {
        goto L_0x0042e26a;
    }
    // 0042e25d  6834724900             -push 0x497234
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813364 /*0x497234*/;
    cpu.esp -= 4;
    // 0042e262  e8a969ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042e267  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042e26a:
    // 0042e26a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e26e  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042e270  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e272  7e2b                   -jle 0x42e29f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e29f;
    }
    // 0042e274  8d7504                 -lea esi, [ebp + 4]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
L_0x0042e277:
    // 0042e277  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042e27a  8d4efc                 -lea ecx, [esi - 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0042e27d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e27e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e27f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e280  6824724900             -push 0x497224
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813348 /*0x497224*/;
    cpu.esp -= 4;
    // 0042e285  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e286  e8af960400             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 0042e28b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042e28e  83f803                 +cmp eax, 3
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
    // 0042e291  750c                   -jne 0x42e29f
    if (!cpu.flags.zf)
    {
        goto L_0x0042e29f;
    }
    // 0042e293  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e297  47                     -inc edi
    (cpu.edi)++;
    // 0042e298  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e29b  3bf8                   +cmp edi, eax
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
    // 0042e29d  7cd8                   -jl 0x42e277
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042e277;
    }
L_0x0042e29f:
    // 0042e29f  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e2a3  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042e2a9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e2aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e2ab  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042e2af  e86c000000             -call 0x42e320
    cpu.esp -= 4;
    sub_42e320(app, cpu);
    // 0042e2b4  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042e2b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e2b9  6820c94800             -push 0x48c920
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770080 /*0x48c920*/;
    cpu.esp -= 4;
    // 0042e2be  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e2bf  e876960400             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 0042e2c4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e2c7  83f801                 +cmp eax, 1
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
    // 0042e2ca  0f8450ffffff           -je 0x42e220
    if (cpu.flags.zf)
    {
        goto L_0x0042e220;
    }
L_0x0042e2d0:
    // 0042e2d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e2d1  e801930400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0042e2d6  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042e2dc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042e2df  e8dc000000             -call 0x42e3c0
    cpu.esp -= 4;
    sub_42e3c0(app, cpu);
    // 0042e2e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e2e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e2e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e2e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e2e8  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042e2ee  e91d00ffff             -jmp 0x41e310
    return sub_41e310(app, cpu);
L_0x0042e2f3:
    // 0042e2f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e2f4  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0042e2fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e300  b960000000             -mov ecx, 0x60
    cpu.ecx = 96 /*0x60*/;
    // 0042e305  e886f4ffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042e30a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e30c  a3c4d44a00             -mov dword ptr [0x4ad4c4], eax
    app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */) = cpu.eax;
    // 0042e311  750b                   -jne 0x42e31e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e31e;
    }
    // 0042e313  687c724900             -push 0x49727c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813436 /*0x49727c*/;
    cpu.esp -= 4;
    // 0042e318  e8f368ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042e31d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e31e:
    // 0042e31e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e320  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e321  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e322  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042e324  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0042e326  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e327  68e8724900             -push 0x4972e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813544 /*0x4972e8*/;
    cpu.esp -= 4;
    // 0042e32c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042e32e  e853b10400             -call 0x479486
    cpu.esp -= 4;
    sub_479486(app, cpu);
    // 0042e333  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e336  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e338  7518                   -jne 0x42e352
    if (!cpu.flags.zf)
    {
        goto L_0x0042e352;
    }
    // 0042e33a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e33e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042e342  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e343  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e344  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042e346  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e348  e8a3f5ffff             -call 0x42d8f0
    cpu.esp -= 4;
    sub_42d8f0(app, cpu);
    // 0042e34d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e34e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e34f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0042e352:
    // 0042e352  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042e354  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e355  68dc724900             -push 0x4972dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813532 /*0x4972dc*/;
    cpu.esp -= 4;
    // 0042e35a  e827b10400             -call 0x479486
    cpu.esp -= 4;
    sub_479486(app, cpu);
    // 0042e35f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e362  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e364  7518                   -jne 0x42e37e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e37e;
    }
    // 0042e366  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e36a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042e36e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e36f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e370  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042e372  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e374  e837f7ffff             -call 0x42dab0
    cpu.esp -= 4;
    sub_42dab0(app, cpu);
    // 0042e379  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e37a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e37b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0042e37e:
    // 0042e37e  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0042e380  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e381  68d4724900             -push 0x4972d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813524 /*0x4972d4*/;
    cpu.esp -= 4;
    // 0042e386  e8fbb00400             -call 0x479486
    cpu.esp -= 4;
    sub_479486(app, cpu);
    // 0042e38b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e38e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e390  7518                   -jne 0x42e3aa
    if (!cpu.flags.zf)
    {
        goto L_0x0042e3aa;
    }
    // 0042e392  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e396  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042e39a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e39b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e39c  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042e39e  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e3a0  e8dbf5ffff             -call 0x42d980
    cpu.esp -= 4;
    sub_42d980(app, cpu);
    // 0042e3a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3a7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0042e3aa:
    // 0042e3aa  6894724900             -push 0x497294
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813460 /*0x497294*/;
    cpu.esp -= 4;
    // 0042e3af  e85c68ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042e3b4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042e3b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3b9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42e3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e3c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e3c1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042e3c3  c7463800000000         -mov dword ptr [esi + 0x38], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 0042e3ca  e8d1010000             -call 0x42e5a0
    cpu.esp -= 4;
    sub_42e5a0(app, cpu);
    // 0042e3cf  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e3d1  e83a000000             -call 0x42e410
    cpu.esp -= 4;
    sub_42e410(app, cpu);
    // 0042e3d6  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e3d8  e8c3030000             -call 0x42e7a0
    cpu.esp -= 4;
    sub_42e7a0(app, cpu);
    // 0042e3dd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e3df  e88c0a0000             -call 0x42ee70
    cpu.esp -= 4;
    sub_42ee70(app, cpu);
    // 0042e3e4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e3e6  e8e50c0000             -call 0x42f0d0
    cpu.esp -= 4;
    sub_42f0d0(app, cpu);
    // 0042e3eb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e3ed  e80e0c0000             -call 0x42f000
    cpu.esp -= 4;
    sub_42f000(app, cpu);
    // 0042e3f2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e3f4  e857290000             -call 0x430d50
    cpu.esp -= 4;
    sub_430d50(app, cpu);
    // 0042e3f9  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e3fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3fc  e9eff0ffff             -jmp 0x42d4f0
    return sub_42d4f0(app, cpu);
}

/* align: skip  */
void Application::sub_42e410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e410  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e411  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e412  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042e414  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0042e417  e8f4f7ffff             -call 0x42dc10
    cpu.esp -= 4;
    sub_42dc10(app, cpu);
    // 0042e41c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e41e  7411                   -je 0x42e431
    if (cpu.flags.zf)
    {
        goto L_0x0042e431;
    }
L_0x0042e420:
    // 0042e420  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e422  e819000000             -call 0x42e440
    cpu.esp -= 4;
    sub_42e440(app, cpu);
    // 0042e427  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042e42d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e42f  75ef                   -jne 0x42e420
    if (!cpu.flags.zf)
    {
        goto L_0x0042e420;
    }
L_0x0042e431:
    // 0042e431  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e433  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e434  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e435  e996010000             -jmp 0x42e5d0
    return sub_42e5d0(app, cpu);
}

/* align: skip  */
void Application::sub_42e440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e440  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042e445  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e446  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e447  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042e449  8b7018                 -mov esi, dword ptr [eax + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0042e44c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e44e  7410                   -je 0x42e460
    if (cpu.flags.zf)
    {
        goto L_0x0042e460;
    }
L_0x0042e450:
    // 0042e450  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042e452  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e454  e817000000             -call 0x42e470
    cpu.esp -= 4;
    sub_42e470(app, cpu);
    // 0042e459  8b7660                 -mov esi, dword ptr [esi + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 0042e45c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e45e  75f0                   -jne 0x42e450
    if (!cpu.flags.zf)
    {
        goto L_0x0042e450;
    }
L_0x0042e460:
    // 0042e460  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e461  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e462  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e470  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e473  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e474  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e475  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042e477  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042e47d  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042e47f  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0042e482  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042e485  8d0481                 -lea eax, [ecx + eax*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 0042e488  8b8ad0000000           -mov ecx, dword ptr [edx + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0042e48e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042e492  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042e494  8b8ad4000000           -mov ecx, dword ptr [edx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0042e49a  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0042e49e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042e4a0  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042e4a4  8b82d8000000           -mov eax, dword ptr [edx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0042e4aa  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042e4ac  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042e4b0  e84b000000             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042e4b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e4b7  7409                   -je 0x42e4c2
    if (cpu.flags.zf)
    {
        goto L_0x0042e4c2;
    }
    // 0042e4b9  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042e4bb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e4bd  e80e000000             -call 0x42e4d0
    cpu.esp -= 4;
    sub_42e4d0(app, cpu);
L_0x0042e4c2:
    // 0042e4c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4c4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e4c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e4d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e4d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e4d2  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042e4d4  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042e4d6  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042e4db  8b8780000000           -mov eax, dword ptr [edi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 0042e4e1  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0042e4e4  e8a7f2ffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042e4e9  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e4eb  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0042e4ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4ee  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042e4f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4f1  e9caf8ffff             -jmp 0x42ddc0
    return sub_42ddc0(app, cpu);
}

/* align: skip  */
void Application::sub_42e500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e501  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e502  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e503  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042e505  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042e509  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e50b  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042e50d  8b8f84000000           -mov ecx, dword ptr [edi + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 0042e513  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042e515  7e38                   -jle 0x42e54f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e54f;
    }
    // 0042e517  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e518  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e519  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042e51b:
    // 0042e51b  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042e51e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042e520  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042e521  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042e523  8b8788000000           -mov eax, dword ptr [edi + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(136) /* 0x88 */);
    // 0042e529  8d0c52                 -lea ecx, [edx + edx*2]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 2);
    // 0042e52c  8d1488                 -lea edx, [eax + ecx*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 0042e52f  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e533  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e534  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0042e537  e824000000             -call 0x42e560
    cpu.esp -= 4;
    sub_42e560(app, cpu);
    // 0042e53c  8b8f84000000           -mov ecx, dword ptr [edi + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 0042e542  03e8                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042e544  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042e546  83c30c                 -add ebx, 0xc
    (cpu.ebx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e549  3bc1                   +cmp eax, ecx
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
    // 0042e54b  7cce                   -jl 0x42e51b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042e51b;
    }
    // 0042e54d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e54e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e54f:
    // 0042e54f  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0042e551  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e552  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0042e555  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e556  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e557  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e560  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e563  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042e565  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042e568  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042e56c  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0042e56f  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042e573  8d542400               -lea edx, [esp]
    cpu.edx = x86::reg32(cpu.esp);
    // 0042e577  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e578  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042e57c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e57d  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042e57f  c744240800247449       -mov dword ptr [esp + 8], 0x49742400
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1232348160 /*0x49742400*/;
    // 0042e587  e8a4f5ffff             -call 0x42db30
    cpu.esp -= 4;
    sub_42db30(app, cpu);
    // 0042e58c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e58f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42e5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e5a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e5a1  8b7120                 -mov esi, dword ptr [ecx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0042e5a4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e5a6  7417                   -je 0x42e5bf
    if (cpu.flags.zf)
    {
        goto L_0x0042e5bf;
    }
L_0x0042e5a8:
    // 0042e5a8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e5aa  e8a1f9ffff             -call 0x42df50
    cpu.esp -= 4;
    sub_42df50(app, cpu);
    // 0042e5af  898680000000           -mov dword ptr [esi + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0042e5b5  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042e5bb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e5bd  75e9                   -jne 0x42e5a8
    if (!cpu.flags.zf)
    {
        goto L_0x0042e5a8;
    }
L_0x0042e5bf:
    // 0042e5bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e5c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e5d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e5d1  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042e5d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e5d4  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0042e5d7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e5d9  7437                   -je 0x42e612
    if (cpu.flags.zf)
    {
        goto L_0x0042e612;
    }
    // 0042e5db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042e5dc:
    // 0042e5dc  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0042e5df  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e5e1  7424                   -je 0x42e607
    if (cpu.flags.zf)
    {
        goto L_0x0042e607;
    }
L_0x0042e5e3:
    // 0042e5e3  3bfe                   +cmp edi, esi
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
    // 0042e5e5  7416                   -je 0x42e5fd
    if (cpu.flags.zf)
    {
        goto L_0x0042e5fd;
    }
    // 0042e5e7  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042e5e9  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e5eb  e830000000             -call 0x42e620
    cpu.esp -= 4;
    sub_42e620(app, cpu);
    // 0042e5f0  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042e5f2  7409                   -je 0x42e5fd
    if (cpu.flags.zf)
    {
        goto L_0x0042e5fd;
    }
    // 0042e5f4  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042e5f6  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e5f8  e873000000             -call 0x42e670
    cpu.esp -= 4;
    sub_42e670(app, cpu);
L_0x0042e5fd:
    // 0042e5fd  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042e603  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e605  75dc                   -jne 0x42e5e3
    if (!cpu.flags.zf)
    {
        goto L_0x0042e5e3;
    }
L_0x0042e607:
    // 0042e607  8bbfbc000000           -mov edi, dword ptr [edi + 0xbc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 0042e60d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e60f  75cb                   -jne 0x42e5dc
    if (!cpu.flags.zf)
    {
        goto L_0x0042e5dc;
    }
    // 0042e611  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e612:
    // 0042e612  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e613  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e614  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e620  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e621  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e622  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e623  8bb188000000           -mov esi, dword ptr [ecx + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */);
    // 0042e629  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e62a  8bb984000000           -mov edi, dword ptr [ecx + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0042e630  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0042e632  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e634  c744240c00000000       -mov dword ptr [esp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0042e63c  7e1b                   -jle 0x42e659
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e659;
    }
    // 0042e63e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e63f  8bdf                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0042e641:
    // 0042e641  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042e643  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e645  e8b6feffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042e64a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e64c  7404                   -je 0x42e652
    if (cpu.flags.zf)
    {
        goto L_0x0042e652;
    }
    // 0042e64e  ff442410               -inc dword ptr [esp + 0x10]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))++;
L_0x0042e652:
    // 0042e652  83c60c                 +add esi, 0xc
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
    // 0042e655  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e656  75e9                   -jne 0x42e641
    if (!cpu.flags.zf)
    {
        goto L_0x0042e641;
    }
    // 0042e658  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e659:
    // 0042e659  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042e65d  3bc7                   +cmp eax, edi
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
    // 0042e65f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e660  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e661  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e662  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0042e665  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e666  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e670  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e671  8bb190000000           -mov esi, dword ptr [ecx + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */);
    // 0042e677  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e678  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042e67a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e67c  7415                   -je 0x42e693
    if (cpu.flags.zf)
    {
        goto L_0x0042e693;
    }
L_0x0042e67e:
    // 0042e67e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e680  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042e682  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e684  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0042e687  e814000000             -call 0x42e6a0
    cpu.esp -= 4;
    sub_42e6a0(app, cpu);
    // 0042e68c  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042e68f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e691  75eb                   -jne 0x42e67e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e67e;
    }
L_0x0042e693:
    // 0042e693  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e694  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e695  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e6a0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e6a3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e6a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e6a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e6a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e6a7  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042e6a9  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042e6ab  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042e6ad  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0042e6b1  8bb790000000           -mov esi, dword ptr [edi + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */);
    // 0042e6b7  c744241001000000       -mov dword ptr [esp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0042e6bf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e6c1  7458                   -je 0x42e71b
    if (cpu.flags.zf)
    {
        goto L_0x0042e71b;
    }
L_0x0042e6c3:
    // 0042e6c3  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e6c5  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042e6c9  394124                 +cmp dword ptr [ecx + 0x24], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e6cc  7544                   -jne 0x42e712
    if (!cpu.flags.zf)
    {
        goto L_0x0042e712;
    }
    // 0042e6ce  837c241c01             +cmp dword ptr [esp + 0x1c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e6d3  7509                   -jne 0x42e6de
    if (!cpu.flags.zf)
    {
        goto L_0x0042e6de;
    }
    // 0042e6d5  e856000000             -call 0x42e730
    cpu.esp -= 4;
    sub_42e730(app, cpu);
    // 0042e6da  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042e6de:
    // 0042e6de  837c241001             +cmp dword ptr [esp + 0x10], 1
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
    // 0042e6e3  752d                   -jne 0x42e712
    if (!cpu.flags.zf)
    {
        goto L_0x0042e712;
    }
    // 0042e6e5  8b8f90000000           -mov ecx, dword ptr [edi + 0x90]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */);
    // 0042e6eb  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042e6ee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e6ef  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042e6f1  e8aaf1ffff             -call 0x42d8a0
    cpu.esp -= 4;
    sub_42d8a0(app, cpu);
    // 0042e6f6  898790000000           -mov dword ptr [edi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0042e6fc  8b878c000000           -mov eax, dword ptr [edi + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(140) /* 0x8c */);
    // 0042e702  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e703  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0042e705  89878c000000           -mov dword ptr [edi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0042e70b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0042e710  eb05                   -jmp 0x42e717
    goto L_0x0042e717;
L_0x0042e712:
    // 0042e712  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0042e714  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
L_0x0042e717:
    // 0042e717  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e719  75a8                   -jne 0x42e6c3
    if (!cpu.flags.zf)
    {
        goto L_0x0042e6c3;
    }
L_0x0042e71b:
    // 0042e71b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e71c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e71d  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042e71f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e720  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e721  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e724  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42e730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e730  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042e735  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e736  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e737  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042e739  8b7040                 -mov esi, dword ptr [eax + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0042e73c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e73e  7418                   -je 0x42e758
    if (cpu.flags.zf)
    {
        goto L_0x0042e758;
    }
L_0x0042e740:
    // 0042e740  8d4e0c                 -lea ecx, [esi + 0xc]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042e743  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e744  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e745  e866640500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e74a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e74d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e74f  743b                   -je 0x42e78c
    if (cpu.flags.zf)
    {
        goto L_0x0042e78c;
    }
    // 0042e751  8b7634                 -mov esi, dword ptr [esi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0042e754  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e756  75e8                   -jne 0x42e740
    if (!cpu.flags.zf)
    {
        goto L_0x0042e740;
    }
L_0x0042e758:
    // 0042e758  a1d06e4900             -mov eax, dword ptr [0x496ed0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4812496) /* 0x496ed0 */);
    // 0042e75d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e75f  7423                   -je 0x42e784
    if (cpu.flags.zf)
    {
        goto L_0x0042e784;
    }
    // 0042e761  b8d06e4900             -mov eax, 0x496ed0
    cpu.eax = 4812496 /*0x496ed0*/;
    // 0042e766  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0042e768:
    // 0042e768  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042e76a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e76b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e76c  e83f640500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042e771  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e774  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e776  7414                   -je 0x42e78c
    if (cpu.flags.zf)
    {
        goto L_0x0042e78c;
    }
    // 0042e778  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042e77b  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042e77e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042e780  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042e782  75e4                   -jne 0x42e768
    if (!cpu.flags.zf)
    {
        goto L_0x0042e768;
    }
L_0x0042e784:
    // 0042e784  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e785  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042e78a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e78b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e78c:
    // 0042e78c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e78d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e78f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e790  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e7a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e7a1  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042e7a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e7a4  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042e7a7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e7a9  7426                   -je 0x42e7d1
    if (cpu.flags.zf)
    {
        goto L_0x0042e7d1;
    }
    // 0042e7ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042e7ac:
    // 0042e7ac  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0042e7af  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e7b1  7413                   -je 0x42e7c6
    if (cpu.flags.zf)
    {
        goto L_0x0042e7c6;
    }
L_0x0042e7b3:
    // 0042e7b3  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042e7b5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e7b7  e824000000             -call 0x42e7e0
    cpu.esp -= 4;
    sub_42e7e0(app, cpu);
    // 0042e7bc  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042e7c2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e7c4  75ed                   -jne 0x42e7b3
    if (!cpu.flags.zf)
    {
        goto L_0x0042e7b3;
    }
L_0x0042e7c6:
    // 0042e7c6  8bbf98000000           -mov edi, dword ptr [edi + 0x98]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(152) /* 0x98 */);
    // 0042e7cc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e7ce  75dc                   -jne 0x42e7ac
    if (!cpu.flags.zf)
    {
        goto L_0x0042e7ac;
    }
    // 0042e7d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e7d1:
    // 0042e7d1  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042e7d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e7d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e7d5  e956000000             -jmp 0x42e830
    return sub_42e830(app, cpu);
}

/* align: skip  */
void Application::sub_42e7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e7e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e7e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e7e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e7e3  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042e7e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e7e6  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042e7e8  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042e7ee  8b9e84000000           -mov ebx, dword ptr [esi + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0042e7f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e7f6  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042e7f8  7e1b                   -jle 0x42e815
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e815;
    }
L_0x0042e7fa:
    // 0042e7fa  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042e7fc  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042e7fe  e8fdfcffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042e803  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e805  7513                   -jne 0x42e81a
    if (!cpu.flags.zf)
    {
        goto L_0x0042e81a;
    }
    // 0042e807  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042e80d  47                     -inc edi
    (cpu.edi)++;
    // 0042e80e  83c30c                 -add ebx, 0xc
    (cpu.ebx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e811  3bf8                   +cmp edi, eax
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
    // 0042e813  7ce5                   -jl 0x42e7fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042e7fa;
    }
L_0x0042e815:
    // 0042e815  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e816  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e817  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e818  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e819  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e81a:
    // 0042e81a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e81c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e81d  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042e81f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e820  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e821  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e822  e9e9efffff             -jmp 0x42d810
    return sub_42d810(app, cpu);
}

/* align: skip  */
void Application::sub_42e830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e830  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e831  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042e834  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e836  7423                   -je 0x42e85b
    if (cpu.flags.zf)
    {
        goto L_0x0042e85b;
    }
L_0x0042e838:
    // 0042e838  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042e83a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e83c  e80f060000             -call 0x42ee50
    cpu.esp -= 4;
    sub_42ee50(app, cpu);
    // 0042e841  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e843  e818000000             -call 0x42e860
    cpu.esp -= 4;
    sub_42e860(app, cpu);
    // 0042e848  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042e84a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e84c  e8cf020000             -call 0x42eb20
    cpu.esp -= 4;
    sub_42eb20(app, cpu);
    // 0042e851  8bb698000000           -mov esi, dword ptr [esi + 0x98]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 0042e857  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e859  75dd                   -jne 0x42e838
    if (!cpu.flags.zf)
    {
        goto L_0x0042e838;
    }
L_0x0042e85b:
    // 0042e85b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e85c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e860  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042e863  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e864  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042e866  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e867  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e868  8b8588000000           -mov eax, dword ptr [ebp + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(136) /* 0x88 */);
    // 0042e86e  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0042e872  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0042e875  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e876  e8ff890400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042e87b  8b8d88000000           -mov ecx, dword ptr [ebp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(136) /* 0x88 */);
    // 0042e881  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042e883  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042e886  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0042e888  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e88a  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0042e88c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042e88f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042e892  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042e894  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042e896  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0042e89a  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042e89d  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 0042e89f  8b8d88000000           -mov ecx, dword ptr [ebp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(136) /* 0x88 */);
    // 0042e8a5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e8a7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042e8a9  7e17                   -jle 0x42e8c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e8c2;
    }
    // 0042e8ab  8d4e0c                 -lea ecx, [esi + 0xc]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
L_0x0042e8ae:
    // 0042e8ae  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
    // 0042e8b4  8b9588000000           -mov edx, dword ptr [ebp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(136) /* 0x88 */);
    // 0042e8ba  40                     -inc eax
    (cpu.eax)++;
    // 0042e8bb  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042e8be  3bc2                   +cmp eax, edx
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
    // 0042e8c0  7cec                   -jl 0x42e8ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042e8ae;
    }
L_0x0042e8c2:
    // 0042e8c2  8b858c000000           -mov eax, dword ptr [ebp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 0042e8c8  c744241800000000       -mov dword ptr [esp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0042e8d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e8d2  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042e8d6  0f84b8000000           -je 0x42e994
    if (cpu.flags.zf)
    {
        goto L_0x0042e994;
    }
    // 0042e8dc  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0042e8e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0042e8e1:
    // 0042e8e1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e8e5  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042e8e7  c744241800000000       -mov dword ptr [esp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0042e8ef  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0042e8f2  8bbd8c000000           -mov edi, dword ptr [ebp + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 0042e8f8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e8fa  7474                   -je 0x42e970
    if (cpu.flags.zf)
    {
        goto L_0x0042e970;
    }
L_0x0042e8fc:
    // 0042e8fc  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042e8fe  3bda                   +cmp ebx, edx
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
    // 0042e900  7453                   -je 0x42e955
    if (cpu.flags.zf)
    {
        goto L_0x0042e955;
    }
    // 0042e902  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042e904  e817fdffff             -call 0x42e620
    cpu.esp -= 4;
    sub_42e620(app, cpu);
    // 0042e909  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042e90d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042e90f  7444                   -je 0x42e955
    if (cpu.flags.zf)
    {
        goto L_0x0042e955;
    }
    // 0042e911  8b8bb4000000           -mov ecx, dword ptr [ebx + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(180) /* 0xb4 */);
    // 0042e917  41                     -inc ecx
    (cpu.ecx)++;
    // 0042e918  898bb4000000           -mov dword ptr [ebx + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 0042e91e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e920  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e922  7515                   -jne 0x42e939
    if (!cpu.flags.zf)
    {
        goto L_0x0042e939;
    }
    // 0042e924  8b9588000000           -mov edx, dword ptr [ebp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(136) /* 0x88 */);
    // 0042e92a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0042e92d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042e92e  e847890400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042e933  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042e936  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0042e939:
    // 0042e939  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e93d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042e941  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0042e944  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e946  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042e949  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042e94d  890c90                 -mov dword ptr [eax + edx*4], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.ecx;
    // 0042e950  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e952  40                     -inc eax
    (cpu.eax)++;
    // 0042e953  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0042e955:
    // 0042e955  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042e959  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042e95c  42                     -inc edx
    (cpu.edx)++;
    // 0042e95d  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042e960  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e962  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0042e966  7594                   -jne 0x42e8fc
    if (!cpu.flags.zf)
    {
        goto L_0x0042e8fc;
    }
    // 0042e968  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042e96c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x0042e970:
    // 0042e970  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042e974  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e978  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042e97b  47                     -inc edi
    (cpu.edi)++;
    // 0042e97c  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042e97f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0042e983  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e985  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 0042e989  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042e98d  0f854effffff           -jne 0x42e8e1
    if (!cpu.flags.zf)
    {
        goto L_0x0042e8e1;
    }
    // 0042e993  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e994:
    // 0042e994  8b9588000000           -mov edx, dword ptr [ebp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(136) /* 0x88 */);
    // 0042e99a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e99c  e81f000000             -call 0x42e9c0
    cpu.esp -= 4;
    sub_42e9c0(app, cpu);
    // 0042e9a1  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042e9a3  e868f9feff             -call 0x41e310
    cpu.esp -= 4;
    sub_41e310(app, cpu);
    // 0042e9a8  8b9588000000           -mov edx, dword ptr [ebp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(136) /* 0x88 */);
    // 0042e9ae  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042e9b0  e85bf9feff             -call 0x41e310
    cpu.esp -= 4;
    sub_41e310(app, cpu);
    // 0042e9b5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042e9b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e9b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e9b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e9ba  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042e9bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42e9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e9c0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e9c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e9c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e9c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e9c6  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042e9c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e9c9  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042e9cd  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 0042e9d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e9d5  e8a0880400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042e9da  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042e9dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e9dd  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 0042e9e1  e894880400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042e9e6  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042e9e8  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042e9ea  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0042e9ec  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e9ee  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042e9f1  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042e9f3  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042e9f5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042e9f8  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042e9fb  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 0042e9fd  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042e9ff  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042ea01  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0042ea03  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042ea05  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042ea08  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042ea0a  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042ea0c  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042ea0f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ea11  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 0042ea13  7e4f                   -jle 0x42ea64
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ea64;
    }
L_0x0042ea15:
    // 0042ea15  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042ea19  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042ea1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ea1e  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042ea20  e85b000000             -call 0x42ea80
    cpu.esp -= 4;
    sub_42ea80(app, cpu);
    // 0042ea25  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042ea27  83ffff                 +cmp edi, -1
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
    // 0042ea2a  750d                   -jne 0x42ea39
    if (!cpu.flags.zf)
    {
        goto L_0x0042ea39;
    }
    // 0042ea2c  68f0724900             -push 0x4972f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813552 /*0x4972f0*/;
    cpu.esp -= 4;
    // 0042ea31  e8da61ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042ea36  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042ea39:
    // 0042ea39  897c9d00               -mov dword ptr [ebp + ebx*4], edi
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ebx * 4) = cpu.edi;
    // 0042ea3d  43                     -inc ebx
    (cpu.ebx)++;
    // 0042ea3e  3bde                   +cmp ebx, esi
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
    // 0042ea40  7cd3                   -jl 0x42ea15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ea15;
    }
    // 0042ea42  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ea44  7e1e                   -jle 0x42ea64
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ea64;
    }
L_0x0042ea46:
    // 0042ea46  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042ea4a  4e                     -dec esi
    (cpu.esi)--;
    // 0042ea4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ea4c  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042ea4e  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042ea50  e87b000000             -call 0x42ead0
    cpu.esp -= 4;
    sub_42ead0(app, cpu);
    // 0042ea55  8b4cb500               -mov ecx, dword ptr [ebp + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4);
    // 0042ea59  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042ea5c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ea5e  8944390c               -mov dword ptr [ecx + edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edi * 1) = cpu.eax;
    // 0042ea62  7fe2                   -jg 0x42ea46
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042ea46;
    }
L_0x0042ea64:
    // 0042ea64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ea65  e84a890400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042ea6a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042ea6e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042ea6f  e840890400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042ea74  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042ea77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ea78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ea79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ea7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ea7b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042ea7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42ea80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ea80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ea81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ea82  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042ea85  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042ea88  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042ea8a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042ea8c  7e30                   -jle 0x42eabe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042eabe;
    }
    // 0042ea8e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ea8f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ea90  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042ea94  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x0042ea96:
    // 0042ea96  837cb50000             +cmp dword ptr [ebp + esi*4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ea9b  750a                   -jne 0x42eaa7
    if (!cpu.flags.zf)
    {
        goto L_0x0042eaa7;
    }
    // 0042ea9d  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042ea9f  3bcf                   +cmp ecx, edi
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
    // 0042eaa1  7e04                   -jle 0x42eaa7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042eaa7;
    }
    // 0042eaa3  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042eaa5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0042eaa7:
    // 0042eaa7  46                     -inc esi
    (cpu.esi)++;
    // 0042eaa8  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042eaab  3bf2                   +cmp esi, edx
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
    // 0042eaad  7ce7                   -jl 0x42ea96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ea96;
    }
    // 0042eaaf  c744850001000000       -mov dword ptr [ebp + eax*4], 1
    app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4) = 1 /*0x1*/;
    // 0042eab7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eab8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eab9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eaba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eabb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042eabe:
    // 0042eabe  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042eac2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eac3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eac4  c7048101000000         -mov dword ptr [ecx + eax*4], 1
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 1 /*0x1*/;
    // 0042eacb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42ead0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ead0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042ead1  894c2400               -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0042ead5  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042ead9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eada  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042eadb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eadc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eadd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042eadf  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042eae1  7e32                   -jle 0x42eb15
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042eb15;
    }
L_0x0042eae3:
    // 0042eae3  8b44aafc               -mov eax, dword ptr [edx + ebp*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.ebp * 4);
    // 0042eae7  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042eaeb  4d                     -dec ebp
    (cpu.ebp)--;
    // 0042eaec  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042eaee  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0042eaf1  03f3                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eaf3  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042eaf5  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042eaf7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042eaf9  7e16                   -jle 0x42eb11
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042eb11;
    }
    // 0042eafb  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0042eafe  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
L_0x0042eb01:
    // 0042eb01  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 0042eb03  7413                   -je 0x42eb18
    if (cpu.flags.zf)
    {
        goto L_0x0042eb18;
    }
    // 0042eb05  47                     -inc edi
    (cpu.edi)++;
    // 0042eb06  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042eb09  3bfb                   +cmp edi, ebx
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
    // 0042eb0b  7cf4                   -jl 0x42eb01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042eb01;
    }
    // 0042eb0d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0042eb11:
    // 0042eb11  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042eb13  7fce                   -jg 0x42eae3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042eae3;
    }
L_0x0042eb15:
    // 0042eb15  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042eb18:
    // 0042eb18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb1d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42eb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eb20  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042eb23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eb24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042eb25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb26  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042eb28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb29  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0042eb2b  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042eb31  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0042eb35  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0042eb38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042eb39  c744241800000000       -mov dword ptr [esp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0042eb41  e834870400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042eb46  8b8e80000000           -mov ecx, dword ptr [esi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042eb4c  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042eb4e  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0042eb51  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0042eb53  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042eb55  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0042eb57  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042eb5a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042eb5d  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042eb5f  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042eb61  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042eb64  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 0042eb66  8b8e88000000           -mov ecx, dword ptr [esi + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0042eb6c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042eb6e  3bc8                   +cmp ecx, eax
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
    // 0042eb70  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042eb74  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0042eb78  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0042eb7c  0f8e5f010000           -jle 0x42ece1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ece1;
    }
    // 0042eb82  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042eb86  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042eb88  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
L_0x0042eb8c:
    // 0042eb8c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042eb8e  3911                   +cmp dword ptr [ecx], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042eb90  754f                   -jne 0x42ebe1
    if (!cpu.flags.zf)
    {
        goto L_0x0042ebe1;
    }
    // 0042eb92  39542414               +cmp dword ptr [esp + 0x14], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042eb96  751c                   -jne 0x42ebb4
    if (!cpu.flags.zf)
    {
        goto L_0x0042ebb4;
    }
    // 0042eb98  8bbe8c000000           -mov edi, dword ptr [esi + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0042eb9e  899688000000           -mov dword ptr [esi + 0x88], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 0042eba4  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0042eba8  89968c000000           -mov dword ptr [esi + 0x8c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.edx;
    // 0042ebae  899690000000           -mov dword ptr [esi + 0x90], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.edx;
L_0x0042ebb4:
    // 0042ebb4  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0042ebb7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042ebb9  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042ebbb  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042ebbd  e84eecffff             -call 0x42d810
    cpu.esp -= 4;
    sub_42d810(app, cpu);
    // 0042ebc2  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042ebc6  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042ebc8  41                     -inc ecx
    (cpu.ecx)++;
    // 0042ebc9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ebca  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0042ebce  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042ebd0  e8ab010000             -call 0x42ed80
    cpu.esp -= 4;
    sub_42ed80(app, cpu);
    // 0042ebd5  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042ebd9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042ebdd  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x0042ebe1:
    // 0042ebe1  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042ebe5  40                     -inc eax
    (cpu.eax)++;
    // 0042ebe6  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042ebe9  3bc2                   +cmp eax, edx
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
    // 0042ebeb  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042ebef  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0042ebf3  7c97                   -jl 0x42eb8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042eb8c;
    }
    // 0042ebf5  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042ebf9  83f801                 +cmp eax, 1
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
    // 0042ebfc  7542                   -jne 0x42ec40
    if (!cpu.flags.zf)
    {
        goto L_0x0042ec40;
    }
    // 0042ebfe  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0042ec01  8b7c1f0c               -mov edi, dword ptr [edi + ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ebx * 1);
    // 0042ec05  83ffff                 +cmp edi, -1
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
    // 0042ec08  742c                   -je 0x42ec36
    if (cpu.flags.zf)
    {
        goto L_0x0042ec36;
    }
    // 0042ec0a  c1e704                 +shl edi, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.edi);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042ec0d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042ec0f  8b7c1f08               -mov edi, dword ptr [edi + ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ebx * 1);
    // 0042ec13  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042ec15  e8f6ebffff             -call 0x42d810
    cpu.esp -= 4;
    sub_42d810(app, cpu);
    // 0042ec1a  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042ec1c  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042ec1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ec1f  e85c010000             -call 0x42ed80
    cpu.esp -= 4;
    sub_42ed80(app, cpu);
    // 0042ec24  8b9680000000           -mov edx, dword ptr [esi + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042ec2a  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042ec2c  e8af010000             -call 0x42ede0
    cpu.esp -= 4;
    sub_42ede0(app, cpu);
    // 0042ec31  e9b8000000             -jmp 0x42ecee
    goto L_0x0042ecee;
L_0x0042ec36:
    // 0042ec36  68f0734900             -push 0x4973f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813808 /*0x4973f0*/;
    cpu.esp -= 4;
    // 0042ec3b  e9a6000000             -jmp 0x42ece6
    goto L_0x0042ece6;
L_0x0042ec40:
    // 0042ec40  0f8e9b000000           -jle 0x42ece1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ece1;
    }
    // 0042ec46  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042ec4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ec4c  750d                   -jne 0x42ec5b
    if (!cpu.flags.zf)
    {
        goto L_0x0042ec5b;
    }
    // 0042ec4e  68c8734900             -push 0x4973c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813768 /*0x4973c8*/;
    cpu.esp -= 4;
    // 0042ec53  e8b85fffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042ec58  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042ec5b:
    // 0042ec5b  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0042ec61  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042ec63  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042ec65  e896010000             -call 0x42ee00
    cpu.esp -= 4;
    sub_42ee00(app, cpu);
    // 0042ec6a  8b8688000000           -mov eax, dword ptr [esi + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0042ec70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ec72  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0042ec7a  7e72                   -jle 0x42ecee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ecee;
    }
L_0x0042ec7c:
    // 0042ec7c  8b9680000000           -mov edx, dword ptr [esi + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042ec82  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042ec84  e857010000             -call 0x42ede0
    cpu.esp -= 4;
    sub_42ede0(app, cpu);
    // 0042ec89  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ec8b  7561                   -jne 0x42ecee
    if (!cpu.flags.zf)
    {
        goto L_0x0042ecee;
    }
    // 0042ec8d  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0042ec90  8b441f0c               -mov eax, dword ptr [edi + ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ebx * 1);
    // 0042ec94  8d7c1f0c               -lea edi, [edi + ebx + 0xc]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ebx * 1);
    // 0042ec98  83f8ff                 +cmp eax, -1
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
    // 0042ec9b  750d                   -jne 0x42ecaa
    if (!cpu.flags.zf)
    {
        goto L_0x0042ecaa;
    }
    // 0042ec9d  6860734900             -push 0x497360
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813664 /*0x497360*/;
    cpu.esp -= 4;
    // 0042eca2  e8695fffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042eca7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042ecaa:
    // 0042ecaa  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 0042ecac  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042ecae  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042ecb0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0042ecb3  8b5c1808               -mov ebx, dword ptr [eax + ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebx * 1);
    // 0042ecb7  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042ecb9  e852ebffff             -call 0x42d810
    cpu.esp -= 4;
    sub_42d810(app, cpu);
    // 0042ecbe  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042ecc0  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042ecc2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ecc3  e8b8000000             -call 0x42ed80
    cpu.esp -= 4;
    sub_42ed80(app, cpu);
    // 0042ecc8  8b8e88000000           -mov ecx, dword ptr [esi + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0042ecce  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042ecd2  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042ecd6  40                     -inc eax
    (cpu.eax)++;
    // 0042ecd7  3bc1                   +cmp eax, ecx
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
    // 0042ecd9  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042ecdd  7c9d                   -jl 0x42ec7c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ec7c;
    }
    // 0042ecdf  eb0d                   -jmp 0x42ecee
    goto L_0x0042ecee;
L_0x0042ece1:
    // 0042ece1  6840734900             -push 0x497340
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813632 /*0x497340*/;
    cpu.esp -= 4;
L_0x0042ece6:
    // 0042ece6  e8255fffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042eceb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042ecee:
    // 0042ecee  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042ecf2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042ecf4  7405                   -je 0x42ecfb
    if (cpu.flags.zf)
    {
        goto L_0x0042ecfb;
    }
    // 0042ecf6  e8b5140000             -call 0x4301b0
    cpu.esp -= 4;
    sub_4301b0(app, cpu);
L_0x0042ecfb:
    // 0042ecfb  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042ecff  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042ed01  e81a000000             -call 0x42ed20
    cpu.esp -= 4;
    sub_42ed20(app, cpu);
    // 0042ed06  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ed07  e8a8860400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042ed0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ed0f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042ed11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed15  83c418                 +add esp, 0x18
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
    // 0042ed18  e933000000             -jmp 0x42ed50
    return sub_42ed50(app, cpu);
}

/* align: skip  */
void Application::sub_42ed20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ed20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ed21  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042ed23  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042ed25  7e1a                   -jle 0x42ed41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ed41;
    }
    // 0042ed27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ed28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ed29  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042ed2c  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x0042ed2e:
    // 0042ed2e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ed30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ed31  e87e860400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042ed36  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ed39  83c610                 +add esi, 0x10
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042ed3c  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042ed3d  75ef                   -jne 0x42ed2e
    if (!cpu.flags.zf)
    {
        goto L_0x0042ed2e;
    }
    // 0042ed3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ed41:
    // 0042ed41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ed42  e86d860400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042ed47  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ed4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42ed50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ed50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ed51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ed52  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042ed54  8bb78c000000           -mov esi, dword ptr [edi + 0x8c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(140) /* 0x8c */);
    // 0042ed5a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ed5c  7410                   -je 0x42ed6e
    if (cpu.flags.zf)
    {
        goto L_0x0042ed6e;
    }
L_0x0042ed5e:
    // 0042ed5e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ed60  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042ed62  e8f9e9ffff             -call 0x42d760
    cpu.esp -= 4;
    sub_42d760(app, cpu);
    // 0042ed67  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042ed6a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ed6c  75f0                   -jne 0x42ed5e
    if (!cpu.flags.zf)
    {
        goto L_0x0042ed5e;
    }
L_0x0042ed6e:
    // 0042ed6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42ed80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ed80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042ed81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ed82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ed83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ed84  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042ed86  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042ed88  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042ed8a  8b8f80000000           -mov ecx, dword ptr [edi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 0042ed90  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042ed92  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042ed94  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042ed98  7e3d                   -jle 0x42edd7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042edd7;
    }
    // 0042ed9a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ed9b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042ed9d:
    // 0042ed9d  8b8f84000000           -mov ecx, dword ptr [edi + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 0042eda3  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042eda7  03cb                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eda9  e852f7ffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042edae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042edb0  7412                   -je 0x42edc4
    if (cpu.flags.zf)
    {
        goto L_0x0042edc4;
    }
    // 0042edb2  8b4cb500               -mov ecx, dword ptr [ebp + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4);
    // 0042edb6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042edba  41                     -inc ecx
    (cpu.ecx)++;
    // 0042edbb  40                     -inc eax
    (cpu.eax)++;
    // 0042edbc  894cb500               -mov dword ptr [ebp + esi*4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4) = cpu.ecx;
    // 0042edc0  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042edc4:
    // 0042edc4  8b8780000000           -mov eax, dword ptr [edi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 0042edca  46                     -inc esi
    (cpu.esi)++;
    // 0042edcb  83c30c                 -add ebx, 0xc
    (cpu.ebx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042edce  3bf0                   +cmp esi, eax
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
    // 0042edd0  7ccb                   -jl 0x42ed9d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ed9d;
    }
    // 0042edd2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042edd6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042edd7:
    // 0042edd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eddb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42ede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ede0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042ede2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042ede4  7e0b                   -jle 0x42edf1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042edf1;
    }
L_0x0042ede6:
    // 0042ede6  833c8100               +cmp dword ptr [ecx + eax*4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042edea  740b                   -je 0x42edf7
    if (cpu.flags.zf)
    {
        goto L_0x0042edf7;
    }
    // 0042edec  40                     -inc eax
    (cpu.eax)++;
    // 0042eded  3bc2                   +cmp eax, edx
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
    // 0042edef  7cf5                   -jl 0x42ede6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ede6;
    }
L_0x0042edf1:
    // 0042edf1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042edf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042edf7:
    // 0042edf7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042edf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42ee00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ee00  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ee01  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042ee04  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042ee06  7e30                   -jle 0x42ee38
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ee38;
    }
    // 0042ee08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ee09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ee0a  8d710c                 -lea esi, [ecx + 0xc]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042ee0d  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0042ee0f:
    // 0042ee0f  8b46f4                 -mov eax, dword ptr [esi - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-12) /* -0xc */);
    // 0042ee12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ee14  751a                   -jne 0x42ee30
    if (!cpu.flags.zf)
    {
        goto L_0x0042ee30;
    }
    // 0042ee16  83ffff                 +cmp edi, -1
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
    // 0042ee19  7504                   -jne 0x42ee1f
    if (!cpu.flags.zf)
    {
        goto L_0x0042ee1f;
    }
    // 0042ee1b  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ee1d  eb11                   -jmp 0x42ee30
    goto L_0x0042ee30;
L_0x0042ee1f:
    // 0042ee1f  3b3e                   +cmp edi, dword ptr [esi]
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
    // 0042ee21  740d                   -je 0x42ee30
    if (cpu.flags.zf)
    {
        goto L_0x0042ee30;
    }
    // 0042ee23  683c744900             -push 0x49743c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813884 /*0x49743c*/;
    cpu.esp -= 4;
    // 0042ee28  e8e35dffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042ee2d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042ee30:
    // 0042ee30  83c610                 +add esi, 0x10
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042ee33  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042ee34  75d9                   -jne 0x42ee0f
    if (!cpu.flags.zf)
    {
        goto L_0x0042ee0f;
    }
    // 0042ee36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ee37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ee38:
    // 0042ee38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042ee3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ee3e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42ee50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ee50  8b818c000000           -mov eax, dword ptr [ecx + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0042ee56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ee58  740f                   -je 0x42ee69
    if (cpu.flags.zf)
    {
        goto L_0x0042ee69;
    }
L_0x0042ee5a:
    // 0042ee5a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042ee5c  8991b4000000           -mov dword ptr [ecx + 0xb4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */) = cpu.edx;
    // 0042ee62  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042ee65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ee67  75f1                   -jne 0x42ee5a
    if (!cpu.flags.zf)
    {
        goto L_0x0042ee5a;
    }
L_0x0042ee69:
    // 0042ee69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42ee70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ee70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ee71  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042ee73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ee74  8b7b30                 -mov edi, dword ptr [ebx + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0042ee77  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042ee79  7426                   -je 0x42eea1
    if (cpu.flags.zf)
    {
        goto L_0x0042eea1;
    }
    // 0042ee7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042ee7c:
    // 0042ee7c  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0042ee7f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ee81  7413                   -je 0x42ee96
    if (cpu.flags.zf)
    {
        goto L_0x0042ee96;
    }
L_0x0042ee83:
    // 0042ee83  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042ee85  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042ee87  e824000000             -call 0x42eeb0
    cpu.esp -= 4;
    sub_42eeb0(app, cpu);
    // 0042ee8c  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042ee92  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ee94  75ed                   -jne 0x42ee83
    if (!cpu.flags.zf)
    {
        goto L_0x0042ee83;
    }
L_0x0042ee96:
    // 0042ee96  8bbf98000000           -mov edi, dword ptr [edi + 0x98]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(152) /* 0x98 */);
    // 0042ee9c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042ee9e  75dc                   -jne 0x42ee7c
    if (!cpu.flags.zf)
    {
        goto L_0x0042ee7c;
    }
    // 0042eea0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042eea1:
    // 0042eea1  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042eea3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eea4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eea5  e936000000             -jmp 0x42eee0
    return sub_42eee0(app, cpu);
}

/* align: skip  */
void Application::sub_42eeb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eeb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eeb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eeb2  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042eeb4  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042eeb6  8d8f80000000           -lea ecx, [edi + 0x80]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 0042eebc  e83ff6ffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042eec1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042eec3  740b                   -je 0x42eed0
    if (cpu.flags.zf)
    {
        goto L_0x0042eed0;
    }
    // 0042eec5  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042eec7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042eec9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eeca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eecb  e970ebffff             -jmp 0x42da40
    return sub_42da40(app, cpu);
L_0x0042eed0:
    // 0042eed0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eed1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eed2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42eee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eee1  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042eee3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eee4  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0042eee7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042eee9  7437                   -je 0x42ef22
    if (cpu.flags.zf)
    {
        goto L_0x0042ef22;
    }
    // 0042eeeb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042eeec:
    // 0042eeec  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0042eeef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042eef1  7424                   -je 0x42ef17
    if (cpu.flags.zf)
    {
        goto L_0x0042ef17;
    }
L_0x0042eef3:
    // 0042eef3  3bfe                   +cmp edi, esi
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
    // 0042eef5  7416                   -je 0x42ef0d
    if (cpu.flags.zf)
    {
        goto L_0x0042ef0d;
    }
    // 0042eef7  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042eef9  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042eefb  e820f7ffff             -call 0x42e620
    cpu.esp -= 4;
    sub_42e620(app, cpu);
    // 0042ef00  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042ef02  7409                   -je 0x42ef0d
    if (cpu.flags.zf)
    {
        goto L_0x0042ef0d;
    }
    // 0042ef04  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042ef06  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042ef08  e823000000             -call 0x42ef30
    cpu.esp -= 4;
    sub_42ef30(app, cpu);
L_0x0042ef0d:
    // 0042ef0d  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042ef13  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ef15  75dc                   -jne 0x42eef3
    if (!cpu.flags.zf)
    {
        goto L_0x0042eef3;
    }
L_0x0042ef17:
    // 0042ef17  8bbfbc000000           -mov edi, dword ptr [edi + 0xbc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 0042ef1d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042ef1f  75cb                   -jne 0x42eeec
    if (!cpu.flags.zf)
    {
        goto L_0x0042eeec;
    }
    // 0042ef21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ef22:
    // 0042ef22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42ef30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042ef31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ef32  8b99a4000000           -mov ebx, dword ptr [ecx + 0xa4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0042ef38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ef39  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0042ef3b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042ef3d  7448                   -je 0x42ef87
    if (cpu.flags.zf)
    {
        goto L_0x0042ef87;
    }
    // 0042ef3f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ef40  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042ef41:
    // 0042ef41  8bb5a4000000           -mov esi, dword ptr [ebp + 0xa4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */);
    // 0042ef47  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042ef49  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042ef4b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042ef4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ef51  742b                   -je 0x42ef7e
    if (cpu.flags.zf)
    {
        goto L_0x0042ef7e;
    }
L_0x0042ef53:
    // 0042ef53  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ef55  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042ef59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ef5a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042ef5b  e8505c0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042ef60  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042ef63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ef65  750e                   -jne 0x42ef75
    if (!cpu.flags.zf)
    {
        goto L_0x0042ef75;
    }
    // 0042ef67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ef68  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042ef6a  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042ef6c  e81f000000             -call 0x42ef90
    cpu.esp -= 4;
    sub_42ef90(app, cpu);
    // 0042ef71  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042ef73  eb05                   -jmp 0x42ef7a
    goto L_0x0042ef7a;
L_0x0042ef75:
    // 0042ef75  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0042ef77  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
L_0x0042ef7a:
    // 0042ef7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ef7c  75d5                   -jne 0x42ef53
    if (!cpu.flags.zf)
    {
        goto L_0x0042ef53;
    }
L_0x0042ef7e:
    // 0042ef7e  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042ef81  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042ef83  75bc                   -jne 0x42ef41
    if (!cpu.flags.zf)
    {
        goto L_0x0042ef41;
    }
    // 0042ef85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ef87:
    // 0042ef87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42ef90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef90  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042ef94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ef95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ef96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ef97  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042ef99  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042ef9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ef9c  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0042ef9e  3986a8000000           +cmp dword ptr [esi + 0xa8], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042efa4  7505                   -jne 0x42efab
    if (!cpu.flags.zf)
    {
        goto L_0x0042efab;
    }
    // 0042efa6  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0042efab:
    // 0042efab  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042efad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042efae  741d                   -je 0x42efcd
    if (cpu.flags.zf)
    {
        goto L_0x0042efcd;
    }
    // 0042efb0  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042efb3  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0042efb6  e8f9830400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042efbb  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042efbe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042efc1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042efc3  7519                   -jne 0x42efde
    if (!cpu.flags.zf)
    {
        goto L_0x0042efde;
    }
    // 0042efc5  899ea8000000           -mov dword ptr [esi + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 0042efcb  eb1c                   -jmp 0x42efe9
    goto L_0x0042efe9;
L_0x0042efcd:
    // 0042efcd  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042efd0  e8df830400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042efd5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042efd8  89bea4000000           -mov dword ptr [esi + 0xa4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */) = cpu.edi;
L_0x0042efde:
    // 0042efde  83fd01                 +cmp ebp, 1
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
    // 0042efe1  7506                   -jne 0x42efe9
    if (!cpu.flags.zf)
    {
        goto L_0x0042efe9;
    }
    // 0042efe3  89bea8000000           -mov dword ptr [esi + 0xa8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.edi;
L_0x0042efe9:
    // 0042efe9  8b86a0000000           -mov eax, dword ptr [esi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 0042efef  48                     -dec eax
    (cpu.eax)--;
    // 0042eff0  8986a0000000           -mov dword ptr [esi + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0042eff6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042eff8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eff9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042effa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042effb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042effc  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42f000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042f001  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042f003  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f004  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0042f007  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042f009  744f                   -je 0x42f05a
    if (cpu.flags.zf)
    {
        goto L_0x0042f05a;
    }
    // 0042f00b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042f00c:
    // 0042f00c  8b87b4000000           -mov eax, dword ptr [edi + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */);
    // 0042f012  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f014  7539                   -jne 0x42f04f
    if (!cpu.flags.zf)
    {
        goto L_0x0042f04f;
    }
    // 0042f016  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0042f019  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f01b  7432                   -je 0x42f04f
    if (cpu.flags.zf)
    {
        goto L_0x0042f04f;
    }
L_0x0042f01d:
    // 0042f01d  3bf7                   +cmp esi, edi
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
    // 0042f01f  7424                   -je 0x42f045
    if (cpu.flags.zf)
    {
        goto L_0x0042f045;
    }
    // 0042f021  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042f023  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042f025  e8f6f5ffff             -call 0x42e620
    cpu.esp -= 4;
    sub_42e620(app, cpu);
    // 0042f02a  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042f02c  7417                   -je 0x42f045
    if (cpu.flags.zf)
    {
        goto L_0x0042f045;
    }
    // 0042f02e  8b86b4000000           -mov eax, dword ptr [esi + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0042f034  8b8fb4000000           -mov ecx, dword ptr [edi + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */);
    // 0042f03a  3bc8                   +cmp ecx, eax
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
    // 0042f03c  7f07                   -jg 0x42f045
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042f045;
    }
    // 0042f03e  40                     -inc eax
    (cpu.eax)++;
    // 0042f03f  8987b4000000           -mov dword ptr [edi + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.eax;
L_0x0042f045:
    // 0042f045  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042f04b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f04d  75ce                   -jne 0x42f01d
    if (!cpu.flags.zf)
    {
        goto L_0x0042f01d;
    }
L_0x0042f04f:
    // 0042f04f  8bbfbc000000           -mov edi, dword ptr [edi + 0xbc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 0042f055  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042f057  75b3                   -jne 0x42f00c
    if (!cpu.flags.zf)
    {
        goto L_0x0042f00c;
    }
    // 0042f059  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042f05a:
    // 0042f05a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f05b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f05c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f060  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f065  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042f066  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f067  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f068  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f06a  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0042f06c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042f06e  7505                   -jne 0x42f075
    if (!cpu.flags.zf)
    {
        goto L_0x0042f075;
    }
    // 0042f070  e88bf2ffff             -call 0x42e300
    cpu.esp -= 4;
    sub_42e300(app, cpu);
L_0x0042f075:
    // 0042f075  b938000000             -mov ecx, 0x38
    cpu.ecx = 56 /*0x38*/;
    // 0042f07a  e811e7ffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042f07f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042f081  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f083  750d                   -jne 0x42f092
    if (!cpu.flags.zf)
    {
        goto L_0x0042f092;
    }
    // 0042f085  6874744900             -push 0x497474
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813940 /*0x497474*/;
    cpu.esp -= 4;
    // 0042f08a  e8815bffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f08f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042f092:
    // 0042f092  8d560c                 -lea edx, [esi + 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042f095  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042f097  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0042f099:
    // 0042f099  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042f09b  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0042f09e  40                     -inc eax
    (cpu.eax)++;
    // 0042f09f  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042f0a1  75f6                   -jne 0x42f099
    if (!cpu.flags.zf)
    {
        goto L_0x0042f099;
    }
    // 0042f0a3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f0a7  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0042f0aa  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0042f0ac  c7463400000000         -mov dword ptr [esi + 0x34], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 0042f0b3  c7463000000000         -mov dword ptr [esi + 0x30], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0042f0ba  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f0bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f0c0  8b4840                 -mov ecx, dword ptr [eax + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0042f0c3  897040                 -mov dword ptr [eax + 0x40], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0042f0c6  894e34                 -mov dword ptr [esi + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 0042f0c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f0ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f0cb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42f0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f0d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042f0d3  e808000000             -call 0x42f0e0
    cpu.esp -= 4;
    sub_42f0e0(app, cpu);
    // 0042f0d8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f0da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f0db  e980010000             -jmp 0x42f260
    return sub_42f260(app, cpu);
}

/* align: skip  */
void Application::sub_42f0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0e0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042f0e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042f0e4  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042f0e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f0e7  8b7340                 -mov esi, dword ptr [ebx + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */);
    // 0042f0ea  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f0ec  0f84cc000000           -je 0x42f1be
    if (cpu.flags.zf)
    {
        goto L_0x0042f1be;
    }
    // 0042f0f2  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042f0f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f0f7  0f84c1000000           -je 0x42f1be
    if (cpu.flags.zf)
    {
        goto L_0x0042f1be;
    }
    // 0042f0fd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042f0fe  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042f100  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f102  0f84b2000000           -je 0x42f1ba
    if (cpu.flags.zf)
    {
        goto L_0x0042f1ba;
    }
    // 0042f108  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042f109:
    // 0042f109  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0042f10c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f10e  7d0b                   -jge 0x42f11b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042f11b;
    }
    // 0042f110  8d4e0c                 -lea ecx, [esi + 0xc]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042f113  e878380000             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 0042f118  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0042f11b:
    // 0042f11b  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0042f11e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042f120  7d11                   -jge 0x42f133
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042f133;
    }
    // 0042f122  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042f125  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f126  68dc744900             -push 0x4974dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814044 /*0x4974dc*/;
    cpu.esp -= 4;
    // 0042f12b  e8e05affff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f130  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0042f133:
    // 0042f133  833e01                 +cmp dword ptr [esi], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042f136  7575                   -jne 0x42f1ad
    if (!cpu.flags.zf)
    {
        goto L_0x0042f1ad;
    }
    // 0042f138  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042f13d  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0042f140  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0042f146  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042f14a  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0042f14d  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0042f153  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0042f157  8b04b8                 -mov eax, dword ptr [eax + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0042f15a  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042f15d  8b88d8000000           -mov ecx, dword ptr [eax + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(216) /* 0xd8 */);
    // 0042f163  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0042f167  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f16b  e860000000             -call 0x42f1d0
    cpu.esp -= 4;
    sub_42f1d0(app, cpu);
    // 0042f170  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042f172  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042f174  7511                   -jne 0x42f187
    if (!cpu.flags.zf)
    {
        goto L_0x0042f187;
    }
    // 0042f176  8d560c                 -lea edx, [esi + 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042f179  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042f17a  68b0744900             -push 0x4974b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814000 /*0x4974b0*/;
    cpu.esp -= 4;
    // 0042f17f  e88c5affff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f184  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0042f187:
    // 0042f187  8b8794000000           -mov eax, dword ptr [edi + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(148) /* 0x94 */);
    // 0042f18d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f18f  740d                   -je 0x42f19e
    if (cpu.flags.zf)
    {
        goto L_0x0042f19e;
    }
    // 0042f191  688c744900             -push 0x49748c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4813964 /*0x49748c*/;
    cpu.esp -= 4;
    // 0042f196  e8755affff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f19b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042f19e:
    // 0042f19e  89b794000000           -mov dword ptr [edi + 0x94], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(148) /* 0x94 */) = cpu.esi;
    // 0042f1a4  897e2c                 -mov dword ptr [esi + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0042f1a7  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0042f1ad:
    // 0042f1ad  8b7634                 -mov esi, dword ptr [esi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0042f1b0  45                     -inc ebp
    (cpu.ebp)++;
    // 0042f1b1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f1b3  0f8550ffffff           -jne 0x42f109
    if (!cpu.flags.zf)
    {
        goto L_0x0042f109;
    }
    // 0042f1b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042f1ba:
    // 0042f1ba  896b3c                 -mov dword ptr [ebx + 0x3c], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */) = cpu.ebp;
    // 0042f1bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042f1be:
    // 0042f1be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f1bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f1c0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042f1c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f1d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f1d1  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042f1d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f1d4  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042f1d6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f1d8  7417                   -je 0x42f1f1
    if (cpu.flags.zf)
    {
        goto L_0x0042f1f1;
    }
L_0x0042f1da:
    // 0042f1da  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042f1dc  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042f1de  e81d000000             -call 0x42f200
    cpu.esp -= 4;
    sub_42f200(app, cpu);
    // 0042f1e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f1e5  750f                   -jne 0x42f1f6
    if (!cpu.flags.zf)
    {
        goto L_0x0042f1f6;
    }
    // 0042f1e7  8bb698000000           -mov esi, dword ptr [esi + 0x98]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 0042f1ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f1ef  75e9                   -jne 0x42f1da
    if (!cpu.flags.zf)
    {
        goto L_0x0042f1da;
    }
L_0x0042f1f1:
    // 0042f1f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f1f2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042f1f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f1f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042f1f6:
    // 0042f1f6  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042f1f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f1f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f1fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f200  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042f203  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f204  8bba80000000           -mov edi, dword ptr [edx + 0x80]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0042f20a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042f20c  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042f210  3bf8                   +cmp edi, eax
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
    // 0042f212  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042f216  7e3c                   -jle 0x42f254
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042f254;
    }
    // 0042f218  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042f219  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042f21a  8baa84000000           -mov ebp, dword ptr [edx + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */);
    // 0042f220  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f221  8bdd                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
L_0x0042f223:
    // 0042f223  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042f226  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042f228  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042f229  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042f22b  8d0452                 -lea eax, [edx + edx*2]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 2);
    // 0042f22e  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042f230  8d4c8500               -lea ecx, [ebp + eax*4]
    cpu.ecx = x86::reg32(cpu.ebp + cpu.eax * 4);
    // 0042f234  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042f235  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042f239  e822f3ffff             -call 0x42e560
    cpu.esp -= 4;
    sub_42e560(app, cpu);
    // 0042f23e  83c30c                 -add ebx, 0xc
    (cpu.ebx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042f241  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f245  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042f247  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042f249  3bc7                   +cmp eax, edi
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
    // 0042f24b  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042f24f  7cd2                   -jl 0x42f223
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042f223;
    }
    // 0042f251  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f252  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f253  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042f254:
    // 0042f254  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042f258  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f259  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0042f25c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042f25f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f260  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f261  b916000000             -mov ecx, 0x16
    cpu.ecx = 22 /*0x16*/;
    // 0042f266  e8950b0000             -call 0x42fe00
    cpu.esp -= 4;
    sub_42fe00(app, cpu);
    // 0042f26b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f26d  7420                   -je 0x42f28f
    if (cpu.flags.zf)
    {
        goto L_0x0042f28f;
    }
    // 0042f26f  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 0042f275  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0042f27a  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0042f27c  e87f0b0000             -call 0x42fe00
    cpu.esp -= 4;
    sub_42fe00(app, cpu);
    // 0042f281  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f283  740a                   -je 0x42f28f
    if (cpu.flags.zf)
    {
        goto L_0x0042f28f;
    }
    // 0042f285  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f287  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042f289  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f28a  e981e5ffff             -jmp 0x42d810
    return sub_42d810(app, cpu);
L_0x0042f28f:
    // 0042f28f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f290  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f2a0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f2a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f2a6  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042f2a8  8b4040                 -mov eax, dword ptr [eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0042f2ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f2ad  740c                   -je 0x42f2bb
    if (cpu.flags.zf)
    {
        goto L_0x0042f2bb;
    }
L_0x0042f2af:
    // 0042f2af  397008                 +cmp dword ptr [eax + 8], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042f2b2  741f                   -je 0x42f2d3
    if (cpu.flags.zf)
    {
        goto L_0x0042f2d3;
    }
    // 0042f2b4  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0042f2b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f2b9  75f4                   -jne 0x42f2af
    if (!cpu.flags.zf)
    {
        goto L_0x0042f2af;
    }
L_0x0042f2bb:
    // 0042f2bb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f2bd  e80e3a0000             -call 0x432cd0
    cpu.esp -= 4;
    sub_432cd0(app, cpu);
    // 0042f2c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f2c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f2c4  6814754900             -push 0x497514
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814100 /*0x497514*/;
    cpu.esp -= 4;
    // 0042f2c9  e84259ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f2ce  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042f2d1:
    // 0042f2d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f2d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042f2d3:
    // 0042f2d3  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042f2d5  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0042f2d7  3bca                   +cmp ecx, edx
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
    // 0042f2d9  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0042f2dc  74f3                   -je 0x42f2d1
    if (cpu.flags.zf)
    {
        goto L_0x0042f2d1;
    }
    // 0042f2de  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f2e4  894244                 -mov dword ptr [edx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0042f2e7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042f2e9  83f901                 +cmp ecx, 1
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
    // 0042f2ec  75e3                   -jne 0x42f2d1
    if (!cpu.flags.zf)
    {
        goto L_0x0042f2d1;
    }
    // 0042f2ee  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042f2f0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f2f5  8b4848                 -mov ecx, dword ptr [eax + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0042f2f8  e883e5ffff             -call 0x42d880
    cpu.esp -= 4;
    sub_42d880(app, cpu);
    // 0042f2fd  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f303  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f304  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0042f307  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f310  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f315  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042f318  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042f319  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f31a  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042f31c  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0042f31f  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042f322  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042f324  0f84f6000000           -je 0x42f420
    if (cpu.flags.zf)
    {
        goto L_0x0042f420;
    }
    // 0042f32a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042f32b  8b6828                 -mov ebp, dword ptr [eax + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042f32e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f32f  e8ec010000             -call 0x42f520
    cpu.esp -= 4;
    sub_42f520(app, cpu);
    // 0042f334  8b8fd4000000           -mov ecx, dword ptr [edi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 0042f33a  8b97d8000000           -mov edx, dword ptr [edi + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */);
    // 0042f340  8b87d0000000           -mov eax, dword ptr [edi + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */);
    // 0042f346  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0042f34a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0042f34e  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042f352  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042f354  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0042f358  e853f90200             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0042f35d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042f361  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042f365  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042f369  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042f36d  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f372  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0042f376  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0042f37a  8b7020                 -mov esi, dword ptr [eax + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0042f37d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f37f  743e                   -je 0x42f3bf
    if (cpu.flags.zf)
    {
        goto L_0x0042f3bf;
    }
L_0x0042f381:
    // 0042f381  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042f387  83f814                 +cmp eax, 0x14
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
    // 0042f38a  7429                   -je 0x42f3b5
    if (cpu.flags.zf)
    {
        goto L_0x0042f3b5;
    }
    // 0042f38c  83f815                 +cmp eax, 0x15
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042f38f  7424                   -je 0x42f3b5
    if (cpu.flags.zf)
    {
        goto L_0x0042f3b5;
    }
    // 0042f391  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042f393  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f397  e864f1ffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042f39c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f39e  7415                   -je 0x42f3b5
    if (cpu.flags.zf)
    {
        goto L_0x0042f3b5;
    }
    // 0042f3a0  8b86b4000000           -mov eax, dword ptr [esi + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0042f3a6  3bc3                   +cmp eax, ebx
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
    // 0042f3a8  7e0b                   -jle 0x42f3b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042f3b5;
    }
    // 0042f3aa  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f3b0  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042f3b2  897128                 -mov dword ptr [ecx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.esi;
L_0x0042f3b5:
    // 0042f3b5  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042f3bb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f3bd  75c2                   -jne 0x42f381
    if (!cpu.flags.zf)
    {
        goto L_0x0042f381;
    }
L_0x0042f3bf:
    // 0042f3bf  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f3c5  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042f3c7  8b4228                 -mov eax, dword ptr [edx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0042f3ca  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042f3cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f3cd  e84eeaffff             -call 0x42de20
    cpu.esp -= 4;
    sub_42de20(app, cpu);
    // 0042f3d2  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f3d8  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0042f3db  c782b000000001000000   -mov dword ptr [edx + 0xb0], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(176) /* 0xb0 */) = 1 /*0x1*/;
    // 0042f3e5  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f3eb  e850010000             -call 0x42f540
    cpu.esp -= 4;
    sub_42f540(app, cpu);
    // 0042f3f0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f3f5  8b4828                 -mov ecx, dword ptr [eax + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042f3f8  e8e3070000             -call 0x42fbe0
    cpu.esp -= 4;
    sub_42fbe0(app, cpu);
    // 0042f3fd  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0042f403  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042f404  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042f407  e834390200             -call 0x452d40
    cpu.esp -= 4;
    sub_452d40(app, cpu);
    // 0042f40c  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f412  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0042f417  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042f419  e812000000             -call 0x42f430
    cpu.esp -= 4;
    sub_42f430(app, cpu);
    // 0042f41e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f41f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042f420:
    // 0042f420  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f421  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f422  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042f425  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042f431  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f432  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f433  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042f435  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0042f437  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0042f43a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f43c  7436                   -je 0x42f474
    if (cpu.flags.zf)
    {
        goto L_0x0042f474;
    }
L_0x0042f43e:
    // 0042f43e  8b86b0000000           -mov eax, dword ptr [esi + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
    // 0042f444  8b8eac000000           -mov ecx, dword ptr [esi + 0xac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 0042f44a  3bc1                   +cmp eax, ecx
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
    // 0042f44c  7404                   -je 0x42f452
    if (cpu.flags.zf)
    {
        goto L_0x0042f452;
    }
    // 0042f44e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f450  7405                   -je 0x42f457
    if (cpu.flags.zf)
    {
        goto L_0x0042f457;
    }
L_0x0042f452:
    // 0042f452  83fb01                 +cmp ebx, 1
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
    // 0042f455  7513                   -jne 0x42f46a
    if (!cpu.flags.zf)
    {
        goto L_0x0042f46a;
    }
L_0x0042f457:
    // 0042f457  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f459  e852000000             -call 0x42f4b0
    cpu.esp -= 4;
    sub_42f4b0(app, cpu);
    // 0042f45e  8b86b0000000           -mov eax, dword ptr [esi + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
    // 0042f464  8986ac000000           -mov dword ptr [esi + 0xac], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.eax;
L_0x0042f46a:
    // 0042f46a  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042f470  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f472  75ca                   -jne 0x42f43e
    if (!cpu.flags.zf)
    {
        goto L_0x0042f43e;
    }
L_0x0042f474:
    // 0042f474  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0042f477  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f479  7426                   -je 0x42f4a1
    if (cpu.flags.zf)
    {
        goto L_0x0042f4a1;
    }
L_0x0042f47b:
    // 0042f47b  83beb000000001         +cmp dword ptr [esi + 0xb0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042f482  7513                   -jne 0x42f497
    if (!cpu.flags.zf)
    {
        goto L_0x0042f497;
    }
    // 0042f484  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f486  e825000000             -call 0x42f4b0
    cpu.esp -= 4;
    sub_42f4b0(app, cpu);
    // 0042f48b  8b8eb0000000           -mov ecx, dword ptr [esi + 0xb0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
    // 0042f491  898eac000000           -mov dword ptr [esi + 0xac], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.ecx;
L_0x0042f497:
    // 0042f497  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042f49d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f49f  75da                   -jne 0x42f47b
    if (!cpu.flags.zf)
    {
        goto L_0x0042f47b;
    }
L_0x0042f4a1:
    // 0042f4a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f4a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f4a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f4a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f4b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f4b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f4b2  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042f4b4  8bb790000000           -mov esi, dword ptr [edi + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */);
    // 0042f4ba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f4bc  7414                   -je 0x42f4d2
    if (cpu.flags.zf)
    {
        goto L_0x0042f4d2;
    }
L_0x0042f4be:
    // 0042f4be  8b97b0000000           -mov edx, dword ptr [edi + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(176) /* 0xb0 */);
    // 0042f4c4  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042f4c6  e815000000             -call 0x42f4e0
    cpu.esp -= 4;
    sub_42f4e0(app, cpu);
    // 0042f4cb  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042f4ce  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f4d0  75ec                   -jne 0x42f4be
    if (!cpu.flags.zf)
    {
        goto L_0x0042f4be;
    }
L_0x0042f4d2:
    // 0042f4d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f4d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f4d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f4e0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042f4e2  7517                   -jne 0x42f4fb
    if (!cpu.flags.zf)
    {
        goto L_0x0042f4fb;
    }
    // 0042f4e4  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0042f4e7  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042f4ed  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042f4f0  8188a802000000000040   -or dword ptr [eax + 0x2a8], 0x40000000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) |= x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
    // 0042f4fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042f4fb:
    // 0042f4fb  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0042f4fe  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042f503  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0042f506  81a0a8020000ffffffbf   -and dword ptr [eax + 0x2a8], 0xbfffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) &= x86::reg32(x86::sreg32(3221225471 /*0xbfffffff*/));
    // 0042f510  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f520  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f525  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042f527  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0042f52a  3bc1                   +cmp eax, ecx
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
    // 0042f52c  7410                   -je 0x42f53e
    if (cpu.flags.zf)
    {
        goto L_0x0042f53e;
    }
L_0x0042f52e:
    // 0042f52e  8988b0000000           -mov dword ptr [eax + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
    // 0042f534  8b80bc000000           -mov eax, dword ptr [eax + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0042f53a  3bc1                   +cmp eax, ecx
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
    // 0042f53c  75f0                   -jne 0x42f52e
    if (!cpu.flags.zf)
    {
        goto L_0x0042f52e;
    }
L_0x0042f53e:
    // 0042f53e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f540  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f541  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042f543  e818000000             -call 0x42f560
    cpu.esp -= 4;
    sub_42f560(app, cpu);
    // 0042f548  8b4e4c                 -mov ecx, dword ptr [esi + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 0042f54b  e8600c0000             -call 0x4301b0
    cpu.esp -= 4;
    sub_4301b0(app, cpu);
    // 0042f550  c7464c00000000         -mov dword ptr [esi + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 0042f557  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f559  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f55a  e941000000             -jmp 0x42f5a0
    return sub_42f5a0(app, cpu);
}

/* align: skip  */
void Application::sub_42f560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042f561  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f562  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042f564  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042f566  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0042f569  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f56b  7427                   -je 0x42f594
    if (cpu.flags.zf)
    {
        goto L_0x0042f594;
    }
    // 0042f56d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042f56e:
    // 0042f56e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042f570  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042f573  7515                   -jne 0x42f58a
    if (!cpu.flags.zf)
    {
        goto L_0x0042f58a;
    }
    // 0042f575  8b4e48                 -mov ecx, dword ptr [esi + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0042f578  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042f57b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f57c  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042f57e  e81de3ffff             -call 0x42d8a0
    cpu.esp -= 4;
    sub_42d8a0(app, cpu);
    // 0042f583  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0042f586  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042f588  eb05                   -jmp 0x42f58f
    goto L_0x0042f58f;
L_0x0042f58a:
    // 0042f58a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042f58c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0042f58f:
    // 0042f58f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f591  75db                   -jne 0x42f56e
    if (!cpu.flags.zf)
    {
        goto L_0x0042f56e;
    }
    // 0042f593  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042f594:
    // 0042f594  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f595  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f596  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f5a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042f5a1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042f5a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042f5a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f5a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f5a5  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042f5a7  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042f5a9  8b5f48                 -mov ebx, dword ptr [edi + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */);
    // 0042f5ac  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042f5ae  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0042f5b2  0f8480000000           -je 0x42f638
    if (cpu.flags.zf)
    {
        goto L_0x0042f638;
    }
    // 0042f5b8  eb04                   -jmp 0x42f5be
    goto L_0x0042f5be;
L_0x0042f5ba:
    // 0042f5ba  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0042f5be:
    // 0042f5be  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042f5c0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042f5c2  750d                   -jne 0x42f5d1
    if (!cpu.flags.zf)
    {
        goto L_0x0042f5d1;
    }
    // 0042f5c4  6888754900             -push 0x497588
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814216 /*0x497588*/;
    cpu.esp -= 4;
    // 0042f5c9  e84256ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f5ce  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042f5d1:
    // 0042f5d1  8b452c                 -mov eax, dword ptr [ebp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0042f5d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f5d6  750d                   -jne 0x42f5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0042f5e5;
    }
    // 0042f5d8  685c754900             -push 0x49755c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814172 /*0x49755c*/;
    cpu.esp -= 4;
    // 0042f5dd  e82e56ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f5e2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042f5e5:
    // 0042f5e5  8b752c                 -mov esi, dword ptr [ebp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0042f5e8  8b868c000000           -mov eax, dword ptr [esi + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0042f5ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f5f0  750d                   -jne 0x42f5ff
    if (!cpu.flags.zf)
    {
        goto L_0x0042f5ff;
    }
    // 0042f5f2  6840754900             -push 0x497540
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814144 /*0x497540*/;
    cpu.esp -= 4;
    // 0042f5f7  e81456ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f5fc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042f5ff:
    // 0042f5ff  8bb68c000000           -mov esi, dword ptr [esi + 0x8c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0042f605  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f607  7424                   -je 0x42f62d
    if (cpu.flags.zf)
    {
        goto L_0x0042f62d;
    }
L_0x0042f609:
    // 0042f609  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042f60b  8b4f4c                 -mov ecx, dword ptr [edi + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */);
    // 0042f60e  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042f610  e86be2ffff             -call 0x42d880
    cpu.esp -= 4;
    sub_42d880(app, cpu);
    // 0042f615  89474c                 -mov dword ptr [edi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0042f618  c783b000000001000000   -mov dword ptr [ebx + 0xb0], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(176) /* 0xb0 */) = 1 /*0x1*/;
    // 0042f622  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042f625  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f627  75e0                   -jne 0x42f609
    if (!cpu.flags.zf)
    {
        goto L_0x0042f609;
    }
    // 0042f629  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0042f62d:
    // 0042f62d  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042f630  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042f632  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0042f636  7582                   -jne 0x42f5ba
    if (!cpu.flags.zf)
    {
        goto L_0x0042f5ba;
    }
L_0x0042f638:
    // 0042f638  f6475010               +test byte ptr [edi + 0x50], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(80) /* 0x50 */) & 16 /*0x10*/));
    // 0042f63c  745e                   -je 0x42f69c
    if (cpu.flags.zf)
    {
        goto L_0x0042f69c;
    }
    // 0042f63e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042f640  7506                   -jne 0x42f648
    if (!cpu.flags.zf)
    {
        goto L_0x0042f648;
    }
    // 0042f642  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0042f646  eb07                   -jmp 0x42f64f
    goto L_0x0042f64f;
L_0x0042f648:
    // 0042f648  8b452c                 -mov eax, dword ptr [ebp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0042f64b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042f64f:
    // 0042f64f  8b6f10                 -mov ebp, dword ptr [edi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0042f652  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042f654  7446                   -je 0x42f69c
    if (cpu.flags.zf)
    {
        goto L_0x0042f69c;
    }
L_0x0042f656:
    // 0042f656  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0042f659  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f65d  3bc1                   +cmp eax, ecx
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
    // 0042f65f  7434                   -je 0x42f695
    if (cpu.flags.zf)
    {
        goto L_0x0042f695;
    }
    // 0042f661  8b8894000000           -mov ecx, dword ptr [eax + 0x94]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 0042f667  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042f669  752a                   -jne 0x42f695
    if (!cpu.flags.zf)
    {
        goto L_0x0042f695;
    }
    // 0042f66b  8bb08c000000           -mov esi, dword ptr [eax + 0x8c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 0042f671  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f673  7420                   -je 0x42f695
    if (cpu.flags.zf)
    {
        goto L_0x0042f695;
    }
L_0x0042f675:
    // 0042f675  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042f677  8b4f4c                 -mov ecx, dword ptr [edi + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */);
    // 0042f67a  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042f67c  e8ffe1ffff             -call 0x42d880
    cpu.esp -= 4;
    sub_42d880(app, cpu);
    // 0042f681  89474c                 -mov dword ptr [edi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0042f684  c783b000000001000000   -mov dword ptr [ebx + 0xb0], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(176) /* 0xb0 */) = 1 /*0x1*/;
    // 0042f68e  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042f691  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042f693  75e0                   -jne 0x42f675
    if (!cpu.flags.zf)
    {
        goto L_0x0042f675;
    }
L_0x0042f695:
    // 0042f695  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0042f698  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042f69a  75ba                   -jne 0x42f656
    if (!cpu.flags.zf)
    {
        goto L_0x0042f656;
    }
L_0x0042f69c:
    // 0042f69c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f69d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f69e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f69f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f6a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f6a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f6b0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f6b5  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042f6b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f6b9  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042f6bb  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0042f6be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042f6c0  0f848e000000           -je 0x42f754
    if (cpu.flags.zf)
    {
        goto L_0x0042f754;
    }
    // 0042f6c6  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042f6c9  a3b8d44a00             -mov dword ptr [0x4ad4b8], eax
    app->getMemory<x86::reg32>(x86::reg32(4904120) /* 0x4ad4b8 */) = cpu.eax;
    // 0042f6ce  8b8ed0000000           -mov ecx, dword ptr [esi + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0042f6d4  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0042f6da  8b86d8000000           -mov eax, dword ptr [esi + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0042f6e0  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0042f6e4  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0042f6e8  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f6ec  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f6ee  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042f6f2  e8b9f50200             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0042f6f7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042f6fb  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042f6ff  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042f703  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0042f707  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f70d  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042f711  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042f715  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042f719  e812010000             -call 0x42f830
    cpu.esp -= 4;
    sub_42f830(app, cpu);
    // 0042f71e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f720  e83b000000             -call 0x42f760
    cpu.esp -= 4;
    sub_42f760(app, cpu);
    // 0042f725  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f72b  e8200a0000             -call 0x430150
    cpu.esp -= 4;
    sub_430150(app, cpu);
    // 0042f730  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f736  c7414400000000         -mov dword ptr [ecx + 0x44], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0042f73d  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f743  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f745  8b4228                 -mov eax, dword ptr [edx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0042f748  8b15b8d44a00           -mov edx, dword ptr [0x4ad4b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904120) /* 0x4ad4b8 */);
    // 0042f74e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f74f  e8cce6ffff             -call 0x42de20
    cpu.esp -= 4;
    sub_42de20(app, cpu);
L_0x0042f754:
    // 0042f754  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f755  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042f758  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f760  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042f763  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f764  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042f766  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0042f76c  8b96d8000000           -mov edx, dword ptr [esi + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0042f772  8b86d0000000           -mov eax, dword ptr [esi + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0042f778  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0042f77c  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0042f780  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f784  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f786  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0042f78a  e821f50200             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0042f78f  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042f793  d825d0d44a00           -fsub dword ptr [0x4ad4d0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4904144) /* 0x4ad4d0 */));
    // 0042f799  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042f79d  d825d4d44a00           -fsub dword ptr [0x4ad4d4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4904148) /* 0x4ad4d4 */));
    // 0042f7a3  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0042f7a7  d825d8d44a00           -fsub dword ptr [0x4ad4d8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4904152) /* 0x4ad4d8 */));
    // 0042f7ad  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042f7b1  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042f7b5  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042f7b9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042f7bd  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042f7bf  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0042f7c1  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0042f7c3  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0042f7c5  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042f7c9  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0042f7cd  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042f7cf  d9c3                   -fld st(3)
    cpu.fpu.push(x86::Float(cpu.fpu.st(3)));
    // 0042f7d1  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 0042f7d3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042f7d5  d81d88774800           -fcomp dword ptr [0x487788]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749192) /* 0x487788 */)));
    cpu.fpu.pop();
    // 0042f7db  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042f7dd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042f7df  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042f7e1  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042f7e6  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042f7e8  7419                   -je 0x42f803
    if (cpu.flags.zf)
    {
        goto L_0x0042f803;
    }
    // 0042f7ea  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f7ef  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042f7f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042f7f4  7414                   -je 0x42f80a
    if (cpu.flags.zf)
    {
        goto L_0x0042f80a;
    }
    // 0042f7f6  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042f7fa  e801edffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042f7ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f801  7507                   -jne 0x42f80a
    if (!cpu.flags.zf)
    {
        goto L_0x0042f80a;
    }
L_0x0042f803:
    // 0042f803  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042f805  e806fbffff             -call 0x42f310
    cpu.esp -= 4;
    sub_42f310(app, cpu);
L_0x0042f80a:
    // 0042f80a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042f80e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042f812  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042f816  890dd0d44a00           -mov dword ptr [0x4ad4d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904144) /* 0x4ad4d0 */) = cpu.ecx;
    // 0042f81c  8915d4d44a00           -mov dword ptr [0x4ad4d4], edx
    app->getMemory<x86::reg32>(x86::reg32(4904148) /* 0x4ad4d4 */) = cpu.edx;
    // 0042f822  a3d8d44a00             -mov dword ptr [0x4ad4d8], eax
    app->getMemory<x86::reg32>(x86::reg32(4904152) /* 0x4ad4d8 */) = cpu.eax;
    // 0042f827  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f828  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042f82b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42f830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f830  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042f833  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f838  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042f839  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042f83a  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042f83e  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0042f841  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042f843  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042f845  3bcd                   +cmp ecx, ebp
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
    // 0042f847  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0042f84b  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0042f84f  7508                   -jne 0x42f859
    if (!cpu.flags.zf)
    {
        goto L_0x0042f859;
    }
    // 0042f851  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f852  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042f854  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f855  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042f858  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042f859:
    // 0042f859  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0042f85c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042f85d  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042f860  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042f861  e84a090000             -call 0x4301b0
    cpu.esp -= 4;
    sub_4301b0(app, cpu);
    // 0042f866  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f86b  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0042f86e  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f874  896950                 -mov dword ptr [ecx + 0x50], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.ebp;
    // 0042f877  8bbe98000000           -mov edi, dword ptr [esi + 0x98]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 0042f87d  3bfd                   +cmp edi, ebp
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
    // 0042f87f  0f84ca000000           -je 0x42f94f
    if (cpu.flags.zf)
    {
        goto L_0x0042f94f;
    }
L_0x0042f885:
    // 0042f885  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0042f887  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042f88b  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042f88d  89ae9c000000           -mov dword ptr [esi + 0x9c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = cpu.ebp;
    // 0042f893  e868f9ffff             -call 0x42f200
    cpu.esp -= 4;
    sub_42f200(app, cpu);
    // 0042f898  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042f89a  0f848b000000           -je 0x42f92b
    if (cpu.flags.zf)
    {
        goto L_0x0042f92b;
    }
    // 0042f8a0  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0042f8a5  89869c000000           -mov dword ptr [esi + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 0042f8ab  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f8b1  894250                 -mov dword ptr [edx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0042f8b4  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f8b9  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042f8bb  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0042f8be  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f8c4  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0042f8c7  e8b4dfffff             -call 0x42d880
    cpu.esp -= 4;
    sub_42d880(app, cpu);
    // 0042f8cc  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f8d2  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042f8d5  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f8da  396844                 +cmp dword ptr [eax + 0x44], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042f8dd  7509                   -jne 0x42f8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0042f8e8;
    }
    // 0042f8df  8b8e94000000           -mov ecx, dword ptr [esi + 0x94]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 0042f8e5  894844                 -mov dword ptr [eax + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.ecx;
L_0x0042f8e8:
    // 0042f8e8  3bdd                   +cmp ebx, ebp
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
    // 0042f8ea  751d                   -jne 0x42f909
    if (!cpu.flags.zf)
    {
        goto L_0x0042f909;
    }
    // 0042f8ec  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042f8f0  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042f8f2  e859010000             -call 0x42fa50
    cpu.esp -= 4;
    sub_42fa50(app, cpu);
    // 0042f8f7  3bc5                   +cmp eax, ebp
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
    // 0042f8f9  7409                   -je 0x42f904
    if (cpu.flags.zf)
    {
        goto L_0x0042f904;
    }
    // 0042f8fb  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f901  894228                 -mov dword ptr [edx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0042f904:
    // 0042f904  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0042f909:
    // 0042f909  39aea0000000           +cmp dword ptr [esi + 0xa0], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042f90f  7533                   -jne 0x42f944
    if (!cpu.flags.zf)
    {
        goto L_0x0042f944;
    }
    // 0042f911  8b869c000000           -mov eax, dword ptr [esi + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */);
    // 0042f917  c786a000000001000000   -mov dword ptr [esi + 0xa0], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = 1 /*0x1*/;
    // 0042f921  0c04                   +or al, 4
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0042f923  89869c000000           -mov dword ptr [esi + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 0042f929  eb19                   -jmp 0x42f944
    goto L_0x0042f944;
L_0x0042f92b:
    // 0042f92b  83bea000000001         +cmp dword ptr [esi + 0xa0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042f932  7510                   -jne 0x42f944
    if (!cpu.flags.zf)
    {
        goto L_0x0042f944;
    }
    // 0042f934  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f938  89aea0000000           -mov dword ptr [esi + 0xa0], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = cpu.ebp;
    // 0042f93e  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0042f940  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042f944:
    // 0042f944  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042f947  3bfd                   +cmp edi, ebp
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
    // 0042f949  0f8536ffffff           -jne 0x42f885
    if (!cpu.flags.zf)
    {
        goto L_0x0042f885;
    }
L_0x0042f94f:
    // 0042f94f  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f955  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042f959  8b4144                 -mov eax, dword ptr [ecx + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0042f95c  3bc5                   +cmp eax, ebp
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
    // 0042f95e  741a                   -je 0x42f97a
    if (cpu.flags.zf)
    {
        goto L_0x0042f97a;
    }
    // 0042f960  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042f962  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f966  3bcd                   +cmp ecx, ebp
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
    // 0042f968  7508                   -jne 0x42f972
    if (!cpu.flags.zf)
    {
        goto L_0x0042f972;
    }
    // 0042f96a  0c02                   +or al, 2
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0042f96c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042f970  eb16                   -jmp 0x42f988
    goto L_0x0042f988;
L_0x0042f972:
    // 0042f972  0c01                   +or al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0042f974  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042f978  eb0e                   -jmp 0x42f988
    goto L_0x0042f988;
L_0x0042f97a:
    // 0042f97a  f644241008             +test byte ptr [esp + 0x10], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 8 /*0x8*/));
    // 0042f97f  7407                   -je 0x42f988
    if (cpu.flags.zf)
    {
        goto L_0x0042f988;
    }
    // 0042f981  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042f983  e818010000             -call 0x42faa0
    cpu.esp -= 4;
    sub_42faa0(app, cpu);
L_0x0042f988:
    // 0042f988  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042f98c  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0042f98f  7440                   -je 0x42f9d1
    if (cpu.flags.zf)
    {
        goto L_0x0042f9d1;
    }
    // 0042f991  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f996  8b7044                 -mov esi, dword ptr [eax + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0042f999  3bf5                   +cmp esi, ebp
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
    // 0042f99b  750d                   -jne 0x42f9aa
    if (!cpu.flags.zf)
    {
        goto L_0x0042f9aa;
    }
    // 0042f99d  68ac754900             -push 0x4975ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814252 /*0x4975ac*/;
    cpu.esp -= 4;
    // 0042f9a2  e86952ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f9a7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042f9aa:
    // 0042f9aa  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042f9ac  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042f9af  3bc8                   +cmp ecx, eax
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
    // 0042f9b1  0f8486000000           -je 0x42fa3d
    if (cpu.flags.zf)
    {
        goto L_0x0042fa3d;
    }
    // 0042f9b7  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042f9ba  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f9c0  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042f9c2  e8d9000000             -call 0x42faa0
    cpu.esp -= 4;
    sub_42faa0(app, cpu);
    // 0042f9c7  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042f9c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f9ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f9cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f9cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f9cd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042f9d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042f9d1:
    // 0042f9d1  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0042f9d4  743d                   -je 0x42fa13
    if (cpu.flags.zf)
    {
        goto L_0x0042fa13;
    }
    // 0042f9d6  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042f9dc  8b7144                 -mov esi, dword ptr [ecx + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0042f9df  3bf5                   +cmp esi, ebp
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
    // 0042f9e1  750d                   -jne 0x42f9f0
    if (!cpu.flags.zf)
    {
        goto L_0x0042f9f0;
    }
    // 0042f9e3  68ac754900             -push 0x4975ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814252 /*0x4975ac*/;
    cpu.esp -= 4;
    // 0042f9e8  e82352ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042f9ed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042f9f0:
    // 0042f9f0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042f9f2  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042f9f5  3bc8                   +cmp ecx, eax
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
    // 0042f9f7  7444                   -je 0x42fa3d
    if (cpu.flags.zf)
    {
        goto L_0x0042fa3d;
    }
    // 0042f9f9  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042f9fc  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fa02  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042fa04  e897000000             -call 0x42faa0
    cpu.esp -= 4;
    sub_42faa0(app, cpu);
    // 0042fa09  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042fa0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa0f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042fa12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042fa13:
    // 0042fa13  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042fa17  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0042fa1a  3bf5                   +cmp esi, ebp
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
    // 0042fa1c  741f                   -je 0x42fa3d
    if (cpu.flags.zf)
    {
        goto L_0x0042fa3d;
    }
L_0x0042fa1e:
    // 0042fa1e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042fa20  f6809c00000004         +test byte ptr [eax + 0x9c], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(156) /* 0x9c */) & 4 /*0x4*/));
    // 0042fa27  740d                   -je 0x42fa36
    if (cpu.flags.zf)
    {
        goto L_0x0042fa36;
    }
    // 0042fa29  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fa2f  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042fa31  e86a000000             -call 0x42faa0
    cpu.esp -= 4;
    sub_42faa0(app, cpu);
L_0x0042fa36:
    // 0042fa36  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042fa39  3bf5                   +cmp esi, ebp
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
    // 0042fa3b  75e1                   -jne 0x42fa1e
    if (!cpu.flags.zf)
    {
        goto L_0x0042fa1e;
    }
L_0x0042fa3d:
    // 0042fa3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa3f  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042fa41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa43  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042fa46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fa50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fa50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042fa51  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042fa52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042fa53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042fa54  8bba8c000000           -mov edi, dword ptr [edx + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(140) /* 0x8c */);
    // 0042fa5a  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042fa5c  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042fa5f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042fa61  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0042fa65  7428                   -je 0x42fa8f
    if (cpu.flags.zf)
    {
        goto L_0x0042fa8f;
    }
    // 0042fa67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042fa68:
    // 0042fa68  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0042fa6a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042fa6e  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042fa70  e88beaffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042fa75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fa77  740e                   -je 0x42fa87
    if (cpu.flags.zf)
    {
        goto L_0x0042fa87;
    }
    // 0042fa79  8b86b4000000           -mov eax, dword ptr [esi + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0042fa7f  3bc3                   +cmp eax, ebx
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
    // 0042fa81  7e04                   -jle 0x42fa87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042fa87;
    }
    // 0042fa83  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042fa85  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x0042fa87:
    // 0042fa87  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042fa8a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042fa8c  75da                   -jne 0x42fa68
    if (!cpu.flags.zf)
    {
        goto L_0x0042fa68;
    }
    // 0042fa8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042fa8f:
    // 0042fa8f  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0042fa91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fa95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42faa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042faa0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042faa5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042faa6  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042faa8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042faa9  8b4828                 -mov ecx, dword ptr [eax + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042faac  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042faae  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042fab0  750d                   -jne 0x42fabf
    if (!cpu.flags.zf)
    {
        goto L_0x0042fabf;
    }
    // 0042fab2  68c0754900             -push 0x4975c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814272 /*0x4975c0*/;
    cpu.esp -= 4;
    // 0042fab7  e85451ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042fabc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042fabf:
    // 0042fabf  e85cfaffff             -call 0x42f520
    cpu.esp -= 4;
    sub_42f520(app, cpu);
    // 0042fac4  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042fac6  e825000000             -call 0x42faf0
    cpu.esp -= 4;
    sub_42faf0(app, cpu);
    // 0042facb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042facd  e86efaffff             -call 0x42f540
    cpu.esp -= 4;
    sub_42f540(app, cpu);
    // 0042fad2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042fad4  e8e7000000             -call 0x42fbc0
    cpu.esp -= 4;
    sub_42fbc0(app, cpu);
    // 0042fad9  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0042fadb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042fadd  e84ef9ffff             -call 0x42f430
    cpu.esp -= 4;
    sub_42f430(app, cpu);
    // 0042fae2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042fae4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fae5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fae6  e945000000             -jmp 0x42fb30
    return sub_42fb30(app, cpu);
}

/* align: skip  */
void Application::sub_42faf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042faf0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042faf5  8b4828                 -mov ecx, dword ptr [eax + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042faf8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042fafa  7520                   -jne 0x42fb1c
    if (!cpu.flags.zf)
    {
        goto L_0x0042fb1c;
    }
    // 0042fafc  68d4754900             -push 0x4975d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814292 /*0x4975d4*/;
    cpu.esp -= 4;
    // 0042fb01  e80a51ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042fb06  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fb0b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042fb0e  8b4828                 -mov ecx, dword ptr [eax + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042fb11  c781b000000001000000   -mov dword ptr [ecx + 0xb0], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = 1 /*0x1*/;
    // 0042fb1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042fb1c:
    // 0042fb1c  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042fb1f  c782b000000001000000   -mov dword ptr [edx + 0xb0], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(176) /* 0xb0 */) = 1 /*0x1*/;
    // 0042fb29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fb30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042fb31  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fb36  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042fb37  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042fb39  8b4828                 -mov ecx, dword ptr [eax + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042fb3c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042fb3e  750f                   -jne 0x42fb4f
    if (!cpu.flags.zf)
    {
        goto L_0x0042fb4f;
    }
    // 0042fb40  680000fa44             -push 0x44fa0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1157234688 /*0x44fa0000*/;
    cpu.esp -= 4;
    // 0042fb45  e8f6310200             -call 0x452d40
    cpu.esp -= 4;
    sub_452d40(app, cpu);
    // 0042fb4a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042fb4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fb4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fb4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042fb4f:
    // 0042fb4f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042fb50  e88b000000             -call 0x42fbe0
    cpu.esp -= 4;
    sub_42fbe0(app, cpu);
    // 0042fb55  e836720400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042fb5a  8b4f4c                 -mov ecx, dword ptr [edi + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */);
    // 0042fb5d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042fb5f  e82c000000             -call 0x42fb90
    cpu.esp -= 4;
    sub_42fb90(app, cpu);
    // 0042fb64  3bf0                   +cmp esi, eax
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
    // 0042fb66  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042fb6a  7e04                   -jle 0x42fb70
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042fb70;
    }
    // 0042fb6c  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x0042fb70:
    // 0042fb70  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0042fb74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042fb75  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0042fb7b  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042fb7e  e8bd310200             -call 0x452d40
    cpu.esp -= 4;
    sub_452d40(app, cpu);
    // 0042fb83  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042fb85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fb86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fb87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fb88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fb90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042fb91  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042fb93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042fb94  bffeffffff             -mov edi, 0xfffffffe
    cpu.edi = 4294967294 /*0xfffffffe*/;
    // 0042fb99  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042fb9b  7419                   -je 0x42fbb6
    if (cpu.flags.zf)
    {
        goto L_0x0042fbb6;
    }
L_0x0042fb9d:
    // 0042fb9d  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042fb9f  e83c000000             -call 0x42fbe0
    cpu.esp -= 4;
    sub_42fbe0(app, cpu);
    // 0042fba4  e8e7710400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042fba9  3bc7                   +cmp eax, edi
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
    // 0042fbab  7e02                   -jle 0x42fbaf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042fbaf;
    }
    // 0042fbad  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0042fbaf:
    // 0042fbaf  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042fbb2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042fbb4  75e7                   -jne 0x42fb9d
    if (!cpu.flags.zf)
    {
        goto L_0x0042fb9d;
    }
L_0x0042fbb6:
    // 0042fbb6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042fbb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fbb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fbba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fbc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fbc0  8b414c                 -mov eax, dword ptr [ecx + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0042fbc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fbc5  7414                   -je 0x42fbdb
    if (cpu.flags.zf)
    {
        goto L_0x0042fbdb;
    }
    // 0042fbc7  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0042fbcc:
    // 0042fbcc  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042fbce  898ab0000000           -mov dword ptr [edx + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
    // 0042fbd4  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042fbd7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fbd9  75f1                   -jne 0x42fbcc
    if (!cpu.flags.zf)
    {
        goto L_0x0042fbcc;
    }
L_0x0042fbdb:
    // 0042fbdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fbe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0042fbe0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042fbe2  7507                   -jne 0x42fbeb
    if (!cpu.flags.zf)
    {
        goto L_0x0042fbeb;
    }
    // 0042fbe4  d905d0754800           -fld dword ptr [0x4875d0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */)));
    // 0042fbea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042fbeb:
    // 0042fbeb  8b8180000000           -mov eax, dword ptr [ecx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0042fbf1  83f817                 +cmp eax, 0x17
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(23 /*0x17*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042fbf4  7742                   -ja 0x42fc38
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042fc38;
    }
    // 0042fbf6  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0042fbf8  8a8864fc4200           -mov cl, byte ptr [eax + 0x42fc64]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4389988) /* 0x42fc64 */);
    // 0042fbfe  ff248d40fc4200         -jmp dword ptr [ecx*4 + 0x42fc40]
    cpu.ip = app->getMemory<x86::reg32>(4389952 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0042fc05:
    // 0042fc05  803d101552001e         +cmp byte ptr [0x521510], 0x1e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(30 /*0x1e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042fc0c  7307                   -jae 0x42fc15
    if (!cpu.flags.cf)
    {
        goto L_0x0042fc15;
    }
  [[fallthrough]];
  case 0x0042fc0e:
    // 0042fc0e  d90504794800           -fld dword ptr [0x487904]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4749572) /* 0x487904 */)));
    // 0042fc14  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042fc15:
L_0x0042fc15:
    // 0042fc15  d90510754800           -fld dword ptr [0x487510]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748560) /* 0x487510 */)));
    // 0042fc1b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042fc1c:
    // 0042fc1c  d90500794800           -fld dword ptr [0x487900]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4749568) /* 0x487900 */)));
    // 0042fc22  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042fc23:
    // 0042fc23  d90504754800           -fld dword ptr [0x487504]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748548) /* 0x487504 */)));
    // 0042fc29  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042fc2a:
    // 0042fc2a  d90518744800           -fld dword ptr [0x487418]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748312) /* 0x487418 */)));
    // 0042fc30  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042fc31:
    // 0042fc31  d90520744800           -fld dword ptr [0x487420]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748320) /* 0x487420 */)));
    // 0042fc37  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042fc38:
L_0x0042fc38:
    // 0042fc38  d905d0754800           -fld dword ptr [0x4875d0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */)));
    // 0042fc3e  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_42fc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fc80  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fc85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fc87  7415                   -je 0x42fc9e
    if (cpu.flags.zf)
    {
        goto L_0x0042fc9e;
    }
    // 0042fc89  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0042fc8c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042fc8e  740e                   -je 0x42fc9e
    if (cpu.flags.zf)
    {
        goto L_0x0042fc9e;
    }
    // 0042fc90  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042fc93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fc95  7407                   -je 0x42fc9e
    if (cpu.flags.zf)
    {
        goto L_0x0042fc9e;
    }
    // 0042fc97  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0042fc9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042fc9e:
    // 0042fc9e  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042fca1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fcb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fcb0  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042fcb3  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0042fcb9  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0042fcbf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042fcc0  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0042fcc4  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0042fcca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042fccb  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0042fccf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042fcd0  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042fcd4  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042fcd6  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042fcd9  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0042fcdd  e8ceef0200             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0042fce2  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042fce6  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042fcea  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042fcee  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0042fcf2  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fcf8  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042fcfc  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0042fd00  8b7120                 -mov esi, dword ptr [ecx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0042fd03  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042fd05  743b                   -je 0x42fd42
    if (cpu.flags.zf)
    {
        goto L_0x0042fd42;
    }
L_0x0042fd07:
    // 0042fd07  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042fd0d  83f814                 +cmp eax, 0x14
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
    // 0042fd10  7422                   -je 0x42fd34
    if (cpu.flags.zf)
    {
        goto L_0x0042fd34;
    }
    // 0042fd12  83f815                 +cmp eax, 0x15
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042fd15  741d                   -je 0x42fd34
    if (cpu.flags.zf)
    {
        goto L_0x0042fd34;
    }
    // 0042fd17  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042fd19  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042fd1d  e8dee7ffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042fd22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fd24  740e                   -je 0x42fd34
    if (cpu.flags.zf)
    {
        goto L_0x0042fd34;
    }
    // 0042fd26  8b86b4000000           -mov eax, dword ptr [esi + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0042fd2c  3bc7                   +cmp eax, edi
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
    // 0042fd2e  7e04                   -jle 0x42fd34
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042fd34;
    }
    // 0042fd30  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042fd32  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0042fd34:
    // 0042fd34  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042fd3a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042fd3c  75c9                   -jne 0x42fd07
    if (!cpu.flags.zf)
    {
        goto L_0x0042fd07;
    }
    // 0042fd3e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042fd40  750a                   -jne 0x42fd4c
    if (!cpu.flags.zf)
    {
        goto L_0x0042fd4c;
    }
L_0x0042fd42:
    // 0042fd42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fd43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fd44  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042fd47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fd48  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042fd4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042fd4c:
    // 0042fd4c  8b8380000000           -mov eax, dword ptr [ebx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(128) /* 0x80 */);
    // 0042fd52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fd53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fd54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fd55  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042fd58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fd60  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042fd63  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0042fd69  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0042fd6f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042fd70  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0042fd74  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0042fd7a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042fd7b  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0042fd7f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042fd80  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042fd84  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042fd86  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042fd89  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0042fd8d  e81eef0200             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0042fd92  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042fd96  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042fd9a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042fd9e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0042fda2  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fda8  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042fdac  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0042fdb0  8b7120                 -mov esi, dword ptr [ecx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0042fdb3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042fdb5  7437                   -je 0x42fdee
    if (cpu.flags.zf)
    {
        goto L_0x0042fdee;
    }
L_0x0042fdb7:
    // 0042fdb7  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042fdbd  83f814                 +cmp eax, 0x14
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
    // 0042fdc0  7422                   -je 0x42fde4
    if (cpu.flags.zf)
    {
        goto L_0x0042fde4;
    }
    // 0042fdc2  83f815                 +cmp eax, 0x15
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042fdc5  741d                   -je 0x42fde4
    if (cpu.flags.zf)
    {
        goto L_0x0042fde4;
    }
    // 0042fdc7  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042fdc9  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042fdcd  e82ee7ffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 0042fdd2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fdd4  740e                   -je 0x42fde4
    if (cpu.flags.zf)
    {
        goto L_0x0042fde4;
    }
    // 0042fdd6  8b86b4000000           -mov eax, dword ptr [esi + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 0042fddc  3bc7                   +cmp eax, edi
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
    // 0042fdde  7e04                   -jle 0x42fde4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042fde4;
    }
    // 0042fde0  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042fde2  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0042fde4:
    // 0042fde4  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042fdea  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042fdec  75c9                   -jne 0x42fdb7
    if (!cpu.flags.zf)
    {
        goto L_0x0042fdb7;
    }
L_0x0042fdee:
    // 0042fdee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fdef  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042fdf1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fdf2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fdf3  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0042fdf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fe00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fe00  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fe05  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0042fe08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fe0a  7412                   -je 0x42fe1e
    if (cpu.flags.zf)
    {
        goto L_0x0042fe1e;
    }
L_0x0042fe0c:
    // 0042fe0c  398880000000           +cmp dword ptr [eax + 0x80], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042fe12  740c                   -je 0x42fe20
    if (cpu.flags.zf)
    {
        goto L_0x0042fe20;
    }
    // 0042fe14  8b80bc000000           -mov eax, dword ptr [eax + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0042fe1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fe1c  75ee                   -jne 0x42fe0c
    if (!cpu.flags.zf)
    {
        goto L_0x0042fe0c;
    }
L_0x0042fe1e:
    // 0042fe1e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042fe20:
    // 0042fe20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fe30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fe30  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fe35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042fe37  7501                   -jne 0x42fe3a
    if (!cpu.flags.zf)
    {
        goto L_0x0042fe3a;
    }
    // 0042fe39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042fe3a:
    // 0042fe3a  8b5038                 -mov edx, dword ptr [eax + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0042fe3d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042fe3f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042fe41  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 0042fe44  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042fe46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42fe50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042fe50  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0042fe53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042fe54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042fe55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042fe56  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042fe58  e87359ffff             -call 0x4257d0
    cpu.esp -= 4;
    sub_4257d0(app, cpu);
    // 0042fe5d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0042fe62  3bc1                   +cmp eax, ecx
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
    // 0042fe64  0f8458010000           -je 0x42ffc2
    if (cpu.flags.zf)
    {
        goto L_0x0042ffc2;
    }
    // 0042fe6a  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fe6f  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042fe71  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042fe74  39aea4000000           +cmp dword ptr [esi + 0xa4], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042fe7a  752a                   -jne 0x42fea6
    if (!cpu.flags.zf)
    {
        goto L_0x0042fea6;
    }
    // 0042fe7c  390ddcd44a00           +cmp dword ptr [0x4ad4dc], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4904156) /* 0x4ad4dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042fe82  7512                   -jne 0x42fe96
    if (!cpu.flags.zf)
    {
        goto L_0x0042fe96;
    }
    // 0042fe84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042fe85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042fe86  687b142ebe             -push 0xbe2e147b
    app->getMemory<x86::reg32>(cpu.esp-4) = 3190690939 /*0xbe2e147b*/;
    cpu.esp -= 4;
    // 0042fe8b  e890c70200             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 0042fe90  892ddcd44a00           -mov dword ptr [0x4ad4dc], ebp
    app->getMemory<x86::reg32>(x86::reg32(4904156) /* 0x4ad4dc */) = cpu.ebp;
L_0x0042fe96:
    // 0042fe96  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042fe9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fe9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fe9e  896938                 -mov dword ptr [ecx + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 0042fea1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042fea2  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0042fea5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042fea6:
    // 0042fea6  890ddcd44a00           -mov dword ptr [0x4ad4dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904156) /* 0x4ad4dc */) = cpu.ecx;
    // 0042feac  8b97d0000000           -mov edx, dword ptr [edi + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */);
    // 0042feb2  8b8fd8000000           -mov ecx, dword ptr [edi + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */);
    // 0042feb8  8b87d4000000           -mov eax, dword ptr [edi + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 0042febe  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0042fec2  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0042fec6  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042feca  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042fecc  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0042fed0  e8dbed0200             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0042fed5  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042fed9  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042fedd  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042fee1  c744240c0010a5d4       -mov dword ptr [esp + 0xc], 0xd4a51000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 3567587328 /*0xd4a51000*/;
    // 0042fee9  c7442410e8000000       -mov dword ptr [esp + 0x10], 0xe8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 232 /*0xe8*/;
    // 0042fef1  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0042fef5  df6c240c               -fild qword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0042fef9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0042fefd  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0042ff01  8bb6a4000000           -mov esi, dword ptr [esi + 0xa4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0042ff07  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ff0b  3bf5                   +cmp esi, ebp
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
    // 0042ff0d  742f                   -je 0x42ff3e
    if (cpu.flags.zf)
    {
        goto L_0x0042ff3e;
    }
    // 0042ff0f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0042ff10:
    // 0042ff10  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ff12  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042ff16  8d8b80000000           -lea ecx, [ebx + 0x80]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(128) /* 0x80 */);
    // 0042ff1c  e8af000000             -call 0x42ffd0
    cpu.esp -= 4;
    sub_42ffd0(app, cpu);
    // 0042ff21  d8542410               -fcom dword ptr [esp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042ff25  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042ff27  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042ff2a  7a08                   -jp 0x42ff34
    if (cpu.flags.pf)
    {
        goto L_0x0042ff34;
    }
    // 0042ff2c  d95c2410               +fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ff30  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0042ff32  eb02                   -jmp 0x42ff36
    goto L_0x0042ff36;
L_0x0042ff34:
    // 0042ff34  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042ff36:
    // 0042ff36  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042ff39  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ff3b  75d3                   -jne 0x42ff10
    if (!cpu.flags.zf)
    {
        goto L_0x0042ff10;
    }
    // 0042ff3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ff3e:
    // 0042ff3e  e87dd50200             -call 0x45d4c0
    cpu.esp -= 4;
    sub_45d4c0(app, cpu);
    // 0042ff43  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042ff45  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042ff47  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042ff49  e8d2c60200             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 0042ff4e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042ff54  8b8d80000000           -mov ecx, dword ptr [ebp + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(128) /* 0x80 */);
    // 0042ff5a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042ff5c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042ff5e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042ff60  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042ff62  8988d0000000           -mov dword ptr [eax + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 0042ff68  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042ff6e  8b8d84000000           -mov ecx, dword ptr [ebp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(132) /* 0x84 */);
    // 0042ff74  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042ff76  8988d4000000           -mov dword ptr [eax + 0xd4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */) = cpu.ecx;
    // 0042ff7c  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042ff82  8b8d88000000           -mov ecx, dword ptr [ebp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(136) /* 0x88 */);
    // 0042ff88  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042ff8a  8988d8000000           -mov dword ptr [eax + 0xd8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(216) /* 0xd8 */) = cpu.ecx;
    // 0042ff90  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042ff96  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042ff98  396a38                 +cmp dword ptr [edx + 0x38], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ff9b  7416                   -je 0x42ffb3
    if (cpu.flags.zf)
    {
        goto L_0x0042ffb3;
    }
    // 0042ff9d  32d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0042ff9f  e81cc40200             -call 0x45c3c0
    cpu.esp -= 4;
    sub_45c3c0(app, cpu);
    // 0042ffa4  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042ffa9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ffaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ffab  896838                 -mov dword ptr [eax + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 0042ffae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ffaf  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0042ffb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ffb3:
    // 0042ffb3  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0042ffb5  e806c40200             -call 0x45c3c0
    cpu.esp -= 4;
    sub_45c3c0(app, cpu);
    // 0042ffba  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042ffbf  896838                 -mov dword ptr [eax + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ebp;
L_0x0042ffc2:
    // 0042ffc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ffc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ffc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ffc5  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0042ffc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42ffd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ffd0  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0042ffd2  d822                   -fsub dword ptr [edx]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx));
    // 0042ffd4  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0042ffd7  d86204                 -fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0042ffda  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0042ffdd  d86208                 -fsub dword ptr [edx + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0042ffe0  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042ffe2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0042ffe4  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0042ffe6  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0042ffe8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042ffea  d9c3                   -fld st(3)
    cpu.fpu.push(x86::Float(cpu.fpu.st(3)));
    // 0042ffec  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 0042ffee  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042fff0  dddb                   -fstp st(3)
    cpu.fpu.st(3) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042fff2  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042fff4  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042fff6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430000  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00430004  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430005  8b82a8020000           -mov eax, dword ptr [edx + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(680) /* 0x2a8 */);
    // 0043000b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043000c  8d4270                 -lea eax, [edx + 0x70]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0043000f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430010  8d4248                 -lea eax, [edx + 0x48]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00430013  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430014  8d4220                 -lea eax, [edx + 0x20]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00430017  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430018  81c2cc000000           -add edx, 0xcc
    (cpu.edx) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 0043001e  e80d000000             -call 0x430030
    cpu.esp -= 4;
    sub_430030(app, cpu);
    // 00430023  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_430030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430030  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00430033  894154                 -mov dword ptr [ecx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00430036  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00430039  894158                 -mov dword ptr [ecx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0043003c  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0043003f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00430043  89515c                 -mov dword ptr [ecx + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 00430046  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00430049  895130                 -mov dword ptr [ecx + 0x30], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0043004c  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0043004f  895134                 -mov dword ptr [ecx + 0x34], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00430052  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00430055  894138                 -mov dword ptr [ecx + 0x38], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00430058  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043005c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0043005f  89513c                 -mov dword ptr [ecx + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00430062  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00430065  895140                 -mov dword ptr [ecx + 0x40], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00430068  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0043006b  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0043006e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00430072  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00430075  895148                 -mov dword ptr [ecx + 0x48], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00430078  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0043007b  89514c                 -mov dword ptr [ecx + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0043007e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00430081  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00430085  894150                 -mov dword ptr [ecx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00430088  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043008c  89512c                 -mov dword ptr [ecx + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0043008f  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00430092  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4300a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004300a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004300a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004300a2  e859fdffff             -call 0x42fe00
    cpu.esp -= 4;
    sub_42fe00(app, cpu);
    // 004300a7  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004300a9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004300ab  741e                   -je 0x4300cb
    if (cpu.flags.zf)
    {
        goto L_0x004300cb;
    }
    // 004300ad  8bb790000000           -mov esi, dword ptr [edi + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */);
    // 004300b3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004300b5  7414                   -je 0x4300cb
    if (cpu.flags.zf)
    {
        goto L_0x004300cb;
    }
L_0x004300b7:
    // 004300b7  8b97b0000000           -mov edx, dword ptr [edi + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(176) /* 0xb0 */);
    // 004300bd  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004300bf  e80c000000             -call 0x4300d0
    cpu.esp -= 4;
    sub_4300d0(app, cpu);
    // 004300c4  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004300c7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004300c9  75ec                   -jne 0x4300b7
    if (!cpu.flags.zf)
    {
        goto L_0x004300b7;
    }
L_0x004300cb:
    // 004300cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004300cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004300cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4300d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004300d0  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004300d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004300d3  8b3530845100           -mov esi, dword ptr [0x518430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004300d9  83fa01                 +cmp edx, 1
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
    // 004300dc  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004300df  8b0c8e                 -mov ecx, dword ptr [esi + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4);
    // 004300e2  8b7054                 -mov esi, dword ptr [eax + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004300e5  89b1d0000000           -mov dword ptr [ecx + 0xd0], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */) = cpu.esi;
    // 004300eb  8b7058                 -mov esi, dword ptr [eax + 0x58]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004300ee  89b1d4000000           -mov dword ptr [ecx + 0xd4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */) = cpu.esi;
    // 004300f4  8b705c                 -mov esi, dword ptr [eax + 0x5c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004300f7  89b1d8000000           -mov dword ptr [ecx + 0xd8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */) = cpu.esi;
    // 004300fd  8b7030                 -mov esi, dword ptr [eax + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00430100  897124                 -mov dword ptr [ecx + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 00430103  8b7034                 -mov esi, dword ptr [eax + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00430106  897128                 -mov dword ptr [ecx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00430109  8b7038                 -mov esi, dword ptr [eax + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0043010c  89712c                 -mov dword ptr [ecx + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 0043010f  8b703c                 -mov esi, dword ptr [eax + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 00430112  89714c                 -mov dword ptr [ecx + 0x4c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.esi;
    // 00430115  8b7040                 -mov esi, dword ptr [eax + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00430118  897150                 -mov dword ptr [ecx + 0x50], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.esi;
    // 0043011b  8b7044                 -mov esi, dword ptr [eax + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0043011e  897154                 -mov dword ptr [ecx + 0x54], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.esi;
    // 00430121  8b7048                 -mov esi, dword ptr [eax + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00430124  897174                 -mov dword ptr [ecx + 0x74], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */) = cpu.esi;
    // 00430127  8b704c                 -mov esi, dword ptr [eax + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0043012a  897178                 -mov dword ptr [ecx + 0x78], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */) = cpu.esi;
    // 0043012d  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00430130  89717c                 -mov dword ptr [ecx + 0x7c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.esi;
    // 00430133  8b702c                 -mov esi, dword ptr [eax + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00430136  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00430139  7512                   -jne 0x43014d
    if (!cpu.flags.zf)
    {
        goto L_0x0043014d;
    }
    // 0043013b  81e6ffffffbf           +and esi, 0xbfffffff
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(3221225471 /*0xbfffffff*/))));
    // 00430141  89b1a8020000           -mov dword ptr [ecx + 0x2a8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.esi;
    // 00430147  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430148  e93330ffff             -jmp 0x423180
    return sub_423180(app, cpu);
L_0x0043014d:
    // 0043014d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043014e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430150  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430151  8b7128                 -mov esi, dword ptr [ecx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00430154  8b0dc0d44a00           -mov ecx, dword ptr [0x4ad4c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904128) /* 0x4ad4c0 */);
    // 0043015a  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00430160  3bc1                   +cmp eax, ecx
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
    // 00430162  7418                   -je 0x43017c
    if (cpu.flags.zf)
    {
        goto L_0x0043017c;
    }
    // 00430164  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430166  7521                   -jne 0x430189
    if (!cpu.flags.zf)
    {
        goto L_0x00430189;
    }
    // 00430168  83f901                 +cmp ecx, 1
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
    // 0043016b  752a                   -jne 0x430197
    if (!cpu.flags.zf)
    {
        goto L_0x00430197;
    }
    // 0043016d  e82effffff             -call 0x4300a0
    cpu.esp -= 4;
    sub_4300a0(app, cpu);
    // 00430172  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00430177  e844c7fdff             -call 0x40c8c0
    cpu.esp -= 4;
    sub_40c8c0(app, cpu);
L_0x0043017c:
    // 0043017c  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00430182  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430183  a3c0d44a00             -mov dword ptr [0x4ad4c0], eax
    app->getMemory<x86::reg32>(x86::reg32(4904128) /* 0x4ad4c0 */) = cpu.eax;
    // 00430188  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00430189:
    // 00430189  8b8e80000000           -mov ecx, dword ptr [esi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0043018f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430190  890dc0d44a00           -mov dword ptr [0x4ad4c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904128) /* 0x4ad4c0 */) = cpu.ecx;
    // 00430196  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00430197:
    // 00430197  8b9680000000           -mov edx, dword ptr [esi + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0043019d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043019e  8915c0d44a00           -mov dword ptr [0x4ad4c0], edx
    app->getMemory<x86::reg32>(x86::reg32(4904128) /* 0x4ad4c0 */) = cpu.edx;
    // 004301a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4301b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004301b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004301b1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004301b3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004301b5  7412                   -je 0x4301c9
    if (cpu.flags.zf)
    {
        goto L_0x004301c9;
    }
L_0x004301b7:
    // 004301b7  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004301b9  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004301bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004301bd  e8f2710400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 004301c2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004301c5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004301c7  75ee                   -jne 0x4301b7
    if (!cpu.flags.zf)
    {
        goto L_0x004301b7;
    }
L_0x004301c9:
    // 004301c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004301ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4301d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004301d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004301d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004301d3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004301d5  7412                   -je 0x4301e9
    if (cpu.flags.zf)
    {
        goto L_0x004301e9;
    }
L_0x004301d7:
    // 004301d7  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004301d9  8b7660                 -mov esi, dword ptr [esi + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 004301dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004301dd  e8d2710400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 004301e2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004301e5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004301e7  75ee                   -jne 0x4301d7
    if (!cpu.flags.zf)
    {
        goto L_0x004301d7;
    }
L_0x004301e9:
    // 004301e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004301ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4301f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004301f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004301f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004301f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004301f3  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004301f5  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004301f7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004301f9  c644240800             -mov byte ptr [esp + 8], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004301fe  7412                   -je 0x430212
    if (cpu.flags.zf)
    {
        goto L_0x00430212;
    }
    // 00430200  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430201  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00430203  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00430206  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00430208  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043020a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0043020c  49                     -dec ecx
    (cpu.ecx)--;
    // 0043020d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043020e  884c2408               -mov byte ptr [esp + 8], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.cl;
L_0x00430212:
    // 00430212  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00430213  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430215  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00430219  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043021b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043021c  e87e750400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430221  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00430225  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00430228  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0043022a  7417                   -je 0x430243
    if (cpu.flags.zf)
    {
        goto L_0x00430243;
    }
    // 0043022c  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00430231  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00430237  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00430238  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043023a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043023b  e85f750400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430240  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00430243:
    // 00430243  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430244  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430245  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430246  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430250  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00430253  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430254  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430255  8b35c4d44a00           -mov esi, dword ptr [0x4ad4c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0043025b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043025c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0043025e  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00430262  668b463c               -mov ax, word ptr [esi + 0x3c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00430266  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430267  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430269  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0043026b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043026c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00430270  e82a750400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430275  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00430278  66837c241000           +cmp word ptr [esp + 0x10], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043027e  7475                   -je 0x4302f5
    if (cpu.flags.zf)
    {
        goto L_0x004302f5;
    }
    // 00430280  8b7640                 -mov esi, dword ptr [esi + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 00430283  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00430285  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430287  746c                   -je 0x4302f5
    if (cpu.flags.zf)
    {
        goto L_0x004302f5;
    }
L_0x00430289:
    // 00430289  8d560c                 -lea edx, [esi + 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043028c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043028e  e85dffffff             -call 0x4301f0
    cpu.esp -= 4;
    sub_4301f0(app, cpu);
    // 00430293  c644240f00             -mov byte ptr [esp + 0xf], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 00430298  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043029a  8844240f               -mov byte ptr [esp + 0xf], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(15) /* 0xf */) = cpu.al;
    // 0043029e  8a5604                 -mov dl, byte ptr [esi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004302a1  02d2                   -add dl, dl
    (cpu.dl) += x86::reg8(x86::sreg8(cpu.dl));
    // 004302a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004302a4  0ac2                   -or al, dl
    cpu.al |= x86::reg8(x86::sreg8(cpu.dl));
    // 004302a6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004302a8  88442417               -mov byte ptr [esp + 0x17], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(23) /* 0x17 */) = cpu.al;
    // 004302ac  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004302b0  8d4c2417               -lea ecx, [esp + 0x17]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(23) /* 0x17 */);
    // 004302b4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004302b6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004302b7  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004302bb  e8df740400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 004302c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004302c1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004302c3  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004302c7  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004302c9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004302ca  e8d0740400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 004302cf  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004302d3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004302d6  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004302db  3be8                   +cmp ebp, eax
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
    // 004302dd  7c0e                   -jl 0x4302ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004302ed;
    }
    // 004302df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004302e0  68f0754900             -push 0x4975f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814320 /*0x4975f0*/;
    cpu.esp -= 4;
    // 004302e5  e82649ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004302ea  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004302ed:
    // 004302ed  8b7634                 -mov esi, dword ptr [esi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004302f0  45                     -inc ebp
    (cpu.ebp)++;
    // 004302f1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004302f3  7594                   -jne 0x430289
    if (!cpu.flags.zf)
    {
        goto L_0x00430289;
    }
L_0x004302f5:
    // 004302f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004302f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004302f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004302f8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004302fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430300  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00430303  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430304  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430305  8b35c4d44a00           -mov esi, dword ptr [0x4ad4c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0043030b  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0043030d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043030e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043030f  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00430313  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430315  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00430319  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0043031b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043031c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00430320  e87a740400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430325  8b7e20                 -mov edi, dword ptr [esi + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00430328  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043032b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0043032d  0f84b5000000           -je 0x4303e8
    if (cpu.flags.zf)
    {
        goto L_0x004303e8;
    }
    // 00430333  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00430334:
    // 00430334  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00430336  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00430338  e8b3feffff             -call 0x4301f0
    cpu.esp -= 4;
    sub_4301f0(app, cpu);
    // 0043033d  c644241300             -mov byte ptr [esp + 0x13], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 0 /*0x0*/;
    // 00430342  8a87b0000000           -mov al, byte ptr [edi + 0xb0]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(176) /* 0xb0 */);
    // 00430348  88442413               -mov byte ptr [esp + 0x13], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = cpu.al;
    // 0043034c  8a97ac000000           -mov dl, byte ptr [edi + 0xac]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(172) /* 0xac */);
    // 00430352  02d2                   -add dl, dl
    (cpu.dl) += x86::reg8(x86::sreg8(cpu.dl));
    // 00430354  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430355  0ac2                   -or al, dl
    cpu.al |= x86::reg8(x86::sreg8(cpu.dl));
    // 00430357  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430359  8844241b               -mov byte ptr [esp + 0x1b], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(27) /* 0x1b */) = cpu.al;
    // 0043035d  8d44241b               -lea eax, [esp + 0x1b]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(27) /* 0x1b */);
    // 00430361  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430363  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430364  e836740400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430369  668b8f8c000000         -mov cx, word ptr [edi + 0x8c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(140) /* 0x8c */);
    // 00430370  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430371  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430373  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00430377  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00430379  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043037a  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 0043037e  e81c740400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430383  8bb790000000           -mov esi, dword ptr [edi + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */);
    // 00430389  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0043038c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043038e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430390  7447                   -je 0x4303d9
    if (cpu.flags.zf)
    {
        goto L_0x004303d9;
    }
L_0x00430392:
    // 00430392  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00430396  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00430398  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043039e  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004303a2  3bd9                   +cmp ebx, ecx
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
    // 004303a4  7e0d                   -jle 0x4303b3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004303b3;
    }
    // 004303a6  6838764900             -push 0x497638
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814392 /*0x497638*/;
    cpu.esp -= 4;
    // 004303ab  e86048ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004303b0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004303b3:
    // 004303b3  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004303b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004303b8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004303ba  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004303be  668b4224               -mov ax, word ptr [edx + 0x24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004303c2  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004303c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004303c5  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004303c9  e8d1730400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 004303ce  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004303d1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004303d4  43                     -inc ebx
    (cpu.ebx)++;
    // 004303d5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004303d7  75b9                   -jne 0x430392
    if (!cpu.flags.zf)
    {
        goto L_0x00430392;
    }
L_0x004303d9:
    // 004303d9  8bbfbc000000           -mov edi, dword ptr [edi + 0xbc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 004303df  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004303e1  0f854dffffff           -jne 0x430334
    if (!cpu.flags.zf)
    {
        goto L_0x00430334;
    }
    // 004303e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004303e8:
    // 004303e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004303e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004303ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004303eb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004303ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4303f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004303f0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 004303f5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004303f6  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004303f8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004303f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004303fa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004303fc  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004303ff  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00430401  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430402  e898730400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430407  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0043040c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043040f  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00430412  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00430414  7457                   -je 0x43046d
    if (cpu.flags.zf)
    {
        goto L_0x0043046d;
    }
    // 00430416  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430417  8b7018                 -mov esi, dword ptr [eax + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0043041a  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0043041c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043041e  7436                   -je 0x430456
    if (cpu.flags.zf)
    {
        goto L_0x00430456;
    }
L_0x00430420:
    // 00430420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00430421  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430423  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 00430425  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430426  e874730400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0043042b  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430431  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00430434  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00430437  3bf8                   +cmp edi, eax
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
    // 00430439  7c0e                   -jl 0x430449
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00430449;
    }
    // 0043043b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043043c  68a8764900             -push 0x4976a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814504 /*0x4976a8*/;
    cpu.esp -= 4;
    // 00430441  e8ca47ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00430446  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00430449:
    // 00430449  8b7660                 -mov esi, dword ptr [esi + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 0043044c  47                     -inc edi
    (cpu.edi)++;
    // 0043044d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043044f  75cf                   -jne 0x430420
    if (!cpu.flags.zf)
    {
        goto L_0x00430420;
    }
    // 00430451  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
L_0x00430456:
    // 00430456  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00430459  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043045a  3bf8                   +cmp edi, eax
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
    // 0043045c  740f                   -je 0x43046d
    if (cpu.flags.zf)
    {
        goto L_0x0043046d;
    }
    // 0043045e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043045f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430460  687c764900             -push 0x49767c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814460 /*0x49767c*/;
    cpu.esp -= 4;
    // 00430465  e8a647ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0043046a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0043046d:
    // 0043046d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043046e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043046f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430470  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00430471  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430472  8b35c4d44a00           -mov esi, dword ptr [0x4ad4c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430478  c744240400000000       -mov dword ptr [esp + 4], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00430480  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430481  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00430484  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00430486  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430488  7410                   -je 0x43049a
    if (cpu.flags.zf)
    {
        goto L_0x0043049a;
    }
L_0x0043048a:
    // 0043048a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043048e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00430491  42                     -inc edx
    (cpu.edx)++;
    // 00430492  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430494  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00430498  75f0                   -jne 0x43048a
    if (!cpu.flags.zf)
    {
        goto L_0x0043048a;
    }
L_0x0043049a:
    // 0043049a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043049b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043049d  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004304a1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004304a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004304a4  e8f6720400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 004304a9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004304ac  66837c240800           +cmp word ptr [esp + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004304b2  741a                   -je 0x4304ce
    if (cpu.flags.zf)
    {
        goto L_0x004304ce;
    }
    // 004304b4  8b7648                 -mov esi, dword ptr [esi + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004304b7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004304b9  7413                   -je 0x4304ce
    if (cpu.flags.zf)
    {
        goto L_0x004304ce;
    }
L_0x004304bb:
    // 004304bb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004304bd  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004304bf  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004304c2  e829fdffff             -call 0x4301f0
    cpu.esp -= 4;
    sub_4301f0(app, cpu);
    // 004304c7  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004304ca  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004304cc  75ed                   -jne 0x4304bb
    if (!cpu.flags.zf)
    {
        goto L_0x004304bb;
    }
L_0x004304ce:
    // 004304ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004304cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004304d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004304d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4304e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004304e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004304e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004304e2  8b3dc4d44a00           -mov edi, dword ptr [0x4ad4c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 004304e8  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004304ea  e801ffffff             -call 0x4303f0
    cpu.esp -= 4;
    sub_4303f0(app, cpu);
    // 004304ef  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004304f1  e80afeffff             -call 0x430300
    cpu.esp -= 4;
    sub_430300(app, cpu);
    // 004304f6  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004304f8  e853fdffff             -call 0x430250
    cpu.esp -= 4;
    sub_430250(app, cpu);
    // 004304fd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004304ff  e86cffffff             -call 0x430470
    cpu.esp -= 4;
    sub_430470(app, cpu);
    // 00430504  8b570c                 -mov edx, dword ptr [edi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00430507  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430509  e8e2fcffff             -call 0x4301f0
    cpu.esp -= 4;
    sub_4301f0(app, cpu);
    // 0043050e  8b5728                 -mov edx, dword ptr [edi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00430511  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430513  e8d8fcffff             -call 0x4301f0
    cpu.esp -= 4;
    sub_4301f0(app, cpu);
    // 00430518  8b5738                 -mov edx, dword ptr [edi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 0043051b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043051d  e8cefcffff             -call 0x4301f0
    cpu.esp -= 4;
    sub_4301f0(app, cpu);
    // 00430522  8b4744                 -mov eax, dword ptr [edi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 00430525  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430527  7405                   -je 0x43052e
    if (cpu.flags.zf)
    {
        goto L_0x0043052e;
    }
    // 00430529  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0043052c  eb02                   -jmp 0x430530
    goto L_0x00430530;
L_0x0043052e:
    // 0043052e  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00430530:
    // 00430530  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430532  e8b9fcffff             -call 0x4301f0
    cpu.esp -= 4;
    sub_4301f0(app, cpu);
    // 00430537  8d4750                 -lea eax, [edi + 0x50]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 0043053a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043053b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043053d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0043053f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430540  e85a720400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430545  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430546  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430548  83c754                 -add edi, 0x54
    (cpu.edi) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0043054b  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0043054d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043054e  e84c720400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430553  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430554  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430556  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00430558  68c86e4900             -push 0x496ec8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812488 /*0x496ec8*/;
    cpu.esp -= 4;
    // 0043055d  e83d720400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00430562  83c430                 +add esp, 0x30
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00430565  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430567  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430568  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430569  e9a2cfffff             -jmp 0x42d510
    return sub_42d510(app, cpu);
}

/* align: skip  */
void Application::sub_430570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430570  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00430571  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00430572  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430573  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00430575  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430576  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00430578  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0043057d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043057f  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00430581  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00430583  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00430584  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430586  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043058a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043058c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043058d  e8f6700400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00430592  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00430596  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00430599  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0043059b  7507                   -jne 0x4305a4
    if (!cpu.flags.zf)
    {
        goto L_0x004305a4;
    }
    // 0043059d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043059e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043059f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004305a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004305a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004305a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004305a4:
    // 004305a4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004305a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004305aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004305ab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004305ad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004305ae  e8d5700400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004305b3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004305b6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004305bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004305bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004305bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004305be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004305bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4305c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004305c0  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 004305c5  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004305c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004305ca  740c                   -je 0x4305d8
    if (cpu.flags.zf)
    {
        goto L_0x004305d8;
    }
L_0x004305cc:
    // 004305cc  394824                 +cmp dword ptr [eax + 0x24], ecx
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
    // 004305cf  7409                   -je 0x4305da
    if (cpu.flags.zf)
    {
        goto L_0x004305da;
    }
    // 004305d1  8b4060                 -mov eax, dword ptr [eax + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 004305d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004305d6  75f4                   -jne 0x4305cc
    if (!cpu.flags.zf)
    {
        goto L_0x004305cc;
    }
L_0x004305d8:
    // 004305d8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004305da:
    // 004305da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4305e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004305e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004305e1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004305e3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004305e5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004305e7  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004305e9  740e                   -je 0x4305f9
    if (cpu.flags.zf)
    {
        goto L_0x004305f9;
    }
L_0x004305eb:
    // 004305eb  395024                 +cmp dword ptr [eax + 0x24], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004305ee  7419                   -je 0x430609
    if (cpu.flags.zf)
    {
        goto L_0x00430609;
    }
    // 004305f0  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004305f2  8b4060                 -mov eax, dword ptr [eax + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 004305f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004305f7  75f2                   -jne 0x4305eb
    if (!cpu.flags.zf)
    {
        goto L_0x004305eb;
    }
L_0x004305f9:
    // 004305f9  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004305fd  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004305ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430600  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00430606  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00430609:
    // 00430609  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043060b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043060c  7505                   -jne 0x430613
    if (!cpu.flags.zf)
    {
        goto L_0x00430613;
    }
    // 0043060e  8b7060                 -mov esi, dword ptr [eax + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 00430611  eb06                   -jmp 0x430619
    goto L_0x00430619;
L_0x00430613:
    // 00430613  8b5060                 -mov edx, dword ptr [eax + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 00430616  895160                 -mov dword ptr [ecx + 0x60], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x00430619:
    // 00430619  e8966d0400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0043061e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00430622  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00430625  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0043062b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043062d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043062e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_430640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430640  81ec94000000           -sub esp, 0x94
    (cpu.esp) -= x86::reg32(x86::sreg32(148 /*0x94*/));
    // 00430646  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043064a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043064b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043064c  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0043064e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043064f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430650  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430652  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00430654  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430655  e82e700400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0043065a  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430660  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00430664  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00430669  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043066c  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0043066f  3bc1                   +cmp eax, ecx
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
    // 00430671  740f                   -je 0x430682
    if (cpu.flags.zf)
    {
        goto L_0x00430682;
    }
    // 00430673  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430674  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00430675  6870774900             -push 0x497770
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814704 /*0x497770*/;
    cpu.esp -= 4;
    // 0043067a  e89145ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0043067f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00430682:
    // 00430682  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430688  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0043068a  8b7220                 -mov esi, dword ptr [edx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0043068d  3bf7                   +cmp esi, edi
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
    // 0043068f  0f8414010000           -je 0x4307a9
    if (cpu.flags.zf)
    {
        goto L_0x004307a9;
    }
    // 00430695  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00430696:
    // 00430696  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0043069a  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0043069c  e8cffeffff             -call 0x430570
    cpu.esp -= 4;
    sub_430570(app, cpu);
    // 004306a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004306a3  750d                   -jne 0x4306b2
    if (!cpu.flags.zf)
    {
        goto L_0x004306b2;
    }
    // 004306a5  6848774900             -push 0x497748
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814664 /*0x497748*/;
    cpu.esp -= 4;
    // 004306aa  e86145ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004306af  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004306b2:
    // 004306b2  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004306b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004306b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004306b8  e8f3440500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 004306bd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004306c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004306c2  7413                   -je 0x4306d7
    if (cpu.flags.zf)
    {
        goto L_0x004306d7;
    }
    // 004306c4  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004306c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004306c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004306ca  6800774900             -push 0x497700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814592 /*0x497700*/;
    cpu.esp -= 4;
    // 004306cf  e83c45ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004306d4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004306d7:
    // 004306d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004306d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004306da  8d54241b               -lea edx, [esp + 0x1b]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(27) /* 0x1b */);
    // 004306de  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004306e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004306e1  e8a26f0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004306e6  8a442423               -mov al, byte ptr [esp + 0x23]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(35) /* 0x23 */);
    // 004306ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004306eb  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004306ee  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004306f0  8986b0000000           -mov dword ptr [esi + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 004306f6  8a4c242b               -mov cl, byte ptr [esp + 0x2b]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(43) /* 0x2b */);
    // 004306fa  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 004306fc  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00430700  83e101                 -and ecx, 1
    cpu.ecx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00430703  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00430705  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00430706  898eac000000           -mov dword ptr [esi + 0xac], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.ecx;
    // 0043070c  e8776f0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00430711  8b8e90000000           -mov ecx, dword ptr [esi + 0x90]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */);
    // 00430717  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0043071a  e891faffff             -call 0x4301b0
    cpu.esp -= 4;
    sub_4301b0(app, cpu);
    // 0043071f  89be8c000000           -mov dword ptr [esi + 0x8c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.edi;
    // 00430725  89be90000000           -mov dword ptr [esi + 0x90], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.edi;
    // 0043072b  66397c2414             +cmp word ptr [esp + 0x14], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00430730  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00430734  7664                   -jbe 0x43079a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043079a;
    }
L_0x00430736:
    // 00430736  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0043073b  e850d0ffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 00430740  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00430742  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00430746  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430747  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430749  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0043074b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043074c  e8376f0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00430751  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00430755  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00430758  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043075e  e85dfeffff             -call 0x4305c0
    cpu.esp -= 4;
    sub_4305c0(app, cpu);
    // 00430763  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00430765  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00430767  750d                   -jne 0x430776
    if (!cpu.flags.zf)
    {
        goto L_0x00430776;
    }
    // 00430769  68d4764900             -push 0x4976d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814548 /*0x4976d4*/;
    cpu.esp -= 4;
    // 0043076e  e89d44ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00430773  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00430776:
    // 00430776  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00430778  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043077a  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0043077c  e83fd6ffff             -call 0x42ddc0
    cpu.esp -= 4;
    sub_42ddc0(app, cpu);
    // 00430781  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00430785  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00430789  40                     -inc eax
    (cpu.eax)++;
    // 0043078a  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00430790  3bc1                   +cmp eax, ecx
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
    // 00430792  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00430796  7c9e                   -jl 0x430736
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00430736;
    }
    // 00430798  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0043079a:
    // 0043079a  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 004307a0  3bf7                   +cmp esi, edi
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
    // 004307a2  0f85eefeffff           -jne 0x430696
    if (!cpu.flags.zf)
    {
        goto L_0x00430696;
    }
    // 004307a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004307a9:
    // 004307a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004307aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004307ab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004307ac  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 004307b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4307c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004307c0  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004307c6  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004307ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004307cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004307cc  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004307ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004307cf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004307d1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004307d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004307d4  e8af6e0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004307d9  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004307dd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004307e0  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004307e3  0f84c5000000           -je 0x4308ae
    if (cpu.flags.zf)
    {
        goto L_0x004308ae;
    }
    // 004307e9  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 004307ef  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004307f4  8b493c                 -mov ecx, dword ptr [ecx + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 004307f7  3bc1                   +cmp eax, ecx
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
    // 004307f9  740f                   -je 0x43080a
    if (cpu.flags.zf)
    {
        goto L_0x0043080a;
    }
    // 004307fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004307fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004307fd  68cc774900             -push 0x4977cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814796 /*0x4977cc*/;
    cpu.esp -= 4;
    // 00430802  e80944ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00430807  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0043080a:
    // 0043080a  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430810  8b7240                 -mov esi, dword ptr [edx + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 00430813  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430815  0f8493000000           -je 0x4308ae
    if (cpu.flags.zf)
    {
        goto L_0x004308ae;
    }
    // 0043081b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0043081c:
    // 0043081c  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00430820  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00430822  e849fdffff             -call 0x430570
    cpu.esp -= 4;
    sub_430570(app, cpu);
    // 00430827  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430829  750d                   -jne 0x430838
    if (!cpu.flags.zf)
    {
        goto L_0x00430838;
    }
    // 0043082b  68a0774900             -push 0x4977a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814752 /*0x4977a0*/;
    cpu.esp -= 4;
    // 00430830  e8db43ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00430835  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00430838:
    // 00430838  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043083b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0043083f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00430840  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430841  e86a430500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00430846  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00430849  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043084b  7413                   -je 0x430860
    if (cpu.flags.zf)
    {
        goto L_0x00430860;
    }
    // 0043084d  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00430851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00430852  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00430853  6800774900             -push 0x497700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814592 /*0x497700*/;
    cpu.esp -= 4;
    // 00430858  e8b343ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0043085d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00430860:
    // 00430860  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430861  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430863  8d542417               -lea edx, [esp + 0x17]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(23) /* 0x17 */);
    // 00430867  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430869  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043086a  e8196e0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0043086f  8a44241f               -mov al, byte ptr [esp + 0x1f]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(31) /* 0x1f */);
    // 00430873  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430874  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00430877  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430879  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0043087b  8a4c2427               -mov cl, byte ptr [esp + 0x27]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(39) /* 0x27 */);
    // 0043087f  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00430881  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00430885  83e101                 -and ecx, 1
    cpu.ecx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00430888  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0043088a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043088b  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0043088e  e8f56d0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00430893  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00430897  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0043089a  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043089f  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004308a2  8b7634                 -mov esi, dword ptr [esi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004308a5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004308a7  0f856fffffff           -jne 0x43081c
    if (!cpu.flags.zf)
    {
        goto L_0x0043081c;
    }
    // 004308ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004308ae:
    // 004308ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004308af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004308b0  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004308b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4308c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004308c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004308c1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004308c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004308c4  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004308c6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004308c8  7418                   -je 0x4308e2
    if (cpu.flags.zf)
    {
        goto L_0x004308e2;
    }
L_0x004308ca:
    // 004308ca  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004308cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004308ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004308cf  e8dc420500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 004308d4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004308d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004308d9  740c                   -je 0x4308e7
    if (cpu.flags.zf)
    {
        goto L_0x004308e7;
    }
    // 004308db  8b7634                 -mov esi, dword ptr [esi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004308de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004308e0  75e8                   -jne 0x4308ca
    if (!cpu.flags.zf)
    {
        goto L_0x004308ca;
    }
L_0x004308e2:
    // 004308e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004308e3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004308e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004308e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004308e7:
    // 004308e7  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004308e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004308ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004308eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4308f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004308f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004308f1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004308f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004308f4  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004308f6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004308f8  7418                   -je 0x430912
    if (cpu.flags.zf)
    {
        goto L_0x00430912;
    }
L_0x004308fa:
    // 004308fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004308fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004308fc  e8af420500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00430901  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00430904  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430906  740f                   -je 0x430917
    if (cpu.flags.zf)
    {
        goto L_0x00430917;
    }
    // 00430908  8bb698000000           -mov esi, dword ptr [esi + 0x98]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 0043090e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430910  75e8                   -jne 0x4308fa
    if (!cpu.flags.zf)
    {
        goto L_0x004308fa;
    }
L_0x00430912:
    // 00430912  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430913  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00430915  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430916  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00430917:
    // 00430917  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00430919  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043091a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043091b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430920  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430921  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00430923  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430924  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00430926  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430928  7418                   -je 0x430942
    if (cpu.flags.zf)
    {
        goto L_0x00430942;
    }
L_0x0043092a:
    // 0043092a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043092b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043092c  e87f420500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00430931  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00430934  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430936  740f                   -je 0x430947
    if (cpu.flags.zf)
    {
        goto L_0x00430947;
    }
    // 00430938  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0043093e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430940  75e8                   -jne 0x43092a
    if (!cpu.flags.zf)
    {
        goto L_0x0043092a;
    }
L_0x00430942:
    // 00430942  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430943  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00430945  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430946  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00430947:
    // 00430947  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00430949  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043094a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043094b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430950  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430955  83ec68                 -sub esp, 0x68
    (cpu.esp) -= x86::reg32(x86::sreg32(104 /*0x68*/));
    // 00430958  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043095b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043095c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043095d  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0043095f  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00430961  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430962  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430964  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00430966  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430967  e81c6d0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0043096c  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430972  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00430975  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00430978  3bc3                   +cmp eax, ebx
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
    // 0043097a  745d                   -je 0x4309d9
    if (cpu.flags.zf)
    {
        goto L_0x004309d9;
    }
    // 0043097c  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00430980  7e57                   -jle 0x4309d9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004309d9;
    }
    // 00430982  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430983  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00430984:
    // 00430984  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430985  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430987  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0043098b  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 0043098d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043098e  e8f56c0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00430993  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00430996  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0043099b  e8f0cdffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 004309a0  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 004309a5  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004309a9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004309ab  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004309ad  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004309af  7405                   -je 0x4309b6
    if (cpu.flags.zf)
    {
        goto L_0x004309b6;
    }
    // 004309b1  894360                 -mov dword ptr [ebx + 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004309b4  eb09                   -jmp 0x4309bf
    goto L_0x004309bf;
L_0x004309b6:
    // 004309b6  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 004309bc  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004309bf:
    // 004309bf  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 004309c5  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004309c7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004309cb  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004309ce  40                     -inc eax
    (cpu.eax)++;
    // 004309cf  3bc1                   +cmp eax, ecx
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
    // 004309d1  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004309d5  7cad                   -jl 0x430984
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00430984;
    }
    // 004309d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004309d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004309d9:
    // 004309d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004309da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004309db  83c468                 -add esp, 0x68
    (cpu.esp) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 004309de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4309e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004309e0  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 004309e6  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 004309ea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004309eb  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004309ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004309ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004309ef  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004309f1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004309f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004309f4  e88f6c0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004309f9  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004309fd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00430a00  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00430a03  7474                   -je 0x430a79
    if (cpu.flags.zf)
    {
        goto L_0x00430a79;
    }
    // 00430a05  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00430a07  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00430a0a  766d                   -jbe 0x430a79
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00430a79;
    }
    // 00430a0c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00430a0d:
    // 00430a0d  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00430a11  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00430a13  e858fbffff             -call 0x430570
    cpu.esp -= 4;
    sub_430570(app, cpu);
    // 00430a18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430a1a  750d                   -jne 0x430a29
    if (!cpu.flags.zf)
    {
        goto L_0x00430a29;
    }
    // 00430a1c  6828784900             -push 0x497828
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814888 /*0x497828*/;
    cpu.esp -= 4;
    // 00430a21  e8ea41ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00430a26  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00430a29:
    // 00430a29  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430a2f  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00430a33  8b4940                 -mov ecx, dword ptr [ecx + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00430a36  e885feffff             -call 0x4308c0
    cpu.esp -= 4;
    sub_4308c0(app, cpu);
    // 00430a3b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00430a3d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00430a3f  750d                   -jne 0x430a4e
    if (!cpu.flags.zf)
    {
        goto L_0x00430a4e;
    }
    // 00430a41  6800784900             -push 0x497800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4814848 /*0x497800*/;
    cpu.esp -= 4;
    // 00430a46  e8c541ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00430a4b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00430a4e:
    // 00430a4e  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00430a53  e838cdffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 00430a58  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 00430a5a  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430a60  46                     -inc esi
    (cpu.esi)++;
    // 00430a61  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00430a64  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00430a67  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00430a6a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00430a6e  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00430a74  3bf2                   +cmp esi, edx
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
    // 00430a76  7c95                   -jl 0x430a0d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00430a0d;
    }
    // 00430a78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00430a79:
    // 00430a79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430a7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430a7b  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00430a81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430a90  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00430a96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430a97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430a98  8b3dc4d44a00           -mov edi, dword ptr [0x4ad4c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430a9e  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00430aa0  8b4f18                 -mov ecx, dword ptr [edi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00430aa3  e828f7ffff             -call 0x4301d0
    cpu.esp -= 4;
    sub_4301d0(app, cpu);
    // 00430aa8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430aaa  e8a1feffff             -call 0x430950
    cpu.esp -= 4;
    sub_430950(app, cpu);
    // 00430aaf  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430ab1  e88afbffff             -call 0x430640
    cpu.esp -= 4;
    sub_430640(app, cpu);
    // 00430ab6  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430ab8  e803fdffff             -call 0x4307c0
    cpu.esp -= 4;
    sub_4307c0(app, cpu);
    // 00430abd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430abf  e81cffffff             -call 0x4309e0
    cpu.esp -= 4;
    sub_4309e0(app, cpu);
    // 00430ac4  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430ac8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430aca  e8a1faffff             -call 0x430570
    cpu.esp -= 4;
    sub_430570(app, cpu);
    // 00430acf  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00430ad2  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430ad6  e815feffff             -call 0x4308f0
    cpu.esp -= 4;
    sub_4308f0(app, cpu);
    // 00430adb  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430adf  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430ae1  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00430ae4  e887faffff             -call 0x430570
    cpu.esp -= 4;
    sub_430570(app, cpu);
    // 00430ae9  8b4f20                 -mov ecx, dword ptr [edi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00430aec  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430af0  e82bfeffff             -call 0x430920
    cpu.esp -= 4;
    sub_430920(app, cpu);
    // 00430af5  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430af9  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430afb  894728                 -mov dword ptr [edi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00430afe  e86dfaffff             -call 0x430570
    cpu.esp -= 4;
    sub_430570(app, cpu);
    // 00430b03  8b4f30                 -mov ecx, dword ptr [edi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00430b06  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430b0a  e8e1fdffff             -call 0x4308f0
    cpu.esp -= 4;
    sub_4308f0(app, cpu);
    // 00430b0f  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430b13  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430b15  894738                 -mov dword ptr [edi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00430b18  e853faffff             -call 0x430570
    cpu.esp -= 4;
    sub_430570(app, cpu);
    // 00430b1d  8b4f40                 -mov ecx, dword ptr [edi + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(64) /* 0x40 */);
    // 00430b20  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430b24  e897fdffff             -call 0x4308c0
    cpu.esp -= 4;
    sub_4308c0(app, cpu);
    // 00430b29  894744                 -mov dword ptr [edi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00430b2c  8d4750                 -lea eax, [edi + 0x50]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 00430b2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430b30  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430b32  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00430b34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00430b35  e84e6b0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00430b3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430b3b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430b3d  83c754                 -add edi, 0x54
    (cpu.edi) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00430b40  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00430b42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430b43  e8406b0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00430b48  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430b49  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00430b4b  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00430b4d  68c86e4900             -push 0x496ec8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812488 /*0x496ec8*/;
    cpu.esp -= 4;
    // 00430b52  e8316b0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00430b57  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00430b5a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00430b5c  e8efc9ffff             -call 0x42d550
    cpu.esp -= 4;
    sub_42d550(app, cpu);
    // 00430b61  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00430b67  8b15c4e54900           -mov edx, dword ptr [0x49e5c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 00430b6d  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00430b70  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00430b76  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00430b7c  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00430b7f  e88ce7ffff             -call 0x42f310
    cpu.esp -= 4;
    sub_42f310(app, cpu);
    // 00430b84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430b85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430b86  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00430b8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430b90  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00430b93  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 00430b99  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00430b9f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00430ba3  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00430ba9  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00430bad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430bae  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00430bb2  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00430bb6  e8f5e00200             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 00430bbb  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00430bbf  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00430bc3  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00430bc7  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00430bcb  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430bd1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00430bd5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00430bd9  8b7120                 -mov esi, dword ptr [ecx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00430bdc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430bde  7429                   -je 0x430c09
    if (cpu.flags.zf)
    {
        goto L_0x00430c09;
    }
L_0x00430be0:
    // 00430be0  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00430be6  83f814                 +cmp eax, 0x14
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
    // 00430be9  7405                   -je 0x430bf0
    if (cpu.flags.zf)
    {
        goto L_0x00430bf0;
    }
    // 00430beb  83f815                 +cmp eax, 0x15
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00430bee  750f                   -jne 0x430bff
    if (!cpu.flags.zf)
    {
        goto L_0x00430bff;
    }
L_0x00430bf0:
    // 00430bf0  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00430bf2  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00430bf6  e805d9ffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 00430bfb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430bfd  7511                   -jne 0x430c10
    if (!cpu.flags.zf)
    {
        goto L_0x00430c10;
    }
L_0x00430bff:
    // 00430bff  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00430c05  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430c07  75d7                   -jne 0x430be0
    if (!cpu.flags.zf)
    {
        goto L_0x00430be0;
    }
L_0x00430c09:
    // 00430c09  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00430c0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430c0c  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00430c0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00430c10:
    // 00430c10  8b9680000000           -mov edx, dword ptr [esi + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00430c16  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00430c18  83fa14                 +cmp edx, 0x14
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00430c1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430c1c  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00430c1f  40                     -inc eax
    (cpu.eax)++;
    // 00430c20  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00430c23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430c30  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00430c33  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 00430c39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430c3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00430c3b  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00430c3d  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00430c43  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00430c47  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00430c4d  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00430c51  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00430c55  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00430c59  e852e00200             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 00430c5e  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00430c62  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00430c66  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00430c6a  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00430c6e  8b0dc4d44a00           -mov ecx, dword ptr [0x4ad4c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00430c74  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00430c78  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00430c7c  8b7120                 -mov esi, dword ptr [ecx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00430c7f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430c81  7421                   -je 0x430ca4
    if (cpu.flags.zf)
    {
        goto L_0x00430ca4;
    }
L_0x00430c83:
    // 00430c83  39be80000000           +cmp dword ptr [esi + 0x80], edi
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
    // 00430c89  750f                   -jne 0x430c9a
    if (!cpu.flags.zf)
    {
        goto L_0x00430c9a;
    }
    // 00430c8b  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00430c8d  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00430c91  e86ad8ffff             -call 0x42e500
    cpu.esp -= 4;
    sub_42e500(app, cpu);
    // 00430c96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430c98  7512                   -jne 0x430cac
    if (!cpu.flags.zf)
    {
        goto L_0x00430cac;
    }
L_0x00430c9a:
    // 00430c9a  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00430ca0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00430ca2  75df                   -jne 0x430c83
    if (!cpu.flags.zf)
    {
        goto L_0x00430c83;
    }
L_0x00430ca4:
    // 00430ca4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430ca5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00430ca7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430ca8  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00430cab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00430cac:
    // 00430cac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430cad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00430cb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430cb3  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00430cb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_430cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00430cc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00430cc1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00430cc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00430cc3  8ba998000000           -mov ebp, dword ptr [ecx + 0x98]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00430cc9  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00430ccb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00430ccd  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00430cd1  7449                   -je 0x430d1c
    if (cpu.flags.zf)
    {
        goto L_0x00430d1c;
    }
    // 00430cd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00430cd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00430cd5:
    // 00430cd5  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00430cd8  8bb88c000000           -mov edi, dword ptr [eax + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 00430cde  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00430ce0  7431                   -je 0x430d13
    if (cpu.flags.zf)
    {
        goto L_0x00430d13;
    }
L_0x00430ce2:
    // 00430ce2  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 00430ce4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00430ce8  3bf0                   +cmp esi, eax
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
    // 00430cea  7420                   -je 0x430d0c
    if (cpu.flags.zf)
    {
        goto L_0x00430d0c;
    }
    // 00430cec  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00430cee  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00430cf0  7504                   -jne 0x430cf6
    if (!cpu.flags.zf)
    {
        goto L_0x00430cf6;
    }
    // 00430cf2  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00430cf4  eb0f                   -jmp 0x430d05
    goto L_0x00430d05;
L_0x00430cf6:
    // 00430cf6  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00430cf8  e833000000             -call 0x430d30
    cpu.esp -= 4;
    sub_430d30(app, cpu);
    // 00430cfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00430cff  750b                   -jne 0x430d0c
    if (!cpu.flags.zf)
    {
        goto L_0x00430d0c;
    }
    // 00430d01  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00430d03  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x00430d05:
    // 00430d05  e876cbffff             -call 0x42d880
    cpu.esp -= 4;
    sub_42d880(app, cpu);
    // 00430d0a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00430d0c:
    // 00430d0c  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00430d0f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00430d11  75cf                   -jne 0x430ce2
    if (!cpu.flags.zf)
    {
        goto L_0x00430ce2;
    }
L_0x00430d13:
    // 00430d13  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00430d16  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00430d18  75bb                   -jne 0x430cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00430cd5;
    }
    // 00430d1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430d1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00430d1c:
    // 00430d1c  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00430d1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430d1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430d20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00430d21  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
