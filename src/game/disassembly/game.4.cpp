#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_41a390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a390  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041a393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a394  c744240400000000       -mov dword ptr [esp + 4], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0041a39c  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0041a3a4  c744240c00000000       -mov dword ptr [esp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0041a3ac  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041a3ae  e8fd580000             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 0041a3b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041a3b5  7e32                   -jle 0x41a3e9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041a3e9;
    }
L_0x0041a3b7:
    // 0041a3b7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041a3b9  e8425d0000             -call 0x420100
    cpu.esp -= 4;
    sub_420100(app, cpu);
    // 0041a3be  8b4050                 -mov eax, dword ptr [eax + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0041a3c1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0041a3c3:
    // 0041a3c3  3b048df8014900         +cmp eax, dword ptr [ecx*4 + 0x4901f8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4784632) /* 0x4901f8 */ + cpu.ecx * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a3ca  7441                   -je 0x41a40d
    if (cpu.flags.zf)
    {
        goto L_0x0041a40d;
    }
    // 0041a3cc  41                     -inc ecx
    (cpu.ecx)++;
    // 0041a3cd  83f903                 +cmp ecx, 3
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
    // 0041a3d0  7cf1                   -jl 0x41a3c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041a3c3;
    }
    // 0041a3d2  6894084900             -push 0x490894
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786324 /*0x490894*/;
    cpu.esp -= 4;
    // 0041a3d7  e834a80000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041a3dc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041a3df:
    // 0041a3df  46                     -inc esi
    (cpu.esi)++;
    // 0041a3e0  e8cb580000             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 0041a3e5  3bf0                   +cmp esi, eax
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
    // 0041a3e7  7cce                   -jl 0x41a3b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041a3b7;
    }
L_0x0041a3e9:
    // 0041a3e9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041a3eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041a3ec:
    // 0041a3ec  8b4c8400               -mov ecx, dword ptr [esp + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 4);
    // 0041a3f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041a3f2  7415                   -je 0x41a409
    if (cpu.flags.zf)
    {
        goto L_0x0041a409;
    }
    // 0041a3f4  40                     -inc eax
    (cpu.eax)++;
    // 0041a3f5  83f803                 +cmp eax, 3
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
    // 0041a3f8  7cf2                   -jl 0x41a3ec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041a3ec;
    }
    // 0041a3fa  6868084900             -push 0x490868
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786280 /*0x490868*/;
    cpu.esp -= 4;
    // 0041a3ff  e80ca80000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041a404  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041a407  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0041a409:
    // 0041a409  83c40c                 +add esp, 0xc
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
    // 0041a40c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041a40d:
    // 0041a40d  c7448c0401000000       -mov dword ptr [esp + ecx*4 + 4], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = 1 /*0x1*/;
    // 0041a415  ebc8                   -jmp 0x41a3df
    goto L_0x0041a3df;
}

/* align: skip  */
void Application::sub_41a420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a420  e90b000000             -jmp 0x41a430
    return sub_41a430(app, cpu);
}

/* align: skip  */
void Application::sub_41a430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a430  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a431  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a432  b91d000000             -mov ecx, 0x1d
    cpu.ecx = 29 /*0x1d*/;
    // 0041a437  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041a439  e8b2adffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041a43e  8b7828                 -mov edi, dword ptr [eax + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041a441  b91e000000             -mov ecx, 0x1e
    cpu.ecx = 30 /*0x1e*/;
    // 0041a446  e8a5adffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041a44b  8b8fd0000000           -mov ecx, dword ptr [edi + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */);
    // 0041a451  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041a454  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041a456  7419                   -je 0x41a471
    if (cpu.flags.zf)
    {
        goto L_0x0041a471;
    }
    // 0041a458  8339ff                 +cmp dword ptr [ecx], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a45b  740a                   -je 0x41a467
    if (cpu.flags.zf)
    {
        goto L_0x0041a467;
    }
L_0x0041a45d:
    // 0041a45d  8b54b104               -mov edx, dword ptr [ecx + esi*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4);
    // 0041a461  46                     -inc esi
    (cpu.esi)++;
    // 0041a462  83faff                 +cmp edx, -1
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
    // 0041a465  75f6                   -jne 0x41a45d
    if (!cpu.flags.zf)
    {
        goto L_0x0041a45d;
    }
L_0x0041a467:
    // 0041a467  8b80c4000000           -mov eax, dword ptr [eax + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 0041a46d  3bc6                   +cmp eax, esi
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
    // 0041a46f  7c03                   -jl 0x41a474
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041a474;
    }
L_0x0041a471:
    // 0041a471  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0041a474:
    // 0041a474  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a475  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a476  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41a480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041a480  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041a485  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a488  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041a489  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041a48a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a48b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a48c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041a48e  8d9840050000           -lea ebx, [eax + 0x540]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1344) /* 0x540 */);
    // 0041a494  8b7728                 -mov esi, dword ptr [edi + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041a497  e864c4ffff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 0041a49c  e85fc4ffff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 0041a4a1  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041a4a5  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0041a4a7  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041a4ab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041a4ac  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041a4b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041a4b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041a4b2  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041a4b6  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041a4ba  e8e1880000             -call 0x422da0
    cpu.esp -= 4;
    sub_422da0(app, cpu);
    // 0041a4bf  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041a4c5  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a4c8  0f8796020000           -ja 0x41a764
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a4ce  ff24856ca74100         -jmp dword ptr [eax*4 + 0x41a76c]
    cpu.ip = app->getMemory<x86::reg32>(4302700 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041a4d5:
    // 0041a4d5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0041a4da  3bef                   +cmp ebp, edi
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
    // 0041a4dc  752d                   -jne 0x41a50b
    if (!cpu.flags.zf)
    {
        goto L_0x0041a50b;
    }
    // 0041a4de  b9c8fc4800             -mov ecx, 0x48fcc8
    cpu.ecx = 4783304 /*0x48fcc8*/;
    // 0041a4e3  89becc000000           -mov dword ptr [esi + 0xcc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.edi;
    // 0041a4e9  e832acffff             -call 0x415120
    cpu.esp -= 4;
    sub_415120(app, cpu);
    // 0041a4ee  b92c014900             -mov ecx, 0x49012c
    cpu.ecx = 4784428 /*0x49012c*/;
    // 0041a4f3  e868acffff             -call 0x415160
    cpu.esp -= 4;
    sub_415160(app, cpu);
    // 0041a4f8  e883010400             -call 0x45a680
    cpu.esp -= 4;
    sub_45a680(app, cpu);
    // 0041a4fd  893da0d34a00           -mov dword ptr [0x4ad3a0], edi
    app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */) = cpu.edi;
    // 0041a503  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a504  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a505  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a506  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a507  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a50a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041a50b:
    // 0041a50b  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a50e  0f8550020000           -jne 0x41a764
    if (!cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a514  b9c8fc4800             -mov ecx, 0x48fcc8
    cpu.ecx = 4783304 /*0x48fcc8*/;
    // 0041a519  c786cc0000000b000000   -mov dword ptr [esi + 0xcc], 0xb
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 11 /*0xb*/;
    // 0041a523  e8f8abffff             -call 0x415120
    cpu.esp -= 4;
    sub_415120(app, cpu);
    // 0041a528  e883570000             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 0041a52d  3bc7                   +cmp eax, edi
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
    // 0041a52f  7e0a                   -jle 0x41a53b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041a53b;
    }
    // 0041a531  b92c014900             -mov ecx, 0x49012c
    cpu.ecx = 4784428 /*0x49012c*/;
    // 0041a536  e825acffff             -call 0x415160
    cpu.esp -= 4;
    sub_415160(app, cpu);
L_0x0041a53b:
    // 0041a53b  8b4b1c                 -mov ecx, dword ptr [ebx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0041a53e  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0041a545  83e1ef                 -and ecx, 0xffffffef
    cpu.ecx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0041a548  83c920                 -or ecx, 0x20
    cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041a54b  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041a54e  e82d010400             -call 0x45a680
    cpu.esp -= 4;
    sub_45a680(app, cpu);
    // 0041a553  893da0d34a00           -mov dword ptr [0x4ad3a0], edi
    app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */) = cpu.edi;
    // 0041a559  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a55a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a55c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a55d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a560  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a561:
    // 0041a561  68fc084900             -push 0x4908fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786428 /*0x4908fc*/;
    cpu.esp -= 4;
    // 0041a566  baec084900             -mov edx, 0x4908ec
    cpu.edx = 4786412 /*0x4908ec*/;
    // 0041a56b  b9e0084900             -mov ecx, 0x4908e0
    cpu.ecx = 4786400 /*0x4908e0*/;
    // 0041a570  e83bf1ffff             -call 0x4196b0
    cpu.esp -= 4;
    sub_4196b0(app, cpu);
    // 0041a575  c786cc00000002000000   -mov dword ptr [esi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 0041a57f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a580  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a581  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a582  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a583  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a586  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a587:
    // 0041a587  e804f1ffff             -call 0x419690
    cpu.esp -= 4;
    sub_419690(app, cpu);
    // 0041a58c  83f8ff                 +cmp eax, -1
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
    // 0041a58f  8986c4000000           -mov dword ptr [esi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0041a595  0f84c9010000           -je 0x41a764
    if (cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a59b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041a59d  83f801                 +cmp eax, 1
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
    // 0041a5a0  0f95c2                 -setne dl
    cpu.dl = !cpu.flags.zf;
    // 0041a5a3  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0041a5a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a5a7  8996cc000000           -mov dword ptr [esi + 0xcc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.edx;
    // 0041a5ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a5ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a5af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a5b0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a5b3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a5b4:
    // 0041a5b4  f644241002             +test byte ptr [esp + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0041a5b9  0f85a5010000           -jne 0x41a764
    if (!cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a5bf  d94324                 -fld dword ptr [ebx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 0041a5c2  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041a5c8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041a5ca  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0041a5cd  0f8a91010000           -jp 0x41a764
    if (cpu.flags.pf)
    {
        goto L_0x0041a764;
    }
    // 0041a5d3  e8c8430000             -call 0x41e9a0
    cpu.esp -= 4;
    sub_41e9a0(app, cpu);
    // 0041a5d8  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041a5da  e8d1560000             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 0041a5df  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041a5e1  3bc7                   +cmp eax, edi
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
    // 0041a5e3  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 0041a5e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a5e7  8d4c0906               -lea ecx, [ecx + ecx + 6]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */ + cpu.ecx * 1);
    // 0041a5eb  898ecc000000           -mov dword ptr [esi + 0xcc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ecx;
    // 0041a5f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a5f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a5f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a5f4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a5f7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a5f8:
    // 0041a5f8  e8a3010000             -call 0x41a7a0
    cpu.esp -= 4;
    sub_41a7a0(app, cpu);
    // 0041a5fd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0041a602  e8b9010000             -call 0x41a7c0
    cpu.esp -= 4;
    sub_41a7c0(app, cpu);
    // 0041a607  8986d0000000           -mov dword ptr [esi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 0041a60d  c786cc00000007000000   -mov dword ptr [esi + 0xcc], 7
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 7 /*0x7*/;
    // 0041a617  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a618  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a619  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a61a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a61b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a61e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a61f:
    // 0041a61f  e80c020000             -call 0x41a830
    cpu.esp -= 4;
    sub_41a830(app, cpu);
    // 0041a624  83f801                 +cmp eax, 1
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
    // 0041a627  0f8537010000           -jne 0x41a764
    if (!cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a62d  e81e020000             -call 0x41a850
    cpu.esp -= 4;
    sub_41a850(app, cpu);
    // 0041a632  e8896c0000             -call 0x4212c0
    cpu.esp -= 4;
    sub_4212c0(app, cpu);
    // 0041a637  c786cc00000004000000   -mov dword ptr [esi + 0xcc], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 4 /*0x4*/;
    // 0041a641  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a642  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a643  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a644  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a645  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a648  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a649:
    // 0041a649  68d8084900             -push 0x4908d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786392 /*0x4908d8*/;
    cpu.esp -= 4;
    // 0041a64e  bacc084900             -mov edx, 0x4908cc
    cpu.edx = 4786380 /*0x4908cc*/;
    // 0041a653  b9c0084900             -mov ecx, 0x4908c0
    cpu.ecx = 4786368 /*0x4908c0*/;
    // 0041a658  e853f0ffff             -call 0x4196b0
    cpu.esp -= 4;
    sub_4196b0(app, cpu);
    // 0041a65d  c786cc00000009000000   -mov dword ptr [esi + 0xcc], 9
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 9 /*0x9*/;
    // 0041a667  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a668  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a669  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a66a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a66b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a66e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a66f:
    // 0041a66f  e81cf0ffff             -call 0x419690
    cpu.esp -= 4;
    sub_419690(app, cpu);
    // 0041a674  83f8ff                 +cmp eax, -1
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
    // 0041a677  8986c4000000           -mov dword ptr [esi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0041a67d  0f84e1000000           -je 0x41a764
    if (cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a683  83f801                 +cmp eax, 1
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
    // 0041a686  0f85ce000000           -jne 0x41a75a
    if (!cpu.flags.zf)
    {
        goto L_0x0041a75a;
    }
    // 0041a68c  c786cc0000000a000000   -mov dword ptr [esi + 0xcc], 0xa
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 10 /*0xa*/;
L_0x0041a696:
    // 0041a696  e805010000             -call 0x41a7a0
    cpu.esp -= 4;
    sub_41a7a0(app, cpu);
L_0x0041a69b:
    // 0041a69b  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041a69d  e81e010000             -call 0x41a7c0
    cpu.esp -= 4;
    sub_41a7c0(app, cpu);
    // 0041a6a2  8986d0000000           -mov dword ptr [esi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 0041a6a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6ac  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a6af  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a6b0:
    // 0041a6b0  e87b010000             -call 0x41a830
    cpu.esp -= 4;
    sub_41a830(app, cpu);
    // 0041a6b5  83f801                 +cmp eax, 1
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
    // 0041a6b8  0f85a6000000           -jne 0x41a764
    if (!cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a6be  e81d020000             -call 0x41a8e0
    cpu.esp -= 4;
    sub_41a8e0(app, cpu);
    // 0041a6c3  c786cc00000006000000   -mov dword ptr [esi + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 0041a6cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6d1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a6d4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a6d5:
    // 0041a6d5  f644241002             +test byte ptr [esp + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0041a6da  0f8584000000           -jne 0x41a764
    if (!cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a6e0  b9c8fc4800             -mov ecx, 0x48fcc8
    cpu.ecx = 4783304 /*0x48fcc8*/;
    // 0041a6e5  e816aaffff             -call 0x415100
    cpu.esp -= 4;
    sub_415100(app, cpu);
    // 0041a6ea  c786cc00000005000000   -mov dword ptr [esi + 0xcc], 5
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 5 /*0x5*/;
    // 0041a6f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a6f8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a6fb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a6fc:
    // 0041a6fc  d94724                 -fld dword ptr [edi + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(36) /* 0x24 */)));
    // 0041a6ff  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041a705  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041a707  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0041a70a  7a58                   -jp 0x41a764
    if (cpu.flags.pf)
    {
        goto L_0x0041a764;
    }
    // 0041a70c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041a70e  e8ddc1ffff             -call 0x4168f0
    cpu.esp -= 4;
    sub_4168f0(app, cpu);
    // 0041a713  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041a715  89becc000000           -mov dword ptr [esi + 0xcc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.edi;
    // 0041a71b  e890ff0300             -call 0x45a6b0
    cpu.esp -= 4;
    sub_45a6b0(app, cpu);
    // 0041a720  893da0d34a00           -mov dword ptr [0x4ad3a0], edi
    app->getMemory<x86::reg32>(x86::reg32(4903840) /* 0x4ad3a0 */) = cpu.edi;
    // 0041a726  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a727  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a728  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a729  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a72a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a72d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041a72e:
    // 0041a72e  c786cc0000000c000000   -mov dword ptr [esi + 0xcc], 0xc
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 12 /*0xc*/;
    // 0041a738  e873550000             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 0041a73d  83f801                 +cmp eax, 1
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
    // 0041a740  0f8e55ffffff           -jle 0x41a69b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041a69b;
    }
    // 0041a746  e94bffffff             -jmp 0x41a696
    goto L_0x0041a696;
  case 0x0041a74b:
    // 0041a74b  e8e0000000             -call 0x41a830
    cpu.esp -= 4;
    sub_41a830(app, cpu);
    // 0041a750  83f801                 +cmp eax, 1
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
    // 0041a753  750f                   -jne 0x41a764
    if (!cpu.flags.zf)
    {
        goto L_0x0041a764;
    }
    // 0041a755  e836f5ffff             -call 0x419c90
    cpu.esp -= 4;
    sub_419c90(app, cpu);
L_0x0041a75a:
    // 0041a75a  c786cc00000004000000   -mov dword ptr [esi + 0xcc], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 4 /*0x4*/;
L_0x0041a764:
    // 0041a764  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a765  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a766  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a767  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a768  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a76b  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41a7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a7a0  b91e000000             -mov ecx, 0x1e
    cpu.ecx = 30 /*0x1e*/;
    // 0041a7a5  e846aaffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041a7aa  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041a7ad  c780cc00000001000000   -mov dword ptr [eax + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 0041a7b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41a7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a7c0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041a7c2  7538                   -jne 0x41a7fc
    if (!cpu.flags.zf)
    {
        goto L_0x0041a7fc;
    }
    // 0041a7c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a7c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a7c6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041a7c8  e8e3540000             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 0041a7cd  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041a7cf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041a7d1  7e16                   -jle 0x41a7e9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041a7e9;
    }
L_0x0041a7d3:
    // 0041a7d3  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041a7d5  e826590000             -call 0x420100
    cpu.esp -= 4;
    sub_420100(app, cpu);
    // 0041a7da  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0041a7dd  8904b538014900         -mov dword ptr [esi*4 + 0x490138], eax
    app->getMemory<x86::reg32>(x86::reg32(4784440) /* 0x490138 */ + cpu.esi * 4) = cpu.eax;
    // 0041a7e4  46                     -inc esi
    (cpu.esi)++;
    // 0041a7e5  3bf7                   +cmp esi, edi
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
    // 0041a7e7  7cea                   -jl 0x41a7d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041a7d3;
    }
L_0x0041a7e9:
    // 0041a7e9  c704b538014900ffffffff -mov dword ptr [esi*4 + 0x490138], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4784440) /* 0x490138 */ + cpu.esi * 4) = 4294967295 /*0xffffffff*/;
    // 0041a7f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a7f5  b838014900             -mov eax, 0x490138
    cpu.eax = 4784440 /*0x490138*/;
    // 0041a7fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a7fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041a7fc:
    // 0041a7fc  83f901                 +cmp ecx, 1
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
    // 0041a7ff  7517                   -jne 0x41a818
    if (!cpu.flags.zf)
    {
        goto L_0x0041a818;
    }
    // 0041a801  e8eaec0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 0041a806  ba48014900             -mov edx, 0x490148
    cpu.edx = 4784456 /*0x490148*/;
    // 0041a80b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041a80d  e87e420000             -call 0x41ea90
    cpu.esp -= 4;
    sub_41ea90(app, cpu);
    // 0041a812  b848014900             -mov eax, 0x490148
    cpu.eax = 4784456 /*0x490148*/;
    // 0041a817  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041a818:
    // 0041a818  6808094900             -push 0x490908
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786440 /*0x490908*/;
    cpu.esp -= 4;
    // 0041a81d  e8eea30000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041a822  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041a825  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041a827  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41a830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a830  b91e000000             -mov ecx, 0x1e
    cpu.ecx = 30 /*0x1e*/;
    // 0041a835  e8b6a9ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041a83a  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041a83d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041a83f  8b90cc000000           -mov edx, dword ptr [eax + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */);
    // 0041a845  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041a847  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 0041a84a  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041a84c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41a850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a850  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041a853  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a854  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a855  e836f4ffff             -call 0x419c90
    cpu.esp -= 4;
    sub_419c90(app, cpu);
    // 0041a85a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041a85c  83feff                 +cmp esi, -1
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
    // 0041a85f  750d                   -jne 0x41a86e
    if (!cpu.flags.zf)
    {
        goto L_0x0041a86e;
    }
    // 0041a861  6820094900             -push 0x490920
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786464 /*0x490920*/;
    cpu.esp -= 4;
    // 0041a866  e8a5a30000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041a86b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041a86e:
    // 0041a86e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041a870  e86b410000             -call 0x41e9e0
    cpu.esp -= 4;
    sub_41e9e0(app, cpu);
    // 0041a875  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041a877  e814fbffff             -call 0x41a390
    cpu.esp -= 4;
    sub_41a390(app, cpu);
    // 0041a87c  8d3440                 -lea esi, [eax + eax*2]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041a87f  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0041a882  8b8670014900           -mov eax, dword ptr [esi + 0x490170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4784496) /* 0x490170 */);
    // 0041a888  8b8e6c014900           -mov ecx, dword ptr [esi + 0x49016c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4784492) /* 0x49016c */);
    // 0041a88e  8b9668014900           -mov edx, dword ptr [esi + 0x490168]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4784488) /* 0x490168 */);
    // 0041a894  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041a895  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041a896  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041a897  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041a899  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041a89b  e880750100             -call 0x431e20
    cpu.esp -= 4;
    sub_431e20(app, cpu);
    // 0041a8a0  8b8e8c014900           -mov ecx, dword ptr [esi + 0x49018c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4784524) /* 0x49018c */);
    // 0041a8a6  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0041a8ac  8b9690014900           -mov edx, dword ptr [esi + 0x490190]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4784528) /* 0x490190 */);
    // 0041a8b2  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0041a8b6  8b8e94014900           -mov ecx, dword ptr [esi + 0x490194]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4784532) /* 0x490194 */);
    // 0041a8bc  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0041a8c0  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0041a8c4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041a8ca  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041a8ce  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0041a8d1  e84a760100             -call 0x431f20
    cpu.esp -= 4;
    sub_431f20(app, cpu);
    // 0041a8d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a8d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a8d8  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041a8db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41a8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a8e0  e84bfbffff             -call 0x41a430
    cpu.esp -= 4;
    sub_41a430(app, cpu);
    // 0041a8e5  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041a8e7  e8f4570000             -call 0x4200e0
    cpu.esp -= 4;
    sub_4200e0(app, cpu);
    // 0041a8ec  8b88ec020000           -mov ecx, dword ptr [eax + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0041a8f2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0041a8f7  e924cf0300             -jmp 0x457820
    return sub_457820(app, cpu);
}

/* align: skip  */
void Application::sub_41a900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a900  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041a903  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a904  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a905  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041a907  b923000000             -mov ecx, 0x23
    cpu.ecx = 35 /*0x23*/;
    // 0041a90c  e8dfa8ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041a911  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041a914  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041a918  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041a91c  c786cc00000001000000   -mov dword ptr [esi + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 0041a926  c746680000803f         -mov dword ptr [esi + 0x68], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = 1065353216 /*0x3f800000*/;
    // 0041a92d  c7467000000000         -mov dword ptr [esi + 0x70], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0041a934  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0041a93b  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0041a942  8d86c4000000           -lea eax, [esi + 0xc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041a948  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041a949  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041a94a  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041a94c  e8af000000             -call 0x41aa00
    cpu.esp -= 4;
    sub_41aa00(app, cpu);
    // 0041a951  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041a953  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041a959  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0041a95d  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041a960  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041a963  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041a966  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041a96c  8b9054d74800           -mov edx, dword ptr [eax + 0x48d754]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 0041a972  8b8050d74800           -mov eax, dword ptr [eax + 0x48d750]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 0041a978  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041a979  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041a97a  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041a97f  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041a984  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041a987  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041a98b  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0041a98f  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041a995  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041a998  e873ceffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 0041a99d  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a9a3  750f                   -jne 0x41a9b4
    if (!cpu.flags.zf)
    {
        goto L_0x0041a9b4;
    }
    // 0041a9a5  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041a9ab  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041a9ad  b95c094900             -mov ecx, 0x49095c
    cpu.ecx = 4786524 /*0x49095c*/;
    // 0041a9b2  eb33                   -jmp 0x41a9e7
    goto L_0x0041a9e7;
L_0x0041a9b4:
    // 0041a9b4  81fffe000000           +cmp edi, 0xfe
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a9ba  741f                   -je 0x41a9db
    if (cpu.flags.zf)
    {
        goto L_0x0041a9db;
    }
    // 0041a9bc  81ff00010000           +cmp edi, 0x100
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a9c2  7417                   -je 0x41a9db
    if (cpu.flags.zf)
    {
        goto L_0x0041a9db;
    }
    // 0041a9c4  81ff01010000           +cmp edi, 0x101
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(257 /*0x101*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a9ca  740f                   -je 0x41a9db
    if (cpu.flags.zf)
    {
        goto L_0x0041a9db;
    }
    // 0041a9cc  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041a9d2  b944094900             -mov ecx, 0x490944
    cpu.ecx = 4786500 /*0x490944*/;
    // 0041a9d7  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0041a9d9  eb0c                   -jmp 0x41a9e7
    goto L_0x0041a9e7;
L_0x0041a9db:
    // 0041a9db  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041a9e0  b92c094900             -mov ecx, 0x49092c
    cpu.ecx = 4786476 /*0x49092c*/;
    // 0041a9e5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
L_0x0041a9e7:
    // 0041a9e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041a9e9  680000003f             -push 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056964608 /*0x3f000000*/;
    cpu.esp -= 4;
    // 0041a9ee  68cdcc4c3f             -push 0x3f4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061997773 /*0x3f4ccccd*/;
    cpu.esp -= 4;
    // 0041a9f3  e8988e0400             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0041a9f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a9f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a9fa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041a9fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41aa00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041aa00  81f9ff000000           +cmp ecx, 0xff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041aa06  0f8fba010000           -jg 0x41abc6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041abc6;
    }
    // 0041aa0c  0f849f010000           -je 0x41abb1
    if (cpu.flags.zf)
    {
        goto L_0x0041abb1;
    }
    // 0041aa12  83f90a                 +cmp ecx, 0xa
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
    // 0041aa15  0f87b7010000           -ja 0x41abd2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041abd2;
    }
    // 0041aa1b  ff248d54ac4100         -jmp dword ptr [ecx*4 + 0x41ac54]
    cpu.ip = app->getMemory<x86::reg32>(4303956 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0041aa22:
    // 0041aa22  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041aa26  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041aa2a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0041aa30  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041aa32  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0041aa38  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0041aa3e  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041aa43  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041aa49  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0041aa4c:
    // 0041aa4c  c70200008042           -mov dword ptr [edx], 0x42800000
    app->getMemory<x86::reg32>(cpu.edx) = 1115684864 /*0x42800000*/;
    // 0041aa52  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041aa56  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x0041aa5c:
    // 0041aa5c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041aa60  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
L_0x0041aa66:
    // 0041aa66  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041aa6b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041aa6d  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041aa73  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0041aa76:
    // 0041aa76  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041aa7a  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041aa80  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041aa84  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0041aa8a  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041aa8f  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 0041aa95  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041aa97  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041aa9d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0041aaa0:
    // 0041aaa0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041aaa4  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041aaa8  c70200004043           -mov dword ptr [edx], 0x43400000
    app->getMemory<x86::reg32>(cpu.edx) = 1128267776 /*0x43400000*/;
    // 0041aaae  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041aab0  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0041aab6  c70101000000           -mov dword ptr [ecx], 1
    app->getMemory<x86::reg32>(cpu.ecx) = 1 /*0x1*/;
    // 0041aabc  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041aac1  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041aac7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0041aaca:
    // 0041aaca  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041aace  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0041aad4  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041aad8  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041aadd  c70200008042           -mov dword ptr [edx], 0x42800000
    app->getMemory<x86::reg32>(cpu.edx) = 1115684864 /*0x42800000*/;
    // 0041aae3  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041aae5  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0041aaeb  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041aaf1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0041aaf4:
    // 0041aaf4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041aaf8  c70200008042           -mov dword ptr [edx], 0x42800000
    app->getMemory<x86::reg32>(cpu.edx) = 1115684864 /*0x42800000*/;
    // 0041aafe  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ab02  c70100008042           -mov dword ptr [ecx], 0x42800000
    app->getMemory<x86::reg32>(cpu.ecx) = 1115684864 /*0x42800000*/;
    // 0041ab08  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041ab0d  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 0041ab13  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ab15  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ab1b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0041ab1e:
    // 0041ab1e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041ab22  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ab26  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041ab2c  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041ab2e  c70000008042           -mov dword ptr [eax], 0x42800000
    app->getMemory<x86::reg32>(cpu.eax) = 1115684864 /*0x42800000*/;
    // 0041ab34  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0041ab3a  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041ab3f  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ab45  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0041ab48:
    // 0041ab48  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041ab4e  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041ab52  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041ab58  e9fffeffff             -jmp 0x41aa5c
    goto L_0x0041aa5c;
  case 0x0041ab5d:
    // 0041ab5d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041ab61  c70200004043           -mov dword ptr [edx], 0x43400000
    app->getMemory<x86::reg32>(cpu.edx) = 1128267776 /*0x43400000*/;
    // 0041ab67  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ab6b  c70100000043           -mov dword ptr [ecx], 0x43000000
    app->getMemory<x86::reg32>(cpu.ecx) = 1124073472 /*0x43000000*/;
    // 0041ab71  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041ab76  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 0041ab7c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ab7e  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ab84  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0041ab87:
    // 0041ab87  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041ab8b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ab8f  c70200008042           -mov dword ptr [edx], 0x42800000
    app->getMemory<x86::reg32>(cpu.edx) = 1115684864 /*0x42800000*/;
    // 0041ab95  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041ab97  c70000004043           -mov dword ptr [eax], 0x43400000
    app->getMemory<x86::reg32>(cpu.eax) = 1128267776 /*0x43400000*/;
    // 0041ab9d  c70101000000           -mov dword ptr [ecx], 1
    app->getMemory<x86::reg32>(cpu.ecx) = 1 /*0x1*/;
    // 0041aba3  b9a0044900             -mov ecx, 0x4904a0
    cpu.ecx = 4785312 /*0x4904a0*/;
    // 0041aba8  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041abae  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041abb1:
    // 0041abb1  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041abb7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041abbb  c70200004043           -mov dword ptr [edx], 0x43400000
    app->getMemory<x86::reg32>(cpu.edx) = 1128267776 /*0x43400000*/;
    // 0041abc1  e996feffff             -jmp 0x41aa5c
    goto L_0x0041aa5c;
L_0x0041abc6:
    // 0041abc6  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041abc8  2d00010000             +sub eax, 0x100
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
    // 0041abcd  7459                   -je 0x41ac28
    if (cpu.flags.zf)
    {
        goto L_0x0041ac28;
    }
    // 0041abcf  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041abd0  7436                   -je 0x41ac08
    if (cpu.flags.zf)
    {
        goto L_0x0041ac08;
    }
  [[fallthrough]];
  case 0x0041abd2:
L_0x0041abd2:
    // 0041abd2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041abd6  c70200008042           -mov dword ptr [edx], 0x42800000
    app->getMemory<x86::reg32>(cpu.edx) = 1115684864 /*0x42800000*/;
    // 0041abdc  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041abe0  81f900010000           +cmp ecx, 0x100
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
    // 0041abe6  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041abec  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0041abf2  0f8c6efeffff           -jl 0x41aa66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041aa66;
    }
    // 0041abf8  b974094900             -mov ecx, 0x490974
    cpu.ecx = 4786548 /*0x490974*/;
    // 0041abfd  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041abff  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ac05  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041ac08:
    // 0041ac08  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041ac0c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0041ac12  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ac14  c70100008042           -mov dword ptr [ecx], 0x42800000
    app->getMemory<x86::reg32>(cpu.ecx) = 1115684864 /*0x42800000*/;
    // 0041ac1a  b974094900             -mov ecx, 0x490974
    cpu.ecx = 4786548 /*0x490974*/;
    // 0041ac1f  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ac25  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0041ac28:
    // 0041ac28  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ac2c  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041ac32  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041ac36  b974094900             -mov ecx, 0x490974
    cpu.ecx = 4786548 /*0x490974*/;
    // 0041ac3b  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0041ac41  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ac43  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0041ac49  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041ac4f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41ac80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ac80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ac81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ac82  8b7128                 -mov esi, dword ptr [ecx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0041ac85  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041ac8b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041ac8c  0f849e000000           -je 0x41ad30
    if (cpu.flags.zf)
    {
        goto L_0x0041ad30;
    }
    // 0041ac92  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041ac93  741b                   -je 0x41acb0
    if (cpu.flags.zf)
    {
        goto L_0x0041acb0;
    }
    // 0041ac95  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041ac96  0f85bc000000           -jne 0x41ad58
    if (!cpu.flags.zf)
    {
        goto L_0x0041ad58;
    }
    // 0041ac9c  c746680000803f         -mov dword ptr [esi + 0x68], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = 1065353216 /*0x3f800000*/;
    // 0041aca3  c786cc00000000000000   -mov dword ptr [esi + 0xcc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 0 /*0x0*/;
    // 0041acad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041acae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041acaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041acb0:
    // 0041acb0  d94668                 -fld dword ptr [esi + 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(104) /* 0x68 */)));
    // 0041acb3  d81d44764800           -fcomp dword ptr [0x487644]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748868) /* 0x487644 */)));
    cpu.fpu.pop();
    // 0041acb9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041acbb  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041acc0  7511                   -jne 0x41acd3
    if (!cpu.flags.zf)
    {
        goto L_0x0041acd3;
    }
    // 0041acc2  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0041acc5  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0041accc  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0041acce  0c20                   -or al, 0x20
    cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0041acd0  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0041acd3:
    // 0041acd3  d94124                 -fld dword ptr [ecx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
    // 0041acd6  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041acdc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041acde  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0041ace1  7a0a                   -jp 0x41aced
    if (cpu.flags.pf)
    {
        goto L_0x0041aced;
    }
    // 0041ace3  c786cc00000003000000   -mov dword ptr [esi + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
L_0x0041aced:
    // 0041aced  e83eaa0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041acf2  d8a6c8000000           -fsub dword ptr [esi + 0xc8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 0041acf8  d9542404               -fst dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 0041acfc  d80d58744800           -fmul dword ptr [0x487458]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */));
    // 0041ad02  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0041ad08  d84e68                 -fmul dword ptr [esi + 0x68]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(104) /* 0x68 */));
    // 0041ad0b  d95e68                 -fstp dword ptr [esi + 0x68]
    app->getMemory<float>(cpu.esi + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ad0e  e81daa0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041ad13  8b86c4000000           -mov eax, dword ptr [esi + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041ad19  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ad1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ad21  7435                   -je 0x41ad58
    if (cpu.flags.zf)
    {
        goto L_0x0041ad58;
    }
    // 0041ad23  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041ad27  d84670                 -fadd dword ptr [esi + 0x70]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(112) /* 0x70 */));
    // 0041ad2a  d95e70                 -fstp dword ptr [esi + 0x70]
    app->getMemory<float>(cpu.esi + x86::reg32(112) /* 0x70 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ad2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ad2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ad2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ad30:
    // 0041ad30  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0041ad33  c741200000803f         -mov dword ptr [ecx + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 0041ad3a  83e2df                 -and edx, 0xffffffdf
    cpu.edx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0041ad3d  83ca10                 -or edx, 0x10
    cpu.edx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ad40  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041ad43  e8e8a90400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041ad48  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ad4e  c786cc00000002000000   -mov dword ptr [esi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
L_0x0041ad58:
    // 0041ad58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ad59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ad5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ad60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ad60  890d90c74a00           -mov dword ptr [0x4ac790], ecx
    app->getMemory<x86::reg32>(x86::reg32(4900752) /* 0x4ac790 */) = cpu.ecx;
    // 0041ad66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ad70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ad70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ad71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ad72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ad73  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041ad75  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041ad77  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041ad79  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0041ad7b  0f8e95000000           -jle 0x41ae16
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041ae16;
    }
    // 0041ad81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041ad82  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x0041ad86:
    // 0041ad86  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041ad88  750e                   -jne 0x41ad98
    if (!cpu.flags.zf)
    {
        goto L_0x0041ad98;
    }
    // 0041ad8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ad8b  68bc094900             -push 0x4909bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786620 /*0x4909bc*/;
    cpu.esp -= 4;
    // 0041ad90  e87b9e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041ad95  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041ad98:
    // 0041ad98  8b4cbd00               -mov ecx, dword ptr [ebp + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + cpu.edi * 4);
    // 0041ad9c  e8bf5a0000             -call 0x420860
    cpu.esp -= 4;
    sub_420860(app, cpu);
    // 0041ada1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ada3  7408                   -je 0x41adad
    if (cpu.flags.zf)
    {
        goto L_0x0041adad;
    }
    // 0041ada5  d905c0764800           +fld dword ptr [0x4876c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748992) /* 0x4876c0 */)));
    // 0041adab  eb06                   -jmp 0x41adb3
    goto L_0x0041adb3;
L_0x0041adad:
    // 0041adad  d90508774800           -fld dword ptr [0x487708]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4749064) /* 0x487708 */)));
L_0x0041adb3:
    // 0041adb3  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041adb9  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041adbf  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041adc2  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041adc5  8b8854d74800           -mov ecx, dword ptr [eax + 0x48d754]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 0041adcb  8b9050d74800           -mov edx, dword ptr [eax + 0x48d750]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 0041add1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041add2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041add3  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041add8  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041addd  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041ade2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ade3  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041ade6  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041ade9  e822caffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 0041adee  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041adf4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041adf6  750e                   -jne 0x41ae06
    if (!cpu.flags.zf)
    {
        goto L_0x0041ae06;
    }
    // 0041adf8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041adf9  6884094900             -push 0x490984
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786564 /*0x490984*/;
    cpu.esp -= 4;
    // 0041adfe  e80d9e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041ae03  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041ae06:
    // 0041ae06  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041ae0c  47                     -inc edi
    (cpu.edi)++;
    // 0041ae0d  3bfb                   +cmp edi, ebx
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
    // 0041ae0f  0f8c71ffffff           -jl 0x41ad86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ad86;
    }
    // 0041ae15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041ae16:
    // 0041ae16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ae17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ae18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ae19  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41ae20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ae20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ae21  8b7128                 -mov esi, dword ptr [ecx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0041ae24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ae25  e8c65d0000             -call 0x420bf0
    cpu.esp -= 4;
    sub_420bf0(app, cpu);
    // 0041ae2a  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041ae2c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041ae2e  743c                   -je 0x41ae6c
    if (cpu.flags.zf)
    {
        goto L_0x0041ae6c;
    }
    // 0041ae30  e8ab5d0000             -call 0x420be0
    cpu.esp -= 4;
    sub_420be0(app, cpu);
    // 0041ae35  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041ae3b  83e900                 +sub ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041ae3e  7414                   -je 0x41ae54
    if (cpu.flags.zf)
    {
        goto L_0x0041ae54;
    }
    // 0041ae40  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041ae41  7529                   -jne 0x41ae6c
    if (!cpu.flags.zf)
    {
        goto L_0x0041ae6c;
    }
    // 0041ae43  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041ae49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ae4a  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041ae4c  e81fffffff             -call 0x41ad70
    cpu.esp -= 4;
    sub_41ad70(app, cpu);
    // 0041ae51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ae52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ae53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ae54:
    // 0041ae54  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041ae5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ae5b  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041ae5d  e80e000000             -call 0x41ae70
    cpu.esp -= 4;
    sub_41ae70(app, cpu);
    // 0041ae62  c786cc00000001000000   -mov dword ptr [esi + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
L_0x0041ae6c:
    // 0041ae6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ae6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ae6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ae70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ae70  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ae73  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ae74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041ae75  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041ae79  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ae7a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ae7b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041ae7d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041ae7f  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041ae81  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041ae83  0f8eb6000000           -jle 0x41af3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041af3f;
    }
L_0x0041ae89:
    // 0041ae89  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041ae8b  750e                   -jne 0x41ae9b
    if (!cpu.flags.zf)
    {
        goto L_0x0041ae9b;
    }
    // 0041ae8d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ae8e  68680a4900             -push 0x490a68
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786792 /*0x490a68*/;
    cpu.esp -= 4;
    // 0041ae93  e8789d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041ae98  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041ae9b:
    // 0041ae9b  c786900000000000803f   -mov dword ptr [esi + 0x90], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 1065353216 /*0x3f800000*/;
    // 0041aea5  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041aeab  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041aead  750e                   -jne 0x41aebd
    if (!cpu.flags.zf)
    {
        goto L_0x0041aebd;
    }
    // 0041aeaf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041aeb0  683c0a4900             -push 0x490a3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786748 /*0x490a3c*/;
    cpu.esp -= 4;
    // 0041aeb5  e8569d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041aeba  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041aebd:
    // 0041aebd  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041aec1  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041aec5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041aec6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041aec7  8b0cbb                 -mov ecx, dword ptr [ebx + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.edi * 4);
    // 0041aeca  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041aece  e82dfbffff             -call 0x41aa00
    cpu.esp -= 4;
    sub_41aa00(app, cpu);
    // 0041aed3  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041aed9  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041aedc  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0041aee0  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041aee3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041aee6  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041aeec  8b9054d74800           -mov edx, dword ptr [eax + 0x48d754]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 0041aef2  8b8050d74800           -mov eax, dword ptr [eax + 0x48d750]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 0041aef8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041aef9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041aefa  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041aeff  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041af04  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041af07  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041af0b  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0041af0f  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041af15  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041af18  e8f3c8ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 0041af1d  47                     -inc edi
    (cpu.edi)++;
    // 0041af1e  c786900000000000803f   -mov dword ptr [esi + 0x90], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 1065353216 /*0x3f800000*/;
    // 0041af28  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041af2e  3bfd                   +cmp edi, ebp
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
    // 0041af30  0f8c53ffffff           -jl 0x41ae89
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ae89;
    }
    // 0041af36  83ff08                 +cmp edi, 8
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
    // 0041af39  0f8dae000000           -jge 0x41afed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041afed;
    }
