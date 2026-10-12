#include "menu.h"
namespace menu
{

/* align: skip  */
void Application::asm_sub_42d4a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d4a7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d4a8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042d4aa  b800100000             -mov eax, 0x1000
    cpu.eax = 4096 /*0x1000*/;
    // 0042d4af  e81c82ffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042d4b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d4b5  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042d4b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d4b9  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042d4bb  3b1d005e4900           +cmp ebx, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d4c1  0f8315010000           -jae 0x42d5dc
    if (!cpu.flags.cf)
    {
        goto L_0x0042d5dc;
    }
    // 0042d4c7  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042d4c9  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042d4cb  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0042d4ce  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042d4d1  8b0485005d4900         -mov eax, dword ptr [eax*4 + 0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 0042d4d8  f644c80401             +test byte ptr [eax + ecx*8 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8) & 1 /*0x1*/));
    // 0042d4dd  0f84f9000000           -je 0x42d5dc
    if (cpu.flags.zf)
    {
        goto L_0x0042d5dc;
    }
    // 0042d4e3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d4e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d4e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d4e7  e8c6b5ffff             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 0042d4ec  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042d4ef  83f8ff                 +cmp eax, -1
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
    // 0042d4f2  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042d4f5  0f84eb000000           -je 0x42d5e6
    if (cpu.flags.zf)
    {
        goto L_0x0042d5e6;
    }
    // 0042d4fb  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042d4fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d4fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d4ff  e8aeb5ffff             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 0042d504  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042d507  83f8ff                 +cmp eax, -1
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
    // 0042d50a  0f84d6000000           -je 0x42d5e6
    if (cpu.flags.zf)
    {
        goto L_0x0042d5e6;
    }
    // 0042d510  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d511  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042d514  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d516  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042d518  7e6f                   -jle 0x42d589
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042d589;
    }
    // 0042d51a  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0042d51f  8d8500f0ffff           -lea eax, [ebp - 0x1000]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4096) /* -0x1000 */);
    // 0042d525  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d526  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d527  e8e4dcffff             -call 0x42b210
    cpu.esp -= 4;
    sub_42b210(app, cpu);
    // 0042d52c  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 0042d531  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d532  e8f80f0000             -call 0x42e52f
    cpu.esp -= 4;
    sub_42e52f(app, cpu);
    // 0042d537  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042d53a  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0042d53d:
    // 0042d53d  b800100000             -mov eax, 0x1000
    cpu.eax = 4096 /*0x1000*/;
    // 0042d542  3bf8                   +cmp edi, eax
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
    // 0042d544  7d02                   -jge 0x42d548
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042d548;
    }
    // 0042d546  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0042d548:
    // 0042d548  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d549  8d8500f0ffff           -lea eax, [ebp - 0x1000]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4096) /* -0x1000 */);
    // 0042d54f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d551  e8b7a1ffff             -call 0x42770d
    cpu.esp -= 4;
    sub_42770d(app, cpu);
    // 0042d556  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042d559  83f8ff                 +cmp eax, -1
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
    // 0042d55c  7408                   -je 0x42d566
    if (cpu.flags.zf)
    {
        goto L_0x0042d566;
    }
    // 0042d55e  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d560  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042d562  7e18                   -jle 0x42d57c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042d57c;
    }
    // 0042d564  ebd7                   -jmp 0x42d53d
    goto L_0x0042d53d;
L_0x0042d566:
    // 0042d566  833de853490005         +cmp dword ptr [0x4953e8], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d56d  750a                   -jne 0x42d579
    if (!cpu.flags.zf)
    {
        goto L_0x0042d579;
    }
    // 0042d56f  c705e45349000d000000   -mov dword ptr [0x4953e4], 0xd
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 13 /*0xd*/;
L_0x0042d579:
    // 0042d579  83ceff                 +or esi, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
L_0x0042d57c:
    // 0042d57c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d57f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d580  e8aa0f0000             -call 0x42e52f
    cpu.esp -= 4;
    sub_42e52f(app, cpu);
    // 0042d585  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d586  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d587  eb40                   -jmp 0x42d5c9
    goto L_0x0042d5c9;
L_0x0042d589:
    // 0042d589  7d3e                   -jge 0x42d5c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042d5c9;
    }
    // 0042d58b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042d58d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d591  e81cb5ffff             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 0042d596  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d597  e888d4ffff             -call 0x42aa24
    cpu.esp -= 4;
    sub_42aa24(app, cpu);
    // 0042d59c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042d59f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d5a0  ff1550004300           -call dword ptr [0x430050]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390992) /* 0x430050 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d5a6  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d5a8  f7de                   +neg esi
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
    // 0042d5aa  1bf6                   -sbb esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 0042d5ac  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0042d5ae  4e                     -dec esi
    (cpu.esi)--;
    // 0042d5af  83feff                 +cmp esi, -1
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
    // 0042d5b2  7515                   -jne 0x42d5c9
    if (!cpu.flags.zf)
    {
        goto L_0x0042d5c9;
    }
    // 0042d5b4  c705e45349000d000000   -mov dword ptr [0x4953e4], 0xd
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 13 /*0xd*/;
    // 0042d5be  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d5c4  a3e8534900             -mov dword ptr [0x4953e8], eax
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.eax;
L_0x0042d5c9:
    // 0042d5c9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042d5cb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d5ce  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d5cf  e8deb4ffff             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 0042d5d4  83c40c                 +add esp, 0xc
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
    // 0042d5d7  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042d5d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d5da  eb0d                   -jmp 0x42d5e9
    goto L_0x0042d5e9;
L_0x0042d5dc:
    // 0042d5dc  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
L_0x0042d5e6:
    // 0042d5e6  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042d5e9:
    // 0042d5e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d5ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d5eb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d5ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d5ed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d5ed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d5ee  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042d5f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d5f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d5f2  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042d5f5  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042d5f7  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d5f8  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d5f9  7459                   -je 0x42d654
    if (cpu.flags.zf)
    {
        goto L_0x0042d654;
    }
    // 0042d5fb  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d5fc  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d5fd  7446                   -je 0x42d645
    if (cpu.flags.zf)
    {
        goto L_0x0042d645;
    }
    // 0042d5ff  83e804                 +sub eax, 4
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
    // 0042d602  7441                   -je 0x42d645
    if (cpu.flags.zf)
    {
        goto L_0x0042d645;
    }
    // 0042d604  83e803                 +sub eax, 3
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
    // 0042d607  743c                   -je 0x42d645
    if (cpu.flags.zf)
    {
        goto L_0x0042d645;
    }
    // 0042d609  83e804                 +sub eax, 4
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
    // 0042d60c  742a                   -je 0x42d638
    if (cpu.flags.zf)
    {
        goto L_0x0042d638;
    }
    // 0042d60e  83e806                 +sub eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042d611  7418                   -je 0x42d62b
    if (cpu.flags.zf)
    {
        goto L_0x0042d62b;
    }
    // 0042d613  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d614  7408                   -je 0x42d61e
    if (cpu.flags.zf)
    {
        goto L_0x0042d61e;
    }
    // 0042d616  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042d619  e9f8000000             -jmp 0x42d716
    goto L_0x0042d716;
L_0x0042d61e:
    // 0042d61e  8b359c564900           -mov esi, dword ptr [0x49569c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4806300) /* 0x49569c */);
    // 0042d624  b89c564900             -mov eax, 0x49569c
    cpu.eax = 4806300 /*0x49569c*/;
    // 0042d629  eb34                   -jmp 0x42d65f
    goto L_0x0042d65f;
L_0x0042d62b:
    // 0042d62b  8b3598564900           -mov esi, dword ptr [0x495698]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4806296) /* 0x495698 */);
    // 0042d631  b898564900             -mov eax, 0x495698
    cpu.eax = 4806296 /*0x495698*/;
    // 0042d636  eb27                   -jmp 0x42d65f
    goto L_0x0042d65f;
L_0x0042d638:
    // 0042d638  8b35a0564900           -mov esi, dword ptr [0x4956a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4806304) /* 0x4956a0 */);
    // 0042d63e  b8a0564900             -mov eax, 0x4956a0
    cpu.eax = 4806304 /*0x4956a0*/;
    // 0042d643  eb1a                   -jmp 0x42d65f
    goto L_0x0042d65f;
L_0x0042d645:
    // 0042d645  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d646  e8cf000000             -call 0x42d71a
    cpu.esp -= 4;
    sub_42d71a(app, cpu);
    // 0042d64b  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042d64e  83c008                 +add eax, 8
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
    // 0042d651  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d652  eb0b                   -jmp 0x42d65f
    goto L_0x0042d65f;
L_0x0042d654:
    // 0042d654  8b3594564900           -mov esi, dword ptr [0x495694]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4806292) /* 0x495694 */);
    // 0042d65a  b894564900             -mov eax, 0x495694
    cpu.eax = 4806292 /*0x495694*/;
L_0x0042d65f:
    // 0042d65f  83fe01                 +cmp esi, 1
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
    // 0042d662  7507                   -jne 0x42d66b
    if (!cpu.flags.zf)
    {
        goto L_0x0042d66b;
    }
    // 0042d664  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042d666  e9ab000000             -jmp 0x42d716
    goto L_0x0042d716;
L_0x0042d66b:
    // 0042d66b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042d66d  7507                   -jne 0x42d676
    if (!cpu.flags.zf)
    {
        goto L_0x0042d676;
    }
    // 0042d66f  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042d671  e896a6ffff             -call 0x427d0c
    cpu.esp -= 4;
    sub_427d0c(app, cpu);
L_0x0042d676:
    // 0042d676  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d677  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042d679  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d67a  3bf9                   +cmp edi, ecx
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
    // 0042d67c  740a                   -je 0x42d688
    if (cpu.flags.zf)
    {
        goto L_0x0042d688;
    }
    // 0042d67e  83ff0b                 +cmp edi, 0xb
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d681  7405                   -je 0x42d688
    if (cpu.flags.zf)
    {
        goto L_0x0042d688;
    }
    // 0042d683  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d686  7526                   -jne 0x42d6ae
    if (!cpu.flags.zf)
    {
        goto L_0x0042d6ae;
    }
L_0x0042d688:
    // 0042d688  8b1d5c544900           -mov ebx, dword ptr [0x49545c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4805724) /* 0x49545c */);
    // 0042d68e  83255c54490000         -and dword ptr [0x49545c], 0
    app->getMemory<x86::reg32>(x86::reg32(4805724) /* 0x49545c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042d695  3bf9                   +cmp edi, ecx
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
    // 0042d697  7544                   -jne 0x42d6dd
    if (!cpu.flags.zf)
    {
        goto L_0x0042d6dd;
    }
    // 0042d699  8b158cd54300           -mov edx, dword ptr [0x43d58c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */);
    // 0042d69f  c7058cd543008c000000   -mov dword ptr [0x43d58c], 0x8c
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = 140 /*0x8c*/;
    // 0042d6a9  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042d6ac  eb03                   -jmp 0x42d6b1
    goto L_0x0042d6b1;
L_0x0042d6ae:
    // 0042d6ae  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0042d6b1:
    // 0042d6b1  3bf9                   +cmp edi, ecx
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
    // 0042d6b3  7528                   -jne 0x42d6dd
    if (!cpu.flags.zf)
    {
        goto L_0x0042d6dd;
    }
    // 0042d6b5  a180d54300             -mov eax, dword ptr [0x43d580]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445568) /* 0x43d580 */);
    // 0042d6ba  8b0d84d54300           -mov ecx, dword ptr [0x43d584]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445572) /* 0x43d584 */);
    // 0042d6c0  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042d6c2  3bc1                   +cmp eax, ecx
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
    // 0042d6c4  7d1e                   -jge 0x42d6e4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042d6e4;
    }
    // 0042d6c6  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0042d6c9  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d6cb  8d149510d54300         -lea edx, [edx*4 + 0x43d510]
    cpu.edx = x86::reg32(x86::reg32(4445456) /* 0x43d510 */ + cpu.edx * 4);
L_0x0042d6d2:
    // 0042d6d2  832200                 -and dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042d6d5  83c20c                 +add edx, 0xc
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042d6d8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d6d9  75f7                   -jne 0x42d6d2
    if (!cpu.flags.zf)
    {
        goto L_0x0042d6d2;
    }
    // 0042d6db  eb07                   -jmp 0x42d6e4
    goto L_0x0042d6e4;
L_0x0042d6dd:
    // 0042d6dd  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042d6e0  3bf9                   +cmp edi, ecx
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
    // 0042d6e2  750e                   -jne 0x42d6f2
    if (!cpu.flags.zf)
    {
        goto L_0x0042d6f2;
    }
L_0x0042d6e4:
    // 0042d6e4  ff358cd54300           -push dword ptr [0x43d58c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */);
    cpu.esp -= 4;
    // 0042d6ea  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042d6ec  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d6ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d6ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d6f0  eb0e                   -jmp 0x42d700
    goto L_0x0042d700;
L_0x0042d6f2:
    // 0042d6f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d6f3  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d6f5  83ff0b                 +cmp edi, 0xb
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d6f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d6f9  7405                   -je 0x42d700
    if (cpu.flags.zf)
    {
        goto L_0x0042d700;
    }
    // 0042d6fb  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d6fe  7513                   -jne 0x42d713
    if (!cpu.flags.zf)
    {
        goto L_0x0042d713;
    }
L_0x0042d700:
    // 0042d700  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d703  891d5c544900           -mov dword ptr [0x49545c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4805724) /* 0x49545c */) = cpu.ebx;
    // 0042d709  7508                   -jne 0x42d713
    if (!cpu.flags.zf)
    {
        goto L_0x0042d713;
    }
    // 0042d70b  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042d70e  a38cd54300             -mov dword ptr [0x43d58c], eax
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = cpu.eax;
L_0x0042d713:
    // 0042d713  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d715  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042d716:
    // 0042d716  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d717  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d718  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d719  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d71a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d71a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042d71e  8b0d88d54300           -mov ecx, dword ptr [0x43d588]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445576) /* 0x43d588 */);
    // 0042d724  39150cd54300           +cmp dword ptr [0x43d50c], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4445452) /* 0x43d50c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d72a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d72b  b808d54300             -mov eax, 0x43d508
    cpu.eax = 4445448 /*0x43d508*/;
    // 0042d730  7416                   -je 0x42d748
    if (cpu.flags.zf)
    {
        goto L_0x0042d748;
    }
    // 0042d732  8d3449                 -lea esi, [ecx + ecx*2]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042d735  8d34b508d54300         -lea esi, [esi*4 + 0x43d508]
    cpu.esi = x86::reg32(x86::reg32(4445448) /* 0x43d508 */ + cpu.esi * 4);
L_0x0042d73c:
    // 0042d73c  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042d73f  3bc6                   +cmp eax, esi
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
    // 0042d741  7305                   -jae 0x42d748
    if (!cpu.flags.cf)
    {
        goto L_0x0042d748;
    }
    // 0042d743  395004                 +cmp dword ptr [eax + 4], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d746  75f4                   -jne 0x42d73c
    if (!cpu.flags.zf)
    {
        goto L_0x0042d73c;
    }
L_0x0042d748:
    // 0042d748  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042d74b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d74c  8d0c8d08d54300         -lea ecx, [ecx*4 + 0x43d508]
    cpu.ecx = x86::reg32(x86::reg32(4445448) /* 0x43d508 */ + cpu.ecx * 4);
    // 0042d753  3bc1                   +cmp eax, ecx
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
    // 0042d755  7305                   -jae 0x42d75c
    if (!cpu.flags.cf)
    {
        goto L_0x0042d75c;
    }
    // 0042d757  395004                 +cmp dword ptr [eax + 4], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d75a  7402                   -je 0x42d75e
    if (cpu.flags.zf)
    {
        goto L_0x0042d75e;
    }
L_0x0042d75c:
    // 0042d75c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042d75e:
    // 0042d75e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d75f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d75f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d760  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042d762  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042d764  68a80e4300             -push 0x430ea8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394664 /*0x430ea8*/;
    cpu.esp -= 4;
    // 0042d769  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 0042d76e  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0042d774  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d775  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0042d77c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042d77f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d780  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d781  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d782  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042d785  a1a8564900             -mov eax, dword ptr [0x4956a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806312) /* 0x4956a8 */);
    // 0042d78a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042d78c  3bc3                   +cmp eax, ebx
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
    // 0042d78e  753e                   -jne 0x42d7ce
    if (!cpu.flags.zf)
    {
        goto L_0x0042d7ce;
    }
    // 0042d790  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042d793  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d794  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d796  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d797  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d798  68a00e4300             -push 0x430ea0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394656 /*0x430ea0*/;
    cpu.esp -= 4;
    // 0042d79d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d79e  ff1548004300           -call dword ptr [0x430048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390984) /* 0x430048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d7a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d7a6  7404                   -je 0x42d7ac
    if (cpu.flags.zf)
    {
        goto L_0x0042d7ac;
    }
    // 0042d7a8  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042d7aa  eb1d                   -jmp 0x42d7c9
    goto L_0x0042d7c9;
L_0x0042d7ac:
    // 0042d7ac  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042d7af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d7b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d7b1  689c0e4300             -push 0x430e9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394652 /*0x430e9c*/;
    cpu.esp -= 4;
    // 0042d7b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d7b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d7b8  ff154c004300           -call dword ptr [0x43004c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390988) /* 0x43004c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d7be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d7c0  0f84ce000000           -je 0x42d894
    if (cpu.flags.zf)
    {
        return sub_42d894(app, cpu);
    }
    // 0042d7c6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042d7c8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042d7c9:
    // 0042d7c9  a3a8564900             -mov dword ptr [0x4956a8], eax
    app->getMemory<x86::reg32>(x86::reg32(4806312) /* 0x4956a8 */) = cpu.eax;
L_0x0042d7ce:
    // 0042d7ce  83f802                 +cmp eax, 2
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
    // 0042d7d1  7524                   -jne 0x42d7f7
    if (!cpu.flags.zf)
    {
        goto L_0x0042d7f7;
    }
    // 0042d7d3  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0042d7d6  3bc3                   +cmp eax, ebx
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
    // 0042d7d8  7505                   -jne 0x42d7df
    if (!cpu.flags.zf)
    {
        goto L_0x0042d7df;
    }
    // 0042d7da  a17c564900             -mov eax, dword ptr [0x49567c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806268) /* 0x49567c */);
L_0x0042d7df:
    // 0042d7df  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d7e2  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d7e5  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d7e8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d7eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d7ec  ff154c004300           -call dword ptr [0x43004c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390988) /* 0x43004c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d7f2  e99f000000             -jmp 0x42d896
    return sub_42d896(app, cpu);
