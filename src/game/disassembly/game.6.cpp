#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_420bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420bf0  a10cca4a00             -mov eax, dword ptr [0x4aca0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901388) /* 0x4aca0c */);
    // 00420bf5  83f808                 +cmp eax, 8
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
    // 00420bf8  7f04                   -jg 0x420bfe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00420bfe;
    }
    // 00420bfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420bfc  7d15                   -jge 0x420c13
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420c13;
    }
L_0x00420bfe:
    // 00420bfe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420bff  68781f4900             -push 0x491f78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792184 /*0x491f78*/;
    cpu.esp -= 4;
    // 00420c04  e8ae610500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00420c09  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420c0c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420c0e  a30cca4a00             -mov dword ptr [0x4aca0c], eax
    app->getMemory<x86::reg32>(x86::reg32(4901388) /* 0x4aca0c */) = cpu.eax;
L_0x00420c13:
    // 00420c13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420c20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420c21  e86af0ffff             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 00420c26  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420c28  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00420c2a  750d                   -jne 0x420c39
    if (!cpu.flags.zf)
    {
        goto L_0x00420c39;
    }
    // 00420c2c  68b41f4900             -push 0x491fb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792244 /*0x491fb4*/;
    cpu.esp -= 4;
    // 00420c31  e8da3f0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420c36  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00420c39:
    // 00420c39  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00420c3d  dc0d98744800           -fmul qword ptr [0x487498]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748440) /* 0x487498 */));
    // 00420c43  dc15e0724800           -fcom qword ptr [0x4872e0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748000) /* 0x4872e0 */)));
    // 00420c49  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00420c4b  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00420c50  7508                   -jne 0x420c5a
    if (!cpu.flags.zf)
    {
        goto L_0x00420c5a;
    }
    // 00420c52  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00420c54  d905bc764800           -fld dword ptr [0x4876bc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748988) /* 0x4876bc */)));
L_0x00420c5a:
    // 00420c5a  d8ae28010000           -fsubr dword ptr [esi + 0x128]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(296) /* 0x128 */)) - cpu.fpu.st(0);
    // 00420c60  8b8634010000           -mov eax, dword ptr [esi + 0x134]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(308) /* 0x134 */);
    // 00420c66  40                     -inc eax
    (cpu.eax)++;
    // 00420c67  d99628010000           -fst dword ptr [esi + 0x128]
    app->getMemory<float>(cpu.esi + x86::reg32(296) /* 0x128 */) = float(cpu.fpu.st(0));
    // 00420c6d  898634010000           -mov dword ptr [esi + 0x134], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 00420c73  e818610500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00420c78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c79  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_420c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420c80  8b81fc020000           -mov eax, dword ptr [ecx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 00420c86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420c88  7418                   -je 0x420ca2
    if (cpu.flags.zf)
    {
        goto L_0x00420ca2;
    }
    // 00420c8a  399010010000           +cmp dword ptr [eax + 0x110], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420c90  7410                   -je 0x420ca2
    if (cpu.flags.zf)
    {
        goto L_0x00420ca2;
    }
    // 00420c92  899010010000           -mov dword ptr [eax + 0x110], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 00420c98  c7800c01000001000000   -mov dword ptr [eax + 0x10c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(268) /* 0x10c */) = 1 /*0x1*/;
L_0x00420ca2:
    // 00420ca2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420cb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420cb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420cb3  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00420cb5  c704bde4c94a0001000000 -mov dword ptr [edi*4 + 0x4ac9e4], 1
    app->getMemory<x86::reg32>(x86::reg32(4901348) /* 0x4ac9e4 */ + cpu.edi * 4) = 1 /*0x1*/;
    // 00420cc0  e86bfeffff             -call 0x420b30
    cpu.esp -= 4;
    sub_420b30(app, cpu);
    // 00420cc5  e8e6efffff             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 00420cca  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00420ccc  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00420cce  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00420cd0  7e15                   -jle 0x420ce7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00420ce7;
    }
L_0x00420cd2:
    // 00420cd2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420cd4  e807f4ffff             -call 0x4200e0
    cpu.esp -= 4;
    sub_4200e0(app, cpu);
    // 00420cd9  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00420cdb  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420cdd  e80e000000             -call 0x420cf0
    cpu.esp -= 4;
    sub_420cf0(app, cpu);
    // 00420ce2  46                     -inc esi
    (cpu.esi)++;
    // 00420ce3  3bf3                   +cmp esi, ebx
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
    // 00420ce5  7ceb                   -jl 0x420cd2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420cd2;
    }
L_0x00420ce7:
    // 00420ce7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ce8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ce9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420cf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420cf1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420cf2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420cf4  7c7b                   -jl 0x420d71
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420d71;
    }
    // 00420cf6  83fa0a                 +cmp edx, 0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420cf9  7d76                   -jge 0x420d71
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420d71;
    }
    // 00420cfb  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420cfe  7471                   -je 0x420d71
    if (cpu.flags.zf)
    {
        goto L_0x00420d71;
    }
    // 00420d00  8bb1fc020000           -mov esi, dword ptr [ecx + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 00420d06  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00420d08  7475                   -je 0x420d7f
    if (cpu.flags.zf)
    {
        goto L_0x00420d7f;
    }
    // 00420d0a  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00420d10  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00420d12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420d14  7469                   -je 0x420d7f
    if (cpu.flags.zf)
    {
        goto L_0x00420d7f;
    }
L_0x00420d16:
    // 00420d16  3910                   +cmp dword ptr [eax], edx
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
    // 00420d18  740c                   -je 0x420d26
    if (cpu.flags.zf)
    {
        goto L_0x00420d26;
    }
    // 00420d1a  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420d1c  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00420d1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420d21  75f3                   -jne 0x420d16
    if (!cpu.flags.zf)
    {
        goto L_0x00420d16;
    }
    // 00420d23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420d26:
    // 00420d26  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00420d28  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00420d2b  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00420d2e  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00420d31  c7043200000000         -mov dword ptr [edx + esi], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1) = 0 /*0x0*/;
    // 00420d38  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00420d3a  c784378c00000000000000 -mov dword ptr [edi + esi + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(140) /* 0x8c */ + cpu.esi * 1) = 0 /*0x0*/;
    // 00420d45  8b8e80000000           -mov ecx, dword ptr [esi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00420d4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420d4c  c7861c0100000000f041   -mov dword ptr [esi + 0x11c], 0x41f00000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */) = 1106247680 /*0x41f00000*/;
    // 00420d56  e865f6ffff             -call 0x4203c0
    cpu.esp -= 4;
    sub_4203c0(app, cpu);
    // 00420d5b  898680000000           -mov dword ptr [esi + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 00420d61  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00420d67  48                     -dec eax
    (cpu.eax)--;
    // 00420d68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d69  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00420d6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420d71:
    // 00420d71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420d72  68201f4900             -push 0x491f20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792096 /*0x491f20*/;
    cpu.esp -= 4;
    // 00420d77  e8943e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420d7c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00420d7f:
    // 00420d7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420d90  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420d95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420d96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420d98  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00420d9a  750d                   -jne 0x420da9
    if (!cpu.flags.zf)
    {
        goto L_0x00420da9;
    }
    // 00420d9c  68d01f4900             -push 0x491fd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792272 /*0x491fd0*/;
    cpu.esp -= 4;
    // 00420da1  e86a3e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420da6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00420da9:
    // 00420da9  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420dae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420daf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420db1  6808010000             -push 0x108
    app->getMemory<x86::reg32>(cpu.esp-4) = 264 /*0x108*/;
    cpu.esp -= 4;
    // 00420db6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420db7  e8e3690500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00420dbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420dbd  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00420dbf  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00420dc1  68e4c94a00             -push 0x4ac9e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4901348 /*0x4ac9e4*/;
    cpu.esp -= 4;
    // 00420dc6  e8d4690500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00420dcb  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00420dce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420dcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420dd0  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420dd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420dd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420dd8  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00420dda  750d                   -jne 0x420de9
    if (!cpu.flags.zf)
    {
        goto L_0x00420de9;
    }
    // 00420ddc  68f81f4900             -push 0x491ff8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792312 /*0x491ff8*/;
    cpu.esp -= 4;
    // 00420de1  e82a3e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420de6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00420de9:
    // 00420de9  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420dee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420def  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420df1  6808010000             -push 0x108
    app->getMemory<x86::reg32>(cpu.esp-4) = 264 /*0x108*/;
    cpu.esp -= 4;
    // 00420df6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420df7  e88c680500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00420dfc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420dfd  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00420dff  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00420e01  68e4c94a00             -push 0x4ac9e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4901348 /*0x4ac9e4*/;
    cpu.esp -= 4;
    // 00420e06  e87d680500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00420e0b  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00420e0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420e10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420e11  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00420e13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420e14  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420e16  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 00420e18  6860185200             -push 0x521860
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380192 /*0x521860*/;
    cpu.esp -= 4;
    // 00420e1d  e87d690500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00420e22  a1a0185200             -mov eax, dword ptr [0x5218a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */);
    // 00420e27  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420e2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420e2c  0f848a000000           -je 0x420ebc
    if (cpu.flags.zf)
    {
        goto L_0x00420ebc;
    }
    // 00420e32  833d9c185200ff         +cmp dword ptr [0x52189c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420e39  7465                   -je 0x420ea0
    if (cpu.flags.zf)
    {
        goto L_0x00420ea0;
    }
    // 00420e3b  8b882c010000           -mov ecx, dword ptr [eax + 0x12c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(300) /* 0x12c */);
    // 00420e41  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00420e47  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420e48  8db82c010000           -lea edi, [eax + 0x12c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(300) /* 0x12c */);
    // 00420e4e  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00420e51  3b81fc020000           +cmp eax, dword ptr [ecx + 0x2fc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420e57  740d                   -je 0x420e66
    if (cpu.flags.zf)
    {
        goto L_0x00420e66;
    }
    // 00420e59  68e8204900             -push 0x4920e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792552 /*0x4920e8*/;
    cpu.esp -= 4;
    // 00420e5e  e8ad3d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420e63  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00420e66:
    // 00420e66  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00420e68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420e6a  7c08                   -jl 0x420e74
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420e74;
    }
    // 00420e6c  3b052c845100           +cmp eax, dword ptr [0x51842c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420e72  7c0e                   -jl 0x420e82
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420e82;
    }
L_0x00420e74:
    // 00420e74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420e75  6898204900             -push 0x492098
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792472 /*0x492098*/;
    cpu.esp -= 4;
    // 00420e7a  e8913d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420e7f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00420e82:
    // 00420e82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420e83  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420e85  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00420e87  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420e88  e812690500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00420e8d  83c410                 +add esp, 0x10
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
    // 00420e90  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420e92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e93  e878010000             -call 0x421010
    cpu.esp -= 4;
    sub_421010(app, cpu);
    // 00420e98  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420e9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e9b  e9c0010000             -jmp 0x421060
    return sub_421060(app, cpu);
L_0x00420ea0:
    // 00420ea0  6850204900             -push 0x492050
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792400 /*0x492050*/;
    cpu.esp -= 4;
    // 00420ea5  e8663d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420eaa  83c404                 +add esp, 4
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
    // 00420ead  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420eaf  e85c010000             -call 0x421010
    cpu.esp -= 4;
    sub_421010(app, cpu);
    // 00420eb4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420eb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420eb7  e9a4010000             -jmp 0x421060
    return sub_421060(app, cpu);
L_0x00420ebc:
    // 00420ebc  a19c185200             -mov eax, dword ptr [0x52189c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */);
    // 00420ec1  83f8ff                 +cmp eax, -1
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
    // 00420ec4  740e                   -je 0x420ed4
    if (cpu.flags.zf)
    {
        goto L_0x00420ed4;
    }
    // 00420ec6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420ec7  6820204900             -push 0x492020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792352 /*0x492020*/;
    cpu.esp -= 4;
    // 00420ecc  e83f3d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420ed1  83c408                 +add esp, 8
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
L_0x00420ed4:
    // 00420ed4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420ed6  e835010000             -call 0x421010
    cpu.esp -= 4;
    sub_421010(app, cpu);
    // 00420edb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420edd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ede  e97d010000             -jmp 0x421060
    return sub_421060(app, cpu);
}

/* align: skip  */
void Application::sub_420ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420ef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420ef1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420ef2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00420ef4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420ef5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420ef7  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 00420ef9  6860185200             -push 0x521860
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380192 /*0x521860*/;
    cpu.esp -= 4;
    // 00420efe  e885670500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00420f03  a1a0185200             -mov eax, dword ptr [0x5218a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */);
    // 00420f08  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420f0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420f0d  0f849d000000           -je 0x420fb0
    if (cpu.flags.zf)
    {
        goto L_0x00420fb0;
    }
    // 00420f13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420f14  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420f16  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00420f1a  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00420f1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420f1d  e866670500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00420f22  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00420f26  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420f29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420f2b  7d12                   -jge 0x420f3f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420f3f;
    }
    // 00420f2d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420f2e  683c224900             -push 0x49223c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792892 /*0x49223c*/;
    cpu.esp -= 4;
    // 00420f33  e8d83c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420f38  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00420f3c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00420f3f:
    // 00420f3f  8b0d2c845100           -mov ecx, dword ptr [0x51842c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 00420f45  3bc1                   +cmp eax, ecx
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
    // 00420f47  7c13                   -jl 0x420f5c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420f5c;
    }
    // 00420f49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420f4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420f4b  680c224900             -push 0x49220c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792844 /*0x49220c*/;
    cpu.esp -= 4;
    // 00420f50  e8bb3c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420f55  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00420f59  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00420f5c:
    // 00420f5c  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00420f62  833c8100               +cmp dword ptr [ecx + eax*4], 0
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
    // 00420f66  750e                   -jne 0x420f76
    if (!cpu.flags.zf)
    {
        goto L_0x00420f76;
    }
    // 00420f68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420f69  68cc214900             -push 0x4921cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792780 /*0x4921cc*/;
    cpu.esp -= 4;
    // 00420f6e  e89d3c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420f73  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00420f76:
    // 00420f76  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420f78  e863010000             -call 0x4210e0
    cpu.esp -= 4;
    sub_4210e0(app, cpu);
    // 00420f7d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420f7f  e84c020000             -call 0x4211d0
    cpu.esp -= 4;
    sub_4211d0(app, cpu);
    // 00420f84  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420f88  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00420f8d  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00420f90  8bb1fc020000           -mov esi, dword ptr [ecx + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 00420f96  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00420f98  750d                   -jne 0x420fa7
    if (!cpu.flags.zf)
    {
        goto L_0x00420fa7;
    }
    // 00420f9a  6880214900             -push 0x492180
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792704 /*0x492180*/;
    cpu.esp -= 4;
    // 00420f9f  e86c3c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420fa4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00420fa7:
    // 00420fa7  8935a0185200           -mov dword ptr [0x5218a0], esi
    app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */) = cpu.esi;
    // 00420fad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420fae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420faf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420fb0:
    // 00420fb0  a19c185200             -mov eax, dword ptr [0x52189c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */);
    // 00420fb5  83f8ff                 +cmp eax, -1
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
    // 00420fb8  740e                   -je 0x420fc8
    if (cpu.flags.zf)
    {
        goto L_0x00420fc8;
    }
    // 00420fba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420fbb  6838214900             -push 0x492138
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792632 /*0x492138*/;
    cpu.esp -= 4;
    // 00420fc0  e84b3c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420fc5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00420fc8:
    // 00420fc8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420fca  e811010000             -call 0x4210e0
    cpu.esp -= 4;
    sub_4210e0(app, cpu);
    // 00420fcf  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420fd1  e8fa010000             -call 0x4211d0
    cpu.esp -= 4;
    sub_4211d0(app, cpu);
    // 00420fd6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420fd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420fd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420fe0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420fe1  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00420fe3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420fe4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420fe5  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00420fe7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420fe9  683c010000             -push 0x13c
    app->getMemory<x86::reg32>(cpu.esp-4) = 316 /*0x13c*/;
    cpu.esp -= 4;
    // 00420fee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420fef  e8ab670500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00420ff4  83c410                 +add esp, 0x10
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
    // 00420ff7  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00420ff9  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00420ffb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ffc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ffd  e9cedbffff             -jmp 0x41ebd0
    return sub_41ebd0(app, cpu);
}

/* align: skip  */
void Application::sub_421010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421010  a16c185200             -mov eax, dword ptr [0x52186c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 00421015  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421016  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421017  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421019  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042101b  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042101d  7e2f                   -jle 0x42104e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042104e;
    }
    // 0042101f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00421020:
    // 00421020  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00421022  e8d9f0ffff             -call 0x420100
    cpu.esp -= 4;
    sub_420100(app, cpu);
    // 00421027  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00421029  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042102b  750d                   -jne 0x42103a
    if (!cpu.flags.zf)
    {
        goto L_0x0042103a;
    }
    // 0042102d  6864224900             -push 0x492264
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792932 /*0x492264*/;
    cpu.esp -= 4;
    // 00421032  e8d93b0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421037  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042103a:
    // 0042103a  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042103c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042103e  e89dffffff             -call 0x420fe0
    cpu.esp -= 4;
    sub_420fe0(app, cpu);
    // 00421043  a16c185200             -mov eax, dword ptr [0x52186c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 00421048  46                     -inc esi
    (cpu.esi)++;
    // 00421049  3bf0                   +cmp esi, eax
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
    // 0042104b  7cd3                   -jl 0x421020
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421020;
    }
    // 0042104d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042104e:
    // 0042104e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042104f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421050  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421060  a198185200             -mov eax, dword ptr [0x521898]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */);
    // 00421065  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421066  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421067  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421069  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042106b  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042106d  7e2f                   -jle 0x42109e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042109e;
    }
    // 0042106f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00421070:
    // 00421070  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00421072  e8b9f0ffff             -call 0x420130
    cpu.esp -= 4;
    sub_420130(app, cpu);
    // 00421077  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00421079  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042107b  750d                   -jne 0x42108a
    if (!cpu.flags.zf)
    {
        goto L_0x0042108a;
    }
    // 0042107d  68a0224900             -push 0x4922a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792992 /*0x4922a0*/;
    cpu.esp -= 4;
    // 00421082  e8893b0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421087  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042108a:
    // 0042108a  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042108c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042108e  e84dffffff             -call 0x420fe0
    cpu.esp -= 4;
    sub_420fe0(app, cpu);
    // 00421093  a198185200             -mov eax, dword ptr [0x521898]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */);
    // 00421098  46                     -inc esi
    (cpu.esi)++;
    // 00421099  3bf0                   +cmp esi, eax
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
    // 0042109b  7cd3                   -jl 0x421070
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421070;
    }
    // 0042109d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042109e:
    // 0042109e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042109f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004210a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4210b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004210b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004210b1  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004210b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004210b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004210b5  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004210b7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004210b9  683c010000             -push 0x13c
    app->getMemory<x86::reg32>(cpu.esp-4) = 316 /*0x13c*/;
    cpu.esp -= 4;
    // 004210be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004210bf  e8c4650500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004210c4  83c410                 +add esp, 0x10
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
    // 004210c7  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004210c9  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004210cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004210cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004210cd  e90eddffff             -jmp 0x41ede0
    return sub_41ede0(app, cpu);
}

/* align: skip  */
void Application::sub_4210e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004210e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004210e1  a16c185200             -mov eax, dword ptr [0x52186c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 004210e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004210e7  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004210e9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004210ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004210ef  0f8ed3000000           -jle 0x4211c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004211c8;
    }
    // 004210f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004210f6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004210f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004210f8:
    // 004210f8  8b349d60185200         -mov esi, dword ptr [ebx*4 + 0x521860]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5380192) /* 0x521860 */ + cpu.ebx * 4);
    // 004210ff  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421101  7c08                   -jl 0x42110b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042110b;
    }
    // 00421103  3b352c845100           +cmp esi, dword ptr [0x51842c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421109  7e0e                   -jle 0x421119
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00421119;
    }
L_0x0042110b:
    // 0042110b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042110c  6800244900             -push 0x492400
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793344 /*0x492400*/;
    cpu.esp -= 4;
    // 00421111  e8fa3a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421116  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00421119:
    // 00421119  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042111e  833cb000               +cmp dword ptr [eax + esi*4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421122  750e                   -jne 0x421132
    if (!cpu.flags.zf)
    {
        goto L_0x00421132;
    }
    // 00421124  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421125  68c4234900             -push 0x4923c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793284 /*0x4923c4*/;
    cpu.esp -= 4;
    // 0042112a  e8e13a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042112f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00421132:
    // 00421132  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421138  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042113b  f682f802000008         +test byte ptr [edx + 0x2f8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(760) /* 0x2f8 */) & 8 /*0x8*/));
    // 00421142  750d                   -jne 0x421151
    if (!cpu.flags.zf)
    {
        goto L_0x00421151;
    }
    // 00421144  6868234900             -push 0x492368
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793192 /*0x492368*/;
    cpu.esp -= 4;
    // 00421149  e8c23a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042114e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00421151:
    // 00421151  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421156  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00421159  8ba9fc020000           -mov ebp, dword ptr [ecx + 0x2fc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0042115f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421161  750d                   -jne 0x421170
    if (!cpu.flags.zf)
    {
        goto L_0x00421170;
    }
    // 00421163  6818234900             -push 0x492318
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793112 /*0x492318*/;
    cpu.esp -= 4;
    // 00421168  e8a33a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042116d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00421170:
    // 00421170  e8bbdeffff             -call 0x41f030
    cpu.esp -= 4;
    sub_41f030(app, cpu);
    // 00421175  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00421179  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042117b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042117d  e82effffff             -call 0x4210b0
    cpu.esp -= 4;
    sub_4210b0(app, cpu);
    // 00421182  8b4748                 -mov eax, dword ptr [edi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */);
    // 00421185  8b4d48                 -mov ecx, dword ptr [ebp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 00421188  3bc1                   +cmp eax, ecx
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
    // 0042118a  740f                   -je 0x42119b
    if (cpu.flags.zf)
    {
        goto L_0x0042119b;
    }
    // 0042118c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042118d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042118e  68dc224900             -push 0x4922dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793052 /*0x4922dc*/;
    cpu.esp -= 4;
    // 00421193  e8783a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421198  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042119b:
    // 0042119b  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004211a1  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004211a3  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 004211a6  89b8fc020000           -mov dword ptr [eax + 0x2fc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(764) /* 0x2fc */) = cpu.edi;
    // 004211ac  89b72c010000           -mov dword ptr [edi + 0x12c], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(300) /* 0x12c */) = cpu.esi;
    // 004211b2  e819f0ffff             -call 0x4201d0
    cpu.esp -= 4;
    sub_4201d0(app, cpu);
    // 004211b7  a16c185200             -mov eax, dword ptr [0x52186c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 004211bc  43                     -inc ebx
    (cpu.ebx)++;
    // 004211bd  3bd8                   +cmp ebx, eax
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
    // 004211bf  0f8c33ffffff           -jl 0x4210f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004210f8;
    }
    // 004211c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004211c8:
    // 004211c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4211d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004211d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004211d1  a198185200             -mov eax, dword ptr [0x521898]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */);
    // 004211d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004211d7  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004211d9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004211dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004211df  0f8ed3000000           -jle 0x4212b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004212b8;
    }
    // 004211e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004211e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004211e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004211e8:
    // 004211e8  8b349d70185200         -mov esi, dword ptr [ebx*4 + 0x521870]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5380208) /* 0x521870 */ + cpu.ebx * 4);
    // 004211ef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004211f1  7c08                   -jl 0x4211fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004211fb;
    }
    // 004211f3  3b352c845100           +cmp esi, dword ptr [0x51842c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004211f9  7e0e                   -jle 0x421209
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00421209;
    }
L_0x004211fb:
    // 004211fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004211fc  6858254900             -push 0x492558
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793688 /*0x492558*/;
    cpu.esp -= 4;
    // 00421201  e80a3a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421206  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00421209:
    // 00421209  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042120e  833cb000               +cmp dword ptr [eax + esi*4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421212  750e                   -jne 0x421222
    if (!cpu.flags.zf)
    {
        goto L_0x00421222;
    }
    // 00421214  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421215  681c254900             -push 0x49251c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793628 /*0x49251c*/;
    cpu.esp -= 4;
    // 0042121a  e8f1390000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042121f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00421222:
    // 00421222  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421228  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042122b  f682f802000008         +test byte ptr [edx + 0x2f8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(760) /* 0x2f8 */) & 8 /*0x8*/));
    // 00421232  750d                   -jne 0x421241
    if (!cpu.flags.zf)
    {
        goto L_0x00421241;
    }
    // 00421234  68c0244900             -push 0x4924c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793536 /*0x4924c0*/;
    cpu.esp -= 4;
    // 00421239  e8d2390000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042123e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00421241:
    // 00421241  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421246  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00421249  8ba9fc020000           -mov ebp, dword ptr [ecx + 0x2fc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0042124f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421251  750d                   -jne 0x421260
    if (!cpu.flags.zf)
    {
        goto L_0x00421260;
    }
    // 00421253  6870244900             -push 0x492470
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793456 /*0x492470*/;
    cpu.esp -= 4;
    // 00421258  e8b3390000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042125d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00421260:
    // 00421260  e8cbddffff             -call 0x41f030
    cpu.esp -= 4;
    sub_41f030(app, cpu);
    // 00421265  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00421269  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042126b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042126d  e83efeffff             -call 0x4210b0
    cpu.esp -= 4;
    sub_4210b0(app, cpu);
    // 00421272  8b4748                 -mov eax, dword ptr [edi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */);
    // 00421275  8b4d48                 -mov ecx, dword ptr [ebp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 00421278  3bc1                   +cmp eax, ecx
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
    // 0042127a  740f                   -je 0x42128b
    if (cpu.flags.zf)
    {
        goto L_0x0042128b;
    }
    // 0042127c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042127d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042127e  6830244900             -push 0x492430
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793392 /*0x492430*/;
    cpu.esp -= 4;
    // 00421283  e888390000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421288  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042128b:
    // 0042128b  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421291  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00421293  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00421296  89b8fc020000           -mov dword ptr [eax + 0x2fc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(764) /* 0x2fc */) = cpu.edi;
    // 0042129c  89b72c010000           -mov dword ptr [edi + 0x12c], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(300) /* 0x12c */) = cpu.esi;
    // 004212a2  e829efffff             -call 0x4201d0
    cpu.esp -= 4;
    sub_4201d0(app, cpu);
    // 004212a7  a198185200             -mov eax, dword ptr [0x521898]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */);
    // 004212ac  43                     -inc ebx
    (cpu.ebx)++;
    // 004212ad  3bd8                   +cmp ebx, eax
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
    // 004212af  0f8c33ffffff           -jl 0x4211e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004211e8;
    }
    // 004212b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004212b8:
    // 004212b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4212c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004212c0  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004212c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004212c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004212c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004212c6  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004212c8  bea0184900             -mov esi, 0x4918a0
    cpu.esi = 4790432 /*0x4918a0*/;
    // 004212cd  bffdffffff             -mov edi, 0xfffffffd
    cpu.edi = 4294967293 /*0xfffffffd*/;
L_0x004212d2:
    // 004212d2  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004212d4  e8b7160100             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 004212d9  83f8ff                 +cmp eax, -1
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
    // 004212dc  7512                   -jne 0x4212f0
    if (!cpu.flags.zf)
    {
        goto L_0x004212f0;
    }
    // 004212de  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004212e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004212e1  68c0254900             -push 0x4925c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793792 /*0x4925c0*/;
    cpu.esp -= 4;
    // 004212e6  e8cc5a0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004212eb  83c408                 +add esp, 8
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
    // 004212ee  eb25                   -jmp 0x421315
    goto L_0x00421315;
L_0x004212f0:
    // 004212f0  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004212f6  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004212f9  8b91a8020000           -mov edx, dword ptr [ecx + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 004212ff  23d7                   -and edx, edi
    cpu.edx &= x86::reg32(x86::sreg32(cpu.edi));
    // 00421301  8991a8020000           -mov dword ptr [ecx + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 00421307  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042130d  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00421310  e80b920200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
L_0x00421315:
    // 00421315  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421318  81feac184900           +cmp esi, 0x4918ac
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4790444 /*0x4918ac*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042131e  7cb2                   -jl 0x4212d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004212d2;
    }
    // 00421320  e88be9ffff             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 00421325  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00421327  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042132b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042132d  0f8eb4000000           -jle 0x4213e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004213e7;
    }
    // 00421333  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00421334:
    // 00421334  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00421336  e8a5edffff             -call 0x4200e0
    cpu.esp -= 4;
    sub_4200e0(app, cpu);
    // 0042133b  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042133d  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042133f  e8dcfc0000             -call 0x431020
    cpu.esp -= 4;
    sub_431020(app, cpu);
    // 00421344  83e807                 +sub eax, 7
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421347  7422                   -je 0x42136b
    if (cpu.flags.zf)
    {
        goto L_0x0042136b;
    }
    // 00421349  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042134a  7418                   -je 0x421364
    if (cpu.flags.zf)
    {
        goto L_0x00421364;
    }
    // 0042134c  83e803                 +sub eax, 3
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
    // 0042134f  740f                   -je 0x421360
    if (cpu.flags.zf)
    {
        goto L_0x00421360;
    }
    // 00421351  6898254900             -push 0x492598
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793752 /*0x492598*/;
    cpu.esp -= 4;
    // 00421356  e85c5a0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042135b  83c404                 +add esp, 4
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
    // 0042135e  eb10                   -jmp 0x421370
    goto L_0x00421370;
L_0x00421360:
    // 00421360  33ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00421362  eb0c                   -jmp 0x421370
    goto L_0x00421370;
L_0x00421364:
    // 00421364  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00421369  eb05                   -jmp 0x421370
    goto L_0x00421370;
L_0x0042136b:
    // 0042136b  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
L_0x00421370:
    // 00421370  8b0cada0184900         -mov ecx, dword ptr [ebp*4 + 0x4918a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4790432) /* 0x4918a0 */ + cpu.ebp * 4);
    // 00421377  e814160100             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 0042137c  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421382  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00421385  8b8ea8020000           -mov ecx, dword ptr [esi + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 0042138b  83c902                 -or ecx, 2
    cpu.ecx |= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042138e  898ea8020000           -mov dword ptr [esi + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 00421394  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042139a  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0042139d  e87e910200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 004213a2  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004213a4  e8c7d5ffff             -call 0x41e970
    cpu.esp -= 4;
    sub_41e970(app, cpu);
    // 004213a9  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004213ab  e8d089ffff             -call 0x419d80
    cpu.esp -= 4;
    sub_419d80(app, cpu);
    // 004213b0  40                     -inc eax
    (cpu.eax)++;
    // 004213b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004213b2  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004213b6  6888254900             -push 0x492588
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793736 /*0x492588*/;
    cpu.esp -= 4;
    // 004213bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004213bc  e8375a0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004213c1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004213c4  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004213c6  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004213ca  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004213d0  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004213d2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004213d4  e817000000             -call 0x4213f0
    cpu.esp -= 4;
    sub_4213f0(app, cpu);
    // 004213d9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004213dd  47                     -inc edi
    (cpu.edi)++;
    // 004213de  3bf8                   +cmp edi, eax
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
    // 004213e0  0f8c4effffff           -jl 0x421334
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421334;
    }
    // 004213e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004213e7:
    // 004213e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213ea  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004213ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4213f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004213f0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004213f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004213f4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004213f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004213f7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004213f9  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004213fb  e8a0d20300             -call 0x45e6a0
    cpu.esp -= 4;
    sub_45e6a0(app, cpu);
    // 00421400  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 00421406  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00421409  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0042140c  80cc40                 -or ah, 0x40
    cpu.ah |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0042140f  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 00421415  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00421418  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042141c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00421420  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00421424  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00421426:
    // 00421426  8b4c9408               -mov ecx, dword ptr [esp + edx*4 + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.edx * 4);
    // 0042142a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042142c  8b7118                 -mov esi, dword ptr [ecx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0042142f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421431  7e12                   -jle 0x421445
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00421445;
    }
L_0x00421433:
    // 00421433  8b711c                 -mov esi, dword ptr [ecx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00421436  40                     -inc eax
    (cpu.eax)++;
    // 00421437  8b7486fc               -mov esi, dword ptr [esi + eax*4 - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4);
    // 0042143b  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0042143e  8b7118                 -mov esi, dword ptr [ecx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00421441  3bc6                   +cmp eax, esi
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
    // 00421443  7cee                   -jl 0x421433
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421433;
    }
L_0x00421445:
    // 00421445  42                     -inc edx
    (cpu.edx)++;
    // 00421446  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421449  7cdb                   -jl 0x421426
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421426;
    }
    // 0042144b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042144c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042144e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042144f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00421452  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421460  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 00421465  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421466  3c06                   +cmp al, 6
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421468  7725                   -ja 0x42148f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042148f;
    }
    // 0042146a  e8c1420400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042146f  d825ac184900           -fsub dword ptr [0x4918ac]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4790444) /* 0x4918ac */));
    // 00421475  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0042147b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042147d  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00421480  7a0f                   -jp 0x421491
    if (cpu.flags.pf)
    {
        goto L_0x00421491;
    }
    // 00421482  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00421484  e8a7420400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00421489  d91dac184900           -fstp dword ptr [0x4918ac]
    app->getMemory<float>(x86::reg32(4790444) /* 0x4918ac */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042148f:
    // 0042148f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421490  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421491:
    // 00421491  d81d90744800           -fcomp dword ptr [0x487490]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748432) /* 0x487490 */)));
    cpu.fpu.pop();
    // 00421497  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00421499  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042149c  7bf1                   -jnp 0x42148f
    if (!cpu.flags.pf)
    {
        goto L_0x0042148f;
    }
    // 0042149e  e88d420400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004214a3  d91dac184900           -fstp dword ptr [0x4918ac]
    app->getMemory<float>(x86::reg32(4790444) /* 0x4918ac */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004214a9  e8b2f4ffff             -call 0x420960
    cpu.esp -= 4;
    sub_420960(app, cpu);
    // 004214ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004214b0  74dd                   -je 0x42148f
    if (cpu.flags.zf)
    {
        goto L_0x0042148f;
    }
    // 004214b2  e8f966ffff             -call 0x417bb0
    cpu.esp -= 4;
    sub_417bb0(app, cpu);
    // 004214b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004214b9  74d4                   -je 0x42148f
    if (cpu.flags.zf)
    {
        goto L_0x0042148f;
    }
    // 004214bb  e8309effff             -call 0x41b2f0
    cpu.esp -= 4;
    sub_41b2f0(app, cpu);
    // 004214c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004214c2  74cb                   -je 0x42148f
    if (cpu.flags.zf)
    {
        goto L_0x0042148f;
    }
    // 004214c4  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004214c9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004214cb  8bb118030000           -mov esi, dword ptr [ecx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 004214d1  b9fc254900             -mov ecx, 0x4925fc
    cpu.ecx = 4793852 /*0x4925fc*/;
    // 004214d6  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004214d8  e833570400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 004214dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004214df  74ae                   -je 0x42148f
    if (cpu.flags.zf)
    {
        goto L_0x0042148f;
    }
    // 004214e1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004214e3  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004214e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004214e6  e935520400             -jmp 0x466720
    return sub_466720(app, cpu);
}

/* align: skip  */
void Application::sub_4214f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004214f0  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004214f3  a11c264900             -mov eax, dword ptr [0x49261c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4793884) /* 0x49261c */);
    // 004214f8  8b1518264900           -mov edx, dword ptr [0x492618]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4793880) /* 0x492618 */);
    // 004214fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004214ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421500  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00421502  8b0d20264900           -mov ecx, dword ptr [0x492620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4793888) /* 0x492620 */);
    // 00421508  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421509  89442416               -mov dword ptr [esp + 0x16], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(22) /* 0x16 */) = cpu.eax;
    // 0042150d  894c241a               -mov dword ptr [esp + 0x1a], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(26) /* 0x1a */) = cpu.ecx;
    // 00421511  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 00421516  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421518  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0042151a  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0042151c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042151e  680c264900             -push 0x49260c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793868 /*0x49260c*/;
    cpu.esp -= 4;
    // 00421523  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421524  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00421526  c644241801             -mov byte ptr [esp + 0x18], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) = 1 /*0x1*/;
    // 0042152b  885c2419               -mov byte ptr [esp + 0x19], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(25) /* 0x19 */) = cpu.bl;
    // 0042152f  885c241a               -mov byte ptr [esp + 0x1a], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(26) /* 0x1a */) = cpu.bl;
    // 00421533  c644241b02             -mov byte ptr [esp + 0x1b], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(27) /* 0x1b */) = 2 /*0x2*/;
    // 00421538  885c241c               -mov byte ptr [esp + 0x1c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.bl;
    // 0042153c  885c241d               -mov byte ptr [esp + 0x1d], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) = cpu.bl;
    // 00421540  885c241e               -mov byte ptr [esp + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 00421544  885c241f               -mov byte ptr [esp + 0x1f], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(31) /* 0x1f */) = cpu.bl;
    // 00421548  885c2420               -mov byte ptr [esp + 0x20], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.bl;
    // 0042154c  885c2421               -mov byte ptr [esp + 0x21], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(33) /* 0x21 */) = cpu.bl;
    // 00421550  8954244a               -mov dword ptr [esp + 0x4a], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(74) /* 0x4a */) = cpu.edx;
    // 00421554  c644245e80             -mov byte ptr [esp + 0x5e], 0x80
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(94) /* 0x5e */) = 128 /*0x80*/;
    // 00421559  885c245f               -mov byte ptr [esp + 0x5f], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(95) /* 0x5f */) = cpu.bl;
    // 0042155d  66895c2460             -mov word ptr [esp + 0x60], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.bx;
    // 00421562  66895c2462             -mov word ptr [esp + 0x62], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(98) /* 0x62 */) = cpu.bx;
    // 00421567  885c2464               -mov byte ptr [esp + 0x64], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.bl;
    // 0042156b  885c2465               -mov byte ptr [esp + 0x65], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(101) /* 0x65 */) = cpu.bl;
    // 0042156f  885c2466               -mov byte ptr [esp + 0x66], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(102) /* 0x66 */) = cpu.bl;
    // 00421573  885c2467               -mov byte ptr [esp + 0x67], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(103) /* 0x67 */) = cpu.bl;
    // 00421577  885c2468               -mov byte ptr [esp + 0x68], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.bl;
    // 0042157b  885c2469               -mov byte ptr [esp + 0x69], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(105) /* 0x69 */) = cpu.bl;
    // 0042157f  e83c680500             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 00421584  885e0f                 -mov byte ptr [esi + 0xf], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.bl;
    // 00421587  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0042158a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0042158f  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00421593  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00421595  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00421598  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0042159a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042159b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042159c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042159d  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004215a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4215b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004215b0  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004215b6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004215b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004215b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004215ba  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004215bc  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004215c1  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004215c5  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004215c7  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 004215c9  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 004215ce  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004215d0  6824264900             -push 0x492624
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793892 /*0x492624*/;
    cpu.esp -= 4;
    // 004215d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004215d6  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 004215d8  e8e3670500             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 004215dd  c6460f00               -mov byte ptr [esi + 0xf], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004215e1  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004215e4  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004215e9  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004215ed  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004215f0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004215f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004215f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004215f4  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004215fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421600  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00421603  b080                   -mov al, 0x80
    cpu.al = 128 /*0x80*/;
    // 00421605  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421606  88442407               -mov byte ptr [esp + 7], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0042160a  88442408               -mov byte ptr [esp + 8], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0042160e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421613  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00421615  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421616  8844240d               -mov byte ptr [esp + 0xd], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0042161a  89442419               -mov dword ptr [esp + 0x19], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(25) /* 0x19 */) = cpu.eax;
    // 0042161e  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 00421623  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421625  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00421627  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00421629  6830264900             -push 0x492630
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793904 /*0x492630*/;
    cpu.esp -= 4;
    // 0042162e  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00421630  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421631  c6442414c0             -mov byte ptr [esp + 0x14], 0xc0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = 192 /*0xc0*/;
    // 00421636  c644241550             -mov byte ptr [esp + 0x15], 0x50
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = 80 /*0x50*/;
    // 0042163b  c644241604             -mov byte ptr [esp + 0x16], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */) = 4 /*0x4*/;
    // 00421640  66c744241a8002         -mov word ptr [esp + 0x1a], 0x280
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(26) /* 0x1a */) = 640 /*0x280*/;
    // 00421647  66c744241ce001         -mov word ptr [esp + 0x1c], 0x1e0
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = 480 /*0x1e0*/;
    // 0042164e  66c744241e1000         -mov word ptr [esp + 0x1e], 0x10
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = 16 /*0x10*/;
    // 00421655  c644242000             -mov byte ptr [esp + 0x20], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0042165a  c744242100000000       -mov dword ptr [esp + 0x21], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(33) /* 0x21 */) = 0 /*0x0*/;
    // 00421662  e859670500             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 00421667  c6460f00               -mov byte ptr [esi + 0xf], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 0042166b  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0042166e  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 00421673  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00421677  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00421679  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042167c  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0042167d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042167e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042167f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00421682  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421691  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00421693  b900155200             -mov ecx, 0x521500
    cpu.ecx = 5379328 /*0x521500*/;
    // 00421698  e8d3fd0200             -call 0x451470
    cpu.esp -= 4;
    sub_451470(app, cpu);
    // 0042169d  b940175200             -mov ecx, 0x521740
    cpu.ecx = 5379904 /*0x521740*/;
    // 004216a2  e8c9fd0200             -call 0x451470
    cpu.esp -= 4;
    sub_451470(app, cpu);
    // 004216a7  b920165200             -mov ecx, 0x521620
    cpu.ecx = 5379616 /*0x521620*/;
    // 004216ac  e8bffd0200             -call 0x451470
    cpu.esp -= 4;
    sub_451470(app, cpu);
    // 004216b1  a13d165200             -mov eax, dword ptr [0x52163d]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379645) /* 0x52163d */);
    // 004216b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004216b7  683c264900             -push 0x49263c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793916 /*0x49263c*/;
    cpu.esp -= 4;
    // 004216bc  e8f6560500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004216c1  83c408                 +add esp, 8
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
    // 004216c4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004216c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216c7  e9f4fb0200             -jmp 0x4512c0
    return sub_4512c0(app, cpu);
}

/* align: skip  */
void Application::sub_4216d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004216d0  e80bfa0200             -call 0x4510e0
    cpu.esp -= 4;
    sub_4510e0(app, cpu);
    // 004216d5  b900155200             -mov ecx, 0x521500
    cpu.ecx = 5379328 /*0x521500*/;
    // 004216da  e811feffff             -call 0x4214f0
    cpu.esp -= 4;
    sub_4214f0(app, cpu);
    // 004216df  b940175200             -mov ecx, 0x521740
    cpu.ecx = 5379904 /*0x521740*/;
    // 004216e4  e8c7feffff             -call 0x4215b0
    cpu.esp -= 4;
    sub_4215b0(app, cpu);
    // 004216e9  b920165200             -mov ecx, 0x521620
    cpu.ecx = 5379616 /*0x521620*/;
    // 004216ee  e80dffffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    // 004216f3  a13d165200             -mov eax, dword ptr [0x52163d]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379645) /* 0x52163d */);
    // 004216f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004216f9  6864264900             -push 0x492664
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793956 /*0x492664*/;
    cpu.esp -= 4;
    // 004216fe  e8b4560500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00421703  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421706  b900155200             -mov ecx, 0x521500
    cpu.ecx = 5379328 /*0x521500*/;
    // 0042170b  e850fe0200             -call 0x451560
    cpu.esp -= 4;
    sub_451560(app, cpu);
    // 00421710  b940175200             -mov ecx, 0x521740
    cpu.ecx = 5379904 /*0x521740*/;
    // 00421715  e846fe0200             -call 0x451560
    cpu.esp -= 4;
    sub_451560(app, cpu);
    // 0042171a  b920165200             -mov ecx, 0x521620
    cpu.ecx = 5379616 /*0x521620*/;
    // 0042171f  e83cfe0200             -call 0x451560
    cpu.esp -= 4;
    sub_451560(app, cpu);
    // 00421724  8b0d3d165200           -mov ecx, dword ptr [0x52163d]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379645) /* 0x52163d */);
    // 0042172a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042172b  6850264900             -push 0x492650
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793936 /*0x492650*/;
    cpu.esp -= 4;
    // 00421730  e882560500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00421735  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421738  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421741  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421742  8bb118030000           -mov esi, dword ptr [ecx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 00421748  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042174a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042174e  7421                   -je 0x421771
    if (cpu.flags.zf)
    {
        goto L_0x00421771;
    }
    // 00421750  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421752  b980264900             -mov ecx, 0x492680
    cpu.ecx = 4793984 /*0x492680*/;
    // 00421757  e8b4540400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 0042175c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042175e  7411                   -je 0x421771
    if (cpu.flags.zf)
    {
        goto L_0x00421771;
    }
    // 00421760  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00421764  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421765  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00421767  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00421769  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042176c  e87f610400             -call 0x4678f0
    cpu.esp -= 4;
    sub_4678f0(app, cpu);
L_0x00421771:
    // 00421771  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421772  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421773  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421780  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421785  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00421788  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042178a  898264020000           -mov dword ptr [edx + 0x264], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */) = cpu.eax;
    // 00421790  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421796  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00421799  898268020000           -mov dword ptr [edx + 0x268], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(616) /* 0x268 */) = cpu.eax;
    // 0042179f  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004217a5  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 004217a8  89826c020000           -mov dword ptr [edx + 0x26c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(620) /* 0x26c */) = cpu.eax;
    // 004217ae  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004217b3  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004217b6  8b81a8020000           -mov eax, dword ptr [ecx + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 004217bc  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004217be  8981a8020000           -mov dword ptr [ecx + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 004217c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4217d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004217d0  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004217d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004217d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004217d5  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004217d7  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004217d9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004217db  750d                   -jne 0x4217ea
    if (!cpu.flags.zf)
    {
        goto L_0x004217ea;
    }
    // 004217dd  688c264900             -push 0x49268c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793996 /*0x49268c*/;
    cpu.esp -= 4;
    // 004217e2  e829340000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004217e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004217ea:
    // 004217ea  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004217ec  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004217ee  e81dcc0300             -call 0x45e410
    cpu.esp -= 4;
    sub_45e410(app, cpu);
    // 004217f3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004217f5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004217f7  e884ffffff             -call 0x421780
    cpu.esp -= 4;
    sub_421780(app, cpu);
    // 004217fc  8b87e8020000           -mov eax, dword ptr [edi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(744) /* 0x2e8 */);
    // 00421802  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00421805  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421807  0f851f010000           -jne 0x42192c
    if (!cpu.flags.zf)
    {
        goto L_0x0042192c;
    }
    // 0042180d  8b87b8020000           -mov eax, dword ptr [edi + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(696) /* 0x2b8 */);
    // 00421813  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421815  0f85b2000000           -jne 0x4218cd
    if (!cpu.flags.zf)
    {
        goto L_0x004218cd;
    }
    // 0042181b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421820  8b97c8020000           -mov edx, dword ptr [edi + 0x2c8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(712) /* 0x2c8 */);
    // 00421826  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 00421829  8991c8020000           -mov dword ptr [ecx + 0x2c8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */) = cpu.edx;
    // 0042182f  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421834  8b97d0000000           -mov edx, dword ptr [edi + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */);
    // 0042183a  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0042183d  8991d0000000           -mov dword ptr [ecx + 0xd0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */) = cpu.edx;
    // 00421843  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421848  8b97d4000000           -mov edx, dword ptr [edi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 0042184e  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 00421851  8991d4000000           -mov dword ptr [ecx + 0xd4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */) = cpu.edx;
    // 00421857  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042185c  8b97d8000000           -mov edx, dword ptr [edi + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */);
    // 00421862  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 00421865  8991d8000000           -mov dword ptr [ecx + 0xd8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */) = cpu.edx;
    // 0042186b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421870  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 00421873  8d91cc000000           -lea edx, [ecx + 0xcc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 00421879  e8c21b0300             -call 0x453440
    cpu.esp -= 4;
    sub_453440(app, cpu);
    // 0042187e  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421884  8b040e                 -mov eax, dword ptr [esi + ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 00421887  8b88c8020000           -mov ecx, dword ptr [eax + 0x2c8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */);
    // 0042188d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042188f  0f84a9000000           -je 0x42193e
    if (cpu.flags.zf)
    {
        goto L_0x0042193e;
    }
    // 00421895  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00421899  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042189a  8d90cc000000           -lea edx, [eax + 0xcc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(204) /* 0xcc */);
    // 004218a0  e89b260300             -call 0x453f40
    cpu.esp -= 4;
    sub_453f40(app, cpu);
    // 004218a5  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004218aa  d82558744800           -fsub dword ptr [0x487458]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */));
    // 004218b0  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 004218b3  d999d4000000           -fstp dword ptr [ecx + 0xd4]
    app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004218b9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004218bf  8b0c16                 -mov ecx, dword ptr [esi + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 1);
    // 004218c2  e829dd0200             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    // 004218c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004218c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004218c9  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004218cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004218cd:
    // 004218cd  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004218d3  8b0c16                 -mov ecx, dword ptr [esi + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 1);
    // 004218d6  8b90d0000000           -mov edx, dword ptr [eax + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */);
    // 004218dc  8991d0000000           -mov dword ptr [ecx + 0xd0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */) = cpu.edx;
    // 004218e2  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004218e8  8b87b8020000           -mov eax, dword ptr [edi + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(696) /* 0x2b8 */);
    // 004218ee  8b140e                 -mov edx, dword ptr [esi + ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004218f1  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 004218f7  8982d4000000           -mov dword ptr [edx + 0xd4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */) = cpu.eax;
    // 004218fd  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421903  8b8fb8020000           -mov ecx, dword ptr [edi + 0x2b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(696) /* 0x2b8 */);
    // 00421909  8b0416                 -mov eax, dword ptr [esi + edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 1);
    // 0042190c  8b89d8000000           -mov ecx, dword ptr [ecx + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00421912  8988d8000000           -mov dword ptr [eax + 0xd8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(216) /* 0xd8 */) = cpu.ecx;
    // 00421918  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042191e  8b0c16                 -mov ecx, dword ptr [esi + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 1);
    // 00421921  e8cadc0200             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    // 00421926  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421927  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421928  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0042192b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042192c:
    // 0042192c  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042192e  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421933  8b1406                 -mov edx, dword ptr [esi + eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 00421936  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00421939  e8d2d40300             -call 0x45ee10
    cpu.esp -= 4;
    sub_45ee10(app, cpu);
L_0x0042193e:
    // 0042193e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421944  8b0c16                 -mov ecx, dword ptr [esi + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 1);
    // 00421947  e8a4dc0200             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    // 0042194c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042194d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042194e  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00421951  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421960  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421965  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421966  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00421968  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0042196b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042196d  89812c010000           -mov dword ptr [ecx + 0x12c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(300) /* 0x12c */) = cpu.eax;
    // 00421973  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421979  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042197c  898130010000           -mov dword ptr [ecx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 00421982  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421988  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042198b  898134010000           -mov dword ptr [ecx + 0x134], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 00421991  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421997  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042199a  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 004219a0  83e2f7                 -and edx, 0xfffffff7
    cpu.edx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
    // 004219a3  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 004219a9  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004219ae  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 004219b1  e86a8b0200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 004219b6  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004219bc  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 004219bf  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 004219c5  83e1fb                 -and ecx, 0xfffffffb
    cpu.ecx &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/));
    // 004219c8  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 004219ce  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004219d4  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 004219d7  e8448b0200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 004219dc  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004219e1  8b34b0                 -mov esi, dword ptr [eax + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 004219e4  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 004219ea  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004219ec  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 004219f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004219f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421a00  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421a05  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421a06  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00421a08  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421a09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421a0a  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00421a0c  8b0c98                 -mov ecx, dword ptr [eax + ebx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00421a0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421a10  e8ab600300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00421a15  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421a1a  8b8d84020000           -mov ecx, dword ptr [ebp + 0x284]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(644) /* 0x284 */);
    // 00421a20  8b3498                 -mov esi, dword ptr [eax + ebx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00421a23  8b3c88                 -mov edi, dword ptr [eax + ecx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00421a26  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00421a28  89aeec020000           -mov dword ptr [esi + 0x2ec], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */) = cpu.ebp;
    // 00421a2e  e82dffffff             -call 0x421960
    cpu.esp -= 4;
    sub_421960(app, cpu);
    // 00421a33  8a87e0020000           -mov al, byte ptr [edi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(736) /* 0x2e0 */);
    // 00421a39  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00421a3b  3ac3                   +cmp al, bl
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
    // 00421a3d  742b                   -je 0x421a6a
    if (cpu.flags.zf)
    {
        goto L_0x00421a6a;
    }
    // 00421a3f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421a41  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421a46  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421a49  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421a4f  83e1fd                 +and ecx, 0xfffffffd
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/))));
    // 00421a52  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 00421a58  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421a5a  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421a60  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00421a63  e8b88a0200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421a68  eb13                   -jmp 0x421a7d
    goto L_0x00421a7d;
L_0x00421a6a:
    // 00421a6a  8a454a                 -mov al, byte ptr [ebp + 0x4a]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(74) /* 0x4a */);
    // 00421a6d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00421a72  84c2                   +test dl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.al));
    // 00421a74  7507                   -jne 0x421a7d
    if (!cpu.flags.zf)
    {
        goto L_0x00421a7d;
    }
    // 00421a76  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00421a78  e8c3fcffff             -call 0x421740
    cpu.esp -= 4;
    sub_421740(app, cpu);
L_0x00421a7d:
    // 00421a7d  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421a7f  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421a84  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 00421a86  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00421a89  8b0ca8                 -mov ecx, dword ptr [eax + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 4);
    // 00421a8c  e87fd30300             -call 0x45ee10
    cpu.esp -= 4;
    sub_45ee10(app, cpu);
    // 00421a91  899ed0000000           -mov dword ptr [esi + 0xd0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.ebx;
    // 00421a97  899ed4000000           -mov dword ptr [esi + 0xd4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */) = cpu.ebx;
    // 00421a9d  899ed8000000           -mov dword ptr [esi + 0xd8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */) = cpu.ebx;
    // 00421aa3  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00421aa6  895624                 -mov dword ptr [esi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00421aa9  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00421aac  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00421aaf  8b4f2c                 -mov ecx, dword ptr [edi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */);
    // 00421ab2  894e2c                 -mov dword ptr [esi + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 00421ab5  8b574c                 -mov edx, dword ptr [edi + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */);
    // 00421ab8  89564c                 -mov dword ptr [esi + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00421abb  8b4750                 -mov eax, dword ptr [edi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 00421abe  894650                 -mov dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00421ac1  8b4f54                 -mov ecx, dword ptr [edi + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 00421ac4  894e54                 -mov dword ptr [esi + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 00421ac7  8b5774                 -mov edx, dword ptr [edi + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(116) /* 0x74 */);
    // 00421aca  895674                 -mov dword ptr [esi + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00421acd  8b4778                 -mov eax, dword ptr [edi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 00421ad0  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421ad2  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00421ad5  8b4f7c                 -mov ecx, dword ptr [edi + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(124) /* 0x7c */);
    // 00421ad8  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 00421adb  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421ae0  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421ae3  8b98a8020000           -mov ebx, dword ptr [eax + 0x2a8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421ae9  83cb04                 -or ebx, 4
    cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421aec  8998a8020000           -mov dword ptr [eax + 0x2a8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ebx;
    // 00421af2  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421af4  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421afa  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00421afd  e81e8a0200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421b02  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00421b04  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421b0a  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00421b0d  8bb8a8020000           -mov edi, dword ptr [eax + 0x2a8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421b13  83cf08                 -or edi, 8
    cpu.edi |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421b16  89b8a8020000           -mov dword ptr [eax + 0x2a8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edi;
    // 00421b1c  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421b1e  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421b23  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421b26  e8f5890200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421b2b  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421b2d  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421b33  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00421b36  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421b3c  83e2df                 -and edx, 0xffffffdf
    cpu.edx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 00421b3f  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 00421b45  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00421b47  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421b4d  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00421b50  e8cb890200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421b55  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421b57  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421b5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b5d  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421b60  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421b66  83e1bf                 +and ecx, 0xffffffbf
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/))));
    // 00421b69  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 00421b6f  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421b71  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421b77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b7a  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00421b7d  e99e890200             -jmp 0x44a520
    return sub_44a520(app, cpu);
}

/* align: skip  */
void Application::sub_421b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421b90  e86bf4fdff             -call 0x401000
    cpu.esp -= 4;
    sub_401000(app, cpu);
    // 00421b95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421b97  7406                   -je 0x421b9f
    if (cpu.flags.zf)
    {
        goto L_0x00421b9f;
    }
    // 00421b99  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421b9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421b9f:
    // 00421b9f  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00421ba4  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421ba6  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421bab  8b9184020000           -mov edx, dword ptr [ecx + 0x284]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(644) /* 0x284 */);
    // 00421bb1  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421bb4  8a88e0020000           -mov cl, byte ptr [eax + 0x2e0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(736) /* 0x2e0 */);
    // 00421bba  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00421bbc  7617                   -jbe 0x421bd5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00421bd5;
    }
    // 00421bbe  8b88e4020000           -mov ecx, dword ptr [eax + 0x2e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(740) /* 0x2e4 */);
    // 00421bc4  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00421bc6  e8c5090000             -call 0x422590
    cpu.esp -= 4;
    sub_422590(app, cpu);
    // 00421bcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421bcd  7506                   -jne 0x421bd5
    if (!cpu.flags.zf)
    {
        goto L_0x00421bd5;
    }
    // 00421bcf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421bd4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421bd5:
    // 00421bd5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421bd7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_468ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00468ce0;
L_0x00421be0:
    // 00421be0  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421be5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421be6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421be7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421be8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421be9  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00421beb  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00421bed  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 00421bf0  e8cb5e0300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00421bf5  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421bfa  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 00421bfd  83b9d0020000ff         +cmp dword ptr [ecx + 0x2d0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(720) /* 0x2d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421c04  0f85ca000000           -jne 0x421cd4
    if (!cpu.flags.zf)
    {
        goto L_0x00421cd4;
    }
    // 00421c0a  8b8d84020000           -mov ecx, dword ptr [ebp + 0x284]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(644) /* 0x284 */);
    // 00421c10  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421c12  7405                   -je 0x421c19
    if (cpu.flags.zf)
    {
        goto L_0x00421c19;
    }
    // 00421c14  83f9ff                 +cmp ecx, -1
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
    // 00421c17  7513                   -jne 0x421c2c
    if (!cpu.flags.zf)
    {
        goto L_0x00421c2c;
    }
L_0x00421c19:
    // 00421c19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421c1a  68a4264900             -push 0x4926a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794020 /*0x4926a4*/;
    cpu.esp -= 4;
    // 00421c1f  e8ec2f0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421c24  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421c29  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00421c2c:
    // 00421c2c  8b9584020000           -mov edx, dword ptr [ebp + 0x284]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(644) /* 0x284 */);
    // 00421c32  8b1cb8                 -mov ebx, dword ptr [eax + edi*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 00421c35  8b3490                 -mov esi, dword ptr [eax + edx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421c38  8a86e0020000           -mov al, byte ptr [esi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(736) /* 0x2e0 */);
    // 00421c3e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00421c40  761c                   -jbe 0x421c5e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00421c5e;
    }
    // 00421c42  8b86e4020000           -mov eax, dword ptr [esi + 0x2e4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(740) /* 0x2e4 */);
    // 00421c48  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421c4a  e841090000             -call 0x422590
    cpu.esp -= 4;
    sub_422590(app, cpu);
    // 00421c4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421c51  750b                   -jne 0x421c5e
    if (!cpu.flags.zf)
    {
        goto L_0x00421c5e;
    }
    // 00421c53  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00421c55  e836090000             -call 0x422590
    cpu.esp -= 4;
    sub_422590(app, cpu);
    // 00421c5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421c5c  7476                   -je 0x421cd4
    if (cpu.flags.zf)
    {
        goto L_0x00421cd4;
    }
L_0x00421c5e:
    // 00421c5e  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00421c60  e82b090000             -call 0x422590
    cpu.esp -= 4;
    sub_422590(app, cpu);
    // 00421c65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421c67  7509                   -jne 0x421c72
    if (!cpu.flags.zf)
    {
        goto L_0x00421c72;
    }
    // 00421c69  e892f3fdff             -call 0x401000
    cpu.esp -= 4;
    sub_401000(app, cpu);
    // 00421c6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421c70  7562                   -jne 0x421cd4
    if (!cpu.flags.zf)
    {
        goto L_0x00421cd4;
    }
L_0x00421c72:
    // 00421c72  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00421c74  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00421c76  e885fdffff             -call 0x421a00
    cpu.esp -= 4;
    sub_421a00(app, cpu);
    // 00421c7b  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421c81  8b04b9                 -mov eax, dword ptr [ecx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edi * 4);
    // 00421c84  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421c8a  83e2fd                 -and edx, 0xfffffffd
    cpu.edx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/));
    // 00421c8d  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 00421c93  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421c99  8b0cba                 -mov ecx, dword ptr [edx + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 00421c9c  e87f880200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421ca1  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00421ca3  e8e8080000             -call 0x422590
    cpu.esp -= 4;
    sub_422590(app, cpu);
    // 00421ca8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421caa  752d                   -jne 0x421cd9
    if (!cpu.flags.zf)
    {
        goto L_0x00421cd9;
    }
    // 00421cac  8b86e4020000           -mov eax, dword ptr [esi + 0x2e4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(740) /* 0x2e4 */);
    // 00421cb2  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00421cb4  8a96e0020000           -mov dl, byte ptr [esi + 0x2e0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(736) /* 0x2e0 */);
    // 00421cba  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421cbc  8b5490fc               -mov edx, dword ptr [eax + edx*4 - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.edx * 4);
    // 00421cc0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00421cc2  8b96e4020000           -mov edx, dword ptr [esi + 0x2e4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(740) /* 0x2e4 */);
    // 00421cc8  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00421cca  8a86e0020000           -mov al, byte ptr [esi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(736) /* 0x2e0 */);
    // 00421cd0  894c82fc               -mov dword ptr [edx + eax*4 - 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4) = cpu.ecx;
L_0x00421cd4:
    // 00421cd4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cd7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421cd9:
    // 00421cd9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cda  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00421cdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cdd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cdf  e9cc080000             -jmp 0x4225b0
    return sub_4225b0(app, cpu);
L_0x00421cf0:
    // 00421cf0  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00421cf5  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00421cf8  e9e3feffff             -jmp 0x421be0
    goto L_0x00421be0;
L_entry_0x00468ce0:
    // 00468ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468ce1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468ce2  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00468ce4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468ce5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468ce7  e894d9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468cec  e89fe00000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00468cf1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468cf3  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00468cf5  e886d9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468cfa  e891e00000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00468cff  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468d01  83feff                 +cmp esi, -1
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
    // 00468d04  750c                   -jne 0x468d12
    if (!cpu.flags.zf)
    {
        goto L_0x00468d12;
    }
    // 00468d06  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00468d09  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00468d0b  e820feffff             -call 0x468b30
    cpu.esp -= 4;
    sub_468b30(app, cpu);
    // 00468d10  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00468d12:
    // 00468d12  83ffff                 +cmp edi, -1
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
    // 00468d15  7505                   -jne 0x468d1c
    if (!cpu.flags.zf)
    {
        goto L_0x00468d1c;
    }
    // 00468d17  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00468d1a  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
L_0x00468d1c:
    // 00468d1c  3b35c0f35100           +cmp esi, dword ptr [0x51f3c0]
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
    // 00468d22  7d04                   -jge 0x468d28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00468d28;
    }
    // 00468d24  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468d26  7d0e                   -jge 0x468d36
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00468d36;
    }
L_0x00468d28:
    // 00468d28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468d29  68b82d4a00             -push 0x4a2db8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861368 /*0x4a2db8*/;
    cpu.esp -= 4;
    // 00468d2e  e8ddbefbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468d33  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00468d36:
    // 00468d36  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00468d3c  8b04ba                 -mov eax, dword ptr [edx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 00468d3f  8b88e8020000           -mov ecx, dword ptr [eax + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(744) /* 0x2e8 */);
    // 00468d45  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00468d47  750c                   -jne 0x468d55
    if (!cpu.flags.zf)
    {
        goto L_0x00468d55;
    }
    // 00468d49  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00468d4b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00468d4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d50  e99b8ffbff             -jmp 0x421cf0
    goto L_0x00421cf0;
L_0x00468d55:
    // 00468d55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421d00  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00421d03  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421d05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421d06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421d07  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00421d09  740d                   -je 0x421d18
    if (cpu.flags.zf)
    {
        goto L_0x00421d18;
    }
    // 00421d0b  681c274900             -push 0x49271c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794140 /*0x49271c*/;
    cpu.esp -= 4;
    // 00421d10  e8fb2e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421d15  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00421d18:
    // 00421d18  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421d1a  750d                   -jne 0x421d29
    if (!cpu.flags.zf)
    {
        goto L_0x00421d29;
    }
    // 00421d1c  68f8264900             -push 0x4926f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794104 /*0x4926f8*/;
    cpu.esp -= 4;
    // 00421d21  e8ea2e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421d26  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00421d29:
    // 00421d29  8b8784020000           -mov eax, dword ptr [edi + 0x284]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(644) /* 0x284 */);
    // 00421d2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421d31  7405                   -je 0x421d38
    if (cpu.flags.zf)
    {
        goto L_0x00421d38;
    }
    // 00421d33  83f8ff                 +cmp eax, -1
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
    // 00421d36  750e                   -jne 0x421d46
    if (!cpu.flags.zf)
    {
        goto L_0x00421d46;
    }
L_0x00421d38:
    // 00421d38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421d39  68cc264900             -push 0x4926cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794060 /*0x4926cc*/;
    cpu.esp -= 4;
    // 00421d3e  e8cd2e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421d43  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00421d46:
    // 00421d46  8b8784020000           -mov eax, dword ptr [edi + 0x284]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(644) /* 0x284 */);
    // 00421d4c  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421d52  8b2c81                 -mov ebp, dword ptr [ecx + eax*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00421d55  8a85e0020000           -mov al, byte ptr [ebp + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(736) /* 0x2e0 */);
    // 00421d5b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00421d5d  7509                   -jne 0x421d68
    if (!cpu.flags.zf)
    {
        goto L_0x00421d68;
    }
    // 00421d5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d60  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00421d63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d64  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00421d67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421d68:
    // 00421d68  8b95e4020000           -mov edx, dword ptr [ebp + 0x2e4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(740) /* 0x2e4 */);
    // 00421d6e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421d6f  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00421d71  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00421d73  e818080000             -call 0x422590
    cpu.esp -= 4;
    sub_422590(app, cpu);
    // 00421d78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421d7a  7407                   -je 0x421d83
    if (cpu.flags.zf)
    {
        goto L_0x00421d83;
    }
    // 00421d7c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00421d7e  e82d080000             -call 0x4225b0
    cpu.esp -= 4;
    sub_4225b0(app, cpu);
L_0x00421d83:
    // 00421d83  c7872003000000000000   -mov dword ptr [edi + 0x320], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(800) /* 0x320 */) = 0 /*0x0*/;
    // 00421d8d  a148845100             -mov eax, dword ptr [0x518448]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00421d92  48                     -dec eax
    (cpu.eax)--;
    // 00421d93  894774                 -mov dword ptr [edi + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 00421d96  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421d98  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421d9d  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00421da0  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00421da3  8b0ca8                 -mov ecx, dword ptr [eax + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 4);
    // 00421da6  e8d5d00300             -call 0x45ee80
    cpu.esp -= 4;
    sub_45ee80(app, cpu);
    // 00421dab  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421dad  e8cef9ffff             -call 0x421780
    cpu.esp -= 4;
    sub_421780(app, cpu);
    // 00421db2  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421db4  c786ec02000000000000   -mov dword ptr [esi + 0x2ec], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */) = 0 /*0x0*/;
    // 00421dbe  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421dc3  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421dc6  8ba8a8020000           -mov ebp, dword ptr [eax + 0x2a8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421dcc  83e5fb                 -and ebp, 0xfffffffb
    cpu.ebp &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/));
    // 00421dcf  89a8a8020000           -mov dword ptr [eax + 0x2a8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ebp;
    // 00421dd5  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421dd7  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421ddd  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00421de0  e83b870200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421de5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00421de7  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421ded  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00421df0  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421df6  83e2f7                 -and edx, 0xfffffff7
    cpu.edx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
    // 00421df9  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 00421dff  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421e01  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421e06  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421e09  e812870200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421e0e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421e10  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421e16  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00421e19  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421e1f  83c920                 -or ecx, 0x20
    cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00421e22  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 00421e28  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00421e2a  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421e30  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00421e33  e8e8860200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421e38  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421e3a  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421e3f  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421e42  8ba8a8020000           -mov ebp, dword ptr [eax + 0x2a8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00421e48  83e5bf                 -and ebp, 0xffffffbf
    cpu.ebp &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/));
    // 00421e4b  89a8a8020000           -mov dword ptr [eax + 0x2a8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ebp;
    // 00421e51  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421e53  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421e59  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00421e5c  e8bf860200             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00421e61  8b8780000000           -mov eax, dword ptr [edi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 00421e67  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421e6d  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00421e70  8b88b8020000           -mov ecx, dword ptr [eax + 0x2b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(696) /* 0x2b8 */);
    // 00421e76  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421e78  7418                   -je 0x421e92
    if (cpu.flags.zf)
    {
        goto L_0x00421e92;
    }
    // 00421e7a  d981d0000000           +fld dword ptr [ecx + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    // 00421e80  d981d4000000           +fld dword ptr [ecx + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    // 00421e86  8b89d8000000           -mov ecx, dword ptr [ecx + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00421e8c  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00421e90  eb16                   -jmp 0x421ea8
    goto L_0x00421ea8;
L_0x00421e92:
    // 00421e92  d980d0000000           -fld dword ptr [eax + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    // 00421e98  d980d4000000           -fld dword ptr [eax + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */)));
    // 00421e9e  8b80d8000000           -mov eax, dword ptr [eax + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(216) /* 0xd8 */);
    // 00421ea4  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00421ea8:
    // 00421ea8  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00421eac  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00421eae  d82558744800           -fsub dword ptr [0x487458]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */));
    // 00421eb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421eb5  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00421eb8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421ebb  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00421ebf  d8258c774800           -fsub dword ptr [0x48778c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4749196) /* 0x48778c */));
    // 00421ec5  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00421ec8  e833d80200             -call 0x44f700
    cpu.esp -= 4;
    sub_44f700(app, cpu);
    // 00421ecd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00421ecf  e81cd70200             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    // 00421ed4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00421ed6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ed7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ed8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ed9  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00421edc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421ee0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421ee1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00421ee3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421ee4  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00421ee6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421ee8  7c08                   -jl 0x421ef2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421ef2;
    }
    // 00421eea  3b35c0f35100           +cmp esi, dword ptr [0x51f3c0]
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
    // 00421ef0  7e0f                   -jle 0x421f01
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00421f01;
    }
L_0x00421ef2:
    // 00421ef2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421ef3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421ef4  6850274900             -push 0x492750
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794192 /*0x492750*/;
    cpu.esp -= 4;
    // 00421ef9  e8122d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00421efe  83c40c                 +add esp, 0xc
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
L_0x00421f01:
    // 00421f01  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00421f06  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00421f08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f09  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00421f0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f0d  e9eefdffff             -jmp 0x421d00
    return sub_421d00(app, cpu);
}

/* align: skip  */
void Application::sub_421f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421f20  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421f23  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00421f28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421f29  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421f2a  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00421f2c  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421f2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421f30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421f31  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00421f33  8b8120030000           -mov eax, dword ptr [ecx + 0x320]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(800) /* 0x320 */);
    // 00421f39  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00421f3d  83f801                 +cmp eax, 1
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
    // 00421f40  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00421f44  7507                   -jne 0x421f4d
    if (!cpu.flags.zf)
    {
        goto L_0x00421f4d;
    }
    // 00421f46  e8e5060000             -call 0x422630
    cpu.esp -= 4;
    sub_422630(app, cpu);
    // 00421f4b  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00421f4d:
    // 00421f4d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00421f4f  3bef                   +cmp ebp, edi
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
    // 00421f51  7418                   -je 0x421f6b
    if (cpu.flags.zf)
    {
        goto L_0x00421f6b;
    }
    // 00421f53  8b9d18030000           -mov ebx, dword ptr [ebp + 0x318]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(792) /* 0x318 */);
    // 00421f59  3bdf                   +cmp ebx, edi
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
    // 00421f5b  740e                   -je 0x421f6b
    if (cpu.flags.zf)
    {
        goto L_0x00421f6b;
    }
    // 00421f5d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00421f5f  b980274900             -mov ecx, 0x492780
    cpu.ecx = 4794240 /*0x492780*/;
    // 00421f64  e8a74c0400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00421f69  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00421f6b:
    // 00421f6b  e840c8ffff             -call 0x41e7b0
    cpu.esp -= 4;
    sub_41e7b0(app, cpu);
    // 00421f70  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00421f72  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421f74  0f84ce010000           -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 00421f7a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421f7c  7432                   -je 0x421fb0
    if (cpu.flags.zf)
    {
        goto L_0x00421fb0;
    }
    // 00421f7e  8b96ec020000           -mov edx, dword ptr [esi + 0x2ec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00421f84  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00421f86  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421f88  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 00421f8b  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00421f8f  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421f92  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00421f96  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00421f98  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00421f9a  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00421f9e  db06                   -fild dword ptr [esi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi))));
    // 00421fa0  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00421fa3  e898590400             -call 0x467940
    cpu.esp -= 4;
    sub_467940(app, cpu);
    // 00421fa8  c744241001000000       -mov dword ptr [esp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
L_0x00421fb0:
    // 00421fb0  8bbe18030000           -mov edi, dword ptr [esi + 0x318]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(792) /* 0x318 */);
    // 00421fb6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421fb8  0f848a010000           -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 00421fbe  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00421fc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421fc6  0f841b010000           -je 0x4220e7
    if (cpu.flags.zf)
    {
        goto L_0x004220e7;
    }
    // 00421fcc  80784818               +cmp byte ptr [eax + 0x48], 0x18
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421fd0  0f8772010000           -ja 0x422148
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 00421fd6  e825f0fdff             -call 0x401000
    cpu.esp -= 4;
    sub_401000(app, cpu);
    // 00421fdb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421fdd  0f8565010000           -jne 0x422148
    if (!cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 00421fe3  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00421fe7  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00421fec  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00421fee  8b9380000000           -mov edx, dword ptr [ebx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(128) /* 0x80 */);
    // 00421ff4  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00421ff7  e89414feff             -call 0x403490
    cpu.esp -= 4;
    sub_403490(app, cpu);
    // 00421ffc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421ffe  0f8444010000           -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 00422004  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00422009  3bc6                   +cmp eax, esi
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
    // 0042200b  7564                   -jne 0x422071
    if (!cpu.flags.zf)
    {
        goto L_0x00422071;
    }
    // 0042200d  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042200f  b974274900             -mov ecx, 0x492774
    cpu.ecx = 4794228 /*0x492774*/;
    // 00422014  e8f74b0400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00422019  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042201b  0f8427010000           -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 00422021  8b9384020000           -mov edx, dword ptr [ebx + 0x284]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(644) /* 0x284 */);
    // 00422027  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042202a  3bd1                   +cmp edx, ecx
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
    // 0042202c  0f8416010000           -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 00422032  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00422034  7422                   -je 0x422058
    if (cpu.flags.zf)
    {
        goto L_0x00422058;
    }
    // 00422036  8b8db4020000           -mov ecx, dword ptr [ebp + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(692) /* 0x2b4 */);
    // 0042203c  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0042203f  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00422043  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00422046  db442418               +fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0042204a  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0042204e  d95c2404               +fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422052  db44241c               +fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 00422056  eb75                   -jmp 0x4220cd
    goto L_0x004220cd;
L_0x00422058:
    // 00422058  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042205c  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042205f  db442418               +fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00422063  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00422067  d95c2404               +fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042206b  db44241c               +fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 0042206f  eb5c                   -jmp 0x4220cd
    goto L_0x004220cd;
L_0x00422071:
    // 00422071  83f802                 +cmp eax, 2
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
    // 00422074  0f85ce000000           -jne 0x422148
    if (!cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 0042207a  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042207c  b96c274900             -mov ecx, 0x49276c
    cpu.ecx = 4794220 /*0x49276c*/;
    // 00422081  e88a4b0400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00422086  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422088  0f84ba000000           -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 0042208e  8b9384020000           -mov edx, dword ptr [ebx + 0x284]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(644) /* 0x284 */);
    // 00422094  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00422097  3bd1                   +cmp edx, ecx
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
    // 00422099  0f84a9000000           -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 0042209f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004220a1  7413                   -je 0x4220b6
    if (cpu.flags.zf)
    {
        goto L_0x004220b6;
    }
    // 004220a3  8b8db4020000           -mov ecx, dword ptr [ebp + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(692) /* 0x2b4 */);
    // 004220a9  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004220ac  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004220b0  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004220b4  eb08                   -jmp 0x4220be
    goto L_0x004220be;
L_0x004220b6:
    // 004220b6  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004220ba  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x004220be:
    // 004220be  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 004220c2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004220c5  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004220c9  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
L_0x004220cd:
    // 004220cd  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004220d0  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004220d2  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004220d4  e867580400             -call 0x467940
    cpu.esp -= 4;
    sub_467940(app, cpu);
    // 004220d9  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004220db  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004220df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004220e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004220e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004220e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004220e3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004220e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004220e7:
    // 004220e7  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004220e9  b964274900             -mov ecx, 0x492764
    cpu.ecx = 4794212 /*0x492764*/;
    // 004220ee  e81d4b0400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 004220f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004220f5  7451                   -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 004220f7  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004220fb  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004220fe  398a84020000           +cmp dword ptr [edx + 0x284], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(644) /* 0x284 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422104  7442                   -je 0x422148
    if (cpu.flags.zf)
    {
        goto L_0x00422148;
    }
    // 00422106  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00422108  7413                   -je 0x42211d
    if (cpu.flags.zf)
    {
        goto L_0x0042211d;
    }
    // 0042210a  8b8db4020000           -mov ecx, dword ptr [ebp + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(692) /* 0x2b4 */);
    // 00422110  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00422113  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00422117  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042211b  eb08                   -jmp 0x422125
    goto L_0x00422125;
L_0x0042211d:
    // 0042211d  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00422121  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00422125:
    // 00422125  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00422129  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042212c  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042212e  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00422130  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422134  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00422138  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042213b  e800580400             -call 0x467940
    cpu.esp -= 4;
    sub_467940(app, cpu);
    // 00422140  c744241001000000       -mov dword ptr [esp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
L_0x00422148:
    // 00422148  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042214c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042214d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042214e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042214f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422150  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00422153  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_422160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422160  81ecc4000000           -sub esp, 0xc4
    (cpu.esp) -= x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00422166  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0042216b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042216c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042216d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042216e  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00422170  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422172  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00422177  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422178  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0042217e  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00422180  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 00422184  c7442424804fc347       -mov dword ptr [esp + 0x24], 0x47c34f80
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 1203982208 /*0x47c34f80*/;
    // 0042218c  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0042218f  39b9e8020000           +cmp dword ptr [ecx + 0x2e8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422195  740d                   -je 0x4221a4
    if (cpu.flags.zf)
    {
        goto L_0x004221a4;
    }
    // 00422197  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422198  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422199  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042219a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042219c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042219d  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 004221a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004221a4:
    // 004221a4  e8b77f0300             -call 0x45a160
    cpu.esp -= 4;
    sub_45a160(app, cpu);
    // 004221a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004221ab  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 004221b0  7512                   -jne 0x4221c4
    if (!cpu.flags.zf)
    {
        goto L_0x004221c4;
    }
    // 004221b2  83f807                 +cmp eax, 7
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
    // 004221b5  7512                   -jne 0x4221c9
    if (!cpu.flags.zf)
    {
        goto L_0x004221c9;
    }
    // 004221b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004221b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004221b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004221ba  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004221bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004221bd  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 004221c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004221c4:
    // 004221c4  83f807                 +cmp eax, 7
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
    // 004221c7  740a                   -je 0x4221d3
    if (cpu.flags.zf)
    {
        goto L_0x004221d3;
    }
L_0x004221c9:
    // 004221c9  c74424100000f041       -mov dword ptr [esp + 0x10], 0x41f00000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1106247680 /*0x41f00000*/;
    // 004221d1  eb08                   -jmp 0x4221db
    goto L_0x004221db;
L_0x004221d3:
    // 004221d3  c744241000007041       -mov dword ptr [esp + 0x10], 0x41700000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1097859072 /*0x41700000*/;
L_0x004221db:
    // 004221db  e8b0f9ffff             -call 0x421b90
    cpu.esp -= 4;
    sub_421b90(app, cpu);
    // 004221e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004221e2  740a                   -je 0x4221ee
    if (cpu.flags.zf)
    {
        goto L_0x004221ee;
    }
    // 004221e4  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004221e8  dcc0                   -fadd st(0), st(0)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(0));
    // 004221ea  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004221ee:
    // 004221ee  8b96ec020000           -mov edx, dword ptr [esi + 0x2ec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 004221f4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004221fa  c74424300000c8c2       -mov dword ptr [esp + 0x30], 0xc2c80000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = 3267887104 /*0xc2c80000*/;
    // 00422202  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 00422206  8b8290000000           -mov eax, dword ptr [edx + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(144) /* 0x90 */);
    // 0042220c  8b2c81                 -mov ebp, dword ptr [ecx + eax*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042220f  8b5524                 -mov edx, dword ptr [ebp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00422212  899424b0000000         -mov dword ptr [esp + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.edx;
    // 00422219  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0042221c  898424b4000000         -mov dword ptr [esp + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 00422223  8b4d2c                 -mov ecx, dword ptr [ebp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 00422226  898c24b8000000         -mov dword ptr [esp + 0xb8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.ecx;
    // 0042222d  ba8a060100             -mov edx, 0x1068a
    cpu.edx = 67210 /*0x1068a*/;
    // 00422232  8d8c24ac000000         -lea ecx, [esp + 0xac]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00422239  e812a80200             -call 0x44ca50
    cpu.esp -= 4;
    sub_44ca50(app, cpu);
    // 0042223e  8b95d0000000           -mov edx, dword ptr [ebp + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(208) /* 0xd0 */);
    // 00422244  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 00422248  8b85d4000000           -mov eax, dword ptr [ebp + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(212) /* 0xd4 */);
    // 0042224e  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00422252  8b8dd8000000           -mov ecx, dword ptr [ebp + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(216) /* 0xd8 */);
    // 00422258  894c2468               -mov dword ptr [esp + 0x68], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ecx;
    // 0042225c  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00422260  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00422262  e849ca0300             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 00422267  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042226b  e850b30000             -call 0x42d5c0
    cpu.esp -= 4;
    sub_42d5c0(app, cpu);
    // 00422270  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00422272  3bdf                   +cmp ebx, edi
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
    // 00422274  750d                   -jne 0x422283
    if (!cpu.flags.zf)
    {
        goto L_0x00422283;
    }
    // 00422276  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422277  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422278  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422279  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042227b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042227c  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00422282  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422283:
    // 00422283  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00422287  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0042228b  3bc7                   +cmp eax, edi
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
    // 0042228d  0f8e0f020000           -jle 0x4224a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004224a2;
    }
L_0x00422293:
    // 00422293  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00422295  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422297  0f8cf0010000           -jl 0x42248d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042248d;
    }
    // 0042229d  3b052c845100           +cmp eax, dword ptr [0x51842c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004222a3  0f8de4010000           -jge 0x42248d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042248d;
    }
    // 004222a9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004222af  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004222b2  8b3482                 -mov esi, dword ptr [edx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004222b5  f686a802000002         +test byte ptr [esi + 0x2a8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(680) /* 0x2a8 */) & 2 /*0x2*/));
    // 004222bc  0f84cb010000           -je 0x42248d
    if (cpu.flags.zf)
    {
        goto L_0x0042248d;
    }
    // 004222c2  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 004222c8  8b8dec020000           -mov ecx, dword ptr [ebp + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(748) /* 0x2ec */);
    // 004222ce  3bc1                   +cmp eax, ecx
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
    // 004222d0  0f84b7010000           -je 0x42248d
    if (cpu.flags.zf)
    {
        goto L_0x0042248d;
    }
    // 004222d6  3bf5                   +cmp esi, ebp
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
    // 004222d8  0f84af010000           -je 0x42248d
    if (cpu.flags.zf)
    {
        goto L_0x0042248d;
    }
    // 004222de  8b8618030000           -mov eax, dword ptr [esi + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(792) /* 0x318 */);
    // 004222e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004222e6  0f84a1010000           -je 0x42248d
    if (cpu.flags.zf)
    {
        goto L_0x0042248d;
    }
    // 004222ec  8b8ed0000000           -mov ecx, dword ptr [esi + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 004222f2  898c2488000000         -mov dword ptr [esp + 0x88], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ecx;
    // 004222f9  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 004222ff  8994248c000000         -mov dword ptr [esp + 0x8c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.edx;
    // 00422306  8b86d8000000           -mov eax, dword ptr [esi + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0042230c  8d942484000000         -lea edx, [esp + 0x84]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00422313  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00422315  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0042231c  e88fc90300             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 00422321  d9842488000000         -fld dword ptr [esp + 0x88]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(136) /* 0x88 */)));
    // 00422328  d8642460               -fsub dword ptr [esp + 0x60]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(96) /* 0x60 */));
    // 0042232c  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00422330  d95c2438               -fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422334  d984248c000000         -fld dword ptr [esp + 0x8c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(140) /* 0x8c */)));
    // 0042233b  d8642464               -fsub dword ptr [esp + 0x64]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(100) /* 0x64 */));
    // 0042233f  d95c243c               -fstp dword ptr [esp + 0x3c]
    app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422343  d9842490000000         -fld dword ptr [esp + 0x90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(144) /* 0x90 */)));
    // 0042234a  d8642468               -fsub dword ptr [esp + 0x68]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */));
    // 0042234e  d95c2440               -fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422352  e839a90200             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 00422357  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422359  d9442440               -fld dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 0042235d  d84c2440               -fmul dword ptr [esp + 0x40]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */));
    // 00422361  d9442438               -fld dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */)));
    // 00422365  d84c2438               -fmul dword ptr [esp + 0x38]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */));
    // 00422369  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0042236f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422371  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00422373  d9fa                   +fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 00422375  d9542428               +fst dword ptr [esp + 0x28]
    app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    // 00422379  d9442410               +fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042237d  7408                   -je 0x422387
    if (cpu.flags.zf)
    {
        goto L_0x00422387;
    }
    // 0042237f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422381  d98688020000           -fld dword ptr [esi + 0x288]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(648) /* 0x288 */)));
L_0x00422387:
    // 00422387  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00422389  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0042238b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042238d  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00422390  0f8af7000000           -jp 0x42248d
    if (cpu.flags.pf)
    {
        goto L_0x0042248d;
    }
    // 00422396  d9442438               -fld dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */)));
    // 0042239a  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004223a0  c744243c00000000       -mov dword ptr [esp + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 004223a8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004223aa  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 004223ad  7b1f                   -jnp 0x4223ce
    if (!cpu.flags.pf)
    {
        goto L_0x004223ce;
    }
    // 004223af  d9442440               -fld dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 004223b3  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004223b9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004223bb  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 004223be  7b0e                   -jnp 0x4223ce
    if (!cpu.flags.pf)
    {
        goto L_0x004223ce;
    }
    // 004223c0  ba8b060100             -mov edx, 0x1068b
    cpu.edx = 67211 /*0x1068b*/;
    // 004223c5  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004223c9  e882a60200             -call 0x44ca50
    cpu.esp -= 4;
    sub_44ca50(app, cpu);
L_0x004223ce:
    // 004223ce  d9442440               -fld dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 004223d2  d88c24b8000000         -fmul dword ptr [esp + 0xb8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(184) /* 0xb8 */));
    // 004223d9  d944243c               -fld dword ptr [esp + 0x3c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */)));
    // 004223dd  d88c24b4000000         -fmul dword ptr [esp + 0xb4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(180) /* 0xb4 */));
    // 004223e4  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004223e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004223ea  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004223ec  d9442438               +fld dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */)));
    // 004223f0  d88c24b0000000         +fmul dword ptr [esp + 0xb0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(176) /* 0xb0 */));
    // 004223f7  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004223f9  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004223fd  7504                   -jne 0x422403
    if (!cpu.flags.zf)
    {
        goto L_0x00422403;
    }
    // 004223ff  8974242c               -mov dword ptr [esp + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.esi;
L_0x00422403:
    // 00422403  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00422407  dc1dd8744800           -fcomp qword ptr [0x4874d8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */)));
    cpu.fpu.pop();
    // 0042240d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042240f  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00422414  7577                   -jne 0x42248d
    if (!cpu.flags.zf)
    {
        goto L_0x0042248d;
    }
    // 00422416  8bbe18030000           -mov edi, dword ptr [esi + 0x318]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(792) /* 0x318 */);
    // 0042241c  b918ae4800             -mov ecx, 0x48ae18
    cpu.ecx = 4763160 /*0x48ae18*/;
    // 00422421  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00422423  e8e8470400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00422428  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042242a  7510                   -jne 0x42243c
    if (!cpu.flags.zf)
    {
        goto L_0x0042243c;
    }
    // 0042242c  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042242e  b990274900             -mov ecx, 0x492790
    cpu.ecx = 4794256 /*0x492790*/;
    // 00422433  e8d8470400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00422438  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042243a  7451                   -je 0x42248d
    if (cpu.flags.zf)
    {
        goto L_0x0042248d;
    }
L_0x0042243c:
    // 0042243c  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00422440  d85c2430               -fcomp dword ptr [esp + 0x30]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    cpu.fpu.pop();
    // 00422444  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422446  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042244b  7540                   -jne 0x42248d
    if (!cpu.flags.zf)
    {
        goto L_0x0042248d;
    }
    // 0042244d  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 00422451  d85c2424               -fcomp dword ptr [esp + 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    cpu.fpu.pop();
    // 00422455  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422457  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042245a  7a31                   -jp 0x42248d
    if (cpu.flags.pf)
    {
        goto L_0x0042248d;
    }
    // 0042245c  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00422462  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422464  7413                   -je 0x422479
    if (cpu.flags.zf)
    {
        goto L_0x00422479;
    }
    // 00422466  80784818               +cmp byte ptr [eax + 0x48], 0x18
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042246a  770d                   -ja 0x422479
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00422479;
    }
    // 0042246c  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042246e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00422470  e81b10feff             -call 0x403490
    cpu.esp -= 4;
    sub_403490(app, cpu);
    // 00422475  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422477  7414                   -je 0x42248d
    if (cpu.flags.zf)
    {
        goto L_0x0042248d;
    }
L_0x00422479:
    // 00422479  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042247d  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00422481  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00422485  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00422489  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x0042248d:
    // 0042248d  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00422491  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00422495  40                     -inc eax
    (cpu.eax)++;
    // 00422496  3bc1                   +cmp eax, ecx
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
    // 00422498  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0042249c  0f8cf1fdffff           -jl 0x422293
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422293;
    }
L_0x004224a2:
    // 004224a2  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004224a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224aa  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 004224b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4224c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004224c0  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004224c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004224c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004224c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004224c8  8b3488                 -mov esi, dword ptr [eax + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004224cb  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004224cd  8b8684020000           -mov eax, dword ptr [esi + 0x284]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(644) /* 0x284 */);
    // 004224d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004224d5  7405                   -je 0x4224dc
    if (cpu.flags.zf)
    {
        goto L_0x004224dc;
    }
    // 004224d7  83f8ff                 +cmp eax, -1
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
    // 004224da  750e                   -jne 0x4224ea
    if (!cpu.flags.zf)
    {
        goto L_0x004224ea;
    }
L_0x004224dc:
    // 004224dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004224dd  6898274900             -push 0x492798
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794264 /*0x492798*/;
    cpu.esp -= 4;
    // 004224e2  e829270000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004224e7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004224ea:
    // 004224ea  8b8e84020000           -mov ecx, dword ptr [esi + 0x284]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(644) /* 0x284 */);
    // 004224f0  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004224f6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004224f8  8b3c8a                 -mov edi, dword ptr [edx + ecx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 004224fb  8a87e0020000           -mov al, byte ptr [edi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(736) /* 0x2e0 */);
    // 00422501  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00422503  7625                   -jbe 0x42252a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042252a;
    }
L_0x00422505:
    // 00422505  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00422507  e874d20300             -call 0x45f780
    cpu.esp -= 4;
    sub_45f780(app, cpu);
    // 0042250c  8b8fe4020000           -mov ecx, dword ptr [edi + 0x2e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(740) /* 0x2e4 */);
    // 00422512  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00422515  3982b4020000           +cmp dword ptr [edx + 0x2b4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(692) /* 0x2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042251b  7413                   -je 0x422530
    if (cpu.flags.zf)
    {
        goto L_0x00422530;
    }
    // 0042251d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042251f  46                     -inc esi
    (cpu.esi)++;
    // 00422520  8a87e0020000           -mov al, byte ptr [edi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(736) /* 0x2e0 */);
    // 00422526  3bf0                   +cmp esi, eax
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
    // 00422528  7cdb                   -jl 0x422505
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422505;
    }
L_0x0042252a:
    // 0042252a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042252b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042252c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042252e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042252f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422530:
    // 00422530  8b8fe4020000           -mov ecx, dword ptr [edi + 0x2e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(740) /* 0x2e4 */);
    // 00422536  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422537  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042253a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042253b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042253c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042253e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_422540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422540  a17c264900             -mov eax, dword ptr [0x49267c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4793980) /* 0x49267c */);
    // 00422545  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422546  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422547  83f801                 +cmp eax, 1
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
    // 0042254a  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0042254c  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042254e  751a                   -jne 0x42256a
    if (!cpu.flags.zf)
    {
        goto L_0x0042256a;
    }
    // 00422550  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422551  b900020000             -mov ecx, 0x200
    cpu.ecx = 512 /*0x200*/;
    // 00422556  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422558  bf10ca4a00             -mov edi, 0x4aca10
    cpu.edi = 4901392 /*0x4aca10*/;
    // 0042255d  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042255f  c7057c26490000000000   -mov dword ptr [0x49267c], 0
    app->getMemory<x86::reg32>(x86::reg32(4793980) /* 0x49267c */) = 0 /*0x0*/;
    // 00422569  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042256a:
    // 0042256a  81fe00080000           +cmp esi, 0x800
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422570  7c0d                   -jl 0x42257f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042257f;
    }
    // 00422572  68c0274900             -push 0x4927c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794304 /*0x4927c0*/;
    cpu.esp -= 4;
    // 00422577  e894260000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042257c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042257f:
    // 0042257f  fec3                   -inc bl
    (cpu.bl)++;
    // 00422581  889e10ca4a00           -mov byte ptr [esi + 0x4aca10], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4901392) /* 0x4aca10 */) = cpu.bl;
    // 00422587  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422588  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422589  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_422590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422590  8b81b4020000           -mov eax, dword ptr [ecx + 0x2b4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */);
    // 00422596  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00422598  8a9010ca4a00           -mov dl, byte ptr [eax + 0x4aca10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4901392) /* 0x4aca10 */);
    // 0042259e  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004225a0  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 004225a3  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004225a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4225b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004225b0  8b8184020000           -mov eax, dword ptr [ecx + 0x284]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(644) /* 0x284 */);
    // 004225b6  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004225bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004225bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004225be  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004225c1  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004225c3  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004225c5  8a90e0020000           -mov dl, byte ptr [eax + 0x2e0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(736) /* 0x2e0 */);
    // 004225cb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004225cd  7e25                   -jle 0x4225f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004225f4;
    }
    // 004225cf  8b80e4020000           -mov eax, dword ptr [eax + 0x2e4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(740) /* 0x2e4 */);
    // 004225d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004225d6:
    // 004225d6  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004225d8  8bbfb4020000           -mov edi, dword ptr [edi + 0x2b4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(692) /* 0x2b4 */);
    // 004225de  8a9f10ca4a00           -mov bl, byte ptr [edi + 0x4aca10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4901392) /* 0x4aca10 */);
    // 004225e4  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004225e6  7401                   -je 0x4225e9
    if (cpu.flags.zf)
    {
        goto L_0x004225e9;
    }
    // 004225e8  46                     -inc esi
    (cpu.esi)++;
L_0x004225e9:
    // 004225e9  83c004                 +add eax, 4
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
    // 004225ec  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004225ed  75e7                   -jne 0x4225d6
    if (!cpu.flags.zf)
    {
        goto L_0x004225d6;
    }
    // 004225ef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004225f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225f2  7507                   -jne 0x4225fb
    if (!cpu.flags.zf)
    {
        goto L_0x004225fb;
    }
L_0x004225f4:
    // 004225f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225f6  e9a5000000             -jmp 0x4226a0
    return sub_4226a0(app, cpu);
L_0x004225fb:
    // 004225fb  8a597c                 -mov bl, byte ptr [ecx + 0x7c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 004225fe  fec3                   -inc bl
    (cpu.bl)++;
    // 00422600  8ac3                   -mov al, bl
    cpu.al = cpu.bl;
    // 00422602  88597c                 -mov byte ptr [ecx + 0x7c], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.bl;
    // 00422605  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042260a  3bc6                   +cmp eax, esi
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
    // 0042260c  7c04                   -jl 0x422612
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422612;
    }
    // 0042260e  c6417c00               -mov byte ptr [ecx + 0x7c], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
L_0x00422612:
    // 00422612  c7812003000001000000   -mov dword ptr [ecx + 0x320], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(800) /* 0x320 */) = 1 /*0x1*/;
    // 0042261c  e8bf000000             -call 0x4226e0
    cpu.esp -= 4;
    sub_4226e0(app, cpu);
    // 00422621  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422622  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422623  e978c2ffff             -jmp 0x41e8a0
    return sub_41e8a0(app, cpu);
}

/* align: skip  */
void Application::sub_422630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422631  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422632  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00422634  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042263a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042263c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042263d  8b8584020000           -mov eax, dword ptr [ebp + 0x284]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(644) /* 0x284 */);
    // 00422643  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422644  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00422647  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00422649  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042264b  8a9ae0020000           -mov bl, byte ptr [edx + 0x2e0]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(736) /* 0x2e0 */);
    // 00422651  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00422653  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422655  7e2f                   -jle 0x422686
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00422686;
    }
    // 00422657  8b92e4020000           -mov edx, dword ptr [edx + 0x2e4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(740) /* 0x2e4 */);
    // 0042265d  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x0042265f:
    // 0042265f  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00422661  8b9bb4020000           -mov ebx, dword ptr [ebx + 0x2b4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(692) /* 0x2b4 */);
    // 00422667  80bb10ca4a0000         +cmp byte ptr [ebx + 0x4aca10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4901392) /* 0x4aca10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042266e  740a                   -je 0x42267a
    if (cpu.flags.zf)
    {
        goto L_0x0042267a;
    }
    // 00422670  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422672  8a5d7c                 -mov bl, byte ptr [ebp + 0x7c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(124) /* 0x7c */);
    // 00422675  3bd9                   +cmp ebx, ecx
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
    // 00422677  741b                   -je 0x422694
    if (cpu.flags.zf)
    {
        goto L_0x00422694;
    }
    // 00422679  41                     -inc ecx
    (cpu.ecx)++;
L_0x0042267a:
    // 0042267a  40                     -inc eax
    (cpu.eax)++;
    // 0042267b  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042267e  3bc6                   +cmp eax, esi
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
    // 00422680  7cdd                   -jl 0x42265f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042265f;
    }
    // 00422682  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00422684  7507                   -jne 0x42268d
    if (!cpu.flags.zf)
    {
        goto L_0x0042268d;
    }
L_0x00422686:
    // 00422686  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00422688  e813000000             -call 0x4226a0
    cpu.esp -= 4;
    sub_4226a0(app, cpu);
L_0x0042268d:
    // 0042268d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042268e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042268f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422690  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422692  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422693  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422694:
    // 00422694  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00422697  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422698  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422699  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042269a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042269b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4226a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004226a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004226a1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004226a3  83be2003000001         +cmp dword ptr [esi + 0x320], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(800) /* 0x320 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004226aa  7505                   -jne 0x4226b1
    if (!cpu.flags.zf)
    {
        goto L_0x004226b1;
    }
    // 004226ac  e8efc1ffff             -call 0x41e8a0
    cpu.esp -= 4;
    sub_41e8a0(app, cpu);
L_0x004226b1:
    // 004226b1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004226b3  c70524d24a0001000000   -mov dword ptr [0x4ad224], 1
    app->getMemory<x86::reg32>(x86::reg32(4903460) /* 0x4ad224 */) = 1 /*0x1*/;
    // 004226bd  a320d24a00             -mov dword ptr [0x4ad220], eax
    app->getMemory<x86::reg32>(x86::reg32(4903456) /* 0x4ad220 */) = cpu.eax;
    // 004226c2  a31cd24a00             -mov dword ptr [0x4ad21c], eax
    app->getMemory<x86::reg32>(x86::reg32(4903452) /* 0x4ad21c */) = cpu.eax;
    // 004226c7  898620030000           -mov dword ptr [esi + 0x320], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(800) /* 0x320 */) = cpu.eax;
    // 004226cd  a318d24a00             -mov dword ptr [0x4ad218], eax
    app->getMemory<x86::reg32>(x86::reg32(4903448) /* 0x4ad218 */) = cpu.eax;
    // 004226d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004226d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4226e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004226e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004226e1  8b354c845100           -mov esi, dword ptr [0x51844c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004226e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004226e8  8b3dc4e54900           -mov edi, dword ptr [0x49e5c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004226ee  3b0cbe                 +cmp ecx, dword ptr [esi + edi*4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004226f1  754a                   -jne 0x42273d
    if (!cpu.flags.zf)
    {
        goto L_0x0042273d;
    }
    // 004226f3  a120d24a00             -mov eax, dword ptr [0x4ad220]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903456) /* 0x4ad220 */);
    // 004226f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004226fa  750a                   -jne 0x422706
    if (!cpu.flags.zf)
    {
        goto L_0x00422706;
    }
    // 004226fc  c70524d24a0001000000   -mov dword ptr [0x4ad224], 1
    app->getMemory<x86::reg32>(x86::reg32(4903460) /* 0x4ad224 */) = 1 /*0x1*/;
L_0x00422706:
    // 00422706  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 0042270c  dc0568774800           -fadd qword ptr [0x487768]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749160) /* 0x487768 */));
    // 00422712  e879460500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00422717  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042271d  a320d24a00             -mov dword ptr [0x4ad220], eax
    app->getMemory<x86::reg32>(x86::reg32(4903456) /* 0x4ad220 */) = cpu.eax;
    // 00422722  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 00422725  8b8884020000           -mov ecx, dword ptr [eax + 0x284]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(644) /* 0x284 */);
    // 0042272b  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0042272e  c70518d24a0000000000   -mov dword ptr [0x4ad218], 0
    app->getMemory<x86::reg32>(x86::reg32(4903448) /* 0x4ad218 */) = 0 /*0x0*/;
    // 00422738  a31cd24a00             -mov dword ptr [0x4ad21c], eax
    app->getMemory<x86::reg32>(x86::reg32(4903452) /* 0x4ad21c */) = cpu.eax;
L_0x0042273d:
    // 0042273d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042273e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042273f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_422740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422740  8b0d20d24a00           -mov ecx, dword ptr [0x4ad220]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903456) /* 0x4ad220 */);
    // 00422746  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00422749  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042274b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042274c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042274d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042274e  0f848f020000           -je 0x4229e3
    if (cpu.flags.zf)
    {
        goto L_0x004229e3;
    }
    // 00422754  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0042275a  3bd1                   +cmp edx, ecx
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
    // 0042275c  0f8f81020000           -jg 0x4229e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004229e3;
    }
    // 00422762  db0550f85100           -fild dword ptr [0x51f850]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */))));
    // 00422768  a11cd24a00             -mov eax, dword ptr [0x4ad21c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903452) /* 0x4ad21c */);
    // 0042276d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042276f  dc0d80774800           +fmul qword ptr [0x487780]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749184) /* 0x487780 */));
    // 00422775  d95c2410               +fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422779  0f845d020000           -je 0x4229dc
    if (cpu.flags.zf)
    {
        goto L_0x004229dc;
    }
    // 0042277f  a124d24a00             -mov eax, dword ptr [0x4ad224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903460) /* 0x4ad224 */);
    // 00422784  c744240c0000803f       -mov dword ptr [esp + 0xc], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1065353216 /*0x3f800000*/;
    // 0042278c  83f801                 +cmp eax, 1
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
    // 0042278f  7539                   -jne 0x4227ca
    if (!cpu.flags.zf)
    {
        goto L_0x004227ca;
    }
    // 00422791  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 00422797  db0520d24a00           -fild dword ptr [0x4ad220]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4903456) /* 0x4ad220 */))));
    // 0042279d  dc2568774800           -fsub qword ptr [0x487768]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4749160) /* 0x487768 */));
    // 004227a3  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004227a5  dc0d78774800           -fmul qword ptr [0x487778]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749176) /* 0x487778 */));
    // 004227ab  d954240c               -fst dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    // 004227af  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 004227b5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004227b7  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004227bc  7537                   -jne 0x4227f5
    if (!cpu.flags.zf)
    {
        goto L_0x004227f5;
    }
    // 004227be  c70524d24a0000000000   -mov dword ptr [0x4ad224], 0
    app->getMemory<x86::reg32>(x86::reg32(4903460) /* 0x4ad224 */) = 0 /*0x0*/;
    // 004227c8  eb04                   -jmp 0x4227ce
    goto L_0x004227ce;
L_0x004227ca:
    // 004227ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004227cc  755d                   -jne 0x42282b
    if (!cpu.flags.zf)
    {
        goto L_0x0042282b;
    }
L_0x004227ce:
    // 004227ce  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004227d0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004227d2  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004227d6  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004227da  dc1dd8754800           -fcomp qword ptr [0x4875d8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748760) /* 0x4875d8 */)));
    cpu.fpu.pop();
    // 004227e0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004227e2  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004227e5  7a3c                   -jp 0x422823
    if (cpu.flags.pf)
    {
        goto L_0x00422823;
    }
    // 004227e7  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004227eb  dc0d78774800           -fmul qword ptr [0x487778]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749176) /* 0x487778 */));
    // 004227f1  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004227f5:
    // 004227f5  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004227f9  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004227ff  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422801  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00422804  7a0a                   -jp 0x422810
    if (cpu.flags.pf)
    {
        goto L_0x00422810;
    }
    // 00422806  c744240c00000000       -mov dword ptr [esp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0042280e  eb1b                   -jmp 0x42282b
    goto L_0x0042282b;
L_0x00422810:
    // 00422810  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00422814  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0042281a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042281c  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00422821  7508                   -jne 0x42282b
    if (!cpu.flags.zf)
    {
        goto L_0x0042282b;
    }
L_0x00422823:
    // 00422823  c744240c0000803f       -mov dword ptr [esp + 0xc], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1065353216 /*0x3f800000*/;
L_0x0042282b:
    // 0042282b  d9442410               +fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042282f  d80d08754800           +fmul dword ptr [0x487508]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */));
    // 00422835  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422836  e855450500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042283b  d9442414               +fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042283f  d80d94774800           +fmul dword ptr [0x487794]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749204) /* 0x487794 */));
    // 00422845  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00422847  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042284b  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0042284f  e83c450500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00422854  d9442414               +fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00422858  d80d90774800           +fmul dword ptr [0x487790]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749200) /* 0x487790 */));
    // 0042285e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00422860  d9542420               +fst dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    // 00422864  e827450500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00422869  d9442414               +fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042286d  d80d68754800           +fmul dword ptr [0x487568]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748648) /* 0x487568 */));
    // 00422873  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00422875  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0042287a  d95c2424               +fstp dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042287e:
    // 0042287e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00422882  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00422884  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422885  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422886  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422887  b924000000             -mov ecx, 0x24
    cpu.ecx = 36 /*0x24*/;
    // 0042288c  e88fbaffff             -call 0x41e320
    cpu.esp -= 4;
    sub_41e320(app, cpu);
    // 00422891  db442418               +fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00422895  d8442424               +fadd dword ptr [esp + 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 00422899  e8f2440500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042289e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004228a0  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004228a1  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004228a5  75d7                   -jne 0x42287e
    if (!cpu.flags.zf)
    {
        goto L_0x0042287e;
    }
    // 004228a7  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004228ab  a11cd24a00             -mov eax, dword ptr [0x4ad21c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903452) /* 0x4ad21c */);
    // 004228b0  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004228b2  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 004228b6  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004228ba  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004228bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004228bd:
    // 004228bd  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004228bf  8a90e0020000           -mov dl, byte ptr [eax + 0x2e0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(736) /* 0x2e0 */);
    // 004228c5  3bf2                   +cmp esi, edx
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
    // 004228c7  0f8d0f010000           -jge 0x4229dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004229dc;
    }
    // 004228cd  8b88e4020000           -mov ecx, dword ptr [eax + 0x2e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(740) /* 0x2e4 */);
    // 004228d3  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 004228d6  8b8ab4020000           -mov ecx, dword ptr [edx + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(692) /* 0x2b4 */);
    // 004228dc  8a9910ca4a00           -mov bl, byte ptr [ecx + 0x4aca10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4901392) /* 0x4aca10 */);
    // 004228e2  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004228e4  0f84e8000000           -je 0x4229d2
    if (cpu.flags.zf)
    {
        goto L_0x004229d2;
    }
    // 004228ea  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004228f0  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004228f5  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004228f8  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004228fa  8a517c                 -mov dl, byte ptr [ecx + 0x7c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 004228fd  3bd5                   +cmp edx, ebp
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
    // 004228ff  755b                   -jne 0x42295c
    if (!cpu.flags.zf)
    {
        goto L_0x0042295c;
    }
    // 00422901  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 00422907  db0520d24a00           -fild dword ptr [0x4ad220]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4903456) /* 0x4ad220 */))));
    // 0042290d  dc2568774800           -fsub qword ptr [0x487768]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4749160) /* 0x487768 */));
    // 00422913  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00422915  dc0d78774800           -fmul qword ptr [0x487778]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749176) /* 0x487778 */));
    // 0042291b  dc0dd8744800           -fmul qword ptr [0x4874d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 00422921  dc0568734800           -fadd qword ptr [0x487368]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 00422927  dc1560744800           -fcom qword ptr [0x487460]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748384) /* 0x487460 */)));
    // 0042292d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042292f  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00422934  7508                   -jne 0x42293e
    if (!cpu.flags.zf)
    {
        goto L_0x0042293e;
    }
    // 00422936  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422938  d90510734800           +fld dword ptr [0x487310]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748048) /* 0x487310 */)));
L_0x0042293e:
    // 0042293e  d90594744800           +fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00422944  d8e9                   +fsubr st(1)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(1)) - cpu.fpu.st(0);
    // 00422946  d84c241c               +fmul dword ptr [esp + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */));
    // 0042294a  dc0dd8744800           +fmul qword ptr [0x4874d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 00422950  d95c2418               +fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422954  d90594744800           +fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 0042295a  eb14                   -jmp 0x422970
    goto L_0x00422970;
L_0x0042295c:
    // 0042295c  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00422962  d90540764800           -fld dword ptr [0x487640]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748864) /* 0x487640 */)));
    // 00422968  c744241800000000       -mov dword ptr [esp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00422970:
    // 00422970  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00422974  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422975  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422979  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0042297d  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422980  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00422984  d80d90774800           -fmul dword ptr [0x487790]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749200) /* 0x487790 */));
    // 0042298a  e801440500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042298f  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00422993  d864241c               -fsub dword ptr [esp + 0x1c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */));
    // 00422997  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422998  e8f3430500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042299d  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 004229a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004229a2  d8642424               -fsub dword ptr [esp + 0x24]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004229a6  e8e5430500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 004229ab  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004229ad  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004229af  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004229b5  49                     -dec ecx
    (cpu.ecx)--;
    // 004229b6  e865b9ffff             -call 0x41e320
    cpu.esp -= 4;
    sub_41e320(app, cpu);
    // 004229bb  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004229bf  d8442420               -fadd dword ptr [esp + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 004229c3  e8c8430500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 004229c8  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004229cc  a11cd24a00             -mov eax, dword ptr [0x4ad21c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903452) /* 0x4ad21c */);
    // 004229d1  45                     -inc ebp
    (cpu.ebp)++;
L_0x004229d2:
    // 004229d2  46                     -inc esi
    (cpu.esi)++;
    // 004229d3  83fd08                 +cmp ebp, 8
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004229d6  0f8ce1feffff           -jl 0x4228bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004228bd;
    }
L_0x004229dc:
    // 004229dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229df  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004229e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004229e3:
    // 004229e3  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004229e8  8b0dc4e54900           -mov ecx, dword ptr [0x49e5c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004229ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229f0  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004229f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229f4  83c41c                 +add esp, 0x1c
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
    // 004229f7  e9a4fcffff             -jmp 0x4226a0
    return sub_4226a0(app, cpu);
}

/* align: skip  */
void Application::sub_422a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422a00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422a01  8b353cd24a00           -mov esi, dword ptr [0x4ad23c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4903484) /* 0x4ad23c */);
    // 00422a07  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422a08  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00422a0a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422a0c  7415                   -je 0x422a23
    if (cpu.flags.zf)
    {
        goto L_0x00422a23;
    }
L_0x00422a0e:
    // 00422a0e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422a0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422a10  e89b210600             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00422a15  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00422a18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422a1a  741a                   -je 0x422a36
    if (cpu.flags.zf)
    {
        goto L_0x00422a36;
    }
    // 00422a1c  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00422a1f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422a21  75eb                   -jne 0x422a0e
    if (!cpu.flags.zf)
    {
        goto L_0x00422a0e;
    }
L_0x00422a23:
    // 00422a23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422a24  68e0274900             -push 0x4927e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794336 /*0x4927e0*/;
    cpu.esp -= 4;
    // 00422a29  e889430500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00422a2e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00422a31  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422a33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422a36:
    // 00422a36  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00422a39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_422a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422a40  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00422a46  b8c0145200             -mov eax, 0x5214c0
    cpu.eax = 5379264 /*0x5214c0*/;
L_0x00422a4b:
    // 00422a4b  66c74002ffff           -mov word ptr [eax + 2], 0xffff
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 65535 /*0xffff*/;
    // 00422a51  66c700ffff             -mov word ptr [eax], 0xffff
    app->getMemory<x86::reg16>(cpu.eax) = 65535 /*0xffff*/;
    // 00422a56  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422a59  3de4145200             +cmp eax, 0x5214e4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5379300 /*0x5214e4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422a5e  7ceb                   -jl 0x422a4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422a4b;
    }
    // 00422a60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422a61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422a62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422a63  6840c74800             -push 0x48c740
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769600 /*0x48c740*/;
    cpu.esp -= 4;
    // 00422a68  6888284900             -push 0x492888
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794504 /*0x492888*/;
    cpu.esp -= 4;
    // 00422a6d  e8ec510500             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 00422a72  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00422a74  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00422a77  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00422a79  7517                   -jne 0x422a92
    if (!cpu.flags.zf)
    {
        goto L_0x00422a92;
    }
    // 00422a7b  6870284900             -push 0x492870
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794480 /*0x492870*/;
    cpu.esp -= 4;
    // 00422a80  e832430500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00422a85  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422a88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a8b  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00422a91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422a92:
    // 00422a92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422a93  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00422a97  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00422a99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422a9a  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00422a9c  e8374e0500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00422aa1  8a450c                 -mov al, byte ptr [ebp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00422aa4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00422aa7  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00422aa9  0f8501010000           -jne 0x422bb0
    if (!cpu.flags.zf)
    {
        goto L_0x00422bb0;
    }
    // 00422aaf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422ab0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00422ab5:
    // 00422ab5  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00422ab7  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00422abb  6860284900             -push 0x492860
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794464 /*0x492860*/;
    cpu.esp -= 4;
    // 00422ac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422ac1  e86a740500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00422ac6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00422ac9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422acb  750c                   -jne 0x422ad9
    if (!cpu.flags.zf)
    {
        goto L_0x00422ad9;
    }
    // 00422acd  891d40d24a00           -mov dword ptr [0x4ad240], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903488) /* 0x4ad240 */) = cpu.ebx;
    // 00422ad3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00422ad4  e9b5000000             -jmp 0x422b8e
    goto L_0x00422b8e;
L_0x00422ad9:
    // 00422ad9  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00422adb  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00422adf  6850284900             -push 0x492850
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794448 /*0x492850*/;
    cpu.esp -= 4;
    // 00422ae4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422ae5  e846740500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00422aea  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00422aed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422aef  750c                   -jne 0x422afd
    if (!cpu.flags.zf)
    {
        goto L_0x00422afd;
    }
    // 00422af1  891d44d24a00           -mov dword ptr [0x4ad244], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903492) /* 0x4ad244 */) = cpu.ebx;
    // 00422af7  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00422af8  e991000000             -jmp 0x422b8e
    goto L_0x00422b8e;
L_0x00422afd:
    // 00422afd  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00422b01  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00422b05  80f93a                 +cmp cl, 0x3a
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
    // 00422b08  7411                   -je 0x422b1b
    if (cpu.flags.zf)
    {
        goto L_0x00422b1b;
    }
L_0x00422b0a:
    // 00422b0a  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00422b0c  0f8498000000           -je 0x422baa
    if (cpu.flags.zf)
    {
        goto L_0x00422baa;
    }
    // 00422b12  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00422b15  40                     -inc eax
    (cpu.eax)++;
    // 00422b16  80f93a                 +cmp cl, 0x3a
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
    // 00422b19  75ef                   -jne 0x422b0a
    if (!cpu.flags.zf)
    {
        goto L_0x00422b0a;
    }
L_0x00422b1b:
    // 00422b1b  803800                 +cmp byte ptr [eax], 0
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
    // 00422b1e  0f8486000000           -je 0x422baa
    if (cpu.flags.zf)
    {
        goto L_0x00422baa;
    }
    // 00422b24  8d8c2490000000         -lea ecx, [esp + 0x90]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00422b2b  8d9424d0000000         -lea edx, [esp + 0xd0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00422b32  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422b33  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422b34  40                     -inc eax
    (cpu.eax)++;
    // 00422b35  6848284900             -push 0x492848
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794440 /*0x492848*/;
    cpu.esp -= 4;
    // 00422b3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422b3b  e8144b0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00422b40  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00422b42  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00422b45  3bf3                   +cmp esi, ebx
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
    // 00422b47  7c16                   -jl 0x422b5f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422b5f;
    }
    // 00422b49  8d8c24d0000000         -lea ecx, [esp + 0xd0]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00422b50  e8abfeffff             -call 0x422a00
    cpu.esp -= 4;
    sub_422a00(app, cpu);
    // 00422b55  668904bdc0145200       -mov word ptr [edi*4 + 0x5214c0], ax
    app->getMemory<x86::reg16>(x86::reg32(5379264) /* 0x5214c0 */ + cpu.edi * 4) = cpu.ax;
    // 00422b5d  eb0a                   -jmp 0x422b69
    goto L_0x00422b69;
L_0x00422b5f:
    // 00422b5f  66c704bdc01452000000   -mov word ptr [edi*4 + 0x5214c0], 0
    app->getMemory<x86::reg16>(x86::reg32(5379264) /* 0x5214c0 */ + cpu.edi * 4) = 0 /*0x0*/;
L_0x00422b69:
    // 00422b69  83fe02                 +cmp esi, 2
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
    // 00422b6c  7516                   -jne 0x422b84
    if (!cpu.flags.zf)
    {
        goto L_0x00422b84;
    }
    // 00422b6e  8d8c2490000000         -lea ecx, [esp + 0x90]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00422b75  e886feffff             -call 0x422a00
    cpu.esp -= 4;
    sub_422a00(app, cpu);
    // 00422b7a  668904bdc2145200       -mov word ptr [edi*4 + 0x5214c2], ax
    app->getMemory<x86::reg16>(x86::reg32(5379266) /* 0x5214c2 */ + cpu.edi * 4) = cpu.ax;
    // 00422b82  eb0a                   -jmp 0x422b8e
    goto L_0x00422b8e;
L_0x00422b84:
    // 00422b84  66c704bdc21452000000   -mov word ptr [edi*4 + 0x5214c2], 0
    app->getMemory<x86::reg16>(x86::reg32(5379266) /* 0x5214c2 */ + cpu.edi * 4) = 0 /*0x0*/;
L_0x00422b8e:
    // 00422b8e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422b8f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00422b93  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00422b95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422b96  47                     -inc edi
    (cpu.edi)++;
    // 00422b97  e83c4d0500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00422b9c  8a450c                 -mov al, byte ptr [ebp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00422b9f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00422ba2  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00422ba4  0f840bffffff           -je 0x422ab5
    if (cpu.flags.zf)
    {
        goto L_0x00422ab5;
    }
L_0x00422baa:
    // 00422baa  83ff09                 +cmp edi, 9
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422bad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422bae  741a                   -je 0x422bca
    if (cpu.flags.zf)
    {
        goto L_0x00422bca;
    }
L_0x00422bb0:
    // 00422bb0  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00422bb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422bb3  6818284900             -push 0x492818
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794392 /*0x492818*/;
    cpu.esp -= 4;
    // 00422bb8  e8fa410500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00422bbd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00422bc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422bc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422bc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422bc3  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00422bc9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422bca:
    // 00422bca  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00422bcc:
    // 00422bcc  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00422bce  668b0cb5c0145200       -mov cx, word ptr [esi*4 + 0x5214c0]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5379264) /* 0x5214c0 */ + cpu.esi * 4);
    // 00422bd6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422bd7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422bd8  6808284900             -push 0x492808
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794376 /*0x492808*/;
    cpu.esp -= 4;
    // 00422bdd  e8d5410500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00422be2  668b04b5c2145200       -mov ax, word ptr [esi*4 + 0x5214c2]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5379266) /* 0x5214c2 */ + cpu.esi * 4);
    // 00422bea  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00422bed  663dffff               +cmp ax, 0xffff
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
    // 00422bf1  7413                   -je 0x422c06
    if (cpu.flags.zf)
    {
        goto L_0x00422c06;
    }
    // 00422bf3  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00422bf8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422bf9  6804284900             -push 0x492804
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794372 /*0x492804*/;
    cpu.esp -= 4;
    // 00422bfe  e8b4410500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00422c03  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00422c06:
    // 00422c06  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00422c0b  e8a7410500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00422c10  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422c13  46                     -inc esi
    (cpu.esi)++;
    // 00422c14  83fe09                 +cmp esi, 9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422c17  7cb3                   -jl 0x422bcc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422bcc;
    }
    // 00422c19  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422c1a  e8b8490500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00422c1f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422c22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c24  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c25  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00422c2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_422c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422c30  a13cd24a00             -mov eax, dword ptr [0x4ad23c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903484) /* 0x4ad23c */);
    // 00422c35  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00422c3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422c3d  741b                   -je 0x422c5a
    if (cpu.flags.zf)
    {
        goto L_0x00422c5a;
    }
L_0x00422c3f:
    // 00422c3f  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00422c42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422c43  890d3cd24a00           -mov dword ptr [0x4ad23c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903484) /* 0x4ad23c */) = cpu.ecx;
    // 00422c49  e866470500             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00422c4e  a13cd24a00             -mov eax, dword ptr [0x4ad23c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903484) /* 0x4ad23c */);
    // 00422c53  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422c56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422c58  75e5                   -jne 0x422c3f
    if (!cpu.flags.zf)
    {
        goto L_0x00422c3f;
    }
L_0x00422c5a:
    // 00422c5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422c5b  6840c74800             -push 0x48c740
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769600 /*0x48c740*/;
    cpu.esp -= 4;
    // 00422c60  68c8284900             -push 0x4928c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794568 /*0x4928c8*/;
    cpu.esp -= 4;
    // 00422c65  c7053cd24a0000000000   -mov dword ptr [0x4ad23c], 0
    app->getMemory<x86::reg32>(x86::reg32(4903484) /* 0x4ad23c */) = 0 /*0x0*/;
    // 00422c6f  e8ea4f0500             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 00422c74  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00422c76  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00422c79  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422c7b  7515                   -jne 0x422c92
    if (!cpu.flags.zf)
    {
        goto L_0x00422c92;
    }
    // 00422c7d  68b0284900             -push 0x4928b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794544 /*0x4928b0*/;
    cpu.esp -= 4;
    // 00422c82  e830410500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00422c87  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422c8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c8b  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00422c91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422c92:
    // 00422c92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422c93  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00422c97  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00422c99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422c9a  e8394c0500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00422c9f  8a470c                 -mov al, byte ptr [edi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00422ca2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00422ca5  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00422ca7  755a                   -jne 0x422d03
    if (!cpu.flags.zf)
    {
        goto L_0x00422d03;
    }
    // 00422ca9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00422caa:
    // 00422caa  6a28                   -push 0x28
    app->getMemory<x86::reg32>(cpu.esp-4) = 40 /*0x28*/;
    cpu.esp -= 4;
    // 00422cac  e8c9450500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00422cb1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00422cb3  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00422cb7  8d4620                 -lea eax, [esi + 0x20]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00422cba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422cbb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422cbc  68a8284900             -push 0x4928a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794536 /*0x4928a8*/;
    cpu.esp -= 4;
    // 00422cc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422cc2  e88d490500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00422cc7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00422cca  83f802                 +cmp eax, 2
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
    // 00422ccd  740d                   -je 0x422cdc
    if (cpu.flags.zf)
    {
        goto L_0x00422cdc;
    }
    // 00422ccf  6894284900             -push 0x492894
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794516 /*0x492894*/;
    cpu.esp -= 4;
    // 00422cd4  e8de400500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00422cd9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00422cdc:
    // 00422cdc  8b153cd24a00           -mov edx, dword ptr [0x4ad23c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4903484) /* 0x4ad23c */);
    // 00422ce2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422ce3  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00422ce7  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00422ce9  895624                 -mov dword ptr [esi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00422cec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422ced  89353cd24a00           -mov dword ptr [0x4ad23c], esi
    app->getMemory<x86::reg32>(x86::reg32(4903484) /* 0x4ad23c */) = cpu.esi;
    // 00422cf3  e8e04b0500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00422cf8  8a470c                 -mov al, byte ptr [edi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00422cfb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00422cfe  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00422d00  74a8                   -je 0x422caa
    if (cpu.flags.zf)
    {
        goto L_0x00422caa;
    }
    // 00422d02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00422d03:
    // 00422d03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422d04  e8ce480500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00422d09  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422d0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d0d  81c480000000           +add esp, 0x80
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00422d13  e928fdffff             -jmp 0x422a40
    return sub_422a40(app, cpu);
}

/* align: skip  */
void Application::sub_422d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00422d20  81c1fff0ffff           -add ecx, 0xfffff0ff
    (cpu.ecx) += x86::reg32(x86::sreg32(4294963455 /*0xfffff0ff*/));
    // 00422d26  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422d28  83f904                 +cmp ecx, 4
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
    // 00422d2b  7744                   -ja 0x422d71
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00422d71;
    }
    // 00422d2d  ff248d742d4200         -jmp dword ptr [ecx*4 + 0x422d74]
    cpu.ip = app->getMemory<x86::reg32>(4337012 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00422d34:
    // 00422d34  f60528d24a0001         +test byte ptr [0x4ad228], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(4903464) /* 0x4ad228 */) & 1 /*0x1*/));
    // 00422d3b  7434                   -je 0x422d71
    if (cpu.flags.zf)
    {
        goto L_0x00422d71;
    }
    // 00422d3d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422d42  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00422d43:
    // 00422d43  f60528d24a0002         +test byte ptr [0x4ad228], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(4903464) /* 0x4ad228 */) & 2 /*0x2*/));
    // 00422d4a  7425                   -je 0x422d71
    if (cpu.flags.zf)
    {
        goto L_0x00422d71;
    }
    // 00422d4c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422d51  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00422d52:
    // 00422d52  a144d24a00             -mov eax, dword ptr [0x4ad244]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903492) /* 0x4ad244 */);
    // 00422d57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422d59  a130d24a00             -mov eax, dword ptr [0x4ad230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903472) /* 0x4ad230 */);
    // 00422d5e  750f                   -jne 0x422d6f
    if (!cpu.flags.zf)
    {
        goto L_0x00422d6f;
    }
    // 00422d60  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00422d61:
    // 00422d61  a140d24a00             -mov eax, dword ptr [0x4ad240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903488) /* 0x4ad240 */);
    // 00422d66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422d68  a134d24a00             -mov eax, dword ptr [0x4ad234]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903476) /* 0x4ad234 */);
    // 00422d6d  7502                   -jne 0x422d71
    if (!cpu.flags.zf)
    {
        goto L_0x00422d71;
    }
L_0x00422d6f:
    // 00422d6f  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
  [[fallthrough]];
  case 0x00422d71:
L_0x00422d71:
    // 00422d71  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_422d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422d90  e84bfe0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00422d95  f7d8                   +neg eax
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
    // 00422d97  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00422d99  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00422d9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_422da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00422da0  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00422da3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422da4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422da5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422da6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422da7  6828d24a00             -push 0x4ad228
    app->getMemory<x86::reg32>(cpu.esp-4) = 4903464 /*0x4ad228*/;
    cpu.esp -= 4;
    // 00422dac  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00422db0  894c2438               -mov dword ptr [esp + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 00422db4  682cd24a00             -push 0x4ad22c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4903468 /*0x4ad22c*/;
    cpu.esp -= 4;
    // 00422db9  6838d24a00             -push 0x4ad238
    app->getMemory<x86::reg32>(cpu.esp-4) = 4903480 /*0x4ad238*/;
    cpu.esp -= 4;
    // 00422dbe  ba30d24a00             -mov edx, 0x4ad230
    cpu.edx = 4903472 /*0x4ad230*/;
    // 00422dc3  b934d24a00             -mov ecx, 0x4ad234
    cpu.ecx = 4903476 /*0x4ad234*/;
    // 00422dc8  e853fb0300             -call 0x462920
    cpu.esp -= 4;
    sub_462920(app, cpu);
    // 00422dcd  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00422dd1  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00422dd5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422dd6  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00422dda  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422ddb  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00422ddd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422dde  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00422de2  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00422de6  8974242c               -mov dword ptr [esp + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 00422dea  89742438               -mov dword ptr [esp + 0x38], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.esi;
    // 00422dee  8974243c               -mov dword ptr [esp + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 00422df2  89742434               -mov dword ptr [esp + 0x34], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 00422df6  89742430               -mov dword ptr [esp + 0x30], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.esi;
    // 00422dfa  e8a1f80300             -call 0x4626a0
    cpu.esp -= 4;
    sub_4626a0(app, cpu);
    // 00422dff  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00422e01  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00422e03  8a542420               -mov dl, byte ptr [esp + 0x20]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00422e07  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00422e0b  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00422e0f  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 00422e13  eb02                   -jmp 0x422e17
    goto L_0x00422e17;
L_0x00422e15:
    // 00422e15  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00422e17:
    // 00422e17  668b0c9dc0145200       -mov cx, word ptr [ebx*4 + 0x5214c0]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5379264) /* 0x5214c0 */ + cpu.ebx * 4);
    // 00422e1f  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00422e21  f6c50f                 +test ch, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 15 /*0xf*/));
    // 00422e24  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00422e28  7413                   -je 0x422e3d
    if (cpu.flags.zf)
    {
        goto L_0x00422e3d;
    }
    // 00422e2a  81e1ffff0000           +and ecx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00422e30  e8ebfeffff             -call 0x422d20
    cpu.esp -= 4;
    sub_422d20(app, cpu);
    // 00422e35  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00422e37  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00422e3b  eb11                   -jmp 0x422e4e
    goto L_0x00422e4e;
L_0x00422e3d:
    // 00422e3d  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00422e43  e848ffffff             -call 0x422d90
    cpu.esp -= 4;
    sub_422d90(app, cpu);
    // 00422e48  8a542420               -mov dl, byte ptr [esp + 0x20]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00422e4c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00422e4e:
    // 00422e4e  668b0c9dc2145200       -mov cx, word ptr [ebx*4 + 0x5214c2]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5379266) /* 0x5214c2 */ + cpu.ebx * 4);
    // 00422e56  f6c50f                 +test ch, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 15 /*0xf*/));
    // 00422e59  7413                   -je 0x422e6e
    if (cpu.flags.zf)
    {
        goto L_0x00422e6e;
    }
    // 00422e5b  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00422e61  e8bafeffff             -call 0x422d20
    cpu.esp -= 4;
    sub_422d20(app, cpu);
    // 00422e66  0bf8                   +or edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00422e68  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00422e6c  eb11                   -jmp 0x422e7f
    goto L_0x00422e7f;
L_0x00422e6e:
    // 00422e6e  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00422e74  e817ffffff             -call 0x422d90
    cpu.esp -= 4;
    sub_422d90(app, cpu);
    // 00422e79  8a542420               -mov dl, byte ptr [esp + 0x20]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00422e7d  0bf0                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00422e7f:
    // 00422e7f  83fb08                 +cmp ebx, 8
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
    // 00422e82  0f876a010000           -ja 0x422ff2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00422ff2;
    }
    // 00422e88  ff249dd0304200         -jmp dword ptr [ebx*4 + 0x4230d0]
    cpu.ip = app->getMemory<x86::reg32>(4337872 + cpu.ebx * 4); goto dynamic_jump;
  case 0x00422e8f:
    // 00422e8f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422e91  750d                   -jne 0x422ea0
    if (!cpu.flags.zf)
    {
        goto L_0x00422ea0;
    }
    // 00422e93  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422e95  7509                   -jne 0x422ea0
    if (!cpu.flags.zf)
    {
        goto L_0x00422ea0;
    }
    // 00422e97  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00422e9a  0f8452010000           -je 0x422ff2
    if (cpu.flags.zf)
    {
        goto L_0x00422ff2;
    }
L_0x00422ea0:
    // 00422ea0  83cd01                 +or ebp, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebp |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 00422ea3  e94a010000             -jmp 0x422ff2
    goto L_0x00422ff2;
  case 0x00422ea8:
    // 00422ea8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422eaa  750d                   -jne 0x422eb9
    if (!cpu.flags.zf)
    {
        goto L_0x00422eb9;
    }
    // 00422eac  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422eae  7509                   -jne 0x422eb9
    if (!cpu.flags.zf)
    {
        goto L_0x00422eb9;
    }
    // 00422eb0  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00422eb3  0f8439010000           -je 0x422ff2
    if (cpu.flags.zf)
    {
        goto L_0x00422ff2;
    }
L_0x00422eb9:
    // 00422eb9  83cd02                 +or ebp, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebp |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 00422ebc  e931010000             -jmp 0x422ff2
    goto L_0x00422ff2;
  case 0x00422ec1:
    // 00422ec1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422ec3  750d                   -jne 0x422ed2
    if (!cpu.flags.zf)
    {
        goto L_0x00422ed2;
    }
    // 00422ec5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422ec7  7509                   -jne 0x422ed2
    if (!cpu.flags.zf)
    {
        goto L_0x00422ed2;
    }
    // 00422ec9  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 00422ecc  0f8420010000           -je 0x422ff2
    if (cpu.flags.zf)
    {
        goto L_0x00422ff2;
    }
L_0x00422ed2:
    // 00422ed2  83cd04                 +or ebp, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebp |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 00422ed5  e918010000             -jmp 0x422ff2
    goto L_0x00422ff2;
  case 0x00422eda:
    // 00422eda  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00422ede  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00422ee4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422ee6  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00422ee9  0f8a03010000           -jp 0x422ff2
    if (cpu.flags.pf)
    {
        goto L_0x00422ff2;
    }
    // 00422eef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422ef1  750d                   -jne 0x422f00
    if (!cpu.flags.zf)
    {
        goto L_0x00422f00;
    }
    // 00422ef3  db44241c               +fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 00422ef7  d95c2418               +fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422efb  e9f2000000             -jmp 0x422ff2
    goto L_0x00422ff2;
L_0x00422f00:
    // 00422f00  c74424180000fe42       -mov dword ptr [esp + 0x18], 0x42fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 1123942400 /*0x42fe0000*/;
    // 00422f08  e9e5000000             -jmp 0x422ff2
    goto L_0x00422ff2;
  case 0x00422f0d:
    // 00422f0d  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00422f11  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00422f17  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422f19  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00422f1c  0f8ad0000000           -jp 0x422ff2
    if (cpu.flags.pf)
    {
        goto L_0x00422ff2;
    }
    // 00422f22  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422f24  750d                   -jne 0x422f33
    if (!cpu.flags.zf)
    {
        goto L_0x00422f33;
    }
    // 00422f26  db44241c               +fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 00422f2a  d95c2418               +fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00422f2e  e9bf000000             -jmp 0x422ff2
    goto L_0x00422ff2;
L_0x00422f33:
    // 00422f33  c74424180000fec2       -mov dword ptr [esp + 0x18], 0xc2fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 3271426048 /*0xc2fe0000*/;
    // 00422f3b  e9b2000000             -jmp 0x422ff2
    goto L_0x00422ff2;
  case 0x00422f40:
    // 00422f40  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00422f44  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00422f4a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422f4c  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00422f4f  0f8a9d000000           -jp 0x422ff2
    if (cpu.flags.pf)
    {
        goto L_0x00422ff2;
    }
    // 00422f55  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422f57  750a                   -jne 0x422f63
    if (!cpu.flags.zf)
    {
        goto L_0x00422f63;
    }
    // 00422f59  db44241c               +fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 00422f5d  d9542414               +fst dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    // 00422f61  eb53                   -jmp 0x422fb6
    goto L_0x00422fb6;
L_0x00422f63:
    // 00422f63  c74424140000fe42       -mov dword ptr [esp + 0x14], 0x42fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1123942400 /*0x42fe0000*/;
    // 00422f6b  e982000000             -jmp 0x422ff2
    goto L_0x00422ff2;
  case 0x00422f70:
    // 00422f70  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00422f74  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00422f7a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422f7c  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00422f7f  7a71                   -jp 0x422ff2
    if (cpu.flags.pf)
    {
        goto L_0x00422ff2;
    }
    // 00422f81  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422f83  750a                   -jne 0x422f8f
    if (!cpu.flags.zf)
    {
        goto L_0x00422f8f;
    }
    // 00422f85  db44241c               +fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 00422f89  d9542414               +fst dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    // 00422f8d  eb27                   -jmp 0x422fb6
    goto L_0x00422fb6;
L_0x00422f8f:
    // 00422f8f  c74424140000fec2       -mov dword ptr [esp + 0x14], 0xc2fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 3271426048 /*0xc2fe0000*/;
    // 00422f97  eb59                   -jmp 0x422ff2
    goto L_0x00422ff2;
  case 0x00422f99:
    // 00422f99  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00422f9d  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00422fa3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422fa5  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00422fa8  7a48                   -jp 0x422ff2
    if (cpu.flags.pf)
    {
        goto L_0x00422ff2;
    }
    // 00422faa  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422fac  751d                   -jne 0x422fcb
    if (!cpu.flags.zf)
    {
        goto L_0x00422fcb;
    }
L_0x00422fae:
    // 00422fae  db44241c               -fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 00422fb2  d9542410               -fst dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
L_0x00422fb6:
    // 00422fb6  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00422fbc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422fbe  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00422fc1  7b2f                   -jnp 0x422ff2
    if (!cpu.flags.pf)
    {
        goto L_0x00422ff2;
    }
    // 00422fc3  81cd80000000           +or ebp, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.ebp |= x86::reg32(x86::sreg32(128 /*0x80*/))));
    // 00422fc9  eb27                   -jmp 0x422ff2
    goto L_0x00422ff2;
L_0x00422fcb:
    // 00422fcb  c74424100000fe42       -mov dword ptr [esp + 0x10], 0x42fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1123942400 /*0x42fe0000*/;
    // 00422fd3  eb1d                   -jmp 0x422ff2
    goto L_0x00422ff2;
  case 0x00422fd5:
    // 00422fd5  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00422fd9  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00422fdf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00422fe1  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00422fe4  7a0c                   -jp 0x422ff2
    if (cpu.flags.pf)
    {
        goto L_0x00422ff2;
    }
    // 00422fe6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422fe8  74c4                   -je 0x422fae
    if (cpu.flags.zf)
    {
        goto L_0x00422fae;
    }
    // 00422fea  c74424100000fec2       -mov dword ptr [esp + 0x10], 0xc2fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 3271426048 /*0xc2fe0000*/;
L_0x00422ff2:
    // 00422ff2  43                     -inc ebx
    (cpu.ebx)++;
    // 00422ff3  83fb09                 +cmp ebx, 9
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
    // 00422ff6  0f8c19feffff           -jl 0x422e15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422e15;
    }
    // 00422ffc  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00423000  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00423006  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00423008  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0042300b  7a78                   -jp 0x423085
    if (cpu.flags.pf)
    {
        goto L_0x00423085;
    }
    // 0042300d  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00423011  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00423017  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00423019  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0042301c  7a67                   -jp 0x423085
    if (cpu.flags.pf)
    {
        goto L_0x00423085;
    }
    // 0042301e  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00423022  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00423028  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042302a  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0042302d  7a56                   -jp 0x423085
    if (cpu.flags.pf)
    {
        goto L_0x00423085;
    }
    // 0042302f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00423033  83f80a                 +cmp eax, 0xa
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
    // 00423036  7e08                   -jle 0x423040
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423040;
    }
    // 00423038  c74424140000fec2       -mov dword ptr [esp + 0x14], 0xc2fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 3271426048 /*0xc2fe0000*/;
L_0x00423040:
    // 00423040  83f8f6                 +cmp eax, -0xa
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
    // 00423043  7d08                   -jge 0x42304d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042304d;
    }
    // 00423045  c74424140000fe42       -mov dword ptr [esp + 0x14], 0x42fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1123942400 /*0x42fe0000*/;
L_0x0042304d:
    // 0042304d  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00423051  83f80a                 +cmp eax, 0xa
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
    // 00423054  7e08                   -jle 0x42305e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042305e;
    }
    // 00423056  c74424180000fec2       -mov dword ptr [esp + 0x18], 0xc2fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 3271426048 /*0xc2fe0000*/;
L_0x0042305e:
    // 0042305e  83f8f6                 +cmp eax, -0xa
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
    // 00423061  7d08                   -jge 0x42306b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042306b;
    }
    // 00423063  c74424180000fe42       -mov dword ptr [esp + 0x18], 0x42fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 1123942400 /*0x42fe0000*/;
L_0x0042306b:
    // 0042306b  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0042306e  7408                   -je 0x423078
    if (cpu.flags.zf)
    {
        goto L_0x00423078;
    }
    // 00423070  c74424100000fe42       -mov dword ptr [esp + 0x10], 0x42fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1123942400 /*0x42fe0000*/;
L_0x00423078:
    // 00423078  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 0042307b  7408                   -je 0x423085
    if (cpu.flags.zf)
    {
        goto L_0x00423085;
    }
    // 0042307d  c74424100000fec2       -mov dword ptr [esp + 0x10], 0xc2fe0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 3271426048 /*0xc2fe0000*/;
L_0x00423085:
    // 00423085  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00423089  d80d98774800           -fmul dword ptr [0x487798]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749208) /* 0x487798 */));
    // 0042308f  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00423093  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00423097  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0042309b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042309c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042309d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042309f  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004230a3  d80d98774800           -fmul dword ptr [0x487798]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749208) /* 0x487798 */));
    // 004230a9  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004230ad  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004230af  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004230b3  d80d98774800           -fmul dword ptr [0x487798]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749208) /* 0x487798 */));
    // 004230b9  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004230bd  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004230c3  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004230c5  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 004230c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004230c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004230c9  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004230cc  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_423100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423101  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423102  ba40c74800             -mov edx, 0x48c740
    cpu.edx = 4769600 /*0x48c740*/;
    // 00423107  b9e82d4900             -mov ecx, 0x492de8
    cpu.ecx = 4795880 /*0x492de8*/;
    // 0042310c  e82f990200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00423111  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00423113  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00423115  7503                   -jne 0x42311a
    if (!cpu.flags.zf)
    {
        goto L_0x0042311a;
    }
    // 00423117  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423118  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423119  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042311a:
    // 0042311a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042311e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042311f  68d82d4900             -push 0x492dd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795864 /*0x492dd8*/;
    cpu.esp -= 4;
    // 00423124  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423125  e810480500             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 0042312a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042312b  e8a7440500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00423130  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00423134  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423135  68c82d4900             -push 0x492dc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795848 /*0x492dc8*/;
    cpu.esp -= 4;
    // 0042313a  e8783c0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042313f  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00423143  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00423146  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423147  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423148  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423150  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423155  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423156  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00423158  8bb118030000           -mov esi, dword ptr [ecx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 0042315e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00423160  741a                   -je 0x42317c
    if (cpu.flags.zf)
    {
        goto L_0x0042317c;
    }
    // 00423162  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00423164  b9f42d4900             -mov ecx, 0x492df4
    cpu.ecx = 4795892 /*0x492df4*/;
    // 00423169  e8a23a0400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 0042316e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423170  740a                   -je 0x42317c
    if (cpu.flags.zf)
    {
        goto L_0x0042317c;
    }
    // 00423172  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00423174  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00423176  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423177  e9a4350400             -jmp 0x466720
    return sub_466720(app, cpu);
L_0x0042317c:
    // 0042317c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042317d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423180  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423181  8bb118030000           -mov esi, dword ptr [ecx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 00423187  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00423189  741a                   -je 0x4231a5
    if (cpu.flags.zf)
    {
        goto L_0x004231a5;
    }
    // 0042318b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042318d  b9042e4900             -mov ecx, 0x492e04
    cpu.ecx = 4795908 /*0x492e04*/;
    // 00423192  e8793a0400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00423197  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423199  740a                   -je 0x4231a5
    if (cpu.flags.zf)
    {
        goto L_0x004231a5;
    }
    // 0042319b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042319d  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042319f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004231a0  e97b350400             -jmp 0x466720
    return sub_466720(app, cpu);
L_0x004231a5:
    // 004231a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004231a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4231b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004231b0  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004231b6  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 004231ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004231bb  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004231bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004231be  68642e4900             -push 0x492e64
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796004 /*0x492e64*/;
    cpu.esp -= 4;
    // 004231c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004231c4  e82f3c0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004231c9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004231cc  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004231d0  e8bb500400             -call 0x468290
    cpu.esp -= 4;
    sub_468290(app, cpu);
    // 004231d5  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004231d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004231da  68502e4900             -push 0x492e50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795984 /*0x492e50*/;
    cpu.esp -= 4;
    // 004231df  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004231e0  e8133c0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004231e5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004231e8  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004231ec  e8bfdb0300             -call 0x460db0
    cpu.esp -= 4;
    sub_460db0(app, cpu);
    // 004231f1  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004231f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004231f6  683c2e4900             -push 0x492e3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795964 /*0x492e3c*/;
    cpu.esp -= 4;
    // 004231fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004231fc  e8f73b0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00423201  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423204  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00423208  e823fd0300             -call 0x462f30
    cpu.esp -= 4;
    sub_462f30(app, cpu);
    // 0042320d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00423211  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423212  68282e4900             -push 0x492e28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795944 /*0x492e28*/;
    cpu.esp -= 4;
    // 00423217  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423218  e8db3b0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042321d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423220  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00423224  e857c60300             -call 0x45f880
    cpu.esp -= 4;
    sub_45f880(app, cpu);
    // 00423229  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042322d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042322e  68102e4900             -push 0x492e10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795920 /*0x492e10*/;
    cpu.esp -= 4;
    // 00423233  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423234  e8bf3b0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00423239  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042323c  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00423240  e88b110200             -call 0x4443d0
    cpu.esp -= 4;
    sub_4443d0(app, cpu);
    // 00423245  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423246  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0042324c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423250  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 00423255  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0042325b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00423260  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 00423264  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423265  68102e4900             -push 0x492e10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795920 /*0x492e10*/;
    cpu.esp -= 4;
    // 0042326a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042326b  e8883b0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00423270  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423273  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 00423277  e8a4110200             -call 0x444420
    cpu.esp -= 4;
    sub_444420(app, cpu);
    // 0042327c  8b1510155200           -mov edx, dword ptr [0x521510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 00423282  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 00423286  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042328c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042328d  68502e4900             -push 0x492e50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795984 /*0x492e50*/;
    cpu.esp -= 4;
    // 00423292  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423293  e8603b0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00423298  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042329b  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 0042329f  e87cdb0300             -call 0x460e20
    cpu.esp -= 4;
    sub_460e20(app, cpu);
    // 004232a4  8b0d10155200           -mov ecx, dword ptr [0x521510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 004232aa  8d542400               -lea edx, [esp]
    cpu.edx = x86::reg32(cpu.esp);
    // 004232ae  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004232b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004232b5  683c2e4900             -push 0x492e3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795964 /*0x492e3c*/;
    cpu.esp -= 4;
    // 004232ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004232bb  e8383b0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004232c0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004232c3  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 004232c7  e8f4fc0300             -call 0x462fc0
    cpu.esp -= 4;
    sub_462fc0(app, cpu);
    // 004232cc  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 004232d1  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 004232d5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004232da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004232db  68282e4900             -push 0x492e28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795944 /*0x492e28*/;
    cpu.esp -= 4;
    // 004232e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004232e1  e8123b0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004232e6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004232e9  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 004232ed  e86ec80300             -call 0x45fb60
    cpu.esp -= 4;
    sub_45fb60(app, cpu);
    // 004232f2  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004232f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423300  e88bbaffff             -call 0x41ed90
    cpu.esp -= 4;
    sub_41ed90(app, cpu);
    // 00423305  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423307  66a35a155200           -mov word ptr [0x52155a], ax
    app->getMemory<x86::reg16>(x86::reg32(5379418) /* 0x52155a */) = cpu.ax;
    // 0042330d  668bc8                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 00423310  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423312  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423320  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 00423325  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423326  83f840                 +cmp eax, 0x40
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
    // 00423329  7c77                   -jl 0x4233a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004233a2;
    }
    // 0042332b  a190d34a00             -mov eax, dword ptr [0x4ad390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903824) /* 0x4ad390 */);
    // 00423330  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423332  7507                   -jne 0x42333b
    if (!cpu.flags.zf)
    {
        goto L_0x0042333b;
    }
    // 00423334  e8c7ffffff             -call 0x423300
    cpu.esp -= 4;
    sub_423300(app, cpu);
    // 00423339  eb05                   -jmp 0x423340
    goto L_0x00423340;
L_0x0042333b:
    // 0042333b  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
L_0x00423340:
    // 00423340  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423346  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00423348  8b8a80000000           -mov ecx, dword ptr [edx + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0042334e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423354  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00423357  8b8ad8000000           -mov ecx, dword ptr [edx + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0042335d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042335e  8b8ad4000000           -mov ecx, dword ptr [edx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 00423364  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423365  8b8ad0000000           -mov ecx, dword ptr [edx + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0042336b  8b92c8020000           -mov edx, dword ptr [edx + 0x2c8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(712) /* 0x2c8 */);
    // 00423371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423372  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00423374  e8a7ea0000             -call 0x431e20
    cpu.esp -= 4;
    sub_431e20(app, cpu);
    // 00423379  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0042337b:
    // 0042337b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042337d  7421                   -je 0x4233a0
    if (cpu.flags.zf)
    {
        goto L_0x004233a0;
    }
    // 0042337f  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423384  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00423386  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423388  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042338a  e8c1380300             -call 0x456c50
    cpu.esp -= 4;
    sub_456c50(app, cpu);
    // 0042338f  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423395  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423397  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00423399  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042339b  e8b0380300             -call 0x456c50
    cpu.esp -= 4;
    sub_456c50(app, cpu);
L_0x004233a0:
    // 004233a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004233a2:
    // 004233a2  e8b9280300             -call 0x455c60
    cpu.esp -= 4;
    sub_455c60(app, cpu);
    // 004233a7  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004233a9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004233ab  74f3                   -je 0x4233a0
    if (cpu.flags.zf)
    {
        goto L_0x004233a0;
    }
L_0x004233ad:
    // 004233ad  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004233af  8a4e48                 -mov cl, byte ptr [esi + 0x48]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004233b2  e83920feff             -call 0x4053f0
    cpu.esp -= 4;
    sub_4053f0(app, cpu);
    // 004233b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004233b9  75c0                   -jne 0x42337b
    if (!cpu.flags.zf)
    {
        goto L_0x0042337b;
    }
    // 004233bb  8bb630030000           -mov esi, dword ptr [esi + 0x330]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(816) /* 0x330 */);
    // 004233c1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004233c3  75e8                   -jne 0x4233ad
    if (!cpu.flags.zf)
    {
        goto L_0x004233ad;
    }
    // 004233c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4233d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004233d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004233d1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004233d3  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 004233d6  81ecd8000000           -sub esp, 0xd8
    (cpu.esp) -= x86::reg32(x86::sreg32(216 /*0xd8*/));
    // 004233dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004233dd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004233de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004233df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004233e0  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004233e2  68bc324900             -push 0x4932bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797116 /*0x4932bc*/;
    cpu.esp -= 4;
    // 004233e7  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004233e9  897c2430               -mov dword ptr [esp + 0x30], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edi;
    // 004233ed  e8c5390500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004233f2  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 004233f7  e86b450500             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 004233fc  68a4324900             -push 0x4932a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797092 /*0x4932a4*/;
    cpu.esp -= 4;
    // 00423401  e877510500             -call 0x47857d
    cpu.esp -= 4;
    sub_47857d(app, cpu);
    // 00423406  6808c74800             -push 0x48c708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769544 /*0x48c708*/;
    cpu.esp -= 4;
    // 0042340b  6898324900             -push 0x493298
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797080 /*0x493298*/;
    cpu.esp -= 4;
    // 00423410  e849480500             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 00423415  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00423418  3bc7                   +cmp eax, edi
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
    // 0042341a  7518                   -jne 0x423434
    if (!cpu.flags.zf)
    {
        goto L_0x00423434;
    }
    // 0042341c  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042341e  68803e0000             -push 0x3e80
    app->getMemory<x86::reg32>(cpu.esp-4) = 16000 /*0x3e80*/;
    cpu.esp -= 4;
    // 00423423  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00423428  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0042342d  e83ef80300             -call 0x462c70
    cpu.esp -= 4;
    sub_462c70(app, cpu);
    // 00423432  eb09                   -jmp 0x42343d
    goto L_0x0042343d;
L_0x00423434:
    // 00423434  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423435  e89d410500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0042343a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042343d:
    // 0042343d  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00423441  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423442  6890324900             -push 0x493290
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797072 /*0x493290*/;
    cpu.esp -= 4;
    // 00423447  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423448  e807420500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0042344d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423450  83f801                 +cmp eax, 1
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
    // 00423453  750b                   -jne 0x423460
    if (!cpu.flags.zf)
    {
        goto L_0x00423460;
    }
    // 00423455  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00423459  e842300000             -call 0x4264a0
    cpu.esp -= 4;
    sub_4264a0(app, cpu);
    // 0042345e  eb2e                   -jmp 0x42348e
    goto L_0x0042348e;
L_0x00423460:
    // 00423460  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423462  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00423467  e8f4270000             -call 0x425c60
    cpu.esp -= 4;
    sub_425c60(app, cpu);
    // 0042346c  83f801                 +cmp eax, 1
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
    // 0042346f  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00423473  0f842a130000           -je 0x4247a3
    if (cpu.flags.zf)
    {
        goto L_0x004247a3;
    }
    // 00423479  83f802                 +cmp eax, 2
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
    // 0042347c  7510                   -jne 0x42348e
    if (!cpu.flags.zf)
    {
        goto L_0x0042348e;
    }
    // 0042347e  803d1015520001         +cmp byte ptr [0x521510], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423485  7507                   -jne 0x42348e
    if (!cpu.flags.zf)
    {
        goto L_0x0042348e;
    }
    // 00423487  c6051015520007         -mov byte ptr [0x521510], 7
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = 7 /*0x7*/;
L_0x0042348e:
    // 0042348e  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 00423493  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00423497  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042349c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042349d  6888324900             -push 0x493288
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797064 /*0x493288*/;
    cpu.esp -= 4;
    // 004234a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004234a3  a3dc284900             -mov dword ptr [0x4928dc], eax
    app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */) = cpu.eax;
    // 004234a8  e84b390500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004234ad  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004234b0  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004234b4  e8974d0400             -call 0x468250
    cpu.esp -= 4;
    sub_468250(app, cpu);
    // 004234b9  803d1015520007         +cmp byte ptr [0x521510], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004234c0  7428                   -je 0x4234ea
    if (cpu.flags.zf)
    {
        goto L_0x004234ea;
    }
    // 004234c2  8b1510155200           -mov edx, dword ptr [0x521510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 004234c8  8d442468               -lea eax, [esp + 0x68]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004234cc  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004234d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004234d3  68642e4900             -push 0x492e64
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796004 /*0x492e64*/;
    cpu.esp -= 4;
    // 004234d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004234d9  e8d9380500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004234de  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004234e1  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004234e5  e8564e0400             -call 0x468340
    cpu.esp -= 4;
    sub_468340(app, cpu);
L_0x004234ea:
    // 004234ea  e841220400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004234ef  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 004234f5  dd5c2438               -fstp qword ptr [esp + 0x38]
    app->getMemory<double>(cpu.esp + x86::reg32(56) /* 0x38 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004234f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004234fa  6878324900             -push 0x493278
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797048 /*0x493278*/;
    cpu.esp -= 4;
    // 004234ff  e8b3380500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423504  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423507  b967120000             -mov ecx, 0x1267
    cpu.ecx = 4711 /*0x1267*/;
    // 0042350c  e8efa10200             -call 0x44d700
    cpu.esp -= 4;
    sub_44d700(app, cpu);
    // 00423511  e84a210400             -call 0x465660
    cpu.esp -= 4;
    sub_465660(app, cpu);
    // 00423516  ba28000000             -mov edx, 0x28
    cpu.edx = 40 /*0x28*/;
    // 0042351b  b9a0fc5100             -mov ecx, 0x51fca0
    cpu.ecx = 5373088 /*0x51fca0*/;
    // 00423520  c6050484510000         -mov byte ptr [0x518404], 0
    app->getMemory<x86::reg8>(x86::reg32(5342212) /* 0x518404 */) = 0 /*0x0*/;
    // 00423527  c6050584510000         -mov byte ptr [0x518405], 0
    app->getMemory<x86::reg8>(x86::reg32(5342213) /* 0x518405 */) = 0 /*0x0*/;
    // 0042352e  c60508d2490000         -mov byte ptr [0x49d208], 0
    app->getMemory<x86::reg8>(x86::reg32(4837896) /* 0x49d208 */) = 0 /*0x0*/;
    // 00423535  c705a4fc510000000000   -mov dword ptr [0x51fca4], 0
    app->getMemory<x86::reg32>(x86::reg32(5373092) /* 0x51fca4 */) = 0 /*0x0*/;
    // 0042353f  c705a8fc5100000080bf   -mov dword ptr [0x51fca8], 0xbf800000
    app->getMemory<x86::reg32>(x86::reg32(5373096) /* 0x51fca8 */) = 3212836864 /*0xbf800000*/;
    // 00423549  c705acfc51000000803f   -mov dword ptr [0x51fcac], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(5373100) /* 0x51fcac */) = 1065353216 /*0x3f800000*/;
    // 00423553  e8f8940200             -call 0x44ca50
    cpu.esp -= 4;
    sub_44ca50(app, cpu);
    // 00423558  8b15e4284900           -mov edx, dword ptr [0x4928e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4794596) /* 0x4928e4 */);
    // 0042355e  c70518d249000000803f   -mov dword ptr [0x49d218], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(4837912) /* 0x49d218 */) = 1065353216 /*0x3f800000*/;
    // 00423568  891514d24900           -mov dword ptr [0x49d214], edx
    app->getMemory<x86::reg32>(x86::reg32(4837908) /* 0x49d214 */) = cpu.edx;
    // 0042356e  e84d320000             -call 0x4267c0
    cpu.esp -= 4;
    sub_4267c0(app, cpu);
    // 00423573  e888fbffff             -call 0x423100
    cpu.esp -= 4;
    sub_423100(app, cpu);
    // 00423578  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423579  686c324900             -push 0x49326c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797036 /*0x49326c*/;
    cpu.esp -= 4;
    // 0042357e  e82d160300             -call 0x454bb0
    cpu.esp -= 4;
    sub_454bb0(app, cpu);
    // 00423583  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423586  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423588  b964324900             -mov ecx, 0x493264
    cpu.ecx = 4797028 /*0x493264*/;
    // 0042358d  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0042358f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00423591  e85a09ffff             -call 0x413ef0
    cpu.esp -= 4;
    sub_413ef0(app, cpu);
    // 00423596  e825450300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 0042359b  e8001dffff             -call 0x4152a0
    cpu.esp -= 4;
    sub_4152a0(app, cpu);
    // 004235a0  e88b3a0000             -call 0x427030
    cpu.esp -= 4;
    sub_427030(app, cpu);
    // 004235a5  e8c6480000             -call 0x427e70
    cpu.esp -= 4;
    sub_427e70(app, cpu);
    // 004235aa  803d1015520007         +cmp byte ptr [0x521510], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004235b1  0f8594010000           -jne 0x42374b
    if (!cpu.flags.zf)
    {
        goto L_0x0042374b;
    }
    // 004235b7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004235b9  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004235bb  e8b011ffff             -call 0x414770
    cpu.esp -= 4;
    sub_414770(app, cpu);
    // 004235c0  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004235c5  c70588d34a0001000000   -mov dword ptr [0x4ad388], 1
    app->getMemory<x86::reg32>(x86::reg32(4903816) /* 0x4ad388 */) = 1 /*0x1*/;
    // 004235cf  e88c3f0000             -call 0x427560
    cpu.esp -= 4;
    sub_427560(app, cpu);
    // 004235d4  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004235d9  e81233ffff             -call 0x4168f0
    cpu.esp -= 4;
    sub_4168f0(app, cpu);
    // 004235de  e89d33ffff             -call 0x416980
    cpu.esp -= 4;
    sub_416980(app, cpu);
    // 004235e3  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004235e5  e8a61bffff             -call 0x415190
    cpu.esp -= 4;
    sub_415190(app, cpu);
L_0x004235ea:
    // 004235ea  e801f50300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 004235ef  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004235f3  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004235f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004235f8  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004235fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004235fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004235fe  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00423602  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00423606  e895f7ffff             -call 0x422da0
    cpu.esp -= 4;
    sub_422da0(app, cpu);
    // 0042360b  e800120400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00423610  e81b210400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423615  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 0042361b  e870370500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00423620  a348845100             -mov dword ptr [0x518448], eax
    app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */) = cpu.eax;
    // 00423625  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00423629  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0042362b  7432                   -je 0x42365f
    if (cpu.flags.zf)
    {
        goto L_0x0042365f;
    }
L_0x0042362d:
    // 0042362d  e8bef40300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00423632  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00423636  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042363a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042363b  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0042363f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423640  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423641  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00423645  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00423649  e852f7ffff             -call 0x422da0
    cpu.esp -= 4;
    sub_422da0(app, cpu);
    // 0042364e  e8bd110400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00423653  f644241401             +test byte ptr [esp + 0x14], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 1 /*0x1*/));
    // 00423658  75d3                   -jne 0x42362d
    if (!cpu.flags.zf)
    {
        goto L_0x0042362d;
    }
    // 0042365a  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0042365f:
    // 0042365f  a158845100             -mov eax, dword ptr [0x518458]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342296) /* 0x518458 */);
    // 00423664  3bc7                   +cmp eax, edi
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
    // 00423666  7402                   -je 0x42366a
    if (cpu.flags.zf)
    {
        goto L_0x0042366a;
    }
    // 00423668  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042366a:
    // 0042366a  3bf7                   +cmp esi, edi
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
    // 0042366c  0f8478ffffff           -je 0x4235ea
    if (cpu.flags.zf)
    {
        goto L_0x004235ea;
    }
    // 00423672  6860324900             -push 0x493260
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797024 /*0x493260*/;
    cpu.esp -= 4;
    // 00423677  ba5c324900             -mov edx, 0x49325c
    cpu.edx = 4797020 /*0x49325c*/;
    // 0042367c  b950324900             -mov ecx, 0x493250
    cpu.ecx = 4797008 /*0x493250*/;
    // 00423681  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00423683  e82860ffff             -call 0x4196b0
    cpu.esp -= 4;
    sub_4196b0(app, cpu);
    // 00423688  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0042368d  e85e32ffff             -call 0x4168f0
    cpu.esp -= 4;
    sub_4168f0(app, cpu);
    // 00423692  e8e932ffff             -call 0x416980
    cpu.esp -= 4;
    sub_416980(app, cpu);
    // 00423697  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00423699  e8f21affff             -call 0x415190
    cpu.esp -= 4;
    sub_415190(app, cpu);
L_0x0042369e:
    // 0042369e  e84df40300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 004236a3  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004236a7  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004236ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004236ac  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004236b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004236b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004236b2  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004236b6  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004236ba  e8e1f6ffff             -call 0x422da0
    cpu.esp -= 4;
    sub_422da0(app, cpu);
    // 004236bf  e84c110400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 004236c4  e867200400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004236c9  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 004236cf  e8bc360500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 004236d4  a348845100             -mov dword ptr [0x518448], eax
    app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */) = cpu.eax;
    // 004236d9  e8b25fffff             -call 0x419690
    cpu.esp -= 4;
    sub_419690(app, cpu);
    // 004236de  83f8ff                 +cmp eax, -1
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
    // 004236e1  7414                   -je 0x4236f7
    if (cpu.flags.zf)
    {
        goto L_0x004236f7;
    }
    // 004236e3  f7d8                   +neg eax
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
    // 004236e5  1ac0                   -sbb al, al
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.al) + cpu.flags.cf);
    // 004236e7  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004236ec  2406                   +and al, 6
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(6 /*0x6*/))));
    // 004236ee  fec0                   +inc al
    {
        x86::reg8& tmp = cpu.al;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 004236f0  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 004236f5  eb05                   -jmp 0x4236fc
    goto L_0x004236fc;
L_0x004236f7:
    // 004236f7  83fe01                 +cmp esi, 1
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
    // 004236fa  7527                   -jne 0x423723
    if (!cpu.flags.zf)
    {
        goto L_0x00423723;
    }
L_0x004236fc:
    // 004236fc  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00423701  893d88d34a00           -mov dword ptr [0x4ad388], edi
    app->getMemory<x86::reg32>(x86::reg32(4903816) /* 0x4ad388 */) = cpu.edi;
    // 00423707  e86410ffff             -call 0x414770
    cpu.esp -= 4;
    sub_414770(app, cpu);
    // 0042370c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042370e  e8dd31ffff             -call 0x4168f0
    cpu.esp -= 4;
    sub_4168f0(app, cpu);
    // 00423713  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423715  e8463e0000             -call 0x427560
    cpu.esp -= 4;
    sub_427560(app, cpu);
    // 0042371a  803d1015520007         +cmp byte ptr [0x521510], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423721  7415                   -je 0x423738
    if (cpu.flags.zf)
    {
        goto L_0x00423738;
    }
L_0x00423723:
    // 00423723  a158845100             -mov eax, dword ptr [0x518458]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342296) /* 0x518458 */);
    // 00423728  3bc7                   +cmp eax, edi
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
    // 0042372a  7402                   -je 0x42372e
    if (cpu.flags.zf)
    {
        goto L_0x0042372e;
    }
    // 0042372c  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042372e:
    // 0042372e  3bf7                   +cmp esi, edi
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
    // 00423730  0f8468ffffff           -je 0x42369e
    if (cpu.flags.zf)
    {
        goto L_0x0042369e;
    }
    // 00423736  eb13                   -jmp 0x42374b
    goto L_0x0042374b;
L_0x00423738:
    // 00423738  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042373a  e8b131ffff             -call 0x4168f0
    cpu.esp -= 4;
    sub_4168f0(app, cpu);
    // 0042373f  e80c3e0000             -call 0x427550
    cpu.esp -= 4;
    sub_427550(app, cpu);
    // 00423744  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00423746  e815400000             -call 0x427760
    cpu.esp -= 4;
    sub_427760(app, cpu);
L_0x0042374b:
    // 0042374b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00423750  893d48845100           -mov dword ptr [0x518448], edi
    app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */) = cpu.edi;
    // 00423756  e805abffff             -call 0x41e260
    cpu.esp -= 4;
    sub_41e260(app, cpu);
    // 0042375b  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 00423760  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00423765  a3dc284900             -mov dword ptr [0x4928dc], eax
    app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */) = cpu.eax;
    // 0042376a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042376b  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0042376f  6888324900             -push 0x493288
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797064 /*0x493288*/;
    cpu.esp -= 4;
    // 00423774  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423775  e87e360500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042377a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042377d  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00423781  e8ca4a0400             -call 0x468250
    cpu.esp -= 4;
    sub_468250(app, cpu);
    // 00423786  e8a51f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042378b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042378d  e87e9f0200             -call 0x44d710
    cpu.esp -= 4;
    sub_44d710(app, cpu);
    // 00423792  e8991f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423797  dc0d88784800           -fmul qword ptr [0x487888]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749448) /* 0x487888 */));
    // 0042379d  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004237a0  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004237a3  6824324900             -push 0x493224
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796964 /*0x493224*/;
    cpu.esp -= 4;
    // 004237a8  e80a360500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004237ad  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004237b0  e87b1f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004237b5  dc0d88784800           -fmul qword ptr [0x487888]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749448) /* 0x487888 */));
    // 004237bb  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 004237c1  e8ca350500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 004237c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004237c7  e87e360500             -call 0x476e4a
    cpu.esp -= 4;
    sub_476e4a(app, cpu);
    // 004237cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004237cf  e85c1f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004237d4  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004237d8  e873faffff             -call 0x423250
    cpu.esp -= 4;
    sub_423250(app, cpu);
    // 004237dd  e84e1f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004237e2  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 004237e6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004237e9  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004237ec  68fc314900             -push 0x4931fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796924 /*0x4931fc*/;
    cpu.esp -= 4;
    // 004237f1  e8c1350500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004237f6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004237f9  e8321f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004237fe  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423802  e8291f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423807  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 0042380b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042380e  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423811  68e4314900             -push 0x4931e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796900 /*0x4931e4*/;
    cpu.esp -= 4;
    // 00423816  e89c350500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042381b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042381e  e80d1d0000             -call 0x425530
    cpu.esp -= 4;
    sub_425530(app, cpu);
    // 00423823  e8c8150000             -call 0x424df0
    cpu.esp -= 4;
    sub_424df0(app, cpu);
    // 00423828  8b0d10155200           -mov ecx, dword ptr [0x521510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 0042382e  8d542468               -lea edx, [esp + 0x68]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00423832  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00423838  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423839  68d0314900             -push 0x4931d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796880 /*0x4931d0*/;
    cpu.esp -= 4;
    // 0042383e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042383f  e8b4350500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00423844  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423847  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0042384b  e8e0f60000             -call 0x432f30
    cpu.esp -= 4;
    sub_432f30(app, cpu);
    // 00423850  e86b420300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00423855  e856a90000             -call 0x42e1b0
    cpu.esp -= 4;
    sub_42e1b0(app, cpu);
    // 0042385a  e8e18efeff             -call 0x40c740
    cpu.esp -= 4;
    sub_40c740(app, cpu);
    // 0042385f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00423861  7517                   -jne 0x42387a
    if (!cpu.flags.zf)
    {
        goto L_0x0042387a;
    }
    // 00423863  68b6020000             -push 0x2b6
    app->getMemory<x86::reg32>(cpu.esp-4) = 694 /*0x2b6*/;
    cpu.esp -= 4;
    // 00423868  68a4314900             -push 0x4931a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796836 /*0x4931a4*/;
    cpu.esp -= 4;
    // 0042386d  686c314900             -push 0x49316c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796780 /*0x49316c*/;
    cpu.esp -= 4;
    // 00423872  e840350500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423877  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042387a:
    // 0042387a  e8b11e0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042387f  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00423883  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423886  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423889  6844314900             -push 0x493144
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796740 /*0x493144*/;
    cpu.esp -= 4;
    // 0042388e  e824350500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423893  8b3548845100           -mov esi, dword ptr [0x518448]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00423899  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042389c  46                     -inc esi
    (cpu.esi)++;
    // 0042389d  893548845100           -mov dword ptr [0x518448], esi
    app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */) = cpu.esi;
    // 004238a3  e898d30200             -call 0x450c40
    cpu.esp -= 4;
    sub_450c40(app, cpu);
    // 004238a8  e8831e0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004238ad  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 004238b2  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004238b6  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004238ba  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004238bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004238c0  6834314900             -push 0x493134
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796724 /*0x493134*/;
    cpu.esp -= 4;
    // 004238c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004238c6  e82d350500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004238cb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004238ce  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004238d3  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004238d7  e8146cfeff             -call 0x40a4f0
    cpu.esp -= 4;
    sub_40a4f0(app, cpu);
    // 004238dc  e84f1e0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004238e1  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 004238e5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004238e8  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004238eb  6818314900             -push 0x493118
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796696 /*0x493118*/;
    cpu.esp -= 4;
    // 004238f0  e8c2340500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004238f5  8b1510155200           -mov edx, dword ptr [0x521510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 004238fb  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004238ff  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00423905  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423906  6800314900             -push 0x493100
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796672 /*0x493100*/;
    cpu.esp -= 4;
    // 0042390b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042390c  e8e7340500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00423911  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00423914  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00423918  e8a3de0300             -call 0x4617c0
    cpu.esp -= 4;
    sub_4617c0(app, cpu);
    // 0042391d  e89e410300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00423922  e899410300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00423927  e8041e0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042392c  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423930  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 00423935  e8466e0300             -call 0x45a780
    cpu.esp -= 4;
    sub_45a780(app, cpu);
    // 0042393a  e8f11d0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042393f  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00423943  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423946  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423949  68dc304900             -push 0x4930dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796636 /*0x4930dc*/;
    cpu.esp -= 4;
    // 0042394e  e864340500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423953  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423956  e8e56d0300             -call 0x45a740
    cpu.esp -= 4;
    sub_45a740(app, cpu);
    // 0042395b  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042395d  e8fea8ffff             -call 0x41e260
    cpu.esp -= 4;
    sub_41e260(app, cpu);
    // 00423962  e8c91d0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423967  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 0042396b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042396e  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423971  68bc304900             -push 0x4930bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796604 /*0x4930bc*/;
    cpu.esp -= 4;
    // 00423976  e83c340500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042397b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042397e  e8ad1d0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423983  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423987  e834410300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 0042398c  e89f1d0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423991  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00423995  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423998  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042399b  689c304900             -push 0x49309c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796572 /*0x49309c*/;
    cpu.esp -= 4;
    // 004239a0  e812340500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004239a5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004239a8  e8831d0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004239ad  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004239b1  b9b0474200             -mov ecx, 0x4247b0
    cpu.ecx = 4343728 /*0x4247b0*/;
    // 004239b6  e8f56a0300             -call 0x45a4b0
    cpu.esp -= 4;
    sub_45a4b0(app, cpu);
    // 004239bb  e8701d0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004239c0  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 004239c4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004239c7  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004239ca  6880304900             -push 0x493080
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796544 /*0x493080*/;
    cpu.esp -= 4;
    // 004239cf  e8e3330500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004239d4  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 004239d9  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004239de  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004239e1  3bc3                   +cmp eax, ebx
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
    // 004239e3  7c1c                   -jl 0x423a01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423a01;
    }
    // 004239e5  e836f9ffff             -call 0x423320
    cpu.esp -= 4;
    sub_423320(app, cpu);
    // 004239ea  689a99d93f             -push 0x3fd9999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1071225242 /*0x3fd9999a*/;
    cpu.esp -= 4;
    // 004239ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004239f0  687b142ebe             -push 0xbe2e147b
    app->getMemory<x86::reg32>(cpu.esp-4) = 3190690939 /*0xbe2e147b*/;
    cpu.esp -= 4;
    // 004239f5  e8268c0300             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 004239fa  e8c19a0300             -call 0x45d4c0
    cpu.esp -= 4;
    sub_45d4c0(app, cpu);
    // 004239ff  eb0c                   -jmp 0x423a0d
    goto L_0x00423a0d;
L_0x00423a01:
    // 00423a01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423a02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423a03  687b142ebe             -push 0xbe2e147b
    app->getMemory<x86::reg32>(cpu.esp-4) = 3190690939 /*0xbe2e147b*/;
    cpu.esp -= 4;
    // 00423a08  e8138c0300             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
L_0x00423a0d:
    // 00423a0d  8b0d10155200           -mov ecx, dword ptr [0x521510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 00423a13  8d542468               -lea edx, [esp + 0x68]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00423a17  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00423a1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423a1e  6800314900             -push 0x493100
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796672 /*0x493100*/;
    cpu.esp -= 4;
    // 00423a23  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423a24  e8cf330500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00423a29  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423a2c  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00423a30  e88bdd0300             -call 0x4617c0
    cpu.esp -= 4;
    sub_4617c0(app, cpu);
    // 00423a35  3b052c845100           +cmp eax, dword ptr [0x51842c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423a3b  7d09                   -jge 0x423a46
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423a46;
    }
    // 00423a3d  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00423a41  e80adc0300             -call 0x461650
    cpu.esp -= 4;
    sub_461650(app, cpu);
L_0x00423a46:
    // 00423a46  e865170000             -call 0x4251b0
    cpu.esp -= 4;
    sub_4251b0(app, cpu);
    // 00423a4b  e89038ffff             -call 0x4172e0
    cpu.esp -= 4;
    sub_4172e0(app, cpu);
    // 00423a50  e85bd30000             -call 0x430db0
    cpu.esp -= 4;
    sub_430db0(app, cpu);
    // 00423a55  e8a6ceffff             -call 0x420900
    cpu.esp -= 4;
    sub_420900(app, cpu);
    // 00423a5a  686c304900             -push 0x49306c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796524 /*0x49306c*/;
    cpu.esp -= 4;
    // 00423a5f  e853330500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423a64  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423a67  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00423a6c  e81fa20000             -call 0x42dc90
    cpu.esp -= 4;
    sub_42dc90(app, cpu);
    // 00423a71  803d1015520040         +cmp byte ptr [0x521510], 0x40
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
    // 00423a78  7205                   -jb 0x423a7f
    if (cpu.flags.cf)
    {
        goto L_0x00423a7f;
    }
    // 00423a7a  e871620000             -call 0x429cf0
    cpu.esp -= 4;
    sub_429cf0(app, cpu);
L_0x00423a7f:
    // 00423a7f  e8ac290000             -call 0x426430
    cpu.esp -= 4;
    sub_426430(app, cpu);
    // 00423a84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423a86  7505                   -jne 0x423a8d
    if (!cpu.flags.zf)
    {
        goto L_0x00423a8d;
    }
    // 00423a88  e8c3f6ffff             -call 0x423150
    cpu.esp -= 4;
    sub_423150(app, cpu);
L_0x00423a8d:
    // 00423a8d  e8fe690300             -call 0x45a490
    cpu.esp -= 4;
    sub_45a490(app, cpu);
    // 00423a92  e8991c0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423a97  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423a9b  b9b0474200             -mov ecx, 0x4247b0
    cpu.ecx = 4343728 /*0x4247b0*/;
    // 00423aa0  e84b6a0300             -call 0x45a4f0
    cpu.esp -= 4;
    sub_45a4f0(app, cpu);
    // 00423aa5  e8861c0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423aaa  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00423aae  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423ab1  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423ab4  6848304900             -push 0x493048
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796488 /*0x493048*/;
    cpu.esp -= 4;
    // 00423ab9  e8f9320500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423abe  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 00423ac3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423ac6  3bc7                   +cmp eax, edi
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
    // 00423ac8  7505                   -jne 0x423acf
    if (!cpu.flags.zf)
    {
        goto L_0x00423acf;
    }
    // 00423aca  e811db0000             -call 0x4315e0
    cpu.esp -= 4;
    sub_4315e0(app, cpu);
L_0x00423acf:
    // 00423acf  e85c1c0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423ad4  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423ad8  e8a30e0000             -call 0x424980
    cpu.esp -= 4;
    sub_424980(app, cpu);
    // 00423add  e84e1c0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423ae2  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00423ae6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423ae9  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423aec  6820304900             -push 0x493020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796448 /*0x493020*/;
    cpu.esp -= 4;
    // 00423af1  e8c1320500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423af6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423af9  e8321c0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423afe  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423b02  e8291c0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423b07  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00423b0b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423b0e  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423b11  6804304900             -push 0x493004
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796420 /*0x493004*/;
    cpu.esp -= 4;
    // 00423b16  e89c320500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423b1b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423b1e  e86d690300             -call 0x45a490
    cpu.esp -= 4;
    sub_45a490(app, cpu);
    // 00423b23  e8081c0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423b28  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423b2a  e8f1ac0400             -call 0x46e820
    cpu.esp -= 4;
    sub_46e820(app, cpu);
    // 00423b2f  e8fc280000             -call 0x426430
    cpu.esp -= 4;
    sub_426430(app, cpu);
    // 00423b34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423b36  7427                   -je 0x423b5f
    if (cpu.flags.zf)
    {
        goto L_0x00423b5f;
    }
    // 00423b38  e803290000             -call 0x426440
    cpu.esp -= 4;
    sub_426440(app, cpu);
    // 00423b3d  e8fe8bfeff             -call 0x40c740
    cpu.esp -= 4;
    sub_40c740(app, cpu);
    // 00423b42  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00423b44  7526                   -jne 0x423b6c
    if (!cpu.flags.zf)
    {
        goto L_0x00423b6c;
    }
    // 00423b46  6864030000             -push 0x364
    app->getMemory<x86::reg32>(cpu.esp-4) = 868 /*0x364*/;
    cpu.esp -= 4;
    // 00423b4b  68a4314900             -push 0x4931a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796836 /*0x4931a4*/;
    cpu.esp -= 4;
    // 00423b50  686c314900             -push 0x49316c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796780 /*0x49316c*/;
    cpu.esp -= 4;
    // 00423b55  e85d320500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423b5a  83c40c                 +add esp, 0xc
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
    // 00423b5d  eb0d                   -jmp 0x423b6c
    goto L_0x00423b6c;
L_0x00423b5f:
    // 00423b5f  381d10155200           +cmp byte ptr [0x521510], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423b65  7305                   -jae 0x423b6c
    if (!cpu.flags.cf)
    {
        goto L_0x00423b6c;
    }
    // 00423b67  e824b4ffff             -call 0x41ef90
    cpu.esp -= 4;
    sub_41ef90(app, cpu);
L_0x00423b6c:
    // 00423b6c  391ddc284900           +cmp dword ptr [0x4928dc], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423b72  7e70                   -jle 0x423be4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423be4;
    }
    // 00423b74  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423b79  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00423b7b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423b80  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 00423b86  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00423b89  8bb1e8020000           -mov esi, dword ptr [ecx + 0x2e8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 00423b8f  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00423b95  41                     -inc ecx
    (cpu.ecx)++;
    // 00423b96  890d48845100           -mov dword ptr [0x518448], ecx
    app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */) = cpu.ecx;
    // 00423b9c  e89fd00200             -call 0x450c40
    cpu.esp -= 4;
    sub_450c40(app, cpu);
    // 00423ba1  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423ba3  b9fc2f4900             -mov ecx, 0x492ffc
    cpu.ecx = 4796412 /*0x492ffc*/;
    // 00423ba8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00423baa  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00423bb0  8b96ec020000           -mov edx, dword ptr [esi + 0x2ec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00423bb6  8b8a84000000           -mov ecx, dword ptr [edx + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */);
    // 00423bbc  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00423bbe  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423bc3  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00423bc6  e8159d0400             -call 0x46d8e0
    cpu.esp -= 4;
    sub_46d8e0(app, cpu);
    // 00423bcb  8b8eec020000           -mov ecx, dword ptr [esi + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00423bd1  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423bd6  8b9184000000           -mov edx, dword ptr [ecx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 00423bdc  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00423bdf  e80c880400             -call 0x46c3f0
    cpu.esp -= 4;
    sub_46c3f0(app, cpu);
L_0x00423be4:
    // 00423be4  e8471b0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423be9  dc642438               -fsub qword ptr [esp + 0x38]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(56) /* 0x38 */));
    // 00423bed  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423bf0  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423bf3  68e02f4900             -push 0x492fe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796384 /*0x492fe0*/;
    cpu.esp -= 4;
    // 00423bf8  e8ba310500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00423bfd  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 00423c02  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423c05  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423c07  7705                   -ja 0x423c0e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00423c0e;
    }
    // 00423c09  e8b2d6ffff             -call 0x4212c0
    cpu.esp -= 4;
    sub_4212c0(app, cpu);
L_0x00423c0e:
    // 00423c0e  381d10155200           +cmp byte ptr [0x521510], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423c14  7207                   -jb 0x423c1d
    if (cpu.flags.cf)
    {
        goto L_0x00423c1d;
    }
    // 00423c16  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423c18  e8530bffff             -call 0x414770
    cpu.esp -= 4;
    sub_414770(app, cpu);
L_0x00423c1d:
    // 00423c1d  e80e280000             -call 0x426430
    cpu.esp -= 4;
    sub_426430(app, cpu);
    // 00423c22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423c24  751d                   -jne 0x423c43
    if (!cpu.flags.zf)
    {
        goto L_0x00423c43;
    }
    // 00423c26  833dc0f3510001         +cmp dword ptr [0x51f3c0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423c2d  7505                   -jne 0x423c34
    if (!cpu.flags.zf)
    {
        goto L_0x00423c34;
    }
    // 00423c2f  e89c2d0300             -call 0x4569d0
    cpu.esp -= 4;
    sub_4569d0(app, cpu);
L_0x00423c34:
    // 00423c34  e897a5ffff             -call 0x41e1d0
    cpu.esp -= 4;
    sub_41e1d0(app, cpu);
    // 00423c39  e8d2180000             -call 0x425510
    cpu.esp -= 4;
    sub_425510(app, cpu);
    // 00423c3e  e81da5ffff             -call 0x41e160
    cpu.esp -= 4;
    sub_41e160(app, cpu);
L_0x00423c43:
    // 00423c43  c744242400000000       -mov dword ptr [esp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00423c4b  e8e01a0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00423c50  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00423c54:
    // 00423c54  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423c56  e8b5a4ffff             -call 0x41e110
    cpu.esp -= 4;
    sub_41e110(app, cpu);
    // 00423c5b  e8100c0400             -call 0x464870
    cpu.esp -= 4;
    sub_464870(app, cpu);
    // 00423c60  e85b150400             -call 0x4651c0
    cpu.esp -= 4;
    sub_4651c0(app, cpu);
    // 00423c65  8b0de4284900           -mov ecx, dword ptr [0x4928e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4794596) /* 0x4928e4 */);
    // 00423c6b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00423c6d  893d44a55100           -mov dword ptr [0x51a544], edi
    app->getMemory<x86::reg32>(x86::reg32(5350724) /* 0x51a544 */) = cpu.edi;
    // 00423c73  c705d8284900000080bf   -mov dword ptr [0x4928d8], 0xbf800000
    app->getMemory<x86::reg32>(x86::reg32(4794584) /* 0x4928d8 */) = 3212836864 /*0xbf800000*/;
    // 00423c7d  890d14d24900           -mov dword ptr [0x49d214], ecx
    app->getMemory<x86::reg32>(x86::reg32(4837908) /* 0x49d214 */) = cpu.ecx;
    // 00423c83  e8481d0000             -call 0x4259d0
    cpu.esp -= 4;
    sub_4259d0(app, cpu);
    // 00423c88  893da0d34a00           -mov dword ptr [0x4ad3a0], edi
    app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */) = cpu.edi;
    // 00423c8e  893dbcfc4900           -mov dword ptr [0x49fcbc], edi
    app->getMemory<x86::reg32>(x86::reg32(4848828) /* 0x49fcbc */) = cpu.edi;
    // 00423c94  e8676a0300             -call 0x45a700
    cpu.esp -= 4;
    sub_45a700(app, cpu);
    // 00423c99  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423c9f  c7058c2d4a00ffffffff   -mov dword ptr [0x4a2d8c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4861324) /* 0x4a2d8c */) = 4294967295 /*0xffffffff*/;
    // 00423ca9  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00423cab  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00423caf  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00423cb1  89b8c8020000           -mov dword ptr [eax + 0x2c8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */) = cpu.edi;
L_0x00423cb7:
    // 00423cb7  e834ee0300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00423cbc  e84f0b0400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00423cc1  e89ad7ffff             -call 0x421460
    cpu.esp -= 4;
    sub_421460(app, cpu);
    // 00423cc6  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423ccc  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00423cce  39bac8020000           +cmp dword ptr [edx + 0x2c8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(712) /* 0x2c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423cd4  0f85ac000000           -jne 0x423d86
    if (!cpu.flags.zf)
    {
        goto L_0x00423d86;
    }
    // 00423cda  393dc0f35100           +cmp dword ptr [0x51f3c0], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423ce0  0f8ea0000000           -jle 0x423d86
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423d86;
    }
    // 00423ce6  e845f00200             -call 0x452d30
    cpu.esp -= 4;
    sub_452d30(app, cpu);
    // 00423ceb  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423cf0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00423cf2  89b9c8020000           -mov dword ptr [ecx + 0x2c8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */) = cpu.edi;
    // 00423cf8  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423cfe  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00423d00  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423d06  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00423d0c  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00423d0f  89b8c8020000           -mov dword ptr [eax + 0x2c8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */) = cpu.edi;
    // 00423d15  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423d1b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423d20  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00423d22  8b8a80000000           -mov ecx, dword ptr [edx + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 00423d28  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00423d2b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00423d2d  8b8ad0000000           -mov ecx, dword ptr [edx + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 00423d33  8988d0000000           -mov dword ptr [eax + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 00423d39  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423d3f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00423d41  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00423d47  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423d4c  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00423d4f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00423d51  8b8ad4000000           -mov ecx, dword ptr [edx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 00423d57  8988d4000000           -mov dword ptr [eax + 0xd4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */) = cpu.ecx;
    // 00423d5d  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423d63  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00423d65  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00423d6b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423d70  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00423d73  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00423d75  8b8ad8000000           -mov ecx, dword ptr [edx + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 00423d7b  8988d8000000           -mov dword ptr [eax + 0xd8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(216) /* 0xd8 */) = cpu.ecx;
    // 00423d81  e8da970300             -call 0x45d560
    cpu.esp -= 4;
    sub_45d560(app, cpu);
L_0x00423d86:
    // 00423d86  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 00423d8b  b103                   -mov cl, 3
    cpu.cl = 3 /*0x3*/;
    // 00423d8d  3c40                   +cmp al, 0x40
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423d8f  7302                   -jae 0x423d93
    if (!cpu.flags.cf)
    {
        goto L_0x00423d93;
    }
    // 00423d91  b102                   -mov cl, 2
    cpu.cl = 2 /*0x2*/;
L_0x00423d93:
    // 00423d93  e8f8e40300             -call 0x462290
    cpu.esp -= 4;
    sub_462290(app, cpu);
    // 00423d98  e8f3beffff             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 00423d9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423d9f  7412                   -je 0x423db3
    if (cpu.flags.zf)
    {
        goto L_0x00423db3;
    }
    // 00423da1  b129                   -mov cl, 0x29
    cpu.cl = 41 /*0x29*/;
    // 00423da3  e838ee0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00423da8  f7d8                   +neg eax
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
    // 00423daa  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00423dac  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00423dae  a38cd34a00             -mov dword ptr [0x4ad38c], eax
    app->getMemory<x86::reg32>(x86::reg32(4903820) /* 0x4ad38c */) = cpu.eax;
L_0x00423db3:
    // 00423db3  b10f                   -mov cl, 0xf
    cpu.cl = 15 /*0xf*/;
    // 00423db5  e826ee0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00423dba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423dbc  740e                   -je 0x423dcc
    if (cpu.flags.zf)
    {
        goto L_0x00423dcc;
    }
    // 00423dbe  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00423dc3  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00423dc5  e8966fffff             -call 0x41ad60
    cpu.esp -= 4;
    sub_41ad60(app, cpu);
    // 00423dca  eb0c                   -jmp 0x423dd8
    goto L_0x00423dd8;
L_0x00423dcc:
    // 00423dcc  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423dce  e88d6fffff             -call 0x41ad60
    cpu.esp -= 4;
    sub_41ad60(app, cpu);
    // 00423dd3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00423dd8:
    // 00423dd8  391d04d54a00           +cmp dword ptr [0x4ad504], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4904196) /* 0x4ad504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423dde  7515                   -jne 0x423df5
    if (!cpu.flags.zf)
    {
        goto L_0x00423df5;
    }
    // 00423de0  391dc0f35100           +cmp dword ptr [0x51f3c0], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423de6  7e0d                   -jle 0x423df5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423df5;
    }
    // 00423de8  68c42f4900             -push 0x492fc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796356 /*0x492fc4*/;
    cpu.esp -= 4;
    // 00423ded  e81e0e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00423df2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00423df5:
    // 00423df5  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423dfb  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 00423e00  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00423e03  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423e08  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 00423e0e  8b3490                 -mov esi, dword ptr [eax + edx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00423e11  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423e13  e89891feff             -call 0x40cfb0
    cpu.esp -= 4;
    sub_40cfb0(app, cpu);
    // 00423e18  393de0284900           +cmp dword ptr [0x4928e0], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794592) /* 0x4928e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423e1e  0f8486020000           -je 0x4240aa
    if (cpu.flags.zf)
    {
        goto L_0x004240aa;
    }
    // 00423e24  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00423e29  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00423e2b  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 00423e31  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00423e37  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00423e3a  3bd7                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423e3c  0f8468020000           -je 0x4240aa
    if (cpu.flags.zf)
    {
        goto L_0x004240aa;
    }
    // 00423e42  8b92d0000000           -mov edx, dword ptr [edx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 00423e48  89542444               -mov dword ptr [esp + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 00423e4c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00423e4e  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 00423e54  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00423e57  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 00423e5d  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00423e61  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00423e63  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 00423e69  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00423e6c  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 00423e72  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00423e76  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00423e78  8d542440               -lea edx, [esp + 0x40]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00423e7c  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00423e82  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00423e85  e826ae0300             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 00423e8a  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00423e8e  e84daa0400             -call 0x46e8e0
    cpu.esp -= 4;
    sub_46e8e0(app, cpu);
    // 00423e93  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00423e97  3bc7                   +cmp eax, edi
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
    // 00423e99  a198d34a00             -mov eax, dword ptr [0x4ad398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903832) /* 0x4ad398 */);
    // 00423e9e  7442                   -je 0x423ee2
    if (cpu.flags.zf)
    {
        goto L_0x00423ee2;
    }
    // 00423ea0  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00423ea4  3bc7                   +cmp eax, edi
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
    // 00423ea6  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423ea8  dc0d40734800           +fmul qword ptr [0x487340]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748096) /* 0x487340 */));
    // 00423eae  dc0df0754800           +fmul qword ptr [0x4875f0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748784) /* 0x4875f0 */));
    // 00423eb4  7410                   -je 0x423ec6
    if (cpu.flags.zf)
    {
        goto L_0x00423ec6;
    }
    // 00423eb6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423eb7  b9ac2f4900             -mov ecx, 0x492fac
    cpu.ecx = 4796332 /*0x492fac*/;
    // 00423ebc  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423ebf  e80cfb0300             -call 0x4639d0
    cpu.esp -= 4;
    sub_4639d0(app, cpu);
    // 00423ec4  eb32                   -jmp 0x423ef8
    goto L_0x00423ef8;
L_0x00423ec6:
    // 00423ec6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423ec7  68cdcc4c3e             -push 0x3e4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1045220557 /*0x3e4ccccd*/;
    cpu.esp -= 4;
    // 00423ecc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423ecd  b9ac2f4900             -mov ecx, 0x492fac
    cpu.ecx = 4796332 /*0x492fac*/;
    // 00423ed2  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423ed5  e8b6f90300             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 00423eda  891d98d34a00           -mov dword ptr [0x4ad398], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903832) /* 0x4ad398 */) = cpu.ebx;
    // 00423ee0  eb16                   -jmp 0x423ef8
    goto L_0x00423ef8;
L_0x00423ee2:
    // 00423ee2  3bc7                   +cmp eax, edi
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
    // 00423ee4  7412                   -je 0x423ef8
    if (cpu.flags.zf)
    {
        goto L_0x00423ef8;
    }
    // 00423ee6  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423ee8  b9ac2f4900             -mov ecx, 0x492fac
    cpu.ecx = 4796332 /*0x492fac*/;
    // 00423eed  e85efa0300             -call 0x463950
    cpu.esp -= 4;
    sub_463950(app, cpu);
    // 00423ef2  893d98d34a00           -mov dword ptr [0x4ad398], edi
    app->getMemory<x86::reg32>(x86::reg32(4903832) /* 0x4ad398 */) = cpu.edi;
L_0x00423ef8:
    // 00423ef8  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00423efc  e81fab0400             -call 0x46ea20
    cpu.esp -= 4;
    sub_46ea20(app, cpu);
    // 00423f01  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00423f05  3bc7                   +cmp eax, edi
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
    // 00423f07  a19cd34a00             -mov eax, dword ptr [0x4ad39c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903836) /* 0x4ad39c */);
    // 00423f0c  0f84c3000000           -je 0x423fd5
    if (cpu.flags.zf)
    {
        goto L_0x00423fd5;
    }
    // 00423f12  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00423f16  3bc7                   +cmp eax, edi
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
    // 00423f18  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 00423f1d  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423f1f  dc0d40734800           +fmul qword ptr [0x487340]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748096) /* 0x487340 */));
    // 00423f25  dc0df0754800           +fmul qword ptr [0x4875f0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748784) /* 0x4875f0 */));
    // 00423f2b  744b                   -je 0x423f78
    if (cpu.flags.zf)
    {
        goto L_0x00423f78;
    }
    // 00423f2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423f2e  83e844                 +sub eax, 0x44
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00423f31  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423f34  7433                   -je 0x423f69
    if (cpu.flags.zf)
    {
        goto L_0x00423f69;
    }
    // 00423f36  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00423f37  7421                   -je 0x423f5a
    if (cpu.flags.zf)
    {
        goto L_0x00423f5a;
    }
    // 00423f39  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00423f3a  740f                   -je 0x423f4b
    if (cpu.flags.zf)
    {
        goto L_0x00423f4b;
    }
    // 00423f3c  b9942f4900             -mov ecx, 0x492f94
    cpu.ecx = 4796308 /*0x492f94*/;
    // 00423f41  e88afa0300             -call 0x4639d0
    cpu.esp -= 4;
    sub_4639d0(app, cpu);
    // 00423f46  e9c5000000             -jmp 0x424010
    goto L_0x00424010;
L_0x00423f4b:
    // 00423f4b  b97c2f4900             -mov ecx, 0x492f7c
    cpu.ecx = 4796284 /*0x492f7c*/;
    // 00423f50  e87bfa0300             -call 0x4639d0
    cpu.esp -= 4;
    sub_4639d0(app, cpu);
    // 00423f55  e9b6000000             -jmp 0x424010
    goto L_0x00424010;
L_0x00423f5a:
    // 00423f5a  b9642f4900             -mov ecx, 0x492f64
    cpu.ecx = 4796260 /*0x492f64*/;
    // 00423f5f  e86cfa0300             -call 0x4639d0
    cpu.esp -= 4;
    sub_4639d0(app, cpu);
    // 00423f64  e9a7000000             -jmp 0x424010
    goto L_0x00424010;
L_0x00423f69:
    // 00423f69  b94c2f4900             -mov ecx, 0x492f4c
    cpu.ecx = 4796236 /*0x492f4c*/;
    // 00423f6e  e85dfa0300             -call 0x4639d0
    cpu.esp -= 4;
    sub_4639d0(app, cpu);
    // 00423f73  e998000000             -jmp 0x424010
    goto L_0x00424010;
L_0x00423f78:
    // 00423f78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423f79  68cdcc4c3e             -push 0x3e4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1045220557 /*0x3e4ccccd*/;
    cpu.esp -= 4;
    // 00423f7e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423f7f  83e844                 +sub eax, 0x44
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00423f82  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00423f85  743c                   -je 0x423fc3
    if (cpu.flags.zf)
    {
        goto L_0x00423fc3;
    }
    // 00423f87  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00423f88  7427                   -je 0x423fb1
    if (cpu.flags.zf)
    {
        goto L_0x00423fb1;
    }
    // 00423f8a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00423f8b  7412                   -je 0x423f9f
    if (cpu.flags.zf)
    {
        goto L_0x00423f9f;
    }
    // 00423f8d  b9942f4900             -mov ecx, 0x492f94
    cpu.ecx = 4796308 /*0x492f94*/;
    // 00423f92  e8f9f80300             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 00423f97  891d9cd34a00           -mov dword ptr [0x4ad39c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903836) /* 0x4ad39c */) = cpu.ebx;
    // 00423f9d  eb71                   -jmp 0x424010
    goto L_0x00424010;
L_0x00423f9f:
    // 00423f9f  b97c2f4900             -mov ecx, 0x492f7c
    cpu.ecx = 4796284 /*0x492f7c*/;
    // 00423fa4  e8e7f80300             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 00423fa9  891d9cd34a00           -mov dword ptr [0x4ad39c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903836) /* 0x4ad39c */) = cpu.ebx;
    // 00423faf  eb5f                   -jmp 0x424010
    goto L_0x00424010;
L_0x00423fb1:
    // 00423fb1  b9642f4900             -mov ecx, 0x492f64
    cpu.ecx = 4796260 /*0x492f64*/;
    // 00423fb6  e8d5f80300             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 00423fbb  891d9cd34a00           -mov dword ptr [0x4ad39c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903836) /* 0x4ad39c */) = cpu.ebx;
    // 00423fc1  eb4d                   -jmp 0x424010
    goto L_0x00424010;
L_0x00423fc3:
    // 00423fc3  b94c2f4900             -mov ecx, 0x492f4c
    cpu.ecx = 4796236 /*0x492f4c*/;
    // 00423fc8  e8c3f80300             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 00423fcd  891d9cd34a00           -mov dword ptr [0x4ad39c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903836) /* 0x4ad39c */) = cpu.ebx;
    // 00423fd3  eb3b                   -jmp 0x424010
    goto L_0x00424010;
L_0x00423fd5:
    // 00423fd5  3bc7                   +cmp eax, edi
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
    // 00423fd7  7437                   -je 0x424010
    if (cpu.flags.zf)
    {
        goto L_0x00424010;
    }
    // 00423fd9  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 00423fde  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423fe0  83e844                 +sub eax, 0x44
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00423fe3  741b                   -je 0x424000
    if (cpu.flags.zf)
    {
        goto L_0x00424000;
    }
    // 00423fe5  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00423fe6  7411                   -je 0x423ff9
    if (cpu.flags.zf)
    {
        goto L_0x00423ff9;
    }
    // 00423fe8  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00423fe9  7407                   -je 0x423ff2
    if (cpu.flags.zf)
    {
        goto L_0x00423ff2;
    }
    // 00423feb  b9942f4900             -mov ecx, 0x492f94
    cpu.ecx = 4796308 /*0x492f94*/;
    // 00423ff0  eb13                   -jmp 0x424005
    goto L_0x00424005;
L_0x00423ff2:
    // 00423ff2  b97c2f4900             -mov ecx, 0x492f7c
    cpu.ecx = 4796284 /*0x492f7c*/;
    // 00423ff7  eb0c                   -jmp 0x424005
    goto L_0x00424005;
L_0x00423ff9:
    // 00423ff9  b9642f4900             -mov ecx, 0x492f64
    cpu.ecx = 4796260 /*0x492f64*/;
    // 00423ffe  eb05                   -jmp 0x424005
    goto L_0x00424005;
L_0x00424000:
    // 00424000  b94c2f4900             -mov ecx, 0x492f4c
    cpu.ecx = 4796236 /*0x492f4c*/;
L_0x00424005:
    // 00424005  e846f90300             -call 0x463950
    cpu.esp -= 4;
    sub_463950(app, cpu);
    // 0042400a  893d9cd34a00           -mov dword ptr [0x4ad39c], edi
    app->getMemory<x86::reg32>(x86::reg32(4903836) /* 0x4ad39c */) = cpu.edi;
L_0x00424010:
    // 00424010  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00424016  8b15c4e54900           -mov edx, dword ptr [0x49e5c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0042401c  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0042401f  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00424025  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0042402b  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0042402e  e87dbc0000             -call 0x42fcb0
    cpu.esp -= 4;
    sub_42fcb0(app, cpu);
    // 00424033  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00424036  7458                   -je 0x424090
    if (cpu.flags.zf)
    {
        goto L_0x00424090;
    }
    // 00424038  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0042403c  e83fa90400             -call 0x46e980
    cpu.esp -= 4;
    sub_46e980(app, cpu);
    // 00424041  3bc7                   +cmp eax, edi
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
    // 00424043  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00424047  7447                   -je 0x424090
    if (cpu.flags.zf)
    {
        goto L_0x00424090;
    }
    // 00424049  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0042404d  a194d34a00             -mov eax, dword ptr [0x4ad394]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903828) /* 0x4ad394 */);
    // 00424052  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00424054  3bc7                   +cmp eax, edi
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
    // 00424056  dc0d40734800           +fmul qword ptr [0x487340]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748096) /* 0x487340 */));
    // 0042405c  dc0df0754800           +fmul qword ptr [0x4875f0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748784) /* 0x4875f0 */));
    // 00424062  7410                   -je 0x424074
    if (cpu.flags.zf)
    {
        goto L_0x00424074;
    }
    // 00424064  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424065  b9342f4900             -mov ecx, 0x492f34
    cpu.ecx = 4796212 /*0x492f34*/;
    // 0042406a  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042406d  e85ef90300             -call 0x4639d0
    cpu.esp -= 4;
    sub_4639d0(app, cpu);
    // 00424072  eb36                   -jmp 0x4240aa
    goto L_0x004240aa;
L_0x00424074:
    // 00424074  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424075  68cdcc4c3e             -push 0x3e4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1045220557 /*0x3e4ccccd*/;
    cpu.esp -= 4;
    // 0042407a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042407b  b9342f4900             -mov ecx, 0x492f34
    cpu.ecx = 4796212 /*0x492f34*/;
    // 00424080  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424083  e808f80300             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 00424088  891d94d34a00           -mov dword ptr [0x4ad394], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903828) /* 0x4ad394 */) = cpu.ebx;
    // 0042408e  eb1a                   -jmp 0x4240aa
    goto L_0x004240aa;
L_0x00424090:
    // 00424090  393d94d34a00           +cmp dword ptr [0x4ad394], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4903828) /* 0x4ad394 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00424096  7412                   -je 0x4240aa
    if (cpu.flags.zf)
    {
        goto L_0x004240aa;
    }
    // 00424098  b9342f4900             -mov ecx, 0x492f34
    cpu.ecx = 4796212 /*0x492f34*/;
    // 0042409d  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042409f  e8acf80300             -call 0x463950
    cpu.esp -= 4;
    sub_463950(app, cpu);
    // 004240a4  893d94d34a00           -mov dword ptr [0x4ad394], edi
    app->getMemory<x86::reg32>(x86::reg32(4903828) /* 0x4ad394 */) = cpu.edi;
L_0x004240aa:
    // 004240aa  b144                   -mov cl, 0x44
    cpu.cl = 68 /*0x44*/;
    // 004240ac  e82feb0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004240b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004240b3  740e                   -je 0x4240c3
    if (cpu.flags.zf)
    {
        goto L_0x004240c3;
    }
    // 004240b5  391d04d54a00           +cmp dword ptr [0x4ad504], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4904196) /* 0x4ad504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004240bb  7506                   -jne 0x4240c3
    if (!cpu.flags.zf)
    {
        goto L_0x004240c3;
    }
    // 004240bd  891d8c2d4a00           -mov dword ptr [0x4a2d8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4861324) /* 0x4a2d8c */) = cpu.ebx;
L_0x004240c3:
    // 004240c3  393d7c845100           +cmp dword ptr [0x51847c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5342332) /* 0x51847c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004240c9  744e                   -je 0x424119
    if (cpu.flags.zf)
    {
        goto L_0x00424119;
    }
    // 004240cb  b158                   -mov cl, 0x58
    cpu.cl = 88 /*0x58*/;
    // 004240cd  e80eeb0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004240d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004240d4  7443                   -je 0x424119
    if (cpu.flags.zf)
    {
        goto L_0x00424119;
    }
    // 004240d6  b158                   -mov cl, 0x58
    cpu.cl = 88 /*0x58*/;
    // 004240d8  e803eb0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004240dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004240df  7410                   -je 0x4240f1
    if (cpu.flags.zf)
    {
        goto L_0x004240f1;
    }
L_0x004240e1:
    // 004240e1  e80aea0300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 004240e6  b158                   -mov cl, 0x58
    cpu.cl = 88 /*0x58*/;
    // 004240e8  e8f3ea0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004240ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004240ef  75f0                   -jne 0x4240e1
    if (!cpu.flags.zf)
    {
        goto L_0x004240e1;
    }
L_0x004240f1:
    // 004240f1  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004240f5  40                     -inc eax
    (cpu.eax)++;
    // 004240f6  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004240fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004240fb  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004240ff  68282f4900             -push 0x492f28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796200 /*0x492f28*/;
    cpu.esp -= 4;
    // 00424104  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424105  e8ee2c0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042410a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042410d  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042410f  8d4c2468               -lea ecx, [esp + 0x68]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00424113  ff157c845100           -call dword ptr [0x51847c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342332) /* 0x51847c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00424119:
    // 00424119  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0042411b  e8c0ea0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424120  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424122  7436                   -je 0x42415a
    if (cpu.flags.zf)
    {
        goto L_0x0042415a;
    }
    // 00424124  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00424126  e8e59fffff             -call 0x41e110
    cpu.esp -= 4;
    sub_41e110(app, cpu);
    // 0042412b  ba4cbb4a00             -mov edx, 0x4abb4c
    cpu.edx = 4897612 /*0x4abb4c*/;
    // 00424130  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424132  e8291b0000             -call 0x425c60
    cpu.esp -= 4;
    sub_425c60(app, cpu);
    // 00424137  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424139  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042413b  e8d09fffff             -call 0x41e110
    cpu.esp -= 4;
    sub_41e110(app, cpu);
    // 00424140  3bf3                   +cmp esi, ebx
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
    // 00424142  0f8447020000           -je 0x42438f
    if (cpu.flags.zf)
    {
        goto L_0x0042438f;
    }
    // 00424148  83fe06                 +cmp esi, 6
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
    // 0042414b  0f8403fbffff           -je 0x423c54
    if (cpu.flags.zf)
    {
        goto L_0x00423c54;
    }
    // 00424151  83fe02                 +cmp esi, 2
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
    // 00424154  0f84fafaffff           -je 0x423c54
    if (cpu.flags.zf)
    {
        goto L_0x00423c54;
    }
L_0x0042415a:
    // 0042415a  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00424160  8b15c4e54900           -mov edx, dword ptr [0x49e5c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 00424166  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00424169  6639b88a020000         +cmp word ptr [eax + 0x28a], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(650) /* 0x28a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00424170  0f8e33010000           -jle 0x4242a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004242a9;
    }
    // 00424176  b1c9                   -mov cl, 0xc9
    cpu.cl = 201 /*0xc9*/;
    // 00424178  e863ea0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0042417d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042417f  740c                   -je 0x42418d
    if (cpu.flags.zf)
    {
        goto L_0x0042418d;
    }
    // 00424181  6800002041             -push 0x41200000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1092616192 /*0x41200000*/;
    cpu.esp -= 4;
    // 00424186  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00424187  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00424188  e8f3840300             -call 0x45c680
    cpu.esp -= 4;
    sub_45c680(app, cpu);
L_0x0042418d:
    // 0042418d  b1d2                   -mov cl, 0xd2
    cpu.cl = 210 /*0xd2*/;
    // 0042418f  e84cea0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424194  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424196  740c                   -je 0x4241a4
    if (cpu.flags.zf)
    {
        goto L_0x004241a4;
    }
    // 00424198  68000020c1             -push 0xc1200000
    app->getMemory<x86::reg32>(cpu.esp-4) = 3240099840 /*0xc1200000*/;
    cpu.esp -= 4;
    // 0042419d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042419e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042419f  e8dc840300             -call 0x45c680
    cpu.esp -= 4;
    sub_45c680(app, cpu);
L_0x004241a4:
    // 004241a4  b1d3                   -mov cl, 0xd3
    cpu.cl = 211 /*0xd3*/;
    // 004241a6  e835ea0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004241ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004241ad  740c                   -je 0x4241bb
    if (cpu.flags.zf)
    {
        goto L_0x004241bb;
    }
    // 004241af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004241b0  68d80f49bf             -push 0xbf490fd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 3209236440 /*0xbf490fd8*/;
    cpu.esp -= 4;
    // 004241b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004241b6  e8c5840300             -call 0x45c680
    cpu.esp -= 4;
    sub_45c680(app, cpu);
L_0x004241bb:
    // 004241bb  b1d1                   -mov cl, 0xd1
    cpu.cl = 209 /*0xd1*/;
    // 004241bd  e81eea0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004241c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004241c4  740c                   -je 0x4241d2
    if (cpu.flags.zf)
    {
        goto L_0x004241d2;
    }
    // 004241c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004241c7  68d80f493f             -push 0x3f490fd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061752792 /*0x3f490fd8*/;
    cpu.esp -= 4;
    // 004241cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004241cd  e8ae840300             -call 0x45c680
    cpu.esp -= 4;
    sub_45c680(app, cpu);
L_0x004241d2:
    // 004241d2  b1cf                   -mov cl, 0xcf
    cpu.cl = 207 /*0xcf*/;
    // 004241d4  e807ea0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004241d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004241db  740c                   -je 0x4241e9
    if (cpu.flags.zf)
    {
        goto L_0x004241e9;
    }
    // 004241dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004241de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004241df  68d80f493f             -push 0x3f490fd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061752792 /*0x3f490fd8*/;
    cpu.esp -= 4;
    // 004241e4  e897840300             -call 0x45c680
    cpu.esp -= 4;
    sub_45c680(app, cpu);
L_0x004241e9:
    // 004241e9  b1c7                   -mov cl, 0xc7
    cpu.cl = 199 /*0xc7*/;
    // 004241eb  e8f0e90300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004241f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004241f2  740c                   -je 0x424200
    if (cpu.flags.zf)
    {
        goto L_0x00424200;
    }
    // 004241f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004241f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004241f6  68d80f49bf             -push 0xbf490fd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 3209236440 /*0xbf490fd8*/;
    cpu.esp -= 4;
    // 004241fb  e880840300             -call 0x45c680
    cpu.esp -= 4;
    sub_45c680(app, cpu);
L_0x00424200:
    // 00424200  b13b                   -mov cl, 0x3b
    cpu.cl = 59 /*0x3b*/;
    // 00424202  e8d9e90300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424207  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424209  740e                   -je 0x424219
    if (cpu.flags.zf)
    {
        goto L_0x00424219;
    }
    // 0042420b  833ddc2849000a         +cmp dword ptr [0x4928dc], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00424212  7e05                   -jle 0x424219
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00424219;
    }
    // 00424214  e887920300             -call 0x45d4a0
    cpu.esp -= 4;
    sub_45d4a0(app, cpu);
L_0x00424219:
    // 00424219  b13c                   -mov cl, 0x3c
    cpu.cl = 60 /*0x3c*/;
    // 0042421b  e8c0e90300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424220  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424222  7415                   -je 0x424239
    if (cpu.flags.zf)
    {
        goto L_0x00424239;
    }
    // 00424224  689a99d93f             -push 0x3fd9999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1071225242 /*0x3fd9999a*/;
    cpu.esp -= 4;
    // 00424229  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042422a  687b142ebe             -push 0xbe2e147b
    app->getMemory<x86::reg32>(cpu.esp-4) = 3190690939 /*0xbe2e147b*/;
    cpu.esp -= 4;
    // 0042422f  e8ec830300             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 00424234  e8a7920300             -call 0x45d4e0
    cpu.esp -= 4;
    sub_45d4e0(app, cpu);
L_0x00424239:
    // 00424239  b13f                   -mov cl, 0x3f
    cpu.cl = 63 /*0x3f*/;
    // 0042423b  e8a0e90300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424240  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424242  7415                   -je 0x424259
    if (cpu.flags.zf)
    {
        goto L_0x00424259;
    }
    // 00424244  6885eb8140             -push 0x4081eb85
    app->getMemory<x86::reg32>(cpu.esp-4) = 1082256261 /*0x4081eb85*/;
    cpu.esp -= 4;
    // 00424249  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042424a  68295c4fbf             -push 0xbf4f5c29
    app->getMemory<x86::reg32>(cpu.esp-4) = 3209649193 /*0xbf4f5c29*/;
    cpu.esp -= 4;
    // 0042424f  e8cc830300             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 00424254  e867920300             -call 0x45d4c0
    cpu.esp -= 4;
    sub_45d4c0(app, cpu);
L_0x00424259:
    // 00424259  b13d                   -mov cl, 0x3d
    cpu.cl = 61 /*0x3d*/;
    // 0042425b  e880e90300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424260  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424262  7415                   -je 0x424279
    if (cpu.flags.zf)
    {
        goto L_0x00424279;
    }
    // 00424264  689a99d93f             -push 0x3fd9999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1071225242 /*0x3fd9999a*/;
    cpu.esp -= 4;
    // 00424269  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042426a  687b142ebe             -push 0xbe2e147b
    app->getMemory<x86::reg32>(cpu.esp-4) = 3190690939 /*0xbe2e147b*/;
    cpu.esp -= 4;
    // 0042426f  e8ac830300             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 00424274  e887920300             -call 0x45d500
    cpu.esp -= 4;
    sub_45d500(app, cpu);
L_0x00424279:
    // 00424279  b13e                   -mov cl, 0x3e
    cpu.cl = 62 /*0x3e*/;
    // 0042427b  e860e90300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424280  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424282  7405                   -je 0x424289
    if (cpu.flags.zf)
    {
        goto L_0x00424289;
    }
    // 00424284  e897920300             -call 0x45d520
    cpu.esp -= 4;
    sub_45d520(app, cpu);
L_0x00424289:
    // 00424289  b143                   -mov cl, 0x43
    cpu.cl = 67 /*0x43*/;
    // 0042428b  e850e90300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424290  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424292  7415                   -je 0x4242a9
    if (cpu.flags.zf)
    {
        goto L_0x004242a9;
    }
    // 00424294  689a99d93f             -push 0x3fd9999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1071225242 /*0x3fd9999a*/;
    cpu.esp -= 4;
    // 00424299  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042429a  687b142ebe             -push 0xbe2e147b
    app->getMemory<x86::reg32>(cpu.esp-4) = 3190690939 /*0xbe2e147b*/;
    cpu.esp -= 4;
    // 0042429f  e87c830300             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 004242a4  e817920300             -call 0x45d4c0
    cpu.esp -= 4;
    sub_45d4c0(app, cpu);
L_0x004242a9:
    // 004242a9  e8d2060000             -call 0x424980
    cpu.esp -= 4;
    sub_424980(app, cpu);
    // 004242ae  a1a4d34a00             -mov eax, dword ptr [0x4ad3a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903844) /* 0x4ad3a4 */);
    // 004242b3  8b3548845100           -mov esi, dword ptr [0x518448]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 004242b9  3bc7                   +cmp eax, edi
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
    // 004242bb  7528                   -jne 0x4242e5
    if (!cpu.flags.zf)
    {
        goto L_0x004242e5;
    }
    // 004242bd  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004242c2:
    // 004242c2  3b3548845100           +cmp esi, dword ptr [0x518448]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004242c8  751b                   -jne 0x4242e5
    if (!cpu.flags.zf)
    {
        goto L_0x004242e5;
    }
    // 004242ca  b9b0474200             -mov ecx, 0x4247b0
    cpu.ecx = 4343728 /*0x4247b0*/;
    // 004242cf  e81c620300             -call 0x45a4f0
    cpu.esp -= 4;
    sub_45a4f0(app, cpu);
    // 004242d4  393da8a45100           +cmp dword ptr [0x51a4a8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5350568) /* 0x51a4a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004242da  7409                   -je 0x4242e5
    if (cpu.flags.zf)
    {
        goto L_0x004242e5;
    }
    // 004242dc  a1a4d34a00             -mov eax, dword ptr [0x4ad3a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903844) /* 0x4ad3a4 */);
    // 004242e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004242e3  74dd                   -je 0x4242c2
    if (cpu.flags.zf)
    {
        goto L_0x004242c2;
    }
L_0x004242e5:
    // 004242e5  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004242e9  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 004242ee  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004242f4  42                     -inc edx
    (cpu.edx)++;
    // 004242f5  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004242f9  8b15c4e54900           -mov edx, dword ptr [0x49e5c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004242ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424301  7511                   -jne 0x424314
    if (!cpu.flags.zf)
    {
        goto L_0x00424314;
    }
    // 00424303  8b3491                 -mov esi, dword ptr [ecx + edx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00424306  6683be8a02000000       +cmp word ptr [esi + 0x28a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(650) /* 0x28a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042430e  7e04                   -jle 0x424314
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00424314;
    }
    // 00424310  33ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00424312  eb08                   -jmp 0x42431c
    goto L_0x0042431c;
L_0x00424314:
    // 00424314  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00424316  7541                   -jne 0x424359
    if (!cpu.flags.zf)
    {
        goto L_0x00424359;
    }
    // 00424318  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042431a  7557                   -jne 0x424373
    if (!cpu.flags.zf)
    {
        goto L_0x00424373;
    }
L_0x0042431c:
    // 0042431c  8b0c91                 -mov ecx, dword ptr [ecx + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0042431f  6683b98a02000000       +cmp word ptr [ecx + 0x28a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(650) /* 0x28a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00424327  7f4a                   -jg 0x424373
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00424373;
    }
    // 00424329  e892910300             -call 0x45d4c0
    cpu.esp -= 4;
    sub_45d4c0(app, cpu);
    // 0042432e  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00424333  680000003f             -push 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056964608 /*0x3f000000*/;
    cpu.esp -= 4;
    // 00424338  689a9919bf             -push 0xbf19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 3206125978 /*0xbf19999a*/;
    cpu.esp -= 4;
    // 0042433d  e8de820300             -call 0x45c620
    cpu.esp -= 4;
    sub_45c620(app, cpu);
    // 00424342  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 00424348  dc05a0754800           -fadd qword ptr [0x4875a0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748704) /* 0x4875a0 */));
    // 0042434e  e83d2a0500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00424353  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00424355  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00424357  741a                   -je 0x424373
    if (cpu.flags.zf)
    {
        goto L_0x00424373;
    }
L_0x00424359:
    // 00424359  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042435b  68d80f49bf             -push 0xbf490fd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 3209236440 /*0xbf490fd8*/;
    cpu.esp -= 4;
    // 00424360  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00424362  e819830300             -call 0x45c680
    cpu.esp -= 4;
    sub_45c680(app, cpu);
    // 00424367  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00424369  7408                   -je 0x424373
    if (cpu.flags.zf)
    {
        goto L_0x00424373;
    }
    // 0042436b  392d48845100           +cmp dword ptr [0x518448], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00424371  7f10                   -jg 0x424383
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00424383;
    }
L_0x00424373:
    // 00424373  833d8c2d4a00ff         +cmp dword ptr [0x4a2d8c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4861324) /* 0x4a2d8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042437a  7517                   -jne 0x424393
    if (!cpu.flags.zf)
    {
        goto L_0x00424393;
    }
    // 0042437c  33ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0042437e  e934f9ffff             -jmp 0x423cb7
    goto L_0x00423cb7;
L_0x00424383:
    // 00424383  c7058c2d4a0002000000   -mov dword ptr [0x4a2d8c], 2
    app->getMemory<x86::reg32>(x86::reg32(4861324) /* 0x4a2d8c */) = 2 /*0x2*/;
    // 0042438d  eb04                   -jmp 0x424393
    goto L_0x00424393;
L_0x0042438f:
    // 0042438f  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
L_0x00424393:
    // 00424393  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00424399  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0042439e  c70544a5510001000000   -mov dword ptr [0x51a544], 1
    app->getMemory<x86::reg32>(x86::reg32(5350724) /* 0x51a544 */) = 1 /*0x1*/;
    // 004243a8  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004243ab  a18c2d4a00             -mov eax, dword ptr [0x4a2d8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4861324) /* 0x4a2d8c */);
    // 004243b0  0fbf918a020000         -movsx edx, word ptr [ecx + 0x28a]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(650) /* 0x28a */)));
    // 004243b7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004243b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004243b9  68082f4900             -push 0x492f08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796168 /*0x492f08*/;
    cpu.esp -= 4;
    // 004243be  e8f4290500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004243c3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004243c6  e805160000             -call 0x4259d0
    cpu.esp -= 4;
    sub_4259d0(app, cpu);
    // 004243cb  8b0ddc284900           -mov ecx, dword ptr [0x4928dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 004243d1  e8daedffff             -call 0x4231b0
    cpu.esp -= 4;
    sub_4231b0(app, cpu);
    // 004243d6  e815400300             -call 0x4583f0
    cpu.esp -= 4;
    sub_4583f0(app, cpu);
    // 004243db  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004243e1  8b15c4e54900           -mov edx, dword ptr [0x49e5c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004243e7  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004243e9  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 004243ec  0fbfb88a020000         -movsx edi, word ptr [eax + 0x28a]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(650) /* 0x28a */)));
    // 004243f3  a12c845100             -mov eax, dword ptr [0x51842c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 004243f8  c70560ba510001000000   -mov dword ptr [0x51ba60], 1
    app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */) = 1 /*0x1*/;
    // 00424402  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424404  7e18                   -jle 0x42441e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042441e;
    }
L_0x00424406:
    // 00424406  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042440c  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042440f  e83cf60300             -call 0x463a50
    cpu.esp -= 4;
    sub_463a50(app, cpu);
    // 00424414  a12c845100             -mov eax, dword ptr [0x51842c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 00424419  46                     -inc esi
    (cpu.esi)++;
    // 0042441a  3bf0                   +cmp esi, eax
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
    // 0042441c  7ce8                   -jl 0x424406
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00424406;
    }
L_0x0042441e:
    // 0042441e  e88d6f0300             -call 0x45b3b0
    cpu.esp -= 4;
    sub_45b3b0(app, cpu);
    // 00424423  c70560ba510000000000   -mov dword ptr [0x51ba60], 0
    app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */) = 0 /*0x0*/;
    // 0042442d  e80e630300             -call 0x45a740
    cpu.esp -= 4;
    sub_45a740(app, cpu);
L_0x00424432:
    // 00424432  e8b9e60300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00424437  e8d4030400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 0042443c  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0042443e  e89de70300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424443  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424445  75eb                   -jne 0x424432
    if (!cpu.flags.zf)
    {
        goto L_0x00424432;
    }
    // 00424447  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 0042444c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042444e  0f85bc020000           -jne 0x424710
    if (!cpu.flags.zf)
    {
        goto L_0x00424710;
    }
    // 00424454  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00424458  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042445a  0f85b0020000           -jne 0x424710
    if (!cpu.flags.zf)
    {
        goto L_0x00424710;
    }
    // 00424460  f6058c2d4a0001         +test byte ptr [0x4a2d8c], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(4861324) /* 0x4a2d8c */) & 1 /*0x1*/));
    // 00424467  7408                   -je 0x424471
    if (cpu.flags.zf)
    {
        goto L_0x00424471;
    }
    // 00424469  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042446b  0f8fde000000           -jg 0x42454f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042454f;
    }
L_0x00424471:
    // 00424471  e8fa9cffff             -call 0x41e170
    cpu.esp -= 4;
    sub_41e170(app, cpu);
    // 00424476  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0042447b  e8609dffff             -call 0x41e1e0
    cpu.esp -= 4;
    sub_41e1e0(app, cpu);
    // 00424480  e89b7dffff             -call 0x41c220
    cpu.esp -= 4;
    sub_41c220(app, cpu);
    // 00424485  e8a6120400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042448a  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042448e:
    // 0042448e  e85de60300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00424493  e878030400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00424498  e893120400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042449d  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 004244a1  dc1d80784800           -fcomp qword ptr [0x487880]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749440) /* 0x487880 */)));
    cpu.fpu.pop();
    // 004244a7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004244a9  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 004244ac  7be0                   -jnp 0x42448e
    if (!cpu.flags.pf)
    {
        goto L_0x0042448e;
    }
    // 004244ae  e87d120400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004244b3  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004244b7  e8c4040000             -call 0x424980
    cpu.esp -= 4;
    sub_424980(app, cpu);
    // 004244bc  b139                   -mov cl, 0x39
    cpu.cl = 57 /*0x39*/;
    // 004244be  e81de70300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004244c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004244c5  0f8502020000           -jne 0x4246cd
    if (!cpu.flags.zf)
    {
        goto L_0x004246cd;
    }
    // 004244cb  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 004244cd  e80ee70300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004244d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004244d4  74b8                   -je 0x42448e
    if (cpu.flags.zf)
    {
        goto L_0x0042448e;
    }
    // 004244d6  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 004244d8  e803e70300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004244dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004244df  7415                   -je 0x4244f6
    if (cpu.flags.zf)
    {
        goto L_0x004244f6;
    }
L_0x004244e1:
    // 004244e1  e80ae60300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 004244e6  e825030400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 004244eb  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 004244ed  e8eee60300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004244f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004244f4  75eb                   -jne 0x4244e1
    if (!cpu.flags.zf)
    {
        goto L_0x004244e1;
    }
L_0x004244f6:
    // 004244f6  ba4cbb4a00             -mov edx, 0x4abb4c
    cpu.edx = 4897612 /*0x4abb4c*/;
    // 004244fb  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004244fd  e85e170000             -call 0x425c60
    cpu.esp -= 4;
    sub_425c60(app, cpu);
    // 00424502  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00424504  83fe01                 +cmp esi, 1
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
    // 00424507  7446                   -je 0x42454f
    if (cpu.flags.zf)
    {
        goto L_0x0042454f;
    }
    // 00424509  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0042450b  e8d0e60300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424510  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424512  7415                   -je 0x424529
    if (cpu.flags.zf)
    {
        goto L_0x00424529;
    }
L_0x00424514:
    // 00424514  e8d7e50300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00424519  e8f2020400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 0042451e  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00424520  e8bbe60300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424525  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424527  75eb                   -jne 0x424514
    if (!cpu.flags.zf)
    {
        goto L_0x00424514;
    }
L_0x00424529:
    // 00424529  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042452b  e8b09cffff             -call 0x41e1e0
    cpu.esp -= 4;
    sub_41e1e0(app, cpu);
    // 00424530  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00424532  0f8477010000           -je 0x4246af
    if (cpu.flags.zf)
    {
        goto L_0x004246af;
    }
    // 00424538  83fe02                 +cmp esi, 2
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
    // 0042453b  0f846e010000           -je 0x4246af
    if (cpu.flags.zf)
    {
        goto L_0x004246af;
    }
    // 00424541  83fe06                 +cmp esi, 6
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
    // 00424544  0f8527ffffff           -jne 0x424471
    if (!cpu.flags.zf)
    {
        goto L_0x00424471;
    }
    // 0042454a  e905f7ffff             -jmp 0x423c54
    goto L_0x00423c54;
L_0x0042454f:
    // 0042454f  f6058c2d4a0001         +test byte ptr [0x4a2d8c], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(4861324) /* 0x4a2d8c */) & 1 /*0x1*/));
    // 00424556  0f84b4010000           -je 0x424710
    if (cpu.flags.zf)
    {
        goto L_0x00424710;
    }
    // 0042455c  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 00424561  bf0c000000             -mov edi, 0xc
    cpu.edi = 12 /*0xc*/;
    // 00424566  3bc7                   +cmp eax, edi
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
    // 00424568  756b                   -jne 0x4245d5
    if (!cpu.flags.zf)
    {
        goto L_0x004245d5;
    }
    // 0042456a  b9fc2e4900             -mov ecx, 0x492efc
    cpu.ecx = 4796156 /*0x492efc*/;
    // 0042456f  e84cd00000             -call 0x4315c0
    cpu.esp -= 4;
    sub_4315c0(app, cpu);
L_0x00424574:
    // 00424574  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00424576  e865e60300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0042457b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042457d  7415                   -je 0x424594
    if (cpu.flags.zf)
    {
        goto L_0x00424594;
    }
L_0x0042457f:
    // 0042457f  e86ce50300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00424584  e887020400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00424589  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0042458b  e850e60300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424590  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424592  75eb                   -jne 0x42457f
    if (!cpu.flags.zf)
    {
        goto L_0x0042457f;
    }
L_0x00424594:
    // 00424594  ba4cbb4a00             -mov edx, 0x4abb4c
    cpu.edx = 4897612 /*0x4abb4c*/;
    // 00424599  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042459b  e8c0160000             -call 0x425c60
    cpu.esp -= 4;
    sub_425c60(app, cpu);
    // 004245a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004245a2  7515                   -jne 0x4245b9
    if (!cpu.flags.zf)
    {
        goto L_0x004245b9;
    }
L_0x004245a4:
    // 004245a4  e867020400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 004245a9  ba4cbb4a00             -mov edx, 0x4abb4c
    cpu.edx = 4897612 /*0x4abb4c*/;
    // 004245ae  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004245b0  e8ab160000             -call 0x425c60
    cpu.esp -= 4;
    sub_425c60(app, cpu);
    // 004245b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004245b7  74eb                   -je 0x4245a4
    if (cpu.flags.zf)
    {
        goto L_0x004245a4;
    }
L_0x004245b9:
    // 004245b9  83f802                 +cmp eax, 2
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
    // 004245bc  0f84ed000000           -je 0x4246af
    if (cpu.flags.zf)
    {
        goto L_0x004246af;
    }
    // 004245c2  83f806                 +cmp eax, 6
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
    // 004245c5  0f8489f6ffff           -je 0x423c54
    if (cpu.flags.zf)
    {
        goto L_0x00423c54;
    }
    // 004245cb  83f801                 +cmp eax, 1
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
    // 004245ce  75a4                   -jne 0x424574
    if (!cpu.flags.zf)
    {
        goto L_0x00424574;
    }
    // 004245d0  e940010000             -jmp 0x424715
    goto L_0x00424715;
L_0x004245d5:
    // 004245d5  e8969bffff             -call 0x41e170
    cpu.esp -= 4;
    sub_41e170(app, cpu);
L_0x004245da:
    // 004245da  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004245df  e8fc9bffff             -call 0x41e1e0
    cpu.esp -= 4;
    sub_41e1e0(app, cpu);
    // 004245e4  e8377cffff             -call 0x41c220
    cpu.esp -= 4;
    sub_41c220(app, cpu);
    // 004245e9  e842110400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004245ee  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004245f2:
    // 004245f2  e8f9e40300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 004245f7  e814020400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 004245fc  e82f110400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00424601  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00424605  dc1d80784800           -fcomp qword ptr [0x487880]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749440) /* 0x487880 */)));
    cpu.fpu.pop();
    // 0042460b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042460d  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00424610  7be0                   -jnp 0x4245f2
    if (!cpu.flags.pf)
    {
        goto L_0x004245f2;
    }
    // 00424612  e819110400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00424617  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042461b  e860030000             -call 0x424980
    cpu.esp -= 4;
    sub_424980(app, cpu);
    // 00424620  b139                   -mov cl, 0x39
    cpu.cl = 57 /*0x39*/;
    // 00424622  e8b9e50300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424627  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424629  0f85c3000000           -jne 0x4246f2
    if (!cpu.flags.zf)
    {
        goto L_0x004246f2;
    }
    // 0042462f  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00424631  e8aae50300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424636  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424638  74b8                   -je 0x4245f2
    if (cpu.flags.zf)
    {
        goto L_0x004245f2;
    }
    // 0042463a  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0042463c  e89fe50300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424641  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424643  7415                   -je 0x42465a
    if (cpu.flags.zf)
    {
        goto L_0x0042465a;
    }
L_0x00424645:
    // 00424645  e8a6e40300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 0042464a  e8c1010400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 0042464f  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00424651  e88ae50300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424656  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424658  75eb                   -jne 0x424645
    if (!cpu.flags.zf)
    {
        goto L_0x00424645;
    }
L_0x0042465a:
    // 0042465a  ba4cbb4a00             -mov edx, 0x4abb4c
    cpu.edx = 4897612 /*0x4abb4c*/;
    // 0042465f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424661  e8fa150000             -call 0x425c60
    cpu.esp -= 4;
    sub_425c60(app, cpu);
    // 00424666  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00424668  83fe01                 +cmp esi, 1
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
    // 0042466b  0f8493000000           -je 0x424704
    if (cpu.flags.zf)
    {
        goto L_0x00424704;
    }
    // 00424671  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00424673  e868e50300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00424678  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042467a  7415                   -je 0x424691
    if (cpu.flags.zf)
    {
        goto L_0x00424691;
    }
L_0x0042467c:
    // 0042467c  e86fe40300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00424681  e88a010400             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00424686  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00424688  e853e50300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0042468d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042468f  75eb                   -jne 0x42467c
    if (!cpu.flags.zf)
    {
        goto L_0x0042467c;
    }
L_0x00424691:
    // 00424691  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424693  e8489bffff             -call 0x41e1e0
    cpu.esp -= 4;
    sub_41e1e0(app, cpu);
    // 00424698  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042469a  7413                   -je 0x4246af
    if (cpu.flags.zf)
    {
        goto L_0x004246af;
    }
    // 0042469c  83fe02                 +cmp esi, 2
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
    // 0042469f  740e                   -je 0x4246af
    if (cpu.flags.zf)
    {
        goto L_0x004246af;
    }
    // 004246a1  83fe06                 +cmp esi, 6
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
    // 004246a4  0f8530ffffff           -jne 0x4245da
    if (!cpu.flags.zf)
    {
        goto L_0x004245da;
    }
    // 004246aa  e9a5f5ffff             -jmp 0x423c54
    goto L_0x00423c54;
L_0x004246af:
    // 004246af  e8dc8d0300             -call 0x45d490
    cpu.esp -= 4;
    sub_45d490(app, cpu);
    // 004246b4  c7058c2d4a00ffffffff   -mov dword ptr [0x4a2d8c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4861324) /* 0x4a2d8c */) = 4294967295 /*0xffffffff*/;
    // 004246be  e8cd790300             -call 0x45c090
    cpu.esp -= 4;
    sub_45c090(app, cpu);
    // 004246c3  e8182cffff             -call 0x4172e0
    cpu.esp -= 4;
    sub_4172e0(app, cpu);
    // 004246c8  e950f5ffff             -jmp 0x423c1d
    goto L_0x00423c1d;
L_0x004246cd:
    // 004246cd  e8be8d0300             -call 0x45d490
    cpu.esp -= 4;
    sub_45d490(app, cpu);
    // 004246d2  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004246d4  e8079bffff             -call 0x41e1e0
    cpu.esp -= 4;
    sub_41e1e0(app, cpu);
    // 004246d9  c7058c2d4a00ffffffff   -mov dword ptr [0x4a2d8c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4861324) /* 0x4a2d8c */) = 4294967295 /*0xffffffff*/;
    // 004246e3  e8a8790300             -call 0x45c090
    cpu.esp -= 4;
    sub_45c090(app, cpu);
    // 004246e8  e8f32bffff             -call 0x4172e0
    cpu.esp -= 4;
    sub_4172e0(app, cpu);
    // 004246ed  e92bf5ffff             -jmp 0x423c1d
    goto L_0x00423c1d;
L_0x004246f2:
    // 004246f2  e809600300             -call 0x45a700
    cpu.esp -= 4;
    sub_45a700(app, cpu);
    // 004246f7  393ddc284900           +cmp dword ptr [0x4928dc], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004246fd  7d05                   -jge 0x424704
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00424704;
    }
    // 004246ff  e85c200000             -call 0x426760
    cpu.esp -= 4;
    sub_426760(app, cpu);
L_0x00424704:
    // 00424704  e807a9feff             -call 0x40f010
    cpu.esp -= 4;
    sub_40f010(app, cpu);
    // 00424709  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042470b  e8d09affff             -call 0x41e1e0
    cpu.esp -= 4;
    sub_41e1e0(app, cpu);
L_0x00424710:
    // 00424710  e8eb5f0300             -call 0x45a700
    cpu.esp -= 4;
    sub_45a700(app, cpu);
L_0x00424715:
    // 00424715  e816100400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042471a  dc642418               -fsub qword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 0042471e  db442424               -fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 00424722  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00424725  d8f1                   -fdiv st(1)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(1));
    // 00424727  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042472a  68ec2e4900             -push 0x492eec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796140 /*0x492eec*/;
    cpu.esp -= 4;
    // 0042472f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424731  e881260500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00424736  a11c845100             -mov eax, dword ptr [0x51841c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342236) /* 0x51841c */);
    // 0042473b  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00424742  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00424744  a10c845100             -mov eax, dword ptr [0x51840c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342220) /* 0x51840c */);
    // 00424749  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042474c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0042474f  8d0c90                 -lea ecx, [eax + edx*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 4);
    // 00424752  a124845100             -mov eax, dword ptr [0x518424]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342244) /* 0x518424 */);
    // 00424757  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0042475a  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0042475d  8d1481                 -lea edx, [ecx + eax*4]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 00424760  8b0d2c845100           -mov ecx, dword ptr [0x51842c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 00424766  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00424769  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0042476c  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042476e  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00424771  8d0c82                 -lea ecx, [edx + eax*4]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 4);
    // 00424774  c1e90a                 -shr ecx, 0xa
    cpu.ecx >>= 10 /*0xa*/ % 32;
    // 00424777  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424778  68d82e4900             -push 0x492ed8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796120 /*0x492ed8*/;
    cpu.esp -= 4;
    // 0042477d  e835260500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00424782  68d42e4900             -push 0x492ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796116 /*0x492ed4*/;
    cpu.esp -= 4;
    // 00424787  e82b260500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042478c  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00424791  e8d1310500             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00424796  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00424799  e8c20e0400             -call 0x465660
    cpu.esp -= 4;
    sub_465660(app, cpu);
    // 0042479e  e81d030000             -call 0x424ac0
    cpu.esp -= 4;
    sub_424ac0(app, cpu);
L_0x004247a3:
    // 004247a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004247a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004247a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004247a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004247a7  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004247a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004247aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4247b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004247b0  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 004247b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004247b6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004247b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004247ba  7e32                   -jle 0x4247ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004247ee;
    }
L_0x004247bc:
    // 004247bc  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004247c1  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 004247c4  6683b88a02000000       +cmp word ptr [eax + 0x28a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(650) /* 0x28a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004247cc  7e16                   -jle 0x4247e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004247e4;
    }
    // 004247ce  f6406402               +test byte ptr [eax + 0x64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(100) /* 0x64 */) & 2 /*0x2*/));
    // 004247d2  7409                   -je 0x4247dd
    if (cpu.flags.zf)
    {
        goto L_0x004247dd;
    }
    // 004247d4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004247d6  e8752f0300             -call 0x457750
    cpu.esp -= 4;
    sub_457750(app, cpu);
    // 004247db  eb07                   -jmp 0x4247e4
    goto L_0x004247e4;
L_0x004247dd:
    // 004247dd  c7407400000000         -mov dword ptr [eax + 0x74], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
L_0x004247e4:
    // 004247e4  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 004247e9  46                     -inc esi
    (cpu.esi)++;
    // 004247ea  3bf0                   +cmp esi, eax
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
    // 004247ec  7cce                   -jl 0x4247bc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004247bc;
    }
L_0x004247ee:
    // 004247ee  e86d140300             -call 0x455c60
    cpu.esp -= 4;
    sub_455c60(app, cpu);
    // 004247f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004247f5  747e                   -je 0x424875
    if (cpu.flags.zf)
    {
        goto L_0x00424875;
    }
    // 004247f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004247f8  8b3d30845100           -mov edi, dword ptr [0x518430]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
L_0x004247fe:
    // 004247fe  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00424804  8bb030030000           -mov esi, dword ptr [eax + 0x330]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(816) /* 0x330 */);
    // 0042480a  8b0c8f                 -mov ecx, dword ptr [edi + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0042480d  8b81e8020000           -mov eax, dword ptr [ecx + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 00424813  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424815  7557                   -jne 0x42486e
    if (!cpu.flags.zf)
    {
        goto L_0x0042486e;
    }
    // 00424817  8b81c8020000           -mov eax, dword ptr [ecx + 0x2c8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */);
    // 0042481d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042481f  744d                   -je 0x42486e
    if (cpu.flags.zf)
    {
        goto L_0x0042486e;
    }
    // 00424821  8b91b8020000           -mov edx, dword ptr [ecx + 0x2b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */);
    // 00424827  d982d4000000           -fld dword ptr [edx + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(212) /* 0xd4 */)));
    // 0042482d  d805b8744800           -fadd dword ptr [0x4874b8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 00424833  d899d4000000           -fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 00424839  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042483b  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042483e  7a2e                   -jp 0x42486e
    if (cpu.flags.pf)
    {
        goto L_0x0042486e;
    }
    // 00424840  d982d4000000           -fld dword ptr [edx + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(212) /* 0xd4 */)));
    // 00424846  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0042484c  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 00424852  d825b8744800           -fsub dword ptr [0x4874b8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 00424858  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424859  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042485b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042485c  8b0c87                 -mov ecx, dword ptr [edi + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 0042485f  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424862  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424863  e898ae0200             -call 0x44f700
    cpu.esp -= 4;
    sub_44f700(app, cpu);
    // 00424868  8b3d30845100           -mov edi, dword ptr [0x518430]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
L_0x0042486e:
    // 0042486e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00424870  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00424872  758a                   -jne 0x4247fe
    if (!cpu.flags.zf)
    {
        goto L_0x004247fe;
    }
    // 00424874  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00424875:
    // 00424875  e876c50000             -call 0x430df0
    cpu.esp -= 4;
    sub_430df0(app, cpu);
    // 0042487a  e82150feff             -call 0x4098a0
    cpu.esp -= 4;
    sub_4098a0(app, cpu);
    // 0042487f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424880  e93b320300             -jmp 0x457ac0
    return sub_457ac0(app, cpu);
}

/* align: skip  */
void Application::sub_424890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424890  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00424895  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00424898  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042489a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042489b  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 004248a1  81c900000002           -or ecx, 0x2000000
    cpu.ecx |= x86::reg32(x86::sreg32(33554432 /*0x2000000*/));
    // 004248a7  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 004248ad  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004248b3  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004248b5  8bb1c8020000           -mov esi, dword ptr [ecx + 0x2c8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */);
    // 004248bb  8d91cc000000           -lea edx, [ecx + 0xcc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 004248c1  e87aeb0200             -call 0x453440
    cpu.esp -= 4;
    sub_453440(app, cpu);
    // 004248c6  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004248cb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004248cd  8b91c8020000           -mov edx, dword ptr [ecx + 0x2c8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */);
    // 004248d3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004248d5  0f849e000000           -je 0x424979
    if (cpu.flags.zf)
    {
        goto L_0x00424979;
    }
    // 004248db  f6421104               +test byte ptr [edx + 0x11], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */) & 4 /*0x4*/));
    // 004248df  740b                   -je 0x4248ec
    if (cpu.flags.zf)
    {
        goto L_0x004248ec;
    }
    // 004248e1  89b1c8020000           -mov dword ptr [ecx + 0x2c8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */) = cpu.esi;
    // 004248e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004248e8  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004248eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004248ec:
    // 004248ec  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 004248f2  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004248f6  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004248f8  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 004248fe  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00424902  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00424904  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0042490a  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042490e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00424910  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00424914  e897a30300             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 00424919  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042491f  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00424923  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424924  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00424928  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042492a  8b88c8020000           -mov ecx, dword ptr [eax + 0x2c8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */);
    // 00424930  e80bf60200             -call 0x453f40
    cpu.esp -= 4;
    sub_453f40(app, cpu);
    // 00424935  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042493b  d825b8744800           -fsub dword ptr [0x4874b8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 00424941  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00424943  d891d4000000           -fcom dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    // 00424949  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042494b  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042494e  7a19                   -jp 0x424969
    if (cpu.flags.pf)
    {
        goto L_0x00424969;
    }
    // 00424950  d999d4000000           -fstp dword ptr [ecx + 0xd4]
    app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424956  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042495c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042495e  89b0c8020000           -mov dword ptr [eax + 0x2c8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */) = cpu.esi;
    // 00424964  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424965  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00424968  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00424969:
    // 00424969  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042496f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424971  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00424973  89b0c8020000           -mov dword ptr [eax + 0x2c8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */) = cpu.esi;
L_0x00424979:
    // 00424979  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042497a  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0042497d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_424980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424980  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 00424985  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424986  8b3570d34a00           -mov esi, dword ptr [0x4ad370]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4903792) /* 0x4ad370 */);
    // 0042498c  a3a8d34a00             -mov dword ptr [0x4ad3a8], eax
    app->getMemory<x86::reg32>(x86::reg32(4903848) /* 0x4ad3a8 */) = cpu.eax;
    // 00424991  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00424993  750b                   -jne 0x4249a0
    if (!cpu.flags.zf)
    {
        goto L_0x004249a0;
    }
    // 00424995  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0042499b  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042499e  eb47                   -jmp 0x4249e7
    goto L_0x004249e7;
L_0x004249a0:
    // 004249a0  a1acd34a00             -mov eax, dword ptr [0x4ad3ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903852) /* 0x4ad3ac */);
    // 004249a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004249a7  7408                   -je 0x4249b1
    if (cpu.flags.zf)
    {
        goto L_0x004249b1;
    }
    // 004249a9  3b35e8284900           +cmp esi, dword ptr [0x4928e8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4794600) /* 0x4928e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004249af  743b                   -je 0x4249ec
    if (cpu.flags.zf)
    {
        goto L_0x004249ec;
    }
L_0x004249b1:
    // 004249b1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004249b3  8935e8284900           -mov dword ptr [0x4928e8], esi
    app->getMemory<x86::reg32>(x86::reg32(4794600) /* 0x4928e8 */) = cpu.esi;
    // 004249b9  7e31                   -jle 0x4249ec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004249ec;
    }
    // 004249bb  8b0d20bb4a00           -mov ecx, dword ptr [0x4abb20]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 004249c1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004249c6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004249c8  7422                   -je 0x4249ec
    if (cpu.flags.zf)
    {
        goto L_0x004249ec;
    }
    // 004249ca  8b813c050000           -mov eax, dword ptr [ecx + 0x53c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1340) /* 0x53c */);
    // 004249d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004249d2  7411                   -je 0x4249e5
    if (cpu.flags.zf)
    {
        goto L_0x004249e5;
    }
L_0x004249d4:
    // 004249d4  3bd6                   +cmp edx, esi
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
    // 004249d6  7d0d                   -jge 0x4249e5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004249e5;
    }
    // 004249d8  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004249da  42                     -inc edx
    (cpu.edx)++;
    // 004249db  8b813c050000           -mov eax, dword ptr [ecx + 0x53c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1340) /* 0x53c */);
    // 004249e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004249e3  75ef                   -jne 0x4249d4
    if (!cpu.flags.zf)
    {
        goto L_0x004249d4;
    }
L_0x004249e5:
    // 004249e5  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
L_0x004249e7:
    // 004249e7  a3acd34a00             -mov dword ptr [0x4ad3ac], eax
    app->getMemory<x86::reg32>(x86::reg32(4903852) /* 0x4ad3ac */) = cpu.eax;
L_0x004249ec:
    // 004249ec  8b9080000000           -mov edx, dword ptr [eax + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004249f2  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004249f7  8b3490                 -mov esi, dword ptr [eax + edx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004249fa  8b86e8020000           -mov eax, dword ptr [esi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 00424a00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424a02  743c                   -je 0x424a40
    if (cpu.flags.zf)
    {
        goto L_0x00424a40;
    }
L_0x00424a04:
    // 00424a04  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00424a0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424a0c  750d                   -jne 0x424a1b
    if (!cpu.flags.zf)
    {
        goto L_0x00424a1b;
    }
    // 00424a0e  68cc324900             -push 0x4932cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797132 /*0x4932cc*/;
    cpu.esp -= 4;
    // 00424a13  e8f8010000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00424a18  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00424a1b:
    // 00424a1b  e8608a0300             -call 0x45d480
    cpu.esp -= 4;
    sub_45d480(app, cpu);
    // 00424a20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424a22  740c                   -je 0x424a30
    if (cpu.flags.zf)
    {
        goto L_0x00424a30;
    }
    // 00424a24  8b8eec020000           -mov ecx, dword ptr [esi + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00424a2a  f6414a01               +test byte ptr [ecx + 0x4a], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(74) /* 0x4a */) & 1 /*0x1*/));
    // 00424a2e  7510                   -jne 0x424a40
    if (!cpu.flags.zf)
    {
        goto L_0x00424a40;
    }
L_0x00424a30:
    // 00424a30  8bb6e8020000           -mov esi, dword ptr [esi + 0x2e8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 00424a36  8b86e8020000           -mov eax, dword ptr [esi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 00424a3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424a3e  75c4                   -jne 0x424a04
    if (!cpu.flags.zf)
    {
        goto L_0x00424a04;
    }
L_0x00424a40:
    // 00424a40  8b8eec020000           -mov ecx, dword ptr [esi + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00424a46  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00424a48  890dacd34a00           -mov dword ptr [0x4ad3ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903852) /* 0x4ad3ac */) = cpu.ecx;
    // 00424a4e  6890484200             -push 0x424890
    app->getMemory<x86::reg32>(cpu.esp-4) = 4343952 /*0x424890*/;
    cpu.esp -= 4;
    // 00424a53  8a5148                 -mov dl, byte ptr [ecx + 0x48]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00424a56  8bb180000000           -mov esi, dword ptr [ecx + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 00424a5c  80fa19                 +cmp dl, 0x19
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(25 /*0x19*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00424a5f  8b911c030000           -mov edx, dword ptr [ecx + 0x31c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(796) /* 0x31c */);
    // 00424a65  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00424a68  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424a69  8b9118030000           -mov edx, dword ptr [ecx + 0x318]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 00424a6f  48                     -dec eax
    (cpu.eax)--;
    // 00424a70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424a71  8b9114030000           -mov edx, dword ptr [ecx + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(788) /* 0x314 */);
    // 00424a77  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00424a7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424a7b  8b948180000000         -mov edx, dword ptr [ecx + eax*4 + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */ + cpu.eax * 4);
    // 00424a82  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00424a84  e8278b0300             -call 0x45d5b0
    cpu.esp -= 4;
    sub_45d5b0(app, cpu);
    // 00424a89  e8520d0000             -call 0x4257e0
    cpu.esp -= 4;
    sub_4257e0(app, cpu);
    // 00424a8e  e8ade30200             -call 0x452e40
    cpu.esp -= 4;
    sub_452e40(app, cpu);
    // 00424a93  c705a841510000000000   -mov dword ptr [0x5141a8], 0
    app->getMemory<x86::reg32>(x86::reg32(5325224) /* 0x5141a8 */) = 0 /*0x0*/;
    // 00424a9d  e82e0d0000             -call 0x4257d0
    cpu.esp -= 4;
    sub_4257d0(app, cpu);
    // 00424aa2  f7d8                   +neg eax
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
    // 00424aa4  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00424aa6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424aa7  f7d8                   +neg eax
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
    // 00424aa9  a380c74a00             -mov dword ptr [0x4ac780], eax
    app->getMemory<x86::reg32>(x86::reg32(4900736) /* 0x4ac780 */) = cpu.eax;
    // 00424aae  e93d910200             -jmp 0x44dbf0
    return sub_44dbf0(app, cpu);
}

/* align: skip  */
void Application::sub_424ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424ac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424ac1  8b0db0d34a00           -mov ecx, dword ptr [0x4ad3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903856) /* 0x4ad3b0 */);
    // 00424ac7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00424acc  3bc8                   +cmp ecx, eax
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
    // 00424ace  0f8435010000           -je 0x424c09
    if (cpu.flags.zf)
    {
        goto L_0x00424c09;
    }
    // 00424ad4  a3b0d34a00             -mov dword ptr [0x4ad3b0], eax
    app->getMemory<x86::reg32>(x86::reg32(4903856) /* 0x4ad3b0 */) = cpu.eax;
    // 00424ad9  e8a27efeff             -call 0x40c980
    cpu.esp -= 4;
    sub_40c980(app, cpu);
    // 00424ade  e8cde30300             -call 0x462eb0
    cpu.esp -= 4;
    sub_462eb0(app, cpu);
    // 00424ae3  a11c845100             -mov eax, dword ptr [0x51841c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342236) /* 0x51841c */);
    // 00424ae8  8b0d0c845100           -mov ecx, dword ptr [0x51840c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342220) /* 0x51840c */);
    // 00424aee  8b1524845100           -mov edx, dword ptr [0x518424]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342244) /* 0x518424 */);
    // 00424af4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424af5  a12c845100             -mov eax, dword ptr [0x51842c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 00424afa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424afb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424afc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424afd  6828334900             -push 0x493328
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797224 /*0x493328*/;
    cpu.esp -= 4;
    // 00424b02  e8b0220500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00424b07  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00424b0c  e8562e0500             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00424b11  8b0d2c845100           -mov ecx, dword ptr [0x51842c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 00424b17  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00424b1a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00424b1d  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424b1f  8d0cc0                 -lea ecx, [eax + eax*8]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00424b22  a124845100             -mov eax, dword ptr [0x518424]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342244) /* 0x518424 */);
    // 00424b27  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00424b2a  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 00424b2d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00424b30  8d0c88                 -lea ecx, [eax + ecx*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 00424b33  a10c845100             -mov eax, dword ptr [0x51840c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342220) /* 0x51840c */);
    // 00424b38  8d1480                 -lea edx, [eax + eax*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00424b3b  a11c845100             -mov eax, dword ptr [0x51841c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342236) /* 0x51841c */);
    // 00424b40  8d0cd1                 -lea ecx, [ecx + edx*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.edx * 8);
    // 00424b43  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00424b4a  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00424b4c  8d0491                 -lea eax, [ecx + edx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 4);
    // 00424b4f  c1e80a                 -shr eax, 0xa
    cpu.eax >>= 10 /*0xa*/ % 32;
    // 00424b52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424b53  68d82e4900             -push 0x492ed8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4796120 /*0x492ed8*/;
    cpu.esp -= 4;
    // 00424b58  e85a220500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00424b5d  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00424b62  e8002e0500             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00424b67  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00424b6a  e8b1d80300             -call 0x462420
    cpu.esp -= 4;
    sub_462420(app, cpu);
    // 00424b6f  e87c5c0300             -call 0x45a7f0
    cpu.esp -= 4;
    sub_45a7f0(app, cpu);
    // 00424b74  e8977b0100             -call 0x43c710
    cpu.esp -= 4;
    sub_43c710(app, cpu);
    // 00424b79  e8c2190200             -call 0x446540
    cpu.esp -= 4;
    sub_446540(app, cpu);
    // 00424b7e  c705b0d34a0000000000   -mov dword ptr [0x4ad3b0], 0
    app->getMemory<x86::reg32>(x86::reg32(4903856) /* 0x4ad3b0 */) = 0 /*0x0*/;
    // 00424b88  6808334900             -push 0x493308
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797192 /*0x493308*/;
    cpu.esp -= 4;
    // 00424b8d  e825220500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00424b92  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00424b97  e8cb2d0500             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00424b9c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00424b9f  e8cc7c0200             -call 0x44c870
    cpu.esp -= 4;
    sub_44c870(app, cpu);
    // 00424ba4  e8277e0200             -call 0x44c9d0
    cpu.esp -= 4;
    sub_44c9d0(app, cpu);
    // 00424ba9  e8027e0200             -call 0x44c9b0
    cpu.esp -= 4;
    sub_44c9b0(app, cpu);
    // 00424bae  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424bb0  8a0d31165200           -mov cl, byte ptr [0x521631]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379633) /* 0x521631 */);
    // 00424bb6  894c2400               -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00424bba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424bbb  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00424bbf  8b0d04ef5100           -mov ecx, dword ptr [0x51ef04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00424bc5  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 00424bcb  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424bce  e8cd180400             -call 0x4664a0
    cpu.esp -= 4;
    sub_4664a0(app, cpu);
    // 00424bd3  8b1530165200           -mov edx, dword ptr [0x521630]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379632) /* 0x521630 */);
    // 00424bd9  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00424bdf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424be0  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00424be4  8b0d04ef5100           -mov ecx, dword ptr [0x51ef04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00424bea  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00424bee  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 00424bf4  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424bf7  e8c4180400             -call 0x4664c0
    cpu.esp -= 4;
    sub_4664c0(app, cpu);
    // 00424bfc  68f0324900             -push 0x4932f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797168 /*0x4932f0*/;
    cpu.esp -= 4;
    // 00424c01  e8b1210500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00424c06  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00424c09:
    // 00424c09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424c0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_424c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424c10  833db4d34a0001         +cmp dword ptr [0x4ad3b4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4903860) /* 0x4ad3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00424c17  745f                   -je 0x424c78
    if (cpu.flags.zf)
    {
        goto L_0x00424c78;
    }
    // 00424c19  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00424c1d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00424c21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424c22  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424c23  6848d24a00             -push 0x4ad248
    app->getMemory<x86::reg32>(cpu.esp-4) = 4903496 /*0x4ad248*/;
    cpu.esp -= 4;
    // 00424c28  c705b4d34a0001000000   -mov dword ptr [0x4ad3b4], 1
    app->getMemory<x86::reg32>(x86::reg32(4903860) /* 0x4ad3b4 */) = 1 /*0x1*/;
    // 00424c32  e836370500             -call 0x47836d
    cpu.esp -= 4;
    sub_47836d(app, cpu);
    // 00424c37  6848d24a00             -push 0x4ad248
    app->getMemory<x86::reg32>(cpu.esp-4) = 4903496 /*0x4ad248*/;
    cpu.esp -= 4;
    // 00424c3c  684c334900             -push 0x49334c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797260 /*0x49334c*/;
    cpu.esp -= 4;
    // 00424c41  e871210500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00424c46  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00424c4b  e8172d0500             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00424c50  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00424c53  e868feffff             -call 0x424ac0
    cpu.esp -= 4;
    sub_424ac0(app, cpu);
    // 00424c58  b948d24a00             -mov ecx, 0x4ad248
    cpu.ecx = 4903496 /*0x4ad248*/;
    // 00424c5d  e8ce090400             -call 0x465630
    cpu.esp -= 4;
    sub_465630(app, cpu);
    // 00424c62  e899fa0300             -call 0x464700
    cpu.esp -= 4;
    sub_464700(app, cpu);
    // 00424c67  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00424c69  c705b4d34a0000000000   -mov dword ptr [0x4ad3b4], 0
    app->getMemory<x86::reg32>(x86::reg32(4903860) /* 0x4ad3b4 */) = 0 /*0x0*/;
    // 00424c73  e8e7390500             -call 0x47865f
    cpu.esp -= 4;
    sub_47865f(app, cpu);
L_0x00424c78:
    // 00424c78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_424c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424c80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424c81  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424c82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00424c83  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00424c85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424c86  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00424c88  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00424c89  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00424c8b  c644241300             -mov byte ptr [esp + 0x13], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 0 /*0x0*/;
    // 00424c90  7504                   -jne 0x424c96
    if (!cpu.flags.zf)
    {
        goto L_0x00424c96;
    }
    // 00424c92  8d6c2413               -lea ebp, [esp + 0x13]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(19) /* 0x13 */);
L_0x00424c96:
    // 00424c96  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00424c98  7504                   -jne 0x424c9e
    if (!cpu.flags.zf)
    {
        goto L_0x00424c9e;
    }
    // 00424c9a  8d5c2413               -lea ebx, [esp + 0x13]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(19) /* 0x13 */);
L_0x00424c9e:
    // 00424c9e  8b35b8d34a00           -mov esi, dword ptr [0x4ad3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4903864) /* 0x4ad3b8 */);
    // 00424ca4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00424ca6  7440                   -je 0x424ce8
    if (cpu.flags.zf)
    {
        goto L_0x00424ce8;
    }
L_0x00424ca8:
    // 00424ca8  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 00424caa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424cab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00424cac  e87f520500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00424cb1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424cb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424cb6  7526                   -jne 0x424cde
    if (!cpu.flags.zf)
    {
        goto L_0x00424cde;
    }
    // 00424cb8  8d86e8030000           -lea eax, [esi + 0x3e8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1000) /* 0x3e8 */);
    // 00424cbe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424cbf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424cc0  e8ebfe0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00424cc5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00424cc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424cca  7512                   -jne 0x424cde
    if (!cpu.flags.zf)
    {
        goto L_0x00424cde;
    }
    // 00424ccc  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00424cd0  8b8658040000           -mov eax, dword ptr [esi + 0x458]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1112) /* 0x458 */);
    // 00424cd6  3bc8                   +cmp ecx, eax
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
    // 00424cd8  0f84cb000000           -je 0x424da9
    if (cpu.flags.zf)
    {
        goto L_0x00424da9;
    }
L_0x00424cde:
    // 00424cde  8bb65c040000           -mov esi, dword ptr [esi + 0x45c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 00424ce4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00424ce6  75c0                   -jne 0x424ca8
    if (!cpu.flags.zf)
    {
        goto L_0x00424ca8;
    }
L_0x00424ce8:
    // 00424ce8  8b3db8d34a00           -mov edi, dword ptr [0x4ad3b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4903864) /* 0x4ad3b8 */);
    // 00424cee  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00424cf0  7410                   -je 0x424d02
    if (cpu.flags.zf)
    {
        goto L_0x00424d02;
    }
L_0x00424cf2:
    // 00424cf2  8b875c040000           -mov eax, dword ptr [edi + 0x45c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1116) /* 0x45c */);
    // 00424cf8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424cfa  7406                   -je 0x424d02
    if (cpu.flags.zf)
    {
        goto L_0x00424d02;
    }
    // 00424cfc  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00424cfe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00424d00  75f0                   -jne 0x424cf2
    if (!cpu.flags.zf)
    {
        goto L_0x00424cf2;
    }
L_0x00424d02:
    // 00424d02  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00424d06  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00424d0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424d0b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00424d0e  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424d12  d9442438               -fld dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */)));
    // 00424d16  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424d1a  d9442434               -fld dword ptr [esp + 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */)));
    // 00424d1e  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00424d21  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424d22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00424d23  6858334900             -push 0x493358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797272 /*0x493358*/;
    cpu.esp -= 4;
    // 00424d28  e88a200500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00424d2d  6860040000             -push 0x460
    app->getMemory<x86::reg32>(cpu.esp-4) = 1120 /*0x460*/;
    cpu.esp -= 4;
    // 00424d32  e843250500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00424d37  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00424d39  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00424d3c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00424d3e  7469                   -je 0x424da9
    if (cpu.flags.zf)
    {
        goto L_0x00424da9;
    }
    // 00424d40  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00424d42  7408                   -je 0x424d4c
    if (cpu.flags.zf)
    {
        goto L_0x00424d4c;
    }
    // 00424d44  89b75c040000           -mov dword ptr [edi + 0x45c], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1116) /* 0x45c */) = cpu.esi;
    // 00424d4a  eb06                   -jmp 0x424d52
    goto L_0x00424d52;
L_0x00424d4c:
    // 00424d4c  8935b8d34a00           -mov dword ptr [0x4ad3b8], esi
    app->getMemory<x86::reg32>(x86::reg32(4903864) /* 0x4ad3b8 */) = cpu.esi;
L_0x00424d52:
    // 00424d52  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00424d54  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00424d56  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00424d59  e852030000             -call 0x4250b0
    cpu.esp -= 4;
    sub_4250b0(app, cpu);
    // 00424d5e  8d86e8030000           -lea eax, [esi + 0x3e8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1000) /* 0x3e8 */);
    // 00424d64  6a63                   -push 0x63
    app->getMemory<x86::reg32>(cpu.esp-4) = 99 /*0x63*/;
    cpu.esp -= 4;
    // 00424d66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424d67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424d68  e853300500             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 00424d6d  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00424d71  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00424d75  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00424d79  898e4c040000           -mov dword ptr [esi + 0x44c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1100) /* 0x44c */) = cpu.ecx;
    // 00424d7f  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00424d83  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424d86  c6864b04000000         -mov byte ptr [esi + 0x44b], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1099) /* 0x44b */) = 0 /*0x0*/;
    // 00424d8d  899650040000           -mov dword ptr [esi + 0x450], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.edx;
    // 00424d93  898654040000           -mov dword ptr [esi + 0x454], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */) = cpu.eax;
    // 00424d99  898e58040000           -mov dword ptr [esi + 0x458], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1112) /* 0x458 */) = cpu.ecx;
    // 00424d9f  c7865c04000000000000   -mov dword ptr [esi + 0x45c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1116) /* 0x45c */) = 0 /*0x0*/;
L_0x00424da9:
    // 00424da9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424daa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424dab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424dac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424dad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424dae  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_424dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424dc0  a1b8d34a00             -mov eax, dword ptr [0x4ad3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903864) /* 0x4ad3b8 */);
    // 00424dc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424dc7  7417                   -je 0x424de0
    if (cpu.flags.zf)
    {
        goto L_0x00424de0;
    }
    // 00424dc9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00424dca:
    // 00424dca  8bb05c040000           -mov esi, dword ptr [eax + 0x45c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1116) /* 0x45c */);
    // 00424dd0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424dd1  e8de250500             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00424dd6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00424dd9  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00424ddb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00424ddd  75eb                   -jne 0x424dca
    if (!cpu.flags.zf)
    {
        goto L_0x00424dca;
    }
    // 00424ddf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00424de0:
    // 00424de0  c705b8d34a0000000000   -mov dword ptr [0x4ad3b8], 0
    app->getMemory<x86::reg32>(x86::reg32(4903864) /* 0x4ad3b8 */) = 0 /*0x0*/;
    // 00424dea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_424df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424df0  81ec8c030000           -sub esp, 0x38c
    (cpu.esp) -= x86::reg32(x86::sreg32(908 /*0x38c*/));
    // 00424df6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424df7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00424df8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424df9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00424dfa  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00424dff  e8bcffffff             -call 0x424dc0
    cpu.esp -= 4;
    sub_424dc0(app, cpu);
    // 00424e04  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 00424e09  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00424e0d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00424e12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424e13  68cc334900             -push 0x4933cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797388 /*0x4933cc*/;
    cpu.esp -= 4;
    // 00424e18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424e19  e8da1f0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00424e1e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424e21  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 00424e26  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00424e2a  e8117c0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00424e2f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00424e31  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00424e33  0f846b020000           -je 0x4250a4
    if (cpu.flags.zf)
    {
        goto L_0x004250a4;
    }
    // 00424e39  f6460c10               +test byte ptr [esi + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 00424e3d  0f8561020000           -jne 0x4250a4
    if (!cpu.flags.zf)
    {
        goto L_0x004250a4;
    }
    // 00424e43  b320                   -mov bl, 0x20
    cpu.bl = 32 /*0x20*/;
L_0x00424e45:
    // 00424e45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424e46  8d9424a0010000         -lea edx, [esp + 0x1a0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 00424e4d  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00424e52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424e53  e8802a0500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00424e58  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424e5b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424e5d  0f8441020000           -je 0x4250a4
    if (cpu.flags.zf)
    {
        goto L_0x004250a4;
    }
    // 00424e63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424e64  8d8424a0000000         -lea eax, [esp + 0xa0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 00424e6b  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00424e70  8bef                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00424e72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424e73  47                     -inc edi
    (cpu.edi)++;
    // 00424e74  e85f2a0500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00424e79  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424e7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424e7e  0f84b3010000           -je 0x425037
    if (cpu.flags.zf)
    {
        goto L_0x00425037;
    }
    // 00424e84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424e85  8d8c2420010000         -lea ecx, [esp + 0x120]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 00424e8c  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00424e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424e92  47                     -inc edi
    (cpu.edi)++;
    // 00424e93  e8402a0500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00424e98  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424e9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424e9d  0f8469010000           -je 0x42500c
    if (cpu.flags.zf)
    {
        goto L_0x0042500c;
    }
    // 00424ea3  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00424ea7  8d84241c010000         -lea eax, [esp + 0x11c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00424eae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424eaf  68c4334900             -push 0x4933c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797380 /*0x4933c4*/;
    cpu.esp -= 4;
    // 00424eb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424eb5  e89a270500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00424eba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424ebd  83f801                 +cmp eax, 1
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
    // 00424ec0  0f856e010000           -jne 0x425034
    if (!cpu.flags.zf)
    {
        goto L_0x00425034;
    }
    // 00424ec6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424ec7  8d8c2420010000         -lea ecx, [esp + 0x120]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 00424ece  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00424ed3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424ed4  47                     -inc edi
    (cpu.edi)++;
    // 00424ed5  e8fe290500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00424eda  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424edd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424edf  0f8452010000           -je 0x425037
    if (cpu.flags.zf)
    {
        goto L_0x00425037;
    }
    // 00424ee5  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00424ee9  8d84241c010000         -lea eax, [esp + 0x11c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00424ef0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424ef1  68bc334900             -push 0x4933bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797372 /*0x4933bc*/;
    cpu.esp -= 4;
    // 00424ef6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424ef7  e858270500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00424efc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424eff  83f801                 +cmp eax, 1
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
    // 00424f02  0f8504010000           -jne 0x42500c
    if (!cpu.flags.zf)
    {
        goto L_0x0042500c;
    }
    // 00424f08  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424f09  8d8c2420010000         -lea ecx, [esp + 0x120]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 00424f10  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00424f15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424f16  47                     -inc edi
    (cpu.edi)++;
    // 00424f17  e8bc290500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00424f1c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424f1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424f21  0f840d010000           -je 0x425034
    if (cpu.flags.zf)
    {
        goto L_0x00425034;
    }
    // 00424f27  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00424f2b  8d84241c010000         -lea eax, [esp + 0x11c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00424f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424f33  68b0334900             -push 0x4933b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797360 /*0x4933b0*/;
    cpu.esp -= 4;
    // 00424f38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424f39  e816270500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00424f3e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424f41  83f801                 +cmp eax, 1
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
    // 00424f44  0f85ed000000           -jne 0x425037
    if (!cpu.flags.zf)
    {
        goto L_0x00425037;
    }
    // 00424f4a  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00424f4c  8d8c24a0010000         -lea ecx, [esp + 0x1a0]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 00424f53  68a8334900             -push 0x4933a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797352 /*0x4933a8*/;
    cpu.esp -= 4;
    // 00424f58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424f59  47                     -inc edi
    (cpu.edi)++;
    // 00424f5a  e8d14f0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00424f5f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424f62  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424f64  0f85f5000000           -jne 0x42505f
    if (!cpu.flags.zf)
    {
        goto L_0x0042505f;
    }
    // 00424f6a  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00424f6c  8d9424a0000000         -lea edx, [esp + 0xa0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 00424f73  68a0334900             -push 0x4933a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797344 /*0x4933a0*/;
    cpu.esp -= 4;
    // 00424f78  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424f79  e8b24f0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00424f7e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424f81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424f83  0f85fe000000           -jne 0x425087
    if (!cpu.flags.zf)
    {
        goto L_0x00425087;
    }
    // 00424f89  8a8c24a1010000         -mov cl, byte ptr [esp + 0x1a1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(417) /* 0x1a1 */);
    // 00424f90  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00424f95  80f90d                 +cmp cl, 0xd
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
    // 00424f98  760d                   -jbe 0x424fa7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00424fa7;
    }
L_0x00424f9a:
    // 00424f9a  8a8c049d010000         -mov cl, byte ptr [esp + eax + 0x19d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(413) /* 0x19d */ + cpu.eax * 1);
    // 00424fa1  40                     -inc eax
    (cpu.eax)++;
    // 00424fa2  80f90d                 +cmp cl, 0xd
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
    // 00424fa5  77f3                   -ja 0x424f9a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00424f9a;
    }
L_0x00424fa7:
    // 00424fa7  8a8c24a1000000         -mov cl, byte ptr [esp + 0xa1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(161) /* 0xa1 */);
    // 00424fae  c684049c01000000       -mov byte ptr [esp + eax + 0x19c], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(412) /* 0x19c */ + cpu.eax * 1) = 0 /*0x0*/;
    // 00424fb6  3acb                   +cmp cl, bl
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
    // 00424fb8  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00424fbd  760c                   -jbe 0x424fcb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00424fcb;
    }
L_0x00424fbf:
    // 00424fbf  8a8c049d000000         -mov cl, byte ptr [esp + eax + 0x9d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(157) /* 0x9d */ + cpu.eax * 1);
    // 00424fc6  40                     -inc eax
    (cpu.eax)++;
    // 00424fc7  3acb                   +cmp cl, bl
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
    // 00424fc9  77f4                   -ja 0x424fbf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00424fbf;
    }
L_0x00424fcb:
    // 00424fcb  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00424fcf  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00424fd3  c684049c00000000       -mov byte ptr [esp + eax + 0x9c], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(156) /* 0x9c */ + cpu.eax * 1) = 0 /*0x0*/;
    // 00424fdb  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00424fdf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00424fe1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00424fe2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424fe3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424fe4  8d9424b1000000         -lea edx, [esp + 0xb1]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(177) /* 0xb1 */);
    // 00424feb  8d8c24b1010000         -lea ecx, [esp + 0x1b1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(433) /* 0x1b1 */);
    // 00424ff2  e889fcffff             -call 0x424c80
    cpu.esp -= 4;
    sub_424c80(app, cpu);
    // 00424ff7  f6460c10               +test byte ptr [esi + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 00424ffb  0f8444feffff           -je 0x424e45
    if (cpu.flags.zf)
    {
        goto L_0x00424e45;
    }
    // 00425001  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425002  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425003  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425004  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425005  81c48c030000           -add esp, 0x38c
    (cpu.esp) += x86::reg32(x86::sreg32(908 /*0x38c*/));
    // 0042500b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042500c:
    // 0042500c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042500d  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00425011  6878334900             -push 0x493378
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797304 /*0x493378*/;
    cpu.esp -= 4;
    // 00425016  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425017  e8dc1d0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042501c  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00425020  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425021  e8eafbffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00425026  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00425029  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042502a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042502b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042502c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042502d  81c48c030000           +add esp, 0x38c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(908 /*0x38c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00425033  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425034:
    // 00425034  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425035  eb51                   -jmp 0x425088
    goto L_0x00425088;
L_0x00425037:
    // 00425037  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425038  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042503c  6878334900             -push 0x493378
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797304 /*0x493378*/;
    cpu.esp -= 4;
    // 00425041  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425042  e8b11d0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00425047  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042504b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042504c  e8bffbffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00425051  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00425054  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425055  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425056  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425057  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425058  81c48c030000           -add esp, 0x38c
    (cpu.esp) += x86::reg32(x86::sreg32(908 /*0x38c*/));
    // 0042505e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042505f:
    // 0042505f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425060  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00425064  6878334900             -push 0x493378
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797304 /*0x493378*/;
    cpu.esp -= 4;
    // 00425069  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042506a  e8891d0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042506f  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00425073  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425074  e897fbffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00425079  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042507c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042507d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042507e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042507f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425080  81c48c030000           -add esp, 0x38c
    (cpu.esp) += x86::reg32(x86::sreg32(908 /*0x38c*/));
    // 00425086  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425087:
    // 00425087  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00425088:
    // 00425088  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042508c  6878334900             -push 0x493378
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797304 /*0x493378*/;
    cpu.esp -= 4;
    // 00425091  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425092  e8611d0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00425097  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042509b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042509c  e86ffbffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004250a1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004250a4:
    // 004250a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004250a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004250a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004250a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004250a8  81c48c030000           -add esp, 0x38c
    (cpu.esp) += x86::reg32(x86::sreg32(908 /*0x38c*/));
    // 004250ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4250b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004250b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004250b1  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004250b3  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004250b5  2bf0                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004250b7:
    // 004250b7  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004250b9  880c06                 -mov byte ptr [esi + eax], cl
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.cl;
    // 004250bc  40                     -inc eax
    (cpu.eax)++;
    // 004250bd  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004250bf  75f6                   -jne 0x4250b7
    if (!cpu.flags.zf)
    {
        goto L_0x004250b7;
    }
    // 004250c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004250c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4250d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004250d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004250d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004250d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004250d3  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004250d5  e8b6d80000             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 004250da  83f801                 +cmp eax, 1
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
    // 004250dd  7c24                   -jl 0x425103
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00425103;
    }
    // 004250df  3b052c845100           +cmp eax, dword ptr [0x51842c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004250e5  7d1c                   -jge 0x425103
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00425103;
    }
    // 004250e7  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004250ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004250ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004250ef  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004250f2  8a8aa8020000           -mov cl, byte ptr [edx + 0x2a8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(680) /* 0x2a8 */);
    // 004250f8  80e101                 -and cl, 1
    cpu.cl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004250fb  f6d9                   +neg cl
    {
        x86::reg8 tmp1 = 0;
        x86::reg8& tmp2 = cpu.cl;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004250fd  1bc9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004250ff  23c1                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00425101  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425102  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425103:
    // 00425103  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 00425108  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042510a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042510c  755a                   -jne 0x425168
    if (!cpu.flags.zf)
    {
        goto L_0x00425168;
    }
    // 0042510e  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00425112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425113  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00425115  e85629feff             -call 0x407a70
    cpu.esp -= 4;
    sub_407a70(app, cpu);
    // 0042511a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042511c  747f                   -je 0x42519d
    if (cpu.flags.zf)
    {
        goto L_0x0042519d;
    }
    // 0042511e  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00425122  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00425124  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00425126  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425127  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00425129  7e29                   -jle 0x425154
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00425154;
    }
L_0x0042512b:
    // 0042512b  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0042512e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00425130  7410                   -je 0x425142
    if (cpu.flags.zf)
    {
        goto L_0x00425142;
    }
    // 00425132  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00425134  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00425136  740a                   -je 0x425142
    if (cpu.flags.zf)
    {
        goto L_0x00425142;
    }
    // 00425138  8b9980020000           -mov ebx, dword ptr [ecx + 0x280]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */);
    // 0042513e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00425140  7507                   -jne 0x425149
    if (!cpu.flags.zf)
    {
        goto L_0x00425149;
    }
L_0x00425142:
    // 00425142  42                     -inc edx
    (cpu.edx)++;
    // 00425143  3bd7                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425145  7ce4                   -jl 0x42512b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042512b;
    }
    // 00425147  eb0b                   -jmp 0x425154
    goto L_0x00425154;
L_0x00425149:
    // 00425149  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0042514c  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042514e  8bb280000000           -mov esi, dword ptr [edx + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
L_0x00425154:
    // 00425154  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425155  e85a220500             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042515a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042515d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042515f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425160  743b                   -je 0x42519d
    if (cpu.flags.zf)
    {
        goto L_0x0042519d;
    }
    // 00425162  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00425164  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425165  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425166  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425167  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425168:
    // 00425168  e813a60300             -call 0x45f780
    cpu.esp -= 4;
    sub_45f780(app, cpu);
    // 0042516d  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042516f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00425171  83faff                 +cmp edx, -1
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
    // 00425174  7427                   -je 0x42519d
    if (cpu.flags.zf)
    {
        goto L_0x0042519d;
    }
    // 00425176  8b3d2c845100           -mov edi, dword ptr [0x51842c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 0042517c  8b3530845100           -mov esi, dword ptr [0x518430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
L_0x00425182:
    // 00425182  3bc7                   +cmp eax, edi
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
    // 00425184  7d17                   -jge 0x42519d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042519d;
    }
    // 00425186  8b0c86                 -mov ecx, dword ptr [esi + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 00425189  f681a802000001         +test byte ptr [ecx + 0x2a8], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) & 1 /*0x1*/));
    // 00425190  7408                   -je 0x42519a
    if (cpu.flags.zf)
    {
        goto L_0x0042519a;
    }
    // 00425192  3991b4020000           +cmp dword ptr [ecx + 0x2b4], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425198  7405                   -je 0x42519f
    if (cpu.flags.zf)
    {
        goto L_0x0042519f;
    }
L_0x0042519a:
    // 0042519a  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042519b  ebe5                   -jmp 0x425182
    goto L_0x00425182;
L_0x0042519d:
    // 0042519d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042519f:
    // 0042519f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004251a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004251a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004251a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4251b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004251b0  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 004251b5  81ec00030000           -sub esp, 0x300
    (cpu.esp) -= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 004251bb  8d8c2480000000         -lea ecx, [esp + 0x80]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004251c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004251c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004251c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004251c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004251c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004251c7  6838364900             -push 0x493638
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798008 /*0x493638*/;
    cpu.esp -= 4;
    // 004251cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004251cd  e8261c0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004251d2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004251d5  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 004251da  8d8c2490000000         -lea ecx, [esp + 0x90]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004251e1  e85a780200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 004251e6  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004251e8  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004251ea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004251ec  0f84d1020000           -je 0x4254c3
    if (cpu.flags.zf)
    {
        goto L_0x004254c3;
    }
    // 004251f2  f6470c10               +test byte ptr [edi + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 004251f6  0f85c7020000           -jne 0x4254c3
    if (!cpu.flags.zf)
    {
        goto L_0x004254c3;
    }
    // 004251fc  b320                   -mov bl, 0x20
    cpu.bl = 32 /*0x20*/;
L_0x004251fe:
    // 004251fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004251ff  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00425206  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 0042520b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042520c  e8c7260500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00425211  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425214  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425216  0f84a7020000           -je 0x4254c3
    if (cpu.flags.zf)
    {
        goto L_0x004254c3;
    }
    // 0042521c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042521d  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00425221  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00425226  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425227  e8ac260500             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 0042522c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042522f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425231  0f848c020000           -je 0x4254c3
    if (cpu.flags.zf)
    {
        goto L_0x004254c3;
    }
    // 00425237  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042523b  8d942415010000         -lea edx, [esp + 0x115]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(277) /* 0x115 */);
    // 00425242  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425243  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425244  681c364900             -push 0x49361c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797980 /*0x49361c*/;
    cpu.esp -= 4;
    // 00425249  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042524c  e8661b0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00425251  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00425253  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0042525a  68a0334900             -push 0x4933a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797344 /*0x4933a0*/;
    cpu.esp -= 4;
    // 0042525f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425260  e8cb4c0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425265  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00425268  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042526a  740d                   -je 0x425279
    if (cpu.flags.zf)
    {
        goto L_0x00425279;
    }
    // 0042526c  6888354900             -push 0x493588
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797832 /*0x493588*/;
    cpu.esp -= 4;
    // 00425271  e89af9ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00425276  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00425279:
    // 00425279  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0042527b  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042527f  687c354900             -push 0x49357c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797820 /*0x49357c*/;
    cpu.esp -= 4;
    // 00425284  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425285  e8a64c0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0042528a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042528d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042528f  740d                   -je 0x42529e
    if (cpu.flags.zf)
    {
        goto L_0x0042529e;
    }
    // 00425291  68e8344900             -push 0x4934e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797672 /*0x4934e8*/;
    cpu.esp -= 4;
    // 00425296  e875f9ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042529b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042529e:
    // 0042529e  8a8c2415010000         -mov cl, byte ptr [esp + 0x115]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(277) /* 0x115 */);
    // 004252a5  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004252aa  3acb                   +cmp cl, bl
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
    // 004252ac  760c                   -jbe 0x4252ba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004252ba;
    }
L_0x004252ae:
    // 004252ae  8a8c0411010000         -mov cl, byte ptr [esp + eax + 0x111]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(273) /* 0x111 */ + cpu.eax * 1);
    // 004252b5  40                     -inc eax
    (cpu.eax)++;
    // 004252b6  3acb                   +cmp cl, bl
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
    // 004252b8  77f4                   -ja 0x4252ae
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004252ae;
    }
L_0x004252ba:
    // 004252ba  c684041001000000       -mov byte ptr [esp + eax + 0x110], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(272) /* 0x110 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 004252c2  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004252c6  8d842415010000         -lea eax, [esp + 0x115]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(277) /* 0x115 */);
    // 004252cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004252ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004252cf  68c8344900             -push 0x4934c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797640 /*0x4934c8*/;
    cpu.esp -= 4;
    // 004252d4  e8de1a0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004252d9  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004252db  8d4c2425               -lea ecx, [esp + 0x25]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(37) /* 0x25 */);
    // 004252df  68c0344900             -push 0x4934c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797632 /*0x4934c0*/;
    cpu.esp -= 4;
    // 004252e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004252e5  83ceff                 -or esi, 0xffffffff
    cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004252e8  e8434c0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 004252ed  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004252f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004252f2  7502                   -jne 0x4252f6
    if (!cpu.flags.zf)
    {
        goto L_0x004252f6;
    }
    // 004252f4  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004252f6:
    // 004252f6  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004252f8  8d542419               -lea edx, [esp + 0x19]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 004252fc  68b4344900             -push 0x4934b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797620 /*0x4934b4*/;
    cpu.esp -= 4;
    // 00425301  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425302  e8294c0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425307  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042530a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042530c  7505                   -jne 0x425313
    if (!cpu.flags.zf)
    {
        goto L_0x00425313;
    }
    // 0042530e  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00425313:
    // 00425313  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00425315  8d442419               -lea eax, [esp + 0x19]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00425319  68a4344900             -push 0x4934a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797604 /*0x4934a4*/;
    cpu.esp -= 4;
    // 0042531e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042531f  e80c4c0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425324  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425327  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425329  7505                   -jne 0x425330
    if (!cpu.flags.zf)
    {
        goto L_0x00425330;
    }
    // 0042532b  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00425330:
    // 00425330  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00425332  8d4c2419               -lea ecx, [esp + 0x19]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00425336  6898344900             -push 0x493498
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797592 /*0x493498*/;
    cpu.esp -= 4;
    // 0042533b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042533c  e8ef4b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425341  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425344  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425346  7505                   -jne 0x42534d
    if (!cpu.flags.zf)
    {
        goto L_0x0042534d;
    }
    // 00425348  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
L_0x0042534d:
    // 0042534d  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 0042534f  8d542419               -lea edx, [esp + 0x19]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00425353  6888344900             -push 0x493488
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797576 /*0x493488*/;
    cpu.esp -= 4;
    // 00425358  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425359  e8d24b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0042535e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425361  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425363  7505                   -jne 0x42536a
    if (!cpu.flags.zf)
    {
        goto L_0x0042536a;
    }
    // 00425365  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
L_0x0042536a:
    // 0042536a  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042536c  8d442419               -lea eax, [esp + 0x19]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00425370  687c344900             -push 0x49347c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797564 /*0x49347c*/;
    cpu.esp -= 4;
    // 00425375  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425376  e8b54b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0042537b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042537e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425380  7505                   -jne 0x425387
    if (!cpu.flags.zf)
    {
        goto L_0x00425387;
    }
    // 00425382  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
L_0x00425387:
    // 00425387  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 00425389  8d4c2419               -lea ecx, [esp + 0x19]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 0042538d  6870344900             -push 0x493470
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797552 /*0x493470*/;
    cpu.esp -= 4;
    // 00425392  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425393  e8984b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425398  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042539b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042539d  7505                   -jne 0x4253a4
    if (!cpu.flags.zf)
    {
        goto L_0x004253a4;
    }
    // 0042539f  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
L_0x004253a4:
    // 004253a4  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004253a6  8d542419               -lea edx, [esp + 0x19]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 004253aa  6864344900             -push 0x493464
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797540 /*0x493464*/;
    cpu.esp -= 4;
    // 004253af  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004253b0  e87b4b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 004253b5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004253b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004253ba  7505                   -jne 0x4253c1
    if (!cpu.flags.zf)
    {
        goto L_0x004253c1;
    }
    // 004253bc  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
L_0x004253c1:
    // 004253c1  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004253c3  8d442419               -lea eax, [esp + 0x19]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 004253c7  6858344900             -push 0x493458
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797528 /*0x493458*/;
    cpu.esp -= 4;
    // 004253cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004253cd  e85e4b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 004253d2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004253d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004253d7  7505                   -jne 0x4253de
    if (!cpu.flags.zf)
    {
        goto L_0x004253de;
    }
    // 004253d9  be0e000000             -mov esi, 0xe
    cpu.esi = 14 /*0xe*/;
L_0x004253de:
    // 004253de  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004253e0  8d4c2419               -lea ecx, [esp + 0x19]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 004253e4  6844344900             -push 0x493444
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797508 /*0x493444*/;
    cpu.esp -= 4;
    // 004253e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004253ea  e8414b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 004253ef  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004253f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004253f4  7505                   -jne 0x4253fb
    if (!cpu.flags.zf)
    {
        goto L_0x004253fb;
    }
    // 004253f6  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
L_0x004253fb:
    // 004253fb  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004253fd  8d542419               -lea edx, [esp + 0x19]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00425401  683c344900             -push 0x49343c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797500 /*0x49343c*/;
    cpu.esp -= 4;
    // 00425406  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425407  e8244b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0042540c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042540f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425411  7505                   -jne 0x425418
    if (!cpu.flags.zf)
    {
        goto L_0x00425418;
    }
    // 00425413  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
L_0x00425418:
    // 00425418  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042541a  8d442419               -lea eax, [esp + 0x19]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 0042541e  6830344900             -push 0x493430
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797488 /*0x493430*/;
    cpu.esp -= 4;
    // 00425423  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425424  e8074b0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425429  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042542c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042542e  7505                   -jne 0x425435
    if (!cpu.flags.zf)
    {
        goto L_0x00425435;
    }
    // 00425430  be11000000             -mov esi, 0x11
    cpu.esi = 17 /*0x11*/;
L_0x00425435:
    // 00425435  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00425437  8d4c2419               -lea ecx, [esp + 0x19]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 0042543b  6828344900             -push 0x493428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797480 /*0x493428*/;
    cpu.esp -= 4;
    // 00425440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425441  e8ea4a0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425446  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425449  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042544b  7505                   -jne 0x425452
    if (!cpu.flags.zf)
    {
        goto L_0x00425452;
    }
    // 0042544d  be12000000             -mov esi, 0x12
    cpu.esi = 18 /*0x12*/;
L_0x00425452:
    // 00425452  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00425454  8d542419               -lea edx, [esp + 0x19]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00425458  681c344900             -push 0x49341c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797468 /*0x49341c*/;
    cpu.esp -= 4;
    // 0042545d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042545e  e8cd4a0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425463  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425466  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425468  7505                   -jne 0x42546f
    if (!cpu.flags.zf)
    {
        goto L_0x0042546f;
    }
    // 0042546a  be13000000             -mov esi, 0x13
    cpu.esi = 19 /*0x13*/;
L_0x0042546f:
    // 0042546f  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00425471  8d442419               -lea eax, [esp + 0x19]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00425475  6810344900             -push 0x493410
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797456 /*0x493410*/;
    cpu.esp -= 4;
    // 0042547a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042547b  e8b04a0500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00425480  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425483  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425485  7507                   -jne 0x42548e
    if (!cpu.flags.zf)
    {
        goto L_0x0042548e;
    }
    // 00425487  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 0042548c  eb13                   -jmp 0x4254a1
    goto L_0x004254a1;
L_0x0042548e:
    // 0042548e  83feff                 +cmp esi, -1
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
    // 00425491  750e                   -jne 0x4254a1
    if (!cpu.flags.zf)
    {
        goto L_0x004254a1;
    }
    // 00425493  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425494  68e0334900             -push 0x4933e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797408 /*0x4933e0*/;
    cpu.esp -= 4;
    // 00425499  e872f7ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042549e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004254a1:
    // 004254a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004254a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004254a4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004254a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004254a8  8d942425010000         -lea edx, [esp + 0x125]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(293) /* 0x125 */);
    // 004254af  b94cbb4a00             -mov ecx, 0x4abb4c
    cpu.ecx = 4897612 /*0x4abb4c*/;
    // 004254b4  e8c7f7ffff             -call 0x424c80
    cpu.esp -= 4;
    sub_424c80(app, cpu);
    // 004254b9  f6470c10               +test byte ptr [edi + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 004254bd  0f843bfdffff           -je 0x4251fe
    if (cpu.flags.zf)
    {
        goto L_0x004251fe;
    }
L_0x004254c3:
    // 004254c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004254c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004254c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004254c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004254c7  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 004254cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46d010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0046d010;
L_0x004254d0:
    // 004254d0  83f901                 +cmp ecx, 1
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
    // 004254d3  7c30                   -jl 0x425505
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00425505;
    }
    // 004254d5  83f90a                 +cmp ecx, 0xa
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
    // 004254d8  7f2b                   -jg 0x425505
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00425505;
    }
    // 004254da  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004254dc  7419                   -je 0x4254f7
    if (cpu.flags.zf)
    {
        goto L_0x004254f7;
    }
    // 004254de  83f901                 +cmp ecx, 1
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
    // 004254e1  7e14                   -jle 0x4254f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004254f7;
    }
    // 004254e3  b8f0135200             -mov eax, 0x5213f0
    cpu.eax = 5379056 /*0x5213f0*/;
    // 004254e8  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
L_0x004254eb:
    // 004254eb  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 004254f1  83c014                 +add eax, 0x14
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
    // 004254f4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004254f5  75f4                   -jne 0x4254eb
    if (!cpu.flags.zf)
    {
        goto L_0x004254eb;
    }
L_0x004254f7:
    // 004254f7  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 004254fa  c70485dc13520001000000 -mov dword ptr [eax*4 + 0x5213dc], 1
    app->getMemory<x86::reg32>(x86::reg32(5379036) /* 0x5213dc */ + cpu.eax * 4) = 1 /*0x1*/;
L_0x00425505:
    // 00425505  c3                     -ret 
    cpu.esp += 4;
    return;
L_entry_0x0046d010:
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
    __ftol(app, cpu);
    // 0046d01e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d020  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d022  e85996ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046d027  e8649d0000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
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
    goto L_0x004254d0;
}

/* align: skip  */
void Application::sub_425510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425510  b8f0135200             -mov eax, 0x5213f0
    cpu.eax = 5379056 /*0x5213f0*/;
L_0x00425515:
    // 00425515  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0042551b  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042551e  3db8145200             +cmp eax, 0x5214b8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5379256 /*0x5214b8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425523  7cf0                   -jl 0x425515
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00425515;
    }
    // 00425525  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425530  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425531  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00425533  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00425536  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00425539  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 0042553e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042553f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425540  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425541  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00425546  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425547  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425548  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042554c  6830374900             -push 0x493730
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798256 /*0x493730*/;
    cpu.esp -= 4;
    // 00425551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425552  e8a1180500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00425557  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042555a  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0042555f  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00425563  e8d8740200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00425568  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042556a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042556c  0f849e000000           -je 0x425610
    if (cpu.flags.zf)
    {
        goto L_0x00425610;
    }
    // 00425572  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425573  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00425575  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00425577  68f0284900             -push 0x4928f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794608 /*0x4928f0*/;
    cpu.esp -= 4;
    // 0042557c  e807210500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00425581  6824374900             -push 0x493724
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798244 /*0x493724*/;
    cpu.esp -= 4;
    // 00425586  e82c180500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042558b  d905f8284900           -fld dword ptr [0x4928f8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794616) /* 0x4928f8 */)));
    // 00425591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425592  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00425596  d905f4284900           -fld dword ptr [0x4928f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794612) /* 0x4928f4 */)));
    // 0042559c  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004255a0  d905f0284900           -fld dword ptr [0x4928f0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794608) /* 0x4928f0 */)));
    // 004255a6  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004255a9  6810374900             -push 0x493710
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798224 /*0x493710*/;
    cpu.esp -= 4;
    // 004255ae  e804180500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004255b3  d90504294900           -fld dword ptr [0x492904]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794628) /* 0x492904 */)));
    // 004255b9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004255bc  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004255c0  d90500294900           -fld dword ptr [0x492900]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794624) /* 0x492900 */)));
    // 004255c6  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004255ca  d905fc284900           -fld dword ptr [0x4928fc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794620) /* 0x4928fc */)));
    // 004255d0  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004255d3  6810374900             -push 0x493710
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798224 /*0x493710*/;
    cpu.esp -= 4;
    // 004255d8  e8da170500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004255dd  d90510294900           -fld dword ptr [0x492910]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794640) /* 0x492910 */)));
    // 004255e3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004255e6  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004255ea  d9050c294900           -fld dword ptr [0x49290c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794636) /* 0x49290c */)));
    // 004255f0  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004255f4  d90508294900           -fld dword ptr [0x492908]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794632) /* 0x492908 */)));
    // 004255fa  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004255fd  6810374900             -push 0x493710
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798224 /*0x493710*/;
    cpu.esp -= 4;
    // 00425602  e8b0170500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00425607  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425608  e8ca1f0500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0042560d  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00425610:
    // 00425610  6800374900             -push 0x493700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798208 /*0x493700*/;
    cpu.esp -= 4;
    // 00425615  e89d170500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042561a  8b1510155200           -mov edx, dword ptr [0x521510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 00425620  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00425624  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042562a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042562b  68ec364900             -push 0x4936ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798188 /*0x4936ec*/;
    cpu.esp -= 4;
    // 00425630  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425631  e8c2170500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00425636  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00425639  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0042563e  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00425642  e8f9730200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00425647  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425649  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0042564d  0f84cd000000           -je 0x425720
    if (cpu.flags.zf)
    {
        goto L_0x00425720;
    }
    // 00425653  68382c4900             -push 0x492c38
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795448 /*0x492c38*/;
    cpu.esp -= 4;
    // 00425658  68e8364900             -push 0x4936e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798184 /*0x4936e8*/;
    cpu.esp -= 4;
    // 0042565d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042565e  e8d7220500             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 00425663  8b0d382c4900           -mov ecx, dword ptr [0x492c38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4795448) /* 0x492c38 */);
    // 00425669  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042566a  68d8364900             -push 0x4936d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798168 /*0x4936d8*/;
    cpu.esp -= 4;
    // 0042566f  e843170500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00425674  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00425677  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00425679  bee0135200             -mov esi, 0x5213e0
    cpu.esi = 5379040 /*0x5213e0*/;
L_0x0042567e:
    // 0042567e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00425682  8d6e0c                 -lea ebp, [esi + 0xc]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00425685  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00425688  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042568b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042568c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042568d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042568e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042568f  68c8364900             -push 0x4936c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798152 /*0x4936c8*/;
    cpu.esp -= 4;
    // 00425694  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425695  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0042569b  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 004256a2  e893220500             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 004256a7  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004256aa  83f804                 +cmp eax, 4
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
    // 004256ad  7556                   -jne 0x425705
    if (!cpu.flags.zf)
    {
        goto L_0x00425705;
    }
    // 004256af  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004256b1  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004256b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004256b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004256ba  68b4364900             -push 0x4936b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798132 /*0x4936b4*/;
    cpu.esp -= 4;
    // 004256bf  e8f3160500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004256c4  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004256c7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004256c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004256c9  68a0364900             -push 0x4936a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798112 /*0x4936a0*/;
    cpu.esp -= 4;
    // 004256ce  e8e4160500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004256d3  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004256d5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004256d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004256d7  688c364900             -push 0x49368c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798092 /*0x49368c*/;
    cpu.esp -= 4;
    // 004256dc  e8d6160500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004256e1  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004256e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004256e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004256e6  6878364900             -push 0x493678
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798072 /*0x493678*/;
    cpu.esp -= 4;
    // 004256eb  e8c7160500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004256f0  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004256f3  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004256f6  47                     -inc edi
    (cpu.edi)++;
    // 004256f7  81fea8145200           +cmp esi, 0x5214a8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5379240 /*0x5214a8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004256fd  0f8c7bffffff           -jl 0x42567e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042567e;
    }
    // 00425703  eb0e                   -jmp 0x425713
    goto L_0x00425713;
L_0x00425705:
    // 00425705  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425706  684c364900             -push 0x49364c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798028 /*0x49364c*/;
    cpu.esp -= 4;
    // 0042570b  e8a7160500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00425710  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00425713:
    // 00425713  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00425717  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425718  e8ba1e0500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0042571d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00425720:
    // 00425720  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425721  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425722  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425723  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425724  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00425726  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425727  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425730  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00425732  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425734  0f848f000000           -je 0x4257c9
    if (cpu.flags.zf)
    {
        goto L_0x004257c9;
    }
    // 0042573a  833dc0f3510001         +cmp dword ptr [0x51f3c0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425741  7532                   -jne 0x425775
    if (!cpu.flags.zf)
    {
        goto L_0x00425775;
    }
    // 00425743  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00425749  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042574a  8b35c4e54900           -mov esi, dword ptr [0x49e5c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 00425750  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00425753  8b3530845100           -mov esi, dword ptr [0x518430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00425759  8b8980000000           -mov ecx, dword ptr [ecx + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0042575f  8b0c8e                 -mov ecx, dword ptr [esi + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4);
    // 00425762  8bb1a8020000           -mov esi, dword ptr [ecx + 0x2a8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 00425768  81ce00000008           -or esi, 0x8000000
    cpu.esi |= x86::reg32(x86::sreg32(134217728 /*0x8000000*/));
    // 0042576e  89b1a8020000           -mov dword ptr [ecx + 0x2a8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.esi;
    // 00425774  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00425775:
    // 00425775  8b0d14d24900           -mov ecx, dword ptr [0x49d214]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4837908) /* 0x49d214 */);
    // 0042577b  890dd8284900           -mov dword ptr [0x4928d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(4794584) /* 0x4928d8 */) = cpu.ecx;
    // 00425781  8b0de4284900           -mov ecx, dword ptr [0x4928e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4794596) /* 0x4928e4 */);
    // 00425787  890d14d24900           -mov dword ptr [0x49d214], ecx
    app->getMemory<x86::reg32>(x86::reg32(4837908) /* 0x49d214 */) = cpu.ecx;
    // 0042578d  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00425793  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00425795  ba60135200             -mov edx, 0x521360
    cpu.edx = 5378912 /*0x521360*/;
    // 0042579a  890da0d34a00           -mov dword ptr [0x4ad3a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */) = cpu.ecx;
    // 004257a0  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004257a2:
    // 004257a2  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004257a4  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 004257a7  40                     -inc eax
    (cpu.eax)++;
    // 004257a8  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004257aa  75f6                   -jne 0x4257a2
    if (!cpu.flags.zf)
    {
        goto L_0x004257a2;
    }
    // 004257ac  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004257b0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004257b4  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004257b8  891544135200           -mov dword ptr [0x521344], edx
    app->getMemory<x86::reg32>(x86::reg32(5378884) /* 0x521344 */) = cpu.edx;
    // 004257be  a34c135200             -mov dword ptr [0x52134c], eax
    app->getMemory<x86::reg32>(x86::reg32(5378892) /* 0x52134c */) = cpu.eax;
    // 004257c3  890d48135200           -mov dword ptr [0x521348], ecx
    app->getMemory<x86::reg32>(x86::reg32(5378888) /* 0x521348 */) = cpu.ecx;
L_0x004257c9:
    // 004257c9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4257d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004257d0  8b0da0d34a00           -mov ecx, dword ptr [0x4ad3a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */);
    // 004257d6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004257d8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004257da  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004257dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4257e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004257e0  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004257e5  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004257e8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004257ea  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004257ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004257f0  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 004257f6  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004257f9  e852a60000             -call 0x42fe50
    cpu.esp -= 4;
    sub_42fe50(app, cpu);
    // 004257fe  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00425804  a1a0d34a00             -mov eax, dword ptr [0x4ad3a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */);
    // 00425809  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042580b  3bc8                   +cmp ecx, eax
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
    // 0042580d  a1dcd34a00             -mov eax, dword ptr [0x4ad3dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903900) /* 0x4ad3dc */);
    // 00425812  0f8d21010000           -jge 0x425939
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00425939;
    }
    // 00425818  3bc6                   +cmp eax, esi
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
    // 0042581a  7537                   -jne 0x425853
    if (!cpu.flags.zf)
    {
        goto L_0x00425853;
    }
    // 0042581c  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00425821  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00425823  8b8ad0000000           -mov ecx, dword ptr [edx + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 00425829  890d4cd34a00           -mov dword ptr [0x4ad34c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903756) /* 0x4ad34c */) = cpu.ecx;
    // 0042582f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00425831  8b8ad4000000           -mov ecx, dword ptr [edx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 00425837  890d50d34a00           -mov dword ptr [0x4ad350], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903760) /* 0x4ad350 */) = cpu.ecx;
    // 0042583d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042583f  8b8ad8000000           -mov ecx, dword ptr [edx + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 00425845  890d54d34a00           -mov dword ptr [0x4ad354], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903764) /* 0x4ad354 */) = cpu.ecx;
    // 0042584b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042584d  89b2c8020000           -mov dword ptr [edx + 0x2c8], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(712) /* 0x2c8 */) = cpu.esi;
L_0x00425853:
    // 00425853  b960135200             -mov ecx, 0x521360
    cpu.ecx = 5378912 /*0x521360*/;
    // 00425858  e873f8ffff             -call 0x4250d0
    cpu.esp -= 4;
    sub_4250d0(app, cpu);
    // 0042585d  83f801                 +cmp eax, 1
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
    // 00425860  0f8cbe000000           -jl 0x425924
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00425924;
    }
    // 00425866  3b052c845100           +cmp eax, dword ptr [0x51842c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042586c  0f8db2000000           -jge 0x425924
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00425924;
    }
    // 00425872  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00425878  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0042587b  3bce                   +cmp ecx, esi
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
    // 0042587d  0f84a7000000           -je 0x42592a
    if (cpu.flags.zf)
    {
        goto L_0x0042592a;
    }
    // 00425883  d90548135200           -fld dword ptr [0x521348]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5378888) /* 0x521348 */)));
    // 00425889  d9ff                   -fcos 
    cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));
    // 0042588b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042588c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042588d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042588e  d9054c135200           -fld dword ptr [0x52134c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5378892) /* 0x52134c */)));
    // 00425894  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 00425896  d80d44135200           -fmul dword ptr [0x521344]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5378884) /* 0x521344 */));
    // 0042589c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0042589e  d90548135200           -fld dword ptr [0x521348]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5378888) /* 0x521348 */)));
    // 004258a4  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 004258a6  d80d44135200           -fmul dword ptr [0x521344]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5378884) /* 0x521344 */));
    // 004258ac  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004258b0  d9054c135200           -fld dword ptr [0x52134c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5378892) /* 0x52134c */)));
    // 004258b6  d9ff                   -fcos 
    cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));
    // 004258b8  d80d44135200           -fmul dword ptr [0x521344]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5378884) /* 0x521344 */));
    // 004258be  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004258c0  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004258c2  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004258c6  d881d0000000           -fadd dword ptr [ecx + 0xd0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */));
    // 004258cc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004258ce  d999d0000000           -fstp dword ptr [ecx + 0xd0]
    app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004258d4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004258da  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004258dc  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004258df  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004258e1  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004258e5  d882d4000000           -fadd dword ptr [edx + 0xd4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(212) /* 0xd4 */));
    // 004258eb  d999d4000000           -fstp dword ptr [ecx + 0xd4]
    app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004258f1  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004258f7  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004258fb  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004258fe  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00425900  d882d8000000           -fadd dword ptr [edx + 0xd8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(216) /* 0xd8 */));
    // 00425906  32d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00425908  d999d8000000           -fstp dword ptr [ecx + 0xd8]
    app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042590e  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00425910  e8ab6a0300             -call 0x45c3c0
    cpu.esp -= 4;
    sub_45c3c0(app, cpu);
    // 00425915  c705dcd34a0001000000   -mov dword ptr [0x4ad3dc], 1
    app->getMemory<x86::reg32>(x86::reg32(4903900) /* 0x4ad3dc */) = 1 /*0x1*/;
    // 0042591f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425920  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00425923  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425924:
    // 00425924  8935a0d34a00           -mov dword ptr [0x4ad3a0], esi
    app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */) = cpu.esi;
L_0x0042592a:
    // 0042592a  c705dcd34a0001000000   -mov dword ptr [0x4ad3dc], 1
    app->getMemory<x86::reg32>(x86::reg32(4903900) /* 0x4ad3dc */) = 1 /*0x1*/;
    // 00425934  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425935  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00425938  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425939:
    // 00425939  3bc6                   +cmp eax, esi
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
    // 0042593b  744a                   -je 0x425987
    if (cpu.flags.zf)
    {
        goto L_0x00425987;
    }
    // 0042593d  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00425943  8b0d4cd34a00           -mov ecx, dword ptr [0x4ad34c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903756) /* 0x4ad34c */);
    // 00425949  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042594b  8988d0000000           -mov dword ptr [eax + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 00425951  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00425957  8b0d50d34a00           -mov ecx, dword ptr [0x4ad350]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903760) /* 0x4ad350 */);
    // 0042595d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042595f  8988d4000000           -mov dword ptr [eax + 0xd4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */) = cpu.ecx;
    // 00425965  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042596b  8b0d54d34a00           -mov ecx, dword ptr [0x4ad354]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903764) /* 0x4ad354 */);
    // 00425971  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00425973  8988d8000000           -mov dword ptr [eax + 0xd8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(216) /* 0xd8 */) = cpu.ecx;
    // 00425979  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042597f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00425981  89b0c8020000           -mov dword ptr [eax + 0x2c8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */) = cpu.esi;
L_0x00425987:
    // 00425987  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0042598c  8935dcd34a00           -mov dword ptr [0x4ad3dc], esi
    app->getMemory<x86::reg32>(x86::reg32(4903900) /* 0x4ad3dc */) = cpu.esi;
    // 00425992  83f801                 +cmp eax, 1
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
    // 00425995  7528                   -jne 0x4259bf
    if (!cpu.flags.zf)
    {
        goto L_0x004259bf;
    }
    // 00425997  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0042599d  8b15c4e54900           -mov edx, dword ptr [0x49e5c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004259a3  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 004259a6  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004259ac  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004259b2  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 004259b5  81a0a8020000fffffff7   -and dword ptr [eax + 0x2a8], 0xf7ffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) &= x86::reg32(x86::sreg32(4160749567 /*0xf7ffffff*/));
L_0x004259bf:
    // 004259bf  8935a0d34a00           -mov dword ptr [0x4ad3a0], esi
    app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */) = cpu.esi;
    // 004259c5  893580c74a00           -mov dword ptr [0x4ac780], esi
    app->getMemory<x86::reg32>(x86::reg32(4900736) /* 0x4ac780 */) = cpu.esi;
    // 004259cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004259cc  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004259cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4259d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004259d0  c705a0d34a0000000000   -mov dword ptr [0x4ad3a0], 0
    app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */) = 0 /*0x0*/;
    // 004259da  e801feffff             -call 0x4257e0
    cpu.esp -= 4;
    sub_4257e0(app, cpu);
    // 004259df  833dc0f3510001         +cmp dword ptr [0x51f3c0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004259e6  7527                   -jne 0x425a0f
    if (!cpu.flags.zf)
    {
        goto L_0x00425a0f;
    }
    // 004259e8  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004259ed  8b0dc4e54900           -mov ecx, dword ptr [0x49e5c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004259f3  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004259f6  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004259fc  8b8280000000           -mov eax, dword ptr [edx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 00425a02  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00425a05  81a0a8020000fffffff7   -and dword ptr [eax + 0x2a8], 0xf7ffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) &= x86::reg32(x86::sreg32(4160749567 /*0xf7ffffff*/));
L_0x00425a0f:
    // 00425a0f  d905d8284900           -fld dword ptr [0x4928d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4794584) /* 0x4928d8 */)));
    // 00425a15  d81dec724800           -fcomp dword ptr [0x4872ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    cpu.fpu.pop();
    // 00425a1b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00425a1d  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00425a20  7b0c                   -jnp 0x425a2e
    if (!cpu.flags.pf)
    {
        goto L_0x00425a2e;
    }
    // 00425a22  8b15d8284900           -mov edx, dword ptr [0x4928d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4794584) /* 0x4928d8 */);
    // 00425a28  891514d24900           -mov dword ptr [0x49d214], edx
    app->getMemory<x86::reg32>(x86::reg32(4837908) /* 0x49d214 */) = cpu.edx;
L_0x00425a2e:
    // 00425a2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425a30  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425a33  a1402c4900             -mov eax, dword ptr [0x492c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4795456) /* 0x492c40 */);
    // 00425a38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425a39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425a3b  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00425a3d  c7442408ffffffff       -mov dword ptr [esp + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 00425a45  0f84d6000000           -je 0x425b21
    if (cpu.flags.zf)
    {
        goto L_0x00425b21;
    }
    // 00425a4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425a4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425a4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425a4e  bf402c4900             -mov edi, 0x492c40
    cpu.edi = 4795456 /*0x492c40*/;
    // 00425a53  8bef                   -mov ebp, edi
    cpu.ebp = cpu.edi;
L_0x00425a55:
    // 00425a55  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00425a57  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425a58  68f82c4900             -push 0x492cf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795640 /*0x492cf8*/;
    cpu.esp -= 4;
    // 00425a5d  e84ef10500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00425a62  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425a65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425a67  0f8499000000           -je 0x425b06
    if (cpu.flags.zf)
    {
        goto L_0x00425b06;
    }
    // 00425a6d  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00425a6f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425a71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425a72  e8b4300500             -call 0x478b2b
    cpu.esp -= 4;
    sub_478b2b(app, cpu);
    // 00425a77  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00425a79  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425a7c  83feff                 +cmp esi, -1
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
    // 00425a7f  7514                   -jne 0x425a95
    if (!cpu.flags.zf)
    {
        goto L_0x00425a95;
    }
    // 00425a81  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425a82  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425a84  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00425a88  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00425a8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425a8b  e80f1d0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00425a90  83c410                 +add esp, 0x10
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
    // 00425a93  eb71                   -jmp 0x425b06
    goto L_0x00425b06;
L_0x00425a95:
    // 00425a95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425a96  e806300500             -call 0x478aa1
    cpu.esp -= 4;
    sub_478aa1(app, cpu);
    // 00425a9b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00425a9e  83f8ff                 +cmp eax, -1
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
    // 00425aa1  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00425aa5  7512                   -jne 0x425ab9
    if (!cpu.flags.zf)
    {
        goto L_0x00425ab9;
    }
    // 00425aa7  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00425aa9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425aaa  6844374900             -push 0x493744
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798276 /*0x493744*/;
    cpu.esp -= 4;
    // 00425aaf  e85cf1ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00425ab4  83c408                 +add esp, 8
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
    // 00425ab7  eb4d                   -jmp 0x425b06
    goto L_0x00425b06;
L_0x00425ab9:
    // 00425ab9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425aba  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425abc  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00425ac0  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00425ac2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425ac3  e8d71c0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00425ac8  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00425acc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00425acf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425ad1  742a                   -je 0x425afd
    if (cpu.flags.zf)
    {
        goto L_0x00425afd;
    }
L_0x00425ad3:
    // 00425ad3  8d542413               -lea edx, [esp + 0x13]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(19) /* 0x13 */);
    // 00425ad7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425ad9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425ada  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425adb  e8832d0500             -call 0x478863
    cpu.esp -= 4;
    sub_478863(app, cpu);
    // 00425ae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425ae1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425ae3  8d442427               -lea eax, [esp + 0x27]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(39) /* 0x27 */);
    // 00425ae7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425ae9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425aea  e8b01c0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00425aef  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00425af3  83c41c                 +add esp, 0x1c
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
    // 00425af6  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00425af7  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00425afb  75d6                   -jne 0x425ad3
    if (!cpu.flags.zf)
    {
        goto L_0x00425ad3;
    }
L_0x00425afd:
    // 00425afd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425afe  e8802c0500             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 00425b03  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00425b06:
    // 00425b06  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00425b09  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00425b0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425b0e  c7442414ffffffff       -mov dword ptr [esp + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
    // 00425b16  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00425b18  0f8537ffffff           -jne 0x425a55
    if (!cpu.flags.zf)
    {
        goto L_0x00425a55;
    }
    // 00425b1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425b1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425b20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00425b21:
    // 00425b21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425b22  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425b25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425b30  a1402c4900             -mov eax, dword ptr [0x492c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4795456) /* 0x492c40 */);
    // 00425b35  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425b38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425b3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425b3b  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00425b3d  0f84af000000           -je 0x425bf2
    if (cpu.flags.zf)
    {
        goto L_0x00425bf2;
    }
    // 00425b43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00425b44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425b45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425b46  bf402c4900             -mov edi, 0x492c40
    cpu.edi = 4795456 /*0x492c40*/;
    // 00425b4b  8bef                   -mov ebp, edi
    cpu.ebp = cpu.edi;
L_0x00425b4d:
    // 00425b4d  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00425b4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425b50  68f82c4900             -push 0x492cf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795640 /*0x492cf8*/;
    cpu.esp -= 4;
    // 00425b55  e856f00500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00425b5a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425b5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425b5f  747e                   -je 0x425bdf
    if (cpu.flags.zf)
    {
        goto L_0x00425bdf;
    }
    // 00425b61  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425b62  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425b64  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00425b68  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00425b6a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425b6b  e8181b0500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00425b70  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00425b74  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00425b77  83f8ff                 +cmp eax, -1
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
    // 00425b7a  7463                   -je 0x425bdf
    if (cpu.flags.zf)
    {
        goto L_0x00425bdf;
    }
    // 00425b7c  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00425b7e  6824c74800             -push 0x48c724
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769572 /*0x48c724*/;
    cpu.esp -= 4;
    // 00425b83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425b84  e8d5200500             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 00425b89  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00425b8b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425b8e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00425b90  7510                   -jne 0x425ba2
    if (!cpu.flags.zf)
    {
        goto L_0x00425ba2;
    }
    // 00425b92  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00425b94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425b95  686c374900             -push 0x49376c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798316 /*0x49376c*/;
    cpu.esp -= 4;
    // 00425b9a  e871f0ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00425b9f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00425ba2:
    // 00425ba2  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00425ba6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425ba8  742c                   -je 0x425bd6
    if (cpu.flags.zf)
    {
        goto L_0x00425bd6;
    }
L_0x00425baa:
    // 00425baa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425bab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425bad  8d4c241b               -lea ecx, [esp + 0x1b]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(27) /* 0x1b */);
    // 00425bb1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425bb3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425bb4  e8cf1a0500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00425bb9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425bba  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425bbc  8d54242b               -lea edx, [esp + 0x2b]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(43) /* 0x2b */);
    // 00425bc0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00425bc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425bc3  e8d71b0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00425bc8  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00425bcc  83c420                 +add esp, 0x20
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
    // 00425bcf  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00425bd0  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00425bd4  75d4                   -jne 0x425baa
    if (!cpu.flags.zf)
    {
        goto L_0x00425baa;
    }
L_0x00425bd6:
    // 00425bd6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425bd7  e8fb190500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00425bdc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00425bdf:
    // 00425bdf  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00425be2  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00425be5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425be7  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00425be9  0f855effffff           -jne 0x425b4d
    if (!cpu.flags.zf)
    {
        goto L_0x00425b4d;
    }
    // 00425bef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425bf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425bf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00425bf2:
    // 00425bf2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425bf3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425bf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425c00  a1402c4900             -mov eax, dword ptr [0x492c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4795456) /* 0x492c40 */);
    // 00425c05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425c07  7438                   -je 0x425c41
    if (cpu.flags.zf)
    {
        goto L_0x00425c41;
    }
    // 00425c09  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425c0a  8b1db8704800           -mov ebx, dword ptr [0x4870b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747448) /* 0x4870b8 */);
    // 00425c10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425c11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425c12  bf402c4900             -mov edi, 0x492c40
    cpu.edi = 4795456 /*0x492c40*/;
    // 00425c17  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00425c19:
    // 00425c19  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00425c1b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425c1c  68f82c4900             -push 0x492cf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795640 /*0x492cf8*/;
    cpu.esp -= 4;
    // 00425c21  e88aef0500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00425c26  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425c29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425c2b  7405                   -je 0x425c32
    if (cpu.flags.zf)
    {
        goto L_0x00425c32;
    }
    // 00425c2d  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00425c2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425c30  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00425c32:
    // 00425c32  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00425c35  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00425c38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425c3a  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00425c3c  75db                   -jne 0x425c19
    if (!cpu.flags.zf)
    {
        goto L_0x00425c19;
    }
    // 00425c3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425c3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425c40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00425c41:
    // 00425c41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425c50  68a02d4900             -push 0x492da0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4795808 /*0x492da0*/;
    cpu.esp -= 4;
    // 00425c55  ff15b8704800           -call dword ptr [0x4870b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747448) /* 0x4870b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00425c5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425c60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425c61  dd0528d44a00           -fld qword ptr [0x4ad428]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4903976) /* 0x4ad428 */)));
    // 00425c67  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 00425c6d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00425c6e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425c6f  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00425c71  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00425c73  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00425c75  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00425c7a  751e                   -jne 0x425c9a
    if (!cpu.flags.zf)
    {
        goto L_0x00425c9a;
    }
    // 00425c7c  e8affa0300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00425c81  dc2528d44a00           -fsub qword ptr [0x4ad428]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4903976) /* 0x4ad428 */));
    // 00425c87  dc1d68734800           -fcomp qword ptr [0x487368]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)));
    cpu.fpu.pop();
    // 00425c8d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00425c8f  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00425c92  7a06                   -jp 0x425c9a
    if (cpu.flags.pf)
    {
        goto L_0x00425c9a;
    }
    // 00425c94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425c95  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00425c97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425c98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425c99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425c9a:
    // 00425c9a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00425c9c  7433                   -je 0x425cd1
    if (cpu.flags.zf)
    {
        goto L_0x00425cd1;
    }
    // 00425c9e  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00425ca4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00425ca5  e826baffff             -call 0x4216d0
    cpu.esp -= 4;
    sub_4216d0(app, cpu);
    // 00425caa  bf1c384900             -mov edi, 0x49381c
    cpu.edi = 4798492 /*0x49381c*/;
    // 00425caf  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 00425cb4  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00425cb6  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 00425cb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425cb9  7451                   -je 0x425d0c
    if (cpu.flags.zf)
    {
        goto L_0x00425d0c;
    }
    // 00425cbb  b910384900             -mov ecx, 0x493810
    cpu.ecx = 4798480 /*0x493810*/;
    // 00425cc0  e80bb90000             -call 0x4315d0
    cpu.esp -= 4;
    sub_4315d0(app, cpu);
    // 00425cc5  b904384900             -mov ecx, 0x493804
    cpu.ecx = 4798468 /*0x493804*/;
    // 00425cca  e801b90000             -call 0x4315d0
    cpu.esp -= 4;
    sub_4315d0(app, cpu);
    // 00425ccf  eb3b                   -jmp 0x425d0c
    goto L_0x00425d0c;
L_0x00425cd1:
    // 00425cd1  e8aa490300             -call 0x45a680
    cpu.esp -= 4;
    sub_45a680(app, cpu);
    // 00425cd6  e855e90300             -call 0x464630
    cpu.esp -= 4;
    sub_464630(app, cpu);
    // 00425cdb  e840c70300             -call 0x462420
    cpu.esp -= 4;
    sub_462420(app, cpu);
    // 00425ce0  e86b0c0000             -call 0x426950
    cpu.esp -= 4;
    sub_426950(app, cpu);
    // 00425ce5  a16c845100             -mov eax, dword ptr [0x51846c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342316) /* 0x51846c */);
    // 00425cea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425cec  7402                   -je 0x425cf0
    if (cpu.flags.zf)
    {
        goto L_0x00425cf0;
    }
    // 00425cee  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00425cf0:
    // 00425cf0  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00425cf6  e895b9ffff             -call 0x421690
    cpu.esp -= 4;
    sub_421690(app, cpu);
    // 00425cfb  813ddc28490080000000   +cmp dword ptr [0x4928dc], 0x80
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425d05  7d05                   -jge 0x425d0c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00425d0c;
    }
    // 00425d07  e8344a0300             -call 0x45a740
    cpu.esp -= 4;
    sub_45a740(app, cpu);
L_0x00425d0c:
    // 00425d0c  e8ffea0300             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00425d11  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00425d13  891d10d44a00           -mov dword ptr [0x4ad410], ebx
    app->getMemory<x86::reg32>(x86::reg32(4903952) /* 0x4ad410 */) = cpu.ebx;
    // 00425d19  e822020000             -call 0x425f40
    cpu.esp -= 4;
    sub_425f40(app, cpu);
    // 00425d1e  8b3510d44a00           -mov esi, dword ptr [0x4ad410]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4903952) /* 0x4ad410 */);
    // 00425d24  81fe67120000           +cmp esi, 0x1267
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4711 /*0x1267*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425d2a  7e0d                   -jle 0x425d39
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00425d39;
    }
    // 00425d2c  68ec374900             -push 0x4937ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798444 /*0x4937ec*/;
    cpu.esp -= 4;
    // 00425d31  e8daeeffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00425d36  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00425d39:
    // 00425d39  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00425d3b  0f8582000000           -jne 0x425dc3
    if (!cpu.flags.zf)
    {
        goto L_0x00425dc3;
    }
    // 00425d41  e86a490300             -call 0x45a6b0
    cpu.esp -= 4;
    sub_45a6b0(app, cpu);
    // 00425d46  e8c5ea0300             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00425d4b  e8e0f90300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00425d50  dd1d28d44a00           -fstp qword ptr [0x4ad428]
    app->getMemory<double>(x86::reg32(4903976) /* 0x4ad428 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00425d56  83fe01                 +cmp esi, 1
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
    // 00425d59  7468                   -je 0x425dc3
    if (cpu.flags.zf)
    {
        goto L_0x00425dc3;
    }
    // 00425d5b  a170845100             -mov eax, dword ptr [0x518470]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342320) /* 0x518470 */);
    // 00425d60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425d62  7402                   -je 0x425d66
    if (cpu.flags.zf)
    {
        goto L_0x00425d66;
    }
    // 00425d64  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00425d66:
    // 00425d66  e8c5f90300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00425d6b  dd1d28d44a00           -fstp qword ptr [0x4ad428]
    app->getMemory<double>(x86::reg32(4903976) /* 0x4ad428 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00425d71:
    // 00425d71  e87acd0300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00425d76  e895ea0300             -call 0x464810
    cpu.esp -= 4;
    sub_464810(app, cpu);
    // 00425d7b  e8b0f90300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00425d80  dc2528d44a00           -fsub qword ptr [0x4ad428]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4903976) /* 0x4ad428 */));
    // 00425d86  dc1d68734800           -fcomp qword ptr [0x487368]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)));
    cpu.fpu.pop();
    // 00425d8c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00425d8e  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00425d93  750d                   -jne 0x425da2
    if (!cpu.flags.zf)
    {
        goto L_0x00425da2;
    }
    // 00425d95  68d8374900             -push 0x4937d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798424 /*0x4937d8*/;
    cpu.esp -= 4;
    // 00425d9a  e871eeffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00425d9f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00425da2:
    // 00425da2  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00425da4  e837ce0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00425da9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425dab  75c4                   -jne 0x425d71
    if (!cpu.flags.zf)
    {
        goto L_0x00425d71;
    }
    // 00425dad  e87eceffff             -call 0x422c30
    cpu.esp -= 4;
    sub_422c30(app, cpu);
    // 00425db2  813ddc28490080000000   +cmp dword ptr [0x4928dc], 0x80
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425dbc  7d05                   -jge 0x425dc3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00425dc3;
    }
    // 00425dbe  e83d490300             -call 0x45a700
    cpu.esp -= 4;
    sub_45a700(app, cpu);
L_0x00425dc3:
    // 00425dc3  e868f90300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00425dc8  dd1d28d44a00           -fstp qword ptr [0x4ad428]
    app->getMemory<double>(x86::reg32(4903976) /* 0x4ad428 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00425dce  e85dceffff             -call 0x422c30
    cpu.esp -= 4;
    sub_422c30(app, cpu);
    // 00425dd3  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00425dd9  e8f2b8ffff             -call 0x4216d0
    cpu.esp -= 4;
    sub_4216d0(app, cpu);
    // 00425dde  83fe01                 +cmp esi, 1
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
    // 00425de1  0f84a3000000           -je 0x425e8a
    if (cpu.flags.zf)
    {
        goto L_0x00425e8a;
    }
    // 00425de7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00425de9  7407                   -je 0x425df2
    if (cpu.flags.zf)
    {
        goto L_0x00425df2;
    }
    // 00425deb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00425ded  e8ae060000             -call 0x4264a0
    cpu.esp -= 4;
    sub_4264a0(app, cpu);
L_0x00425df2:
    // 00425df2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00425df4  7505                   -jne 0x425dfb
    if (!cpu.flags.zf)
    {
        goto L_0x00425dfb;
    }
    // 00425df6  e8c50b0000             -call 0x4269c0
    cpu.esp -= 4;
    sub_4269c0(app, cpu);
L_0x00425dfb:
    // 00425dfb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00425dfd  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00425e00  a031165200             -mov al, byte ptr [0x521631]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379633) /* 0x521631 */);
    // 00425e05  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00425e09  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 00425e0d  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 00425e13  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00425e16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425e17  68b0374900             -push 0x4937b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798384 /*0x4937b0*/;
    cpu.esp -= 4;
    // 00425e1c  e8960f0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00425e21  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00425e23  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425e26  8a0d31165200           -mov cl, byte ptr [0x521631]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379633) /* 0x521631 */);
    // 00425e2c  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00425e30  8b0d04ef5100           -mov ecx, dword ptr [0x51ef04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00425e36  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00425e3a  d80db8784800           -fmul dword ptr [0x4878b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749496) /* 0x4878b8 */));
    // 00425e40  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00425e43  e858060400             -call 0x4664a0
    cpu.esp -= 4;
    sub_4664a0(app, cpu);
    // 00425e48  8b1530165200           -mov edx, dword ptr [0x521630]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379632) /* 0x521630 */);
    // 00425e4e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00425e54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425e55  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00425e59  8b0d04ef5100           -mov ecx, dword ptr [0x51ef04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00425e5f  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00425e63  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 00425e69  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00425e6c  e84f060400             -call 0x4664c0
    cpu.esp -= 4;
    sub_4664c0(app, cpu);
    // 00425e71  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 00425e76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425e78  751a                   -jne 0x425e94
    if (!cpu.flags.zf)
    {
        goto L_0x00425e94;
    }
    // 00425e7a  e8f1e90300             -call 0x464870
    cpu.esp -= 4;
    sub_464870(app, cpu);
    // 00425e7f  e83cf30300             -call 0x4651c0
    cpu.esp -= 4;
    sub_4651c0(app, cpu);
    // 00425e84  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00425e86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425e87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425e88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425e89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425e8a:
    // 00425e8a  b9a4374900             -mov ecx, 0x4937a4
    cpu.ecx = 4798372 /*0x4937a4*/;
    // 00425e8f  e83cb70000             -call 0x4315d0
    cpu.esp -= 4;
    sub_4315d0(app, cpu);
L_0x00425e94:
    // 00425e94  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00425e96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425e97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425e98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425e99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425ea0  833ddc28490007         +cmp dword ptr [0x4928dc], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425ea7  7506                   -jne 0x425eaf
    if (!cpu.flags.zf)
    {
        goto L_0x00425eaf;
    }
    // 00425ea9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00425eae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425eaf:
    // 00425eaf  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 00425eb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425eb6  7e3f                   -jle 0x425ef7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00425ef7;
    }
    // 00425eb8  e843b1fdff             -call 0x401000
    cpu.esp -= 4;
    sub_401000(app, cpu);
    // 00425ebd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425ebf  7406                   -je 0x425ec7
    if (cpu.flags.zf)
    {
        goto L_0x00425ec7;
    }
    // 00425ec1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00425ec6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425ec7:
    // 00425ec7  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00425ecc  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00425ece  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00425ed3  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 00425ed9  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00425edc  8b81e8020000           -mov eax, dword ptr [ecx + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 00425ee2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425ee4  7406                   -je 0x425eec
    if (cpu.flags.zf)
    {
        goto L_0x00425eec;
    }
    // 00425ee6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00425eeb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425eec:
    // 00425eec  e83f180000             -call 0x427730
    cpu.esp -= 4;
    sub_427730(app, cpu);
    // 00425ef1  83f801                 +cmp eax, 1
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
    // 00425ef4  7501                   -jne 0x425ef7
    if (!cpu.flags.zf)
    {
        goto L_0x00425ef7;
    }
    // 00425ef6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00425ef7:
    // 00425ef7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00425ef9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425f00  a104ef5100             -mov eax, dword ptr [0x51ef04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00425f05  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425f07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425f08  ff15f0714800           -call dword ptr [0x4871f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747760) /* 0x4871f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00425f0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425f10  a104ef5100             -mov eax, dword ptr [0x51ef04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00425f15  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00425f17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425f18  ff15f0714800           -call dword ptr [0x4871f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747760) /* 0x4871f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00425f1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_425f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425f20  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00425f24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425f25  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00425f29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425f2a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00425f2b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425f2c  ff15f8714800           -call dword ptr [0x4871f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747768) /* 0x4871f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00425f32  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_425f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425f40  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 00425f45  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00425f4b  3c09                   +cmp al, 9
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
    // 00425f4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425f4e  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00425f50  7709                   -ja 0x425f5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00425f5b;
    }
    // 00425f52  e849ffffff             -call 0x425ea0
    cpu.esp -= 4;
    sub_425ea0(app, cpu);
    // 00425f57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425f59  7405                   -je 0x425f60
    if (cpu.flags.zf)
    {
        goto L_0x00425f60;
    }
L_0x00425f5b:
    // 00425f5b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00425f60:
    // 00425f60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425f61  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00425f65  6890324900             -push 0x493290
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797072 /*0x493290*/;
    cpu.esp -= 4;
    // 00425f6a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00425f6b  e8880e0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00425f70  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00425f73  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00425f75  e886ce0300             -call 0x462e00
    cpu.esp -= 4;
    sub_462e00(app, cpu);
    // 00425f7a  e881ffffff             -call 0x425f00
    cpu.esp -= 4;
    sub_425f00(app, cpu);
    // 00425f7f  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00425f83  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425f85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00425f86  6824384900             -push 0x493824
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798500 /*0x493824*/;
    cpu.esp -= 4;
    // 00425f8b  6824384900             -push 0x493824
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798500 /*0x493824*/;
    cpu.esp -= 4;
    // 00425f90  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00425f92  e87a2e0500             -call 0x478e11
    cpu.esp -= 4;
    sub_478e11(app, cpu);
    // 00425f97  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00425f9a  a310d44a00             -mov dword ptr [0x4ad410], eax
    app->getMemory<x86::reg32>(x86::reg32(4903952) /* 0x4ad410 */) = cpu.eax;
    // 00425f9f  e86cffffff             -call 0x425f10
    cpu.esp -= 4;
    sub_425f10(app, cpu);
    // 00425fa4  a110d44a00             -mov eax, dword ptr [0x4ad410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903952) /* 0x4ad410 */);
    // 00425fa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00425fab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00425fac  7513                   -jne 0x425fc1
    if (!cpu.flags.zf)
    {
        goto L_0x00425fc1;
    }
    // 00425fae  833ddc284900ff         +cmp dword ptr [0x4928dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00425fb5  750a                   -jne 0x425fc1
    if (!cpu.flags.zf)
    {
        goto L_0x00425fc1;
    }
    // 00425fb7  c70510d44a0001000000   -mov dword ptr [0x4ad410], 1
    app->getMemory<x86::reg32>(x86::reg32(4903952) /* 0x4ad410 */) = 1 /*0x1*/;
L_0x00425fc1:
    // 00425fc1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00425fc6  e835ce0300             -call 0x462e00
    cpu.esp -= 4;
    sub_462e00(app, cpu);
    // 00425fcb  81c480000000           +add esp, 0x80
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00425fd1  e93ae80300             -jmp 0x464810
    return sub_464810(app, cpu);
}

/* align: skip  */
void Application::sub_425fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00425fe0  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00425fe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00425fe4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00425fe6  e845e60300             -call 0x464630
    cpu.esp -= 4;
    sub_464630(app, cpu);
    // 00425feb  e830c40300             -call 0x462420
    cpu.esp -= 4;
    sub_462420(app, cpu);
    // 00425ff0  8b0ddc284900           -mov ecx, dword ptr [0x4928dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 00425ff6  e8b5d1ffff             -call 0x4231b0
    cpu.esp -= 4;
    sub_4231b0(app, cpu);
    // 00425ffb  e8c0eaffff             -call 0x424ac0
    cpu.esp -= 4;
    sub_424ac0(app, cpu);
    // 00426000  e84bcb0300             -call 0x462b50
    cpu.esp -= 4;
    sub_462b50(app, cpu);
    // 00426005  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00426009  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042600a  6844384900             -push 0x493844
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798532 /*0x493844*/;
    cpu.esp -= 4;
    // 0042600f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426010  e8e30d0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00426015  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00426018  e873000000             -call 0x426090
    cpu.esp -= 4;
    sub_426090(app, cpu);
    // 0042601d  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00426021  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00426023  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426024  683c384900             -push 0x49383c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798524 /*0x49383c*/;
    cpu.esp -= 4;
    // 00426029  6830384900             -push 0x493830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798512 /*0x493830*/;
    cpu.esp -= 4;
    // 0042602e  6830384900             -push 0x493830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798512 /*0x493830*/;
    cpu.esp -= 4;
    // 00426033  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00426035  e8d72d0500             -call 0x478e11
    cpu.esp -= 4;
    sub_478e11(app, cpu);
    // 0042603a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042603d  e8eef60300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00426042  dc05a8744800           -fadd qword ptr [0x4874a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748456) /* 0x4874a8 */));
    // 00426048  8b3580704800           -mov esi, dword ptr [0x487080]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747392) /* 0x487080 */);
    // 0042604e  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00426052:
    // 00426052  68f4010000             -push 0x1f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 500 /*0x1f4*/;
    cpu.esp -= 4;
    // 00426057  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00426059  e832000000             -call 0x426090
    cpu.esp -= 4;
    sub_426090(app, cpu);
    // 0042605e  83f801                 +cmp eax, 1
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
    // 00426061  7412                   -je 0x426075
    if (cpu.flags.zf)
    {
        goto L_0x00426075;
    }
    // 00426063  e8c8f60300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00426068  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0042606c  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0042606e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00426070  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00426073  7add                   -jp 0x426052
    if (cpu.flags.pf)
    {
        goto L_0x00426052;
    }
L_0x00426075:
    // 00426075  e886e60300             -call 0x464700
    cpu.esp -= 4;
    sub_464700(app, cpu);
    // 0042607a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042607c  e8de250500             -call 0x47865f
    cpu.esp -= 4;
    sub_47865f(app, cpu);
    // 00426081  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426082  90                     -nop 
    ;
    // 00426083  90                     -nop 
    ;
    // 00426084  90                     -nop 
    ;
    // 00426085  90                     -nop 
    ;
    // 00426086  90                     -nop 
    ;
    // 00426087  90                     -nop 
    ;
    // 00426088  90                     -nop 
    ;
    // 00426089  90                     -nop 
    ;
    // 0042608a  90                     -nop 
    ;
    // 0042608b  90                     -nop 
    ;
    // 0042608c  90                     -nop 
    ;
    // 0042608d  90                     -nop 
    ;
    // 0042608e  90                     -nop 
    ;
    // 0042608f  90                     -nop 
    ;
    return sub_426090(app, cpu);
}

/* align: skip  */
void Application::sub_426090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426090  6808c74800             -push 0x48c708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769544 /*0x48c708*/;
    cpu.esp -= 4;
    // 00426095  6848384900             -push 0x493848
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798536 /*0x493848*/;
    cpu.esp -= 4;
    // 0042609a  e8bf1b0500             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 0042609f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004260a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004260a4  7501                   -jne 0x4260a7
    if (!cpu.flags.zf)
    {
        goto L_0x004260a7;
    }
    // 004260a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004260a7:
    // 004260a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004260a8  e82a150500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 004260ad  6848384900             -push 0x493848
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798536 /*0x493848*/;
    cpu.esp -= 4;
    // 004260b2  e851200500             -call 0x478108
    cpu.esp -= 4;
    sub_478108(app, cpu);
    // 004260b7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004260ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004260bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46db80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0046db80;
L_0x004260c0:
    // 004260c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004260c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004260c2  e869e50300             -call 0x464630
    cpu.esp -= 4;
    sub_464630(app, cpu);
    // 004260c7  e854c30300             -call 0x462420
    cpu.esp -= 4;
    sub_462420(app, cpu);
    // 004260cc  8b0ddc284900           -mov ecx, dword ptr [0x4928dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 004260d2  e8d9d0ffff             -call 0x4231b0
    cpu.esp -= 4;
    sub_4231b0(app, cpu);
    // 004260d7  e8e4e9ffff             -call 0x424ac0
    cpu.esp -= 4;
    sub_424ac0(app, cpu);
    // 004260dc  e86fca0300             -call 0x462b50
    cpu.esp -= 4;
    sub_462b50(app, cpu);
    // 004260e1  e8aaffffff             -call 0x426090
    cpu.esp -= 4;
    sub_426090(app, cpu);
    // 004260e6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004260e8  681c384900             -push 0x49381c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798492 /*0x49381c*/;
    cpu.esp -= 4;
    // 004260ed  6830384900             -push 0x493830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798512 /*0x493830*/;
    cpu.esp -= 4;
    // 004260f2  6830384900             -push 0x493830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798512 /*0x493830*/;
    cpu.esp -= 4;
    // 004260f7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004260f9  e8132d0500             -call 0x478e11
    cpu.esp -= 4;
    sub_478e11(app, cpu);
    // 004260fe  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00426101  e82af60300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00426106  dc05a8744800           -fadd qword ptr [0x4874a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748456) /* 0x4874a8 */));
    // 0042610c  8b3580704800           -mov esi, dword ptr [0x487080]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747392) /* 0x487080 */);
    // 00426112  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00426116:
    // 00426116  68f4010000             -push 0x1f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 500 /*0x1f4*/;
    cpu.esp -= 4;
    // 0042611b  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042611d  e86effffff             -call 0x426090
    cpu.esp -= 4;
    sub_426090(app, cpu);
    // 00426122  83f801                 +cmp eax, 1
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
    // 00426125  7412                   -je 0x426139
    if (cpu.flags.zf)
    {
        goto L_0x00426139;
    }
    // 00426127  e804f60300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042612c  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00426130  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00426132  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00426134  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00426137  7add                   -jp 0x426116
    if (cpu.flags.pf)
    {
        goto L_0x00426116;
    }
L_0x00426139:
    // 00426139  e8c2e50300             -call 0x464700
    cpu.esp -= 4;
    sub_464700(app, cpu);
    // 0042613e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00426140  e81a250500             -call 0x47865f
    cpu.esp -= 4;
    sub_47865f(app, cpu);
    // 00426145  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426146  90                     -nop 
    ;
    // 00426147  90                     -nop 
    ;
    // 00426148  90                     -nop 
    ;
    // 00426149  90                     -nop 
    ;
    // 0042614a  90                     -nop 
    ;
    // 0042614b  90                     -nop 
    ;
    // 0042614c  90                     -nop 
    ;
    // 0042614d  90                     -nop 
    ;
    // 0042614e  90                     -nop 
    ;
    // 0042614f  90                     -nop 
    ;
L_entry_0x0046db80:
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
    __ftol(app, cpu);
    // 0046db90  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046db92  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046db96  e8e58affff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046db9b  e8f0910000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
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
    goto L_0x004260c0;
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
    goto L_0x004260c0;
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
    goto L_0x004260c0;
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
    goto L_0x004260c0;
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
void Application::sub_426150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426150  81ec44020000           -sub esp, 0x244
    (cpu.esp) -= x86::reg32(x86::sreg32(580 /*0x244*/));
    // 00426156  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 0042615a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042615b  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00426160  6800040000             -push 0x400
    app->getMemory<x86::reg32>(cpu.esp-4) = 1024 /*0x400*/;
    cpu.esp -= 4;
    // 00426165  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426166  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00426168  e84f2f0500             -call 0x4790bc
    cpu.esp -= 4;
    sub_4790bc(app, cpu);
    // 0042616d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00426170  83f8ff                 +cmp eax, -1
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
    // 00426173  0f84e5010000           -je 0x42635e
    if (cpu.flags.zf)
    {
        goto L_0x0042635e;
    }
    // 00426179  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042617a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042617b  e8c0450300             -call 0x45a740
    cpu.esp -= 4;
    sub_45a740(app, cpu);
    // 00426180  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00426183  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00426186  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00426189  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042618a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042618c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042618d  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00426191  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426192  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426193  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426194  8d442464               -lea eax, [esp + 0x64]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00426198  681c394900             -push 0x49391c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798748 /*0x49391c*/;
    cpu.esp -= 4;
    // 0042619d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042619e  e8550c0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004261a3  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004261a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004261a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004261aa  6810394900             -push 0x493910
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798736 /*0x493910*/;
    cpu.esp -= 4;
    // 004261af  6810394900             -push 0x493910
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798736 /*0x493910*/;
    cpu.esp -= 4;
    // 004261b4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004261b6  e8562c0500             -call 0x478e11
    cpu.esp -= 4;
    sub_478e11(app, cpu);
    // 004261bb  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004261be  e83d450300             -call 0x45a700
    cpu.esp -= 4;
    sub_45a700(app, cpu);
    // 004261c3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004261c7  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004261cb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004261cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004261cd  e8572c0500             -call 0x478e29
    cpu.esp -= 4;
    sub_478e29(app, cpu);
    // 004261d2  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004261d6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004261d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004261db  0f8e48010000           -jle 0x426329
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00426329;
    }
    // 004261e1  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004261e5  8d4c2450               -lea ecx, [esp + 0x50]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004261e9  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004261ee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004261ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004261f0  e86e260500             -call 0x478863
    cpu.esp -= 4;
    sub_478863(app, cpu);
    // 004261f5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004261f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004261fa  0f8e29010000           -jle 0x426329
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00426329;
    }
    // 00426200  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00426204  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00426207  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426209  83cbff                 +or ebx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042620c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0042620e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00426210  49                     -dec ecx
    (cpu.ecx)--;
    // 00426211  8d442450               -lea eax, [esp + 0x50]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00426215  8d7c0c4f               -lea edi, [esp + ecx + 0x4f]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(79) /* 0x4f */ + cpu.ecx * 1);
    // 00426219  3bf8                   +cmp edi, eax
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
    // 0042621b  740e                   -je 0x42622b
    if (cpu.flags.zf)
    {
        goto L_0x0042622b;
    }
L_0x0042621d:
    // 0042621d  803f22                 +cmp byte ptr [edi], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00426220  7412                   -je 0x426234
    if (cpu.flags.zf)
    {
        goto L_0x00426234;
    }
    // 00426222  4f                     -dec edi
    (cpu.edi)--;
    // 00426223  8d4c2450               -lea ecx, [esp + 0x50]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00426227  3bf9                   +cmp edi, ecx
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
    // 00426229  75f2                   -jne 0x42621d
    if (!cpu.flags.zf)
    {
        goto L_0x0042621d;
    }
L_0x0042622b:
    // 0042622b  803f22                 +cmp byte ptr [edi], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042622e  0f85f5000000           -jne 0x426329
    if (!cpu.flags.zf)
    {
        goto L_0x00426329;
    }
L_0x00426234:
    // 00426234  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00426238  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426239  6804394900             -push 0x493904
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798724 /*0x493904*/;
    cpu.esp -= 4;
    // 0042623e  e8740b0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00426243  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00426247  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042624b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042624c  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00426250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426251  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00426255  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426256  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426257  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042625a  68b0384900             -push 0x4938b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798640 /*0x4938b0*/;
    cpu.esp -= 4;
    // 0042625f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426260  e8ef130500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00426265  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00426269  68a4384900             -push 0x4938a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798628 /*0x4938a4*/;
    cpu.esp -= 4;
    // 0042626e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042626f  e83ce90500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00426274  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00426277  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426279  7504                   -jne 0x42627f
    if (!cpu.flags.zf)
    {
        goto L_0x0042627f;
    }
    // 0042627b  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0042627d  eb38                   -jmp 0x4262b7
    goto L_0x004262b7;
L_0x0042627f:
    // 0042627f  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00426283  68a0384900             -push 0x4938a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798624 /*0x4938a0*/;
    cpu.esp -= 4;
    // 00426288  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426289  e822e90500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0042628e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00426291  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426293  7507                   -jne 0x42629c
    if (!cpu.flags.zf)
    {
        goto L_0x0042629c;
    }
    // 00426295  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0042629a  eb1b                   -jmp 0x4262b7
    goto L_0x004262b7;
L_0x0042629c:
    // 0042629c  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004262a0  6894384900             -push 0x493894
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798612 /*0x493894*/;
    cpu.esp -= 4;
    // 004262a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004262a6  e805e90500             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 004262ab  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004262ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004262b0  7505                   -jne 0x4262b7
    if (!cpu.flags.zf)
    {
        goto L_0x004262b7;
    }
    // 004262b2  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x004262b7:
    // 004262b7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004262bb  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004262bf  3bc8                   +cmp ecx, eax
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
    // 004262c1  750f                   -jne 0x4262d2
    if (!cpu.flags.zf)
    {
        goto L_0x004262d2;
    }
    // 004262c3  6874384900             -push 0x493874
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798580 /*0x493874*/;
    cpu.esp -= 4;
    // 004262c8  e8636effff             -call 0x41d130
    cpu.esp -= 4;
    sub_41d130(app, cpu);
    // 004262cd  83c404                 +add esp, 4
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
    // 004262d0  eb73                   -jmp 0x426345
    goto L_0x00426345;
L_0x004262d2:
    // 004262d2  83fbff                 +cmp ebx, -1
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
    // 004262d5  7452                   -je 0x426329
    if (cpu.flags.zf)
    {
        goto L_0x00426329;
    }
    // 004262d7  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004262db  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004262de  7e49                   -jle 0x426329
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00426329;
    }
    // 004262e0  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 004262e5  881d57155200           -mov byte ptr [0x521557], bl
    app->getMemory<x86::reg8>(x86::reg32(5379415) /* 0x521557 */) = cpu.bl;
    // 004262eb  c6051515520004         -mov byte ptr [0x521515], 4
    app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */) = 4 /*0x4*/;
    // 004262f2  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004262f4  881516155200           -mov byte ptr [0x521516], dl
    app->getMemory<x86::reg8>(x86::reg32(5379350) /* 0x521516 */) = cpu.dl;
    // 004262fa  8a4604                 -mov al, byte ptr [esi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004262fd  a217155200             -mov byte ptr [0x521517], al
    app->getMemory<x86::reg8>(x86::reg32(5379351) /* 0x521517 */) = cpu.al;
    // 00426302  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00426305  880d18155200           -mov byte ptr [0x521518], cl
    app->getMemory<x86::reg8>(x86::reg32(5379352) /* 0x521518 */) = cpu.cl;
    // 0042630b  8a560c                 -mov dl, byte ptr [esi + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042630e  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00426314  881519155200           -mov byte ptr [0x521519], dl
    app->getMemory<x86::reg8>(x86::reg32(5379353) /* 0x521519 */) = cpu.dl;
    // 0042631a  e871b3ffff             -call 0x421690
    cpu.esp -= 4;
    sub_421690(app, cpu);
    // 0042631f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00426324  e8b7fcffff             -call 0x425fe0
    cpu.esp -= 4;
    sub_425fe0(app, cpu);
L_0x00426329:
    // 00426329  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042632c  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0042632f  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00426332  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426333  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00426335  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426336  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426337  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426338  6854384900             -push 0x493854
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798548 /*0x493854*/;
    cpu.esp -= 4;
    // 0042633d  e8ee6dffff             -call 0x41d130
    cpu.esp -= 4;
    sub_41d130(app, cpu);
    // 00426342  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00426345:
    // 00426345  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00426349  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042634a  e834240500             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 0042634f  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00426353  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426354  e82a240500             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 00426359  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042635c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042635d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042635e:
    // 0042635e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042635f  81c444020000           -add esp, 0x244
    (cpu.esp) += x86::reg32(x86::sreg32(580 /*0x244*/));
    // 00426365  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426370  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 00426375  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426376  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426378  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042637a  0f84a3000000           -je 0x426423
    if (cpu.flags.zf)
    {
        goto L_0x00426423;
    }
    // 00426380  81fb80000000           +cmp ebx, 0x80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426386  0f8c97000000           -jl 0x426423
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00426423;
    }
    // 0042638c  81fb84000000           +cmp ebx, 0x84
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426392  0f8f8b000000           -jg 0x426423
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00426423;
    }
    // 00426398  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0042639d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042639f  7550                   -jne 0x4263f1
    if (!cpu.flags.zf)
    {
        goto L_0x004263f1;
    }
    // 004263a1  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004263a4  7e7d                   -jle 0x426423
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00426423;
    }
    // 004263a6  833dc0f3510001         +cmp dword ptr [0x51f3c0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004263ad  7e10                   -jle 0x4263bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004263bf;
    }
    // 004263af  e8bc030300             -call 0x456770
    cpu.esp -= 4;
    sub_456770(app, cpu);
    // 004263b4  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 004263b9  ff1580704800           -call dword ptr [0x487080]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747392) /* 0x487080 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004263bf:
    // 004263bf  8a0d20d44a00           -mov cl, byte ptr [0x4ad420]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4903968) /* 0x4ad420 */);
    // 004263c5  a024d44a00             -mov al, byte ptr [0x4ad424]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4903972) /* 0x4ad424 */);
    // 004263ca  880d15155200           -mov byte ptr [0x521515], cl
    app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */) = cpu.cl;
    // 004263d0  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 004263d6  881d10155200           -mov byte ptr [0x521510], bl
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.bl;
    // 004263dc  a257155200             -mov byte ptr [0x521557], al
    app->getMemory<x86::reg8>(x86::reg32(5379415) /* 0x521557 */) = cpu.al;
    // 004263e1  e8aab2ffff             -call 0x421690
    cpu.esp -= 4;
    sub_421690(app, cpu);
    // 004263e6  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004263eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004263ec  e9effbffff             -jmp 0x425fe0
    return sub_425fe0(app, cpu);
L_0x004263f1:
    // 004263f1  8a1524d44a00           -mov dl, byte ptr [0x4ad424]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(4903972) /* 0x4ad424 */);
    // 004263f7  a020d44a00             -mov al, byte ptr [0x4ad420]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4903968) /* 0x4ad420 */);
    // 004263fc  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00426402  881d10155200           -mov byte ptr [0x521510], bl
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.bl;
    // 00426408  881557155200           -mov byte ptr [0x521557], dl
    app->getMemory<x86::reg8>(x86::reg32(5379415) /* 0x521557 */) = cpu.dl;
    // 0042640e  a215155200             -mov byte ptr [0x521515], al
    app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */) = cpu.al;
    // 00426413  e878b2ffff             -call 0x421690
    cpu.esp -= 4;
    sub_421690(app, cpu);
    // 00426418  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0042641d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042641e  e9bdfbffff             -jmp 0x425fe0
    return sub_425fe0(app, cpu);
L_0x00426423:
    // 00426423  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426424  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426430  8b0d90374900           -mov ecx, dword ptr [0x493790]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798352) /* 0x493790 */);
    // 00426436  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426438  83f9ff                 +cmp ecx, -1
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
    // 0042643b  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0042643e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426440  a190374900             -mov eax, dword ptr [0x493790]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798352) /* 0x493790 */);
    // 00426445  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00426448  83f8ff                 +cmp eax, -1
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
    // 0042644b  7449                   -je 0x426496
    if (cpu.flags.zf)
    {
        goto L_0x00426496;
    }
    // 0042644d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042644f  7c15                   -jl 0x426466
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00426466;
    }
    // 00426451  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426452  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00426456  683c394900             -push 0x49393c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798780 /*0x49393c*/;
    cpu.esp -= 4;
    // 0042645b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042645c  e897090500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00426461  83c40c                 +add esp, 0xc
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
    // 00426464  eb1d                   -jmp 0x426483
    goto L_0x00426483;
L_0x00426466:
    // 00426466  8b0d30394900           -mov ecx, dword ptr [0x493930]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798768) /* 0x493930 */);
    // 0042646c  8b1534394900           -mov edx, dword ptr [0x493934]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798772) /* 0x493934 */);
    // 00426472  a038394900             -mov al, byte ptr [0x493938]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4798776) /* 0x493938 */);
    // 00426477  894c2400               -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0042647b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042647f  88442408               -mov byte ptr [esp + 8], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.al;
L_0x00426483:
    // 00426483  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 00426487  e804560300             -call 0x45ba90
    cpu.esp -= 4;
    sub_45ba90(app, cpu);
    // 0042648c  c70590374900ffffffff   -mov dword ptr [0x493790], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4798352) /* 0x493790 */) = 4294967295 /*0xffffffff*/;
L_0x00426496:
    // 00426496  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00426499  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4264a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004264a0  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004264a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004264a4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004264a6  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 004264ac  e81fb2ffff             -call 0x4216d0
    cpu.esp -= 4;
    sub_4216d0(app, cpu);
    // 004264b1  e87ac7ffff             -call 0x422c30
    cpu.esp -= 4;
    sub_422c30(app, cpu);
    // 004264b6  8d46fe                 -lea eax, [esi - 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 004264b9  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004264bc  0f872f020000           -ja 0x4266f1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004266f1;
    }
    // 004264c2  ff248504674200         -jmp dword ptr [eax*4 + 0x426704]
    cpu.ip = app->getMemory<x86::reg32>(4351748 + cpu.eax * 4); goto dynamic_jump;
  case 0x004264c9:
    // 004264c9  833ddc284900ff         +cmp dword ptr [0x4928dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004264d0  750e                   -jne 0x4264e0
    if (!cpu.flags.zf)
    {
        goto L_0x004264e0;
    }
    // 004264d2  803d1015520001         +cmp byte ptr [0x521510], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004264d9  7505                   -jne 0x4264e0
    if (!cpu.flags.zf)
    {
        goto L_0x004264e0;
    }
    // 004264db  e820f7ffff             -call 0x425c00
    cpu.esp -= 4;
    sub_425c00(app, cpu);
L_0x004264e0:
    // 004264e0  803d1015520020         +cmp byte ptr [0x521510], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004264e7  7305                   -jae 0x4264ee
    if (!cpu.flags.cf)
    {
        goto L_0x004264ee;
    }
    // 004264e9  e862f7ffff             -call 0x425c50
    cpu.esp -= 4;
    sub_425c50(app, cpu);
L_0x004264ee:
    // 004264ee  833ddc284900ff         +cmp dword ptr [0x4928dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004264f5  0f8403020000           -je 0x4266fe
    if (cpu.flags.zf)
    {
        goto L_0x004266fe;
    }
L_0x004264fb:
    // 004264fb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004264fd  e8defaffff             -call 0x425fe0
    cpu.esp -= 4;
    sub_425fe0(app, cpu);
    // 00426502  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426503  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00426506  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426507:
    // 00426507  e8f4f6ffff             -call 0x425c00
    cpu.esp -= 4;
    sub_425c00(app, cpu);
    // 0042650c  a158155200             -mov eax, dword ptr [0x521558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379416) /* 0x521558 */);
    // 00426511  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00426515  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042651a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042651b  683c394900             -push 0x49393c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798780 /*0x49393c*/;
    cpu.esp -= 4;
    // 00426520  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426521  e8d2080500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00426526  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00426529  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042652d  e8ee540300             -call 0x45ba20
    cpu.esp -= 4;
    sub_45ba20(app, cpu);
    // 00426532  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00426538  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 0042653d  e84eb1ffff             -call 0x421690
    cpu.esp -= 4;
    sub_421690(app, cpu);
    // 00426542  833ddc284900ff         +cmp dword ptr [0x4928dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426549  75b0                   -jne 0x4264fb
    if (!cpu.flags.zf)
    {
        goto L_0x004264fb;
    }
    // 0042654b  8b1558155200           -mov edx, dword ptr [0x521558]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379416) /* 0x521558 */);
    // 00426551  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426552  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00426558  891590374900           -mov dword ptr [0x493790], edx
    app->getMemory<x86::reg32>(x86::reg32(4798352) /* 0x493790 */) = cpu.edx;
    // 0042655e  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00426561  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426562:
    // 00426562  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 00426567  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00426569  0f8e8f010000           -jle 0x4266fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004266fe;
    }
    // 0042656f  83f80a                 +cmp eax, 0xa
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
    // 00426572  0f8d86010000           -jge 0x4266fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004266fe;
    }
    // 00426578  a158155200             -mov eax, dword ptr [0x521558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379416) /* 0x521558 */);
    // 0042657d  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00426581  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00426586  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426587  683c394900             -push 0x49393c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798780 /*0x49393c*/;
    cpu.esp -= 4;
    // 0042658c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042658d  e866080500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00426592  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00426595  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00426599  e812510300             -call 0x45b6b0
    cpu.esp -= 4;
    sub_45b6b0(app, cpu);
    // 0042659e  b970394900             -mov ecx, 0x493970
    cpu.ecx = 4798832 /*0x493970*/;
    // 004265a3  e818150300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 004265a8  8b1558155200           -mov edx, dword ptr [0x521558]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379416) /* 0x521558 */);
    // 004265ae  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004265b2  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004265b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004265b9  685c394900             -push 0x49395c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798812 /*0x49395c*/;
    cpu.esp -= 4;
    // 004265be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004265bf  e834080500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004265c4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004265c7  e8b4e3ffff             -call 0x424980
    cpu.esp -= 4;
    sub_424980(app, cpu);
    // 004265cc  e8afe3ffff             -call 0x424980
    cpu.esp -= 4;
    sub_424980(app, cpu);
    // 004265d1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004265d6  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004265da  ff157c845100           -call dword ptr [0x51847c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342332) /* 0x51847c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004265e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004265e1  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004265e4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004265e5:
    // 004265e5  c70590374900feffffff   -mov dword ptr [0x493790], 0xfffffffe
    app->getMemory<x86::reg32>(x86::reg32(4798352) /* 0x493790 */) = 4294967294 /*0xfffffffe*/;
    // 004265ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004265f0  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004265f3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004265f4:
    // 004265f4  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 004265f9  c70590d34a0001000000   -mov dword ptr [0x4ad390], 1
    app->getMemory<x86::reg32>(x86::reg32(4903824) /* 0x4ad390 */) = 1 /*0x1*/;
    // 00426603  83f8ff                 +cmp eax, -1
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
    // 00426606  7407                   -je 0x42660f
    if (cpu.flags.zf)
    {
        goto L_0x0042660f;
    }
    // 00426608  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042660a  e8d1f9ffff             -call 0x425fe0
    cpu.esp -= 4;
    sub_425fe0(app, cpu);
L_0x0042660f:
    // 0042660f  0fbe0512155200         -movsx eax, byte ptr [0x521512]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5379346) /* 0x521512 */)));
    // 00426616  83f804                 +cmp eax, 4
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
    // 00426619  c7054116520001000000   -mov dword ptr [0x521641], 1
    app->getMemory<x86::reg32>(x86::reg32(5379649) /* 0x521641 */) = 1 /*0x1*/;
    // 00426623  7757                   -ja 0x42667c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042667c;
    }
    // 00426625  ff24851c674200         -jmp dword ptr [eax*4 + 0x42671c]
    cpu.ip = app->getMemory<x86::reg32>(4351772 + cpu.eax * 4); goto dynamic_jump;
  case 0x0042662c:
    // 0042662c  8a0d15155200           -mov cl, byte ptr [0x521515]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */);
    // 00426632  b043                   -mov al, 0x43
    cpu.al = 67 /*0x43*/;
    // 00426634  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 00426636  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426637  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 0042663c  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0042663f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426640:
    // 00426640  8a0d15155200           -mov cl, byte ptr [0x521515]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */);
    // 00426646  b046                   -mov al, 0x46
    cpu.al = 70 /*0x46*/;
    // 00426648  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 0042664a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042664b  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 00426650  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00426653  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426654:
    // 00426654  8a0d15155200           -mov cl, byte ptr [0x521515]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */);
    // 0042665a  b049                   -mov al, 0x49
    cpu.al = 73 /*0x49*/;
    // 0042665c  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 0042665e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042665f  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 00426664  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00426667  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426668:
    // 00426668  8a0d15155200           -mov cl, byte ptr [0x521515]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */);
    // 0042666e  b04c                   -mov al, 0x4c
    cpu.al = 76 /*0x4c*/;
    // 00426670  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 00426672  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426673  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 00426678  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0042667b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042667c:
L_0x0042667c:
    // 0042667c  8a0d15155200           -mov cl, byte ptr [0x521515]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */);
    // 00426682  b040                   -mov al, 0x40
    cpu.al = 64 /*0x40*/;
    // 00426684  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 00426686  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426687  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 0042668c  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0042668f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426690:
    // 00426690  833ddc284900ff         +cmp dword ptr [0x4928dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426697  7407                   -je 0x4266a0
    if (cpu.flags.zf)
    {
        goto L_0x004266a0;
    }
    // 00426699  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042669b  e840f9ffff             -call 0x425fe0
    cpu.esp -= 4;
    sub_425fe0(app, cpu);
L_0x004266a0:
    // 004266a0  a015155200             -mov al, byte ptr [0x521515]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379349) /* 0x521515 */);
    // 004266a5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004266a7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004266a9  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 004266ac  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004266ae  c7054116520001000000   -mov dword ptr [0x521641], 1
    app->getMemory<x86::reg32>(x86::reg32(5379649) /* 0x521641 */) = 1 /*0x1*/;
    // 004266b8  668b155a155200         -mov dx, word ptr [0x52155a]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5379418) /* 0x52155a */);
    // 004266bf  8d0c8d04000000         -lea ecx, [ecx*4 + 4]
    cpu.ecx = x86::reg32(x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 004266c6  83c902                 -or ecx, 2
    cpu.ecx |= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004266c9  891518d44a00           -mov dword ptr [0x4ad418], edx
    app->getMemory<x86::reg32>(x86::reg32(4903960) /* 0x4ad418 */) = cpu.edx;
    // 004266cf  890d1cd44a00           -mov dword ptr [0x4ad41c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903964) /* 0x4ad41c */) = cpu.ecx;
    // 004266d5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004266d7  8a0d57155200           -mov cl, byte ptr [0x521557]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379415) /* 0x521557 */);
    // 004266dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004266de  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 004266e1  890d24d44a00           -mov dword ptr [0x4ad424], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903972) /* 0x4ad424 */) = cpu.ecx;
    // 004266e7  891520d44a00           -mov dword ptr [0x4ad420], edx
    app->getMemory<x86::reg32>(x86::reg32(4903968) /* 0x4ad420 */) = cpu.edx;
    // 004266ed  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004266f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004266f1:
    // 004266f1  6848394900             -push 0x493948
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798792 /*0x493948*/;
    cpu.esp -= 4;
    // 004266f6  e815e5ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004266fb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004266fe:
    // 004266fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004266ff  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00426702  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_426730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426730  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00426736  e895afffff             -call 0x4216d0
    cpu.esp -= 4;
    sub_4216d0(app, cpu);
    // 0042673b  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 00426740  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00426746  c6804f175200ff         -mov byte ptr [eax + 0x52174f], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5379919) /* 0x52174f */) = 255 /*0xff*/;
    // 0042674d  e93eafffff             -jmp 0x421690
    return sub_421690(app, cpu);
}

/* align: skip  */
void Application::sub_426760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426760  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00426766  e865afffff             -call 0x4216d0
    cpu.esp -= 4;
    sub_4216d0(app, cpu);
    // 0042676b  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 00426770  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00426776  fec0                   +inc al
    {
        x86::reg8& tmp = cpu.al;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00426778  a210155200             -mov byte ptr [0x521510], al
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.al;
    // 0042677d  e80eafffff             -call 0x421690
    cpu.esp -= 4;
    sub_421690(app, cpu);
    // 00426782  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00426787  e954f8ffff             -jmp 0x425fe0
    return sub_425fe0(app, cpu);
}

/* align: skip  */
void Application::sub_426790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00426791  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00426793  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 00426799  e832afffff             -call 0x4216d0
    cpu.esp -= 4;
    sub_4216d0(app, cpu);
    // 0042679e  8b0d8c374900           -mov ecx, dword ptr [0x49378c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798348) /* 0x49378c */);
    // 004267a4  881d10155200           -mov byte ptr [0x521510], bl
    app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */) = cpu.bl;
    // 004267aa  e8e1aeffff             -call 0x421690
    cpu.esp -= 4;
    sub_421690(app, cpu);
    // 004267af  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004267b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004267b5  e926f8ffff             -jmp 0x425fe0
    return sub_425fe0(app, cpu);
}

/* align: skip  */
void Application::sub_4267c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004267c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004267c1  a035165200             -mov al, byte ptr [0x521635]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379637) /* 0x521635 */);
    // 004267c6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004267c8  743f                   -je 0x426809
    if (cpu.flags.zf)
    {
        goto L_0x00426809;
    }
    // 004267ca  e821df0100             -call 0x4446f0
    cpu.esp -= 4;
    sub_4446f0(app, cpu);
    // 004267cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004267d1  742d                   -je 0x426800
    if (cpu.flags.zf)
    {
        goto L_0x00426800;
    }
    // 004267d3  66a136165200           -mov ax, word ptr [0x521636]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */);
    // 004267d9  663d8002               +cmp ax, 0x280
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(640 /*0x280*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004267dd  7418                   -je 0x4267f7
    if (cpu.flags.zf)
    {
        goto L_0x004267f7;
    }
    // 004267df  663d0002               +cmp ax, 0x200
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(512 /*0x200*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004267e3  7412                   -je 0x4267f7
    if (cpu.flags.zf)
    {
        goto L_0x004267f7;
    }
    // 004267e5  66c705361652008002     -mov word ptr [0x521636], 0x280
    app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */) = 640 /*0x280*/;
    // 004267ee  66c70538165200e001     -mov word ptr [0x521638], 0x1e0
    app->getMemory<x86::reg16>(x86::reg32(5379640) /* 0x521638 */) = 480 /*0x1e0*/;
L_0x004267f7:
    // 004267f7  c6053516520000         -mov byte ptr [0x521635], 0
    app->getMemory<x86::reg8>(x86::reg32(5379637) /* 0x521635 */) = 0 /*0x0*/;
    // 004267fe  eb09                   -jmp 0x426809
    goto L_0x00426809;
L_0x00426800:
    // 00426800  a035165200             -mov al, byte ptr [0x521635]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379637) /* 0x521635 */);
    // 00426805  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00426807  7509                   -jne 0x426812
    if (!cpu.flags.zf)
    {
        goto L_0x00426812;
    }
L_0x00426809:
    // 00426809  66c7053a1652001000     -mov word ptr [0x52163a], 0x10
    app->getMemory<x86::reg16>(x86::reg32(5379642) /* 0x52163a */) = 16 /*0x10*/;
L_0x00426812:
    // 00426812  8b0d38165200           -mov ecx, dword ptr [0x521638]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379640) /* 0x521638 */);
    // 00426818  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042681a  66a13a165200           -mov ax, word ptr [0x52163a]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5379642) /* 0x52163a */);
    // 00426820  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00426822  668b1536165200         -mov dx, word ptr [0x521636]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */);
    // 00426829  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042682f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426830  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00426831  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00426832  68fc394900             -push 0x4939fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798972 /*0x4939fc*/;
    cpu.esp -= 4;
    // 00426837  e87b050500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042683c  a035165200             -mov al, byte ptr [0x521635]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379637) /* 0x521635 */);
    // 00426841  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00426844  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00426846  7507                   -jne 0x42684f
    if (!cpu.flags.zf)
    {
        goto L_0x0042684f;
    }
    // 00426848  e893fb0100             -call 0x4463e0
    cpu.esp -= 4;
    sub_4463e0(app, cpu);
    // 0042684d  eb74                   -jmp 0x4268c3
    goto L_0x004268c3;
L_0x0042684f:
    // 0042684f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00426851  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00426853  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 00426856  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00426858  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042685a  a3f8ba4900             -mov dword ptr [0x49baf8], eax
    app->getMemory<x86::reg32>(x86::reg32(4831992) /* 0x49baf8 */) = cpu.eax;
    // 0042685f  7507                   -jne 0x426868
    if (!cpu.flags.zf)
    {
        goto L_0x00426868;
    }
    // 00426861  68d4394900             -push 0x4939d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798932 /*0x4939d4*/;
    cpu.esp -= 4;
    // 00426866  eb05                   -jmp 0x42686d
    goto L_0x0042686d;
L_0x00426868:
    // 00426868  68ac394900             -push 0x4939ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798892 /*0x4939ac*/;
    cpu.esp -= 4;
L_0x0042686d:
    // 0042686d  e845050500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00426872  8b153c165200           -mov edx, dword ptr [0x52163c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379644) /* 0x52163c */);
    // 00426878  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042687a  66a13a165200           -mov ax, word ptr [0x52163a]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5379642) /* 0x52163a */);
    // 00426880  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00426886  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00426889  891500bb4900           -mov dword ptr [0x49bb00], edx
    app->getMemory<x86::reg32>(x86::reg32(4832000) /* 0x49bb00 */) = cpu.edx;
    // 0042688f  8b1538165200           -mov edx, dword ptr [0x521638]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379640) /* 0x521638 */);
    // 00426895  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00426897  668b0d36165200         -mov cx, word ptr [0x521636]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */);
    // 0042689e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042689f  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004268a5  e856bd0100             -call 0x442600
    cpu.esp -= 4;
    sub_442600(app, cpu);
    // 004268aa  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004268ad  e8de780100             -call 0x43e190
    cpu.esp -= 4;
    sub_43e190(app, cpu);
    // 004268b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004268b4  750d                   -jne 0x4268c3
    if (!cpu.flags.zf)
    {
        goto L_0x004268c3;
    }
    // 004268b6  689c394900             -push 0x49399c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798876 /*0x49399c*/;
    cpu.esp -= 4;
    // 004268bb  e850e3ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004268c0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004268c3:
    // 004268c3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004268c5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004268c8  a031165200             -mov al, byte ptr [0x521631]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379633) /* 0x521631 */);
    // 004268cd  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004268d1  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 004268d5  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 004268db  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004268de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004268df  68b0374900             -push 0x4937b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798384 /*0x4937b0*/;
    cpu.esp -= 4;
    // 004268e4  e8ce040500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004268e9  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004268eb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004268ee  8a0d31165200           -mov cl, byte ptr [0x521631]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5379633) /* 0x521631 */);
    // 004268f4  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004268f8  8b0d04ef5100           -mov ecx, dword ptr [0x51ef04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 004268fe  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00426902  d80db8784800           -fmul dword ptr [0x4878b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749496) /* 0x4878b8 */));
    // 00426908  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042690b  e890fb0300             -call 0x4664a0
    cpu.esp -= 4;
    sub_4664a0(app, cpu);
    // 00426910  8b1530165200           -mov edx, dword ptr [0x521630]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379632) /* 0x521630 */);
    // 00426916  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042691c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042691d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00426921  8b0d04ef5100           -mov ecx, dword ptr [0x51ef04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00426927  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0042692b  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 00426931  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00426934  e887fb0300             -call 0x4664c0
    cpu.esp -= 4;
    sub_4664c0(app, cpu);
    // 00426939  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042693b  a033165200             -mov al, byte ptr [0x521633]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379635) /* 0x521633 */);
    // 00426940  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00426941  687c394900             -push 0x49397c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798844 /*0x49397c*/;
    cpu.esp -= 4;
    // 00426946  e86c040500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042694b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042694e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426950  a13d165200             -mov eax, dword ptr [0x52163d]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379645) /* 0x52163d */);
    // 00426955  8b0d3c165200           -mov ecx, dword ptr [0x52163c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379644) /* 0x52163c */);
    // 0042695b  0fbe1535165200         -movsx edx, byte ptr [0x521635]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5379637) /* 0x521635 */)));
    // 00426962  a30cd44a00             -mov dword ptr [0x4ad40c], eax
    app->getMemory<x86::reg32>(x86::reg32(4903948) /* 0x4ad40c */) = cpu.eax;
    // 00426967  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426969  66a136165200           -mov ax, word ptr [0x521636]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */);
    // 0042696f  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00426975  890dfcd34a00           -mov dword ptr [0x4ad3fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903932) /* 0x4ad3fc */) = cpu.ecx;
    // 0042697b  8b0d38165200           -mov ecx, dword ptr [0x521638]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379640) /* 0x521638 */);
    // 00426981  8915f0d34a00           -mov dword ptr [0x4ad3f0], edx
    app->getMemory<x86::reg32>(x86::reg32(4903920) /* 0x4ad3f0 */) = cpu.edx;
    // 00426987  a308d44a00             -mov dword ptr [0x4ad408], eax
    app->getMemory<x86::reg32>(x86::reg32(4903944) /* 0x4ad408 */) = cpu.eax;
    // 0042698c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042698e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426990  668b153a165200         -mov dx, word ptr [0x52163a]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5379642) /* 0x52163a */);
    // 00426997  a033165200             -mov al, byte ptr [0x521633]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379635) /* 0x521633 */);
    // 0042699c  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004269a2  891500d44a00           -mov dword ptr [0x4ad400], edx
    app->getMemory<x86::reg32>(x86::reg32(4903936) /* 0x4ad400 */) = cpu.edx;
    // 004269a8  890d04d44a00           -mov dword ptr [0x4ad404], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903940) /* 0x4ad404 */) = cpu.ecx;
    // 004269ae  a3f4d34a00             -mov dword ptr [0x4ad3f4], eax
    app->getMemory<x86::reg32>(x86::reg32(4903924) /* 0x4ad3f4 */) = cpu.eax;
    // 004269b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4269c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004269c0  0fbe0d32165200         -movsx ecx, byte ptr [0x521632]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5379634) /* 0x521632 */)));
    // 004269c7  e814c40300             -call 0x462de0
    cpu.esp -= 4;
    sub_462de0(app, cpu);
    // 004269cc  a11cd44a00             -mov eax, dword ptr [0x4ad41c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903964) /* 0x4ad41c */);
    // 004269d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004269d3  753b                   -jne 0x426a10
    if (!cpu.flags.zf)
    {
        goto L_0x00426a10;
    }
    // 004269d5  e8c6f4ffff             -call 0x425ea0
    cpu.esp -= 4;
    sub_425ea0(app, cpu);
    // 004269da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004269dc  7433                   -je 0x426a11
    if (cpu.flags.zf)
    {
        goto L_0x00426a11;
    }
    // 004269de  66a108d44a00           -mov ax, word ptr [0x4ad408]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(4903944) /* 0x4ad408 */);
    // 004269e4  668b0d04d44a00         -mov cx, word ptr [0x4ad404]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(4903940) /* 0x4ad404 */);
    // 004269eb  668b1500d44a00         -mov dx, word ptr [0x4ad400]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4903936) /* 0x4ad400 */);
    // 004269f2  66a336165200           -mov word ptr [0x521636], ax
    app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */) = cpu.ax;
    // 004269f8  a0fcd34a00             -mov al, byte ptr [0x4ad3fc]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4903932) /* 0x4ad3fc */);
    // 004269fd  66890d38165200         -mov word ptr [0x521638], cx
    app->getMemory<x86::reg16>(x86::reg32(5379640) /* 0x521638 */) = cpu.cx;
    // 00426a04  6689153a165200         -mov word ptr [0x52163a], dx
    app->getMemory<x86::reg16>(x86::reg32(5379642) /* 0x52163a */) = cpu.dx;
    // 00426a0b  a23c165200             -mov byte ptr [0x52163c], al
    app->getMemory<x86::reg8>(x86::reg32(5379644) /* 0x52163c */) = cpu.al;
L_0x00426a10:
    // 00426a10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00426a11:
    // 00426a11  0fbe0d35165200         -movsx ecx, byte ptr [0x521635]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5379637) /* 0x521635 */)));
    // 00426a18  390df0d34a00           +cmp dword ptr [0x4ad3f0], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4903920) /* 0x4ad3f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00426a1e  756c                   -jne 0x426a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00426a8c;
    }
    // 00426a20  a108d44a00             -mov eax, dword ptr [0x4ad408]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903944) /* 0x4ad408 */);
    // 00426a25  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00426a27  668b1536165200         -mov dx, word ptr [0x521636]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */);
    // 00426a2e  3bc2                   +cmp eax, edx
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
    // 00426a30  755a                   -jne 0x426a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00426a8c;
    }
    // 00426a32  a138165200             -mov eax, dword ptr [0x521638]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379640) /* 0x521638 */);
    // 00426a37  8b0d04d44a00           -mov ecx, dword ptr [0x4ad404]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903940) /* 0x4ad404 */);
    // 00426a3d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00426a42  3bc8                   +cmp ecx, eax
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
    // 00426a44  7546                   -jne 0x426a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00426a8c;
    }
    // 00426a46  a100d44a00             -mov eax, dword ptr [0x4ad400]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903936) /* 0x4ad400 */);
    // 00426a4b  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00426a4d  668b0d3a165200         -mov cx, word ptr [0x52163a]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5379642) /* 0x52163a */);
    // 00426a54  3bc1                   +cmp eax, ecx
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
    // 00426a56  7534                   -jne 0x426a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00426a8c;
    }
    // 00426a58  a1f4d34a00             -mov eax, dword ptr [0x4ad3f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903924) /* 0x4ad3f4 */);
    // 00426a5d  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00426a5f  8a1533165200           -mov dl, byte ptr [0x521633]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5379635) /* 0x521633 */);
    // 00426a65  3bc2                   +cmp eax, edx
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
    // 00426a67  7523                   -jne 0x426a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00426a8c;
    }
    // 00426a69  a13c165200             -mov eax, dword ptr [0x52163c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379644) /* 0x52163c */);
    // 00426a6e  8b0dfcd34a00           -mov ecx, dword ptr [0x4ad3fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903932) /* 0x4ad3fc */);
    // 00426a74  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00426a79  3bc8                   +cmp ecx, eax
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
    // 00426a7b  750f                   -jne 0x426a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00426a8c;
    }
    // 00426a7d  8b0d0cd44a00           -mov ecx, dword ptr [0x4ad40c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903948) /* 0x4ad40c */);
    // 00426a83  a13d165200             -mov eax, dword ptr [0x52163d]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379645) /* 0x52163d */);
    // 00426a88  3bc8                   +cmp ecx, eax
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
    // 00426a8a  7484                   -je 0x426a10
    if (cpu.flags.zf)
    {
        goto L_0x00426a10;
    }
L_0x00426a8c:
    // 00426a8c  b930394900             -mov ecx, 0x493930
    cpu.ecx = 4798768 /*0x493930*/;
    // 00426a91  e81a4c0300             -call 0x45b6b0
    cpu.esp -= 4;
    sub_45b6b0(app, cpu);
    // 00426a96  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 00426a9b  e940f5ffff             -jmp 0x425fe0
    return sub_425fe0(app, cpu);
}

/* align: skip  */
void Application::sub_426aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00426aa0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00426aa1  6854010000             -push 0x154
    app->getMemory<x86::reg32>(cpu.esp-4) = 340 /*0x154*/;
    cpu.esp -= 4;
    // 00426aa6  e8cf070500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00426aab  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00426aad  b955000000             -mov ecx, 0x55
    cpu.ecx = 85 /*0x55*/;
    // 00426ab2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00426ab4  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00426ab6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00426ab9  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00426abb  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00426abd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00426abe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_426ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00426ac0  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00426ac3  83f807                 +cmp eax, 7
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
    // 00426ac6  771f                   -ja 0x426ae7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00426ae7;
    }
    // 00426ac8  ff2485f06a4200         -jmp dword ptr [eax*4 + 0x426af0]
    cpu.ip = app->getMemory<x86::reg32>(4352752 + cpu.eax * 4); goto dynamic_jump;
  case 0x00426acf:
    // 00426acf  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00426ad4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426ad5:
    // 00426ad5  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00426ada  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426adb:
    // 00426adb  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00426ae0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426ae1:
    // 00426ae1  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00426ae6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00426ae7:
L_0x00426ae7:
    // 00426ae7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00426aec  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

}