L_0x0041af3f:
    // 0041af3f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041af41  750e                   -jne 0x41af51
    if (!cpu.flags.zf)
    {
        goto L_0x0041af51;
    }
    // 0041af43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041af44  68180a4900             -push 0x490a18
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786712 /*0x490a18*/;
    cpu.esp -= 4;
    // 0041af49  e8c29c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041af4e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041af51:
    // 0041af51  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041af57  c7869000000000000000   -mov dword ptr [esi + 0x90], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
    // 0041af61  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041af64  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041af67  8b8854d74800           -mov ecx, dword ptr [eax + 0x48d754]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 0041af6d  8b9050d74800           -mov edx, dword ptr [eax + 0x48d750]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 0041af73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041af74  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041af75  680000803b             -push 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 998244352 /*0x3b800000*/;
    cpu.esp -= 4;
    // 0041af7a  680000803b             -push 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 998244352 /*0x3b800000*/;
    cpu.esp -= 4;
    // 0041af7f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041af81  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041af83  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041af86  e885c8ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 0041af8b  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041af91  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041af93  750e                   -jne 0x41afa3
    if (!cpu.flags.zf)
    {
        goto L_0x0041afa3;
    }
    // 0041af95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041af96  68f4094900             -push 0x4909f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786676 /*0x4909f4*/;
    cpu.esp -= 4;
    // 0041af9b  e8709c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041afa0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041afa3:
    // 0041afa3  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041afa9  c7869000000000000000   -mov dword ptr [esi + 0x90], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
    // 0041afb3  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041afb6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041afb9  8b8854d74800           -mov ecx, dword ptr [eax + 0x48d754]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 0041afbf  8b9050d74800           -mov edx, dword ptr [eax + 0x48d750]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 0041afc5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041afc6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041afc7  680000803b             -push 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 998244352 /*0x3b800000*/;
    cpu.esp -= 4;
    // 0041afcc  680000803b             -push 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 998244352 /*0x3b800000*/;
    cpu.esp -= 4;
    // 0041afd1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041afd3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041afd5  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041afd8  e833c8ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 0041afdd  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041afe3  47                     -inc edi
    (cpu.edi)++;
    // 0041afe4  83ff08                 +cmp edi, 8
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
    // 0041afe7  0f8c52ffffff           -jl 0x41af3f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041af3f;
    }
L_0x0041afed:
    // 0041afed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041afee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041afef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041aff0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041aff1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041aff4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41b000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b000  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041b003  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b004  e847000000             -call 0x41b050
    cpu.esp -= 4;
    sub_41b050(app, cpu);
    // 0041b009  8b0d10155200           -mov ecx, dword ptr [0x521510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 0041b00f  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b013  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041b019  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b01a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b01b  68a00a4900             -push 0x490aa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786848 /*0x490aa0*/;
    cpu.esp -= 4;
    // 0041b020  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b021  e8d2bd0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041b026  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041b02a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b02b  e8909d0300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0041b030  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041b032  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b033  688c0a4900             -push 0x490a8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786828 /*0x490a8c*/;
    cpu.esp -= 4;
    // 0041b038  e84dd00500             -call 0x47808a
    cpu.esp -= 4;
    sub_47808a(app, cpu);
    // 0041b03d  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041b040  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041b042  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b043  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041b046  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041b050  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0041b053  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b056  7719                   -ja 0x41b071
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041b071;
    }
    // 0041b058  ff248574b04100         -jmp dword ptr [eax*4 + 0x41b074]
    cpu.ip = app->getMemory<x86::reg32>(4305012 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041b05f:
    // 0041b05f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041b064  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041b065:
    // 0041b065  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0041b06a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041b06b:
    // 0041b06b  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0041b070  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b071:
    // 0041b071  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b073  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41b0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b0b0  a1f4bf4a00             -mov eax, dword ptr [0x4abff4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898804) /* 0x4abff4 */);
    // 0041b0b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b0b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b0b8  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041b0ba  750d                   -jne 0x41b0c9
    if (!cpu.flags.zf)
    {
        goto L_0x0041b0c9;
    }
    // 0041b0bc  68f80a4900             -push 0x490af8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786936 /*0x490af8*/;
    cpu.esp -= 4;
    // 0041b0c1  e84a9b0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b0c6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b0c9:
    // 0041b0c9  a1f4bf4a00             -mov eax, dword ptr [0x4abff4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898804) /* 0x4abff4 */);
    // 0041b0ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b0cf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b0d1  6800050000             -push 0x500
    app->getMemory<x86::reg32>(cpu.esp-4) = 1280 /*0x500*/;
    cpu.esp -= 4;
    // 0041b0d6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b0d7  e8c3c60500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041b0dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b0dd  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0041b0df  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0041b0e1  68c0185200             -push 0x5218c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380288 /*0x5218c0*/;
    cpu.esp -= 4;
    // 0041b0e6  e8b4c60500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041b0eb  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041b0ee  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0041b0f0:
    // 0041b0f0  8b0cb56cc74a00         -mov ecx, dword ptr [esi*4 + 0x4ac76c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900716) /* 0x4ac76c */ + cpu.esi * 4);
    // 0041b0f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b0f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b0f9  68b80a4900             -push 0x490ab8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786872 /*0x490ab8*/;
    cpu.esp -= 4;
    // 0041b0fe  e887cf0500             -call 0x47808a
    cpu.esp -= 4;
    sub_47808a(app, cpu);
    // 0041b103  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041b106  46                     -inc esi
    (cpu.esi)++;
    // 0041b107  83fe05                 +cmp esi, 5
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
    // 0041b10a  7ce4                   -jl 0x41b0f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041b0f0;
    }
    // 0041b10c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b10d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b110  a1f4bf4a00             -mov eax, dword ptr [0x4abff4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898804) /* 0x4abff4 */);
    // 0041b115  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b116  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b118  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041b11a  750d                   -jne 0x41b129
    if (!cpu.flags.zf)
    {
        goto L_0x0041b129;
    }
    // 0041b11c  68200b4900             -push 0x490b20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786976 /*0x490b20*/;
    cpu.esp -= 4;
    // 0041b121  e8ea9a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b126  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b129:
    // 0041b129  a1f4bf4a00             -mov eax, dword ptr [0x4abff4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898804) /* 0x4abff4 */);
    // 0041b12e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b12f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b131  6800050000             -push 0x500
    app->getMemory<x86::reg32>(cpu.esp-4) = 1280 /*0x500*/;
    cpu.esp -= 4;
    // 0041b136  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b137  e84cc50500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041b13c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b13d  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0041b13f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0041b141  68c0185200             -push 0x5218c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380288 /*0x5218c0*/;
    cpu.esp -= 4;
    // 0041b146  e83dc50500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041b14b  8b0df4bf4a00           -mov ecx, dword ptr [0x4abff4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898804) /* 0x4abff4 */);
    // 0041b151  83c420                 +add esp, 0x20
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
    // 0041b154  e807000000             -call 0x41b160
    cpu.esp -= 4;
    sub_41b160(app, cpu);
    // 0041b159  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b15a  e931020000             -jmp 0x41b390
    return sub_41b390(app, cpu);
}

/* align: skip  */
void Application::sub_41b160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b160  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b161  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b162  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041b164  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041b166  750d                   -jne 0x41b175
    if (!cpu.flags.zf)
    {
        goto L_0x0041b175;
    }
    // 0041b168  68880b4900             -push 0x490b88
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787080 /*0x490b88*/;
    cpu.esp -= 4;
    // 0041b16d  e89e9a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b172  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b175:
    // 0041b175  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0041b177:
    // 0041b177  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b178  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b179  68480b4900             -push 0x490b48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787016 /*0x490b48*/;
    cpu.esp -= 4;
    // 0041b17e  893cb56cc74a00         -mov dword ptr [esi*4 + 0x4ac76c], edi
    app->getMemory<x86::reg32>(x86::reg32(4900716) /* 0x4ac76c */ + cpu.esi * 4) = cpu.edi;
    // 0041b185  e800cf0500             -call 0x47808a
    cpu.esp -= 4;
    sub_47808a(app, cpu);
    // 0041b18a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041b18d  46                     -inc esi
    (cpu.esi)++;
    // 0041b18e  81c700010000           -add edi, 0x100
    (cpu.edi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0041b194  83fe05                 +cmp esi, 5
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
    // 0041b197  7cde                   -jl 0x41b177
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041b177;
    }
    // 0041b199  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b19a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b19b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b1a0  a1f4bf4a00             -mov eax, dword ptr [0x4abff4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898804) /* 0x4abff4 */);
    // 0041b1a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b1a7  740d                   -je 0x41b1b6
    if (cpu.flags.zf)
    {
        goto L_0x0041b1b6;
    }
    // 0041b1a9  68d40b4900             -push 0x490bd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787156 /*0x490bd4*/;
    cpu.esp -= 4;
    // 0041b1ae  e85d9a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b1b3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b1b6:
    // 0041b1b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b1b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b1b8  6800050000             -push 0x500
    app->getMemory<x86::reg32>(cpu.esp-4) = 1280 /*0x500*/;
    cpu.esp -= 4;
    // 0041b1bd  e8b8c00500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0041b1c2  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041b1c4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b1c7  b940010000             -mov ecx, 0x140
    cpu.ecx = 320 /*0x140*/;
    // 0041b1cc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b1ce  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0041b1d0  8935f4bf4a00           -mov dword ptr [0x4abff4], esi
    app->getMemory<x86::reg32>(x86::reg32(4898804) /* 0x4abff4 */) = cpu.esi;
    // 0041b1d6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b1d8  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0041b1da  750d                   -jne 0x41b1e9
    if (!cpu.flags.zf)
    {
        goto L_0x0041b1e9;
    }
    // 0041b1dc  68b00b4900             -push 0x490bb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787120 /*0x490bb0*/;
    cpu.esp -= 4;
    // 0041b1e1  e82a9a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b1e6  83c404                 +add esp, 4
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
L_0x0041b1e9:
    // 0041b1e9  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041b1eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b1ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b1ed  e96effffff             -jmp 0x41b160
    return sub_41b160(app, cpu);
}

/* align: skip  */
void Application::sub_41b200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b200  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b201  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041b202  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b203  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0041b205  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b206  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0041b20b  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041b20d  e8de9fffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041b212  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041b215  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041b217  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b21d  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0041b223  8bb2d4000000           -mov esi, dword ptr [edx + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0041b229  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b22b  0f848d000000           -je 0x41b2be
    if (cpu.flags.zf)
    {
        goto L_0x0041b2be;
    }
L_0x0041b231:
    // 0041b231  8b86b8000000           -mov eax, dword ptr [esi + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 0041b237  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b239  7417                   -je 0x41b252
    if (cpu.flags.zf)
    {
        goto L_0x0041b252;
    }
    // 0041b23b  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041b241  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b243  741c                   -je 0x41b261
    if (cpu.flags.zf)
    {
        goto L_0x0041b261;
    }
    // 0041b245  399ec4000000           +cmp dword ptr [esi + 0xc4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b24b  7471                   -je 0x41b2be
    if (cpu.flags.zf)
    {
        goto L_0x0041b2be;
    }
    // 0041b24d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b24f  7410                   -je 0x41b261
    if (cpu.flags.zf)
    {
        goto L_0x0041b261;
    }
    // 0041b251  47                     -inc edi
    (cpu.edi)++;
L_0x0041b252:
    // 0041b252  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041b258  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b25a  75d5                   -jne 0x41b231
    if (!cpu.flags.zf)
    {
        goto L_0x0041b231;
    }
    // 0041b25c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b25d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b25e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b25f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b260  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b261:
    // 0041b261  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b264  7c0d                   -jl 0x41b273
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041b273;
    }
    // 0041b266  68f80b4900             -push 0x490bf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787192 /*0x490bf8*/;
    cpu.esp -= 4;
    // 0041b26b  e8a0990000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b270  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b273:
    // 0041b273  8b04bd6cc74a00         -mov eax, dword ptr [edi*4 + 0x4ac76c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900716) /* 0x4ac76c */ + cpu.edi * 4);
    // 0041b27a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041b27b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b27c  e8f7ca0500             -call 0x477d78
    cpu.esp -= 4;
    sub_477d78(app, cpu);
    // 0041b281  8b0cbd6cc74a00         -mov ecx, dword ptr [edi*4 + 0x4ac76c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900716) /* 0x4ac76c */ + cpu.edi * 4);
    // 0041b288  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 0041b28d  898ed0000000           -mov dword ptr [esi + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 0041b293  899ec4000000           -mov dword ptr [esi + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 0041b299  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0041b29f  898688000000           -mov dword ptr [esi + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0041b2a5  89868c000000           -mov dword ptr [esi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0041b2ab  898690000000           -mov dword ptr [esi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0041b2b1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b2b4  c786cc00000001000000   -mov dword ptr [esi + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
L_0x0041b2be:
    // 0041b2be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b2bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b2c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b2c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b2c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b2d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b2d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041b2d3  e828fdffff             -call 0x41b000
    cpu.esp -= 4;
    sub_41b000(app, cpu);
    // 0041b2d8  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041b2da  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041b2dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b2dd  e91effffff             -jmp 0x41b200
    return sub_41b200(app, cpu);
}

/* align: skip  */
void Application::sub_41b2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b2f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b2f1  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0041b2f6  e8f59effff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041b2fb  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041b2fe  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041b300  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b306  8b88c4000000           -mov ecx, dword ptr [eax + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 0041b30c  8bb0cc000000           -mov esi, dword ptr [eax + 0xcc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */);
    // 0041b312  3bce                   +cmp ecx, esi
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
    // 0041b314  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b315  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 0041b318  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041b31a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b321  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b322  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b323  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041b325  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0041b32a  e8c19effff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041b32f  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041b332  683c0c4900             -push 0x490c3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787260 /*0x490c3c*/;
    cpu.esp -= 4;
    // 0041b337  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b33d  e87e9a0300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0041b342  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b345  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041b347  e864020000             -call 0x41b5b0
    cpu.esp -= 4;
    sub_41b5b0(app, cpu);
    // 0041b34c  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0041b34e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b34f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b350  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b351  68100c4900             -push 0x490c10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787216 /*0x490c10*/;
    cpu.esp -= 4;
    // 0041b356  68c0185200             -push 0x5218c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380288 /*0x5218c0*/;
    cpu.esp -= 4;
    // 0041b35b  e85ecb0500             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 0041b360  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041b363  89becc000000           -mov dword ptr [esi + 0xcc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.edi;
    // 0041b369  c786900000000000803f   -mov dword ptr [esi + 0x90], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 1065353216 /*0x3f800000*/;
    // 0041b373  c786d0000000c0185200   -mov dword ptr [esi + 0xd0], 0x5218c0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = 5380288 /*0x5218c0*/;
    // 0041b37d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b37e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b37f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b380  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b391  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b392  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b393  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0041b398  e8539effff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041b39d  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041b39f  683c0c4900             -push 0x490c3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787260 /*0x490c3c*/;
    cpu.esp -= 4;
    // 0041b3a4  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041b3a7  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b3ad  e80e9a0300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0041b3b2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b3b5  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041b3b7  e8f4010000             -call 0x41b5b0
    cpu.esp -= 4;
    sub_41b5b0(app, cpu);
    // 0041b3bc  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041b3c2  8b96c4000000           -mov edx, dword ptr [esi + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041b3c8  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0041b3ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b3cb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b3cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b3cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b3ce  68440c4900             -push 0x490c44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787268 /*0x490c44*/;
    cpu.esp -= 4;
    // 0041b3d3  68c0185200             -push 0x5218c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380288 /*0x5218c0*/;
    cpu.esp -= 4;
    // 0041b3d8  e8e1ca0500             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 0041b3dd  8b86c4000000           -mov eax, dword ptr [esi + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041b3e3  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041b3e9  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041b3ec  3bc1                   +cmp eax, ecx
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
    // 0041b3ee  c786d0000000c0185200   -mov dword ptr [esi + 0xd0], 0x5218c0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = 5380288 /*0x5218c0*/;
    // 0041b3f8  7c12                   -jl 0x41b40c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041b40c;
    }
    // 0041b3fa  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041b400  c781c400000001000000   -mov dword ptr [ecx + 0xc4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */) = 1 /*0x1*/;
    // 0041b40a  eb10                   -jmp 0x41b41c
    goto L_0x0041b41c;
L_0x0041b40c:
    // 0041b40c  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041b412  c782c400000000000000   -mov dword ptr [edx + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
L_0x0041b41c:
    // 0041b41c  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041b41f  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b425  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0041b42b  8bb2d4000000           -mov esi, dword ptr [edx + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0041b431  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b433  7460                   -je 0x41b495
    if (cpu.flags.zf)
    {
        goto L_0x0041b495;
    }
    // 0041b435  bf6cc74a00             -mov edi, 0x4ac76c
    cpu.edi = 4900716 /*0x4ac76c*/;
    // 0041b43a  bb0000803f             -mov ebx, 0x3f800000
    cpu.ebx = 1065353216 /*0x3f800000*/;
L_0x0041b43f:
    // 0041b43f  8b86b8000000           -mov eax, dword ptr [esi + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 0041b445  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b447  7442                   -je 0x41b48b
    if (cpu.flags.zf)
    {
        goto L_0x0041b48b;
    }
    // 0041b449  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041b44f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b451  7435                   -je 0x41b488
    if (cpu.flags.zf)
    {
        goto L_0x0041b488;
    }
    // 0041b453  81ff80c74a00           +cmp edi, 0x4ac780
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4900736 /*0x4ac780*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b459  7c0d                   -jl 0x41b468
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041b468;
    }
    // 0041b45b  68f80b4900             -push 0x490bf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787192 /*0x490bf8*/;
    cpu.esp -= 4;
    // 0041b460  e8ab970000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b465  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b468:
    // 0041b468  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0041b46a  8986d0000000           -mov dword ptr [esi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 0041b470  899e84000000           -mov dword ptr [esi + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 0041b476  899e88000000           -mov dword ptr [esi + 0x88], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.ebx;
    // 0041b47c  899e8c000000           -mov dword ptr [esi + 0x8c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.ebx;
    // 0041b482  899e90000000           -mov dword ptr [esi + 0x90], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.ebx;
L_0x0041b488:
    // 0041b488  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b48b:
    // 0041b48b  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041b491  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b493  75aa                   -jne 0x41b43f
    if (!cpu.flags.zf)
    {
        goto L_0x0041b43f;
    }
L_0x0041b495:
    // 0041b495  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b496  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b497  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b498  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b4a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b4a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b4a2  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0041b4a7  e8449dffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041b4ac  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041b4af  683c0c4900             -push 0x490c3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787260 /*0x490c3c*/;
    cpu.esp -= 4;
    // 0041b4b4  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b4ba  ff86c4000000           -inc dword ptr [esi + 0xc4]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */))++;
    // 0041b4c0  e8fb980300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0041b4c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041b4c8  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041b4ca  e8e1000000             -call 0x41b5b0
    cpu.esp -= 4;
    sub_41b5b0(app, cpu);
    // 0041b4cf  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041b4d5  8b96c4000000           -mov edx, dword ptr [esi + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041b4db  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0041b4dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b4de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b4df  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b4e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b4e1  68440c4900             -push 0x490c44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787268 /*0x490c44*/;
    cpu.esp -= 4;
    // 0041b4e6  68c0185200             -push 0x5218c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380288 /*0x5218c0*/;
    cpu.esp -= 4;
    // 0041b4eb  e8cec90500             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 0041b4f0  8b86c4000000           -mov eax, dword ptr [esi + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041b4f6  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041b4fc  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041b4ff  3bc1                   +cmp eax, ecx
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
    // 0041b501  c786d0000000c0185200   -mov dword ptr [esi + 0xd0], 0x5218c0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = 5380288 /*0x5218c0*/;
    // 0041b50b  7c13                   -jl 0x41b520
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041b520;
    }
    // 0041b50d  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041b513  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b514  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b515  c781c400000001000000   -mov dword ptr [ecx + 0xc4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */) = 1 /*0x1*/;
    // 0041b51f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b520:
    // 0041b520  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041b526  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b527  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b528  c782c400000000000000   -mov dword ptr [edx + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
    // 0041b532  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b540  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b541  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041b543  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0041b548  e8a39cffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041b54d  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041b550  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b556  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0041b55c  8b82d4000000           -mov eax, dword ptr [edx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0041b562  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b564  743c                   -je 0x41b5a2
    if (cpu.flags.zf)
    {
        goto L_0x0041b5a2;
    }
L_0x0041b566:
    // 0041b566  8b88b8000000           -mov ecx, dword ptr [eax + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0041b56c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b56e  7412                   -je 0x41b582
    if (cpu.flags.zf)
    {
        goto L_0x0041b582;
    }
    // 0041b570  8b88cc000000           -mov ecx, dword ptr [eax + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */);
    // 0041b576  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b578  7428                   -je 0x41b5a2
    if (cpu.flags.zf)
    {
        goto L_0x0041b5a2;
    }
    // 0041b57a  39b0c4000000           +cmp dword ptr [eax + 0xc4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b580  740c                   -je 0x41b58e
    if (cpu.flags.zf)
    {
        goto L_0x0041b58e;
    }
L_0x0041b582:
    // 0041b582  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b588  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b58a  75da                   -jne 0x41b566
    if (!cpu.flags.zf)
    {
        goto L_0x0041b566;
    }
    // 0041b58c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b58d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b58e:
    // 0041b58e  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b594  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b596  740a                   -je 0x41b5a2
    if (cpu.flags.zf)
    {
        goto L_0x0041b5a2;
    }
    // 0041b598  c780c400000001000000   -mov dword ptr [eax + 0xc4], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = 1 /*0x1*/;
L_0x0041b5a2:
    // 0041b5a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b5a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b5b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b5b1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b5b3  ba700c4900             -mov edx, 0x490c70
    cpu.edx = 4787312 /*0x490c70*/;
    // 0041b5b8  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b5bc  e82f340000             -call 0x41e9f0
    cpu.esp -= 4;
    sub_41e9f0(app, cpu);
    // 0041b5c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b5c3  7502                   -jne 0x41b5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0041b5c7;
    }
    // 0041b5c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b5c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b5c7:
    // 0041b5c7  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0041b5cb  83c404                 +add esp, 4
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
    // 0041b5ce  e9bdb70500             -jmp 0x476d90
    return __ftol(app, cpu);
}

/* align: skip  */
void Application::sub_41b5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b5e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b5e1  e8caffffff             -call 0x41b5b0
    cpu.esp -= 4;
    sub_41b5b0(app, cpu);
    // 0041b5e6  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041b5e8  683c0c4900             -push 0x490c3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787260 /*0x490c3c*/;
    cpu.esp -= 4;
    // 0041b5ed  46                     -inc esi
    (cpu.esi)++;
    // 0041b5ee  e8cd970300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0041b5f3  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0041b5f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b5f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b5f7  687c0c4900             -push 0x490c7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787324 /*0x490c7c*/;
    cpu.esp -= 4;
    // 0041b5fc  68d2185200             -push 0x5218d2
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380306 /*0x5218d2*/;
    cpu.esp -= 4;
    // 0041b601  e8b8c80500             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 0041b606  83c418                 +add esp, 0x18
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
    // 0041b609  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041b60b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b60c  e90f000000             -jmp 0x41b620
    goto L_0x0041b620;
L_0x0041b620:
    // 0041b620  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b621  894c2400               -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0041b625  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041b627  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0041b62b  ba700c4900             -mov edx, 0x490c70
    cpu.edx = 4787312 /*0x490c70*/;
    // 0041b630  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b634  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041b638  e813340000             -call 0x41ea50
    cpu.esp -= 4;
    sub_41ea50(app, cpu);
    // 0041b63d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b63e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b640  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0041b643  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041b645  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b646  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b647  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b64d  3bc2                   +cmp eax, edx
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
    // 0041b64f  0f849c000000           -je 0x41b6f1
    if (cpu.flags.zf)
    {
        goto L_0x0041b6f1;
    }
    // 0041b655  be0000803f             -mov esi, 0x3f800000
    cpu.esi = 1065353216 /*0x3f800000*/;
L_0x0041b65a:
    // 0041b65a  3990b8000000           +cmp dword ptr [eax + 0xb8], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b660  742a                   -je 0x41b68c
    if (cpu.flags.zf)
    {
        goto L_0x0041b68c;
    }
    // 0041b662  899084000000           -mov dword ptr [eax + 0x84], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = cpu.edx;
    // 0041b668  899088000000           -mov dword ptr [eax + 0x88], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 0041b66e  89908c000000           -mov dword ptr [eax + 0x8c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */) = cpu.edx;
    // 0041b674  89b090000000           -mov dword ptr [eax + 0x90], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = cpu.esi;
    // 0041b67a  3990cc000000           +cmp dword ptr [eax + 0xcc], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b680  746f                   -je 0x41b6f1
    if (cpu.flags.zf)
    {
        goto L_0x0041b6f1;
    }
    // 0041b682  3990d0000000           +cmp dword ptr [eax + 0xd0], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b688  7467                   -je 0x41b6f1
    if (cpu.flags.zf)
    {
        goto L_0x0041b6f1;
    }
    // 0041b68a  eb57                   -jmp 0x41b6e3
    goto L_0x0041b6e3;
L_0x0041b68c:
    // 0041b68c  3990c4000000           +cmp dword ptr [eax + 0xc4], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b692  7408                   -je 0x41b69c
    if (cpu.flags.zf)
    {
        goto L_0x0041b69c;
    }
    // 0041b694  d905c0764800           +fld dword ptr [0x4876c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748992) /* 0x4876c0 */)));
    // 0041b69a  eb06                   -jmp 0x41b6a2
    goto L_0x0041b6a2;
L_0x0041b69c:
    // 0041b69c  d90508774800           -fld dword ptr [0x487708]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4749064) /* 0x487708 */)));
L_0x0041b6a2:
    // 0041b6a2  8b88bc000000           -mov ecx, dword ptr [eax + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0041b6a8  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041b6ae  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0041b6b1  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0041b6b4  8bb954d74800           -mov edi, dword ptr [ecx + 0x48d754]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773716) /* 0x48d754 */);
    // 0041b6ba  8b8950d74800           -mov ecx, dword ptr [ecx + 0x48d750]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773712) /* 0x48d750 */);
    // 0041b6c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b6c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b6c2  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041b6c7  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041b6cc  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041b6d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b6d2  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041b6d5  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041b6d8  e833c1ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 0041b6dd  89b090000000           -mov dword ptr [eax + 0x90], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = cpu.esi;
L_0x0041b6e3:
    // 0041b6e3  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b6e9  3bc2                   +cmp eax, edx
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
    // 0041b6eb  0f8569ffffff           -jne 0x41b65a
    if (!cpu.flags.zf)
    {
        goto L_0x0041b65a;
    }
L_0x0041b6f1:
    // 0041b6f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b6f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b6f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b700  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0041b703  8b88c4000000           -mov ecx, dword ptr [eax + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 0041b709  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041b70b  751a                   -jne 0x41b727
    if (!cpu.flags.zf)
    {
        goto L_0x0041b727;
    }
    // 0041b70d  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041b713  c780c400000001000000   -mov dword ptr [eax + 0xc4], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = 1 /*0x1*/;
    // 0041b71d  baa0c74a00             -mov edx, 0x4ac7a0
    cpu.edx = 4900768 /*0x4ac7a0*/;
    // 0041b722  e909000000             -jmp 0x41b730
    goto L_0x0041b730;
L_0x0041b727:
    // 0041b727  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b730:
    // 0041b730  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0041b733  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b734  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041b735  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b736  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b737  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0041b73b  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041b73d  e8aedd0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 0041b742  83f801                 +cmp eax, 1
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
    // 0041b745  7405                   -je 0x41b74c
    if (cpu.flags.zf)
    {
        goto L_0x0041b74c;
    }
    // 0041b747  e8d498ffff             -call 0x415020
    cpu.esp -= 4;
    sub_415020(app, cpu);
L_0x0041b74c:
    // 0041b74c  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041b74e  bd0000803f             -mov ebp, 0x3f800000
    cpu.ebp = 1065353216 /*0x3f800000*/;
