#include "menu.h"
namespace menu
{

/* align: skip  */
void Application::asm_sub_425d88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425d88  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 00425d8c  7511                   -jne 0x425d9f
    if (!cpu.flags.zf)
    {
        goto L_0x00425d9f;
    }
    // 00425d8e  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00425d91  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00425d94  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00425d97  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00425d9a  e801000000             -call 0x425da0
    cpu.esp -= 4;
    sub_425da0(app, cpu);
L_0x00425d9f:
    // 00425d9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_425da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425da0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425da1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00425da3  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00425da5  6890064300             -push 0x430690
    app->getMemory<x86::reg32>(cpu.esp-4) = 4392592 /*0x430690*/;
    cpu.esp -= 4;
    // 00425daa  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 00425daf  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00425db5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425db6  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00425dbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425dbe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425dbf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425dc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425dc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425dc2  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00425dc5  8365fc00               +and dword ptr [ebp - 4], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
L_0x00425dc9:
    // 00425dc9  ff4d10                 +dec dword ptr [ebp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00425dcc  781b                   -js 0x425de9
    if (cpu.flags.sf)
    {
        return sub_425de9(app, cpu);
    }
    // 00425dce  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00425dd1  2b4d0c                 +sub ecx, dword ptr [ebp + 0xc]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00425dd4  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00425dd7  ff5514                 -call dword ptr [ebp + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00425dda  ebed                   -jmp 0x425dc9
    goto L_0x00425dc9;
}

/* align: skip  */
void Application::asm_sub_425ddc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425ddc  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 00425ddf  e81a000000             -call 0x425dfe
    cpu.esp -= 4;
    sub_425dfe(app, cpu);
    // 00425de4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425de5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_425de6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425de6  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00425de9  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00425ded  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00425df0  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00425df7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425df8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425df9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425dfa  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425dfb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_425de9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00425de9;
    // 00425de6  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
L_entry_0x00425de9:
    // 00425de9  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00425ded  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00425df0  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00425df7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425df8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425df9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425dfa  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425dfb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_425dfe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425dfe  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00425e02  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00425e04  813863736de0           +cmp dword ptr [eax], 0xe06d7363
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
    // 00425e0a  7403                   -je 0x425e0f
    if (cpu.flags.zf)
    {
        goto L_0x00425e0f;
    }
    // 00425e0c  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00425e0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425e0f:
    // 00425e0f  e918360000             -jmp 0x42942c
    return sub_42942c(app, cpu);
}

/* align: skip  */
void Application::asm_sub_425e14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425e14  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00425e18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425e1a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425e1b  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00425e1f  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00425e23  e85d3c0000             -call 0x429a85
    cpu.esp -= 4;
    sub_429a85(app, cpu);
    // 00425e28  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00425e2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_425e2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425e2c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425e2d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00425e2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425e30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425e31  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00425e34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425e35  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425e36  ff1590004300           -call dword ptr [0x430090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391056) /* 0x430090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00425e3c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425e3e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425e40  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425e42  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00425e45  e8463e0000             -call 0x429c90
    cpu.esp -= 4;
    sub_429c90(app, cpu);
    // 00425e4a  2b05c8534900           +sub eax, dword ptr [0x4953c8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4805576) /* 0x4953c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00425e50  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00425e53  1b15cc534900           -sbb edx, dword ptr [0x4953cc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4805580) /* 0x4953cc */)) + cpu.flags.cf);
    // 00425e59  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00425e5b  03c1                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00425e5d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425e5e  13d7                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 00425e60  6810270000             -push 0x2710
    app->getMemory<x86::reg32>(cpu.esp-4) = 10000 /*0x2710*/;
    cpu.esp -= 4;
    // 00425e65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425e66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425e67  e8b43d0000             -call 0x429c20
    cpu.esp -= 4;
    sub_429c20(app, cpu);
    // 00425e6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425e6d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425e6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_425e6f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425e6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425e70  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00425e72  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425e73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425e74  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00425e77  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425e78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425e79  ff1590004300           -call dword ptr [0x430090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391056) /* 0x430090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00425e7f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425e81  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425e83  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425e85  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00425e88  e8033e0000             -call 0x429c90
    cpu.esp -= 4;
    sub_429c90(app, cpu);
    // 00425e8d  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00425e90  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00425e92  03c1                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00425e94  13d6                   -adc edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00425e96  a3c8534900             -mov dword ptr [0x4953c8], eax
    app->getMemory<x86::reg32>(x86::reg32(4805576) /* 0x4953c8 */) = cpu.eax;
    // 00425e9b  8915cc534900           -mov dword ptr [0x4953cc], edx
    app->getMemory<x86::reg32>(x86::reg32(4805580) /* 0x4953cc */) = cpu.edx;
    // 00425ea1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425ea2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425ea3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_425ea4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425ea4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425ea5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00425ea7  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00425eaa  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00425ead  c745ec49000000         -mov dword ptr [ebp - 0x14], 0x49
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 73 /*0x49*/;
    // 00425eb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425eb5  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00425eb8  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00425ebb  e8101f0000             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 00425ec0  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00425ec3  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00425ec6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425ec7  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00425eca  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00425ecd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425ece  e8f13d0000             -call 0x429cc4
    cpu.esp -= 4;
    sub_429cc4(app, cpu);
    // 00425ed3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00425ed6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425ed7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_425ed8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425ed8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425ed9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00425edd  3b35005e4900           +cmp esi, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425ee3  7355                   -jae 0x425f3a
    if (!cpu.flags.cf)
    {
        goto L_0x00425f3a;
    }
    // 00425ee5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00425ee7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00425ee9  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00425eec  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00425eef  8b0485005d4900         -mov eax, dword ptr [eax*4 + 0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 00425ef6  f644c80401             +test byte ptr [eax + ecx*8 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8) & 1 /*0x1*/));
    // 00425efb  743d                   -je 0x425f3a
    if (cpu.flags.zf)
    {
        goto L_0x00425f3a;
    }
    // 00425efd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425efe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425eff  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425f01  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425f03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425f04  e8a92b0000             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 00425f09  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00425f0b  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00425f0e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425f11  3bfb                   +cmp edi, ebx
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
    // 00425f13  741f                   -je 0x425f34
    if (cpu.flags.zf)
    {
        goto L_0x00425f34;
    }
    // 00425f15  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00425f17  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425f19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425f1a  e8932b0000             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 00425f1f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00425f21  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425f24  3bfb                   +cmp edi, ebx
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
    // 00425f26  740c                   -je 0x425f34
    if (cpu.flags.zf)
    {
        goto L_0x00425f34;
    }
    // 00425f28  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425f2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425f2b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425f2c  e8812b0000             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 00425f31  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00425f34:
    // 00425f34  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00425f36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425f37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425f38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425f39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425f3a:
    // 00425f3a  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00425f41  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 00425f4b  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00425f4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425f4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_425f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425f50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425f51  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00425f53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425f54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425f55  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00425f58  e8d6200000             -call 0x428033
    cpu.esp -= 4;
    sub_428033(app, cpu);
    // 00425f5d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00425f5f  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00425f62  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425f63  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00425f66  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00425f69  e88f210000             -call 0x4280fd
    cpu.esp -= 4;
    sub_4280fd(app, cpu);
    // 00425f6e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00425f71  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00425f73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425f74  e847210000             -call 0x4280c0
    cpu.esp -= 4;
    sub_4280c0(app, cpu);
    // 00425f79  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00425f7c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00425f7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425f7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425f80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425f81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_425f82(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425f82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425f83  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00425f85  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425f88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425f89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425f8a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00425f8d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425f8e  3b35005e4900           +cmp esi, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425f94  0f83c5010000           -jae 0x42615f
    if (!cpu.flags.cf)
    {
        goto L_0x0042615f;
    }
    // 00425f9a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00425f9c  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00425f9f  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00425fa2  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 00425fa5  8d1c85005d4900         -lea ebx, [eax*4 + 0x495d00]
    cpu.ebx = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 00425fac  8b0485005d4900         -mov eax, dword ptr [eax*4 + 0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 00425fb3  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00425fb5  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00425fb8  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00425fbb  0f849e010000           -je 0x42615f
    if (cpu.flags.zf)
    {
        goto L_0x0042615f;
    }
    // 00425fc1  8365f800               -and dword ptr [ebp - 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00425fc5  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00425fc8  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 00425fcc  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00425fce  7467                   -je 0x426037
    if (cpu.flags.zf)
    {
        goto L_0x00426037;
    }
    // 00425fd0  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00425fd3  7562                   -jne 0x426037
    if (!cpu.flags.zf)
    {
        goto L_0x00426037;
    }
    // 00425fd5  f6c248                 +test dl, 0x48
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 72 /*0x48*/));
    // 00425fd8  741d                   -je 0x425ff7
    if (cpu.flags.zf)
    {
        goto L_0x00425ff7;
    }
    // 00425fda  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00425fdd  3c0a                   +cmp al, 0xa
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
    // 00425fdf  7416                   -je 0x425ff7
    if (cpu.flags.zf)
    {
        goto L_0x00425ff7;
    }
    // 00425fe1  ff4d10                 -dec dword ptr [ebp + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))--;
    // 00425fe4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00425fe6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00425fe8  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00425feb  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
    // 00425ff2  c64430050a             -mov byte ptr [eax + esi + 5], 0xa
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */ + cpu.esi * 1) = 10 /*0xa*/;
L_0x00425ff7:
    // 00425ff7  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00425ffa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425ffc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425ffd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00425fff  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00426002  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426003  ff3430                 -push dword ptr [eax + esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1);
    cpu.esp -= 4;
    // 00426006  ff1598004300           -call dword ptr [0x430098]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391064) /* 0x430098 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042600c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042600e  753a                   -jne 0x42604a
    if (!cpu.flags.zf)
    {
        goto L_0x0042604a;
    }
    // 00426010  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426016  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00426018  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426019  3bc1                   +cmp eax, ecx
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
    // 0042601b  7515                   -jne 0x426032
    if (!cpu.flags.zf)
    {
        goto L_0x00426032;
    }
    // 0042601d  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 00426027  890de8534900           -mov dword ptr [0x4953e8], ecx
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.ecx;
    // 0042602d  e93e010000             -jmp 0x426170
    goto L_0x00426170;
L_0x00426032:
    // 00426032  83f86d                 +cmp eax, 0x6d
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
    // 00426035  7507                   -jne 0x42603e
    if (!cpu.flags.zf)
    {
        goto L_0x0042603e;
    }
L_0x00426037:
    // 00426037  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00426039  e935010000             -jmp 0x426173
    goto L_0x00426173;
L_0x0042603e:
    // 0042603e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042603f  e831470000             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 00426044  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426045  e926010000             -jmp 0x426170
    goto L_0x00426170;
L_0x0042604a:
    // 0042604a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042604c  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042604f  0155f8                 -add dword ptr [ebp - 8], edx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00426052  8d4c3004               -lea ecx, [eax + esi + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00426056  8a443004               -mov al, byte ptr [eax + esi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 0042605a  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0042605c  0f84f8000000           -je 0x42615a
    if (cpu.flags.zf)
    {
        goto L_0x0042615a;
    }
    // 00426062  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00426064  7409                   -je 0x42606f
    if (cpu.flags.zf)
    {
        goto L_0x0042606f;
    }
    // 00426066  803f0a                 +cmp byte ptr [edi], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00426069  7504                   -jne 0x42606f
    if (!cpu.flags.zf)
    {
        goto L_0x0042606f;
    }
    // 0042606b  0c04                   +or al, 4
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0042606d  eb02                   -jmp 0x426071
    goto L_0x00426071;
L_0x0042606f:
    // 0042606f  24fb                   -and al, 0xfb
    cpu.al &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x00426071:
    // 00426071  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00426073  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426076  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00426079  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042607c  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042607e  3bc1                   +cmp eax, ecx
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
    // 00426080  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00426083  0f83cb000000           -jae 0x426154
    if (!cpu.flags.cf)
    {
        goto L_0x00426154;
    }
L_0x00426089:
    // 00426089  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042608c  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0042608e  3c1a                   +cmp al, 0x1a
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
    // 00426090  0f84ae000000           -je 0x426144
    if (cpu.flags.zf)
    {
        goto L_0x00426144;
    }
    // 00426096  3c0d                   +cmp al, 0xd
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
    // 00426098  740b                   -je 0x4260a5
    if (cpu.flags.zf)
    {
        goto L_0x004260a5;
    }
    // 0042609a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042609c  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042609d  ff4510                 +inc dword ptr [ebp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004260a0  e991000000             -jmp 0x426136
    goto L_0x00426136;
L_0x004260a5:
    // 004260a5  49                     -dec ecx
    (cpu.ecx)--;
    // 004260a6  394d10                 +cmp dword ptr [ebp + 0x10], ecx
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
    // 004260a9  7318                   -jae 0x4260c3
    if (!cpu.flags.cf)
    {
        goto L_0x004260c3;
    }
    // 004260ab  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004260ae  40                     -inc eax
    (cpu.eax)++;
    // 004260af  80380a                 +cmp byte ptr [eax], 0xa
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
    // 004260b2  7506                   -jne 0x4260ba
    if (!cpu.flags.zf)
    {
        goto L_0x004260ba;
    }
    // 004260b4  83451002               +add dword ptr [ebp + 0x10], 2
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
    // 004260b8  eb5e                   -jmp 0x426118
    goto L_0x00426118;
L_0x004260ba:
    // 004260ba  c6070d                 -mov byte ptr [edi], 0xd
    app->getMemory<x86::reg8>(cpu.edi) = 13 /*0xd*/;
    // 004260bd  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004260be  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004260c1  eb73                   -jmp 0x426136
    goto L_0x00426136;
L_0x004260c3:
    // 004260c3  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004260c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004260c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004260c9  ff4510                 -inc dword ptr [ebp + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))++;
    // 004260cc  8d45ff                 -lea eax, [ebp - 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 004260cf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004260d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004260d2  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004260d4  ff3430                 -push dword ptr [eax + esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1);
    cpu.esp -= 4;
    // 004260d7  ff1598004300           -call dword ptr [0x430098]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391064) /* 0x430098 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004260dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004260df  750a                   -jne 0x4260eb
    if (!cpu.flags.zf)
    {
        goto L_0x004260eb;
    }
    // 004260e1  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004260e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004260e9  7547                   -jne 0x426132
    if (!cpu.flags.zf)
    {
        goto L_0x00426132;
    }
L_0x004260eb:
    // 004260eb  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 004260ef  7441                   -je 0x426132
    if (cpu.flags.zf)
    {
        goto L_0x00426132;
    }
    // 004260f1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004260f3  f644300448             +test byte ptr [eax + esi + 4], 0x48
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 72 /*0x48*/));
    // 004260f8  7413                   -je 0x42610d
    if (cpu.flags.zf)
    {
        goto L_0x0042610d;
    }
    // 004260fa  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 004260fd  3c0a                   +cmp al, 0xa
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
    // 004260ff  7417                   -je 0x426118
    if (cpu.flags.zf)
    {
        goto L_0x00426118;
    }
    // 00426101  c6070d                 -mov byte ptr [edi], 0xd
    app->getMemory<x86::reg8>(cpu.edi) = 13 /*0xd*/;
    // 00426104  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00426106  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00426107  88443105               -mov byte ptr [ecx + esi + 5], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */ + cpu.esi * 1) = cpu.al;
    // 0042610b  eb29                   -jmp 0x426136
    goto L_0x00426136;
L_0x0042610d:
    // 0042610d  3b7d0c                 +cmp edi, dword ptr [ebp + 0xc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426110  750b                   -jne 0x42611d
    if (!cpu.flags.zf)
    {
        goto L_0x0042611d;
    }
    // 00426112  807dff0a               +cmp byte ptr [ebp - 1], 0xa
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
    // 00426116  7505                   -jne 0x42611d
    if (!cpu.flags.zf)
    {
        goto L_0x0042611d;
    }
L_0x00426118:
    // 00426118  c6070a                 -mov byte ptr [edi], 0xa
    app->getMemory<x86::reg8>(cpu.edi) = 10 /*0xa*/;
    // 0042611b  eb18                   -jmp 0x426135
    goto L_0x00426135;
L_0x0042611d:
    // 0042611d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042611f  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00426121  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00426124  e889290000             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 00426129  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042612c  807dff0a               +cmp byte ptr [ebp - 1], 0xa
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
    // 00426130  7404                   -je 0x426136
    if (cpu.flags.zf)
    {
        goto L_0x00426136;
    }
L_0x00426132:
    // 00426132  c6070d                 -mov byte ptr [edi], 0xd
    app->getMemory<x86::reg8>(cpu.edi) = 13 /*0xd*/;
L_0x00426135:
    // 00426135  47                     -inc edi
    (cpu.edi)++;
L_0x00426136:
    // 00426136  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00426139  394d10                 +cmp dword ptr [ebp + 0x10], ecx
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
    // 0042613c  0f8247ffffff           -jb 0x426089
    if (cpu.flags.cf)
    {
        goto L_0x00426089;
    }
    // 00426142  eb10                   -jmp 0x426154
    goto L_0x00426154;
L_0x00426144:
    // 00426144  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00426146  8d743004               -lea esi, [eax + esi + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 0042614a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042614c  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0042614e  7504                   -jne 0x426154
    if (!cpu.flags.zf)
    {
        goto L_0x00426154;
    }
    // 00426150  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00426152  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x00426154:
    // 00426154  2b7d0c                 +sub edi, dword ptr [ebp + 0xc]
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00426157  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
L_0x0042615a:
    // 0042615a  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042615d  eb14                   -jmp 0x426173
    goto L_0x00426173;
L_0x0042615f:
    // 0042615f  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00426166  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
L_0x00426170:
    // 00426170  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00426173:
    // 00426173  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426174  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426175  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426176  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426177  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_426178(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426178  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426179  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042617b  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0042617e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042617f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426180  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426183  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00426185  3b3d005e4900           +cmp edi, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042618b  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0042618e  0f834b020000           -jae 0x4263df
    if (!cpu.flags.cf)
    {
        goto L_0x004263df;
    }
    // 00426194  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00426196  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00426199  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0042619c  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 0042619f  8d0485005d4900         -lea eax, [eax*4 + 0x495d00]
    cpu.eax = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 004261a6  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004261a9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004261ab  03c7                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004261ad  f6400401               +test byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 004261b1  0f8428020000           -je 0x4263df
    if (cpu.flags.zf)
    {
        goto L_0x004263df;
    }
    // 004261b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004261b8  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 004261ba  ff15a8004300           -call dword ptr [0x4300a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391080) /* 0x4300a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004261c0  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004261c3  83f801                 +cmp eax, 1
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
    // 004261c6  0f848c000000           -je 0x426258
    if (cpu.flags.zf)
    {
        goto L_0x00426258;
    }
    // 004261cc  83f802                 +cmp eax, 2
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
    // 004261cf  7424                   -je 0x4261f5
    if (cpu.flags.zf)
    {
        goto L_0x004261f5;
    }
    // 004261d1  83f803                 +cmp eax, 3
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
    // 004261d4  742a                   -je 0x426200
    if (cpu.flags.zf)
    {
        goto L_0x00426200;
    }
    // 004261d6  3bc3                   +cmp eax, ebx
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
    // 004261d8  0f85a9000000           -jne 0x426287
    if (!cpu.flags.zf)
    {
        goto L_0x00426287;
    }
    // 004261de  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
L_0x004261e8:
    // 004261e8  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
L_0x004261ec:
    // 004261ec  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004261ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004261f0  e9f7010000             -jmp 0x4263ec
    goto L_0x004263ec;
L_0x004261f5:
    // 004261f5  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004261f8  66c746060020           -mov word ptr [esi + 6], 0x2000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 8192 /*0x2000*/;
    // 004261fe  eb09                   -jmp 0x426209
    goto L_0x00426209;
L_0x00426200:
    // 00426200  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426203  66c746060010           -mov word ptr [esi + 6], 0x1000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 4096 /*0x1000*/;
L_0x00426209:
    // 00426209  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042620c  83f802                 +cmp eax, 2
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
    // 0042620f  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00426211  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00426214  66c746080100           -mov word ptr [esi + 8], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0042621a  66895e04               -mov word ptr [esi + 4], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.bx;
    // 0042621e  66895e0c               -mov word ptr [esi + 0xc], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.bx;
    // 00426222  66895e0a               -mov word ptr [esi + 0xa], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.bx;
    // 00426226  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00426229  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0042622c  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0042622f  7505                   -jne 0x426236
    if (!cpu.flags.zf)
    {
        goto L_0x00426236;
    }
L_0x00426231:
    // 00426231  895e14                 -mov dword ptr [esi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00426234  ebb6                   -jmp 0x4261ec
    goto L_0x004261ec;
L_0x00426236:
    // 00426236  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426239  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042623a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042623b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042623e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042623f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426240  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00426242  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426243  ff3438                 -push dword ptr [eax + edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 1);
    cpu.esp -= 4;
    // 00426246  ff15a4004300           -call dword ptr [0x4300a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391076) /* 0x4300a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042624c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042624e  74e1                   -je 0x426231
    if (cpu.flags.zf)
    {
        goto L_0x00426231;
    }
    // 00426250  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426253  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00426256  eb94                   -jmp 0x4261ec
    goto L_0x004261ec;
L_0x00426258:
    // 00426258  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042625b  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 0042625e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042625f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00426262  66895e06               -mov word ptr [esi + 6], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.bx;
    // 00426266  66895e0c               -mov word ptr [esi + 0xc], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.bx;
    // 0042626a  66895e0a               -mov word ptr [esi + 0xa], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.bx;
    // 0042626e  66895e04               -mov word ptr [esi + 4], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.bx;
    // 00426272  66c746080100           -mov word ptr [esi + 8], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00426278  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042627a  ff3438                 -push dword ptr [eax + edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 1);
    cpu.esp -= 4;
    // 0042627d  ff1530004300           -call dword ptr [0x430030]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390960) /* 0x430030 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426283  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426285  7512                   -jne 0x426299
    if (!cpu.flags.zf)
    {
        goto L_0x00426299;
    }
L_0x00426287:
    // 00426287  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042628d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042628e  e8e2440000             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 00426293  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426294  e94fffffff             -jmp 0x4261e8
    goto L_0x004261e8;
L_0x00426299:
    // 00426299  f645ac01               +test byte ptr [ebp - 0x54], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-84) /* -0x54 */) & 1 /*0x1*/));
    // 0042629d  7408                   -je 0x4262a7
    if (cpu.flags.zf)
    {
        goto L_0x004262a7;
    }
    // 0042629f  66814e062401           +or word ptr [esi + 6], 0x124
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) |= x86::reg16(x86::sreg16(292 /*0x124*/))));
    // 004262a5  eb06                   -jmp 0x4262ad
    goto L_0x004262ad;
L_0x004262a7:
    // 004262a7  66814e06b601           -or word ptr [esi + 6], 0x1b6
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) |= x86::reg16(x86::sreg16(438 /*0x1b6*/));
L_0x004262ad:
    // 004262ad  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004262b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262b1  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004262b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262b5  ff15a0004300           -call dword ptr [0x4300a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391072) /* 0x4300a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004262bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004262bd  0f8425ffffff           -je 0x4261e8
    if (cpu.flags.zf)
    {
        goto L_0x004261e8;
    }
    // 004262c3  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004262c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262c7  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004262ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262cb  ff159c004300           -call dword ptr [0x43009c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391068) /* 0x43009c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004262d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004262d3  0f840fffffff           -je 0x4261e8
    if (cpu.flags.zf)
    {
        goto L_0x004261e8;
    }
    // 004262d9  0fb745ec               -movzx eax, word ptr [ebp - 0x14]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    // 004262dd  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004262e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004262e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262e2  0fb745ea               -movzx eax, word ptr [ebp - 0x16]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */));
    // 004262e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262e7  0fb745e8               -movzx eax, word ptr [ebp - 0x18]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-24) /* -0x18 */));
    // 004262eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262ec  0fb745e6               -movzx eax, word ptr [ebp - 0x1a]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */));
    // 004262f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262f1  0fb745e2               -movzx eax, word ptr [ebp - 0x1e]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-30) /* -0x1e */));
    // 004262f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262f6  0fb745e0               -movzx eax, word ptr [ebp - 0x20]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-32) /* -0x20 */));
    // 004262fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262fb  e8dc440000             -call 0x42a7dc
    cpu.esp -= 4;
    sub_42a7dc(app, cpu);
    // 00426300  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00426303  395db8                 +cmp dword ptr [ebp - 0x48], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426306  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00426309  7505                   -jne 0x426310
    if (!cpu.flags.zf)
    {
        goto L_0x00426310;
    }
    // 0042630b  395dbc                 +cmp dword ptr [ebp - 0x44], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042630e  7453                   -je 0x426363
    if (cpu.flags.zf)
    {
        goto L_0x00426363;
    }
L_0x00426310:
    // 00426310  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00426313  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426314  8d45b8                 -lea eax, [ebp - 0x48]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 00426317  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426318  ff15a0004300           -call dword ptr [0x4300a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391072) /* 0x4300a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042631e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426320  0f84b1000000           -je 0x4263d7
    if (cpu.flags.zf)
    {
        goto L_0x004263d7;
    }
    // 00426326  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00426329  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042632a  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042632d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042632e  ff159c004300           -call dword ptr [0x43009c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391068) /* 0x43009c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426334  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426336  0f849b000000           -je 0x4263d7
    if (cpu.flags.zf)
    {
        goto L_0x004263d7;
    }
    // 0042633c  0fb745ec               -movzx eax, word ptr [ebp - 0x14]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    // 00426340  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426341  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426342  0fb745ea               -movzx eax, word ptr [ebp - 0x16]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */));
    // 00426346  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426347  0fb745e8               -movzx eax, word ptr [ebp - 0x18]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-24) /* -0x18 */));
    // 0042634b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042634c  0fb745e6               -movzx eax, word ptr [ebp - 0x1a]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */));
    // 00426350  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426351  0fb745e2               -movzx eax, word ptr [ebp - 0x1e]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-30) /* -0x1e */));
    // 00426355  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426356  0fb745e0               -movzx eax, word ptr [ebp - 0x20]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-32) /* -0x20 */));
    // 0042635a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042635b  e87c440000             -call 0x42a7dc
    cpu.esp -= 4;
    sub_42a7dc(app, cpu);
    // 00426360  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x00426363:
    // 00426363  395db0                 +cmp dword ptr [ebp - 0x50], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426366  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00426369  750a                   -jne 0x426375
    if (!cpu.flags.zf)
    {
        goto L_0x00426375;
    }
    // 0042636b  395db4                 +cmp dword ptr [ebp - 0x4c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042636e  7505                   -jne 0x426375
    if (!cpu.flags.zf)
    {
        goto L_0x00426375;
    }
    // 00426370  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00426373  eb4b                   -jmp 0x4263c0
    goto L_0x004263c0;
L_0x00426375:
    // 00426375  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00426378  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426379  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0042637c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042637d  ff15a0004300           -call dword ptr [0x4300a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391072) /* 0x4300a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426383  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426385  7450                   -je 0x4263d7
    if (cpu.flags.zf)
    {
        goto L_0x004263d7;
    }
    // 00426387  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0042638a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042638b  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042638e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042638f  ff159c004300           -call dword ptr [0x43009c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391068) /* 0x43009c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426395  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426397  743e                   -je 0x4263d7
    if (cpu.flags.zf)
    {
        goto L_0x004263d7;
    }
    // 00426399  0fb745ec               -movzx eax, word ptr [ebp - 0x14]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    // 0042639d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042639e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042639f  0fb745ea               -movzx eax, word ptr [ebp - 0x16]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */));
    // 004263a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004263a4  0fb745e8               -movzx eax, word ptr [ebp - 0x18]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-24) /* -0x18 */));
    // 004263a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004263a9  0fb745e6               -movzx eax, word ptr [ebp - 0x1a]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */));
    // 004263ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004263ae  0fb745e2               -movzx eax, word ptr [ebp - 0x1e]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-30) /* -0x1e */));
    // 004263b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004263b3  0fb745e0               -movzx eax, word ptr [ebp - 0x20]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-32) /* -0x20 */));
    // 004263b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004263b8  e81f440000             -call 0x42a7dc
    cpu.esp -= 4;
    sub_42a7dc(app, cpu);
    // 004263bd  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x004263c0:
    // 004263c0  804e0780               +or byte ptr [esi + 7], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 004263c4  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004263c7  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004263ca  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004263cc  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004263cf  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004263d2  e915feffff             -jmp 0x4261ec
    goto L_0x004261ec;
L_0x004263d7:
    // 004263d7  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004263da  e90dfeffff             -jmp 0x4261ec
    goto L_0x004261ec;
L_0x004263df:
    // 004263df  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 004263e9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x004263ec:
    // 004263ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004263ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004263ee  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004263ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4263f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004263f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004263f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004263f3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004263f6  8365f400               -and dword ptr [ebp - 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004263fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004263fb  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004263fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004263ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426400  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426402  81e380000000           +and ebx, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(128 /*0x80*/))));
    // 00426408  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426409  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042640c  c745f00c000000         -mov dword ptr [ebp - 0x10], 0xc
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 12 /*0xc*/;
    // 00426413  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00426416  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00426419  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042641c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042641d  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00426420  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426421  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426424  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426425  ff15b0004300           -call dword ptr [0x4300b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391088) /* 0x4300b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042642b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042642d  7512                   -jne 0x426441
    if (!cpu.flags.zf)
    {
        goto L_0x00426441;
    }
    // 0042642f  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426435  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426436  e83a430000             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 0042643b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042643c  e92b010000             -jmp 0x42656c
    goto L_0x0042656c;
L_0x00426441:
    // 00426441  e858440000             -call 0x42a89e
    cpu.esp -= 4;
    sub_42a89e(app, cpu);
    // 00426446  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426449  83f8ff                 +cmp eax, -1
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
    // 0042644c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0042644e  0f84f7000000           -je 0x42654b
    if (cpu.flags.zf)
    {
        goto L_0x0042654b;
    }
    // 00426454  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00426456  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 00426458  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0042645b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042645c  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 00426463  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 00426465  c644c10489             -mov byte ptr [ecx + eax*8 + 4], 0x89
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = 137 /*0x89*/;
    // 0042646a  e82f440000             -call 0x42a89e
    cpu.esp -= 4;
    sub_42a89e(app, cpu);
    // 0042646f  83f8ff                 +cmp eax, -1
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
    // 00426472  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00426475  0f84bb000000           -je 0x426536
    if (cpu.flags.zf)
    {
        goto L_0x00426536;
    }
    // 0042647b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042647d  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 0042647f  c1f905                 +sar ecx, 5
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
    // 00426482  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 00426489  c644c10489             -mov byte ptr [ecx + eax*8 + 4], 0x89
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = 137 /*0x89*/;
    // 0042648e  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 00426493  854510                 -test dword ptr [ebp + 0x10], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) & cpu.eax));
    // 00426496  750e                   -jne 0x4264a6
    if (!cpu.flags.zf)
    {
        goto L_0x004264a6;
    }
    // 00426498  f6451140               +test byte ptr [ebp + 0x11], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(17) /* 0x11 */) & 64 /*0x40*/));
    // 0042649c  753b                   -jne 0x4264d9
    if (!cpu.flags.zf)
    {
        goto L_0x004264d9;
    }
    // 0042649e  390558544900           +cmp dword ptr [0x495458], eax
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
    // 004264a4  7533                   -jne 0x4264d9
    if (!cpu.flags.zf)
    {
        goto L_0x004264d9;
    }
L_0x004264a6:
    // 004264a6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004264a8  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004264aa  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 004264ac  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004264af  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 004264b6  8064c1047f             -and byte ptr [ecx + eax*8 + 4], 0x7f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004264bb  8d44c104               -lea eax, [ecx + eax*8 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004264bf  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004264c2  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004264c4  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 004264c6  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004264c9  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 004264d0  8064c1047f             -and byte ptr [ecx + eax*8 + 4], 0x7f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004264d5  8d44c104               -lea eax, [ecx + eax*8 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