L_0x0042d7f7:
    // 0042d7f7  83f801                 +cmp eax, 1
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
    // 0042d7fa  0f8594000000           -jne 0x42d894
    if (!cpu.flags.zf)
    {
        return sub_42d894(app, cpu);
    }
    // 0042d800  395d18                 +cmp dword ptr [ebp + 0x18], ebx
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
    // 0042d803  7508                   -jne 0x42d80d
    if (!cpu.flags.zf)
    {
        goto L_0x0042d80d;
    }
    // 0042d805  a18c564900             -mov eax, dword ptr [0x49568c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    // 0042d80a  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0042d80d:
    // 0042d80d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d80e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d80f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d812  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d815  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0042d818  f7d8                   +neg eax
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
    // 0042d81a  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0042d81c  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042d81f  40                     -inc eax
    (cpu.eax)++;
    // 0042d820  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d821  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d824  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d82a  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0042d82d  3bc3                   +cmp eax, ebx
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
    // 0042d82f  7463                   -je 0x42d894
    if (cpu.flags.zf)
    {
        return sub_42d894(app, cpu);
    }
    // 0042d831  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0042d834  8d3c00                 -lea edi, [eax + eax]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 0042d837  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042d839  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042d83c  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042d83e  e88d7effff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042d843  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042d846  8bf4                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0042d848  8975dc                 -mov dword ptr [ebp - 0x24], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.esi;
    // 0042d84b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d84c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d84d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d84e  e8bdd9ffff             -call 0x42b210
    cpu.esp -= 4;
    sub_42b210(app, cpu);
    // 0042d853  83c40c                 +add esp, 0xc
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
    // 0042d856  eb0b                   -jmp 0x42d863
    return sub_42d863(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42d858(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d858  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d85a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d85b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d85c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d85c  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d85f  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042d861  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042d863  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042d867  3bf3                   +cmp esi, ebx
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
    // 0042d869  7429                   -je 0x42d894
    if (cpu.flags.zf)
    {
        goto L_0x0042d894;
    }
    // 0042d86b  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0042d86e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d86f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d872  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d875  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d877  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d87a  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d880  3bc3                   +cmp eax, ebx
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
    // 0042d882  7410                   -je 0x42d894
    if (cpu.flags.zf)
    {
        goto L_0x0042d894;
    }
    // 0042d884  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d887  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d888  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d889  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d88c  ff1548004300           -call dword ptr [0x430048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390984) /* 0x430048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d892  eb02                   -jmp 0x42d896
    goto L_0x0042d896;
L_0x0042d894:
    // 0042d894  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042d896:
    // 0042d896  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0042d899  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042d89c  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042d8a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d863(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042d863;
    // 0042d85c  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d85f  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042d861  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_entry_0x0042d863:
    // 0042d863  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042d867  3bf3                   +cmp esi, ebx
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
    // 0042d869  7429                   -je 0x42d894
    if (cpu.flags.zf)
    {
        goto L_0x0042d894;
    }
    // 0042d86b  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0042d86e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d86f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d872  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d875  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d877  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d87a  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d880  3bc3                   +cmp eax, ebx
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
    // 0042d882  7410                   -je 0x42d894
    if (cpu.flags.zf)
    {
        goto L_0x0042d894;
    }
    // 0042d884  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d887  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d888  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d889  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d88c  ff1548004300           -call dword ptr [0x430048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390984) /* 0x430048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d892  eb02                   -jmp 0x42d896
    goto L_0x0042d896;
L_0x0042d894:
    // 0042d894  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042d896:
    // 0042d896  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0042d899  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042d89c  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042d8a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d896(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042d896;
    // 0042d85c  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d85f  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042d861  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042d863  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042d867  3bf3                   +cmp esi, ebx
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
    // 0042d869  7429                   -je 0x42d894
    if (cpu.flags.zf)
    {
        goto L_0x0042d894;
    }
    // 0042d86b  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0042d86e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d86f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d872  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d875  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d877  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d87a  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d880  3bc3                   +cmp eax, ebx
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
    // 0042d882  7410                   -je 0x42d894
    if (cpu.flags.zf)
    {
        goto L_0x0042d894;
    }
    // 0042d884  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d887  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d888  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d889  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d88c  ff1548004300           -call dword ptr [0x430048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390984) /* 0x430048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d892  eb02                   -jmp 0x42d896
    goto L_0x0042d896;
L_0x0042d894:
    // 0042d894  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042d896:
L_entry_0x0042d896:
    // 0042d896  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0042d899  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042d89c  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042d8a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d894(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042d894;
    // 0042d85c  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d85f  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042d861  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042d863  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042d867  3bf3                   +cmp esi, ebx
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
    // 0042d869  7429                   -je 0x42d894
    if (cpu.flags.zf)
    {
        goto L_0x0042d894;
    }
    // 0042d86b  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0042d86e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d86f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d872  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d875  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d877  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d87a  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d880  3bc3                   +cmp eax, ebx
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
    // 0042d882  7410                   -je 0x42d894
    if (cpu.flags.zf)
    {
        goto L_0x0042d894;
    }
    // 0042d884  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d887  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d888  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d889  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d88c  ff1548004300           -call dword ptr [0x430048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390984) /* 0x430048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d892  eb02                   -jmp 0x42d896
    goto L_0x0042d896;
L_0x0042d894:
L_entry_0x0042d894:
    // 0042d894  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042d896:
    // 0042d896  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0042d899  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042d89c  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042d8a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d8a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d8a8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d8a9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042d8ab  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042d8ad  68b80e4300             -push 0x430eb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394680 /*0x430eb8*/;
    cpu.esp -= 4;
    // 0042d8b2  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 0042d8b7  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0042d8bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d8be  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0042d8c5  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042d8c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d8c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d8ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d8cb  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042d8ce  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042d8d0  393dac564900           +cmp dword ptr [0x4956ac], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806316) /* 0x4956ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d8d6  7546                   -jne 0x42d91e
    if (!cpu.flags.zf)
    {
        goto L_0x0042d91e;
    }
    // 0042d8d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d8d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d8da  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d8dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d8de  68a00e4300             -push 0x430ea0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394656 /*0x430ea0*/;
    cpu.esp -= 4;
    // 0042d8e3  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
    // 0042d8e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d8e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d8ea  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d8f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d8f2  7408                   -je 0x42d8fc
    if (cpu.flags.zf)
    {
        goto L_0x0042d8fc;
    }
    // 0042d8f4  891dac564900           -mov dword ptr [0x4956ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(4806316) /* 0x4956ac */) = cpu.ebx;
    // 0042d8fa  eb22                   -jmp 0x42d91e
    goto L_0x0042d91e;
L_0x0042d8fc:
    // 0042d8fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d8fd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d8fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d8ff  689c0e4300             -push 0x430e9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394652 /*0x430e9c*/;
    cpu.esp -= 4;
    // 0042d904  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d905  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d906  ff1544004300           -call dword ptr [0x430044]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390980) /* 0x430044 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d90c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d90e  0f8422010000           -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042d914  c705ac56490002000000   -mov dword ptr [0x4956ac], 2
    app->getMemory<x86::reg32>(x86::reg32(4806316) /* 0x4956ac */) = 2 /*0x2*/;
L_0x0042d91e:
    // 0042d91e  397d14                 +cmp dword ptr [ebp + 0x14], edi
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
    // 0042d921  7e10                   -jle 0x42d933
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042d933;
    }
    // 0042d923  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d926  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d929  e89e010000             -call 0x42dacc
    cpu.esp -= 4;
    sub_42dacc(app, cpu);
    // 0042d92e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d92f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d930  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x0042d933:
    // 0042d933  a1ac564900             -mov eax, dword ptr [0x4956ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806316) /* 0x4956ac */);
    // 0042d938  83f802                 +cmp eax, 2
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
    // 0042d93b  751d                   -jne 0x42d95a
    if (!cpu.flags.zf)
    {
        goto L_0x0042d95a;
    }
    // 0042d93d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042d940  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d943  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d946  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d949  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d94c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d94f  ff1544004300           -call dword ptr [0x430044]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390980) /* 0x430044 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d955  e9de000000             -jmp 0x42da38
    return sub_42da38(app, cpu);
L_0x0042d95a:
    // 0042d95a  83f801                 +cmp eax, 1
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
    // 0042d95d  0f85d3000000           -jne 0x42da36
    if (!cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042d963  397d20                 +cmp dword ptr [ebp + 0x20], edi
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
    // 0042d966  7508                   -jne 0x42d970
    if (!cpu.flags.zf)
    {
        goto L_0x0042d970;
    }
    // 0042d968  a18c564900             -mov eax, dword ptr [0x49568c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    // 0042d96d  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0042d970:
    // 0042d970  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d972  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d975  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d978  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0042d97b  f7d8                   +neg eax
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
    // 0042d97d  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0042d97f  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042d982  40                     -inc eax
    (cpu.eax)++;
    // 0042d983  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d984  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042d987  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d98d  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042d98f  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 0042d992  3bdf                   +cmp ebx, edi
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
    // 0042d994  0f849c000000           -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042d99a  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0042d99d  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 0042d9a0  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042d9a3  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042d9a5  e8267dffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042d9aa  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042d9ad  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0042d9af  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0042d9b2  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042d9b6  eb13                   -jmp 0x42d9cb
    return sub_42d9cb(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42d9b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d9b8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d9ba  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d9bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d9bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d9bc  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d9bf  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042d9c1  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0042d9c4  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042d9c8  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042d9cb  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 0042d9ce  7466                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042d9d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d9d1  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042d9d4  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d9d7  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d9da  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d9dc  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042d9df  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d9e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d9e7  744d                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042d9e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d9ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d9eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d9ec  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042d9ef  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d9f2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d9f5  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d9fb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d9fd  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0042da00  3bf7                   +cmp esi, edi
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
    // 0042da02  7432                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042da04  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0042da08  7440                   -je 0x42da4a
    if (cpu.flags.zf)
    {
        goto L_0x0042da4a;
    }
    // 0042da0a  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0042da0d  0f84b2000000           -je 0x42dac5
    if (cpu.flags.zf)
    {
        return sub_42dac5(app, cpu);
    }
    // 0042da13  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0042da16  7f1e                   -jg 0x42da36
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042da36;
    }
    // 0042da18  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042da1b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042da1e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042da1f  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042da22  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042da25  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042da28  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042da2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da30  0f858f000000           -jne 0x42dac5
    if (!cpu.flags.zf)
    {
        return sub_42dac5(app, cpu);
    }
L_0x0042da36:
    // 0042da36  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042da38  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0042da3b  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042da3e  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042da45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da48  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042da4a:
    // 0042da4a  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0042da51  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0042da54  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042da57  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042da59  e8727cffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042da5e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042da61  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0042da63  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0042da66  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042da6a  eb12                   -jmp 0x42da7e
    return sub_42da7e(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42d9cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042d9cb;
    // 0042d9bc  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d9bf  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042d9c1  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0042d9c4  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042d9c8  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
L_entry_0x0042d9cb:
    // 0042d9cb  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 0042d9ce  7466                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042d9d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d9d1  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042d9d4  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d9d7  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d9da  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d9dc  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042d9df  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d9e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d9e7  744d                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042d9e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d9ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d9eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d9ec  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042d9ef  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d9f2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d9f5  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d9fb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d9fd  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0042da00  3bf7                   +cmp esi, edi
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
    // 0042da02  7432                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042da04  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0042da08  7440                   -je 0x42da4a
    if (cpu.flags.zf)
    {
        goto L_0x0042da4a;
    }
    // 0042da0a  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0042da0d  0f84b2000000           -je 0x42dac5
    if (cpu.flags.zf)
    {
        return sub_42dac5(app, cpu);
    }
    // 0042da13  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0042da16  7f1e                   -jg 0x42da36
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042da36;
    }
    // 0042da18  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042da1b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042da1e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042da1f  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042da22  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042da25  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042da28  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042da2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da30  0f858f000000           -jne 0x42dac5
    if (!cpu.flags.zf)
    {
        return sub_42dac5(app, cpu);
    }
L_0x0042da36:
    // 0042da36  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042da38  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0042da3b  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042da3e  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042da45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da48  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042da4a:
    // 0042da4a  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0042da51  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0042da54  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042da57  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042da59  e8727cffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042da5e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042da61  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0042da63  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0042da66  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042da6a  eb12                   -jmp 0x42da7e
    return sub_42da7e(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42da38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042da38;
    // 0042d9bc  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d9bf  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042d9c1  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0042d9c4  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042d9c8  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042d9cb  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 0042d9ce  7466                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042d9d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d9d1  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042d9d4  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d9d7  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d9da  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d9dc  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042d9df  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d9e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d9e7  744d                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042d9e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d9ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d9eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d9ec  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042d9ef  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d9f2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d9f5  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d9fb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d9fd  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0042da00  3bf7                   +cmp esi, edi
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
    // 0042da02  7432                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042da04  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0042da08  7440                   -je 0x42da4a
    if (cpu.flags.zf)
    {
        goto L_0x0042da4a;
    }
    // 0042da0a  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0042da0d  0f84b2000000           -je 0x42dac5
    if (cpu.flags.zf)
    {
        return sub_42dac5(app, cpu);
    }
    // 0042da13  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0042da16  7f1e                   -jg 0x42da36
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042da36;
    }
    // 0042da18  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042da1b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042da1e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042da1f  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042da22  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042da25  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042da28  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042da2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da30  0f858f000000           -jne 0x42dac5
    if (!cpu.flags.zf)
    {
        return sub_42dac5(app, cpu);
    }
L_0x0042da36:
    // 0042da36  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_entry_0x0042da38:
    // 0042da38  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0042da3b  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042da3e  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042da45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da48  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042da4a:
    // 0042da4a  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0042da51  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0042da54  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042da57  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042da59  e8727cffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042da5e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042da61  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0042da63  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0042da66  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042da6a  eb12                   -jmp 0x42da7e
    return sub_42da7e(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42da36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042da36;
    // 0042d9bc  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d9bf  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042d9c1  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0042d9c4  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042d9c8  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042d9cb  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 0042d9ce  7466                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042d9d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d9d1  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042d9d4  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042d9d7  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042d9da  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d9dc  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042d9df  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d9e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d9e7  744d                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042d9e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d9ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d9eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d9ec  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042d9ef  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d9f2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d9f5  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d9fb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d9fd  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0042da00  3bf7                   +cmp esi, edi
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
    // 0042da02  7432                   -je 0x42da36
    if (cpu.flags.zf)
    {
        goto L_0x0042da36;
    }
    // 0042da04  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0042da08  7440                   -je 0x42da4a
    if (cpu.flags.zf)
    {
        goto L_0x0042da4a;
    }
    // 0042da0a  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0042da0d  0f84b2000000           -je 0x42dac5
    if (cpu.flags.zf)
    {
        return sub_42dac5(app, cpu);
    }
    // 0042da13  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0042da16  7f1e                   -jg 0x42da36
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042da36;
    }
    // 0042da18  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042da1b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042da1e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042da1f  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042da22  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042da25  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042da28  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042da2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da30  0f858f000000           -jne 0x42dac5
    if (!cpu.flags.zf)
    {
        return sub_42dac5(app, cpu);
    }
L_0x0042da36:
L_entry_0x0042da36:
    // 0042da36  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042da38  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0042da3b  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042da3e  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042da45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da48  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042da4a:
    // 0042da4a  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0042da51  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0042da54  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042da57  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042da59  e8727cffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042da5e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042da61  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0042da63  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0042da66  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042da6a  eb12                   -jmp 0x42da7e
    return sub_42da7e(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42da6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042da6c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042da6e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42da70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042da70  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042da73  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042da75  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042da77  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042da7b  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0042da7e  3bdf                   +cmp ebx, edi
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
    // 0042da80  74b4                   -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042da82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042da83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042da84  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042da87  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042da8a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042da8d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042da90  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042da96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da98  749c                   -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042da9a  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0042da9d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042da9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042da9f  7504                   -jne 0x42daa5
    if (!cpu.flags.zf)
    {
        goto L_0x0042daa5;
    }
    // 0042daa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042daa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042daa3  eb06                   -jmp 0x42daab
    goto L_0x0042daab;
L_0x0042daa5:
    // 0042daa5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042daa8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x0042daab:
    // 0042daab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042daac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042daad  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 0042dab2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042dab5  ff1514014300           -call dword ptr [0x430114]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391188) /* 0x430114 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042dabb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042dabd  3bf7                   +cmp esi, edi
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
    // 0042dabf  0f8471ffffff           -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042dac5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042dac7  e96cffffff             -jmp 0x42da38
    return sub_42da38(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42da7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042da7e;
    // 0042da70  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042da73  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042da75  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042da77  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042da7b  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
L_entry_0x0042da7e:
    // 0042da7e  3bdf                   +cmp ebx, edi
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
    // 0042da80  74b4                   -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042da82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042da83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042da84  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042da87  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042da8a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042da8d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042da90  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042da96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da98  749c                   -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042da9a  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0042da9d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042da9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042da9f  7504                   -jne 0x42daa5
    if (!cpu.flags.zf)
    {
        goto L_0x0042daa5;
    }
    // 0042daa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042daa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042daa3  eb06                   -jmp 0x42daab
    goto L_0x0042daab;
L_0x0042daa5:
    // 0042daa5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042daa8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x0042daab:
    // 0042daab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042daac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042daad  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 0042dab2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042dab5  ff1514014300           -call dword ptr [0x430114]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391188) /* 0x430114 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042dabb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042dabd  3bf7                   +cmp esi, edi
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
    // 0042dabf  0f8471ffffff           -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042dac5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042dac7  e96cffffff             -jmp 0x42da38
    return sub_42da38(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42dac5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042dac5;
    // 0042da70  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042da73  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042da75  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042da77  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042da7b  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0042da7e  3bdf                   +cmp ebx, edi
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
    // 0042da80  74b4                   -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042da82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042da83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042da84  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042da87  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042da8a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042da8d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042da90  ff1540004300           -call dword ptr [0x430040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390976) /* 0x430040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042da96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da98  749c                   -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
    // 0042da9a  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0042da9d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042da9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042da9f  7504                   -jne 0x42daa5
    if (!cpu.flags.zf)
    {
        goto L_0x0042daa5;
    }
    // 0042daa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042daa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042daa3  eb06                   -jmp 0x42daab
    goto L_0x0042daab;
L_0x0042daa5:
    // 0042daa5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042daa8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x0042daab:
    // 0042daab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042daac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042daad  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 0042dab2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042dab5  ff1514014300           -call dword ptr [0x430114]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391188) /* 0x430114 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042dabb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042dabd  3bf7                   +cmp esi, edi
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
    // 0042dabf  0f8471ffffff           -je 0x42da36
    if (cpu.flags.zf)
    {
        return sub_42da36(app, cpu);
    }
L_entry_0x0042dac5:
    // 0042dac5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042dac7  e96cffffff             -jmp 0x42da38
    return sub_42da38(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42dacc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dacc  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042dad0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042dad4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042dad6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dad7  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0042dada  740d                   -je 0x42dae9
    if (cpu.flags.zf)
    {
        goto L_0x0042dae9;
    }
L_0x0042dadc:
    // 0042dadc  803800                 +cmp byte ptr [eax], 0
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
    // 0042dadf  7408                   -je 0x42dae9
    if (cpu.flags.zf)
    {
        goto L_0x0042dae9;
    }
    // 0042dae1  40                     -inc eax
    (cpu.eax)++;
    // 0042dae2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042dae4  49                     -dec ecx
    (cpu.ecx)--;
    // 0042dae5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042dae7  75f3                   -jne 0x42dadc
    if (!cpu.flags.zf)
    {
        goto L_0x0042dadc;
    }
L_0x0042dae9:
    // 0042dae9  803800                 +cmp byte ptr [eax], 0
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
    // 0042daec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042daed  7505                   -jne 0x42daf4
    if (!cpu.flags.zf)
    {
        goto L_0x0042daf4;
    }
    // 0042daef  2b442404               -sub eax, dword ptr [esp + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0042daf3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042daf4:
    // 0042daf4  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042daf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42daf7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042daf7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042dafb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dafc  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042db00  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042db02  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0042db05  3bca                   +cmp ecx, edx
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
    // 0042db07  7204                   -jb 0x42db0d
    if (cpu.flags.cf)
    {
        goto L_0x0042db0d;
    }
    // 0042db09  3bce                   +cmp ecx, esi
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
    // 0042db0b  7303                   -jae 0x42db10
    if (!cpu.flags.cf)
    {
        goto L_0x0042db10;
    }
L_0x0042db0d:
    // 0042db0d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042db0f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042db10:
    // 0042db10  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042db14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042db15  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0042db17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42db18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042db18  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042db19  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042db1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042db1e  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042db22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042db23  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 0042db25  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0042db27  e8cbffffff             -call 0x42daf7
    cpu.esp -= 4;
    sub_42daf7(app, cpu);
    // 0042db2c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042db2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042db31  7417                   -je 0x42db4a
    if (cpu.flags.zf)
    {
        goto L_0x0042db4a;
    }
    // 0042db33  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042db36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042db37  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042db39  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 0042db3b  e8b7ffffff             -call 0x42daf7
    cpu.esp -= 4;
    sub_42daf7(app, cpu);
    // 0042db40  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042db43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042db45  7403                   -je 0x42db4a
    if (cpu.flags.zf)
    {
        goto L_0x0042db4a;
    }
    // 0042db47  ff4608                 -inc dword ptr [esi + 8]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */))++;
L_0x0042db4a:
    // 0042db4a  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042db4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042db4e  ff7704                 -push dword ptr [edi + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0042db51  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 0042db53  e89fffffff             -call 0x42daf7
    cpu.esp -= 4;
    sub_42daf7(app, cpu);
    // 0042db58  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042db5b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042db5d  7403                   -je 0x42db62
    if (cpu.flags.zf)
    {
        goto L_0x0042db62;
    }
    // 0042db5f  ff4608                 -inc dword ptr [esi + 8]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */))++;
L_0x0042db62:
    // 0042db62  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0042db65  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042db66  ff7708                 -push dword ptr [edi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042db69  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 0042db6b  e887ffffff             -call 0x42daf7
    cpu.esp -= 4;
    sub_42daf7(app, cpu);
    // 0042db70  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042db73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042db74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042db75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42db76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042db76  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042db7a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042db7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042db7c  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0042db7e  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042db81  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042db83  03f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042db85  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0042db87  8d343f                 -lea esi, [edi + edi]
    cpu.esi = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0042db8a  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0042db8d  0bf1                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042db8f  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042db92  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042db94  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0042db97  c1ea1f                 -shr edx, 0x1f
    cpu.edx >>= 31 /*0x1f*/ % 32;
    // 0042db9a  d1e1                   -shl ecx, 1
    cpu.ecx <<= 1 /*0x1*/ % 32;
    // 0042db9c  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0042db9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042db9f  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042dba2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dba3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42dba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dba4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042dba8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dba9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042dbaa  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042dbad  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042dbb0  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042dbb2  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042dbb4  c1e61f                 -shl esi, 0x1f
    cpu.esi <<= 31 /*0x1f*/ % 32;
    // 0042dbb7  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 0042dbb9  0bce                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0042dbbb  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0042dbbe  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042dbc0  c1e71f                 -shl edi, 0x1f
    cpu.edi <<= 31 /*0x1f*/ % 32;
    // 0042dbc3  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 0042dbc5  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 0042dbc7  0bcf                   -or ecx, edi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0042dbc9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dbca  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042dbcd  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0042dbcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dbd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42dbd1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dbd1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042dbd2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042dbd4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042dbd7  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042dbda  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dbdb  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042dbde  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042dbe0  3bc2                   +cmp eax, edx
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
    // 0042dbe2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dbe3  c745fc4e400000         -mov dword ptr [ebp - 4], 0x404e
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 16462 /*0x404e*/;
    // 0042dbea  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0042dbec  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042dbef  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042dbf2  7651                   -jbe 0x42dc45
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042dc45;
    }
    // 0042dbf4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042dbf5  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042dbf8:
    // 0042dbf8  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0042dbfa  8d7df0                 -lea edi, [ebp - 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042dbfd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042dbfe  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042dbff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc00  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042dc01  e870ffffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042dc06  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc07  e86affffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042dc0c  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042dc0f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042dc10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc11  e802ffffff             -call 0x42db18
    cpu.esp -= 4;
    sub_42db18(app, cpu);
    // 0042dc16  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc17  e85affffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042dc1c  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042dc1f  8365f400               -and dword ptr [ebp - 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042dc23  8365f800               -and dword ptr [ebp - 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042dc27  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 0042dc2a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0042dc2d  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042dc30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042dc31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc32  e8e1feffff             -call 0x42db18
    cpu.esp -= 4;
    sub_42db18(app, cpu);
    // 0042dc37  83c41c                 +add esp, 0x1c
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
    // 0042dc3a  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042dc3d  ff4d10                 +dec dword ptr [ebp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042dc40  75b6                   -jne 0x42dbf8
    if (!cpu.flags.zf)
    {
        goto L_0x0042dbf8;
    }
    // 0042dc42  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042dc44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042dc45:
    // 0042dc45  395308                 +cmp dword ptr [ebx + 8], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042dc48  7528                   -jne 0x42dc72
    if (!cpu.flags.zf)
    {
        goto L_0x0042dc72;
    }
    // 0042dc4a  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042dc4d  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042dc4f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0042dc52  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042dc55  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042dc57  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042dc59  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 0042dc5c  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0042dc5f  0bf1                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042dc61  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0042dc64  8145fcf0ff0000         +add dword ptr [ebp - 4], 0xfff0
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65520 /*0xfff0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042dc6b  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0042dc6e  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0042dc70  ebd3                   -jmp 0x42dc45
    goto L_0x0042dc45;
L_0x0042dc72:
    // 0042dc72  be00800000             -mov esi, 0x8000
    cpu.esi = 32768 /*0x8000*/;
L_0x0042dc77:
    // 0042dc77  857308                 -test dword ptr [ebx + 8], esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) & cpu.esi));
    // 0042dc7a  7510                   -jne 0x42dc8c
    if (!cpu.flags.zf)
    {
        goto L_0x0042dc8c;
    }
    // 0042dc7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc7d  e8f4feffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042dc82  8145fcffff0000         +add dword ptr [ebp - 4], 0xffff
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042dc89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dc8a  ebeb                   -jmp 0x42dc77
    goto L_0x0042dc77;
L_0x0042dc8c:
    // 0042dc8c  668b45fc               -mov ax, word ptr [ebp - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042dc90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dc91  6689430a               -mov word ptr [ebx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0042dc95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dc96  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dc97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42dc98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0042dc98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042dc99  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042dc9b  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0042dc9e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc9f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dca0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042dca1  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042dca4  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 0042dca7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042dca9  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0042dcac  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042dcae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dcaf  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0042dcb2  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 0042dcb5  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0042dcb8  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0042dcbb  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0042dcbe  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0042dcc1  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0042dcc4  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 0042dcc7  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0042dcca  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0042dccd  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0042dcd0  897d10                 -mov dword ptr [ebp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0042dcd3:
    // 0042dcd3  8a0f                   -mov cl, byte ptr [edi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042dcd5  80f920                 +cmp cl, 0x20
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
    // 0042dcd8  740f                   -je 0x42dce9
    if (cpu.flags.zf)
    {
        goto L_0x0042dce9;
    }
    // 0042dcda  80f909                 +cmp cl, 9
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
    // 0042dcdd  740a                   -je 0x42dce9
    if (cpu.flags.zf)
    {
        goto L_0x0042dce9;
    }
    // 0042dcdf  80f90a                 +cmp cl, 0xa
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
    // 0042dce2  7405                   -je 0x42dce9
    if (cpu.flags.zf)
    {
        goto L_0x0042dce9;
    }
    // 0042dce4  80f90d                 +cmp cl, 0xd
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
    // 0042dce7  7503                   -jne 0x42dcec
    if (!cpu.flags.zf)
    {
        goto L_0x0042dcec;
    }
L_0x0042dce9:
    // 0042dce9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042dcea  ebe7                   -jmp 0x42dcd3
    goto L_0x0042dcd3;
L_0x0042dcec:
    // 0042dcec  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042dcee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042dcef:
    // 0042dcef  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042dcf1  47                     -inc edi
    (cpu.edi)++;
    // 0042dcf2  83f80b                 +cmp eax, 0xb
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
    // 0042dcf5  0f8777020000           -ja 0x42df72
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042df72;
    }
    // 0042dcfb  ff248539e14200         -jmp dword ptr [eax*4 + 0x42e139]
    cpu.ip = app->getMemory<x86::reg32>(4383033 + cpu.eax * 4); goto dynamic_jump;
  case 0x0042dd02:
    // 0042dd02  80fb31                 +cmp bl, 0x31
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
    // 0042dd05  7c0c                   -jl 0x42dd13
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042dd13;
    }
    // 0042dd07  80fb39                 +cmp bl, 0x39
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
    // 0042dd0a  7f07                   -jg 0x42dd13
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042dd13;
    }
L_0x0042dd0c:
    // 0042dd0c  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042dd0e  e91d020000             -jmp 0x42df30
    goto L_0x0042df30;
L_0x0042dd13:
    // 0042dd13  3a1d34d84300           +cmp bl, byte ptr [0x43d834]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042dd19  7507                   -jne 0x42dd22
    if (!cpu.flags.zf)
    {
        goto L_0x0042dd22;
    }
L_0x0042dd1b:
    // 0042dd1b  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0042dd1d  e946020000             -jmp 0x42df68
    goto L_0x0042df68;
L_0x0042dd22:
    // 0042dd22  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0042dd25  83e82b                 +sub eax, 0x2b
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
    // 0042dd28  741e                   -je 0x42dd48
    if (cpu.flags.zf)
    {
        goto L_0x0042dd48;
    }
    // 0042dd2a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042dd2b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042dd2c  740e                   -je 0x42dd3c
    if (cpu.flags.zf)
    {
        goto L_0x0042dd3c;
    }
    // 0042dd2e  83e803                 +sub eax, 3
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
    // 0042dd31  0f85d4020000           -jne 0x42e00b
    if (!cpu.flags.zf)
    {
        goto L_0x0042e00b;
    }
    // 0042dd37  e98f000000             -jmp 0x42ddcb
    goto L_0x0042ddcb;
L_0x0042dd3c:
    // 0042dd3c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042dd3e  c745d800800000         -mov dword ptr [ebp - 0x28], 0x8000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = 32768 /*0x8000*/;
    // 0042dd45  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd46  eba7                   -jmp 0x42dcef
    goto L_0x0042dcef;
L_0x0042dd48:
    // 0042dd48  8365d800               +and dword ptr [ebp - 0x28], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0042dd4c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042dd4e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd4f  eb9e                   -jmp 0x42dcef
    goto L_0x0042dcef;
  case 0x0042dd51:
    // 0042dd51  80fb31                 +cmp bl, 0x31
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
    // 0042dd54  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0042dd57  7c05                   -jl 0x42dd5e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042dd5e;
    }
    // 0042dd59  80fb39                 +cmp bl, 0x39
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
    // 0042dd5c  7eae                   -jle 0x42dd0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042dd0c;
    }