L_0x0041b753:
    // 0041b753  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b755  750d                   -jne 0x41b764
    if (!cpu.flags.zf)
    {
        goto L_0x0041b764;
    }
    // 0041b757  68a80c4900             -push 0x490ca8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787368 /*0x490ca8*/;
    cpu.esp -= 4;
    // 0041b75c  e8af940000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b761  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b764:
    // 0041b764  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0041b767  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041b76b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041b76c  68940c4900             -push 0x490c94
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787348 /*0x490c94*/;
    cpu.esp -= 4;
    // 0041b771  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041b772  e881b60500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041b777  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041b77b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b77c  e83f960300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0041b781  8986d0000000           -mov dword ptr [esi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 0041b787  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b789  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0041b78f  898688000000           -mov dword ptr [esi + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0041b795  89868c000000           -mov dword ptr [esi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0041b79b  89ae90000000           -mov dword ptr [esi + 0x90], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.ebp;
    // 0041b7a1  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041b7a7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041b7aa  3bf0                   +cmp esi, eax
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
    // 0041b7ac  750d                   -jne 0x41b7bb
    if (!cpu.flags.zf)
    {
        goto L_0x0041b7bb;
    }
    // 0041b7ae  68a80c4900             -push 0x490ca8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787368 /*0x490ca8*/;
    cpu.esp -= 4;
    // 0041b7b3  e858940000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041b7b8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041b7bb:
    // 0041b7bb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041b7bf  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041b7c3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b7c4  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041b7c8  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0041b7cb  e870000000             -call 0x41b840
    cpu.esp -= 4;
    sub_41b840(app, cpu);
    // 0041b7d0  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041b7d6  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0041b7da  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041b7dd  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041b7e0  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041b7e6  8b8854d74800           -mov ecx, dword ptr [eax + 0x48d754]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 0041b7ec  8b9050d74800           -mov edx, dword ptr [eax + 0x48d750]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 0041b7f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041b7f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041b7f4  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041b7f9  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041b7fe  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041b801  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041b804  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041b808  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0041b80c  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041b812  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041b815  e8f6bfffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 0041b81a  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0041b81c  89ae90000000           -mov dword ptr [esi + 0x90], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.ebp;
    // 0041b822  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041b828  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b82b  0f8c22ffffff           -jl 0x41b753
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041b753;
    }
    // 0041b831  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b832  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b833  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b834  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b835  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0041b838  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041b840  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0041b843  83f809                 +cmp eax, 9
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
    // 0041b846  0f87c5000000           -ja 0x41b911
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041b911;
    }
    // 0041b84c  ff248524b94100         -jmp dword ptr [eax*4 + 0x41b924]
    cpu.ip = app->getMemory<x86::reg32>(4307236 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041b853:
    // 0041b853  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b857  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041b85d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0041b863  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b866:
    // 0041b866  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b86a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0041b870  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0041b876  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b879:
    // 0041b879  c70200008042           -mov dword ptr [edx], 0x42800000
    app->getMemory<x86::reg32>(cpu.edx) = 1115684864 /*0x42800000*/;
    // 0041b87f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b883  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0041b889  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b88c:
    // 0041b88c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b890  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0041b896  c70000000043           -mov dword ptr [eax], 0x43000000
    app->getMemory<x86::reg32>(cpu.eax) = 1124073472 /*0x43000000*/;
    // 0041b89c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b89f:
    // 0041b89f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b8a3  c70200008042           -mov dword ptr [edx], 0x42800000
    app->getMemory<x86::reg32>(cpu.edx) = 1115684864 /*0x42800000*/;
    // 0041b8a9  c70100000043           -mov dword ptr [ecx], 0x43000000
    app->getMemory<x86::reg32>(cpu.ecx) = 1124073472 /*0x43000000*/;
    // 0041b8af  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b8b2:
    // 0041b8b2  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041b8b8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b8bc  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041b8c2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b8c5:
    // 0041b8c5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b8c9  c70200004043           -mov dword ptr [edx], 0x43400000
    app->getMemory<x86::reg32>(cpu.edx) = 1128267776 /*0x43400000*/;
    // 0041b8cf  c70000000043           -mov dword ptr [eax], 0x43000000
    app->getMemory<x86::reg32>(cpu.eax) = 1124073472 /*0x43000000*/;
    // 0041b8d5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b8d8:
    // 0041b8d8  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b8dc  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0041b8e2  c70100004043           -mov dword ptr [ecx], 0x43400000
    app->getMemory<x86::reg32>(cpu.ecx) = 1128267776 /*0x43400000*/;
    // 0041b8e8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b8eb:
    // 0041b8eb  c70200008042           -mov dword ptr [edx], 0x42800000
    app->getMemory<x86::reg32>(cpu.edx) = 1115684864 /*0x42800000*/;
    // 0041b8f1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b8f5  c70200004043           -mov dword ptr [edx], 0x43400000
    app->getMemory<x86::reg32>(cpu.edx) = 1128267776 /*0x43400000*/;
    // 0041b8fb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0041b8fe:
    // 0041b8fe  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b902  c70200000043           -mov dword ptr [edx], 0x43000000
    app->getMemory<x86::reg32>(cpu.edx) = 1124073472 /*0x43000000*/;
    // 0041b908  c70000004043           -mov dword ptr [eax], 0x43400000
    app->getMemory<x86::reg32>(cpu.eax) = 1128267776 /*0x43400000*/;
    // 0041b90e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0041b911:
    // 0041b911  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041b915  c70200004043           -mov dword ptr [edx], 0x43400000
    app->getMemory<x86::reg32>(cpu.edx) = 1128267776 /*0x43400000*/;
    // 0041b91b  c70100008042           -mov dword ptr [ecx], 0x42800000
    app->getMemory<x86::reg32>(cpu.ecx) = 1115684864 /*0x42800000*/;
    // 0041b921  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41b950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b950  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0041b953  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041b955  8982cc000000           -mov dword ptr [edx + 0xcc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(204) /* 0xcc */) = cpu.eax;
    // 0041b95b  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0041b95e  8982c4000000           -mov dword ptr [edx + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0041b964  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0041b967  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041b96a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041b971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041b972  8b3d88c74a00           -mov edi, dword ptr [0x4ac788]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041b978  e89333ffff             -call 0x40ed10
    cpu.esp -= 4;
    sub_40ed10(app, cpu);
    // 0041b97d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041b97f  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041b984  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b986  7436                   -je 0x41b9be
    if (cpu.flags.zf)
    {
        goto L_0x0041b9be;
    }
    // 0041b988  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041b98a  7432                   -je 0x41b9be
    if (cpu.flags.zf)
    {
        goto L_0x0041b9be;
    }
    // 0041b98c  e84f36ffff             -call 0x40efe0
    cpu.esp -= 4;
    sub_40efe0(app, cpu);
    // 0041b991  8d8f00090000           -lea ecx, [edi + 0x900]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(2304) /* 0x900 */);
    // 0041b997  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0041b99e  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0041b9a5  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0041b9ac  e89fffffff             -call 0x41b950
    cpu.esp -= 4;
    sub_41b950(app, cpu);
    // 0041b9b1  8d8f30090000           -lea ecx, [edi + 0x930]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(2352) /* 0x930 */);
    // 0041b9b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b9b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b9b9  e992ffffff             -jmp 0x41b950
    return sub_41b950(app, cpu);
L_0x0041b9be:
    // 0041b9be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b9bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041b9c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41b9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041b9d0  833d70c84a0001         +cmp dword ptr [0x4ac870], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4900976) /* 0x4ac870 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041b9d7  7519                   -jne 0x41b9f2
    if (!cpu.flags.zf)
    {
        goto L_0x0041b9f2;
    }
    // 0041b9d9  a141165200             -mov eax, dword ptr [0x521641]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379649) /* 0x521641 */);
    // 0041b9de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041b9e0  750a                   -jne 0x41b9ec
    if (!cpu.flags.zf)
    {
        goto L_0x0041b9ec;
    }
    // 0041b9e2  e889ffffff             -call 0x41b970
    cpu.esp -= 4;
    sub_41b970(app, cpu);
    // 0041b9e7  a141165200             -mov eax, dword ptr [0x521641]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379649) /* 0x521641 */);
L_0x0041b9ec:
    // 0041b9ec  a370c84a00             -mov dword ptr [0x4ac870], eax
    app->getMemory<x86::reg32>(x86::reg32(4900976) /* 0x4ac870 */) = cpu.eax;
    // 0041b9f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041b9f2:
    // 0041b9f2  8b0d41165200           -mov ecx, dword ptr [0x521641]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379649) /* 0x521641 */);
    // 0041b9f8  890d70c84a00           -mov dword ptr [0x4ac870], ecx
    app->getMemory<x86::reg32>(x86::reg32(4900976) /* 0x4ac870 */) = cpu.ecx;
    // 0041b9fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ba00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041ba00  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041ba03  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ba04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041ba05  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041ba07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ba08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ba09  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0041ba0c  e87f2cffff             -call 0x40e690
    cpu.esp -= 4;
    sub_40e690(app, cpu);
    // 0041ba11  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041ba13  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0041ba15  3bf5                   +cmp esi, ebp
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
    // 0041ba17  744e                   -je 0x41ba67
    if (cpu.flags.zf)
    {
        goto L_0x0041ba67;
    }
    // 0041ba19  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0041ba1c  3bc5                   +cmp eax, ebp
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
    // 0041ba1e  7523                   -jne 0x41ba43
    if (!cpu.flags.zf)
    {
        goto L_0x0041ba43;
    }
    // 0041ba20  396e28                 +cmp dword ptr [esi + 0x28], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ba23  751a                   -jne 0x41ba3f
    if (!cpu.flags.zf)
    {
        goto L_0x0041ba3f;
    }
    // 0041ba25  e8e635ffff             -call 0x40f010
    cpu.esp -= 4;
    sub_40f010(app, cpu);
    // 0041ba2a  89afcc000000           -mov dword ptr [edi + 0xcc], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = cpu.ebp;
    // 0041ba30  89afc4000000           -mov dword ptr [edi + 0xc4], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = cpu.ebp;
    // 0041ba36  e8552cffff             -call 0x40e690
    cpu.esp -= 4;
    sub_40e690(app, cpu);
    // 0041ba3b  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041ba3d  eb63                   -jmp 0x41baa2
    goto L_0x0041baa2;
L_0x0041ba3f:
    // 0041ba3f  3bc5                   +cmp eax, ebp
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
    // 0041ba41  745f                   -je 0x41baa2
    if (cpu.flags.zf)
    {
        goto L_0x0041baa2;
    }
L_0x0041ba43:
    // 0041ba43  6639a88a020000         +cmp word ptr [eax + 0x28a], bp
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(650) /* 0x28a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bp));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0041ba4a  7f56                   -jg 0x41baa2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041baa2;
    }
    // 0041ba4c  8b87cc000000           -mov eax, dword ptr [edi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */);
    // 0041ba52  3bc5                   +cmp eax, ebp
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
    // 0041ba54  7e4c                   -jle 0x41baa2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041baa2;
    }
    // 0041ba56  83f804                 +cmp eax, 4
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
    // 0041ba59  7f47                   -jg 0x41baa2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041baa2;
    }
    // 0041ba5b  c787cc00000006000000   -mov dword ptr [edi + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 0041ba65  eb3b                   -jmp 0x41baa2
    goto L_0x0041baa2;