L_0x004264d9:
    // 004264d9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004264db  7433                   -je 0x426510
    if (cpu.flags.zf)
    {
        goto L_0x00426510;
    }
    // 004264dd  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004264df  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004264e1  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 004264e3  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004264e6  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 004264ed  804cc10410             -or byte ptr [ecx + eax*8 + 4], 0x10
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004264f2  8d44c104               -lea eax, [ecx + eax*8 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004264f6  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004264f9  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004264fb  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 004264fd  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00426500  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 00426507  804cc10410             -or byte ptr [ecx + eax*8 + 4], 0x10
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0042650c  8d44c104               -lea eax, [ecx + eax*8 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
L_0x00426510:
    // 00426510  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00426513  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 00426515  e819440000             -call 0x42a933
    cpu.esp -= 4;
    sub_42a933(app, cpu);
    // 0042651a  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0042651d  ff7604                 -push dword ptr [esi + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 00426520  e80e440000             -call 0x42a933
    cpu.esp -= 4;
    sub_42a933(app, cpu);
    // 00426525  8325e453490000         -and dword ptr [0x4953e4], 0
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042652c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042652f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00426531:
    // 00426531  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426532  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426533  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426534  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426535  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00426536:
    // 00426536  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00426538  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042653a  23f7                   -and esi, edi
    cpu.esi &= x86::reg32(x86::sreg32(cpu.edi));
    // 0042653c  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0042653f  8b0485005d4900         -mov eax, dword ptr [eax*4 + 0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 00426546  8064f00400             -and byte ptr [eax + esi*8 + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 8) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0042654b:
    // 0042654b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042654e  8b35ac004300           -mov esi, dword ptr [0x4300ac]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4391084) /* 0x4300ac */);
    // 00426554  c705e453490018000000   -mov dword ptr [0x4953e4], 0x18
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 24 /*0x18*/;
    // 0042655e  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426560  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00426563  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426565  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042656c:
    // 0042656c  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042656f  ebc0                   -jmp 0x426531
    goto L_0x00426531;
}

/* align: skip  */
void Application::asm_sub_426571(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426571  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426572  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00426574  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 00426578  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426579  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042657c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042657d  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0042657f  7f04                   -jg 0x426585
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00426585;
    }
    // 00426581  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00426583  eb36                   -jmp 0x4265bb
    goto L_0x004265bb;
L_0x00426585:
    // 00426585  ff4d0c                 +dec dword ptr [ebp + 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00426588  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426589  742a                   -je 0x4265b5
    if (cpu.flags.zf)
    {
        goto L_0x004265b5;
    }
    // 0042658b  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x0042658e:
    // 0042658e  ff4e04                 +dec dword ptr [esi + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00426591  780a                   -js 0x42659d
    if (cpu.flags.sf)
    {
        goto L_0x0042659d;
    }
    // 00426593  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00426595  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 00426598  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00426599  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0042659b  eb07                   -jmp 0x4265a4
    goto L_0x004265a4;
L_0x0042659d:
    // 0042659d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042659e  e852160000             -call 0x427bf5
    cpu.esp -= 4;
    sub_427bf5(app, cpu);
    // 004265a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004265a4:
    // 004265a4  83f8ff                 +cmp eax, -1
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
    // 004265a7  7416                   -je 0x4265bf
    if (cpu.flags.zf)
    {
        goto L_0x004265bf;
    }
    // 004265a9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004265ab  47                     -inc edi
    (cpu.edi)++;
    // 004265ac  3c0a                   +cmp al, 0xa
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
    // 004265ae  7405                   -je 0x4265b5
    if (cpu.flags.zf)
    {
        goto L_0x004265b5;
    }
    // 004265b0  ff4d0c                 +dec dword ptr [ebp + 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004265b3  75d9                   -jne 0x42658e
    if (!cpu.flags.zf)
    {
        goto L_0x0042658e;
    }
L_0x004265b5:
    // 004265b5  802700                 -and byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x004265b8:
    // 004265b8  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004265ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004265bb:
    // 004265bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004265bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004265bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004265be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004265bf:
    // 004265bf  3b7d08                 +cmp edi, dword ptr [ebp + 8]
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
    // 004265c2  75f1                   -jne 0x4265b5
    if (!cpu.flags.zf)
    {
        goto L_0x004265b5;
    }
    // 004265c4  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004265c6  ebf0                   -jmp 0x4265b8
    goto L_0x004265b8;
}

/* align: skip  */
void Application::asm_sub_4265c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004265c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004265c9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004265cd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004265ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004265cf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004265d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004265d2  750f                   -jne 0x4265e3
    if (!cpu.flags.zf)
    {
        goto L_0x004265e3;
    }
    // 004265d4  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004265d8  e898e8ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 004265dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004265de  e900010000             -jmp 0x4266e3
    goto L_0x004266e3;
L_0x004265e3:
    // 004265e3  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004265e7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004265e9  750e                   -jne 0x4265f9
    if (!cpu.flags.zf)
    {
        goto L_0x004265f9;
    }
    // 004265eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004265ec  e855e8ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 004265f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004265f2:
    // 004265f2  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004265f4  e9ea000000             -jmp 0x4266e3
    goto L_0x004266e3;
L_0x004265f9:
    // 004265f9  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004265fb  83fee0                 +cmp esi, -0x20
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
    // 004265fe  0f87c0000000           -ja 0x4266c4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004266c4;
    }
    // 00426604  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426605  e8d2040000             -call 0x426adc
    cpu.esp -= 4;
    sub_426adc(app, cpu);
    // 0042660a  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042660c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042660d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042660f  0f848c000000           -je 0x4266a1
    if (cpu.flags.zf)
    {
        goto L_0x004266a1;
    }
    // 00426615  3b357cd24300           +cmp esi, dword ptr [0x43d27c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4444796) /* 0x43d27c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042661b  7744                   -ja 0x426661
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00426661;
    }
    // 0042661d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042661e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042661f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426620  e8c20c0000             -call 0x4272e7
    cpu.esp -= 4;
    sub_4272e7(app, cpu);
    // 00426625  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00426628  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042662a  7404                   -je 0x426630
    if (cpu.flags.zf)
    {
        goto L_0x00426630;
    }
    // 0042662c  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0042662e  eb29                   -jmp 0x426659
    goto L_0x00426659;
L_0x00426630:
    // 00426630  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426631  e8fc070000             -call 0x426e32
    cpu.esp -= 4;
    sub_426e32(app, cpu);
    // 00426636  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00426638  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426639  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042663b  7424                   -je 0x426661
    if (cpu.flags.zf)
    {
        goto L_0x00426661;
    }
    // 0042663d  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00426640  48                     -dec eax
    (cpu.eax)--;
    // 00426641  3bc6                   +cmp eax, esi
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
    // 00426643  7202                   -jb 0x426647
    if (cpu.flags.cf)
    {
        goto L_0x00426647;
    }
    // 00426645  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00426647:
    // 00426647  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426648  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426649  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042664a  e871120000             -call 0x4278c0
    cpu.esp -= 4;
    sub_4278c0(app, cpu);
    // 0042664f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426650  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426651  e8b1040000             -call 0x426b07
    cpu.esp -= 4;
    sub_426b07(app, cpu);
    // 00426656  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00426659:
    // 00426659  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042665b  0f8580000000           -jne 0x4266e1
    if (!cpu.flags.zf)
    {
        goto L_0x004266e1;
    }
L_0x00426661:
    // 00426661  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00426663  7503                   -jne 0x426668
    if (!cpu.flags.zf)
    {
        goto L_0x00426668;
    }
    // 00426665  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00426667  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00426668:
    // 00426668  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0042666b  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042666e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042666f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426671  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 00426677  ff1588004300           -call dword ptr [0x430088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391048) /* 0x430088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042667d  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042667f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00426681  7441                   -je 0x4266c4
    if (cpu.flags.zf)
    {
        goto L_0x004266c4;
    }
    // 00426683  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00426686  48                     -dec eax
    (cpu.eax)--;
    // 00426687  3bc6                   +cmp eax, esi
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
    // 00426689  7202                   -jb 0x42668d
    if (cpu.flags.cf)
    {
        goto L_0x0042668d;
    }
    // 0042668b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0042668d:
    // 0042668d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042668e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042668f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426690  e82b120000             -call 0x4278c0
    cpu.esp -= 4;
    sub_4278c0(app, cpu);
    // 00426695  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426696  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426697  e86b040000             -call 0x426b07
    cpu.esp -= 4;
    sub_426b07(app, cpu);
    // 0042669c  83c414                 +add esp, 0x14
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
    // 0042669f  eb1f                   -jmp 0x4266c0
    goto L_0x004266c0;
L_0x004266a1:
    // 004266a1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004266a3  7503                   -jne 0x4266a8
    if (!cpu.flags.zf)
    {
        goto L_0x004266a8;
    }
    // 004266a5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004266a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004266a8:
    // 004266a8  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004266ab  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 004266ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004266af  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004266b0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004266b2  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 004266b8  ff15b4004300           -call dword ptr [0x4300b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391092) /* 0x4300b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004266be  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004266c0:
    // 004266c0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004266c2  751d                   -jne 0x4266e1
    if (!cpu.flags.zf)
    {
        goto L_0x004266e1;
    }
L_0x004266c4:
    // 004266c4  833ddc53490000         +cmp dword ptr [0x4953dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805596) /* 0x4953dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004266cb  7414                   -je 0x4266e1
    if (cpu.flags.zf)
    {
        goto L_0x004266e1;
    }
    // 004266cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004266ce  e80a0f0000             -call 0x4275dd
    cpu.esp -= 4;
    sub_4275dd(app, cpu);
    // 004266d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004266d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004266d6  0f851dffffff           -jne 0x4265f9
    if (!cpu.flags.zf)
    {
        goto L_0x004265f9;
    }
    // 004266dc  e911ffffff             -jmp 0x4265f2
    goto L_0x004265f2;
L_0x004266e1:
    // 004266e1  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004266e3:
    // 004266e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004266e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004266e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004266e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004266e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4266f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004266f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004266f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004266f3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004266f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004266f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004266f8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004266f9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004266fa  fc                     -cld 
    cpu.flags.df = 0;
    // 004266fb  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004266fe  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426701  f7400406000000         +test dword ptr [eax + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00426708  0f8582000000           -jne 0x426790
    if (!cpu.flags.zf)
    {
        goto L_0x00426790;
    }
    // 0042670e  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00426711  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00426714  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00426717  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042671a  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0042671d  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00426720  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
L_0x00426723:
    // 00426723  83feff                 +cmp esi, -1
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
    // 00426726  7461                   -je 0x426789
    if (cpu.flags.zf)
    {
        goto L_0x00426789;
    }
    // 00426728  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 0042672b  837c8f0400             +cmp dword ptr [edi + ecx*4 + 4], 0
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
    // 00426730  7445                   -je 0x426777
    if (cpu.flags.zf)
    {
        goto L_0x00426777;
    }
    // 00426732  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426733  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426734  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00426737  ff548f04               -call dword ptr [edi + ecx*4 + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042673b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042673c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042673d  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426740  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00426742  7433                   -je 0x426777
    if (cpu.flags.zf)
    {
        goto L_0x00426777;
    }
    // 00426744  783c                   -js 0x426782
    if (cpu.flags.sf)
    {
        goto L_0x00426782;
    }
    // 00426746  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00426749  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042674a  e895f2ffff             -call 0x4259e4
    cpu.esp -= 4;
    sub_4259e4(app, cpu);
    // 0042674f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00426752  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00426755  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426756  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426757  e8caf2ffff             -call 0x425a26
    cpu.esp -= 4;
    sub_425a26(app, cpu);
    // 0042675c  83c408                 +add esp, 8
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
    // 0042675f  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00426762  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00426764  8b448f08               -mov eax, dword ptr [edi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00426768  e84df3ffff             -call 0x425aba
    cpu.esp -= 4;
    sub_425aba(app, cpu);
    // 0042676d  8b048f                 -mov eax, dword ptr [edi + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00426770  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00426773  ff548f08               -call dword ptr [edi + ecx*4 + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00426777:
    // 00426777  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0042677a  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 0042677d  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00426780  eba1                   -jmp 0x426723
    goto L_0x00426723;
L_0x00426782:
    // 00426782  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 00426787  eb1c                   -jmp 0x4267a5
    goto L_0x004267a5;
L_0x00426789:
    // 00426789  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042678e  eb15                   -jmp 0x4267a5
    goto L_0x004267a5;
L_0x00426790:
    // 00426790  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426791  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00426794  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00426796  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426797  e88af2ffff             -call 0x425a26
    cpu.esp -= 4;
    sub_425a26(app, cpu);
    // 0042679c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042679f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004267a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004267a5:
    // 004267a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004267a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004267a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004267a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004267a9  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004267ab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004267ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4267ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004267ad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004267ae  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004267b2  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 004267b4  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004267b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004267b8  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004267bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004267bc  e865f2ffff             -call 0x425a26
    cpu.esp -= 4;
    sub_425a26(app, cpu);
    // 004267c1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004267c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004267c5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4267c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004267c8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004267c9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004267cb  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004267cd  68a0064300             -push 0x4306a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4392608 /*0x4306a0*/;
    cpu.esp -= 4;
    // 004267d2  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 004267d7  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004267dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004267de  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004267e5  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 004267e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004267e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004267ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004267eb  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004267ee  ff15c0004300           -call dword ptr [0x4300c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391104) /* 0x4300c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004267f4  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004267f6  8ad4                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004267f8  8915fc534900           -mov dword ptr [0x4953fc], edx
    app->getMemory<x86::reg32>(x86::reg32(4805628) /* 0x4953fc */) = cpu.edx;
    // 004267fe  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00426800  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00426806  890df8534900           -mov dword ptr [0x4953f8], ecx
    app->getMemory<x86::reg32>(x86::reg32(4805624) /* 0x4953f8 */) = cpu.ecx;
    // 0042680c  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0042680f  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00426811  890df4534900           -mov dword ptr [0x4953f4], ecx
    app->getMemory<x86::reg32>(x86::reg32(4805620) /* 0x4953f4 */) = cpu.ecx;
    // 00426817  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0042681a  a3f0534900             -mov dword ptr [0x4953f0], eax
    app->getMemory<x86::reg32>(x86::reg32(4805616) /* 0x4953f0 */) = cpu.eax;
    // 0042681f  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00426821  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426822  e83b020000             -call 0x426a62
    cpu.esp -= 4;
    sub_426a62(app, cpu);
    // 00426827  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426828  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042682a  7508                   -jne 0x426834
    if (!cpu.flags.zf)
    {
        goto L_0x00426834;
    }
    // 0042682c  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0042682e  e8b0000000             -call 0x4268e3
    cpu.esp -= 4;
    sub_4268e3(app, cpu);
    // 00426833  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00426834:
    // 00426834  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00426837  e8cb200000             -call 0x428907
    cpu.esp -= 4;
    sub_428907(app, cpu);
    // 0042683c  ff15bc004300           -call dword ptr [0x4300bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391100) /* 0x4300bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426842  a3305e4900             -mov dword ptr [0x495e30], eax
    app->getMemory<x86::reg32>(x86::reg32(4808240) /* 0x495e30 */) = cpu.eax;
    // 00426847  e8f7460000             -call 0x42af43
    cpu.esp -= 4;
    sub_42af43(app, cpu);
    // 0042684c  a3d0534900             -mov dword ptr [0x4953d0], eax
    app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */) = cpu.eax;
    // 00426851  e8a0440000             -call 0x42acf6
    cpu.esp -= 4;
    sub_42acf6(app, cpu);
    // 00426856  e8e2430000             -call 0x42ac3d
    cpu.esp -= 4;
    sub_42ac3d(app, cpu);
    // 0042685b  e86e140000             -call 0x427cce
    cpu.esp -= 4;
    sub_427cce(app, cpu);
    // 00426860  8975d0                 -mov dword ptr [ebp - 0x30], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.esi;
    // 00426863  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 00426866  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426867  ff15b8004300           -call dword ptr [0x4300b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391096) /* 0x4300b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042686d  e873430000             -call 0x42abe5
    cpu.esp -= 4;
    sub_42abe5(app, cpu);
    // 00426872  89459c                 -mov dword ptr [ebp - 0x64], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-100) /* -0x64 */) = cpu.eax;
    // 00426875  f645d001               +test byte ptr [ebp - 0x30], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-48) /* -0x30 */) & 1 /*0x1*/));
    // 00426879  7406                   -je 0x426881
    if (cpu.flags.zf)
    {
        goto L_0x00426881;
    }
    // 0042687b  0fb745d4               -movzx eax, word ptr [ebp - 0x2c]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */));
    // 0042687f  eb03                   -jmp 0x426884
    goto L_0x00426884;
L_0x00426881:
    // 00426881  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00426883  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00426884:
    // 00426884  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426885  ff759c                 -push dword ptr [ebp - 0x64]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    cpu.esp -= 4;
    // 00426888  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426889  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042688a  ff1528004300           -call dword ptr [0x430028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390952) /* 0x430028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426890  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426891  e8ba70ffff             -call 0x41d950
    cpu.esp -= 4;
    sub_41d950(app, cpu);
    // 00426896  8945a0                 -mov dword ptr [ebp - 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = cpu.eax;
    // 00426899  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042689a  e85c140000             -call 0x427cfb
    cpu.esp -= 4;
    sub_427cfb(app, cpu);
    // 0042689f  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004268a2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004268a4  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004268a6  894d98                 -mov dword ptr [ebp - 0x68], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-104) /* -0x68 */) = cpu.ecx;
    // 004268a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004268aa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004268ab  e8b1410000             -call 0x42aa61
    cpu.esp -= 4;
    sub_42aa61(app, cpu);
    // 004268b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004268b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004268b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4268b3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004268b3  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004268b6  ff7598                 -push dword ptr [ebp - 0x68]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-104) /* -0x68 */);
    cpu.esp -= 4;
    // 004268b9  e84e140000             -call 0x427d0c
    cpu.esp -= 4;
    sub_427d0c(app, cpu);
    return sub_4268be(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4268be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004268be  833dd853490001         +cmp dword ptr [0x4953d8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805592) /* 0x4953d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004268c5  7505                   -jne 0x4268cc
    if (!cpu.flags.zf)
    {
        goto L_0x004268cc;
    }
    // 004268c7  e8a9470000             -call 0x42b075
    cpu.esp -= 4;
    sub_42b075(app, cpu);
L_0x004268cc:
    // 004268cc  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004268d0  e8d9470000             -call 0x42b0ae
    cpu.esp -= 4;
    sub_42b0ae(app, cpu);
    // 004268d5  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 004268da  ff1570d24300           -call dword ptr [0x43d270]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4444784) /* 0x43d270 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    NFS2_ASSERT(false);  // falls off the end of the routine
}

/* align: skip  */
void Application::asm_sub_4268e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004268e3  833dd853490001         +cmp dword ptr [0x4953d8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805592) /* 0x4953d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004268ea  7505                   -jne 0x4268f1
    if (!cpu.flags.zf)
    {
        goto L_0x004268f1;
    }
    // 004268ec  e884470000             -call 0x42b075
    cpu.esp -= 4;
    sub_42b075(app, cpu);
L_0x004268f1:
    // 004268f1  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004268f5  e8b4470000             -call 0x42b0ae
    cpu.esp -= 4;
    sub_42b0ae(app, cpu);
    // 004268fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004268fb  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 00426900  ff15c4004300           -call dword ptr [0x4300c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391108) /* 0x4300c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    NFS2_ASSERT(false);  // falls off the end of the routine
}

/* align: skip  */
void Application::asm_sub_426907(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426907  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426908  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426909  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042690d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042690e  0faf742414             -imul esi, dword ptr [esp + 0x14]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00426913  83fee0                 +cmp esi, -0x20
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
    // 00426916  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00426918  770d                   -ja 0x426927
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00426927;
    }
    // 0042691a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042691c  7503                   -jne 0x426921
    if (!cpu.flags.zf)
    {
        goto L_0x00426921;
    }
    // 0042691e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00426920  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00426921:
    // 00426921  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00426924  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
L_0x00426927:
    // 00426927  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00426929  83fee0                 +cmp esi, -0x20
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
    // 0042692c  772a                   -ja 0x426958
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00426958;
    }
    // 0042692e  3b1d7cd24300           +cmp ebx, dword ptr [0x43d27c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4444796) /* 0x43d27c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426934  770d                   -ja 0x426943
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00426943;
    }
    // 00426936  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426937  e8f6040000             -call 0x426e32
    cpu.esp -= 4;
    sub_426e32(app, cpu);
    // 0042693c  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042693e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042693f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00426941  752b                   -jne 0x42696e
    if (!cpu.flags.zf)
    {
        goto L_0x0042696e;
    }
L_0x00426943:
    // 00426943  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426944  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00426946  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 0042694c  ff1588004300           -call dword ptr [0x430088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391048) /* 0x430088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426952  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00426954  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00426956  7522                   -jne 0x42697a
    if (!cpu.flags.zf)
    {
        goto L_0x0042697a;
    }
L_0x00426958:
    // 00426958  833ddc53490000         +cmp dword ptr [0x4953dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805596) /* 0x4953dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042695f  7419                   -je 0x42697a
    if (cpu.flags.zf)
    {
        goto L_0x0042697a;
    }
    // 00426961  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426962  e8760c0000             -call 0x4275dd
    cpu.esp -= 4;
    sub_4275dd(app, cpu);
    // 00426967  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426969  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042696a  7414                   -je 0x426980
    if (cpu.flags.zf)
    {
        goto L_0x00426980;
    }
    // 0042696c  ebb9                   -jmp 0x426927
    goto L_0x00426927;
L_0x0042696e:
    // 0042696e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042696f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426972  e899480000             -call 0x42b210
    cpu.esp -= 4;
    sub_42b210(app, cpu);
    // 00426977  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042697a:
    // 0042697a  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0042697c:
    // 0042697c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042697d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042697e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042697f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00426980:
    // 00426980  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00426982  ebf8                   -jmp 0x42697c
    goto L_0x0042697c;
}

/* align: skip  */
void Application::asm_sub_426984(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426984  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426985  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426986  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426987  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426988  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042698c  3b3d005e4900           +cmp edi, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426992  0f8386000000           -jae 0x426a1e
    if (!cpu.flags.cf)
    {
        goto L_0x00426a1e;
    }
    // 00426998  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042699a  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0042699c  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0042699f  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004269a2  8d1c85005d4900         -lea ebx, [eax*4 + 0x495d00]
    cpu.ebx = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 004269a9  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004269ac  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004269ae  f644300401             +test byte ptr [eax + esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 1 /*0x1*/));
    // 004269b3  7469                   -je 0x426a1e
    if (cpu.flags.zf)
    {
        goto L_0x00426a1e;
    }
    // 004269b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004269b6  e869400000             -call 0x42aa24
    cpu.esp -= 4;
    sub_42aa24(app, cpu);
    // 004269bb  83f8ff                 +cmp eax, -1
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
    // 004269be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004269bf  743c                   -je 0x4269fd
    if (cpu.flags.zf)
    {
        goto L_0x004269fd;
    }
    // 004269c1  83ff01                 +cmp edi, 1
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
    // 004269c4  7405                   -je 0x4269cb
    if (cpu.flags.zf)
    {
        goto L_0x004269cb;
    }
    // 004269c6  83ff02                 +cmp edi, 2
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
    // 004269c9  7516                   -jne 0x4269e1
    if (!cpu.flags.zf)
    {
        goto L_0x004269e1;
    }
L_0x004269cb:
    // 004269cb  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004269cd  e852400000             -call 0x42aa24
    cpu.esp -= 4;
    sub_42aa24(app, cpu);
    // 004269d2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004269d4  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004269d6  e849400000             -call 0x42aa24
    cpu.esp -= 4;
    sub_42aa24(app, cpu);
    // 004269db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004269dc  3bc5                   +cmp eax, ebp
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
    // 004269de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004269df  741c                   -je 0x4269fd
    if (cpu.flags.zf)
    {
        goto L_0x004269fd;
    }
L_0x004269e1:
    // 004269e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004269e2  e83d400000             -call 0x42aa24
    cpu.esp -= 4;
    sub_42aa24(app, cpu);
    // 004269e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004269e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004269e9  ff15ac004300           -call dword ptr [0x4300ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391084) /* 0x4300ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004269ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004269f1  750a                   -jne 0x4269fd
    if (!cpu.flags.zf)
    {
        goto L_0x004269fd;
    }
    // 004269f3  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004269f9  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004269fb  eb02                   -jmp 0x4269ff
    goto L_0x004269ff;
L_0x004269fd:
    // 004269fd  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004269ff:
    // 004269ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426a00  e8a53f0000             -call 0x42a9aa
    cpu.esp -= 4;
    sub_42a9aa(app, cpu);
    // 00426a05  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00426a07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a08  8064300400             -and byte ptr [eax + esi + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00426a0d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00426a0f  7409                   -je 0x426a1a
    if (cpu.flags.zf)
    {
        goto L_0x00426a1a;
    }
    // 00426a11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426a12  e85e3d0000             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 00426a17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a18  eb15                   -jmp 0x426a2f
    goto L_0x00426a2f;
L_0x00426a1a:
    // 00426a1a  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00426a1c  eb14                   -jmp 0x426a32
    goto L_0x00426a32;
L_0x00426a1e:
    // 00426a1e  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00426a25  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
L_0x00426a2f:
    // 00426a2f  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00426a32:
    // 00426a32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_426a37(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426a37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426a38  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00426a3c  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00426a3f  a883                   +test al, 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 131 /*0x83*/));
    // 00426a41  741d                   -je 0x426a60
    if (cpu.flags.zf)
    {
        goto L_0x00426a60;
    }
    // 00426a43  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00426a45  7419                   -je 0x426a60
    if (cpu.flags.zf)
    {
        goto L_0x00426a60;
    }
    // 00426a47  ff7608                 -push dword ptr [esi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00426a4a  e8f7e3ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00426a4f  6681660cf7fb           -and word ptr [esi + 0xc], 0xfbf7
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg16(x86::sreg16(64503 /*0xfbf7*/));
    // 00426a55  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426a57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a58  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00426a5a  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00426a5d  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00426a60:
    // 00426a60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_426a62(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426a62  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426a64  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426a66  39442408               +cmp dword ptr [esp + 8], eax
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
    // 00426a6a  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00426a6f  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00426a72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426a73  ff15cc004300           -call dword ptr [0x4300cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391116) /* 0x4300cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426a79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426a7b  a32c5e4900             -mov dword ptr [0x495e2c], eax
    app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */) = cpu.eax;
    // 00426a80  7415                   -je 0x426a97
    if (cpu.flags.zf)
    {
        goto L_0x00426a97;
    }
    // 00426a82  e817000000             -call 0x426a9e
    cpu.esp -= 4;
    sub_426a9e(app, cpu);
    // 00426a87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426a89  750f                   -jne 0x426a9a
    if (!cpu.flags.zf)
    {
        goto L_0x00426a9a;
    }
    // 00426a8b  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 00426a91  ff15c8004300           -call dword ptr [0x4300c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391112) /* 0x4300c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00426a97:
    // 00426a97  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426a99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00426a9a:
    // 00426a9a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00426a9c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426a9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_426a9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426a9e  6840010000             -push 0x140
    app->getMemory<x86::reg32>(cpu.esp-4) = 320 /*0x140*/;
    cpu.esp -= 4;
    // 00426aa3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426aa5  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 00426aab  ff1588004300           -call dword ptr [0x430088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391048) /* 0x430088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426ab1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426ab3  a3285e4900             -mov dword ptr [0x495e28], eax
    app->getMemory<x86::reg32>(x86::reg32(4808232) /* 0x495e28 */) = cpu.eax;
    // 00426ab8  7501                   -jne 0x426abb
    if (!cpu.flags.zf)
    {
        goto L_0x00426abb;
    }
    // 00426aba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00426abb:
    // 00426abb  8325205e490000         -and dword ptr [0x495e20], 0
    app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00426ac2  8325245e490000         -and dword ptr [0x495e24], 0
    app->getMemory<x86::reg32>(x86::reg32(4808228) /* 0x495e24 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00426ac9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00426acb  a31c5e4900             -mov dword ptr [0x495e1c], eax
    app->getMemory<x86::reg32>(x86::reg32(4808220) /* 0x495e1c */) = cpu.eax;
    // 00426ad0  c705145e490010000000   -mov dword ptr [0x495e14], 0x10
    app->getMemory<x86::reg32>(x86::reg32(4808212) /* 0x495e14 */) = 16 /*0x10*/;
    // 00426ada  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426adb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_426adc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426adc  a1245e4900             -mov eax, dword ptr [0x495e24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808228) /* 0x495e24 */);
    // 00426ae1  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00426ae4  a1285e4900             -mov eax, dword ptr [0x495e28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808232) /* 0x495e28 */);
    // 00426ae9  8d0c88                 -lea ecx, [eax + ecx*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ecx * 4);
L_0x00426aec:
    // 00426aec  3bc1                   +cmp eax, ecx
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
    // 00426aee  7314                   -jae 0x426b04
    if (!cpu.flags.cf)
    {
        goto L_0x00426b04;
    }
    // 00426af0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00426af4  2b500c                 -sub edx, dword ptr [eax + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 00426af7  81fa00001000           +cmp edx, 0x100000
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
    // 00426afd  7207                   -jb 0x426b06
    if (cpu.flags.cf)
    {
        goto L_0x00426b06;
    }
    // 00426aff  83c014                 +add eax, 0x14
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
    // 00426b02  ebe8                   -jmp 0x426aec
    goto L_0x00426aec;
L_0x00426b04:
    // 00426b04  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00426b06:
    // 00426b06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_426b07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426b07  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426b08  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00426b0a  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00426b0d  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426b10  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426b13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426b14  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426b15  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00426b18  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00426b1a  2b710c                 -sub esi, dword ptr [ecx + 0xc]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 00426b1d  8b5afc                 -mov ebx, dword ptr [edx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00426b20  83c2fc                 -add edx, -4
    (cpu.edx) += x86::reg32(x86::sreg32(-4 /*-0x4*/));
    // 00426b23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426b24  c1ee0f                 -shr esi, 0xf
    cpu.esi >>= 15 /*0xf*/ % 32;
    // 00426b27  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00426b29  8b7afc                 -mov edi, dword ptr [edx - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00426b2c  69c904020000           -imul ecx, ecx, 0x204
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 00426b32  4b                     -dec ebx
    (cpu.ebx)--;
    // 00426b33  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00426b36  8d8c0144010000         -lea ecx, [ecx + eax + 0x144]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(324) /* 0x144 */ + cpu.eax * 1);
    // 00426b3d  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00426b40  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 00426b43  8b0c13                 -mov ecx, dword ptr [ebx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.edx * 1);
    // 00426b46  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00426b49  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00426b4c  757f                   -jne 0x426bcd
    if (!cpu.flags.zf)
    {
        goto L_0x00426bcd;
    }
    // 00426b4e  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00426b51  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 00426b53  49                     -dec ecx
    (cpu.ecx)--;
    // 00426b54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426b55  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00426b58  3bcf                   +cmp ecx, edi
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
    // 00426b5a  7603                   -jbe 0x426b5f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00426b5f;
    }
    // 00426b5c  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x00426b5f:
    // 00426b5f  8b4c1304               -mov ecx, dword ptr [ebx + edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 00426b63  3b4c1308               +cmp ecx, dword ptr [ebx + edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edx * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426b67  7548                   -jne 0x426bb1
    if (!cpu.flags.zf)
    {
        goto L_0x00426bb1;
    }
    // 00426b69  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426b6c  83f920                 +cmp ecx, 0x20
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
    // 00426b6f  731c                   -jae 0x426b8d
    if (!cpu.flags.cf)
    {
        goto L_0x00426b8d;
    }
    // 00426b71  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 00426b76  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 00426b78  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00426b7c  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00426b7e  217cb044               +and dword ptr [eax + esi*4 + 0x44], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(cpu.edi))));
    // 00426b82  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00426b84  752b                   -jne 0x426bb1
    if (!cpu.flags.zf)
    {
        goto L_0x00426bb1;
    }
    // 00426b86  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426b89  2139                   +and dword ptr [ecx], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.edi))));
    // 00426b8b  eb24                   -jmp 0x426bb1
    goto L_0x00426bb1;
L_0x00426b8d:
    // 00426b8d  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 00426b90  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 00426b95  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 00426b97  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426b9a  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00426b9e  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00426ba0  21bcb0c4000000         +and dword ptr [eax + esi*4 + 0xc4], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(cpu.edi))));
    // 00426ba7  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00426ba9  7506                   -jne 0x426bb1
    if (!cpu.flags.zf)
    {
        goto L_0x00426bb1;
    }
    // 00426bab  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426bae  217904                 -and dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.edi));