L_0x0042dd5e:
    // 0042dd5e  3a1d34d84300           +cmp bl, byte ptr [0x43d834]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042dd64  0f84bc000000           -je 0x42de26
    if (cpu.flags.zf)
    {
        goto L_0x0042de26;
    }
    // 0042dd6a  80fb2b                 +cmp bl, 0x2b
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
    // 0042dd6d  7431                   -je 0x42dda0
    if (cpu.flags.zf)
    {
        goto L_0x0042dda0;
    }
    // 0042dd6f  80fb2d                 +cmp bl, 0x2d
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
    // 0042dd72  742c                   -je 0x42dda0
    if (cpu.flags.zf)
    {
        goto L_0x0042dda0;
    }
    // 0042dd74  80fb30                 +cmp bl, 0x30
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
    // 0042dd77  7452                   -je 0x42ddcb
    if (cpu.flags.zf)
    {
        goto L_0x0042ddcb;
    }
L_0x0042dd79:
    // 0042dd79  80fb43                 +cmp bl, 0x43
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
    // 0042dd7c  0f8e89020000           -jle 0x42e00b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e00b;
    }
    // 0042dd82  80fb45                 +cmp bl, 0x45
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
    // 0042dd85  7e12                   -jle 0x42dd99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042dd99;
    }
    // 0042dd87  80fb63                 +cmp bl, 0x63
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
    // 0042dd8a  0f8e7b020000           -jle 0x42e00b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e00b;
    }
    // 0042dd90  80fb65                 +cmp bl, 0x65
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
    // 0042dd93  0f8f72020000           -jg 0x42e00b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042e00b;
    }
L_0x0042dd99:
    // 0042dd99  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0042dd9b  e9c8010000             -jmp 0x42df68
    goto L_0x0042df68;
L_0x0042dda0:
    // 0042dda0  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042dda1  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 0042dda3  e9c0010000             -jmp 0x42df68
    goto L_0x0042df68;
  case 0x0042dda8:
    // 0042dda8  80fb31                 +cmp bl, 0x31
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
    // 0042ddab  7c09                   -jl 0x42ddb6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ddb6;
    }
    // 0042ddad  80fb39                 +cmp bl, 0x39
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
    // 0042ddb0  0f8e56ffffff           -jle 0x42dd0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042dd0c;
    }
L_0x0042ddb6:
    // 0042ddb6  3a1d34d84300           +cmp bl, byte ptr [0x43d834]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ddbc  0f8459ffffff           -je 0x42dd1b
    if (cpu.flags.zf)
    {
        goto L_0x0042dd1b;
    }
    // 0042ddc2  80fb30                 +cmp bl, 0x30
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
    // 0042ddc5  0f85b5010000           -jne 0x42df80
    if (!cpu.flags.zf)
    {
        goto L_0x0042df80;
    }
L_0x0042ddcb:
    // 0042ddcb  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042ddcd  e91dffffff             -jmp 0x42dcef
    goto L_0x0042dcef;
  case 0x0042ddd2:
    // 0042ddd2  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x0042ddd5:
    // 0042ddd5  391530d84300           +cmp dword ptr [0x43d830], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042dddb  7e11                   -jle 0x42ddee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ddee;
    }
    // 0042dddd  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042dde0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dde1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042dde2  e87adeffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042dde7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dde8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dde9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042ddeb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ddec  eb0e                   -jmp 0x42ddfc
    goto L_0x0042ddfc;
L_0x0042ddee:
    // 0042ddee  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042ddf4  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042ddf7  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0042ddfa  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042ddfc:
    // 0042ddfc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ddfe  741e                   -je 0x42de1e
    if (cpu.flags.zf)
    {
        goto L_0x0042de1e;
    }
    // 0042de00  837dfc19               +cmp dword ptr [ebp - 4], 0x19
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
    // 0042de04  7310                   -jae 0x42de16
    if (!cpu.flags.cf)
    {
        goto L_0x0042de16;
    }
    // 0042de06  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042de09  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042de0c  80eb30                 +sub bl, 0x30
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
    // 0042de0f  ff45f4                 +inc dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042de12  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0042de14  eb03                   -jmp 0x42de19
    goto L_0x0042de19;
L_0x0042de16:
    // 0042de16  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042de19:
    // 0042de19  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042de1b  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042de1c  ebb7                   -jmp 0x42ddd5
    goto L_0x0042ddd5;
L_0x0042de1e:
    // 0042de1e  3a1d34d84300           +cmp bl, byte ptr [0x43d834]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042de24  7567                   -jne 0x42de8d
    if (!cpu.flags.zf)
    {
        goto L_0x0042de8d;
    }
L_0x0042de26:
    // 0042de26  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042de28  e9c2feffff             -jmp 0x42dcef
    goto L_0x0042dcef;
  case 0x0042de2d:
    // 0042de2d  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 0042de31  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0042de34  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 0042de37  750d                   -jne 0x42de46
    if (!cpu.flags.zf)
    {
        goto L_0x0042de46;
    }
L_0x0042de39:
    // 0042de39  80fb30                 +cmp bl, 0x30
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
    // 0042de3c  7508                   -jne 0x42de46
    if (!cpu.flags.zf)
    {
        goto L_0x0042de46;
    }
    // 0042de3e  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042de41  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042de43  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042de44  ebf3                   -jmp 0x42de39
    goto L_0x0042de39;
L_0x0042de46:
    // 0042de46  391530d84300           +cmp dword ptr [0x43d830], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042de4c  7e11                   -jle 0x42de5f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042de5f;
    }
    // 0042de4e  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042de51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042de52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042de53  e809deffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042de58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042de59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042de5a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042de5c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042de5d  eb0e                   -jmp 0x42de6d
    goto L_0x0042de6d;
L_0x0042de5f:
    // 0042de5f  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042de65  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042de68  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0042de6b  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042de6d:
    // 0042de6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042de6f  741c                   -je 0x42de8d
    if (cpu.flags.zf)
    {
        goto L_0x0042de8d;
    }
    // 0042de71  837dfc19               +cmp dword ptr [ebp - 4], 0x19
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
    // 0042de75  7311                   -jae 0x42de88
    if (!cpu.flags.cf)
    {
        goto L_0x0042de88;
    }
    // 0042de77  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042de7a  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042de7d  80eb30                 +sub bl, 0x30
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
    // 0042de80  ff45f4                 +inc dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042de83  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042de86  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x0042de88:
    // 0042de88  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042de8a  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042de8b  ebb9                   -jmp 0x42de46
    goto L_0x0042de46;
L_0x0042de8d:
    // 0042de8d  80fb2b                 +cmp bl, 0x2b
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
    // 0042de90  0f840affffff           -je 0x42dda0
    if (cpu.flags.zf)
    {
        goto L_0x0042dda0;
    }
    // 0042de96  80fb2d                 +cmp bl, 0x2d
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
    // 0042de99  0f8401ffffff           -je 0x42dda0
    if (cpu.flags.zf)
    {
        goto L_0x0042dda0;
    }
    // 0042de9f  e9d5feffff             -jmp 0x42dd79
    goto L_0x0042dd79;
  case 0x0042dea4:
    // 0042dea4  391530d84300           +cmp dword ptr [0x43d830], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042deaa  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 0042dead  7e11                   -jle 0x42dec0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042dec0;
    }
    // 0042deaf  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042deb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042deb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042deb4  e8a8ddffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042deb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042deba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042debb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042debd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042debe  eb0e                   -jmp 0x42dece
    goto L_0x0042dece;
L_0x0042dec0:
    // 0042dec0  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042dec6  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042dec9  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0042decc  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042dece:
    // 0042dece  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ded0  0f84aa000000           -je 0x42df80
    if (cpu.flags.zf)
    {
        goto L_0x0042df80;
    }
    // 0042ded6  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ded8  eb57                   -jmp 0x42df31
    goto L_0x0042df31;
  case 0x0042deda:
    // 0042deda  8d4ffe                 -lea ecx, [edi - 2]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 0042dedd  80fb31                 +cmp bl, 0x31
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
    // 0042dee0  894d10                 -mov dword ptr [ebp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042dee3  7c05                   -jl 0x42deea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042deea;
    }
    // 0042dee5  80fb39                 +cmp bl, 0x39
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
    // 0042dee8  7e44                   -jle 0x42df2e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042df2e;
    }
L_0x0042deea:
    // 0042deea  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0042deed  83e82b                 +sub eax, 0x2b
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
    // 0042def0  7474                   -je 0x42df66
    if (cpu.flags.zf)
    {
        goto L_0x0042df66;
    }
    // 0042def2  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042def3  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042def4  7464                   -je 0x42df5a
    if (cpu.flags.zf)
    {
        goto L_0x0042df5a;
    }
    // 0042def6  83e803                 +sub eax, 3
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
    // 0042def9  0f850f010000           -jne 0x42e00e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e00e;
    }
L_0x0042deff:
    // 0042deff  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042df01  eb65                   -jmp 0x42df68
    goto L_0x0042df68;
  case 0x0042df03:
    // 0042df03  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
L_0x0042df06:
    // 0042df06  80fb30                 +cmp bl, 0x30
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
    // 0042df09  7505                   -jne 0x42df10
    if (!cpu.flags.zf)
    {
        goto L_0x0042df10;
    }
    // 0042df0b  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042df0d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042df0e  ebf6                   -jmp 0x42df06
    goto L_0x0042df06;
L_0x0042df10:
    // 0042df10  80fb31                 +cmp bl, 0x31
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
    // 0042df13  0f8cf2000000           -jl 0x42e00b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042e00b;
    }
    // 0042df19  80fb39                 +cmp bl, 0x39
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
    // 0042df1c  0f8fe9000000           -jg 0x42e00b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042e00b;
    }
    // 0042df22  eb0a                   -jmp 0x42df2e
    goto L_0x0042df2e;
  case 0x0042df24:
    // 0042df24  80fb31                 +cmp bl, 0x31
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
    // 0042df27  7c0e                   -jl 0x42df37
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042df37;
    }
    // 0042df29  80fb39                 +cmp bl, 0x39
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
    // 0042df2c  7f09                   -jg 0x42df37
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042df37;
    }
L_0x0042df2e:
    // 0042df2e  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
L_0x0042df30:
    // 0042df30  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042df31:
    // 0042df31  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042df32  e9b8fdffff             -jmp 0x42dcef
    goto L_0x0042dcef;
L_0x0042df37:
    // 0042df37  80fb30                 +cmp bl, 0x30
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
    // 0042df3a  7544                   -jne 0x42df80
    if (!cpu.flags.zf)
    {
        goto L_0x0042df80;
    }
    // 0042df3c  ebc1                   -jmp 0x42deff
    goto L_0x0042deff;
  case 0x0042df3e:
    // 0042df3e  837d2000               +cmp dword ptr [ebp + 0x20], 0
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
    // 0042df42  742a                   -je 0x42df6e
    if (cpu.flags.zf)
    {
        goto L_0x0042df6e;
    }
    // 0042df44  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0042df47  8d4fff                 -lea ecx, [edi - 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0042df4a  83e82b                 +sub eax, 0x2b
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
    // 0042df4d  894d10                 -mov dword ptr [ebp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042df50  7414                   -je 0x42df66
    if (cpu.flags.zf)
    {
        goto L_0x0042df66;
    }
    // 0042df52  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042df53  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042df54  0f85b4000000           -jne 0x42e00e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e00e;
    }