L_0x0041ba67:
    // 0041ba67  8b87cc000000           -mov eax, dword ptr [edi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */);
    // 0041ba6d  3bc5                   +cmp eax, ebp
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
    // 0041ba6f  7e31                   -jle 0x41baa2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041baa2;
    }
    // 0041ba71  83f805                 +cmp eax, 5
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
    // 0041ba74  7f2c                   -jg 0x41baa2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041baa2;
    }
    // 0041ba76  e89535ffff             -call 0x40f010
    cpu.esp -= 4;
    sub_40f010(app, cpu);
    // 0041ba7b  89afcc000000           -mov dword ptr [edi + 0xcc], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = cpu.ebp;
    // 0041ba81  89afc4000000           -mov dword ptr [edi + 0xc4], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = cpu.ebp;
    // 0041ba87  e8042cffff             -call 0x40e690
    cpu.esp -= 4;
    sub_40e690(app, cpu);
    // 0041ba8c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041ba8e  8b87cc000000           -mov eax, dword ptr [edi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */);
    // 0041ba94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ba95  68bc0c4900             -push 0x490cbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787388 /*0x490cbc*/;
    cpu.esp -= 4;
    // 0041ba9a  e871910000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041ba9f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041baa2:
    // 0041baa2  e86932ffff             -call 0x40ed10
    cpu.esp -= 4;
    sub_40ed10(app, cpu);
    // 0041baa7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041baa9  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0041baab  3bf1                   +cmp esi, ecx
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
    // 0041baad  740b                   -je 0x41baba
    if (cpu.flags.zf)
    {
        goto L_0x0041baba;
    }
    // 0041baaf  8b97d4000000           -mov edx, dword ptr [edi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 0041bab5  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0041bab8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0041baba:
    // 0041baba  8b87cc000000           -mov eax, dword ptr [edi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */);
    // 0041bac0  83f807                 +cmp eax, 7
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
    // 0041bac3  0f872e020000           -ja 0x41bcf7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041bcf7;
    }
    // 0041bac9  ff248500bd4100         -jmp dword ptr [eax*4 + 0x41bd00]
    cpu.ip = app->getMemory<x86::reg32>(4308224 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041bad0:
    // 0041bad0  3bf1                   +cmp esi, ecx
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
    // 0041bad2  7517                   -jne 0x41baeb
    if (!cpu.flags.zf)
    {
        goto L_0x0041baeb;
    }
    // 0041bad4  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0041bad7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bad8  83e2ef                 -and edx, 0xffffffef
    cpu.edx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0041badb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041badc  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041badf  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0041bae2  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041bae5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bae6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bae7  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041baea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041baeb:
    // 0041baeb  c787cc00000001000000   -mov dword ptr [edi + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 0041baf5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041baf6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041baf7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041baf8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041baf9  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bafc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bafd:
    // 0041bafd  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041bb00  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bb01  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0041bb06  e835930300             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0041bb0b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041bb0e  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041bb12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bb13  6860cf4800             -push 0x48cf60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771680 /*0x48cf60*/;
    cpu.esp -= 4;
    // 0041bb18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bb19  e8dab20500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041bb1e  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 0041bb21  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0041bb24  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bb27  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041bb2b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0041bb2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041bb2e  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0041bb31  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bb32  e8597d0400             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0041bb37  c787cc00000002000000   -mov dword ptr [edi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 0041bb41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb45  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bb48  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bb49:
    // 0041bb49  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041bb4c  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0041bb4e  744a                   -je 0x41bb9a
    if (cpu.flags.zf)
    {
        goto L_0x0041bb9a;
    }
    // 0041bb50  3be9                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041bb52  7407                   -je 0x41bb5b
    if (cpu.flags.zf)
    {
        goto L_0x0041bb5b;
    }
    // 0041bb54  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0041bb56  e88531ffff             -call 0x40ece0
    cpu.esp -= 4;
    sub_40ece0(app, cpu);
L_0x0041bb5b:
    // 0041bb5b  a141165200             -mov eax, dword ptr [0x521641]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379649) /* 0x521641 */);
    // 0041bb60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bb62  741c                   -je 0x41bb80
    if (cpu.flags.zf)
    {
        goto L_0x0041bb80;
    }
    // 0041bb64  e8c7bb0000             -call 0x427730
    cpu.esp -= 4;
    sub_427730(app, cpu);
    // 0041bb69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bb6b  7513                   -jne 0x41bb80
    if (!cpu.flags.zf)
    {
        goto L_0x0041bb80;
    }
    // 0041bb6d  8b4b1c                 -mov ecx, dword ptr [ebx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0041bb70  c743200000803f         -mov dword ptr [ebx + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 0041bb77  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0041bb7a  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bb7d  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0041bb80:
    // 0041bb80  c787cc00000003000000   -mov dword ptr [edi + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
    // 0041bb8a  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041bb8d  24fb                   -and al, 0xfb
    cpu.al &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0041bb8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb90  894640                 -mov dword ptr [esi + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0041bb93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bb96  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bb99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bb9a:
    // 0041bb9a  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0041bb9c  0f8455010000           -je 0x41bcf7
    if (cpu.flags.zf)
    {
        goto L_0x0041bcf7;
    }
    // 0041bba2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041bba4  e8b727ffff             -call 0x40e360
    cpu.esp -= 4;
    sub_40e360(app, cpu);
    // 0041bba9  c787cc00000006000000   -mov dword ptr [edi + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 0041bbb3  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041bbb6  24f7                   -and al, 0xf7
    cpu.al &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0041bbb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbb9  894640                 -mov dword ptr [esi + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0041bbbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbbd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbbf  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bbc2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bbc3:
    // 0041bbc3  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0041bbc5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041bbc7  e85432ffff             -call 0x40ee20
    cpu.esp -= 4;
    sub_40ee20(app, cpu);
    // 0041bbcc  8987c4000000           -mov dword ptr [edi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0041bbd2  e8599b0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041bbd7  d91d74c84a00           -fstp dword ptr [0x4ac874]
    app->getMemory<float>(x86::reg32(4900980) /* 0x4ac874 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041bbdd  c787cc00000005000000   -mov dword ptr [edi + 0xcc], 5
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 5 /*0x5*/;
    // 0041bbe7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbe8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbe9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bbeb  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bbee  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bbef:
    // 0041bbef  e83c9b0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041bbf4  d82574c84a00           -fsub dword ptr [0x4ac874]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4900980) /* 0x4ac874 */));
    // 0041bbfa  db87c4000000           -fild dword ptr [edi + 0xc4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */))));
    // 0041bc00  dc0d10774800           -fmul qword ptr [0x487710]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749072) /* 0x487710 */));
    // 0041bc06  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0041bc08  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041bc0a  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041bc0d  7a56                   -jp 0x41bc65
    if (cpu.flags.pf)
    {
        goto L_0x0041bc65;
    }
    // 0041bc0f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041bc11  c787c400000000000000   -mov dword ptr [edi + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
    // 0041bc1b  741d                   -je 0x41bc3a
    if (cpu.flags.zf)
    {
        goto L_0x0041bc3a;
    }
    // 0041bc1d  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0041bc1f  e87c30ffff             -call 0x40eca0
    cpu.esp -= 4;
    sub_40eca0(app, cpu);
    // 0041bc24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bc26  7412                   -je 0x41bc3a
    if (cpu.flags.zf)
    {
        goto L_0x0041bc3a;
    }
    // 0041bc28  c787cc00000004000000   -mov dword ptr [edi + 0xcc], 4
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 4 /*0x4*/;
    // 0041bc32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc36  83c444                 +add esp, 0x44
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041bc39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bc3a:
    // 0041bc3a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041bc3c  e8ff27ffff             -call 0x40e440
    cpu.esp -= 4;
    sub_40e440(app, cpu);
    // 0041bc41  eb57                   -jmp 0x41bc9a
    goto L_0x0041bc9a;
L_0x0041bc43:
    // 0041bc43  e87827ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    // 0041bc48  8b97d4000000           -mov edx, dword ptr [edi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 0041bc4e  c787cc00000001000000   -mov dword ptr [edi + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 0041bc58  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0041bc5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc5e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0041bc60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bc61  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bc64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bc65:
    // 0041bc65  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0041bc68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bc6a  0f8487000000           -je 0x41bcf7
    if (cpu.flags.zf)
    {
        goto L_0x0041bcf7;
    }
    // 0041bc70  0fbf888a020000         -movsx ecx, word ptr [eax + 0x28a]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(650) /* 0x28a */)));
    // 0041bc77  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041bc7b  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0041bc7f  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041bc85  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041bc87  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041bc8a  7a6b                   -jp 0x41bcf7
    if (cpu.flags.pf)
    {
        goto L_0x0041bcf7;
    }
    // 0041bc8c  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041bc8e  e8cd26ffff             -call 0x40e360
    cpu.esp -= 4;
    sub_40e360(app, cpu);
    // 0041bc93  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041bc95  e8e627ffff             -call 0x40e480
    cpu.esp -= 4;
    sub_40e480(app, cpu);
L_0x0041bc9a:
    // 0041bc9a  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0041bc9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bc9f  75a2                   -jne 0x41bc43
    if (!cpu.flags.zf)
    {
        goto L_0x0041bc43;
    }
    // 0041bca1  c787cc00000006000000   -mov dword ptr [edi + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 0041bcab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcaf  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bcb2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bcb3:
    // 0041bcb3  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0041bcb6  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0041bcb9  83e2ef                 -and edx, 0xffffffef
    cpu.edx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0041bcbc  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041bcbe  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041bcc1  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041bcc4  e89726ffff             -call 0x40e360
    cpu.esp -= 4;
    sub_40e360(app, cpu);
    // 0041bcc9  c787cc00000007000000   -mov dword ptr [edi + 0xcc], 7
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 7 /*0x7*/;
    // 0041bcd3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcd4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcd5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcd6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcd7  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bcda  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bcdb:
    // 0041bcdb  d94324                 -fld dword ptr [ebx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 0041bcde  d85b20                 -fcomp dword ptr [ebx + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0041bce1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041bce3  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041bce6  7a0f                   -jp 0x41bcf7
    if (cpu.flags.pf)
    {
        goto L_0x0041bcf7;
    }
    // 0041bce8  e8d326ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    // 0041bced  c787cc00000000000000   -mov dword ptr [edi + 0xcc], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 0 /*0x0*/;
L_0x0041bcf7:
    // 0041bcf7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcf9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcfa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bcfb  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0041bcfe  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41bd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041bd20  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041bd23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041bd24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041bd25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bd26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041bd27  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041bd29  8b5f28                 -mov ebx, dword ptr [edi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041bd2c  e85f29ffff             -call 0x40e690
    cpu.esp -= 4;
    sub_40e690(app, cpu);
    // 0041bd31  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041bd33  e8d82fffff             -call 0x40ed10
    cpu.esp -= 4;
    sub_40ed10(app, cpu);
    // 0041bd38  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0041bd3a  8b83cc000000           -mov eax, dword ptr [ebx + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */);
    // 0041bd40  83f807                 +cmp eax, 7
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
    // 0041bd43  0f87fc010000           -ja 0x41bf45
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041bf45;
    }
    // 0041bd49  ff248550bf4100         -jmp dword ptr [eax*4 + 0x41bf50]
    cpu.ip = app->getMemory<x86::reg32>(4308816 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041bd50:
    // 0041bd50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041bd52  0f8593010000           -jne 0x41beeb
    if (!cpu.flags.zf)
    {
        goto L_0x0041beeb;
    }
    // 0041bd58  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041bd5b  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0041bd5e  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0041bd60  0c20                   -or al, 0x20
    cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0041bd62  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041bd65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bd66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bd67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bd68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bd69  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041bd6c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bd6d:
    // 0041bd6d  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041bd70  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041bd73  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0041bd75  7437                   -je 0x41bdae
    if (cpu.flags.zf)
    {
        goto L_0x0041bdae;
    }
    // 0041bd77  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bd78  68f8b94800             -push 0x48b9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4766200 /*0x48b9f8*/;
    cpu.esp -= 4;
    // 0041bd7d  e8be900300             -call 0x454e40
    cpu.esp -= 4;
    sub_454e40(app, cpu);
    // 0041bd82  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041bd85  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041bd89  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bd8a  6860cf4800             -push 0x48cf60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4771680 /*0x48cf60*/;
    cpu.esp -= 4;
    // 0041bd8f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041bd90  e863b00500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041bd95  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 0041bd98  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0041bd9b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bd9e  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041bda2  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0041bda4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041bda5  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0041bda8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041bda9  e8e27a0400             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
L_0x0041bdae:
    // 0041bdae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bdaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bdb0  c783cc00000002000000   -mov dword ptr [ebx + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 0041bdba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bdbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bdbc  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041bdbf  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bdc0:
    // 0041bdc0  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041bdc3  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0041bdc5  7455                   -je 0x41be1c
    if (cpu.flags.zf)
    {
        goto L_0x0041be1c;
    }
    // 0041bdc7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041bdc9  7407                   -je 0x41bdd2
    if (cpu.flags.zf)
    {
        goto L_0x0041bdd2;
    }
    // 0041bdcb  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0041bdcd  e80e2fffff             -call 0x40ece0
    cpu.esp -= 4;
    sub_40ece0(app, cpu);
L_0x0041bdd2:
    // 0041bdd2  a141165200             -mov eax, dword ptr [0x521641]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379649) /* 0x521641 */);
    // 0041bdd7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bdd9  741c                   -je 0x41bdf7
    if (cpu.flags.zf)
    {
        goto L_0x0041bdf7;
    }
    // 0041bddb  e850b90000             -call 0x427730
    cpu.esp -= 4;
    sub_427730(app, cpu);
    // 0041bde0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041bde2  7513                   -jne 0x41bdf7
    if (!cpu.flags.zf)
    {
        goto L_0x0041bdf7;
    }
    // 0041bde4  8b4f1c                 -mov ecx, dword ptr [edi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041bde7  c747200000803f         -mov dword ptr [edi + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 0041bdee  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0041bdf1  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041bdf4  894f1c                 -mov dword ptr [edi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0041bdf7:
    // 0041bdf7  c783cc00000003000000   -mov dword ptr [ebx + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
    // 0041be01  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041be04  24fb                   -and al, 0xfb
    cpu.al &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0041be06  894640                 -mov dword ptr [esi + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0041be09  e822990400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041be0e  d91d7cc84a00           -fstp dword ptr [0x4ac87c]
    app->getMemory<float>(x86::reg32(4900988) /* 0x4ac87c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041be14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be18  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041be1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041be1c:
    // 0041be1c  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0041be1e  0f8421010000           -je 0x41bf45
    if (cpu.flags.zf)
    {
        goto L_0x0041bf45;
    }
    // 0041be24  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041be26  e83525ffff             -call 0x40e360
    cpu.esp -= 4;
    sub_40e360(app, cpu);
    // 0041be2b  c783cc00000006000000   -mov dword ptr [ebx + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 0041be35  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0041be38  24f7                   -and al, 0xf7
    cpu.al &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0041be3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be3b  894640                 -mov dword ptr [esi + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0041be3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be41  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041be44  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041be45:
    // 0041be45  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0041be47  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041be49  e8d22fffff             -call 0x40ee20
    cpu.esp -= 4;
    sub_40ee20(app, cpu);
    // 0041be4e  8983c4000000           -mov dword ptr [ebx + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0041be54  e8d7980400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041be59  dc0510774800           -fadd qword ptr [0x487710]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749072) /* 0x487710 */));
    // 0041be5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be62  d91d78c84a00           -fstp dword ptr [0x4ac878]
    app->getMemory<float>(x86::reg32(4900984) /* 0x4ac878 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041be68  c783cc00000005000000   -mov dword ptr [ebx + 0xcc], 5
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 5 /*0x5*/;
    // 0041be72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041be73  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041be76  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041be77:
    // 0041be77  e8b4980400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041be7c  d82578c84a00           -fsub dword ptr [0x4ac878]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4900984) /* 0x4ac878 */));
    // 0041be82  db83c4000000           -fild dword ptr [ebx + 0xc4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(196) /* 0xc4 */))));
    // 0041be88  dc0d10774800           -fmul qword ptr [0x487710]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749072) /* 0x487710 */));
    // 0041be8e  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0041be90  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041be92  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041be95  0f8aaa000000           -jp 0x41bf45
    if (cpu.flags.pf)
    {
        goto L_0x0041bf45;
    }
    // 0041be9b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041be9d  c783c400000000000000   -mov dword ptr [ebx + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
    // 0041bea7  741d                   -je 0x41bec6
    if (cpu.flags.zf)
    {
        goto L_0x0041bec6;
    }
    // 0041bea9  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0041beab  e8f02dffff             -call 0x40eca0
    cpu.esp -= 4;
    sub_40eca0(app, cpu);
    // 0041beb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041beb2  7412                   -je 0x41bec6
    if (cpu.flags.zf)
    {
        goto L_0x0041bec6;
    }
    // 0041beb4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041beb5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041beb6  c783cc00000004000000   -mov dword ptr [ebx + 0xcc], 4
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 4 /*0x4*/;
    // 0041bec0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bec1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bec2  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041bec5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bec6:
    // 0041bec6  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0041bec9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041becb  7512                   -jne 0x41bedf
    if (!cpu.flags.zf)
    {
        goto L_0x0041bedf;
    }
    // 0041becd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bece  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041becf  c783cc00000006000000   -mov dword ptr [ebx + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 0041bed9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041beda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bedb  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041bede  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041bedf:
    // 0041bedf  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041bee1  e87a24ffff             -call 0x40e360
    cpu.esp -= 4;
    sub_40e360(app, cpu);
    // 0041bee6  e8d524ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
L_0x0041beeb:
    // 0041beeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041beec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041beed  c783cc00000001000000   -mov dword ptr [ebx + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 0041bef7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bef8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bef9  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041befc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041befd:
    // 0041befd  8b571c                 -mov edx, dword ptr [edi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041bf00  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041bf02  83e2ef                 -and edx, 0xffffffef
    cpu.edx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0041bf05  c7472000000000         -mov dword ptr [edi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0041bf0c  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041bf0f  89571c                 -mov dword ptr [edi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041bf12  e84924ffff             -call 0x40e360
    cpu.esp -= 4;
    sub_40e360(app, cpu);
    // 0041bf17  c783cc00000007000000   -mov dword ptr [ebx + 0xcc], 7
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 7 /*0x7*/;
    // 0041bf21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bf22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bf23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bf24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bf25  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041bf28  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041bf29:
    // 0041bf29  d94724                 -fld dword ptr [edi + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(36) /* 0x24 */)));
    // 0041bf2c  d85f20                 -fcomp dword ptr [edi + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0041bf2f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041bf31  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041bf34  7a0f                   -jp 0x41bf45
    if (cpu.flags.pf)
    {
        goto L_0x0041bf45;
    }
    // 0041bf36  e88524ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    // 0041bf3b  c783cc00000000000000   -mov dword ptr [ebx + 0xcc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(204) /* 0xcc */) = 0 /*0x0*/;
L_0x0041bf45:
    // 0041bf45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bf46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bf47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bf48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041bf49  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041bf4c  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41bf70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041bf70  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041bf75  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041bf77  05b0040000             -add eax, 0x4b0
    (cpu.eax) += x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 0041bf7c  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 0041bf81  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0041bf84  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0041bf87  c7401c09000000         -mov dword ptr [eax + 0x1c], 9
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 9 /*0x9*/;
    // 0041bf8e  e88db4ffff             -call 0x417420
    cpu.esp -= 4;
    sub_417420(app, cpu);
    // 0041bf93  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041bf99  8991cc000000           -mov dword ptr [ecx + 0xcc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */) = cpu.edx;
    // 0041bf9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41bfa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041bfa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041bfa1  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041bfa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041bfa4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041bfa5  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0041bfa8  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041bfaa  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041bfb0  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041bfb6  83f805                 +cmp eax, 5
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
    // 0041bfb9  0f87a7010000           -ja 0x41c166
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041c166;
    }
    // 0041bfbf  ff248500c24100         -jmp dword ptr [eax*4 + 0x41c200]
    cpu.ip = app->getMemory<x86::reg32>(4309504 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041bfc6:
    // 0041bfc6  39bed0000000           +cmp dword ptr [esi + 0xd0], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041bfcc  7510                   -jne 0x41bfde
    if (!cpu.flags.zf)
    {
        goto L_0x0041bfde;
    }
    // 0041bfce  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 0041bfd3  e8981effff             -call 0x40de70
    cpu.esp -= 4;
    sub_40de70(app, cpu);
    // 0041bfd8  8986d0000000           -mov dword ptr [esi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
L_0x0041bfde:
    // 0041bfde  89bec4000000           -mov dword ptr [esi + 0xc4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.edi;
    // 0041bfe4  893df0bf4a00           -mov dword ptr [0x4abff0], edi
    app->getMemory<x86::reg32>(x86::reg32(4898800) /* 0x4abff0 */) = cpu.edi;
    // 0041bfea  8b8ec4000000           -mov ecx, dword ptr [esi + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041bff0  8b0c8d04024900         -mov ecx, dword ptr [ecx*4 + 0x490204]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784644) /* 0x490204 */ + cpu.ecx * 4);
    // 0041bff7  e86426ffff             -call 0x40e660
    cpu.esp -= 4;
    sub_40e660(app, cpu);
    // 0041bffc  3bc7                   +cmp eax, edi
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
    // 0041bffe  7508                   -jne 0x41c008
    if (!cpu.flags.zf)
    {
        goto L_0x0041c008;
    }
    // 0041c000  89bed0000000           -mov dword ptr [esi + 0xd0], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.edi;
    // 0041c006  eb10                   -jmp 0x41c018
    goto L_0x0041c018;
L_0x0041c008:
    // 0041c008  8b96d0000000           -mov edx, dword ptr [esi + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041c00e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c00f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c010  e863bd0500             -call 0x477d78
    cpu.esp -= 4;
    sub_477d78(app, cpu);
    // 0041c015  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041c018:
    // 0041c018  a1f0bf4a00             -mov eax, dword ptr [0x4abff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4898800) /* 0x4abff0 */);
    // 0041c01d  f7d8                   +neg eax
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
    // 0041c01f  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0041c021  2474                   +and al, 0x74
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(116 /*0x74*/))));
    // 0041c023  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041c026  c786cc00000001000000   -mov dword ptr [esi + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 0041c030  8b0d88c74a00           -mov ecx, dword ptr [0x4ac788]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041c036  e8e5a7ffff             -call 0x416820
    cpu.esp -= 4;
    sub_416820(app, cpu);
    // 0041c03b  e926010000             -jmp 0x41c166
    goto L_0x0041c166;
  case 0x0041c040:
    // 0041c040  d94324                 -fld dword ptr [ebx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 0041c043  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0041c049  8b4b1c                 -mov ecx, dword ptr [ebx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0041c04c  c743200000803f         -mov dword ptr [ebx + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 0041c053  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0041c056  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c059  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041c05b  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041c05e  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0041c063  0f85fd000000           -jne 0x41c166
    if (!cpu.flags.zf)
    {
        goto L_0x0041c166;
    }
    // 0041c069  c786cc00000002000000   -mov dword ptr [esi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 0041c073  e8b8960400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041c078  d99ec8000000           +fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041c07e  e9e3000000             -jmp 0x41c166
    goto L_0x0041c166;
  case 0x0041c083:
    // 0041c083  e8a8960400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041c088  d8a6c8000000           -fsub dword ptr [esi + 0xc8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 0041c08e  dc1d20754800           -fcomp qword ptr [0x487520]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748576) /* 0x487520 */)));
    cpu.fpu.pop();
    // 0041c094  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041c096  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0041c09b  0f85c5000000           -jne 0x41c166
    if (!cpu.flags.zf)
    {
        goto L_0x0041c166;
    }
    // 0041c0a1  c786cc00000003000000   -mov dword ptr [esi + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
    // 0041c0ab  89bec8000000           -mov dword ptr [esi + 0xc8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = cpu.edi;
    // 0041c0b1  e9b0000000             -jmp 0x41c166
    goto L_0x0041c166;
  case 0x0041c0b6:
    // 0041c0b6  d94324                 -fld dword ptr [ebx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 0041c0b9  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041c0bf  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0041c0c2  897b20                 -mov dword ptr [ebx + 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0041c0c5  83e2ef                 -and edx, 0xffffffef
    cpu.edx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0041c0c8  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041c0cb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041c0cd  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041c0d0  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041c0d3  0f8a8d000000           -jp 0x41c166
    if (cpu.flags.pf)
    {
        goto L_0x0041c166;
    }
    // 0041c0d9  c786cc00000004000000   -mov dword ptr [esi + 0xcc], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 4 /*0x4*/;
    // 0041c0e3  e848960400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041c0e8  d99ec8000000           +fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041c0ee  eb76                   -jmp 0x41c166
    goto L_0x0041c166;
  case 0x0041c0f0:
    // 0041c0f0  e83b960400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041c0f5  d8a6c8000000           -fsub dword ptr [esi + 0xc8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 0041c0fb  dc1d18774800           -fcomp qword ptr [0x487718]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749080) /* 0x487718 */)));
    cpu.fpu.pop();
    // 0041c101  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041c103  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0041c108  755c                   -jne 0x41c166
    if (!cpu.flags.zf)
    {
        goto L_0x0041c166;
    }
    // 0041c10a  c786cc00000005000000   -mov dword ptr [esi + 0xcc], 5
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 5 /*0x5*/;
    // 0041c114  89bec8000000           -mov dword ptr [esi + 0xc8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = cpu.edi;
    // 0041c11a  eb4a                   -jmp 0x41c166
    goto L_0x0041c166;
  case 0x0041c11c:
    // 0041c11c  8b96c4000000           -mov edx, dword ptr [esi + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041c122  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041c127  8986cc000000           -mov dword ptr [esi + 0xcc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.eax;
    // 0041c12d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c12f  8986c4000000           -mov dword ptr [esi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0041c135  8b0df0bf4a00           -mov ecx, dword ptr [0x4abff0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4898800) /* 0x4abff0 */);
    // 0041c13b  8d1448                 -lea edx, [eax + ecx*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 2);
    // 0041c13e  8b0c9504024900         -mov ecx, dword ptr [edx*4 + 0x490204]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784644) /* 0x490204 */ + cpu.edx * 4);
    // 0041c145  e81625ffff             -call 0x40e660
    cpu.esp -= 4;
    sub_40e660(app, cpu);
    // 0041c14a  3bc7                   +cmp eax, edi
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
    // 0041c14c  7508                   -jne 0x41c156
    if (!cpu.flags.zf)
    {
        goto L_0x0041c156;
    }
    // 0041c14e  89bed0000000           -mov dword ptr [esi + 0xd0], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.edi;
    // 0041c154  eb10                   -jmp 0x41c166
    goto L_0x0041c166;
L_0x0041c156:
    // 0041c156  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c157  8b86d0000000           -mov eax, dword ptr [esi + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041c15d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c15e  e815bc0500             -call 0x477d78
    cpu.esp -= 4;
    sub_477d78(app, cpu);
    // 0041c163  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041c166:
    // 0041c166  8b7328                 -mov esi, dword ptr [ebx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0041c169  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041c16f  8b89d0000000           -mov ecx, dword ptr [ecx + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0041c175  3bcf                   +cmp ecx, edi
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
    // 0041c177  7408                   -je 0x41c181
    if (cpu.flags.zf)
    {
        goto L_0x0041c181;
    }
    // 0041c179  e8521dffff             -call 0x40ded0
    cpu.esp -= 4;
    sub_40ded0(app, cpu);
    // 0041c17e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041c180  4f                     -dec edi
    (cpu.edi)--;
L_0x0041c181:
    // 0041c181  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041c187  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041c18a  b867666666             -mov eax, 0x66666667
    cpu.eax = 1717986919 /*0x66666667*/;
    // 0041c18f  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0041c192  8b9134d74800           -mov edx, dword ptr [ecx + 0x48d734]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773684) /* 0x48d734 */);
    // 0041c198  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0041c19a  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0041c19d  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041c19f  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0041c1a2  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041c1a4  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041c1a6  3bfb                   +cmp edi, ebx
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
    // 0041c1a8  7501                   -jne 0x41c1ab
    if (!cpu.flags.zf)
    {
        goto L_0x0041c1ab;
    }
    // 0041c1aa  4f                     -dec edi
    (cpu.edi)--;
L_0x0041c1ab:
    // 0041c1ab  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041c1ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c1ae  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041c1af  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0041c1b1  40                     -inc eax
    (cpu.eax)++;
    // 0041c1b2  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041c1b5  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0041c1b8  8d500a                 -lea edx, [eax + 0xa]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0041c1bb  899138d74800           -mov dword ptr [ecx + 0x48d738], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773688) /* 0x48d738 */) = cpu.edx;
    // 0041c1c1  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041c1c7  8b89bc000000           -mov ecx, dword ptr [ecx + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
    // 0041c1cd  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0041c1d0  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0041c1d3  899138d74800           -mov dword ptr [ecx + 0x48d738], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773688) /* 0x48d738 */) = cpu.edx;
    // 0041c1d9  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041c1da  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c1dc  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 0041c1e1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0041c1e3  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c1e5  8b86d4000000           -mov eax, dword ptr [esi + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041c1eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c1ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c1ed  8b80bc000000           -mov eax, dword ptr [eax + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0041c1f3  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041c1f6  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0041c1f9  899130d74800           -mov dword ptr [ecx + 0x48d730], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773680) /* 0x48d730 */) = cpu.edx;
    // 0041c1ff  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41c220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c220  e8eb2dffff             -call 0x40f010
    cpu.esp -= 4;
    sub_40f010(app, cpu);
    // 0041c225  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041c22a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c22c  7423                   -je 0x41c251
    if (cpu.flags.zf)
    {
        goto L_0x0041c251;
    }
    // 0041c22e  8b8088090000           -mov eax, dword ptr [eax + 0x988]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2440) /* 0x988 */);
    // 0041c234  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c236  7424                   -je 0x41c25c
    if (cpu.flags.zf)
    {
        goto L_0x0041c25c;
    }
    // 0041c238  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041c23e  c740680000a041         -mov dword ptr [eax + 0x68], 0x41a00000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */) = 1101004800 /*0x41a00000*/;
    // 0041c245  c7407000000000         -mov dword ptr [eax + 0x70], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0041c24c  e91ffdffff             -jmp 0x41bf70
    return sub_41bf70(app, cpu);
L_0x0041c251:
    // 0041c251  68e80c4900             -push 0x490ce8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787432 /*0x490ce8*/;
    cpu.esp -= 4;
    // 0041c256  e8b5890000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041c25b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041c25c:
    // 0041c25c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41c260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c260  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c261  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c263  8b0d38165200           -mov ecx, dword ptr [0x521638]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379640) /* 0x521638 */);
    // 0041c269  66a136165200           -mov ax, word ptr [0x521636]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5379638) /* 0x521636 */);
    // 0041c26f  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0041c275  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0041c279  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0041c27d  894c2400               -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0041c281  d80db0754800           -fmul dword ptr [0x4875b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748720) /* 0x4875b0 */));
    // 0041c287  d91d8cc84a00           -fstp dword ptr [0x4ac88c]
    app->getMemory<float>(x86::reg32(4901004) /* 0x4ac88c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041c28d  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0041c291  d80dac754800           -fmul dword ptr [0x4875ac]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748716) /* 0x4875ac */));
    // 0041c297  d91d90c84a00           -fstp dword ptr [0x4ac890]
    app->getMemory<float>(x86::reg32(4901008) /* 0x4ac890 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041c29d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c29e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41c2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c2a0  a1d8c84a00             -mov eax, dword ptr [0x4ac8d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */);
    // 0041c2a5  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041c2ab  83f908                 +cmp ecx, 8
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
    // 0041c2ae  7512                   -jne 0x41c2c2
    if (!cpu.flags.zf)
    {
        goto L_0x0041c2c2;
    }
    // 0041c2b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c2b2  7e30                   -jle 0x41c2e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041c2e4;
    }
    // 0041c2b4  48                     -dec eax
    (cpu.eax)--;
    // 0041c2b5  a3d8c84a00             -mov dword ptr [0x4ac8d8], eax
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.eax;
    // 0041c2ba  c68098c84a0000         -mov byte ptr [eax + 0x4ac898], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4901016) /* 0x4ac898 */) = 0 /*0x0*/;
    // 0041c2c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c2c2:
    // 0041c2c2  83f81e                 +cmp eax, 0x1e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c2c5  7f1d                   -jg 0x41c2e4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041c2e4;
    }
    // 0041c2c7  83f940                 +cmp ecx, 0x40
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
    // 0041c2ca  7505                   -jne 0x41c2d1
    if (!cpu.flags.zf)
    {
        goto L_0x0041c2d1;
    }
    // 0041c2cc  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
L_0x0041c2d1:
    // 0041c2d1  888898c84a00           -mov byte ptr [eax + 0x4ac898], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4901016) /* 0x4ac898 */) = cpu.cl;
    // 0041c2d7  40                     -inc eax
    (cpu.eax)++;
    // 0041c2d8  a3d8c84a00             -mov dword ptr [0x4ac8d8], eax
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.eax;
    // 0041c2dd  c68098c84a0000         -mov byte ptr [eax + 0x4ac898], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4901016) /* 0x4ac898 */) = 0 /*0x0*/;
L_0x0041c2e4:
    // 0041c2e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41c2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c2f0  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041c2f5  05f0030000             -add eax, 0x3f0
    (cpu.eax) += x86::reg32(x86::sreg32(1008 /*0x3f0*/));
    // 0041c2fa  8b4828                 -mov ecx, dword ptr [eax + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041c2fd  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0041c303  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041c305  898acc000000           -mov dword ptr [edx + 0xcc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(204) /* 0xcc */) = cpu.ecx;
    // 0041c30b  880d98c84a00           -mov byte ptr [0x4ac898], cl
    app->getMemory<x86::reg8>(x86::reg32(4901016) /* 0x4ac898 */) = cpu.cl;
    // 0041c311  890dd8c84a00           -mov dword ptr [0x4ac8d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.ecx;
    // 0041c317  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0041c31a  83e2ef                 -and edx, 0xffffffef
    cpu.edx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0041c31d  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0041c320  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041c323  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0041c326  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041c329  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41c330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041c330  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c331  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041c332  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c333  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c334  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041c336  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041c339  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041c33f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041c343  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041c349  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041c34f  83f803                 +cmp eax, 3
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
    // 0041c352  0f872f020000           -ja 0x41c587
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041c587;
    }
    // 0041c358  ff2485c0c54100         -jmp dword ptr [eax*4 + 0x41c5c0]
    cpu.ip = app->getMemory<x86::reg32>(4310464 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041c35f:
    // 0041c35f  b141                   -mov cl, 0x41
    cpu.cl = 65 /*0x41*/;
    // 0041c361  e87a680400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0041c366  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c368  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c36a  7462                   -je 0x41c3ce
    if (cpu.flags.zf)
    {
        goto L_0x0041c3ce;
    }
    // 0041c36c  833d8ca4510001         +cmp dword ptr [0x51a48c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c373  7559                   -jne 0x41c3ce
    if (!cpu.flags.zf)
    {
        goto L_0x0041c3ce;
    }
    // 0041c375  833ddcc84a0004         +cmp dword ptr [0x4ac8dc], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4901084) /* 0x4ac8dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c37c  7526                   -jne 0x41c3a4
    if (!cpu.flags.zf)
    {
        goto L_0x0041c3a4;
    }
    // 0041c37e  e8ad930400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041c383  d905e0c84a00           -fld dword ptr [0x4ac8e0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4901088) /* 0x4ac8e0 */)));
    // 0041c389  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0041c38b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041c38d  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041c392  0f84ef010000           -je 0x41c587
    if (cpu.flags.zf)
    {
        goto L_0x0041c587;
    }
    // 0041c398  891de0c84a00           -mov dword ptr [0x4ac8e0], ebx
    app->getMemory<x86::reg32>(x86::reg32(4901088) /* 0x4ac8e0 */) = cpu.ebx;
    // 0041c39e  891ddcc84a00           -mov dword ptr [0x4ac8dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(4901084) /* 0x4ac8dc */) = cpu.ebx;
L_0x0041c3a4:
    // 0041c3a4  391d24d44a00           +cmp dword ptr [0x4ad424], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4903972) /* 0x4ad424 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c3aa  740c                   -je 0x41c3b8
    if (cpu.flags.zf)
    {
        goto L_0x0041c3b8;
    }
    // 0041c3ac  c786c400000001000000   -mov dword ptr [esi + 0xc4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = 1 /*0x1*/;
    // 0041c3b6  eb0a                   -jmp 0x41c3c2
    goto L_0x0041c3c2;
L_0x0041c3b8:
    // 0041c3b8  c786c400000002000000   -mov dword ptr [esi + 0xc4], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = 2 /*0x2*/;
L_0x0041c3c2:
    // 0041c3c2  881d98c84a00           -mov byte ptr [0x4ac898], bl
    app->getMemory<x86::reg8>(x86::reg32(4901016) /* 0x4ac898 */) = cpu.bl;
    // 0041c3c8  891dd8c84a00           -mov dword ptr [0x4ac8d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.ebx;
L_0x0041c3ce:
    // 0041c3ce  b142                   -mov cl, 0x42
    cpu.cl = 66 /*0x42*/;
    // 0041c3d0  e80b680400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0041c3d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c3d7  7452                   -je 0x41c42b
    if (cpu.flags.zf)
    {
        goto L_0x0041c42b;
    }
    // 0041c3d9  833d8ca4510001         +cmp dword ptr [0x51a48c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c3e0  7549                   -jne 0x41c42b
    if (!cpu.flags.zf)
    {
        goto L_0x0041c42b;
    }
    // 0041c3e2  833ddcc84a0004         +cmp dword ptr [0x4ac8dc], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4901084) /* 0x4ac8dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c3e9  752a                   -jne 0x41c415
    if (!cpu.flags.zf)
    {
        goto L_0x0041c415;
    }
    // 0041c3eb  e840930400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041c3f0  d905e0c84a00           -fld dword ptr [0x4ac8e0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4901088) /* 0x4ac8e0 */)));
    // 0041c3f6  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0041c3f8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041c3fa  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041c3ff  0f8482010000           -je 0x41c587
    if (cpu.flags.zf)
    {
        goto L_0x0041c587;
    }
    // 0041c405  c705e0c84a0000000000   -mov dword ptr [0x4ac8e0], 0
    app->getMemory<x86::reg32>(x86::reg32(4901088) /* 0x4ac8e0 */) = 0 /*0x0*/;
    // 0041c40f  891ddcc84a00           -mov dword ptr [0x4ac8dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(4901084) /* 0x4ac8dc */) = cpu.ebx;
L_0x0041c415:
    // 0041c415  c786c400000002000000   -mov dword ptr [esi + 0xc4], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = 2 /*0x2*/;
    // 0041c41f  881d98c84a00           -mov byte ptr [0x4ac898], bl
    app->getMemory<x86::reg8>(x86::reg32(4901016) /* 0x4ac898 */) = cpu.bl;
    // 0041c425  891dd8c84a00           -mov dword ptr [0x4ac8d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.ebx;
L_0x0041c42b:
    // 0041c42b  b138                   -mov cl, 0x38
    cpu.cl = 56 /*0x38*/;
    // 0041c42d  e8ae670400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0041c432  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c434  7421                   -je 0x41c457
    if (cpu.flags.zf)
    {
        goto L_0x0041c457;
    }
    // 0041c436  b11f                   -mov cl, 0x1f
    cpu.cl = 31 /*0x1f*/;
    // 0041c438  e8a3670400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0041c43d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c43f  7416                   -je 0x41c457
    if (cpu.flags.zf)
    {
        goto L_0x0041c457;
    }
    // 0041c441  c786c400000004000000   -mov dword ptr [esi + 0xc4], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = 4 /*0x4*/;
    // 0041c44b  881d98c84a00           -mov byte ptr [0x4ac898], bl
    app->getMemory<x86::reg8>(x86::reg32(4901016) /* 0x4ac898 */) = cpu.bl;
    // 0041c451  891dd8c84a00           -mov dword ptr [0x4ac8d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.ebx;
L_0x0041c457:
    // 0041c457  399ec4000000           +cmp dword ptr [esi + 0xc4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c45d  0f8424010000           -je 0x41c587
    if (cpu.flags.zf)
    {
        goto L_0x0041c587;
    }
    // 0041c463  8b4f1c                 -mov ecx, dword ptr [edi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041c466  c747200000803f         -mov dword ptr [edi + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 0041c46d  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0041c470  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041c475  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041c478  894f1c                 -mov dword ptr [edi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041c47b  8b8ec4000000           -mov ecx, dword ptr [esi + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041c481  3bc8                   +cmp ecx, eax
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
    // 0041c483  8986cc000000           -mov dword ptr [esi + 0xcc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.eax;
    // 0041c489  7544                   -jne 0x41c4cf
    if (!cpu.flags.zf)
    {
        goto L_0x0041c4cf;
    }
    // 0041c48b  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041c491  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041c496  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0041c499  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041c49b  389926030000           +cmp byte ptr [ecx + 0x326], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(806) /* 0x326 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041c4a1  7416                   -je 0x41c4b9
    if (cpu.flags.zf)
    {
        goto L_0x0041c4b9;
    }
    // 0041c4a3  b970ce4800             -mov ecx, 0x48ce70
    cpu.ecx = 4771440 /*0x48ce70*/;
    // 0041c4a8  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c4ae  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041c4b2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0041c4b4  e9ce000000             -jmp 0x41c587
    goto L_0x0041c587;
L_0x0041c4b9:
    // 0041c4b9  b964ce4800             -mov ecx, 0x48ce64
    cpu.ecx = 4771428 /*0x48ce64*/;
    // 0041c4be  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c4c4  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041c4c8  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041c4ca  e9b8000000             -jmp 0x41c587
    goto L_0x0041c587;
L_0x0041c4cf:
    // 0041c4cf  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041c4d1  b988ce4800             -mov ecx, 0x48ce88
    cpu.ecx = 4771464 /*0x48ce88*/;
    // 0041c4d6  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041c4dc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041c4e0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0041c4e2  e9a0000000             -jmp 0x41c587
    goto L_0x0041c587;
  case 0x0041c4e7:
    // 0041c4e7  e894e10300             -call 0x45a680
    cpu.esp -= 4;
    sub_45a680(app, cpu);
    // 0041c4ec  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0041c4ee  e8ed660400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0041c4f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c4f5  740f                   -je 0x41c506
    if (cpu.flags.zf)
    {
        goto L_0x0041c506;
    }
    // 0041c4f7  e8b4e10300             -call 0x45a6b0
    cpu.esp -= 4;
    sub_45a6b0(app, cpu);
    // 0041c4fc  e8effdffff             -call 0x41c2f0
    cpu.esp -= 4;
    sub_41c2f0(app, cpu);
    // 0041c501  e981000000             -jmp 0x41c587
    goto L_0x0041c587;
L_0x0041c506:
    // 0041c506  b11c                   -mov cl, 0x1c
    cpu.cl = 28 /*0x1c*/;
    // 0041c508  e8d3660400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0041c50d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c50f  7576                   -jne 0x41c587
    if (!cpu.flags.zf)
    {
        goto L_0x0041c587;
    }
    // 0041c511  a1e4c84a00             -mov eax, dword ptr [0x4ac8e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901092) /* 0x4ac8e4 */);
    // 0041c516  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c518  3bc3                   +cmp eax, ebx
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
    // 0041c51a  746b                   -je 0x41c587
    if (cpu.flags.zf)
    {
        goto L_0x0041c587;
    }
    // 0041c51c  891de4c84a00           -mov dword ptr [0x4ac8e4], ebx
    app->getMemory<x86::reg32>(x86::reg32(4901092) /* 0x4ac8e4 */) = cpu.ebx;
    // 0041c522  e889e10300             -call 0x45a6b0
    cpu.esp -= 4;
    sub_45a6b0(app, cpu);
    // 0041c527  c786cc00000002000000   -mov dword ptr [esi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 0041c531  eb54                   -jmp 0x41c587
    goto L_0x0041c587;
  case 0x0041c533:
    // 0041c533  8b96c4000000           -mov edx, dword ptr [esi + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 0041c539  b998c84a00             -mov ecx, 0x4ac898
    cpu.ecx = 4901016 /*0x4ac898*/;
    // 0041c53e  e86d050000             -call 0x41cab0
    cpu.esp -= 4;
    sub_41cab0(app, cpu);
    // 0041c543  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041c546  c7472000000000         -mov dword ptr [edi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0041c54d  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0041c54f  0c20                   +or al, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0041c551  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041c554  c786cc00000003000000   -mov dword ptr [esi + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
    // 0041c55e  eb27                   -jmp 0x41c587
    goto L_0x0041c587;
  case 0x0041c560:
    // 0041c560  d94724                 -fld dword ptr [edi + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(36) /* 0x24 */)));
    // 0041c563  d85f20                 -fcomp dword ptr [edi + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0041c566  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041c568  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041c56b  7a1a                   -jp 0x41c587
    if (cpu.flags.pf)
    {
        goto L_0x0041c587;
    }
    // 0041c56d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041c56f  899ecc000000           -mov dword ptr [esi + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 0041c575  881d98c84a00           -mov byte ptr [0x4ac898], bl
    app->getMemory<x86::reg8>(x86::reg32(4901016) /* 0x4ac898 */) = cpu.bl;
    // 0041c57b  891dd8c84a00           -mov dword ptr [0x4ac8d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = cpu.ebx;
    // 0041c581  899ec4000000           -mov dword ptr [esi + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
L_0x0041c587:
    // 0041c587  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0041c58c  6898c84a00             -push 0x4ac898
    app->getMemory<x86::reg32>(cpu.esp-4) = 4901016 /*0x4ac898*/;
    cpu.esp -= 4;
    // 0041c591  6840195200             -push 0x521940
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380416 /*0x521940*/;
    cpu.esp -= 4;
    // 0041c596  e892b90500             -call 0x477f2d
    cpu.esp -= 4;
    sub_477f2d(app, cpu);
    // 0041c59b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c59e  b11c                   -mov cl, 0x1c
    cpu.cl = 28 /*0x1c*/;
    // 0041c5a0  c786d000000040195200   -mov dword ptr [esi + 0xd0], 0x521940
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = 5380416 /*0x521940*/;
    // 0041c5aa  e831660400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0041c5af  f7d8                   +neg eax
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
    // 0041c5b1  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0041c5b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c5b4  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0041c5b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c5b7  a3e4c84a00             -mov dword ptr [0x4ac8e4], eax
    app->getMemory<x86::reg32>(x86::reg32(4901092) /* 0x4ac8e4 */) = cpu.eax;
    // 0041c5bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c5bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c5be  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41c5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c5d0  a198024900             -mov eax, dword ptr [0x490298]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784792) /* 0x490298 */);
    // 0041c5d5  83f8ff                 +cmp eax, -1
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
    // 0041c5d8  7414                   -je 0x41c5ee
    if (cpu.flags.zf)
    {
        goto L_0x0041c5ee;
    }
    // 0041c5da  ba98024900             -mov edx, 0x490298
    cpu.edx = 4784792 /*0x490298*/;
L_0x0041c5df:
    // 0041c5df  3bc8                   +cmp ecx, eax
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
    // 0041c5e1  740e                   -je 0x41c5f1
    if (cpu.flags.zf)
    {
        goto L_0x0041c5f1;
    }
    // 0041c5e3  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0041c5e6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c5e9  83f8ff                 +cmp eax, -1
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
    // 0041c5ec  75f1                   -jne 0x41c5df
    if (!cpu.flags.zf)
    {
        goto L_0x0041c5df;
    }
L_0x0041c5ee:
    // 0041c5ee  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c5f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c5f1:
    // 0041c5f1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041c5f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41c600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c600  8b1598024900           -mov edx, dword ptr [0x490298]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784792) /* 0x490298 */);
    // 0041c606  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041c608  83faff                 +cmp edx, -1
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
    // 0041c60b  7411                   -je 0x41c61e
    if (cpu.flags.zf)
    {
        goto L_0x0041c61e;
    }
L_0x0041c60d:
    // 0041c60d  3bca                   +cmp ecx, edx
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
    // 0041c60f  740f                   -je 0x41c620
    if (cpu.flags.zf)
    {
        goto L_0x0041c620;
    }
    // 0041c611  8b14859c024900         -mov edx, dword ptr [eax*4 + 0x49029c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784796) /* 0x49029c */ + cpu.eax * 4);
    // 0041c618  40                     -inc eax
    (cpu.eax)++;
    // 0041c619  83faff                 +cmp edx, -1
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
    // 0041c61c  75ef                   -jne 0x41c60d
    if (!cpu.flags.zf)
    {
        goto L_0x0041c60d;
    }
L_0x0041c61e:
    // 0041c61e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0041c620:
    // 0041c620  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41c630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c630  e8cbffffff             -call 0x41c600
    cpu.esp -= 4;
    sub_41c600(app, cpu);
    // 0041c635  8b0c859c024900         -mov ecx, dword ptr [eax*4 + 0x49029c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784796) /* 0x49029c */ + cpu.eax * 4);
    // 0041c63c  40                     -inc eax
    (cpu.eax)++;
    // 0041c63d  83f9ff                 +cmp ecx, -1
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
    // 0041c640  7502                   -jne 0x41c644
    if (!cpu.flags.zf)
    {
        goto L_0x0041c644;
    }
    // 0041c642  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0041c644:
    // 0041c644  8b048598024900         -mov eax, dword ptr [eax*4 + 0x490298]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784792) /* 0x490298 */ + cpu.eax * 4);
    // 0041c64b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41c650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041c650  81ec94000000           -sub esp, 0x94
    (cpu.esp) -= x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c656  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c657  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041c659  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041c65a  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0041c65c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0041c65e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041c660  7416                   -je 0x41c678
    if (cpu.flags.zf)
    {
        goto L_0x0041c678;
    }
L_0x0041c662:
    // 0041c662  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0041c665  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c666  e832ae0500             -call 0x47749d
    cpu.esp -= 4;
    sub_47749d(app, cpu);
    // 0041c66b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c66e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0041c670  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0041c673  47                     -inc edi
    (cpu.edi)++;
    // 0041c674  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041c676  75ea                   -jne 0x41c662
    if (!cpu.flags.zf)
    {
        goto L_0x0041c662;
    }
L_0x0041c678:
    // 0041c678  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0041c67a  680c0e4900             -push 0x490e0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787724 /*0x490e0c*/;
    cpu.esp -= 4;
    // 0041c67f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c680  e8abd80500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0041c685  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c688  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c68a  7537                   -jne 0x41c6c3
    if (!cpu.flags.zf)
    {
        goto L_0x0041c6c3;
    }
    // 0041c68c  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041c690  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c691  68000e4900             -push 0x490e00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787712 /*0x490e00*/;
    cpu.esp -= 4;
    // 0041c696  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c697  e8b8af0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c69c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c69f  e84cbd0300             -call 0x4583f0
    cpu.esp -= 4;
    sub_4583f0(app, cpu);
    // 0041c6a4  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041c6a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c6a9  e85aba0500             -call 0x478108
    cpu.esp -= 4;
    sub_478108(app, cpu);
    // 0041c6ae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041c6b1  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041c6b5  e896bc0300             -call 0x458350
    cpu.esp -= 4;
    sub_458350(app, cpu);
    // 0041c6ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c6bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c6bc  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c6c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c6c3:
    // 0041c6c3  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0041c6c5  68f80d4900             -push 0x490df8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787704 /*0x490df8*/;
    cpu.esp -= 4;
    // 0041c6ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c6cb  e860d80500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0041c6d0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c6d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c6d5  7525                   -jne 0x41c6fc
    if (!cpu.flags.zf)
    {
        goto L_0x0041c6fc;
    }
    // 0041c6d7  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041c6db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c6dc  68f00d4900             -push 0x490df0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787696 /*0x490df0*/;
    cpu.esp -= 4;
    // 0041c6e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c6e2  e86daf0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c6e7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c6ea  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041c6ee  e85dbc0300             -call 0x458350
    cpu.esp -= 4;
    sub_458350(app, cpu);
    // 0041c6f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c6f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c6f5  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c6fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c6fc:
    // 0041c6fc  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041c6fe  68e80d4900             -push 0x490de8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787688 /*0x490de8*/;
    cpu.esp -= 4;
    // 0041c703  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c704  e827d80500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0041c709  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c70c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c70e  750d                   -jne 0x41c71d
    if (!cpu.flags.zf)
    {
        goto L_0x0041c71d;
    }
    // 0041c710  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c711  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c712  81c494000000           +add esp, 0x94
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(148 /*0x94*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041c718  e9d3bc0300             -jmp 0x4583f0
    return sub_4583f0(app, cpu);
L_0x0041c71d:
    // 0041c71d  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c721  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c722  68d80d4900             -push 0x490dd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787672 /*0x490dd8*/;
    cpu.esp -= 4;
    // 0041c727  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c728  e827af0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c72d  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0041c732  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c735  3bc7                   +cmp eax, edi
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
    // 0041c737  7531                   -jne 0x41c76a
    if (!cpu.flags.zf)
    {
        goto L_0x0041c76a;
    }
    // 0041c739  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c73d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c73f  0f8e3c030000           -jle 0x41ca81
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041ca81;
    }
    // 0041c745  83f814                 +cmp eax, 0x14
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
    // 0041c748  0f8f33030000           -jg 0x41ca81
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041ca81;
    }
    // 0041c74e  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041c752  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c753  dc0de0724800           -fmul qword ptr [0x4872e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748000) /* 0x4872e0 */));
    // 0041c759  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041c75c  e87fdf0300             -call 0x45a6e0
    cpu.esp -= 4;
    sub_45a6e0(app, cpu);
    // 0041c761  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c762  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c763  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c769  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c76a:
    // 0041c76a  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c76e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c76f  68cc0d4900             -push 0x490dcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787660 /*0x490dcc*/;
    cpu.esp -= 4;
    // 0041c774  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c775  e8daae0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c77a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c77d  3bc7                   +cmp eax, edi
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
    // 0041c77f  7536                   -jne 0x41c7b7
    if (!cpu.flags.zf)
    {
        goto L_0x0041c7b7;
    }
    // 0041c781  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c785  83f864                 +cmp eax, 0x64
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c788  0f8cf3020000           -jl 0x41ca81
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ca81;
    }
    // 0041c78e  3dd0070000             +cmp eax, 0x7d0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2000 /*0x7d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c793  0f8fe8020000           -jg 0x41ca81
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041ca81;
    }
    // 0041c799  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041c79d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c79e  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0041c7a4  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041c7a7  e894650300             -call 0x452d40
    cpu.esp -= 4;
    sub_452d40(app, cpu);
    // 0041c7ac  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041c7ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c7af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c7b0  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c7b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c7b7:
    // 0041c7b7  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 0041c7b9  68bc0d4900             -push 0x490dbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787644 /*0x490dbc*/;
    cpu.esp -= 4;
    // 0041c7be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c7bf  e86cd70500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0041c7c4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c7c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c7c9  7513                   -jne 0x41c7de
    if (!cpu.flags.zf)
    {
        goto L_0x0041c7de;
    }
    // 0041c7cb  893d78d34a00           -mov dword ptr [0x4ad378], edi
    app->getMemory<x86::reg32>(x86::reg32(4903800) /* 0x4ad378 */) = cpu.edi;
    // 0041c7d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c7d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c7d3  81c494000000           +add esp, 0x94
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(148 /*0x94*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041c7d9  e9224e0300             -jmp 0x451600
    return sub_451600(app, cpu);
L_0x0041c7de:
    // 0041c7de  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 0041c7e0  68ac0d4900             -push 0x490dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787628 /*0x490dac*/;
    cpu.esp -= 4;
    // 0041c7e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c7e6  e845d70500             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 0041c7eb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c7ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c7f0  750e                   -jne 0x41c800
    if (!cpu.flags.zf)
    {
        goto L_0x0041c800;
    }
    // 0041c7f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c7f3  a378d34a00             -mov dword ptr [0x4ad378], eax
    app->getMemory<x86::reg32>(x86::reg32(4903800) /* 0x4ad378 */) = cpu.eax;
    // 0041c7f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c7f9  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c7ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c800:
    // 0041c800  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0041c802  68a40d4900             -push 0x490da4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787620 /*0x490da4*/;
    cpu.esp -= 4;
    // 0041c807  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c808  e8c3b80500             -call 0x4780d0
    cpu.esp -= 4;
    _strncmp(app, cpu);
    // 0041c80d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c810  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c812  750f                   -jne 0x41c823
    if (!cpu.flags.zf)
    {
        goto L_0x0041c823;
    }
    // 0041c814  893d74d34a00           -mov dword ptr [0x4ad374], edi
    app->getMemory<x86::reg32>(x86::reg32(4903796) /* 0x4ad374 */) = cpu.edi;
    // 0041c81a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c81b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c81c  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c822  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c823:
    // 0041c823  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0041c825  689c0d4900             -push 0x490d9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787612 /*0x490d9c*/;
    cpu.esp -= 4;
    // 0041c82a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c82b  e8a0b80500             -call 0x4780d0
    cpu.esp -= 4;
    _strncmp(app, cpu);
    // 0041c830  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c833  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c835  750e                   -jne 0x41c845
    if (!cpu.flags.zf)
    {
        goto L_0x0041c845;
    }
    // 0041c837  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c838  a374d34a00             -mov dword ptr [0x4ad374], eax
    app->getMemory<x86::reg32>(x86::reg32(4903796) /* 0x4ad374 */) = cpu.eax;
    // 0041c83d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c83e  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c844  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c845:
    // 0041c845  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041c849  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041c84d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c84e  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041c852  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c853  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041c857  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c858  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c859  68880d4900             -push 0x490d88
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787592 /*0x490d88*/;
    cpu.esp -= 4;
    // 0041c85e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c85f  e8f0ad0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c864  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041c867  83f804                 +cmp eax, 4
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
    // 0041c86a  7512                   -jne 0x41c87e
    if (!cpu.flags.zf)
    {
        goto L_0x0041c87e;
    }
    // 0041c86c  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041c870  e8db980000             -call 0x426150
    cpu.esp -= 4;
    sub_426150(app, cpu);
    // 0041c875  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c877  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c87d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c87e:
    // 0041c87e  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c882  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c883  687c0d4900             -push 0x490d7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787580 /*0x490d7c*/;
    cpu.esp -= 4;
    // 0041c888  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c889  e8c6ad0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c88e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c891  3bc7                   +cmp eax, edi
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
    // 0041c893  751f                   -jne 0x41c8b4
    if (!cpu.flags.zf)
    {
        goto L_0x0041c8b4;
    }
    // 0041c895  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c899  e832fdffff             -call 0x41c5d0
    cpu.esp -= 4;
    sub_41c5d0(app, cpu);
    // 0041c89e  3bc7                   +cmp eax, edi
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
    // 0041c8a0  0f85db010000           -jne 0x41ca81
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca81;
    }
    // 0041c8a6  e8e59e0000             -call 0x426790
    cpu.esp -= 4;
    sub_426790(app, cpu);
    // 0041c8ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c8ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c8ad  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c8b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c8b4:
    // 0041c8b4  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041c8b6  68740d4900             -push 0x490d74
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787572 /*0x490d74*/;
    cpu.esp -= 4;
    // 0041c8bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c8bc  e80fb80500             -call 0x4780d0
    cpu.esp -= 4;
    _strncmp(app, cpu);
    // 0041c8c1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c8c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c8c6  7525                   -jne 0x41c8ed
    if (!cpu.flags.zf)
    {
        goto L_0x0041c8ed;
    }
    // 0041c8c8  8b0d10155200           -mov ecx, dword ptr [0x521510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 0041c8ce  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041c8d4  e857fdffff             -call 0x41c630
    cpu.esp -= 4;
    sub_41c630(app, cpu);
    // 0041c8d9  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041c8db  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041c8df  e8ac9e0000             -call 0x426790
    cpu.esp -= 4;
    sub_426790(app, cpu);
    // 0041c8e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c8e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c8e6  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c8ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c8ed:
    // 0041c8ed  393d8ca45100           +cmp dword ptr [0x51a48c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c8f3  0f8588010000           -jne 0x41ca81
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca81;
    }
    // 0041c8f9  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c8fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c8fe  68640d4900             -push 0x490d64
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787556 /*0x490d64*/;
    cpu.esp -= 4;
    // 0041c903  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c904  e84bad0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c909  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c90c  3bc7                   +cmp eax, edi
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
    // 0041c90e  7524                   -jne 0x41c934
    if (!cpu.flags.zf)
    {
        goto L_0x0041c934;
    }
    // 0041c910  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041c915  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c917  0f8564010000           -jne 0x41ca81
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca81;
    }
    // 0041c91d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c921  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0041c923  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041c926  e8259d0300             -call 0x456650
    cpu.esp -= 4;
    sub_456650(app, cpu);
    // 0041c92b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c92c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c92d  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c933  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c934:
    // 0041c934  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c938  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c939  68580d4900             -push 0x490d58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787544 /*0x490d58*/;
    cpu.esp -= 4;
    // 0041c93e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c93f  e810ad0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c944  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c947  3bc7                   +cmp eax, edi
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
    // 0041c949  7523                   -jne 0x41c96e
    if (!cpu.flags.zf)
    {
        goto L_0x0041c96e;
    }
    // 0041c94b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c94f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041c951  0f8c2a010000           -jl 0x41ca81
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ca81;
    }
    // 0041c957  83f906                 +cmp ecx, 6
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041c95a  0f8f21010000           -jg 0x41ca81
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041ca81;
    }
    // 0041c960  e86bdb0300             -call 0x45a4d0
    cpu.esp -= 4;
    sub_45a4d0(app, cpu);
    // 0041c965  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c966  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c967  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c96d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c96e:
    // 0041c96e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041c970  68500d4900             -push 0x490d50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787536 /*0x490d50*/;
    cpu.esp -= 4;
    // 0041c975  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c976  e855b70500             -call 0x4780d0
    cpu.esp -= 4;
    _strncmp(app, cpu);
    // 0041c97b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c97e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c980  750d                   -jne 0x41c98f
    if (!cpu.flags.zf)
    {
        goto L_0x0041c98f;
    }
    // 0041c982  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c983  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c984  81c494000000           +add esp, 0x94
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(148 /*0x94*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041c98a  e9e1900300             -jmp 0x455a70
    return sub_455a70(app, cpu);
L_0x0041c98f:
    // 0041c98f  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c993  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041c994  68400d4900             -push 0x490d40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787520 /*0x490d40*/;
    cpu.esp -= 4;
    // 0041c999  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c99a  e8b5ac0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c99f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c9a2  3bc7                   +cmp eax, edi
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
    // 0041c9a4  7524                   -jne 0x41c9ca
    if (!cpu.flags.zf)
    {
        goto L_0x0041c9ca;
    }
    // 0041c9a6  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041c9ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c9ad  0f85ce000000           -jne 0x41ca81
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca81;
    }
    // 0041c9b3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c9b7  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0041c9b9  83caff                 -or edx, 0xffffffff
    cpu.edx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041c9bc  e88f9c0300             -call 0x456650
    cpu.esp -= 4;
    sub_456650(app, cpu);
    // 0041c9c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c9c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c9c3  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041c9c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041c9ca:
    // 0041c9ca  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c9ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041c9cf  68300d4900             -push 0x490d30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787504 /*0x490d30*/;
    cpu.esp -= 4;
    // 0041c9d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041c9d5  e87aac0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041c9da  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041c9dd  3bc7                   +cmp eax, edi
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
    // 0041c9df  7526                   -jne 0x41ca07
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca07;
    }
    // 0041c9e1  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041c9e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041c9e8  0f8593000000           -jne 0x41ca81
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca81;
    }
    // 0041c9ee  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041c9f2  83caff                 -or edx, 0xffffffff
    cpu.edx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041c9f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041c9f6  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041c9f9  e8529c0300             -call 0x456650
    cpu.esp -= 4;
    sub_456650(app, cpu);
    // 0041c9fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041c9ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ca00  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041ca06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ca07:
    // 0041ca07  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ca0b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ca0c  68280d4900             -push 0x490d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787496 /*0x490d28*/;
    cpu.esp -= 4;
    // 0041ca11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ca12  e83dac0500             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 0041ca17  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041ca1a  3bc7                   +cmp eax, edi
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
    // 0041ca1c  7512                   -jne 0x41ca30
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca30;
    }
    // 0041ca1e  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ca22  e849990000             -call 0x426370
    cpu.esp -= 4;
    sub_426370(app, cpu);
    // 0041ca27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ca28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ca29  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041ca2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ca30:
    // 0041ca30  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0041ca32  681c0d4900             -push 0x490d1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787484 /*0x490d1c*/;
    cpu.esp -= 4;
    // 0041ca37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ca38  e893b60500             -call 0x4780d0
    cpu.esp -= 4;
    _strncmp(app, cpu);
    // 0041ca3d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041ca40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ca42  7519                   -jne 0x41ca5d
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca5d;
    }
    // 0041ca44  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041ca49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ca4b  7534                   -jne 0x41ca81
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca81;
    }
    // 0041ca4d  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041ca4f  e8ccb70300             -call 0x458220
    cpu.esp -= 4;
    sub_458220(app, cpu);
    // 0041ca54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ca55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ca56  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041ca5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ca5d:
    // 0041ca5d  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 0041ca5f  68100d4900             -push 0x490d10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787472 /*0x490d10*/;
    cpu.esp -= 4;
    // 0041ca64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ca65  e866b60500             -call 0x4780d0
    cpu.esp -= 4;
    _strncmp(app, cpu);
    // 0041ca6a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041ca6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ca6f  7510                   -jne 0x41ca81
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca81;
    }
    // 0041ca71  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041ca76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ca78  7507                   -jne 0x41ca81
    if (!cpu.flags.zf)
    {
        goto L_0x0041ca81;
    }
    // 0041ca7a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ca7c  e89fb70300             -call 0x458220
    cpu.esp -= 4;
    sub_458220(app, cpu);