L_0x00426bb1:
    // 00426bb1  8b4c1308               -mov ecx, dword ptr [ebx + edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edx * 1);
    // 00426bb5  8b7c1304               -mov edi, dword ptr [ebx + edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 00426bb9  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00426bbc  8b4c1304               -mov ecx, dword ptr [ebx + edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 00426bc0  8b7c1308               -mov edi, dword ptr [ebx + edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edx * 1);
    // 00426bc4  035df8                 -add ebx, dword ptr [ebp - 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00426bc7  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00426bca  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00426bcd:
    // 00426bcd  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00426bcf  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00426bd2  4f                     -dec edi
    (cpu.edi)--;
    // 00426bd3  83ff3f                 +cmp edi, 0x3f
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
    // 00426bd6  7603                   -jbe 0x426bdb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00426bdb;
    }
    // 00426bd8  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 00426bda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00426bdb:
    // 00426bdb  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00426bde  83e101                 +and ecx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 00426be1  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 00426be4  0f85a0000000           -jne 0x426c8a
    if (!cpu.flags.zf)
    {
        goto L_0x00426c8a;
    }
    // 00426bea  2b55fc                 -sub edx, dword ptr [ebp - 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00426bed  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00426bf0  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00426bf3  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 00426bf5  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00426bf8  49                     -dec ecx
    (cpu.ecx)--;
    // 00426bf9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426bfa  3bca                   +cmp ecx, edx
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
    // 00426bfc  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00426bff  7605                   -jbe 0x426c06
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00426c06;
    }
    // 00426c01  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00426c04  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00426c06:
    // 00426c06  035dfc                 -add ebx, dword ptr [ebp - 4]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00426c09  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00426c0b  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00426c0e  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00426c11  4f                     -dec edi
    (cpu.edi)--;
    // 00426c12  3bfa                   +cmp edi, edx
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
    // 00426c14  7602                   -jbe 0x426c18
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00426c18;
    }
    // 00426c16  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x00426c18:
    // 00426c18  3bcf                   +cmp ecx, edi
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
    // 00426c1a  746b                   -je 0x426c87
    if (cpu.flags.zf)
    {
        goto L_0x00426c87;
    }
    // 00426c1c  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00426c1f  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00426c22  3b5108                 +cmp edx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426c25  7548                   -jne 0x426c6f
    if (!cpu.flags.zf)
    {
        goto L_0x00426c6f;
    }
    // 00426c27  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426c2a  83f920                 +cmp ecx, 0x20
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
    // 00426c2d  731c                   -jae 0x426c4b
    if (!cpu.flags.cf)
    {
        goto L_0x00426c4b;
    }
    // 00426c2f  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 00426c34  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00426c36  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00426c3a  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00426c3c  2154b044               +and dword ptr [eax + esi*4 + 0x44], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00426c40  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00426c42  752b                   -jne 0x426c6f
    if (!cpu.flags.zf)
    {
        goto L_0x00426c6f;
    }
    // 00426c44  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426c47  2111                   +and dword ptr [ecx], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00426c49  eb24                   -jmp 0x426c6f
    goto L_0x00426c6f;
L_0x00426c4b:
    // 00426c4b  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 00426c4e  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 00426c53  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00426c55  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00426c58  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00426c5c  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00426c5e  2194b0c4000000         +and dword ptr [eax + esi*4 + 0xc4], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00426c65  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00426c67  7506                   -jne 0x426c6f
    if (!cpu.flags.zf)
    {
        goto L_0x00426c6f;
    }
    // 00426c69  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426c6c  215104                 -and dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.edx));
L_0x00426c6f:
    // 00426c6f  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00426c72  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00426c75  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00426c78  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00426c7b  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00426c7e  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00426c81  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00426c84  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x00426c87:
    // 00426c87  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x00426c8a:
    // 00426c8a  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 00426c8e  7509                   -jne 0x426c99
    if (!cpu.flags.zf)
    {
        goto L_0x00426c99;
    }
    // 00426c90  397d0c                 +cmp dword ptr [ebp + 0xc], edi
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
    // 00426c93  0f8489000000           -je 0x426d22
    if (cpu.flags.zf)
    {
        goto L_0x00426d22;
    }
L_0x00426c99:
    // 00426c99  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00426c9c  8d0cf9                 -lea ecx, [ecx + edi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.edi * 8);
    // 00426c9f  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00426ca2  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00426ca5  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00426ca8  8d0cf9                 -lea ecx, [ecx + edi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.edi * 8);
    // 00426cab  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00426cae  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00426cb1  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00426cb4  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00426cb7  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00426cba  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 00426cbd  7563                   -jne 0x426d22
    if (!cpu.flags.zf)
    {
        goto L_0x00426d22;
    }
    // 00426cbf  8a4c0704               -mov cl, byte ptr [edi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00426cc3  83ff20                 +cmp edi, 0x20
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
    // 00426cc6  884d0f                 -mov byte ptr [ebp + 0xf], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */) = cpu.cl;
    // 00426cc9  fec1                   +inc cl
    {
        x86::reg8& tmp = cpu.cl;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00426ccb  884c0704               -mov byte ptr [edi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 00426ccf  7325                   -jae 0x426cf6
    if (!cpu.flags.cf)
    {
        goto L_0x00426cf6;
    }
    // 00426cd1  807d0f00               +cmp byte ptr [ebp + 0xf], 0
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
    // 00426cd5  750e                   -jne 0x426ce5
    if (!cpu.flags.zf)
    {
        goto L_0x00426ce5;
    }
    // 00426cd7  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00426cdc  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00426cde  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00426ce0  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426ce3  0919                   -or dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00426ce5:
    // 00426ce5  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00426cea  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00426cec  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00426cee  8d44b044               -lea eax, [eax + esi*4 + 0x44]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.esi * 4);
    // 00426cf2  0918                   +or dword ptr [eax], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00426cf4  eb29                   -jmp 0x426d1f
    goto L_0x00426d1f;
L_0x00426cf6:
    // 00426cf6  807d0f00               +cmp byte ptr [ebp + 0xf], 0
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
    // 00426cfa  7510                   -jne 0x426d0c
    if (!cpu.flags.zf)
    {
        goto L_0x00426d0c;
    }
    // 00426cfc  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 00426cff  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00426d04  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00426d06  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426d09  095904                 -or dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00426d0c:
    // 00426d0c  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 00426d0f  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 00426d14  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 00426d16  8d84b0c4000000         -lea eax, [eax + esi*4 + 0xc4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.esi * 4);
    // 00426d1d  0938                   +or dword ptr [eax], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edi))));
L_0x00426d1f:
    // 00426d1f  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x00426d22:
    // 00426d22  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00426d25  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00426d27  895c13fc               -mov dword ptr [ebx + edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */ + cpu.edx * 1) = cpu.ebx;
    // 00426d2b  ff08                   +dec dword ptr [eax]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.eax);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00426d2d  0f85fa000000           -jne 0x426e2d
    if (!cpu.flags.zf)
    {
        goto L_0x00426e2d;
    }
    // 00426d33  a1205e4900             -mov eax, dword ptr [0x495e20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */);
    // 00426d38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426d3a  0f84df000000           -je 0x426e1f
    if (cpu.flags.zf)
    {
        goto L_0x00426e1f;
    }
    // 00426d40  8b0d185e4900           -mov ecx, dword ptr [0x495e18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4808216) /* 0x495e18 */);
    // 00426d46  8b3d38004300           -mov edi, dword ptr [0x430038]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4390968) /* 0x430038 */);
    // 00426d4c  c1e10f                 -shl ecx, 0xf
    cpu.ecx <<= 15 /*0xf*/ % 32;
    // 00426d4f  03480c                 -add ecx, dword ptr [eax + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 00426d52  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 00426d57  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 00426d5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426d5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426d5e  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426d60  8b0d185e4900           -mov ecx, dword ptr [0x495e18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4808216) /* 0x495e18 */);
    // 00426d66  a1205e4900             -mov eax, dword ptr [0x495e20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */);
    // 00426d6b  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 00426d70  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00426d72  095008                 -or dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) |= x86::reg32(x86::sreg32(cpu.edx));
    // 00426d75  a1205e4900             -mov eax, dword ptr [0x495e20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */);
    // 00426d7a  8b0d185e4900           -mov ecx, dword ptr [0x495e18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4808216) /* 0x495e18 */);
    // 00426d80  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00426d83  83a488c400000000       -and dword ptr [eax + ecx*4 + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00426d8b  a1205e4900             -mov eax, dword ptr [0x495e20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */);
    // 00426d90  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00426d93  fe4843                 -dec byte ptr [eax + 0x43]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(67) /* 0x43 */))--;
    // 00426d96  a1205e4900             -mov eax, dword ptr [0x495e20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */);
    // 00426d9b  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00426d9e  80794300               +cmp byte ptr [ecx + 0x43], 0
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
    // 00426da2  7509                   -jne 0x426dad
    if (!cpu.flags.zf)
    {
        goto L_0x00426dad;
    }
    // 00426da4  836004fe               -and dword ptr [eax + 4], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 00426da8  a1205e4900             -mov eax, dword ptr [0x495e20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */);
L_0x00426dad:
    // 00426dad  837808ff               +cmp dword ptr [eax + 8], -1
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
    // 00426db1  756c                   -jne 0x426e1f
    if (!cpu.flags.zf)
    {
        goto L_0x00426e1f;
    }
    // 00426db3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426db4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426db6  ff700c                 -push dword ptr [eax + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00426db9  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426dbb  a1205e4900             -mov eax, dword ptr [0x495e20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */);
    // 00426dc0  ff7010                 -push dword ptr [eax + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00426dc3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426dc5  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 00426dcb  ff1584004300           -call dword ptr [0x430084]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391044) /* 0x430084 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426dd1  a1245e4900             -mov eax, dword ptr [0x495e24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808228) /* 0x495e24 */);
    // 00426dd6  8b15285e4900           -mov edx, dword ptr [0x495e28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4808232) /* 0x495e28 */);
    // 00426ddc  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00426ddf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00426de2  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00426de4  a1205e4900             -mov eax, dword ptr [0x495e20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */);
    // 00426de9  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00426deb  8d4c11ec               -lea ecx, [ecx + edx - 0x14]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-20) /* -0x14 */ + cpu.edx * 1);
    // 00426def  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426df0  8d4814                 -lea ecx, [eax + 0x14]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00426df3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426df4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426df5  e876440000             -call 0x42b270
    cpu.esp -= 4;
    sub_42b270(app, cpu);
    // 00426dfa  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426dfd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00426e00  ff0d245e4900           -dec dword ptr [0x495e24]
    (app->getMemory<x86::reg32>(x86::reg32(4808228) /* 0x495e24 */))--;
    // 00426e06  3b05205e4900           +cmp eax, dword ptr [0x495e20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426e0c  7603                   -jbe 0x426e11
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00426e11;
    }
    // 00426e0e  83e814                 +sub eax, 0x14
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00426e11:
    // 00426e11  8b0d285e4900           -mov ecx, dword ptr [0x495e28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4808232) /* 0x495e28 */);
    // 00426e17  890d1c5e4900           -mov dword ptr [0x495e1c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4808220) /* 0x495e1c */) = cpu.ecx;
    // 00426e1d  eb03                   -jmp 0x426e22
    goto L_0x00426e22;
L_0x00426e1f:
    // 00426e1f  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00426e22:
    // 00426e22  a3205e4900             -mov dword ptr [0x495e20], eax
    app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */) = cpu.eax;
    // 00426e27  8935185e4900           -mov dword ptr [0x495e18], esi
    app->getMemory<x86::reg32>(x86::reg32(4808216) /* 0x495e18 */) = cpu.esi;
L_0x00426e2d:
    // 00426e2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426e2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426e2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426e30  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426e31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_426e32(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426e32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00426e33  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00426e35  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00426e38  a1245e4900             -mov eax, dword ptr [0x495e24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808228) /* 0x495e24 */);
    // 00426e3d  8b15285e4900           -mov edx, dword ptr [0x495e28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4808232) /* 0x495e28 */);
    // 00426e43  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426e44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00426e45  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00426e48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426e49  8d3c82                 -lea edi, [edx + eax*4]
    cpu.edi = x86::reg32(cpu.edx + cpu.eax * 4);
    // 00426e4c  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00426e4f  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00426e52  8d4817                 -lea ecx, [eax + 0x17]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 00426e55  83e1f0                 -and ecx, 0xfffffff0
    cpu.ecx &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 00426e58  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 00426e5b  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00426e5e  49                     -dec ecx
    (cpu.ecx)--;
    // 00426e5f  83f920                 +cmp ecx, 0x20
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
    // 00426e62  7d0e                   -jge 0x426e72
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00426e72;
    }
    // 00426e64  83ceff                 -or esi, 0xffffffff
    cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00426e67  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 00426e69  834df8ff               +or dword ptr [ebp - 8], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00426e6d  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00426e70  eb10                   -jmp 0x426e82
    goto L_0x00426e82;
L_0x00426e72:
    // 00426e72  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 00426e75  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00426e78  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00426e7a  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00426e7c  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00426e7f  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00426e82:
    // 00426e82  a11c5e4900             -mov eax, dword ptr [0x495e1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808220) /* 0x495e1c */);
    // 00426e87  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00426e89  3bdf                   +cmp ebx, edi
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
    // 00426e8b  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00426e8e  7319                   -jae 0x426ea9
    if (!cpu.flags.cf)
    {
        goto L_0x00426ea9;
    }
L_0x00426e90:
    // 00426e90  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00426e93  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00426e95  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00426e98  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 00426e9a  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00426e9c  750b                   -jne 0x426ea9
    if (!cpu.flags.zf)
    {
        goto L_0x00426ea9;
    }
    // 00426e9e  83c314                 -add ebx, 0x14
    (cpu.ebx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00426ea1  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
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
    // 00426ea4  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00426ea7  72e7                   -jb 0x426e90
    if (cpu.flags.cf)
    {
        goto L_0x00426e90;
    }
L_0x00426ea9:
    // 00426ea9  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
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
    // 00426eac  7579                   -jne 0x426f27
    if (!cpu.flags.zf)
    {
        goto L_0x00426f27;
    }
    // 00426eae  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00426eb0:
    // 00426eb0  3bd8                   +cmp ebx, eax
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
    // 00426eb2  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00426eb5  7315                   -jae 0x426ecc
    if (!cpu.flags.cf)
    {
        goto L_0x00426ecc;
    }
    // 00426eb7  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00426eba  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00426ebc  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00426ebf  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 00426ec1  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00426ec3  7505                   -jne 0x426eca
    if (!cpu.flags.zf)
    {
        goto L_0x00426eca;
    }
    // 00426ec5  83c314                 +add ebx, 0x14
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
    // 00426ec8  ebe6                   -jmp 0x426eb0
    goto L_0x00426eb0;
L_0x00426eca:
    // 00426eca  3bd8                   +cmp ebx, eax
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
L_0x00426ecc:
    // 00426ecc  7559                   -jne 0x426f27
    if (!cpu.flags.zf)
    {
        goto L_0x00426f27;
    }
L_0x00426ece:
    // 00426ece  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
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
    // 00426ed1  7311                   -jae 0x426ee4
    if (!cpu.flags.cf)
    {
        goto L_0x00426ee4;
    }
    // 00426ed3  837b0800               +cmp dword ptr [ebx + 8], 0
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
    // 00426ed7  7508                   -jne 0x426ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00426ee1;
    }
    // 00426ed9  83c314                 +add ebx, 0x14
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
    // 00426edc  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00426edf  ebed                   -jmp 0x426ece
    goto L_0x00426ece;
L_0x00426ee1:
    // 00426ee1  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
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
L_0x00426ee4:
    // 00426ee4  7526                   -jne 0x426f0c
    if (!cpu.flags.zf)
    {
        goto L_0x00426f0c;
    }
    // 00426ee6  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00426ee8:
    // 00426ee8  3bd8                   +cmp ebx, eax
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
    // 00426eea  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00426eed  730d                   -jae 0x426efc
    if (!cpu.flags.cf)
    {
        goto L_0x00426efc;
    }
    // 00426eef  837b0800               +cmp dword ptr [ebx + 8], 0
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
    // 00426ef3  7505                   -jne 0x426efa
    if (!cpu.flags.zf)
    {
        goto L_0x00426efa;
    }
    // 00426ef5  83c314                 +add ebx, 0x14
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
    // 00426ef8  ebee                   -jmp 0x426ee8
    goto L_0x00426ee8;
L_0x00426efa:
    // 00426efa  3bd8                   +cmp ebx, eax
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
L_0x00426efc:
    // 00426efc  750e                   -jne 0x426f0c
    if (!cpu.flags.zf)
    {
        goto L_0x00426f0c;
    }
    // 00426efe  e838020000             -call 0x42713b
    cpu.esp -= 4;
    sub_42713b(app, cpu);
    // 00426f03  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00426f05  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00426f07  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00426f0a  7414                   -je 0x426f20
    if (cpu.flags.zf)
    {
        goto L_0x00426f20;
    }
L_0x00426f0c:
    // 00426f0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426f0d  e8da020000             -call 0x4271ec
    cpu.esp -= 4;
    sub_4271ec(app, cpu);
    // 00426f12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426f13  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00426f16  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00426f18  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00426f1b  8338ff                 +cmp dword ptr [eax], -1
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
    // 00426f1e  7507                   -jne 0x426f27
    if (!cpu.flags.zf)
    {
        goto L_0x00426f27;
    }
L_0x00426f20:
    // 00426f20  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00426f22  e90f020000             -jmp 0x427136
    goto L_0x00427136;
L_0x00426f27:
    // 00426f27  891d1c5e4900           -mov dword ptr [0x495e1c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4808220) /* 0x495e1c */) = cpu.ebx;
    // 00426f2d  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00426f30  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00426f32  83faff                 +cmp edx, -1
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
    // 00426f35  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00426f38  7414                   -je 0x426f4e
    if (cpu.flags.zf)
    {
        goto L_0x00426f4e;
    }
    // 00426f3a  8b8c90c4000000         -mov ecx, dword ptr [eax + edx*4 + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 00426f41  8b7c9044               -mov edi, dword ptr [eax + edx*4 + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 00426f45  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00426f48  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 00426f4a  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00426f4c  7537                   -jne 0x426f85
    if (!cpu.flags.zf)
    {
        goto L_0x00426f85;
    }
L_0x00426f4e:
    // 00426f4e  8b90c4000000           -mov edx, dword ptr [eax + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 00426f54  8b7044                 -mov esi, dword ptr [eax + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00426f57  2355f8                 -and edx, dword ptr [ebp - 8]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00426f5a  2375f4                 -and esi, dword ptr [ebp - 0xc]
    cpu.esi &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00426f5d  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00426f61  8d4844                 -lea ecx, [eax + 0x44]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00426f64  0bd6                   +or edx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.esi))));
    // 00426f66  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00426f69  7517                   -jne 0x426f82
    if (!cpu.flags.zf)
    {
        goto L_0x00426f82;
    }
L_0x00426f6b:
    // 00426f6b  8b9184000000           -mov edx, dword ptr [ecx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 00426f71  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00426f74  2355f8                 -and edx, dword ptr [ebp - 8]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00426f77  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00426f7a  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00426f7c  2339                   -and edi, dword ptr [ecx]
    cpu.edi &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 00426f7e  0bd7                   +or edx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00426f80  74e9                   -je 0x426f6b
    if (cpu.flags.zf)
    {
        goto L_0x00426f6b;
    }
L_0x00426f82:
    // 00426f82  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00426f85:
    // 00426f85  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00426f87  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00426f89  69c904020000           -imul ecx, ecx, 0x204
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 00426f8f  8d8c0144010000         -lea ecx, [ecx + eax + 0x144]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(324) /* 0x144 */ + cpu.eax * 1);
    // 00426f96  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00426f99  8b4c9044               -mov ecx, dword ptr [eax + edx*4 + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 00426f9d  23ce                   +and ecx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.esi))));
    // 00426f9f  750d                   -jne 0x426fae
    if (!cpu.flags.zf)
    {
        goto L_0x00426fae;
    }
    // 00426fa1  8b8c90c4000000         -mov ecx, dword ptr [eax + edx*4 + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 00426fa8  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00426faa  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00426fad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00426fae:
    // 00426fae  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00426fb0  7c05                   -jl 0x426fb7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00426fb7;
    }
    // 00426fb2  d1e1                   +shl ecx, 1
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
    // 00426fb4  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00426fb5  ebf7                   -jmp 0x426fae
    goto L_0x00426fae;
L_0x00426fb7:
    // 00426fb7  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00426fba  8b54f904               -mov edx, dword ptr [ecx + edi*8 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 00426fbe  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00426fc0  2b4df0                 -sub ecx, dword ptr [ebp - 0x10]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00426fc3  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00426fc5  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00426fc8  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00426fcb  4e                     -dec esi
    (cpu.esi)--;
    // 00426fcc  83fe3f                 +cmp esi, 0x3f
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
    // 00426fcf  7e03                   -jle 0x426fd4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00426fd4;
    }
    // 00426fd1  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 00426fd3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00426fd4:
    // 00426fd4  3bf7                   +cmp esi, edi
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
    // 00426fd6  0f840d010000           -je 0x4270e9
    if (cpu.flags.zf)
    {
        goto L_0x004270e9;
    }
    // 00426fdc  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00426fdf  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 00426fe2  7561                   -jne 0x427045
    if (!cpu.flags.zf)
    {
        goto L_0x00427045;
    }
    // 00426fe4  83ff20                 +cmp edi, 0x20
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
    // 00426fe7  7d2b                   -jge 0x427014
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00427014;
    }
    // 00426fe9  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00426fee  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00426ff0  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00426ff2  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00426ff5  8d7c3804               -lea edi, [eax + edi + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1);
    // 00426ff9  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00426ffb  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00426ffe  235c8844               +and ebx, dword ptr [eax + ecx*4 + 0x44]
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4)))));
    // 00427002  895c8844               -mov dword ptr [eax + ecx*4 + 0x44], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4) = cpu.ebx;
    // 00427006  fe0f                   +dec byte ptr [edi]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.edi);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00427008  7538                   -jne 0x427042
    if (!cpu.flags.zf)
    {
        goto L_0x00427042;
    }
    // 0042700a  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042700d  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00427010  210b                   +and dword ptr [ebx], ecx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebx) &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00427012  eb31                   -jmp 0x427045
    goto L_0x00427045;
L_0x00427014:
    // 00427014  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 00427017  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0042701c  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0042701e  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00427021  8d7c3804               -lea edi, [eax + edi + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1);
    // 00427025  8d8c88c4000000         -lea ecx, [eax + ecx*4 + 0xc4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4);
    // 0042702c  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0042702e  2119                   +and dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00427030  fe0f                   +dec byte ptr [edi]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.edi);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00427032  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00427035  750b                   -jne 0x427042
    if (!cpu.flags.zf)
    {
        goto L_0x00427042;
    }
    // 00427037  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042703a  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0042703d  214b04                 +and dword ptr [ebx + 4], ecx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00427040  eb03                   -jmp 0x427045
    goto L_0x00427045;
L_0x00427042:
    // 00427042  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00427045:
    // 00427045  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00427048  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0042704b  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 0042704f  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00427052  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00427055  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00427058  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0042705b  0f8494000000           -je 0x4270f5
    if (cpu.flags.zf)
    {
        goto L_0x004270f5;
    }
    // 00427061  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00427064  8b7cf104               -mov edi, dword ptr [ecx + esi*8 + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 00427068  8d0cf1                 -lea ecx, [ecx + esi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.esi * 8);
    // 0042706b  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0042706e  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00427071  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00427074  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00427077  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042707a  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0042707d  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 00427080  7564                   -jne 0x4270e6
    if (!cpu.flags.zf)
    {
        goto L_0x004270e6;
    }
    // 00427082  8a4c0604               -mov cl, byte ptr [esi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00427086  83fe20                 +cmp esi, 0x20
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
    // 00427089  884d0b                 -mov byte ptr [ebp + 0xb], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) = cpu.cl;
    // 0042708c  7d29                   -jge 0x4270b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004270b7;
    }
    // 0042708e  fec1                   -inc cl
    (cpu.cl)++;
    // 00427090  807d0b00               +cmp byte ptr [ebp + 0xb], 0
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
    // 00427094  884c0604               -mov byte ptr [esi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 00427098  750b                   -jne 0x4270a5
    if (!cpu.flags.zf)
    {
        goto L_0x004270a5;
    }
    // 0042709a  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 0042709f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004270a1  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 004270a3  093b                   -or dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x004270a5:
    // 004270a5  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 004270aa  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004270ac  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 004270ae  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004270b1  097c8844               +or dword ptr [eax + ecx*4 + 0x44], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4) |= x86::reg32(x86::sreg32(cpu.edi))));
    // 004270b5  eb2f                   -jmp 0x4270e6
    goto L_0x004270e6;
L_0x004270b7:
    // 004270b7  fec1                   -inc cl
    (cpu.cl)++;
    // 004270b9  807d0b00               +cmp byte ptr [ebp + 0xb], 0
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
    // 004270bd  884c0604               -mov byte ptr [esi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 004270c1  750d                   -jne 0x4270d0
    if (!cpu.flags.zf)
    {
        goto L_0x004270d0;
    }
    // 004270c3  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 004270c6  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 004270cb  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 004270cd  097b04                 -or dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x004270d0:
    // 004270d0  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004270d3  8dbc88c4000000         -lea edi, [eax + ecx*4 + 0xc4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4);
    // 004270da  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 004270dd  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 004270e2  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 004270e4  0937                   -or dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) |= x86::reg32(x86::sreg32(cpu.esi));
L_0x004270e6:
    // 004270e6  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x004270e9:
    // 004270e9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004270eb  740b                   -je 0x4270f8
    if (cpu.flags.zf)
    {
        goto L_0x004270f8;
    }
    // 004270ed  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004270ef  894c11fc               -mov dword ptr [ecx + edx - 4], ecx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edx * 1) = cpu.ecx;
    // 004270f3  eb03                   -jmp 0x4270f8
    goto L_0x004270f8;
L_0x004270f5:
    // 004270f5  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x004270f8:
    // 004270f8  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004270fb  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004270fd  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00427100  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00427102  894c32fc               -mov dword ptr [edx + esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1) = cpu.ecx;
    // 00427106  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00427109  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042710b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042710d  8d7901                 -lea edi, [ecx + 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00427110  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00427112  751a                   -jne 0x42712e
    if (!cpu.flags.zf)
    {
        goto L_0x0042712e;
    }
    // 00427114  3b1d205e4900           +cmp ebx, dword ptr [0x495e20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042711a  7512                   -jne 0x42712e
    if (!cpu.flags.zf)
    {
        goto L_0x0042712e;
    }
    // 0042711c  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042711f  3b0d185e4900           +cmp ecx, dword ptr [0x495e18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808216) /* 0x495e18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427125  7507                   -jne 0x42712e
    if (!cpu.flags.zf)
    {
        goto L_0x0042712e;
    }
    // 00427127  8325205e490000         -and dword ptr [0x495e20], 0
    app->getMemory<x86::reg32>(x86::reg32(4808224) /* 0x495e20 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042712e:
    // 0042712e  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00427131  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00427133  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
L_0x00427136:
    // 00427136  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427137  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427138  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427139  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042713a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42713b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042713b  a1245e4900             -mov eax, dword ptr [0x495e24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808228) /* 0x495e24 */);
    // 00427140  8b0d145e4900           -mov ecx, dword ptr [0x495e14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4808212) /* 0x495e14 */);
    // 00427146  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427147  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427148  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042714a  3bc1                   +cmp eax, ecx
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
    // 0042714c  7530                   -jne 0x42717e
    if (!cpu.flags.zf)
    {
        goto L_0x0042717e;
    }
    // 0042714e  8d448950               -lea eax, [ecx + ecx*4 + 0x50]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(80) /* 0x50 */ + cpu.ecx * 4);
    // 00427152  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00427155  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00427156  ff35285e4900           -push dword ptr [0x495e28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808232) /* 0x495e28 */);
    cpu.esp -= 4;
    // 0042715c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042715d  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 00427163  ff15b4004300           -call dword ptr [0x4300b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391092) /* 0x4300b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00427169  3bc7                   +cmp eax, edi
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
    // 0042716b  7461                   -je 0x4271ce
    if (cpu.flags.zf)
    {
        goto L_0x004271ce;
    }
    // 0042716d  8305145e490010         -add dword ptr [0x495e14], 0x10
    (app->getMemory<x86::reg32>(x86::reg32(4808212) /* 0x495e14 */)) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00427174  a3285e4900             -mov dword ptr [0x495e28], eax
    app->getMemory<x86::reg32>(x86::reg32(4808232) /* 0x495e28 */) = cpu.eax;
    // 00427179  a1245e4900             -mov eax, dword ptr [0x495e24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808228) /* 0x495e24 */);
L_0x0042717e:
    // 0042717e  8b0d285e4900           -mov ecx, dword ptr [0x495e28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4808232) /* 0x495e28 */);
    // 00427184  68c4410000             -push 0x41c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 16836 /*0x41c4*/;
    cpu.esp -= 4;
    // 00427189  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042718b  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042718e  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 00427194  8d3481                 -lea esi, [ecx + eax*4]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 00427197  ff1588004300           -call dword ptr [0x430088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391048) /* 0x430088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042719d  3bc7                   +cmp eax, edi
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
    // 0042719f  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004271a2  742a                   -je 0x4271ce
    if (cpu.flags.zf)
    {
        goto L_0x004271ce;
    }
    // 004271a4  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004271a6  6800200000             -push 0x2000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 004271ab  6800001000             -push 0x100000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576 /*0x100000*/;
    cpu.esp -= 4;
    // 004271b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004271b1  ff1534004300           -call dword ptr [0x430034]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390964) /* 0x430034 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004271b7  3bc7                   +cmp eax, edi
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
    // 004271b9  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004271bc  7514                   -jne 0x4271d2
    if (!cpu.flags.zf)
    {
        goto L_0x004271d2;
    }
    // 004271be  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004271c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004271c2  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 004271c8  ff1584004300           -call dword ptr [0x430084]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391044) /* 0x430084 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004271ce:
    // 004271ce  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004271d0  eb17                   -jmp 0x4271e9
    goto L_0x004271e9;
L_0x004271d2:
    // 004271d2  834e08ff               -or dword ptr [esi + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004271d6  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004271d8  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004271db  ff05245e4900           -inc dword ptr [0x495e24]
    (app->getMemory<x86::reg32>(x86::reg32(4808228) /* 0x495e24 */))++;
    // 004271e1  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004271e4  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004271e7  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004271e9:
    // 004271e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004271ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004271eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4271ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004271ec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004271ed  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004271ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004271f0  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004271f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004271f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004271f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004271f6  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004271f9  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004271fc  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004271fe:
    // 004271fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427200  7c05                   -jl 0x427207
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427207;
    }
    // 00427202  d1e0                   +shl eax, 1
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
    // 00427204  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00427205  ebf7                   -jmp 0x4271fe
    goto L_0x004271fe;
L_0x00427207:
    // 00427207  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00427209  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0042720b  69c004020000           -imul eax, eax, 0x204
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 00427211  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427212  8d843044010000         -lea eax, [eax + esi + 0x144]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(324) /* 0x144 */ + cpu.esi * 1);
    // 00427219  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0042721c:
    // 0042721c  894008                 -mov dword ptr [eax + 8], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042721f  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00427222  83c008                 +add eax, 8
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
    // 00427225  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00427226  75f4                   -jne 0x42721c
    if (!cpu.flags.zf)
    {
        goto L_0x0042721c;
    }
    // 00427228  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0042722a  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042722c  c1e70f                 -shl edi, 0xf
    cpu.edi <<= 15 /*0xf*/ % 32;
    // 0042722f  03790c                 -add edi, dword ptr [ecx + 0xc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 00427232  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00427237  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 0042723c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042723d  ff1534004300           -call dword ptr [0x430034]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390964) /* 0x430034 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00427243  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427245  7508                   -jne 0x42724f
    if (!cpu.flags.zf)
    {
        goto L_0x0042724f;
    }
    // 00427247  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042724a  e993000000             -jmp 0x4272e2
    goto L_0x004272e2;
L_0x0042724f:
    // 0042724f  8d9700700000           -lea edx, [edi + 0x7000]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(28672) /* 0x7000 */);
    // 00427255  3bfa                   +cmp edi, edx
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
    // 00427257  773c                   -ja 0x427295
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00427295;
    }
    // 00427259  8d4710                 -lea eax, [edi + 0x10]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
L_0x0042725c:
    // 0042725c  8348f8ff               -or dword ptr [eax - 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00427260  8388ec0f0000ff         -or dword ptr [eax + 0xfec], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4076) /* 0xfec */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00427267  8d88fc0f0000           -lea ecx, [eax + 0xffc]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4092) /* 0xffc */);
    // 0042726d  c740fcf00f0000         -mov dword ptr [eax - 4], 0xff0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = 4080 /*0xff0*/;
    // 00427274  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00427276  8d88fcefffff           -lea ecx, [eax - 0x1004]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4100) /* -0x1004 */);
    // 0042727c  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0042727f  c780e80f0000f00f0000   -mov dword ptr [eax + 0xfe8], 0xff0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4072) /* 0xfe8 */) = 4080 /*0xff0*/;
    // 00427289  0500100000             -add eax, 0x1000
    (cpu.eax) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0042728e  8d48f0                 -lea ecx, [eax - 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 00427291  3bca                   +cmp ecx, edx
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
    // 00427293  76c7                   -jbe 0x42725c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042725c;
    }