L_0x0042df5a:
    // 0042df5a  834de8ff               +or dword ptr [ebp - 0x18], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042df5e  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0042df60  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042df61  e989fdffff             -jmp 0x42dcef
    goto L_0x0042dcef;
L_0x0042df66:
    // 0042df66  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
L_0x0042df68:
    // 0042df68  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042df69  e981fdffff             -jmp 0x42dcef
    goto L_0x0042dcef;
L_0x0042df6e:
    // 0042df6e  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0042df70  4f                     -dec edi
    (cpu.edi)--;
    // 0042df71  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
  [[fallthrough]];
  case 0x0042df72:
L_0x0042df72:
    // 0042df72  83f80a                 +cmp eax, 0xa
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
    // 0042df75  0f8495000000           -je 0x42e010
    if (cpu.flags.zf)
    {
        goto L_0x0042e010;
    }
    // 0042df7b  e96ffdffff             -jmp 0x42dcef
    goto L_0x0042dcef;
L_0x0042df80:
    // 0042df80  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042df83  e988000000             -jmp 0x42e010
    goto L_0x0042e010;
  case 0x0042df88:
    // 0042df88  c745e001000000         -mov dword ptr [ebp - 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = 1 /*0x1*/;
    // 0042df8f  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042df91:
    // 0042df91  833d30d8430001         +cmp dword ptr [0x43d830], 1
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
    // 0042df98  7e0f                   -jle 0x42dfa9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042dfa9;
    }
    // 0042df9a  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042df9d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042df9f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042dfa0  e8bcdcffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042dfa5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dfa6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dfa7  eb0f                   -jmp 0x42dfb8
    goto L_0x0042dfb8;
L_0x0042dfa9:
    // 0042dfa9  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042dfaf  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042dfb2  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0042dfb5  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042dfb8:
    // 0042dfb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dfba  741c                   -je 0x42dfd8
    if (cpu.flags.zf)
    {
        goto L_0x0042dfd8;
    }
    // 0042dfbc  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0042dfbf  8d04b6                 -lea eax, [esi + esi*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 4);
    // 0042dfc2  8d7441d0               -lea esi, [ecx + eax*2 - 0x30]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 0042dfc6  81fe50140000           +cmp esi, 0x1450
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
    // 0042dfcc  7f05                   -jg 0x42dfd3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042dfd3;
    }
    // 0042dfce  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042dfd0  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042dfd1  ebbe                   -jmp 0x42df91
    goto L_0x0042df91;
L_0x0042dfd3:
    // 0042dfd3  be51140000             -mov esi, 0x1451
    cpu.esi = 5201 /*0x1451*/;
L_0x0042dfd8:
    // 0042dfd8  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
L_0x0042dfdb:
    // 0042dfdb  833d30d8430001         +cmp dword ptr [0x43d830], 1
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
    // 0042dfe2  7e0f                   -jle 0x42dff3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042dff3;
    }
    // 0042dfe4  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042dfe7  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042dfe9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042dfea  e872dcffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042dfef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dff0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dff1  eb0f                   -jmp 0x42e002
    goto L_0x0042e002;
L_0x0042dff3:
    // 0042dff3  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042dff9  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042dffc  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0042dfff  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042e002:
    // 0042e002  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e004  7405                   -je 0x42e00b
    if (cpu.flags.zf)
    {
        goto L_0x0042e00b;
    }
    // 0042e006  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042e008  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e009  ebd0                   -jmp 0x42dfdb
    goto L_0x0042dfdb;
L_0x0042e00b:
    // 0042e00b  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e00c  eb02                   -jmp 0x42e010
    goto L_0x0042e010;
L_0x0042e00e:
    // 0042e00e  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0042e010:
    // 0042e010  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042e013  837df000               +cmp dword ptr [ebp - 0x10], 0
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
    // 0042e017  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0042e019  0f84d9000000           -je 0x42e0f8
    if (cpu.flags.zf)
    {
        goto L_0x0042e0f8;
    }
    // 0042e01f  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0042e021  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e022  3945fc                 +cmp dword ptr [ebp - 4], eax
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
    // 0042e025  7615                   -jbe 0x42e03c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042e03c;
    }
    // 0042e027  807dbb05               +cmp byte ptr [ebp - 0x45], 5
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
    // 0042e02b  7c03                   -jl 0x42e030
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042e030;
    }
    // 0042e02d  fe45bb                 +inc byte ptr [ebp - 0x45]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-69) /* -0x45 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
L_0x0042e030:
    // 0042e030  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0042e033  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042e036  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e037  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e03a  eb03                   -jmp 0x42e03f
    goto L_0x0042e03f;
L_0x0042e03c:
    // 0042e03c  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x0042e03f:
    // 0042e03f  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 0042e043  0f86a5000000           -jbe 0x42e0ee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042e0ee;
    }
L_0x0042e049:
    // 0042e049  48                     -dec eax
    (cpu.eax)--;
    // 0042e04a  803800                 +cmp byte ptr [eax], 0
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
    // 0042e04d  7508                   -jne 0x42e057
    if (!cpu.flags.zf)
    {
        goto L_0x0042e057;
    }
    // 0042e04f  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e052  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e055  ebf2                   -jmp 0x42e049
    goto L_0x0042e049;
L_0x0042e057:
    // 0042e057  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0042e05a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e05b  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 0042e05e  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0042e061  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e062  e86afbffff             -call 0x42dbd1
    cpu.esp -= 4;
    sub_42dbd1(app, cpu);
    // 0042e067  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042e06a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042e06c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e06f  394de8                 +cmp dword ptr [ebp - 0x18], ecx
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
    // 0042e072  7d02                   -jge 0x42e076
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042e076;
    }
    // 0042e074  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0042e076:
    // 0042e076  0345f8                 -add eax, dword ptr [ebp - 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0042e079  394de0                 +cmp dword ptr [ebp - 0x20], ecx
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
    // 0042e07c  7503                   -jne 0x42e081
    if (!cpu.flags.zf)
    {
        goto L_0x0042e081;
    }
    // 0042e07e  034518                 -add eax, dword ptr [ebp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
L_0x0042e081:
    // 0042e081  394ddc                 +cmp dword ptr [ebp - 0x24], ecx
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
    // 0042e084  7503                   -jne 0x42e089
    if (!cpu.flags.zf)
    {
        goto L_0x0042e089;
    }
    // 0042e086  2b451c                 -sub eax, dword ptr [ebp + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
L_0x0042e089:
    // 0042e089  3d50140000             +cmp eax, 0x1450
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
    // 0042e08e  7e30                   -jle 0x42e0c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e0c0;
    }
    // 0042e090  c745d401000000         -mov dword ptr [ebp - 0x2c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = 1 /*0x1*/;
L_0x0042e097:
    // 0042e097  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042e09a  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042e09d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042e0a0  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x0042e0a3:
    // 0042e0a3  837dd400               +cmp dword ptr [ebp - 0x2c], 0
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
    // 0042e0a7  7460                   -je 0x42e109
    if (cpu.flags.zf)
    {
        goto L_0x0042e109;
    }
    // 0042e0a9  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042e0ab  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
    // 0042e0b0  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 0042e0b5  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0042e0b7  c745ec02000000         -mov dword ptr [ebp - 0x14], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 2 /*0x2*/;
    // 0042e0be  eb5e                   -jmp 0x42e11e
    goto L_0x0042e11e;
L_0x0042e0c0:
    // 0042e0c0  3db0ebffff             +cmp eax, 0xffffebb0
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
    // 0042e0c5  7d09                   -jge 0x42e0d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042e0d0;
    }
    // 0042e0c7  c745d001000000         -mov dword ptr [ebp - 0x30], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = 1 /*0x1*/;
    // 0042e0ce  ebc7                   -jmp 0x42e097
    goto L_0x0042e097;
L_0x0042e0d0:
    // 0042e0d0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042e0d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e0d4  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0042e0d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e0d8  e8e8060000             -call 0x42e7c5
    cpu.esp -= 4;
    sub_42e7c5(app, cpu);
    // 0042e0dd  8b55c0                 -mov edx, dword ptr [ebp - 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0042e0e0  8b5dc2                 -mov ebx, dword ptr [ebp - 0x3e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-62) /* -0x3e */);
    // 0042e0e3  8b75c6                 -mov esi, dword ptr [ebp - 0x3a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-58) /* -0x3a */);
    // 0042e0e6  8b45ca                 -mov eax, dword ptr [ebp - 0x36]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-54) /* -0x36 */);
    // 0042e0e9  83c40c                 +add esp, 0xc
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
    // 0042e0ec  ebb5                   -jmp 0x42e0a3
    goto L_0x0042e0a3;
L_0x0042e0ee:
    // 0042e0ee  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042e0f0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e0f2  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042e0f4  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0042e0f6  ebab                   -jmp 0x42e0a3
    goto L_0x0042e0a3;
L_0x0042e0f8:
    // 0042e0f8  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042e0fa  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e0fc  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042e0fe  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0042e100  c745ec04000000         -mov dword ptr [ebp - 0x14], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 4 /*0x4*/;
    // 0042e107  eb15                   -jmp 0x42e11e
    goto L_0x0042e11e;
L_0x0042e109:
    // 0042e109  837dd000               +cmp dword ptr [ebp - 0x30], 0
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
    // 0042e10d  740f                   -je 0x42e11e
    if (cpu.flags.zf)
    {
        goto L_0x0042e11e;
    }
    // 0042e10f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042e111  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e113  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042e115  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042e117  c745ec01000000         -mov dword ptr [ebp - 0x14], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 1 /*0x1*/;
L_0x0042e11e:
    // 0042e11e  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042e121  0b45d8                 -or eax, dword ptr [ebp - 0x28]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 0042e124  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e125  897106                 -mov dword ptr [ecx + 6], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.esi;
    // 0042e128  895902                 -mov dword ptr [ecx + 2], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.ebx;
    // 0042e12b  6689410a               -mov word ptr [ecx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0042e12f  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0042e132  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e133  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 0042e136  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e137  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e138  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_42e169(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e169  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e16a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042e16c  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042e16f  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042e172  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e173  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0042e176  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e177  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042e179  beff7f0000             -mov esi, 0x7fff
    cpu.esi = 32767 /*0x7fff*/;
    // 0042e17e  81e100800000           -and ecx, 0x8000
    cpu.ecx &= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0042e184  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 0042e186  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0042e189  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e18a  c645e4cc               -mov byte ptr [ebp - 0x1c], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 204 /*0xcc*/;
    // 0042e18e  c645e5cc               -mov byte ptr [ebp - 0x1b], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-27) /* -0x1b */) = 204 /*0xcc*/;
    // 0042e192  c645e6cc               -mov byte ptr [ebp - 0x1a], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-26) /* -0x1a */) = 204 /*0xcc*/;
    // 0042e196  c645e7cc               -mov byte ptr [ebp - 0x19], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-25) /* -0x19 */) = 204 /*0xcc*/;
    // 0042e19a  c645e8cc               -mov byte ptr [ebp - 0x18], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = 204 /*0xcc*/;
    // 0042e19e  c645e9cc               -mov byte ptr [ebp - 0x17], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */) = 204 /*0xcc*/;
    // 0042e1a2  c645eacc               -mov byte ptr [ebp - 0x16], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 204 /*0xcc*/;
    // 0042e1a6  c645ebcc               -mov byte ptr [ebp - 0x15], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */) = 204 /*0xcc*/;
    // 0042e1aa  c645eccc               -mov byte ptr [ebp - 0x14], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 204 /*0xcc*/;
    // 0042e1ae  c645edcc               -mov byte ptr [ebp - 0x13], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-19) /* -0x13 */) = 204 /*0xcc*/;
    // 0042e1b2  c645eefb               -mov byte ptr [ebp - 0x12], 0xfb
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-18) /* -0x12 */) = 251 /*0xfb*/;
    // 0042e1b6  c645ef3f               -mov byte ptr [ebp - 0x11], 0x3f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-17) /* -0x11 */) = 63 /*0x3f*/;
    // 0042e1ba  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0042e1c1  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042e1c3  7406                   -je 0x42e1cb
    if (cpu.flags.zf)
    {
        goto L_0x0042e1cb;
    }
    // 0042e1c5  c643022d               -mov byte ptr [ebx + 2], 0x2d
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 45 /*0x2d*/;
    // 0042e1c9  eb04                   -jmp 0x42e1cf
    goto L_0x0042e1cf;
L_0x0042e1cb:
    // 0042e1cb  c6430220               -mov byte ptr [ebx + 2], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32 /*0x20*/;
L_0x0042e1cf:
    // 0042e1cf  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042e1d2  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0042e1d5  751e                   -jne 0x42e1f5
    if (!cpu.flags.zf)
    {
        goto L_0x0042e1f5;
    }
    // 0042e1d7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e1d9  751a                   -jne 0x42e1f5
    if (!cpu.flags.zf)
    {
        goto L_0x0042e1f5;
    }
    // 0042e1db  397d08                 +cmp dword ptr [ebp + 8], edi
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
    // 0042e1de  7515                   -jne 0x42e1f5
    if (!cpu.flags.zf)
    {
        goto L_0x0042e1f5;
    }
L_0x0042e1e0:
    // 0042e1e0  66832300               +and word ptr [ebx], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.ebx) &= x86::reg16(x86::sreg16(0 /*0x0*/))));
    // 0042e1e4  c6430220               -mov byte ptr [ebx + 2], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32 /*0x20*/;
    // 0042e1e8  c6430301               -mov byte ptr [ebx + 3], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 1 /*0x1*/;
    // 0042e1ec  c6430430               -mov byte ptr [ebx + 4], 0x30
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 48 /*0x30*/;
    // 0042e1f0  e9fe010000             -jmp 0x42e3f3
    goto L_0x0042e3f3;
L_0x0042e1f5:
    // 0042e1f5  663bd6                 +cmp dx, si
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.si));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e1f8  757a                   -jne 0x42e274
    if (!cpu.flags.zf)
    {
        goto L_0x0042e274;
    }
    // 0042e1fa  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 0042e1ff  66c7030100             -mov word ptr [ebx], 1
    app->getMemory<x86::reg16>(cpu.ebx) = 1 /*0x1*/;
    // 0042e204  3bf8                   +cmp edi, eax
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
    // 0042e206  7506                   -jne 0x42e20e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e20e;
    }
    // 0042e208  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0042e20c  740f                   -je 0x42e21d
    if (cpu.flags.zf)
    {
        goto L_0x0042e21d;
    }
L_0x0042e20e:
    // 0042e20e  f7c700000040           +test edi, 0x40000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 1073741824 /*0x40000000*/));
    // 0042e214  7507                   -jne 0x42e21d
    if (!cpu.flags.zf)
    {
        goto L_0x0042e21d;
    }
    // 0042e216  68e80e4300             -push 0x430ee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394728 /*0x430ee8*/;
    cpu.esp -= 4;
    // 0042e21b  eb46                   -jmp 0x42e263
    goto L_0x0042e263;
L_0x0042e21d:
    // 0042e21d  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0042e220  7415                   -je 0x42e237
    if (cpu.flags.zf)
    {
        goto L_0x0042e237;
    }
    // 0042e222  81ff000000c0           +cmp edi, 0xc0000000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225472 /*0xc0000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e228  750d                   -jne 0x42e237
    if (!cpu.flags.zf)
    {
        goto L_0x0042e237;
    }
    // 0042e22a  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0042e22e  752e                   -jne 0x42e25e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e25e;
    }
    // 0042e230  68e00e4300             -push 0x430ee0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394720 /*0x430ee0*/;
    cpu.esp -= 4;
    // 0042e235  eb0f                   -jmp 0x42e246
    goto L_0x0042e246;
L_0x0042e237:
    // 0042e237  3bf8                   +cmp edi, eax
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
    // 0042e239  7523                   -jne 0x42e25e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e25e;
    }
    // 0042e23b  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0042e23f  751d                   -jne 0x42e25e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e25e;
    }
    // 0042e241  68d80e4300             -push 0x430ed8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394712 /*0x430ed8*/;
    cpu.esp -= 4;
L_0x0042e246:
    // 0042e246  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042e249  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e24a  e841dfffff             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042e24f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e250  c6430305               -mov byte ptr [ebx + 3], 5
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 5 /*0x5*/;
    // 0042e254  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e255:
    // 0042e255  8365fc00               +and dword ptr [ebp - 4], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0042e259  e96e010000             -jmp 0x42e3cc
    goto L_0x0042e3cc;
L_0x0042e25e:
    // 0042e25e  68d00e4300             -push 0x430ed0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394704 /*0x430ed0*/;
    cpu.esp -= 4;
L_0x0042e263:
    // 0042e263  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042e266  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e267  e824dfffff             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042e26c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e26d  c6430306               -mov byte ptr [ebx + 3], 6
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 6 /*0x6*/;
    // 0042e271  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e272  ebe1                   -jmp 0x42e255
    goto L_0x0042e255;
L_0x0042e274:
    // 0042e274  0fb7c2                 -movzx eax, dx
    cpu.eax = x86::reg32(cpu.dx);
    // 0042e277  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042e279  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042e27b  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0042e27e  69c0104d0000           -imul eax, eax, 0x4d10
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(19728 /*0x4d10*/)));
    // 0042e284  c1ee08                 -shr esi, 8
    cpu.esi >>= 8 /*0x8*/ % 32;
    // 0042e287  668365f000             -and word ptr [ebp - 0x10], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) &= x86::reg16(x86::sreg16(0 /*0x0*/));
    // 0042e28c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042e28e  8d0c4e                 -lea ecx, [esi + ecx*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ecx * 2);
    // 0042e291  668955fa               -mov word ptr [ebp - 6], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.dx;
    // 0042e295  6bc94d                 -imul ecx, ecx, 0x4d
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(77 /*0x4d*/)));
    // 0042e298  897df6                 -mov dword ptr [ebp - 0xa], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */) = cpu.edi;
    // 0042e29b  8db4010cedbcec         -lea esi, [ecx + eax - 0x134312f4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-323162868) /* -0x134312f4 */ + cpu.eax * 1);
    // 0042e2a2  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042e2a5  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0042e2a8  8945f2                 -mov dword ptr [ebp - 0xe], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */) = cpu.eax;
    // 0042e2ab  0fbfc6                 -movsx eax, si
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0042e2ae  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0042e2b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e2b1  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e2b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e2b5  e80b050000             -call 0x42e7c5
    cpu.esp -= 4;
    sub_42e7c5(app, cpu);
    // 0042e2ba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e2bd  66817dfaff3f           +cmp word ptr [ebp - 6], 0x3fff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16383 /*0x3fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e2c3  7210                   -jb 0x42e2d5
    if (cpu.flags.cf)
    {
        goto L_0x0042e2d5;
    }
    // 0042e2c5  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042e2c8  46                     -inc esi
    (cpu.esi)++;
    // 0042e2c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e2ca  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e2cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e2ce  e8d2020000             -call 0x42e5a5
    cpu.esp -= 4;
    sub_42e5a5(app, cpu);
    // 0042e2d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e2d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e2d5:
    // 0042e2d5  f6451801               +test byte ptr [ebp + 0x18], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */) & 1 /*0x1*/));
    // 0042e2d9  668933                 -mov word ptr [ebx], si
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.si;
    // 0042e2dc  7411                   -je 0x42e2ef
    if (cpu.flags.zf)
    {
        goto L_0x0042e2ef;
    }
    // 0042e2de  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042e2e1  0fbfc6                 -movsx eax, si
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0042e2e4  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042e2e6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042e2e8  7f08                   -jg 0x42e2f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042e2f2;
    }
    // 0042e2ea  e9f1feffff             -jmp 0x42e1e0
    goto L_0x0042e1e0;
L_0x0042e2ef:
    // 0042e2ef  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