L_0x0041ca81:
    // 0041ca81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ca82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ca83  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0041ca89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ca90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ca90  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041ca92  6800004040             -push 0x40400000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1077936128 /*0x40400000*/;
    cpu.esp -= 4;
    // 0041ca97  ba7c024900             -mov edx, 0x49027c
    cpu.edx = 4784764 /*0x49027c*/;
    // 0041ca9c  e83f24ffff             -call 0x40eee0
    cpu.esp -= 4;
    sub_40eee0(app, cpu);
    // 0041caa1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41cab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cab0  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041cab3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cab4  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041cab6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cab7  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041caba  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041cabc  7507                   -jne 0x41cac5
    if (!cpu.flags.zf)
    {
        goto L_0x0041cac5;
    }
    // 0041cabe  e88dfbffff             -call 0x41c650
    cpu.esp -= 4;
    sub_41c650(app, cpu);
    // 0041cac3  eb5d                   -jmp 0x41cb22
    goto L_0x0041cb22;
L_0x0041cac5:
    // 0041cac5  a1dcc84a00             -mov eax, dword ptr [0x4ac8dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901084) /* 0x4ac8dc */);
    // 0041caca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041cacc  7511                   -jne 0x41cadf
    if (!cpu.flags.zf)
    {
        goto L_0x0041cadf;
    }
    // 0041cace  e85d8c0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041cad3  dc05a8744800           -fadd qword ptr [0x4874a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748456) /* 0x4874a8 */));
    // 0041cad9  d91de0c84a00           -fstp dword ptr [0x4ac8e0]
    app->getMemory<float>(x86::reg32(4901088) /* 0x4ac8e0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041cadf:
    // 0041cadf  8b15dcc84a00           -mov edx, dword ptr [0x4ac8dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4901084) /* 0x4ac8dc */);
    // 0041cae5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041cae7  42                     -inc edx
    (cpu.edx)++;
    // 0041cae8  8915dcc84a00           -mov dword ptr [0x4ac8dc], edx
    app->getMemory<x86::reg32>(x86::reg32(4901084) /* 0x4ac8dc */) = cpu.edx;
    // 0041caee  8d542409               -lea edx, [esp + 9]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(9) /* 0x9 */);
    // 0041caf2  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0041caf4:
    // 0041caf4  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0041caf6  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0041caf9  40                     -inc eax
    (cpu.eax)++;
    // 0041cafa  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0041cafc  75f6                   -jne 0x41caf4
    if (!cpu.flags.zf)
    {
        goto L_0x0041caf4;
    }
    // 0041cafe  83fb01                 +cmp ebx, 1
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
    // 0041cb01  885c2408               -mov byte ptr [esp + 8], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 0041cb05  7509                   -jne 0x41cb10
    if (!cpu.flags.zf)
    {
        goto L_0x0041cb10;
    }
    // 0041cb07  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041cb0b  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0041cb0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cb0e  eb07                   -jmp 0x41cb17
    goto L_0x0041cb17;
L_0x0041cb10:
    // 0041cb10  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041cb14  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041cb16  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0041cb17:
    // 0041cb17  8b0dc4e54900           -mov ecx, dword ptr [0x49e5c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041cb1d  e88e9c0300             -call 0x4567b0
    cpu.esp -= 4;
    sub_4567b0(app, cpu);
L_0x0041cb22:
    // 0041cb22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cb23  c60598c84a0000         -mov byte ptr [0x4ac898], 0
    app->getMemory<x86::reg8>(x86::reg32(4901016) /* 0x4ac898 */) = 0 /*0x0*/;
    // 0041cb2a  c705d8c84a0000000000   -mov dword ptr [0x4ac8d8], 0
    app->getMemory<x86::reg32>(x86::reg32(4901080) /* 0x4ac8d8 */) = 0 /*0x0*/;
    // 0041cb34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cb35  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041cb38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41cb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cb40  a124d44a00             -mov eax, dword ptr [0x4ad424]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903972) /* 0x4ad424 */);
    // 0041cb45  81ec80010000           -sub esp, 0x180
    (cpu.esp) -= x86::reg32(x86::sreg32(384 /*0x180*/));
    // 0041cb4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041cb4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cb4e  755b                   -jne 0x41cbab
    if (!cpu.flags.zf)
    {
        goto L_0x0041cbab;
    }
    // 0041cb50  41                     -inc ecx
    (cpu.ecx)++;
    // 0041cb51  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041cb55  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cb56  8d0cd2                 -lea ecx, [edx + edx*8]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 8);
    // 0041cb59  be7c024900             -mov esi, 0x49027c
    cpu.esi = 4784764 /*0x49027c*/;
    // 0041cb5e  8d144de0f35100         -lea edx, [ecx*2 + 0x51f3e0]
    cpu.edx = x86::reg32(x86::reg32(5370848) /* 0x51f3e0 */ + cpu.ecx * 2);
    // 0041cb65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041cb66  683c0e4900             -push 0x490e3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787772 /*0x490e3c*/;
    cpu.esp -= 4;
    // 0041cb6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cb6c  e887a20500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041cb71  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0041cb74:
    // 0041cb74  8d8c2484000000         -lea ecx, [esp + 0x84]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0041cb7b  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0041cb80  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041cb84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cb85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041cb86  e8a7b50500             -call 0x478132
    cpu.esp -= 4;
    sub_478132(app, cpu);
    // 0041cb8b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041cb8e  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041cb90  8d8c2484000000         -lea ecx, [esp + 0x84]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0041cb97  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041cb99  6800004040             -push 0x40400000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1077936128 /*0x40400000*/;
    cpu.esp -= 4;
    // 0041cb9e  e83d23ffff             -call 0x40eee0
    cpu.esp -= 4;
    sub_40eee0(app, cpu);
    // 0041cba3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cba4  81c480010000           -add esp, 0x180
    (cpu.esp) += x86::reg32(x86::sreg32(384 /*0x180*/));
    // 0041cbaa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041cbab:
    // 0041cbab  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041cbad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cbae  3c01                   +cmp al, 1
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
    // 0041cbb0  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041cbb5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041cbb6  751a                   -jne 0x41cbd2
    if (!cpu.flags.zf)
    {
        goto L_0x0041cbd2;
    }
    // 0041cbb8  8b3490                 -mov esi, dword ptr [eax + edx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0041cbbb  f6862603000001         +test byte ptr [esi + 0x326], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(806) /* 0x326 */) & 1 /*0x1*/));
    // 0041cbc2  7407                   -je 0x41cbcb
    if (cpu.flags.zf)
    {
        goto L_0x0041cbcb;
    }
    // 0041cbc4  be84024900             -mov esi, 0x490284
    cpu.esi = 4784772 /*0x490284*/;
    // 0041cbc9  eb0c                   -jmp 0x41cbd7
    goto L_0x0041cbd7;
L_0x0041cbcb:
    // 0041cbcb  be8c024900             -mov esi, 0x49028c
    cpu.esi = 4784780 /*0x49028c*/;
    // 0041cbd0  eb05                   -jmp 0x41cbd7
    goto L_0x0041cbd7;
L_0x0041cbd2:
    // 0041cbd2  be7c024900             -mov esi, 0x49027c
    cpu.esi = 4784764 /*0x49027c*/;
L_0x0041cbd7:
    // 0041cbd7  8b3dc4e54900           -mov edi, dword ptr [0x49e5c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041cbdd  8b3cb8                 -mov edi, dword ptr [eax + edi*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0041cbe0  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0041cbe3  8a9f26030000           -mov bl, byte ptr [edi + 0x326]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(806) /* 0x326 */);
    // 0041cbe9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cbea  329826030000           -xor bl, byte ptr [eax + 0x326]
    cpu.bl ^= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(806) /* 0x326 */)));
    // 0041cbf0  b8340e4900             -mov eax, 0x490e34
    cpu.eax = 4787764 /*0x490e34*/;
    // 0041cbf5  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0041cbf8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cbf9  7405                   -je 0x41cc00
    if (cpu.flags.zf)
    {
        goto L_0x0041cc00;
    }
    // 0041cbfb  b82c0e4900             -mov eax, 0x490e2c
    cpu.eax = 4787756 /*0x490e2c*/;
L_0x0041cc00:
    // 0041cc00  41                     -inc ecx
    (cpu.ecx)++;
    // 0041cc01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cc02  8d0cd2                 -lea ecx, [edx + edx*8]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 8);
    // 0041cc05  8d144de0f35100         -lea edx, [ecx*2 + 0x51f3e0]
    cpu.edx = x86::reg32(x86::reg32(5370848) /* 0x51f3e0 */ + cpu.ecx * 2);
    // 0041cc0c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041cc0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cc0e  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041cc12  68140e4900             -push 0x490e14
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787732 /*0x490e14*/;
    cpu.esp -= 4;
    // 0041cc17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041cc18  e8dba10500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041cc1d  83c414                 +add esp, 0x14
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
    // 0041cc20  e94fffffff             -jmp 0x41cb74
    goto L_0x0041cb74;
}

/* align: skip  */
void Application::sub_41cc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cc30  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041cc33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cc34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041cc35  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041cc37  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041cc3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041cc3c  e85cb10500             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 0041cc41  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041cc43  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041cc46  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041cc48  7e18                   -jle 0x41cc62
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041cc62;
    }
    // 0041cc4a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0041cc4c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0041cc4f  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041cc51  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041cc55  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041cc57  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041cc58  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041cc5a  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0041cc5c  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041cc5e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x0041cc62:
    // 0041cc62  668b37                 -mov si, word ptr [edi]
    cpu.si = app->getMemory<x86::reg16>(cpu.edi);
    // 0041cc65  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 0041cc68  7451                   -je 0x41ccbb
    if (cpu.flags.zf)
    {
        goto L_0x0041ccbb;
    }
    // 0041cc6a  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041cc6e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cc6f  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041cc73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041cc74  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041cc78  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cc7c  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x0041cc84:
    // 0041cc84  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0041cc88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cc89  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041cc8a  d80d8cc84a00           -fmul dword ptr [0x4ac88c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4901004) /* 0x4ac88c */));
    // 0041cc90  d844241c               -fadd dword ptr [esp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */));
    // 0041cc94  e8f7a00500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041cc99  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041cc9b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041cc9d  e86e78ffff             -call 0x414510
    cpu.esp -= 4;
    sub_414510(app, cpu);
    // 0041cca2  668b7702               -mov si, word ptr [edi + 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0041cca6  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0041cca9  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041ccad  83c20a                 -add edx, 0xa
    (cpu.edx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0041ccb0  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 0041ccb3  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0041ccb7  75cb                   -jne 0x41cc84
    if (!cpu.flags.zf)
    {
        goto L_0x0041cc84;
    }
    // 0041ccb9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ccba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041ccbb:
    // 0041ccbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ccbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ccbd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ccc0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_41ccd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ccd0  890decc84a00           -mov dword ptr [0x4ac8ec], ecx
    app->getMemory<x86::reg32>(x86::reg32(4901100) /* 0x4ac8ec */) = cpu.ecx;
    // 0041ccd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41cce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041cce0  83ec68                 -sub esp, 0x68
    (cpu.esp) -= x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0041cce3  a104c94a00             -mov eax, dword ptr [0x4ac904]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901124) /* 0x4ac904 */);
    // 0041cce8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cce9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041cceb  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0041cced  884c2404               -mov byte ptr [esp + 4], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.cl;
    // 0041ccf1  0f852b010000           -jne 0x41ce22
    if (!cpu.flags.zf)
    {
        goto L_0x0041ce22;
    }
    // 0041ccf7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0041ccfc  b9580e4900             -mov ecx, 0x490e58
    cpu.ecx = 4787800 /*0x490e58*/;
    // 0041cd01  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cd07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041cd09  a304c94a00             -mov dword ptr [0x4ac904], eax
    app->getMemory<x86::reg32>(x86::reg32(4901124) /* 0x4ac904 */) = cpu.eax;
    // 0041cd0e  750d                   -jne 0x41cd1d
    if (!cpu.flags.zf)
    {
        goto L_0x0041cd1d;
    }
    // 0041cd10  68480e4900             -push 0x490e48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787784 /*0x490e48*/;
    cpu.esp -= 4;
    // 0041cd15  e8f67e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041cd1a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041cd1d:
    // 0041cd1d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cd1e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041cd20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0041cd21:
    // 0041cd21  83f961                 +cmp ecx, 0x61
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041cd24  c681f8bf4a00ff         -mov byte ptr [ecx + 0x4abff8], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4898808) /* 0x4abff8 */) = 255 /*0xff*/;
    // 0041cd2b  c68100c14a00ff         -mov byte ptr [ecx + 0x4ac100], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 255 /*0xff*/;
    // 0041cd32  7c2f                   -jl 0x41cd63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041cd63;
    }
    // 0041cd34  83f97a                 +cmp ecx, 0x7a
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041cd37  7f2a                   -jg 0x41cd63
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041cd63;
    }
    // 0041cd39  8d419f                 -lea eax, [ecx - 0x61]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-97) /* -0x61 */);
    // 0041cd3c  bf0d000000             -mov edi, 0xd
    cpu.edi = 13 /*0xd*/;
    // 0041cd41  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041cd42  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0041cd44  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041cd46  8ac2                   -mov al, dl
    cpu.al = cpu.dl;
    // 0041cd48  b205                   -mov dl, 5
    cpu.dl = 5 /*0x5*/;
    // 0041cd4a  f6ea                   -imul dl
    cpu.ax = x86::reg16(x86::sreg16(static_cast<x86::sreg8>(cpu.al)) * x86::sreg16(x86::sreg8(cpu.dl)));
    // 0041cd4c  888100c14a00           -mov byte ptr [ecx + 0x4ac100], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = cpu.al;
    // 0041cd52  8ac3                   -mov al, bl
    cpu.al = cpu.bl;
    // 0041cd54  b209                   -mov dl, 9
    cpu.dl = 9 /*0x9*/;
    // 0041cd56  f6ea                   +imul dl
    {
        cpu.ax = x86::sreg16(static_cast<x86::sreg8>(cpu.al)) * x86::sreg16(x86::sreg8(cpu.dl));
        cpu.flags.of = cpu.flags.cf = (static_cast<x86::sreg16>(cpu.ax) != x86::sreg16(static_cast<x86::sreg8>(cpu.al)));
    }
    // 0041cd58  8881f8bf4a00           -mov byte ptr [ecx + 0x4abff8], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4898808) /* 0x4abff8 */) = cpu.al;
    // 0041cd5e  e9b0000000             -jmp 0x41ce13
    goto L_0x0041ce13;
L_0x0041cd63:
    // 0041cd63  83f930                 +cmp ecx, 0x30
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041cd66  7c1f                   -jl 0x41cd87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041cd87;
    }
    // 0041cd68  83f939                 +cmp ecx, 0x39
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041cd6b  7f1a                   -jg 0x41cd87
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041cd87;
    }
    // 0041cd6d  8ac1                   -mov al, cl
    cpu.al = cpu.cl;
    // 0041cd6f  b205                   -mov dl, 5
    cpu.dl = 5 /*0x5*/;
    // 0041cd71  f6ea                   -imul dl
    cpu.ax = x86::reg16(x86::sreg16(static_cast<x86::sreg8>(cpu.al)) * x86::sreg16(x86::sreg8(cpu.dl)));
    // 0041cd73  0410                   +add al, 0x10
    {
        x86::reg8& tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041cd75  c681f8bf4a0012         -mov byte ptr [ecx + 0x4abff8], 0x12
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4898808) /* 0x4abff8 */) = 18 /*0x12*/;
    // 0041cd7c  888100c14a00           -mov byte ptr [ecx + 0x4ac100], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = cpu.al;
    // 0041cd82  e98c000000             -jmp 0x41ce13
    goto L_0x0041ce13;
L_0x0041cd87:
    // 0041cd87  8d41df                 -lea eax, [ecx - 0x21]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-33) /* -0x21 */);
    // 0041cd8a  83f81e                 +cmp eax, 0x1e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041cd8d  0f8780000000           -ja 0x41ce13
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041ce13;
    }
    // 0041cd93  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041cd95  8a915fcf4100           -mov dl, byte ptr [ecx + 0x41cf5f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4312927) /* 0x41cf5f */);
    // 0041cd9b  ff24954ccf4100         -jmp dword ptr [edx*4 + 0x41cf4c]
    cpu.ip = app->getMemory<x86::reg32>(4312908 + cpu.edx * 4); goto dynamic_jump;
  case 0x0041cda2:
    // 0041cda2  c68100c14a0000         -mov byte ptr [ecx + 0x4ac100], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 0 /*0x0*/;
    // 0041cda9  eb61                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdab:
    // 0041cdab  c68100c14a0005         -mov byte ptr [ecx + 0x4ac100], 5
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 5 /*0x5*/;
    // 0041cdb2  eb58                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdb4:
    // 0041cdb4  c68100c14a000a         -mov byte ptr [ecx + 0x4ac100], 0xa
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 10 /*0xa*/;
    // 0041cdbb  eb4f                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdbd:
    // 0041cdbd  c68100c14a000f         -mov byte ptr [ecx + 0x4ac100], 0xf
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 15 /*0xf*/;
    // 0041cdc4  eb46                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdc6:
    // 0041cdc6  c68100c14a0014         -mov byte ptr [ecx + 0x4ac100], 0x14
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 20 /*0x14*/;
    // 0041cdcd  eb3d                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdcf:
    // 0041cdcf  c68100c14a0019         -mov byte ptr [ecx + 0x4ac100], 0x19
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 25 /*0x19*/;
    // 0041cdd6  eb34                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdd8:
    // 0041cdd8  c68100c14a001e         -mov byte ptr [ecx + 0x4ac100], 0x1e
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 30 /*0x1e*/;
    // 0041cddf  eb2b                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cde1:
    // 0041cde1  c68100c14a0023         -mov byte ptr [ecx + 0x4ac100], 0x23
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 35 /*0x23*/;
    // 0041cde8  eb22                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdea:
    // 0041cdea  c68100c14a0028         -mov byte ptr [ecx + 0x4ac100], 0x28
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 40 /*0x28*/;
    // 0041cdf1  eb19                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdf3:
    // 0041cdf3  c68100c14a002d         -mov byte ptr [ecx + 0x4ac100], 0x2d
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 45 /*0x2d*/;
    // 0041cdfa  eb10                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041cdfc:
    // 0041cdfc  c68100c14a0032         -mov byte ptr [ecx + 0x4ac100], 0x32
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 50 /*0x32*/;
    // 0041ce03  eb07                   -jmp 0x41ce0c
    goto L_0x0041ce0c;
  case 0x0041ce05:
    // 0041ce05  c68100c14a0037         -mov byte ptr [ecx + 0x4ac100], 0x37
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4899072) /* 0x4ac100 */) = 55 /*0x37*/;
L_0x0041ce0c:
    // 0041ce0c  c681f8bf4a001b         -mov byte ptr [ecx + 0x4abff8], 0x1b
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4898808) /* 0x4abff8 */) = 27 /*0x1b*/;
  [[fallthrough]];
  case 0x0041ce13:
L_0x0041ce13:
    // 0041ce13  41                     -inc ecx
    (cpu.ecx)++;
    // 0041ce14  81f900010000           +cmp ecx, 0x100
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
    // 0041ce1a  0f8c01ffffff           -jl 0x41cd21
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041cd21;
    }
    // 0041ce20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ce21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041ce22:
    // 0041ce22  0fbe442404             -movsx eax, byte ptr [esp + 4]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041ce27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ce28  e870a60500             -call 0x47749d
    cpu.esp -= 4;
    sub_47749d(app, cpu);
    // 0041ce2d  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0041ce30  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ce32  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ce34  8a90f8bf4a00           -mov dl, byte ptr [eax + 0x4abff8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4898808) /* 0x4abff8 */);
    // 0041ce3a  8a8800c14a00           -mov cl, byte ptr [eax + 0x4ac100]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4899072) /* 0x4ac100 */);
    // 0041ce40  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041ce42  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ce45  3dff000000             +cmp eax, 0xff
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
    // 0041ce4a  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041ce4e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041ce52  750d                   -jne 0x41ce61
    if (!cpu.flags.zf)
    {
        goto L_0x0041ce61;
    }
    // 0041ce54  3bca                   +cmp ecx, edx
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
    // 0041ce56  7509                   -jne 0x41ce61
    if (!cpu.flags.zf)
    {
        goto L_0x0041ce61;
    }
    // 0041ce58  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ce5a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ce5b  83c468                 -add esp, 0x68
    (cpu.esp) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0041ce5e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0041ce61:
    // 0041ce61  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041ce65  83c105                 -add ecx, 5
    (cpu.ecx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0041ce68  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0041ce6b  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041ce6f  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 0041ce72  dc0d28774800           -fmul qword ptr [0x487728]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749096) /* 0x487728 */));
    // 0041ce78  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041ce7c  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0041ce80  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041ce84  8b159cd44800           -mov edx, dword ptr [0x48d49c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4773020) /* 0x48d49c */);
    // 0041ce8a  c644246800             -mov byte ptr [esp + 0x68], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(104) /* 0x68 */) = 0 /*0x0*/;
    // 0041ce8f  dc0d28774800           -fmul qword ptr [0x487728]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749096) /* 0x487728 */));
    // 0041ce95  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0041ce99  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041ce9d  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0041cea1  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041cea5  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0041cea9  dc0d28774800           -fmul qword ptr [0x487728]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749096) /* 0x487728 */));
    // 0041ceaf  8d4809                 -lea ecx, [eax + 9]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 0041ceb2  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0041ceb6  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0041ceba  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 0041cebe  8b0d98d44800           -mov ecx, dword ptr [0x48d498]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4773016) /* 0x48d498 */);
    // 0041cec4  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041cec8  d9542408               -fst dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 0041cecc  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0041ced0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041ced4  894c2450               -mov dword ptr [esp + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 0041ced8  8b0d84c74a00           -mov ecx, dword ptr [0x4ac784]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900740) /* 0x4ac784 */);
    // 0041cede  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0041cee2  dc0d28774800           -fmul qword ptr [0x487728]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749096) /* 0x487728 */));
    // 0041cee8  d9c3                   -fld st(3)
    cpu.fpu.push(x86::Float(cpu.fpu.st(3)));
    // 0041ceea  a1a0d44800             -mov eax, dword ptr [0x48d4a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4773024) /* 0x48d4a0 */);
    // 0041ceef  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 0041cef3  d95c2430               -fstp dword ptr [esp + 0x30]
    app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cef7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0041cef9  d95c2440               -fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cefd  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0041ceff  d95c2434               -fstp dword ptr [esp + 0x34]
    app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cf03  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0041cf05  d9542444               -fst dword ptr [esp + 0x44]
    app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */) = float(cpu.fpu.st(0));
    // 0041cf09  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 0041cf0b  8b0d04c94a00           -mov ecx, dword ptr [0x4ac904]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901124) /* 0x4ac904 */);
    // 0041cf11  c744246401000000       -mov dword ptr [esp + 0x64], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 1 /*0x1*/;
    // 0041cf19  d95c2438               -fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cf1d  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0041cf21  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0041cf25  d95c2448               -fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cf29  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0041cf2d  c744245ca4707d3f       -mov dword ptr [esp + 0x5c], 0x3f7d70a4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 1065185444 /*0x3f7d70a4*/;
    // 0041cf35  d95c243c               -fstp dword ptr [esp + 0x3c]
    app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041cf39  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cf3f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041cf44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041cf45  83c468                 -add esp, 0x68
    (cpu.esp) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0041cf48  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41cfa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041cfa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041cfa1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041cfa2  8b1dbc704800           -mov ebx, dword ptr [0x4870bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747452) /* 0x4870bc */);
    // 0041cfa8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cfa9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041cfaa  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041cfac  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041cfae  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041cfb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cfb1  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0041cfb5  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cfb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041cfb9  740d                   -je 0x41cfc8
    if (cpu.flags.zf)
    {
        goto L_0x0041cfc8;
    }
    // 0041cfbb  689c0e4900             -push 0x490e9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787868 /*0x490e9c*/;
    cpu.esp -= 4;
    // 0041cfc0  e84b7c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041cfc5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041cfc8:
    // 0041cfc8  803e00                 +cmp byte ptr [esi], 0
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
    // 0041cfcb  7461                   -je 0x41d02e
    if (cpu.flags.zf)
    {
        goto L_0x0041d02e;
    }
    // 0041cfcd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041cfce  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0041cfd2:
    // 0041cfd2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041cfd4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041cfd5  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041cfd7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041cfd9  740d                   -je 0x41cfe8
    if (cpu.flags.zf)
    {
        goto L_0x0041cfe8;
    }
    // 0041cfdb  68800e4900             -push 0x490e80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787840 /*0x490e80*/;
    cpu.esp -= 4;
    // 0041cfe0  e82b7c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041cfe5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041cfe8:
    // 0041cfe8  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0041cfea  80f920                 +cmp cl, 0x20
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
    // 0041cfed  740d                   -je 0x41cffc
    if (cpu.flags.zf)
    {
        goto L_0x0041cffc;
    }
    // 0041cfef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041cff0  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041cff2  e8e9fcffff             -call 0x41cce0
    cpu.esp -= 4;
    sub_41cce0(app, cpu);
    // 0041cff7  83f801                 +cmp eax, 1
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
    // 0041cffa  7515                   -jne 0x41d011
    if (!cpu.flags.zf)
    {
        goto L_0x0041d011;
    }
L_0x0041cffc:
    // 0041cffc  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0041d000  dc0530774800           -fadd qword ptr [0x487730]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749104) /* 0x487730 */));
    // 0041d006  e8859d0500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041d00b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041d00d  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0041d011:
    // 0041d011  46                     -inc esi
    (cpu.esi)++;
    // 0041d012  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041d014  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d015  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041d017  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d019  740d                   -je 0x41d028
    if (cpu.flags.zf)
    {
        goto L_0x0041d028;
    }
    // 0041d01b  68640e4900             -push 0x490e64
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787812 /*0x490e64*/;
    cpu.esp -= 4;
    // 0041d020  e8eb7b0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041d025  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041d028:
    // 0041d028  803e00                 +cmp byte ptr [esi], 0
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
    // 0041d02b  75a5                   -jne 0x41cfd2
    if (!cpu.flags.zf)
    {
        goto L_0x0041cfd2;
    }
    // 0041d02d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041d02e:
    // 0041d02e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d02f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d030  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d032  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41d040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d040  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d041  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d042  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d043  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041d045  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041d047  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041d049  743c                   -je 0x41d087
    if (cpu.flags.zf)
    {
        goto L_0x0041d087;
    }
    // 0041d04b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d04c  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0041d04e  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041d051  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041d053  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0041d055  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0041d057  49                     -dec ecx
    (cpu.ecx)--;
    // 0041d058  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d059  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041d05b  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041d05f  7e26                   -jle 0x41d087
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d087;
    }
    // 0041d061  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041d065  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d069  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d06a  dc0d38774800           -fmul qword ptr [0x487738]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749112) /* 0x487738 */));
    // 0041d070  e81b9d0500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041d075  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d076  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d078  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0041d07a  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0041d07c  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0041d07e  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041d080  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041d082  e819ffffff             -call 0x41cfa0
    cpu.esp -= 4;
    sub_41cfa0(app, cpu);
L_0x0041d087:
    // 0041d087  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d088  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d089  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d08a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41d090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d090  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041d091  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d092  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d093  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0041d095  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0041d097  e8dea10500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0041d09c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041d09e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041d0a1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041d0a3  750d                   -jne 0x41d0b2
    if (!cpu.flags.zf)
    {
        goto L_0x0041d0b2;
    }
    // 0041d0a5  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 0041d0aa  e8617b0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041d0af  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041d0b2:
    // 0041d0b2  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0041d0b4  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041d0b7  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041d0b9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0041d0bb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0041d0bd  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0041d0c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d0c1  e8b4a10500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0041d0c6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041d0c9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0041d0cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d0cd  750d                   -jne 0x41d0dc
    if (!cpu.flags.zf)
    {
        goto L_0x0041d0dc;
    }
    // 0041d0cf  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 0041d0d4  e8377b0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041d0d9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041d0dc:
    // 0041d0dc  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d0de  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
L_0x0041d0e0:
    // 0041d0e0  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0041d0e2  41                     -inc ecx
    (cpu.ecx)++;
    // 0041d0e3  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0041d0e5  42                     -inc edx
    (cpu.edx)++;
    // 0041d0e6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041d0e8  75f6                   -jne 0x41d0e0
    if (!cpu.flags.zf)
    {
        goto L_0x0041d0e0;
    }
    // 0041d0ea  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0041d0f1  a108c94a00             -mov eax, dword ptr [0x4ac908]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901128) /* 0x4ac908 */);
    // 0041d0f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d0f8  7425                   -je 0x41d11f
    if (cpu.flags.zf)
    {
        goto L_0x0041d11f;
    }
L_0x0041d0fa:
    // 0041d0fa  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041d0fd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0041d0ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d100  e8afa20500             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0041d105  8b0d08c94a00           -mov ecx, dword ptr [0x4ac908]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901128) /* 0x4ac908 */);
    // 0041d10b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d10c  e8a3a20500             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0041d111  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041d114  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041d116  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041d118  a308c94a00             -mov dword ptr [0x4ac908], eax
    app->getMemory<x86::reg32>(x86::reg32(4901128) /* 0x4ac908 */) = cpu.eax;
    // 0041d11d  75db                   -jne 0x41d0fa
    if (!cpu.flags.zf)
    {
        goto L_0x0041d0fa;
    }
L_0x0041d11f:
    // 0041d11f  893508c94a00           -mov dword ptr [0x4ac908], esi
    app->getMemory<x86::reg32>(x86::reg32(4901128) /* 0x4ac908 */) = cpu.esi;
    // 0041d125  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0041d12c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d12d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d12e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d12f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41d130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d130  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041d134  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041d138  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d139  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d13a  6808c34a00             -push 0x4ac308
    app->getMemory<x86::reg32>(cpu.esp-4) = 4899592 /*0x4ac308*/;
    cpu.esp -= 4;
    // 0041d13f  e829b20500             -call 0x47836d
    cpu.esp -= 4;
    sub_47836d(app, cpu);
    // 0041d144  83c40c                 +add esp, 0xc
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
    // 0041d147  b908c34a00             -mov ecx, 0x4ac308
    cpu.ecx = 4899592 /*0x4ac308*/;
    // 0041d14c  e93fffffff             -jmp 0x41d090
    return sub_41d090(app, cpu);
}