L_0x00427295:
    // 00427295  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00427298  8d4f0c                 -lea ecx, [edi + 0xc]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0042729b  05f8010000             -add eax, 0x1f8
    (cpu.eax) += x86::reg32(x86::sreg32(504 /*0x1f8*/));
    // 004272a0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004272a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004272a3  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004272a6  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004272a9  8d4a0c                 -lea ecx, [edx + 0xc]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004272ac  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004272af  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004272b2  83649e4400             -and dword ptr [esi + ebx*4 + 0x44], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */ + cpu.ebx * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004272b7  89bc9ec4000000         -mov dword ptr [esi + ebx*4 + 0xc4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */ + cpu.ebx * 4) = cpu.edi;
    // 004272be  8a4643                 -mov al, byte ptr [esi + 0x43]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(67) /* 0x43 */);
    // 004272c1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004272c3  fec1                   -inc cl
    (cpu.cl)++;
    // 004272c5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004272c7  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004272ca  884e43                 -mov byte ptr [esi + 0x43], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(67) /* 0x43 */) = cpu.cl;
    // 004272cd  7503                   -jne 0x4272d2
    if (!cpu.flags.zf)
    {
        goto L_0x004272d2;
    }
    // 004272cf  097804                 -or dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x004272d2:
    // 004272d2  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 004272d7  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004272d9  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004272db  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 004272dd  215008                 -and dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(cpu.edx));
    // 004272e0  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004272e2:
    // 004272e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004272e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004272e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004272e5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004272e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4272e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004272e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004272e8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004272ea  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004272ed  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004272f0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004272f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004272f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004272f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004272f6  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004272f9  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004272fb  8d7017                 -lea esi, [eax + 0x17]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004272fe  2b510c                 -sub edx, dword ptr [ecx + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 00427301  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00427304  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 00427307  c1ea0f                 -shr edx, 0xf
    cpu.edx >>= 15 /*0xf*/ % 32;
    // 0042730a  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042730c  69c904020000           -imul ecx, ecx, 0x204
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 00427312  8d8c0144010000         -lea ecx, [ecx + eax + 0x144]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(324) /* 0x144 */ + cpu.eax * 1);
    // 00427319  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0042731c  8b4ffc                 -mov ecx, dword ptr [edi - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 0042731f  49                     -dec ecx
    (cpu.ecx)--;
    // 00427320  3bf1                   +cmp esi, ecx
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
    // 00427322  894d10                 -mov dword ptr [ebp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00427325  8b5c39fc               -mov ebx, dword ptr [ecx + edi - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 00427329  8d7c39fc               -lea edi, [ecx + edi - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 0042732d  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00427330  0f8e5f010000           -jle 0x427495
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00427495;
    }
    // 00427336  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00427339  0f854f010000           -jne 0x42748e
    if (!cpu.flags.zf)
    {
        goto L_0x0042748e;
    }
    // 0042733f  03d9                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00427341  3bf3                   +cmp esi, ebx
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
    // 00427343  0f8f45010000           -jg 0x42748e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042748e;
    }
    // 00427349  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042734c  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0042734f  49                     -dec ecx
    (cpu.ecx)--;
    // 00427350  83f93f                 +cmp ecx, 0x3f
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
    // 00427353  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00427356  7606                   -jbe 0x42735e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042735e;
    }
    // 00427358  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0042735a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042735b  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
L_0x0042735e:
    // 0042735e  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00427361  3b5f08                 +cmp ebx, dword ptr [edi + 8]
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
    // 00427364  7548                   -jne 0x4273ae
    if (!cpu.flags.zf)
    {
        goto L_0x004273ae;
    }
    // 00427366  83f920                 +cmp ecx, 0x20
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
    // 00427369  731f                   -jae 0x42738a
    if (!cpu.flags.cf)
    {
        goto L_0x0042738a;
    }
    // 0042736b  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00427370  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00427372  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00427375  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00427379  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0042737b  215c9044               +and dword ptr [eax + edx*4 + 0x44], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0042737f  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00427381  752b                   -jne 0x4273ae
    if (!cpu.flags.zf)
    {
        goto L_0x004273ae;
    }
    // 00427383  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427386  2119                   +and dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00427388  eb24                   -jmp 0x4273ae
    goto L_0x004273ae;
L_0x0042738a:
    // 0042738a  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 0042738d  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00427392  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00427394  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00427397  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0042739b  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0042739d  219c90c4000000         +and dword ptr [eax + edx*4 + 0xc4], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004273a4  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 004273a6  7506                   -jne 0x4273ae
    if (!cpu.flags.zf)
    {
        goto L_0x004273ae;
    }
    // 004273a8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004273ab  215904                 -and dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004273ae:
    // 004273ae  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004273b1  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004273b4  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004273b7  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004273ba  8b7f08                 -mov edi, dword ptr [edi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004273bd  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004273c0  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004273c3  2bce                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004273c5  014dfc                 -add dword ptr [ebp - 4], ecx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004273c8  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 004273cc  0f8eaa000000           -jle 0x42747c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042747c;
    }
    // 004273d2  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004273d5  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004273d8  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 004273db  4f                     -dec edi
    (cpu.edi)--;
    // 004273dc  8d4c31fc               -lea ecx, [ecx + esi - 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 004273e0  83ff3f                 +cmp edi, 0x3f
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
    // 004273e3  7603                   -jbe 0x4273e8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004273e8;
    }
    // 004273e5  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 004273e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004273e8:
    // 004273e8  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004273eb  8d1cfb                 -lea ebx, [ebx + edi*8]
    cpu.ebx = x86::reg32(cpu.ebx + cpu.edi * 8);
    // 004273ee  895d10                 -mov dword ptr [ebp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004273f1  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004273f4  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004273f7  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004273fa  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004273fd  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00427400  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00427403  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00427406  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00427409  3b5908                 +cmp ebx, dword ptr [ecx + 8]
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
    // 0042740c  755c                   -jne 0x42746a
    if (!cpu.flags.zf)
    {
        goto L_0x0042746a;
    }
    // 0042740e  8a4c0704               -mov cl, byte ptr [edi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00427412  83ff20                 +cmp edi, 0x20
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
    // 00427415  884d13                 -mov byte ptr [ebp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(19) /* 0x13 */) = cpu.cl;
    // 00427418  fec1                   +inc cl
    {
        x86::reg8& tmp = cpu.cl;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0042741a  884c0704               -mov byte ptr [edi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 0042741e  7321                   -jae 0x427441
    if (!cpu.flags.cf)
    {
        goto L_0x00427441;
    }
    // 00427420  807d1300               +cmp byte ptr [ebp + 0x13], 0
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
    // 00427424  750e                   -jne 0x427434
    if (!cpu.flags.zf)
    {
        goto L_0x00427434;
    }
    // 00427426  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0042742b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042742d  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0042742f  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427432  0919                   +or dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x00427434:
    // 00427434  8d449044               -lea eax, [eax + edx*4 + 0x44]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 00427438  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 0042743d  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042743f  eb25                   -jmp 0x427466
    goto L_0x00427466;
L_0x00427441:
    // 00427441  807d1300               +cmp byte ptr [ebp + 0x13], 0
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
    // 00427445  7510                   -jne 0x427457
    if (!cpu.flags.zf)
    {
        goto L_0x00427457;
    }
    // 00427447  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 0042744a  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0042744f  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00427451  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427454  095904                 -or dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00427457:
    // 00427457  8d8490c4000000         -lea eax, [eax + edx*4 + 0xc4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 0042745e  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 00427461  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
L_0x00427466:
    // 00427466  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00427468  0910                   +or dword ptr [eax], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx))));
L_0x0042746a:
    // 0042746a  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042746d  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00427470  8d4432fc               -lea eax, [edx + esi - 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 00427474  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00427476  894c01fc               -mov dword ptr [ecx + eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ecx;
    // 0042747a  eb03                   -jmp 0x42747f
    goto L_0x0042747f;
L_0x0042747c:
    // 0042747c  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x0042747f:
    // 0042747f  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00427482  8942fc                 -mov dword ptr [edx - 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00427485  894432f8               -mov dword ptr [edx + esi - 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */ + cpu.esi * 1) = cpu.eax;
    // 00427489  e947010000             -jmp 0x4275d5
    goto L_0x004275d5;
L_0x0042748e:
    // 0042748e  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00427490  e943010000             -jmp 0x4275d8
    goto L_0x004275d8;
L_0x00427495:
    // 00427495  0f8d3a010000           -jge 0x4275d5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004275d5;
    }
    // 0042749b  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042749e  297510                 -sub dword ptr [ebp + 0x10], esi
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004274a1  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004274a4  894bfc                 -mov dword ptr [ebx - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004274a7  8d5c33fc               -lea ebx, [ebx + esi - 4]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 004274ab  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004274ae  895d0c                 -mov dword ptr [ebp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004274b1  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 004274b4  4e                     -dec esi
    (cpu.esi)--;
    // 004274b5  894bfc                 -mov dword ptr [ebx - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004274b8  83fe3f                 +cmp esi, 0x3f
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
    // 004274bb  7603                   -jbe 0x4274c0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004274c0;
    }
    // 004274bd  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 004274bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004274c0:
    // 004274c0  f645fc01               +test byte ptr [ebp - 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 1 /*0x1*/));
    // 004274c4  0f8585000000           -jne 0x42754f
    if (!cpu.flags.zf)
    {
        goto L_0x0042754f;
    }
    // 004274ca  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004274cd  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 004274d0  4e                     -dec esi
    (cpu.esi)--;
    // 004274d1  83fe3f                 +cmp esi, 0x3f
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
    // 004274d4  7603                   -jbe 0x4274d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004274d9;
    }
    // 004274d6  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 004274d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004274d9:
    // 004274d9  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004274dc  3b4f08                 +cmp ecx, dword ptr [edi + 8]
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
    // 004274df  7547                   -jne 0x427528
    if (!cpu.flags.zf)
    {
        goto L_0x00427528;
    }
    // 004274e1  83fe20                 +cmp esi, 0x20
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
    // 004274e4  731e                   -jae 0x427504
    if (!cpu.flags.cf)
    {
        goto L_0x00427504;
    }
    // 004274e6  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 004274eb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004274ed  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 004274ef  8d740604               -lea esi, [esi + eax + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 004274f3  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004274f5  215c9044               +and dword ptr [eax + edx*4 + 0x44], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004274f9  fe0e                   +dec byte ptr [esi]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.esi);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 004274fb  7528                   -jne 0x427525
    if (!cpu.flags.zf)
    {
        goto L_0x00427525;
    }
    // 004274fd  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427500  2119                   +and dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00427502  eb21                   -jmp 0x427525
    goto L_0x00427525;
L_0x00427504:
    // 00427504  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 00427507  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0042750c  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0042750e  8d4c0604               -lea ecx, [esi + eax + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00427512  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00427514  219c90c4000000         +and dword ptr [eax + edx*4 + 0xc4], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0042751b  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0042751d  7506                   -jne 0x427525
    if (!cpu.flags.zf)
    {
        goto L_0x00427525;
    }
    // 0042751f  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427522  215904                 -and dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00427525:
    // 00427525  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x00427528:
    // 00427528  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0042752b  8b7704                 -mov esi, dword ptr [edi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042752e  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00427531  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00427534  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00427537  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0042753a  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042753d  0375fc                 -add esi, dword ptr [ebp - 4]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00427540  897510                 -mov dword ptr [ebp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00427543  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00427546  4e                     -dec esi
    (cpu.esi)--;
    // 00427547  83fe3f                 +cmp esi, 0x3f
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
    // 0042754a  7603                   -jbe 0x42754f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042754f;
    }
    // 0042754c  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0042754e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042754f:
    // 0042754f  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00427552  8b7cf104               -mov edi, dword ptr [ecx + esi*8 + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 00427556  8d0cf1                 -lea ecx, [ecx + esi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.esi * 8);
    // 00427559  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0042755c  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042755f  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00427562  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00427565  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00427568  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042756b  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
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
    // 0042756e  755c                   -jne 0x4275cc
    if (!cpu.flags.zf)
    {
        goto L_0x004275cc;
    }
    // 00427570  8a4c0604               -mov cl, byte ptr [esi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00427574  83fe20                 +cmp esi, 0x20
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
    // 00427577  884d0f                 -mov byte ptr [ebp + 0xf], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */) = cpu.cl;
    // 0042757a  fec1                   +inc cl
    {
        x86::reg8& tmp = cpu.cl;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0042757c  884c0604               -mov byte ptr [esi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 00427580  7321                   -jae 0x4275a3
    if (!cpu.flags.cf)
    {
        goto L_0x004275a3;
    }
    // 00427582  807d0f00               +cmp byte ptr [ebp + 0xf], 0
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
    // 00427586  750e                   -jne 0x427596
    if (!cpu.flags.zf)
    {
        goto L_0x00427596;
    }
    // 00427588  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 0042758d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042758f  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 00427591  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427594  0939                   +or dword ptr [ecx], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.edi))));
L_0x00427596:
    // 00427596  8d449044               -lea eax, [eax + edx*4 + 0x44]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 0042759a  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 0042759f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004275a1  eb25                   -jmp 0x4275c8
    goto L_0x004275c8;
L_0x004275a3:
    // 004275a3  807d0f00               +cmp byte ptr [ebp + 0xf], 0
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
    // 004275a7  7510                   -jne 0x4275b9
    if (!cpu.flags.zf)
    {
        goto L_0x004275b9;
    }
    // 004275a9  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 004275ac  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 004275b1  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 004275b3  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004275b6  097904                 -or dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x004275b9:
    // 004275b9  8d8490c4000000         -lea eax, [eax + edx*4 + 0xc4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 004275c0  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 004275c3  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
L_0x004275c8:
    // 004275c8  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004275ca  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
L_0x004275cc:
    // 004275cc  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004275cf  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004275d1  894418fc               -mov dword ptr [eax + ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.ebx * 1) = cpu.eax;
L_0x004275d5:
    // 004275d5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004275d7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004275d8:
    // 004275d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004275d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004275da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004275db  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004275dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4275dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004275dd  a1e0534900             -mov eax, dword ptr [0x4953e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805600) /* 0x4953e0 */);
    // 004275e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004275e4  740f                   -je 0x4275f5
    if (cpu.flags.zf)
    {
        goto L_0x004275f5;
    }
    // 004275e6  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004275ea  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004275ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004275ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004275ef  7404                   -je 0x4275f5
    if (cpu.flags.zf)
    {
        goto L_0x004275f5;
    }
    // 004275f1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004275f3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004275f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004275f5:
    // 004275f5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004275f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4275f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004275f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004275f9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004275fb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004275fc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004275fd  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00427600  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00427603  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00427606  a882                   +test al, 0x82
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 130 /*0x82*/));
    // 00427608  0f84f3000000           -je 0x427701
    if (cpu.flags.zf)
    {
        goto L_0x00427701;
    }
    // 0042760e  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00427610  0f85eb000000           -jne 0x427701
    if (!cpu.flags.zf)
    {
        goto L_0x00427701;
    }
    // 00427616  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00427618  7416                   -je 0x427630
    if (cpu.flags.zf)
    {
        goto L_0x00427630;
    }
    // 0042761a  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042761e  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00427620  0f84db000000           -je 0x427701
    if (cpu.flags.zf)
    {
        goto L_0x00427701;
    }
    // 00427626  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00427629  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0042762b  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0042762d  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00427630:
    // 00427630  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00427633  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00427637  83650c00               -and dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042763b  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0042763d  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0042763f  66a90c01               +test ax, 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 268 /*0x10c*/));
    // 00427643  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00427646  7522                   -jne 0x42766a
    if (!cpu.flags.zf)
    {
        goto L_0x0042766a;
    }
    // 00427648  81fee0cf4300           +cmp esi, 0x43cfe0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4444128 /*0x43cfe0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042764e  7408                   -je 0x427658
    if (cpu.flags.zf)
    {
        goto L_0x00427658;
    }
    // 00427650  81fe00d04300           +cmp esi, 0x43d000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4444160 /*0x43d000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427656  750b                   -jne 0x427663
    if (!cpu.flags.zf)
    {
        goto L_0x00427663;
    }
L_0x00427658:
    // 00427658  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427659  e88b3f0000             -call 0x42b5e9
    cpu.esp -= 4;
    sub_42b5e9(app, cpu);
    // 0042765e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427660  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427661  7507                   -jne 0x42766a
    if (!cpu.flags.zf)
    {
        goto L_0x0042766a;
    }
L_0x00427663:
    // 00427663  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427664  e83c3f0000             -call 0x42b5a5
    cpu.esp -= 4;
    sub_42b5a5(app, cpu);
    // 00427669  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042766a:
    // 0042766a  66f7460c0801           +test word ptr [esi + 0xc], 0x108
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) & 264 /*0x108*/));
    // 00427670  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427671  7464                   -je 0x4276d7
    if (cpu.flags.zf)
    {
        goto L_0x004276d7;
    }
    // 00427673  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00427676  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00427678  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042767a  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042767d  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0042767f  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00427682  49                     -dec ecx
    (cpu.ecx)--;
    // 00427683  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00427685  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00427688  7e10                   -jle 0x42769a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042769a;
    }
    // 0042768a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042768b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042768c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042768d  e87b000000             -call 0x42770d
    cpu.esp -= 4;
    sub_42770d(app, cpu);
    // 00427692  83c40c                 +add esp, 0xc
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
    // 00427695  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00427698  eb33                   -jmp 0x4276cd
    goto L_0x004276cd;
L_0x0042769a:
    // 0042769a  83fbff                 +cmp ebx, -1
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
    // 0042769d  7416                   -je 0x4276b5
    if (cpu.flags.zf)
    {
        goto L_0x004276b5;
    }
    // 0042769f  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004276a1  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004276a3  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 004276a6  83e11f                 +and ecx, 0x1f
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/))));
    // 004276a9  8b0485005d4900         -mov eax, dword ptr [eax*4 + 0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 004276b0  8d04c8                 -lea eax, [eax + ecx*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 8);
    // 004276b3  eb05                   -jmp 0x4276ba
    goto L_0x004276ba;
L_0x004276b5:
    // 004276b5  b848d34300             -mov eax, 0x43d348
    cpu.eax = 4445000 /*0x43d348*/;
L_0x004276ba:
    // 004276ba  f6400420               +test byte ptr [eax + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 32 /*0x20*/));
    // 004276be  740d                   -je 0x4276cd
    if (cpu.flags.zf)
    {
        goto L_0x004276cd;
    }
    // 004276c0  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004276c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004276c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004276c5  e8e8130000             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 004276ca  83c40c                 +add esp, 0xc
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
L_0x004276cd:
    // 004276cd  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004276d0  8a4d08                 -mov cl, byte ptr [ebp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004276d3  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004276d5  eb14                   -jmp 0x4276eb
    goto L_0x004276eb;
L_0x004276d7:
    // 004276d7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004276d9  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004276dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004276dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004276de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004276df  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004276e0  e828000000             -call 0x42770d
    cpu.esp -= 4;
    sub_42770d(app, cpu);
    // 004276e5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004276e8  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004276eb:
    // 004276eb  397d0c                 +cmp dword ptr [ebp + 0xc], edi
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
    // 004276ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004276ef  7406                   -je 0x4276f7
    if (cpu.flags.zf)
    {
        goto L_0x004276f7;
    }
    // 004276f1  834e0c20               +or dword ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 004276f5  eb0f                   -jmp 0x427706
    goto L_0x00427706;
L_0x004276f7:
    // 004276f7  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004276fa  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004276ff  eb08                   -jmp 0x427709
    goto L_0x00427709;
L_0x00427701:
    // 00427701  0c20                   -or al, 0x20
    cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00427703  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00427706:
    // 00427706  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00427709:
    // 00427709  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042770a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042770b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042770c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42770d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042770d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042770e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00427710  81ec14040000           -sub esp, 0x414
    (cpu.esp) -= x86::reg32(x86::sreg32(1044 /*0x414*/));
    // 00427716  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427719  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042771a  3b0d005e4900           +cmp ecx, dword ptr [0x495e00]
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
    // 00427720  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427721  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427722  0f8379010000           -jae 0x4278a1
    if (!cpu.flags.cf)
    {
        goto L_0x004278a1;
    }
    // 00427728  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042772a  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042772c  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0042772f  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00427732  8d1c85005d4900         -lea ebx, [eax*4 + 0x495d00]
    cpu.ebx = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 00427739  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0042773c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042773e  8a443004               -mov al, byte ptr [eax + esi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00427742  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00427744  0f8457010000           -je 0x4278a1
    if (cpu.flags.zf)
    {
        goto L_0x004278a1;
    }
    // 0042774a  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042774c  397d10                 +cmp dword ptr [ebp + 0x10], edi
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
    // 0042774f  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 00427752  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00427755  7507                   -jne 0x42775e
    if (!cpu.flags.zf)
    {
        goto L_0x0042775e;
    }
L_0x00427757:
    // 00427757  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00427759  e957010000             -jmp 0x4278b5
    goto L_0x004278b5;
L_0x0042775e:
    // 0042775e  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00427760  740c                   -je 0x42776e
    if (cpu.flags.zf)
    {
        goto L_0x0042776e;
    }
    // 00427762  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00427764  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427765  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427766  e847130000             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 0042776b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042776e:
    // 0042776e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00427770  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00427772  f6400480               +test byte ptr [eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 128 /*0x80*/));
    // 00427776  0f84c1000000           -je 0x42783d
    if (cpu.flags.zf)
    {
        goto L_0x0042783d;
    }
    // 0042777c  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042777f  397d10                 +cmp dword ptr [ebp + 0x10], edi
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
    // 00427782  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00427785  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00427788  0f86e7000000           -jbe 0x427875
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00427875;
    }
L_0x0042778e:
    // 0042778e  8d85ecfbffff           -lea eax, [ebp - 0x414]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
L_0x00427794:
    // 00427794  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00427797  2b4d0c                 -sub ecx, dword ptr [ebp + 0xc]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0042779a  3b4d10                 +cmp ecx, dword ptr [ebp + 0x10]
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
    // 0042779d  7329                   -jae 0x4277c8
    if (!cpu.flags.cf)
    {
        goto L_0x004277c8;
    }
    // 0042779f  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004277a2  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 004277a5  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004277a7  80f90a                 +cmp cl, 0xa
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
    // 004277aa  7507                   -jne 0x4277b3
    if (!cpu.flags.zf)
    {
        goto L_0x004277b3;
    }
    // 004277ac  ff45f0                 -inc dword ptr [ebp - 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))++;
    // 004277af  c6000d                 -mov byte ptr [eax], 0xd
    app->getMemory<x86::reg8>(cpu.eax) = 13 /*0xd*/;
    // 004277b2  40                     -inc eax
    (cpu.eax)++;
L_0x004277b3:
    // 004277b3  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004277b5  40                     -inc eax
    (cpu.eax)++;
    // 004277b6  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004277b8  8d95ecfbffff           -lea edx, [ebp - 0x414]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
    // 004277be  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004277c0  81f900040000           +cmp ecx, 0x400
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
    // 004277c6  7ccc                   -jl 0x427794
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427794;
    }
L_0x004277c8:
    // 004277c8  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004277ca  8d85ecfbffff           -lea eax, [ebp - 0x414]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
    // 004277d0  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004277d2  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004277d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004277d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004277d8  8d85ecfbffff           -lea eax, [ebp - 0x414]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
    // 004277de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004277df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004277e0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004277e2  ff3430                 -push dword ptr [eax + esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1);
    cpu.esp -= 4;
    // 004277e5  ff15dc004300           -call dword ptr [0x4300dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391132) /* 0x4300dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004277eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004277ed  7443                   -je 0x427832
    if (cpu.flags.zf)
    {
        goto L_0x00427832;
    }
    // 004277ef  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004277f2  0145f8                 -add dword ptr [ebp - 8], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004277f5  3bc7                   +cmp eax, edi
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
    // 004277f7  7c0b                   -jl 0x427804
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427804;
    }
    // 004277f9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004277fc  2b450c                 -sub eax, dword ptr [ebp + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004277ff  3b4510                 +cmp eax, dword ptr [ebp + 0x10]
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
    // 00427802  728a                   -jb 0x42778e
    if (cpu.flags.cf)
    {
        goto L_0x0042778e;
    }
L_0x00427804:
    // 00427804  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00427806:
    // 00427806  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00427809  3bc7                   +cmp eax, edi
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
    // 0042780b  0f858b000000           -jne 0x42789c
    if (!cpu.flags.zf)
    {
        goto L_0x0042789c;
    }
    // 00427811  397d08                 +cmp dword ptr [ebp + 8], edi
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
    // 00427814  745f                   -je 0x427875
    if (cpu.flags.zf)
    {
        goto L_0x00427875;
    }
    // 00427816  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00427818  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427819  394508                 +cmp dword ptr [ebp + 8], eax
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
    // 0042781c  754c                   -jne 0x42786a
    if (!cpu.flags.zf)
    {
        goto L_0x0042786a;
    }
    // 0042781e  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 00427828  a3e8534900             -mov dword ptr [0x4953e8], eax
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.eax;
    // 0042782d  e980000000             -jmp 0x4278b2
    goto L_0x004278b2;
L_0x00427832:
    // 00427832  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00427838  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042783b  ebc7                   -jmp 0x427804
    goto L_0x00427804;
L_0x0042783d:
    // 0042783d  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00427840  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427842  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00427845  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00427848  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 0042784a  ff15dc004300           -call dword ptr [0x4300dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391132) /* 0x4300dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00427850  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427852  740b                   -je 0x42785f
    if (cpu.flags.zf)
    {
        goto L_0x0042785f;
    }
    // 00427854  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00427857  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0042785a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0042785d  eba7                   -jmp 0x427806
    goto L_0x00427806;
L_0x0042785f:
    // 0042785f  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00427865  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00427868  eb9c                   -jmp 0x427806
    goto L_0x00427806;
L_0x0042786a:
    // 0042786a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042786d  e8032f0000             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 00427872  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427873  eb3d                   -jmp 0x4278b2
    goto L_0x004278b2;
L_0x00427875:
    // 00427875  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00427877  f644300440             +test byte ptr [eax + esi + 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 64 /*0x40*/));
    // 0042787c  740c                   -je 0x42788a
    if (cpu.flags.zf)
    {
        goto L_0x0042788a;
    }
    // 0042787e  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00427881  80381a                 +cmp byte ptr [eax], 0x1a
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
    // 00427884  0f84cdfeffff           -je 0x427757
    if (cpu.flags.zf)
    {
        goto L_0x00427757;
    }
L_0x0042788a:
    // 0042788a  c705e45349001c000000   -mov dword ptr [0x4953e4], 0x1c
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 28 /*0x1c*/;
    // 00427894  893de8534900           -mov dword ptr [0x4953e8], edi
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.edi;
    // 0042789a  eb16                   -jmp 0x4278b2
    goto L_0x004278b2;
L_0x0042789c:
    // 0042789c  2b45f0                 +sub eax, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042789f  eb14                   -jmp 0x4278b5
    goto L_0x004278b5;
L_0x004278a1:
    // 004278a1  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004278a8  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
L_0x004278b2:
    // 004278b2  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x004278b5:
    // 004278b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004278b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004278b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004278b8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004278b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4278c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004278c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004278c1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004278c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004278c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004278c5  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004278c8  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004278cb  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004278ce  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004278d0  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004278d2  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004278d4  3bfe                   +cmp edi, esi
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
    // 004278d6  7608                   -jbe 0x4278e0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004278e0;
    }
    // 004278d8  3bf8                   +cmp edi, eax
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
    // 004278da  0f8278010000           -jb 0x427a58
    if (cpu.flags.cf)
    {
        goto L_0x00427a58;
    }
L_0x004278e0:
    // 004278e0  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004278e6  7514                   -jne 0x4278fc
    if (!cpu.flags.zf)
    {
        goto L_0x004278fc;
    }
    // 004278e8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004278eb  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004278ee  83f908                 +cmp ecx, 8
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
    // 004278f1  7229                   -jb 0x42791c
    if (cpu.flags.cf)
    {
        goto L_0x0042791c;
    }
    // 004278f3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004278f5  ff2495087a4200         -jmp dword ptr [edx*4 + 0x427a08]
    cpu.ip = app->getMemory<x86::reg32>(4356616 + cpu.edx * 4); goto dynamic_jump;
L_0x004278fc:
    // 004278fc  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004278fe  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00427903  83e904                 +sub ecx, 4
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
    // 00427906  720c                   -jb 0x427914
    if (cpu.flags.cf)
    {
        goto L_0x00427914;
    }
    // 00427908  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042790b  03c8                   +add ecx, eax
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
    // 0042790d  ff248520794200         -jmp dword ptr [eax*4 + 0x427920]
    cpu.ip = app->getMemory<x86::reg32>(4356384 + cpu.eax * 4); goto dynamic_jump;
L_0x00427914:
    // 00427914  ff248d187a4200         -jmp dword ptr [ecx*4 + 0x427a18]
    cpu.ip = app->getMemory<x86::reg32>(4356632 + cpu.ecx * 4); goto dynamic_jump;