L_0x0042e2f2:
    // 0042e2f2  83ff15                 +cmp edi, 0x15
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e2f5  7e03                   -jle 0x42e2fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e2fa;
    }
    // 0042e2f7  6a15                   -push 0x15
    app->getMemory<x86::reg32>(cpu.esp-4) = 21 /*0x15*/;
    cpu.esp -= 4;
    // 0042e2f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e2fa:
    // 0042e2fa  0fb775fa               -movzx esi, word ptr [ebp - 6]
    cpu.esi = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */));
    // 0042e2fe  81eefe3f0000           -sub esi, 0x3ffe
    (cpu.esi) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 0042e304  668365fa00             +and word ptr [ebp - 6], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */) &= x86::reg16(x86::sreg16(0 /*0x0*/))));
    // 0042e309  c7451c08000000         -mov dword ptr [ebp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
L_0x0042e310:
    // 0042e310  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e313  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e314  e85df8ffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042e319  ff4d1c                 +dec dword ptr [ebp + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e31c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e31d  75f1                   -jne 0x42e310
    if (!cpu.flags.zf)
    {
        goto L_0x0042e310;
    }
    // 0042e31f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e321  7d17                   -jge 0x42e33a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042e33a;
    }
    // 0042e323  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0042e325  81e6ff000000           +and esi, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0042e32b  7e0d                   -jle 0x42e33a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e33a;
    }
L_0x0042e32d:
    // 0042e32d  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e330  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e331  e86ef8ffff             -call 0x42dba4
    cpu.esp -= 4;
    sub_42dba4(app, cpu);
    // 0042e336  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e337  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e338  75f3                   -jne 0x42e32d
    if (!cpu.flags.zf)
    {
        goto L_0x0042e32d;
    }
L_0x0042e33a:
    // 0042e33a  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0042e33d  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042e340  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042e342  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042e345  7e50                   -jle 0x42e397
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e397;
    }
    // 0042e347  894d14                 -mov dword ptr [ebp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x0042e34a:
    // 0042e34a  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e34d  8d7d08                 -lea edi, [ebp + 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042e350  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042e351  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042e352  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e355  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e356  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042e357  e81af8ffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042e35c  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e35f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e360  e811f8ffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042e365  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042e368  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e369  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e36c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e36d  e8a6f7ffff             -call 0x42db18
    cpu.esp -= 4;
    sub_42db18(app, cpu);
    // 0042e372  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e375  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e376  e8fbf7ffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042e37b  8a45fb                 -mov al, byte ptr [ebp - 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 0042e37e  8b4d1c                 -mov ecx, dword ptr [ebp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0042e381  8065fb00               -and byte ptr [ebp - 5], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042e385  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042e388  0430                   +add al, 0x30
    {
        x86::reg8& tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042e38a  ff451c                 +inc dword ptr [ebp + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e38d  ff4d14                 +dec dword ptr [ebp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e390  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 0042e392  75b6                   -jne 0x42e34a
    if (!cpu.flags.zf)
    {
        goto L_0x0042e34a;
    }
    // 0042e394  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
L_0x0042e397:
    // 0042e397  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0042e39a  48                     -dec eax
    (cpu.eax)--;
    // 0042e39b  48                     -dec eax
    (cpu.eax)--;
    // 0042e39c  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042e39f  8d4b04                 -lea ecx, [ebx + 4]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042e3a2  7c30                   -jl 0x42e3d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042e3d4;
    }
L_0x0042e3a4:
    // 0042e3a4  3bc1                   +cmp eax, ecx
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
    // 0042e3a6  720f                   -jb 0x42e3b7
    if (cpu.flags.cf)
    {
        goto L_0x0042e3b7;
    }
    // 0042e3a8  803839                 +cmp byte ptr [eax], 0x39
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
    // 0042e3ab  7506                   -jne 0x42e3b3
    if (!cpu.flags.zf)
    {
        goto L_0x0042e3b3;
    }
    // 0042e3ad  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 0042e3b0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e3b1  ebf1                   -jmp 0x42e3a4
    goto L_0x0042e3a4;
L_0x0042e3b3:
    // 0042e3b3  3bc1                   +cmp eax, ecx
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
    // 0042e3b5  7304                   -jae 0x42e3bb
    if (!cpu.flags.cf)
    {
        goto L_0x0042e3bb;
    }
L_0x0042e3b7:
    // 0042e3b7  40                     -inc eax
    (cpu.eax)++;
    // 0042e3b8  66ff03                 -inc word ptr [ebx]
    (app->getMemory<x86::reg16>(cpu.ebx))++;
L_0x0042e3bb:
    // 0042e3bb  fe00                   -inc byte ptr [eax]
    (app->getMemory<x86::reg8>(cpu.eax))++;
L_0x0042e3bd:
    // 0042e3bd  2ac3                   -sub al, bl
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.bl));
    // 0042e3bf  2c03                   -sub al, 3
    (cpu.al) -= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 0042e3c1  884303                 -mov byte ptr [ebx + 3], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0042e3c4  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042e3c7  8064180400             -and byte ptr [eax + ebx + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebx * 1) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0042e3cc:
    // 0042e3cc  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0042e3cf:
    // 0042e3cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3d2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e3d4:
    // 0042e3d4  3bc1                   +cmp eax, ecx
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
    // 0042e3d6  720c                   -jb 0x42e3e4
    if (cpu.flags.cf)
    {
        goto L_0x0042e3e4;
    }
    // 0042e3d8  803830                 +cmp byte ptr [eax], 0x30
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
    // 0042e3db  7503                   -jne 0x42e3e0
    if (!cpu.flags.zf)
    {
        goto L_0x0042e3e0;
    }
    // 0042e3dd  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e3de  ebf4                   -jmp 0x42e3d4
    goto L_0x0042e3d4;
L_0x0042e3e0:
    // 0042e3e0  3bc1                   +cmp eax, ecx
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
    // 0042e3e2  73d9                   -jae 0x42e3bd
    if (!cpu.flags.cf)
    {
        goto L_0x0042e3bd;
    }
L_0x0042e3e4:
    // 0042e3e4  66832300               -and word ptr [ebx], 0
    app->getMemory<x86::reg16>(cpu.ebx) &= x86::reg16(x86::sreg16(0 /*0x0*/));
    // 0042e3e8  c6430220               -mov byte ptr [ebx + 2], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32 /*0x20*/;
    // 0042e3ec  c6430301               -mov byte ptr [ebx + 3], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 1 /*0x1*/;
    // 0042e3f0  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
L_0x0042e3f3:
    // 0042e3f3  80630500               +and byte ptr [ebx + 5], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042e3f7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042e3f9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e3fa  ebd3                   -jmp 0x42e3cf
    goto L_0x0042e3cf;
}

/* align: skip  */
void Application::asm_sub_42e400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e400  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e401  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042e403  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e404  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042e407  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e409  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042e40c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0042e40e  41                     -inc ecx
    (cpu.ecx)++;
    // 0042e40f  f7d9                   +neg ecx
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
    // 0042e411  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e412  8a450c                 -mov al, byte ptr [ebp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042e415  fd                     -std 
    cpu.flags.df = 1;
    // 0042e416  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0042e418  47                     -inc edi
    (cpu.edi)++;
    // 0042e419  3807                   +cmp byte ptr [edi], al
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042e41b  7404                   -je 0x42e421
    if (cpu.flags.zf)
    {
        goto L_0x0042e421;
    }
    // 0042e41d  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042e41f  eb02                   -jmp 0x42e423
    goto L_0x0042e423;
L_0x0042e421:
    // 0042e421  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0042e423:
    // 0042e423  fc                     -cld 
    cpu.flags.df = 0;
    // 0042e424  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e425  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e426  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42e427(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e427  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e428  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e429  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e42a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e42b  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x0042e42f:
    // 0042e42f  833d30d8430001         +cmp dword ptr [0x43d830], 1
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
    // 0042e436  7e0f                   -jle 0x42e447
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e447;
    }
    // 0042e438  0fb607                 -movzx eax, byte ptr [edi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0042e43b  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042e43d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e43e  e81ed8ffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042e443  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e444  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e445  eb0f                   -jmp 0x42e456
    goto L_0x0042e456;
L_0x0042e447:
    // 0042e447  0fb607                 -movzx eax, byte ptr [edi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0042e44a  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042e450  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0042e453  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0042e456:
    // 0042e456  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e458  7403                   -je 0x42e45d
    if (cpu.flags.zf)
    {
        goto L_0x0042e45d;
    }
    // 0042e45a  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e45b  ebd2                   -jmp 0x42e42f
    goto L_0x0042e42f;
L_0x0042e45d:
    // 0042e45d  0fb637                 -movzx esi, byte ptr [edi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0042e460  47                     -inc edi
    (cpu.edi)++;
    // 0042e461  83fe2d                 +cmp esi, 0x2d
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
    // 0042e464  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0042e466  7405                   -je 0x42e46d
    if (cpu.flags.zf)
    {
        goto L_0x0042e46d;
    }
    // 0042e468  83fe2b                 +cmp esi, 0x2b
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
    // 0042e46b  7504                   -jne 0x42e471
    if (!cpu.flags.zf)
    {
        goto L_0x0042e471;
    }
L_0x0042e46d:
    // 0042e46d  0fb637                 -movzx esi, byte ptr [edi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0042e470  47                     -inc edi
    (cpu.edi)++;
L_0x0042e471:
    // 0042e471  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042e473:
    // 0042e473  833d30d8430001         +cmp dword ptr [0x43d830], 1
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
    // 0042e47a  7e0c                   -jle 0x42e488
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e488;
    }
    // 0042e47c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042e47e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e47f  e8ddd7ffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042e484  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e485  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e486  eb0b                   -jmp 0x42e493
    goto L_0x0042e493;
L_0x0042e488:
    // 0042e488  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042e48d  8a0470                 -mov al, byte ptr [eax + esi*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.esi * 2);
    // 0042e490  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042e493:
    // 0042e493  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e495  740d                   -je 0x42e4a4
    if (cpu.flags.zf)
    {
        goto L_0x0042e4a4;
    }
    // 0042e497  8d049b                 -lea eax, [ebx + ebx*4]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 4);
    // 0042e49a  8d5c46d0               -lea ebx, [esi + eax*2 - 0x30]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 0042e49e  0fb637                 -movzx esi, byte ptr [edi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0042e4a1  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e4a2  ebcf                   -jmp 0x42e473
    goto L_0x0042e473;
L_0x0042e4a4:
    // 0042e4a4  83fd2d                 +cmp ebp, 0x2d
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
    // 0042e4a7  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042e4a9  7502                   -jne 0x42e4ad
    if (!cpu.flags.zf)
    {
        goto L_0x0042e4ad;
    }
    // 0042e4ab  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0042e4ad:
    // 0042e4ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42e4b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e4b2  833d045e490000         +cmp dword ptr [0x495e04], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4808196) /* 0x495e04 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e4b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e4ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e4bb  8b350c544900           -mov esi, dword ptr [0x49540c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */);
    // 0042e4c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e4c2  7465                   -je 0x42e529
    if (cpu.flags.zf)
    {
        goto L_0x0042e529;
    }
    // 0042e4c4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e4c6  751b                   -jne 0x42e4e3
    if (!cpu.flags.zf)
    {
        goto L_0x0042e4e3;
    }
    // 0042e4c8  393514544900           +cmp dword ptr [0x495414], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805652) /* 0x495414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e4ce  7459                   -je 0x42e529
    if (cpu.flags.zf)
    {
        goto L_0x0042e529;
    }
    // 0042e4d0  e8ab030000             -call 0x42e880
    cpu.esp -= 4;
    sub_42e880(app, cpu);
    // 0042e4d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e4d7  7550                   -jne 0x42e529
    if (!cpu.flags.zf)
    {
        goto L_0x0042e529;
    }
    // 0042e4d9  8b350c544900           -mov esi, dword ptr [0x49540c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */);
    // 0042e4df  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042e4e1  7446                   -je 0x42e529
    if (cpu.flags.zf)
    {
        goto L_0x0042e529;
    }
L_0x0042e4e3:
    // 0042e4e3  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042e4e7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042e4e9  743e                   -je 0x42e529
    if (cpu.flags.zf)
    {
        goto L_0x0042e529;
    }
    // 0042e4eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e4ec  e8df98ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042e4f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e4f2  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0042e4f4:
    // 0042e4f4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e4f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e4f8  742f                   -je 0x42e529
    if (cpu.flags.zf)
    {
        goto L_0x0042e529;
    }
    // 0042e4fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e4fb  e8d098ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042e500  3bc7                   +cmp eax, edi
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
    // 0042e502  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e503  7617                   -jbe 0x42e51c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042e51c;
    }
    // 0042e505  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e507  803c383d               +cmp byte ptr [eax + edi], 0x3d
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
    // 0042e50b  750f                   -jne 0x42e51c
    if (!cpu.flags.zf)
    {
        goto L_0x0042e51c;
    }
    // 0042e50d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e50e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e50f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e510  e82c030000             -call 0x42e841
    cpu.esp -= 4;
    sub_42e841(app, cpu);
    // 0042e515  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e518  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e51a  7405                   -je 0x42e521
    if (cpu.flags.zf)
    {
        goto L_0x0042e521;
    }
L_0x0042e51c:
    // 0042e51c  83c604                 +add esi, 4
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
    // 0042e51f  ebd3                   -jmp 0x42e4f4
    goto L_0x0042e4f4;
L_0x0042e521:
    // 0042e521  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e523  8d443801               -lea eax, [eax + edi + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */ + cpu.edi * 1);
    // 0042e527  eb02                   -jmp 0x42e52b
    goto L_0x0042e52b;
L_0x0042e529:
    // 0042e529  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042e52b:
    // 0042e52b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e52c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e52d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e52e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42e52f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e52f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042e533  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e534  3b05005e4900           +cmp eax, dword ptr [0x495e00]
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
    // 0042e53a  735a                   -jae 0x42e596
    if (!cpu.flags.cf)
    {
        goto L_0x0042e596;
    }
    // 0042e53c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042e53e  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042e541  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0042e544  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 0042e54b  8d54c104               -lea edx, [ecx + eax*8 + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 0042e54f  8a4cc104               -mov cl, byte ptr [ecx + eax*8 + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 0042e553  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0042e556  743e                   -je 0x42e596
    if (cpu.flags.zf)
    {
        goto L_0x0042e596;
    }
    // 0042e558  8ac1                   -mov al, cl
    cpu.al = cpu.cl;
    // 0042e55a  be00800000             -mov esi, 0x8000
    cpu.esi = 32768 /*0x8000*/;
    // 0042e55f  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0042e564  3974240c               +cmp dword ptr [esp + 0xc], esi
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
    // 0042e568  7505                   -jne 0x42e56f
    if (!cpu.flags.zf)
    {
        goto L_0x0042e56f;
    }
    // 0042e56a  80e17f                 +and cl, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(127 /*0x7f*/))));
    // 0042e56d  eb0d                   -jmp 0x42e57c
    goto L_0x0042e57c;
L_0x0042e56f:
    // 0042e56f  817c240c00400000       +cmp dword ptr [esp + 0xc], 0x4000
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
    // 0042e577  7511                   -jne 0x42e58a
    if (!cpu.flags.zf)
    {
        goto L_0x0042e58a;
    }
    // 0042e579  80c980                 -or cl, 0x80
    cpu.cl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0042e57c:
    // 0042e57c  f7d8                   +neg eax
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
    // 0042e57e  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0042e580  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 0042e582  662500c0               -and ax, 0xc000
    cpu.ax &= x86::reg16(x86::sreg16(49152 /*0xc000*/));
    // 0042e586  03c6                   +add eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042e588  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e589  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e58a:
    // 0042e58a  c705e453490016000000   -mov dword ptr [0x4953e4], 0x16
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 22 /*0x16*/;
    // 0042e594  eb0a                   -jmp 0x42e5a0
    goto L_0x0042e5a0;
L_0x0042e596:
    // 0042e596  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
L_0x0042e5a0:
    // 0042e5a0  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042e5a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e5a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42e5a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e5a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e5a6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042e5a8  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0042e5ab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e5ac  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042e5af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e5b0  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042e5b3  668b4b0a               -mov cx, word ptr [ebx + 0xa]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0042e5b7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e5b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e5ba  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0042e5bd  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0042e5c0  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0042e5c3  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0042e5c6  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0042e5ca  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042e5cc  baff7f0000             -mov edx, 0x7fff
    cpu.edx = 32767 /*0x7fff*/;
    // 0042e5d1  33f8                   -xor edi, eax
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e5d3  23c2                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
    // 0042e5d5  23ca                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 0042e5d7  81e700800000           -and edi, 0x8000
    cpu.edi &= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0042e5dd  663dff7f               +cmp ax, 0x7fff
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e5e1  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0042e5e4  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042e5e7  0f83b8010000           -jae 0x42e7a5
    if (!cpu.flags.cf)
    {
        goto L_0x0042e7a5;
    }
    // 0042e5ed  6681f9ff7f             +cmp cx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e5f2  0f83ad010000           -jae 0x42e7a5
    if (!cpu.flags.cf)
    {
        goto L_0x0042e7a5;
    }
    // 0042e5f8  6681fafdbf             +cmp dx, 0xbffd
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(49149 /*0xbffd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e5fd  0f87a2010000           -ja 0x42e7a5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042e7a5;
    }
    // 0042e603  6681fabf3f             +cmp dx, 0x3fbf
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16319 /*0x3fbf*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e608  7704                   -ja 0x42e60e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042e60e;
    }
    // 0042e60a  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042e60c  eb3a                   -jmp 0x42e648
    goto L_0x0042e648;
L_0x0042e60e:
    // 0042e60e  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0042e611  baffffff7f             -mov edx, 0x7fffffff
    cpu.edx = 2147483647 /*0x7fffffff*/;
    // 0042e616  7518                   -jne 0x42e630
    if (!cpu.flags.zf)
    {
        goto L_0x0042e630;
    }
    // 0042e618  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e61b  855608                 -test dword ptr [esi + 8], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) & cpu.edx));
    // 0042e61e  7510                   -jne 0x42e630
    if (!cpu.flags.zf)
    {
        goto L_0x0042e630;
    }
    // 0042e620  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e622  394604                 +cmp dword ptr [esi + 4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e625  750b                   -jne 0x42e632
    if (!cpu.flags.zf)
    {
        goto L_0x0042e632;
    }
    // 0042e627  3906                   +cmp dword ptr [esi], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e629  7507                   -jne 0x42e632
    if (!cpu.flags.zf)
    {
        goto L_0x0042e632;
    }
    // 0042e62b  e96f010000             -jmp 0x42e79f
    goto L_0x0042e79f;
L_0x0042e630:
    // 0042e630  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042e632:
    // 0042e632  663bc8                 +cmp cx, ax
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e635  751e                   -jne 0x42e655
    if (!cpu.flags.zf)
    {
        goto L_0x0042e655;
    }
    // 0042e637  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e63a  855308                 -test dword ptr [ebx + 8], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) & cpu.edx));
    // 0042e63d  7516                   -jne 0x42e655
    if (!cpu.flags.zf)
    {
        goto L_0x0042e655;
    }
    // 0042e63f  394304                 +cmp dword ptr [ebx + 4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e642  7511                   -jne 0x42e655
    if (!cpu.flags.zf)
    {
        goto L_0x0042e655;
    }
    // 0042e644  3903                   +cmp dword ptr [ebx], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e646  750d                   -jne 0x42e655
    if (!cpu.flags.zf)
    {
        goto L_0x0042e655;
    }
L_0x0042e648:
    // 0042e648  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042e64b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042e64e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0042e650  e96b010000             -jmp 0x42e7c0
    goto L_0x0042e7c0;
L_0x0042e655:
    // 0042e655  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0042e658  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0042e65b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0042e65e  c7450c05000000         -mov dword ptr [ebp + 0xc], 5
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 5 /*0x5*/;
L_0x0042e665:
    // 0042e665  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042e668  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042e66a  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 0042e66e  7e49                   -jle 0x42e6b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e6b9;
    }
    // 0042e670  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042e672  8d4b08                 -lea ecx, [ebx + 8]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0042e675  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0042e678  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042e67b  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0042e67e  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x0042e681:
    // 0042e681  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042e684  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042e687  0fb700                 -movzx eax, word ptr [eax]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.eax));
    // 0042e68a  0fb709                 -movzx ecx, word ptr [ecx]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(cpu.ecx));
    // 0042e68d  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042e690  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042e693  83c1fc                 -add ecx, -4
    (cpu.ecx) += x86::reg32(x86::sreg32(-4 /*-0x4*/));
    // 0042e696  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e697  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e698  ff31                   -push dword ptr [ecx]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    // 0042e69a  e858f4ffff             -call 0x42daf7
    cpu.esp -= 4;
    sub_42daf7(app, cpu);
    // 0042e69f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e6a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e6a4  7406                   -je 0x42e6ac
    if (cpu.flags.zf)
    {
        goto L_0x0042e6ac;
    }
    // 0042e6a6  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042e6a9  66ff00                 -inc word ptr [eax]
    (app->getMemory<x86::reg16>(cpu.eax))++;