/* align: skip  */
void Application::sub_41d160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d160  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041d163  8b0decc84a00           -mov ecx, dword ptr [0x4ac8ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901100) /* 0x4ac8ec */);
    // 0041d169  c74424080000803f       -mov dword ptr [esp + 8], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1065353216 /*0x3f800000*/;
    // 0041d171  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041d173  c744240c0000803f       -mov dword ptr [esp + 0xc], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1065353216 /*0x3f800000*/;
    // 0041d17b  c74424100000803f       -mov dword ptr [esp + 0x10], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1065353216 /*0x3f800000*/;
    // 0041d183  c74424140000803f       -mov dword ptr [esp + 0x14], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1065353216 /*0x3f800000*/;
    // 0041d18b  7420                   -je 0x41d1ad
    if (cpu.flags.zf)
    {
        goto L_0x0041d1ad;
    }
    // 0041d18d  8b1554f85100           -mov edx, dword ptr [0x51f854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0041d193  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041d197  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d198  a150f85100             -mov eax, dword ptr [0x51f850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0041d19d  83c2b5                 -add edx, -0x4b
    (cpu.edx) += x86::reg32(x86::sreg32(-75 /*-0x4b*/));
    // 0041d1a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d1a1  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d1a2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d1a4  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041d1a6  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0041d1a8  e883faffff             -call 0x41cc30
    cpu.esp -= 4;
    sub_41cc30(app, cpu);
L_0x0041d1ad:
    // 0041d1ad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d1ae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041d1af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d1b0  8b3508c94a00           -mov esi, dword ptr [0x4ac908]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4901128) /* 0x4ac908 */);
    // 0041d1b6  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0041d1bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d1bc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041d1be  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0041d1c2  0f849f000000           -je 0x41d267
    if (cpu.flags.zf)
    {
        goto L_0x0041d267;
    }
    // 0041d1c8  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d1ca  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041d1cd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041d1cf  33ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0041d1d1  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0041d1d3  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0041d1d5  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0041d1d8  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 0041d1db  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d1dc  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d1de  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041d1e0  a150f85100             -mov eax, dword ptr [0x51f850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0041d1e5  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d1e6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d1e8  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0041d1ea  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0041d1ec  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041d1ee  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0041d1f1  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x0041d1f5:
    // 0041d1f5  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d1f9  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d1fb  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0041d1fe  83c30f                 -add ebx, 0xf
    (cpu.ebx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0041d201  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d202  e899fdffff             -call 0x41cfa0
    cpu.esp -= 4;
    sub_41cfa0(app, cpu);
    // 0041d207  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041d20a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d20c  7514                   -jne 0x41d222
    if (!cpu.flags.zf)
    {
        goto L_0x0041d222;
    }
    // 0041d20e  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 0041d214  dc0548774800           -fadd qword ptr [0x487748]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749128) /* 0x487748 */));
    // 0041d21a  e8719b0500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041d21f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0041d222:
    // 0041d222  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0041d228  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041d22b  3bd0                   +cmp edx, eax
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
    // 0041d22d  7e17                   -jle 0x41d246
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d246;
    }
    // 0041d22f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d231  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d232  e87da10500             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0041d237  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d238  e877a10500             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0041d23d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041d240  893d08c94a00           -mov dword ptr [0x4ac908], edi
    app->getMemory<x86::reg32>(x86::reg32(4901128) /* 0x4ac908 */) = cpu.edi;
L_0x0041d246:
    // 0041d246  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0041d24a  dc0540774800           -fadd qword ptr [0x487740]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749120) /* 0x487740 */));
    // 0041d250  e83b9b0500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041d255  45                     -inc ebp
    (cpu.ebp)++;
    // 0041d256  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041d258  83fd01                 +cmp ebp, 1
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
    // 0041d25b  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0041d25f  7406                   -je 0x41d267
    if (cpu.flags.zf)
    {
        goto L_0x0041d267;
    }
    // 0041d261  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041d263  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0041d265  758e                   -jne 0x41d1f5
    if (!cpu.flags.zf)
    {
        goto L_0x0041d1f5;
    }
L_0x0041d267:
    // 0041d267  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d268  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d269  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d26a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d26b  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041d26e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41d270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d270  e92bfe0000             -jmp 0x42d0a0
    return sub_42d0a0(app, cpu);
}

/* align: skip  */
void Application::sub_41d280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d280  a178d34a00             -mov eax, dword ptr [0x4ad378]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903800) /* 0x4ad378 */);
    // 0041d285  83ec74                 -sub esp, 0x74
    (cpu.esp) -= x86::reg32(x86::sreg32(116 /*0x74*/));
    // 0041d288  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d28a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d28b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d28c  0f84be020000           -je 0x41d550
    if (cpu.flags.zf)
    {
        goto L_0x0041d550;
    }
    // 0041d292  e8a9570100             -call 0x432a40
    cpu.esp -= 4;
    sub_432a40(app, cpu);
    // 0041d297  e8b4570100             -call 0x432a50
    cpu.esp -= 4;
    sub_432a50(app, cpu);
    // 0041d29c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041d29e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041d2a0  0f8439010000           -je 0x41d3df
    if (cpu.flags.zf)
    {
        goto L_0x0041d3df;
    }
L_0x0041d2a6:
    // 0041d2a6  8b86e8020000           -mov eax, dword ptr [esi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 0041d2ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d2ae  0f851c010000           -jne 0x41d3d0
    if (!cpu.flags.zf)
    {
        goto L_0x0041d3d0;
    }
    // 0041d2b4  f686a802000002         +test byte ptr [esi + 0x2a8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(680) /* 0x2a8 */) & 2 /*0x2*/));
    // 0041d2bb  0f840f010000           -je 0x41d3d0
    if (cpu.flags.zf)
    {
        goto L_0x0041d3d0;
    }
    // 0041d2c1  8b86d0000000           -mov eax, dword ptr [esi + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041d2c7  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0041d2cb  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041d2d1  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041d2d5  8b96d8000000           -mov edx, dword ptr [esi + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0041d2db  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0041d2df  8b86dc000000           -mov eax, dword ptr [esi + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */);
    // 0041d2e5  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0041d2e9  8b8ee0000000           -mov ecx, dword ptr [esi + 0xe0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(224) /* 0xe0 */);
    // 0041d2ef  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 0041d2f3  8b96e4000000           -mov edx, dword ptr [esi + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(228) /* 0xe4 */);
    // 0041d2f9  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d2fd  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0041d301  e8da970200             -call 0x446ae0
    cpu.esp -= 4;
    sub_446ae0(app, cpu);
    // 0041d306  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0041d30a  d81d18d24900           -fcomp dword ptr [0x49d218]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4837912) /* 0x49d218 */)));
    cpu.fpu.pop();
    // 0041d310  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041d312  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041d315  0f8bb5000000           -jnp 0x41d3d0
    if (!cpu.flags.pf)
    {
        goto L_0x0041d3d0;
    }
    // 0041d31b  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0041d31f  d9051cd24900           -fld dword ptr [0x49d21c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837916) /* 0x49d21c */)));
    // 0041d325  dc0d28744800           -fmul qword ptr [0x487428]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748328) /* 0x487428 */));
    // 0041d32b  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0041d32d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041d32f  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041d332  0f8b98000000           -jnp 0x41d3d0
    if (!cpu.flags.pf)
    {
        goto L_0x0041d3d0;
    }
    // 0041d338  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041d33c  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041d340  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041d344  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0041d348  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d34c  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041d350  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0041d354  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d355  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d359  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041d35d  e8de970200             -call 0x446b40
    cpu.esp -= 4;
    sub_446b40(app, cpu);
    // 0041d362  8b0d80fc5100           -mov ecx, dword ptr [0x51fc80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5373056) /* 0x51fc80 */);
    // 0041d368  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d36c  3bc1                   +cmp eax, ecx
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
    // 0041d36e  7c60                   -jl 0x41d3d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d3d0;
    }
    // 0041d370  3b055cf85100           +cmp eax, dword ptr [0x51f85c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371996) /* 0x51f85c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d376  7d58                   -jge 0x41d3d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d3d0;
    }
    // 0041d378  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d37c  8b0d84fc5100           -mov ecx, dword ptr [0x51fc84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5373060) /* 0x51fc84 */);
    // 0041d382  3bc1                   +cmp eax, ecx
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
    // 0041d384  7c4a                   -jl 0x41d3d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d3d0;
    }
    // 0041d386  3b0560f85100           +cmp eax, dword ptr [0x51f860]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5372000) /* 0x51f860 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d38c  7d42                   -jge 0x41d3d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d3d0;
    }
    // 0041d38e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041d390  e83b590100             -call 0x432cd0
    cpu.esp -= 4;
    sub_432cd0(app, cpu);
    // 0041d395  8d4c243c               -lea ecx, [esp + 0x3c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0041d399  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d39a  68c40e4900             -push 0x490ec4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787908 /*0x490ec4*/;
    cpu.esp -= 4;
    // 0041d39f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d3a0  e8539a0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041d3a5  d9442438               -fld dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */)));
    // 0041d3a9  d8a688020000           -fsub dword ptr [esi + 0x288]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(648) /* 0x288 */));
    // 0041d3af  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041d3b3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041d3b6  8d4c243c               -lea ecx, [esp + 0x3c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0041d3ba  d825b8744800           -fsub dword ptr [0x4874b8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0041d3c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d3c1  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d3c5  d91d84c74a00           -fstp dword ptr [0x4ac784]
    app->getMemory<float>(x86::reg32(4900740) /* 0x4ac784 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d3cb  e8d0fbffff             -call 0x41cfa0
    cpu.esp -= 4;
    sub_41cfa0(app, cpu);
L_0x0041d3d0:
    // 0041d3d0  e87b560100             -call 0x432a50
    cpu.esp -= 4;
    sub_432a50(app, cpu);
    // 0041d3d5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041d3d7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041d3d9  0f85c7feffff           -jne 0x41d2a6
    if (!cpu.flags.zf)
    {
        goto L_0x0041d2a6;
    }
L_0x0041d3df:
    // 0041d3df  e87c880300             -call 0x455c60
    cpu.esp -= 4;
    sub_455c60(app, cpu);
    // 0041d3e4  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041d3e6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041d3e8  0f8462010000           -je 0x41d550
    if (cpu.flags.zf)
    {
        goto L_0x0041d550;
    }
    // 0041d3ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d3ef  8a5c240f               -mov bl, byte ptr [esp + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(15) /* 0xf */);
L_0x0041d3f3:
    // 0041d3f3  f6474a40               +test byte ptr [edi + 0x4a], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(74) /* 0x4a */) & 64 /*0x40*/));
    // 0041d3f7  0f8444010000           -je 0x41d541
    if (cpu.flags.zf)
    {
        goto L_0x0041d541;
    }
    // 0041d3fd  8b8780000000           -mov eax, dword ptr [edi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 0041d403  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041d409  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0041d40c  8b86e8020000           -mov eax, dword ptr [esi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 0041d412  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d414  740c                   -je 0x41d422
    if (cpu.flags.zf)
    {
        goto L_0x0041d422;
    }
L_0x0041d416:
    // 0041d416  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041d418  8b86e8020000           -mov eax, dword ptr [esi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 0041d41e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d420  75f4                   -jne 0x41d416
    if (!cpu.flags.zf)
    {
        goto L_0x0041d416;
    }
L_0x0041d422:
    // 0041d422  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041d424  e827a6feff             -call 0x407a50
    cpu.esp -= 4;
    sub_407a50(app, cpu);
    // 0041d429  8b88c8040000           -mov ecx, dword ptr [eax + 0x4c8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1224) /* 0x4c8 */);
    // 0041d42f  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0041d432  7402                   -je 0x41d436
    if (cpu.flags.zf)
    {
        goto L_0x0041d436;
    }
    // 0041d434  b350                   -mov bl, 0x50
    cpu.bl = 80 /*0x50*/;
L_0x0041d436:
    // 0041d436  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0041d439  7402                   -je 0x41d43d
    if (cpu.flags.zf)
    {
        goto L_0x0041d43d;
    }
    // 0041d43b  b347                   -mov bl, 0x47
    cpu.bl = 71 /*0x47*/;
L_0x0041d43d:
    // 0041d43d  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0041d440  7402                   -je 0x41d444
    if (cpu.flags.zf)
    {
        goto L_0x0041d444;
    }
    // 0041d442  b341                   -mov bl, 0x41
    cpu.bl = 65 /*0x41*/;
L_0x0041d444:
    // 0041d444  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 0041d447  7402                   -je 0x41d44b
    if (cpu.flags.zf)
    {
        goto L_0x0041d44b;
    }
    // 0041d449  b353                   -mov bl, 0x53
    cpu.bl = 83 /*0x53*/;
L_0x0041d44b:
    // 0041d44b  8b9618030000           -mov edx, dword ptr [esi + 0x318]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(792) /* 0x318 */);
    // 0041d451  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0041d455  f7da                   +neg edx
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
    // 0041d457  1bd2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0041d459  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041d45c  83e20b                 -and edx, 0xb
    cpu.edx &= x86::reg32(x86::sreg32(11 /*0xb*/));
    // 0041d45f  83c26e                 -add edx, 0x6e
    (cpu.edx) += x86::reg32(x86::sreg32(110 /*0x6e*/));
    // 0041d462  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d463  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d464  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0041d467  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d468  68b80e4900             -push 0x490eb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787896 /*0x490eb8*/;
    cpu.esp -= 4;
    // 0041d46d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d46e  e885990500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041d473  8b96d0000000           -mov edx, dword ptr [esi + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041d479  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041d47c  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041d480  8b86d4000000           -mov eax, dword ptr [esi + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041d486  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041d48a  8b8ed8000000           -mov ecx, dword ptr [esi + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0041d490  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0041d494  8b96dc000000           -mov edx, dword ptr [esi + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */);
    // 0041d49a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0041d49e  8b86e0000000           -mov eax, dword ptr [esi + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(224) /* 0xe0 */);
    // 0041d4a4  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0041d4a8  8b8ee4000000           -mov ecx, dword ptr [esi + 0xe4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(228) /* 0xe4 */);
    // 0041d4ae  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0041d4b2  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041d4b6  e825960200             -call 0x446ae0
    cpu.esp -= 4;
    sub_446ae0(app, cpu);
    // 0041d4bb  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0041d4bf  d81d18d24900           -fcomp dword ptr [0x49d218]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4837912) /* 0x49d218 */)));
    cpu.fpu.pop();
    // 0041d4c5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041d4c7  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041d4ca  7b75                   -jnp 0x41d541
    if (!cpu.flags.pf)
    {
        goto L_0x0041d541;
    }
    // 0041d4cc  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041d4d0  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0041d4d4  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041d4d8  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041d4dc  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d4e0  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0041d4e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d4e5  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d4e9  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041d4ed  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0041d4f1  e84a960200             -call 0x446b40
    cpu.esp -= 4;
    sub_446b40(app, cpu);
    // 0041d4f6  a180fc5100             -mov eax, dword ptr [0x51fc80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5373056) /* 0x51fc80 */);
    // 0041d4fb  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d4ff  3bd0                   +cmp edx, eax
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
    // 0041d501  7c3e                   -jl 0x41d541
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d541;
    }
    // 0041d503  3b155cf85100           +cmp edx, dword ptr [0x51f85c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371996) /* 0x51f85c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d509  7d36                   -jge 0x41d541
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d541;
    }
    // 0041d50b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d50f  8b0d84fc5100           -mov ecx, dword ptr [0x51fc84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5373060) /* 0x51fc84 */);
    // 0041d515  3bc1                   +cmp eax, ecx
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
    // 0041d517  7c28                   -jl 0x41d541
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d541;
    }
    // 0041d519  3b0560f85100           +cmp eax, dword ptr [0x51f860]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5372000) /* 0x51f860 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d51f  7d20                   -jge 0x41d541
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d541;
    }
    // 0041d521  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0041d525  d8a688020000           -fsub dword ptr [esi + 0x288]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(648) /* 0x288 */));
    // 0041d52b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d52c  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0041d530  d825b8744800           -fsub dword ptr [0x4874b8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0041d536  d91d84c74a00           -fstp dword ptr [0x4ac784]
    app->getMemory<float>(x86::reg32(4900740) /* 0x4ac784 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d53c  e85ffaffff             -call 0x41cfa0
    cpu.esp -= 4;
    sub_41cfa0(app, cpu);
L_0x0041d541:
    // 0041d541  8bbf30030000           -mov edi, dword ptr [edi + 0x330]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(816) /* 0x330 */);
    // 0041d547  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041d549  0f85a4feffff           -jne 0x41d3f3
    if (!cpu.flags.zf)
    {
        goto L_0x0041d3f3;
    }
    // 0041d54f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041d550:
    // 0041d550  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d551  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d552  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 0041d555  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41d560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d560  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0041d563  e818fdffff             -call 0x41d280
    cpu.esp -= 4;
    sub_41d280(app, cpu);
    // 0041d568  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 0041d56d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d56f  0f84cf010000           -je 0x41d744
    if (cpu.flags.zf)
    {
        goto L_0x0041d744;
    }
    // 0041d575  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0041d57a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041d57b  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0041d57d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d57f  0f8ea0010000           -jle 0x41d725
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041d725;
    }
    // 0041d585  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d586  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041d587  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041d588  bbe0f35100             -mov ebx, 0x51f3e0
    cpu.ebx = 5370848 /*0x51f3e0*/;
    // 0041d58d  8d7c2440               -lea edi, [esp + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0041d591  2bfb                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0041d593:
    // 0041d593  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041d598  8b0ca8                 -mov ecx, dword ptr [eax + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 4);
    // 0041d59b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041d5a0  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0041d5a6  8b3490                 -mov esi, dword ptr [eax + edx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0041d5a9  8b86e8020000           -mov eax, dword ptr [esi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 0041d5af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d5b1  740c                   -je 0x41d5bf
    if (cpu.flags.zf)
    {
        goto L_0x0041d5bf;
    }
L_0x0041d5b3:
    // 0041d5b3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041d5b5  8b86e8020000           -mov eax, dword ptr [esi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(744) /* 0x2e8 */);
    // 0041d5bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d5bd  75f4                   -jne 0x41d5b3
    if (!cpu.flags.zf)
    {
        goto L_0x0041d5b3;
    }
L_0x0041d5bf:
    // 0041d5bf  8b8ed0000000           -mov ecx, dword ptr [esi + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041d5c5  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041d5c9  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041d5cf  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0041d5d3  8b86d8000000           -mov eax, dword ptr [esi + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0041d5d9  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0041d5dd  8b8edc000000           -mov ecx, dword ptr [esi + 0xdc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */);
    // 0041d5e3  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 0041d5e7  8b96e0000000           -mov edx, dword ptr [esi + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(224) /* 0xe0 */);
    // 0041d5ed  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0041d5f1  8b86e4000000           -mov eax, dword ptr [esi + 0xe4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(228) /* 0xe4 */);
    // 0041d5f7  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041d5fb  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0041d5ff  e8dc940200             -call 0x446ae0
    cpu.esp -= 4;
    sub_446ae0(app, cpu);
    // 0041d604  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0041d608  d81d50774800           -fcomp dword ptr [0x487750]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749136) /* 0x487750 */)));
    cpu.fpu.pop();
    // 0041d60e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041d610  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041d615  7517                   -jne 0x41d62e
    if (!cpu.flags.zf)
    {
        goto L_0x0041d62e;
    }
    // 0041d617  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0041d619  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0041d61d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d61e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d61f  e89ca70500             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 0041d624  83c40c                 +add esp, 0xc
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
    // 0041d627  c644244300             -mov byte ptr [esp + 0x43], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(67) /* 0x43 */) = 0 /*0x0*/;
    // 0041d62c  eb0c                   -jmp 0x41d63a
    goto L_0x0041d63a;
L_0x0041d62e:
    // 0041d62e  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0041d630:
    // 0041d630  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0041d632  880c07                 -mov byte ptr [edi + eax], cl
    app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1) = cpu.cl;
    // 0041d635  40                     -inc eax
    (cpu.eax)++;
    // 0041d636  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0041d638  75f6                   -jne 0x41d630
    if (!cpu.flags.zf)
    {
        goto L_0x0041d630;
    }
L_0x0041d63a:
    // 0041d63a  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0041d63e  d81d18d24900           -fcomp dword ptr [0x49d218]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4837912) /* 0x49d218 */)));
    cpu.fpu.pop();
    // 0041d644  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041d646  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041d649  0f8bbf000000           -jnp 0x41d70e
    if (!cpu.flags.pf)
    {
        goto L_0x0041d70e;
    }
    // 0041d64f  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041d653  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0041d657  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041d65b  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0041d65f  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d663  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0041d667  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d668  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d66c  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041d670  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0041d674  e8c7940200             -call 0x446b40
    cpu.esp -= 4;
    sub_446b40(app, cpu);
    // 0041d679  a180fc5100             -mov eax, dword ptr [0x51fc80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5373056) /* 0x51fc80 */);
    // 0041d67e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041d682  3bd0                   +cmp edx, eax
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
    // 0041d684  0f8c84000000           -jl 0x41d70e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d70e;
    }
    // 0041d68a  3b155cf85100           +cmp edx, dword ptr [0x51f85c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371996) /* 0x51f85c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d690  7d7c                   -jge 0x41d70e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d70e;
    }
    // 0041d692  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041d696  8b0d84fc5100           -mov ecx, dword ptr [0x51fc84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5373060) /* 0x51fc84 */);
    // 0041d69c  3bc1                   +cmp eax, ecx
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
    // 0041d69e  7c6e                   -jl 0x41d70e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d70e;
    }
    // 0041d6a0  3b0560f85100           +cmp eax, dword ptr [0x51f860]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5372000) /* 0x51f860 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d6a6  7d66                   -jge 0x41d70e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d70e;
    }
    // 0041d6a8  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0041d6ac  d8a688020000           -fsub dword ptr [esi + 0x288]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(648) /* 0x288 */));
    // 0041d6b2  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041d6b8  d825b8744800           -fsub dword ptr [0x4874b8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0041d6be  d91d84c74a00           -fstp dword ptr [0x4ac784]
    app->getMemory<float>(x86::reg32(4900740) /* 0x4ac784 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d6c4  8b0ca9                 -mov ecx, dword ptr [ecx + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 0041d6c7  f6812603000001         +test byte ptr [ecx + 0x326], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(806) /* 0x326 */) & 1 /*0x1*/));
    // 0041d6ce  c7059cd4480000000000   -mov dword ptr [0x48d49c], 0
    app->getMemory<x86::reg32>(x86::reg32(4773020) /* 0x48d49c */) = 0 /*0x0*/;
    // 0041d6d8  7516                   -jne 0x41d6f0
    if (!cpu.flags.zf)
    {
        goto L_0x0041d6f0;
    }
    // 0041d6da  c70598d448000000803f   -mov dword ptr [0x48d498], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(4773016) /* 0x48d498 */) = 1065353216 /*0x3f800000*/;
    // 0041d6e4  c705a0d4480000000000   -mov dword ptr [0x48d4a0], 0
    app->getMemory<x86::reg32>(x86::reg32(4773024) /* 0x48d4a0 */) = 0 /*0x0*/;
    // 0041d6ee  eb14                   -jmp 0x41d704
    goto L_0x0041d704;
L_0x0041d6f0:
    // 0041d6f0  c70598d4480000000000   -mov dword ptr [0x48d498], 0
    app->getMemory<x86::reg32>(x86::reg32(4773016) /* 0x48d498 */) = 0 /*0x0*/;
    // 0041d6fa  c705a0d448000000803f   -mov dword ptr [0x48d4a0], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(4773024) /* 0x48d4a0 */) = 1065353216 /*0x3f800000*/;
L_0x0041d704:
    // 0041d704  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d705  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0041d709  e832f9ffff             -call 0x41d040
    cpu.esp -= 4;
    sub_41d040(app, cpu);
L_0x0041d70e:
    // 0041d70e  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0041d713  45                     -inc ebp
    (cpu.ebp)++;
    // 0041d714  83ef12                 -sub edi, 0x12
    (cpu.edi) -= x86::reg32(x86::sreg32(18 /*0x12*/));
    // 0041d717  83c312                 -add ebx, 0x12
    (cpu.ebx) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 0041d71a  3be8                   +cmp ebp, eax
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
    // 0041d71c  0f8c71feffff           -jl 0x41d593
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d593;
    }
    // 0041d722  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d723  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d724  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041d725:
    // 0041d725  c70598d448000000803f   -mov dword ptr [0x48d498], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(4773016) /* 0x48d498 */) = 1065353216 /*0x3f800000*/;
    // 0041d72f  c7059cd448000000803f   -mov dword ptr [0x48d49c], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(4773020) /* 0x48d49c */) = 1065353216 /*0x3f800000*/;
    // 0041d739  c705a0d448000000803f   -mov dword ptr [0x48d4a0], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(4773024) /* 0x48d4a0 */) = 1065353216 /*0x3f800000*/;
    // 0041d743  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041d744:
    // 0041d744  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0041d747  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41d750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d750  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041d752  7434                   -je 0x41d788
    if (cpu.flags.zf)
    {
        goto L_0x0041d788;
    }
    // 0041d754  e8d77f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041d759  d90520c94a00           -fld dword ptr [0x4ac920]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4901152) /* 0x4ac920 */)));
    // 0041d75f  a11cc94a00             -mov eax, dword ptr [0x4ac91c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901148) /* 0x4ac91c */);
    // 0041d764  b924000000             -mov ecx, 0x24
    cpu.ecx = 36 /*0x24*/;
    // 0041d769  d8e9                   -fsubr st(1)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(1)) - cpu.fpu.st(0);
    // 0041d76b  40                     -inc eax
    (cpu.eax)++;
    // 0041d76c  d91c853cc44a00         -fstp dword ptr [eax*4 + 0x4ac43c]
    app->getMemory<float>(x86::reg32(4899900) /* 0x4ac43c */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d773  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d774  d91d20c94a00           -fstp dword ptr [0x4ac920]
    app->getMemory<float>(x86::reg32(4901152) /* 0x4ac920 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d77a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0041d77c  ff0518c94a00           -inc dword ptr [0x4ac918]
    (app->getMemory<x86::reg32>(x86::reg32(4901144) /* 0x4ac918 */))++;
    // 0041d782  89151cc94a00           -mov dword ptr [0x4ac91c], edx
    app->getMemory<x86::reg32>(x86::reg32(4901148) /* 0x4ac91c */) = cpu.edx;
L_0x0041d788:
    // 0041d788  833d18c94a0024         +cmp dword ptr [0x4ac918], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4901144) /* 0x4ac918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d78f  7d07                   -jge 0x41d798
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d798;
    }
    // 0041d791  d90558774800           -fld dword ptr [0x487758]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4749144) /* 0x487758 */)));
    // 0041d797  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041d798:
    // 0041d798  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0041d79e  b840c44a00             -mov eax, 0x4ac440
    cpu.eax = 4899904 /*0x4ac440*/;
L_0x0041d7a3:
    // 0041d7a3  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 0041d7a5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041d7a8  3dd0c44a00             +cmp eax, 0x4ac4d0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4900048 /*0x4ac4d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041d7ad  7cf4                   -jl 0x41d7a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d7a3;
    }
    // 0041d7af  d80d54774800           -fmul dword ptr [0x487754]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749140) /* 0x487754 */));
    // 0041d7b5  dc3d68734800           -fdivr qword ptr [0x487368]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)) / cpu.fpu.st(0);
    // 0041d7bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41d7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041d7c0  81ec80010000           -sub esp, 0x180
    (cpu.esp) -= x86::reg32(x86::sreg32(384 /*0x180*/));
    // 0041d7c6  e8e5100000             -call 0x41e8b0
    cpu.esp -= 4;
    sub_41e8b0(app, cpu);
    // 0041d7cb  a1a4d34a00             -mov eax, dword ptr [0x4ad3a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903844) /* 0x4ad3a4 */);
    // 0041d7d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d7d2  7449                   -je 0x41d81d
    if (cpu.flags.zf)
    {
        goto L_0x0041d81d;
    }
    // 0041d7d4  83e802                 +sub eax, 2
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
    // 0041d7d7  7423                   -je 0x41d7fc
    if (cpu.flags.zf)
    {
        goto L_0x0041d7fc;
    }
    // 0041d7d9  83e802                 +sub eax, 2
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
    // 0041d7dc  7417                   -je 0x41d7f5
    if (cpu.flags.zf)
    {
        goto L_0x0041d7f5;
    }
    // 0041d7de  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041d7df  a154f85100             -mov eax, dword ptr [0x51f854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0041d7e4  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d7e5  7407                   -je 0x41d7ee
    if (cpu.flags.zf)
    {
        goto L_0x0041d7ee;
    }
    // 0041d7e7  b9c40f4900             -mov ecx, 0x490fc4
    cpu.ecx = 4788164 /*0x490fc4*/;
    // 0041d7ec  eb19                   -jmp 0x41d807
    goto L_0x0041d807;
L_0x0041d7ee:
    // 0041d7ee  b9b40f4900             -mov ecx, 0x490fb4
    cpu.ecx = 4788148 /*0x490fb4*/;
    // 0041d7f3  eb12                   -jmp 0x41d807
    goto L_0x0041d807;
L_0x0041d7f5:
    // 0041d7f5  b9700f4900             -mov ecx, 0x490f70
    cpu.ecx = 4788080 /*0x490f70*/;
    // 0041d7fa  eb05                   -jmp 0x41d801
    goto L_0x0041d801;
L_0x0041d7fc:
    // 0041d7fc  b9300f4900             -mov ecx, 0x490f30
    cpu.ecx = 4788016 /*0x490f30*/;
L_0x0041d801:
    // 0041d801  a154f85100             -mov eax, dword ptr [0x51f854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0041d806  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
L_0x0041d807:
    // 0041d807  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d809  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0041d80b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d80c  a150f85100             -mov eax, dword ptr [0x51f850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0041d811  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d812  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d814  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041d816  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0041d818  e823f8ffff             -call 0x41d040
    cpu.esp -= 4;
    sub_41d040(app, cpu);
L_0x0041d81d:
    // 0041d81d  a174d34a00             -mov eax, dword ptr [0x4ad374]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903796) /* 0x4ad374 */);
    // 0041d822  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d824  7463                   -je 0x41d889
    if (cpu.flags.zf)
    {
        goto L_0x0041d889;
    }
    // 0041d826  a174415100             -mov eax, dword ptr [0x514174]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5325172) /* 0x514174 */);
    // 0041d82b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0041d830  d9051cd24900           -fld dword ptr [0x49d21c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837916) /* 0x49d21c */)));
    // 0041d836  dc0de0724800           -fmul qword ptr [0x4872e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748000) /* 0x4872e0 */));
    // 0041d83c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d83d  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041d840  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d844  d90500f85100           -fld dword ptr [0x51f800]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5371904) /* 0x51f800 */)));
    // 0041d84a  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0041d84c  dc0de0724800           -fmul qword ptr [0x4872e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748000) /* 0x4872e0 */));
    // 0041d852  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d855  e8f6feffff             -call 0x41d750
    cpu.esp -= 4;
    sub_41d750(app, cpu);
    // 0041d85a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041d85d  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041d861  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041d864  68180f4900             -push 0x490f18
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787992 /*0x490f18*/;
    cpu.esp -= 4;
    // 0041d869  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d86a  e889950500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041d86f  a150f85100             -mov eax, dword ptr [0x51f850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0041d874  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0041d877  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041d878  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041d87a  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0041d87c  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041d87e  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041d882  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0041d884  e817f7ffff             -call 0x41cfa0
    cpu.esp -= 4;
    sub_41cfa0(app, cpu);
L_0x0041d889:
    // 0041d889  a180d34a00             -mov eax, dword ptr [0x4ad380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903808) /* 0x4ad380 */);
    // 0041d88e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d890  0f85a9010000           -jne 0x41da3f
    if (!cpu.flags.zf)
    {
        goto L_0x0041da3f;
    }
    // 0041d896  a18ca45100             -mov eax, dword ptr [0x51a48c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5350540) /* 0x51a48c */);
    // 0041d89b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d89d  7518                   -jne 0x41d8b7
    if (!cpu.flags.zf)
    {
        goto L_0x0041d8b7;
    }
    // 0041d89f  a184d34a00             -mov eax, dword ptr [0x4ad384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903812) /* 0x4ad384 */);
    // 0041d8a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d8a6  0f84ed000000           -je 0x41d999
    if (cpu.flags.zf)
    {
        goto L_0x0041d999;
    }
    // 0041d8ac  81c480010000           +add esp, 0x180
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041d8b2  e9799affff             -jmp 0x417330
    return sub_417330(app, cpu);
L_0x0041d8b7:
    // 0041d8b7  8b0dc0f35100           -mov ecx, dword ptr [0x51f3c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0041d8bd  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041d8c2  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0041d8c5  3bc2                   +cmp eax, edx
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
    // 0041d8c7  0f84c6000000           -je 0x41d993
    if (cpu.flags.zf)
    {
        goto L_0x0041d993;
    }
    // 0041d8cd  a114034900             -mov eax, dword ptr [0x490314]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784916) /* 0x490314 */);
    // 0041d8d2  3bc1                   +cmp eax, ecx
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
    // 0041d8d4  0f8db9000000           -jge 0x41d993
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041d993;
    }
    // 0041d8da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041d8db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0041d8dc:
    // 0041d8dc  8b0d24d44a00           -mov ecx, dword ptr [0x4ad424]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4903972) /* 0x4ad424 */);
    // 0041d8e2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041d8e4  744f                   -je 0x41d935
    if (cpu.flags.zf)
    {
        goto L_0x0041d935;
    }
    // 0041d8e6  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041d8ec  8b35c4e54900           -mov esi, dword ptr [0x49e5c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041d8f2  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0041d8f5  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0041d8f8  8a9226030000           -mov dl, byte ptr [edx + 0x326]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(806) /* 0x326 */);
    // 0041d8fe  8a9926030000           -mov bl, byte ptr [ecx + 0x326]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(806) /* 0x326 */);
    // 0041d904  32d3                   -xor dl, bl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0041d906  b9100f4900             -mov ecx, 0x490f10
    cpu.ecx = 4787984 /*0x490f10*/;
    // 0041d90b  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0041d90e  7405                   -je 0x41d915
    if (cpu.flags.zf)
    {
        goto L_0x0041d915;
    }
    // 0041d910  b9040f4900             -mov ecx, 0x490f04
    cpu.ecx = 4787972 /*0x490f04*/;
L_0x0041d915:
    // 0041d915  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0041d918  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d919  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d91d  8d0c45e0f35100         -lea ecx, [eax*2 + 0x51f3e0]
    cpu.ecx = x86::reg32(x86::reg32(5370848) /* 0x51f3e0 */ + cpu.eax * 2);
    // 0041d924  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d925  68e00e4900             -push 0x490ee0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787936 /*0x490ee0*/;
    cpu.esp -= 4;
    // 0041d92a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d92b  e8c8940500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041d930  83c410                 +add esp, 0x10
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
    // 0041d933  eb1d                   -jmp 0x41d952
    goto L_0x0041d952;