L_0x0042791c:
    // 0042791c  ff248d9c794200         -jmp dword ptr [ecx*4 + 0x42799c]
    cpu.ip = app->getMemory<x86::reg32>(4356508 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00427930:
    // 00427930  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427932  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00427934  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00427936  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00427939  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042793c  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0042793f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00427942  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00427945  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00427948  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042794b  83f908                 +cmp ecx, 8
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
    // 0042794e  72cc                   -jb 0x42791c
    if (cpu.flags.cf)
    {
        goto L_0x0042791c;
    }
    // 00427950  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00427952  ff2495087a4200         -jmp dword ptr [edx*4 + 0x427a08]
    cpu.ip = app->getMemory<x86::reg32>(4356616 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042795c:
    // 0042795c  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042795e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00427960  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00427962  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00427965  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00427968  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042796b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042796e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00427971  83f908                 +cmp ecx, 8
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
    // 00427974  72a6                   -jb 0x42791c
    if (cpu.flags.cf)
    {
        goto L_0x0042791c;
    }
    // 00427976  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00427978  ff2495087a4200         -jmp dword ptr [edx*4 + 0x427a08]
    cpu.ip = app->getMemory<x86::reg32>(4356616 + cpu.edx * 4); goto dynamic_jump;
  case 0x00427980:
    // 00427980  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427982  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00427984  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00427986  46                     -inc esi
    (cpu.esi)++;
    // 00427987  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042798a  47                     -inc edi
    (cpu.edi)++;
    // 0042798b  83f908                 +cmp ecx, 8
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
    // 0042798e  728c                   -jb 0x42791c
    if (cpu.flags.cf)
    {
        goto L_0x0042791c;
    }
    // 00427990  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00427992  ff2495087a4200         -jmp dword ptr [edx*4 + 0x427a08]
    cpu.ip = app->getMemory<x86::reg32>(4356616 + cpu.edx * 4); goto dynamic_jump;
  case 0x004279bc:
    // 004279bc  8b448ee4               -mov eax, dword ptr [esi + ecx*4 - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4);
    // 004279c0  89448fe4               -mov dword ptr [edi + ecx*4 - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004279c4:
    // 004279c4  8b448ee8               -mov eax, dword ptr [esi + ecx*4 - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4);
    // 004279c8  89448fe8               -mov dword ptr [edi + ecx*4 - 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004279cc:
    // 004279cc  8b448eec               -mov eax, dword ptr [esi + ecx*4 - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4);
    // 004279d0  89448fec               -mov dword ptr [edi + ecx*4 - 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004279d4:
    // 004279d4  8b448ef0               -mov eax, dword ptr [esi + ecx*4 - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4);
    // 004279d8  89448ff0               -mov dword ptr [edi + ecx*4 - 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004279dc:
    // 004279dc  8b448ef4               -mov eax, dword ptr [esi + ecx*4 - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4);
    // 004279e0  89448ff4               -mov dword ptr [edi + ecx*4 - 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004279e4:
    // 004279e4  8b448ef8               -mov eax, dword ptr [esi + ecx*4 - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4);
    // 004279e8  89448ff8               -mov dword ptr [edi + ecx*4 - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004279ec:
    // 004279ec  8b448efc               -mov eax, dword ptr [esi + ecx*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004279f0  89448ffc               -mov dword ptr [edi + ecx*4 - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 004279f4  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004279fb  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004279fd  03f8                   +add edi, eax
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
  case 0x004279ff:
    // 004279ff  ff2495087a4200         -jmp dword ptr [edx*4 + 0x427a08]
    cpu.ip = app->getMemory<x86::reg32>(4356616 + cpu.edx * 4); goto dynamic_jump;
  case 0x00427a18:
    // 00427a18  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427a1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a1d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a1e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427a20:
    // 00427a20  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00427a22  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00427a24  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427a27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a29  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a2a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427a2c:
    // 00427a2c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00427a2e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00427a30  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00427a33  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00427a36  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427a39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a3b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a3c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427a40:
    // 00427a40  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00427a42  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00427a44  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00427a47  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00427a4a  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00427a4d  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00427a50  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427a53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a55  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427a56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427a58:
    // 00427a58  8d7431fc               -lea esi, [ecx + esi - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 00427a5c  8d7c39fc               -lea edi, [ecx + edi - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 00427a60  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00427a66  7524                   -jne 0x427a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00427a8c;
    }
    // 00427a68  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00427a6b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00427a6e  83f908                 +cmp ecx, 8
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
    // 00427a71  720d                   -jb 0x427a80
    if (cpu.flags.cf)
    {
        goto L_0x00427a80;
    }
    // 00427a73  fd                     -std 
    cpu.flags.df = 1;
    // 00427a74  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00427a76  fc                     -cld 
    cpu.flags.df = 0;
    // 00427a77  ff2495a07b4200         -jmp dword ptr [edx*4 + 0x427ba0]
    cpu.ip = app->getMemory<x86::reg32>(4357024 + cpu.edx * 4); goto dynamic_jump;
L_0x00427a80:
    // 00427a80  f7d9                   +neg ecx
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
    // 00427a82  ff248d507b4200         -jmp dword ptr [ecx*4 + 0x427b50]
    cpu.ip = app->getMemory<x86::reg32>(4356944 + cpu.ecx * 4); goto dynamic_jump;
L_0x00427a8c:
    // 00427a8c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00427a8e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00427a93  83f904                 +cmp ecx, 4
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
    // 00427a96  720c                   -jb 0x427aa4
    if (cpu.flags.cf)
    {
        goto L_0x00427aa4;
    }
    // 00427a98  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00427a9b  2bc8                   +sub ecx, eax
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
    // 00427a9d  ff2485a87a4200         -jmp dword ptr [eax*4 + 0x427aa8]
    cpu.ip = app->getMemory<x86::reg32>(4356776 + cpu.eax * 4); goto dynamic_jump;
L_0x00427aa4:
    // 00427aa4  ff248da07b4200         -jmp dword ptr [ecx*4 + 0x427ba0]
    cpu.ip = app->getMemory<x86::reg32>(4357024 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00427ab8:
    // 00427ab8  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00427abb  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427abd  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00427ac0  4e                     -dec esi
    (cpu.esi)--;
    // 00427ac1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00427ac4  4f                     -dec edi
    (cpu.edi)--;
    // 00427ac5  83f908                 +cmp ecx, 8
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
    // 00427ac8  72b6                   -jb 0x427a80
    if (cpu.flags.cf)
    {
        goto L_0x00427a80;
    }
    // 00427aca  fd                     -std 
    cpu.flags.df = 1;
    // 00427acb  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00427acd  fc                     -cld 
    cpu.flags.df = 0;
    // 00427ace  ff2495a07b4200         -jmp dword ptr [edx*4 + 0x427ba0]
    cpu.ip = app->getMemory<x86::reg32>(4357024 + cpu.edx * 4); goto dynamic_jump;
  case 0x00427ad8:
    // 00427ad8  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00427adb  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427add  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00427ae0  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00427ae3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00427ae6  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00427ae9  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00427aec  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00427aef  83f908                 +cmp ecx, 8
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
    // 00427af2  728c                   -jb 0x427a80
    if (cpu.flags.cf)
    {
        goto L_0x00427a80;
    }
    // 00427af4  fd                     -std 
    cpu.flags.df = 1;
    // 00427af5  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00427af7  fc                     -cld 
    cpu.flags.df = 0;
    // 00427af8  ff2495a07b4200         -jmp dword ptr [edx*4 + 0x427ba0]
    cpu.ip = app->getMemory<x86::reg32>(4357024 + cpu.edx * 4); goto dynamic_jump;
  case 0x00427b00:
    // 00427b00  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00427b03  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427b05  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00427b08  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00427b0b  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00427b0e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00427b11  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00427b14  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00427b17  83ee03                 -sub esi, 3
    (cpu.esi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00427b1a  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00427b1d  83f908                 +cmp ecx, 8
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
    // 00427b20  0f825affffff           -jb 0x427a80
    if (cpu.flags.cf)
    {
        goto L_0x00427a80;
    }
    // 00427b26  fd                     -std 
    cpu.flags.df = 1;
    // 00427b27  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00427b29  fc                     -cld 
    cpu.flags.df = 0;
    // 00427b2a  ff2495a07b4200         -jmp dword ptr [edx*4 + 0x427ba0]
    cpu.ip = app->getMemory<x86::reg32>(4357024 + cpu.edx * 4); goto dynamic_jump;
  case 0x00427b54:
    // 00427b54  8b448e1c               -mov eax, dword ptr [esi + ecx*4 + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4);
    // 00427b58  89448f1c               -mov dword ptr [edi + ecx*4 + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00427b5c:
    // 00427b5c  8b448e18               -mov eax, dword ptr [esi + ecx*4 + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4);
    // 00427b60  89448f18               -mov dword ptr [edi + ecx*4 + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00427b64:
    // 00427b64  8b448e14               -mov eax, dword ptr [esi + ecx*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4);
    // 00427b68  89448f14               -mov dword ptr [edi + ecx*4 + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00427b6c:
    // 00427b6c  8b448e10               -mov eax, dword ptr [esi + ecx*4 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4);
    // 00427b70  89448f10               -mov dword ptr [edi + ecx*4 + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00427b74:
    // 00427b74  8b448e0c               -mov eax, dword ptr [esi + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 00427b78  89448f0c               -mov dword ptr [edi + ecx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00427b7c:
    // 00427b7c  8b448e08               -mov eax, dword ptr [esi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00427b80  89448f08               -mov dword ptr [edi + ecx*4 + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00427b84:
    // 00427b84  8b448e04               -mov eax, dword ptr [esi + ecx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 00427b88  89448f04               -mov dword ptr [edi + ecx*4 + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 00427b8c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00427b93  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00427b95  03f8                   +add edi, eax
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
  case 0x00427b97:
    // 00427b97  ff2495a07b4200         -jmp dword ptr [edx*4 + 0x427ba0]
    cpu.ip = app->getMemory<x86::reg32>(4357024 + cpu.edx * 4); goto dynamic_jump;
  case 0x00427bb0:
    // 00427bb0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427bb3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bb4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bb5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bb6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427bb8:
    // 00427bb8  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00427bbb  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00427bbe  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427bc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bc3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bc4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427bc8:
    // 00427bc8  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00427bcb  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00427bce  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00427bd1  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00427bd4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427bd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bd9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bda  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00427bdc:
    // 00427bdc  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00427bdf  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00427be2  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00427be5  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00427be8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00427beb  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00427bee  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00427bf1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bf3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427bf4  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_427bf5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427bf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427bf6  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00427bfa  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00427bfd  a883                   +test al, 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 131 /*0x83*/));
    // 00427bff  0f84c4000000           -je 0x427cc9
    if (cpu.flags.zf)
    {
        goto L_0x00427cc9;
    }
    // 00427c05  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00427c07  0f85bc000000           -jne 0x427cc9
    if (!cpu.flags.zf)
    {
        goto L_0x00427cc9;
    }
    // 00427c0d  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00427c0f  740a                   -je 0x427c1b
    if (cpu.flags.zf)
    {
        goto L_0x00427c1b;
    }
    // 00427c11  0c20                   +or al, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00427c13  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00427c16  e9ae000000             -jmp 0x427cc9
    goto L_0x00427cc9;
L_0x00427c1b:
    // 00427c1b  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00427c1d  66a90c01               +test ax, 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 268 /*0x10c*/));
    // 00427c21  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00427c24  7509                   -jne 0x427c2f
    if (!cpu.flags.zf)
    {
        goto L_0x00427c2f;
    }
    // 00427c26  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427c27  e879390000             -call 0x42b5a5
    cpu.esp -= 4;
    sub_42b5a5(app, cpu);
    // 00427c2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c2d  eb05                   -jmp 0x427c34
    goto L_0x00427c34;
L_0x00427c2f:
    // 00427c2f  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00427c32  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00427c34:
    // 00427c34  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00427c37  ff7608                 -push dword ptr [esi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00427c3a  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00427c3d  e840e3ffff             -call 0x425f82
    cpu.esp -= 4;
    sub_425f82(app, cpu);
    // 00427c42  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00427c45  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00427c48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427c4a  746c                   -je 0x427cb8
    if (cpu.flags.zf)
    {
        goto L_0x00427cb8;
    }
    // 00427c4c  83f8ff                 +cmp eax, -1
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
    // 00427c4f  7467                   -je 0x427cb8
    if (cpu.flags.zf)
    {
        goto L_0x00427cb8;
    }
    // 00427c51  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00427c54  f6c282                 +test dl, 0x82
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 130 /*0x82*/));
    // 00427c57  7534                   -jne 0x427c8d
    if (!cpu.flags.zf)
    {
        goto L_0x00427c8d;
    }
    // 00427c59  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00427c5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427c5d  83f9ff                 +cmp ecx, -1
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
    // 00427c60  7414                   -je 0x427c76
    if (cpu.flags.zf)
    {
        goto L_0x00427c76;
    }
    // 00427c62  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00427c64  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00427c67  83e11f                 +and ecx, 0x1f
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/))));
    // 00427c6a  8b3cbd005d4900         -mov edi, dword ptr [edi*4 + 0x495d00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.edi * 4);
    // 00427c71  8d3ccf                 -lea edi, [edi + ecx*8]
    cpu.edi = x86::reg32(cpu.edi + cpu.ecx * 8);
    // 00427c74  eb05                   -jmp 0x427c7b
    goto L_0x00427c7b;
L_0x00427c76:
    // 00427c76  bf48d34300             -mov edi, 0x43d348
    cpu.edi = 4445000 /*0x43d348*/;
L_0x00427c7b:
    // 00427c7b  8a4f04                 -mov cl, byte ptr [edi + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00427c7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427c7f  80e182                 -and cl, 0x82
    cpu.cl &= x86::reg8(x86::sreg8(130 /*0x82*/));
    // 00427c82  80f982                 +cmp cl, 0x82
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(130 /*0x82*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00427c85  7506                   -jne 0x427c8d
    if (!cpu.flags.zf)
    {
        goto L_0x00427c8d;
    }
    // 00427c87  80ce20                 -or dh, 0x20
    cpu.dh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00427c8a  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00427c8d:
    // 00427c8d  817e1800020000         +cmp dword ptr [esi + 0x18], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427c94  7514                   -jne 0x427caa
    if (!cpu.flags.zf)
    {
        goto L_0x00427caa;
    }
    // 00427c96  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00427c99  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00427c9c  740c                   -je 0x427caa
    if (cpu.flags.zf)
    {
        goto L_0x00427caa;
    }
    // 00427c9e  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 00427ca1  7507                   -jne 0x427caa
    if (!cpu.flags.zf)
    {
        goto L_0x00427caa;
    }
    // 00427ca3  c7461800100000         -mov dword ptr [esi + 0x18], 0x1000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4096 /*0x1000*/;
L_0x00427caa:
    // 00427caa  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00427cac  48                     -dec eax
    (cpu.eax)--;
    // 00427cad  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00427cb0  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 00427cb3  41                     -inc ecx
    (cpu.ecx)++;
    // 00427cb4  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00427cb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427cb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427cb8:
    // 00427cb8  f7d8                   +neg eax
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
    // 00427cba  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00427cbc  83e010                 -and eax, 0x10
    cpu.eax &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00427cbf  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00427cc2  09460c                 -or dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.eax));
    // 00427cc5  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00427cc9:
    // 00427cc9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00427ccc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427ccd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_427cce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427cce  a158d24300             -mov eax, dword ptr [0x43d258]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4444760) /* 0x43d258 */);
    // 00427cd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427cd5  7402                   -je 0x427cd9
    if (cpu.flags.zf)
    {
        goto L_0x00427cd9;
    }
    // 00427cd7  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00427cd9:
    // 00427cd9  685c204300             -push 0x43205c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399196 /*0x43205c*/;
    cpu.esp -= 4;
    // 00427cde  6844204300             -push 0x432044
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399172 /*0x432044*/;
    cpu.esp -= 4;
    // 00427ce3  e8ce000000             -call 0x427db6
    cpu.esp -= 4;
    sub_427db6(app, cpu);
    // 00427ce8  6840204300             -push 0x432040
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399168 /*0x432040*/;
    cpu.esp -= 4;
    // 00427ced  6800204300             -push 0x432000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399104 /*0x432000*/;
    cpu.esp -= 4;
    // 00427cf2  e8bf000000             -call 0x427db6
    cpu.esp -= 4;
    sub_427db6(app, cpu);
    // 00427cf7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00427cfa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_427cfb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427cfb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00427cfd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00427cff  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00427d03  e815000000             -call 0x427d1d
    cpu.esp -= 4;
    sub_427d1d(app, cpu);
    // 00427d08  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00427d0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_427d0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427d0c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00427d0e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00427d10  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00427d14  e804000000             -call 0x427d1d
    cpu.esp -= 4;
    sub_427d1d(app, cpu);
    // 00427d19  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00427d1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_427d1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427d1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427d1e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00427d20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427d21  393d2c544900           +cmp dword ptr [0x49542c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805676) /* 0x49542c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427d27  7511                   -jne 0x427d3a
    if (!cpu.flags.zf)
    {
        goto L_0x00427d3a;
    }
    // 00427d29  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00427d2d  ff15e4004300           -call dword ptr [0x4300e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391140) /* 0x4300e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00427d33  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00427d34  ff15e0004300           -call dword ptr [0x4300e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391136) /* 0x4300e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00427d3a:
    // 00427d3a  837c240c00             +cmp dword ptr [esp + 0xc], 0
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
    // 00427d3f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427d40  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00427d44  893d28544900           -mov dword ptr [0x495428], edi
    app->getMemory<x86::reg32>(x86::reg32(4805672) /* 0x495428 */) = cpu.edi;
    // 00427d4a  881d24544900           -mov byte ptr [0x495424], bl
    app->getMemory<x86::reg8>(x86::reg32(4805668) /* 0x495424 */) = cpu.bl;
    // 00427d50  753c                   -jne 0x427d8e
    if (!cpu.flags.zf)
    {
        goto L_0x00427d8e;
    }
    // 00427d52  a1105e4900             -mov eax, dword ptr [0x495e10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808208) /* 0x495e10 */);
    // 00427d57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427d59  7422                   -je 0x427d7d
    if (cpu.flags.zf)
    {
        goto L_0x00427d7d;
    }
    // 00427d5b  8b0d0c5e4900           -mov ecx, dword ptr [0x495e0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4808204) /* 0x495e0c */);
    // 00427d61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427d62  8d71fc                 -lea esi, [ecx - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00427d65  3bf0                   +cmp esi, eax
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
    // 00427d67  7213                   -jb 0x427d7c
    if (cpu.flags.cf)
    {
        goto L_0x00427d7c;
    }
L_0x00427d69:
    // 00427d69  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00427d6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427d6d  7402                   -je 0x427d71
    if (cpu.flags.zf)
    {
        goto L_0x00427d71;
    }
    // 00427d6f  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00427d71:
    // 00427d71  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00427d74  3b35105e4900           +cmp esi, dword ptr [0x495e10]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808208) /* 0x495e10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427d7a  73ed                   -jae 0x427d69
    if (!cpu.flags.cf)
    {
        goto L_0x00427d69;
    }
L_0x00427d7c:
    // 00427d7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00427d7d:
    // 00427d7d  6868204300             -push 0x432068
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399208 /*0x432068*/;
    cpu.esp -= 4;
    // 00427d82  6860204300             -push 0x432060
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399200 /*0x432060*/;
    cpu.esp -= 4;
    // 00427d87  e82a000000             -call 0x427db6
    cpu.esp -= 4;
    sub_427db6(app, cpu);
    // 00427d8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427d8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00427d8e:
    // 00427d8e  6874204300             -push 0x432074
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399220 /*0x432074*/;
    cpu.esp -= 4;
    // 00427d93  686c204300             -push 0x43206c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399212 /*0x43206c*/;
    cpu.esp -= 4;
    // 00427d98  e819000000             -call 0x427db6
    cpu.esp -= 4;
    sub_427db6(app, cpu);
    // 00427d9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427d9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427d9f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00427da1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427da2  7510                   -jne 0x427db4
    if (!cpu.flags.zf)
    {
        goto L_0x00427db4;
    }
    // 00427da4  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00427da8  893d2c544900           -mov dword ptr [0x49542c], edi
    app->getMemory<x86::reg32>(x86::reg32(4805676) /* 0x49542c */) = cpu.edi;
    // 00427dae  ff15c4004300           -call dword ptr [0x4300c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391108) /* 0x4300c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00427db4:
    // 00427db4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427db5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_427db6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427db6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427db7  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x00427dbb:
    // 00427dbb  3b74240c               +cmp esi, dword ptr [esp + 0xc]
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
    // 00427dbf  730d                   -jae 0x427dce
    if (!cpu.flags.cf)
    {
        goto L_0x00427dce;
    }
    // 00427dc1  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00427dc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00427dc5  7402                   -je 0x427dc9
    if (cpu.flags.zf)
    {
        goto L_0x00427dc9;
    }
    // 00427dc7  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00427dc9:
    // 00427dc9  83c604                 +add esi, 4
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
    // 00427dcc  ebed                   -jmp 0x427dbb
    goto L_0x00427dbb;
L_0x00427dce:
    // 00427dce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427dcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_427dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427dd0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427dd4  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 00427dda  7414                   -je 0x427df0
    if (cpu.flags.zf)
    {
        goto L_0x00427df0;
    }
L_0x00427ddc:
    // 00427ddc  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00427dde  41                     -inc ecx
    (cpu.ecx)++;
    // 00427ddf  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00427de1  7440                   -je 0x427e23
    if (cpu.flags.zf)
    {
        goto L_0x00427e23;
    }
    // 00427de3  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 00427de9  75f1                   -jne 0x427ddc
    if (!cpu.flags.zf)
    {
        goto L_0x00427ddc;
    }
    // 00427deb  0500000000             -add eax, 0
    (cpu.eax) += x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00427df0:
    // 00427df0  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00427df2  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 00427df7  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00427df9  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00427dfc  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00427dfe  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00427e01  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 00427e06  74e8                   -je 0x427df0
    if (cpu.flags.zf)
    {
        goto L_0x00427df0;
    }
    // 00427e08  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00427e0b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00427e0d  7432                   -je 0x427e41
    if (cpu.flags.zf)
    {
        goto L_0x00427e41;
    }
    // 00427e0f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00427e11  7424                   -je 0x427e37
    if (cpu.flags.zf)
    {
        goto L_0x00427e37;
    }
    // 00427e13  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 00427e18  7413                   -je 0x427e2d
    if (cpu.flags.zf)
    {
        goto L_0x00427e2d;
    }
    // 00427e1a  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 00427e1f  7402                   -je 0x427e23
    if (cpu.flags.zf)
    {
        goto L_0x00427e23;
    }
    // 00427e21  ebcd                   -jmp 0x427df0
    goto L_0x00427df0;
L_0x00427e23:
    // 00427e23  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00427e26  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427e2a  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427e2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427e2d:
    // 00427e2d  8d41fe                 -lea eax, [ecx - 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 00427e30  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427e34  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427e36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427e37:
    // 00427e37  8d41fd                 -lea eax, [ecx - 3]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 00427e3a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427e3e  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427e40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00427e41:
    // 00427e41  8d41fc                 -lea eax, [ecx - 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00427e44  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00427e48  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427e4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_427e4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427e4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00427e4c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00427e4e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427e4f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427e50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427e51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427e52  8b356c554900           -mov esi, dword ptr [0x49556c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4805996) /* 0x49556c */);
    // 00427e58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427e59  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00427e5c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00427e5e  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00427e61  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00427e64  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00427e66  3c61                   +cmp al, 0x61
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
    // 00427e68  741a                   -je 0x427e84
    if (cpu.flags.zf)
    {
        goto L_0x00427e84;
    }
    // 00427e6a  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00427e6c  740f                   -je 0x427e7d
    if (cpu.flags.zf)
    {
        goto L_0x00427e7d;
    }
    // 00427e6e  3c77                   +cmp al, 0x77
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00427e70  0f8522010000           -jne 0x427f98
    if (!cpu.flags.zf)
    {
        goto L_0x00427f98;
    }
    // 00427e76  b901030000             -mov ecx, 0x301
    cpu.ecx = 769 /*0x301*/;
    // 00427e7b  eb0c                   -jmp 0x427e89
    goto L_0x00427e89;
L_0x00427e7d:
    // 00427e7d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00427e7f  83ce01                 +or esi, 1
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 00427e82  eb08                   -jmp 0x427e8c
    goto L_0x00427e8c;
L_0x00427e84:
    // 00427e84  b909010000             -mov ecx, 0x109
    cpu.ecx = 265 /*0x109*/;
L_0x00427e89:
    // 00427e89  83ce02                 -or esi, 2
    cpu.esi |= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00427e8c:
    // 00427e8c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00427e8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00427e8f:
    // 00427e8f  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00427e92  47                     -inc edi
    (cpu.edi)++;
    // 00427e93  3ac3                   +cmp al, bl
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
    // 00427e95  0f84e3000000           -je 0x427f7e
    if (cpu.flags.zf)
    {
        goto L_0x00427f7e;
    }
    // 00427e9b  3bd3                   +cmp edx, ebx
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
    // 00427e9d  0f84db000000           -je 0x427f7e
    if (cpu.flags.zf)
    {
        goto L_0x00427f7e;
    }
    // 00427ea3  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00427ea6  83f854                 +cmp eax, 0x54
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427ea9  7f72                   -jg 0x427f1d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00427f1d;
    }
    // 00427eab  7460                   -je 0x427f0d
    if (cpu.flags.zf)
    {
        goto L_0x00427f0d;
    }
    // 00427ead  83e82b                 +sub eax, 0x2b
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
    // 00427eb0  7445                   -je 0x427ef7
    if (cpu.flags.zf)
    {
        goto L_0x00427ef7;
    }
    // 00427eb2  83e819                 +sub eax, 0x19
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00427eb5  7436                   -je 0x427eed
    if (cpu.flags.zf)
    {
        goto L_0x00427eed;
    }
    // 00427eb7  83e80e                 +sub eax, 0xe
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00427eba  741c                   -je 0x427ed8
    if (cpu.flags.zf)
    {
        goto L_0x00427ed8;
    }
    // 00427ebc  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00427ebd  0f85ac000000           -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427ec3  395dfc                 +cmp dword ptr [ebp - 4], ebx
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
    // 00427ec6  0f85a3000000           -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427ecc  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00427ed3  83c920                 +or ecx, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 00427ed6  ebb7                   -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427ed8:
    // 00427ed8  395dfc                 +cmp dword ptr [ebp - 4], ebx
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
    // 00427edb  0f858e000000           -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427ee1  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00427ee8  83c910                 +or ecx, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/))));
    // 00427eeb  eba2                   -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427eed:
    // 00427eed  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00427ef0  757d                   -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427ef2  83c940                 +or ecx, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(64 /*0x40*/))));
    // 00427ef5  eb98                   -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427ef7:
    // 00427ef7  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00427efa  7573                   -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427efc  83e1fe                 -and ecx, 0xfffffffe
    cpu.ecx &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 00427eff  83e6fc                 -and esi, 0xfffffffc
    cpu.esi &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 00427f02  83c902                 -or ecx, 2
    cpu.ecx |= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00427f05  81ce80000000           +or esi, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(128 /*0x80*/))));
    // 00427f0b  eb82                   -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427f0d:
    // 00427f0d  b800100000             -mov eax, 0x1000
    cpu.eax = 4096 /*0x1000*/;
    // 00427f12  85c8                   +test eax, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ecx));
    // 00427f14  7559                   -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427f16  0bc8                   +or ecx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00427f18  e972ffffff             -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427f1d:
    // 00427f1d  83e862                 +sub eax, 0x62
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98 /*0x62*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00427f20  7448                   -je 0x427f6a
    if (cpu.flags.zf)
    {
        goto L_0x00427f6a;
    }
    // 00427f22  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00427f23  742e                   -je 0x427f53
    if (cpu.flags.zf)
    {
        goto L_0x00427f53;
    }
    // 00427f25  83e80b                 +sub eax, 0xb
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00427f28  7412                   -je 0x427f3c
    if (cpu.flags.zf)
    {
        goto L_0x00427f3c;
    }
    // 00427f2a  83e806                 +sub eax, 6
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
    // 00427f2d  7540                   -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427f2f  f6c5c0                 +test ch, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 192 /*0xc0*/));
    // 00427f32  753b                   -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427f34  80cd40                 +or ch, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00427f37  e953ffffff             -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427f3c:
    // 00427f3c  395df8                 +cmp dword ptr [ebp - 8], ebx
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
    // 00427f3f  752e                   -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427f41  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
    // 00427f48  81e6ffbfffff           +and esi, 0xffffbfff
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(4294950911 /*0xffffbfff*/))));
    // 00427f4e  e93cffffff             -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427f53:
    // 00427f53  395df8                 +cmp dword ptr [ebp - 8], ebx
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
    // 00427f56  7517                   -jne 0x427f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00427f6f;
    }
    // 00427f58  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
    // 00427f5f  81ce00400000           +or esi, 0x4000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(16384 /*0x4000*/))));
    // 00427f65  e925ffffff             -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427f6a:
    // 00427f6a  f6c5c0                 +test ch, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 192 /*0xc0*/));
    // 00427f6d  7407                   -je 0x427f76
    if (cpu.flags.zf)
    {
        goto L_0x00427f76;
    }
L_0x00427f6f:
    // 00427f6f  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00427f71  e919ffffff             -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427f76:
    // 00427f76  80cd80                 +or ch, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 00427f79  e911ffffff             -jmp 0x427e8f
    goto L_0x00427e8f;
L_0x00427f7e:
    // 00427f7e  68a4010000             -push 0x1a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 420 /*0x1a4*/;
    cpu.esp -= 4;
    // 00427f83  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00427f86  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00427f87  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00427f8a  e880360000             -call 0x42b60f
    cpu.esp -= 4;
    sub_42b60f(app, cpu);
    // 00427f8f  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00427f91  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00427f94  3bcb                   +cmp ecx, ebx
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
    // 00427f96  7d04                   -jge 0x427f9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00427f9c;
    }
L_0x00427f98:
    // 00427f98  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00427f9a  eb1a                   -jmp 0x427fb6
    goto L_0x00427fb6;
L_0x00427f9c:
    // 00427f9c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00427f9f  ff05bc534900           -inc dword ptr [0x4953bc]
    (app->getMemory<x86::reg32>(x86::reg32(4805564) /* 0x4953bc */))++;
    // 00427fa5  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00427fa8  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00427fab  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00427fad  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00427fb0  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00427fb3  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00427fb6:
    // 00427fb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427fb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427fb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427fb9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427fba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_427fbb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00427fbb  8b15406e4900           -mov edx, dword ptr [0x496e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4812352) /* 0x496e40 */);
    // 00427fc1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00427fc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00427fc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00427fc4  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00427fc6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00427fc8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00427fca  3bd5                   +cmp edx, ebp
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00427fcc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00427fcd  7e5d                   -jle 0x42802c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042802c;
    }
    // 00427fcf  8b1d345e4900           -mov ebx, dword ptr [0x495e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4808244) /* 0x495e34 */);
    // 00427fd5  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00427fd7:
    // 00427fd7  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00427fd9  3bcd                   +cmp ecx, ebp
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
    // 00427fdb  7415                   -je 0x427ff2
    if (cpu.flags.zf)
    {
        goto L_0x00427ff2;
    }
    // 00427fdd  f6410c83               +test byte ptr [ecx + 0xc], 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 131 /*0x83*/));
    // 00427fe1  740a                   -je 0x427fed
    if (cpu.flags.zf)
    {
        goto L_0x00427fed;
    }
    // 00427fe3  40                     -inc eax
    (cpu.eax)++;
    // 00427fe4  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00427fe7  3bc2                   +cmp eax, edx
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
    // 00427fe9  7cec                   -jl 0x427fd7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00427fd7;
    }
    // 00427feb  eb3f                   -jmp 0x42802c
    goto L_0x0042802c;
L_0x00427fed:
    // 00427fed  8b3483                 -mov esi, dword ptr [ebx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 4);
    // 00427ff0  eb24                   -jmp 0x428016
    goto L_0x00428016;
L_0x00427ff2:
    // 00427ff2  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00427ff4  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00427ff6  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00427ff9  e877ceffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 00427ffe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00427fff  8b0d345e4900           -mov ecx, dword ptr [0x495e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4808244) /* 0x495e34 */);
    // 00428005  89040f                 -mov dword ptr [edi + ecx], eax
    app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 1) = cpu.eax;
    // 00428008  a1345e4900             -mov eax, dword ptr [0x495e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808244) /* 0x495e34 */);
    // 0042800d  8b3c07                 -mov edi, dword ptr [edi + eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1);
    // 00428010  3bfd                   +cmp edi, ebp
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
    // 00428012  7418                   -je 0x42802c
    if (cpu.flags.zf)
    {
        goto L_0x0042802c;
    }
    // 00428014  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00428016:
    // 00428016  3bf5                   +cmp esi, ebp
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
    // 00428018  7412                   -je 0x42802c
    if (cpu.flags.zf)
    {
        goto L_0x0042802c;
    }
    // 0042801a  834e10ff               -or dword ptr [esi + 0x10], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042801e  896e04                 -mov dword ptr [esi + 4], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00428021  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00428024  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00428027  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00428029  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
L_0x0042802c:
    // 0042802c  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042802e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042802f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428030  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428031  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428032  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428033(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428033  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428034  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00428038  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042803b  e8a9350000             -call 0x42b5e9
    cpu.esp -= 4;
    sub_42b5e9(app, cpu);
    // 00428040  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428042  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428043  7477                   -je 0x4280bc
    if (cpu.flags.zf)
    {
        goto L_0x004280bc;
    }
    // 00428045  81fee0cf4300           +cmp esi, 0x43cfe0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4444128 /*0x43cfe0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042804b  7504                   -jne 0x428051
    if (!cpu.flags.zf)
    {
        goto L_0x00428051;
    }
    // 0042804d  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042804f  eb0b                   -jmp 0x42805c
    goto L_0x0042805c;
L_0x00428051:
    // 00428051  81fe00d04300           +cmp esi, 0x43d000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4444160 /*0x43d000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428057  7563                   -jne 0x4280bc
    if (!cpu.flags.zf)
    {
        goto L_0x004280bc;
    }
    // 00428059  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042805b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042805c:
    // 0042805c  ff05bc534900           -inc dword ptr [0x4953bc]
    (app->getMemory<x86::reg32>(x86::reg32(4805564) /* 0x4953bc */))++;
    // 00428062  66f7460c0c01           +test word ptr [esi + 0xc], 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) & 268 /*0x10c*/));
    // 00428068  7552                   -jne 0x4280bc
    if (!cpu.flags.zf)
    {
        goto L_0x004280bc;
    }
    // 0042806a  833c853054490000       +cmp dword ptr [eax*4 + 0x495430], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805680) /* 0x495430 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428072  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428073  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428074  8d3c8530544900         -lea edi, [eax*4 + 0x495430]
    cpu.edi = x86::reg32(x86::reg32(4805680) /* 0x495430 */ + cpu.eax * 4);
    // 0042807b  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 00428080  7520                   -jne 0x4280a2
    if (!cpu.flags.zf)
    {
        goto L_0x004280a2;
    }
    // 00428082  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428083  e8edcdffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 00428088  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042808a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042808b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0042808d  7513                   -jne 0x4280a2
    if (!cpu.flags.zf)
    {
        goto L_0x004280a2;
    }
    // 0042808f  8d4614                 -lea eax, [esi + 0x14]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00428092  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00428094  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00428097  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00428099  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042809a  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0042809d  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004280a0  eb0d                   -jmp 0x4280af
    goto L_0x004280af;
L_0x004280a2:
    // 004280a2  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004280a4  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004280a7  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004280aa  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004280ac  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004280af:
    // 004280af  66814e0c0211           -or word ptr [esi + 0xc], 0x1102
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg16(x86::sreg16(4354 /*0x1102*/));
    // 004280b5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004280b7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004280b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004280b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004280ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004280bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004280bc:
    // 004280bc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004280be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004280bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4280c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004280c0  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004280c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004280c6  7422                   -je 0x4280ea
    if (cpu.flags.zf)
    {
        goto L_0x004280ea;
    }
    // 004280c8  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004280cc  f6460d10               +test byte ptr [esi + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004280d0  7429                   -je 0x4280fb
    if (cpu.flags.zf)
    {
        goto L_0x004280fb;
    }
    // 004280d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004280d3  e85ed3ffff             -call 0x425436
    cpu.esp -= 4;
    sub_425436(app, cpu);
    // 004280d8  80660dee               -and byte ptr [esi + 0xd], 0xee
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) &= x86::reg8(x86::sreg8(238 /*0xee*/));
    // 004280dc  83661800               -and dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004280e0  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004280e3  83660800               -and dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004280e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004280e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004280e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004280ea:
    // 004280ea  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004280ee  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004280f2  7407                   -je 0x4280fb
    if (cpu.flags.zf)
    {
        goto L_0x004280fb;
    }
    // 004280f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004280f5  e83cd3ffff             -call 0x425436
    cpu.esp -= 4;
    sub_425436(app, cpu);
    // 004280fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004280fb:
    // 004280fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004280fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4280fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004280fd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004280fe  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00428100  81ec48020000           -sub esp, 0x248
    (cpu.esp) -= x86::reg32(x86::sreg32(584 /*0x248*/));
    // 00428106  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428107  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428108  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428109  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042810c  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042810e  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00428110  47                     -inc edi
    (cpu.edi)++;
    // 00428111  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00428113  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00428116  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 00428119  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0042811c  0f84f4060000           -je 0x428816
    if (cpu.flags.zf)
    {
        goto L_0x00428816;
    }
    // 00428122  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00428125  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00428127  eb08                   -jmp 0x428131
    goto L_0x00428131;