L_0x0042e6ac:
    // 0042e6ac  8345f802               -add dword ptr [ebp - 8], 2
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042e6b0  836df402               +sub dword ptr [ebp - 0xc], 2
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042e6b4  ff4de8                 +dec dword ptr [ebp - 0x18]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e6b7  75c8                   -jne 0x42e681
    if (!cpu.flags.zf)
    {
        goto L_0x0042e681;
    }
L_0x0042e6b9:
    // 0042e6b9  8345fc02               -add dword ptr [ebp - 4], 2
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042e6bd  ff45f0                 -inc dword ptr [ebp - 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))++;
    // 0042e6c0  ff4d0c                 -dec dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))--;
    // 0042e6c3  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 0042e6c7  7f9c                   -jg 0x42e665
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042e665;
    }
    // 0042e6c9  81450802c00000         -add dword ptr [ebp + 8], 0xc002
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(49154 /*0xc002*/));
    // 0042e6d0  66837d0800             +cmp word ptr [ebp + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e6d5  7e25                   -jle 0x42e6fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e6fc;
    }
L_0x0042e6d7:
    // 0042e6d7  f645e780               +test byte ptr [ebp - 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-25) /* -0x19 */) & 128 /*0x80*/));
    // 0042e6db  7518                   -jne 0x42e6f5
    if (!cpu.flags.zf)
    {
        goto L_0x0042e6f5;
    }
    // 0042e6dd  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0042e6e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e6e1  e890f4ffff             -call 0x42db76
    cpu.esp -= 4;
    sub_42db76(app, cpu);
    // 0042e6e6  814508ffff0000         -add dword ptr [ebp + 8], 0xffff
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042e6ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e6ee  66837d0800             +cmp word ptr [ebp + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e6f3  7fe2                   -jg 0x42e6d7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042e6d7;
    }
L_0x0042e6f5:
    // 0042e6f5  66837d0800             +cmp word ptr [ebp + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e6fa  7f39                   -jg 0x42e735
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042e735;
    }
L_0x0042e6fc:
    // 0042e6fc  814508ffff0000         -add dword ptr [ebp + 8], 0xffff
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042e703  66837d0800             +cmp word ptr [ebp + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e708  7d2b                   -jge 0x42e735
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042e735;
    }
    // 0042e70a  0fbf4508               -movsx eax, word ptr [ebp + 8]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0042e70e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0042e710  014508                 -add dword ptr [ebp + 8], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042e713  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0042e715:
    // 0042e715  f645dc01               +test byte ptr [ebp - 0x24], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */) & 1 /*0x1*/));
    // 0042e719  7403                   -je 0x42e71e
    if (cpu.flags.zf)
    {
        goto L_0x0042e71e;
    }
    // 0042e71b  ff45ec                 +inc dword ptr [ebp - 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042e71e:
    // 0042e71e  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0042e721  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e722  e87df4ffff             -call 0x42dba4
    cpu.esp -= 4;
    sub_42dba4(app, cpu);
    // 0042e727  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042e728  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e729  75ea                   -jne 0x42e715
    if (!cpu.flags.zf)
    {
        goto L_0x0042e715;
    }
    // 0042e72b  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e72f  7404                   -je 0x42e735
    if (cpu.flags.zf)
    {
        goto L_0x0042e735;
    }
    // 0042e731  804ddc01               -or byte ptr [ebp - 0x24], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0042e735:
    // 0042e735  66817ddc0080           +cmp word ptr [ebp - 0x24], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e73b  770f                   -ja 0x42e74c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042e74c;
    }
    // 0042e73d  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0042e740  25ffff0100             -and eax, 0x1ffff
    cpu.eax &= x86::reg32(x86::sreg32(131071 /*0x1ffff*/));
    // 0042e745  3d00800100             +cmp eax, 0x18000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98304 /*0x18000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e74a  7535                   -jne 0x42e781
    if (!cpu.flags.zf)
    {
        goto L_0x0042e781;
    }
L_0x0042e74c:
    // 0042e74c  837ddeff               +cmp dword ptr [ebp - 0x22], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-34) /* -0x22 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e750  752c                   -jne 0x42e77e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e77e;
    }
    // 0042e752  8365de00               -and dword ptr [ebp - 0x22], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-34) /* -0x22 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042e756  837de2ff               +cmp dword ptr [ebp - 0x1e], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-30) /* -0x1e */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e75a  751d                   -jne 0x42e779
    if (!cpu.flags.zf)
    {
        goto L_0x0042e779;
    }
    // 0042e75c  8365e200               -and dword ptr [ebp - 0x1e], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-30) /* -0x1e */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042e760  66817de6ffff           +cmp word ptr [ebp - 0x1a], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e766  750b                   -jne 0x42e773
    if (!cpu.flags.zf)
    {
        goto L_0x0042e773;
    }
    // 0042e768  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e76b  66c745e60080           -mov word ptr [ebp - 0x1a], 0x8000
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */) = 32768 /*0x8000*/;
    // 0042e771  eb0e                   -jmp 0x42e781
    goto L_0x0042e781;
L_0x0042e773:
    // 0042e773  66ff45e6               +inc word ptr [ebp - 0x1a]
    {
        auto tmp = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */);
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 0042e777  eb08                   -jmp 0x42e781
    goto L_0x0042e781;
L_0x0042e779:
    // 0042e779  ff45e2                 +inc dword ptr [ebp - 0x1e]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-30) /* -0x1e */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042e77c  eb03                   -jmp 0x42e781
    goto L_0x0042e781;
L_0x0042e77e:
    // 0042e77e  ff45de                 -inc dword ptr [ebp - 0x22]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-34) /* -0x22 */))++;
L_0x0042e781:
    // 0042e781  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042e784  663dff7f               +cmp ax, 0x7fff
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e788  731b                   -jae 0x42e7a5
    if (!cpu.flags.cf)
    {
        goto L_0x0042e7a5;
    }
    // 0042e78a  668b4dde               -mov cx, word ptr [ebp - 0x22]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-34) /* -0x22 */);
    // 0042e78e  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0042e790  66890e                 -mov word ptr [esi], cx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.cx;
    // 0042e793  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0042e796  894e02                 -mov dword ptr [esi + 2], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.ecx;
    // 0042e799  8b4de4                 -mov ecx, dword ptr [ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042e79c  894e06                 -mov dword ptr [esi + 6], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ecx;
L_0x0042e79f:
    // 0042e79f  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0042e7a3  eb1b                   -jmp 0x42e7c0
    goto L_0x0042e7c0;
L_0x0042e7a5:
    // 0042e7a5  66f7df                 +neg di
    {
        x86::reg16 tmp1 = 0;
        x86::reg16& tmp2 = cpu.di;
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0042e7a8  1bff                   -sbb edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 0042e7aa  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042e7ae  81e700000080           -and edi, 0x80000000
    cpu.edi &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0042e7b4  81c70080ff7f           -add edi, 0x7fff8000
    (cpu.edi) += x86::reg32(x86::sreg32(2147450880 /*0x7fff8000*/));
    // 0042e7ba  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042e7bd  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x0042e7c0:
    // 0042e7c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e7c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e7c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e7c3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e7c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42e7c5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e7c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e7c6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042e7c8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042e7cb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e7cc  bba0da4300             -mov ebx, 0x43daa0
    cpu.ebx = 4446880 /*0x43daa0*/;
    // 0042e7d1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042e7d3  83eb60                 -sub ebx, 0x60
    (cpu.ebx) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0042e7d6  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
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
    // 0042e7d9  7463                   -je 0x42e83e
    if (cpu.flags.zf)
    {
        goto L_0x0042e83e;
    }
    // 0042e7db  7d10                   -jge 0x42e7ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042e7ed;
    }
    // 0042e7dd  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042e7e0  bb00dc4300             -mov ebx, 0x43dc00
    cpu.ebx = 4447232 /*0x43dc00*/;
    // 0042e7e5  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0042e7e7  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042e7ea  83eb60                 -sub ebx, 0x60
    (cpu.ebx) -= x86::reg32(x86::sreg32(96 /*0x60*/));
L_0x0042e7ed:
    // 0042e7ed  394d10                 +cmp dword ptr [ebp + 0x10], ecx
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
    // 0042e7f0  7506                   -jne 0x42e7f8
    if (!cpu.flags.zf)
    {
        goto L_0x0042e7f8;
    }
    // 0042e7f2  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042e7f5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
L_0x0042e7f8:
    // 0042e7f8  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
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
    // 0042e7fb  7441                   -je 0x42e83e
    if (cpu.flags.zf)
    {
        goto L_0x0042e83e;
    }
    // 0042e7fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e7fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042e7ff:
    // 0042e7ff  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042e802  83c354                 -add ebx, 0x54
    (cpu.ebx) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0042e805  c17d0c03               -sar dword ptr [ebp + 0xc], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)) >> (3 /*0x3*/ % 32));
    // 0042e809  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0042e80c  3bc1                   +cmp eax, ecx
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
    // 0042e80e  7427                   -je 0x42e837
    if (cpu.flags.zf)
    {
        goto L_0x0042e837;
    }
    // 0042e810  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0042e813  66813c830080           +cmp word ptr [ebx + eax*4], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 4);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042e819  8d3483                 -lea esi, [ebx + eax*4]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 4);
    // 0042e81c  720c                   -jb 0x42e82a
    if (cpu.flags.cf)
    {
        goto L_0x0042e82a;
    }
    // 0042e81e  8d7df4                 -lea edi, [ebp - 0xc]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042e821  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042e822  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042e823  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042e824  ff4df6                 -dec dword ptr [ebp - 0xa]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */))--;
    // 0042e827  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x0042e82a:
    // 0042e82a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e82b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042e82e  e872fdffff             -call 0x42e5a5
    cpu.esp -= 4;
    sub_42e5a5(app, cpu);
    // 0042e833  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e834  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e835  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0042e837:
    // 0042e837  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
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
    // 0042e83a  75c3                   -jne 0x42e7ff
    if (!cpu.flags.zf)
    {
        goto L_0x0042e7ff;
    }
    // 0042e83c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e83d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042e83e:
    // 0042e83e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e83f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e840  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42e841(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e841  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e842  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042e844  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 0042e848  7504                   -jne 0x42e84e
    if (!cpu.flags.zf)
    {
        goto L_0x0042e84e;
    }
    // 0042e84a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042e84c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e84d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e84e:
    // 0042e84e  ff35cc5a4900           -push dword ptr [0x495acc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */);
    cpu.esp -= 4;
    // 0042e854  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042e857  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042e85a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042e85d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042e860  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042e862  ff35e45c4900           -push dword ptr [0x495ce4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807908) /* 0x495ce4 */);
    cpu.esp -= 4;
    // 0042e868  e881000000             -call 0x42e8ee
    cpu.esp -= 4;
    sub_42e8ee(app, cpu);
    // 0042e86d  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042e870  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e872  7507                   -jne 0x42e87b
    if (!cpu.flags.zf)
    {
        goto L_0x0042e87b;
    }
    // 0042e874  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 0042e879  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e87a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e87b:
    // 0042e87b  83c0fe                 -add eax, -2
    (cpu.eax) += x86::reg32(x86::sreg32(-2 /*-0x2*/));
    // 0042e87e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e87f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42e880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e880  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042e881  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e882  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e883  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e884  8b3514544900           -mov esi, dword ptr [0x495414]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4805652) /* 0x495414 */);
    // 0042e88a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e88b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042e88d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042e88f  3bc7                   +cmp eax, edi
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
    // 0042e891  744e                   -je 0x42e8e1
    if (cpu.flags.zf)
    {
        goto L_0x0042e8e1;
    }
    // 0042e893  8b1d14014300           -mov ebx, dword ptr [0x430114]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4391188) /* 0x430114 */);
L_0x0042e899:
    // 0042e899  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e89a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e89b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e89c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e89d  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042e89f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e8a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e8a1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042e8a3  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042e8a5  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042e8a7  3bef                   +cmp ebp, edi
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
    // 0042e8a9  743e                   -je 0x42e8e9
    if (cpu.flags.zf)
    {
        goto L_0x0042e8e9;
    }
    // 0042e8ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e8ac  e8c465ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042e8b1  3bc7                   +cmp eax, edi
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
    // 0042e8b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e8b4  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042e8b8  742f                   -je 0x42e8e9
    if (cpu.flags.zf)
    {
        goto L_0x0042e8e9;
    }
    // 0042e8ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e8bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e8bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e8bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e8be  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042e8c0  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0042e8c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e8c3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042e8c5  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042e8c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e8c9  741e                   -je 0x42e8e9
    if (cpu.flags.zf)
    {
        goto L_0x0042e8e9;
    }
    // 0042e8cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e8cc  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042e8d0  e896020000             -call 0x42eb6b
    cpu.esp -= 4;
    sub_42eb6b(app, cpu);
    // 0042e8d5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042e8d8  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042e8db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e8dc  3bc7                   +cmp eax, edi
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
    // 0042e8de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e8df  75b8                   -jne 0x42e899
    if (!cpu.flags.zf)
    {
        goto L_0x0042e899;
    }
L_0x0042e8e1:
    // 0042e8e1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042e8e3:
    // 0042e8e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e8e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e8e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e8e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e8e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e8e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042e8e9:
    // 0042e8e9  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042e8ec  ebf5                   -jmp 0x42e8e3
    goto L_0x0042e8e3;
}

/* align: skip  */
void Application::asm_sub_42e8ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042e8ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042e8ef  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042e8f1  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042e8f3  68f00e4300             -push 0x430ef0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394736 /*0x430ef0*/;
    cpu.esp -= 4;
    // 0042e8f8  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 0042e8fd  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0042e903  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e904  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0042e90b  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0042e90e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e90f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e910  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e911  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042e914  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042e916  391db0564900           +cmp dword ptr [0x4956b0], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806320) /* 0x4956b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e91c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042e91e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e91f  7540                   -jne 0x42e961
    if (!cpu.flags.zf)
    {
        goto L_0x0042e961;
    }
    // 0042e921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e922  b8a00e4300             -mov eax, 0x430ea0
    cpu.eax = 4394656 /*0x430ea0*/;
    // 0042e927  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e928  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e929  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e92a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e92b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e92c  ff156c004300           -call dword ptr [0x43006c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391020) /* 0x43006c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042e932  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e934  7408                   -je 0x42e93e
    if (cpu.flags.zf)
    {
        goto L_0x0042e93e;
    }
    // 0042e936  893db0564900           -mov dword ptr [0x4956b0], edi
    app->getMemory<x86::reg32>(x86::reg32(4806320) /* 0x4956b0 */) = cpu.edi;
    // 0042e93c  eb23                   -jmp 0x42e961
    goto L_0x0042e961;
L_0x0042e93e:
    // 0042e93e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e93f  b89c0e4300             -mov eax, 0x430e9c
    cpu.eax = 4394652 /*0x430e9c*/;
    // 0042e944  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e945  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042e946  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e947  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e948  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042e949  ff153c004300           -call dword ptr [0x43003c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390972) /* 0x43003c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042e94f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042e951  0f8400020000           -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042e957  c705b056490002000000   -mov dword ptr [0x4956b0], 2
    app->getMemory<x86::reg32>(x86::reg32(4806320) /* 0x4956b0 */) = 2 /*0x2*/;
L_0x0042e961:
    // 0042e961  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042e964  3bf3                   +cmp esi, ebx
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
    // 0042e966  7e10                   -jle 0x42e978
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e978;
    }
    // 0042e968  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e969  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042e96c  e85bf1ffff             -call 0x42dacc
    cpu.esp -= 4;
    sub_42dacc(app, cpu);
    // 0042e971  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e972  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e973  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042e975  897514                 -mov dword ptr [ebp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.esi;
L_0x0042e978:
    // 0042e978  395d1c                 +cmp dword ptr [ebp + 0x1c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e97b  7e10                   -jle 0x42e98d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e98d;
    }
    // 0042e97d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042e980  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042e983  e844f1ffff             -call 0x42dacc
    cpu.esp -= 4;
    sub_42dacc(app, cpu);
    // 0042e988  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e989  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e98a  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0042e98d:
    // 0042e98d  a1b0564900             -mov eax, dword ptr [0x4956b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806320) /* 0x4956b0 */);
    // 0042e992  83f802                 +cmp eax, 2
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
    // 0042e995  751b                   -jne 0x42e9b2
    if (!cpu.flags.zf)
    {
        goto L_0x0042e9b2;
    }
    // 0042e997  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042e99a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042e99d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042e99e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042e9a1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042e9a4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042e9a7  ff153c004300           -call dword ptr [0x43003c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390972) /* 0x43003c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042e9ad  e9a7010000             -jmp 0x42eb59
    return sub_42eb59(app, cpu);
L_0x0042e9b2:
    // 0042e9b2  3bc7                   +cmp eax, edi
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
    // 0042e9b4  0f859d010000           -jne 0x42eb57
    if (!cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042e9ba  395d20                 +cmp dword ptr [ebp + 0x20], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e9bd  7508                   -jne 0x42e9c7
    if (!cpu.flags.zf)
    {
        goto L_0x0042e9c7;
    }
    // 0042e9bf  a18c564900             -mov eax, dword ptr [0x49568c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    // 0042e9c4  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0042e9c7:
    // 0042e9c7  3bf3                   +cmp esi, ebx
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
    // 0042e9c9  7409                   -je 0x42e9d4
    if (cpu.flags.zf)
    {
        goto L_0x0042e9d4;
    }
    // 0042e9cb  395d1c                 +cmp dword ptr [ebp + 0x1c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042e9ce  0f8598000000           -jne 0x42ea6c
    if (!cpu.flags.zf)
    {
        goto L_0x0042ea6c;
    }
L_0x0042e9d4:
    // 0042e9d4  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0042e9d7  7508                   -jne 0x42e9e1
    if (!cpu.flags.zf)
    {
        goto L_0x0042e9e1;
    }
L_0x0042e9d9:
    // 0042e9d9  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
L_0x0042e9db:
    // 0042e9db  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042e9dc  e978010000             -jmp 0x42eb59
    return sub_42eb59(app, cpu);
L_0x0042e9e1:
    // 0042e9e1  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0042e9e4  7e07                   -jle 0x42e9ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042e9ed;
    }
L_0x0042e9e6:
    // 0042e9e6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042e9e8  e96c010000             -jmp 0x42eb59
    return sub_42eb59(app, cpu);
L_0x0042e9ed:
    // 0042e9ed  3bf7                   +cmp esi, edi
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
    // 0042e9ef  7f41                   -jg 0x42ea32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042ea32;
    }
    // 0042e9f1  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0042e9f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042e9f5  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042e9f8  ff1560004300           -call dword ptr [0x430060]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391008) /* 0x430060 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042e9fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ea00  0f8451010000           -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042ea06  3bf3                   +cmp esi, ebx
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
    // 0042ea08  7e2c                   -jle 0x42ea36
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ea36;
    }
    // 0042ea0a  837dc402               +cmp dword ptr [ebp - 0x3c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ea0e  7222                   -jb 0x42ea32
    if (cpu.flags.cf)
    {
        goto L_0x0042ea32;
    }
    // 0042ea10  8d45ca                 -lea eax, [ebp - 0x36]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-54) /* -0x36 */);
    // 0042ea13  385dca                 +cmp byte ptr [ebp - 0x36], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-54) /* -0x36 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ea16  741a                   -je 0x42ea32
    if (cpu.flags.zf)
    {
        goto L_0x0042ea32;
    }