L_0x0041d935:
    // 0041d935  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0041d938  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041d93c  8d0c45e0f35100         -lea ecx, [eax*2 + 0x51f3e0]
    cpu.ecx = x86::reg32(x86::reg32(5370848) /* 0x51f3e0 */ + cpu.eax * 2);
    // 0041d943  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d944  68c80e4900             -push 0x490ec8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787912 /*0x490ec8*/;
    cpu.esp -= 4;
    // 0041d949  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041d94a  e8a9940500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041d94f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0041d952:
    // 0041d952  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0041d959  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0041d95e  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041d962  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041d963  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041d964  e8c9a70500             -call 0x478132
    cpu.esp -= 4;
    sub_478132(app, cpu);
    // 0041d969  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041d96c  8d8c2488000000         -lea ecx, [esp + 0x88]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0041d973  e818f1ffff             -call 0x41ca90
    cpu.esp -= 4;
    sub_41ca90(app, cpu);
    // 0041d978  a114034900             -mov eax, dword ptr [0x490314]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784916) /* 0x490314 */);
    // 0041d97d  8b0dc0f35100           -mov ecx, dword ptr [0x51f3c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0041d983  40                     -inc eax
    (cpu.eax)++;
    // 0041d984  3bc1                   +cmp eax, ecx
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
    // 0041d986  a314034900             -mov dword ptr [0x490314], eax
    app->getMemory<x86::reg32>(x86::reg32(4784916) /* 0x490314 */) = cpu.eax;
    // 0041d98b  0f8c4bffffff           -jl 0x41d8dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041d8dc;
    }
    // 0041d991  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041d992  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041d993:
    // 0041d993  890d14034900           -mov dword ptr [0x490314], ecx
    app->getMemory<x86::reg32>(x86::reg32(4784916) /* 0x490314 */) = cpu.ecx;
L_0x0041d999:
    // 0041d999  e8628fffff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 0041d99e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d9a0  740b                   -je 0x41d9ad
    if (cpu.flags.zf)
    {
        goto L_0x0041d9ad;
    }
    // 0041d9a2  81c480010000           +add esp, 0x180
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041d9a8  e97397ffff             -jmp 0x417120
    return sub_417120(app, cpu);
L_0x0041d9ad:
    // 0041d9ad  e87e9d0000             -call 0x427730
    cpu.esp -= 4;
    sub_427730(app, cpu);
    // 0041d9b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d9b4  740b                   -je 0x41d9c1
    if (cpu.flags.zf)
    {
        goto L_0x0041d9c1;
    }
    // 0041d9b6  81c480010000           +add esp, 0x180
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041d9bc  e90f90ffff             -jmp 0x4169d0
    return sub_4169d0(app, cpu);
L_0x0041d9c1:
    // 0041d9c1  e8da71ffff             -call 0x414ba0
    cpu.esp -= 4;
    sub_414ba0(app, cpu);
    // 0041d9c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d9c8  740b                   -je 0x41d9d5
    if (cpu.flags.zf)
    {
        goto L_0x0041d9d5;
    }
    // 0041d9ca  81c480010000           +add esp, 0x180
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041d9d0  e98b97ffff             -jmp 0x417160
    return sub_417160(app, cpu);
L_0x0041d9d5:
    // 0041d9d5  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0041d9da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041d9dc  7461                   -je 0x41da3f
    if (cpu.flags.zf)
    {
        goto L_0x0041da3f;
    }
    // 0041d9de  e8dda00300             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 0041d9e3  e8584d0000             -call 0x422740
    cpu.esp -= 4;
    sub_422740(app, cpu);
    // 0041d9e8  e8130b0000             -call 0x41e500
    cpu.esp -= 4;
    sub_41e500(app, cpu);
    // 0041d9ed  d90510c94a00           -fld dword ptr [0x4ac910]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4901136) /* 0x4ac910 */)));
    // 0041d9f3  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041d9f9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041d9fb  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0041d9fe  7a0c                   -jp 0x41da0c
    if (cpu.flags.pf)
    {
        goto L_0x0041da0c;
    }
    // 0041da00  8b1514d24900           -mov edx, dword ptr [0x49d214]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4837908) /* 0x49d214 */);
    // 0041da06  891510c94a00           -mov dword ptr [0x4ac910], edx
    app->getMemory<x86::reg32>(x86::reg32(4901136) /* 0x4ac910 */) = cpu.edx;
L_0x0041da0c:
    // 0041da0c  a148845100             -mov eax, dword ptr [0x518448]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0041da11  a324c94a00             -mov dword ptr [0x4ac924], eax
    app->getMemory<x86::reg32>(x86::reg32(4901156) /* 0x4ac924 */) = cpu.eax;
    // 0041da16  e845f7ffff             -call 0x41d160
    cpu.esp -= 4;
    sub_41d160(app, cpu);
    // 0041da1b  8b0dc4e54900           -mov ecx, dword ptr [0x49e5c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041da21  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041da27  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0041da2a  6683b88a02000000       +cmp word ptr [eax + 0x28a], 0
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
    // 0041da32  7e0b                   -jle 0x41da3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041da3f;
    }
    // 0041da34  81c480010000           +add esp, 0x180
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041da3a  e93197ffff             -jmp 0x417170
    return sub_417170(app, cpu);
L_0x0041da3f:
    // 0041da3f  81c480010000           -add esp, 0x180
    (cpu.esp) += x86::reg32(x86::sreg32(384 /*0x180*/));
    // 0041da45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41da50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041da50  a164845100             -mov eax, dword ptr [0x518464]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342308) /* 0x518464 */);
    // 0041da55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041da57  7402                   -je 0x41da5b
    if (cpu.flags.zf)
    {
        goto L_0x0041da5b;
    }
    // 0041da59  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
L_0x0041da5b:
    // 0041da5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41da60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041da60  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041da66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041da67  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041da68  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0041da6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041da6b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041da6c  c684248c00000001       -mov byte ptr [esp + 0x8c], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */) = 1 /*0x1*/;
    // 0041da74  89ac2488000000         -mov dword ptr [esp + 0x88], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ebp;
    // 0041da7b  c744247c0000803f       -mov dword ptr [esp + 0x7c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = 1065353216 /*0x3f800000*/;
    // 0041da83  c74424780000803f       -mov dword ptr [esp + 0x78], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = 1065353216 /*0x3f800000*/;
    // 0041da8b  c74424740000803f       -mov dword ptr [esp + 0x74], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = 1065353216 /*0x3f800000*/;
    // 0041da93  c78424800000000000803f -mov dword ptr [esp + 0x80], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = 1065353216 /*0x3f800000*/;
    // 0041da9e  c78424840000000000803f -mov dword ptr [esp + 0x84], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 1065353216 /*0x3f800000*/;
    // 0041daa9  c74424540000803b       -mov dword ptr [esp + 0x54], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = 998244352 /*0x3b800000*/;
    // 0041dab1  c74424640000803b       -mov dword ptr [esp + 0x64], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 998244352 /*0x3b800000*/;
    // 0041dab9  c744245800007f3f       -mov dword ptr [esp + 0x58], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = 1065287680 /*0x3f7f0000*/;
    // 0041dac1  c74424680000803b       -mov dword ptr [esp + 0x68], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = 998244352 /*0x3b800000*/;
    // 0041dac9  c744245c00007f3f       -mov dword ptr [esp + 0x5c], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 1065287680 /*0x3f7f0000*/;
    // 0041dad1  c744246c00007f3f       -mov dword ptr [esp + 0x6c], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = 1065287680 /*0x3f7f0000*/;
    // 0041dad9  c74424600000803b       -mov dword ptr [esp + 0x60], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = 998244352 /*0x3b800000*/;
    // 0041dae1  c744247000007f3f       -mov dword ptr [esp + 0x70], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = 1065287680 /*0x3f7f0000*/;
L_0x0041dae9:
    // 0041dae9  8d446d00               -lea eax, [ebp + ebp*2]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 2);
    // 0041daed  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041daef  8d348534c94a00         -lea esi, [eax*4 + 0x4ac934]
    cpu.esi = x86::reg32(x86::reg32(4901172) /* 0x4ac934 */ + cpu.eax * 4);
    // 0041daf6  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
L_0x0041dafa:
    // 0041dafa  833e00                 +cmp dword ptr [esi], 0
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
    // 0041dafd  7527                   -jne 0x41db26
    if (!cpu.flags.zf)
    {
        goto L_0x0041db26;
    }
    // 0041daff  8d446d00               -lea eax, [ebp + ebp*2]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 2);
    // 0041db03  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041db07  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0041db09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041db0a  6800104900             -push 0x491000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788224 /*0x491000*/;
    cpu.esp -= 4;
    // 0041db0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041db10  e8e3920500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041db15  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041db18  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041db1a  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041db1e  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db24  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0041db26:
    // 0041db26  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041db28  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041db2a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041db2b  ff15bc704800           -call dword ptr [0x4870bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747452) /* 0x4870bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041db31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041db33  0f85c0000000           -jne 0x41dbf9
    if (!cpu.flags.zf)
    {
        goto L_0x0041dbf9;
    }
    // 0041db39  a150f85100             -mov eax, dword ptr [0x51f850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0041db3e  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0041db41  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041db43  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041db46  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041db48  b867666666             -mov eax, 0x66666667
    cpu.eax = 1717986919 /*0x66666667*/;
    // 0041db4d  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041db4f  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041db52  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041db54  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0041db57  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041db59  a154f85100             -mov eax, dword ptr [0x51f854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0041db5e  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0041db61  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041db63  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0041db65  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041db68  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041db6a  b889888888             -mov eax, 0x88888889
    cpu.eax = 2290649225 /*0x88888889*/;
    // 0041db6f  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041db71  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0041db74  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041db76  0faf0550f85100         -imul eax, dword ptr [0x51f850]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */))));
    // 0041db7d  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041db80  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041db82  89742434               -mov dword ptr [esp + 0x34], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 0041db86  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0041db89  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041db8b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041db8d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041db90  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041db92  b867666666             -mov eax, 0x66666667
    cpu.eax = 1717986919 /*0x66666667*/;
    // 0041db97  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041db99  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041db9b  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041db9e  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041dba0  897c2444               -mov dword ptr [esp + 0x44], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.edi;
    // 0041dba4  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0041dba7  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041dba9  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0041dbac  0faf0554f85100         -imul eax, dword ptr [0x51f854]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */))));
    // 0041dbb3  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041dbb5  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0041dbb9  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041dbbc  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041dbbe  b889888888             -mov eax, 0x88888889
    cpu.eax = 2290649225 /*0x88888889*/;
    // 0041dbc3  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0041dbc7  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041dbc9  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041dbcb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041dbcf  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041dbd2  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041dbd4  897c2448               -mov dword ptr [esp + 0x48], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edi;
    // 0041dbd8  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0041dbdb  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041dbdd  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041dbdf  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0041dbe3  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0041dbe7  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0041dbeb  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0041dbef  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041dbf5  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0041dbf9:
    // 0041dbf9  43                     -inc ebx
    (cpu.ebx)++;
    // 0041dbfa  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041dbfd  83fb03                 +cmp ebx, 3
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
    // 0041dc00  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0041dc04  0f8cf0feffff           -jl 0x41dafa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041dafa;
    }
    // 0041dc0a  45                     -inc ebp
    (cpu.ebp)++;
    // 0041dc0b  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dc0e  0f8cd5feffff           -jl 0x41dae9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041dae9;
    }
    // 0041dc14  a154c94a00             -mov eax, dword ptr [0x4ac954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901204) /* 0x4ac954 */);
    // 0041dc19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dc1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dc1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dc1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041dc1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041dc1f  7516                   -jne 0x41dc37
    if (!cpu.flags.zf)
    {
        goto L_0x0041dc37;
    }
    // 0041dc21  68f80f4900             -push 0x490ff8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788216 /*0x490ff8*/;
    cpu.esp -= 4;
    // 0041dc26  e895710300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0041dc2b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041dc2e  a354c94a00             -mov dword ptr [0x4ac954], eax
    app->getMemory<x86::reg32>(x86::reg32(4901204) /* 0x4ac954 */) = cpu.eax;
    // 0041dc33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041dc35  7407                   -je 0x41dc3e
    if (cpu.flags.zf)
    {
        goto L_0x0041dc3e;
    }
L_0x0041dc37:
    // 0041dc37  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041dc39  e892f0ffff             -call 0x41ccd0
    cpu.esp -= 4;
    sub_41ccd0(app, cpu);
L_0x0041dc3e:
    // 0041dc3e  e81df5ffff             -call 0x41d160
    cpu.esp -= 4;
    sub_41d160(app, cpu);
    // 0041dc43  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041dc45  e886f0ffff             -call 0x41ccd0
    cpu.esp -= 4;
    sub_41ccd0(app, cpu);
    // 0041dc4a  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0041dc50  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41dc60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041dc60  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0041dc66  a17cc94a00             -mov eax, dword ptr [0x4ac97c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901244) /* 0x4ac97c */);
    // 0041dc6b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041dc6c  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0041dc6e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041dc6f  3bc5                   +cmp eax, ebp
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
    // 0041dc71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041dc72  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0041dc76  7435                   -je 0x41dcad
    if (cpu.flags.zf)
    {
        goto L_0x0041dcad;
    }
    // 0041dc78  8b0d60c94a00           -mov ecx, dword ptr [0x4ac960]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901216) /* 0x4ac960 */);
    // 0041dc7e  892d7cc94a00           -mov dword ptr [0x4ac97c], ebp
    app->getMemory<x86::reg32>(x86::reg32(4901244) /* 0x4ac97c */) = cpu.ebp;
    // 0041dc84  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041dc86  741d                   -je 0x41dca5
    if (cpu.flags.zf)
    {
        goto L_0x0041dca5;
    }
    // 0041dc88  bf60c94a00             -mov edi, 0x4ac960
    cpu.edi = 4901216 /*0x4ac960*/;
    // 0041dc8d  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0041dc8f:
    // 0041dc8f  e8bcfdffff             -call 0x41da50
    cpu.esp -= 4;
    sub_41da50(app, cpu);
    // 0041dc94  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041dc97  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0041dc9d  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0041dc9f  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041dca1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041dca3  75ea                   -jne 0x41dc8f
    if (!cpu.flags.zf)
    {
        goto L_0x0041dc8f;
    }
L_0x0041dca5:
    // 0041dca5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041dca7  0f84b3010000           -je 0x41de60
    if (cpu.flags.zf)
    {
        goto L_0x0041de60;
    }
L_0x0041dcad:
    // 0041dcad  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041dcaf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041dcb0  c644247800             -mov byte ptr [esp + 0x78], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 0041dcb5  c74424680000803f       -mov dword ptr [esp + 0x68], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = 1065353216 /*0x3f800000*/;
    // 0041dcbd  c74424640000803f       -mov dword ptr [esp + 0x64], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 1065353216 /*0x3f800000*/;
    // 0041dcc5  c74424600000803f       -mov dword ptr [esp + 0x60], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = 1065353216 /*0x3f800000*/;
    // 0041dccd  c744246c0000803f       -mov dword ptr [esp + 0x6c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = 1065353216 /*0x3f800000*/;
    // 0041dcd5  c74424700000803f       -mov dword ptr [esp + 0x70], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = 1065353216 /*0x3f800000*/;
    // 0041dcdd  c74424400000803b       -mov dword ptr [esp + 0x40], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 998244352 /*0x3b800000*/;
    // 0041dce5  c74424500000803b       -mov dword ptr [esp + 0x50], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = 998244352 /*0x3b800000*/;
    // 0041dced  c74424540000803b       -mov dword ptr [esp + 0x54], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = 998244352 /*0x3b800000*/;
    // 0041dcf5  c744244c0000803b       -mov dword ptr [esp + 0x4c], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = 998244352 /*0x3b800000*/;
    // 0041dcfd  c744244400007f3f       -mov dword ptr [esp + 0x44], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = 1065287680 /*0x3f7f0000*/;
    // 0041dd05  c744244800007f3f       -mov dword ptr [esp + 0x48], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = 1065287680 /*0x3f7f0000*/;
    // 0041dd0d  c744245800007f3f       -mov dword ptr [esp + 0x58], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = 1065287680 /*0x3f7f0000*/;
    // 0041dd15  c744245c00007f3f       -mov dword ptr [esp + 0x5c], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 1065287680 /*0x3f7f0000*/;
    // 0041dd1d  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0041dd21  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041dd25  bb60c94a00             -mov ebx, 0x4ac960
    cpu.ebx = 4901216 /*0x4ac960*/;
    // 0041dd2a  eb04                   -jmp 0x41dd30
    goto L_0x0041dd30;
L_0x0041dd2c:
    // 0041dd2c  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0041dd30:
    // 0041dd30  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041dd34  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0041dd36  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0041dd37  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041dd39  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041dd3d  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0041dd41  eb08                   -jmp 0x41dd4b
    goto L_0x0041dd4b;
L_0x0041dd43:
    // 0041dd43  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041dd47  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0041dd4b:
    // 0041dd4b  833b00                 +cmp dword ptr [ebx], 0
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
    // 0041dd4e  7537                   -jne 0x41dd87
    if (!cpu.flags.zf)
    {
        goto L_0x0041dd87;
    }
    // 0041dd50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041dd51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041dd52  8d942484000000         -lea edx, [esp + 0x84]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0041dd59  6834104900             -push 0x491034
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788276 /*0x491034*/;
    cpu.esp -= 4;
    // 0041dd5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041dd5f  e894900500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041dd64  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041dd67  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041dd6a  7e0d                   -jle 0x41dd79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041dd79;
    }
    // 0041dd6c  680c104900             -push 0x49100c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788236 /*0x49100c*/;
    cpu.esp -= 4;
    // 0041dd71  e89a6e0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041dd76  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041dd79:
    // 0041dd79  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041dd7b  8d4c247c               -lea ecx, [esp + 0x7c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0041dd7f  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041dd85  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0041dd87:
    // 0041dd87  8b0d50f85100           -mov ecx, dword ptr [0x51f850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0041dd8d  b867666666             -mov eax, 0x66666667
    cpu.eax = 1717986919 /*0x66666667*/;
    // 0041dd92  0fafce                 -imul ecx, esi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0041dd95  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041dd98  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041dd9a  8b0d54f85100           -mov ecx, dword ptr [0x51f854]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0041dda0  0faf4c2414             -imul ecx, dword ptr [esp + 0x14]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0041dda5  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041dda8  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041ddaa  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0041ddad  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041ddaf  b889888888             -mov eax, 0x88888889
    cpu.eax = 2290649225 /*0x88888889*/;
    // 0041ddb4  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041ddb7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041ddb9  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041ddbb  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ddbd  b867666666             -mov eax, 0x66666667
    cpu.eax = 1717986919 /*0x66666667*/;
    // 0041ddc2  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041ddc5  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041ddc7  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0041ddcb  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0041ddce  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ddd0  46                     -inc esi
    (cpu.esi)++;
    // 0041ddd1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041ddd3  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0041ddd5  0faf0d50f85100         -imul ecx, dword ptr [0x51f850]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */))));
    // 0041dddc  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041dddf  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041dde1  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041dde5  896c2430               -mov dword ptr [esp + 0x30], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebp;
    // 0041dde9  0faf0d54f85100         -imul ecx, dword ptr [0x51f854]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */))));
    // 0041ddf0  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041ddf3  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041ddf5  896c2434               -mov dword ptr [esp + 0x34], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebp;
    // 0041ddf9  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0041ddfc  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041ddfe  b889888888             -mov eax, 0x88888889
    cpu.eax = 2290649225 /*0x88888889*/;
    // 0041de03  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041de06  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0041de0a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0041de0e  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041de10  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041de12  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0041de16  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041de19  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041de1b  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0041de1e  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041de20  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0041de22  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0041de26  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0041de2a  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041de2e  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041de34  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041de38  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041de3b  41                     -inc ecx
    (cpu.ecx)++;
    // 0041de3c  83fe03                 +cmp esi, 3
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
    // 0041de3f  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041de43  0f8cfafeffff           -jl 0x41dd43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041dd43;
    }
    // 0041de49  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041de4d  81fb78c94a00           +cmp ebx, 0x4ac978
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4901240 /*0x4ac978*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041de53  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0041de57  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041de59  0f8ccdfeffff           -jl 0x41dd2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041dd2c;
    }
    // 0041de5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041de60:
    // 0041de60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041de63  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0041de69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41de70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041de70  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0041de76  a19cc94a00             -mov eax, dword ptr [0x4ac99c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901276) /* 0x4ac99c */);
    // 0041de7b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041de7c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041de7d  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0041de7f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041de80  3bc5                   +cmp eax, ebp
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
    // 0041de82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041de83  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041de85  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0041de89  750d                   -jne 0x41de98
    if (!cpu.flags.zf)
    {
        goto L_0x0041de98;
    }
    // 0041de8b  8b8c24a0000000         -mov ecx, dword ptr [esp + 0xa0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0041de92  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041de94  3bc8                   +cmp ecx, eax
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
    // 0041de96  7437                   -je 0x41decf
    if (cpu.flags.zf)
    {
        goto L_0x0041decf;
    }
L_0x0041de98:
    // 0041de98  8b0d80c94a00           -mov ecx, dword ptr [0x4ac980]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901248) /* 0x4ac980 */);
    // 0041de9e  892d9cc94a00           -mov dword ptr [0x4ac99c], ebp
    app->getMemory<x86::reg32>(x86::reg32(4901276) /* 0x4ac99c */) = cpu.ebp;
    // 0041dea4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041dea6  741d                   -je 0x41dec5
    if (cpu.flags.zf)
    {
        goto L_0x0041dec5;
    }
    // 0041dea8  bf80c94a00             -mov edi, 0x4ac980
    cpu.edi = 4901248 /*0x4ac980*/;
    // 0041dead  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0041deaf:
    // 0041deaf  e89cfbffff             -call 0x41da50
    cpu.esp -= 4;
    sub_41da50(app, cpu);
    // 0041deb4  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041deb7  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0041debd  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0041debf  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041dec1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041dec3  75ea                   -jne 0x41deaf
    if (!cpu.flags.zf)
    {
        goto L_0x0041deaf;
    }
L_0x0041dec5:
    // 0041dec5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041dec7  3be8                   +cmp ebp, eax
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
    // 0041dec9  0f84aa010000           -je 0x41e079
    if (cpu.flags.zf)
    {
        goto L_0x0041e079;
    }
L_0x0041decf:
    // 0041decf  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0041ded2  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0041ded4  894c246c               -mov dword ptr [esp + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 0041ded8  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0041dedb  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0041dedf  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0041dee2  c644247800             -mov byte ptr [esp + 0x78], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 0041dee7  894c2464               -mov dword ptr [esp + 0x64], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ecx;
    // 0041deeb  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 0041deef  c74424700000803f       -mov dword ptr [esp + 0x70], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = 1065353216 /*0x3f800000*/;
    // 0041def7  c74424400000803b       -mov dword ptr [esp + 0x40], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 998244352 /*0x3b800000*/;
    // 0041deff  c74424500000803b       -mov dword ptr [esp + 0x50], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = 998244352 /*0x3b800000*/;
    // 0041df07  c74424540000803b       -mov dword ptr [esp + 0x54], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = 998244352 /*0x3b800000*/;
    // 0041df0f  c744244c0000803b       -mov dword ptr [esp + 0x4c], 0x3b800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = 998244352 /*0x3b800000*/;
    // 0041df17  c744244400007f3f       -mov dword ptr [esp + 0x44], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = 1065287680 /*0x3f7f0000*/;
    // 0041df1f  c744244800007f3f       -mov dword ptr [esp + 0x48], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = 1065287680 /*0x3f7f0000*/;
    // 0041df27  c744245800007f3f       -mov dword ptr [esp + 0x58], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = 1065287680 /*0x3f7f0000*/;
    // 0041df2f  c744245c00007f3f       -mov dword ptr [esp + 0x5c], 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 1065287680 /*0x3f7f0000*/;
    // 0041df37  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0041df3b  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041df3f  bb80c94a00             -mov ebx, 0x4ac980
    cpu.ebx = 4901248 /*0x4ac980*/;
    // 0041df44  eb04                   -jmp 0x41df4a
    goto L_0x0041df4a;
L_0x0041df46:
    // 0041df46  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0041df4a:
    // 0041df4a  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041df4e  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0041df50  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0041df51  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041df53  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041df57  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0041df5b  eb08                   -jmp 0x41df65
    goto L_0x0041df65;
L_0x0041df5d:
    // 0041df5d  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041df61  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0041df65:
    // 0041df65  833b00                 +cmp dword ptr [ebx], 0
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
    // 0041df68  7537                   -jne 0x41dfa1
    if (!cpu.flags.zf)
    {
        goto L_0x0041dfa1;
    }
    // 0041df6a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041df6b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041df6c  8d942484000000         -lea edx, [esp + 0x84]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0041df73  6834104900             -push 0x491034
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788276 /*0x491034*/;
    cpu.esp -= 4;
    // 0041df78  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041df79  e87a8e0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041df7e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041df81  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041df84  7e0d                   -jle 0x41df93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041df93;
    }
    // 0041df86  680c104900             -push 0x49100c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788236 /*0x49100c*/;
    cpu.esp -= 4;
    // 0041df8b  e8806c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041df90  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041df93:
    // 0041df93  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041df95  8d4c247c               -lea ecx, [esp + 0x7c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0041df99  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041df9f  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0041dfa1:
    // 0041dfa1  8b0d50f85100           -mov ecx, dword ptr [0x51f850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0041dfa7  b867666666             -mov eax, 0x66666667
    cpu.eax = 1717986919 /*0x66666667*/;
    // 0041dfac  0fafce                 -imul ecx, esi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0041dfaf  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041dfb2  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041dfb4  8b0d54f85100           -mov ecx, dword ptr [0x51f854]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0041dfba  0faf4c2414             -imul ecx, dword ptr [esp + 0x14]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0041dfbf  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041dfc2  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041dfc4  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0041dfc7  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041dfc9  b889888888             -mov eax, 0x88888889
    cpu.eax = 2290649225 /*0x88888889*/;
    // 0041dfce  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041dfd1  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041dfd3  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041dfd5  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041dfd7  b867666666             -mov eax, 0x66666667
    cpu.eax = 1717986919 /*0x66666667*/;
    // 0041dfdc  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041dfdf  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041dfe1  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0041dfe5  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0041dfe8  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041dfea  46                     -inc esi
    (cpu.esi)++;
    // 0041dfeb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041dfed  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0041dfef  0faf0d50f85100         -imul ecx, dword ptr [0x51f850]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */))));
    // 0041dff6  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041dff9  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041dffb  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041dfff  896c2430               -mov dword ptr [esp + 0x30], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebp;
    // 0041e003  0faf0d54f85100         -imul ecx, dword ptr [0x51f854]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */))));
    // 0041e00a  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041e00d  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041e00f  896c2434               -mov dword ptr [esp + 0x34], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebp;
    // 0041e013  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0041e016  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041e018  b889888888             -mov eax, 0x88888889
    cpu.eax = 2290649225 /*0x88888889*/;
    // 0041e01d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0041e020  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0041e024  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0041e028  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0041e02a  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041e02c  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0041e030  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0041e033  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041e035  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0041e038  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041e03a  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0041e03c  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0041e040  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0041e044  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041e048  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041e04e  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041e052  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041e055  41                     -inc ecx
    (cpu.ecx)++;
    // 0041e056  83fe03                 +cmp esi, 3
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
    // 0041e059  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041e05d  0f8cfafeffff           -jl 0x41df5d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041df5d;
    }
    // 0041e063  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041e067  81fb98c94a00           +cmp ebx, 0x4ac998
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4901272 /*0x4ac998*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041e06d  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0041e071  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041e073  0f8ccdfeffff           -jl 0x41df46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041df46;
    }
L_0x0041e079:
    // 0041e079  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e07a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e07b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e07c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e07d  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0041e083  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41e090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e090  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e091  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041e093  e8c8fbffff             -call 0x41dc60
    cpu.esp -= 4;
    sub_41dc60(app, cpu);
    // 0041e098  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041e09a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e09b  7405                   -je 0x41e0a2
    if (cpu.flags.zf)
    {
        goto L_0x0041e0a2;
    }
    // 0041e09d  e8fe92ffff             -call 0x4173a0
    cpu.esp -= 4;
    sub_4173a0(app, cpu);
L_0x0041e0a2:
    // 0041e0a2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41e0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e0b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e0b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e0b2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041e0b4  e8b7000000             -call 0x41e170
    cpu.esp -= 4;
    sub_41e170(app, cpu);
    // 0041e0b9  e8c2000000             -call 0x41e180
    cpu.esp -= 4;
    sub_41e180(app, cpu);
    // 0041e0be  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e0c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e0c3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041e0c5  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041e0c9  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041e0cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041e0cc  e8ce960500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041e0d1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041e0d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e0d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e0d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e0e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e0e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e0e2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041e0e4  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041e0e8  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041e0ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041e0eb  c705b0c94a0000000000   -mov dword ptr [0x4ac9b0], 0
    app->getMemory<x86::reg32>(x86::reg32(4901296) /* 0x4ac9b0 */) = 0 /*0x0*/;
    // 0041e0f5  e88e950500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041e0fa  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041e0fd  e82e760400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e102  d8642400               -fsub dword ptr [esp]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp));
    // 0041e106  d91da8c94a00           -fstp dword ptr [0x4ac9a8]
    app->getMemory<float>(x86::reg32(4901288) /* 0x4ac9a8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e10c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e10d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e110  83f901                 +cmp ecx, 1
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
    // 0041e113  750c                   -jne 0x41e121
    if (!cpu.flags.zf)
    {
        goto L_0x0041e121;
    }
    // 0041e115  e816760400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e11a  d91db0c94a00           -fstp dword ptr [0x4ac9b0]
    app->getMemory<float>(x86::reg32(4901296) /* 0x4ac9b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e120  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041e121:
    // 0041e121  d905b0c94a00           -fld dword ptr [0x4ac9b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4901296) /* 0x4ac9b0 */)));
    // 0041e127  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041e12d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e12f  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041e134  7521                   -jne 0x41e157
    if (!cpu.flags.zf)
    {
        goto L_0x0041e157;
    }
    // 0041e136  e8f5750400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e13b  d825b0c94a00           -fsub dword ptr [0x4ac9b0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4901296) /* 0x4ac9b0 */));
    // 0041e141  d805a8c94a00           -fadd dword ptr [0x4ac9a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4901288) /* 0x4ac9a8 */));
    // 0041e147  c705b0c94a0000000000   -mov dword ptr [0x4ac9b0], 0
    app->getMemory<x86::reg32>(x86::reg32(4901296) /* 0x4ac9b0 */) = 0 /*0x0*/;
    // 0041e151  d91da8c94a00           -fstp dword ptr [0x4ac9a8]
    app->getMemory<float>(x86::reg32(4901288) /* 0x4ac9a8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041e157:
    // 0041e157  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e160  e8cb750400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e165  d91da8c94a00           -fstp dword ptr [0x4ac9a8]
    app->getMemory<float>(x86::reg32(4901288) /* 0x4ac9a8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e16b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e170  e8bb750400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e175  d91dacc94a00           -fstp dword ptr [0x4ac9ac]
    app->getMemory<float>(x86::reg32(4901292) /* 0x4ac9ac */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e17b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e180  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e181  d905acc94a00           -fld dword ptr [0x4ac9ac]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4901292) /* 0x4ac9ac */)));
    // 0041e187  d825a8c94a00           -fsub dword ptr [0x4ac9a8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4901288) /* 0x4ac9a8 */));
    // 0041e18d  d9542400               -fst dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    // 0041e191  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041e197  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e199  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041e19c  7a23                   -jp 0x41e1c1
    if (cpu.flags.pf)
    {
        goto L_0x0041e1c1;
    }
    // 0041e19e  d905acc94a00           -fld dword ptr [0x4ac9ac]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4901292) /* 0x4ac9ac */)));
    // 0041e1a4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041e1a7  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e1ab  d905a8c94a00           -fld dword ptr [0x4ac9a8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4901288) /* 0x4ac9a8 */)));
    // 0041e1b1  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e1b4  6840104900             -push 0x491040
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788288 /*0x491040*/;
    cpu.esp -= 4;
    // 0041e1b9  e8526a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041e1be  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0041e1c1:
    // 0041e1c1  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0041e1c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e1c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e1d0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041e1d2  a3a0c94a00             -mov dword ptr [0x4ac9a0], eax
    app->getMemory<x86::reg32>(x86::reg32(4901280) /* 0x4ac9a0 */) = cpu.eax;
    // 0041e1d7  a3a4c94a00             -mov dword ptr [0x4ac9a4], eax
    app->getMemory<x86::reg32>(x86::reg32(4901284) /* 0x4ac9a4 */) = cpu.eax;
    // 0041e1dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e1e0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041e1e2  880d8cc74a00           -mov byte ptr [0x4ac78c], cl
    app->getMemory<x86::reg8>(x86::reg32(4900748) /* 0x4ac78c */) = cpu.cl;
    // 0041e1e8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041e1ea  0f9fc0                 -setg al
    cpu.al = (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of));
    // 0041e1ed  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041e1ef  a388d34a00             -mov dword ptr [0x4ad388], eax
    app->getMemory<x86::reg32>(x86::reg32(4903816) /* 0x4ad388 */) = cpu.eax;
    // 0041e1f4  750f                   -jne 0x41e205
    if (!cpu.flags.zf)
    {
        goto L_0x0041e205;
    }
    // 0041e1f6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e1f7  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041e1f9  e892feffff             -call 0x41e090
    cpu.esp -= 4;
    sub_41e090(app, cpu);
    // 0041e1fe  c6058dc74a0000         -mov byte ptr [0x4ac78d], 0
    app->getMemory<x86::reg8>(x86::reg32(4900749) /* 0x4ac78d */) = 0 /*0x0*/;
L_0x0041e205:
    // 0041e205  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e210  a130c94a00             -mov eax, dword ptr [0x4ac930]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901168) /* 0x4ac930 */);
    // 0041e215  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e217  7444                   -je 0x41e25d
    if (cpu.flags.zf)
    {
        goto L_0x0041e25d;
    }
    // 0041e219  ff052cc94a00           -inc dword ptr [0x4ac92c]
    (app->getMemory<x86::reg32>(x86::reg32(4901164) /* 0x4ac92c */))++;
    // 0041e21f  e80c750400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e224  dc25b8c94a00           -fsub qword ptr [0x4ac9b8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4901304) /* 0x4ac9b8 */));
    // 0041e22a  dc1d28754800           -fcomp qword ptr [0x487528]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748584) /* 0x487528 */)));
    cpu.fpu.pop();
    // 0041e230  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e232  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041e235  7b26                   -jnp 0x41e25d
    if (!cpu.flags.pf)
    {
        goto L_0x0041e25d;
    }
    // 0041e237  e8f4740400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e23c  a180845100             -mov eax, dword ptr [0x518480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342336) /* 0x518480 */);
    // 0041e241  dd1db8c94a00           -fstp qword ptr [0x4ac9b8]
    app->getMemory<double>(x86::reg32(4901304) /* 0x4ac9b8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e247  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e249  7412                   -je 0x41e25d
    if (cpu.flags.zf)
    {
        goto L_0x0041e25d;
    }
    // 0041e24b  db052cc94a00           -fild dword ptr [0x4ac92c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4901164) /* 0x4ac92c */))));
    // 0041e251  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e252  da3520034900           -fidiv dword ptr [0x490320]
    cpu.fpu.st(0) /= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4784928) /* 0x490320 */)));
    // 0041e258  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e25b  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0041e25d:
    // 0041e25d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e260  a130c94a00             -mov eax, dword ptr [0x4ac930]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901168) /* 0x4ac930 */);
    // 0041e265  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0041e268  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e269  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041e26b  3bc6                   +cmp eax, esi
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
    // 0041e26d  0f848e000000           -je 0x41e301
    if (cpu.flags.zf)
    {
        goto L_0x0041e301;
    }
    // 0041e273  a1dc284900             -mov eax, dword ptr [0x4928dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
    // 0041e278  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041e27c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041e27d  687c104900             -push 0x49107c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788348 /*0x49107c*/;
    cpu.esp -= 4;
    // 0041e282  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e283  e8708b0500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0041e288  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041e28b  893530c94a00           -mov dword ptr [0x4ac930], esi
    app->getMemory<x86::reg32>(x86::reg32(4901168) /* 0x4ac930 */) = cpu.esi;
    // 0041e291  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041e293  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041e297  7531                   -jne 0x41e2ca
    if (!cpu.flags.zf)
    {
        goto L_0x0041e2ca;
    }
    // 0041e299  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 0041e29e  e89de70200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041e2a3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041e2a5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041e2a7  7418                   -je 0x41e2c1
    if (cpu.flags.zf)
    {
        goto L_0x0041e2c1;
    }
    // 0041e2a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e2aa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041e2ac  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041e2ae  682cc94a00             -push 0x4ac92c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4901164 /*0x4ac92c*/;
    cpu.esp -= 4;
    // 0041e2b3  e8e7940500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041e2b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e2b9  e819930500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041e2be  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0041e2c1:
    // 0041e2c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e2c2  83c450                 +add esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041e2c5  e946000000             -jmp 0x41e310
    return sub_41e310(app, cpu);