L_0x00428129:
    // 00428129  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042812c  8b75d0                 -mov esi, dword ptr [ebp - 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0042812f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00428131:
    // 00428131  3955ec                 +cmp dword ptr [ebp - 0x14], edx
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
    // 00428134  0f8cdc060000           -jl 0x428816
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428816;
    }
    // 0042813a  80fb20                 +cmp bl, 0x20
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
    // 0042813d  7c13                   -jl 0x428152
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428152;
    }
    // 0042813f  80fb78                 +cmp bl, 0x78
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
    // 00428142  7f0e                   -jg 0x428152
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428152;
    }
    // 00428144  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00428147  8a80b4094300           -mov al, byte ptr [eax + 0x4309b4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4393396) /* 0x4309b4 */);
    // 0042814d  83e00f                 +and eax, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/))));
    // 00428150  eb02                   -jmp 0x428154
    goto L_0x00428154;
L_0x00428152:
    // 00428152  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00428154:
    // 00428154  0fbe84c6d4094300       -movsx eax, byte ptr [esi + eax*8 + 0x4309d4]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4393428) /* 0x4309d4 */ + cpu.eax * 8)));
    // 0042815c  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0042815f  83f807                 +cmp eax, 7
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
    // 00428162  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00428165  0f879a060000           -ja 0x428805
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00428805;
    }
    // 0042816b  ff24851e884200         -jmp dword ptr [eax*4 + 0x42881e]
    cpu.ip = app->getMemory<x86::reg32>(4360222 + cpu.eax * 4); goto dynamic_jump;
  case 0x00428172:
    // 00428172  834df0ff               +or dword ptr [ebp - 0x10], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00428176  8955cc                 -mov dword ptr [ebp - 0x34], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.edx;
    // 00428179  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
    // 0042817c  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 0042817f  8955e4                 -mov dword ptr [ebp - 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edx;
    // 00428182  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00428185  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 00428188  e978060000             -jmp 0x428805
    goto L_0x00428805;
  case 0x0042818d:
    // 0042818d  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00428190  83e820                 +sub eax, 0x20
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
    // 00428193  743b                   -je 0x4281d0
    if (cpu.flags.zf)
    {
        goto L_0x004281d0;
    }
    // 00428195  83e803                 +sub eax, 3
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
    // 00428198  742d                   -je 0x4281c7
    if (cpu.flags.zf)
    {
        goto L_0x004281c7;
    }
    // 0042819a  83e808                 +sub eax, 8
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
    // 0042819d  741f                   -je 0x4281be
    if (cpu.flags.zf)
    {
        goto L_0x004281be;
    }
    // 0042819f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004281a0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004281a1  7412                   -je 0x4281b5
    if (cpu.flags.zf)
    {
        goto L_0x004281b5;
    }
    // 004281a3  83e803                 +sub eax, 3
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
    // 004281a6  0f8559060000           -jne 0x428805
    if (!cpu.flags.zf)
    {
        goto L_0x00428805;
    }
    // 004281ac  834dfc08               +or dword ptr [ebp - 4], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(8 /*0x8*/))));
    // 004281b0  e950060000             -jmp 0x428805
    goto L_0x00428805;
L_0x004281b5:
    // 004281b5  834dfc04               +or dword ptr [ebp - 4], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004281b9  e947060000             -jmp 0x428805
    goto L_0x00428805;
L_0x004281be:
    // 004281be  834dfc01               +or dword ptr [ebp - 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004281c2  e93e060000             -jmp 0x428805
    goto L_0x00428805;
L_0x004281c7:
    // 004281c7  804dfc80               +or byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 004281cb  e935060000             -jmp 0x428805
    goto L_0x00428805;
L_0x004281d0:
    // 004281d0  834dfc02               +or dword ptr [ebp - 4], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004281d4  e92c060000             -jmp 0x428805
    goto L_0x00428805;
  case 0x004281d9:
    // 004281d9  80fb2a                 +cmp bl, 0x2a
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
    // 004281dc  7523                   -jne 0x428201
    if (!cpu.flags.zf)
    {
        goto L_0x00428201;
    }
    // 004281de  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004281e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004281e2  e8f5060000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 004281e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004281e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004281ea  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004281ed  0f8d12060000           -jge 0x428805
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00428805;
    }
    // 004281f3  834dfc04               -or dword ptr [ebp - 4], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004281f7  f7d8                   +neg eax
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
L_0x004281f9:
    // 004281f9  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004281fc  e904060000             -jmp 0x428805
    goto L_0x00428805;
L_0x00428201:
    // 00428201  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00428204  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00428207  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042820a  8d4441d0               -lea eax, [ecx + eax*2 - 0x30]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 0042820e  ebe9                   -jmp 0x4281f9
    goto L_0x004281f9;
  case 0x00428210:
    // 00428210  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00428213  e9ed050000             -jmp 0x428805
    goto L_0x00428805;
  case 0x00428218:
    // 00428218  80fb2a                 +cmp bl, 0x2a
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
    // 0042821b  751e                   -jne 0x42823b
    if (!cpu.flags.zf)
    {
        goto L_0x0042823b;
    }
    // 0042821d  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00428220  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428221  e8b6060000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 00428226  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428228  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428229  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0042822c  0f8dd3050000           -jge 0x428805
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00428805;
    }
    // 00428232  834df0ff               +or dword ptr [ebp - 0x10], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00428236  e9ca050000             -jmp 0x428805
    goto L_0x00428805;
L_0x0042823b:
    // 0042823b  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 0042823e  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00428241  8d4441d0               -lea eax, [ecx + eax*2 - 0x30]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 00428245  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00428248  e9b8050000             -jmp 0x428805
    goto L_0x00428805;
  case 0x0042824d:
    // 0042824d  80fb49                 +cmp bl, 0x49
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
    // 00428250  742e                   -je 0x428280
    if (cpu.flags.zf)
    {
        goto L_0x00428280;
    }
    // 00428252  80fb68                 +cmp bl, 0x68
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
    // 00428255  7420                   -je 0x428277
    if (cpu.flags.zf)
    {
        goto L_0x00428277;
    }
    // 00428257  80fb6c                 +cmp bl, 0x6c
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
    // 0042825a  7412                   -je 0x42826e
    if (cpu.flags.zf)
    {
        goto L_0x0042826e;
    }
    // 0042825c  80fb77                 +cmp bl, 0x77
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
    // 0042825f  0f85a0050000           -jne 0x428805
    if (!cpu.flags.zf)
    {
        goto L_0x00428805;
    }
    // 00428265  804dfd08               +or byte ptr [ebp - 3], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00428269  e997050000             -jmp 0x428805
    goto L_0x00428805;
L_0x0042826e:
    // 0042826e  834dfc10               +or dword ptr [ebp - 4], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(16 /*0x10*/))));
    // 00428272  e98e050000             -jmp 0x428805
    goto L_0x00428805;
L_0x00428277:
    // 00428277  834dfc20               +or dword ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 0042827b  e985050000             -jmp 0x428805
    goto L_0x00428805;
L_0x00428280:
    // 00428280  803f36                 +cmp byte ptr [edi], 0x36
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
    // 00428283  7514                   -jne 0x428299
    if (!cpu.flags.zf)
    {
        goto L_0x00428299;
    }
    // 00428285  807f0134               +cmp byte ptr [edi + 1], 0x34
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
    // 00428289  750e                   -jne 0x428299
    if (!cpu.flags.zf)
    {
        goto L_0x00428299;
    }
    // 0042828b  47                     -inc edi
    (cpu.edi)++;
    // 0042828c  47                     -inc edi
    (cpu.edi)++;
    // 0042828d  804dfd80               +or byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 00428291  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00428294  e96c050000             -jmp 0x428805
    goto L_0x00428805;
L_0x00428299:
    // 00428299  8955d0                 -mov dword ptr [ebp - 0x30], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.edx;
  [[fallthrough]];
  case 0x0042829c:
    // 0042829c  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 004282a2  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 004282a5  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 004282a8  f644410180             +test byte ptr [ecx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 004282ad  7419                   -je 0x4282c8
    if (cpu.flags.zf)
    {
        goto L_0x004282c8;
    }
    // 004282af  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004282b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004282b3  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004282b6  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 004282b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004282ba  e87f050000             -call 0x42883e
    cpu.esp -= 4;
    sub_42883e(app, cpu);
    // 004282bf  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004282c1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004282c4  47                     -inc edi
    (cpu.edi)++;
    // 004282c5  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x004282c8:
    // 004282c8  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004282cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004282cc  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004282cf  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 004282d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004282d3  e866050000             -call 0x42883e
    cpu.esp -= 4;
    sub_42883e(app, cpu);
    // 004282d8  83c40c                 +add esp, 0xc
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
    // 004282db  e925050000             -jmp 0x428805
    goto L_0x00428805;
  case 0x004282e0:
    // 004282e0  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 004282e3  83f867                 +cmp eax, 0x67
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
    // 004282e6  0f8f1c020000           -jg 0x428508
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428508;
    }
    // 004282ec  83f865                 +cmp eax, 0x65
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
    // 004282ef  0f8d96000000           -jge 0x42838b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042838b;
    }
    // 004282f5  83f858                 +cmp eax, 0x58
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
    // 004282f8  0f8feb000000           -jg 0x4283e9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004283e9;
    }
    // 004282fe  0f8478020000           -je 0x42857c
    if (cpu.flags.zf)
    {
        goto L_0x0042857c;
    }
    // 00428304  83e843                 +sub eax, 0x43
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
    // 00428307  0f849f000000           -je 0x4283ac
    if (cpu.flags.zf)
    {
        goto L_0x004283ac;
    }
    // 0042830d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042830e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042830f  7470                   -je 0x428381
    if (cpu.flags.zf)
    {
        goto L_0x00428381;
    }
    // 00428311  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00428312  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00428313  746c                   -je 0x428381
    if (cpu.flags.zf)
    {
        goto L_0x00428381;
    }
    // 00428315  83e80c                 +sub eax, 0xc
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
    // 00428318  0f85e9030000           -jne 0x428707
    if (!cpu.flags.zf)
    {
        goto L_0x00428707;
    }
    // 0042831e  66f745fc3008           +test word ptr [ebp - 4], 0x830
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2096 /*0x830*/));
    // 00428324  7504                   -jne 0x42832a
    if (!cpu.flags.zf)
    {
        goto L_0x0042832a;
    }
    // 00428326  804dfd08               -or byte ptr [ebp - 3], 8
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0042832a:
    // 0042832a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042832d  83feff                 +cmp esi, -1
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
    // 00428330  7505                   -jne 0x428337
    if (!cpu.flags.zf)
    {
        goto L_0x00428337;
    }
    // 00428332  beffffff7f             -mov esi, 0x7fffffff
    cpu.esi = 2147483647 /*0x7fffffff*/;
L_0x00428337:
    // 00428337  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042833a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042833b  e89c050000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 00428340  66f745fc1008           +test word ptr [ebp - 4], 0x810
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2064 /*0x810*/));
    // 00428346  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428347  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00428349  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0042834c  0f84fe010000           -je 0x428550
    if (cpu.flags.zf)
    {
        goto L_0x00428550;
    }
    // 00428352  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428354  7509                   -jne 0x42835f
    if (!cpu.flags.zf)
    {
        goto L_0x0042835f;
    }
    // 00428356  8b0d44d34300           -mov ecx, dword ptr [0x43d344]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4444996) /* 0x43d344 */);
    // 0042835c  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
L_0x0042835f:
    // 0042835f  c745dc01000000         -mov dword ptr [ebp - 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = 1 /*0x1*/;
    // 00428366  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00428368:
    // 00428368  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042836a  4e                     -dec esi
    (cpu.esi)--;
    // 0042836b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042836d  0f84d4010000           -je 0x428547
    if (cpu.flags.zf)
    {
        goto L_0x00428547;
    }
    // 00428373  66833800               +cmp word ptr [eax], 0
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
    // 00428377  0f84ca010000           -je 0x428547
    if (cpu.flags.zf)
    {
        goto L_0x00428547;
    }
    // 0042837d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042837e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042837f  ebe7                   -jmp 0x428368
    goto L_0x00428368;
L_0x00428381:
    // 00428381  c745cc01000000         -mov dword ptr [ebp - 0x34], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = 1 /*0x1*/;
    // 00428388  80c320                 -add bl, 0x20
    (cpu.bl) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0042838b:
    // 0042838b  834dfc40               -or dword ptr [ebp - 4], 0x40
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0042838f  8dbdb8fdffff           -lea edi, [ebp - 0x248]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 00428395  3bca                   +cmp ecx, edx
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
    // 00428397  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 0042839a  0f8dcf000000           -jge 0x42846f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042846f;
    }
    // 004283a0  c745f006000000         -mov dword ptr [ebp - 0x10], 6
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 6 /*0x6*/;
    // 004283a7  e9d1000000             -jmp 0x42847d
    goto L_0x0042847d;
L_0x004283ac:
    // 004283ac  66f745fc3008           +test word ptr [ebp - 4], 0x830
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2096 /*0x830*/));
    // 004283b2  7504                   -jne 0x4283b8
    if (!cpu.flags.zf)
    {
        goto L_0x004283b8;
    }
    // 004283b4  804dfd08               -or byte ptr [ebp - 3], 8
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004283b8:
    // 004283b8  66f745fc1008           +test word ptr [ebp - 4], 0x810
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2064 /*0x810*/));
    // 004283be  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004283c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004283c2  743b                   -je 0x4283ff
    if (cpu.flags.zf)
    {
        goto L_0x004283ff;
    }
    // 004283c4  e830050000             -call 0x4288f9
    cpu.esp -= 4;
    sub_4288f9(app, cpu);
    // 004283c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004283ca  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 004283d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004283d1  e8f2340000             -call 0x42b8c8
    cpu.esp -= 4;
    sub_42b8c8(app, cpu);
    // 004283d6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004283d9  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004283dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004283de  7d32                   -jge 0x428412
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00428412;
    }
    // 004283e0  c745d801000000         -mov dword ptr [ebp - 0x28], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = 1 /*0x1*/;
    // 004283e7  eb29                   -jmp 0x428412
    goto L_0x00428412;
L_0x004283e9:
    // 004283e9  83e85a                 +sub eax, 0x5a
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
    // 004283ec  7432                   -je 0x428420
    if (cpu.flags.zf)
    {
        goto L_0x00428420;
    }
    // 004283ee  83e809                 +sub eax, 9
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
    // 004283f1  74c5                   -je 0x4283b8
    if (cpu.flags.zf)
    {
        goto L_0x004283b8;
    }
    // 004283f3  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004283f4  0f84e8010000           -je 0x4285e2
    if (cpu.flags.zf)
    {
        goto L_0x004285e2;
    }
    // 004283fa  e908030000             -jmp 0x428707
    goto L_0x00428707;
L_0x004283ff:
    // 004283ff  e8d8040000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 00428404  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428405  8885b8fdffff           -mov byte ptr [ebp - 0x248], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-584) /* -0x248 */) = cpu.al;
    // 0042840b  c745f401000000         -mov dword ptr [ebp - 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 1 /*0x1*/;
L_0x00428412:
    // 00428412  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 00428418  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0042841b  e9e7020000             -jmp 0x428707
    goto L_0x00428707;
L_0x00428420:
    // 00428420  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00428423  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428424  e8b3040000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 00428429  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042842b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042842c  7433                   -je 0x428461
    if (cpu.flags.zf)
    {
        goto L_0x00428461;
    }
    // 0042842e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00428431  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428433  742c                   -je 0x428461
    if (cpu.flags.zf)
    {
        goto L_0x00428461;
    }
    // 00428435  f645fd08               +test byte ptr [ebp - 3], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 8 /*0x8*/));
    // 00428439  7417                   -je 0x428452
    if (cpu.flags.zf)
    {
        goto L_0x00428452;
    }
    // 0042843b  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0042843e  d1e8                   +shr eax, 1
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
    // 00428440  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00428443  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00428446  c745dc01000000         -mov dword ptr [ebp - 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = 1 /*0x1*/;
    // 0042844d  e9b5020000             -jmp 0x428707
    goto L_0x00428707;
L_0x00428452:
    // 00428452  8365dc00               +and dword ptr [ebp - 0x24], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 00428456  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00428459  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0042845c  e9a3020000             -jmp 0x428704
    goto L_0x00428704;
L_0x00428461:
    // 00428461  a140d34300             -mov eax, dword ptr [0x43d340]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4444992) /* 0x43d340 */);
    // 00428466  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00428469  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042846a  e98e000000             -jmp 0x4284fd
    goto L_0x004284fd;
L_0x0042846f:
    // 0042846f  750c                   -jne 0x42847d
    if (!cpu.flags.zf)
    {
        goto L_0x0042847d;
    }
    // 00428471  80fb67                 +cmp bl, 0x67
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
    // 00428474  7507                   -jne 0x42847d
    if (!cpu.flags.zf)
    {
        goto L_0x0042847d;
    }
    // 00428476  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
L_0x0042847d:
    // 0042847d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00428480  ff75cc                 -push dword ptr [ebp - 0x34]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    cpu.esp -= 4;
    // 00428483  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428486  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00428489  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0042848c  8b48f8                 -mov ecx, dword ptr [eax - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 0042848f  894db8                 -mov dword ptr [ebp - 0x48], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ecx;
    // 00428492  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00428495  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
    // 00428498  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0042849b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042849c  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 004284a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004284a3  8d45b8                 -lea eax, [ebp - 0x48]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004284a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004284a7  ff1568d34300           -call dword ptr [0x43d368]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4445032) /* 0x43d368 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004284ad  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004284b0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004284b3  81e680000000           +and esi, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(128 /*0x80*/))));
    // 004284b9  7414                   -je 0x4284cf
    if (cpu.flags.zf)
    {
        goto L_0x004284cf;
    }
    // 004284bb  837df000               +cmp dword ptr [ebp - 0x10], 0
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
    // 004284bf  750e                   -jne 0x4284cf
    if (!cpu.flags.zf)
    {
        goto L_0x004284cf;
    }
    // 004284c1  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 004284c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004284c8  ff1574d34300           -call dword ptr [0x43d374]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4445044) /* 0x43d374 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004284ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004284cf:
    // 004284cf  80fb67                 +cmp bl, 0x67
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
    // 004284d2  7512                   -jne 0x4284e6
    if (!cpu.flags.zf)
    {
        goto L_0x004284e6;
    }
    // 004284d4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004284d6  750e                   -jne 0x4284e6
    if (!cpu.flags.zf)
    {
        goto L_0x004284e6;
    }
    // 004284d8  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 004284de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004284df  ff156cd34300           -call dword ptr [0x43d36c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4445036) /* 0x43d36c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004284e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004284e6:
    // 004284e6  80bdb8fdffff2d         +cmp byte ptr [ebp - 0x248], 0x2d
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
    // 004284ed  750d                   -jne 0x4284fc
    if (!cpu.flags.zf)
    {
        goto L_0x004284fc;
    }
    // 004284ef  804dfd01               +or byte ptr [ebp - 3], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004284f3  8dbdb9fdffff           -lea edi, [ebp - 0x247]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-583) /* -0x247 */);
    // 004284f9  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
L_0x004284fc:
    // 004284fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004284fd:
    // 004284fd  e8cef8ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 00428502  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428503  e9fc010000             -jmp 0x428704
    goto L_0x00428704;
L_0x00428508:
    // 00428508  83e869                 +sub eax, 0x69
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
    // 0042850b  0f84d1000000           -je 0x4285e2
    if (cpu.flags.zf)
    {
        goto L_0x004285e2;
    }
    // 00428511  83e805                 +sub eax, 5
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
    // 00428514  0f849e000000           -je 0x4285b8
    if (cpu.flags.zf)
    {
        goto L_0x004285b8;
    }
    // 0042851a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042851b  0f8484000000           -je 0x4285a5
    if (cpu.flags.zf)
    {
        goto L_0x004285a5;
    }
    // 00428521  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00428522  7451                   -je 0x428575
    if (cpu.flags.zf)
    {
        goto L_0x00428575;
    }
    // 00428524  83e803                 +sub eax, 3
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
    // 00428527  0f84fdfdffff           -je 0x42832a
    if (cpu.flags.zf)
    {
        goto L_0x0042832a;
    }
    // 0042852d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042852e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042852f  0f84b1000000           -je 0x4285e6
    if (cpu.flags.zf)
    {
        goto L_0x004285e6;
    }
    // 00428535  83e803                 +sub eax, 3
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
    // 00428538  0f85c9010000           -jne 0x428707
    if (!cpu.flags.zf)
    {
        goto L_0x00428707;
    }
    // 0042853e  c745d427000000         -mov dword ptr [ebp - 0x2c], 0x27
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = 39 /*0x27*/;
    // 00428545  eb3c                   -jmp 0x428583
    goto L_0x00428583;
L_0x00428547:
    // 00428547  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00428549  d1f8                   +sar eax, 1
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
    // 0042854b  e9b4010000             -jmp 0x428704
    goto L_0x00428704;
L_0x00428550:
    // 00428550  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428552  7509                   -jne 0x42855d
    if (!cpu.flags.zf)
    {
        goto L_0x0042855d;
    }
    // 00428554  8b0d40d34300           -mov ecx, dword ptr [0x43d340]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4444992) /* 0x43d340 */);
    // 0042855a  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
L_0x0042855d:
    // 0042855d  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0042855f:
    // 0042855f  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00428561  4e                     -dec esi
    (cpu.esi)--;
    // 00428562  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00428564  7408                   -je 0x42856e
    if (cpu.flags.zf)
    {
        goto L_0x0042856e;
    }
    // 00428566  803800                 +cmp byte ptr [eax], 0
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
    // 00428569  7403                   -je 0x42856e
    if (cpu.flags.zf)
    {
        goto L_0x0042856e;
    }
    // 0042856b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042856c  ebf1                   -jmp 0x42855f
    goto L_0x0042855f;
L_0x0042856e:
    // 0042856e  2bc1                   +sub eax, ecx
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
    // 00428570  e98f010000             -jmp 0x428704
    goto L_0x00428704;
L_0x00428575:
    // 00428575  c745f008000000         -mov dword ptr [ebp - 0x10], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 8 /*0x8*/;
L_0x0042857c:
    // 0042857c  c745d407000000         -mov dword ptr [ebp - 0x2c], 7
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = 7 /*0x7*/;
L_0x00428583:
    // 00428583  f645fc80               +test byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 128 /*0x80*/));
    // 00428587  c745f410000000         -mov dword ptr [ebp - 0xc], 0x10
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 16 /*0x10*/;
    // 0042858e  745d                   -je 0x4285ed
    if (cpu.flags.zf)
    {
        goto L_0x004285ed;
    }
    // 00428590  8a45d4                 -mov al, byte ptr [ebp - 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00428593  c645ea30               -mov byte ptr [ebp - 0x16], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 48 /*0x30*/;
    // 00428597  0451                   +add al, 0x51
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
    // 00428599  c745e402000000         -mov dword ptr [ebp - 0x1c], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 2 /*0x2*/;
    // 004285a0  8845eb                 -mov byte ptr [ebp - 0x15], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */) = cpu.al;
    // 004285a3  eb48                   -jmp 0x4285ed
    goto L_0x004285ed;
L_0x004285a5:
    // 004285a5  f645fc80               +test byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 128 /*0x80*/));
    // 004285a9  c745f408000000         -mov dword ptr [ebp - 0xc], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 8 /*0x8*/;
    // 004285b0  743b                   -je 0x4285ed
    if (cpu.flags.zf)
    {
        goto L_0x004285ed;
    }
    // 004285b2  804dfd02               +or byte ptr [ebp - 3], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004285b6  eb35                   -jmp 0x4285ed
    goto L_0x004285ed;
L_0x004285b8:
    // 004285b8  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004285bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004285bc  e81b030000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 004285c1  f645fc20               +test byte ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 32 /*0x20*/));
    // 004285c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004285c6  7409                   -je 0x4285d1
    if (cpu.flags.zf)
    {
        goto L_0x004285d1;
    }
    // 004285c8  668b4dec               -mov cx, word ptr [ebp - 0x14]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004285cc  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004285cf  eb05                   -jmp 0x4285d6
    goto L_0x004285d6;
L_0x004285d1:
    // 004285d1  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004285d4  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
L_0x004285d6:
    // 004285d6  c745d801000000         -mov dword ptr [ebp - 0x28], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = 1 /*0x1*/;
    // 004285dd  e923020000             -jmp 0x428805
    goto L_0x00428805;
L_0x004285e2:
    // 004285e2  834dfc40               -or dword ptr [ebp - 4], 0x40
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x004285e6:
    // 004285e6  c745f40a000000         -mov dword ptr [ebp - 0xc], 0xa
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 10 /*0xa*/;
L_0x004285ed:
    // 004285ed  f645fd80               +test byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 128 /*0x80*/));
    // 004285f1  740c                   -je 0x4285ff
    if (cpu.flags.zf)
    {
        goto L_0x004285ff;
    }
    // 004285f3  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004285f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004285f7  e8ed020000             -call 0x4288e9
    cpu.esp -= 4;
    sub_4288e9(app, cpu);
    // 004285fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004285fd  eb41                   -jmp 0x428640
    goto L_0x00428640;
L_0x004285ff:
    // 004285ff  f645fc20               +test byte ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 32 /*0x20*/));
    // 00428603  7421                   -je 0x428626
    if (cpu.flags.zf)
    {
        goto L_0x00428626;
    }
    // 00428605  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 00428609  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042860c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042860d  740c                   -je 0x42861b
    if (cpu.flags.zf)
    {
        goto L_0x0042861b;
    }
    // 0042860f  e8c8020000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 00428614  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428615  0fbfc0                 -movsx eax, ax
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
L_0x00428618:
    // 00428618  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00428619  eb25                   -jmp 0x428640
    goto L_0x00428640;
L_0x0042861b:
    // 0042861b  e8bc020000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 00428620  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428621  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 00428624  ebf2                   -jmp 0x428618
    goto L_0x00428618;
L_0x00428626:
    // 00428626  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 0042862a  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042862d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042862e  7408                   -je 0x428638
    if (cpu.flags.zf)
    {
        goto L_0x00428638;
    }
    // 00428630  e8a7020000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 00428635  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428636  ebe0                   -jmp 0x428618
    goto L_0x00428618;
L_0x00428638:
    // 00428638  e89f020000             -call 0x4288dc
    cpu.esp -= 4;
    sub_4288dc(app, cpu);
    // 0042863d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042863e  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00428640:
    // 00428640  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 00428644  741b                   -je 0x428661
    if (cpu.flags.zf)
    {
        goto L_0x00428661;
    }
    // 00428646  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00428648  7f17                   -jg 0x428661
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428661;
    }
    // 0042864a  7c04                   -jl 0x428650
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428650;
    }
    // 0042864c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042864e  7311                   -jae 0x428661
    if (!cpu.flags.cf)
    {
        goto L_0x00428661;
    }
L_0x00428650:
    // 00428650  f7d8                   +neg eax
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
    // 00428652  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00428655  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00428657  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00428659  804dfd01               +or byte ptr [ebp - 3], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0042865d  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042865f  eb04                   -jmp 0x428665
    goto L_0x00428665;
L_0x00428661:
    // 00428661  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00428663  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x00428665:
    // 00428665  f645fd80               +test byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 128 /*0x80*/));
    // 00428669  7503                   -jne 0x42866e
    if (!cpu.flags.zf)
    {
        goto L_0x0042866e;
    }
    // 0042866b  83e700                 -and edi, 0
    cpu.edi &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042866e:
    // 0042866e  837df000               +cmp dword ptr [ebp - 0x10], 0
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
    // 00428672  7d09                   -jge 0x42867d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042867d;
    }
    // 00428674  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
    // 0042867b  eb04                   -jmp 0x428681
    goto L_0x00428681;
L_0x0042867d:
    // 0042867d  8365fcf7               -and dword ptr [ebp - 4], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
L_0x00428681:
    // 00428681  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00428683  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00428685  7504                   -jne 0x42868b
    if (!cpu.flags.zf)
    {
        goto L_0x0042868b;
    }
    // 00428687  8365e400               -and dword ptr [ebp - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042868b:
    // 0042868b  8d45b7                 -lea eax, [ebp - 0x49]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-73) /* -0x49 */);
    // 0042868e  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00428691:
    // 00428691  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00428694  ff4df0                 -dec dword ptr [ebp - 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))--;
    // 00428697  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428699  7f06                   -jg 0x4286a1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004286a1;
    }
    // 0042869b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042869d  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0042869f  743b                   -je 0x4286dc
    if (cpu.flags.zf)
    {
        goto L_0x004286dc;
    }
L_0x004286a1:
    // 004286a1  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004286a4  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004286a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004286a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004286a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004286a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004286a9  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004286ac  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 004286af  e87c320000             -call 0x42b930
    cpu.esp -= 4;
    sub_42b930(app, cpu);
    // 004286b4  ff75c4                 -push dword ptr [ebp - 0x3c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    cpu.esp -= 4;
    // 004286b7  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004286b9  83c330                 -add ebx, 0x30
    (cpu.ebx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004286bc  ff75c0                 -push dword ptr [ebp - 0x40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    cpu.esp -= 4;
    // 004286bf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004286c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004286c1  e85a150000             -call 0x429c20
    cpu.esp -= 4;
    sub_429c20(app, cpu);
    // 004286c6  83fb39                 +cmp ebx, 0x39
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
    // 004286c9  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004286cb  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004286cd  7e03                   -jle 0x4286d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004286d2;
    }
    // 004286cf  035dd4                 +add ebx, dword ptr [ebp - 0x2c]
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
L_0x004286d2:
    // 004286d2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004286d5  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004286d8  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004286da  ebb5                   -jmp 0x428691
    goto L_0x00428691;
L_0x004286dc:
    // 004286dc  8d45b7                 -lea eax, [ebp - 0x49]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-73) /* -0x49 */);
    // 004286df  2b45f8                 -sub eax, dword ptr [ebp - 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004286e2  ff45f8                 -inc dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))++;
    // 004286e5  f645fd02               +test byte ptr [ebp - 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 2 /*0x2*/));
    // 004286e9  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004286ec  7419                   -je 0x428707
    if (cpu.flags.zf)
    {
        goto L_0x00428707;
    }
    // 004286ee  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004286f1  803930                 +cmp byte ptr [ecx], 0x30
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
    // 004286f4  7504                   -jne 0x4286fa
    if (!cpu.flags.zf)
    {
        goto L_0x004286fa;
    }
    // 004286f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004286f8  750d                   -jne 0x428707
    if (!cpu.flags.zf)
    {
        goto L_0x00428707;
    }
L_0x004286fa:
    // 004286fa  ff4df8                 -dec dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))--;
    // 004286fd  40                     -inc eax
    (cpu.eax)++;
    // 004286fe  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00428701  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
L_0x00428704:
    // 00428704  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00428707:
    // 00428707  837dd800               +cmp dword ptr [ebp - 0x28], 0
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
    // 0042870b  0f85f4000000           -jne 0x428805
    if (!cpu.flags.zf)
    {
        goto L_0x00428805;
    }
    // 00428711  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00428714  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00428717  7426                   -je 0x42873f
    if (cpu.flags.zf)
    {
        goto L_0x0042873f;
    }
    // 00428719  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0042871c  7406                   -je 0x428724
    if (cpu.flags.zf)
    {
        goto L_0x00428724;
    }
    // 0042871e  c645ea2d               -mov byte ptr [ebp - 0x16], 0x2d
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 45 /*0x2d*/;
    // 00428722  eb14                   -jmp 0x428738
    goto L_0x00428738;
L_0x00428724:
    // 00428724  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00428727  7406                   -je 0x42872f
    if (cpu.flags.zf)
    {
        goto L_0x0042872f;
    }
    // 00428729  c645ea2b               -mov byte ptr [ebp - 0x16], 0x2b
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 43 /*0x2b*/;
    // 0042872d  eb09                   -jmp 0x428738
    goto L_0x00428738;
L_0x0042872f:
    // 0042872f  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00428732  740b                   -je 0x42873f
    if (cpu.flags.zf)
    {
        goto L_0x0042873f;
    }
    // 00428734  c645ea20               -mov byte ptr [ebp - 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 32 /*0x20*/;
L_0x00428738:
    // 00428738  c745e401000000         -mov dword ptr [ebp - 0x1c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 1 /*0x1*/;
L_0x0042873f:
    // 0042873f  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00428742  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 00428745  2b75f4                 -sub esi, dword ptr [ebp - 0xc]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00428748  f6c30c                 +test bl, 0xc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 12 /*0xc*/));
    // 0042874b  7512                   -jne 0x42875f
    if (!cpu.flags.zf)
    {
        goto L_0x0042875f;
    }
    // 0042874d  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00428750  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428751  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00428754  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428755  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00428757  e817010000             -call 0x428873
    cpu.esp -= 4;
    sub_428873(app, cpu);
    // 0042875c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042875f:
    // 0042875f  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00428762  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428763  8d45ea                 -lea eax, [ebp - 0x16]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-22) /* -0x16 */);
    // 00428766  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00428769  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042876c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042876d  e832010000             -call 0x4288a4
    cpu.esp -= 4;
    sub_4288a4(app, cpu);
    // 00428772  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00428775  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00428778  7417                   -je 0x428791
    if (cpu.flags.zf)
    {
        goto L_0x00428791;
    }
    // 0042877a  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0042877d  7512                   -jne 0x428791
    if (!cpu.flags.zf)
    {
        goto L_0x00428791;
    }
    // 0042877f  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00428782  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428783  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00428786  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428787  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00428789  e8e5000000             -call 0x428873
    cpu.esp -= 4;
    sub_428873(app, cpu);
    // 0042878e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00428791:
    // 00428791  837ddc00               +cmp dword ptr [ebp - 0x24], 0
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
    // 00428795  7441                   -je 0x4287d8
    if (cpu.flags.zf)
    {
        goto L_0x004287d8;
    }
    // 00428797  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 0042879b  7e3b                   -jle 0x4287d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004287d8;
    }
    // 0042879d  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004287a0  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004287a3  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004287a6:
    // 004287a6  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004287a9  43                     -inc ebx
    (cpu.ebx)++;
    // 004287aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004287ab  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004287ae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004287af  43                     -inc ebx
    (cpu.ebx)++;
    // 004287b0  e813310000             -call 0x42b8c8
    cpu.esp -= 4;
    sub_42b8c8(app, cpu);
    // 004287b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004287b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004287b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004287b9  7e32                   -jle 0x4287ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004287ed;
    }
    // 004287bb  8d4dec                 -lea ecx, [ebp - 0x14]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004287be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004287bf  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004287c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004287c3  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004287c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004287c7  e8d8000000             -call 0x4288a4
    cpu.esp -= 4;
    sub_4288a4(app, cpu);
    // 004287cc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004287cf  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004287d1  4f                     -dec edi
    (cpu.edi)--;
    // 004287d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004287d4  75d0                   -jne 0x4287a6
    if (!cpu.flags.zf)
    {
        goto L_0x004287a6;
    }
    // 004287d6  eb15                   -jmp 0x4287ed
    goto L_0x004287ed;
