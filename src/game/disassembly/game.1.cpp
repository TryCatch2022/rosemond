#include "game.h"
namespace game
{

/* align: skip  */
void Application::asm_sub_4098a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004098a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004098a1  8b3520bb4a00           -mov esi, dword ptr [0x4abb20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 004098a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004098a9  0f8494000000           -je 0x409943
    if (cpu.flags.zf)
    {
        goto L_0x00409943;
    }
    // 004098af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004098b0:
    // 004098b0  d986b4040000           -fld dword ptr [esi + 0x4b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(1204) /* 0x4b4 */)));
    // 004098b6  d89eb8040000           -fcomp dword ptr [esi + 0x4b8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(1208) /* 0x4b8 */)));
    cpu.fpu.pop();
    // 004098bc  8bbe3c050000           -mov edi, dword ptr [esi + 0x53c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1340) /* 0x53c */);
    // 004098c2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004098c4  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004098c9  750c                   -jne 0x4098d7
    if (!cpu.flags.zf)
    {
        goto L_0x004098d7;
    }
    // 004098cb  8b86b8040000           -mov eax, dword ptr [esi + 0x4b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1208) /* 0x4b8 */);
    // 004098d1  8986b4040000           -mov dword ptr [esi + 0x4b4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1204) /* 0x4b4 */) = cpu.eax;
L_0x004098d7:
    // 004098d7  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 004098dd  8b8610050000           -mov eax, dword ptr [esi + 0x510]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1296) /* 0x510 */);
    // 004098e3  3bc8                   +cmp ecx, eax
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
    // 004098e5  7c18                   -jl 0x4098ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004098ff;
    }
    // 004098e7  8b8614050000           -mov eax, dword ptr [esi + 0x514]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1300) /* 0x514 */);
    // 004098ed  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004098ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004098f1  7e05                   -jle 0x4098f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004098f8;
    }
    // 004098f3  83caff                 +or edx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004098f6  eb02                   -jmp 0x4098fa
    goto L_0x004098fa;
L_0x004098f8:
    // 004098f8  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004098fa:
    // 004098fa  e841ffffff             -call 0x409840
    cpu.esp -= 4;
    sub_409840(app, cpu);
L_0x004098ff:
    // 004098ff  8b8ee0040000           -mov ecx, dword ptr [esi + 0x4e0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1248) /* 0x4e0 */);
    // 00409905  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00409907  7418                   -je 0x409921
    if (cpu.flags.zf)
    {
        goto L_0x00409921;
    }
    // 00409909  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0040990e  e87dddffff             -call 0x407690
    cpu.esp -= 4;
    sub_407690(app, cpu);
    // 00409913  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409915  740a                   -je 0x409921
    if (cpu.flags.zf)
    {
        goto L_0x00409921;
    }
    // 00409917  c786e004000000000000   -mov dword ptr [esi + 0x4e0], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1248) /* 0x4e0 */) = 0 /*0x0*/;
L_0x00409921:
    // 00409921  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00409923  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 00409928  e863ddffff             -call 0x407690
    cpu.esp -= 4;
    sub_407690(app, cpu);
    // 0040992d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040992f  7507                   -jne 0x409938
    if (!cpu.flags.zf)
    {
        goto L_0x00409938;
    }
    // 00409931  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00409933  e858fdffff             -call 0x409690
    cpu.esp -= 4;
    sub_409690(app, cpu);
L_0x00409938:
    // 00409938  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040993a  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0040993c  0f856effffff           -jne 0x4098b0
    if (!cpu.flags.zf)
    {
        goto L_0x004098b0;
    }
    // 00409942  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00409943:
    // 00409943  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409944  e9b7ddffff             -jmp 0x407700
    return sub_407700(app, cpu);
}

/* align: skip  */
void Application::asm_sub_409950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00409950  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00409953  a160ba5100             -mov eax, dword ptr [0x51ba60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */);
    // 00409958  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00409959  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040995a  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040995c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00409961  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409962  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00409964  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040996a  891d60ba5100           -mov dword ptr [0x51ba60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */) = cpu.ebx;
    // 00409970  8b8e80000000           -mov ecx, dword ptr [esi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00409976  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0040997a  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0040997e  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00409981  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00409985  8b8818030000           -mov ecx, dword ptr [eax + 0x318]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 0040998b  e800e80500             -call 0x468190
    cpu.esp -= 4;
    sub_468190(app, cpu);
    // 00409990  8b8680020000           -mov eax, dword ptr [esi + 0x280]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(640) /* 0x280 */);
    // 00409996  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0040999a  3bc3                   +cmp eax, ebx
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
    // 0040999c  0f8eaf000000           -jle 0x409a51
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00409a51;
    }
    // 004099a2  8d8e84000000           -lea ecx, [esi + 0x84]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004099a8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004099a9  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x004099ad:
    // 004099ad  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004099b1  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004099b7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004099b9  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004099bc  8b9a18030000           -mov ebx, dword ptr [edx + 0x318]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(792) /* 0x318 */);
    // 004099c2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004099c4  7463                   -je 0x409a29
    if (cpu.flags.zf)
    {
        goto L_0x00409a29;
    }
    // 004099c6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004099c8  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004099ca  0fbe0e                 -movsx ecx, byte ptr [esi]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 004099cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004099ce  e8cada0600             -call 0x47749d
    cpu.esp -= 4;
    sub_47749d(app, cpu);
    // 004099d3  0fbe17                 -movsx edx, byte ptr [edi]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edi)));
    // 004099d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004099d7  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004099d9  e8bfda0600             -call 0x47749d
    cpu.esp -= 4;
    sub_47749d(app, cpu);
    // 004099de  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004099e1  3be8                   +cmp ebp, eax
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
    // 004099e3  752d                   -jne 0x409a12
    if (!cpu.flags.zf)
    {
        goto L_0x00409a12;
    }
L_0x004099e5:
    // 004099e5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004099e7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004099e9  7427                   -je 0x409a12
    if (cpu.flags.zf)
    {
        goto L_0x00409a12;
    }
    // 004099eb  803f00                 +cmp byte ptr [edi], 0
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
    // 004099ee  7422                   -je 0x409a12
    if (cpu.flags.zf)
    {
        goto L_0x00409a12;
    }
    // 004099f0  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004099f2  741e                   -je 0x409a12
    if (cpu.flags.zf)
    {
        goto L_0x00409a12;
    }
    // 004099f4  0fbe4701               -movsx eax, byte ptr [edi + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */)));
    // 004099f8  46                     -inc esi
    (cpu.esi)++;
    // 004099f9  47                     -inc edi
    (cpu.edi)++;
    // 004099fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004099fb  e89dda0600             -call 0x47749d
    cpu.esp -= 4;
    sub_47749d(app, cpu);
    // 00409a00  0fbe0e                 -movsx ecx, byte ptr [esi]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 00409a03  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409a04  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00409a06  e892da0600             -call 0x47749d
    cpu.esp -= 4;
    sub_47749d(app, cpu);
    // 00409a0b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00409a0e  3bc5                   +cmp eax, ebp
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
    // 00409a10  74d3                   -je 0x4099e5
    if (cpu.flags.zf)
    {
        goto L_0x004099e5;
    }
L_0x00409a12:
    // 00409a12  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00409a14  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00409a16  3ad0                   +cmp dl, al
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
    // 00409a18  7507                   -jne 0x409a21
    if (!cpu.flags.zf)
    {
        goto L_0x00409a21;
    }
    // 00409a1a  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00409a1c  e86fe70500             -call 0x468190
    cpu.esp -= 4;
    sub_468190(app, cpu);
L_0x00409a21:
    // 00409a21  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00409a25  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x00409a29:
    // 00409a29  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00409a2d  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00409a31  8b8e80020000           -mov ecx, dword ptr [esi + 0x280]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(640) /* 0x280 */);
    // 00409a37  40                     -inc eax
    (cpu.eax)++;
    // 00409a38  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00409a3b  3bc1                   +cmp eax, ecx
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
    // 00409a3d  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00409a41  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00409a45  0f8c62ffffff           -jl 0x4099ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004099ad;
    }
    // 00409a4b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00409a50  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00409a51:
    // 00409a51  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00409a55  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00409a5b  a360ba5100             -mov dword ptr [0x51ba60], eax
    app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */) = cpu.eax;
    // 00409a60  8b8e84000000           -mov ecx, dword ptr [esi + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00409a66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00409a67  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00409a6a  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00409a6c  e82fe20500             -call 0x467ca0
    cpu.esp -= 4;
    sub_467ca0(app, cpu);
    // 00409a71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409a72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409a73  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409a74  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00409a77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_409a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00409a80  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00409a82  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00409a84  740c                   -je 0x409a92
    if (cpu.flags.zf)
    {
        goto L_0x00409a92;
    }
L_0x00409a86:
    // 00409a86  2c78                   -sub al, 0x78
    (cpu.al) -= x86::reg8(x86::sreg8(120 /*0x78*/));
    // 00409a88  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00409a8a  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00409a8d  41                     -inc ecx
    (cpu.ecx)++;
    // 00409a8e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00409a90  75f4                   -jne 0x409a86
    if (!cpu.flags.zf)
    {
        goto L_0x00409a86;
    }
L_0x00409a92:
    // 00409a92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_409aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00409aa0  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00409aa2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00409aa4  740c                   -je 0x409ab2
    if (cpu.flags.zf)
    {
        goto L_0x00409ab2;
    }
L_0x00409aa6:
    // 00409aa6  0478                   -add al, 0x78
    (cpu.al) += x86::reg8(x86::sreg8(120 /*0x78*/));
    // 00409aa8  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00409aaa  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00409aad  41                     -inc ecx
    (cpu.ecx)++;
    // 00409aae  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00409ab0  75f4                   -jne 0x409aa6
    if (!cpu.flags.zf)
    {
        goto L_0x00409aa6;
    }
L_0x00409ab2:
    // 00409ab2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_409ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00409ac0  a144bb4a00             -mov eax, dword ptr [0x4abb44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897604) /* 0x4abb44 */);
    // 00409ac5  81eca0000000           -sub esp, 0xa0
    (cpu.esp) -= x86::reg32(x86::sreg32(160 /*0xa0*/));
    // 00409acb  83f801                 +cmp eax, 1
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
    // 00409ace  0f8449040000           -je 0x409f1d
    if (cpu.flags.zf)
    {
        goto L_0x00409f1d;
    }
    // 00409ad4  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 00409ad9  c70544bb4a0001000000   -mov dword ptr [0x4abb44], 1
    app->getMemory<x86::reg32>(x86::reg32(4897604) /* 0x4abb44 */) = 1 /*0x1*/;
    // 00409ae3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409ae5  b950c74800             -mov ecx, 0x48c750
    cpu.ecx = 4769616 /*0x48c750*/;
    // 00409aea  7405                   -je 0x409af1
    if (cpu.flags.zf)
    {
        goto L_0x00409af1;
    }
    // 00409aec  b944c74800             -mov ecx, 0x48c744
    cpu.ecx = 4769604 /*0x48c744*/;
L_0x00409af1:
    // 00409af1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409af2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409af3  ba40c74800             -mov edx, 0x48c740
    cpu.edx = 4769600 /*0x48c740*/;
    // 00409af8  e8432f0400             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00409afd  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00409aff  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 00409b04  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00409b06  b934c74800             -mov ecx, 0x48c734
    cpu.ecx = 4769588 /*0x48c734*/;
    // 00409b0b  7420                   -je 0x409b2d
    if (cpu.flags.zf)
    {
        goto L_0x00409b2d;
    }
    // 00409b0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409b0f  7405                   -je 0x409b16
    if (cpu.flags.zf)
    {
        goto L_0x00409b16;
    }
    // 00409b11  b928c74800             -mov ecx, 0x48c728
    cpu.ecx = 4769576 /*0x48c728*/;
L_0x00409b16:
    // 00409b16  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 00409b1b  e8202f0400             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00409b20  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00409b22  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00409b24  752d                   -jne 0x409b53
    if (!cpu.flags.zf)
    {
        goto L_0x00409b53;
    }
    // 00409b26  680cc74800             -push 0x48c70c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769548 /*0x48c70c*/;
    cpu.esp -= 4;
    // 00409b2b  eb1e                   -jmp 0x409b4b
    goto L_0x00409b4b;
L_0x00409b2d:
    // 00409b2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409b2f  7405                   -je 0x409b36
    if (cpu.flags.zf)
    {
        goto L_0x00409b36;
    }
    // 00409b31  b928c74800             -mov ecx, 0x48c728
    cpu.ecx = 4769576 /*0x48c728*/;
L_0x00409b36:
    // 00409b36  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 00409b3b  e8002f0400             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00409b40  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00409b42  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00409b44  750d                   -jne 0x409b53
    if (!cpu.flags.zf)
    {
        goto L_0x00409b53;
    }
    // 00409b46  68f4c64800             -push 0x48c6f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769524 /*0x48c6f4*/;
    cpu.esp -= 4;
L_0x00409b4b:
    // 00409b4b  e8c0b00100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409b50  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00409b53:
    // 00409b53  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409b58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00409b59  b310                   -mov bl, 0x10
    cpu.bl = 16 /*0x10*/;
L_0x00409b5b:
    // 00409b5b  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409b5e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00409b60  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409b63  c60495408f4a0002       -mov byte ptr [edx*4 + 0x4a8f40], 2
    app->getMemory<x86::reg8>(x86::reg32(4886336) /* 0x4a8f40 */ + cpu.edx * 4) = 2 /*0x2*/;
    // 00409b6b  7438                   -je 0x409ba5
    if (cpu.flags.zf)
    {
        goto L_0x00409ba5;
    }
    // 00409b6d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409b6e  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00409b72  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409b74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409b75  e85edd0600             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00409b7a  8a470c                 -mov al, byte ptr [edi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00409b7d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00409b80  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 00409b82  0f8568030000           -jne 0x409ef0
    if (!cpu.flags.zf)
    {
        goto L_0x00409ef0;
    }
    // 00409b88  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409b8c  e80fffffff             -call 0x409aa0
    cpu.esp -= 4;
    sub_409aa0(app, cpu);
    // 00409b91  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409b95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409b96  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00409b98  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409b9a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409b9b  e8ffdb0600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00409ba0  83c410                 +add esp, 0x10
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
    // 00409ba3  eb1d                   -jmp 0x409bc2
    goto L_0x00409bc2;
L_0x00409ba5:
    // 00409ba5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409ba6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00409ba8  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00409bac  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409bae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409baf  e8d4da0600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00409bb4  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00409bb7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00409bba  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 00409bbc  0f8537030000           -jne 0x409ef9
    if (!cpu.flags.zf)
    {
        goto L_0x00409ef9;
    }
L_0x00409bc2:
    // 00409bc2  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409bc6  e8b5feffff             -call 0x409a80
    cpu.esp -= 4;
    sub_409a80(app, cpu);
    // 00409bcb  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409bd0  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409bd3  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409bd6  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409bda  8d0495208f4a00         -lea eax, [edx*4 + 0x4a8f20]
    cpu.eax = x86::reg32(x86::reg32(4886304) /* 0x4a8f20 */ + cpu.edx * 4);
    // 00409be1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409be2  68ecc64800             -push 0x48c6ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769516 /*0x48c6ec*/;
    cpu.esp -= 4;
    // 00409be7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409be8  e867da0600             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00409bed  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00409bf0  83f801                 +cmp eax, 1
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
    // 00409bf3  7418                   -je 0x409c0d
    if (cpu.flags.zf)
    {
        goto L_0x00409c0d;
    }
    // 00409bf5  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409bfa  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409bfe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409bff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409c00  68c0c64800             -push 0x48c6c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769472 /*0x48c6c0*/;
    cpu.esp -= 4;
    // 00409c05  e806b00100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409c0a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00409c0d:
    // 00409c0d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00409c0f  7454                   -je 0x409c65
    if (cpu.flags.zf)
    {
        goto L_0x00409c65;
    }
    // 00409c11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409c12  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00409c16  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409c18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409c19  e8badc0600             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00409c1e  8a470c                 -mov al, byte ptr [edi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00409c21  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00409c24  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 00409c26  7420                   -je 0x409c48
    if (cpu.flags.zf)
    {
        goto L_0x00409c48;
    }
    // 00409c28  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409c2d  8d1480                 -lea edx, [eax + eax*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409c30  8d0450                 -lea eax, [eax + edx*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 2);
    // 00409c33  8d0c85208f4a00         -lea ecx, [eax*4 + 0x4a8f20]
    cpu.ecx = x86::reg32(x86::reg32(4886304) /* 0x4a8f20 */ + cpu.eax * 4);
    // 00409c3a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409c3b  68a8c64800             -push 0x48c6a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769448 /*0x48c6a8*/;
    cpu.esp -= 4;
    // 00409c40  e8cbaf0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409c45  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00409c48:
    // 00409c48  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409c4c  e84ffeffff             -call 0x409aa0
    cpu.esp -= 4;
    sub_409aa0(app, cpu);
    // 00409c51  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409c55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409c56  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00409c58  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409c5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409c5b  e83fdb0600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00409c60  83c410                 +add esp, 0x10
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
    // 00409c63  eb26                   -jmp 0x409c8b
    goto L_0x00409c8b;
L_0x00409c65:
    // 00409c65  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409c66  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00409c68  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00409c6c  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409c6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409c6f  e814da0600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00409c74  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00409c77  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00409c7a  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 00409c7c  740d                   -je 0x409c8b
    if (cpu.flags.zf)
    {
        goto L_0x00409c8b;
    }
    // 00409c7e  6898c64800             -push 0x48c698
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769432 /*0x48c698*/;
    cpu.esp -= 4;
    // 00409c83  e888af0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409c88  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00409c8b:
    // 00409c8b  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409c8f  e8ecfdffff             -call 0x409a80
    cpu.esp -= 4;
    sub_409a80(app, cpu);
    // 00409c94  8d8c248c000000         -lea ecx, [esp + 0x8c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00409c9b  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409c9f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409ca0  688cc64800             -push 0x48c68c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769420 /*0x48c68c*/;
    cpu.esp -= 4;
    // 00409ca5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409ca6  e8a9d90600             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00409cab  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00409cae  83f801                 +cmp eax, 1
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
    // 00409cb1  0f85ff000000           -jne 0x409db6
    if (!cpu.flags.zf)
    {
        goto L_0x00409db6;
    }
    // 00409cb7  8d84248c000000         -lea eax, [esp + 0x8c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00409cbe  6884c64800             -push 0x48c684
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769412 /*0x48c684*/;
    cpu.esp -= 4;
    // 00409cc3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409cc4  e8e7ae0700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00409cc9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00409ccc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409cce  7515                   -jne 0x409ce5
    if (!cpu.flags.zf)
    {
        goto L_0x00409ce5;
    }
    // 00409cd0  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409cd5  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409cd8  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409cdb  c60495408f4a0000       -mov byte ptr [edx*4 + 0x4a8f40], 0
    app->getMemory<x86::reg8>(x86::reg32(4886336) /* 0x4a8f40 */ + cpu.edx * 4) = 0 /*0x0*/;
    // 00409ce3  eb71                   -jmp 0x409d56
    goto L_0x00409d56;
L_0x00409ce5:
    // 00409ce5  8d84248c000000         -lea eax, [esp + 0x8c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00409cec  687cc64800             -push 0x48c67c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769404 /*0x48c67c*/;
    cpu.esp -= 4;
    // 00409cf1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409cf2  e8b9ae0700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00409cf7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00409cfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409cfc  7515                   -jne 0x409d13
    if (!cpu.flags.zf)
    {
        goto L_0x00409d13;
    }
    // 00409cfe  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409d03  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409d06  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409d09  c60495408f4a0001       -mov byte ptr [edx*4 + 0x4a8f40], 1
    app->getMemory<x86::reg8>(x86::reg32(4886336) /* 0x4a8f40 */ + cpu.edx * 4) = 1 /*0x1*/;
    // 00409d11  eb43                   -jmp 0x409d56
    goto L_0x00409d56;
L_0x00409d13:
    // 00409d13  8d84248c000000         -lea eax, [esp + 0x8c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00409d1a  6874c64800             -push 0x48c674
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769396 /*0x48c674*/;
    cpu.esp -= 4;
    // 00409d1f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409d20  e88bae0700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00409d25  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00409d28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409d2a  7515                   -jne 0x409d41
    if (!cpu.flags.zf)
    {
        goto L_0x00409d41;
    }
    // 00409d2c  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409d31  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409d34  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409d37  c60495408f4a0002       -mov byte ptr [edx*4 + 0x4a8f40], 2
    app->getMemory<x86::reg8>(x86::reg32(4886336) /* 0x4a8f40 */ + cpu.edx * 4) = 2 /*0x2*/;
    // 00409d3f  eb15                   -jmp 0x409d56
    goto L_0x00409d56;
L_0x00409d41:
    // 00409d41  8d84248c000000         -lea eax, [esp + 0x8c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00409d48  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409d49  6854c64800             -push 0x48c654
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769364 /*0x48c654*/;
    cpu.esp -= 4;
    // 00409d4e  e8bdae0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409d53  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00409d56:
    // 00409d56  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00409d58  742d                   -je 0x409d87
    if (cpu.flags.zf)
    {
        goto L_0x00409d87;
    }
    // 00409d5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409d5b  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00409d5f  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409d61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409d62  e871db0600             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00409d67  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00409d6a  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409d6e  e82dfdffff             -call 0x409aa0
    cpu.esp -= 4;
    sub_409aa0(app, cpu);
    // 00409d73  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409d77  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409d78  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00409d7a  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409d7c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409d7d  e81dda0600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00409d82  83c410                 +add esp, 0x10
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
    // 00409d85  eb26                   -jmp 0x409dad
    goto L_0x00409dad;
L_0x00409d87:
    // 00409d87  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409d88  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00409d8a  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00409d8e  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409d90  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409d91  e8f2d80600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00409d96  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00409d99  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00409d9c  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 00409d9e  740d                   -je 0x409dad
    if (cpu.flags.zf)
    {
        goto L_0x00409dad;
    }
    // 00409da0  6898c64800             -push 0x48c698
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769432 /*0x48c698*/;
    cpu.esp -= 4;
    // 00409da5  e866ae0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409daa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00409dad:
    // 00409dad  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409db1  e8cafcffff             -call 0x409a80
    cpu.esp -= 4;
    sub_409a80(app, cpu);
L_0x00409db6:
    // 00409db6  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409dbb  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409dbe  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409dc1  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409dc5  8d0495448f4a00         -lea eax, [edx*4 + 0x4a8f44]
    cpu.eax = x86::reg32(x86::reg32(4886340) /* 0x4a8f44 */ + cpu.edx * 4);
    // 00409dcc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409dcd  6848c64800             -push 0x48c648
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769352 /*0x48c648*/;
    cpu.esp -= 4;
    // 00409dd2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409dd3  e87cd80600             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00409dd8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00409ddb  83f801                 +cmp eax, 1
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
    // 00409dde  7425                   -je 0x409e05
    if (cpu.flags.zf)
    {
        goto L_0x00409e05;
    }
    // 00409de0  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409de5  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409de9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409dea  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409ded  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409df0  8d0495208f4a00         -lea eax, [edx*4 + 0x4a8f20]
    cpu.eax = x86::reg32(x86::reg32(4886304) /* 0x4a8f20 */ + cpu.edx * 4);
    // 00409df7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409df8  6820c64800             -push 0x48c620
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769312 /*0x48c620*/;
    cpu.esp -= 4;
    // 00409dfd  e80eae0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409e02  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00409e05:
    // 00409e05  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00409e07  7459                   -je 0x409e62
    if (cpu.flags.zf)
    {
        goto L_0x00409e62;
    }
    // 00409e09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409e0a  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00409e0e  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409e10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409e11  e8c2da0600             -call 0x4778d8
    cpu.esp -= 4;
    sub_4778d8(app, cpu);
    // 00409e16  8a470c                 -mov al, byte ptr [edi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00409e19  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00409e1c  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 00409e1e  7425                   -je 0x409e45
    if (cpu.flags.zf)
    {
        goto L_0x00409e45;
    }
    // 00409e20  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409e25  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409e29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409e2a  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409e2d  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409e30  8d0495208f4a00         -lea eax, [edx*4 + 0x4a8f20]
    cpu.eax = x86::reg32(x86::reg32(4886304) /* 0x4a8f20 */ + cpu.edx * 4);
    // 00409e37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409e38  68f4c54800             -push 0x48c5f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769268 /*0x48c5f4*/;
    cpu.esp -= 4;
    // 00409e3d  e8cead0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409e42  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00409e45:
    // 00409e45  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409e49  e852fcffff             -call 0x409aa0
    cpu.esp -= 4;
    sub_409aa0(app, cpu);
    // 00409e4e  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409e52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409e53  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00409e55  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409e57  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409e58  e842d90600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00409e5d  83c410                 +add esp, 0x10
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
    // 00409e60  eb26                   -jmp 0x409e88
    goto L_0x00409e88;
L_0x00409e62:
    // 00409e62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409e63  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00409e65  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00409e69  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00409e6b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409e6c  e817d80600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00409e71  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00409e74  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00409e77  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 00409e79  740d                   -je 0x409e88
    if (cpu.flags.zf)
    {
        goto L_0x00409e88;
    }
    // 00409e7b  6898c64800             -push 0x48c698
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769432 /*0x48c698*/;
    cpu.esp -= 4;
    // 00409e80  e88bad0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409e85  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00409e88:
    // 00409e88  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409e8c  e8effbffff             -call 0x409a80
    cpu.esp -= 4;
    sub_409a80(app, cpu);
    // 00409e91  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409e96  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409e99  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409e9c  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409ea0  8d0495488f4a00         -lea eax, [edx*4 + 0x4a8f48]
    cpu.eax = x86::reg32(x86::reg32(4886344) /* 0x4a8f48 */ + cpu.edx * 4);
    // 00409ea7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409ea8  68e4c54800             -push 0x48c5e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769252 /*0x48c5e4*/;
    cpu.esp -= 4;
    // 00409ead  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409eae  e8a1d70600             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 00409eb3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00409eb6  83f801                 +cmp eax, 1
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
    // 00409eb9  7425                   -je 0x409ee0
    if (cpu.flags.zf)
    {
        goto L_0x00409ee0;
    }
    // 00409ebb  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409ec0  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00409ec4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00409ec5  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00409ec8  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 00409ecb  8d0495208f4a00         -lea eax, [edx*4 + 0x4a8f20]
    cpu.eax = x86::reg32(x86::reg32(4886304) /* 0x4a8f20 */ + cpu.edx * 4);
    // 00409ed2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00409ed3  68f4c54800             -push 0x48c5f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769268 /*0x48c5f4*/;
    cpu.esp -= 4;
    // 00409ed8  e833ad0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00409edd  83c40c                 +add esp, 0xc
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
L_0x00409ee0:
    // 00409ee0  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409ee5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00409ee6  a340bb4a00             -mov dword ptr [0x4abb40], eax
    app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */) = cpu.eax;
    // 00409eeb  e96bfcffff             -jmp 0x409b5b
    goto L_0x00409b5b;
L_0x00409ef0:
    // 00409ef0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409ef1  e8e1d60600             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00409ef6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00409ef9:
    // 00409ef9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00409efb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409efc  7409                   -je 0x409f07
    if (cpu.flags.zf)
    {
        goto L_0x00409f07;
    }
    // 00409efe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409eff  e8d3d60600             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00409f04  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00409f07:
    // 00409f07  8b0d40bb4a00           -mov ecx, dword ptr [0x4abb40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409f0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00409f0e  68d4c54800             -push 0x48c5d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769236 /*0x48c5d4*/;
    cpu.esp -= 4;
    // 00409f13  e89fce0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00409f18  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00409f1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409f1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00409f1d:
    // 00409f1d  81c4a0000000           -add esp, 0xa0
    (cpu.esp) += x86::reg32(x86::sreg32(160 /*0xa0*/));
    // 00409f23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_409f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00409f30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409f31  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00409f33  e828bd0400             -call 0x455c60
    cpu.esp -= 4;
    sub_455c60(app, cpu);
    // 00409f38  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00409f3a  3bc2                   +cmp eax, edx
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
    // 00409f3c  7417                   -je 0x409f55
    if (cpu.flags.zf)
    {
        goto L_0x00409f55;
    }
    // 00409f3e  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00409f40:
    // 00409f40  397030                 +cmp dword ptr [eax + 0x30], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00409f43  7506                   -jne 0x409f4b
    if (!cpu.flags.zf)
    {
        goto L_0x00409f4b;
    }
    // 00409f45  884834                 -mov byte ptr [eax + 0x34], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.cl;
    // 00409f48  895030                 -mov dword ptr [eax + 0x30], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.edx;
L_0x00409f4b:
    // 00409f4b  8b8030030000           -mov eax, dword ptr [eax + 0x330]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(816) /* 0x330 */);
    // 00409f51  3bc2                   +cmp eax, edx
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
    // 00409f53  75eb                   -jne 0x409f40
    if (!cpu.flags.zf)
    {
        goto L_0x00409f40;
    }
L_0x00409f55:
    // 00409f55  a120bb4a00             -mov eax, dword ptr [0x4abb20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 00409f5a  3bc2                   +cmp eax, edx
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
    // 00409f5c  7418                   -je 0x409f76
    if (cpu.flags.zf)
    {
        goto L_0x00409f76;
    }
L_0x00409f5e:
    // 00409f5e  39b0e0040000           +cmp dword ptr [eax + 0x4e0], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1248) /* 0x4e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00409f64  7506                   -jne 0x409f6c
    if (!cpu.flags.zf)
    {
        goto L_0x00409f6c;
    }
    // 00409f66  8990e0040000           -mov dword ptr [eax + 0x4e0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1248) /* 0x4e0 */) = cpu.edx;
L_0x00409f6c:
    // 00409f6c  8b803c050000           -mov eax, dword ptr [eax + 0x53c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1340) /* 0x53c */);
    // 00409f72  3bc2                   +cmp eax, edx
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
    // 00409f74  75e8                   -jne 0x409f5e
    if (!cpu.flags.zf)
    {
        goto L_0x00409f5e;
    }
L_0x00409f76:
    // 00409f76  b8801c5200             -mov eax, 0x521c80
    cpu.eax = 5381248 /*0x521c80*/;
L_0x00409f7b:
    // 00409f7b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00409f7d  3bca                   +cmp ecx, edx
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
    // 00409f7f  7406                   -je 0x409f87
    if (cpu.flags.zf)
    {
        goto L_0x00409f87;
    }
    // 00409f81  3bce                   +cmp ecx, esi
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
    // 00409f83  7502                   -jne 0x409f87
    if (!cpu.flags.zf)
    {
        goto L_0x00409f87;
    }
    // 00409f85  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00409f87:
    // 00409f87  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00409f8a  3da81c5200             +cmp eax, 0x521ca8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5381288 /*0x521ca8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00409f8f  7cea                   -jl 0x409f7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00409f7b;
    }
    // 00409f91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_409fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00409fa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00409fa1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00409fa2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00409fa3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409fa4  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00409fa6  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00409fa8  e813fbffff             -call 0x409ac0
    cpu.esp -= 4;
    sub_409ac0(app, cpu);
    // 00409fad  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409fb2  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00409fb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409fb6  7e77                   -jle 0x40a02f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040a02f;
    }
    // 00409fb8  bf208f4a00             -mov edi, 0x4a8f20
    cpu.edi = 4886304 /*0x4a8f20*/;
L_0x00409fbd:
    // 00409fbd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00409fbe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00409fbf  e8ecab0700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00409fc4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00409fc7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00409fc9  7414                   -je 0x409fdf
    if (cpu.flags.zf)
    {
        goto L_0x00409fdf;
    }
    // 00409fcb  a140bb4a00             -mov eax, dword ptr [0x4abb40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897600) /* 0x4abb40 */);
    // 00409fd0  46                     -inc esi
    (cpu.esi)++;
    // 00409fd1  83c72c                 -add edi, 0x2c
    (cpu.edi) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00409fd4  3bf0                   +cmp esi, eax
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
    // 00409fd6  7ce5                   -jl 0x409fbd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00409fbd;
    }
    // 00409fd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409fd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409fda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409fdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00409fdc  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00409fdf:
    // 00409fdf  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00409fe3  8d04b6                 -lea eax, [esi + esi*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 4);
    // 00409fe6  8d0446                 -lea eax, [esi + eax*2]
    cpu.eax = x86::reg32(cpu.esi + cpu.eax * 2);
    // 00409fe9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00409fec  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00409fee  668b88448f4a00         -mov cx, word ptr [eax + 0x4a8f44]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4886340) /* 0x4a8f44 */);
    // 00409ff5  66898a8a020000         -mov word ptr [edx + 0x28a], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(650) /* 0x28a */) = cpu.cx;
    // 00409ffc  66898a8c020000         -mov word ptr [edx + 0x28c], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(652) /* 0x28c */) = cpu.cx;
    // 0040a003  66898a8e020000         -mov word ptr [edx + 0x28e], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(654) /* 0x28e */) = cpu.cx;
    // 0040a00a  8a88408f4a00           -mov cl, byte ptr [eax + 0x4a8f40]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4886336) /* 0x4a8f40 */);
    // 0040a010  888a88020000           -mov byte ptr [edx + 0x288], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(648) /* 0x288 */) = cpu.cl;
    // 0040a016  7417                   -je 0x40a02f
    if (cpu.flags.zf)
    {
        goto L_0x0040a02f;
    }
    // 0040a018  d980488f4a00           -fld dword ptr [eax + 0x4a8f48]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4886344) /* 0x4a8f48 */)));
    // 0040a01e  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 0040a024  e867cd0600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040a029  898514050000           -mov dword ptr [ebp + 0x514], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1300) /* 0x514 */) = cpu.eax;
L_0x0040a02f:
    // 0040a02f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a030  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a031  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a033  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40a040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040a040  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0040a043  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a044  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040a045  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a046  8d44240f               -lea eax, [esp + 0xf]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 0040a04a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a04b  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 0040a04f  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0040a051  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040a053  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a054  6a2e                   -push 0x2e
    app->getMemory<x86::reg32>(cpu.esp-4) = 46 /*0x2e*/;
    cpu.esp -= 4;
    // 0040a056  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040a05a  896c2424               -mov dword ptr [esp + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 0040a05e  885c241b               -mov byte ptr [esp + 0x1b], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(27) /* 0x1b */) = cpu.bl;
    // 0040a062  e869e10500             -call 0x4681d0
    cpu.esp -= 4;
    sub_4681d0(app, cpu);
    // 0040a067  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040a06b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a06c  6804b94800             -push 0x48b904
    app->getMemory<x86::reg32>(cpu.esp-4) = 4765956 /*0x48b904*/;
    cpu.esp -= 4;
    // 0040a071  e83aab0700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0040a076  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a079  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a07b  750d                   -jne 0x40a08a
    if (!cpu.flags.zf)
    {
        goto L_0x0040a08a;
    }
    // 0040a07d  e87e920100             -call 0x423300
    cpu.esp -= 4;
    sub_423300(app, cpu);
    // 0040a082  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0040a084  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0040a088  eb4b                   -jmp 0x40a0d5
    goto L_0x0040a0d5;
L_0x0040a08a:
    // 0040a08a  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040a08c  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
L_0x0040a090:
    // 0040a090  8b14bd80d14900         -mov edx, dword ptr [edi*4 + 0x49d180]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4837760) /* 0x49d180 */ + cpu.edi * 4);
    // 0040a097  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040a09b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a09c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a09d  e80eab0700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0040a0a2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a0a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a0a7  7406                   -je 0x40a0af
    if (cpu.flags.zf)
    {
        goto L_0x0040a0af;
    }
    // 0040a0a9  47                     -inc edi
    (cpu.edi)++;
    // 0040a0aa  83ff21                 +cmp edi, 0x21
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040a0ad  7ce1                   -jl 0x40a090
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040a090;
    }
L_0x0040a0af:
    // 0040a0af  83ff21                 +cmp edi, 0x21
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040a0b2  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0040a0b6  751d                   -jne 0x40a0d5
    if (!cpu.flags.zf)
    {
        goto L_0x0040a0d5;
    }
    // 0040a0b8  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040a0bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040a0bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a0be  68c4c74800             -push 0x48c7c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769732 /*0x48c7c4*/;
    cpu.esp -= 4;
    // 0040a0c3  e8efcc0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a0c8  68a8c74800             -push 0x48c7a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769704 /*0x48c7a8*/;
    cpu.esp -= 4;
    // 0040a0cd  e83eab0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a0d2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0040a0d5:
    // 0040a0d5  6840050000             -push 0x540
    app->getMemory<x86::reg32>(cpu.esp-4) = 1344 /*0x540*/;
    cpu.esp -= 4;
    // 0040a0da  e89bd10600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040a0df  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040a0e1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040a0e4  3bf3                   +cmp esi, ebx
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
    // 0040a0e6  750d                   -jne 0x40a0f5
    if (!cpu.flags.zf)
    {
        goto L_0x0040a0f5;
    }
    // 0040a0e8  688cc74800             -push 0x48c78c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769676 /*0x48c78c*/;
    cpu.esp -= 4;
    // 0040a0ed  e81eab0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a0f2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040a0f5:
    // 0040a0f5  6834030000             -push 0x334
    app->getMemory<x86::reg32>(cpu.esp-4) = 820 /*0x334*/;
    cpu.esp -= 4;
    // 0040a0fa  e87bd10600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040a0ff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040a102  3bc3                   +cmp eax, ebx
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
    // 0040a104  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0040a106  750d                   -jne 0x40a115
    if (!cpu.flags.zf)
    {
        goto L_0x0040a115;
    }
    // 0040a108  688cc74800             -push 0x48c78c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769676 /*0x48c78c*/;
    cpu.esp -= 4;
    // 0040a10d  e8feaa0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a112  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040a115:
    // 0040a115  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0040a119  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0040a11c  8d1480                 -lea edx, [eax + eax*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0040a11f  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0040a122  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a123  e852d10600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040a128  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040a12b  3bc3                   +cmp eax, ebx
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
    // 0040a12d  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0040a130  750d                   -jne 0x40a13f
    if (!cpu.flags.zf)
    {
        goto L_0x0040a13f;
    }
    // 0040a132  686cc74800             -push 0x48c76c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769644 /*0x48c76c*/;
    cpu.esp -= 4;
    // 0040a137  e8d4aa0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a13c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040a13f:
    // 0040a13f  a120bb4a00             -mov eax, dword ptr [0x4abb20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 0040a144  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040a146  89863c050000           -mov dword ptr [esi + 0x53c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1340) /* 0x53c */) = cpu.eax;
    // 0040a14c  893520bb4a00           -mov dword ptr [0x4abb20], esi
    app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */) = cpu.esi;
    // 0040a152  395e18                 +cmp dword ptr [esi + 0x18], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040a155  7e3d                   -jle 0x40a194
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040a194;
    }
    // 0040a157  8b4c2468               -mov ecx, dword ptr [esp + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0040a15b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040a15d  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040a160:
    // 0040a160  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a163  8b69fc                 -mov ebp, dword ptr [ecx - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0040a166  42                     -inc edx
    (cpu.edx)++;
    // 0040a167  83c128                 -add ecx, 0x28
    (cpu.ecx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040a16a  896c3804               -mov dword ptr [eax + edi + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1) = cpu.ebp;
    // 0040a16e  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a171  8b69d8                 -mov ebp, dword ptr [ecx - 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-40) /* -0x28 */);
    // 0040a174  896c3808               -mov dword ptr [eax + edi + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.edi * 1) = cpu.ebp;
    // 0040a178  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a17b  8b69dc                 -mov ebp, dword ptr [ecx - 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-36) /* -0x24 */);
    // 0040a17e  896c380c               -mov dword ptr [eax + edi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edi * 1) = cpu.ebp;
    // 0040a182  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0040a185  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040a188  3bd7                   +cmp edx, edi
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
    // 0040a18a  7cd4                   -jl 0x40a160
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040a160;
    }
    // 0040a18c  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040a190  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0040a194:
    // 0040a194  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a197  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0040a19a  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0040a19d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a19e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040a1a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a1a2  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a1a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a1a5  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040a1a7  e8e4d50400             -call 0x457790
    cpu.esp -= 4;
    sub_457790(app, cpu);
    // 0040a1ac  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a1ae  80484a40               -or byte ptr [eax + 0x4a], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(74) /* 0x4a */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0040a1b2  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a1b4  e807d90400             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 0040a1b9  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0040a1bc  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0040a1c1  3bc7                   +cmp eax, edi
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
    // 0040a1c3  899e38050000           -mov dword ptr [esi + 0x538], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1336) /* 0x538 */) = cpu.ebx;
    // 0040a1c9  7e58                   -jle 0x40a223
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040a223;
    }
    // 0040a1cb  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a1ce  ba0d040000             -mov edx, 0x40d
    cpu.edx = 1037 /*0x40d*/;
    // 0040a1d3  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040a1d7  d9402c                 +fld dword ptr [eax + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */)));
    // 0040a1da  d86004                 +fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0040a1dd  d95c2438               +fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a1e1  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a1e4  d94030                 +fld dword ptr [eax + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(48) /* 0x30 */)));
    // 0040a1e7  d86008                 +fsub dword ptr [eax + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 0040a1ea  d95c243c               +fstp dword ptr [esp + 0x3c]
    app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a1ee  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a1f1  d94034                 +fld dword ptr [eax + 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(52) /* 0x34 */)));
    // 0040a1f4  d8600c                 +fsub dword ptr [eax + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 0040a1f7  c744243c00000000       -mov dword ptr [esp + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 0040a1ff  d95c2440               +fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a203  e848280400             -call 0x44ca50
    cpu.esp -= 4;
    sub_44ca50(app, cpu);
    // 0040a208  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a20a  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040a20e  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040a214  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040a219  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040a21c  e8ff7c0200             -call 0x431f20
    cpu.esp -= 4;
    sub_431f20(app, cpu);
    // 0040a221  eb0e                   -jmp 0x40a231
    goto L_0x0040a231;
L_0x0040a223:
    // 0040a223  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a224  685cc74800             -push 0x48c75c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769628 /*0x48c75c*/;
    cpu.esp -= 4;
    // 0040a229  e8e2a90100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a22e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040a231:
    // 0040a231  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040a233  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0040a235  2bcd                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0040a237  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
L_0x0040a23a:
    // 0040a23a  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0040a23c  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0040a23f  40                     -inc eax
    (cpu.eax)++;
    // 0040a240  3acb                   +cmp cl, bl
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
    // 0040a242  75f6                   -jne 0x40a23a
    if (!cpu.flags.zf)
    {
        goto L_0x0040a23a;
    }
    // 0040a244  0fbe442414             -movsx eax, byte ptr [esp + 0x14]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0040a249  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040a24d  8986c8040000           -mov dword ptr [esi + 0x4c8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1224) /* 0x4c8 */) = cpu.eax;
    // 0040a253  8986c4040000           -mov dword ptr [esi + 0x4c4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1220) /* 0x4c4 */) = cpu.eax;
    // 0040a259  b80000c844             -mov eax, 0x44c80000
    cpu.eax = 1153957888 /*0x44c80000*/;
    // 0040a25e  8986b8040000           -mov dword ptr [esi + 0x4b8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1208) /* 0x4b8 */) = cpu.eax;
    // 0040a264  8986b4040000           -mov dword ptr [esi + 0x4b4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1204) /* 0x4b4 */) = cpu.eax;
    // 0040a26a  b800008040             -mov eax, 0x40800000
    cpu.eax = 1082130432 /*0x40800000*/;
    // 0040a26f  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040a272  898680000000           -mov dword ptr [esi + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0040a278  8986a8000000           -mov dword ptr [esi + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0040a27e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a280  89bec0040000           -mov dword ptr [esi + 0x4c0], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1216) /* 0x4c0 */) = cpu.edi;
    // 0040a286  889e30050000           -mov byte ptr [esi + 0x530], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1328) /* 0x530 */) = cpu.bl;
    // 0040a28c  c786bc04000000004843   -mov dword ptr [esi + 0x4bc], 0x43480000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1212) /* 0x4bc */) = 1128792064 /*0x43480000*/;
    // 0040a296  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0040a299  899eb0040000           -mov dword ptr [esi + 0x4b0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1200) /* 0x4b0 */) = cpu.ebx;
    // 0040a29f  899e24050000           -mov dword ptr [esi + 0x524], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1316) /* 0x524 */) = cpu.ebx;
    // 0040a2a5  899e28050000           -mov dword ptr [esi + 0x528], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1320) /* 0x528 */) = cpu.ebx;
    // 0040a2ab  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0040a2ae  899ecc040000           -mov dword ptr [esi + 0x4cc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1228) /* 0x4cc */) = cpu.ebx;
    // 0040a2b4  899ed0040000           -mov dword ptr [esi + 0x4d0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1232) /* 0x4d0 */) = cpu.ebx;
    // 0040a2ba  c786d40400000000a041   -mov dword ptr [esi + 0x4d4], 0x41a00000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1236) /* 0x4d4 */) = 1101004800 /*0x41a00000*/;
    // 0040a2c4  899ed8040000           -mov dword ptr [esi + 0x4d8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1240) /* 0x4d8 */) = cpu.ebx;
    // 0040a2ca  899e10050000           -mov dword ptr [esi + 0x510], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1296) /* 0x510 */) = cpu.ebx;
    // 0040a2d0  c7861405000048000000   -mov dword ptr [esi + 0x514], 0x48
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1300) /* 0x514 */) = 72 /*0x48*/;
    // 0040a2da  899e18050000           -mov dword ptr [esi + 0x518], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1304) /* 0x518 */) = cpu.ebx;
    // 0040a2e0  899ee0040000           -mov dword ptr [esi + 0x4e0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1248) /* 0x4e0 */) = cpu.ebx;
    // 0040a2e6  898ee4040000           -mov dword ptr [esi + 0x4e4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1252) /* 0x4e4 */) = cpu.ecx;
    // 0040a2ec  0fbf908a020000         -movsx edx, word ptr [eax + 0x28a]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(650) /* 0x28a */)));
    // 0040a2f3  8996dc040000           -mov dword ptr [esi + 0x4dc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1244) /* 0x4dc */) = cpu.edx;
    // 0040a2f9  c7402c02000000         -mov dword ptr [eax + 0x2c], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 2 /*0x2*/;
    // 0040a300  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a302  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a303  895830                 -mov dword ptr [eax + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0040a306  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a308  c6423401               -mov byte ptr [edx + 0x34], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(52) /* 0x34 */) = 1 /*0x1*/;
    // 0040a30c  8b86d8040000           -mov eax, dword ptr [esi + 0x4d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1240) /* 0x4d8 */);
    // 0040a312  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a314  c7862005000000002040   -mov dword ptr [esi + 0x520], 0x40200000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1312) /* 0x520 */) = 1075838976 /*0x40200000*/;
    // 0040a31e  89be1c050000           -mov dword ptr [esi + 0x51c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1308) /* 0x51c */) = cpu.edi;
    // 0040a324  899eec040000           -mov dword ptr [esi + 0x4ec], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1260) /* 0x4ec */) = cpu.ebx;
    // 0040a32a  899ef0040000           -mov dword ptr [esi + 0x4f0], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1264) /* 0x4f0 */) = cpu.ebx;
    // 0040a330  899ef4040000           -mov dword ptr [esi + 0x4f4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1268) /* 0x4f4 */) = cpu.ebx;
    // 0040a336  8b948280000000         -mov edx, dword ptr [edx + eax*4 + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */ + cpu.eax * 4);
    // 0040a33d  e89e840200             -call 0x4327e0
    cpu.esp -= 4;
    sub_4327e0(app, cpu);
    // 0040a342  dc0d80744800           -fmul qword ptr [0x487480]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748416) /* 0x487480 */));
    // 0040a348  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a34a  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0040a34c  d99ed4040000           -fstp dword ptr [esi + 0x4d4]
    app->getMemory<float>(cpu.esi + x86::reg32(1236) /* 0x4d4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a352  e8f9f5ffff             -call 0x409950
    cpu.esp -= 4;
    sub_409950(app, cpu);
    // 0040a357  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a359  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a35a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a35b  895870                 -mov dword ptr [eax + 0x70], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ebx;
    // 0040a35e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a35f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a360  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0040a363  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40a370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040a370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a371  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a372  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a373  8b3520bb4a00           -mov esi, dword ptr [0x4abb20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 0040a379  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0040a37b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a37c  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040a37e  8b8380000000           -mov eax, dword ptr [ebx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(128) /* 0x80 */);
    // 0040a384  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040a386  7414                   -je 0x40a39c
    if (cpu.flags.zf)
    {
        goto L_0x0040a39c;
    }
L_0x0040a388:
    // 0040a388  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a38a  398180000000           +cmp dword ptr [ecx + 0x80], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040a390  7417                   -je 0x40a3a9
    if (cpu.flags.zf)
    {
        goto L_0x0040a3a9;
    }
    // 0040a392  8bb63c050000           -mov esi, dword ptr [esi + 0x53c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1340) /* 0x53c */);
    // 0040a398  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040a39a  75ec                   -jne 0x40a388
    if (!cpu.flags.zf)
    {
        goto L_0x0040a388;
    }
L_0x0040a39c:
    // 0040a39c  68e0c74800             -push 0x48c7e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769760 /*0x48c7e0*/;
    cpu.esp -= 4;
    // 0040a3a1  e86aa80100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a3a6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040a3a9:
    // 0040a3a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a3aa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a3ac  6840050000             -push 0x540
    app->getMemory<x86::reg32>(cpu.esp-4) = 1344 /*0x540*/;
    cpu.esp -= 4;
    // 0040a3b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a3b2  e8e8d30600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0040a3b7  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0040a3ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a3bb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a3bd  8d1480                 -lea edx, [eax + eax*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0040a3c0  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a3c3  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0040a3c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a3c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a3c8  e8d2d30600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0040a3cd  8b4330                 -mov eax, dword ptr [ebx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0040a3d0  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040a3d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a3d5  740c                   -je 0x40a3e3
    if (cpu.flags.zf)
    {
        goto L_0x0040a3e3;
    }
    // 0040a3d7  8b882c030000           -mov ecx, dword ptr [eax + 0x32c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(812) /* 0x32c */);
    // 0040a3dd  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0040a3e1  eb08                   -jmp 0x40a3eb
    goto L_0x0040a3eb;
L_0x0040a3e3:
    // 0040a3e3  c744240cffffffff       -mov dword ptr [esp + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
L_0x0040a3eb:
    // 0040a3eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a3ec  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a3ee  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040a3f2  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0040a3f4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a3f5  e8a5d30600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0040a3fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a3fb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a3fd  83c32c                 -add ebx, 0x2c
    (cpu.ebx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0040a400  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0040a402  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a403  e897d30600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0040a408  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040a40b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a40c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a40d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a40e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a40f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40a410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040a410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a411  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a412  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a413  6840050000             -push 0x540
    app->getMemory<x86::reg32>(cpu.esp-4) = 1344 /*0x540*/;
    cpu.esp -= 4;
    // 0040a418  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040a41a  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040a41c  e859ce0600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040a421  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040a423  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040a426  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040a428  750d                   -jne 0x40a437
    if (!cpu.flags.zf)
    {
        goto L_0x0040a437;
    }
    // 0040a42a  688cc74800             -push 0x48c78c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769676 /*0x48c78c*/;
    cpu.esp -= 4;
    // 0040a42f  e8dca70100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a434  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040a437:
    // 0040a437  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a438  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a43a  6840050000             -push 0x540
    app->getMemory<x86::reg32>(cpu.esp-4) = 1344 /*0x540*/;
    cpu.esp -= 4;
    // 0040a43f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a440  e843d20600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0040a445  a120bb4a00             -mov eax, dword ptr [0x4abb20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 0040a44a  89863c050000           -mov dword ptr [esi + 0x53c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1340) /* 0x53c */) = cpu.eax;
    // 0040a450  893520bb4a00           -mov dword ptr [0x4abb20], esi
    app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */) = cpu.esi;
    // 0040a456  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0040a458  804f4a40               -or byte ptr [edi + 0x4a], 0x40
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(74) /* 0x4a */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0040a45c  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0040a45f  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0040a462  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0040a465  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a466  e80fce0600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040a46b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0040a46e  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0040a471  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a473  750d                   -jne 0x40a482
    if (!cpu.flags.zf)
    {
        goto L_0x0040a482;
    }
    // 0040a475  686cc74800             -push 0x48c76c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769644 /*0x48c76c*/;
    cpu.esp -= 4;
    // 0040a47a  e891a70100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a47f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040a482:
    // 0040a482  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0040a485  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a486  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a488  8d1480                 -lea edx, [eax + eax*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0040a48b  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040a48e  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0040a491  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a492  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a493  e8f0d10600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0040a498  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a499  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a49b  8d4f30                 -lea ecx, [edi + 0x30]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0040a49e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0040a4a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a4a1  e8e2d10600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0040a4a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a4a7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a4a9  83c72c                 -add edi, 0x2c
    (cpu.edi) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0040a4ac  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0040a4ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a4af  e8d4d10600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0040a4b4  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a4b6  83c430                 +add esp, 0x30
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
    // 0040a4b9  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0040a4bc  e88ff4ffff             -call 0x409950
    cpu.esp -= 4;
    sub_409950(app, cpu);
    // 0040a4c1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a4c3  c786e004000000000000   -mov dword ptr [esi + 0x4e0], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1248) /* 0x4e0 */) = 0 /*0x0*/;
    // 0040a4cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a4ce  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0040a4d5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040a4d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a4d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040a4d9  c6403401               -mov byte ptr [eax + 0x34], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(52) /* 0x34 */) = 1 /*0x1*/;
    // 0040a4dd  e91ed2ffff             -jmp 0x407700
    return sub_407700(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40a4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040a4f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040a4f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040a4f3  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0040a4f6  81ecf8000000           -sub esp, 0xf8
    (cpu.esp) -= x86::reg32(x86::sreg32(248 /*0xf8*/));
    // 0040a4fc  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 0040a501  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040a503  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a504  83f801                 +cmp eax, 1
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
    // 0040a507  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a508  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0040a50c  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040a50e  0f847a050000           -je 0x40aa8e
    if (cpu.flags.zf)
    {
        goto L_0x0040aa8e;
    }
    // 0040a514  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0040a51b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040a51d  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0040a51f:
    // 0040a51f  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0040a521  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0040a524  40                     -inc eax
    (cpu.eax)++;
    // 0040a525  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0040a527  75f6                   -jne 0x40a51f
    if (!cpu.flags.zf)
    {
        goto L_0x0040a51f;
    }
    // 0040a529  83cdff                 -or ebp, 0xffffffff
    cpu.ebp |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040a52c  8dbc2488000000         -lea edi, [esp + 0x88]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0040a533  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0040a535  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040a537  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040a539  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0040a53b  49                     -dec ecx
    (cpu.ecx)--;
    // 0040a53c  8d840c87000000         -lea eax, [esp + ecx + 0x87]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(135) /* 0x87 */ + cpu.ecx * 1);
    // 0040a543  8d8c2488000000         -lea ecx, [esp + 0x88]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0040a54a  3bc1                   +cmp eax, ecx
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
    // 0040a54c  7411                   -je 0x40a55f
    if (cpu.flags.zf)
    {
        goto L_0x0040a55f;
    }
L_0x0040a54e:
    // 0040a54e  80385c                 +cmp byte ptr [eax], 0x5c
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
    // 0040a551  7411                   -je 0x40a564
    if (cpu.flags.zf)
    {
        goto L_0x0040a564;
    }
    // 0040a553  48                     -dec eax
    (cpu.eax)--;
    // 0040a554  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0040a55b  3bc2                   +cmp eax, edx
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
    // 0040a55d  75ef                   -jne 0x40a54e
    if (!cpu.flags.zf)
    {
        goto L_0x0040a54e;
    }
L_0x0040a55f:
    // 0040a55f  80385c                 +cmp byte ptr [eax], 0x5c
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
    // 0040a562  7501                   -jne 0x40a565
    if (!cpu.flags.zf)
    {
        goto L_0x0040a565;
    }
L_0x0040a564:
    // 0040a564  40                     -inc eax
    (cpu.eax)++;
L_0x0040a565:
    // 0040a565  c60064                 -mov byte ptr [eax], 0x64
    app->getMemory<x86::reg8>(cpu.eax) = 100 /*0x64*/;
    // 0040a568  40                     -inc eax
    (cpu.eax)++;
    // 0040a569  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a56a  6848c94800             -push 0x48c948
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770120 /*0x48c948*/;
    cpu.esp -= 4;
    // 0040a56f  c60061                 -mov byte ptr [eax], 0x61
    app->getMemory<x86::reg8>(cpu.eax) = 97 /*0x61*/;
    // 0040a572  40                     -inc eax
    (cpu.eax)++;
    // 0040a573  c60074                 -mov byte ptr [eax], 0x74
    app->getMemory<x86::reg8>(cpu.eax) = 116 /*0x74*/;
    // 0040a576  40                     -inc eax
    (cpu.eax)++;
    // 0040a577  c60061                 -mov byte ptr [eax], 0x61
    app->getMemory<x86::reg8>(cpu.eax) = 97 /*0x61*/;
    // 0040a57a  40                     -inc eax
    (cpu.eax)++;
    // 0040a57b  c60032                 -mov byte ptr [eax], 0x32
    app->getMemory<x86::reg8>(cpu.eax) = 50 /*0x32*/;
    // 0040a57e  40                     -inc eax
    (cpu.eax)++;
    // 0040a57f  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
    // 0040a582  40                     -inc eax
    (cpu.eax)++;
    // 0040a583  c60062                 -mov byte ptr [eax], 0x62
    app->getMemory<x86::reg8>(cpu.eax) = 98 /*0x62*/;
    // 0040a586  40                     -inc eax
    (cpu.eax)++;
    // 0040a587  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 0040a58a  40                     -inc eax
    (cpu.eax)++;
    // 0040a58b  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 0040a58e  c6400100               -mov byte ptr [eax + 1], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 0040a592  e820c80600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a597  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a59a  ba40c74800             -mov edx, 0x48c740
    cpu.edx = 4769600 /*0x48c740*/;
    // 0040a59f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040a5a1  e89a240400             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0040a5a6  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040a5a8  8d8c2488000000         -lea ecx, [esp + 0x88]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0040a5af  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040a5b1  751a                   -jne 0x40a5cd
    if (!cpu.flags.zf)
    {
        goto L_0x0040a5cd;
    }
    // 0040a5b3  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0040a5b8  e883240400             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0040a5bd  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040a5bf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040a5c1  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0040a5c5  0f84c3040000           -je 0x40aa8e
    if (cpu.flags.zf)
    {
        goto L_0x0040aa8e;
    }
    // 0040a5cb  eb2b                   -jmp 0x40a5f8
    goto L_0x0040a5f8;
L_0x0040a5cd:
    // 0040a5cd  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 0040a5d2  e869240400             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0040a5d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a5d9  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0040a5dd  7515                   -jne 0x40a5f4
    if (!cpu.flags.zf)
    {
        goto L_0x0040a5f4;
    }
    // 0040a5df  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0040a5e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a5e7  682cc94800             -push 0x48c92c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770092 /*0x48c92c*/;
    cpu.esp -= 4;
    // 0040a5ec  e81fa60100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a5f1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040a5f4:
    // 0040a5f4  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x0040a5f8:
    // 0040a5f8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040a5fa  7456                   -je 0x40a652
    if (cpu.flags.zf)
    {
        goto L_0x0040a652;
    }
    // 0040a5fc  f6430c10               +test byte ptr [ebx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 0040a600  0f8565040000           -jne 0x40aa6b
    if (!cpu.flags.zf)
    {
        goto L_0x0040aa6b;
    }
    // 0040a606  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040a60a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a60b  6820c94800             -push 0x48c920
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770080 /*0x48c920*/;
    cpu.esp -= 4;
    // 0040a610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a611  e824d30600             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 0040a616  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040a619  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a61b  0f844a040000           -je 0x40aa6b
    if (cpu.flags.zf)
    {
        goto L_0x0040aa6b;
    }
    // 0040a621  f6430c10               +test byte ptr [ebx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 0040a625  0f8540040000           -jne 0x40aa6b
    if (!cpu.flags.zf)
    {
        goto L_0x0040aa6b;
    }
    // 0040a62b  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040a62f  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0040a631  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040a633  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0040a635  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0040a637  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040a638  0f842d040000           -je 0x40aa6b
    if (cpu.flags.zf)
    {
        goto L_0x0040aa6b;
    }
    // 0040a63e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a63f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a641  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040a645  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0040a647  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a648  e852d10600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0040a64d  83c410                 +add esp, 0x10
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
    // 0040a650  eb1d                   -jmp 0x40a66f
    goto L_0x0040a66f;
L_0x0040a652:
    // 0040a652  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a653  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a655  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040a659  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0040a65b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a65c  e827d00600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0040a661  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0040a664  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040a667  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0040a669  0f8505040000           -jne 0x40aa74
    if (!cpu.flags.zf)
    {
        goto L_0x0040aa74;
    }
L_0x0040a66f:
    // 0040a66f  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040a673  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a674  6810c94800             -push 0x48c910
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770064 /*0x48c910*/;
    cpu.esp -= 4;
    // 0040a679  e839c70600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a67e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a681  8d542413               -lea edx, [esp + 0x13]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(19) /* 0x13 */);
    // 0040a685  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040a689  c644241300             -mov byte ptr [esp + 0x13], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 0 /*0x0*/;
    // 0040a68e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a68f  6a5f                   -push 0x5f
    app->getMemory<x86::reg32>(cpu.esp-4) = 95 /*0x5f*/;
    cpu.esp -= 4;
    // 0040a691  8d542468               -lea edx, [esp + 0x68]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0040a695  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0040a699  e832db0500             -call 0x4681d0
    cpu.esp -= 4;
    sub_4681d0(app, cpu);
    // 0040a69e  66a10cc94800           -mov ax, word ptr [0x48c90c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(4770060) /* 0x48c90c */);
    // 0040a6a4  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0040a6a8  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040a6ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a6ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a6ae  668944244c             -mov word ptr [esp + 0x4c], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ax;
    // 0040a6b3  e8f8a40700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0040a6b8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a6bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a6bd  7508                   -jne 0x40a6c7
    if (!cpu.flags.zf)
    {
        goto L_0x0040a6c7;
    }
    // 0040a6bf  c744241804000000       -mov dword ptr [esp + 0x18], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 4 /*0x4*/;
L_0x0040a6c7:
    // 0040a6c7  66a108c94800           -mov ax, word ptr [0x48c908]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(4770056) /* 0x48c908 */);
    // 0040a6cd  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0040a6d1  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040a6d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a6d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a6d7  668944244c             -mov word ptr [esp + 0x4c], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ax;
    // 0040a6dc  e8cfa40700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0040a6e1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a6e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a6e6  7508                   -jne 0x40a6f0
    if (!cpu.flags.zf)
    {
        goto L_0x0040a6f0;
    }
    // 0040a6e8  c744241802000000       -mov dword ptr [esp + 0x18], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 2 /*0x2*/;
L_0x0040a6f0:
    // 0040a6f0  66a104c94800           -mov ax, word ptr [0x48c904]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(4770052) /* 0x48c904 */);
    // 0040a6f6  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0040a6fa  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040a6fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a6ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a700  668944244c             -mov word ptr [esp + 0x4c], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ax;
    // 0040a705  e8a6a40700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0040a70a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a70d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a70f  7508                   -jne 0x40a719
    if (!cpu.flags.zf)
    {
        goto L_0x0040a719;
    }
    // 0040a711  c744241808000000       -mov dword ptr [esp + 0x18], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 8 /*0x8*/;
L_0x0040a719:
    // 0040a719  66a100c94800           -mov ax, word ptr [0x48c900]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(4770048) /* 0x48c900 */);
    // 0040a71f  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0040a723  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040a727  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a728  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a729  668944244c             -mov word ptr [esp + 0x4c], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ax;
    // 0040a72e  e87da40700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0040a733  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a736  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a738  750a                   -jne 0x40a744
    if (!cpu.flags.zf)
    {
        goto L_0x0040a744;
    }
    // 0040a73a  c744241810000000       -mov dword ptr [esp + 0x18], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 16 /*0x10*/;
    // 0040a742  eb13                   -jmp 0x40a757
    goto L_0x0040a757;
L_0x0040a744:
    // 0040a744  396c2418               +cmp dword ptr [esp + 0x18], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040a748  750d                   -jne 0x40a757
    if (!cpu.flags.zf)
    {
        goto L_0x0040a757;
    }
    // 0040a74a  68f0c84800             -push 0x48c8f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770032 /*0x48c8f0*/;
    cpu.esp -= 4;
    // 0040a74f  e8bca40100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a754  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040a757:
    // 0040a757  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040a75b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a75c  68e4c84800             -push 0x48c8e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770020 /*0x48c8e4*/;
    cpu.esp -= 4;
    // 0040a761  e851c60600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a766  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a769  8d4c2413               -lea ecx, [esp + 0x13]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(19) /* 0x13 */);
    // 0040a76d  8d542474               -lea edx, [esp + 0x74]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0040a771  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a772  6a5f                   -push 0x5f
    app->getMemory<x86::reg32>(cpu.esp-4) = 95 /*0x5f*/;
    cpu.esp -= 4;
    // 0040a774  8d4c2438               -lea ecx, [esp + 0x38]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040a778  e853da0500             -call 0x4681d0
    cpu.esp -= 4;
    sub_4681d0(app, cpu);
    // 0040a77d  8d542474               -lea edx, [esp + 0x74]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0040a781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a782  6820c94800             -push 0x48c920
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770080 /*0x48c920*/;
    cpu.esp -= 4;
    // 0040a787  e82bc60600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a78c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a78f  8d442413               -lea eax, [esp + 0x13]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(19) /* 0x13 */);
    // 0040a793  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040a797  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040a79b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a79c  6a5f                   -push 0x5f
    app->getMemory<x86::reg32>(cpu.esp-4) = 95 /*0x5f*/;
    cpu.esp -= 4;
    // 0040a79e  e82dda0500             -call 0x4681d0
    cpu.esp -= 4;
    sub_4681d0(app, cpu);
    // 0040a7a3  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040a7a7  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040a7ab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a7ac  68e0c84800             -push 0x48c8e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770016 /*0x48c8e0*/;
    cpu.esp -= 4;
    // 0040a7b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a7b2  e89dce0600             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0040a7b7  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0040a7bb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040a7be  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a7c1  68d4c84800             -push 0x48c8d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770004 /*0x48c8d4*/;
    cpu.esp -= 4;
    // 0040a7c6  e8ecc50600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a7cb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040a7ce  8d442413               -lea eax, [esp + 0x13]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(19) /* 0x13 */);
    // 0040a7d2  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040a7d6  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040a7da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a7db  6a5f                   -push 0x5f
    app->getMemory<x86::reg32>(cpu.esp-4) = 95 /*0x5f*/;
    cpu.esp -= 4;
    // 0040a7dd  e8eed90500             -call 0x4681d0
    cpu.esp -= 4;
    sub_4681d0(app, cpu);
    // 0040a7e2  8d4c2458               -lea ecx, [esp + 0x58]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040a7e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a7e7  68ccc84800             -push 0x48c8cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769996 /*0x48c8cc*/;
    cpu.esp -= 4;
    // 0040a7ec  e8c6c50600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a7f1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040a7f4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040a7f6  7424                   -je 0x40a81c
    if (cpu.flags.zf)
    {
        goto L_0x0040a81c;
    }
    // 0040a7f8  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040a7fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a7fd  68c0c84800             -push 0x48c8c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769984 /*0x48c8c0*/;
    cpu.esp -= 4;
    // 0040a802  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a803  e832d10600             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 0040a808  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a809  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a80b  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040a80f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0040a811  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a812  e888cf0600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0040a817  83c41c                 +add esp, 0x1c
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
    // 0040a81a  eb12                   -jmp 0x40a82e
    goto L_0x0040a82e;
L_0x0040a81c:
    // 0040a81c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a81d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a81f  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040a823  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0040a825  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a826  e85dce0600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0040a82b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0040a82e:
    // 0040a82e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040a832  8d1480                 -lea edx, [eax + eax*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0040a835  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0040a838  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a839  e83cca0600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040a83e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040a840  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040a843  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040a845  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0040a849  750d                   -jne 0x40a858
    if (!cpu.flags.zf)
    {
        goto L_0x0040a858;
    }
    // 0040a84b  6878c44800             -push 0x48c478
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768888 /*0x48c478*/;
    cpu.esp -= 4;
    // 0040a850  e8bba30100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040a855  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040a858:
    // 0040a858  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040a85c  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0040a85e  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040a860  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040a862  0f8eb3000000           -jle 0x40a91b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040a91b;
    }
    // 0040a868  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040a86b:
    // 0040a86b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040a86d  7446                   -je 0x40a8b5
    if (cpu.flags.zf)
    {
        goto L_0x0040a8b5;
    }
    // 0040a86f  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0040a872  8d46fc                 -lea eax, [esi - 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0040a875  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a876  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040a877  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a878  68b0c84800             -push 0x48c8b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769968 /*0x48c8b0*/;
    cpu.esp -= 4;
    // 0040a87d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040a87e  c700003c1c46           -mov dword ptr [eax], 0x461c3c00
    app->getMemory<x86::reg32>(cpu.eax) = 1176255488 /*0x461c3c00*/;
    // 0040a884  c706003c1c46           -mov dword ptr [esi], 0x461c3c00
    app->getMemory<x86::reg32>(cpu.esi) = 1176255488 /*0x461c3c00*/;
    // 0040a88a  c701003c1c46           -mov dword ptr [ecx], 0x461c3c00
    app->getMemory<x86::reg32>(cpu.ecx) = 1176255488 /*0x461c3c00*/;
    // 0040a890  e8a5d00600             -call 0x47793a
    cpu.esp -= 4;
    sub_47793a(app, cpu);
    // 0040a895  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0040a898  83f803                 +cmp eax, 3
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
    // 0040a89b  7401                   -je 0x40a89e
    if (cpu.flags.zf)
    {
        goto L_0x0040a89e;
    }
    // 0040a89d  45                     -inc ebp
    (cpu.ebp)++;
L_0x0040a89e:
    // 0040a89e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040a8a2  8d4ef8                 -lea ecx, [esi - 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-8) /* -0x8 */);
    // 0040a8a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a8a6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a8a8  6a28                   -push 0x28
    app->getMemory<x86::reg32>(cpu.esp-4) = 40 /*0x28*/;
    cpu.esp -= 4;
    // 0040a8aa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a8ab  e8efce0600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0040a8b0  83c410                 +add esp, 0x10
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
    // 0040a8b3  eb29                   -jmp 0x40a8de
    goto L_0x0040a8de;
L_0x0040a8b5:
    // 0040a8b5  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040a8b9  8d46f8                 -lea eax, [esi - 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-8) /* -0x8 */);
    // 0040a8bc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a8bd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040a8bf  6a28                   -push 0x28
    app->getMemory<x86::reg32>(cpu.esp-4) = 40 /*0x28*/;
    cpu.esp -= 4;
    // 0040a8c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040a8c2  e8c1cd0600             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0040a8c7  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 0040a8c9  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 0040a8cb  dc1d50754800           -fcomp qword ptr [0x487550]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748624) /* 0x487550 */)));
    cpu.fpu.pop();
    // 0040a8d1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040a8d4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040a8d6  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040a8db  7501                   -jne 0x40a8de
    if (!cpu.flags.zf)
    {
        goto L_0x0040a8de;
    }
    // 0040a8dd  45                     -inc ebp
    (cpu.ebp)++;
L_0x0040a8de:
    // 0040a8de  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0040a8e1  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0040a8e4  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040a8e8  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a8ec  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 0040a8ee  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a8f2  d946fc                 -fld dword ptr [esi - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(-4) /* -0x4 */)));
    // 0040a8f5  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a8f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a8f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a8fa  6898c84800             -push 0x48c898
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769944 /*0x48c898*/;
    cpu.esp -= 4;
    // 0040a8ff  e8b3c40600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a904  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040a908  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0040a90b  47                     -inc edi
    (cpu.edi)++;
    // 0040a90c  83c628                 -add esi, 0x28
    (cpu.esi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040a90f  3bfa                   +cmp edi, edx
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
    // 0040a911  0f8c54ffffff           -jl 0x40a86b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040a86b;
    }
    // 0040a917  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x0040a91b:
    // 0040a91b  2bd5                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0040a91d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0040a91f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0040a923  7e13                   -jle 0x40a938
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040a938;
    }
    // 0040a925  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040a926  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040a927  6870c84800             -push 0x48c870
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769904 /*0x48c870*/;
    cpu.esp -= 4;
    // 0040a92c  e886c40600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a931  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040a935  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0040a938:
    // 0040a938  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0040a93b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040a93d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040a93f  0f8e88000000           -jle 0x40a9cd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040a9cd;
    }
    // 0040a945  83c62c                 -add esi, 0x2c
    (cpu.esi) += x86::reg32(x86::sreg32(44 /*0x2c*/));
L_0x0040a948:
    // 0040a948  d946d8                 -fld dword ptr [esi - 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(-40) /* -0x28 */)));
    // 0040a94b  d826                   -fsub dword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi));
    // 0040a94d  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 0040a94f  dc1d48754800           -fcomp qword ptr [0x487548]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748616) /* 0x487548 */)));
    cpu.fpu.pop();
    // 0040a955  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040a957  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040a95a  7a62                   -jp 0x40a9be
    if (cpu.flags.pf)
    {
        goto L_0x0040a9be;
    }
    // 0040a95c  d946e0                 -fld dword ptr [esi - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(-32) /* -0x20 */)));
    // 0040a95f  d86608                 -fsub dword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0040a962  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 0040a964  dc1d48754800           -fcomp qword ptr [0x487548]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748616) /* 0x487548 */)));
    cpu.fpu.pop();
    // 0040a96a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040a96c  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040a96f  7a4d                   -jp 0x40a9be
    if (cpu.flags.pf)
    {
        goto L_0x0040a9be;
    }
    // 0040a971  8d6f01                 -lea ebp, [edi + 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0040a974  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040a975  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040a976  683cc84800             -push 0x48c83c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769852 /*0x48c83c*/;
    cpu.esp -= 4;
    // 0040a97b  e837c40600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a980  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 0040a982  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0040a988  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040a98b  d916                   -fst dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    // 0040a98d  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0040a990  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0040a996  d95608                 -fst dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 0040a999  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a99d  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0040a9a0  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040a9a4  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a9a8  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040a9ab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040a9ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040a9ad  681cc84800             -push 0x48c81c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769820 /*0x48c81c*/;
    cpu.esp -= 4;
    // 0040a9b2  e800c40600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040a9b7  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040a9bb  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
L_0x0040a9be:
    // 0040a9be  47                     -inc edi
    (cpu.edi)++;
    // 0040a9bf  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0040a9c2  83c628                 -add esi, 0x28
    (cpu.esi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040a9c5  3bf8                   +cmp edi, eax
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
    // 0040a9c7  0f8c7bffffff           -jl 0x40a948
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040a948;
    }
L_0x0040a9cd:
    // 0040a9cd  8d7c2474               -lea edi, [esp + 0x74]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0040a9d1  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040a9d4  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040a9d6  8d6c2474               -lea ebp, [esp + 0x74]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0040a9da  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040a9dc  668b0d18c84800         -mov cx, word ptr [0x48c818]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(4769816) /* 0x48c818 */);
    // 0040a9e3  66894fff               -mov word ptr [edi - 1], cx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.cx;
    // 0040a9e7  8d7c2458               -lea edi, [esp + 0x58]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040a9eb  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0040a9ee  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040a9f0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0040a9f2  2bf9                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040a9f4  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040a9f6  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0040a9f8  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0040a9fa  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0040a9fc  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040a9ff  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040aa01  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040aa03  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0040aa05  4f                     -dec edi
    (cpu.edi)--;
    // 0040aa06  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040aa09  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040aa0b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040aa0f  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0040aa11  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040aa14  83f810                 +cmp eax, 0x10
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
    // 0040aa17  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0040aa19  7525                   -jne 0x40aa40
    if (!cpu.flags.zf)
    {
        goto L_0x0040aa40;
    }
    // 0040aa1b  837c242c01             +cmp dword ptr [esp + 0x2c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040aa20  7534                   -jne 0x40aa56
    if (!cpu.flags.zf)
    {
        goto L_0x0040aa56;
    }
    // 0040aa22  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040aa26  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040aa2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040aa2b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040aa2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040aa2d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0040aa32  8d8c2480000000         -lea ecx, [esp + 0x80]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0040aa39  e862d5ffff             -call 0x407fa0
    cpu.esp -= 4;
    sub_407fa0(app, cpu);
    // 0040aa3e  eb16                   -jmp 0x40aa56
    goto L_0x0040aa56;
L_0x0040aa40:
    // 0040aa40  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040aa44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040aa45  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040aa46  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040aa4a  8d4c247c               -lea ecx, [esp + 0x7c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0040aa4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040aa4f  8ad0                   -mov dl, al
    cpu.dl = cpu.al;
    // 0040aa51  e8eaf5ffff             -call 0x40a040
    cpu.esp -= 4;
    sub_40a040(app, cpu);
L_0x0040aa56:
    // 0040aa56  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040aa5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040aa5b  e854c90600             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0040aa60  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040aa63  83cdff                 +or ebp, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ebp |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0040aa66  e989fbffff             -jmp 0x40a5f4
    goto L_0x0040a5f4;
L_0x0040aa6b:
    // 0040aa6b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040aa6c  e866cb0600             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0040aa71  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040aa74:
    // 0040aa74  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040aa76  7409                   -je 0x40aa81
    if (cpu.flags.zf)
    {
        goto L_0x0040aa81;
    }
    // 0040aa78  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040aa79  e859cb0600             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0040aa7e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040aa81:
    // 0040aa81  6804c84800             -push 0x48c804
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769796 /*0x48c804*/;
    cpu.esp -= 4;
    // 0040aa86  e82cc30600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040aa8b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040aa8e:
    // 0040aa8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aa8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aa90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aa91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aa92  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040aa94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aa95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40aaa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040aaa0  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0040aaa3  8b542458               -mov edx, dword ptr [esp + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040aaa7  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0040aaab  d944245c               -fld dword ptr [esp + 0x5c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(92) /* 0x5c */)));
    // 0040aaaf  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0040aab3  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0040aab7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0040aabb  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0040aabf  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0040aac3  8d542400               -lea edx, [esp]
    cpu.edx = x86::reg32(cpu.esp);
    // 0040aac7  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0040aacd  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0040aad1  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040aad5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040aad6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0040aad8  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040aadd  b204                   -mov dl, 4
    cpu.dl = 4 /*0x4*/;
    // 0040aadf  d95c2440               -fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040aae3  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0040aae7  e854f5ffff             -call 0x40a040
    cpu.esp -= 4;
    sub_40a040(app, cpu);
    // 0040aaec  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0040aaef  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40ab00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ab00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040ab01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ab02  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0040ab04  8b1520bb4a00           -mov edx, dword ptr [0x4abb20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 0040ab0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ab0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040ab0c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040ab0e  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040ab10  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ab12  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040ab14  7418                   -je 0x40ab2e
    if (cpu.flags.zf)
    {
        goto L_0x0040ab2e;
    }
L_0x0040ab16:
    // 0040ab16  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040ab18  8b863c050000           -mov eax, dword ptr [esi + 0x53c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1340) /* 0x53c */);
    // 0040ab1e  39bb84000000           +cmp dword ptr [ebx + 0x84], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(132) /* 0x84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ab24  740f                   -je 0x40ab35
    if (cpu.flags.zf)
    {
        goto L_0x0040ab35;
    }
    // 0040ab26  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040ab28  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040ab2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040ab2c  75e8                   -jne 0x40ab16
    if (!cpu.flags.zf)
    {
        goto L_0x0040ab16;
    }
L_0x0040ab2e:
    // 0040ab2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ab2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ab30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ab31  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040ab33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ab34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ab35:
    // 0040ab35  3bf2                   +cmp esi, edx
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
    // 0040ab37  7507                   -jne 0x40ab40
    if (!cpu.flags.zf)
    {
        goto L_0x0040ab40;
    }
    // 0040ab39  a320bb4a00             -mov dword ptr [0x4abb20], eax
    app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */) = cpu.eax;
    // 0040ab3e  eb06                   -jmp 0x40ab46
    goto L_0x0040ab46;
L_0x0040ab40:
    // 0040ab40  89813c050000           -mov dword ptr [ecx + 0x53c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1340) /* 0x53c */) = cpu.eax;
L_0x0040ab46:
    // 0040ab46  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040ab48  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040ab4a  895830                 -mov dword ptr [eax + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0040ab4d  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040ab4f  c6413401               -mov byte ptr [ecx + 0x34], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */) = 1 /*0x1*/;
    // 0040ab53  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040ab55  885a35                 -mov byte ptr [edx + 0x35], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(53) /* 0x35 */) = cpu.bl;
    // 0040ab58  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040ab5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ab5c  e853c80600             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0040ab61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ab64  3beb                   +cmp ebp, ebx
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
    // 0040ab66  7414                   -je 0x40ab7c
    if (cpu.flags.zf)
    {
        goto L_0x0040ab7c;
    }
    // 0040ab68  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040ab6a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ab6c  e8afcc0400             -call 0x457820
    cpu.esp -= 4;
    sub_457820(app, cpu);
    // 0040ab71  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040ab73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040ab74  e83bc80600             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0040ab79  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040ab7c:
    // 0040ab7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ab7d  e832c80600             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0040ab82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040ab83  685cc94800             -push 0x48c95c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770140 /*0x48c95c*/;
    cpu.esp -= 4;
    // 0040ab88  e82ac20600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040ab8d  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0040ab92  e8d0cd0600             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0040ab97  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040ab9a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040ab9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aba0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aba1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aba2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040aba3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40abb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040abb0  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040abb2  e949ffffff             -jmp 0x40ab00
    return sub_40ab00(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40abc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040abc0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040abc5  e936ffffff             -jmp 0x40ab00
    return sub_40ab00(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40abd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040abd0  a148bb4a00             -mov eax, dword ptr [0x4abb48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897608) /* 0x4abb48 */);
    // 0040abd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040abd6  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0040abdb  3bc6                   +cmp eax, esi
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
    // 0040abdd  0f848f000000           -je 0x40ac72
    if (cpu.flags.zf)
    {
        goto L_0x0040ac72;
    }
    // 0040abe3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040abe4  6880c94800             -push 0x48c980
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770176 /*0x48c980*/;
    cpu.esp -= 4;
    // 0040abe9  893548bb4a00           -mov dword ptr [0x4abb48], esi
    app->getMemory<x86::reg32>(x86::reg32(4897608) /* 0x4abb48 */) = cpu.esi;
    // 0040abef  e8c3c10600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040abf4  a120bb4a00             -mov eax, dword ptr [0x4abb20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 0040abf9  8b3d60ba5100           -mov edi, dword ptr [0x51ba60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */);
    // 0040abff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ac02  893560ba5100           -mov dword ptr [0x51ba60], esi
    app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */) = cpu.esi;
    // 0040ac08  893530bb4a00           -mov dword ptr [0x4abb30], esi
    app->getMemory<x86::reg32>(x86::reg32(4897584) /* 0x4abb30 */) = cpu.esi;
    // 0040ac0e  bee8030000             -mov esi, 0x3e8
    cpu.esi = 1000 /*0x3e8*/;
    // 0040ac13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040ac15  7428                   -je 0x40ac3f
    if (cpu.flags.zf)
    {
        goto L_0x0040ac3f;
    }
L_0x0040ac17:
    // 0040ac17  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040ac19  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ac1f  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040ac25  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040ac28  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040ac2a  e891ffffff             -call 0x40abc0
    cpu.esp -= 4;
    sub_40abc0(app, cpu);
    // 0040ac2f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040ac31  4e                     -dec esi
    (cpu.esi)--;
    // 0040ac32  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040ac34  7c09                   -jl 0x40ac3f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040ac3f;
    }
    // 0040ac36  a120bb4a00             -mov eax, dword ptr [0x4abb20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4897568) /* 0x4abb20 */);
    // 0040ac3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040ac3d  75d8                   -jne 0x40ac17
    if (!cpu.flags.zf)
    {
        goto L_0x0040ac17;
    }
L_0x0040ac3f:
    // 0040ac3f  ff0548845100           -inc dword ptr [0x518448]
    (app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))++;
    // 0040ac45  e8f65f0400             -call 0x450c40
    cpu.esp -= 4;
    sub_450c40(app, cpu);
    // 0040ac4a  c70530bb4a0000000000   -mov dword ptr [0x4abb30], 0
    app->getMemory<x86::reg32>(x86::reg32(4897584) /* 0x4abb30 */) = 0 /*0x0*/;
    // 0040ac54  893d60ba5100           -mov dword ptr [0x51ba60], edi
    app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */) = cpu.edi;
    // 0040ac5a  686cc94800             -push 0x48c96c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770156 /*0x48c96c*/;
    cpu.esp -= 4;
    // 0040ac5f  e853c10600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040ac64  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ac67  c70548bb4a0000000000   -mov dword ptr [0x4abb48], 0
    app->getMemory<x86::reg32>(x86::reg32(4897608) /* 0x4abb48 */) = 0 /*0x0*/;
    // 0040ac71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040ac72:
    // 0040ac72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ac73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40ac80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ac80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ac81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040ac82  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040ac86  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040ac88  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ac8a  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 0040ac8d  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0040ac90  8d1481                 -lea edx, [ecx + eax*4]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 0040ac93  d9449608               -fld dword ptr [esi + edx*4 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.edx * 4)));
    // 0040ac97  d85c960c               -fcomp dword ptr [esi + edx*4 + 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 4)));
    cpu.fpu.pop();
    // 0040ac9b  8d0496                 -lea eax, [esi + edx*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.edx * 4);
    // 0040ac9e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040aca0  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0040aca3  7a18                   -jp 0x40acbd
    if (cpu.flags.pf)
    {
        goto L_0x0040acbd;
    }
    // 0040aca5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040aca6  68e0c94800             -push 0x48c9e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770272 /*0x48c9e0*/;
    cpu.esp -= 4;
    // 0040acab  e807c10600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040acb0  68c8c94800             -push 0x48c9c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770248 /*0x48c9c8*/;
    cpu.esp -= 4;
    // 0040acb5  e8569f0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040acba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0040acbd:
    // 0040acbd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040acbf  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0040acc2  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040acc5  8d1488                 -lea edx, [eax + ecx*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 0040acc8  d9449608               -fld dword ptr [esi + edx*4 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.edx * 4)));
    // 0040accc  d85c960c               -fcomp dword ptr [esi + edx*4 + 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 4)));
    cpu.fpu.pop();
    // 0040acd0  8d0c96                 -lea ecx, [esi + edx*4]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 4);
    // 0040acd3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040acd5  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040acd8  7a1f                   -jp 0x40acf9
    if (cpu.flags.pf)
    {
        goto L_0x0040acf9;
    }
    // 0040acda  d9410c                 +fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 0040acdd  d86108                 +fsub dword ptr [ecx + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */));
    // 0040ace0  d90568754800           +fld dword ptr [0x487568]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748648) /* 0x487568 */)));
    // 0040ace6  d835bcc94800           +fdiv dword ptr [0x48c9bc]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(x86::reg32(4770236) /* 0x48c9bc */));
    // 0040acec  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040acf0  d84904                 +fmul dword ptr [ecx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */));
    // 0040acf3  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040acf5  d918                   +fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040acf7  eb1f                   -jmp 0x40ad18
    goto L_0x0040ad18;
L_0x0040acf9:
    // 0040acf9  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0040acfc  d8610c                 -fsub dword ptr [ecx + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */));
    // 0040acff  d90568754800           -fld dword ptr [0x487568]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748648) /* 0x487568 */)));
    // 0040ad05  d835bcc94800           -fdiv dword ptr [0x48c9bc]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(x86::reg32(4770236) /* 0x48c9bc */));
    // 0040ad0b  d84904                 -fmul dword ptr [ecx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */));
    // 0040ad0e  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040ad12  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040ad14  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040ad16  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040ad18:
    // 0040ad18  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040ad1a  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0040ad1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ad1e  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040ad21  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040ad24  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040ad28  8b4c8608               -mov ecx, dword ptr [esi + eax*4 + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 4);
    // 0040ad2c  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040ad30  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0040ad32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ad33  c60007                 -mov byte ptr [eax], 7
    app->getMemory<x86::reg8>(cpu.eax) = 7 /*0x7*/;
    // 0040ad36  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40ad40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ad40  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040ad43  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040ad44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ad45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ad46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040ad47  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040ad4b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040ad4d  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040ad4f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0040ad53  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0040ad56  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040ad59  8d1488                 -lea edx, [eax + ecx*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 0040ad5c  d9449608               -fld dword ptr [esi + edx*4 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.edx * 4)));
    // 0040ad60  d85c960c               -fcomp dword ptr [esi + edx*4 + 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 4)));
    cpu.fpu.pop();
    // 0040ad64  8d0c96                 -lea ecx, [esi + edx*4]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 4);
    // 0040ad67  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ad69  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040ad6c  7a0c                   -jp 0x40ad7a
    if (cpu.flags.pf)
    {
        goto L_0x0040ad7a;
    }
    // 0040ad6e  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0040ad71  d9410c                 +fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 0040ad74  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0040ad78  eb0a                   -jmp 0x40ad84
    goto L_0x0040ad84;
L_0x0040ad7a:
    // 0040ad7a  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0040ad7d  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0040ad80  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0040ad84:
    // 0040ad84  8a4114                 -mov al, byte ptr [ecx + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0040ad87  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040ad8b  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0040ad8d  743d                   -je 0x40adcc
    if (cpu.flags.zf)
    {
        goto L_0x0040adcc;
    }
    // 0040ad8f  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040ad93  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0040ad95  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0040ad9b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ad9d  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040ada2  7511                   -jne 0x40adb5
    if (!cpu.flags.zf)
    {
        goto L_0x0040adb5;
    }
    // 0040ada4  d813                   -fcom dword ptr [ebx]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0040ada6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ada8  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040adab  7a1f                   -jp 0x40adcc
    if (cpu.flags.pf)
    {
        goto L_0x0040adcc;
    }
    // 0040adad  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040adb1  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 0040adb3  eb17                   -jmp 0x40adcc
    goto L_0x0040adcc;
L_0x0040adb5:
    // 0040adb5  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040adb9  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0040adbb  d85c2420               -fcomp dword ptr [esp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0040adbf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040adc1  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040adc4  7a06                   -jp 0x40adcc
    if (cpu.flags.pf)
    {
        goto L_0x0040adcc;
    }
    // 0040adc6  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040adc8  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040adca  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040adcc:
    // 0040adcc  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0040adcf  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0040add1  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0040add5  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040adda  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040addd  8d1488                 -lea edx, [eax + ecx*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 0040ade0  8a4c9614               -mov cl, byte ptr [esi + edx*4 + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.edx * 4);
    // 0040ade4  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0040ade7  8d1496                 -lea edx, [esi + edx*4]
    cpu.edx = x86::reg32(cpu.esi + cpu.edx * 4);
    // 0040adea  7454                   -je 0x40ae40
    if (cpu.flags.zf)
    {
        goto L_0x0040ae40;
    }
    // 0040adec  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040adf0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0040adf2  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0040adf8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040adfa  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040adff  7518                   -jne 0x40ae19
    if (!cpu.flags.zf)
    {
        goto L_0x0040ae19;
    }
    // 0040ae01  d813                   -fcom dword ptr [ebx]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0040ae03  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ae05  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040ae08  7a36                   -jp 0x40ae40
    if (cpu.flags.pf)
    {
        goto L_0x0040ae40;
    }
    // 0040ae0a  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0040ae0d  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0040ae12  742c                   -je 0x40ae40
    if (cpu.flags.zf)
    {
        goto L_0x0040ae40;
    }
    // 0040ae14  d85208                 +fcom dword ptr [edx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0040ae17  eb1e                   -jmp 0x40ae37
    goto L_0x0040ae37;
L_0x0040ae19:
    // 0040ae19  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0040ae1b  d85c2420               -fcomp dword ptr [esp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0040ae1f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ae21  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040ae24  7a1a                   -jp 0x40ae40
    if (cpu.flags.pf)
    {
        goto L_0x0040ae40;
    }
    // 0040ae26  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0040ae29  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0040ae2e  7410                   -je 0x40ae40
    if (cpu.flags.zf)
    {
        goto L_0x0040ae40;
    }
    // 0040ae30  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0040ae34  d85a08                 -fcomp dword ptr [edx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
L_0x0040ae37:
    // 0040ae37  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ae39  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0040ae3c  7b02                   -jnp 0x40ae40
    if (!cpu.flags.pf)
    {
        goto L_0x0040ae40;
    }
    // 0040ae3e  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0040ae40:
    // 0040ae40  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0040ae43  7454                   -je 0x40ae99
    if (cpu.flags.zf)
    {
        goto L_0x0040ae99;
    }
    // 0040ae45  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040ae49  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0040ae4b  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0040ae51  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ae53  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040ae58  7518                   -jne 0x40ae72
    if (!cpu.flags.zf)
    {
        goto L_0x0040ae72;
    }
    // 0040ae5a  d813                   -fcom dword ptr [ebx]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0040ae5c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ae5e  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040ae61  7a36                   -jp 0x40ae99
    if (cpu.flags.pf)
    {
        goto L_0x0040ae99;
    }
    // 0040ae63  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0040ae66  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0040ae6b  7476                   -je 0x40aee3
    if (cpu.flags.zf)
    {
        goto L_0x0040aee3;
    }
    // 0040ae6d  d85208                 +fcom dword ptr [edx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0040ae70  eb1e                   -jmp 0x40ae90
    goto L_0x0040ae90;
L_0x0040ae72:
    // 0040ae72  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0040ae74  d85c2420               -fcomp dword ptr [esp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0040ae78  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ae7a  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040ae7d  7a1a                   -jp 0x40ae99
    if (cpu.flags.pf)
    {
        goto L_0x0040ae99;
    }
    // 0040ae7f  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0040ae82  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0040ae87  745a                   -je 0x40aee3
    if (cpu.flags.zf)
    {
        goto L_0x0040aee3;
    }
    // 0040ae89  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0040ae8d  d85a08                 -fcomp dword ptr [edx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
L_0x0040ae90:
    // 0040ae90  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ae92  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0040ae95  7b02                   -jnp 0x40ae99
    if (!cpu.flags.pf)
    {
        goto L_0x0040ae99;
    }
    // 0040ae97  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0040ae99:
    // 0040ae99  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0040ae9c  7445                   -je 0x40aee3
    if (cpu.flags.zf)
    {
        goto L_0x0040aee3;
    }
    // 0040ae9e  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040aea2  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0040aea4  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0040aeaa  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040aeac  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040aeb1  7513                   -jne 0x40aec6
    if (!cpu.flags.zf)
    {
        goto L_0x0040aec6;
    }
    // 0040aeb3  d813                   -fcom dword ptr [ebx]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0040aeb5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040aeb7  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040aeba  7a27                   -jp 0x40aee3
    if (cpu.flags.pf)
    {
        goto L_0x0040aee3;
    }
    // 0040aebc  d91b                   +fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040aebe  d901                   +fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0040aec0  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040aec2  d919                   +fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040aec4  eb1f                   -jmp 0x40aee5
    goto L_0x0040aee5;
L_0x0040aec6:
    // 0040aec6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040aec8  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0040aeca  d85c2420               -fcomp dword ptr [esp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0040aece  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040aed0  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040aed3  7a10                   -jp 0x40aee5
    if (cpu.flags.pf)
    {
        goto L_0x0040aee5;
    }
    // 0040aed5  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040aed9  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0040aedb  d901                   +fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0040aedd  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040aedf  d919                   +fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040aee1  eb02                   -jmp 0x40aee5
    goto L_0x0040aee5;
L_0x0040aee3:
    // 0040aee3  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040aee5:
    // 0040aee5  83fd01                 +cmp ebp, 1
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
    // 0040aee8  7536                   -jne 0x40af20
    if (!cpu.flags.zf)
    {
        goto L_0x0040af20;
    }
    // 0040aeea  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 0040aeed  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040aeef  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040aef4  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040aef7  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040aefa  f644861408             +test byte ptr [esi + eax*4 + 0x14], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.eax * 4) & 8 /*0x8*/));
    // 0040aeff  741f                   -je 0x40af20
    if (cpu.flags.zf)
    {
        goto L_0x0040af20;
    }
    // 0040af01  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040af05  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 0040af08  663bc1                 +cmp ax, cx
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.cx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040af0b  7406                   -je 0x40af13
    if (cpu.flags.zf)
    {
        goto L_0x0040af13;
    }
    // 0040af0d  663dffff               +cmp ax, 0xffff
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
    // 0040af11  7505                   -jne 0x40af18
    if (!cpu.flags.zf)
    {
        goto L_0x0040af18;
    }
L_0x0040af13:
    // 0040af13  66c7020000             -mov word ptr [edx], 0
    app->getMemory<x86::reg16>(cpu.edx) = 0 /*0x0*/;
L_0x0040af18:
    // 0040af18  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0040af1b  66894c2410             -mov word ptr [esp + 0x10], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.cx;
L_0x0040af20:
    // 0040af20  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040af24  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040af26  66ff03                 -inc word ptr [ebx]
    (app->getMemory<x86::reg16>(cpu.ebx))++;
    // 0040af29  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0040af2c  668b0b                 -mov cx, word ptr [ebx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0040af2f  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040af32  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040af35  8d1486                 -lea edx, [esi + eax*4]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 4);
    // 0040af38  8b448620               -mov eax, dword ptr [esi + eax*4 + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */ + cpu.eax * 4);
    // 0040af3c  83f8ff                 +cmp eax, -1
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
    // 0040af3f  7413                   -je 0x40af54
    if (cpu.flags.zf)
    {
        goto L_0x0040af54;
    }
    // 0040af41  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040af47  3bc8                   +cmp ecx, eax
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
    // 0040af49  7c09                   -jl 0x40af54
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040af54;
    }
    // 0040af4b  668b4a24               -mov cx, word ptr [edx + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0040af4f  66894c2410             -mov word ptr [esp + 0x10], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.cx;
L_0x0040af54:
    // 0040af54  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040af58  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0040af5a  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0040af60  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040af62  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040af67  7508                   -jne 0x40af71
    if (!cpu.flags.zf)
    {
        goto L_0x0040af71;
    }
    // 0040af69  c7010000803f           -mov dword ptr [ecx], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx) = 1065353216 /*0x3f800000*/;
    // 0040af6f  eb15                   -jmp 0x40af86
    goto L_0x0040af86;
L_0x0040af71:
    // 0040af71  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0040af73  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0040af79  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040af7b  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040af7e  7a06                   -jp 0x40af86
    if (cpu.flags.pf)
    {
        goto L_0x0040af86;
    }
    // 0040af80  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x0040af86:
    // 0040af86  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040af8a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040af8c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040af8d  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040af8f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0040af91  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040af93  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0040af96  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0040af9a  db442424               -fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 0040af9e  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040afa1  dc0d70754800           -fmul qword ptr [0x487570]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748656) /* 0x487570 */));
    // 0040afa7  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040afaa  dc2d68734800           -fsubr qword ptr [0x487368]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)) - cpu.fpu.st(0);
    // 0040afb0  8b1486                 -mov edx, dword ptr [esi + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0040afb3  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040afb6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040afb7  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040afbb  e8901d0400             -call 0x44cd50
    cpu.esp -= 4;
    sub_44cd50(app, cpu);
    // 0040afc0  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040afc4  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0040afc6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040afc8  7604                   -jbe 0x40afce
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040afce;
    }
    // 0040afca  fec8                   -dec al
    (cpu.al)--;
    // 0040afcc  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
L_0x0040afce:
    // 0040afce  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0040afd0  0f859d000000           -jne 0x40b073
    if (!cpu.flags.zf)
    {
        goto L_0x0040b073;
    }
    // 0040afd6  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040afda  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040afde  d90504b85100           -fld dword ptr [0x51b804]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5355524) /* 0x51b804 */)));
    // 0040afe4  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0040afe6  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 0040afec  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 0040afee  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040aff0:
    // 0040aff0  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0040aff4:
    // 0040aff4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040aff6  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0040aff9  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040affc  8d1488                 -lea edx, [eax + ecx*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 0040afff  8d0496                 -lea eax, [esi + edx*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.edx * 4);
    // 0040b002  8b549628               -mov edx, dword ptr [esi + edx*4 + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */ + cpu.edx * 4);
    // 0040b006  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040b008  7417                   -je 0x40b021
    if (cpu.flags.zf)
    {
        goto L_0x0040b021;
    }
    // 0040b00a  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0040b00d  83f8ff                 +cmp eax, -1
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
    // 0040b010  740f                   -je 0x40b021
    if (cpu.flags.zf)
    {
        goto L_0x0040b021;
    }
    // 0040b012  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040b014  668b0b                 -mov cx, word ptr [ebx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0040b017  3bc8                   +cmp ecx, eax
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
    // 0040b019  7506                   -jne 0x40b021
    if (!cpu.flags.zf)
    {
        goto L_0x0040b021;
    }
    // 0040b01b  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040b01f  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0040b021:
    // 0040b021  6681fdffff             +cmp bp, 0xffff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040b026  750c                   -jne 0x40b034
    if (!cpu.flags.zf)
    {
        goto L_0x0040b034;
    }
    // 0040b028  668b17                 -mov dx, word ptr [edi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi);
    // 0040b02b  6689542410             -mov word ptr [esp + 0x10], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 0040b030  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0040b034:
    // 0040b034  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 0040b037  663bcd                 +cmp cx, bp
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bp));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040b03a  0f8484000000           -je 0x40b0c4
    if (cpu.flags.zf)
    {
        goto L_0x0040b0c4;
    }
    // 0040b040  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0040b042  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040b047  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040b04a  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040b04d  833c86ff               +cmp dword ptr [esi + eax*4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040b051  7471                   -je 0x40b0c4
    if (cpu.flags.zf)
    {
        goto L_0x0040b0c4;
    }
    // 0040b053  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040b055  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040b05a  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040b05d  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040b060  f644861408             +test byte ptr [esi + eax*4 + 0x14], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.eax * 4) & 8 /*0x8*/));
    // 0040b065  7433                   -je 0x40b09a
    if (cpu.flags.zf)
    {
        goto L_0x0040b09a;
    }
    // 0040b067  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040b06b  66892f                 -mov word ptr [edi], bp
    app->getMemory<x86::reg16>(cpu.edi) = cpu.bp;
    // 0040b06e  668929                 -mov word ptr [ecx], bp
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.bp;
    // 0040b071  eb31                   -jmp 0x40b0a4
    goto L_0x0040b0a4;
L_0x0040b073:
    // 0040b073  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040b075  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0040b078  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0040b07b  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040b07e  8b4c8610               -mov ecx, dword ptr [esi + eax*4 + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.eax * 4);
    // 0040b082  8d448610               -lea eax, [esi + eax*4 + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.eax * 4);
    // 0040b086  81f9ffff0000           +cmp ecx, 0xffff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040b08c  0f845effffff           -je 0x40aff0
    if (cpu.flags.zf)
    {
        goto L_0x0040aff0;
    }
    // 0040b092  668be9                 -mov bp, cx
    cpu.bp = cpu.cx;
    // 0040b095  e95affffff             -jmp 0x40aff4
    goto L_0x0040aff4;
L_0x0040b09a:
    // 0040b09a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040b09e  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0040b0a1  66892f                 -mov word ptr [edi], bp
    app->getMemory<x86::reg16>(cpu.edi) = cpu.bp;
L_0x0040b0a4:
    // 0040b0a4  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040b0a8  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040b0ac  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040b0b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b0b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b0b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040b0b3  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040b0b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040b0b8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040b0ba  e8c1fbffff             -call 0x40ac80
    cpu.esp -= 4;
    sub_40ac80(app, cpu);
    // 0040b0bf  66c7030000             -mov word ptr [ebx], 0
    app->getMemory<x86::reg16>(cpu.ebx) = 0 /*0x0*/;
L_0x0040b0c4:
    // 0040b0c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b0c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b0c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b0c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b0c8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040b0cb  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40b0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040b0d0  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0040b0d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040b0d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b0d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040b0d6  68dcca4800             -push 0x48cadc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770524 /*0x48cadc*/;
    cpu.esp -= 4;
    // 0040b0db  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040b0dd  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040b0df  e8d3bc0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b0e4  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040b0e8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040b0eb  891ddc1a5200           -mov dword ptr [0x521adc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5380828) /* 0x521adc */) = cpu.ebx;
    // 0040b0f1  68007f0000             -push 0x7f00
    app->getMemory<x86::reg32>(cpu.esp-4) = 32512 /*0x7f00*/;
    cpu.esp -= 4;
    // 0040b0f6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b0f8  ff15e8714800           -call dword ptr [0x4871e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747752) /* 0x4871e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b0fe  a3481a5200             -mov dword ptr [0x521a48], eax
    app->getMemory<x86::reg32>(x86::reg32(5380680) /* 0x521a48 */) = cpu.eax;
    // 0040b103  e8e87c0500             -call 0x462df0
    cpu.esp -= 4;
    sub_462df0(app, cpu);
    // 0040b108  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b109  a190724800             -mov eax, dword ptr [0x487290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4747920) /* 0x487290 */);
    // 0040b10e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b10f  ff158c724800           -call dword ptr [0x48728c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747916) /* 0x48728c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b115  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b117  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b118  ff1588724800           -call dword ptr [0x487288]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747912) /* 0x487288 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b11e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b120  a3f0bc4a00             -mov dword ptr [0x4abcf0], eax
    app->getMemory<x86::reg32>(x86::reg32(4898032) /* 0x4abcf0 */) = cpu.eax;
    // 0040b125  751f                   -jne 0x40b146
    if (!cpu.flags.zf)
    {
        goto L_0x0040b146;
    }
    // 0040b127  ff1584724800           -call dword ptr [0x487284]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747908) /* 0x487284 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b12d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b12e  68ccca4800             -push 0x48cacc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770508 /*0x48cacc*/;
    cpu.esp -= 4;
    // 0040b133  e87fbc0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b138  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040b13b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040b13d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b13e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b13f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b140  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0040b143  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0040b146:
    // 0040b146  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040b149  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b14b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b14c  b984d44a00             -mov ecx, 0x4ad484
    cpu.ecx = 4904068 /*0x4ad484*/;
    // 0040b151  e8baec0100             -call 0x429e10
    cpu.esp -= 4;
    sub_429e10(app, cpu);
    // 0040b156  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040b158  e813020000             -call 0x40b370
    cpu.esp -= 4;
    sub_40b370(app, cpu);
    // 0040b15d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b15f  7510                   -jne 0x40b171
    if (!cpu.flags.zf)
    {
        goto L_0x0040b171;
    }
    // 0040b161  e85af50100             -call 0x42a6c0
    cpu.esp -= 4;
    sub_42a6c0(app, cpu);
    // 0040b166  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040b168  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b169  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b16a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b16b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0040b16e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0040b171:
    // 0040b171  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040b172  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0040b174  e867030200             -call 0x42b4e0
    cpu.esp -= 4;
    sub_42b4e0(app, cpu);
    // 0040b179  e822f10100             -call 0x42a2a0
    cpu.esp -= 4;
    sub_42a2a0(app, cpu);
    // 0040b17e  e8ada50500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040b183  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040b185  688cca4800             -push 0x48ca8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770444 /*0x48ca8c*/;
    cpu.esp -= 4;
    // 0040b18a  e828bc0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b18f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040b192  e859790500             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 0040b197  b139                   -mov cl, 0x39
    cpu.cl = 57 /*0x39*/;
    // 0040b199  e8427a0500             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0040b19e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b1a0  0f85a3000000           -jne 0x40b249
    if (!cpu.flags.zf)
    {
        goto L_0x0040b249;
    }
    // 0040b1a6  8b35e4714800           -mov esi, dword ptr [0x4871e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747748) /* 0x4871e4 */);
    // 0040b1ac  8b3de0714800           -mov edi, dword ptr [0x4871e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747744) /* 0x4871e0 */);
    // 0040b1b2  8b2ddc714800           -mov ebp, dword ptr [0x4871dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747740) /* 0x4871dc */);
L_0x0040b1b8:
    // 0040b1b8  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0040b1ba  e8217a0500             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0040b1bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b1c1  0f8582000000           -jne 0x40b249
    if (!cpu.flags.zf)
    {
        goto L_0x0040b249;
    }
    // 0040b1c7  b11c                   -mov cl, 0x1c
    cpu.cl = 28 /*0x1c*/;
    // 0040b1c9  e8127a0500             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0040b1ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b1d0  7577                   -jne 0x40b249
    if (!cpu.flags.zf)
    {
        goto L_0x0040b249;
    }
    // 0040b1d2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040b1d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b1d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b1d6  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040b1da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b1db  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040b1dc  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b1de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b1e0  7417                   -je 0x40b1f9
    if (cpu.flags.zf)
    {
        goto L_0x0040b1f9;
    }
    // 0040b1e2  837c241412             +cmp dword ptr [esp + 0x14], 0x12
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040b1e7  7460                   -je 0x40b249
    if (cpu.flags.zf)
    {
        goto L_0x0040b249;
    }
    // 0040b1e9  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040b1ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b1ee  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b1f0  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040b1f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b1f5  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b1f7  eb3c                   -jmp 0x40b235
    goto L_0x0040b235;
L_0x0040b1f9:
    // 0040b1f9  ff15d8714800           -call dword ptr [0x4871d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747736) /* 0x4871d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b1ff  3bd8                   +cmp ebx, eax
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
    // 0040b201  7532                   -jne 0x40b235
    if (!cpu.flags.zf)
    {
        goto L_0x0040b235;
    }
    // 0040b203  8b15f0bc4a00           -mov edx, dword ptr [0x4abcf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898032) /* 0x4abcf0 */);
    // 0040b209  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040b20a  ff1580724800           -call dword ptr [0x487280]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747904) /* 0x487280 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b210  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b212  7521                   -jne 0x40b235
    if (!cpu.flags.zf)
    {
        goto L_0x0040b235;
    }
    // 0040b214  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040b216  e885000000             -call 0x40b2a0
    cpu.esp -= 4;
    sub_40b2a0(app, cpu);
    // 0040b21b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b21d  7511                   -jne 0x40b230
    if (!cpu.flags.zf)
    {
        goto L_0x0040b230;
    }
    // 0040b21f  a1f0bc4a00             -mov eax, dword ptr [0x4abcf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898032) /* 0x4abcf0 */);
    // 0040b224  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040b227  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b229  e812030200             -call 0x42b540
    cpu.esp -= 4;
    sub_42b540(app, cpu);
    // 0040b22e  eb05                   -jmp 0x40b235
    goto L_0x0040b235;
L_0x0040b230:
    // 0040b230  83f802                 +cmp eax, 2
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
    // 0040b233  7514                   -jne 0x40b249
    if (!cpu.flags.zf)
    {
        goto L_0x0040b249;
    }
L_0x0040b235:
    // 0040b235  e8b6780500             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 0040b23a  b139                   -mov cl, 0x39
    cpu.cl = 57 /*0x39*/;
    // 0040b23c  e89f790500             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0040b241  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b243  0f846fffffff           -je 0x40b1b8
    if (cpu.flags.zf)
    {
        goto L_0x0040b1b8;
    }
L_0x0040b249:
    // 0040b249  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040b24a:
    // 0040b24a  b139                   -mov cl, 0x39
    cpu.cl = 57 /*0x39*/;
    // 0040b24c  e88f790500             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0040b251  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b253  7516                   -jne 0x40b26b
    if (!cpu.flags.zf)
    {
        goto L_0x0040b26b;
    }
    // 0040b255  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0040b257  e884790500             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0040b25c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b25e  750b                   -jne 0x40b26b
    if (!cpu.flags.zf)
    {
        goto L_0x0040b26b;
    }
    // 0040b260  b11c                   -mov cl, 0x1c
    cpu.cl = 28 /*0x1c*/;
    // 0040b262  e879790500             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0040b267  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b269  7407                   -je 0x40b272
    if (cpu.flags.zf)
    {
        goto L_0x0040b272;
    }
L_0x0040b26b:
    // 0040b26b  e880780500             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 0040b270  ebd8                   -jmp 0x40b24a
    goto L_0x0040b24a;
L_0x0040b272:
    // 0040b272  6848ca4800             -push 0x48ca48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770376 /*0x48ca48*/;
    cpu.esp -= 4;
    // 0040b277  e83bbb0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b27c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040b27f  e8cc030000             -call 0x40b650
    cpu.esp -= 4;
    sub_40b650(app, cpu);
    // 0040b284  680cca4800             -push 0x48ca0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770316 /*0x48ca0c*/;
    cpu.esp -= 4;
    // 0040b289  e829bb0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b28e  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040b292  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040b295  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b296  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b297  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b298  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0040b29b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40b2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040b2a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b2a1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040b2a3  ff15d8714800           -call dword ptr [0x4871d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747736) /* 0x4871d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b2a9  3bc6                   +cmp eax, esi
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
    // 0040b2ab  0f85b2000000           -jne 0x40b363
    if (!cpu.flags.zf)
    {
        goto L_0x0040b363;
    }
    // 0040b2b1  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0040b2b6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040b2b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b2b9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040b2bb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b2bd  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0040b2c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b2c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b2c4  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b2c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b2c9  742b                   -je 0x40b2f6
    if (cpu.flags.zf)
    {
        goto L_0x0040b2f6;
    }
L_0x0040b2cb:
    // 0040b2cb  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0040b2d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b2d1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b2d3  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b2d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b2d8  0f8585000000           -jne 0x40b363
    if (!cpu.flags.zf)
    {
        goto L_0x0040b363;
    }
    // 0040b2de  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0040b2e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b2e4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040b2e6  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0040b2eb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b2ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b2ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b2ef  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b2f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b2f4  75d5                   -jne 0x40b2cb
    if (!cpu.flags.zf)
    {
        goto L_0x0040b2cb;
    }
L_0x0040b2f6:
    // 0040b2f6  8b15f4bc4a00           -mov edx, dword ptr [0x4abcf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898036) /* 0x4abcf4 */);
    // 0040b2fc  a1f0bc4a00             -mov eax, dword ptr [0x4abcf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898032) /* 0x4abcf0 */);
    // 0040b301  8935e8bc4a00           -mov dword ptr [0x4abce8], esi
    app->getMemory<x86::reg32>(x86::reg32(4898024) /* 0x4abce8 */) = cpu.esi;
    // 0040b307  8935ecbc4a00           -mov dword ptr [0x4abcec], esi
    app->getMemory<x86::reg32>(x86::reg32(4898028) /* 0x4abcec */) = cpu.esi;
    // 0040b30d  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040b310  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040b311  8b15701a5200           -mov edx, dword ptr [0x521a70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5380720) /* 0x521a70 */);
    // 0040b317  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b318  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b319  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b31a  8b0d841a5200           -mov ecx, dword ptr [0x521a84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380740) /* 0x521a84 */);
    // 0040b320  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040b321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b322  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b323  ff15a8724800           -call dword ptr [0x4872a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747944) /* 0x4872a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b329  8b15f0bc4a00           -mov edx, dword ptr [0x4abcf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898032) /* 0x4abcf0 */);
    // 0040b32f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040b330  ff15a0724800           -call dword ptr [0x4872a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747936) /* 0x4872a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b336  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0040b33b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b33c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b33d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b33f  ff9180000000           -call dword ptr [ecx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b345  a1f0bc4a00             -mov eax, dword ptr [0x4abcf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898032) /* 0x4abcf0 */);
    // 0040b34a  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0040b34d  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0040b350  4a                     -dec edx
    (cpu.edx)--;
    // 0040b351  3bca                   +cmp ecx, edx
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
    // 0040b353  7507                   -jne 0x40b35c
    if (!cpu.flags.zf)
    {
        goto L_0x0040b35c;
    }
    // 0040b355  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040b35a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b35b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040b35c:
    // 0040b35c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b35d  ff1594724800           -call dword ptr [0x487294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747924) /* 0x487294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0040b363:
    // 0040b363  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040b365  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b366  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40b370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040b370  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040b373  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b374  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040b375  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b377  6864d44a00             -push 0x4ad464
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904036 /*0x4ad464*/;
    cpu.esp -= 4;
    // 0040b37c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b37e  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040b380  e8b15e0600             -call 0x471236
    cpu.esp -= 4;
    sub_471236(app, cpu);
    // 0040b385  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040b387  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040b389  743e                   -je 0x40b3c9
    if (cpu.flags.zf)
    {
        goto L_0x0040b3c9;
    }
    // 0040b38b  68b0cc4800             -push 0x48ccb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770992 /*0x48ccb0*/;
    cpu.esp -= 4;
L_0x0040b390:
    // 0040b390  e822ba0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b395  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040b398  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040b39a  e8a1f50100             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0040b39f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b3a0  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0040b3a5  e80dba0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b3aa  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0040b3af  e8b3c50600             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0040b3b4  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0040b3b9  e8a9c50600             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0040b3be  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040b3c1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040b3c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b3c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b3c5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040b3c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040b3c9:
    // 0040b3c9  a164d44a00             -mov eax, dword ptr [0x4ad464]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904036) /* 0x4ad464 */);
    // 0040b3ce  6868d44a00             -push 0x4ad468
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904040 /*0x4ad468*/;
    cpu.esp -= 4;
    // 0040b3d3  68787c4800             -push 0x487c78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750456 /*0x487c78*/;
    cpu.esp -= 4;
    // 0040b3d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b3d9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b3db  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b3dd  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040b3df  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040b3e1  7407                   -je 0x40b3ea
    if (cpu.flags.zf)
    {
        goto L_0x0040b3ea;
    }
    // 0040b3e3  686ccc4800             -push 0x48cc6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770924 /*0x48cc6c*/;
    cpu.esp -= 4;
    // 0040b3e8  eba6                   -jmp 0x40b390
    goto L_0x0040b390;
L_0x0040b3ea:
    // 0040b3ea  e841a30500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040b3ef  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0040b3f4  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040b3f8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b3fa  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0040b3fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040b3fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b3fe  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b401  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040b403  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040b405  742c                   -je 0x40b433
    if (cpu.flags.zf)
    {
        goto L_0x0040b433;
    }
L_0x0040b407:
    // 0040b407  e824a30500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040b40c  dc642408               -fsub qword ptr [esp + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0040b410  dc1d78754800           -fcomp qword ptr [0x487578]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748664) /* 0x487578 */)));
    cpu.fpu.pop();
    // 0040b416  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040b418  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040b41d  743f                   -je 0x40b45e
    if (cpu.flags.zf)
    {
        goto L_0x0040b45e;
    }
    // 0040b41f  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0040b424  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0040b426  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040b427  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b428  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b42a  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b42d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040b42f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040b431  75d4                   -jne 0x40b407
    if (!cpu.flags.zf)
    {
        goto L_0x0040b407;
    }
L_0x0040b433:
    // 0040b433  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0040b438  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b43a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b43c  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0040b43e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b440  68e0010000             -push 0x1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 0040b445  6880020000             -push 0x280
    app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 0040b44a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b44b  ff5254                 -call dword ptr [edx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b44e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040b450  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040b452  7414                   -je 0x40b468
    if (cpu.flags.zf)
    {
        goto L_0x0040b468;
    }
    // 0040b454  6854cc4800             -push 0x48cc54
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770900 /*0x48cc54*/;
    cpu.esp -= 4;
    // 0040b459  e932ffffff             -jmp 0x40b390
    goto L_0x0040b390;
L_0x0040b45e:
    // 0040b45e  681ccc4800             -push 0x48cc1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770844 /*0x48cc1c*/;
    cpu.esp -= 4;
    // 0040b463  e928ffffff             -jmp 0x40b390
    goto L_0x0040b390;
L_0x0040b468:
    // 0040b468  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 0040b46d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040b46f  bf601a5200             -mov edi, 0x521a60
    cpu.edi = 5380704 /*0x521a60*/;
    // 0040b474  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b476  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040b478  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0040b47d  bf40400000             -mov edi, 0x4040
    cpu.edi = 16448 /*0x4040*/;
    // 0040b482  c705601a52007c000000   -mov dword ptr [0x521a60], 0x7c
    app->getMemory<x86::reg32>(x86::reg32(5380704) /* 0x521a60 */) = 124 /*0x7c*/;
    // 0040b48c  c705641a520007000000   -mov dword ptr [0x521a64], 7
    app->getMemory<x86::reg32>(x86::reg32(5380708) /* 0x521a64 */) = 7 /*0x7*/;
    // 0040b496  c705681a5200e0010000   -mov dword ptr [0x521a68], 0x1e0
    app->getMemory<x86::reg32>(x86::reg32(5380712) /* 0x521a68 */) = 480 /*0x1e0*/;
    // 0040b4a0  c7056c1a520080020000   -mov dword ptr [0x521a6c], 0x280
    app->getMemory<x86::reg32>(x86::reg32(5380716) /* 0x521a6c */) = 640 /*0x280*/;
    // 0040b4aa  893dc81a5200           -mov dword ptr [0x521ac8], edi
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = cpu.edi;
    // 0040b4b0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b4b2  6870d44a00             -push 0x4ad470
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904048 /*0x4ad470*/;
    cpu.esp -= 4;
    // 0040b4b7  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0040b4bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b4bd  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b4c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b4c2  7450                   -je 0x40b514
    if (cpu.flags.zf)
    {
        goto L_0x0040b514;
    }
    // 0040b4c4  68eccb4800             -push 0x48cbec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770796 /*0x48cbec*/;
    cpu.esp -= 4;
    // 0040b4c9  e8e9b80600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b4ce  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0040b4d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040b4d6  c705c81a520040080000   -mov dword ptr [0x521ac8], 0x840
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = 2112 /*0x840*/;
    // 0040b4e0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b4e2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b4e4  6870d44a00             -push 0x4ad470
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904048 /*0x4ad470*/;
    cpu.esp -= 4;
    // 0040b4e9  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0040b4ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b4ef  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b4f2  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040b4f4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040b4f6  741c                   -je 0x40b514
    if (cpu.flags.zf)
    {
        goto L_0x0040b514;
    }
    // 0040b4f8  68cccb4800             -push 0x48cbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770764 /*0x48cbcc*/;
    cpu.esp -= 4;
    // 0040b4fd  e8b5b80600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b502  68b0cb4800             -push 0x48cbb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770736 /*0x48cbb0*/;
    cpu.esp -= 4;
    // 0040b507  e8abb80600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b50c  83c408                 +add esp, 8
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
    // 0040b50f  e9c4000000             -jmp 0x40b5d8
    goto L_0x0040b5d8;
L_0x0040b514:
    // 0040b514  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0040b519  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b51b  893dc81a5200           -mov dword ptr [0x521ac8], edi
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = cpu.edi;
    // 0040b521  6874d44a00             -push 0x4ad474
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904052 /*0x4ad474*/;
    cpu.esp -= 4;
    // 0040b526  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b528  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0040b52d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b52e  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b531  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b533  744d                   -je 0x40b582
    if (cpu.flags.zf)
    {
        goto L_0x0040b582;
    }
    // 0040b535  6880cb4800             -push 0x48cb80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770688 /*0x48cb80*/;
    cpu.esp -= 4;
    // 0040b53a  e878b80600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b53f  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0040b544  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040b547  c705c81a520040080000   -mov dword ptr [0x521ac8], 0x840
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = 2112 /*0x840*/;
    // 0040b551  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b553  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b555  6874d44a00             -push 0x4ad474
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904052 /*0x4ad474*/;
    cpu.esp -= 4;
    // 0040b55a  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0040b55f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b560  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b563  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040b565  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040b567  7419                   -je 0x40b582
    if (cpu.flags.zf)
    {
        goto L_0x0040b582;
    }
    // 0040b569  6860cb4800             -push 0x48cb60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770656 /*0x48cb60*/;
    cpu.esp -= 4;
    // 0040b56e  e844b80600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b573  6844cb4800             -push 0x48cb44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770628 /*0x48cb44*/;
    cpu.esp -= 4;
    // 0040b578  e83ab80600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b57d  83c408                 +add esp, 8
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
    // 0040b580  eb56                   -jmp 0x40b5d8
    goto L_0x0040b5d8;
L_0x0040b582:
    // 0040b582  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 0040b587  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040b589  bf601a5200             -mov edi, 0x521a60
    cpu.edi = 5380704 /*0x521a60*/;
    // 0040b58e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040b590  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040b592  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0040b597  c705601a52007c000000   -mov dword ptr [0x521a60], 0x7c
    app->getMemory<x86::reg32>(x86::reg32(5380704) /* 0x521a60 */) = 124 /*0x7c*/;
    // 0040b5a1  c705641a520001000000   -mov dword ptr [0x521a64], 1
    app->getMemory<x86::reg32>(x86::reg32(5380708) /* 0x521a64 */) = 1 /*0x1*/;
    // 0040b5ab  c705c81a520000020000   -mov dword ptr [0x521ac8], 0x200
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = 512 /*0x200*/;
    // 0040b5b5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b5b7  6878d44a00             -push 0x4ad478
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904056 /*0x4ad478*/;
    cpu.esp -= 4;
    // 0040b5bc  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0040b5c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b5c2  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b5c5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040b5c7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040b5c9  7434                   -je 0x40b5ff
    if (cpu.flags.zf)
    {
        goto L_0x0040b5ff;
    }
    // 0040b5cb  6824cb4800             -push 0x48cb24
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770596 /*0x48cb24*/;
    cpu.esp -= 4;
    // 0040b5d0  e8e2b70600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b5d5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040b5d8:
    // 0040b5d8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040b5da  e861f30100             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0040b5df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b5e0  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0040b5e5  e8cdb70600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040b5ea  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0040b5ef  e873c30600             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0040b5f4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040b5f7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040b5f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b5fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b5fb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040b5fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040b5ff:
    // 0040b5ff  8b1578d44a00           -mov edx, dword ptr [0x4ad478]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0040b605  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040b606  ff15a4724800           -call dword ptr [0x4872a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747940) /* 0x4872a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b60c  8b0d78d44a00           -mov ecx, dword ptr [0x4ad478]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0040b612  a3f4bc4a00             -mov dword ptr [0x4abcf4], eax
    app->getMemory<x86::reg32>(x86::reg32(4898036) /* 0x4abcf4 */) = cpu.eax;
    // 0040b617  a1481a5200             -mov eax, dword ptr [0x521a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380680) /* 0x521a48 */);
    // 0040b61c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b61d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b61e  ff159c724800           -call dword ptr [0x48729c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747932) /* 0x48729c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040b624  8b0d6cd44a00           -mov ecx, dword ptr [0x4ad46c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904044) /* 0x4ad46c */);
    // 0040b62a  ba18cb4800             -mov edx, 0x48cb18
    cpu.edx = 4770584 /*0x48cb18*/;
    // 0040b62f  a34c1a5200             -mov dword ptr [0x521a4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5380684) /* 0x521a4c */) = cpu.eax;
    // 0040b634  e857090200             -call 0x42bf90
    cpu.esp -= 4;
    sub_42bf90(app, cpu);
    // 0040b639  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040b63b  a36cd44a00             -mov dword ptr [0x4ad46c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904044) /* 0x4ad46c */) = cpu.eax;
    // 0040b640  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b642  0f95c2                 -setne dl
    cpu.dl = !cpu.flags.zf;
    // 0040b645  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b646  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040b648  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b649  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040b64c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40b650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040b650  a1f0bc4a00             -mov eax, dword ptr [0x4abcf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898032) /* 0x4abcf0 */);
    // 0040b655  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b657  7407                   -je 0x40b660
    if (cpu.flags.zf)
    {
        goto L_0x0040b660;
    }
    // 0040b659  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b65a  ff1598724800           -call dword ptr [0x487298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747928) /* 0x487298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0040b660:
    // 0040b660  e85bf00100             -call 0x42a6c0
    cpu.esp -= 4;
    sub_42a6c0(app, cpu);
    // 0040b665  8b0d98d44a00           -mov ecx, dword ptr [0x4ad498]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904088) /* 0x4ad498 */);
    // 0040b66b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040b66d  7405                   -je 0x40b674
    if (cpu.flags.zf)
    {
        goto L_0x0040b674;
    }
    // 0040b66f  e93cfe0100             -jmp 0x42b4b0
    return sub_42b4b0(app, cpu);
L_0x0040b674:
    // 0040b674  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40b680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040b680  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040b682  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040b684  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0040b687  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0040b689  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0040b68c  c7400cffffffff         -mov dword ptr [eax + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 0040b693  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40b6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040b6a0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040b6a4  83ec78                 +sub esp, 0x78
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040b6a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040b6a8  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0040b6aa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040b6ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b6ac  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0040b6af  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040b6b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040b6b1  0f844e010000           -je 0x40b805
    if (cpu.flags.zf)
    {
        goto L_0x0040b805;
    }
    // 0040b6b7  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040b6b8  0f84a7000000           -je 0x40b765
    if (cpu.flags.zf)
    {
        goto L_0x0040b765;
    }
    // 0040b6be  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040b6bf  0f8549050000           -jne 0x40bc0e
    if (!cpu.flags.zf)
    {
        goto L_0x0040bc0e;
    }
    // 0040b6c5  8d7b08                 -lea edi, [ebx + 8]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0040b6c8  b928cd4800             -mov ecx, 0x48cd28
    cpu.ecx = 4771112 /*0x48cd28*/;
    // 0040b6cd  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040b6cf  e81c760200             -call 0x432cf0
    cpu.esp -= 4;
    sub_432cf0(app, cpu);
    // 0040b6d4  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0040b6d6  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040b6d8  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040b6da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b6dc  7e2f                   -jle 0x40b70d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040b70d;
    }
    // 0040b6de  bd50c24000             -mov ebp, 0x40c250
    cpu.ebp = 4244048 /*0x40c250*/;
L_0x0040b6e3:
    // 0040b6e3  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040b6e5  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0040b6e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b6e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b6ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b6eb  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040b6ed  e82e050000             -call 0x40bc20
    cpu.esp -= 4;
    sub_40bc20(app, cpu);
    // 0040b6f2  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040b6f4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b6fa  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040b6fd  46                     -inc esi
    (cpu.esi)++;
    // 0040b6fe  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b701  89aa0c030000           -mov dword ptr [edx + 0x30c], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(780) /* 0x30c */) = cpu.ebp;
    // 0040b707  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040b709  3bf0                   +cmp esi, eax
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
    // 0040b70b  7cd6                   -jl 0x40b6e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040b6e3;
    }
L_0x0040b70d:
    // 0040b70d  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040b70f  b920cd4800             -mov ecx, 0x48cd20
    cpu.ecx = 4771104 /*0x48cd20*/;
    // 0040b714  e8d7750200             -call 0x432cf0
    cpu.esp -= 4;
    sub_432cf0(app, cpu);
    // 0040b719  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0040b71c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040b71e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040b720  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b722  0f8ee6040000           -jle 0x40bc0e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040bc0e;
    }
    // 0040b728  bd90c24000             -mov ebp, 0x40c290
    cpu.ebp = 4244112 /*0x40c290*/;
L_0x0040b72d:
    // 0040b72d  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040b730  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0040b733  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b734  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b735  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b736  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040b738  e8c3070000             -call 0x40bf00
    cpu.esp -= 4;
    sub_40bf00(app, cpu);
    // 0040b73d  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040b740  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b746  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040b749  46                     -inc esi
    (cpu.esi)++;
    // 0040b74a  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b74d  89aa0c030000           -mov dword ptr [edx + 0x30c], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(780) /* 0x30c */) = cpu.ebp;
    // 0040b753  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040b755  3bf0                   +cmp esi, eax
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
    // 0040b757  7cd4                   -jl 0x40b72d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040b72d;
    }
    // 0040b759  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b75a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b75b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b75c  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0040b75e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b75f  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0040b762  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0040b765:
    // 0040b765  8d7b08                 -lea edi, [ebx + 8]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0040b768  b918cd4800             -mov ecx, 0x48cd18
    cpu.ecx = 4771096 /*0x48cd18*/;
    // 0040b76d  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040b76f  e87c750200             -call 0x432cf0
    cpu.esp -= 4;
    sub_432cf0(app, cpu);
    // 0040b774  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0040b776  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040b778  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040b77a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b77c  7e2f                   -jle 0x40b7ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040b7ad;
    }
    // 0040b77e  bde0c14000             -mov ebp, 0x40c1e0
    cpu.ebp = 4243936 /*0x40c1e0*/;
L_0x0040b783:
    // 0040b783  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040b785  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0040b788  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b789  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b78a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b78b  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040b78d  e88e040000             -call 0x40bc20
    cpu.esp -= 4;
    sub_40bc20(app, cpu);
    // 0040b792  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040b794  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b79a  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040b79d  46                     -inc esi
    (cpu.esi)++;
    // 0040b79e  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b7a1  89aa0c030000           -mov dword ptr [edx + 0x30c], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(780) /* 0x30c */) = cpu.ebp;
    // 0040b7a7  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040b7a9  3bf0                   +cmp esi, eax
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
    // 0040b7ab  7cd6                   -jl 0x40b783
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040b783;
    }
L_0x0040b7ad:
    // 0040b7ad  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040b7af  b910cd4800             -mov ecx, 0x48cd10
    cpu.ecx = 4771088 /*0x48cd10*/;
    // 0040b7b4  e837750200             -call 0x432cf0
    cpu.esp -= 4;
    sub_432cf0(app, cpu);
    // 0040b7b9  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0040b7bc  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040b7be  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040b7c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b7c2  0f8e46040000           -jle 0x40bc0e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040bc0e;
    }
    // 0040b7c8  bd20c24000             -mov ebp, 0x40c220
    cpu.ebp = 4244000 /*0x40c220*/;
L_0x0040b7cd:
    // 0040b7cd  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040b7d0  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0040b7d3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040b7d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040b7d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b7d6  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040b7d8  e823070000             -call 0x40bf00
    cpu.esp -= 4;
    sub_40bf00(app, cpu);
    // 0040b7dd  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040b7e0  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b7e6  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040b7e9  46                     -inc esi
    (cpu.esi)++;
    // 0040b7ea  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b7ed  89aa0c030000           -mov dword ptr [edx + 0x30c], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(780) /* 0x30c */) = cpu.ebp;
    // 0040b7f3  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040b7f5  3bf0                   +cmp esi, eax
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
    // 0040b7f7  7cd4                   -jl 0x40b7cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040b7cd;
    }
    // 0040b7f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b7fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b7fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b7fc  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0040b7fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040b7ff  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0040b802  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0040b805:
    // 0040b805  8d6b08                 -lea ebp, [ebx + 8]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0040b808  b908cd4800             -mov ecx, 0x48cd08
    cpu.ecx = 4771080 /*0x48cd08*/;
    // 0040b80d  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0040b80f  e8dc740200             -call 0x432cf0
    cpu.esp -= 4;
    sub_432cf0(app, cpu);
    // 0040b814  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0040b816  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0040b819  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040b81b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040b81d  0f8edd020000           -jle 0x40bb00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040bb00;
    }
L_0x0040b823:
    // 0040b823  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040b825  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b82b  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b82e  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b831  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040b837  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040b83a  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040b840  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b843  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b848  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040b84b  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040b851  83e2fd                 -and edx, 0xfffffffd
    cpu.edx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/));
    // 0040b854  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040b85a  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b85d  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b863  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040b866  e8b5ec0300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040b86b  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b86e  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b874  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b877  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0040b87a  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0040b87d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040b87f  7519                   -jne 0x40b89a
    if (!cpu.flags.zf)
    {
        goto L_0x0040b89a;
    }
    // 0040b881  8b88b4020000           -mov ecx, dword ptr [eax + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(692) /* 0x2b4 */);
    // 0040b887  e8843f0500             -call 0x45f810
    cpu.esp -= 4;
    sub_45f810(app, cpu);
    // 0040b88c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040b88d  68d8cc4800             -push 0x48ccd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771032 /*0x48ccd8*/;
    cpu.esp -= 4;
    // 0040b892  e879930100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040b897  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040b89a:
    // 0040b89a  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b89d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b8a3  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b8a6  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040b8ac  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040b8af  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040b8b5  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b8b8  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b8bd  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040b8c0  e85bec0300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040b8c5  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b8c8  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b8ce  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040b8d1  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040b8d7  83e1bf                 -and ecx, 0xffffffbf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/));
    // 0040b8da  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040b8e0  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b8e3  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b8e9  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b8ec  e82fec0300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040b8f1  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b8f4  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b8f9  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040b8fc  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040b8ff  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0040b905  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0040b909  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b90b  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0040b911  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 0040b915  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b917  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0040b91d  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 0040b921  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b923  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040b927  e884330500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040b92c  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b92f  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b935  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040b939  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b93c  e8ff7a0400             -call 0x453440
    cpu.esp -= 4;
    sub_453440(app, cpu);
    // 0040b941  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b944  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b94a  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040b94e  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040b951  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040b952  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0040b956  8b88c8020000           -mov ecx, dword ptr [eax + 0x2c8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */);
    // 0040b95c  e8df850400             -call 0x453f40
    cpu.esp -= 4;
    sub_453f40(app, cpu);
    // 0040b961  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b964  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b96a  dc2518754800           -fsub qword ptr [0x487518]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4748568) /* 0x487518 */));
    // 0040b970  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040b973  ba17000000             -mov edx, 0x17
    cpu.edx = 23 /*0x17*/;
    // 0040b978  8d4c2438               -lea ecx, [esp + 0x38]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040b97c  d998d4000000           -fstp dword ptr [eax + 0xd4]
    app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040b982  e8c9100400             -call 0x44ca50
    cpu.esp -= 4;
    sub_44ca50(app, cpu);
    // 0040b987  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b98a  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b990  d9442444               -fld dword ptr [esp + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 0040b994  8d048a                 -lea eax, [edx + ecx*4]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 4);
    // 0040b997  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040b99a  d84928                 -fmul dword ptr [ecx + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(40) /* 0x28 */));
    // 0040b99d  d9442440               -fld dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 0040b9a1  d8492c                 -fmul dword ptr [ecx + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */));
    // 0040b9a4  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040b9a6  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040b9aa  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b9ac  d944243c               -fld dword ptr [esp + 0x3c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */)));
    // 0040b9b0  d8492c                 -fmul dword ptr [ecx + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */));
    // 0040b9b3  d9442444               -fld dword ptr [esp + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 0040b9b7  d84924                 -fmul dword ptr [ecx + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */));
    // 0040b9ba  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040b9be  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040b9c0  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040b9c4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040b9c6  d9442440               -fld dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 0040b9ca  d84824                 -fmul dword ptr [eax + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 0040b9cd  d944243c               -fld dword ptr [esp + 0x3c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */)));
    // 0040b9d1  d84828                 -fmul dword ptr [eax + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 0040b9d4  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040b9d6  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040b9da  e8b1120400             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 0040b9df  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0040b9e5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040b9e7  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040b9ea  0f8bea000000           -jnp 0x40bada
    if (!cpu.flags.pf)
    {
        goto L_0x0040bada;
    }
    // 0040b9f0  d83d94744800           +fdivr dword ptr [0x487494]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)) / cpu.fpu.st(0);
    // 0040b9f6  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040b9f9  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040b9ff  d9442414               +fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0040ba03  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040ba05  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040ba09  d9442418               +fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0040ba0d  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040ba0f  d95c2418               +fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040ba13  d84c241c               +fmul dword ptr [esp + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */));
    // 0040ba17  d95c241c               +fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040ba1b  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040ba1e  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0040ba22  89424c                 -mov dword ptr [edx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0040ba25  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040ba28  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ba2e  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040ba31  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0040ba35  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 0040ba38  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040ba3b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ba40  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040ba43  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0040ba47  895154                 -mov dword ptr [ecx + 0x54], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0040ba4a  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040ba4d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ba53  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040ba56  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040ba5a  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0040ba5d  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040ba60  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ba66  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040ba69  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040ba6d  894878                 -mov dword ptr [eax + 0x78], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */) = cpu.ecx;
    // 0040ba70  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040ba73  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ba78  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040ba7b  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040ba7f  89517c                 -mov dword ptr [ecx + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0040ba82  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040ba85  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ba8b  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040ba8e  d9407c                 +fld dword ptr [eax + 0x7c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */)));
    // 0040ba91  d84850                 +fmul dword ptr [eax + 0x50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(80) /* 0x50 */));
    // 0040ba94  d94078                 +fld dword ptr [eax + 0x78]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(120) /* 0x78 */)));
    // 0040ba97  d84854                 +fmul dword ptr [eax + 0x54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */));
    // 0040ba9a  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040ba9c  d95824                 +fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040ba9f  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040baa2  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040baa7  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040baaa  d94074                 +fld dword ptr [eax + 0x74]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(116) /* 0x74 */)));
    // 0040baad  d84854                 +fmul dword ptr [eax + 0x54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */));
    // 0040bab0  d9407c                 +fld dword ptr [eax + 0x7c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */)));
    // 0040bab3  d8484c                 +fmul dword ptr [eax + 0x4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(76) /* 0x4c */));
    // 0040bab6  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bab8  d95828                 +fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040babb  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040babe  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bac4  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bac7  d94078                 +fld dword ptr [eax + 0x78]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(120) /* 0x78 */)));
    // 0040baca  d8484c                 +fmul dword ptr [eax + 0x4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(76) /* 0x4c */));
    // 0040bacd  d94074                 +fld dword ptr [eax + 0x74]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(116) /* 0x74 */)));
    // 0040bad0  d84850                 +fmul dword ptr [eax + 0x50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(80) /* 0x50 */));
    // 0040bad3  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bad5  d9582c                 +fstp dword ptr [eax + 0x2c]
    app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bad8  eb02                   -jmp 0x40badc
    goto L_0x0040badc;
L_0x0040bada:
    // 0040bada  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040badc:
    // 0040badc  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040bade  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bae4  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0040bae7  46                     -inc esi
    (cpu.esi)++;
    // 0040bae8  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040baeb  c7800c03000070c14000   -mov dword ptr [eax + 0x30c], 0x40c170
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(780) /* 0x30c */) = 4243824 /*0x40c170*/;
    // 0040baf5  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0040baf8  3bf0                   +cmp esi, eax
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
    // 0040bafa  0f8c23fdffff           -jl 0x40b823
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040b823;
    }
L_0x0040bb00:
    // 0040bb00  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0040bb02  b9d0cc4800             -mov ecx, 0x48ccd0
    cpu.ecx = 4771024 /*0x48ccd0*/;
    // 0040bb07  e8e4710200             -call 0x432cf0
    cpu.esp -= 4;
    sub_432cf0(app, cpu);
    // 0040bb0c  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0040bb0f  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0040bb12  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040bb14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040bb16  0f8ef2000000           -jle 0x40bc0e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040bc0e;
    }
L_0x0040bb1c:
    // 0040bb1c  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040bb1f  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bb25  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040bb28  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bb2b  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bb31  83ca10                 -or edx, 0x10
    cpu.edx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040bb34  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040bb3a  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040bb3d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bb43  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bb46  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bb4c  83e1fd                 -and ecx, 0xfffffffd
    cpu.ecx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/));
    // 0040bb4f  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040bb55  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040bb58  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bb5d  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bb60  e8bbe90300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bb65  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040bb68  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bb6e  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bb71  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0040bb74  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0040bb77  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040bb79  7519                   -jne 0x40bb94
    if (!cpu.flags.zf)
    {
        goto L_0x0040bb94;
    }
    // 0040bb7b  8b88b4020000           -mov ecx, dword ptr [eax + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(692) /* 0x2b4 */);
    // 0040bb81  e88a3c0500             -call 0x45f810
    cpu.esp -= 4;
    sub_45f810(app, cpu);
    // 0040bb86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040bb87  68d8cc4800             -push 0x48ccd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771032 /*0x48ccd8*/;
    cpu.esp -= 4;
    // 0040bb8c  e87f900100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040bb91  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040bb94:
    // 0040bb94  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040bb97  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bb9c  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bb9f  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bba5  83c920                 -or ecx, 0x20
    cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040bba8  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040bbae  8b0cb7                 -mov ecx, dword ptr [edi + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040bbb1  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bbb7  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bbba  e861e90300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bbbf  8b04b7                 -mov eax, dword ptr [edi + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040bbc2  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bbc8  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bbcb  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bbd1  83e2bf                 -and edx, 0xffffffbf
    cpu.edx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/));
    // 0040bbd4  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040bbda  8b14b7                 -mov edx, dword ptr [edi + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    // 0040bbdd  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bbe2  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bbe5  e836e90300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bbea  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040bbed  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bbf2  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0040bbf5  46                     -inc esi
    (cpu.esi)++;
    // 0040bbf6  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bbf9  c7810c030000b0c14000   -mov dword ptr [ecx + 0x30c], 0x40c1b0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(780) /* 0x30c */) = 4243888 /*0x40c1b0*/;
    // 0040bc03  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0040bc06  3bf0                   +cmp esi, eax
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
    // 0040bc08  0f8c0effffff           -jl 0x40bb1c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040bb1c;
    }
L_0x0040bc0e:
    // 0040bc0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bc0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bc10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bc11  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0040bc13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bc14  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0040bc17  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40bc20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bc20  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0040bc23  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bc29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040bc2a  8bb42480000000         -mov esi, dword ptr [esp + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0040bc31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040bc32  8bbc2488000000         -mov edi, dword ptr [esp + 0x88]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0040bc39  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bc3c  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bc3f  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bc45  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040bc48  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040bc4e  8b14be                 -mov edx, dword ptr [esi + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bc51  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bc56  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bc59  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bc5f  83e2fd                 -and edx, 0xfffffffd
    cpu.edx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/));
    // 0040bc62  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040bc68  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bc6b  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bc71  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bc74  e8a7e80300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bc79  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bc7c  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bc82  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bc85  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0040bc88  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0040bc8b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040bc8d  7519                   -jne 0x40bca8
    if (!cpu.flags.zf)
    {
        goto L_0x0040bca8;
    }
    // 0040bc8f  8b88b4020000           -mov ecx, dword ptr [eax + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(692) /* 0x2b4 */);
    // 0040bc95  e8763b0500             -call 0x45f810
    cpu.esp -= 4;
    sub_45f810(app, cpu);
    // 0040bc9a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040bc9b  68d8cc4800             -push 0x48ccd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771032 /*0x48ccd8*/;
    cpu.esp -= 4;
    // 0040bca0  e86b8f0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040bca5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040bca8:
    // 0040bca8  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bcab  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bcb1  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bcb4  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bcba  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040bcbd  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040bcc3  8b14be                 -mov edx, dword ptr [esi + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bcc6  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bccb  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bcce  e84de80300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bcd3  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bcd6  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bcdc  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bcdf  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bce5  83e1bf                 -and ecx, 0xffffffbf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/));
    // 0040bce8  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040bcee  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bcf1  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bcf7  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bcfa  e821e80300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bcff  8b14be                 -mov edx, dword ptr [esi + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bd02  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bd07  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bd0a  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 0040bd0d  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0040bd13  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 0040bd17  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040bd19  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0040bd1f  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0040bd23  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040bd25  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0040bd2b  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0040bd2f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040bd31  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040bd35  e8762f0500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040bd3a  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bd3d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bd43  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040bd47  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bd4a  e8f1760400             -call 0x453440
    cpu.esp -= 4;
    sub_453440(app, cpu);
    // 0040bd4f  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bd52  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bd58  8d542430               -lea edx, [esp + 0x30]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040bd5c  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bd5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040bd60  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0040bd64  8b88c8020000           -mov ecx, dword ptr [eax + 0x2c8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */);
    // 0040bd6a  e8d1810400             -call 0x453f40
    cpu.esp -= 4;
    sub_453f40(app, cpu);
    // 0040bd6f  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bd72  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bd78  dc2518754800           -fsub qword ptr [0x487518]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4748568) /* 0x487518 */));
    // 0040bd7e  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bd81  ba17000000             -mov edx, 0x17
    cpu.edx = 23 /*0x17*/;
    // 0040bd86  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0040bd8a  d998d4000000           -fstp dword ptr [eax + 0xd4]
    app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bd90  e8bb0c0400             -call 0x44ca50
    cpu.esp -= 4;
    sub_44ca50(app, cpu);
    // 0040bd95  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bd98  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bd9e  d944243c               -fld dword ptr [esp + 0x3c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */)));
    // 0040bda2  8d048a                 -lea eax, [edx + ecx*4]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 4);
    // 0040bda5  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bda8  d84928                 -fmul dword ptr [ecx + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(40) /* 0x28 */));
    // 0040bdab  d9442438               -fld dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */)));
    // 0040bdaf  d8492c                 -fmul dword ptr [ecx + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */));
    // 0040bdb2  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bdb4  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bdb8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040bdba  d9442434               -fld dword ptr [esp + 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */)));
    // 0040bdbe  d8492c                 -fmul dword ptr [ecx + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */));
    // 0040bdc1  d944243c               -fld dword ptr [esp + 0x3c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */)));
    // 0040bdc5  d84924                 -fmul dword ptr [ecx + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */));
    // 0040bdc8  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040bdcc  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bdce  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bdd2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040bdd4  d9442438               -fld dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */)));
    // 0040bdd8  d84824                 -fmul dword ptr [eax + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 0040bddb  d9442434               -fld dword ptr [esp + 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */)));
    // 0040bddf  d84828                 -fmul dword ptr [eax + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 0040bde2  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bde4  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bde8  e8a30e0400             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 0040bded  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0040bdf3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040bdf5  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040bdf8  0f8bf0000000           -jnp 0x40beee
    if (!cpu.flags.pf)
    {
        goto L_0x0040beee;
    }
    // 0040bdfe  d83d94744800           -fdivr dword ptr [0x487494]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)) / cpu.fpu.st(0);
    // 0040be04  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040be07  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040be0d  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0040be11  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040be13  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040be17  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0040be1b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040be1d  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040be21  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0040be25  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040be29  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040be2c  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040be30  89424c                 -mov dword ptr [edx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0040be33  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040be36  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040be3c  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040be3f  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040be43  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 0040be46  8b14be                 -mov edx, dword ptr [esi + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040be49  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040be4e  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040be51  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0040be55  895154                 -mov dword ptr [ecx + 0x54], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0040be58  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040be5b  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040be61  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040be64  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040be68  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0040be6b  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040be6e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040be74  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040be77  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040be7b  894878                 -mov dword ptr [eax + 0x78], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */) = cpu.ecx;
    // 0040be7e  8b14be                 -mov edx, dword ptr [esi + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040be81  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040be86  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040be89  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040be8d  89517c                 -mov dword ptr [ecx + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0040be90  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040be93  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040be99  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040be9c  d9407c                 -fld dword ptr [eax + 0x7c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */)));
    // 0040be9f  d84850                 -fmul dword ptr [eax + 0x50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(80) /* 0x50 */));
    // 0040bea2  d94078                 -fld dword ptr [eax + 0x78]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(120) /* 0x78 */)));
    // 0040bea5  d84854                 -fmul dword ptr [eax + 0x54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */));
    // 0040bea8  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040beaa  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bead  8b14be                 -mov edx, dword ptr [esi + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040beb0  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040beb5  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040beb8  d94074                 -fld dword ptr [eax + 0x74]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(116) /* 0x74 */)));
    // 0040bebb  d84854                 -fmul dword ptr [eax + 0x54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */));
    // 0040bebe  d9407c                 -fld dword ptr [eax + 0x7c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */)));
    // 0040bec1  d8484c                 -fmul dword ptr [eax + 0x4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(76) /* 0x4c */));
    // 0040bec4  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bec6  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bec9  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040becc  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bed2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bed3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bed4  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bed7  d94078                 -fld dword ptr [eax + 0x78]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(120) /* 0x78 */)));
    // 0040beda  d8484c                 -fmul dword ptr [eax + 0x4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(76) /* 0x4c */));
    // 0040bedd  d94074                 -fld dword ptr [eax + 0x74]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(116) /* 0x74 */)));
    // 0040bee0  d84850                 -fmul dword ptr [eax + 0x50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(80) /* 0x50 */));
    // 0040bee3  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bee5  d9582c                 -fstp dword ptr [eax + 0x2c]
    app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bee8  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0040beeb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0040beee:
    // 0040beee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040beef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bef0  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bef2  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0040bef5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40bf00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bf00  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bf06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040bf07  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040bf0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040bf0c  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040bf10  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bf13  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bf16  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bf1c  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040bf1f  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040bf25  8b14be                 -mov edx, dword ptr [esi + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bf28  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bf2d  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bf30  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bf36  83e2fd                 -and edx, 0xfffffffd
    cpu.edx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/));
    // 0040bf39  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040bf3f  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bf42  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bf48  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bf4b  e8d0e50300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bf50  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bf53  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bf59  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bf5c  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0040bf5f  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0040bf62  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040bf64  7519                   -jne 0x40bf7f
    if (!cpu.flags.zf)
    {
        goto L_0x0040bf7f;
    }
    // 0040bf66  8b88b4020000           -mov ecx, dword ptr [eax + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(692) /* 0x2b4 */);
    // 0040bf6c  e89f380500             -call 0x45f810
    cpu.esp -= 4;
    sub_45f810(app, cpu);
    // 0040bf71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040bf72  68d8cc4800             -push 0x48ccd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771032 /*0x48ccd8*/;
    cpu.esp -= 4;
    // 0040bf77  e8948c0100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040bf7c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040bf7f:
    // 0040bf7f  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bf82  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bf88  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bf8b  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bf91  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040bf94  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040bf9a  8b14be                 -mov edx, dword ptr [esi + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bf9d  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bfa2  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040bfa5  e876e50300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bfaa  8b0cbe                 -mov ecx, dword ptr [esi + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bfad  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bfb3  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040bfb6  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040bfbc  83e1bf                 -and ecx, 0xffffffbf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/));
    // 0040bfbf  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040bfc5  8b04be                 -mov eax, dword ptr [esi + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4);
    // 0040bfc8  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040bfce  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040bfd1  e84ae50300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040bfd6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bfd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bfd8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40bfe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bfe0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040bfe1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040bfe3  83feff                 +cmp esi, -1
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
    // 0040bfe6  7e3e                   -jle 0x40c026
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c026;
    }
    // 0040bfe8  83fe18                 +cmp esi, 0x18
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040bfeb  7d39                   -jge 0x40c026
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c026;
    }
    // 0040bfed  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0040bfef  e86bbd0600             -call 0x477d5f
    cpu.esp -= 4;
    sub_477d5f(app, cpu);
    // 0040bff4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040bff7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040bff9  7418                   -je 0x40c013
    if (cpu.flags.zf)
    {
        goto L_0x0040c013;
    }
    // 0040bffb  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040bffd  e87ef6ffff             -call 0x40b680
    cpu.esp -= 4;
    sub_40b680(app, cpu);
    // 0040c002  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040c004  8904b508bd4a00         -mov dword ptr [esi*4 + 0x4abd08], eax
    app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4) = cpu.eax;
    // 0040c00b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c00c  e88ff6ffff             -call 0x40b6a0
    cpu.esp -= 4;
    sub_40b6a0(app, cpu);
    // 0040c011  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c012  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c013:
    // 0040c013  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c015  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c016  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040c018  8904b508bd4a00         -mov dword ptr [esi*4 + 0x4abd08], eax
    app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4) = cpu.eax;
    // 0040c01f  e87cf6ffff             -call 0x40b6a0
    cpu.esp -= 4;
    sub_40b6a0(app, cpu);
    // 0040c024  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c025  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c026:
    // 0040c026  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0040c028  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c029  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40c030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c030  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c031  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c032  be08bd4a00             -mov esi, 0x4abd08
    cpu.esi = 4898056 /*0x4abd08*/;
    // 0040c037  bf18000000             -mov edi, 0x18
    cpu.edi = 24 /*0x18*/;
L_0x0040c03c:
    // 0040c03c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040c03e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040c040  740f                   -je 0x40c051
    if (cpu.flags.zf)
    {
        goto L_0x0040c051;
    }
    // 0040c042  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040c043  e825bd0600             -call 0x477d6d
    cpu.esp -= 4;
    sub_477d6d(app, cpu);
    // 0040c048  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040c04b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0040c051:
    // 0040c051  83c604                 +add esi, 4
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
    // 0040c054  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040c055  75e5                   -jne 0x40c03c
    if (!cpu.flags.zf)
    {
        goto L_0x0040c03c;
    }
    // 0040c057  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c058  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c059  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40c060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c060  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c061  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040c065  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0040c068  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c069  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040c06c  3bc2                   +cmp eax, edx
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
    // 0040c06e  c74424048003d947       -mov dword ptr [esp + 4], 0x47d90380
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1205404544 /*0x47d90380*/;
    // 0040c076  7408                   -je 0x40c080
    if (cpu.flags.zf)
    {
        goto L_0x0040c080;
    }
    // 0040c078  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040c07b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c07c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c07d  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x0040c080:
    // 0040c080  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c081  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0040c084  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040c086  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040c088  7e6f                   -jle 0x40c0f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c0f9;
    }
    // 0040c08a  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c08c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c08d  8b3d30845100           -mov edi, dword ptr [0x518430]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
L_0x0040c093:
    // 0040c093  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040c095  745c                   -je 0x40c0f3
    if (cpu.flags.zf)
    {
        goto L_0x0040c0f3;
    }
    // 0040c097  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040c09a  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0040c09e  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 0040c0a1  d8a0d0000000           -fsub dword ptr [eax + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */));
    // 0040c0a7  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0040c0ab  d8a0d8000000           -fsub dword ptr [eax + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */));
    // 0040c0b1  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040c0b3  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040c0b5  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0040c0b7  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040c0b9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040c0bb  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0040c0bd  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c0bf  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c0c1  dd05d8744800           -fld qword ptr [0x4874d8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */)));
    // 0040c0c7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040c0c9  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0040c0cd  d88088020000           -fadd dword ptr [eax + 0x288]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(648) /* 0x288 */));
    // 0040c0d3  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040c0d5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c0d7  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040c0dc  7513                   -jne 0x40c0f1
    if (!cpu.flags.zf)
    {
        goto L_0x0040c0f1;
    }
    // 0040c0de  d854240c               -fcom dword ptr [esp + 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0040c0e2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c0e4  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040c0e7  7a08                   -jp 0x40c0f1
    if (cpu.flags.pf)
    {
        goto L_0x0040c0f1;
    }
    // 0040c0e9  d95c240c               +fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c0ed  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040c0ef  eb02                   -jmp 0x40c0f3
    goto L_0x0040c0f3;
L_0x0040c0f1:
    // 0040c0f1  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040c0f3:
    // 0040c0f3  42                     -inc edx
    (cpu.edx)++;
    // 0040c0f4  3bd6                   +cmp edx, esi
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
    // 0040c0f6  7c9b                   -jl 0x40c093
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040c093;
    }
    // 0040c0f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040c0f9:
    // 0040c0f9  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040c0fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c0fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c0fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c0fe  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40c110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c110  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040c113  83f918                 +cmp ecx, 0x18
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c116  7d26                   -jge 0x40c13e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c13e;
    }
    // 0040c118  83f9ff                 +cmp ecx, -1
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
    // 0040c11b  7e21                   -jle 0x40c13e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c13e;
    }
    // 0040c11d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040c121  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040c125  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c126  8b0c8d08bd4a00         -mov ecx, dword ptr [ecx*4 + 0x4abd08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.ecx * 4);
    // 0040c12d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040c12e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040c132  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c133  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040c137  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040c138  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c139  e822ffffff             -call 0x40c060
    cpu.esp -= 4;
    sub_40c060(app, cpu);
L_0x0040c13e:
    // 0040c13e  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40c150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c150  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c152  83f918                 +cmp ecx, 0x18
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c155  7d0f                   -jge 0x40c166
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c166;
    }
    // 0040c157  83f9ff                 +cmp ecx, -1
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
    // 0040c15a  7e0a                   -jle 0x40c166
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c166;
    }
    // 0040c15c  8b048d08bd4a00         -mov eax, dword ptr [ecx*4 + 0x4abd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.ecx * 4);
    // 0040c163  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x0040c166:
    // 0040c166  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40c170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c170  8b150cbd4a00           -mov edx, dword ptr [0x4abd0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898060) /* 0x4abd0c */);
    // 0040c176  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c17b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c17c  3b4208                 +cmp eax, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c17f  7f18                   -jg 0x40c199
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c199;
    }
    // 0040c181  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c183  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c185  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c186  8b3c86                 -mov edi, dword ptr [esi + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0040c189  3bf9                   +cmp edi, ecx
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
    // 0040c18b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c18c  750b                   -jne 0x40c199
    if (!cpu.flags.zf)
    {
        goto L_0x0040c199;
    }
    // 0040c18e  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040c191  8b1482                 -mov edx, dword ptr [edx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c194  e8f7090000             -call 0x40cb90
    cpu.esp -= 4;
    sub_40cb90(app, cpu);
L_0x0040c199:
    // 0040c199  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c19e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c19f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40c1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c1b0  8b150cbd4a00           -mov edx, dword ptr [0x4abd0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898060) /* 0x4abd0c */);
    // 0040c1b6  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c1bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c1bc  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0040c1bf  3bc6                   +cmp eax, esi
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
    // 0040c1c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c1c2  7f11                   -jg 0x40c1d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c1d5;
    }
    // 0040c1c4  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040c1c7  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c1ca  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c1cc  3bc2                   +cmp eax, edx
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
    // 0040c1ce  7505                   -jne 0x40c1d5
    if (!cpu.flags.zf)
    {
        goto L_0x0040c1d5;
    }
    // 0040c1d0  e8cb070000             -call 0x40c9a0
    cpu.esp -= 4;
    sub_40c9a0(app, cpu);
L_0x0040c1d5:
    // 0040c1d5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c1da  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40c1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c1e0  8b1510bd4a00           -mov edx, dword ptr [0x4abd10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898064) /* 0x4abd10 */);
    // 0040c1e6  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c1eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c1ec  3b4208                 +cmp eax, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c1ef  7f18                   -jg 0x40c209
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c209;
    }
    // 0040c1f1  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c1f3  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c1f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c1f6  8b3c86                 -mov edi, dword ptr [esi + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0040c1f9  3bf9                   +cmp edi, ecx
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
    // 0040c1fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c1fc  750b                   -jne 0x40c209
    if (!cpu.flags.zf)
    {
        goto L_0x0040c209;
    }
    // 0040c1fe  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040c201  8b1482                 -mov edx, dword ptr [edx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c204  e887090000             -call 0x40cb90
    cpu.esp -= 4;
    sub_40cb90(app, cpu);
L_0x0040c209:
    // 0040c209  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c20e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c20f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40c220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c220  8b1510bd4a00           -mov edx, dword ptr [0x4abd10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898064) /* 0x4abd10 */);
    // 0040c226  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c22b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c22c  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0040c22f  3bc6                   +cmp eax, esi
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
    // 0040c231  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c232  7f11                   -jg 0x40c245
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c245;
    }
    // 0040c234  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040c237  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c23a  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c23c  3bc2                   +cmp eax, edx
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
    // 0040c23e  7505                   -jne 0x40c245
    if (!cpu.flags.zf)
    {
        goto L_0x0040c245;
    }
    // 0040c240  e85b070000             -call 0x40c9a0
    cpu.esp -= 4;
    sub_40c9a0(app, cpu);
L_0x0040c245:
    // 0040c245  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c24a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40c250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c250  8b1514bd4a00           -mov edx, dword ptr [0x4abd14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898068) /* 0x4abd14 */);
    // 0040c256  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c25b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c25c  3b4208                 +cmp eax, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c25f  7f18                   -jg 0x40c279
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c279;
    }
    // 0040c261  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c263  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c265  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c266  8b3c86                 -mov edi, dword ptr [esi + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0040c269  3bf9                   +cmp edi, ecx
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
    // 0040c26b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c26c  750b                   -jne 0x40c279
    if (!cpu.flags.zf)
    {
        goto L_0x0040c279;
    }
    // 0040c26e  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040c271  8b1482                 -mov edx, dword ptr [edx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c274  e817090000             -call 0x40cb90
    cpu.esp -= 4;
    sub_40cb90(app, cpu);
L_0x0040c279:
    // 0040c279  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c27e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c27f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40c290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c290  8b1514bd4a00           -mov edx, dword ptr [0x4abd14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898068) /* 0x4abd14 */);
    // 0040c296  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c29b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c29c  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0040c29f  3bc6                   +cmp eax, esi
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
    // 0040c2a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c2a2  7f11                   -jg 0x40c2b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c2b5;
    }
    // 0040c2a4  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040c2a7  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c2aa  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c2ac  3bc2                   +cmp eax, edx
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
    // 0040c2ae  7505                   -jne 0x40c2b5
    if (!cpu.flags.zf)
    {
        goto L_0x0040c2b5;
    }
    // 0040c2b0  e8eb060000             -call 0x40c9a0
    cpu.esp -= 4;
    sub_40c9a0(app, cpu);
L_0x0040c2b5:
    // 0040c2b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c2ba  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40c2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c2c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c2c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c2c2  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040c2c4  e8b7390200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040c2c9  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040c2cb  83feff                 +cmp esi, -1
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
    // 0040c2ce  0f84a4020000           -je 0x40c578
    if (cpu.flags.zf)
    {
        goto L_0x0040c578;
    }
    // 0040c2d4  66a11abe4a00           -mov ax, word ptr [0x4abe1a]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(4898330) /* 0x4abe1a */);
    // 0040c2da  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040c2dc  0f8499020000           -je 0x40c57b
    if (cpu.flags.zf)
    {
        goto L_0x0040c57b;
    }
    // 0040c2e2  80fc01                 +cmp ah, 1
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040c2e5  0f8490020000           -je 0x40c57b
    if (cpu.flags.zf)
    {
        goto L_0x0040c57b;
    }
    // 0040c2eb  83fe01                 +cmp esi, 1
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
    // 0040c2ee  740e                   -je 0x40c2fe
    if (cpu.flags.zf)
    {
        goto L_0x0040c2fe;
    }
    // 0040c2f0  83fe02                 +cmp esi, 2
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
    // 0040c2f3  7409                   -je 0x40c2fe
    if (cpu.flags.zf)
    {
        goto L_0x0040c2fe;
    }
    // 0040c2f5  83fe03                 +cmp esi, 3
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
    // 0040c2f8  0f857d020000           -jne 0x40c57b
    if (!cpu.flags.zf)
    {
        goto L_0x0040c57b;
    }
L_0x0040c2fe:
    // 0040c2fe  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c303  8b0d34cd4800           -mov ecx, dword ptr [0x48cd34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c309  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c30a  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c30d  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040c313  83c902                 -or ecx, 2
    cpu.ecx |= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040c316  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040c31c  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c322  a134cd4800             -mov eax, dword ptr [0x48cd34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c327  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c32a  e8f1e10300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040c32f  8b0cb508bd4a00         -mov ecx, dword ptr [esi*4 + 0x4abd08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c336  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c33b  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c33d  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c340  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c345  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c348  8b0d34cd4800           -mov ecx, dword ptr [0x48cd34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c34e  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c351  8b8ad0000000           -mov ecx, dword ptr [edx + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0040c357  8988d0000000           -mov dword ptr [eax + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 0040c35d  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c364  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c36a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c36c  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c36f  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c374  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c377  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c37d  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c380  8b89d4000000           -mov ecx, dword ptr [ecx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0040c386  8988d4000000           -mov dword ptr [eax + 0xd4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */) = cpu.ecx;
    // 0040c38c  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c393  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c399  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c39b  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c39e  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c3a3  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c3a6  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c3ac  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c3af  8b89d8000000           -mov ecx, dword ptr [ecx + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0040c3b5  8988d8000000           -mov dword ptr [eax + 0xd8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(216) /* 0xd8 */) = cpu.ecx;
    // 0040c3bb  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c3c1  a134cd4800             -mov eax, dword ptr [0x48cd34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c3c6  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c3c9  d980d4000000           -fld dword ptr [eax + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */)));
    // 0040c3cf  d82518744800           -fsub dword ptr [0x487418]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748312) /* 0x487418 */));
    // 0040c3d5  d998d4000000           -fstp dword ptr [eax + 0xd4]
    app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c3db  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c3e0  8b0d34cd4800           -mov ecx, dword ptr [0x48cd34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c3e6  8b1d14be4a00           -mov ebx, dword ptr [0x4abe14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c3ec  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c3ef  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0040c3f5  891598be4a00           -mov dword ptr [0x4abe98], edx
    app->getMemory<x86::reg32>(x86::reg32(4898456) /* 0x4abe98 */) = cpu.edx;
    // 0040c3fb  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c402  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c404  8b149a                 -mov edx, dword ptr [edx + ebx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 0040c407  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c40a  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c40d  8b4a24                 -mov ecx, dword ptr [edx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0040c410  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0040c413  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c41a  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c420  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c422  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c425  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c42a  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c42d  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c433  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c436  8b4928                 -mov ecx, dword ptr [ecx + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0040c439  894828                 -mov dword ptr [eax + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 0040c43c  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c443  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c449  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c44b  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c44e  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c453  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c456  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c45c  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c45f  8b492c                 -mov ecx, dword ptr [ecx + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 0040c462  89482c                 -mov dword ptr [eax + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0040c465  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c46c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c46e  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c474  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c475  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c478  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c47d  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c480  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c486  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c489  8b494c                 -mov ecx, dword ptr [ecx + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0040c48c  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 0040c48f  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c496  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c49c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c49e  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c4a1  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c4a6  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c4a9  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c4af  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c4b2  8b4950                 -mov ecx, dword ptr [ecx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 0040c4b5  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 0040c4b8  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c4bf  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c4c5  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c4c7  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c4ca  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c4cf  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c4d2  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c4d8  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c4db  8b4954                 -mov ecx, dword ptr [ecx + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 0040c4de  894854                 -mov dword ptr [eax + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 0040c4e1  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c4e8  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c4ee  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c4f0  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c4f3  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c4f8  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c4fb  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c501  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c504  8b4974                 -mov ecx, dword ptr [ecx + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */);
    // 0040c507  894874                 -mov dword ptr [eax + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 0040c50a  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c511  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c517  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c519  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c51c  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c521  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c524  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c52a  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c52d  8b4978                 -mov ecx, dword ptr [ecx + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0040c530  894878                 -mov dword ptr [eax + 0x78], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */) = cpu.ecx;
    // 0040c533  8b14b508bd4a00         -mov edx, dword ptr [esi*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040c53a  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c540  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c542  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c545  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c54a  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c54d  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c553  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040c556  8b497c                 -mov ecx, dword ptr [ecx + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 0040c559  89487c                 -mov dword ptr [eax + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 0040c55c  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 0040c562  dc0d80754800           -fmul qword ptr [0x487580]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748672) /* 0x487580 */));
    // 0040c568  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0040c56a  dcc0                   -fadd st(0), st(0)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(0));
    // 0040c56c  d80598be4a00           -fadd dword ptr [0x4abe98]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4898456) /* 0x4abe98 */));
    // 0040c572  d99fd4000000           -fstp dword ptr [edi + 0xd4]
    app->getMemory<float>(cpu.edi + x86::reg32(212) /* 0xd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040c578:
    // 0040c578  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c579  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c57a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c57b:
    // 0040c57b  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c581  a134cd4800             -mov eax, dword ptr [0x48cd34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c586  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c587  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c588  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c58b  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040c591  83e1fd                 +and ecx, 0xfffffffd
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/))));
    // 0040c594  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040c59a  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c5a0  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c5a6  8b0c91                 -mov ecx, dword ptr [ecx + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040c5a9  e972df0300             -jmp 0x44a520
    return sub_44a520(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40c5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c5b0  e8cb360200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040c5b5  83f8ff                 +cmp eax, -1
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
    // 0040c5b8  0f847d010000           -je 0x40c73b
    if (cpu.flags.zf)
    {
        goto L_0x0040c73b;
    }
    // 0040c5be  83f801                 +cmp eax, 1
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
    // 0040c5c1  7431                   -je 0x40c5f4
    if (cpu.flags.zf)
    {
        goto L_0x0040c5f4;
    }
    // 0040c5c3  83f802                 +cmp eax, 2
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
    // 0040c5c6  742c                   -je 0x40c5f4
    if (cpu.flags.zf)
    {
        goto L_0x0040c5f4;
    }
    // 0040c5c8  83f803                 +cmp eax, 3
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
    // 0040c5cb  7427                   -je 0x40c5f4
    if (cpu.flags.zf)
    {
        goto L_0x0040c5f4;
    }
    // 0040c5cd  a134cd4800             -mov eax, dword ptr [0x48cd34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c5d2  83f8ff                 +cmp eax, -1
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
    // 0040c5d5  0f8460010000           -je 0x40c73b
    if (cpu.flags.zf)
    {
        goto L_0x0040c73b;
    }
    // 0040c5db  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c5e1  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040c5e4  e857240500             -call 0x45ea40
    cpu.esp -= 4;
    sub_45ea40(app, cpu);
    // 0040c5e9  c70534cd4800ffffffff   -mov dword ptr [0x48cd34], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */) = 4294967295 /*0xffffffff*/;
    // 0040c5f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c5f4:
    // 0040c5f4  833d34cd4800ff         +cmp dword ptr [0x48cd34], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c5fb  0f853a010000           -jne 0x40c73b
    if (!cpu.flags.zf)
    {
        goto L_0x0040c73b;
    }
    // 0040c601  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040c603  b944cd4800             -mov ecx, 0x48cd44
    cpu.ecx = 4771140 /*0x48cd44*/;
    // 0040c608  e8031e0500             -call 0x45e410
    cpu.esp -= 4;
    sub_45e410(app, cpu);
    // 0040c60d  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c613  a334cd4800             -mov dword ptr [0x48cd34], eax
    app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */) = cpu.eax;
    // 0040c618  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c61b  c7807c020000003c1c46   -mov dword ptr [eax + 0x27c], 0x461c3c00
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(636) /* 0x27c */) = 1176255488 /*0x461c3c00*/;
    // 0040c625  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c62b  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c631  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040c634  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040c63a  83e2fb                 -and edx, 0xfffffffb
    cpu.edx &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/));
    // 0040c63d  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040c643  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c648  8b0d34cd4800           -mov ecx, dword ptr [0x48cd34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c64e  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c651  e8cade0300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040c656  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c65c  a134cd4800             -mov eax, dword ptr [0x48cd34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c661  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c664  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040c66a  83e1f7                 -and ecx, 0xfffffff7
    cpu.ecx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
    // 0040c66d  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040c673  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c679  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c67f  8b0c91                 -mov ecx, dword ptr [ecx + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040c682  e899de0300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040c687  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c68c  8b0d34cd4800           -mov ecx, dword ptr [0x48cd34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c692  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c695  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040c69b  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040c69e  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040c6a4  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c6aa  a134cd4800             -mov eax, dword ptr [0x48cd34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c6af  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c6b2  e869de0300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040c6b7  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c6bd  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c6c3  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040c6c6  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040c6cc  83e1bf                 -and ecx, 0xffffffbf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/));
    // 0040c6cf  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0040c6d5  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c6da  8b0d34cd4800           -mov ecx, dword ptr [0x48cd34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c6e0  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040c6e3  e838de0300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040c6e8  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c6ee  a134cd4800             -mov eax, dword ptr [0x48cd34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c6f3  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040c6f6  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0040c6fc  80ce01                 -or dh, 1
    cpu.dh |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0040c6ff  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040c705  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c70b  8b1534cd4800           -mov edx, dword ptr [0x48cd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c711  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040c714  8b88f8020000           -mov ecx, dword ptr [eax + 0x2f8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(760) /* 0x2f8 */);
    // 0040c71a  83c904                 -or ecx, 4
    cpu.ecx |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040c71d  8988f8020000           -mov dword ptr [eax + 0x2f8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(760) /* 0x2f8 */) = cpu.ecx;
    // 0040c723  a134cd4800             -mov eax, dword ptr [0x48cd34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771124) /* 0x48cd34 */);
    // 0040c728  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040c72e  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040c731  c78210030000c0c24000   -mov dword ptr [edx + 0x310], 0x40c2c0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(784) /* 0x310 */) = 4244160 /*0x40c2c0*/;
L_0x0040c73b:
    // 0040c73b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40c740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c741  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c742  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c743  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c744  c644240f01             -mov byte ptr [esp + 0xf], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 0040c749  e8428dffff             -call 0x405490
    cpu.esp -= 4;
    sub_405490(app, cpu);
    // 0040c74e  e8fd8cffff             -call 0x405450
    cpu.esp -= 4;
    sub_405450(app, cpu);
    // 0040c753  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0040c758  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c75a  bf68bd4a00             -mov edi, 0x4abd68
    cpu.edi = 4898152 /*0x4abd68*/;
    // 0040c75f  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040c761  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040c763  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0040c768  c70584be4a0000000000   -mov dword ptr [0x4abe84], 0
    app->getMemory<x86::reg32>(x86::reg32(4898436) /* 0x4abe84 */) = 0 /*0x0*/;
    // 0040c772  c70588be4a0000000000   -mov dword ptr [0x4abe88], 0
    app->getMemory<x86::reg32>(x86::reg32(4898440) /* 0x4abe88 */) = 0 /*0x0*/;
    // 0040c77c  a3ecbd4a00             -mov dword ptr [0x4abdec], eax
    app->getMemory<x86::reg32>(x86::reg32(4898284) /* 0x4abdec */) = cpu.eax;
    // 0040c781  a3f0bd4a00             -mov dword ptr [0x4abdf0], eax
    app->getMemory<x86::reg32>(x86::reg32(4898288) /* 0x4abdf0 */) = cpu.eax;
    // 0040c786  a3f4bd4a00             -mov dword ptr [0x4abdf4], eax
    app->getMemory<x86::reg32>(x86::reg32(4898292) /* 0x4abdf4 */) = cpu.eax;
    // 0040c78b  a3f8bd4a00             -mov dword ptr [0x4abdf8], eax
    app->getMemory<x86::reg32>(x86::reg32(4898296) /* 0x4abdf8 */) = cpu.eax;
    // 0040c790  a3fcbd4a00             -mov dword ptr [0x4abdfc], eax
    app->getMemory<x86::reg32>(x86::reg32(4898300) /* 0x4abdfc */) = cpu.eax;
    // 0040c795  a300be4a00             -mov dword ptr [0x4abe00], eax
    app->getMemory<x86::reg32>(x86::reg32(4898304) /* 0x4abe00 */) = cpu.eax;
    // 0040c79a  891d04be4a00           -mov dword ptr [0x4abe04], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.ebx;
    // 0040c7a0  891d08be4a00           -mov dword ptr [0x4abe08], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898312) /* 0x4abe08 */) = cpu.ebx;
    // 0040c7a6  891d0cbe4a00           -mov dword ptr [0x4abe0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */) = cpu.ebx;
    // 0040c7ac  891d10be4a00           -mov dword ptr [0x4abe10], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */) = cpu.ebx;
    // 0040c7b2  891d14be4a00           -mov dword ptr [0x4abe14], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */) = cpu.ebx;
    // 0040c7b8  c60518be4a0001         -mov byte ptr [0x4abe18], 1
    app->getMemory<x86::reg8>(x86::reg32(4898328) /* 0x4abe18 */) = 1 /*0x1*/;
    // 0040c7bf  881d19be4a00           -mov byte ptr [0x4abe19], bl
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = cpu.bl;
    // 0040c7c5  881d1abe4a00           -mov byte ptr [0x4abe1a], bl
    app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */) = cpu.bl;
    // 0040c7cb  881d1bbe4a00           -mov byte ptr [0x4abe1b], bl
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = cpu.bl;
    // 0040c7d1  e80af8ffff             -call 0x40bfe0
    cpu.esp -= 4;
    sub_40bfe0(app, cpu);
    // 0040c7d6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040c7d8  7506                   -jne 0x40c7e0
    if (!cpu.flags.zf)
    {
        goto L_0x0040c7e0;
    }
    // 0040c7da  885c240f               -mov byte ptr [esp + 0xf], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(15) /* 0xf */) = cpu.bl;
    // 0040c7de  eb36                   -jmp 0x40c816
    goto L_0x0040c816;
L_0x0040c7e0:
    // 0040c7e0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0040c7e5  e866f9ffff             -call 0x40c150
    cpu.esp -= 4;
    sub_40c150(app, cpu);
    // 0040c7ea  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040c7ec  3bf3                   +cmp esi, ebx
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
    // 0040c7ee  7e26                   -jle 0x40c816
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c816;
    }
    // 0040c7f0  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 0040c7f7  e8a4000400             -call 0x44c8a0
    cpu.esp -= 4;
    sub_44c8a0(app, cpu);
    // 0040c7fc  a324be4a00             -mov dword ptr [0x4abe24], eax
    app->getMemory<x86::reg32>(x86::reg32(4898340) /* 0x4abe24 */) = cpu.eax;
    // 0040c801  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c803  3bf3                   +cmp esi, ebx
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
    // 0040c805  7e0f                   -jle 0x40c816
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c816;
    }
L_0x0040c807:
    // 0040c807  8b0d24be4a00           -mov ecx, dword ptr [0x4abe24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898340) /* 0x4abe24 */);
    // 0040c80d  40                     -inc eax
    (cpu.eax)++;
    // 0040c80e  3bc6                   +cmp eax, esi
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
    // 0040c810  895c81fc               -mov dword ptr [ecx + eax*4 - 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4) = cpu.ebx;
    // 0040c814  7cf1                   -jl 0x40c807
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040c807;
    }
L_0x0040c816:
    // 0040c816  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0040c81b  e8c0f7ffff             -call 0x40bfe0
    cpu.esp -= 4;
    sub_40bfe0(app, cpu);
    // 0040c820  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040c822  7506                   -jne 0x40c82a
    if (!cpu.flags.zf)
    {
        goto L_0x0040c82a;
    }
    // 0040c824  885c240f               -mov byte ptr [esp + 0xf], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(15) /* 0xf */) = cpu.bl;
    // 0040c828  eb36                   -jmp 0x40c860
    goto L_0x0040c860;
L_0x0040c82a:
    // 0040c82a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0040c82f  e81cf9ffff             -call 0x40c150
    cpu.esp -= 4;
    sub_40c150(app, cpu);
    // 0040c834  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040c836  3bf3                   +cmp esi, ebx
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
    // 0040c838  7e26                   -jle 0x40c860
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c860;
    }
    // 0040c83a  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 0040c841  e85a000400             -call 0x44c8a0
    cpu.esp -= 4;
    sub_44c8a0(app, cpu);
    // 0040c846  a328be4a00             -mov dword ptr [0x4abe28], eax
    app->getMemory<x86::reg32>(x86::reg32(4898344) /* 0x4abe28 */) = cpu.eax;
    // 0040c84b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c84d  3bf3                   +cmp esi, ebx
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
    // 0040c84f  7e0f                   -jle 0x40c860
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c860;
    }
L_0x0040c851:
    // 0040c851  8b1528be4a00           -mov edx, dword ptr [0x4abe28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898344) /* 0x4abe28 */);
    // 0040c857  40                     -inc eax
    (cpu.eax)++;
    // 0040c858  3bc6                   +cmp eax, esi
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
    // 0040c85a  895c82fc               -mov dword ptr [edx + eax*4 - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4) = cpu.ebx;
    // 0040c85e  7cf1                   -jl 0x40c851
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040c851;
    }
L_0x0040c860:
    // 0040c860  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0040c865  e876f7ffff             -call 0x40bfe0
    cpu.esp -= 4;
    sub_40bfe0(app, cpu);
    // 0040c86a  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040c86c  7505                   -jne 0x40c873
    if (!cpu.flags.zf)
    {
        goto L_0x0040c873;
    }
    // 0040c86e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c86f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c870  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c871  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c872  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c873:
    // 0040c873  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0040c878  e8d3f8ffff             -call 0x40c150
    cpu.esp -= 4;
    sub_40c150(app, cpu);
    // 0040c87d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040c87f  3bf3                   +cmp esi, ebx
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
    // 0040c881  7e26                   -jle 0x40c8a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c8a9;
    }
    // 0040c883  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 0040c88a  e811000400             -call 0x44c8a0
    cpu.esp -= 4;
    sub_44c8a0(app, cpu);
    // 0040c88f  a32cbe4a00             -mov dword ptr [0x4abe2c], eax
    app->getMemory<x86::reg32>(x86::reg32(4898348) /* 0x4abe2c */) = cpu.eax;
    // 0040c894  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c896  3bf3                   +cmp esi, ebx
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
    // 0040c898  7e0f                   -jle 0x40c8a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c8a9;
    }
L_0x0040c89a:
    // 0040c89a  8b0d2cbe4a00           -mov ecx, dword ptr [0x4abe2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898348) /* 0x4abe2c */);
    // 0040c8a0  40                     -inc eax
    (cpu.eax)++;
    // 0040c8a1  3bc6                   +cmp eax, esi
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
    // 0040c8a3  895c81fc               -mov dword ptr [ecx + eax*4 - 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4) = cpu.ebx;
    // 0040c8a7  7cf1                   -jl 0x40c89a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040c89a;
    }
L_0x0040c8a9:
    // 0040c8a9  8a44240f               -mov al, byte ptr [esp + 0xf]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(15) /* 0xf */);
    // 0040c8ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c8ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c8af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c8b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c8b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40c8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c8c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c8c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c8c2  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040c8c4  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0040c8c9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c8cb  bf68bd4a00             -mov edi, 0x4abd68
    cpu.edi = 4898152 /*0x4abd68*/;
    // 0040c8d0  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040c8d2  83faff                 +cmp edx, -1
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
    // 0040c8d5  c70584be4a0000000000   -mov dword ptr [0x4abe84], 0
    app->getMemory<x86::reg32>(x86::reg32(4898436) /* 0x4abe84 */) = 0 /*0x0*/;
    // 0040c8df  c70588be4a0000000000   -mov dword ptr [0x4abe88], 0
    app->getMemory<x86::reg32>(x86::reg32(4898440) /* 0x4abe88 */) = 0 /*0x0*/;
    // 0040c8e9  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040c8eb  a3ecbd4a00             -mov dword ptr [0x4abdec], eax
    app->getMemory<x86::reg32>(x86::reg32(4898284) /* 0x4abdec */) = cpu.eax;
    // 0040c8f0  a3f0bd4a00             -mov dword ptr [0x4abdf0], eax
    app->getMemory<x86::reg32>(x86::reg32(4898288) /* 0x4abdf0 */) = cpu.eax;
    // 0040c8f5  a3f4bd4a00             -mov dword ptr [0x4abdf4], eax
    app->getMemory<x86::reg32>(x86::reg32(4898292) /* 0x4abdf4 */) = cpu.eax;
    // 0040c8fa  a3f8bd4a00             -mov dword ptr [0x4abdf8], eax
    app->getMemory<x86::reg32>(x86::reg32(4898296) /* 0x4abdf8 */) = cpu.eax;
    // 0040c8ff  a3fcbd4a00             -mov dword ptr [0x4abdfc], eax
    app->getMemory<x86::reg32>(x86::reg32(4898300) /* 0x4abdfc */) = cpu.eax;
    // 0040c904  a300be4a00             -mov dword ptr [0x4abe00], eax
    app->getMemory<x86::reg32>(x86::reg32(4898304) /* 0x4abe00 */) = cpu.eax;
    // 0040c909  891d04be4a00           -mov dword ptr [0x4abe04], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.ebx;
    // 0040c90f  891d08be4a00           -mov dword ptr [0x4abe08], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898312) /* 0x4abe08 */) = cpu.ebx;
    // 0040c915  891d0cbe4a00           -mov dword ptr [0x4abe0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */) = cpu.ebx;
    // 0040c91b  891d10be4a00           -mov dword ptr [0x4abe10], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */) = cpu.ebx;
    // 0040c921  891d14be4a00           -mov dword ptr [0x4abe14], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */) = cpu.ebx;
    // 0040c927  c60518be4a0001         -mov byte ptr [0x4abe18], 1
    app->getMemory<x86::reg8>(x86::reg32(4898328) /* 0x4abe18 */) = 1 /*0x1*/;
    // 0040c92e  881d19be4a00           -mov byte ptr [0x4abe19], bl
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = cpu.bl;
    // 0040c934  881d1abe4a00           -mov byte ptr [0x4abe1a], bl
    app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */) = cpu.bl;
    // 0040c93a  881d1bbe4a00           -mov byte ptr [0x4abe1b], bl
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = cpu.bl;
    // 0040c940  7431                   -je 0x40c973
    if (cpu.flags.zf)
    {
        goto L_0x0040c973;
    }
    // 0040c942  8d0c9508bd4a00         -lea ecx, [edx*4 + 0x4abd08]
    cpu.ecx = x86::reg32(x86::reg32(4898056) /* 0x4abd08 */ + cpu.edx * 4);
    // 0040c949  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c94a  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c94c  395e08                 +cmp dword ptr [esi + 8], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c94f  7e15                   -jle 0x40c966
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c966;
    }
    // 0040c951  8d149520be4a00         -lea edx, [edx*4 + 0x4abe20]
    cpu.edx = x86::reg32(x86::reg32(4898336) /* 0x4abe20 */ + cpu.edx * 4);
L_0x0040c958:
    // 0040c958  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0040c95a  40                     -inc eax
    (cpu.eax)++;
    // 0040c95b  895c86fc               -mov dword ptr [esi + eax*4 - 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4) = cpu.ebx;
    // 0040c95f  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040c961  3b4608                 +cmp eax, dword ptr [esi + 8]
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
    // 0040c964  7cf2                   -jl 0x40c958
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040c958;
    }
L_0x0040c966:
    // 0040c966  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c967  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c968  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0040c96d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c96e  e96df6ffff             -jmp 0x40bfe0
    return sub_40bfe0(app, cpu);
L_0x0040c973:
    // 0040c973  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c974  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c975  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40c980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c980  e9abf6ffff             -jmp 0x40c030
    return sub_40c030(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40c990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c990  c60519be4a0000         -mov byte ptr [0x4abe19], 0
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = 0 /*0x0*/;
    // 0040c997  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40c9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c9a0  a01abe4a00             -mov al, byte ptr [0x4abe1a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
    // 0040c9a5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040c9a8  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040c9aa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c9ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c9ac  0f84cb010000           -je 0x40cb7d
    if (cpu.flags.zf)
    {
        goto L_0x0040cb7d;
    }
    // 0040c9b2  e8c9320200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040c9b7  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040c9b9  83feff                 +cmp esi, -1
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
    // 0040c9bc  0f84bb010000           -je 0x40cb7d
    if (cpu.flags.zf)
    {
        goto L_0x0040cb7d;
    }
    // 0040c9c2  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040c9c7  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040c9c9  3bc3                   +cmp eax, ebx
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
    // 0040c9cb  0f85dc000000           -jne 0x40caad
    if (!cpu.flags.zf)
    {
        goto L_0x0040caad;
    }
    // 0040c9d1  e8aa320200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040c9d6  83f801                 +cmp eax, 1
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
    // 0040c9d9  7507                   -jne 0x40c9e2
    if (!cpu.flags.zf)
    {
        goto L_0x0040c9e2;
    }
    // 0040c9db  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040c9dd  e8be360200             -call 0x4300a0
    cpu.esp -= 4;
    sub_4300a0(app, cpu);
L_0x0040c9e2:
    // 0040c9e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c9e3  e898320200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040c9e8  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040c9ea  e8d1feffff             -call 0x40c8c0
    cpu.esp -= 4;
    sub_40c8c0(app, cpu);
    // 0040c9ef  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0040c9f4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c9f6  bf68bd4a00             -mov edi, 0x4abd68
    cpu.edi = 4898152 /*0x4abd68*/;
    // 0040c9fb  c70584be4a0000000000   -mov dword ptr [0x4abe84], 0
    app->getMemory<x86::reg32>(x86::reg32(4898436) /* 0x4abe84 */) = 0 /*0x0*/;
    // 0040ca05  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040ca07  c70588be4a0000000000   -mov dword ptr [0x4abe88], 0
    app->getMemory<x86::reg32>(x86::reg32(4898440) /* 0x4abe88 */) = 0 /*0x0*/;
    // 0040ca11  a3ecbd4a00             -mov dword ptr [0x4abdec], eax
    app->getMemory<x86::reg32>(x86::reg32(4898284) /* 0x4abdec */) = cpu.eax;
    // 0040ca16  a3f0bd4a00             -mov dword ptr [0x4abdf0], eax
    app->getMemory<x86::reg32>(x86::reg32(4898288) /* 0x4abdf0 */) = cpu.eax;
    // 0040ca1b  a3f4bd4a00             -mov dword ptr [0x4abdf4], eax
    app->getMemory<x86::reg32>(x86::reg32(4898292) /* 0x4abdf4 */) = cpu.eax;
    // 0040ca20  a3f8bd4a00             -mov dword ptr [0x4abdf8], eax
    app->getMemory<x86::reg32>(x86::reg32(4898296) /* 0x4abdf8 */) = cpu.eax;
    // 0040ca25  a3fcbd4a00             -mov dword ptr [0x4abdfc], eax
    app->getMemory<x86::reg32>(x86::reg32(4898300) /* 0x4abdfc */) = cpu.eax;
    // 0040ca2a  a300be4a00             -mov dword ptr [0x4abe00], eax
    app->getMemory<x86::reg32>(x86::reg32(4898304) /* 0x4abe00 */) = cpu.eax;
    // 0040ca2f  891d04be4a00           -mov dword ptr [0x4abe04], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.ebx;
    // 0040ca35  891d08be4a00           -mov dword ptr [0x4abe08], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898312) /* 0x4abe08 */) = cpu.ebx;
    // 0040ca3b  891d0cbe4a00           -mov dword ptr [0x4abe0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */) = cpu.ebx;
    // 0040ca41  891d10be4a00           -mov dword ptr [0x4abe10], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */) = cpu.ebx;
    // 0040ca47  891d14be4a00           -mov dword ptr [0x4abe14], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */) = cpu.ebx;
    // 0040ca4d  c60518be4a0001         -mov byte ptr [0x4abe18], 1
    app->getMemory<x86::reg8>(x86::reg32(4898328) /* 0x4abe18 */) = 1 /*0x1*/;
    // 0040ca54  881d19be4a00           -mov byte ptr [0x4abe19], bl
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = cpu.bl;
    // 0040ca5a  881d1abe4a00           -mov byte ptr [0x4abe1a], bl
    app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */) = cpu.bl;
    // 0040ca60  881d1bbe4a00           -mov byte ptr [0x4abe1b], bl
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = cpu.bl;
    // 0040ca66  e8c58c0500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040ca6b  dd1decbd4a00           -fstp qword ptr [0x4abdec]
    app->getMemory<double>(x86::reg32(4898284) /* 0x4abdec */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040ca71  e86a0d0000             -call 0x40d7e0
    cpu.esp -= 4;
    sub_40d7e0(app, cpu);
    // 0040ca76  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040ca7b  881d19be4a00           -mov byte ptr [0x4abe19], bl
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = cpu.bl;
    // 0040ca81  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040ca82  68cdcc4c3e             -push 0x3e4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1045220557 /*0x3e4ccccd*/;
    cpu.esp -= 4;
    // 0040ca87  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040ca89  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ca8e  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0040ca93  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0040ca99  b950cd4800             -mov ecx, 0x48cd50
    cpu.ecx = 4771152 /*0x48cd50*/;
    // 0040ca9e  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040caa1  e8ea6d0500             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0040caa6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040caa7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040caa8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040caa9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040caac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040caad:
    // 0040caad  8b0cb508bd4a00         -mov ecx, dword ptr [esi*4 + 0x4abd08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040cab4  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0040cab7  4a                     -dec edx
    (cpu.edx)--;
    // 0040cab8  3bc2                   +cmp eax, edx
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
    // 0040caba  751b                   -jne 0x40cad7
    if (!cpu.flags.zf)
    {
        goto L_0x0040cad7;
    }
    // 0040cabc  381d1abe4a00           +cmp byte ptr [0x4abe1a], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040cac2  0f85b5000000           -jne 0x40cb7d
    if (!cpu.flags.zf)
    {
        goto L_0x0040cb7d;
    }
    // 0040cac8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cac9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040caca  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0040cacf  83c408                 +add esp, 8
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
    // 0040cad2  e9390e0000             -jmp 0x40d910
    return sub_40d910(app, cpu);
L_0x0040cad7:
    // 0040cad7  381d19be4a00           +cmp byte ptr [0x4abe19], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040cadd  0f849a000000           -je 0x40cb7d
    if (cpu.flags.zf)
    {
        goto L_0x0040cb7d;
    }
    // 0040cae3  d90590be4a00           -fld dword ptr [0x4abe90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4898448) /* 0x4abe90 */)));
    // 0040cae9  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0040caef  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040caf3  e8388c0500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040caf8  dc5c2408               -fcomp qword ptr [esp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 0040cafc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040cafe  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040cb03  750c                   -jne 0x40cb11
    if (!cpu.flags.zf)
    {
        goto L_0x0040cb11;
    }
    // 0040cb05  881d19be4a00           -mov byte ptr [0x4abe19], bl
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = cpu.bl;
    // 0040cb0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb0d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040cb10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040cb11:
    // 0040cb11  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040cb16  48                     -dec eax
    (cpu.eax)--;
    // 0040cb17  83fe01                 +cmp esi, 1
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
    // 0040cb1a  740a                   -je 0x40cb26
    if (cpu.flags.zf)
    {
        goto L_0x0040cb26;
    }
    // 0040cb1c  83fe02                 +cmp esi, 2
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
    // 0040cb1f  7405                   -je 0x40cb26
    if (cpu.flags.zf)
    {
        goto L_0x0040cb26;
    }
    // 0040cb21  83fe03                 +cmp esi, 3
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
    // 0040cb24  7557                   -jne 0x40cb7d
    if (!cpu.flags.zf)
    {
        goto L_0x0040cb7d;
    }
L_0x0040cb26:
    // 0040cb26  391d10be4a00           +cmp dword ptr [0x4abe10], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040cb2c  7e1a                   -jle 0x40cb48
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040cb48;
    }
    // 0040cb2e  3bc3                   +cmp eax, ebx
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
    // 0040cb30  891d10be4a00           -mov dword ptr [0x4abe10], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */) = cpu.ebx;
    // 0040cb36  7c45                   -jl 0x40cb7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040cb7d;
    }
    // 0040cb38  8b0cb520be4a00         -mov ecx, dword ptr [esi*4 + 0x4abe20]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898336) /* 0x4abe20 */ + cpu.esi * 4);
    // 0040cb3f  c70481feffffff         -mov dword ptr [ecx + eax*4], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 4294967294 /*0xfffffffe*/;
    // 0040cb46  eb12                   -jmp 0x40cb5a
    goto L_0x0040cb5a;
L_0x0040cb48:
    // 0040cb48  3bc3                   +cmp eax, ebx
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
    // 0040cb4a  7c31                   -jl 0x40cb7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040cb7d;
    }
    // 0040cb4c  8b14b520be4a00         -mov edx, dword ptr [esi*4 + 0x4abe20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898336) /* 0x4abe20 */ + cpu.esi * 4);
    // 0040cb53  c7048201000000         -mov dword ptr [edx + eax*4], 1
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 1 /*0x1*/;
L_0x0040cb5a:
    // 0040cb5a  e8810c0000             -call 0x40d7e0
    cpu.esp -= 4;
    sub_40d7e0(app, cpu);
    // 0040cb5f  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 0040cb65  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040cb66  dc0530744800           -fadd qword ptr [0x487430]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748336) /* 0x487430 */));
    // 0040cb6c  e81fa20600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040cb71  ba90c94000             -mov edx, 0x40c990
    cpu.edx = 4245904 /*0x40c990*/;
    // 0040cb76  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040cb78  e8a3410400             -call 0x450d20
    cpu.esp -= 4;
    sub_450d20(app, cpu);
L_0x0040cb7d:
    // 0040cb7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb7f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040cb82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40cb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cb90  8a0d1abe4a00           -mov cl, byte ptr [0x4abe1a]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
    // 0040cb96  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0040cb98  3ac8                   +cmp cl, al
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040cb9a  7410                   -je 0x40cbac
    if (cpu.flags.zf)
    {
        goto L_0x0040cbac;
    }
    // 0040cb9c  a219be4a00             -mov byte ptr [0x4abe19], al
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = cpu.al;
    // 0040cba1  e88a8b0500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040cba6  d91d90be4a00           -fstp dword ptr [0x4abe90]
    app->getMemory<float>(x86::reg32(4898448) /* 0x4abe90 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040cbac:
    // 0040cbac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40cbb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cbb0  a01abe4a00             -mov al, byte ptr [0x4abe1a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
    // 0040cbb5  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040cbb8  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040cbba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040cbbb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040cbbc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040cbbd  0f84b3010000           -je 0x40cd76
    if (cpu.flags.zf)
    {
        goto L_0x0040cd76;
    }
    // 0040cbc3  e8b8300200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040cbc8  83f8ff                 +cmp eax, -1
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
    // 0040cbcb  0f84a5010000           -je 0x40cd76
    if (cpu.flags.zf)
    {
        goto L_0x0040cd76;
    }
    // 0040cbd1  83f801                 +cmp eax, 1
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
    // 0040cbd4  740e                   -je 0x40cbe4
    if (cpu.flags.zf)
    {
        goto L_0x0040cbe4;
    }
    // 0040cbd6  83f802                 +cmp eax, 2
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
    // 0040cbd9  7409                   -je 0x40cbe4
    if (cpu.flags.zf)
    {
        goto L_0x0040cbe4;
    }
    // 0040cbdb  83f803                 +cmp eax, 3
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
    // 0040cbde  0f8592010000           -jne 0x40cd76
    if (!cpu.flags.zf)
    {
        goto L_0x0040cd76;
    }
L_0x0040cbe4:
    // 0040cbe4  8b1d4c845100           -mov ebx, dword ptr [0x51844c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040cbea  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040cbec  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0040cbf2  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040cbf8  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040cbfb  8bb2e8020000           -mov esi, dword ptr [edx + 0x2e8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(744) /* 0x2e8 */);
    // 0040cc01  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040cc03  0f846d010000           -je 0x40cd76
    if (cpu.flags.zf)
    {
        goto L_0x0040cd76;
    }
    // 0040cc09  8b148508bd4a00         -mov edx, dword ptr [eax*4 + 0x4abd08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.eax * 4);
    // 0040cc10  8b3d14be4a00           -mov edi, dword ptr [0x4abe14]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040cc16  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040cc18  8b04b8                 -mov eax, dword ptr [eax + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0040cc1b  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040cc1e  d980d0000000           -fld dword ptr [eax + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    // 0040cc24  d8a6d0000000           -fsub dword ptr [esi + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */));
    // 0040cc2a  d980d8000000           -fld dword ptr [eax + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */)));
    // 0040cc30  d8a6d8000000           -fsub dword ptr [esi + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(216) /* 0xd8 */));
    // 0040cc36  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040cc38  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040cc3a  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0040cc3c  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040cc3e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040cc40  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040cc42  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040cc44  d81598754800           -fcom dword ptr [0x487598]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748696) /* 0x487598 */)));
    // 0040cc4a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040cc4c  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040cc51  0f841d010000           -je 0x40cd74
    if (cpu.flags.zf)
    {
        goto L_0x0040cd74;
    }
    // 0040cc57  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040cc5a  8b04b8                 -mov eax, dword ptr [eax + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0040cc5d  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040cc60  d980d0000000           -fld dword ptr [eax + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    // 0040cc66  d8a6d0000000           -fsub dword ptr [esi + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */));
    // 0040cc6c  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040cc70  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040cc72  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040cc75  8bb680000000           -mov esi, dword ptr [esi + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0040cc7b  8b04b8                 -mov eax, dword ptr [eax + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0040cc7e  8b34b1                 -mov esi, dword ptr [ecx + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0040cc81  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040cc84  8bb6e8020000           -mov esi, dword ptr [esi + 0x2e8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 0040cc8a  d980d4000000           -fld dword ptr [eax + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */)));
    // 0040cc90  d8a6d4000000           -fsub dword ptr [esi + 0xd4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */));
    // 0040cc96  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040cc9a  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040cc9d  8b04ba                 -mov eax, dword ptr [edx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 0040cca0  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040cca3  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040cca5  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040ccab  d982d8000000           -fld dword ptr [edx + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(216) /* 0xd8 */)));
    // 0040ccb1  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040ccb4  8b81e8020000           -mov eax, dword ptr [ecx + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 0040ccba  d8a0d8000000           -fsub dword ptr [eax + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */));
    // 0040ccc0  d9542418               -fst dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    // 0040ccc4  d84c2418               -fmul dword ptr [esp + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 0040ccc8  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0040cccc  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0040ccd0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040ccd2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040ccd4  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040ccd6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ccd8  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040ccdd  0f8493000000           -je 0x40cd76
    if (cpu.flags.zf)
    {
        goto L_0x0040cd76;
    }
    // 0040cce3  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040cce5  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040cce9  e862fd0300             -call 0x44ca50
    cpu.esp -= 4;
    sub_44ca50(app, cpu);
    // 0040ccee  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040ccf4  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0040ccf8  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040ccfa  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040cd00  8b8280000000           -mov eax, dword ptr [edx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040cd06  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040cd09  8b8ae8020000           -mov ecx, dword ptr [edx + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(744) /* 0x2e8 */);
    // 0040cd0f  d8497c                 -fmul dword ptr [ecx + 0x7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(124) /* 0x7c */));
    // 0040cd12  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0040cd16  d84978                 -fmul dword ptr [ecx + 0x78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(120) /* 0x78 */));
    // 0040cd19  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040cd1b  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0040cd1f  d84974                 -fmul dword ptr [ecx + 0x74]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(116) /* 0x74 */));
    // 0040cd22  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040cd24  dc1590754800           -fcom qword ptr [0x487590]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748688) /* 0x487590 */)));
    // 0040cd2a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040cd2c  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040cd31  7541                   -jne 0x40cd74
    if (!cpu.flags.zf)
    {
        goto L_0x0040cd74;
    }
    // 0040cd33  dc1d88754800           -fcomp qword ptr [0x487588]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748680) /* 0x487588 */)));
    cpu.fpu.pop();
    // 0040cd39  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040cd3b  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040cd3e  7a36                   -jp 0x40cd76
    if (cpu.flags.pf)
    {
        goto L_0x0040cd76;
    }
    // 0040cd40  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0040cd44  d8492c                 -fmul dword ptr [ecx + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */));
    // 0040cd47  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0040cd4b  d84928                 -fmul dword ptr [ecx + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(40) /* 0x28 */));
    // 0040cd4e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040cd50  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0040cd54  d84924                 -fmul dword ptr [ecx + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */));
    // 0040cd57  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040cd59  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0040cd5f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040cd61  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040cd66  750e                   -jne 0x40cd76
    if (!cpu.flags.zf)
    {
        goto L_0x0040cd76;
    }
    // 0040cd68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd6a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040cd6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd70  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040cd73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040cd74:
    // 0040cd74  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040cd76:
    // 0040cd76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd78  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040cd7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd7b  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040cd7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40cd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cd80  803d1bbe4a0001         +cmp byte ptr [0x4abe1b], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040cd87  7507                   -jne 0x40cd90
    if (!cpu.flags.zf)
    {
        goto L_0x0040cd90;
    }
    // 0040cd89  dd0570744800           -fld qword ptr [0x487470]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    // 0040cd8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040cd90:
    // 0040cd90  dd05fcbd4a00           -fld qword ptr [0x4abdfc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4898300) /* 0x4abdfc */)));
    // 0040cd96  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0040cd9c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040cd9e  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040cda3  7507                   -jne 0x40cdac
    if (!cpu.flags.zf)
    {
        goto L_0x0040cdac;
    }
    // 0040cda5  dd05fcbd4a00           -fld qword ptr [0x4abdfc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4898300) /* 0x4abdfc */)));
    // 0040cdab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040cdac:
    // 0040cdac  dd05f4bd4a00           -fld qword ptr [0x4abdf4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4898292) /* 0x4abdf4 */)));
    // 0040cdb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40cdc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cdc0  803d1bbe4a0001         +cmp byte ptr [0x4abe1b], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040cdc7  7410                   -je 0x40cdd9
    if (cpu.flags.zf)
    {
        goto L_0x0040cdd9;
    }
    // 0040cdc9  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0040cdcd  dc05ecbd4a00           -fadd qword ptr [0x4abdec]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4898284) /* 0x4abdec */));
    // 0040cdd3  dd1decbd4a00           -fstp qword ptr [0x4abdec]
    app->getMemory<double>(x86::reg32(4898284) /* 0x4abdec */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040cdd9:
    // 0040cdd9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40cde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cde0  803d1bbe4a0001         +cmp byte ptr [0x4abe1b], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040cde7  7507                   -jne 0x40cdf0
    if (!cpu.flags.zf)
    {
        goto L_0x0040cdf0;
    }
    // 0040cde9  dd0570744800           -fld qword ptr [0x487470]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    // 0040cdef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040cdf0:
    // 0040cdf0  dd05fcbd4a00           -fld qword ptr [0x4abdfc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4898300) /* 0x4abdfc */)));
    // 0040cdf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40ce00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ce00  a104be4a00             -mov eax, dword ptr [0x4abe04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */);
    // 0040ce05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40ce10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ce10  a10cbe4a00             -mov eax, dword ptr [0x4abe0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */);
    // 0040ce15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40ce20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ce20  dd05ecbd4a00           -fld qword ptr [0x4abdec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4898284) /* 0x4abdec */)));
    // 0040ce26  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0040ce2c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ce2e  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040ce33  7516                   -jne 0x40ce4b
    if (!cpu.flags.zf)
    {
        goto L_0x0040ce4b;
    }
    // 0040ce35  dd05fcbd4a00           -fld qword ptr [0x4abdfc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4898300) /* 0x4abdfc */)));
    // 0040ce3b  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0040ce41  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ce43  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0040ce46  7a03                   -jp 0x40ce4b
    if (cpu.flags.pf)
    {
        goto L_0x0040ce4b;
    }
    // 0040ce48  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0040ce4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ce4b:
    // 0040ce4b  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0040ce4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40ce50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ce50  d90584be4a00           -fld dword ptr [0x4abe84]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4898436) /* 0x4abe84 */)));
    // 0040ce56  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0040ce5c  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0040ce5f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ce60  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ce62  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0040ce65  7a0b                   -jp 0x40ce72
    if (cpu.flags.pf)
    {
        goto L_0x0040ce72;
    }
    // 0040ce67  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0040ce6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ce6e  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0040ce71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ce72:
    // 0040ce72  e8092e0200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040ce77  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040ce79  83feff                 +cmp esi, -1
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
    // 0040ce7c  750b                   -jne 0x40ce89
    if (!cpu.flags.zf)
    {
        goto L_0x0040ce89;
    }
    // 0040ce7e  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0040ce84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ce85  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0040ce88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ce89:
    // 0040ce89  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040ce8a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040ce8c  e8bff2ffff             -call 0x40c150
    cpu.esp -= 4;
    sub_40c150(app, cpu);
    // 0040ce91  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0040ce93  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040ce98  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0040ce9c  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040ce9e  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0040cea4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040ceaa  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040cead  8b92d0000000           -mov edx, dword ptr [edx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0040ceb3  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0040ceb7  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040ceb9  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040cebf  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040cec2  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0040cec8  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0040cecc  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040cece  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040ced4  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040ced7  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0040cedd  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0040cee1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040cee3  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040cee7  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040ceed  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040cef0  e8bb1d0500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040cef5  8b04b508bd4a00         -mov eax, dword ptr [esi*4 + 0x4abd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040cefc  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040cf02  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040cf04  8b348a                 -mov esi, dword ptr [edx + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040cf07  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040cf0d  8b34b2                 -mov esi, dword ptr [edx + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040cf10  d986d0000000           -fld dword ptr [esi + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */)));
    // 0040cf16  d8642410               -fsub dword ptr [esp + 0x10]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0040cf1a  d95c2438               -fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040cf1e  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0040cf20  8b348e                 -mov esi, dword ptr [esi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4);
    // 0040cf23  8b34b2                 -mov esi, dword ptr [edx + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040cf26  d986d4000000           -fld dword ptr [esi + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */)));
    // 0040cf2c  d8642414               -fsub dword ptr [esp + 0x14]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0040cf30  d95c243c               -fstp dword ptr [esp + 0x3c]
    app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040cf34  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040cf36  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040cf39  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040cf3c  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040cf40  d982d8000000           -fld dword ptr [edx + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(216) /* 0xd8 */)));
    // 0040cf46  d8642418               -fsub dword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 0040cf4a  d95c2440               -fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040cf4e  e83dfd0300             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 0040cf53  d82d84be4a00           -fsubr dword ptr [0x4abe84]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(4898436) /* 0x4abe84 */)) - cpu.fpu.st(0);
    // 0040cf59  d81588be4a00           -fcom dword ptr [0x4abe88]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4898440) /* 0x4abe88 */)));
    // 0040cf5f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040cf61  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040cf66  7508                   -jne 0x40cf70
    if (!cpu.flags.zf)
    {
        goto L_0x0040cf70;
    }
    // 0040cf68  d91d88be4a00           +fstp dword ptr [0x4abe88]
    app->getMemory<float>(x86::reg32(4898440) /* 0x4abe88 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040cf6e  eb02                   -jmp 0x40cf72
    goto L_0x0040cf72;
L_0x0040cf70:
    // 0040cf70  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040cf72:
    // 0040cf72  db0514be4a00           -fild dword ptr [0x4abe14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */))));
    // 0040cf78  4f                     -dec edi
    (cpu.edi)--;
    // 0040cf79  d82594744800           -fsub dword ptr [0x487494]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0040cf7f  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0040cf83  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0040cf87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cf88  d82594744800           -fsub dword ptr [0x487494]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0040cf8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cf8f  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040cf91  d90588be4a00           -fld dword ptr [0x4abe88]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4898440) /* 0x4abe88 */)));
    // 0040cf97  d83584be4a00           -fdiv dword ptr [0x4abe84]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(x86::reg32(4898436) /* 0x4abe84 */));
    // 0040cf9d  da742400               -fidiv dword ptr [esp]
    cpu.fpu.st(0) /= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0040cfa1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040cfa3  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0040cfa6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40cfb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cfb0  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 0040cfb5  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040cfb8  83f84a                 +cmp eax, 0x4a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(74 /*0x4a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040cfbb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040cfbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040cfbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040cfbe  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040cfc0  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 0040cfc5  befdffffff             -mov esi, 0xfffffffd
    cpu.esi = 4294967293 /*0xfffffffd*/;
    // 0040cfca  756b                   -jne 0x40d037
    if (!cpu.flags.zf)
    {
        goto L_0x0040d037;
    }
    // 0040cfcc  393d14be4a00           +cmp dword ptr [0x4abe14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040cfd2  0f8ecf000000           -jle 0x40d0a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d0a7;
    }
    // 0040cfd8  b980cd4800             -mov ecx, 0x48cd80
    cpu.ecx = 4771200 /*0x48cd80*/;
    // 0040cfdd  e8ae590200             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 0040cfe2  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040cfe8  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040cfeb  8b91a8020000           -mov edx, dword ptr [ecx + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0040cff1  23d6                   -and edx, esi
    cpu.edx &= x86::reg32(x86::sreg32(cpu.esi));
    // 0040cff3  8991a8020000           -mov dword ptr [ecx + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040cff9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040cfff  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040d002  e819d50300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040d007  b978cd4800             -mov ecx, 0x48cd78
    cpu.ecx = 4771192 /*0x48cd78*/;
    // 0040d00c  e87f590200             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 0040d011  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d017  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040d01a  8b91a8020000           -mov edx, dword ptr [ecx + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0040d020  83ca02                 -or edx, 2
    cpu.edx |= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040d023  8991a8020000           -mov dword ptr [ecx + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040d029  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d02f  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040d032  e8e9d40300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
L_0x0040d037:
    // 0040d037  833ddc2849004d         +cmp dword ptr [0x4928dc], 0x4d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(77 /*0x4d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d03e  7567                   -jne 0x40d0a7
    if (!cpu.flags.zf)
    {
        goto L_0x0040d0a7;
    }
    // 0040d040  393d14be4a00           +cmp dword ptr [0x4abe14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d046  7e5f                   -jle 0x40d0a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d0a7;
    }
    // 0040d048  b970cd4800             -mov ecx, 0x48cd70
    cpu.ecx = 4771184 /*0x48cd70*/;
    // 0040d04d  e83e590200             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 0040d052  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d058  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040d05b  8bb9a8020000           -mov edi, dword ptr [ecx + 0x2a8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0040d061  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 0040d063  89b9a8020000           -mov dword ptr [ecx + 0x2a8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.edi;
    // 0040d069  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d06f  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040d072  e8a9d40300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0040d077  b968cd4800             -mov ecx, 0x48cd68
    cpu.ecx = 4771176 /*0x48cd68*/;
    // 0040d07c  e80f590200             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 0040d081  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d087  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040d08a  8b91a8020000           -mov edx, dword ptr [ecx + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0040d090  83ca02                 -or edx, 2
    cpu.edx |= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040d093  8991a8020000           -mov dword ptr [ecx + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0040d099  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d09f  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0040d0a2  e879d40300             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
L_0x0040d0a7:
    // 0040d0a7  e8d42b0200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040d0ac  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040d0ae  83feff                 +cmp esi, -1
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
    // 0040d0b1  7509                   -jne 0x40d0bc
    if (!cpu.flags.zf)
    {
        goto L_0x0040d0bc;
    }
    // 0040d0b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d0b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d0b5  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0040d0b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d0b8  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040d0bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040d0bc:
    // 0040d0bc  e8eff4ffff             -call 0x40c5b0
    cpu.esp -= 4;
    sub_40c5b0(app, cpu);
    // 0040d0c1  3b3538cd4800           +cmp esi, dword ptr [0x48cd38]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4771128) /* 0x48cd38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d0c7  7475                   -je 0x40d13e
    if (cpu.flags.zf)
    {
        goto L_0x0040d13e;
    }
    // 0040d0c9  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0040d0ce  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d0d0  bf68bd4a00             -mov edi, 0x4abd68
    cpu.edi = 4898152 /*0x4abd68*/;
    // 0040d0d5  c70584be4a0000000000   -mov dword ptr [0x4abe84], 0
    app->getMemory<x86::reg32>(x86::reg32(4898436) /* 0x4abe84 */) = 0 /*0x0*/;
    // 0040d0df  c70588be4a0000000000   -mov dword ptr [0x4abe88], 0
    app->getMemory<x86::reg32>(x86::reg32(4898440) /* 0x4abe88 */) = 0 /*0x0*/;
    // 0040d0e9  a3ecbd4a00             -mov dword ptr [0x4abdec], eax
    app->getMemory<x86::reg32>(x86::reg32(4898284) /* 0x4abdec */) = cpu.eax;
    // 0040d0ee  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040d0f0  a3f0bd4a00             -mov dword ptr [0x4abdf0], eax
    app->getMemory<x86::reg32>(x86::reg32(4898288) /* 0x4abdf0 */) = cpu.eax;
    // 0040d0f5  a3f4bd4a00             -mov dword ptr [0x4abdf4], eax
    app->getMemory<x86::reg32>(x86::reg32(4898292) /* 0x4abdf4 */) = cpu.eax;
    // 0040d0fa  a3f8bd4a00             -mov dword ptr [0x4abdf8], eax
    app->getMemory<x86::reg32>(x86::reg32(4898296) /* 0x4abdf8 */) = cpu.eax;
    // 0040d0ff  a3fcbd4a00             -mov dword ptr [0x4abdfc], eax
    app->getMemory<x86::reg32>(x86::reg32(4898300) /* 0x4abdfc */) = cpu.eax;
    // 0040d104  a300be4a00             -mov dword ptr [0x4abe00], eax
    app->getMemory<x86::reg32>(x86::reg32(4898304) /* 0x4abe00 */) = cpu.eax;
    // 0040d109  a304be4a00             -mov dword ptr [0x4abe04], eax
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.eax;
    // 0040d10e  a308be4a00             -mov dword ptr [0x4abe08], eax
    app->getMemory<x86::reg32>(x86::reg32(4898312) /* 0x4abe08 */) = cpu.eax;
    // 0040d113  a30cbe4a00             -mov dword ptr [0x4abe0c], eax
    app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */) = cpu.eax;
    // 0040d118  a310be4a00             -mov dword ptr [0x4abe10], eax
    app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */) = cpu.eax;
    // 0040d11d  a314be4a00             -mov dword ptr [0x4abe14], eax
    app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */) = cpu.eax;
    // 0040d122  c60518be4a0001         -mov byte ptr [0x4abe18], 1
    app->getMemory<x86::reg8>(x86::reg32(4898328) /* 0x4abe18 */) = 1 /*0x1*/;
    // 0040d129  a219be4a00             -mov byte ptr [0x4abe19], al
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = cpu.al;
    // 0040d12e  a21abe4a00             -mov byte ptr [0x4abe1a], al
    app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */) = cpu.al;
    // 0040d133  a21bbe4a00             -mov byte ptr [0x4abe1b], al
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = cpu.al;
    // 0040d138  893538cd4800           -mov dword ptr [0x48cd38], esi
    app->getMemory<x86::reg32>(x86::reg32(4771128) /* 0x48cd38 */) = cpu.esi;
L_0x0040d13e:
    // 0040d13e  83fe01                 +cmp esi, 1
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
    // 0040d141  7413                   -je 0x40d156
    if (cpu.flags.zf)
    {
        goto L_0x0040d156;
    }
    // 0040d143  83fe02                 +cmp esi, 2
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
    // 0040d146  740e                   -je 0x40d156
    if (cpu.flags.zf)
    {
        goto L_0x0040d156;
    }
    // 0040d148  83fe03                 +cmp esi, 3
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
    // 0040d14b  7409                   -je 0x40d156
    if (cpu.flags.zf)
    {
        goto L_0x0040d156;
    }
    // 0040d14d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d14e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d14f  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0040d151  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d152  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040d155  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040d156:
    // 0040d156  8b8bd4000000           -mov ecx, dword ptr [ebx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(212) /* 0xd4 */);
    // 0040d15c  8b93d8000000           -mov edx, dword ptr [ebx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(216) /* 0xd8 */);
    // 0040d162  8b83d0000000           -mov eax, dword ptr [ebx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(208) /* 0xd0 */);
    // 0040d168  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0040d16c  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0040d170  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040d174  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040d176  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0040d17a  e8311b0500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040d17f  8b8388020000           -mov eax, dword ptr [ebx + 0x288]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(648) /* 0x288 */);
    // 0040d185  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040d189  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040d18d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040d18e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040d192  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040d193  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040d194  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040d195  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040d197  e874efffff             -call 0x40c110
    cpu.esp -= 4;
    sub_40c110(app, cpu);
    // 0040d19c  dd05ecbd4a00           -fld qword ptr [0x4abdec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4898284) /* 0x4abdec */)));
    // 0040d1a2  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0040d1a8  a330cd4800             -mov dword ptr [0x48cd30], eax
    app->getMemory<x86::reg32>(x86::reg32(4771120) /* 0x48cd30 */) = cpu.eax;
    // 0040d1ad  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d1af  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040d1b4  754e                   -jne 0x40d204
    if (!cpu.flags.zf)
    {
        goto L_0x0040d204;
    }
    // 0040d1b6  e875850500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040d1bb  dc25ecbd4a00           -fsub qword ptr [0x4abdec]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4898284) /* 0x4abdec */));
    // 0040d1c1  dd1df4bd4a00           -fstp qword ptr [0x4abdf4]
    app->getMemory<double>(x86::reg32(4898292) /* 0x4abdf4 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d1c7  8b8bd0000000           -mov ecx, dword ptr [ebx + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(208) /* 0xd0 */);
    // 0040d1cd  8b93d4000000           -mov edx, dword ptr [ebx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(212) /* 0xd4 */);
    // 0040d1d3  8b83d8000000           -mov eax, dword ptr [ebx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(216) /* 0xd8 */);
    // 0040d1d9  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0040d1dd  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0040d1e1  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040d1e5  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040d1e7  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0040d1eb  e8c01a0500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040d1f0  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040d1f4  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040d1f8  890da0be4a00           -mov dword ptr [0x4abea0], ecx
    app->getMemory<x86::reg32>(x86::reg32(4898464) /* 0x4abea0 */) = cpu.ecx;
    // 0040d1fe  89159cbe4a00           -mov dword ptr [0x4abe9c], edx
    app->getMemory<x86::reg32>(x86::reg32(4898460) /* 0x4abe9c */) = cpu.edx;
L_0x0040d204:
    // 0040d204  a130cd4800             -mov eax, dword ptr [0x48cd30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771120) /* 0x48cd30 */);
    // 0040d209  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d20a  83f8ff                 +cmp eax, -1
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
    // 0040d20d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d20e  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0040d211  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d212  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040d215  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40d220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d220  a01abe4a00             -mov al, byte ptr [0x4abe1a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
    // 0040d225  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0040d228  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040d22a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d22b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040d22c  0f841d020000           -je 0x40d44f
    if (cpu.flags.zf)
    {
        goto L_0x0040d44f;
    }
    // 0040d232  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d237  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d239  0f8410020000           -je 0x40d44f
    if (cpu.flags.zf)
    {
        goto L_0x0040d44f;
    }
    // 0040d23f  e83c2a0200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040d244  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040d246  83fbff                 +cmp ebx, -1
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
    // 0040d249  0f8400020000           -je 0x40d44f
    if (cpu.flags.zf)
    {
        goto L_0x0040d44f;
    }
    // 0040d24f  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040d254  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d255  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040d256  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d258  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0040d25e  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d264  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d267  8b92d0000000           -mov edx, dword ptr [edx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0040d26d  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 0040d271  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d273  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040d279  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d27c  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0040d282  89542444               -mov dword ptr [esp + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0040d286  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d288  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040d28e  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d291  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0040d297  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 0040d29b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d29d  8d54243c               -lea edx, [esp + 0x3c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0040d2a1  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040d2a7  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040d2aa  e8011a0500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040d2af  8b049d08bd4a00         -mov eax, dword ptr [ebx*4 + 0x4abd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.ebx * 4);
    // 0040d2b6  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0040d2b9  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d2bc  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0040d2c0  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d2c6  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040d2c9  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d2cc  8b92d0000000           -mov edx, dword ptr [edx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0040d2d2  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0040d2d6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d2d9  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040d2dc  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d2df  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0040d2e5  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0040d2e9  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d2ec  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040d2ef  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d2f2  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0040d2f8  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0040d2fc  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d2ff  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040d303  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d306  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040d309  e8a2190500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040d30e  d9442440               -fld dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 0040d312  d8642418               -fsub dword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 0040d316  8d4c2464               -lea ecx, [esp + 0x64]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0040d31a  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d31e  d9442444               -fld dword ptr [esp + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 0040d322  d864241c               -fsub dword ptr [esp + 0x1c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */));
    // 0040d326  d95c246c               -fstp dword ptr [esp + 0x6c]
    app->getMemory<float>(cpu.esp + x86::reg32(108) /* 0x6c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d32a  d9442448               -fld dword ptr [esp + 0x48]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 0040d32e  d8642420               -fsub dword ptr [esp + 0x20]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 0040d332  d95c2470               -fstp dword ptr [esp + 0x70]
    app->getMemory<float>(cpu.esp + x86::reg32(112) /* 0x70 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d336  e855f90300             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 0040d33b  e8509a0600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040d340  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0040d342  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040d346  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0040d34b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0040d350  3bc6                   +cmp eax, esi
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
    // 0040d352  0f8e9f000000           -jle 0x40d3f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d3f7;
    }
L_0x0040d358:
    // 0040d358  8b049d08bd4a00         -mov eax, dword ptr [ebx*4 + 0x4abd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.ebx * 4);
    // 0040d35f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d362  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0040d365  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d36b  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d36e  8b92d0000000           -mov edx, dword ptr [edx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0040d374  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0040d378  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d37b  8b14b2                 -mov edx, dword ptr [edx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040d37e  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d381  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0040d387  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0040d38b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d38e  8b14b2                 -mov edx, dword ptr [edx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040d391  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d394  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0040d39a  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0040d39e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d3a1  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040d3a5  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0040d3a8  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040d3ab  e800190500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040d3b0  d9442440               -fld dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 0040d3b4  d8642418               -fsub dword ptr [esp + 0x18]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 0040d3b8  8d4c2464               -lea ecx, [esp + 0x64]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0040d3bc  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d3c0  d9442444               -fld dword ptr [esp + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 0040d3c4  d864241c               -fsub dword ptr [esp + 0x1c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */));
    // 0040d3c8  d95c246c               -fstp dword ptr [esp + 0x6c]
    app->getMemory<float>(cpu.esp + x86::reg32(108) /* 0x6c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d3cc  d9442448               -fld dword ptr [esp + 0x48]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 0040d3d0  d8642420               -fsub dword ptr [esp + 0x20]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 0040d3d4  d95c2470               -fstp dword ptr [esp + 0x70]
    app->getMemory<float>(cpu.esp + x86::reg32(112) /* 0x70 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d3d8  e8b3f80300             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 0040d3dd  e8ae990600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040d3e2  3bf8                   +cmp edi, eax
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
    // 0040d3e4  7e04                   -jle 0x40d3ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d3ea;
    }
    // 0040d3e6  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0040d3e8  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x0040d3ea:
    // 0040d3ea  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040d3ee  46                     -inc esi
    (cpu.esi)++;
    // 0040d3ef  3bf0                   +cmp esi, eax
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
    // 0040d3f1  0f8c61ffffff           -jl 0x40d358
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d358;
    }
L_0x0040d3f7:
    // 0040d3f7  8a8568bd4a00           -mov al, byte ptr [ebp + 0x4abd68]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(4898152) /* 0x4abd68 */);
    // 0040d3fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3fe  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040d400  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d401  744c                   -je 0x40d44f
    if (cpu.flags.zf)
    {
        goto L_0x0040d44f;
    }
    // 0040d403  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d408  c68568bd4a0001         -mov byte ptr [ebp + 0x4abd68], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(4898152) /* 0x4abd68 */) = 1 /*0x1*/;
    // 0040d40f  3bc5                   +cmp eax, ebp
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
    // 0040d411  740f                   -je 0x40d422
    if (cpu.flags.zf)
    {
        goto L_0x0040d422;
    }
    // 0040d413  48                     -dec eax
    (cpu.eax)--;
    // 0040d414  3bc5                   +cmp eax, ebp
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
    // 0040d416  740a                   -je 0x40d422
    if (cpu.flags.zf)
    {
        goto L_0x0040d422;
    }
    // 0040d418  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0040d41d  e8ee040000             -call 0x40d910
    cpu.esp -= 4;
    sub_40d910(app, cpu);
L_0x0040d422:
    // 0040d422  e859280200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040d427  83f8ff                 +cmp eax, -1
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
    // 0040d42a  7423                   -je 0x40d44f
    if (cpu.flags.zf)
    {
        goto L_0x0040d44f;
    }
    // 0040d42c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040d42d  7520                   -jne 0x40d44f
    if (!cpu.flags.zf)
    {
        goto L_0x0040d44f;
    }
    // 0040d42f  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d435  8b1524be4a00           -mov edx, dword ptr [0x4abe24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898340) /* 0x4abe24 */);
    // 0040d43b  c7048affffffff         -mov dword ptr [edx + ecx*4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = 4294967295 /*0xffffffff*/;
    // 0040d442  a104be4a00             -mov eax, dword ptr [0x4abe04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */);
    // 0040d447  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0040d44a  a304be4a00             -mov dword ptr [0x4abe04], eax
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.eax;
L_0x0040d44f:
    // 0040d44f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d450  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d451  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0040d454  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40d460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d460  e91b280200             -jmp 0x42fc80
    return sub_42fc80(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40d470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d470  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d475  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d476  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d478  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040d479  0f84a0010000           -je 0x40d61f
    if (cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
    // 0040d47f  803d1abe4a0001         +cmp byte ptr [0x4abe1a], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040d486  0f8493010000           -je 0x40d61f
    if (cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
    // 0040d48c  a13ccd4800             -mov eax, dword ptr [0x48cd3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771132) /* 0x48cd3c */);
    // 0040d491  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0040d497  3bc1                   +cmp eax, ecx
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
    // 0040d499  0f8f80010000           -jg 0x40d61f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040d61f;
    }
    // 0040d49f  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 0040d4a5  dc05a0754800           -fadd qword ptr [0x4875a0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748704) /* 0x4875a0 */));
    // 0040d4ab  e8e0980600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040d4b0  a33ccd4800             -mov dword ptr [0x48cd3c], eax
    app->getMemory<x86::reg32>(x86::reg32(4771132) /* 0x48cd3c */) = cpu.eax;
    // 0040d4b5  e8c6270200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040d4ba  83f8ff                 +cmp eax, -1
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
    // 0040d4bd  0f845c010000           -je 0x40d61f
    if (cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
    // 0040d4c3  83f801                 +cmp eax, 1
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
    // 0040d4c6  740e                   -je 0x40d4d6
    if (cpu.flags.zf)
    {
        goto L_0x0040d4d6;
    }
    // 0040d4c8  83f802                 +cmp eax, 2
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
    // 0040d4cb  7409                   -je 0x40d4d6
    if (cpu.flags.zf)
    {
        goto L_0x0040d4d6;
    }
    // 0040d4cd  83f803                 +cmp eax, 3
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
    // 0040d4d0  0f8549010000           -jne 0x40d61f
    if (!cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
L_0x0040d4d6:
    // 0040d4d6  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040d4dc  8b3530845100           -mov esi, dword ptr [0x518430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d4e2  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040d4e4  8b8a80000000           -mov ecx, dword ptr [edx + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040d4ea  8b148e                 -mov edx, dword ptr [esi + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4);
    // 0040d4ed  8b8ae8020000           -mov ecx, dword ptr [edx + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(744) /* 0x2e8 */);
    // 0040d4f3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040d4f5  0f8424010000           -je 0x40d61f
    if (cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
    // 0040d4fb  8b048508bd4a00         -mov eax, dword ptr [eax*4 + 0x4abd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.eax * 4);
    // 0040d502  8b3d14be4a00           -mov edi, dword ptr [0x4abe14]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d508  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d50b  8b04ba                 -mov eax, dword ptr [edx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 0040d50e  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0040d511  8d14ba                 -lea edx, [edx + edi*4]
    cpu.edx = x86::reg32(cpu.edx + cpu.edi * 4);
    // 0040d514  d980d0000000           -fld dword ptr [eax + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    // 0040d51a  d8a1d0000000           -fsub dword ptr [ecx + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */));
    // 0040d520  d980d8000000           -fld dword ptr [eax + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */)));
    // 0040d526  d8a1d8000000           -fsub dword ptr [ecx + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */));
    // 0040d52c  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040d52e  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040d530  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0040d532  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040d534  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040d536  d81d9c754800           -fcomp dword ptr [0x48759c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748700) /* 0x48759c */)));
    cpu.fpu.pop();
    // 0040d53c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d53e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d540  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040d543  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d545  7b46                   -jnp 0x40d58d
    if (!cpu.flags.pf)
    {
        goto L_0x0040d58d;
    }
    // 0040d547  83ff01                 +cmp edi, 1
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
    // 0040d54a  0f8ecf000000           -jle 0x40d61f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d61f;
    }
    // 0040d550  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0040d553  8b0496                 -mov eax, dword ptr [esi + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 0040d556  d980d0000000           -fld dword ptr [eax + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    // 0040d55c  d8a1d0000000           -fsub dword ptr [ecx + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */));
    // 0040d562  d980d8000000           -fld dword ptr [eax + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */)));
    // 0040d568  d8a1d8000000           -fsub dword ptr [ecx + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */));
    // 0040d56e  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040d570  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040d572  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0040d574  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040d576  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040d578  d81d9c754800           -fcomp dword ptr [0x48759c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748700) /* 0x48759c */)));
    cpu.fpu.pop();
    // 0040d57e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d580  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d582  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040d585  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d587  0f8a92000000           -jp 0x40d61f
    if (cpu.flags.pf)
    {
        goto L_0x0040d61f;
    }
L_0x0040d58d:
    // 0040d58d  e8ee260200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040d592  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040d594  83feff                 +cmp esi, -1
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
    // 0040d597  0f8482000000           -je 0x40d61f
    if (cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
    // 0040d59d  8b0d08be4a00           -mov ecx, dword ptr [0x4abe08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898312) /* 0x4abe08 */);
    // 0040d5a3  a110be4a00             -mov eax, dword ptr [0x4abe10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */);
    // 0040d5a8  41                     -inc ecx
    (cpu.ecx)++;
    // 0040d5a9  890d08be4a00           -mov dword ptr [0x4abe08], ecx
    app->getMemory<x86::reg32>(x86::reg32(4898312) /* 0x4abe08 */) = cpu.ecx;
    // 0040d5af  8b0d0cbe4a00           -mov ecx, dword ptr [0x4abe0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */);
    // 0040d5b5  41                     -inc ecx
    (cpu.ecx)++;
    // 0040d5b6  40                     -inc eax
    (cpu.eax)++;
    // 0040d5b7  83f902                 +cmp ecx, 2
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
    // 0040d5ba  890d0cbe4a00           -mov dword ptr [0x4abe0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */) = cpu.ecx;
    // 0040d5c0  a310be4a00             -mov dword ptr [0x4abe10], eax
    app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */) = cpu.eax;
    // 0040d5c5  7e0f                   -jle 0x40d5d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d5d6;
    }
    // 0040d5c7  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0040d5cc  e83f030000             -call 0x40d910
    cpu.esp -= 4;
    sub_40d910(app, cpu);
    // 0040d5d1  a110be4a00             -mov eax, dword ptr [0x4abe10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */);
L_0x0040d5d6:
    // 0040d5d6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040d5d8  7e45                   -jle 0x40d61f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d61f;
    }
    // 0040d5da  83fe02                 +cmp esi, 2
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
    // 0040d5dd  7e1f                   -jle 0x40d5fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d5fe;
    }
    // 0040d5df  83fe03                 +cmp esi, 3
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
    // 0040d5e2  753b                   -jne 0x40d61f
    if (!cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
    // 0040d5e4  83f801                 +cmp eax, 1
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
    // 0040d5e7  742f                   -je 0x40d618
    if (cpu.flags.zf)
    {
        goto L_0x0040d618;
    }
    // 0040d5e9  83f802                 +cmp eax, 2
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
    // 0040d5ec  7531                   -jne 0x40d61f
    if (!cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
    // 0040d5ee  a104be4a00             -mov eax, dword ptr [0x4abe04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */);
    // 0040d5f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d5f4  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040d5f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d5f8  a304be4a00             -mov dword ptr [0x4abe04], eax
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.eax;
    // 0040d5fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040d5fe:
    // 0040d5fe  83f801                 +cmp eax, 1
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
    // 0040d601  7510                   -jne 0x40d613
    if (!cpu.flags.zf)
    {
        goto L_0x0040d613;
    }
    // 0040d603  a104be4a00             -mov eax, dword ptr [0x4abe04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */);
    // 0040d608  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d609  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0040d60c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d60d  a304be4a00             -mov dword ptr [0x4abe04], eax
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.eax;
    // 0040d612  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040d613:
    // 0040d613  83f802                 +cmp eax, 2
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
    // 0040d616  7507                   -jne 0x40d61f
    if (!cpu.flags.zf)
    {
        goto L_0x0040d61f;
    }
L_0x0040d618:
    // 0040d618  830504be4a0014         -add dword ptr [0x4abe04], 0x14
    (app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */)) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0040d61f:
    // 0040d61f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d620  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d621  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40d630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d630  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d635  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d636  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d638  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040d639  0f848f010000           -je 0x40d7ce
    if (cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
    // 0040d63f  803d1abe4a0001         +cmp byte ptr [0x4abe1a], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040d646  0f8482010000           -je 0x40d7ce
    if (cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
    // 0040d64c  a140cd4800             -mov eax, dword ptr [0x48cd40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4771136) /* 0x48cd40 */);
    // 0040d651  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0040d657  3bc1                   +cmp eax, ecx
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
    // 0040d659  0f8f6f010000           -jg 0x40d7ce
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040d7ce;
    }
    // 0040d65f  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 0040d665  dc05a0754800           -fadd qword ptr [0x4875a0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748704) /* 0x4875a0 */));
    // 0040d66b  e820970600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040d670  a340cd4800             -mov dword ptr [0x48cd40], eax
    app->getMemory<x86::reg32>(x86::reg32(4771136) /* 0x48cd40 */) = cpu.eax;
    // 0040d675  e806260200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040d67a  83f8ff                 +cmp eax, -1
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
    // 0040d67d  0f844b010000           -je 0x40d7ce
    if (cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
    // 0040d683  83f801                 +cmp eax, 1
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
    // 0040d686  740e                   -je 0x40d696
    if (cpu.flags.zf)
    {
        goto L_0x0040d696;
    }
    // 0040d688  83f802                 +cmp eax, 2
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
    // 0040d68b  7409                   -je 0x40d696
    if (cpu.flags.zf)
    {
        goto L_0x0040d696;
    }
    // 0040d68d  83f803                 +cmp eax, 3
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
    // 0040d690  0f8538010000           -jne 0x40d7ce
    if (!cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
L_0x0040d696:
    // 0040d696  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040d69c  8b3530845100           -mov esi, dword ptr [0x518430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d6a2  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040d6a4  8b8a80000000           -mov ecx, dword ptr [edx + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040d6aa  8b148e                 -mov edx, dword ptr [esi + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4);
    // 0040d6ad  8b8ae8020000           -mov ecx, dword ptr [edx + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(744) /* 0x2e8 */);
    // 0040d6b3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040d6b5  0f8413010000           -je 0x40d7ce
    if (cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
    // 0040d6bb  8b048508bd4a00         -mov eax, dword ptr [eax*4 + 0x4abd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.eax * 4);
    // 0040d6c2  8b3d14be4a00           -mov edi, dword ptr [0x4abe14]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d6c8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040d6cb  8b04ba                 -mov eax, dword ptr [edx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 0040d6ce  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0040d6d1  8d14ba                 -lea edx, [edx + edi*4]
    cpu.edx = x86::reg32(cpu.edx + cpu.edi * 4);
    // 0040d6d4  d980d0000000           -fld dword ptr [eax + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    // 0040d6da  d8a1d0000000           -fsub dword ptr [ecx + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */));
    // 0040d6e0  d980d8000000           -fld dword ptr [eax + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */)));
    // 0040d6e6  d8a1d8000000           -fsub dword ptr [ecx + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */));
    // 0040d6ec  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040d6ee  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040d6f0  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0040d6f2  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040d6f4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040d6f6  d81d9c754800           -fcomp dword ptr [0x48759c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748700) /* 0x48759c */)));
    cpu.fpu.pop();
    // 0040d6fc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d6fe  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d700  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040d703  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d705  7b46                   -jnp 0x40d74d
    if (!cpu.flags.pf)
    {
        goto L_0x0040d74d;
    }
    // 0040d707  83ff01                 +cmp edi, 1
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
    // 0040d70a  0f8ebe000000           -jle 0x40d7ce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d7ce;
    }
    // 0040d710  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0040d713  8b0496                 -mov eax, dword ptr [esi + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 0040d716  d980d0000000           -fld dword ptr [eax + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    // 0040d71c  d8a1d0000000           -fsub dword ptr [ecx + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */));
    // 0040d722  d980d8000000           -fld dword ptr [eax + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */)));
    // 0040d728  d8a1d8000000           -fsub dword ptr [ecx + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */));
    // 0040d72e  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040d730  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040d732  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0040d734  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040d736  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040d738  d81d9c754800           -fcomp dword ptr [0x48759c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748700) /* 0x48759c */)));
    cpu.fpu.pop();
    // 0040d73e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d740  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d742  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040d745  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d747  0f8a81000000           -jp 0x40d7ce
    if (cpu.flags.pf)
    {
        goto L_0x0040d7ce;
    }
L_0x0040d74d:
    // 0040d74d  e82e250200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040d752  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040d754  83feff                 +cmp esi, -1
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
    // 0040d757  7475                   -je 0x40d7ce
    if (cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
    // 0040d759  8b0d0cbe4a00           -mov ecx, dword ptr [0x4abe0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */);
    // 0040d75f  a110be4a00             -mov eax, dword ptr [0x4abe10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */);
    // 0040d764  41                     -inc ecx
    (cpu.ecx)++;
    // 0040d765  40                     -inc eax
    (cpu.eax)++;
    // 0040d766  83f902                 +cmp ecx, 2
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
    // 0040d769  890d0cbe4a00           -mov dword ptr [0x4abe0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */) = cpu.ecx;
    // 0040d76f  a310be4a00             -mov dword ptr [0x4abe10], eax
    app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */) = cpu.eax;
    // 0040d774  7e0f                   -jle 0x40d785
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d785;
    }
    // 0040d776  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0040d77b  e890010000             -call 0x40d910
    cpu.esp -= 4;
    sub_40d910(app, cpu);
    // 0040d780  a110be4a00             -mov eax, dword ptr [0x4abe10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */);
L_0x0040d785:
    // 0040d785  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040d787  7e45                   -jle 0x40d7ce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d7ce;
    }
    // 0040d789  83fe02                 +cmp esi, 2
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
    // 0040d78c  7e1f                   -jle 0x40d7ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d7ad;
    }
    // 0040d78e  83fe03                 +cmp esi, 3
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
    // 0040d791  753b                   -jne 0x40d7ce
    if (!cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
    // 0040d793  83f801                 +cmp eax, 1
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
    // 0040d796  742f                   -je 0x40d7c7
    if (cpu.flags.zf)
    {
        goto L_0x0040d7c7;
    }
    // 0040d798  83f802                 +cmp eax, 2
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
    // 0040d79b  7531                   -jne 0x40d7ce
    if (!cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
    // 0040d79d  a104be4a00             -mov eax, dword ptr [0x4abe04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */);
    // 0040d7a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7a3  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040d7a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7a7  a304be4a00             -mov dword ptr [0x4abe04], eax
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.eax;
    // 0040d7ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040d7ad:
    // 0040d7ad  83f801                 +cmp eax, 1
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
    // 0040d7b0  7510                   -jne 0x40d7c2
    if (!cpu.flags.zf)
    {
        goto L_0x0040d7c2;
    }
    // 0040d7b2  a104be4a00             -mov eax, dword ptr [0x4abe04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */);
    // 0040d7b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7b8  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0040d7bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7bc  a304be4a00             -mov dword ptr [0x4abe04], eax
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.eax;
    // 0040d7c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040d7c2:
    // 0040d7c2  83f802                 +cmp eax, 2
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
    // 0040d7c5  7507                   -jne 0x40d7ce
    if (!cpu.flags.zf)
    {
        goto L_0x0040d7ce;
    }
L_0x0040d7c7:
    // 0040d7c7  830504be4a0014         -add dword ptr [0x4abe04], 0x14
    (app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */)) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0040d7ce:
    // 0040d7ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40d7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d7e0  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0040d7e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d7e4  e897240200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040d7e9  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040d7eb  83feff                 +cmp esi, -1
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
    // 0040d7ee  0f8402010000           -je 0x40d8f6
    if (cpu.flags.zf)
    {
        goto L_0x0040d8f6;
    }
    // 0040d7f4  a114be4a00             -mov eax, dword ptr [0x4abe14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d7f9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040d7fb  40                     -inc eax
    (cpu.eax)++;
    // 0040d7fc  68cdcc4c3e             -push 0x3e4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1045220557 /*0x3e4ccccd*/;
    cpu.esp -= 4;
    // 0040d801  a314be4a00             -mov dword ptr [0x4abe14], eax
    app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */) = cpu.eax;
    // 0040d806  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040d80b  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0040d810  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d812  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d817  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0040d81d  b988cd4800             -mov ecx, 0x48cd88
    cpu.ecx = 4771208 /*0x48cd88*/;
    // 0040d822  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040d825  e866600500             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0040d82a  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040d82f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d831  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0040d837  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d83d  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d840  8b92d0000000           -mov edx, dword ptr [edx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */);
    // 0040d846  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0040d84a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d84c  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040d852  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d855  8b92d4000000           -mov edx, dword ptr [edx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0040d85b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0040d85f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d861  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040d867  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0040d86a  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0040d870  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0040d874  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d876  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040d87a  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040d880  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040d883  e828140500             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0040d888  8b04b508bd4a00         -mov eax, dword ptr [esi*4 + 0x4abd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898056) /* 0x4abd08 */ + cpu.esi * 4);
    // 0040d88f  8b0d14be4a00           -mov ecx, dword ptr [0x4abe14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */);
    // 0040d895  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d897  8b348a                 -mov esi, dword ptr [edx + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040d89a  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d8a0  8b34b2                 -mov esi, dword ptr [edx + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040d8a3  d986d0000000           -fld dword ptr [esi + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */)));
    // 0040d8a9  d8642408               -fsub dword ptr [esp + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0040d8ad  d95c2430               -fstp dword ptr [esp + 0x30]
    app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d8b1  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d8b3  8b348e                 -mov esi, dword ptr [esi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4);
    // 0040d8b6  8b34b2                 -mov esi, dword ptr [edx + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0040d8b9  d986d4000000           -fld dword ptr [esi + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */)));
    // 0040d8bf  d864240c               -fsub dword ptr [esp + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0040d8c3  d95c2434               -fstp dword ptr [esp + 0x34]
    app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d8c7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040d8c9  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0040d8cc  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040d8cf  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040d8d3  d982d8000000           -fld dword ptr [edx + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(216) /* 0xd8 */)));
    // 0040d8d9  d8642410               -fsub dword ptr [esp + 0x10]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0040d8dd  d95c2438               -fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d8e1  e8aaf30300             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 0040d8e6  d91d84be4a00           -fstp dword ptr [0x4abe84]
    app->getMemory<float>(x86::reg32(4898436) /* 0x4abe84 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d8ec  c70588be4a0000000000   -mov dword ptr [0x4abe88], 0
    app->getMemory<x86::reg32>(x86::reg32(4898440) /* 0x4abe88 */) = 0 /*0x0*/;
L_0x0040d8f6:
    // 0040d8f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d8f7  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0040d8fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40d900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d900  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d902  a01abe4a00             -mov al, byte ptr [0x4abe1a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
    // 0040d907  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40d910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0040d910  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040d911  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040d913  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0040d916  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0040d91c  a01abe4a00             -mov al, byte ptr [0x4abe1a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */);
    // 0040d921  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d922  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d923  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040d925  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040d926  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040d928  0f844e030000           -je 0x40dc7c
    if (cpu.flags.zf)
    {
        goto L_0x0040dc7c;
    }
    // 0040d92e  c6051abe4a0001         -mov byte ptr [0x4abe1a], 1
    app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */) = 1 /*0x1*/;
    // 0040d935  e8f67d0500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040d93a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d93c  e8ef7d0500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040d941  dc25ecbd4a00           -fsub qword ptr [0x4abdec]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4898284) /* 0x4abdec */));
    // 0040d947  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0040d94a  83f806                 +cmp eax, 6
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
    // 0040d94d  dd1dfcbd4a00           +fstp qword ptr [0x4abdfc]
    app->getMemory<double>(x86::reg32(4898300) /* 0x4abdfc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d953  0f8723030000           -ja 0x40dc7c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040dc7c;
    }
    // 0040d959  ff248584dc4000         -jmp dword ptr [eax*4 + 0x40dc84]
    cpu.ip = app->getMemory<x86::reg32>(4250756 + cpu.eax * 4); goto dynamic_jump;
  case 0x0040d960:
    // 0040d960  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040d965  c6051bbe4a0001         -mov byte ptr [0x4abe1b], 1
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = 1 /*0x1*/;
    // 0040d96c  e8cf740400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040d971  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040d972  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040d976  68e8cd4800             -push 0x48cde8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771304 /*0x48cde8*/;
    cpu.esp -= 4;
    // 0040d97b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040d97c  e877940600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040d981  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040d987  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040d98a  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0040d98c  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040d98e  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d994  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d995  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040d99a  8b8280000000           -mov eax, dword ptr [edx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040d9a0  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040d9a5  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040d9a8  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040d9ac  e8df5e0500             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0040d9b1  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d9b7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040d9b9  8bb018030000           -mov esi, dword ptr [eax + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 0040d9bf  e914020000             -jmp 0x40dbd8
    goto L_0x0040dbd8;
  case 0x0040d9c4:
    // 0040d9c4  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040d9c9  c6051bbe4a0001         -mov byte ptr [0x4abe1b], 1
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = 1 /*0x1*/;
    // 0040d9d0  e86b740400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040d9d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040d9d6  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040d9da  68e8cd4800             -push 0x48cde8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771304 /*0x48cde8*/;
    cpu.esp -= 4;
    // 0040d9df  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040d9e0  e813940600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040d9e5  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040d9eb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040d9ee  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0040d9f0  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040d9f2  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040d9f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d9f9  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040d9fe  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040da04  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040da09  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040da0c  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040da10  e87b5e0500             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0040da15  e9d7010000             -jmp 0x40dbf1
    goto L_0x0040dbf1;
  case 0x0040da1a:
    // 0040da1a  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040da1f  e81c740400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040da24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040da25  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040da29  68d8cd4800             -push 0x48cdd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771288 /*0x48cdd8*/;
    cpu.esp -= 4;
    // 0040da2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040da2f  e8c4930600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040da34  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040da3a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040da3d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040da3f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040da41  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040da47  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040da48  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040da4d  8b8280000000           -mov eax, dword ptr [edx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040da53  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040da58  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040da5b  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040da5f  e82c5e0500             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0040da64  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040da6a  b9d0cd4800             -mov ecx, 0x48cdd0
    cpu.ecx = 4771280 /*0x48cdd0*/;
    // 0040da6f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040da71  8bb018030000           -mov esi, dword ptr [eax + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 0040da77  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040da79  e892910500             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 0040da7e  3bc3                   +cmp eax, ebx
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
    // 0040da80  7409                   -je 0x40da8b
    if (cpu.flags.zf)
    {
        goto L_0x0040da8b;
    }
    // 0040da82  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040da84  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040da86  e8958c0500             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
L_0x0040da8b:
    // 0040da8b  e8f0210200             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0040da90  83f802                 +cmp eax, 2
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
    // 0040da93  7505                   -jne 0x40da9a
    if (!cpu.flags.zf)
    {
        goto L_0x0040da9a;
    }
    // 0040da95  e806020000             -call 0x40dca0
    cpu.esp -= 4;
    sub_40dca0(app, cpu);
L_0x0040da9a:
    // 0040da9a  833ddc28490008         +cmp dword ptr [0x4928dc], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040daa1  0f8dd5010000           -jge 0x40dc7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040dc7c;
    }
    // 0040daa7  e999010000             -jmp 0x40dc45
    goto L_0x0040dc45;
  case 0x0040daac:
    // 0040daac  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040dab1  c6051bbe4a0001         -mov byte ptr [0x4abe1b], 1
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = 1 /*0x1*/;
    // 0040dab8  e883730400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040dabd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040dabe  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040dac2  68c0cd4800             -push 0x48cdc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771264 /*0x48cdc0*/;
    cpu.esp -= 4;
    // 0040dac7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040dac8  e82b930600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040dacd  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040dad3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040dad6  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0040dad8  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0040dada  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040dae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040dae1  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040dae6  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040daec  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040daf1  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040daf4  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040daf8  e8935d0500             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0040dafd  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040db02  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040db04  8bb118030000           -mov esi, dword ptr [ecx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 0040db0a  e9c9000000             -jmp 0x40dbd8
    goto L_0x0040dbd8;
  case 0x0040db0f:
    // 0040db0f  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040db14  c6051bbe4a0001         -mov byte ptr [0x4abe1b], 1
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = 1 /*0x1*/;
    // 0040db1b  e820730400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040db20  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040db21  68e8cd4800             -push 0x48cde8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771304 /*0x48cde8*/;
    cpu.esp -= 4;
    // 0040db26  eb6a                   -jmp 0x40db92
    goto L_0x0040db92;
  case 0x0040db28:
    // 0040db28  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040db2d  c6051bbe4a0001         -mov byte ptr [0x4abe1b], 1
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = 1 /*0x1*/;
    // 0040db34  e807730400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040db39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040db3a  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040db3e  68e8cd4800             -push 0x48cde8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771304 /*0x48cde8*/;
    cpu.esp -= 4;
    // 0040db43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040db44  e8af920600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040db49  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040db4f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040db52  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0040db54  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040db56  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040db5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040db5d  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040db62  8b8280000000           -mov eax, dword ptr [edx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0040db68  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040db6d  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0040db70  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040db74  e8175d0500             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0040db79  eb76                   -jmp 0x40dbf1
    goto L_0x0040dbf1;
  case 0x0040db7b:
    // 0040db7b  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040db80  c6051bbe4a0001         -mov byte ptr [0x4abe1b], 1
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = 1 /*0x1*/;
    // 0040db87  e8b4720400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040db8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040db8d  68b0cd4800             -push 0x48cdb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771248 /*0x48cdb0*/;
    cpu.esp -= 4;
L_0x0040db92:
    // 0040db92  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040db96  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040db97  e85c920600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040db9c  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0040dba1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040dba4  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040dba6  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040dba8  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040dbad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040dbae  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040dbb3  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0040dbb9  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040dbbd  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040dbc2  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0040dbc5  e8c65c0500             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0040dbca  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040dbd0  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040dbd2  8bb218030000           -mov esi, dword ptr [edx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(792) /* 0x318 */);
L_0x0040dbd8:
    // 0040dbd8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040dbda  b9a0cd4800             -mov ecx, 0x48cda0
    cpu.ecx = 4771232 /*0x48cda0*/;
    // 0040dbdf  e82c900500             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 0040dbe4  3bc3                   +cmp eax, ebx
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
    // 0040dbe6  7409                   -je 0x40dbf1
    if (cpu.flags.zf)
    {
        goto L_0x0040dbf1;
    }
    // 0040dbe8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040dbea  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040dbec  e82f8b0500             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
L_0x0040dbf1:
    // 0040dbf1  c705ecbd4a0000000000   -mov dword ptr [0x4abdec], 0
    app->getMemory<x86::reg32>(x86::reg32(4898284) /* 0x4abdec */) = 0 /*0x0*/;
    // 0040dbfb  c705f0bd4a0000000000   -mov dword ptr [0x4abdf0], 0
    app->getMemory<x86::reg32>(x86::reg32(4898288) /* 0x4abdf0 */) = 0 /*0x0*/;
    // 0040dc05  c705f4bd4a0000000000   -mov dword ptr [0x4abdf4], 0
    app->getMemory<x86::reg32>(x86::reg32(4898292) /* 0x4abdf4 */) = 0 /*0x0*/;
    // 0040dc0f  c705f8bd4a0000000000   -mov dword ptr [0x4abdf8], 0
    app->getMemory<x86::reg32>(x86::reg32(4898296) /* 0x4abdf8 */) = 0 /*0x0*/;
    // 0040dc19  c705fcbd4a0000000000   -mov dword ptr [0x4abdfc], 0
    app->getMemory<x86::reg32>(x86::reg32(4898300) /* 0x4abdfc */) = 0 /*0x0*/;
    // 0040dc23  c70500be4a0000000000   -mov dword ptr [0x4abe00], 0
    app->getMemory<x86::reg32>(x86::reg32(4898304) /* 0x4abe00 */) = 0 /*0x0*/;
    // 0040dc2d  891d04be4a00           -mov dword ptr [0x4abe04], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898308) /* 0x4abe04 */) = cpu.ebx;
    // 0040dc33  891d08be4a00           -mov dword ptr [0x4abe08], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898312) /* 0x4abe08 */) = cpu.ebx;
    // 0040dc39  891d0cbe4a00           -mov dword ptr [0x4abe0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898316) /* 0x4abe0c */) = cpu.ebx;
    // 0040dc3f  891d10be4a00           -mov dword ptr [0x4abe10], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898320) /* 0x4abe10 */) = cpu.ebx;
L_0x0040dc45:
    // 0040dc45  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040dc47  bf68bd4a00             -mov edi, 0x4abd68
    cpu.edi = 4898152 /*0x4abd68*/;
    // 0040dc4c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0040dc51  a384be4a00             -mov dword ptr [0x4abe84], eax
    app->getMemory<x86::reg32>(x86::reg32(4898436) /* 0x4abe84 */) = cpu.eax;
    // 0040dc56  a388be4a00             -mov dword ptr [0x4abe88], eax
    app->getMemory<x86::reg32>(x86::reg32(4898440) /* 0x4abe88 */) = cpu.eax;
    // 0040dc5b  891d14be4a00           -mov dword ptr [0x4abe14], ebx
    app->getMemory<x86::reg32>(x86::reg32(4898324) /* 0x4abe14 */) = cpu.ebx;
    // 0040dc61  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040dc63  c60518be4a0001         -mov byte ptr [0x4abe18], 1
    app->getMemory<x86::reg8>(x86::reg32(4898328) /* 0x4abe18 */) = 1 /*0x1*/;
    // 0040dc6a  881d19be4a00           -mov byte ptr [0x4abe19], bl
    app->getMemory<x86::reg8>(x86::reg32(4898329) /* 0x4abe19 */) = cpu.bl;
    // 0040dc70  881d1abe4a00           -mov byte ptr [0x4abe1a], bl
    app->getMemory<x86::reg8>(x86::reg32(4898330) /* 0x4abe1a */) = cpu.bl;
    // 0040dc76  881d1bbe4a00           -mov byte ptr [0x4abe1b], bl
    app->getMemory<x86::reg8>(x86::reg32(4898331) /* 0x4abe1b */) = cpu.bl;
L_0x0040dc7c:
    // 0040dc7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dc7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dc7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dc7f  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040dc81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dc82  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_40dca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040dca0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0040dca3  8b0d10155200           -mov ecx, dword ptr [0x521510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 0040dca9  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040dcaf  e85ca10100             -call 0x427e10
    cpu.esp -= 4;
    sub_427e10(app, cpu);
    // 0040dcb4  8b0d10155200           -mov ecx, dword ptr [0x521510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 0040dcba  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dcbe  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040dcc4  e867a10100             -call 0x427e30
    cpu.esp -= 4;
    sub_427e30(app, cpu);
    // 0040dcc9  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dccd  e80ef1ffff             -call 0x40cde0
    cpu.esp -= 4;
    sub_40cde0(app, cpu);
    // 0040dcd2  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dcd6  e8c577ffff             -call 0x4054a0
    cpu.esp -= 4;
    sub_4054a0(app, cpu);
    // 0040dcdb  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dcdf  e87c77ffff             -call 0x405460
    cpu.esp -= 4;
    sub_405460(app, cpu);
    // 0040dce4  d87c240c               -fdivr dword ptr [esp + 0xc]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)) / cpu.fpu.st(0);
    // 0040dce8  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dcec  e81f270100             -call 0x420410
    cpu.esp -= 4;
    sub_420410(app, cpu);
    // 0040dcf1  a108be4a00             -mov eax, dword ptr [0x4abe08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898312) /* 0x4abe08 */);
    // 0040dcf6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040dcf8  7536                   -jne 0x40dd30
    if (!cpu.flags.zf)
    {
        goto L_0x0040dd30;
    }
    // 0040dcfa  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0040dcfe  d8250c754800           -fsub dword ptr [0x48750c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748556) /* 0x48750c */));
    // 0040dd04  d85c2400               -fcomp dword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp)));
    cpu.fpu.pop();
    // 0040dd08  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dd0a  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040dd0d  7a28                   -jp 0x40dd37
    if (cpu.flags.pf)
    {
        goto L_0x0040dd37;
    }
    // 0040dd0f  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0040dd13  d805b8744800           -fadd dword ptr [0x4874b8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0040dd19  d85c2400               -fcomp dword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp)));
    cpu.fpu.pop();
    // 0040dd1d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dd1f  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040dd24  7511                   -jne 0x40dd37
    if (!cpu.flags.zf)
    {
        goto L_0x0040dd37;
    }
    // 0040dd26  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0040dd2e  eb07                   -jmp 0x40dd37
    goto L_0x0040dd37;
L_0x0040dd30:
    // 0040dd30  7e05                   -jle 0x40dd37
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040dd37;
    }
    // 0040dd32  83f802                 +cmp eax, 2
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
    // 0040dd35  7e2c                   -jle 0x40dd63
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040dd63;
    }
L_0x0040dd37:
    // 0040dd37  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0040dd3b  d82500754800           -fsub dword ptr [0x487500]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748544) /* 0x487500 */));
    // 0040dd41  d85c2400               -fcomp dword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp)));
    cpu.fpu.pop();
    // 0040dd45  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dd47  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040dd4c  751d                   -jne 0x40dd6b
    if (!cpu.flags.zf)
    {
        goto L_0x0040dd6b;
    }
    // 0040dd4e  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0040dd52  d8250c754800           -fsub dword ptr [0x48750c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748556) /* 0x48750c */));
    // 0040dd58  d85c2400               -fcomp dword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp)));
    cpu.fpu.pop();
    // 0040dd5c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dd5e  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040dd61  7a08                   -jp 0x40dd6b
    if (cpu.flags.pf)
    {
        goto L_0x0040dd6b;
    }
L_0x0040dd63:
    // 0040dd63  c74424080000803f       -mov dword ptr [esp + 8], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1065353216 /*0x3f800000*/;
L_0x0040dd6b:
    // 0040dd6b  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0040dd6f  d81da8754800           -fcomp dword ptr [0x4875a8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748712) /* 0x4875a8 */)));
    cpu.fpu.pop();
    // 0040dd75  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dd77  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040dd7c  7508                   -jne 0x40dd86
    if (!cpu.flags.zf)
    {
        goto L_0x0040dd86;
    }
    // 0040dd7e  c744240800000040       -mov dword ptr [esp + 8], 0x40000000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1073741824 /*0x40000000*/;
L_0x0040dd86:
    // 0040dd86  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0040dd8a  d85c2410               -fcomp dword ptr [esp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0040dd8e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dd90  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0040dd95  740f                   -je 0x40dda6
    if (cpu.flags.zf)
    {
        goto L_0x0040dda6;
    }
    // 0040dd97  d81da8754800           -fcomp dword ptr [0x4875a8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748712) /* 0x4875a8 */)));
    cpu.fpu.pop();
    // 0040dd9d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dd9f  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0040dda2  7a0c                   -jp 0x40ddb0
    if (cpu.flags.pf)
    {
        goto L_0x0040ddb0;
    }
    // 0040dda4  eb02                   -jmp 0x40dda8
    goto L_0x0040dda8;
L_0x0040dda6:
    // 0040dda6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040dda8:
    // 0040dda8  c744240800004040       -mov dword ptr [esp + 8], 0x40400000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1077936128 /*0x40400000*/;
L_0x0040ddb0:
    // 0040ddb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ddb1  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 0040ddb6  b9f8cd4800             -mov ecx, 0x48cdf8
    cpu.ecx = 4771320 /*0x48cdf8*/;
    // 0040ddbb  e880ec0300             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0040ddc0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040ddc2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040ddc4  7418                   -je 0x40ddde
    if (cpu.flags.zf)
    {
        goto L_0x0040ddde;
    }
    // 0040ddc6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ddc7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ddc9  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040ddcd  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0040ddcf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ddd0  e8ca990600             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0040ddd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ddd6  e8fc970600             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0040dddb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0040ddde:
    // 0040ddde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dddf  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0040dde2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40ddf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ddf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ddf1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040ddf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ddf4  e881940600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040ddf9  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040ddfb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ddfe  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040de00  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040de02  7414                   -je 0x40de18
    if (cpu.flags.zf)
    {
        goto L_0x0040de18;
    }
    // 0040de04  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040de06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040de07  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040de09  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040de0c  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040de0e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040de10  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040de13  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 0040de15  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040de17  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040de18:
    // 0040de18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40de20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040de20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040de21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040de22  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040de24  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040de26  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 0040de28  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0040de2a  740d                   -je 0x40de39
    if (cpu.flags.zf)
    {
        goto L_0x0040de39;
    }
L_0x0040de2c:
    // 0040de2c  3ad3                   +cmp dl, bl
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
    // 0040de2e  740c                   -je 0x40de3c
    if (cpu.flags.zf)
    {
        goto L_0x0040de3c;
    }
    // 0040de30  8a5c3001               -mov bl, byte ptr [eax + esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */ + cpu.esi * 1);
    // 0040de34  40                     -inc eax
    (cpu.eax)++;
    // 0040de35  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0040de37  75f3                   -jne 0x40de2c
    if (!cpu.flags.zf)
    {
        goto L_0x0040de2c;
    }
L_0x0040de39:
    // 0040de39  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0040de3c:
    // 0040de3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40de40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040de40  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0040de42  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040de44  80fa20                 +cmp dl, 0x20
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
    // 0040de47  7418                   -je 0x40de61
    if (cpu.flags.zf)
    {
        goto L_0x0040de61;
    }
L_0x0040de49:
    // 0040de49  80fa09                 +cmp dl, 9
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
    // 0040de4c  7413                   -je 0x40de61
    if (cpu.flags.zf)
    {
        goto L_0x0040de61;
    }
    // 0040de4e  80fa0a                 +cmp dl, 0xa
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040de51  740e                   -je 0x40de61
    if (cpu.flags.zf)
    {
        goto L_0x0040de61;
    }
    // 0040de53  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0040de55  740a                   -je 0x40de61
    if (cpu.flags.zf)
    {
        goto L_0x0040de61;
    }
    // 0040de57  8a540801               -mov dl, byte ptr [eax + ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 0040de5b  40                     -inc eax
    (cpu.eax)++;
    // 0040de5c  80fa20                 +cmp dl, 0x20
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
    // 0040de5f  75e8                   -jne 0x40de49
    if (!cpu.flags.zf)
    {
        goto L_0x0040de49;
    }
L_0x0040de61:
    // 0040de61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40de70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040de70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040de71  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040de73  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0040de76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040de77  e8fe930600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040de7c  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040de7e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040de81  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040de83  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040de85  7414                   -je 0x40de9b
    if (cpu.flags.zf)
    {
        goto L_0x0040de9b;
    }
    // 0040de87  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040de89  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040de8a  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040de8c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040de8f  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040de91  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040de93  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040de96  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 0040de98  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040de9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040de9b:
    // 0040de9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40dea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040dea0  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040dea2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040dea3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040dea5  741e                   -je 0x40dec5
    if (cpu.flags.zf)
    {
        goto L_0x0040dec5;
    }
    // 0040dea7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040dea9  741a                   -je 0x40dec5
    if (cpu.flags.zf)
    {
        goto L_0x0040dec5;
    }
    // 0040deab  668b30                 -mov si, word ptr [eax]
    cpu.si = app->getMemory<x86::reg16>(cpu.eax);
    // 0040deae  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 0040deb1  7412                   -je 0x40dec5
    if (cpu.flags.zf)
    {
        goto L_0x0040dec5;
    }
    // 0040deb3  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040deb5:
    // 0040deb5  66893401               -mov word ptr [ecx + eax], si
    app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 1) = cpu.si;
    // 0040deb9  668b7002               -mov si, word ptr [eax + 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0040debd  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040dec0  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 0040dec3  75f0                   -jne 0x40deb5
    if (!cpu.flags.zf)
    {
        goto L_0x0040deb5;
    }
L_0x0040dec5:
    // 0040dec5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dec6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40ded0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ded0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040ded2  663901                 +cmp word ptr [ecx], ax
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040ded5  7408                   -je 0x40dedf
    if (cpu.flags.zf)
    {
        goto L_0x0040dedf;
    }
L_0x0040ded7:
    // 0040ded7  40                     -inc eax
    (cpu.eax)++;
    // 0040ded8  66833c4100             +cmp word ptr [ecx + eax*2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040dedd  75f8                   -jne 0x40ded7
    if (!cpu.flags.zf)
    {
        goto L_0x0040ded7;
    }
L_0x0040dedf:
    // 0040dedf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40dee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040dee0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040dee2:
    // 0040dee2  668b1441               -mov dx, word ptr [ecx + eax*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2);
    // 0040dee6  6683fa20               +cmp dx, 0x20
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040deea  7412                   -je 0x40defe
    if (cpu.flags.zf)
    {
        goto L_0x0040defe;
    }
    // 0040deec  6683fa09               +cmp dx, 9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040def0  740c                   -je 0x40defe
    if (cpu.flags.zf)
    {
        goto L_0x0040defe;
    }
    // 0040def2  6683fa0a               +cmp dx, 0xa
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10 /*0xa*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040def6  7406                   -je 0x40defe
    if (cpu.flags.zf)
    {
        goto L_0x0040defe;
    }
    // 0040def8  6683fa0d               +cmp dx, 0xd
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040defc  7508                   -jne 0x40df06
    if (!cpu.flags.zf)
    {
        goto L_0x0040df06;
    }
L_0x0040defe:
    // 0040defe  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0040df01  7403                   -je 0x40df06
    if (cpu.flags.zf)
    {
        goto L_0x0040df06;
    }
    // 0040df03  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040df04  ebdc                   -jmp 0x40dee2
    goto L_0x0040dee2;
L_0x0040df06:
    // 0040df06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40df10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040df10  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 0040df13  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040df15  6683fa20               +cmp dx, 0x20
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040df19  741d                   -je 0x40df38
    if (cpu.flags.zf)
    {
        goto L_0x0040df38;
    }
L_0x0040df1b:
    // 0040df1b  6683fa09               +cmp dx, 9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040df1f  7417                   -je 0x40df38
    if (cpu.flags.zf)
    {
        goto L_0x0040df38;
    }
    // 0040df21  6683fa0a               +cmp dx, 0xa
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10 /*0xa*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040df25  7411                   -je 0x40df38
    if (cpu.flags.zf)
    {
        goto L_0x0040df38;
    }
    // 0040df27  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0040df2a  740c                   -je 0x40df38
    if (cpu.flags.zf)
    {
        goto L_0x0040df38;
    }
    // 0040df2c  668b544102             -mov dx, word ptr [ecx + eax*2 + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 0040df31  40                     -inc eax
    (cpu.eax)++;
    // 0040df32  6683fa20               +cmp dx, 0x20
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040df36  75e3                   -jne 0x40df1b
    if (!cpu.flags.zf)
    {
        goto L_0x0040df1b;
    }
L_0x0040df38:
    // 0040df38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40df40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040df40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040df41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040df42  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040df44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040df45  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040df47  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040df49  66833820               +cmp word ptr [eax], 0x20
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040df4d  7435                   -je 0x40df84
    if (cpu.flags.zf)
    {
        goto L_0x0040df84;
    }
    // 0040df4f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0040df51:
    // 0040df51  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0040df54  6683f909               +cmp cx, 9
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040df58  742a                   -je 0x40df84
    if (cpu.flags.zf)
    {
        goto L_0x0040df84;
    }
    // 0040df5a  6683f90a               +cmp cx, 0xa
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10 /*0xa*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040df5e  7424                   -je 0x40df84
    if (cpu.flags.zf)
    {
        goto L_0x0040df84;
    }
    // 0040df60  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0040df63  741f                   -je 0x40df84
    if (cpu.flags.zf)
    {
        goto L_0x0040df84;
    }
    // 0040df65  e846650000             -call 0x4144b0
    cpu.esp -= 4;
    sub_4144b0(app, cpu);
    // 0040df6a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040df6c  7e04                   -jle 0x40df72
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040df72;
    }
    // 0040df6e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040df70  7405                   -je 0x40df77
    if (cpu.flags.zf)
    {
        goto L_0x0040df77;
    }
L_0x0040df72:
    // 0040df72  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
L_0x0040df77:
    // 0040df77  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040df7a  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040df7c  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040df7e  66833e20               +cmp word ptr [esi], 0x20
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040df82  75cd                   -jne 0x40df51
    if (!cpu.flags.zf)
    {
        goto L_0x0040df51;
    }
L_0x0040df84:
    // 0040df84  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0040df86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040df87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040df88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040df89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40df90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040df90  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0040df96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040df97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040df98  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040df9a  e891770500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040df9f  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dfa3  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040dfa8  e8936e0400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040dfad  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040dfb0  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0040dfb2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040dfb4  7429                   -je 0x40dfdf
    if (cpu.flags.zf)
    {
        goto L_0x0040dfdf;
    }
L_0x0040dfb6:
    // 0040dfb6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040dfb8  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040dfbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040dfbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040dfbe  6860cf4800             -push 0x48cf60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771680 /*0x48cf60*/;
    cpu.esp -= 4;
    // 0040dfc3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040dfc4  e82f8e0600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040dfc9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040dfcc  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040dfd0  e8cb500500             -call 0x4630a0
    cpu.esp -= 4;
    sub_4630a0(app, cpu);
    // 0040dfd5  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0040dfd8  8b760c                 -mov esi, dword ptr [esi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0040dfdb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040dfdd  75d7                   -jne 0x40dfb6
    if (!cpu.flags.zf)
    {
        goto L_0x0040dfb6;
    }
L_0x0040dfdf:
    // 0040dfdf  e84c770500             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0040dfe4  d8642408               -fsub dword ptr [esp + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0040dfe8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040dfeb  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dfee  6838cf4800             -push 0x48cf38
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771640 /*0x48cf38*/;
    cpu.esp -= 4;
    // 0040dff3  e8bf8d0600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040dff8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040dffb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dffc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dffd  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0040e003  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e010  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040e016  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e017  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e018  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0040e01a  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040e01c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0040e01e  0f84ea000000           -je 0x40e10e
    if (cpu.flags.zf)
    {
        goto L_0x0040e10e;
    }
    // 0040e024  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040e026  0f84e2000000           -je 0x40e10e
    if (cpu.flags.zf)
    {
        goto L_0x0040e10e;
    }
    // 0040e02c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e02d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e02e  b904bf4a00             -mov ecx, 0x4abf04
    cpu.ecx = 4898564 /*0x4abf04*/;
    // 0040e033  e868020000             -call 0x40e2a0
    cpu.esp -= 4;
    sub_40e2a0(app, cpu);
    // 0040e038  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040e03a  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0040e03f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e041  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0040e043  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040e045  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e046  e8529d0600             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 0040e04b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040e04d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e050  41                     -inc ecx
    (cpu.ecx)++;
    // 0040e051  e81afeffff             -call 0x40de70
    cpu.esp -= 4;
    sub_40de70(app, cpu);
    // 0040e056  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0040e058  8a842498000000         -mov al, byte ptr [esp + 0x98]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0040e05f  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040e061  750b                   -jne 0x40e06e
    if (!cpu.flags.zf)
    {
        goto L_0x0040e06e;
    }
    // 0040e063  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0040e065  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0040e067  e8b4000000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    // 0040e06c  eb0a                   -jmp 0x40e078
    goto L_0x0040e078;
L_0x0040e06e:
    // 0040e06e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e06f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e070  e8039d0600             -call 0x477d78
    cpu.esp -= 4;
    sub_477d78(app, cpu);
    // 0040e075  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040e078:
    // 0040e078  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0040e07a  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0040e07d  e84efeffff             -call 0x40ded0
    cpu.esp -= 4;
    sub_40ded0(app, cpu);
    // 0040e082  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0040e084  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e085  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040e08a  e8b16d0400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040e08f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e092  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e093  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e097  6860cf4800             -push 0x48cf60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771680 /*0x48cf60*/;
    cpu.esp -= 4;
    // 0040e09c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e09d  e8568d0600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040e0a2  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0040e0a9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040e0ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e0ae  7508                   -jne 0x40e0b8
    if (!cpu.flags.zf)
    {
        goto L_0x0040e0b8;
    }
    // 0040e0b0  dd0558734800           +fld qword ptr [0x487358]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */)));
    // 0040e0b6  eb07                   -jmp 0x40e0bf
    goto L_0x0040e0bf;
L_0x0040e0b8:
    // 0040e0b8  db842494000000         -fild dword ptr [esp + 0x94]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */))));
L_0x0040e0bf:
    // 0040e0bf  e8cc8c0600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040e0c4  89463c                 -mov dword ptr [esi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0040e0c7  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 0040e0cc  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0040e0cf  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0040e0d2  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040e0d8  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040e0da  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040e0dc  8d4e08                 -lea ecx, [esi + 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0040e0df  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040e0e1  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0040e0e4  c7464400000000         -mov dword ptr [esi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0040e0eb  2bfb                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0040e0ed:
    // 0040e0ed  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0040e0ef  881407                 -mov byte ptr [edi + eax], dl
    app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1) = cpu.dl;
    // 0040e0f2  40                     -inc eax
    (cpu.eax)++;
    // 0040e0f3  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0040e0f5  75f6                   -jne 0x40e0ed
    if (!cpu.flags.zf)
    {
        goto L_0x0040e0ed;
    }
    // 0040e0f7  e874000000             -call 0x40e170
    cpu.esp -= 4;
    sub_40e170(app, cpu);
    // 0040e0fc  894638                 -mov dword ptr [esi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0040e0ff  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040e101  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e102  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e103  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e104  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e105  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040e10b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0040e10e:
    // 0040e10e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e10f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e111  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e112  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040e118  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40e120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e120  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 0040e123  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e124  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040e126  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0040e129  7434                   -je 0x40e15f
    if (cpu.flags.zf)
    {
        goto L_0x0040e15f;
    }
    // 0040e12b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e12c  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e12e  2bf2                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040e130:
    // 0040e130  663d0900               +cmp ax, 9
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040e134  7412                   -je 0x40e148
    if (cpu.flags.zf)
    {
        goto L_0x0040e148;
    }
    // 0040e136  663d0d00               +cmp ax, 0xd
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040e13a  740c                   -je 0x40e148
    if (cpu.flags.zf)
    {
        goto L_0x0040e148;
    }
    // 0040e13c  663d2200               +cmp ax, 0x22
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040e140  7406                   -je 0x40e148
    if (cpu.flags.zf)
    {
        goto L_0x0040e148;
    }
    // 0040e142  663d0a00               +cmp ax, 0xa
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10 /*0xa*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040e146  7505                   -jne 0x40e14d
    if (!cpu.flags.zf)
    {
        goto L_0x0040e14d;
    }
L_0x0040e148:
    // 0040e148  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
L_0x0040e14d:
    // 0040e14d  66890416               -mov word ptr [esi + edx], ax
    app->getMemory<x86::reg16>(cpu.esi + cpu.edx * 1) = cpu.ax;
    // 0040e151  668b4202               -mov ax, word ptr [edx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0040e155  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040e158  47                     -inc edi
    (cpu.edi)++;
    // 0040e159  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0040e15c  75d2                   -jne 0x40e130
    if (!cpu.flags.zf)
    {
        goto L_0x0040e130;
    }
    // 0040e15e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040e15f:
    // 0040e15f  66c704790000           -mov word ptr [ecx + edi*2], 0
    app->getMemory<x86::reg16>(cpu.ecx + cpu.edi * 2) = 0 /*0x0*/;
    // 0040e165  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e166  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0040e170  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e171  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e173  0fbe4601               -movsx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */)));
    // 0040e177  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e178  e820930600             -call 0x47749d
    cpu.esp -= 4;
    sub_47749d(app, cpu);
    // 0040e17d  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0040e180  83c0cf                 -add eax, -0x31
    (cpu.eax) += x86::reg32(x86::sreg32(-49 /*-0x31*/));
    // 0040e183  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e186  83f843                 +cmp eax, 0x43
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e189  777b                   -ja 0x40e206
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040e206;
    }
    // 0040e18b  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040e18d  8a885ce24000           -mov cl, byte ptr [eax + 0x40e25c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4252252) /* 0x40e25c */);
    // 0040e193  ff248d20e24000         -jmp dword ptr [ecx*4 + 0x40e220]
    cpu.ip = app->getMemory<x86::reg32>(4252192 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0040e19a:
    // 0040e19a  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0040e19d  2c30                   -sub al, 0x30
    (cpu.al) -= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 0040e19f  f6d8                   +neg al
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
    // 0040e1a1  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0040e1a3  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040e1a6  83c005                 +add eax, 5
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040e1a9  eb60                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1ab:
    // 0040e1ab  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040e1ad  eb5c                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1af:
    // 0040e1af  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040e1b4  eb55                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1b6:
    // 0040e1b6  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0040e1bb  eb4e                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1bd:
    // 0040e1bd  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0040e1c2  eb47                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1c4:
    // 0040e1c4  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0040e1c9  eb40                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1cb:
    // 0040e1cb  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0040e1d0  eb39                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1d2:
    // 0040e1d2  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0040e1d7  eb32                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1d9:
    // 0040e1d9  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0040e1de  eb2b                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1e0:
    // 0040e1e0  a11cd44a00             -mov eax, dword ptr [0x4ad41c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903964) /* 0x4ad41c */);
    // 0040e1e5  f7d8                   +neg eax
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
    // 0040e1e7  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0040e1e9  83e005                 -and eax, 5
    cpu.eax &= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0040e1ec  83c00b                 +add eax, 0xb
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040e1ef  eb1a                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1f1:
    // 0040e1f1  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0040e1f6  eb13                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1f8:
    // 0040e1f8  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0040e1fd  eb0c                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e1ff:
    // 0040e1ff  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0040e204  eb05                   -jmp 0x40e20b
    goto L_0x0040e20b;
  case 0x0040e206:
L_0x0040e206:
    // 0040e206  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0040e20b:
    // 0040e20b  8b0c8508ce4800         -mov ecx, dword ptr [eax*4 + 0x48ce08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4771336) /* 0x48ce08 */ + cpu.eax * 4);
    // 0040e212  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040e217  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e218  ff2568845100           -jmp dword ptr [0x518468]
    return app->dynamic_call(app->getMemory<x86::reg32>(5342312), cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_40e2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e2a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e2a1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e2a3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0040e2a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e2a8  7508                   -jne 0x40e2b2
    if (!cpu.flags.zf)
    {
        goto L_0x0040e2b2;
    }
    // 0040e2aa  e821000000             -call 0x40e2d0
    cpu.esp -= 4;
    sub_40e2d0(app, cpu);
    // 0040e2af  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0040e2b2:
    // 0040e2b2  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0040e2b5  8b4844                 -mov ecx, dword ptr [eax + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0040e2b8  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0040e2bb  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0040e2c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e2c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e2d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e2d1  6800090000             -push 0x900
    app->getMemory<x86::reg32>(cpu.esp-4) = 2304 /*0x900*/;
    cpu.esp -= 4;
    // 0040e2d6  e89f8f0600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040e2db  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040e2dd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e2e0  b940020000             -mov ecx, 0x240
    cpu.ecx = 576 /*0x240*/;
    // 0040e2e5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e2e7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040e2e9  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040e2eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e2ec  8d4244                 -lea eax, [edx + 0x44]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(68) /* 0x44 */);
    // 0040e2ef  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 0040e2f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0040e2f5:
    // 0040e2f5  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040e2f8  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0040e2fa  83c048                 +add eax, 0x48
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040e2fd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040e2fe  75f5                   -jne 0x40e2f5
    if (!cpu.flags.zf)
    {
        goto L_0x0040e2f5;
    }
    // 0040e300  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040e302  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e303  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e310  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e311  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e313  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e315  750d                   -jne 0x40e324
    if (!cpu.flags.zf)
    {
        goto L_0x0040e324;
    }
    // 0040e317  686ccf4800             -push 0x48cf6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771692 /*0x48cf6c*/;
    cpu.esp -= 4;
    // 0040e31c  e8ef680100             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0040e321  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040e324:
    // 0040e324  f6464001               +test byte ptr [esi + 0x40], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(64) /* 0x40 */) & 1 /*0x1*/));
    // 0040e328  741e                   -je 0x40e348
    if (cpu.flags.zf)
    {
        goto L_0x0040e348;
    }
    // 0040e32a  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0040e32d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e32f  7417                   -je 0x40e348
    if (cpu.flags.zf)
    {
        goto L_0x0040e348;
    }
    // 0040e331  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e332  e87d900600             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0040e337  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e33a  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0040e341  c7464000000000         -mov dword ptr [esi + 0x40], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x0040e348:
    // 0040e348  a10cbf4a00             -mov eax, dword ptr [0x4abf0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898572) /* 0x4abf0c */);
    // 0040e34d  89350cbf4a00           -mov dword ptr [0x4abf0c], esi
    app->getMemory<x86::reg32>(x86::reg32(4898572) /* 0x4abf0c */) = cpu.esi;
    // 0040e353  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0040e356  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e357  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e360  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040e366  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e367  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e369  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e36b  743d                   -je 0x40e3aa
    if (cpu.flags.zf)
    {
        goto L_0x0040e3aa;
    }
    // 0040e36d  f6464002               +test byte ptr [esi + 0x40], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(64) /* 0x40 */) & 2 /*0x2*/));
    // 0040e371  7537                   -jne 0x40e3aa
    if (!cpu.flags.zf)
    {
        goto L_0x0040e3aa;
    }
    // 0040e373  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0040e376  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0040e379  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0040e37b  742d                   -je 0x40e3aa
    if (cpu.flags.zf)
    {
        goto L_0x0040e3aa;
    }
    // 0040e37d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e37e  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0040e383  e8b86a0400             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0040e388  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e38b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e38c  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040e390  6860cf4800             -push 0x48cf60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771680 /*0x48cf60*/;
    cpu.esp -= 4;
    // 0040e395  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e396  e85d8a0600             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0040e39b  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0040e39e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040e3a1  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040e3a5  e8a6550500             -call 0x463950
    cpu.esp -= 4;
    sub_463950(app, cpu);
L_0x0040e3aa:
    // 0040e3aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e3ab  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040e3b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e3c0  a104bf4a00             -mov eax, dword ptr [0x4abf04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898564) /* 0x4abf04 */);
    // 0040e3c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e3c7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040e3c9  7501                   -jne 0x40e3cc
    if (!cpu.flags.zf)
    {
        goto L_0x0040e3cc;
    }
    // 0040e3cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040e3cc:
    // 0040e3cc  8b4044                 -mov eax, dword ptr [eax + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0040e3cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e3d1  a304bf4a00             -mov dword ptr [0x4abf04], eax
    app->getMemory<x86::reg32>(x86::reg32(4898564) /* 0x4abf04 */) = cpu.eax;
    // 0040e3d6  7505                   -jne 0x40e3dd
    if (!cpu.flags.zf)
    {
        goto L_0x0040e3dd;
    }
    // 0040e3d8  a308bf4a00             -mov dword ptr [0x4abf08], eax
    app->getMemory<x86::reg32>(x86::reg32(4898568) /* 0x4abf08 */) = cpu.eax;
L_0x0040e3dd:
    // 0040e3dd  e82effffff             -call 0x40e310
    cpu.esp -= 4;
    sub_40e310(app, cpu);
    // 0040e3e2  e829090000             -call 0x40ed10
    cpu.esp -= 4;
    sub_40ed10(app, cpu);
    // 0040e3e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e3e9  7407                   -je 0x40e3f2
    if (cpu.flags.zf)
    {
        goto L_0x0040e3f2;
    }
    // 0040e3eb  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040e3ed  e8ee080000             -call 0x40ece0
    cpu.esp -= 4;
    sub_40ece0(app, cpu);
L_0x0040e3f2:
    // 0040e3f2  a104bf4a00             -mov eax, dword ptr [0x4abf04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898564) /* 0x4abf04 */);
    // 0040e3f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e3f9  741a                   -je 0x40e415
    if (cpu.flags.zf)
    {
        goto L_0x0040e415;
    }
    // 0040e3fb  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040e3fe  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040e401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e402  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e403  68a0cf4800             -push 0x48cfa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771744 /*0x48cfa0*/;
    cpu.esp -= 4;
    // 0040e408  e8aa890600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040e40d  a104bf4a00             -mov eax, dword ptr [0x4abf04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898564) /* 0x4abf04 */);
    // 0040e412  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0040e415:
    // 0040e415  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e420  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040e422  740d                   -je 0x40e431
    if (cpu.flags.zf)
    {
        goto L_0x0040e431;
    }
    // 0040e424  6683b98a02000000       +cmp word ptr [ecx + 0x28a], 0
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
    // 0040e42c  7f03                   -jg 0x40e431
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040e431;
    }
    // 0040e42e  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0040e430  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040e431:
    // 0040e431  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0040e433  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e440  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040e442  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e443  7432                   -je 0x40e477
    if (cpu.flags.zf)
    {
        goto L_0x0040e477;
    }
    // 0040e445  8b5144                 -mov edx, dword ptr [ecx + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0040e448  8d7144                 -lea esi, [ecx + 0x44]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0040e44b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040e44d  7428                   -je 0x40e477
    if (cpu.flags.zf)
    {
        goto L_0x0040e477;
    }
L_0x0040e44f:
    // 0040e44f  8b4a34                 -mov ecx, dword ptr [edx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 0040e452  e8c9ffffff             -call 0x40e420
    cpu.esp -= 4;
    sub_40e420(app, cpu);
    // 0040e457  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040e459  750c                   -jne 0x40e467
    if (!cpu.flags.zf)
    {
        goto L_0x0040e467;
    }
    // 0040e45b  8b4244                 -mov eax, dword ptr [edx + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
    // 0040e45e  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0040e460  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0040e462  e8a9feffff             -call 0x40e310
    cpu.esp -= 4;
    sub_40e310(app, cpu);
L_0x0040e467:
    // 0040e467  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0040e469  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e46b  740a                   -je 0x40e477
    if (cpu.flags.zf)
    {
        goto L_0x0040e477;
    }
    // 0040e46d  8b5644                 -mov edx, dword ptr [esi + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0040e470  83c644                 -add esi, 0x44
    (cpu.esi) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0040e473  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040e475  75d8                   -jne 0x40e44f
    if (!cpu.flags.zf)
    {
        goto L_0x0040e44f;
    }
L_0x0040e477:
    // 0040e477  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e478  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e480  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040e482  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e483  7424                   -je 0x40e4a9
    if (cpu.flags.zf)
    {
        goto L_0x0040e4a9;
    }
    // 0040e485  8d7144                 -lea esi, [ecx + 0x44]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0040e488  8b4944                 -mov ecx, dword ptr [ecx + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0040e48b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040e48d  741a                   -je 0x40e4a9
    if (cpu.flags.zf)
    {
        goto L_0x0040e4a9;
    }
L_0x0040e48f:
    // 0040e48f  8b4144                 -mov eax, dword ptr [ecx + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0040e492  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0040e494  e877feffff             -call 0x40e310
    cpu.esp -= 4;
    sub_40e310(app, cpu);
    // 0040e499  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0040e49b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e49d  740a                   -je 0x40e4a9
    if (cpu.flags.zf)
    {
        goto L_0x0040e4a9;
    }
    // 0040e49f  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0040e4a2  83c644                 -add esi, 0x44
    (cpu.esi) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0040e4a5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040e4a7  75e6                   -jne 0x40e48f
    if (!cpu.flags.zf)
    {
        goto L_0x0040e48f;
    }
L_0x0040e4a9:
    // 0040e4a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e4aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e4b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e4b1  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040e4b3  2bd1                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0040e4b5:
    // 0040e4b5  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0040e4b7  88040a                 -mov byte ptr [edx + ecx], al
    app->getMemory<x86::reg8>(cpu.edx + cpu.ecx * 1) = cpu.al;
    // 0040e4ba  41                     -inc ecx
    (cpu.ecx)++;
    // 0040e4bb  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040e4bd  75f6                   -jne 0x40e4b5
    if (!cpu.flags.zf)
    {
        goto L_0x0040e4b5;
    }
    // 0040e4bf  b22e                   -mov dl, 0x2e
    cpu.dl = 46 /*0x2e*/;
    // 0040e4c1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040e4c3  e858f9ffff             -call 0x40de20
    cpu.esp -= 4;
    sub_40de20(app, cpu);
    // 0040e4c8  83f8ff                 +cmp eax, -1
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
    // 0040e4cb  7404                   -je 0x40e4d1
    if (cpu.flags.zf)
    {
        goto L_0x0040e4d1;
    }
    // 0040e4cd  c6043000               -mov byte ptr [eax + esi], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.esi * 1) = 0 /*0x0*/;
L_0x0040e4d1:
    // 0040e4d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e4d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e4e0  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040e4e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e4e7  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040e4e9  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040e4ed  e8beffffff             -call 0x40e4b0
    cpu.esp -= 4;
    sub_40e4b0(app, cpu);
    // 0040e4f2  8b0d14bf4a00           -mov ecx, dword ptr [0x4abf14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898580) /* 0x4abf14 */);
    // 0040e4f8  ba04bf4a00             -mov edx, 0x4abf04
    cpu.edx = 4898564 /*0x4abf04*/;
    // 0040e4fd  41                     -inc ecx
    (cpu.ecx)++;
    // 0040e4fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e4ff  890d14bf4a00           -mov dword ptr [0x4abf14], ecx
    app->getMemory<x86::reg32>(x86::reg32(4898580) /* 0x4abf14 */) = cpu.ecx;
    // 0040e505  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040e509  e822000000             -call 0x40e530
    cpu.esp -= 4;
    sub_40e530(app, cpu);
    // 0040e50e  8b0d08bf4a00           -mov ecx, dword ptr [0x4abf08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898568) /* 0x4abf08 */);
    // 0040e514  f7d8                   +neg eax
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
    // 0040e516  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0040e518  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e519  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0040e51b  23c1                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e51d  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040e523  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e530  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e531  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e532  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e533  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040e535  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0040e537  e894000000             -call 0x40e5d0
    cpu.esp -= 4;
    sub_40e5d0(app, cpu);
    // 0040e53c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040e53e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e540  7517                   -jne 0x40e559
    if (!cpu.flags.zf)
    {
        goto L_0x0040e559;
    }
    // 0040e542  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e543  68b8cf4800             -push 0x48cfb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771768 /*0x48cfb8*/;
    cpu.esp -= 4;
    // 0040e548  e86a880600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040e54d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040e550  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040e553  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e554  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e555  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e556  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0040e559:
    // 0040e559  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0040e55b  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040e55d  e8be000000             -call 0x40e620
    cpu.esp -= 4;
    sub_40e620(app, cpu);
    // 0040e562  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e564  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040e568  751b                   -jne 0x40e585
    if (!cpu.flags.zf)
    {
        goto L_0x0040e585;
    }
    // 0040e56a  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040e56c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0040e56e  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0040e571  c7464400000000         -mov dword ptr [esi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0040e578  e883000000             -call 0x40e600
    cpu.esp -= 4;
    sub_40e600(app, cpu);
    // 0040e57d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e57f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e580  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e581  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e582  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0040e585:
    // 0040e585  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e587  7417                   -je 0x40e5a0
    if (cpu.flags.zf)
    {
        goto L_0x0040e5a0;
    }
    // 0040e589  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0040e58f  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040e595  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0040e598  8b8018030000           -mov eax, dword ptr [eax + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 0040e59e  eb12                   -jmp 0x40e5b2
    goto L_0x0040e5b2;
L_0x0040e5a0:
    // 0040e5a0  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0040e5a6  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040e5a8  8b8218030000           -mov eax, dword ptr [edx + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(792) /* 0x318 */);
    // 0040e5ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e5b0  740d                   -je 0x40e5bf
    if (cpu.flags.zf)
    {
        goto L_0x0040e5bf;
    }
L_0x0040e5b2:
    // 0040e5b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e5b4  7409                   -je 0x40e5bf
    if (cpu.flags.zf)
    {
        goto L_0x0040e5bf;
    }
    // 0040e5b6  8a4806                 -mov cl, byte ptr [eax + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0040e5b9  83c901                 -or ecx, 1
    cpu.ecx |= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0040e5bc  884806                 -mov byte ptr [eax + 6], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = cpu.cl;
L_0x0040e5bf:
    // 0040e5bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e5c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e5c1  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040e5c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e5c5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40e5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e5d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e5d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e5d2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040e5d6  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e5d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e5d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e5da  e821680400             -call 0x454e00
    cpu.esp -= 4;
    sub_454e00(app, cpu);
    // 0040e5df  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040e5e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e5e4  7503                   -jne 0x40e5e9
    if (!cpu.flags.zf)
    {
        goto L_0x0040e5e9;
    }
    // 0040e5e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e5e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e5e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040e5e9:
    // 0040e5e9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040e5ed  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e5ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e5f0  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040e5f2  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040e5f4  e817faffff             -call 0x40e010
    cpu.esp -= 4;
    sub_40e010(app, cpu);
    // 0040e5f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e5fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e5fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e600  833900                 +cmp dword ptr [ecx], 0
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
    // 0040e603  7506                   -jne 0x40e60b
    if (!cpu.flags.zf)
    {
        goto L_0x0040e60b;
    }
    // 0040e605  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0040e607  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0040e60a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040e60b:
    // 0040e60b  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0040e60e  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0040e611  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0040e614  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e620  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e621  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e623  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e625  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e626  741b                   -je 0x40e643
    if (cpu.flags.zf)
    {
        goto L_0x0040e643;
    }
    // 0040e628  8d7a08                 -lea edi, [edx + 8]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
L_0x0040e62b:
    // 0040e62b  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0040e62e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e62f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e630  e87b650700             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0040e635  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040e638  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e63a  740c                   -je 0x40e648
    if (cpu.flags.zf)
    {
        goto L_0x0040e648;
    }
    // 0040e63c  8b7644                 -mov esi, dword ptr [esi + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0040e63f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e641  75e8                   -jne 0x40e62b
    if (!cpu.flags.zf)
    {
        goto L_0x0040e62b;
    }
L_0x0040e643:
    // 0040e643  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e644  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e646  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e647  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040e648:
    // 0040e648  68dccf4800             -push 0x48cfdc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771804 /*0x48cfdc*/;
    cpu.esp -= 4;
    // 0040e64d  e865870600             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0040e652  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e655  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040e658  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e659  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e65a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e660  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040e666  8d542400               -lea edx, [esp]
    cpu.edx = x86::reg32(cpu.esp);
    // 0040e66a  e841feffff             -call 0x40e4b0
    cpu.esp -= 4;
    sub_40e4b0(app, cpu);
    // 0040e66f  a118bf4a00             -mov eax, dword ptr [0x4abf18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898584) /* 0x4abf18 */);
    // 0040e674  40                     -inc eax
    (cpu.eax)++;
    // 0040e675  a318bf4a00             -mov dword ptr [0x4abf18], eax
    app->getMemory<x86::reg32>(x86::reg32(4898584) /* 0x4abf18 */) = cpu.eax;
    // 0040e67a  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 0040e67e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e67f  e83c670400             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0040e684  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0040e68a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e690  a104bf4a00             -mov eax, dword ptr [0x4abf04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898564) /* 0x4abf04 */);
    // 0040e695  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e6a0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040e6a4  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0040e6a7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040e6ab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e6ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e6ad  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0040e6af  895128                 -mov dword ptr [ecx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0040e6b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e6b3  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040e6b7  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e6bb  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0040e6bc  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040e6be  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040e6c2  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0040e6c5  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0040e6c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e6c9  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0040e6cc  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0040e6cf  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040e6d1  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0040e6d2  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040e6d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e6d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e6d6  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0040e6d9  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e6dd  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0040e6e0  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40e6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e6f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e6f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e6f2  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040e6f4  8b0d10bf4a00           -mov ecx, dword ptr [0x4abf10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898576) /* 0x4abf10 */);
    // 0040e6fa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040e6fc  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040e6fe  7507                   -jne 0x40e707
    if (!cpu.flags.zf)
    {
        goto L_0x0040e707;
    }
    // 0040e700  e82b000000             -call 0x40e730
    cpu.esp -= 4;
    sub_40e730(app, cpu);
    // 0040e705  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0040e707:
    // 0040e707  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e70b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040e70f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e711  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e712  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e716  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e717  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e71b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e71c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e71d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e71e  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040e720  e87bffffff             -call 0x40e6a0
    cpu.esp -= 4;
    sub_40e6a0(app, cpu);
    // 0040e725  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040e727  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e728  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e729  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40e730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e730  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e731  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 0040e733  e8428b0600             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0040e738  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040e73a  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 0040e73f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e741  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040e743  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e746  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040e748  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040e74a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e74b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40e750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e750  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e751  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e753  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e754  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040e756  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e758  0f8494000000           -je 0x40e7f2
    if (cpu.flags.zf)
    {
        goto L_0x0040e7f2;
    }
    // 0040e75e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e75f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e760  e838960600             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 0040e765  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e769  8b15a4be4a00           -mov edx, dword ptr [0x4abea4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898468) /* 0x4abea4 */);
    // 0040e76f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e772  3bca                   +cmp ecx, edx
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
    // 0040e774  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e778  7519                   -jne 0x40e793
    if (!cpu.flags.zf)
    {
        goto L_0x0040e793;
    }
    // 0040e77a  3b15a8be4a00           +cmp edx, dword ptr [0x4abea8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4898472) /* 0x4abea8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e780  7511                   -jne 0x40e793
    if (!cpu.flags.zf)
    {
        goto L_0x0040e793;
    }
    // 0040e782  803d60ce480001         +cmp byte ptr [0x48ce60], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4771424) /* 0x48ce60 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040e789  7408                   -je 0x40e793
    if (cpu.flags.zf)
    {
        goto L_0x0040e793;
    }
    // 0040e78b  3905ccbe4a00           +cmp dword ptr [0x4abecc], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4898508) /* 0x4abecc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e791  741f                   -je 0x40e7b2
    if (cpu.flags.zf)
    {
        goto L_0x0040e7b2;
    }
L_0x0040e793:
    // 0040e793  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040e797  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e798  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0040e79a  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0040e79c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e79d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e79e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e79f  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040e7a1  b9a4be4a00             -mov ecx, 0x4abea4
    cpu.ecx = 4898468 /*0x4abea4*/;
    // 0040e7a6  e8f5feffff             -call 0x40e6a0
    cpu.esp -= 4;
    sub_40e6a0(app, cpu);
    // 0040e7ab  c60560ce480000         -mov byte ptr [0x48ce60], 0
    app->getMemory<x86::reg8>(x86::reg32(4771424) /* 0x48ce60 */) = 0 /*0x0*/;
L_0x0040e7b2:
    // 0040e7b2  a1d0be4a00             -mov eax, dword ptr [0x4abed0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898512) /* 0x4abed0 */);
    // 0040e7b7  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040e7bb  8b15b0be4a00           -mov edx, dword ptr [0x4abeb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898480) /* 0x4abeb0 */);
    // 0040e7c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e7c2  a1acbe4a00             -mov eax, dword ptr [0x4abeac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898476) /* 0x4abeac */);
    // 0040e7c7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e7c8  8b0db8be4a00           -mov ecx, dword ptr [0x4abeb8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898488) /* 0x4abeb8 */);
    // 0040e7ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e7cf  8b15ccbe4a00           -mov edx, dword ptr [0x4abecc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898508) /* 0x4abecc */);
    // 0040e7d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e7d6  a1b4be4a00             -mov eax, dword ptr [0x4abeb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898484) /* 0x4abeb4 */);
    // 0040e7db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e7dc  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040e7e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e7e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e7e2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e7e3  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040e7e5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040e7e7  e8c4000000             -call 0x40e8b0
    cpu.esp -= 4;
    sub_40e8b0(app, cpu);
    // 0040e7ec  a3c8be4a00             -mov dword ptr [0x4abec8], eax
    app->getMemory<x86::reg32>(x86::reg32(4898504) /* 0x4abec8 */) = cpu.eax;
    // 0040e7f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040e7f2:
    // 0040e7f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e7f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e7f4  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40e800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e800  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e801  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040e803  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e804  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040e806  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040e808  7507                   -jne 0x40e811
    if (!cpu.flags.zf)
    {
        goto L_0x0040e811;
    }
    // 0040e80a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e80b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e80d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e80e  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x0040e811:
    // 0040e811  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e812  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e813  e885950600             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 0040e818  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e81c  8b15d4be4a00           -mov edx, dword ptr [0x4abed4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898516) /* 0x4abed4 */);
    // 0040e822  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e825  3bca                   +cmp ecx, edx
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
    // 0040e827  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e82b  7519                   -jne 0x40e846
    if (!cpu.flags.zf)
    {
        goto L_0x0040e846;
    }
    // 0040e82d  3b15d8be4a00           +cmp edx, dword ptr [0x4abed8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4898520) /* 0x4abed8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e833  7511                   -jne 0x40e846
    if (!cpu.flags.zf)
    {
        goto L_0x0040e846;
    }
    // 0040e835  803d61ce480001         +cmp byte ptr [0x48ce61], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4771425) /* 0x48ce61 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040e83c  7408                   -je 0x40e846
    if (cpu.flags.zf)
    {
        goto L_0x0040e846;
    }
    // 0040e83e  3905fcbe4a00           +cmp dword ptr [0x4abefc], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4898556) /* 0x4abefc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e844  741f                   -je 0x40e865
    if (cpu.flags.zf)
    {
        goto L_0x0040e865;
    }
L_0x0040e846:
    // 0040e846  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040e84a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e84b  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0040e84d  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0040e84f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e850  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e851  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e852  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040e854  b9d4be4a00             -mov ecx, 0x4abed4
    cpu.ecx = 4898516 /*0x4abed4*/;
    // 0040e859  e842feffff             -call 0x40e6a0
    cpu.esp -= 4;
    sub_40e6a0(app, cpu);
    // 0040e85e  c60561ce480000         -mov byte ptr [0x48ce61], 0
    app->getMemory<x86::reg8>(x86::reg32(4771425) /* 0x48ce61 */) = 0 /*0x0*/;
L_0x0040e865:
    // 0040e865  a100bf4a00             -mov eax, dword ptr [0x4abf00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898560) /* 0x4abf00 */);
    // 0040e86a  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040e86e  8b15e0be4a00           -mov edx, dword ptr [0x4abee0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898528) /* 0x4abee0 */);
    // 0040e874  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e875  a1dcbe4a00             -mov eax, dword ptr [0x4abedc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898524) /* 0x4abedc */);
    // 0040e87a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e87b  8b0de8be4a00           -mov ecx, dword ptr [0x4abee8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898536) /* 0x4abee8 */);
    // 0040e881  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e882  8b15fcbe4a00           -mov edx, dword ptr [0x4abefc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4898556) /* 0x4abefc */);
    // 0040e888  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e889  a1e4be4a00             -mov eax, dword ptr [0x4abee4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898532) /* 0x4abee4 */);
    // 0040e88e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e88f  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040e893  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e894  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e895  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e896  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040e898  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040e89a  e811000000             -call 0x40e8b0
    cpu.esp -= 4;
    sub_40e8b0(app, cpu);
    // 0040e89f  a3f8be4a00             -mov dword ptr [0x4abef8], eax
    app->getMemory<x86::reg32>(x86::reg32(4898552) /* 0x4abef8 */) = cpu.eax;
    // 0040e8a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e8a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e8a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e8a7  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40e8b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e8b0  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0040e8b3  d9051cbf4a00           -fld dword ptr [0x4abf1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4898588) /* 0x4abf1c */)));
    // 0040e8b9  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0040e8bf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e8c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e8c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e8c2  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0040e8c6  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0040e8c8  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040e8cc  0faff1                 -imul esi, ecx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0040e8cf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040e8d1  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0040e8d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040e8d5  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0040e8d9  896c2434               -mov dword ptr [esp + 0x34], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebp;
    // 0040e8dd  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0040e8e1  7a3c                   -jp 0x40e91f
    if (cpu.flags.pf)
    {
        goto L_0x0040e91f;
    }
    // 0040e8e3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e8e5  8b1538165200           -mov edx, dword ptr [0x521638]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5379640) /* 0x521638 */);
    // 0040e8eb  66a136165200           -mov ax, word ptr [0x521636]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */);
    // 0040e8f1  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040e8f7  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0040e8fb  db442450               -fild dword ptr [esp + 0x50]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */))));
    // 0040e8ff  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0040e903  d80db0754800           -fmul dword ptr [0x4875b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748720) /* 0x4875b0 */));
    // 0040e909  d91d1cbf4a00           -fstp dword ptr [0x4abf1c]
    app->getMemory<float>(x86::reg32(4898588) /* 0x4abf1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e90f  db442450               -fild dword ptr [esp + 0x50]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */))));
    // 0040e913  d80dac754800           -fmul dword ptr [0x4875ac]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748716) /* 0x4875ac */));
    // 0040e919  d91d20bf4a00           -fstp dword ptr [0x4abf20]
    app->getMemory<float>(x86::reg32(4898592) /* 0x4abf20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040e91f:
    // 0040e91f  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e921  3beb                   +cmp ebp, ebx
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
    // 0040e923  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0040e927  0f84e7010000           -je 0x40eb14
    if (cpu.flags.zf)
    {
        goto L_0x0040eb14;
    }
    // 0040e92d  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0040e931  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0040e935  83e040                 +and eax, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(64 /*0x40*/))));
    // 0040e938  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0040e93c  740e                   -je 0x40e94c
    if (cpu.flags.zf)
    {
        goto L_0x0040e94c;
    }
    // 0040e93e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e93f  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040e941  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0040e943  e8f8010000             -call 0x40eb40
    cpu.esp -= 4;
    sub_40eb40(app, cpu);
    // 0040e948  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x0040e94c:
    // 0040e94c  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0040e950  895c2450               -mov dword ptr [esp + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 0040e954  3bc3                   +cmp eax, ebx
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
    // 0040e956  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0040e95a  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0040e95e  0f8eb0010000           -jle 0x40eb14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040eb14;
    }
    // 0040e964  8b7c2464               -mov edi, dword ptr [esp + 0x64]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0040e968  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0040e96c  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0040e970  eb02                   -jmp 0x40e974
    goto L_0x0040e974;
L_0x0040e972:
    // 0040e972  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0040e974:
    // 0040e974  668b7500               -mov si, word ptr [ebp]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebp);
    // 0040e978  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040e97c  0f8476010000           -je 0x40eaf8
    if (cpu.flags.zf)
    {
        goto L_0x0040eaf8;
    }
    // 0040e982  663bf3                 +cmp si, bx
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040e985  0f8489010000           -je 0x40eb14
    if (cpu.flags.zf)
    {
        goto L_0x0040eb14;
    }
    // 0040e98b  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0040e98f  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0040e991  83e320                 -and ebx, 0x20
    cpu.ebx &= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040e994  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040e996  e8a5f5ffff             -call 0x40df40
    cpu.esp -= 4;
    sub_40df40(app, cpu);
    // 0040e99b  3b442410               +cmp eax, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e99f  7d0c                   -jge 0x40e9ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040e9ad;
    }
    // 0040e9a1  6683fe0a               +cmp si, 0xa
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10 /*0xa*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040e9a5  7406                   -je 0x40e9ad
    if (cpu.flags.zf)
    {
        goto L_0x0040e9ad;
    }
    // 0040e9a7  6683fe40               +cmp si, 0x40
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64 /*0x40*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040e9ab  7559                   -jne 0x40ea06
    if (!cpu.flags.zf)
    {
        goto L_0x0040ea06;
    }
L_0x0040e9ad:
    // 0040e9ad  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040e9b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e9b3  7414                   -je 0x40e9c9
    if (cpu.flags.zf)
    {
        goto L_0x0040e9c9;
    }
    // 0040e9b5  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0040e9b9  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040e9bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040e9be  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0040e9c0  e87b010000             -call 0x40eb40
    cpu.esp -= 4;
    sub_40eb40(app, cpu);
    // 0040e9c5  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x0040e9c9:
    // 0040e9c9  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040e9cd  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040e9d1  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040e9d5  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0040e9d9  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040e9dd  40                     -inc eax
    (cpu.eax)++;
    // 0040e9de  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040e9e0  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0040e9e4  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0040e9e8  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0040e9ec  3bc1                   +cmp eax, ecx
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
    // 0040e9ee  c744245000000000       -mov dword ptr [esp + 0x50], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 0040e9f6  0f8d24010000           -jge 0x40eb20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040eb20;
    }
    // 0040e9fc  6683fe40               +cmp si, 0x40
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64 /*0x40*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040ea00  0f841a010000           -je 0x40eb20
    if (cpu.flags.zf)
    {
        goto L_0x0040eb20;
    }
L_0x0040ea06:
    // 0040ea06  6683fe0a               +cmp si, 0xa
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10 /*0xa*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040ea0a  0f84e8000000           -je 0x40eaf8
    if (cpu.flags.zf)
    {
        goto L_0x0040eaf8;
    }
    // 0040ea10  6683fe22               +cmp si, 0x22
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040ea14  0f84de000000           -je 0x40eaf8
    if (cpu.flags.zf)
    {
        goto L_0x0040eaf8;
    }
    // 0040ea1a  f644246802             +test byte ptr [esp + 0x68], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(104) /* 0x68 */) & 2 /*0x2*/));
    // 0040ea1f  0f85ab000000           -jne 0x40ead0
    if (!cpu.flags.zf)
    {
        goto L_0x0040ead0;
    }
    // 0040ea25  66817d00cf00           +cmp word ptr [ebp], 0xcf
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(207 /*0xcf*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040ea2b  0f849f000000           -je 0x40ead0
    if (cpu.flags.zf)
    {
        goto L_0x0040ead0;
    }
    // 0040ea31  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0040ea35  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040ea39  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ea3b  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0040ea3f  db442464               -fild dword ptr [esp + 0x64]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */))));
    // 0040ea43  d80d1cbf4a00           -fmul dword ptr [0x4abf1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4898588) /* 0x4abf1c */));
    // 0040ea49  da442430               -fiadd dword ptr [esp + 0x30]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0040ea4d  e83e830600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040ea52  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0040ea56  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0040ea58  d80d20bf4a00           -fmul dword ptr [0x4abf20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4898592) /* 0x4abf20 */));
    // 0040ea5e  da44244c               -fiadd dword ptr [esp + 0x4c]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */)));
    // 0040ea62  e829830600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0040ea67  6683fe07               +cmp si, 7
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(7 /*0x7*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040ea6b  751f                   -jne 0x40ea8c
    if (!cpu.flags.zf)
    {
        goto L_0x0040ea8c;
    }
    // 0040ea6d  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040ea71  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040ea73  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0040ea75  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0040ea79  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0040ea7c  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0040ea80  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0040ea83  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0040ea87  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0040ea8a  eb30                   -jmp 0x40eabc
    goto L_0x0040eabc;
L_0x0040ea8c:
    // 0040ea8c  6683fe08               +cmp si, 8
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040ea90  752f                   -jne 0x40eac1
    if (!cpu.flags.zf)
    {
        goto L_0x0040eac1;
    }
    // 0040ea92  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040ea94  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0040ea96  894c2438               -mov dword ptr [esp + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0040ea9a  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040ea9d  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 0040eaa1  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0040eaa4  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 0040eaa8  b90000803f             -mov ecx, 0x3f800000
    cpu.ecx = 1065353216 /*0x3f800000*/;
    // 0040eaad  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0040eab0  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0040eab3  89542444               -mov dword ptr [esp + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0040eab7  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0040eaba  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
L_0x0040eabc:
    // 0040eabc  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
L_0x0040eac1:
    // 0040eac1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040eac2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040eac3  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0040eac5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040eac7  e8445a0000             -call 0x414510
    cpu.esp -= 4;
    sub_414510(app, cpu);
    // 0040eacc  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0040ead0:
    // 0040ead0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040ead2  e8d9590000             -call 0x4144b0
    cpu.esp -= 4;
    sub_4144b0(app, cpu);
    // 0040ead7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040ead9  7e04                   -jle 0x40eadf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040eadf;
    }
    // 0040eadb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040eadd  7405                   -je 0x40eae4
    if (cpu.flags.zf)
    {
        goto L_0x0040eae4;
    }
L_0x0040eadf:
    // 0040eadf  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
L_0x0040eae4:
    // 0040eae4  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0040eae8  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040eaec  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040eaee  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040eaf0  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0040eaf4  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x0040eaf8:
    // 0040eaf8  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040eafc  8b4c2454               -mov ecx, dword ptr [esp + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0040eb00  40                     -inc eax
    (cpu.eax)++;
    // 0040eb01  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040eb04  3bc1                   +cmp eax, ecx
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
    // 0040eb06  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0040eb0a  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0040eb0e  0f8c5efeffff           -jl 0x40e972
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040e972;
    }
L_0x0040eb14:
    // 0040eb14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb17  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040eb19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb1a  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0040eb1d  c22000                 -ret 0x20
    cpu.esp += 4+32 /*0x20*/;
    return;
L_0x0040eb20:
    // 0040eb20  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040eb24  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040eb28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb2b  8d0448                 -lea eax, [eax + ecx*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 0040eb2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb2f  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0040eb32  c22000                 -ret 0x20
    cpu.esp += 4+32 /*0x20*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40eb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040eb40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040eb41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040eb42  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040eb46  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040eb47  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040eb48  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040eb4a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040eb4c  7e3f                   -jle 0x40eb8d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040eb8d;
    }
    // 0040eb4e  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x0040eb50:
    // 0040eb50  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 0040eb53  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040eb57  742d                   -je 0x40eb86
    if (cpu.flags.zf)
    {
        goto L_0x0040eb86;
    }
    // 0040eb59  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040eb5b  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040eb5d  e8def3ffff             -call 0x40df40
    cpu.esp -= 4;
    sub_40df40(app, cpu);
    // 0040eb62  3bc7                   +cmp eax, edi
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
    // 0040eb64  7f27                   -jg 0x40eb8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040eb8d;
    }
    // 0040eb66  6683fe0a               +cmp si, 0xa
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10 /*0xa*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040eb6a  7421                   -je 0x40eb8d
    if (cpu.flags.zf)
    {
        goto L_0x0040eb8d;
    }
    // 0040eb6c  6683fe40               +cmp si, 0x40
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64 /*0x40*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040eb70  741b                   -je 0x40eb8d
    if (cpu.flags.zf)
    {
        goto L_0x0040eb8d;
    }
    // 0040eb72  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 0040eb75  7416                   -je 0x40eb8d
    if (cpu.flags.zf)
    {
        goto L_0x0040eb8d;
    }
    // 0040eb77  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040eb79  e832590000             -call 0x4144b0
    cpu.esp -= 4;
    sub_4144b0(app, cpu);
    // 0040eb7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040eb80  7502                   -jne 0x40eb84
    if (!cpu.flags.zf)
    {
        goto L_0x0040eb84;
    }
    // 0040eb82  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0040eb84:
    // 0040eb84  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040eb86:
    // 0040eb86  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040eb89  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040eb8b  7fc3                   -jg 0x40eb50
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040eb50;
    }
L_0x0040eb8d:
    // 0040eb8d  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0040eb8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb90  2bc5                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0040eb92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb93  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0040eb94  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040eb96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb97  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0040eb99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eb9a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40eba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040eba0  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040eba2  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040eba6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040eba7  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040ebab  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ebac  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040ebb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ebb1  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040ebb5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ebb6  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040ebb8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ebb9  b904bf4a00             -mov ecx, 0x4abf04
    cpu.ecx = 4898564 /*0x4abf04*/;
    // 0040ebbe  e80d000000             -call 0x40ebd0
    cpu.esp -= 4;
    sub_40ebd0(app, cpu);
    // 0040ebc3  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_40ebd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ebd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040ebd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ebd2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040ebd4  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040ebd6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040ebd8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040ebda  0f8481000000           -je 0x40ec61
    if (cpu.flags.zf)
    {
        goto L_0x0040ec61;
    }
    // 0040ebe0  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0040ebe3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040ebe7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040ebe9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040ebea  7511                   -jne 0x40ebfd
    if (!cpu.flags.zf)
    {
        goto L_0x0040ebfd;
    }
    // 0040ebec  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040ebf0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040ebf2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ebf3  e878000000             -call 0x40ec70
    cpu.esp -= 4;
    sub_40ec70(app, cpu);
    // 0040ebf8  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0040ebfb  eb26                   -jmp 0x40ec23
    goto L_0x0040ec23;
L_0x0040ebfd:
    // 0040ebfd  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040ebff  3bd7                   +cmp edx, edi
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
    // 0040ec01  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040ec05  7509                   -jne 0x40ec10
    if (!cpu.flags.zf)
    {
        goto L_0x0040ec10;
    }
    // 0040ec07  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ec08  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0040ec0b  3bfd                   +cmp edi, ebp
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
    // 0040ec0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec0e  7413                   -je 0x40ec23
    if (cpu.flags.zf)
    {
        goto L_0x0040ec23;
    }
L_0x0040ec10:
    // 0040ec10  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040ec12  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0040ec14  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0040ec16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040ec17  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ec18  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040ec1a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ec1b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040ec1e  e87dfaffff             -call 0x40e6a0
    cpu.esp -= 4;
    sub_40e6a0(app, cpu);
L_0x0040ec23:
    // 0040ec23  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040ec27  8b760c                 -mov esi, dword ptr [esi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0040ec2a  f7d8                   +neg eax
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
    // 0040ec2c  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0040ec2f  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0040ec32  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0040ec34  83e002                 -and eax, 2
    cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040ec37  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0040ec3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ec3b  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040ec3f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ec40  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0040ec43  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ec44  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0040ec47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ec48  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0040ec4b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ec4c  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0040ec4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ec50  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040ec54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ec55  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ec56  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040ec58  e853fcffff             -call 0x40e8b0
    cpu.esp -= 4;
    sub_40e8b0(app, cpu);
    // 0040ec5d  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0040ec60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040ec61:
    // 0040ec61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec63  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

}