L_0x0042ea18:
    // 0042ea18  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042ea1b  3ad3                   +cmp dl, bl
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
    // 0042ea1d  7413                   -je 0x42ea32
    if (cpu.flags.zf)
    {
        goto L_0x0042ea32;
    }
    // 0042ea1f  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042ea22  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042ea24  3a08                   +cmp cl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ea26  7204                   -jb 0x42ea2c
    if (cpu.flags.cf)
    {
        goto L_0x0042ea2c;
    }
    // 0042ea28  3aca                   +cmp cl, dl
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
    // 0042ea2a  76ad                   -jbe 0x42e9d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042e9d9;
    }
L_0x0042ea2c:
    // 0042ea2c  40                     -inc eax
    (cpu.eax)++;
    // 0042ea2d  40                     -inc eax
    (cpu.eax)++;
    // 0042ea2e  3818                   +cmp byte ptr [eax], bl
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
    // 0042ea30  75e6                   -jne 0x42ea18
    if (!cpu.flags.zf)
    {
        goto L_0x0042ea18;
    }
L_0x0042ea32:
    // 0042ea32  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042ea34  eba5                   -jmp 0x42e9db
    goto L_0x0042e9db;
L_0x0042ea36:
    // 0042ea36  395d1c                 +cmp dword ptr [ebp + 0x1c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ea39  7e31                   -jle 0x42ea6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ea6c;
    }
    // 0042ea3b  837dc402               +cmp dword ptr [ebp - 0x3c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ea3f  72a5                   -jb 0x42e9e6
    if (cpu.flags.cf)
    {
        goto L_0x0042e9e6;
    }
    // 0042ea41  8d45ca                 -lea eax, [ebp - 0x36]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-54) /* -0x36 */);
    // 0042ea44  385dca                 +cmp byte ptr [ebp - 0x36], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-54) /* -0x36 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ea47  749d                   -je 0x42e9e6
    if (cpu.flags.zf)
    {
        goto L_0x0042e9e6;
    }
L_0x0042ea49:
    // 0042ea49  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042ea4c  3ad3                   +cmp dl, bl
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
    // 0042ea4e  7496                   -je 0x42e9e6
    if (cpu.flags.zf)
    {
        goto L_0x0042e9e6;
    }
    // 0042ea50  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0042ea53  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042ea55  3a08                   +cmp cl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ea57  7208                   -jb 0x42ea61
    if (cpu.flags.cf)
    {
        goto L_0x0042ea61;
    }
    // 0042ea59  3aca                   +cmp cl, dl
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
    // 0042ea5b  0f8678ffffff           -jbe 0x42e9d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042e9d9;
    }
L_0x0042ea61:
    // 0042ea61  40                     -inc eax
    (cpu.eax)++;
    // 0042ea62  40                     -inc eax
    (cpu.eax)++;
    // 0042ea63  3818                   +cmp byte ptr [eax], bl
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
    // 0042ea65  75e2                   -jne 0x42ea49
    if (!cpu.flags.zf)
    {
        goto L_0x0042ea49;
    }
    // 0042ea67  e97affffff             -jmp 0x42e9e6
    goto L_0x0042e9e6;
L_0x0042ea6c:
    // 0042ea6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ea6d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ea6e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ea6f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042ea72  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042ea74  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042ea77  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ea7d  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0042ea80  3bc3                   +cmp eax, ebx
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
    // 0042ea82  0f84cf000000           -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042ea88  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0042ea8b  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042ea8d  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042ea90  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042ea92  e8396cffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042ea97  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042ea9a  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0042ea9c  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0042ea9f  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042eaa3  eb16                   -jmp 0x42eabb
    return sub_42eabb(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42eaa5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eaa5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042eaa7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eaa8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42eaa9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eaa9  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042eaac  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eaae  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 0042eab1  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042eab5  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042eab8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042eaba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eabb  395ddc                 +cmp dword ptr [ebp - 0x24], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042eabe  0f8493000000           -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042eac4  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042eac7  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042eaca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eacb  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042eace  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eacf  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042ead2  8b3570004300           -mov esi, dword ptr [0x430070]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    // 0042ead8  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eada  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042eadc  7479                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042eade  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eadf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eae0  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042eae3  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042eae6  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042eae8  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042eaeb  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eaed  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042eaef  8975e0                 -mov dword ptr [ebp - 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.esi;
    // 0042eaf2  3bf3                   +cmp esi, ebx
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
    // 0042eaf4  7461                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042eaf6  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0042eaf9  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0042eafc  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042eaff  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042eb01  e8ca6bffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042eb06  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042eb09  8bfc                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0042eb0b  897dd8                 -mov dword ptr [ebp - 0x28], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edi;
    // 0042eb0e  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042eb12  eb12                   -jmp 0x42eb26
    return sub_42eb26(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42eabb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042eabb;
    // 0042eaa9  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042eaac  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eaae  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 0042eab1  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042eab5  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042eab8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042eaba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x0042eabb:
    // 0042eabb  395ddc                 +cmp dword ptr [ebp - 0x24], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042eabe  0f8493000000           -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042eac4  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042eac7  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042eaca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eacb  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042eace  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eacf  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042ead2  8b3570004300           -mov esi, dword ptr [0x430070]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    // 0042ead8  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eada  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042eadc  7479                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042eade  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eadf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eae0  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042eae3  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042eae6  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042eae8  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042eaeb  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eaed  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042eaef  8975e0                 -mov dword ptr [ebp - 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.esi;
    // 0042eaf2  3bf3                   +cmp esi, ebx
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
    // 0042eaf4  7461                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        return sub_42eb57(app, cpu);
    }
    // 0042eaf6  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0042eaf9  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0042eafc  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042eaff  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0042eb01  e8ca6bffff             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0042eb06  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042eb09  8bfc                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0042eb0b  897dd8                 -mov dword ptr [ebp - 0x28], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edi;
    // 0042eb0e  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042eb12  eb12                   -jmp 0x42eb26
    return sub_42eb26(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42eb14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eb14  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042eb16  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42eb18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eb18  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042eb1b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eb1d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042eb1f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042eb23  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0042eb26  3bfb                   +cmp edi, ebx
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
    // 0042eb28  742d                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        goto L_0x0042eb57;
    }
    // 0042eb2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb2c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042eb2f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042eb32  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042eb34  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042eb37  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eb3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042eb3f  7416                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        goto L_0x0042eb57;
    }
    // 0042eb41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb43  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042eb46  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042eb49  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042eb4c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042eb4f  ff156c004300           -call dword ptr [0x43006c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391020) /* 0x43006c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eb55  eb02                   -jmp 0x42eb59
    goto L_0x0042eb59;
L_0x0042eb57:
    // 0042eb57  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042eb59:
    // 0042eb59  8d65b4                 -lea esp, [ebp - 0x4c]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0042eb5c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042eb5f  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042eb66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb69  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42eb59(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042eb59;
    // 0042eb18  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042eb1b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eb1d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042eb1f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042eb23  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0042eb26  3bfb                   +cmp edi, ebx
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
    // 0042eb28  742d                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        goto L_0x0042eb57;
    }
    // 0042eb2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb2c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042eb2f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042eb32  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042eb34  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042eb37  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eb3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042eb3f  7416                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        goto L_0x0042eb57;
    }
    // 0042eb41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb43  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042eb46  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042eb49  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042eb4c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042eb4f  ff156c004300           -call dword ptr [0x43006c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391020) /* 0x43006c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eb55  eb02                   -jmp 0x42eb59
    goto L_0x0042eb59;
L_0x0042eb57:
    // 0042eb57  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042eb59:
L_entry_0x0042eb59:
    // 0042eb59  8d65b4                 -lea esp, [ebp - 0x4c]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0042eb5c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042eb5f  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042eb66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb69  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42eb57(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042eb57;
    // 0042eb18  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042eb1b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eb1d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042eb1f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042eb23  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0042eb26  3bfb                   +cmp edi, ebx
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
    // 0042eb28  742d                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        goto L_0x0042eb57;
    }
    // 0042eb2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb2c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042eb2f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042eb32  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042eb34  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042eb37  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eb3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042eb3f  7416                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        goto L_0x0042eb57;
    }
    // 0042eb41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb43  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042eb46  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042eb49  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042eb4c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042eb4f  ff156c004300           -call dword ptr [0x43006c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391020) /* 0x43006c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eb55  eb02                   -jmp 0x42eb59
    goto L_0x0042eb59;
L_0x0042eb57:
L_entry_0x0042eb57:
    // 0042eb57  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042eb59:
    // 0042eb59  8d65b4                 -lea esp, [ebp - 0x4c]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0042eb5c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042eb5f  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042eb66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb69  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42eb26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042eb26;
    // 0042eb18  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042eb1b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eb1d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042eb1f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042eb23  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
L_entry_0x0042eb26:
    // 0042eb26  3bfb                   +cmp edi, ebx
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
    // 0042eb28  742d                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        goto L_0x0042eb57;
    }
    // 0042eb2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb2c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0042eb2f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042eb32  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042eb34  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0042eb37  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eb3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042eb3f  7416                   -je 0x42eb57
    if (cpu.flags.zf)
    {
        goto L_0x0042eb57;
    }
    // 0042eb41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb43  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042eb46  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042eb49  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042eb4c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042eb4f  ff156c004300           -call dword ptr [0x43006c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391020) /* 0x43006c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042eb55  eb02                   -jmp 0x42eb59
    goto L_0x0042eb59;
L_0x0042eb57:
    // 0042eb57  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042eb59:
    // 0042eb59  8d65b4                 -lea esp, [ebp - 0x4c]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0042eb5c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042eb5f  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0042eb66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb69  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42eb6b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eb6b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042eb6c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042eb6e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042eb6f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042eb70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eb71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042eb72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042eb73  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042eb75  397d08                 +cmp dword ptr [ebp + 8], edi
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
    // 0042eb78  7455                   -je 0x42ebcf
    if (cpu.flags.zf)
    {
        goto L_0x0042ebcf;
    }
    // 0042eb7a  6a3d                   -push 0x3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 61 /*0x3d*/;
    cpu.esp -= 4;
    // 0042eb7c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042eb7f  e8dad8ffff             -call 0x42c45e
    cpu.esp -= 4;
    sub_42c45e(app, cpu);
    // 0042eb84  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042eb86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb87  3bf7                   +cmp esi, edi
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
    // 0042eb89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eb8a  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0042eb8d  7440                   -je 0x42ebcf
    if (cpu.flags.zf)
    {
        goto L_0x0042ebcf;
    }
    // 0042eb8f  397508                 +cmp dword ptr [ebp + 8], esi
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
    // 0042eb92  743b                   -je 0x42ebcf
    if (cpu.flags.zf)
    {
        goto L_0x0042ebcf;
    }
    // 0042eb94  a10c544900             -mov eax, dword ptr [0x49540c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */);
    // 0042eb99  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eb9b  385e01                 +cmp byte ptr [esi + 1], bl
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
    // 0042eb9e  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 0042eba1  3b0510544900           +cmp eax, dword ptr [0x495410]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4805648) /* 0x495410 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042eba7  750c                   -jne 0x42ebb5
    if (!cpu.flags.zf)
    {
        goto L_0x0042ebb5;
    }
    // 0042eba9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ebaa  e89b010000             -call 0x42ed4a
    cpu.esp -= 4;
    sub_42ed4a(app, cpu);
    // 0042ebaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ebb0  a30c544900             -mov dword ptr [0x49540c], eax
    app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */) = cpu.eax;
L_0x0042ebb5:
    // 0042ebb5  3bc7                   +cmp eax, edi
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
    // 0042ebb7  7554                   -jne 0x42ec0d
    if (!cpu.flags.zf)
    {
        goto L_0x0042ec0d;
    }
    // 0042ebb9  397d0c                 +cmp dword ptr [ebp + 0xc], edi
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
    // 0042ebbc  7419                   -je 0x42ebd7
    if (cpu.flags.zf)
    {
        goto L_0x0042ebd7;
    }
    // 0042ebbe  393d14544900           +cmp dword ptr [0x495414], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805652) /* 0x495414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ebc4  7411                   -je 0x42ebd7
    if (cpu.flags.zf)
    {
        goto L_0x0042ebd7;
    }
    // 0042ebc6  e8b5fcffff             -call 0x42e880
    cpu.esp -= 4;
    sub_42e880(app, cpu);
    // 0042ebcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ebcd  743e                   -je 0x42ec0d
    if (cpu.flags.zf)
    {
        goto L_0x0042ec0d;
    }
L_0x0042ebcf:
    // 0042ebcf  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042ebd2:
    // 0042ebd2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ebd3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ebd4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ebd5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ebd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ebd7:
    // 0042ebd7  3bdf                   +cmp ebx, edi
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
    // 0042ebd9  0f850c010000           -jne 0x42eceb
    if (!cpu.flags.zf)
    {
        goto L_0x0042eceb;
    }
    // 0042ebdf  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042ebe1  e88f62ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042ebe6  3bc7                   +cmp eax, edi
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
    // 0042ebe8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ebe9  a30c544900             -mov dword ptr [0x49540c], eax
    app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */) = cpu.eax;
    // 0042ebee  74df                   -je 0x42ebcf
    if (cpu.flags.zf)
    {
        goto L_0x0042ebcf;
    }
    // 0042ebf0  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0042ebf2  393d14544900           +cmp dword ptr [0x495414], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805652) /* 0x495414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ebf8  7513                   -jne 0x42ec0d
    if (!cpu.flags.zf)
    {
        goto L_0x0042ec0d;
    }
    // 0042ebfa  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042ebfc  e87462ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042ec01  3bc7                   +cmp eax, edi
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
    // 0042ec03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ec04  a314544900             -mov dword ptr [0x495414], eax
    app->getMemory<x86::reg32>(x86::reg32(4805652) /* 0x495414 */) = cpu.eax;
    // 0042ec09  74c4                   -je 0x42ebcf
    if (cpu.flags.zf)
    {
        goto L_0x0042ebcf;
    }
    // 0042ec0b  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
L_0x0042ec0d:
    // 0042ec0d  2b7508                 -sub esi, dword ptr [ebp + 8]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0042ec10  8b3d0c544900           -mov edi, dword ptr [0x49540c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */);
    // 0042ec16  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0042ec19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ec1a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042ec1d  e8d0000000             -call 0x42ecf2
    cpu.esp -= 4;
    sub_42ecf2(app, cpu);
    // 0042ec22  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042ec24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ec25  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ec27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ec28  7c43                   -jl 0x42ec6d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ec6d;
    }
    // 0042ec2a  833f00                 +cmp dword ptr [edi], 0
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
    // 0042ec2d  743e                   -je 0x42ec6d
    if (cpu.flags.zf)
    {
        goto L_0x0042ec6d;
    }
    // 0042ec2f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042ec31  7432                   -je 0x42ec65
    if (cpu.flags.zf)
    {
        goto L_0x0042ec65;
    }
    // 0042ec33  ff34b7                 -push dword ptr [edi + esi*4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    cpu.esp -= 4;
    // 0042ec36  8d3cb7                 -lea edi, [edi + esi*4]
    cpu.edi = x86::reg32(cpu.edi + cpu.esi * 4);
    // 0042ec39  e80862ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0042ec3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ec3f:
    // 0042ec3f  833f00                 +cmp dword ptr [edi], 0
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
    // 0042ec42  740b                   -je 0x42ec4f
    if (cpu.flags.zf)
    {
        goto L_0x0042ec4f;
    }
    // 0042ec44  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042ec47  46                     -inc esi
    (cpu.esi)++;
    // 0042ec48  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0042ec4a  83c704                 +add edi, 4
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
    // 0042ec4d  ebf0                   -jmp 0x42ec3f
    goto L_0x0042ec3f;
L_0x0042ec4f:
    // 0042ec4f  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ec51  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0042ec54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ec55  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0042ec58  e86b79ffff             -call 0x4265c8
    cpu.esp -= 4;
    sub_4265c8(app, cpu);
    // 0042ec5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ec5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ec60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ec61  743c                   -je 0x42ec9f
    if (cpu.flags.zf)
    {
        goto L_0x0042ec9f;
    }
    // 0042ec63  eb35                   -jmp 0x42ec9a
    goto L_0x0042ec9a;
L_0x0042ec65:
    // 0042ec65  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042ec68  8904b7                 -mov dword ptr [edi + esi*4], eax
    app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4) = cpu.eax;
    // 0042ec6b  eb32                   -jmp 0x42ec9f
    goto L_0x0042ec9f;
L_0x0042ec6d:
    // 0042ec6d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042ec6f  757a                   -jne 0x42eceb
    if (!cpu.flags.zf)
    {
        goto L_0x0042eceb;
    }
    // 0042ec71  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ec73  7d02                   -jge 0x42ec77
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042ec77;
    }
    // 0042ec75  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x0042ec77:
    // 0042ec77  8d04b508000000         -lea eax, [esi*4 + 8]
    cpu.eax = x86::reg32(x86::reg32(8) /* 0x8 */ + cpu.esi * 4);
    // 0042ec7e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ec7f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ec80  e84379ffff             -call 0x4265c8
    cpu.esp -= 4;
    sub_4265c8(app, cpu);
    // 0042ec85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ec86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ec88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ec89  0f8440ffffff           -je 0x42ebcf
    if (cpu.flags.zf)
    {
        goto L_0x0042ebcf;
    }
    // 0042ec8f  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042ec92  890cb0                 -mov dword ptr [eax + esi*4], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4) = cpu.ecx;
    // 0042ec95  8364b00400             -and dword ptr [eax + esi*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042ec9a:
    // 0042ec9a  a30c544900             -mov dword ptr [0x49540c], eax
    app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */) = cpu.eax;
L_0x0042ec9f:
    // 0042ec9f  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 0042eca3  7446                   -je 0x42eceb
    if (cpu.flags.zf)
    {
        goto L_0x0042eceb;
    }
    // 0042eca5  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042eca8  e82391ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042ecad  40                     -inc eax
    (cpu.eax)++;
    // 0042ecae  40                     -inc eax
    (cpu.eax)++;
    // 0042ecaf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ecb0  e8c061ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042ecb5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042ecb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ecb8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ecba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ecbb  742e                   -je 0x42eceb
    if (cpu.flags.zf)
    {
        goto L_0x0042eceb;
    }
    // 0042ecbd  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042ecc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ecc1  e8cad4ffff             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042ecc6  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ecc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ecc9  2b4508                 -sub eax, dword ptr [ebp + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0042eccc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eccd  0345f8                 -add eax, dword ptr [ebp - 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0042ecd0  802000                 -and byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042ecd3  40                     -inc eax
    (cpu.eax)++;
    // 0042ecd4  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0042ecd6  1bdb                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 0042ecd8  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0042ecda  23d8                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0042ecdc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ecdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ecde  ff1568004300           -call dword ptr [0x430068]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391016) /* 0x430068 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ece4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ece5  e85c61ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0042ecea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042eceb:
    // 0042eceb  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042eced  e9e0feffff             -jmp 0x42ebd2
    goto L_0x0042ebd2;
}

/* align: skip  */
void Application::asm_sub_42ecf2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ecf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ecf3  8b350c544900           -mov esi, dword ptr [0x49540c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */);
    // 0042ecf9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ecfa  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ecfc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ecfe  742d                   -je 0x42ed2d
    if (cpu.flags.zf)
    {
        goto L_0x0042ed2d;
    }
    // 0042ed00  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0042ed04:
    // 0042ed04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ed05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ed06  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042ed0a  e832fbffff             -call 0x42e841
    cpu.esp -= 4;
    sub_42e841(app, cpu);
    // 0042ed0f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042ed12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ed14  750d                   -jne 0x42ed23
    if (!cpu.flags.zf)
    {
        goto L_0x0042ed23;
    }
    // 0042ed16  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ed18  8a0438                 -mov al, byte ptr [eax + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.edi * 1);
    // 0042ed1b  3c3d                   +cmp al, 0x3d
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
    // 0042ed1d  741e                   -je 0x42ed3d
    if (cpu.flags.zf)
    {
        goto L_0x0042ed3d;
    }
    // 0042ed1f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042ed21  741a                   -je 0x42ed3d
    if (cpu.flags.zf)
    {
        goto L_0x0042ed3d;
    }
L_0x0042ed23:
    // 0042ed23  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042ed26  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ed29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ed2b  75d7                   -jne 0x42ed04
    if (!cpu.flags.zf)
    {
        goto L_0x0042ed04;
    }