L_0x004287d8:
    // 004287d8  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004287db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004287dc  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004287df  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 004287e2  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 004287e5  e8ba000000             -call 0x4288a4
    cpu.esp -= 4;
    sub_4288a4(app, cpu);
    // 004287ea  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004287ed:
    // 004287ed  f645fc04               +test byte ptr [ebp - 4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4 /*0x4*/));
    // 004287f1  7412                   -je 0x428805
    if (cpu.flags.zf)
    {
        goto L_0x00428805;
    }
    // 004287f3  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004287f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004287f7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004287fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004287fb  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004287fd  e871000000             -call 0x428873
    cpu.esp -= 4;
    sub_428873(app, cpu);
    // 00428802  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00428805:
    // 00428805  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00428808  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042880a  47                     -inc edi
    (cpu.edi)++;
    // 0042880b  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0042880d  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00428810  0f8513f9ffff           -jne 0x428129
    if (!cpu.flags.zf)
    {
        goto L_0x00428129;
    }
L_0x00428816:
    // 00428816  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00428819  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042881a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042881b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042881c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042881d  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_42883e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042883e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042883f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00428841  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00428844  ff4904                 +dec dword ptr [ecx + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00428847  780e                   -js 0x428857
    if (cpu.flags.sf)
    {
        goto L_0x00428857;
    }
    // 00428849  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042884b  8a4508                 -mov al, byte ptr [ebp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042884e  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00428850  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00428852  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 00428855  eb0b                   -jmp 0x428862
    goto L_0x00428862;
L_0x00428857:
    // 00428857  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428858  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042885b  e898edffff             -call 0x4275f8
    cpu.esp -= 4;
    sub_4275f8(app, cpu);
    // 00428860  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428861  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00428862:
    // 00428862  83f8ff                 +cmp eax, -1
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
    // 00428865  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00428868  7505                   -jne 0x42886f
    if (!cpu.flags.zf)
    {
        goto L_0x0042886f;
    }
    // 0042886a  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042886d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042886e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042886f:
    // 0042886f  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 00428871  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428872  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428873(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428873  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428874  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428875  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00428879  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042887b  4f                     -dec edi
    (cpu.edi)--;
    // 0042887c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042887e  7e21                   -jle 0x4288a1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004288a1;
    }
    // 00428880  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x00428884:
    // 00428884  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428885  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00428889  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042888d  e8acffffff             -call 0x42883e
    cpu.esp -= 4;
    sub_42883e(app, cpu);
    // 00428892  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00428895  833eff                 +cmp dword ptr [esi], -1
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
    // 00428898  7407                   -je 0x4288a1
    if (cpu.flags.zf)
    {
        goto L_0x004288a1;
    }
    // 0042889a  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042889c  4f                     -dec edi
    (cpu.edi)--;
    // 0042889d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042889f  7fe3                   -jg 0x428884
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428884;
    }
L_0x004288a1:
    // 004288a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004288a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004288a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4288a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004288a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004288a5  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004288a9  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004288ab  4b                     -dec ebx
    (cpu.ebx)--;
    // 004288ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004288ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004288ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004288b0  7e26                   -jle 0x4288d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004288d8;
    }
    // 004288b2  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004288b6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x004288ba:
    // 004288ba  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 004288bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004288be  46                     -inc esi
    (cpu.esi)++;
    // 004288bf  ff74241c               -push dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004288c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004288c4  e875ffffff             -call 0x42883e
    cpu.esp -= 4;
    sub_42883e(app, cpu);
    // 004288c9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004288cc  833fff                 +cmp dword ptr [edi], -1
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
    // 004288cf  7407                   -je 0x4288d8
    if (cpu.flags.zf)
    {
        goto L_0x004288d8;
    }
    // 004288d1  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004288d3  4b                     -dec ebx
    (cpu.ebx)--;
    // 004288d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004288d6  7fe2                   -jg 0x4288ba
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004288ba;
    }
L_0x004288d8:
    // 004288d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004288d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004288da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004288db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4288dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004288dc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004288e0  830004                 -add dword ptr [eax], 4
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004288e3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004288e5  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004288e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4288e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004288e9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004288ed  830008                 -add dword ptr [eax], 8
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004288f0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004288f2  8b41f8                 -mov eax, dword ptr [ecx - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-8) /* -0x8 */);
    // 004288f5  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004288f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4288f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004288f9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004288fd  830004                 -add dword ptr [eax], 4
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428900  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00428902  668b40fc               -mov ax, word ptr [eax - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00428906  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428907(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428907  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0042890a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042890b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042890c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042890d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042890e  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00428913  e85dc5ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 00428918  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042891a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042891b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042891d  7508                   -jne 0x428927
    if (!cpu.flags.zf)
    {
        goto L_0x00428927;
    }
    // 0042891f  6a1b                   -push 0x1b
    app->getMemory<x86::reg32>(cpu.esp-4) = 27 /*0x1b*/;
    cpu.esp -= 4;
    // 00428921  e898dfffff             -call 0x4268be
    cpu.esp -= 4;
    sub_4268be(app, cpu);
    // 00428926  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00428927:
    // 00428927  8935005d4900           -mov dword ptr [0x495d00], esi
    app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */) = cpu.esi;
    // 0042892d  c705005e490020000000   -mov dword ptr [0x495e00], 0x20
    app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */) = 32 /*0x20*/;
    // 00428937  8d8600010000           -lea eax, [esi + 0x100]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(256) /* 0x100 */);
L_0x0042893d:
    // 0042893d  3bf0                   +cmp esi, eax
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
    // 0042893f  731a                   -jae 0x42895b
    if (!cpu.flags.cf)
    {
        goto L_0x0042895b;
    }
    // 00428941  80660400               -and byte ptr [esi + 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00428945  830eff                 -or dword ptr [esi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00428948  c646050a               -mov byte ptr [esi + 5], 0xa
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 10 /*0xa*/;
    // 0042894c  a1005d4900             -mov eax, dword ptr [0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */);
    // 00428951  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428954  0500010000             +add eax, 0x100
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00428959  ebe2                   -jmp 0x42893d
    goto L_0x0042893d;
L_0x0042895b:
    // 0042895b  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042895f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428960  ff15b8004300           -call dword ptr [0x4300b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391096) /* 0x4300b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428966  66837c244200           +cmp word ptr [esp + 0x42], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(66) /* 0x42 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042896c  0f84c5000000           -je 0x428a37
    if (cpu.flags.zf)
    {
        goto L_0x00428a37;
    }
    // 00428972  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00428976  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428978  0f84b9000000           -je 0x428a37
    if (cpu.flags.zf)
    {
        goto L_0x00428a37;
    }
    // 0042897e  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00428980  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00428983  b800080000             -mov eax, 0x800
    cpu.eax = 2048 /*0x800*/;
    // 00428988  3bf0                   +cmp esi, eax
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
    // 0042898a  8d1c2e                 -lea ebx, [esi + ebp]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0042898d  7c02                   -jl 0x428991
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428991;
    }
    // 0042898f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00428991:
    // 00428991  3935005e4900           +cmp dword ptr [0x495e00], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428997  7d52                   -jge 0x4289eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004289eb;
    }
    // 00428999  bf045d4900             -mov edi, 0x495d04
    cpu.edi = 4807940 /*0x495d04*/;
L_0x0042899e:
    // 0042899e  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004289a3  e8cdc4ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 004289a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004289aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004289ab  7438                   -je 0x4289e5
    if (cpu.flags.zf)
    {
        goto L_0x004289e5;
    }
    // 004289ad  8305005e490020         -add dword ptr [0x495e00], 0x20
    (app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004289b4  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004289b6  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
L_0x004289bc:
    // 004289bc  3bc1                   +cmp eax, ecx
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
    // 004289be  7318                   -jae 0x4289d8
    if (!cpu.flags.cf)
    {
        goto L_0x004289d8;
    }
    // 004289c0  80600400               -and byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 004289c4  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004289c7  c640050a               -mov byte ptr [eax + 5], 0xa
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 10 /*0xa*/;
    // 004289cb  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004289cd  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004289d0  81c100010000           +add ecx, 0x100
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004289d6  ebe4                   -jmp 0x4289bc
    goto L_0x004289bc;
L_0x004289d8:
    // 004289d8  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004289db  3935005e4900           +cmp dword ptr [0x495e00], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004289e1  7cbb                   -jl 0x42899e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042899e;
    }
    // 004289e3  eb06                   -jmp 0x4289eb
    goto L_0x004289eb;
L_0x004289e5:
    // 004289e5  8b35005e4900           -mov esi, dword ptr [0x495e00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */);
L_0x004289eb:
    // 004289eb  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004289ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004289ef  7e46                   -jle 0x428a37
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00428a37;
    }
L_0x004289f1:
    // 004289f1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004289f3  83f8ff                 +cmp eax, -1
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
    // 004289f6  7436                   -je 0x428a2e
    if (cpu.flags.zf)
    {
        goto L_0x00428a2e;
    }
    // 004289f8  8a4d00                 -mov cl, byte ptr [ebp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp);
    // 004289fb  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004289fe  742e                   -je 0x428a2e
    if (cpu.flags.zf)
    {
        goto L_0x00428a2e;
    }
    // 00428a00  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00428a03  750b                   -jne 0x428a10
    if (!cpu.flags.zf)
    {
        goto L_0x00428a10;
    }
    // 00428a05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428a06  ff15a8004300           -call dword ptr [0x4300a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391080) /* 0x4300a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428a0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428a0e  741e                   -je 0x428a2e
    if (cpu.flags.zf)
    {
        goto L_0x00428a2e;
    }
L_0x00428a10:
    // 00428a10  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00428a12  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00428a14  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00428a17  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00428a1a  8b0485005d4900         -mov eax, dword ptr [eax*4 + 0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 00428a21  8d04c8                 -lea eax, [eax + ecx*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 8);
    // 00428a24  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00428a26  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00428a28  8a4d00                 -mov cl, byte ptr [ebp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00428a2b  884804                 -mov byte ptr [eax + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.cl;
L_0x00428a2e:
    // 00428a2e  47                     -inc edi
    (cpu.edi)++;
    // 00428a2f  45                     -inc ebp
    (cpu.ebp)++;
    // 00428a30  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428a33  3bfe                   +cmp edi, esi
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
    // 00428a35  7cba                   -jl 0x4289f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004289f1;
    }
L_0x00428a37:
    // 00428a37  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00428a39:
    // 00428a39  a1005d4900             -mov eax, dword ptr [0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */);
    // 00428a3e  833cd8ff               +cmp dword ptr [eax + ebx*8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428a42  8d34d8                 -lea esi, [eax + ebx*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 8);
    // 00428a45  754d                   -jne 0x428a94
    if (!cpu.flags.zf)
    {
        goto L_0x00428a94;
    }
    // 00428a47  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00428a49  c6460481               -mov byte ptr [esi + 4], 0x81
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 129 /*0x81*/;
    // 00428a4d  7505                   -jne 0x428a54
    if (!cpu.flags.zf)
    {
        goto L_0x00428a54;
    }
    // 00428a4f  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00428a51  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428a52  eb0a                   -jmp 0x428a5e
    goto L_0x00428a5e;
L_0x00428a54:
    // 00428a54  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00428a56  48                     -dec eax
    (cpu.eax)--;
    // 00428a57  f7d8                   +neg eax
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
    // 00428a59  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00428a5b  83c0f5                 -add eax, -0xb
    (cpu.eax) += x86::reg32(x86::sreg32(-11 /*-0xb*/));
L_0x00428a5e:
    // 00428a5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428a5f  ff15ec004300           -call dword ptr [0x4300ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391148) /* 0x4300ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428a65  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00428a67  83ffff                 +cmp edi, -1
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
    // 00428a6a  7417                   -je 0x428a83
    if (cpu.flags.zf)
    {
        goto L_0x00428a83;
    }
    // 00428a6c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428a6d  ff15a8004300           -call dword ptr [0x4300a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391080) /* 0x4300a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428a73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428a75  740c                   -je 0x428a83
    if (cpu.flags.zf)
    {
        goto L_0x00428a83;
    }
    // 00428a77  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00428a7c  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00428a7e  83f802                 +cmp eax, 2
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
    // 00428a81  7506                   -jne 0x428a89
    if (!cpu.flags.zf)
    {
        goto L_0x00428a89;
    }
L_0x00428a83:
    // 00428a83  804e0440               +or byte ptr [esi + 4], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00428a87  eb0f                   -jmp 0x428a98
    goto L_0x00428a98;
L_0x00428a89:
    // 00428a89  83f803                 +cmp eax, 3
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
    // 00428a8c  750a                   -jne 0x428a98
    if (!cpu.flags.zf)
    {
        goto L_0x00428a98;
    }
    // 00428a8e  804e0408               +or byte ptr [esi + 4], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00428a92  eb04                   -jmp 0x428a98
    goto L_0x00428a98;
L_0x00428a94:
    // 00428a94  804e0480               -or byte ptr [esi + 4], 0x80
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00428a98:
    // 00428a98  43                     -inc ebx
    (cpu.ebx)++;
    // 00428a99  83fb03                 +cmp ebx, 3
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
    // 00428a9c  7c9b                   -jl 0x428a39
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428a39;
    }
    // 00428a9e  ff35005e4900           -push dword ptr [0x495e00]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */);
    cpu.esp -= 4;
    // 00428aa4  ff15e8004300           -call dword ptr [0x4300e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391144) /* 0x4300e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428aaa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428aab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428aac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428aad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428aae  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00428ab1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428ab2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428ab2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00428ab6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428ab7  3b05005e4900           +cmp eax, dword ptr [0x495e00]
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
    // 00428abd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428abe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428abf  7373                   -jae 0x428b34
    if (!cpu.flags.cf)
    {
        goto L_0x00428b34;
    }
    // 00428ac1  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00428ac3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00428ac5  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00428ac8  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00428acb  8d3c8d005d4900         -lea edi, [ecx*4 + 0x495d00]
    cpu.edi = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 00428ad2  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 00428ad5  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00428ad7  f644310401             +test byte ptr [ecx + esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 1 /*0x1*/));
    // 00428adc  7456                   -je 0x428b34
    if (cpu.flags.zf)
    {
        goto L_0x00428b34;
    }
    // 00428ade  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428adf  e8401f0000             -call 0x42aa24
    cpu.esp -= 4;
    sub_42aa24(app, cpu);
    // 00428ae4  83f8ff                 +cmp eax, -1
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
    // 00428ae7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428ae8  750c                   -jne 0x428af6
    if (!cpu.flags.zf)
    {
        goto L_0x00428af6;
    }
    // 00428aea  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 00428af4  eb4f                   -jmp 0x428b45
    goto L_0x00428b45;
L_0x00428af6:
    // 00428af6  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00428afa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00428afc  ff74241c               -push dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00428b00  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428b01  ff15f0004300           -call dword ptr [0x4300f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391152) /* 0x4300f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428b07  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00428b09  83fbff                 +cmp ebx, -1
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
    // 00428b0c  7508                   -jne 0x428b16
    if (!cpu.flags.zf)
    {
        goto L_0x00428b16;
    }
    // 00428b0e  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428b14  eb02                   -jmp 0x428b18
    goto L_0x00428b18;
L_0x00428b16:
    // 00428b16  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00428b18:
    // 00428b18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428b1a  7409                   -je 0x428b25
    if (cpu.flags.zf)
    {
        goto L_0x00428b25;
    }
    // 00428b1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428b1d  e8531c0000             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 00428b22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b23  eb20                   -jmp 0x428b45
    goto L_0x00428b45;
L_0x00428b25:
    // 00428b25  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00428b27  80643004fd             +and byte ptr [eax + esi + 4], 0xfd
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 00428b2c  8d443004               -lea eax, [eax + esi + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00428b30  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00428b32  eb14                   -jmp 0x428b48
    goto L_0x00428b48;
L_0x00428b34:
    // 00428b34  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00428b3b  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
L_0x00428b45:
    // 00428b45  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00428b48:
    // 00428b48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428b4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428b4c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00428b50  3b05005e4900           +cmp eax, dword ptr [0x495e00]
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
    // 00428b56  733d                   -jae 0x428b95
    if (!cpu.flags.cf)
    {
        goto L_0x00428b95;
    }
    // 00428b58  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00428b5a  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00428b5c  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00428b5f  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00428b62  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 00428b69  f644d10401             +test byte ptr [ecx + edx*8 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) & 1 /*0x1*/));
    // 00428b6e  7425                   -je 0x428b95
    if (cpu.flags.zf)
    {
        goto L_0x00428b95;
    }
    // 00428b70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428b71  e8ae1e0000             -call 0x42aa24
    cpu.esp -= 4;
    sub_42aa24(app, cpu);
    // 00428b76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428b77  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428b78  ff15f4004300           -call dword ptr [0x4300f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391156) /* 0x4300f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428b7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428b80  7508                   -jne 0x428b8a
    if (!cpu.flags.zf)
    {
        goto L_0x00428b8a;
    }
    // 00428b82  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428b88  eb02                   -jmp 0x428b8c
    goto L_0x00428b8c;
L_0x00428b8a:
    // 00428b8a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00428b8c:
    // 00428b8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428b8e  7412                   -je 0x428ba2
    if (cpu.flags.zf)
    {
        goto L_0x00428ba2;
    }
    // 00428b90  a3e8534900             -mov dword ptr [0x4953e8], eax
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.eax;
L_0x00428b95:
    // 00428b95  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 00428b9f  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00428ba2:
    // 00428ba2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428bfb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428bfb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428bfc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00428bfe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428bff  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00428c02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428c03  bf20059319             -mov edi, 0x19930520
    cpu.edi = 429065504 /*0x19930520*/;
    // 00428c08  393e                   +cmp dword ptr [esi], edi
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
    // 00428c0a  7405                   -je 0x428c11
    if (cpu.flags.zf)
    {
        goto L_0x00428c11;
    }
    // 00428c0c  e871080000             -call 0x429482
    cpu.esp -= 4;
    sub_429482(app, cpu);
L_0x00428c11:
    // 00428c11  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00428c14  f6400466               +test byte ptr [eax + 4], 0x66
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 102 /*0x66*/));
    // 00428c18  741f                   -je 0x428c39
    if (cpu.flags.zf)
    {
        goto L_0x00428c39;
    }
    // 00428c1a  837e0400               +cmp dword ptr [esi + 4], 0
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
    // 00428c1e  746f                   -je 0x428c8f
    if (cpu.flags.zf)
    {
        goto L_0x00428c8f;
    }
    // 00428c20  837d1c00               +cmp dword ptr [ebp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428c24  7569                   -jne 0x428c8f
    if (!cpu.flags.zf)
    {
        goto L_0x00428c8f;
    }
    // 00428c26  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00428c28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428c29  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00428c2c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00428c2f  e80e030000             -call 0x428f42
    cpu.esp -= 4;
    sub_428f42(app, cpu);
    // 00428c34  83c410                 +add esp, 0x10
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
    // 00428c37  eb56                   -jmp 0x428c8f
    goto L_0x00428c8f;
L_0x00428c39:
    // 00428c39  837e0c00               +cmp dword ptr [esi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428c3d  7450                   -je 0x428c8f
    if (cpu.flags.zf)
    {
        goto L_0x00428c8f;
    }
    // 00428c3f  813863736de0           +cmp dword ptr [eax], 0xe06d7363
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
    // 00428c45  752c                   -jne 0x428c73
    if (!cpu.flags.zf)
    {
        goto L_0x00428c73;
    }
    // 00428c47  397814                 +cmp dword ptr [eax + 0x14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428c4a  7627                   -jbe 0x428c73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00428c73;
    }
    // 00428c4c  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00428c4f  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00428c52  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428c54  741d                   -je 0x428c73
    if (cpu.flags.zf)
    {
        goto L_0x00428c73;
    }
    // 00428c56  0fb65524               -movzx edx, byte ptr [ebp + 0x24]
    cpu.edx = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(36) /* 0x24 */));
    // 00428c5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00428c5b  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428c5e  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00428c61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428c62  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00428c65  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00428c68  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00428c6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428c6c  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00428c6e  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00428c71  eb1f                   -jmp 0x428c92
    goto L_0x00428c92;
L_0x00428c73:
    // 00428c73  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428c76  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00428c79  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00428c7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428c7d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00428c80  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00428c83  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00428c86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428c87  e80a000000             -call 0x428c96
    cpu.esp -= 4;
    sub_428c96(app, cpu);
    // 00428c8c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00428c8f:
    // 00428c8f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00428c91  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00428c92:
    // 00428c92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428c93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428c94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428c95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428c96(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428c96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428c97  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00428c99  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00428c9c  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00428c9f  8065ec00               -and byte ptr [ebp - 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00428ca3  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00428ca6  83f8ff                 +cmp eax, -1
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
    // 00428ca9  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00428cac  7c08                   -jl 0x428cb6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428cb6;
    }
    // 00428cae  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00428cb1  3b4104                 +cmp eax, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428cb4  7c05                   -jl 0x428cbb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428cbb;
    }
L_0x00428cb6:
    // 00428cb6  e8c7070000             -call 0x429482
    cpu.esp -= 4;
    sub_429482(app, cpu);
L_0x00428cbb:
    // 00428cbb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428cbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428cbd  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00428cc0  bb63736de0             -mov ebx, 0xe06d7363
    cpu.ebx = 3765269347 /*0xe06d7363*/;
    // 00428cc5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428cc6  bf20059319             -mov edi, 0x19930520
    cpu.edi = 429065504 /*0x19930520*/;
    // 00428ccb  391e                   +cmp dword ptr [esi], ebx
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
    // 00428ccd  0f853f010000           -jne 0x428e12
    if (!cpu.flags.zf)
    {
        goto L_0x00428e12;
    }
    // 00428cd3  837e1003               +cmp dword ptr [esi + 0x10], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428cd7  7556                   -jne 0x428d2f
    if (!cpu.flags.zf)
    {
        goto L_0x00428d2f;
    }
    // 00428cd9  397e14                 +cmp dword ptr [esi + 0x14], edi
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
    // 00428cdc  7551                   -jne 0x428d2f
    if (!cpu.flags.zf)
    {
        goto L_0x00428d2f;
    }
    // 00428cde  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428ce2  754b                   -jne 0x428d2f
    if (!cpu.flags.zf)
    {
        goto L_0x00428d2f;
    }
    // 00428ce4  8b3538544900           -mov esi, dword ptr [0x495438]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4805688) /* 0x495438 */);
    // 00428cea  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00428cec  0f841b010000           -je 0x428e0d
    if (cpu.flags.zf)
    {
        goto L_0x00428e0d;
    }
    // 00428cf2  a13c544900             -mov eax, dword ptr [0x49543c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805692) /* 0x49543c */);
    // 00428cf7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00428cf9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428cfa  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00428cfd  c645ec01               -mov byte ptr [ebp - 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 1 /*0x1*/;
    // 00428d01  e8032d0000             -call 0x42ba09
    cpu.esp -= 4;
    sub_42ba09(app, cpu);
    // 00428d06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428d07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428d09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428d0a  7505                   -jne 0x428d11
    if (!cpu.flags.zf)
    {
        goto L_0x00428d11;
    }
    // 00428d0c  e871070000             -call 0x429482
    cpu.esp -= 4;
    sub_429482(app, cpu);
L_0x00428d11:
    // 00428d11  391e                   +cmp dword ptr [esi], ebx
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
    // 00428d13  0f85f9000000           -jne 0x428e12
    if (!cpu.flags.zf)
    {
        goto L_0x00428e12;
    }
    // 00428d19  837e1003               +cmp dword ptr [esi + 0x10], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428d1d  7510                   -jne 0x428d2f
    if (!cpu.flags.zf)
    {
        goto L_0x00428d2f;
    }
    // 00428d1f  397e14                 +cmp dword ptr [esi + 0x14], edi
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
    // 00428d22  750b                   -jne 0x428d2f
    if (!cpu.flags.zf)
    {
        goto L_0x00428d2f;
    }
    // 00428d24  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428d28  7505                   -jne 0x428d2f
    if (!cpu.flags.zf)
    {
        goto L_0x00428d2f;
    }
    // 00428d2a  e853070000             -call 0x429482
    cpu.esp -= 4;
    sub_429482(app, cpu);
L_0x00428d2f:
    // 00428d2f  391e                   +cmp dword ptr [esi], ebx
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
    // 00428d31  0f85db000000           -jne 0x428e12
    if (!cpu.flags.zf)
    {
        goto L_0x00428e12;
    }
    // 00428d37  837e1003               +cmp dword ptr [esi + 0x10], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428d3b  0f85d1000000           -jne 0x428e12
    if (!cpu.flags.zf)
    {
        goto L_0x00428e12;
    }
    // 00428d41  397e14                 +cmp dword ptr [esi + 0x14], edi
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
    // 00428d44  0f85c8000000           -jne 0x428e12
    if (!cpu.flags.zf)
    {
        goto L_0x00428e12;
    }
    // 00428d4a  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00428d4d  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00428d50  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428d51  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00428d54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428d55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428d56  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428d59  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00428d5c  e807ccffff             -call 0x425968
    cpu.esp -= 4;
    sub_425968(app, cpu);
    // 00428d61  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00428d64  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00428d66:
    // 00428d66  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00428d69  3b45e8                 +cmp eax, dword ptr [ebp - 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428d6c  0f838b000000           -jae 0x428dfd
    if (!cpu.flags.cf)
    {
        goto L_0x00428dfd;
    }
    // 00428d72  393b                   +cmp dword ptr [ebx], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428d74  7f7c                   -jg 0x428df2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428df2;
    }
    // 00428d76  3b7b04                 +cmp edi, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428d79  7f77                   -jg 0x428df2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428df2;
    }
    // 00428d7b  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00428d7e  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00428d81  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00428d84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428d86  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00428d89  7e64                   -jle 0x428def
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00428def;
    }
L_0x00428d8b:
    // 00428d8b  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00428d8e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00428d91  8d7804                 -lea edi, [eax + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00428d94  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00428d96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428d98  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00428d9b  7e1f                   -jle 0x428dbc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00428dbc;
    }
L_0x00428d9d:
    // 00428d9d  ff761c                 -push dword ptr [esi + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00428da0  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 00428da2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00428da5  e83b010000             -call 0x428ee5
    cpu.esp -= 4;
    sub_428ee5(app, cpu);
    // 00428daa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00428dad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428daf  751a                   -jne 0x428dcb
    if (!cpu.flags.zf)
    {
        goto L_0x00428dcb;
    }
    // 00428db1  ff4df8                 -dec dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))--;
    // 00428db4  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00428db7  3945f8                 +cmp dword ptr [ebp - 8], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428dba  7fe1                   -jg 0x428d9d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428d9d;
    }
L_0x00428dbc:
    // 00428dbc  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00428dbf  83450810               -add dword ptr [ebp + 8], 0x10
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00428dc3  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00428dc7  7fc2                   -jg 0x428d8b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428d8b;
    }
    // 00428dc9  eb24                   -jmp 0x428def
    goto L_0x00428def;
L_0x00428dcb:
    // 00428dcb  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 00428dce  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00428dd1  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428dd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428dd5  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 00428dd7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00428dda  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00428ddd  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00428de0  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00428de3  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00428de6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428de7  e8f4010000             -call 0x428fe0
    cpu.esp -= 4;
    sub_428fe0(app, cpu);
    // 00428dec  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
L_0x00428def:
    // 00428def  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
L_0x00428df2:
    // 00428df2  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00428df5  83c314                 +add ebx, 0x14
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
    // 00428df8  e969ffffff             -jmp 0x428d66
    goto L_0x00428d66;
L_0x00428dfd:
    // 00428dfd  807d1c00               +cmp byte ptr [ebp + 0x1c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00428e01  740a                   -je 0x428e0d
    if (cpu.flags.zf)
    {
        goto L_0x00428e0d;
    }
    // 00428e03  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00428e05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428e06  e84a050000             -call 0x429355
    cpu.esp -= 4;
    sub_429355(app, cpu);
    // 00428e0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428e0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00428e0d:
    // 00428e0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428e0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428e0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428e10  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428e11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00428e12:
    // 00428e12  807d1c00               +cmp byte ptr [ebp + 0x1c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00428e16  7520                   -jne 0x428e38
    if (!cpu.flags.zf)
    {
        goto L_0x00428e38;
    }
    // 00428e18  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00428e1b  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428e1e  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 00428e21  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00428e24  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00428e27  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00428e2a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00428e2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428e2e  e80a000000             -call 0x428e3d
    cpu.esp -= 4;
    sub_428e3d(app, cpu);
    // 00428e33  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00428e36  ebd5                   -jmp 0x428e0d
    goto L_0x00428e0d;
L_0x00428e38:
    // 00428e38  e9ef050000             -jmp 0x42942c
    return sub_42942c(app, cpu);
}

/* align: skip  */
void Application::asm_sub_428e3d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428e3d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428e3e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00428e40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428e41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428e42  833d4054490000         +cmp dword ptr [0x495440], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805696) /* 0x495440 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428e49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428e4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428e4b  7421                   -je 0x428e6e
    if (cpu.flags.zf)
    {
        goto L_0x00428e6e;
    }
    // 00428e4d  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00428e50  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428e53  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00428e56  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00428e59  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00428e5c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00428e5f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00428e62  e8d8c9ffff             -call 0x42583f
    cpu.esp -= 4;
    sub_42583f(app, cpu);
    // 00428e67  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00428e6a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428e6c  7573                   -jne 0x428ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00428ee1;
    }
L_0x00428e6e:
    // 00428e6e  8b7d1c                 -mov edi, dword ptr [ebp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00428e71  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00428e74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428e75  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00428e78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428e79  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428e7a  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428e7d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00428e80  e8e3caffff             -call 0x425968
    cpu.esp -= 4;
    sub_425968(app, cpu);
    // 00428e85  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00428e88  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00428e8a:
    // 00428e8a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00428e8d  3b45f8                 +cmp eax, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428e90  734f                   -jae 0x428ee1
    if (!cpu.flags.cf)
    {
        goto L_0x00428ee1;
    }
    // 00428e92  3b3e                   +cmp edi, dword ptr [esi]
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
    // 00428e94  7c43                   -jl 0x428ed9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428ed9;
    }
    // 00428e96  3b7e04                 +cmp edi, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428e99  7f3e                   -jg 0x428ed9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00428ed9;
    }
    // 00428e9b  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00428e9e  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00428ea1  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00428ea4  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00428ea6  8b48f4                 -mov ecx, dword ptr [eax - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-12) /* -0xc */);
    // 00428ea9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00428eab  7406                   -je 0x428eb3
    if (cpu.flags.zf)
    {
        goto L_0x00428eb3;
    }
    // 00428ead  80790800               +cmp byte ptr [ecx + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00428eb1  7526                   -jne 0x428ed9
    if (!cpu.flags.zf)
    {
        goto L_0x00428ed9;
    }