L_0x0041e2ca:
    // 0041e2ca  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0041e2cf  e86ce70200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041e2d4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041e2d6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041e2d8  741d                   -je 0x41e2f7
    if (cpu.flags.zf)
    {
        goto L_0x0041e2f7;
    }
    // 0041e2da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e2db  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041e2dd  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041e2df  6820034900             -push 0x490320
    app->getMemory<x86::reg32>(cpu.esp-4) = 4784928 /*0x490320*/;
    cpu.esp -= 4;
    // 0041e2e4  e89f930500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041e2e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e2ea  e8e8920500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041e2ef  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041e2f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e2f3  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0041e2f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041e2f7:
    // 0041e2f7  c7052003490000000000   -mov dword ptr [0x490320], 0
    app->getMemory<x86::reg32>(x86::reg32(4784928) /* 0x490320 */) = 0 /*0x0*/;
L_0x0041e301:
    // 0041e301  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e302  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0041e305  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e310  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e320  a1c0c94a00             -mov eax, dword ptr [0x4ac9c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901312) /* 0x4ac9c0 */);
    // 0041e325  83ec68                 -sub esp, 0x68
    (cpu.esp) -= x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0041e328  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e32a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041e32b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e32c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041e32d  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0041e32f  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0041e331  7526                   -jne 0x41e359
    if (!cpu.flags.zf)
    {
        goto L_0x0041e359;
    }
    // 0041e333  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0041e338  b974094900             -mov ecx, 0x490974
    cpu.ecx = 4786548 /*0x490974*/;
    // 0041e33d  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041e343  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e345  a3c0c94a00             -mov dword ptr [0x4ac9c0], eax
    app->getMemory<x86::reg32>(x86::reg32(4901312) /* 0x4ac9c0 */) = cpu.eax;
    // 0041e34a  750d                   -jne 0x41e359
    if (!cpu.flags.zf)
    {
        goto L_0x0041e359;
    }
    // 0041e34c  68c8104900             -push 0x4910c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788424 /*0x4910c8*/;
    cpu.esp -= 4;
    // 0041e351  e8ba680000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041e356  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041e359:
    // 0041e359  8b0dc4c94a00           -mov ecx, dword ptr [0x4ac9c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901316) /* 0x4ac9c4 */);
    // 0041e35f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041e361  752f                   -jne 0x41e392
    if (!cpu.flags.zf)
    {
        goto L_0x0041e392;
    }
    // 0041e363  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0041e368  b9b8104900             -mov ecx, 0x4910b8
    cpu.ecx = 4788408 /*0x4910b8*/;
    // 0041e36d  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041e373  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041e375  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041e377  890dc4c94a00           -mov dword ptr [0x4ac9c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(4901316) /* 0x4ac9c4 */) = cpu.ecx;
    // 0041e37d  7513                   -jne 0x41e392
    if (!cpu.flags.zf)
    {
        goto L_0x0041e392;
    }
    // 0041e37f  6890104900             -push 0x491090
    app->getMemory<x86::reg32>(cpu.esp-4) = 4788368 /*0x491090*/;
    cpu.esp -= 4;
    // 0041e384  e887680000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041e389  8b0dc4c94a00           -mov ecx, dword ptr [0x4ac9c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901316) /* 0x4ac9c4 */);
    // 0041e38f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041e392:
    // 0041e392  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0041e394  2503000080             +and eax, 0x80000003
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2147483651 /*0x80000003*/))));
    // 0041e399  7905                   -jns 0x41e3a0
    if (!cpu.flags.sf)
    {
        goto L_0x0041e3a0;
    }
    // 0041e39b  48                     -dec eax
    (cpu.eax)--;
    // 0041e39c  83c8fc                 -or eax, 0xfffffffc
    cpu.eax |= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 0041e39f  40                     -inc eax
    (cpu.eax)++;
L_0x0041e3a0:
    // 0041e3a0  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041e3a4  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0041e3a6  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0041e3aa  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041e3ab  d80d4c764800           -fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 0041e3b1  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0041e3b4  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041e3b6  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0041e3b9  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e3bd  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041e3c1  83fd24                 +cmp ebp, 0x24
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041e3c4  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0041e3c8  d80d4c764800           +fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 0041e3ce  d95c2410               +fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e3d2  d944240c               +fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0041e3d6  d80d10764800           +fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041e3dc  d9442410               +fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0041e3e0  d80d10764800           +fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041e3e6  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e3ea  d944240c               +fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0041e3ee  d8054c764800           +fadd dword ptr [0x48764c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 0041e3f4  d80d10764800           +fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041e3fa  d95c240c               +fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e3fe  d9442410               +fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0041e402  d8054c764800           +fadd dword ptr [0x48764c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 0041e408  d80d10764800           +fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041e40e  d95c2410               +fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e412  7520                   -jne 0x41e434
    if (!cpu.flags.zf)
    {
        goto L_0x0041e434;
    }
    // 0041e414  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e416  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0041e41c  c74424140000003f       -mov dword ptr [esp + 0x14], 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1056964608 /*0x3f000000*/;
    // 0041e424  c744240c0000003f       -mov dword ptr [esp + 0xc], 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1056964608 /*0x3f000000*/;
    // 0041e42c  c74424100000803f       -mov dword ptr [esp + 0x10], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1065353216 /*0x3f800000*/;
L_0x0041e434:
    // 0041e434  dc0d60774800           -fmul qword ptr [0x487760]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749152) /* 0x487760 */));
    // 0041e43a  8b7c247c               -mov edi, dword ptr [esp + 0x7c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0041e43e  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0041e442  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0041e446  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0041e44a  8d743eff               -lea esi, [esi + edi - 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.edi * 1);
    // 0041e44e  8d5438ff               -lea edx, [eax + edi - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */ + cpu.edi * 1);
    // 0041e452  d9542438               -fst dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    // 0041e456  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0041e45a  dc0d60774800           -fmul qword ptr [0x487760]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749152) /* 0x487760 */));
    // 0041e460  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0041e464  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0041e468  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e469  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0041e46d  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0041e471  83fd24                 +cmp ebp, 0x24
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041e474  d9542444               +fst dword ptr [esp + 0x44]
    app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */) = float(cpu.fpu.st(0));
    // 0041e478  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0041e47a  d95c2438               +fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e47e  d944240c               +fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0041e482  dc0d50744800           +fmul qword ptr [0x487450]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748368) /* 0x487450 */));
    // 0041e488  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e489  c644246800             -mov byte ptr [esp + 0x68], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(104) /* 0x68 */) = 0 /*0x0*/;
    // 0041e48e  c744246400000000       -mov dword ptr [esp + 0x64], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 0 /*0x0*/;
    // 0041e496  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041e49a  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0041e49e  c74424580000803f       -mov dword ptr [esp + 0x58], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = 1065353216 /*0x3f800000*/;
    // 0041e4a6  d9542444               +fst dword ptr [esp + 0x44]
    app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */) = float(cpu.fpu.st(0));
    // 0041e4aa  d9442404               +fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041e4ae  dc0d50744800           +fmul qword ptr [0x487450]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748368) /* 0x487450 */));
    // 0041e4b4  c74424540000803f       -mov dword ptr [esp + 0x54], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = 1065353216 /*0x3f800000*/;
    // 0041e4bc  c74424500000803f       -mov dword ptr [esp + 0x50], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = 1065353216 /*0x3f800000*/;
    // 0041e4c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e4c5  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041e4c9  d9542434               +fst dword ptr [esp + 0x34]
    app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    // 0041e4cd  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0041e4cf  d95c2444               +fstp dword ptr [esp + 0x44]
    app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e4d3  d95c2438               +fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e4d7  d95c2448               +fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e4db  d9442474               +fld dword ptr [esp + 0x74]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(116) /* 0x74 */)));
    // 0041e4df  dc0d50744800           +fmul qword ptr [0x487450]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748368) /* 0x487450 */));
    // 0041e4e5  d95c2458               +fstp dword ptr [esp + 0x58]
    app->getMemory<float>(cpu.esp + x86::reg32(88) /* 0x58 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e4e9  7406                   -je 0x41e4f1
    if (cpu.flags.zf)
    {
        goto L_0x0041e4f1;
    }
    // 0041e4eb  8b0dc0c94a00           -mov ecx, dword ptr [0x4ac9c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901312) /* 0x4ac9c0 */);
L_0x0041e4f1:
    // 0041e4f1  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041e4f7  83c468                 -add esp, 0x68
    (cpu.esp) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0041e4fa  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_41e500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e500  8b0dccc94a00           -mov ecx, dword ptr [0x4ac9cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901324) /* 0x4ac9cc */);
    // 0041e506  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041e509  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e50a  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041e50c  3bce                   +cmp ecx, esi
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
    // 0041e50e  0f8489020000           -je 0x41e79d
    if (cpu.flags.zf)
    {
        goto L_0x0041e79d;
    }
    // 0041e514  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0041e51a  3bd1                   +cmp edx, ecx
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
    // 0041e51c  7e1b                   -jle 0x41e539
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041e539;
    }
    // 0041e51e  8935ccc94a00           -mov dword ptr [0x4ac9cc], esi
    app->getMemory<x86::reg32>(x86::reg32(4901324) /* 0x4ac9cc */) = cpu.esi;
    // 0041e524  8935c8c94a00           -mov dword ptr [0x4ac9c8], esi
    app->getMemory<x86::reg32>(x86::reg32(4901320) /* 0x4ac9c8 */) = cpu.esi;
    // 0041e52a  c705d0c94a0001000000   -mov dword ptr [0x4ac9d0], 1
    app->getMemory<x86::reg32>(x86::reg32(4901328) /* 0x4ac9d0 */) = 1 /*0x1*/;
    // 0041e534  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e535  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041e538  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041e539:
    // 0041e539  db0550f85100           -fild dword ptr [0x51f850]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */))));
    // 0041e53f  3935c8c94a00           +cmp dword ptr [0x4ac9c8], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4901320) /* 0x4ac9c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041e545  dc0d80774800           +fmul qword ptr [0x487780]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749184) /* 0x487780 */));
    // 0041e54b  d95c240c               +fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e54f  0f8448020000           -je 0x41e79d
    if (cpu.flags.zf)
    {
        goto L_0x0041e79d;
    }
    // 0041e555  a1d0c94a00             -mov eax, dword ptr [0x4ac9d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901328) /* 0x4ac9d0 */);
    // 0041e55a  c74424040000803f       -mov dword ptr [esp + 4], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1065353216 /*0x3f800000*/;
    // 0041e562  83f801                 +cmp eax, 1
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
    // 0041e565  7535                   -jne 0x41e59c
    if (!cpu.flags.zf)
    {
        goto L_0x0041e59c;
    }
    // 0041e567  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 0041e56d  db05ccc94a00           -fild dword ptr [0x4ac9cc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4901324) /* 0x4ac9cc */))));
    // 0041e573  dc2568774800           -fsub qword ptr [0x487768]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4749160) /* 0x487768 */));
    // 0041e579  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041e57b  dc0d78774800           -fmul qword ptr [0x487778]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749176) /* 0x487778 */));
    // 0041e581  d9542404               -fst dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 0041e585  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0041e58b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e58d  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041e592  7533                   -jne 0x41e5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0041e5c7;
    }
    // 0041e594  8935d0c94a00           -mov dword ptr [0x4ac9d0], esi
    app->getMemory<x86::reg32>(x86::reg32(4901328) /* 0x4ac9d0 */) = cpu.esi;
    // 0041e59a  eb04                   -jmp 0x41e5a0
    goto L_0x0041e5a0;
L_0x0041e59c:
    // 0041e59c  3bc6                   +cmp eax, esi
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
    // 0041e59e  755d                   -jne 0x41e5fd
    if (!cpu.flags.zf)
    {
        goto L_0x0041e5fd;
    }
L_0x0041e5a0:
    // 0041e5a0  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041e5a2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041e5a4  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0041e5a8  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0041e5ac  dc1dd8754800           -fcomp qword ptr [0x4875d8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748760) /* 0x4875d8 */)));
    cpu.fpu.pop();
    // 0041e5b2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e5b4  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041e5b7  7a3c                   -jp 0x41e5f5
    if (cpu.flags.pf)
    {
        goto L_0x0041e5f5;
    }
    // 0041e5b9  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0041e5bd  dc0d78774800           -fmul qword ptr [0x487778]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749176) /* 0x487778 */));
    // 0041e5c3  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041e5c7:
    // 0041e5c7  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041e5cb  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041e5d1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e5d3  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041e5d6  7a0a                   -jp 0x41e5e2
    if (cpu.flags.pf)
    {
        goto L_0x0041e5e2;
    }
    // 0041e5d8  c744240400000000       -mov dword ptr [esp + 4], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0041e5e0  eb1b                   -jmp 0x41e5fd
    goto L_0x0041e5fd;
L_0x0041e5e2:
    // 0041e5e2  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041e5e6  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0041e5ec  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e5ee  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041e5f3  7508                   -jne 0x41e5fd
    if (!cpu.flags.zf)
    {
        goto L_0x0041e5fd;
    }
L_0x0041e5f5:
    // 0041e5f5  c74424040000803f       -mov dword ptr [esp + 4], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1065353216 /*0x3f800000*/;
L_0x0041e5fd:
    // 0041e5fd  d944240c               +fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0041e601  d80db8744800           +fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0041e607  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041e608  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041e609  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041e60a  e881870500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041e60f  d9442418               +fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0041e613  d80d70774800           +fmul dword ptr [0x487770]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749168) /* 0x487770 */));
    // 0041e619  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041e61b  e870870500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041e620  d9442418               +fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0041e624  d80d4c764800           +fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 0041e62a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041e62c  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041e630  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0041e634  d9542420               +fst dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    // 0041e638  e853870500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041e63d  d9442418               +fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0041e641  d80d20774800           +fmul dword ptr [0x487720]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749088) /* 0x487720 */));
    // 0041e647  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0041e649  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0041e64e  d95c2424               +fstp dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041e652:
    // 0041e652  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041e656  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041e658  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041e659  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041e65a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041e65b  b924000000             -mov ecx, 0x24
    cpu.ecx = 36 /*0x24*/;
    // 0041e660  e8bbfcffff             -call 0x41e320
    cpu.esp -= 4;
    sub_41e320(app, cpu);
    // 0041e665  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0041e669  d8442424               +fadd dword ptr [esp + 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 0041e66d  e81e870500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041e672  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041e674  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041e675  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0041e679  75d7                   -jne 0x41e652
    if (!cpu.flags.zf)
    {
        goto L_0x0041e652;
    }
    // 0041e67b  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041e67f  8b1dc8c94a00           -mov ebx, dword ptr [0x4ac9c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4901320) /* 0x4ac9c8 */);
    // 0041e685  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0041e689  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0041e68d  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0041e68f:
    // 0041e68f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041e691  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041e693  8a93e0020000           -mov dl, byte ptr [ebx + 0x2e0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(736) /* 0x2e0 */);
    // 0041e699  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041e69b  0f8edc000000           -jle 0x41e77d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041e77d;
    }
    // 0041e6a1  8bbe34034900           -mov edi, dword ptr [esi + 0x490334]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4784948) /* 0x490334 */);
    // 0041e6a7  8b8be4020000           -mov ecx, dword ptr [ebx + 0x2e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(740) /* 0x2e4 */);
L_0x0041e6ad:
    // 0041e6ad  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041e6af  39bdb4020000           +cmp dword ptr [ebp + 0x2b4], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(692) /* 0x2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041e6b5  740d                   -je 0x41e6c4
    if (cpu.flags.zf)
    {
        goto L_0x0041e6c4;
    }
    // 0041e6b7  40                     -inc eax
    (cpu.eax)++;
    // 0041e6b8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041e6bb  3bc2                   +cmp eax, edx
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
    // 0041e6bd  7cee                   -jl 0x41e6ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041e6ad;
    }
    // 0041e6bf  e9b9000000             -jmp 0x41e77d
    goto L_0x0041e77d;
L_0x0041e6c4:
    // 0041e6c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e6c6  755b                   -jne 0x41e723
    if (!cpu.flags.zf)
    {
        goto L_0x0041e723;
    }
    // 0041e6c8  db0548845100           -fild dword ptr [0x518448]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */))));
    // 0041e6ce  db05ccc94a00           -fild dword ptr [0x4ac9cc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4901324) /* 0x4ac9cc */))));
    // 0041e6d4  dc2568774800           -fsub qword ptr [0x487768]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4749160) /* 0x487768 */));
    // 0041e6da  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041e6dc  dc0d78774800           -fmul qword ptr [0x487778]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749176) /* 0x487778 */));
    // 0041e6e2  dc0dd8744800           -fmul qword ptr [0x4874d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 0041e6e8  dc0568734800           -fadd qword ptr [0x487368]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 0041e6ee  dc1560744800           -fcom qword ptr [0x487460]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748384) /* 0x487460 */)));
    // 0041e6f4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e6f6  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041e6fb  7508                   -jne 0x41e705
    if (!cpu.flags.zf)
    {
        goto L_0x0041e705;
    }
    // 0041e6fd  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e6ff  d90510734800           +fld dword ptr [0x487310]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748048) /* 0x487310 */)));
L_0x0041e705:
    // 0041e705  d90594744800           +fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 0041e70b  d8e9                   +fsubr st(1)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(1)) - cpu.fpu.st(0);
    // 0041e70d  d84c2420               +fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 0041e711  dc0dd8744800           +fmul qword ptr [0x4874d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 0041e717  d95c241c               +fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e71b  d90594744800           +fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 0041e721  eb14                   -jmp 0x41e737
    goto L_0x0041e737;
L_0x0041e723:
    // 0041e723  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 0041e729  d90540764800           -fld dword ptr [0x487640]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748864) /* 0x487640 */)));
    // 0041e72f  c744241c00000000       -mov dword ptr [esp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x0041e737:
    // 0041e737  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0041e73b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e73c  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e73f  d84c241c               -fmul dword ptr [esp + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */));
    // 0041e743  d80d4c764800           -fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 0041e749  e842860500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041e74e  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0041e752  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041e753  d8642424               -fsub dword ptr [esp + 0x24]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 0041e757  e834860500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041e75c  db44241c               -fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 0041e760  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041e761  d8642428               -fsub dword ptr [esp + 0x28]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 0041e765  e826860500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041e76a  8b8e5c034900           -mov ecx, dword ptr [esi + 0x49035c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4784988) /* 0x49035c */);
    // 0041e770  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041e772  e8a9fbffff             -call 0x41e320
    cpu.esp -= 4;
    sub_41e320(app, cpu);
    // 0041e777  8b1dc8c94a00           -mov ebx, dword ptr [0x4ac9c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4901320) /* 0x4ac9c8 */);
L_0x0041e77d:
    // 0041e77d  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0041e781  d8442424               -fadd dword ptr [esp + 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 0041e785  e806860500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041e78a  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041e78d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041e791  83fe28                 +cmp esi, 0x28
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
    // 0041e794  0f8cf5feffff           -jl 0x41e68f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041e68f;
    }
    // 0041e79a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e79b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e79c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041e79d:
    // 0041e79d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e79e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041e7a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e7b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e7b0  a1d4c94a00             -mov eax, dword ptr [0x4ac9d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901332) /* 0x4ac9d4 */);
    // 0041e7b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e7c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e7c1  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041e7c6  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041e7cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e7cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041e7ce  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0041e7d0  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0041e7d6  8b8084020000           -mov eax, dword ptr [eax + 0x284]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(644) /* 0x284 */);
    // 0041e7dc  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0041e7df  8b3c82                 -mov edi, dword ptr [edx + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0041e7e2  e879390000             -call 0x422160
    cpu.esp -= 4;
    sub_422160(app, cpu);
    // 0041e7e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e7e9  0f8498000000           -je 0x41e887
    if (cpu.flags.zf)
    {
        goto L_0x0041e887;
    }
    // 0041e7ef  3b05d4c94a00           +cmp eax, dword ptr [0x4ac9d4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4901332) /* 0x4ac9d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041e7f5  0f8496000000           -je 0x41e891
    if (cpu.flags.zf)
    {
        goto L_0x0041e891;
    }
    // 0041e7fb  a3d4c94a00             -mov dword ptr [0x4ac9d4], eax
    app->getMemory<x86::reg32>(x86::reg32(4901332) /* 0x4ac9d4 */) = cpu.eax;
    // 0041e800  8a87e0020000           -mov al, byte ptr [edi + 0x2e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(736) /* 0x2e0 */);
    // 0041e806  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041e808  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0041e80a  742f                   -je 0x41e83b
    if (cpu.flags.zf)
    {
        goto L_0x0041e83b;
    }
    // 0041e80c  8b8fe4020000           -mov ecx, dword ptr [edi + 0x2e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(740) /* 0x2e4 */);
    // 0041e812  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041e818  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041e81a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0041e81c  83b92003000001         +cmp dword ptr [ecx + 0x320], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(800) /* 0x320 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041e823  7509                   -jne 0x41e82e
    if (!cpu.flags.zf)
    {
        goto L_0x0041e82e;
    }
    // 0041e825  e8063e0000             -call 0x422630
    cpu.esp -= 4;
    sub_422630(app, cpu);
    // 0041e82a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041e82c  eb0d                   -jmp 0x41e83b
    goto L_0x0041e83b;
L_0x0041e82e:
    // 0041e82e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041e830  e85b3d0000             -call 0x422590
    cpu.esp -= 4;
    sub_422590(app, cpu);
    // 0041e835  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e837  7402                   -je 0x41e83b
    if (cpu.flags.zf)
    {
        goto L_0x0041e83b;
    }
    // 0041e839  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0041e83b:
    // 0041e83b  a1d4c94a00             -mov eax, dword ptr [0x4ac9d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901332) /* 0x4ac9d4 */);
    // 0041e840  8bb818030000           -mov edi, dword ptr [eax + 0x318]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 0041e846  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041e848  7447                   -je 0x41e891
    if (cpu.flags.zf)
    {
        goto L_0x0041e891;
    }
    // 0041e84a  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041e84c  b9f0104900             -mov ecx, 0x4910f0
    cpu.ecx = 4788464 /*0x4910f0*/;
    // 0041e851  e8ba830400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 0041e856  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e858  7437                   -je 0x41e891
    if (cpu.flags.zf)
    {
        goto L_0x0041e891;
    }
    // 0041e85a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041e85c  740c                   -je 0x41e86a
    if (cpu.flags.zf)
    {
        goto L_0x0041e86a;
    }
    // 0041e85e  8b8eb4020000           -mov ecx, dword ptr [esi + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(692) /* 0x2b4 */);
    // 0041e864  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041e868  eb08                   -jmp 0x41e872
    goto L_0x0041e872;
L_0x0041e86a:
    // 0041e86a  c7442408ffffffff       -mov dword ptr [esp + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x0041e872:
    // 0041e872  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041e876  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e877  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041e879  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041e87b  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e87e  e86d900400             -call 0x4678f0
    cpu.esp -= 4;
    sub_4678f0(app, cpu);
    // 0041e883  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e884  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e885  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e886  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041e887:
    // 0041e887  c705d4c94a0000000000   -mov dword ptr [0x4ac9d4], 0
    app->getMemory<x86::reg32>(x86::reg32(4901332) /* 0x4ac9d4 */) = 0 /*0x0*/;
L_0x0041e891:
    // 0041e891  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e892  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e893  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041e894  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e8a0  c705d4c94a0000000000   -mov dword ptr [0x4ac9d4], 0
    app->getMemory<x86::reg32>(x86::reg32(4901332) /* 0x4ac9d4 */) = 0 /*0x0*/;
    // 0041e8aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e8b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e8b0  a1c4e54900             -mov eax, dword ptr [0x49e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 0041e8b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e8b7  7c49                   -jl 0x41e902
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041e902;
    }
    // 0041e8b9  833ddc28490014         +cmp dword ptr [0x4928dc], 0x14
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4794588) /* 0x4928dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041e8c0  7f40                   -jg 0x41e902
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041e902;
    }
    // 0041e8c2  a140845100             -mov eax, dword ptr [0x518440]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342272) /* 0x518440 */);
    // 0041e8c7  8b8828030000           -mov ecx, dword ptr [eax + 0x328]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(808) /* 0x328 */);
    // 0041e8cd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041e8cf  7421                   -je 0x41e8f2
    if (cpu.flags.zf)
    {
        goto L_0x0041e8f2;
    }
    // 0041e8d1  bafbffffff             -mov edx, 0xfffffffb
    cpu.edx = 4294967291 /*0xfffffffb*/;
    // 0041e8d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0041e8d7:
    // 0041e8d7  8bb0f8020000           -mov esi, dword ptr [eax + 0x2f8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(760) /* 0x2f8 */);
    // 0041e8dd  23f2                   -and esi, edx
    cpu.esi &= x86::reg32(x86::sreg32(cpu.edx));
    // 0041e8df  89b0f8020000           -mov dword ptr [eax + 0x2f8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(760) /* 0x2f8 */) = cpu.esi;
    // 0041e8e5  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041e8e7  8b8828030000           -mov ecx, dword ptr [eax + 0x328]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(808) /* 0x328 */);
    // 0041e8ed  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041e8ef  75e6                   -jne 0x41e8d7
    if (!cpu.flags.zf)
    {
        goto L_0x0041e8d7;
    }
    // 0041e8f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041e8f2:
    // 0041e8f2  a1d4c94a00             -mov eax, dword ptr [0x4ac9d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901332) /* 0x4ac9d4 */);
    // 0041e8f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e8f9  7407                   -je 0x41e902
    if (cpu.flags.zf)
    {
        goto L_0x0041e902;
    }
    // 0041e8fb  8388f802000004         -or dword ptr [eax + 0x2f8], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(760) /* 0x2f8 */) |= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041e902:
    // 0041e902  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e910  e81b6e0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e915  d91dd8c94a00           -fstp dword ptr [0x4ac9d8]
    app->getMemory<float>(x86::reg32(4901336) /* 0x4ac9d8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e91b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e920  e85be4feff             -call 0x40cd80
    cpu.esp -= 4;
    sub_40cd80(app, cpu);
    // 0041e925  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0041e92b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041e92d  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041e932  7514                   -jne 0x41e948
    if (!cpu.flags.zf)
    {
        goto L_0x0041e948;
    }
    // 0041e934  e8f76d0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041e939  d825d8c94a00           -fsub dword ptr [0x4ac9d8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4901336) /* 0x4ac9d8 */));
    // 0041e93f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041e940  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041e943  e878e4feff             -call 0x40cdc0
    cpu.esp -= 4;
    sub_40cdc0(app, cpu);
L_0x0041e948:
    // 0041e948  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e950  e86b130000             -call 0x41fcc0
    cpu.esp -= 4;
    sub_41fcc0(app, cpu);
    // 0041e955  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041e95b  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0041e95e  e90d000000             -jmp 0x41e970
    return sub_41e970(app, cpu);
}

/* align: skip  */
void Application::sub_41e970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e970  8a91f8020000           -mov dl, byte ptr [ecx + 0x2f8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(760) /* 0x2f8 */);
    // 0041e976  8b81fc020000           -mov eax, dword ptr [ecx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0041e97c  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 0041e97f  7504                   -jne 0x41e985
    if (!cpu.flags.zf)
    {
        goto L_0x0041e985;
    }
    // 0041e981  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041e984  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041e985:
    // 0041e985  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041e987  7504                   -jne 0x41e98d
    if (!cpu.flags.zf)
    {
        goto L_0x0041e98d;
    }
    // 0041e989  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041e98c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041e98d:
    // 0041e98d  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0041e990  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e9a0  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0041e9a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e9b0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041e9b2  c7059c185200ffffffff   -mov dword ptr [0x52189c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */) = 4294967295 /*0xffffffff*/;
    // 0041e9bc  a3a0185200             -mov dword ptr [0x5218a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */) = cpu.eax;
    // 0041e9c1  a36c185200             -mov dword ptr [0x52186c], eax
    app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */) = cpu.eax;
    // 0041e9c6  a398185200             -mov dword ptr [0x521898], eax
    app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */) = cpu.eax;
    // 0041e9cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e9d0  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 0041e9d3  8b0d98184900           -mov ecx, dword ptr [0x491898]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041e9d9  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 0041e9dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e9e0  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 0041e9e3  8b0d98184900           -mov ecx, dword ptr [0x491898]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041e9e9  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 0041e9ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41e9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041e9f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041e9f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041e9f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041e9f3  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041e9f5  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041e9f7  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0041e9fc  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041e9fe  e83de00200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041ea03  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041ea05  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041ea07  7516                   -jne 0x41ea1f
    if (!cpu.flags.zf)
    {
        goto L_0x0041ea1f;
    }
    // 0041ea09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ea0a  68ac194900             -push 0x4919ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790700 /*0x4919ac*/;
    cpu.esp -= 4;
    // 0041ea0f  e8a3830500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041ea14  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ea17  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ea19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea1c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0041ea1f:
    // 0041ea1f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041ea23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ea24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ea25  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041ea27  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ea28  e85b8c0500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041ea2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ea2e  e8a48b0500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041ea33  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041ea36  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041ea3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea3e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41ea50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ea50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ea51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ea52  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041ea54  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041ea56  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 0041ea5b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041ea5d  e8dedf0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041ea62  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041ea64  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041ea66  7505                   -jne 0x41ea6d
    if (!cpu.flags.zf)
    {
        goto L_0x0041ea6d;
    }
    // 0041ea68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea6a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0041ea6d:
    // 0041ea6d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041ea71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ea72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ea73  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041ea75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ea76  e8248d0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041ea7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ea7c  e8568b0500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041ea81  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041ea84  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041ea89  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ea8b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41ea90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ea90  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041ea93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ea94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041ea95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ea96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ea97  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0041ea99  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0041ea9d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ea9f  ba0c1a4900             -mov edx, 0x491a0c
    cpu.edx = 4790796 /*0x491a0c*/;
    // 0041eaa4  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041eaa8  c744241400000000       -mov dword ptr [esp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0041eab0  e83bffffff             -call 0x41e9f0
    cpu.esp -= 4;
    sub_41e9f0(app, cpu);
    // 0041eab5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041eab7  750d                   -jne 0x41eac6
    if (!cpu.flags.zf)
    {
        goto L_0x0041eac6;
    }
    // 0041eab9  68e4194900             -push 0x4919e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790756 /*0x4919e4*/;
    cpu.esp -= 4;
    // 0041eabe  e8f4820500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041eac3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041eac6:
    // 0041eac6  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0041eaca  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0041ead0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041ead2  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0041ead5  7a0a                   -jp 0x41eae1
    if (cpu.flags.pf)
    {
        goto L_0x0041eae1;
    }
    // 0041ead7  c744241403000000       -mov dword ptr [esp + 0x14], 3
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 3 /*0x3*/;
    // 0041eadf  eb34                   -jmp 0x41eb15
    goto L_0x0041eb15;
L_0x0041eae1:
    // 0041eae1  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0041eae5  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0041eaeb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041eaed  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041eaf2  7519                   -jne 0x41eb0d
    if (!cpu.flags.zf)
    {
        goto L_0x0041eb0d;
    }
    // 0041eaf4  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0041eaf8  d81d58744800           -fcomp dword ptr [0x487458]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */)));
    cpu.fpu.pop();
    // 0041eafe  c744241402000000       -mov dword ptr [esp + 0x14], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
    // 0041eb06  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041eb08  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041eb0b  7b08                   -jnp 0x41eb15
    if (!cpu.flags.pf)
    {
        goto L_0x0041eb15;
    }
L_0x0041eb0d:
    // 0041eb0d  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x0041eb15:
    // 0041eb15  a198184900             -mov eax, dword ptr [0x491898]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041eb1a  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041eb1c  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041eb1e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0041eb20:
    // 0041eb20  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041eb24  8b540308               -mov edx, dword ptr [ebx + eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.eax * 1);
    // 0041eb28  3bd1                   +cmp edx, ecx
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
    // 0041eb2a  7f2d                   -jg 0x41eb59
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041eb59;
    }
    // 0041eb2c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041eb30  8b4c030c               -mov ecx, dword ptr [ebx + eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.eax * 1);
    // 0041eb34  3bca                   +cmp ecx, edx
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
    // 0041eb36  7521                   -jne 0x41eb59
    if (!cpu.flags.zf)
    {
        goto L_0x0041eb59;
    }
    // 0041eb38  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041eb3a  8974bd00               -mov dword ptr [ebp + edi*4], esi
    app->getMemory<x86::reg32>(cpu.ebp + cpu.edi * 4) = cpu.esi;
    // 0041eb3e  e88dfeffff             -call 0x41e9d0
    cpu.esp -= 4;
    sub_41e9d0(app, cpu);
    // 0041eb43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041eb44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041eb45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041eb46  68c8194900             -push 0x4919c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790728 /*0x4919c8*/;
    cpu.esp -= 4;
    // 0041eb4b  e867820500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041eb50  a198184900             -mov eax, dword ptr [0x491898]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041eb55  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041eb58  47                     -inc edi
    (cpu.edi)++;
L_0x0041eb59:
    // 0041eb59  83c328                 -add ebx, 0x28
    (cpu.ebx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041eb5c  46                     -inc esi
    (cpu.esi)++;
    // 0041eb5d  81fbe8030000           +cmp ebx, 0x3e8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041eb63  7cbb                   -jl 0x41eb20
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041eb20;
    }
    // 0041eb65  c744bd00ffffffff       -mov dword ptr [ebp + edi*4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + cpu.edi * 4) = 4294967295 /*0xffffffff*/;
    // 0041eb6d  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041eb6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eb70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eb71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eb72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eb73  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041eb76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46e240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0046e240;
L_0x0041eb80:
    // 0041eb80  e85b150000             -call 0x4200e0
    cpu.esp -= 4;
    sub_4200e0(app, cpu);
    // 0041eb85  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041eb87  e904000000             -jmp 0x41eb90
    return sub_41eb90(app, cpu);
L_entry_0x0046e240:
    // 0046e240  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046e242  e83984ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046e247  e8448b0000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0046e24c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e24e  e92d09fbff             -jmp 0x41eb80
    goto L_0x0041eb80;
}

}