L_0x0042ed2d:
    // 0042ed2d  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ed2f  2b050c544900           -sub eax, dword ptr [0x49540c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */)));
    // 0042ed35  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0042ed38  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0042ed3a:
    // 0042ed3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ed3d:
    // 0042ed3d  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ed3f  2b050c544900           -sub eax, dword ptr [0x49540c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */)));
    // 0042ed45  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0042ed48  ebf0                   -jmp 0x42ed3a
    goto L_0x0042ed3a;
}

/* align: skip  */
void Application::asm_sub_42ed4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ed4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ed4b  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042ed4f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042ed51  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042ed53  7504                   -jne 0x42ed59
    if (!cpu.flags.zf)
    {
        goto L_0x0042ed59;
    }
    // 0042ed55  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042ed57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ed59:
    // 0042ed59  833f00                 +cmp dword ptr [edi], 0
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
    // 0042ed5c  8d4704                 -lea eax, [edi + 4]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042ed5f  740a                   -je 0x42ed6b
    if (cpu.flags.zf)
    {
        goto L_0x0042ed6b;
    }
L_0x0042ed61:
    // 0042ed61  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042ed63  41                     -inc ecx
    (cpu.ecx)++;
    // 0042ed64  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ed67  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042ed69  75f6                   -jne 0x42ed61
    if (!cpu.flags.zf)
    {
        goto L_0x0042ed61;
    }
L_0x0042ed6b:
    // 0042ed6b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ed6c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ed6d  8d048d04000000         -lea eax, [ecx*4 + 4]
    cpu.eax = x86::reg32(x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 0042ed74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ed75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ed76  e8fa60ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042ed7b  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042ed7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ed7e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ed80  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0042ed82  7508                   -jne 0x42ed8c
    if (!cpu.flags.zf)
    {
        goto L_0x0042ed8c;
    }
    // 0042ed84  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042ed86  e8337bffff             -call 0x4268be
    cpu.esp -= 4;
    sub_4268be(app, cpu);
    // 0042ed8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ed8c:
    // 0042ed8c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042ed8e  8bdf                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0042ed90:
    // 0042ed90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ed92  7413                   -je 0x42eda7
    if (cpu.flags.zf)
    {
        goto L_0x0042eda7;
    }
    // 0042ed94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ed95  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ed98  e814000000             -call 0x42edb1
    cpu.esp -= 4;
    sub_42edb1(app, cpu);
    // 0042ed9d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0042ed9f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042eda1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eda2  83c604                 +add esi, 4
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
    // 0042eda5  ebe9                   -jmp 0x42ed90
    goto L_0x0042ed90;
L_0x0042eda7:
    // 0042eda7  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042edaa  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0042edac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edaf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42edb1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042edb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042edb2  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042edb6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042edb8  741e                   -je 0x42edd8
    if (cpu.flags.zf)
    {
        goto L_0x0042edd8;
    }
    // 0042edba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042edbb  e81090ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042edc0  40                     -inc eax
    (cpu.eax)++;
    // 0042edc1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042edc2  e8ae60ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042edc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042edca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edcb  740b                   -je 0x42edd8
    if (cpu.flags.zf)
    {
        goto L_0x0042edd8;
    }
    // 0042edcd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042edce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042edcf  e8bcd3ffff             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042edd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edd5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edd6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042edd7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042edd8:
    // 0042edd8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042edda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042eddb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ede0  ff258c004300           -jmp dword ptr [0x43008c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4391052), cpu);
}

/* align: skip  */
void Application::asm_sub_42edf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042edf0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042edf1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042edf3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042edf4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042edf5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042edf6  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042edf9  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042edfc  8d0574564900           -lea eax, [0x495674]
    cpu.eax = x86::reg32(x86::reg32(4806260) /* 0x495674 */);
    // 0042ee02  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0042ee06  753b                   -jne 0x42ee43
    if (!cpu.flags.zf)
    {
        goto L_0x0042ee43;
    }
    // 0042ee08  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0042ee0a  8bff                   -mov edi, edi
    cpu.edi = cpu.edi;
L_0x0042ee0c:
    // 0042ee0c  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0042ee0e  742e                   -je 0x42ee3e
    if (cpu.flags.zf)
    {
        goto L_0x0042ee3e;
    }
    // 0042ee10  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042ee12  46                     -inc esi
    (cpu.esi)++;
    // 0042ee13  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 0042ee15  47                     -inc edi
    (cpu.edi)++;
    // 0042ee16  38c4                   +cmp ah, al
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
    // 0042ee18  74f2                   -je 0x42ee0c
    if (cpu.flags.zf)
    {
        goto L_0x0042ee0c;
    }
    // 0042ee1a  2c41                   -sub al, 0x41
    (cpu.al) -= x86::reg8(x86::sreg8(65 /*0x41*/));
    // 0042ee1c  3c1a                   +cmp al, 0x1a
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
    // 0042ee1e  1ac9                   -sbb cl, cl
    (cpu.cl) -= x86::reg8(x86::sreg8(cpu.cl) + cpu.flags.cf);
    // 0042ee20  80e120                 -and cl, 0x20
    cpu.cl &= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0042ee23  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 0042ee25  0441                   -add al, 0x41
    (cpu.al) += x86::reg8(x86::sreg8(65 /*0x41*/));
    // 0042ee27  86e0                   -xchg al, ah
    {
        x86::reg8 tmp = cpu.al;
        cpu.al = cpu.ah;
        cpu.ah = tmp;
    }
    // 0042ee29  2c41                   -sub al, 0x41
    (cpu.al) -= x86::reg8(x86::sreg8(65 /*0x41*/));
    // 0042ee2b  3c1a                   +cmp al, 0x1a
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
    // 0042ee2d  1ac9                   -sbb cl, cl
    (cpu.cl) -= x86::reg8(x86::sreg8(cpu.cl) + cpu.flags.cf);
    // 0042ee2f  80e120                 -and cl, 0x20
    cpu.cl &= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0042ee32  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 0042ee34  0441                   -add al, 0x41
    (cpu.al) += x86::reg8(x86::sreg8(65 /*0x41*/));
    // 0042ee36  38e0                   +cmp al, ah
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
    // 0042ee38  74d2                   -je 0x42ee0c
    if (cpu.flags.zf)
    {
        goto L_0x0042ee0c;
    }
    // 0042ee3a  1ac0                   +sbb al, al
    {
        x86::reg8& tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042ee3c  1cff                   +sbb al, 0xff
    {
        x86::reg8& tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0042ee3e:
    // 0042ee3e  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042ee41  eb34                   -jmp 0x42ee77
    goto L_0x0042ee77;
L_0x0042ee43:
    // 0042ee43  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0042ee48  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042ee4a  8bff                   -mov edi, edi
    cpu.edi = cpu.edi;
L_0x0042ee4c:
    // 0042ee4c  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0042ee4e  7427                   -je 0x42ee77
    if (cpu.flags.zf)
    {
        goto L_0x0042ee77;
    }
    // 0042ee50  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042ee52  46                     -inc esi
    (cpu.esi)++;
    // 0042ee53  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042ee55  47                     -inc edi
    (cpu.edi)++;
    // 0042ee56  38d8                   +cmp al, bl
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
    // 0042ee58  74f2                   -je 0x42ee4c
    if (cpu.flags.zf)
    {
        goto L_0x0042ee4c;
    }
    // 0042ee5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ee5b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ee5c  e875ceffff             -call 0x42bcd6
    cpu.esp -= 4;
    sub_42bcd6(app, cpu);
    // 0042ee61  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042ee63  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ee66  e86bceffff             -call 0x42bcd6
    cpu.esp -= 4;
    sub_42bcd6(app, cpu);
    // 0042ee6b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ee6e  38c3                   +cmp bl, al
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ee70  74da                   -je 0x42ee4c
    if (cpu.flags.zf)
    {
        goto L_0x0042ee4c;
    }
    // 0042ee72  1bc0                   +sbb eax, eax
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
    // 0042ee74  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0042ee77:
    // 0042ee77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ee78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ee79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ee7a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ee7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ee80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ee80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ee81  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042ee83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ee84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ee85  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ee86  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042ee89  0bc9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0042ee8b  0f8495000000           -je 0x42ef26
    if (cpu.flags.zf)
    {
        goto L_0x0042ef26;
    }
    // 0042ee91  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042ee94  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042ee97  8d0574564900           -lea eax, [0x495674]
    cpu.eax = x86::reg32(x86::reg32(4806260) /* 0x495674 */);
    // 0042ee9d  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0042eea1  7543                   -jne 0x42eee6
    if (!cpu.flags.zf)
    {
        goto L_0x0042eee6;
    }
    // 0042eea3  b741                   -mov bh, 0x41
    cpu.bh = 65 /*0x41*/;
    // 0042eea5  b35a                   -mov bl, 0x5a
    cpu.bl = 90 /*0x5a*/;
    // 0042eea7  b620                   -mov dh, 0x20
    cpu.dh = 32 /*0x20*/;
    // 0042eea9  8d4900                 -lea ecx, [ecx]
    cpu.ecx = x86::reg32(cpu.ecx);
L_0x0042eeac:
    // 0042eeac  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 0042eeae  0ae4                   +or ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(cpu.ah))));
    // 0042eeb0  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0042eeb2  7421                   -je 0x42eed5
    if (cpu.flags.zf)
    {
        goto L_0x0042eed5;
    }
    // 0042eeb4  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0042eeb6  741d                   -je 0x42eed5
    if (cpu.flags.zf)
    {
        goto L_0x0042eed5;
    }
    // 0042eeb8  46                     -inc esi
    (cpu.esi)++;
    // 0042eeb9  47                     -inc edi
    (cpu.edi)++;
    // 0042eeba  38fc                   +cmp ah, bh
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
    // 0042eebc  7206                   -jb 0x42eec4
    if (cpu.flags.cf)
    {
        goto L_0x0042eec4;
    }
    // 0042eebe  38dc                   +cmp ah, bl
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
    // 0042eec0  7702                   -ja 0x42eec4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042eec4;
    }
    // 0042eec2  02e6                   -add ah, dh
    (cpu.ah) += x86::reg8(x86::sreg8(cpu.dh));
L_0x0042eec4:
    // 0042eec4  38f8                   +cmp al, bh
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
    // 0042eec6  7206                   -jb 0x42eece
    if (cpu.flags.cf)
    {
        goto L_0x0042eece;
    }
    // 0042eec8  38d8                   +cmp al, bl
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
    // 0042eeca  7702                   -ja 0x42eece
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042eece;
    }
    // 0042eecc  02c6                   -add al, dh
    (cpu.al) += x86::reg8(x86::sreg8(cpu.dh));
L_0x0042eece:
    // 0042eece  38c4                   +cmp ah, al
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
    // 0042eed0  7509                   -jne 0x42eedb
    if (!cpu.flags.zf)
    {
        goto L_0x0042eedb;
    }
    // 0042eed2  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042eed3  75d7                   -jne 0x42eeac
    if (!cpu.flags.zf)
    {
        goto L_0x0042eeac;
    }
L_0x0042eed5:
    // 0042eed5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042eed7  38c4                   +cmp ah, al
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
    // 0042eed9  744b                   -je 0x42ef26
    if (cpu.flags.zf)
    {
        goto L_0x0042ef26;
    }
L_0x0042eedb:
    // 0042eedb  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0042eee0  7244                   -jb 0x42ef26
    if (cpu.flags.cf)
    {
        goto L_0x0042ef26;
    }
    // 0042eee2  f7d9                   +neg ecx
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
    // 0042eee4  eb40                   -jmp 0x42ef26
    goto L_0x0042ef26;
L_0x0042eee6:
    // 0042eee6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042eee8  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042eeea  8bff                   -mov edi, edi
    cpu.edi = cpu.edi;
L_0x0042eeec:
    // 0042eeec  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042eeee  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042eef0  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042eef2  7423                   -je 0x42ef17
    if (cpu.flags.zf)
    {
        goto L_0x0042ef17;
    }
    // 0042eef4  0bdb                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0042eef6  741f                   -je 0x42ef17
    if (cpu.flags.zf)
    {
        goto L_0x0042ef17;
    }
    // 0042eef8  46                     -inc esi
    (cpu.esi)++;
    // 0042eef9  47                     -inc edi
    (cpu.edi)++;
    // 0042eefa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042eefb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042eefc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042eefd  e8d4cdffff             -call 0x42bcd6
    cpu.esp -= 4;
    sub_42bcd6(app, cpu);
    // 0042ef02  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042ef04  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ef07  e8cacdffff             -call 0x42bcd6
    cpu.esp -= 4;
    sub_42bcd6(app, cpu);
    // 0042ef0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ef0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef10  3bc3                   +cmp eax, ebx
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
    // 0042ef12  7509                   -jne 0x42ef1d
    if (!cpu.flags.zf)
    {
        goto L_0x0042ef1d;
    }
    // 0042ef14  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042ef15  75d5                   -jne 0x42eeec
    if (!cpu.flags.zf)
    {
        goto L_0x0042eeec;
    }
L_0x0042ef17:
    // 0042ef17  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042ef19  3bc3                   +cmp eax, ebx
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
    // 0042ef1b  7409                   -je 0x42ef26
    if (cpu.flags.zf)
    {
        goto L_0x0042ef26;
    }
L_0x0042ef1d:
    // 0042ef1d  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0042ef22  7202                   -jb 0x42ef26
    if (cpu.flags.cf)
    {
        goto L_0x0042ef26;
    }
    // 0042ef24  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x0042ef26:
    // 0042ef26  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042ef28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef2b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ef2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ef30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef30  8d4de0                 -lea ecx, [ebp - 0x20]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0042ef33  e9184afdff             -jmp 0x403950
    return sub_403950(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42ef38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef38  b8080f4300             -mov eax, 0x430f08
    cpu.eax = 4394760 /*0x430f08*/;
    // 0042ef3d  e94e68ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42ef50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef50  8d4de0                 -lea ecx, [ebp - 0x20]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0042ef53  e9f849fdff             -jmp 0x403950
    return sub_403950(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42ef58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef58  b8300f4300             -mov eax, 0x430f30
    cpu.eax = 4394800 /*0x430f30*/;
    // 0042ef5d  e92e68ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42ef70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef70  8d8d44ffffff           -lea ecx, [ebp - 0xbc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-188) /* -0xbc */);
    // 0042ef76  e99543fdff             -jmp 0x403310
    return sub_403310(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42ef7b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef7b  b8580f4300             -mov eax, 0x430f58
    cpu.eax = 4394840 /*0x430f58*/;
    // 0042ef80  e90b68ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42ef90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef90  8d4dec                 -lea ecx, [ebp - 0x14]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0042ef93  e94857fdff             -jmp 0x4046e0
    return sub_4046e0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42ef98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ef98  b8800f4300             -mov eax, 0x430f80
    cpu.eax = 4394880 /*0x430f80*/;
    // 0042ef9d  e9ee67ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42efb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042efb0  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0042efb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042efb4  e8926bffff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042efb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042efba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42efbb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042efbb  b8a80f4300             -mov eax, 0x430fa8
    cpu.eax = 4394920 /*0x430fa8*/;
    // 0042efc0  e9cb67ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42efd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042efd0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042efd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042efd4  e8726bffff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042efd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042efda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42efdb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042efdb  b8d00f4300             -mov eax, 0x430fd0
    cpu.eax = 4394960 /*0x430fd0*/;
    // 0042efe0  e9ab67ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42eff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042eff0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042eff3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042eff4  e8526bffff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042eff9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042effa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42effb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042effb  b8f80f4300             -mov eax, 0x430ff8
    cpu.eax = 4395000 /*0x430ff8*/;
    // 0042f000  e98b67ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f010  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f013  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f014  e8326bffff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042f019  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f01a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42f01b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f01b  b820104300             -mov eax, 0x431020
    cpu.eax = 4395040 /*0x431020*/;
    // 0042f020  e96b67ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f030  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f033  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f034  e8126bffff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042f039  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f03a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42f03b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f03b  b848104300             -mov eax, 0x431048
    cpu.eax = 4395080 /*0x431048*/;
    // 0042f040  e94b67ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f050  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f053  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f054  e8f26affff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042f059  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f05a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42f05b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f05b  b870104300             -mov eax, 0x431070
    cpu.eax = 4395120 /*0x431070*/;
    // 0042f060  e92b67ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f070  8b8554ffffff           -mov eax, dword ptr [ebp - 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-172) /* -0xac */);
    // 0042f076  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f077  e8cf6affff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042f07c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f07d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42f07e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f07e  b898104300             -mov eax, 0x431098
    cpu.eax = 4395160 /*0x431098*/;
    // 0042f083  e90867ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f090  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f093  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f094  e8b26affff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042f099  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f09a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42f09b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f09b  b8c0104300             -mov eax, 0x4310c0
    cpu.eax = 4395200 /*0x4310c0*/;
    // 0042f0a0  e9eb66ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0b0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f0b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f0b4  e8926affff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042f0b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f0ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42f0bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0bb  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f0be  e93d89fdff             -jmp 0x407a00
    return sub_407a00(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f0c3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0c3  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f0c6  e93589fdff             -jmp 0x407a00
    return sub_407a00(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f0cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0cb  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f0ce  81c104010000           +add ecx, 0x104
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042f0d4  e9d7c3feff             -jmp 0x41b4b0
    return sub_41b4b0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f0d9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0d9  b8e8104300             -mov eax, 0x4310e8
    cpu.eax = 4395240 /*0x4310e8*/;
    // 0042f0de  e9ad66ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0f0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f0f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f0f4  e8526affff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042f0f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f0fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42f0fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f0fb  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f0fe  e9fd88fdff             -jmp 0x407a00
    return sub_407a00(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f103(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f103  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f106  e9f588fdff             -jmp 0x407a00
    return sub_407a00(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f10b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f10b  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f10e  81c1f8000000           +add ecx, 0xf8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(248 /*0xf8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042f114  e997c3feff             -jmp 0x41b4b0
    return sub_41b4b0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f119(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f119  b828114300             -mov eax, 0x431128
    cpu.eax = 4395304 /*0x431128*/;
    // 0042f11e  e96d66ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f130  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f133  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042f134  e8126affff             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 0042f139  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042f13a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42f13b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f13b  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042f13e  e9cd41fdff             -jmp 0x403310
    return sub_403310(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f143(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f143  b868114300             -mov eax, 0x431168
    cpu.eax = 4395368 /*0x431168*/;
    // 0042f148  e94366ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f150  8d4d84                 -lea ecx, [ebp - 0x7c]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 0042f153  e9c8c3feff             -jmp 0x41b520
    return sub_41b520(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f158(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f158  b898114300             -mov eax, 0x431198
    cpu.eax = 4395416 /*0x431198*/;
    // 0042f15d  e92e66ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f170  8d8d70ffffff           -lea ecx, [ebp - 0x90]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-144) /* -0x90 */);
    // 0042f176  e9a5c3feff             -jmp 0x41b520
    return sub_41b520(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f17b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f17b  b8c0114300             -mov eax, 0x4311c0
    cpu.eax = 4395456 /*0x4311c0*/;
    // 0042f180  e90b66ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f190  8d8d70ffffff           -lea ecx, [ebp - 0x90]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-144) /* -0x90 */);
    // 0042f196  e985c3feff             -jmp 0x41b520
    return sub_41b520(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f19b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f19b  b8e8114300             -mov eax, 0x4311e8
    cpu.eax = 4395496 /*0x4311e8*/;
    // 0042f1a0  e9eb65ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f1b0  8d8d70ffffff           -lea ecx, [ebp - 0x90]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-144) /* -0x90 */);
    // 0042f1b6  e965c3feff             -jmp 0x41b520
    return sub_41b520(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f1bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f1bb  b810124300             -mov eax, 0x431210
    cpu.eax = 4395536 /*0x431210*/;
    // 0042f1c0  e9cb65ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f1d0  8b4d84                 -mov ecx, dword ptr [ebp - 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 0042f1d3  e9a8e3feff             -jmp 0x41d580
    return sub_41d580(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f1d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f1d8  b838124300             -mov eax, 0x431238
    cpu.eax = 4395576 /*0x431238*/;
    // 0042f1dd  e9ae65ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f1f0  8b4d84                 -mov ecx, dword ptr [ebp - 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 0042f1f3  e91841fdff             -jmp 0x403310
    return sub_403310(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f1f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f1f8  b860124300             -mov eax, 0x431260
    cpu.eax = 4395616 /*0x431260*/;
    // 0042f1fd  e98e65ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

}