L_0x00428eb3:
    // 00428eb3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00428eb5  83c0f0                 -add eax, -0x10
    (cpu.eax) += x86::reg32(x86::sreg32(-16 /*-0x10*/));
    // 00428eb8  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00428ebb  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428ebe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428ebf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00428ec1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428ec2  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00428ec5  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00428ec8  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00428ecb  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00428ece  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00428ed1  e80a010000             -call 0x428fe0
    cpu.esp -= 4;
    sub_428fe0(app, cpu);
    // 00428ed6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
L_0x00428ed9:
    // 00428ed9  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00428edc  83c614                 +add esi, 0x14
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00428edf  eba9                   -jmp 0x428e8a
    goto L_0x00428e8a;
L_0x00428ee1:
    // 00428ee1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428ee2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428ee3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428ee4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428ee5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428ee5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428ee6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428ee7  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00428eeb  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00428eee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428ef0  744a                   -je 0x428f3c
    if (cpu.flags.zf)
    {
        goto L_0x00428f3c;
    }
    // 00428ef2  80780800               +cmp byte ptr [eax + 8], 0
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
    // 00428ef6  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00428ef9  7441                   -je 0x428f3c
    if (cpu.flags.zf)
    {
        goto L_0x00428f3c;
    }
    // 00428efb  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00428eff  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00428f02  3bc1                   +cmp eax, ecx
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
    // 00428f04  7410                   -je 0x428f16
    if (cpu.flags.zf)
    {
        goto L_0x00428f16;
    }
    // 00428f06  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00428f09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00428f0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00428f0b  e8502b0000             -call 0x42ba60
    cpu.esp -= 4;
    sub_42ba60(app, cpu);
    // 00428f10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428f11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428f13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428f14  7522                   -jne 0x428f38
    if (!cpu.flags.zf)
    {
        goto L_0x00428f38;
    }
L_0x00428f16:
    // 00428f16  f60602                 +test byte ptr [esi], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi) & 2 /*0x2*/));
    // 00428f19  7405                   -je 0x428f20
    if (cpu.flags.zf)
    {
        goto L_0x00428f20;
    }
    // 00428f1b  f60708                 +test byte ptr [edi], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi) & 8 /*0x8*/));
    // 00428f1e  7418                   -je 0x428f38
    if (cpu.flags.zf)
    {
        goto L_0x00428f38;
    }
L_0x00428f20:
    // 00428f20  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00428f24  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00428f26  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00428f28  7405                   -je 0x428f2f
    if (cpu.flags.zf)
    {
        goto L_0x00428f2f;
    }
    // 00428f2a  f60701                 +test byte ptr [edi], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi) & 1 /*0x1*/));
    // 00428f2d  7409                   -je 0x428f38
    if (cpu.flags.zf)
    {
        goto L_0x00428f38;
    }
L_0x00428f2f:
    // 00428f2f  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00428f31  7409                   -je 0x428f3c
    if (cpu.flags.zf)
    {
        goto L_0x00428f3c;
    }
    // 00428f33  f60702                 +test byte ptr [edi], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi) & 2 /*0x2*/));
    // 00428f36  7504                   -jne 0x428f3c
    if (!cpu.flags.zf)
    {
        goto L_0x00428f3c;
    }
L_0x00428f38:
    // 00428f38  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00428f3a  eb03                   -jmp 0x428f3f
    goto L_0x00428f3f;
L_0x00428f3c:
    // 00428f3c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00428f3e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00428f3f:
    // 00428f3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428f40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428f41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428f42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428f42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428f43  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00428f45  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00428f47  68480a4300             -push 0x430a48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393544 /*0x430a48*/;
    cpu.esp -= 4;
    // 00428f4c  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 00428f51  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00428f57  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428f58  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00428f5f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00428f62  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428f63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428f64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428f65  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00428f68  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00428f6b  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00428f6e  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00428f71  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00428f74  3b7514                 +cmp esi, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428f77  7455                   -je 0x428fce
    if (cpu.flags.zf)
    {
        return sub_428fce(app, cpu);
    }
    // 00428f79  83feff                 +cmp esi, -1
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
    // 00428f7c  7e05                   -jle 0x428f83
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00428f83;
    }
    // 00428f7e  3b7704                 +cmp esi, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428f81  7c05                   -jl 0x428f88
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428f88;
    }
L_0x00428f83:
    // 00428f83  e8fa040000             -call 0x429482
    cpu.esp -= 4;
    sub_429482(app, cpu);
L_0x00428f88:
    // 00428f88  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00428f8c  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00428f8f  8b44f004               -mov eax, dword ptr [eax + esi*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 00428f93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428f95  740c                   -je 0x428fa3
    if (cpu.flags.zf)
    {
        goto L_0x00428fa3;
    }
    // 00428f97  6803010000             -push 0x103
    app->getMemory<x86::reg32>(cpu.esp-4) = 259 /*0x103*/;
    cpu.esp -= 4;
    // 00428f9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428f9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428f9e  e83d040000             -call 0x4293e0
    cpu.esp -= 4;
    sub_4293e0(app, cpu);
L_0x00428fa3:
    // 00428fa3  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00428fa7  eb1a                   -jmp 0x428fc3
    return sub_428fc3(app, cpu);
}

/* align: skip  */
void Application::asm_sub_428f74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00428f74;
    // 00428f42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428f43  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00428f45  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00428f47  68480a4300             -push 0x430a48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393544 /*0x430a48*/;
    cpu.esp -= 4;
    // 00428f4c  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 00428f51  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00428f57  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428f58  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00428f5f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00428f62  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428f63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428f64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428f65  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00428f68  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00428f6b  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00428f6e  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00428f71  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_entry_0x00428f74:
    // 00428f74  3b7514                 +cmp esi, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428f77  7455                   -je 0x428fce
    if (cpu.flags.zf)
    {
        return sub_428fce(app, cpu);
    }
    // 00428f79  83feff                 +cmp esi, -1
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
    // 00428f7c  7e05                   -jle 0x428f83
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00428f83;
    }
    // 00428f7e  3b7704                 +cmp esi, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00428f81  7c05                   -jl 0x428f88
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00428f88;
    }
L_0x00428f83:
    // 00428f83  e8fa040000             -call 0x429482
    cpu.esp -= 4;
    sub_429482(app, cpu);
L_0x00428f88:
    // 00428f88  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00428f8c  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00428f8f  8b44f004               -mov eax, dword ptr [eax + esi*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 00428f93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00428f95  740c                   -je 0x428fa3
    if (cpu.flags.zf)
    {
        goto L_0x00428fa3;
    }
    // 00428f97  6803010000             -push 0x103
    app->getMemory<x86::reg32>(cpu.esp-4) = 259 /*0x103*/;
    cpu.esp -= 4;
    // 00428f9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428f9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00428f9e  e83d040000             -call 0x4293e0
    cpu.esp -= 4;
    sub_4293e0(app, cpu);
L_0x00428fa3:
    // 00428fa3  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00428fa7  eb1a                   -jmp 0x428fc3
    return sub_428fc3(app, cpu);
}

/* align: skip  */
void Application::asm_sub_428fa9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428fa9  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 00428fac  e84dceffff             -call 0x425dfe
    cpu.esp -= 4;
    sub_425dfe(app, cpu);
    // 00428fb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428fb3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428fb3  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00428fb6  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00428fba  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00428fbd  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00428fc0  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00428fc3  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00428fc6  8b34f0                 -mov esi, dword ptr [eax + esi*8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 8);
    // 00428fc9  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00428fcc  eba6                   -jmp 0x428f74
    return sub_428f74(app, cpu);
    // 00428fce  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00428fd1  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00428fd4  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00428fdb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fde  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428fce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00428fce;
    // 00428fb3  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00428fb6  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00428fba  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00428fbd  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00428fc0  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00428fc3  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00428fc6  8b34f0                 -mov esi, dword ptr [eax + esi*8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 8);
    // 00428fc9  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00428fcc  eba6                   -jmp 0x428f74
    return sub_428f74(app, cpu);
L_entry_0x00428fce:
    // 00428fce  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00428fd1  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00428fd4  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00428fdb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fde  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428fc3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00428fc3;
    // 00428fb3  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00428fb6  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00428fba  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00428fbd  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00428fc0  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
L_entry_0x00428fc3:
    // 00428fc3  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00428fc6  8b34f0                 -mov esi, dword ptr [eax + esi*8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 8);
    // 00428fc9  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00428fcc  eba6                   -jmp 0x428f74
    return sub_428f74(app, cpu);
    // 00428fce  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00428fd1  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00428fd4  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00428fdb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fde  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00428fdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_428fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00428fe0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00428fe1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00428fe3  837d2000               +cmp dword ptr [ebp + 0x20], 0
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
    // 00428fe7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428fe8  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00428feb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00428fec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428fed  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00428ff0  7410                   -je 0x429002
    if (cpu.flags.zf)
    {
        goto L_0x00429002;
    }
    // 00428ff2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00428ff5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00428ff6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00428ff7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00428ffa  e892010000             -call 0x429191
    cpu.esp -= 4;
    sub_429191(app, cpu);
    // 00428fff  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00429002:
    // 00429002  837d2c00               +cmp dword ptr [ebp + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429006  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00429009  7503                   -jne 0x42900e
    if (!cpu.flags.zf)
    {
        goto L_0x0042900e;
    }
    // 0042900b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042900c  eb03                   -jmp 0x429011
    goto L_0x00429011;
L_0x0042900e:
    // 0042900e  ff752c                 -push dword ptr [ebp + 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
L_0x00429011:
    // 00429011  e82bc7ffff             -call 0x425741
    cpu.esp -= 4;
    sub_425741(app, cpu);
    // 00429016  8b7524                 -mov esi, dword ptr [ebp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00429019  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0042901b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042901e  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429021  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429022  e81bffffff             -call 0x428f42
    cpu.esp -= 4;
    sub_428f42(app, cpu);
    // 00429027  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042902a  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0042902f  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00429032  40                     -inc eax
    (cpu.eax)++;
    // 00429033  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00429036  ff730c                 -push dword ptr [ebx + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00429039  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042903c  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042903f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429040  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00429043  e813000000             -call 0x42905b
    cpu.esp -= 4;
    sub_42905b(app, cpu);
    // 00429048  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0042904b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042904d  7407                   -je 0x429056
    if (cpu.flags.zf)
    {
        goto L_0x00429056;
    }
    // 0042904f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429050  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429051  e8a9c6ffff             -call 0x4256ff
    cpu.esp -= 4;
    sub_4256ff(app, cpu);
L_0x00429056:
    // 00429056  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429057  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429058  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429059  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042905a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42905b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042905b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042905c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042905e  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00429060  68580a4300             -push 0x430a58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393560 /*0x430a58*/;
    cpu.esp -= 4;
    // 00429065  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 0042906a  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00429070  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429071  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00429078  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042907b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042907c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042907d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042907e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00429081  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00429084  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 00429087  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00429089  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 0042908c  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042908f  8b4efc                 -mov ecx, dword ptr [esi - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00429092  894dd8                 -mov dword ptr [ebp - 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ecx;
    // 00429095  8b0d38544900           -mov ecx, dword ptr [0x495438]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4805688) /* 0x495438 */);
    // 0042909b  894de4                 -mov dword ptr [ebp - 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ecx;
    // 0042909e  8b0d3c544900           -mov ecx, dword ptr [0x49543c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4805692) /* 0x49543c */);
    // 004290a4  894de0                 -mov dword ptr [ebp - 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ecx;
    // 004290a7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004290aa  893d38544900           -mov dword ptr [0x495438], edi
    app->getMemory<x86::reg32>(x86::reg32(4805688) /* 0x495438 */) = cpu.edi;
    // 004290b0  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004290b3  890d3c544900           -mov dword ptr [0x49543c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4805692) /* 0x49543c */) = cpu.ecx;
    // 004290b9  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004290bc  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 004290c3  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004290c6  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004290c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004290ca  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004290cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004290ce  e8f3c6ffff             -call 0x4257c6
    cpu.esp -= 4;
    sub_4257c6(app, cpu);
    // 004290d3  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004290d6  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 004290d9  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004290dc  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004290e0  e83c000000             -call 0x429121
    cpu.esp -= 4;
    sub_429121(app, cpu);
    // 004290e5  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004290e8  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004290eb  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004290f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004290f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004290f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004290f5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004290f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4290e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004290e8;
    // 0042905b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042905c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042905e  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00429060  68580a4300             -push 0x430a58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393560 /*0x430a58*/;
    cpu.esp -= 4;
    // 00429065  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 0042906a  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00429070  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429071  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00429078  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042907b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042907c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042907d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042907e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00429081  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00429084  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 00429087  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00429089  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 0042908c  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042908f  8b4efc                 -mov ecx, dword ptr [esi - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00429092  894dd8                 -mov dword ptr [ebp - 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ecx;
    // 00429095  8b0d38544900           -mov ecx, dword ptr [0x495438]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4805688) /* 0x495438 */);
    // 0042909b  894de4                 -mov dword ptr [ebp - 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ecx;
    // 0042909e  8b0d3c544900           -mov ecx, dword ptr [0x49543c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4805692) /* 0x49543c */);
    // 004290a4  894de0                 -mov dword ptr [ebp - 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ecx;
    // 004290a7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004290aa  893d38544900           -mov dword ptr [0x495438], edi
    app->getMemory<x86::reg32>(x86::reg32(4805688) /* 0x495438 */) = cpu.edi;
    // 004290b0  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004290b3  890d3c544900           -mov dword ptr [0x49543c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4805692) /* 0x49543c */) = cpu.ecx;
    // 004290b9  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004290bc  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 004290c3  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004290c6  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004290c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004290ca  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004290cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004290ce  e8f3c6ffff             -call 0x4257c6
    cpu.esp -= 4;
    sub_4257c6(app, cpu);
    // 004290d3  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004290d6  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 004290d9  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004290dc  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004290e0  e83c000000             -call 0x429121
    cpu.esp -= 4;
    sub_429121(app, cpu);
    // 004290e5  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
L_entry_0x004290e8:
    // 004290e8  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004290eb  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004290f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004290f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004290f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004290f5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004290f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4290f7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004290f7  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 004290fa  e868000000             -call 0x429167
    cpu.esp -= 4;
    sub_429167(app, cpu);
    // 004290ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429100  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429101(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429101  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00429104  8365d400               -and dword ptr [ebp - 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00429108  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042910a  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042910d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042910e  e813c9ffff             -call 0x425a26
    cpu.esp -= 4;
    sub_425a26(app, cpu);
    // 00429113  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429114  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429115  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00429117  ebcf                   -jmp 0x4290e8
    return sub_4290e8(app, cpu);
}

/* align: skip  */
void Application::asm_sub_429119(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429119  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042911b  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042911e  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    return sub_429121(app, cpu);
}

/* align: skip  */
void Application::asm_sub_429121(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429121  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00429124  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00429127  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042912a  a338544900             -mov dword ptr [0x495438], eax
    app->getMemory<x86::reg32>(x86::reg32(4805688) /* 0x495438 */) = cpu.eax;
    // 0042912f  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00429132  a33c544900             -mov dword ptr [0x49543c], eax
    app->getMemory<x86::reg32>(x86::reg32(4805692) /* 0x49543c */) = cpu.eax;
    // 00429137  813f63736de0           +cmp dword ptr [edi], 0xe06d7363
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
    // 0042913d  7527                   -jne 0x429166
    if (!cpu.flags.zf)
    {
        goto L_0x00429166;
    }
    // 0042913f  837f1003               +cmp dword ptr [edi + 0x10], 3
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
    // 00429143  7521                   -jne 0x429166
    if (!cpu.flags.zf)
    {
        goto L_0x00429166;
    }
    // 00429145  817f1420059319         +cmp dword ptr [edi + 0x14], 0x19930520
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
    // 0042914c  7518                   -jne 0x429166
    if (!cpu.flags.zf)
    {
        goto L_0x00429166;
    }
    // 0042914e  395ddc                 +cmp dword ptr [ebp - 0x24], ebx
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
    // 00429151  7513                   -jne 0x429166
    if (!cpu.flags.zf)
    {
        goto L_0x00429166;
    }
    // 00429153  395dd4                 +cmp dword ptr [ebp - 0x2c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429156  740e                   -je 0x429166
    if (cpu.flags.zf)
    {
        goto L_0x00429166;
    }
    // 00429158  e831c9ffff             -call 0x425a8e
    cpu.esp -= 4;
    sub_425a8e(app, cpu);
    // 0042915d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042915e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042915f  e8f1010000             -call 0x429355
    cpu.esp -= 4;
    sub_429355(app, cpu);
    // 00429164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429165  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00429166:
    // 00429166  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429167(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429167  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042916b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042916d  813863736de0           +cmp dword ptr [eax], 0xe06d7363
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
    // 00429173  7519                   -jne 0x42918e
    if (!cpu.flags.zf)
    {
        goto L_0x0042918e;
    }
    // 00429175  83781003               +cmp dword ptr [eax + 0x10], 3
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
    // 00429179  7513                   -jne 0x42918e
    if (!cpu.flags.zf)
    {
        goto L_0x0042918e;
    }
    // 0042917b  81781420059319         +cmp dword ptr [eax + 0x14], 0x19930520
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
    // 00429182  750a                   -jne 0x42918e
    if (!cpu.flags.zf)
    {
        goto L_0x0042918e;
    }
    // 00429184  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 00429188  7504                   -jne 0x42918e
    if (!cpu.flags.zf)
    {
        goto L_0x0042918e;
    }
    // 0042918a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042918c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042918d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042918e:
    // 0042918e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00429190  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429191(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429191  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429192  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429194  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00429196  68700a4300             -push 0x430a70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393584 /*0x430a70*/;
    cpu.esp -= 4;
    // 0042919b  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 004291a0  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004291a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004291a7  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004291ae  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004291b1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004291b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004291b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004291b4  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004291b7  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004291ba  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004291bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004291bf  0f8475010000           -je 0x42933a
    if (cpu.flags.zf)
    {
        goto L_0x0042933a;
    }
    // 004291c5  80780800               +cmp byte ptr [eax + 8], 0
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
    // 004291c9  0f846b010000           -je 0x42933a
    if (cpu.flags.zf)
    {
        goto L_0x0042933a;
    }
    // 004291cf  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004291d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004291d4  0f8460010000           -je 0x42933a
    if (cpu.flags.zf)
    {
        goto L_0x0042933a;
    }
    // 004291da  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004291dd  8d7c100c               -lea edi, [eax + edx + 0xc]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 1);
    // 004291e1  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004291e5  f60108                 +test byte ptr [ecx], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx) & 8 /*0x8*/));
    // 004291e8  7444                   -je 0x42922e
    if (cpu.flags.zf)
    {
        goto L_0x0042922e;
    }
    // 004291ea  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004291ed  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004291ef  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004291f2  e812280000             -call 0x42ba09
    cpu.esp -= 4;
    sub_42ba09(app, cpu);
    // 004291f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004291f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004291f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004291fb  0f8430010000           -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 00429201  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429203  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429204  e81c280000             -call 0x42ba25
    cpu.esp -= 4;
    sub_42ba25(app, cpu);
    // 00429209  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042920a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042920b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042920d  0f841e010000           -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 00429213  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00429216  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00429218  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042921b  83c108                 +add ecx, 8
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
    // 0042921e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0042921f:
    // 0042921f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429220  e897010000             -call 0x4293bc
    cpu.esp -= 4;
    sub_4293bc(app, cpu);
    // 00429225  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429226  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429227  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00429229  e908010000             -jmp 0x429336
    goto L_0x00429336;
L_0x0042922e:
    // 0042922e  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00429231  f60601                 +test byte ptr [esi], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi) & 1 /*0x1*/));
    // 00429234  7452                   -je 0x429288
    if (cpu.flags.zf)
    {
        goto L_0x00429288;
    }
    // 00429236  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00429239  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042923b  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042923e  e8c6270000             -call 0x42ba09
    cpu.esp -= 4;
    sub_42ba09(app, cpu);
    // 00429243  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429244  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429245  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429247  0f84e4000000           -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 0042924d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042924f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429250  e8d0270000             -call 0x42ba25
    cpu.esp -= 4;
    sub_42ba25(app, cpu);
    // 00429255  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429256  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429257  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429259  0f84d2000000           -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 0042925f  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429262  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00429265  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429266  e805200000             -call 0x42b270
    cpu.esp -= 4;
    sub_42b270(app, cpu);
    // 0042926b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042926e  837e1404               +cmp dword ptr [esi + 0x14], 4
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
    // 00429272  0f85be000000           -jne 0x429336
    if (!cpu.flags.zf)
    {
        goto L_0x00429336;
    }
    // 00429278  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042927a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042927c  0f84b4000000           -je 0x429336
    if (cpu.flags.zf)
    {
        goto L_0x00429336;
    }
    // 00429282  83c608                 +add esi, 8
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
    // 00429285  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429286  eb97                   -jmp 0x42921f
    goto L_0x0042921f;
L_0x00429288:
    // 00429288  837e1800               +cmp dword ptr [esi + 0x18], 0
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
    // 0042928c  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042928f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429291  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00429294  753a                   -jne 0x4292d0
    if (!cpu.flags.zf)
    {
        goto L_0x004292d0;
    }
    // 00429296  e86e270000             -call 0x42ba09
    cpu.esp -= 4;
    sub_42ba09(app, cpu);
    // 0042929b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042929c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042929d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042929f  0f848c000000           -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 004292a5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004292a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004292a8  e878270000             -call 0x42ba25
    cpu.esp -= 4;
    sub_42ba25(app, cpu);
    // 004292ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004292b1  747e                   -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 004292b3  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004292b6  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004292b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004292ba  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004292bd  e8fa000000             -call 0x4293bc
    cpu.esp -= 4;
    sub_4293bc(app, cpu);
    // 004292c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004292c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004292c6  e8a51f0000             -call 0x42b270
    cpu.esp -= 4;
    sub_42b270(app, cpu);
    // 004292cb  83c40c                 +add esp, 0xc
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
    // 004292ce  eb66                   -jmp 0x429336
    goto L_0x00429336;
L_0x004292d0:
    // 004292d0  e834270000             -call 0x42ba09
    cpu.esp -= 4;
    sub_42ba09(app, cpu);
    // 004292d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004292d9  7456                   -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 004292db  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004292dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004292de  e842270000             -call 0x42ba25
    cpu.esp -= 4;
    sub_42ba25(app, cpu);
    // 004292e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004292e7  7448                   -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 004292e9  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004292ec  e850270000             -call 0x42ba41
    cpu.esp -= 4;
    sub_42ba41(app, cpu);
    // 004292f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004292f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004292f4  743b                   -je 0x429331
    if (cpu.flags.zf)
    {
        goto L_0x00429331;
    }
    // 004292f6  f60604                 +test byte ptr [esi], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi) & 4 /*0x4*/));
    // 004292f9  741c                   -je 0x429317
    if (cpu.flags.zf)
    {
        goto L_0x00429317;
    }
    // 004292fb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004292fd  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00429300  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429301  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00429304  e8b3000000             -call 0x4293bc
    cpu.esp -= 4;
    sub_4293bc(app, cpu);
    // 00429309  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042930a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042930b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042930c  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042930f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429310  e825c4ffff             -call 0x42573a
    cpu.esp -= 4;
    sub_42573a(app, cpu);
    // 00429315  eb1f                   -jmp 0x429336
    goto L_0x00429336;
L_0x00429317:
    // 00429317  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0042931a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042931b  ff7318                 -push dword ptr [ebx + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042931e  e899000000             -call 0x4293bc
    cpu.esp -= 4;
    sub_4293bc(app, cpu);
    // 00429323  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429324  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429325  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429326  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00429329  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042932a  e804c4ffff             -call 0x425733
    cpu.esp -= 4;
    sub_425733(app, cpu);
    // 0042932f  eb05                   -jmp 0x429336
    goto L_0x00429336;
L_0x00429331:
    // 00429331  e84c010000             -call 0x429482
    cpu.esp -= 4;
    sub_429482(app, cpu);
L_0x00429336:
    // 00429336  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042933a:
    // 0042933a  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042933d  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00429344  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429345  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429346  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429347  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429348  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429349(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429349  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042934b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042934c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42934d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042934d  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00429350  e9d7000000             -jmp 0x42942c
    return sub_42942c(app, cpu);
}

/* align: skip  */
void Application::asm_sub_429355(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429355  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429356  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429358  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042935a  68800a4300             -push 0x430a80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393600 /*0x430a80*/;
    cpu.esp -= 4;
    // 0042935f  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 00429364  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0042936a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042936b  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00429372  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429373  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429374  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429375  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429376  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429377  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0042937a  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042937d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042937f  741b                   -je 0x42939c
    if (cpu.flags.zf)
    {
        goto L_0x0042939c;
    }
    // 00429381  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00429384  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00429387  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00429389  7411                   -je 0x42939c
    if (cpu.flags.zf)
    {
        goto L_0x0042939c;
    }
    // 0042938b  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042938f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429390  ff7018                 -push dword ptr [eax + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00429393  e89bc3ffff             -call 0x425733
    cpu.esp -= 4;
    sub_425733(app, cpu);
    // 00429398  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042939c:
    // 0042939c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0042939f  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004293a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004293a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004293a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004293a9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004293aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4293ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004293ab  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004293ad  38450c                 +cmp byte ptr [ebp + 0xc], al
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
    // 004293b0  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004293b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4293b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004293b4  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004293b7  e970000000             -jmp 0x42942c
    return sub_42942c(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4293bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004293bc  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004293c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004293c1  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004293c5  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004293c7  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004293ca  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004293cc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004293ce  7c0d                   -jl 0x4293dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004293dd;
    }
    // 004293d0  8b3432                 -mov esi, dword ptr [edx + esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1);
    // 004293d3  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004293d6  8b0c0e                 -mov ecx, dword ptr [esi + ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004293d9  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004293db  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004293dd:
    // 004293dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004293de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4293e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004293e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004293e1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004293e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004293e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004293e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004293e8  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004293eb  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004293ee  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004293f1  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004293f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004293f5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004293f8  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004293fb  8b6dfc                 -mov ebp, dword ptr [ebp - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004293fe  e8aec6ffff             -call 0x425ab1
    cpu.esp -= 4;
    sub_425ab1(app, cpu);
    // 00429403  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429404  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429405  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429407  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429408  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429409  8bdd                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0042940b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042940c  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042940f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429410  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00429412  81f900010000           +cmp ecx, 0x100
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
    // 00429418  7505                   -jne 0x42941f
    if (!cpu.flags.zf)
    {
        goto L_0x0042941f;
    }
    // 0042941a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x0042941f:
    // 0042941f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429420  e88cc6ffff             -call 0x425ab1
    cpu.esp -= 4;
    sub_425ab1(app, cpu);
    // 00429425  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429426  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429427  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429428  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429429  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_42942c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042942c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042942d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042942f  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00429431  68900a4300             -push 0x430a90
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393616 /*0x430a90*/;
    cpu.esp -= 4;
    // 00429436  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 0042943b  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00429441  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429442  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00429449  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042944a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042944b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042944c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042944d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042944e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00429451  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00429455  a144544900             -mov eax, dword ptr [0x495444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805700) /* 0x495444 */);
    // 0042945a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042945c  7416                   -je 0x429474
    if (cpu.flags.zf)
    {
        return sub_429474(app, cpu);
    }
    // 0042945e  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00429465  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429467  eb07                   -jmp 0x429470
    return sub_429470(app, cpu);
}

/* align: skip  */
void Application::asm_sub_429469(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429469  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042946b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042946c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42946d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042946d  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00429470  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00429474  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00429478  e800000000             -call 0x42947d
    cpu.esp -= 4;
    sub_42947d(app, cpu);
    // 0042947d  e962260000             -jmp 0x42bae4
    return sub_42bae4(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42947d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042947d;
    // 0042946d  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00429470  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00429474  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00429478  e800000000             -call 0x42947d
    cpu.esp -= 4;
    sub_42947d(app, cpu);
L_entry_0x0042947d:
    // 0042947d  e962260000             -jmp 0x42bae4
    return sub_42bae4(app, cpu);
}

/* align: skip  */
void Application::asm_sub_429474(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00429474;
    // 0042946d  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00429470  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_entry_0x00429474:
    // 00429474  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00429478  e800000000             -call 0x42947d
    cpu.esp -= 4;
    sub_42947d(app, cpu);
    // 0042947d  e962260000             -jmp 0x42bae4
    return sub_42bae4(app, cpu);
}

/* align: skip  */
void Application::asm_sub_429470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00429470;
    // 0042946d  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
L_entry_0x00429470:
    // 00429470  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00429474  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00429478  e800000000             -call 0x42947d
    cpu.esp -= 4;
    sub_42947d(app, cpu);
    // 0042947d  e962260000             -jmp 0x42bae4
    return sub_42bae4(app, cpu);
}

/* align: skip  */
void Application::asm_sub_429482(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429482  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429483  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429485  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00429487  68a80a4300             -push 0x430aa8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393640 /*0x430aa8*/;
    cpu.esp -= 4;
    // 0042948c  68f0664200             -push 0x4266f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4351728 /*0x4266f0*/;
    cpu.esp -= 4;
    // 00429491  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00429497  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429498  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0042949f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004294a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004294a1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004294a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004294a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004294a4  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004294a7  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004294ab  a164d34300             -mov eax, dword ptr [0x43d364]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445028) /* 0x43d364 */);
    // 004294b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004294b2  7416                   -je 0x4294ca
    if (cpu.flags.zf)
    {
        return sub_4294ca(app, cpu);
    }
    // 004294b4  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 004294bb  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004294bd  eb07                   -jmp 0x4294c6
    return sub_4294c6(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4294bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004294bf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004294c1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004294c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4294c3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004294c3  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004294c6  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004294ca  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004294ce  e800000000             -call 0x4294d3
    cpu.esp -= 4;
    sub_4294d3(app, cpu);
    // 004294d3  e954ffffff             -jmp 0x42942c
    return sub_42942c(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4294d3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004294d3;
    // 004294c3  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004294c6  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004294ca  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004294ce  e800000000             -call 0x4294d3
    cpu.esp -= 4;
    sub_4294d3(app, cpu);
L_entry_0x004294d3:
    // 004294d3  e954ffffff             -jmp 0x42942c
    return sub_42942c(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4294ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004294ca;
    // 004294c3  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004294c6  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_entry_0x004294ca:
    // 004294ca  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004294ce  e800000000             -call 0x4294d3
    cpu.esp -= 4;
    sub_4294d3(app, cpu);
    // 004294d3  e954ffffff             -jmp 0x42942c
    return sub_42942c(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4294c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004294c6;
    // 004294c3  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
L_entry_0x004294c6:
    // 004294c6  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004294ca  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004294ce  e800000000             -call 0x4294d3
    cpu.esp -= 4;
    sub_4294d3(app, cpu);
    // 004294d3  e954ffffff             -jmp 0x42942c
    return sub_42942c(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4294d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004294d8  6800000300             -push 0x30000
    app->getMemory<x86::reg32>(cpu.esp-4) = 196608 /*0x30000*/;
    cpu.esp -= 4;
    // 004294dd  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 004294e2  e849260000             -call 0x42bb30
    cpu.esp -= 4;
    sub_42bb30(app, cpu);
    // 004294e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004294e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004294e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4294ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004294ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004294eb  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004294ed  83ec18                 +sub esp, 0x18
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
    // 004294f0  dd05c80a4300           +fld qword ptr [0x430ac8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4393672) /* 0x430ac8 */)));
    // 004294f6  dd5df8                 +fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004294f9  dd05c00a4300           +fld qword ptr [0x430ac0]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4393664) /* 0x430ac0 */)));
    // 004294ff  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429502  dd45f0                 +fld qword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00429505  dc75f8                 +fdiv qword ptr [ebp - 8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 00429508  dc4df8                 +fmul qword ptr [ebp - 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 0042950b  dc6df0                 +fsubr qword ptr [ebp - 0x10]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) - cpu.fpu.st(0);
    // 0042950e  dd5de8                 +fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429511  dd45e8                 +fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00429514  dc1d40054300           +fcomp qword ptr [0x430540]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4392256) /* 0x430540 */)));
    cpu.fpu.pop();
    // 0042951a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042951c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0042951d  7605                   -jbe 0x429524
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00429524;
    }
    // 0042951f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429521  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429522  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429523  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429524:
    // 00429524  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00429526  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429527  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429528(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429528  68ec0a4300             -push 0x430aec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393708 /*0x430aec*/;
    cpu.esp -= 4;
    // 0042952d  ff1528004300           -call dword ptr [0x430028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390952) /* 0x430028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429533  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429535  7415                   -je 0x42954c
    if (cpu.flags.zf)
    {
        goto L_0x0042954c;
    }
    // 00429537  68d00a4300             -push 0x430ad0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393680 /*0x430ad0*/;
    cpu.esp -= 4;
    // 0042953c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042953d  ff15f8004300           -call dword ptr [0x4300f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391160) /* 0x4300f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429543  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429545  7405                   -je 0x42954c
    if (cpu.flags.zf)
    {
        goto L_0x0042954c;
    }
    // 00429547  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00429549  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042954b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042954c:
    // 0042954c  e999ffffff             -jmp 0x4294ea
    return sub_4294ea(app, cpu);
}

}
